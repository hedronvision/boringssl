/* DTLS implementation written by Nagendra Modadugu
 * (nagendra@cs.stanford.edu) for the OpenSSL project 2005. */
/* ====================================================================
 * Copyright (c) 1998-2005 The OpenSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"
 *
 * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
 *    endorse or promote products derived from this software without
 *    prior written permission. For written permission, please contact
 *    openssl-core@openssl.org.
 *
 * 5. Products derived from this software may not be called "OpenSSL"
 *    nor may "OpenSSL" appear in their names without prior written
 *    permission of the OpenSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the OpenSSL Project
 *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 *
 * This product includes cryptographic software written by Eric Young
 * (eay@cryptsoft.com).  This product includes software written by Tim
 * Hudson (tjh@cryptsoft.com).
 *
 */
/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
 * All rights reserved.
 *
 * This package is an SSL implementation written
 * by Eric Young (eay@cryptsoft.com).
 * The implementation was written so as to conform with Netscapes SSL.
 *
 * This library is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@cryptsoft.com).
 *
 * Copyright remains Eric Young's, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, Eric Young should be given attribution
 * as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by
 *     Eric Young (eay@cryptsoft.com)"
 *    The word 'cryptographic' can be left out if the rouines from the library
 *    being used are not cryptographic related :-).
 * 4. If you include any Windows specific code (or a derivative thereof) from
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
 *
 * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.] */

#include <openssl/ssl.h>

#include <assert.h>
#include <string.h>

#include <algorithm>

#include <openssl/bio.h>
#include <openssl/bytestring.h>
#include <openssl/mem.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>

#include "../crypto/internal.h"
#include "internal.h"


BSSL_NAMESPACE_BEGIN

ssl_open_record_t dtls1_process_ack(SSL *ssl, uint8_t *out_alert,
                                    DTLSRecordNumber ack_record_number,
                                    Span<const uint8_t> data) {
  // As a DTLS-1.3-capable client, it is possible to receive an ACK before we
  // receive ServerHello and learned the server picked DTLS 1.3. Thus, tolerate
  // but ignore ACKs before the version is set.
  if (ssl->s3->version == 0) {
    return ssl_open_record_discard;
  }

  // ACKs are only allowed in DTLS 1.3. Reject them if we've negotiated a
  // version and it's not 1.3.
  if (ssl_protocol_version(ssl) < TLS1_3_VERSION) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_UNEXPECTED_RECORD);
    *out_alert = SSL_AD_UNEXPECTED_MESSAGE;
    return ssl_open_record_error;
  }

  // TODO(crbug.com/42290594): If we implement DTLS 1.3 0-RTT, we may switch to
  // DTLS 1.3, but then rewind to DTLS 1.2. In the intervening time, we may have
  // received an ACK and updated state, and then expose the DTLS 1.2 logic to
  // it. If we haven't received ServerHello, we probably need to continue
  // dropping ACKs.

  CBS cbs = data, record_numbers;
  if (!CBS_get_u16_length_prefixed(&cbs, &record_numbers) ||
      CBS_len(&cbs) != 0) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
    *out_alert = SSL_AD_DECODE_ERROR;
    return ssl_open_record_error;
  }

  while (CBS_len(&record_numbers) != 0) {
    uint64_t epoch, seq;
    if (!CBS_get_u64(&record_numbers, &epoch) ||
        !CBS_get_u64(&record_numbers, &seq)) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
      *out_alert = SSL_AD_DECODE_ERROR;
      return ssl_open_record_error;
    }

    // During the handshake, records must be ACKed at the same or higher epoch.
    // See https://www.rfc-editor.org/errata/eid8108. Additionally, if the
    // record does not fit in DTLSRecordNumber, it is definitely not a record
    // number that we sent.
    if ((ack_record_number.epoch() < ssl_encryption_application &&
         epoch > ack_record_number.epoch()) ||
        epoch > UINT16_MAX || seq > DTLSRecordNumber::kMaxSequence) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_DECODE_ERROR);
      *out_alert = SSL_AD_ILLEGAL_PARAMETER;
      return ssl_open_record_error;
    }

    // Find the sent record that matches this ACK.
    DTLSRecordNumber number(static_cast<uint16_t>(epoch), seq);
    DTLSSentRecord *sent_record = nullptr;
    if (ssl->d1->sent_records != nullptr) {
      for (size_t i = 0; i < ssl->d1->sent_records->size(); i++) {
        if ((*ssl->d1->sent_records)[i].number == number) {
          sent_record = &(*ssl->d1->sent_records)[i];
          break;
        }
      }
    }
    if (sent_record == nullptr) {
      // We may have sent this record and forgotten it, so this is not an error.
      continue;
    }

    // Mark each message as ACKed.
    if (sent_record->first_msg == sent_record->last_msg) {
      ssl->d1->outgoing_messages[sent_record->first_msg].acked.MarkRange(
          sent_record->first_msg_start, sent_record->last_msg_end);
    } else {
      ssl->d1->outgoing_messages[sent_record->first_msg].acked.MarkRange(
          sent_record->first_msg_start, SIZE_MAX);
      for (size_t i = size_t{sent_record->first_msg} + 1;
           i < sent_record->last_msg; i++) {
        ssl->d1->outgoing_messages[i].acked.MarkRange(0, SIZE_MAX);
      }
      if (sent_record->last_msg_end != 0) {
        ssl->d1->outgoing_messages[sent_record->last_msg].acked.MarkRange(
            0, sent_record->last_msg_end);
      }
    }

    // Clear the state so we don't bother re-marking the messages next time.
    sent_record->first_msg = 0;
    sent_record->first_msg_start = 0;
    sent_record->last_msg = 0;
    sent_record->last_msg_end = 0;
  }

  // If the outgoing flight is now fully ACKed, we are done retransmitting.
  if (std::all_of(ssl->d1->outgoing_messages.begin(),
                  ssl->d1->outgoing_messages.end(),
                  [](const auto &msg) { return msg.IsFullyAcked(); })) {
    dtls1_stop_timer(ssl);
    dtls_clear_outgoing_messages(ssl);
  } else {
    // We may still be able to drop unused write epochs.
    dtls_clear_unused_write_epochs(ssl);

    // TODO(crbug.com/42290594): Schedule a retransmit. The peer will have
    // waited before sending the ACK, so a partial ACK suggests packet loss.
  }

  return ssl_open_record_discard;
}

