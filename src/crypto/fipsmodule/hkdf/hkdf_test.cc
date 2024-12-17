/* Copyright 2014 The BoringSSL Authors
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

#include <openssl/digest.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/hkdf.h>
#include <openssl/kdf.h>

#include <gtest/gtest.h>

#include "../../test/file_test.h"
#include "../../test/test_util.h"
#include "../../test/wycheproof_util.h"


namespace {

struct HKDFTestVector {
  const EVP_MD *(*md_func)(void);
  const uint8_t ikm[80];
  const size_t ikm_len;
  const uint8_t salt[80];
  const size_t salt_len;
  const uint8_t info[80];
  const size_t info_len;
  const uint8_t prk[EVP_MAX_MD_SIZE];
  const size_t prk_len;
  const size_t out_len;
  const uint8_t out[82];
};

// These test vectors are from RFC 5869.
static const HKDFTestVector kTests[] = {
    // clang-format off
  {
    EVP_sha256,
    {
      0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
      0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
    }, 22,
    {
      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
      0x0c,
    }, 13,
    {
      0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9,
    }, 10,
    {
      0x07, 0x77, 0x09, 0x36, 0x2c, 0x2e, 0x32, 0xdf, 0x0d, 0xdc, 0x3f, 0x0d,
      0xc4, 0x7b, 0xba, 0x63, 0x90, 0xb6, 0xc7, 0x3b, 0xb5, 0x0f, 0x9c, 0x31,
      0x22, 0xec, 0x84, 0x4a, 0xd7, 0xc2, 0xb3, 0xe5,
    }, 32,
    42, {
      0x3c, 0xb2, 0x5f, 0x25, 0xfa, 0xac, 0xd5, 0x7a, 0x90, 0x43, 0x4f, 0x64,
      0xd0, 0x36, 0x2f, 0x2a, 0x2d, 0x2d, 0x0a, 0x90, 0xcf, 0x1a, 0x5a, 0x4c,
      0x5d, 0xb0, 0x2d, 0x56, 0xec, 0xc4, 0xc5, 0xbf, 0x34, 0x00, 0x72, 0x08,
      0xd5, 0xb8, 0x87, 0x18, 0x58, 0x65
    }
  },
  {
    EVP_sha256,
    {
      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
      0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
      0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23,
      0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
      0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b,
      0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
      0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f
    }, 80,
    {
      0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b,
      0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
      0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83,
      0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
      0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b,
      0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
      0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf
    }, 80,
    {
      0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb,
      0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
      0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3,
      0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
      0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb,
      0xec, 0xed, 0xee, 0xef, 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
      0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
    }, 80,
    {
       0x06, 0xa6, 0xb8, 0x8c, 0x58, 0x53, 0x36, 0x1a, 0x06, 0x10, 0x4c, 0x9c,
       0xeb, 0x35, 0xb4, 0x5c, 0xef, 0x76, 0x00, 0x14, 0x90, 0x46, 0x71, 0x01,
       0x4a, 0x19, 0x3f, 0x40, 0xc1, 0x5f, 0xc2, 0x44,
    }, 32,
    82, {
      0xb1, 0x1e, 0x39, 0x8d, 0xc8, 0x03, 0x27, 0xa1, 0xc8, 0xe7, 0xf7, 0x8c,
      0x59, 0x6a, 0x49, 0x34, 0x4f, 0x01, 0x2e, 0xda, 0x2d, 0x4e, 0xfa, 0xd8,
      0xa0, 0x50, 0xcc, 0x4c, 0x19, 0xaf, 0xa9, 0x7c, 0x59, 0x04, 0x5a, 0x99,
      0xca, 0xc7, 0x82, 0x72, 0x71, 0xcb, 0x41, 0xc6, 0x5e, 0x59, 0x0e, 0x09,
      0xda, 0x32, 0x75, 0x60, 0x0c, 0x2f, 0x09, 0xb8, 0x36, 0x77, 0x93, 0xa9,
      0xac, 0xa3, 0xdb, 0x71, 0xcc, 0x30, 0xc5, 0x81, 0x79, 0xec, 0x3e, 0x87,
      0xc1, 0x4c, 0x01, 0xd5, 0xc1, 0xf3, 0x43, 0x4f, 0x1d, 0x87
    }
  },
  {
    EVP_sha256,
    {
      0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
      0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
    }, 22,
    {
       0,
    }, 0,
    {
       0,
    }, 0,
    {
      0x19, 0xef, 0x24, 0xa3, 0x2c, 0x71, 0x7b, 0x16, 0x7f, 0x33, 0xa9, 0x1d,
      0x6f, 0x64, 0x8b, 0xdf, 0x96, 0x59, 0x67, 0x76, 0xaf, 0xdb, 0x63, 0x77,
      0xac, 0x43, 0x4c, 0x1c, 0x29, 0x3c, 0xcb, 0x04
    }, 32,
    42, {
      0x8d, 0xa4, 0xe7, 0x75, 0xa5, 0x63, 0xc1, 0x8f, 0x71, 0x5f, 0x80, 0x2a,
      0x06, 0x3c, 0x5a, 0x31, 0xb8, 0xa1, 0x1f, 0x5c, 0x5e, 0xe1, 0x87, 0x9e,
      0xc3, 0x45, 0x4e, 0x5f, 0x3c, 0x73, 0x8d, 0x2d, 0x9d, 0x20, 0x13, 0x95,
      0xfa, 0xa4, 0xb6, 0x1a, 0x96, 0xc8
    }
  },
  {
    EVP_sha1,
    {
      0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
    }, 11,
    {
      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
      0x0c,
    }, 13,
    {
      0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9,
    }, 10,
    {
      0x9b, 0x6c, 0x18, 0xc4, 0x32, 0xa7, 0xbf, 0x8f, 0x0e, 0x71, 0xc8, 0xeb,
      0x88, 0xf4, 0xb3, 0x0b, 0xaa, 0x2b, 0xa2, 0x43
    }, 20,
    42, {
      0x08, 0x5a, 0x01, 0xea, 0x1b, 0x10, 0xf3, 0x69, 0x33, 0x06, 0x8b, 0x56,
      0xef, 0xa5, 0xad, 0x81, 0xa4, 0xf1, 0x4b, 0x82, 0x2f, 0x5b, 0x09, 0x15,
      0x68, 0xa9, 0xcd, 0xd4, 0xf1, 0x55, 0xfd, 0xa2, 0xc2, 0x2e, 0x42, 0x24,
      0x78, 0xd3, 0x05, 0xf3, 0xf8, 0x96
    }
  },
  {
    EVP_sha1,
    {
      0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
      0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
      0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23,
      0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
      0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b,
      0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
      0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f
    }, 80,
    {
      0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b,
      0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
      0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83,
      0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f,
      0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b,
      0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
      0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf
    }, 80,
    {
      0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xbb,
      0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7,
      0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3,
      0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf,
      0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb,
      0xec, 0xed, 0xee, 0xef, 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
      0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
    }, 80,
    {
      0x8a, 0xda, 0xe0, 0x9a, 0x2a, 0x30, 0x70, 0x59, 0x47, 0x8d, 0x30, 0x9b,
      0x26, 0xc4, 0x11, 0x5a, 0x22, 0x4c, 0xfa, 0xf6,
    }, 20,
    82, {
      0x0b, 0xd7, 0x70, 0xa7, 0x4d, 0x11, 0x60, 0xf7, 0xc9, 0xf1, 0x2c, 0xd5,
      0x91, 0x2a, 0x06, 0xeb, 0xff, 0x6a, 0xdc, 0xae, 0x89, 0x9d, 0x92, 0x19,
      0x1f, 0xe4, 0x30, 0x56, 0x73, 0xba, 0x2f, 0xfe, 0x8f, 0xa3, 0xf1, 0xa4,
      0xe5, 0xad, 0x79, 0xf3, 0xf3, 0x34, 0xb3, 0xb2, 0x02, 0xb2, 0x17, 0x3c,
      0x48, 0x6e, 0xa3, 0x7c, 0xe3, 0xd3, 0x97, 0xed, 0x03, 0x4c, 0x7f, 0x9d,
      0xfe, 0xb1, 0x5c, 0x5e, 0x92, 0x73, 0x36, 0xd0, 0x44, 0x1f, 0x4c, 0x43,
      0x00, 0xe2, 0xcf, 0xf0, 0xd0, 0x90, 0x0b, 0x52, 0xd3, 0xb4
    }
  },
  {
    EVP_sha1,
    {
      0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
      0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
    }, 22,
    {
       0,
    }, 0,
    {
       0,
    }, 0,
    {
      0xda, 0x8c, 0x8a, 0x73, 0xc7, 0xfa, 0x77, 0x28, 0x8e, 0xc6, 0xf5, 0xe7,
      0xc2, 0x97, 0x78, 0x6a, 0xa0, 0xd3, 0x2d, 0x01,
    }, 20,
    42, {
      0x0a, 0xc1, 0xaf, 0x70, 0x02, 0xb3, 0xd7, 0x61, 0xd1, 0xe5, 0x52, 0x98,
      0xda, 0x9d, 0x05, 0x06, 0xb9, 0xae, 0x52, 0x05, 0x72, 0x20, 0xa3, 0x06,
      0xe0, 0x7b, 0x6b, 0x87, 0xe8, 0xdf, 0x21, 0xd0, 0xea, 0x00, 0x03, 0x3d,
      0xe0, 0x39, 0x84, 0xd3, 0x49, 0x18
    }
  },
  {
    EVP_sha1,
    {
      0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
      0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
    }, 22,
    {
       0,
    }, 0,
    {
       0,
    }, 0,
    {
      0x2a, 0xdc, 0xca, 0xda, 0x18, 0x77, 0x9e, 0x7c, 0x20, 0x77, 0xad, 0x2e,
      0xb1, 0x9d, 0x3f, 0x3e, 0x73, 0x13, 0x85, 0xdd,
    }, 20,
    42, {
      0x2c, 0x91, 0x11, 0x72, 0x04, 0xd7, 0x45, 0xf3, 0x50, 0x0d, 0x63, 0x6a,
      0x62, 0xf6, 0x4f, 0x0a, 0xb3, 0xba, 0xe5, 0x48, 0xaa, 0x53, 0xd4, 0x23,
      0xb0, 0xd1, 0xf2, 0x7e, 0xbb, 0xa6, 0xf5, 0xe5, 0x67, 0x3a, 0x08, 0x1d,
      0x70, 0xcc, 0xe7, 0xac, 0xfc, 0x48
    }
  },
    // clang-format on
};

TEST(HKDFTest, TestVectors) {
  for (size_t i = 0; i < OPENSSL_ARRAY_SIZE(kTests); i++) {
    SCOPED_TRACE(i);
    const HKDFTestVector *test = &kTests[i];

    uint8_t prk[EVP_MAX_MD_SIZE];
    size_t prk_len;
    ASSERT_TRUE(HKDF_extract(prk, &prk_len, test->md_func(), test->ikm,
                             test->ikm_len, test->salt, test->salt_len));
    EXPECT_EQ(Bytes(test->prk, test->prk_len), Bytes(prk, prk_len));

    uint8_t buf[82];
    ASSERT_TRUE(HKDF_expand(buf, test->out_len, test->md_func(), prk, prk_len,
                            test->info, test->info_len));
    EXPECT_EQ(Bytes(test->out, test->out_len), Bytes(buf, test->out_len));

    ASSERT_TRUE(HKDF(buf, test->out_len, test->md_func(), test->ikm,
                     test->ikm_len, test->salt, test->salt_len, test->info,
                     test->info_len));
    EXPECT_EQ(Bytes(test->out, test->out_len), Bytes(buf, test->out_len));

    // Repeat the test with the OpenSSL compatibility |EVP_PKEY_derive| API.
    bssl::UniquePtr<EVP_PKEY_CTX> ctx(
        EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, nullptr));
    ASSERT_TRUE(ctx);
    ASSERT_TRUE(EVP_PKEY_derive_init(ctx.get()));
    ASSERT_TRUE(
        EVP_PKEY_CTX_hkdf_mode(ctx.get(), EVP_PKEY_HKDEF_MODE_EXTRACT_ONLY));
    ASSERT_TRUE(EVP_PKEY_CTX_set_hkdf_md(ctx.get(), test->md_func()));
    ASSERT_TRUE(
        EVP_PKEY_CTX_set1_hkdf_key(ctx.get(), test->ikm, test->ikm_len));
    ASSERT_TRUE(
        EVP_PKEY_CTX_set1_hkdf_salt(ctx.get(), test->salt, test->salt_len));
    for (bool copy_ctx : {false, true}) {
      SCOPED_TRACE(copy_ctx);
      bssl::UniquePtr<EVP_PKEY_CTX> copy;
      EVP_PKEY_CTX *use_ctx = ctx.get();
      if (copy_ctx) {
        copy.reset(EVP_PKEY_CTX_dup(ctx.get()));
        ASSERT_TRUE(copy);
        use_ctx = copy.get();
      }

      // A null output should report the length.
      prk_len = 0;
      ASSERT_TRUE(EVP_PKEY_derive(use_ctx, nullptr, &prk_len));
      EXPECT_EQ(prk_len, test->prk_len);

      // Too small of a buffer should cleanly fail.
      prk_len = test->prk_len - 1;
      EXPECT_FALSE(EVP_PKEY_derive(use_ctx, prk, &prk_len));
      ERR_clear_error();

      // Test the correct buffer size.
      OPENSSL_memset(prk, 0, sizeof(prk));
      prk_len = test->prk_len;
      ASSERT_TRUE(EVP_PKEY_derive(use_ctx, prk, &prk_len));
      EXPECT_EQ(Bytes(test->prk, test->prk_len), Bytes(prk, prk_len));

      // Test a larger buffer than necessary.
      OPENSSL_memset(prk, 0, sizeof(prk));
      prk_len = test->prk_len + 1;
      ASSERT_TRUE(EVP_PKEY_derive(use_ctx, prk, &prk_len));
      EXPECT_EQ(Bytes(test->prk, test->prk_len), Bytes(prk, prk_len));
    }

    ctx.reset(EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, nullptr));
    ASSERT_TRUE(ctx);
    ASSERT_TRUE(EVP_PKEY_derive_init(ctx.get()));
    ASSERT_TRUE(
        EVP_PKEY_CTX_hkdf_mode(ctx.get(), EVP_PKEY_HKDEF_MODE_EXPAND_ONLY));
    ASSERT_TRUE(EVP_PKEY_CTX_set_hkdf_md(ctx.get(), test->md_func()));
    ASSERT_TRUE(
        EVP_PKEY_CTX_set1_hkdf_key(ctx.get(), test->prk, test->prk_len));
    // |info| can be passed in multiple parts.
    size_t half = test->info_len / 2;
    ASSERT_TRUE(EVP_PKEY_CTX_add1_hkdf_info(ctx.get(), test->info, half));
    ASSERT_TRUE(EVP_PKEY_CTX_add1_hkdf_info(ctx.get(), test->info + half,
                                            test->info_len - half));
    for (bool copy_ctx : {false, true}) {
      SCOPED_TRACE(copy_ctx);
      bssl::UniquePtr<EVP_PKEY_CTX> copy;
      EVP_PKEY_CTX *use_ctx = ctx.get();
      if (copy_ctx) {
        copy.reset(EVP_PKEY_CTX_dup(ctx.get()));
        ASSERT_TRUE(copy);
        use_ctx = copy.get();
      }
      OPENSSL_memset(buf, 0, sizeof(buf));
      size_t len = test->out_len;
      ASSERT_TRUE(EVP_PKEY_derive(use_ctx, buf, &len));
      EXPECT_EQ(Bytes(test->out, test->out_len), Bytes(buf, len));
    }

    ctx.reset(EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, nullptr));
    ASSERT_TRUE(ctx);
    ASSERT_TRUE(EVP_PKEY_derive_init(ctx.get()));
    ASSERT_TRUE(EVP_PKEY_CTX_hkdf_mode(ctx.get(),
                                       EVP_PKEY_HKDEF_MODE_EXTRACT_AND_EXPAND));
    ASSERT_TRUE(EVP_PKEY_CTX_set_hkdf_md(ctx.get(), test->md_func()));
    ASSERT_TRUE(
        EVP_PKEY_CTX_set1_hkdf_key(ctx.get(), test->ikm, test->ikm_len));
    ASSERT_TRUE(
        EVP_PKEY_CTX_set1_hkdf_salt(ctx.get(), test->salt, test->salt_len));
    // |info| can be passed in multiple parts.
    ASSERT_TRUE(EVP_PKEY_CTX_add1_hkdf_info(ctx.get(), test->info, half));
    ASSERT_TRUE(EVP_PKEY_CTX_add1_hkdf_info(ctx.get(), test->info + half,
                                            test->info_len - half));
    for (bool copy_ctx : {false, true}) {
      SCOPED_TRACE(copy_ctx);
      bssl::UniquePtr<EVP_PKEY_CTX> copy;
      EVP_PKEY_CTX *use_ctx = ctx.get();
      if (copy_ctx) {
        copy.reset(EVP_PKEY_CTX_dup(ctx.get()));
        ASSERT_TRUE(copy);
        use_ctx = copy.get();
      }
      OPENSSL_memset(buf, 0, sizeof(buf));
      size_t len = test->out_len;
      ASSERT_TRUE(EVP_PKEY_derive(use_ctx, buf, &len));
      EXPECT_EQ(Bytes(test->out, test->out_len), Bytes(buf, len));
    }
  }
}

static void RunWycheproofTest(const char *path, const EVP_MD *md) {
  SCOPED_TRACE(path);
  FileTestGTest(path, [&](FileTest *t) {
    t->IgnoreInstruction("keySize");
    std::vector<uint8_t> ikm, info, okm, salt;
    ASSERT_TRUE(t->GetBytes(&ikm, "ikm"));
    ASSERT_TRUE(t->GetBytes(&info, "info"));
    ASSERT_TRUE(t->GetBytes(&okm, "okm"));
    ASSERT_TRUE(t->GetBytes(&salt, "salt"));
    WycheproofResult result;
    ASSERT_TRUE(GetWycheproofResult(t, &result));
    std::string size_str;
    ASSERT_TRUE(t->GetAttribute(&size_str, "size"));

    std::vector<uint8_t> out(atoi(size_str.c_str()));
    bool ret = HKDF(out.data(), out.size(), md, ikm.data(), ikm.size(),
                    salt.data(), salt.size(), info.data(), info.size());
    EXPECT_EQ(result.IsValid(), ret);
    if (result.IsValid()) {
      EXPECT_EQ(Bytes(okm), Bytes(out));
    }
  });
}

TEST(HKDFTest, WycheproofSHA1) {
  RunWycheproofTest("third_party/wycheproof_testvectors/hkdf_sha1_test.txt",
                    EVP_sha1());
}

TEST(HKDFTest, WycheproofSHA256) {
  RunWycheproofTest("third_party/wycheproof_testvectors/hkdf_sha256_test.txt",
                    EVP_sha256());
}

TEST(HKDFTest, WycheproofSHA384) {
  RunWycheproofTest("third_party/wycheproof_testvectors/hkdf_sha384_test.txt",
                    EVP_sha384());
}

TEST(HKDFTest, WycheproofSHA512) {
  RunWycheproofTest("third_party/wycheproof_testvectors/hkdf_sha512_test.txt",
                    EVP_sha512());
}

}  // namespace
