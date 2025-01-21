/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/asn1.h>
#include <openssl/bytestring.h>
#include <openssl/err.h>
#include <openssl/mem.h>
#include <openssl/posix_time.h>

#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "internal.h"

int asn1_utctime_to_tm(struct tm *tm, const ASN1_UTCTIME *d,
                       int allow_timezone_offset) {
  if (d->type != V_ASN1_UTCTIME) {
    return 0;
  }
  CBS cbs;
  CBS_init(&cbs, d->data, (size_t)d->length);
  if (!CBS_parse_utc_time(&cbs, tm, allow_timezone_offset)) {
    return 0;
  }
  return 1;
}

int ASN1_UTCTIME_check(const ASN1_UTCTIME *d) {
  return asn1_utctime_to_tm(NULL, d, /*allow_timezone_offset=*/1);
}

int ASN1_UTCTIME_set_string(ASN1_UTCTIME *s, const char *str) {
  // Although elsewhere we allow timezone offsets with UTCTime, to be compatible
  // with some existing misissued certificates, this function is used to
  // construct new certificates and can be stricter.
  size_t len = strlen(str);
  CBS cbs;
  CBS_init(&cbs, (const uint8_t *)str, len);
  if (!CBS_parse_utc_time(&cbs, /*out_tm=*/NULL,
                          /*allow_timezone_offset=*/0)) {
    return 0;
  }
  if (s != NULL) {
    if (!ASN1_STRING_set(s, str, len)) {
      return 0;
    }
    s->type = V_ASN1_UTCTIME;
  }
  return 1;
}

ASN1_UTCTIME *ASN1_UTCTIME_set(ASN1_UTCTIME *s, int64_t posix_time) {
  return ASN1_UTCTIME_adj(s, posix_time, 0, 0);
}

ASN1_UTCTIME *ASN1_UTCTIME_adj(ASN1_UTCTIME *s, int64_t posix_time,
                               int offset_day, long offset_sec) {
  struct tm data;
  if (!OPENSSL_posix_to_tm(posix_time, &data)) {
    return NULL;
  }

  if (offset_day || offset_sec) {
    if (!OPENSSL_gmtime_adj(&data, offset_day, offset_sec)) {
      return NULL;
    }
  }

  if (data.tm_year < 50 || data.tm_year >= 150) {
    return NULL;
  }

  char buf[14];
  int ret = snprintf(buf, sizeof(buf), "%02d%02d%02d%02d%02d%02dZ",
                     data.tm_year % 100, data.tm_mon + 1, data.tm_mday,
                     data.tm_hour, data.tm_min, data.tm_sec);
  // |snprintf| must write exactly 15 bytes (plus the NUL) to the buffer.
  BSSL_CHECK(ret == static_cast<int>(sizeof(buf) - 1));

  int free_s = 0;
  if (s == NULL) {
    free_s = 1;
    s = ASN1_UTCTIME_new();
    if (s == NULL) {
      return NULL;
    }
  }

  if (!ASN1_STRING_set(s, buf, strlen(buf))) {
    if (free_s) {
      ASN1_UTCTIME_free(s);
    }
    return NULL;
  }
  s->type = V_ASN1_UTCTIME;
  return s;
}