ssl_open_record_t dtls1_open_app_data(SSL *ssl, Span<uint8_t> *out,
                                      size_t *out_consumed, uint8_t *out_alert,
                                      Span<uint8_t> in) {
  assert(!SSL_in_init(ssl));

  uint8_t type;
  DTLSRecordNumber record_number;
  Span<uint8_t> record;
  auto ret = dtls_open_record(ssl, &type, &record_number, &record, out_consumed,
                              out_alert, in);
  if (ret != ssl_open_record_success) {
    return ret;
  }

  if (type == SSL3_RT_HANDSHAKE) {
    // Process handshake fragments for DTLS 1.3 post-handshake messages.
    if (ssl_protocol_version(ssl) >= TLS1_3_VERSION) {
      if (!dtls1_process_handshake_fragments(ssl, out_alert, record)) {
        return ssl_open_record_error;
      }
      return ssl_open_record_discard;
    }

    // Parse the first fragment header to determine if this is a pre-CCS or
    // post-CCS handshake record. DTLS resets handshake message numbers on each
    // handshake, so renegotiations and retransmissions are ambiguous.
    CBS cbs, body;
    struct hm_header_st msg_hdr;
    CBS_init(&cbs, record.data(), record.size());
    if (!dtls1_parse_fragment(&cbs, &msg_hdr, &body)) {
      OPENSSL_PUT_ERROR(SSL, SSL_R_BAD_HANDSHAKE_RECORD);
      *out_alert = SSL_AD_DECODE_ERROR;
      return ssl_open_record_error;
    }

    if (msg_hdr.type == SSL3_MT_FINISHED &&
        msg_hdr.seq == ssl->d1->handshake_read_seq - 1) {
      if (msg_hdr.frag_off == 0) {
        // Retransmit our last flight of messages. If the peer sends the second
        // Finished, they may not have received ours. Only do this for the
        // first fragment, in case the Finished was fragmented.
        if (!dtls1_check_timeout_num(ssl)) {
          *out_alert = 0;  // TODO(davidben): Send an alert?
          return ssl_open_record_error;
        }

        dtls1_retransmit_outgoing_messages(ssl);
      }
      return ssl_open_record_discard;
    }

    // Otherwise, this is a pre-CCS handshake message from an unsupported
    // renegotiation attempt. Fall through to the error path.
  }

  if (type == SSL3_RT_ACK) {
    return dtls1_process_ack(ssl, out_alert, record_number, record);
  }

  if (type != SSL3_RT_APPLICATION_DATA) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_UNEXPECTED_RECORD);
    *out_alert = SSL_AD_UNEXPECTED_MESSAGE;
    return ssl_open_record_error;
  }

  if (record.empty()) {
    return ssl_open_record_discard;
  }

  *out = record;
  return ssl_open_record_success;
}

