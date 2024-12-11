/* Copyright 2024 The BoringSSL Authors
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */

#ifndef OPENSSL_HEADER_MLDSA_H_
#define OPENSSL_HEADER_MLDSA_H_

#include <openssl/base.h>

#if defined(__cplusplus)
extern "C" {
#endif


// ML-DSA.
//
// This implements the Module-Lattice-Based Digital Signature Standard from
// https://csrc.nist.gov/pubs/fips/204/final


// MLDSA_SEED_BYTES is the number of bytes in an ML-DSA seed value.
#define MLDSA_SEED_BYTES 32


// ML-DSA-65.

// MLDSA65_private_key contains an ML-DSA-65 private key. The contents of this
// object should never leave the address space since the format is unstable.
struct MLDSA65_private_key {
  union {
    uint8_t bytes[32 + 32 + 64 + 256 * 4 * (5 + 6 + 6)];
    uint32_t alignment;
  } opaque;
};

// MLDSA65_public_key contains an ML-DSA-65 public key. The contents of this
// object should never leave the address space since the format is unstable.
struct MLDSA65_public_key {
  union {
    uint8_t bytes[32 + 64 + 256 * 4 * 6];
    uint32_t alignment;
  } opaque;
};

// MLDSA65_PRIVATE_KEY_BYTES is the number of bytes in an encoded ML-DSA-65
// private key.
#define MLDSA65_PRIVATE_KEY_BYTES 4032

// MLDSA65_PUBLIC_KEY_BYTES is the number of bytes in an encoded ML-DSA-65
// public key.
#define MLDSA65_PUBLIC_KEY_BYTES 1952

// MLDSA65_SIGNATURE_BYTES is the number of bytes in an encoded ML-DSA-65
// signature.
#define MLDSA65_SIGNATURE_BYTES 3309

// MLDSA65_generate_key generates a random public/private key pair, writes the
// encoded public key to |out_encoded_public_key|, writes the seed to
// |out_seed|, and sets |out_private_key| to the private key. Returns 1 on
// success and 0 on allocation failure.
OPENSSL_EXPORT int MLDSA65_generate_key(
    uint8_t out_encoded_public_key[MLDSA65_PUBLIC_KEY_BYTES],
    uint8_t out_seed[MLDSA_SEED_BYTES],
    struct MLDSA65_private_key *out_private_key);

// MLDSA65_private_key_from_seed regenerates a private key from a seed value
// that was generated by |MLDSA65_generate_key|. Returns 1 on success and 0 on
// allocation failure or if |seed_len| is incorrect.
OPENSSL_EXPORT int MLDSA65_private_key_from_seed(
    struct MLDSA65_private_key *out_private_key, const uint8_t *seed,
    size_t seed_len);

// MLDSA65_public_from_private sets |*out_public_key| to the public key that
// corresponds to |private_key|. Returns 1 on success and 0 on failure.
OPENSSL_EXPORT int MLDSA65_public_from_private(
    struct MLDSA65_public_key *out_public_key,
    const struct MLDSA65_private_key *private_key);

// MLDSA65_sign generates a signature for the message |msg| of length
// |msg_len| using |private_key| (following the randomized algorithm), and
// writes the encoded signature to |out_encoded_signature|. The |context|
// argument is also signed over and can be used to include implicit contextual
// information that isn't included in |msg|. The same value of |context| must be
// presented to |MLDSA65_verify| in order for the generated signature to be
// considered valid. |context| and |context_len| may be |NULL| and 0 to use an
// empty context (this is common). Returns 1 on success and 0 on failure.
OPENSSL_EXPORT int MLDSA65_sign(
    uint8_t out_encoded_signature[MLDSA65_SIGNATURE_BYTES],
    const struct MLDSA65_private_key *private_key, const uint8_t *msg,
    size_t msg_len, const uint8_t *context, size_t context_len);

// MLDSA65_verify verifies that |signature| constitutes a valid
// signature for the message |msg| of length |msg_len| using |public_key|. The
// value of |context| must equal the value that was passed to |MLDSA65_sign|
// when the signature was generated. Returns 1 on success or 0 on error.
OPENSSL_EXPORT int MLDSA65_verify(const struct MLDSA65_public_key *public_key,
                                  const uint8_t *signature,
                                  size_t signature_len, const uint8_t *msg,
                                  size_t msg_len, const uint8_t *context,
                                  size_t context_len);

// MLDSA65_marshal_public_key serializes |public_key| to |out| in the standard
// format for ML-DSA-65 public keys. It returns 1 on success or 0 on
// allocation error.
OPENSSL_EXPORT int MLDSA65_marshal_public_key(
    CBB *out, const struct MLDSA65_public_key *public_key);

// MLDSA65_parse_public_key parses a public key, in the format generated by
// |MLDSA65_marshal_public_key|, from |in| and writes the result to
// |out_public_key|. It returns 1 on success or 0 on parse error or if
// there are trailing bytes in |in|.
OPENSSL_EXPORT int MLDSA65_parse_public_key(
    struct MLDSA65_public_key *public_key, CBS *in);

// MLDSA65_parse_private_key parses a private key, in the NIST format, from |in|
// and writes the result to |out_private_key|. It returns 1 on success or 0 on
// parse error or if there are trailing bytes in |in|.
OPENSSL_EXPORT int MLDSA65_parse_private_key(
    struct MLDSA65_private_key *private_key, CBS *in);


#if defined(__cplusplus)
}  // extern C
#endif

#endif  // OPENSSL_HEADER_MLDSA_H_