int dtls1_write_app_data(SSL *ssl, bool *out_needs_handshake,
                         size_t *out_bytes_written, Span<const uint8_t> in) {
  assert(!SSL_in_init(ssl));
  *out_needs_handshake = false;

  if (ssl->s3->write_shutdown != ssl_shutdown_none) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_PROTOCOL_IS_SHUTDOWN);
    return -1;
  }

  // DTLS does not split the input across records.
  if (in.size() > SSL3_RT_MAX_PLAIN_LENGTH) {
    OPENSSL_PUT_ERROR(SSL, SSL_R_DTLS_MESSAGE_TOO_BIG);
    return -1;
  }

  if (in.empty()) {
    *out_bytes_written = 0;
    return 1;
  }

  // TODO(crbug.com/42290594): Use the 0-RTT epoch if writing 0-RTT.
  int ret = dtls1_write_record(ssl, SSL3_RT_APPLICATION_DATA, in,
                               ssl->d1->write_epoch.epoch());
  if (ret <= 0) {
    return ret;
  }
  *out_bytes_written = in.size();
  return 1;
}

int dtls1_write_record(SSL *ssl, int type, Span<const uint8_t> in,
                       uint16_t epoch) {
  SSLBuffer *buf = &ssl->s3->write_buffer;
  assert(in.size() <= SSL3_RT_MAX_PLAIN_LENGTH);
  // There should never be a pending write buffer in DTLS. One can't write half
  // a datagram, so the write buffer is always dropped in
  // |ssl_write_buffer_flush|.
  assert(buf->empty());

  if (in.size() > SSL3_RT_MAX_PLAIN_LENGTH) {
    OPENSSL_PUT_ERROR(SSL, ERR_R_INTERNAL_ERROR);
    return -1;
  }

  DTLSRecordNumber record_number;
  size_t ciphertext_len;
  if (!buf->EnsureCap(dtls_seal_prefix_len(ssl, epoch),
                      in.size() + SSL_max_seal_overhead(ssl)) ||
      !dtls_seal_record(ssl, &record_number, buf->remaining().data(),
                        &ciphertext_len, buf->remaining().size(), type,
                        in.data(), in.size(), epoch)) {
    buf->Clear();
    return -1;
  }
  buf->DidWrite(ciphertext_len);

  int ret = ssl_write_buffer_flush(ssl);
  if (ret <= 0) {
    return ret;
  }
  return 1;
}

int dtls1_dispatch_alert(SSL *ssl) {
  int ret = dtls1_write_record(ssl, SSL3_RT_ALERT, ssl->s3->send_alert,
                               ssl->d1->write_epoch.epoch());
  if (ret <= 0) {
    return ret;
  }
  ssl->s3->alert_dispatch = false;

  // If the alert is fatal, flush the BIO now.
  if (ssl->s3->send_alert[0] == SSL3_AL_FATAL) {
    BIO_flush(ssl->wbio.get());
  }

  ssl_do_msg_callback(ssl, 1 /* write */, SSL3_RT_ALERT, ssl->s3->send_alert);

  int alert = (ssl->s3->send_alert[0] << 8) | ssl->s3->send_alert[1];
  ssl_do_info_callback(ssl, SSL_CB_WRITE_ALERT, alert);

  return 1;
}

BSSL_NAMESPACE_END
