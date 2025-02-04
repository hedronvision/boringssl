// Copyright 2014 The BoringSSL Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stddef.h>
#include <stdint.h>

#include "internal.h"


const uint8_t kDERRSAPrivate2048[] = {
    0x30, 0x82, 0x04, 0xa3, 0x02, 0x01, 0x00, 0x02, 0x82, 0x01, 0x01, 0x00,
    0xd0, 0x02, 0xde, 0x5d, 0x19, 0x33, 0x48, 0x15, 0xc7, 0x86, 0xde, 0xa3,
    0xec, 0x63, 0x89, 0x14, 0x63, 0x99, 0x30, 0x1f, 0x5d, 0x25, 0xb2, 0xfa,
    0x27, 0x28, 0x4b, 0xb4, 0xf3, 0xba, 0xc6, 0xbc, 0x19, 0x38, 0x89, 0x56,
    0xf0, 0x42, 0xae, 0x9f, 0x84, 0x7b, 0x0d, 0xcf, 0xda, 0x1c, 0xd1, 0xd8,
    0x11, 0x26, 0x3f, 0x67, 0x76, 0x19, 0xfd, 0xfe, 0x6b, 0x12, 0xd4, 0x02,
    0x00, 0x42, 0x1b, 0x0f, 0xb6, 0x78, 0x5e, 0x1d, 0xb9, 0x3d, 0x32, 0x4f,
    0x7f, 0x41, 0xe4, 0xc9, 0x1b, 0x94, 0x40, 0x4e, 0xa2, 0x5c, 0x9c, 0x88,
    0x79, 0xf9, 0x9a, 0x64, 0x1b, 0x83, 0xdf, 0x1f, 0x9b, 0xb1, 0xa5, 0xe4,
    0xdf, 0x6d, 0x75, 0x3f, 0x98, 0xc7, 0x42, 0x53, 0xb4, 0x36, 0xba, 0x60,
    0xdd, 0xbd, 0x2d, 0xa9, 0x9f, 0x63, 0xd2, 0x74, 0xcc, 0xff, 0x13, 0x8a,
    0xa1, 0xd0, 0x91, 0x36, 0x1e, 0x22, 0x6e, 0x45, 0x46, 0xf3, 0xd1, 0xca,
    0xf6, 0x2c, 0x3f, 0x87, 0xf1, 0x15, 0xbf, 0xb0, 0x4d, 0xe3, 0xcc, 0xa7,
    0x18, 0xad, 0xa9, 0xb0, 0x5f, 0xbb, 0x2d, 0xc3, 0x06, 0x55, 0x69, 0x40,
    0xb9, 0x9a, 0x92, 0x14, 0x67, 0xde, 0x4c, 0x0d, 0x09, 0xab, 0x57, 0x41,
    0xe4, 0x30, 0xae, 0xd2, 0x22, 0x01, 0xbb, 0x36, 0xcb, 0x45, 0x0a, 0x82,
    0xc8, 0x56, 0x61, 0x39, 0x6a, 0x0a, 0xea, 0xab, 0x39, 0x28, 0x2c, 0x92,
    0x80, 0xe8, 0x00, 0xd1, 0xfa, 0xcc, 0x1d, 0xf8, 0xe5, 0xd7, 0x03, 0x34,
    0x04, 0x1b, 0x17, 0x35, 0xbc, 0xc6, 0xf9, 0x55, 0x0c, 0x05, 0xd8, 0xd3,
    0xc7, 0x4e, 0x0a, 0x92, 0xf1, 0x1d, 0x0d, 0x01, 0xf3, 0x0e, 0x3a, 0x9b,
    0x9b, 0x75, 0x8f, 0xe8, 0x0d, 0xbb, 0xf6, 0x81, 0x09, 0x48, 0x72, 0x05,
    0x9e, 0x0e, 0x48, 0x62, 0xd2, 0xba, 0x88, 0xa3, 0x18, 0xf5, 0x1b, 0xc9,
    0x9b, 0xff, 0x31, 0x3f, 0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x82, 0x01,
    0x00, 0x76, 0xf1, 0x9c, 0xfb, 0x79, 0x64, 0x84, 0x8c, 0xc7, 0xaa, 0x4c,
    0x77, 0x49, 0xbd, 0xe4, 0xed, 0xbe, 0xc2, 0x22, 0xed, 0x5c, 0x53, 0x29,
    0x53, 0xb7, 0xbe, 0x68, 0x04, 0x11, 0xf6, 0xb4, 0x9b, 0x6c, 0x84, 0x92,
    0xac, 0x1e, 0xf8, 0xd2, 0x67, 0xae, 0xd6, 0xba, 0xa0, 0x27, 0x25, 0xa1,
    0xac, 0xbe, 0xa9, 0xb3, 0x49, 0xd3, 0x13, 0xab, 0xd4, 0xa6, 0x9f, 0x7e,
    0x91, 0xa2, 0x5a, 0x2a, 0xa5, 0x42, 0x7e, 0xf3, 0xba, 0x65, 0x69, 0x23,
    0xf2, 0xa7, 0x5f, 0x23, 0x97, 0x07, 0xe9, 0x2f, 0x18, 0x87, 0xe9, 0x13,
    0x2d, 0x4b, 0x2a, 0x3a, 0x69, 0x91, 0xfe, 0x47, 0x41, 0x08, 0xc3, 0x7d,
    0x8c, 0x31, 0x62, 0xa2, 0xcf, 0xf9, 0xe9, 0xbe, 0xf8, 0xa4, 0x2d, 0x43,
    0x48, 0x0e, 0xa3, 0x95, 0x8f, 0xcf, 0xef, 0xc1, 0xb1, 0x3e, 0x63, 0x81,
    0x66, 0x1d, 0x7f, 0x68, 0xf9, 0x9c, 0x23, 0xae, 0x0f, 0x70, 0xaf, 0xed,
    0xa9, 0x4e, 0x95, 0xd1, 0x39, 0x51, 0x15, 0x55, 0xfc, 0x4e, 0x9e, 0xb3,
    0xb0, 0xc0, 0x07, 0x1d, 0xd9, 0xd2, 0x48, 0x4c, 0x03, 0x31, 0x2d, 0x21,
    0xda, 0x4d, 0xed, 0x29, 0xf8, 0xbf, 0xaf, 0x1f, 0x8d, 0x6f, 0xdc, 0xae,
    0xf0, 0x4a, 0x01, 0xa1, 0xb8, 0x06, 0x61, 0x58, 0x18, 0xff, 0x40, 0xa1,
    0x1c, 0x82, 0xf8, 0x23, 0xaf, 0xce, 0x62, 0x3e, 0x2d, 0x30, 0x09, 0xff,
    0xba, 0xa6, 0x34, 0x7e, 0x6e, 0x9e, 0x59, 0x66, 0x6b, 0x39, 0x08, 0x1f,
    0x3e, 0x76, 0xbc, 0x29, 0xef, 0x10, 0x62, 0x7f, 0xf4, 0xdf, 0xe6, 0x5f,
    0xa4, 0x1f, 0x60, 0xfe, 0x37, 0xdb, 0xd7, 0x8f, 0xff, 0xf9, 0xf0, 0xaf,
    0x66, 0xa2, 0x7d, 0x36, 0x19, 0x7f, 0xe2, 0xc3, 0x84, 0x66, 0x18, 0x2b,
    0x18, 0x16, 0x4f, 0xb3, 0xce, 0x69, 0x6b, 0xb6, 0xd6, 0x98, 0x25, 0xcb,
    0x90, 0x4f, 0x60, 0x68, 0x91, 0x02, 0x81, 0x81, 0x00, 0xf6, 0xd6, 0xae,
    0x84, 0xc0, 0x9f, 0x2f, 0xef, 0xa6, 0x7e, 0x91, 0x7a, 0x4d, 0x1c, 0xe0,
    0x3e, 0x61, 0xf8, 0xcc, 0x4d, 0x0d, 0x09, 0xa3, 0xeb, 0x9a, 0xbe, 0x89,
    0x59, 0x50, 0xf7, 0xd6, 0x8f, 0x66, 0x67, 0x97, 0x7e, 0xb4, 0x2d, 0x73,
    0x08, 0xf8, 0x12, 0x22, 0x7f, 0x5c, 0x76, 0x2b, 0x06, 0x7c, 0xaa, 0x54,
    0x83, 0xce, 0x2d, 0xab, 0xc3, 0xb7, 0xb1, 0x74, 0x10, 0xc9, 0x67, 0xc7,
    0x8c, 0xd1, 0x13, 0x17, 0x1e, 0xb2, 0x4f, 0xc7, 0xda, 0xcf, 0x45, 0xc3,
    0x1c, 0x6d, 0x98, 0x08, 0xc9, 0xf4, 0xd4, 0x6d, 0x16, 0xb4, 0x6b, 0x02,
    0x24, 0x25, 0x0a, 0x2d, 0xc0, 0xa3, 0x2e, 0x4b, 0xae, 0xf7, 0x4e, 0xb5,
    0x68, 0xb2, 0xe7, 0x88, 0xdc, 0x2e, 0xbc, 0x91, 0x42, 0x7f, 0x36, 0xbc,
    0x71, 0x4e, 0xc4, 0x5f, 0xfa, 0xbe, 0x46, 0x89, 0x61, 0xe3, 0x17, 0x3b,
    0x51, 0x29, 0xa8, 0x2c, 0x07, 0x02, 0x81, 0x81, 0x00, 0xd7, 0xbb, 0x45,
    0x76, 0x81, 0x15, 0x3e, 0x1b, 0x95, 0xd8, 0x7c, 0x8c, 0x08, 0x02, 0xe1,
    0x04, 0xaf, 0xa1, 0x59, 0x4c, 0xc7, 0x71, 0xf1, 0xd0, 0xef, 0xa7, 0xb6,
    0xa0, 0x70, 0xd0, 0xf7, 0x86, 0x8d, 0x4a, 0xf6, 0x9f, 0xac, 0xf3, 0x78,
    0xc9, 0xb5, 0xdf, 0x86, 0x71, 0xa9, 0x69, 0x63, 0xe4, 0x8a, 0x22, 0x57,
    0xa2, 0xa8, 0xd5, 0xf1, 0xb0, 0xe5, 0x43, 0x20, 0xd2, 0x18, 0x89, 0x3b,
    0xed, 0x90, 0xf5, 0xde, 0x82, 0x90, 0x7a, 0xd4, 0x0a, 0x3d, 0x89, 0x82,
    0x3a, 0x5f, 0x66, 0x73, 0x0e, 0x98, 0x1c, 0x84, 0x3a, 0x5a, 0x8f, 0xa1,
    0xb8, 0x60, 0xaf, 0x40, 0x8b, 0x6f, 0xda, 0x85, 0xad, 0x55, 0x62, 0x04,
    0xe1, 0x07, 0xb8, 0x49, 0xcb, 0xd4, 0x17, 0xdc, 0xb6, 0xe3, 0x39, 0xf5,
    0x22, 0xa0, 0xec, 0x58, 0xbd, 0x06, 0x4a, 0x87, 0xa1, 0x90, 0x9c, 0x27,
    0xd7, 0xa5, 0x9d, 0xf3, 0x09, 0x02, 0x81, 0x80, 0x28, 0x4c, 0xec, 0xb9,
    0x67, 0xe9, 0x95, 0x9d, 0xff, 0x04, 0xf3, 0x23, 0x90, 0xab, 0x82, 0x41,
    0x2d, 0x25, 0xbd, 0xd5, 0x66, 0xa7, 0x88, 0x47, 0xd3, 0x40, 0x00, 0x94,
    0xc0, 0x8f, 0x76, 0x4c, 0x7b, 0x5f, 0xb6, 0x70, 0x4d, 0x62, 0x8e, 0x41,
    0x8c, 0x9f, 0x09, 0x5a, 0xd9, 0xf1, 0xc1, 0x1c, 0x92, 0x06, 0x0d, 0x3e,
    0x67, 0xcf, 0x35, 0x18, 0x03, 0x49, 0xc9, 0xb5, 0x63, 0xec, 0xb9, 0xbb,
    0xd7, 0xf6, 0xd1, 0xf3, 0x85, 0x11, 0x59, 0x83, 0xf4, 0x0b, 0x63, 0xcb,
    0xa4, 0x69, 0x0a, 0x26, 0x4e, 0xfe, 0xcf, 0xc0, 0xc1, 0x3c, 0x27, 0x61,
    0x57, 0x5a, 0xce, 0x15, 0x81, 0x8e, 0xf1, 0x74, 0x63, 0x94, 0x4a, 0x32,
    0x09, 0xe3, 0x9b, 0x88, 0xb7, 0x68, 0xba, 0x1e, 0xad, 0x3e, 0x76, 0x8d,
    0xd9, 0x5a, 0x5e, 0x81, 0x45, 0xc7, 0xa6, 0x6e, 0x80, 0xf1, 0x2e, 0x12,
    0x16, 0x47, 0x0a, 0xc9, 0x02, 0x81, 0x81, 0x00, 0xa0, 0xc7, 0x6e, 0x46,
    0x9a, 0x7f, 0x85, 0x71, 0x33, 0xa5, 0x4b, 0x75, 0x65, 0x87, 0x17, 0xc2,
    0xd1, 0x4e, 0x33, 0xea, 0x97, 0xfe, 0x20, 0xd5, 0xb1, 0xb6, 0xd1, 0xd2,
    0x13, 0x22, 0x7a, 0x47, 0xaa, 0x48, 0x03, 0x34, 0x0f, 0xc6, 0xc8, 0xef,
    0xb3, 0xff, 0x6a, 0x08, 0x8d, 0xd5, 0x00, 0xe0, 0xd3, 0xde, 0x32, 0x68,
    0x04, 0xe2, 0xa6, 0x25, 0x4b, 0x48, 0x53, 0x4e, 0xa1, 0x80, 0xad, 0xcc,
    0x29, 0x2c, 0x44, 0xf0, 0x13, 0xd3, 0xa6, 0xf2, 0x16, 0xd8, 0xc3, 0xd8,
    0xd3, 0x3e, 0xdc, 0x63, 0x35, 0x14, 0x93, 0xab, 0x95, 0xd0, 0xd4, 0x1b,
    0x40, 0xdb, 0x7c, 0x04, 0x2f, 0x91, 0xb1, 0xec, 0xf3, 0xe4, 0x80, 0x74,
    0x61, 0xb7, 0x84, 0x30, 0x47, 0xda, 0x9c, 0xe1, 0x24, 0xca, 0x0e, 0x1b,
    0x07, 0xc9, 0xfd, 0x7c, 0xab, 0x12, 0xa2, 0xb0, 0xd3, 0xc0, 0xbd, 0xa4,
    0xe7, 0x46, 0xa7, 0x59, 0x02, 0x81, 0x80, 0x30, 0x5a, 0xa3, 0x8e, 0x0f,
    0xeb, 0xad, 0x9f, 0xf6, 0xa4, 0x82, 0xd8, 0x78, 0x83, 0xd2, 0xe4, 0x14,
    0x91, 0x20, 0x6f, 0x1f, 0x2b, 0x08, 0x21, 0x92, 0x5e, 0x30, 0xfe, 0x13,
    0xf2, 0x02, 0xd6, 0xe8, 0x96, 0x40, 0x98, 0x85, 0xb2, 0x63, 0x2b, 0x12,
    0xcf, 0x37, 0x4a, 0x27, 0xb1, 0x5f, 0x6f, 0x76, 0xa0, 0x29, 0xae, 0x2f,
    0x63, 0x72, 0xd9, 0x39, 0xca, 0x09, 0x29, 0x47, 0x98, 0x9f, 0x85, 0xae,
    0xb7, 0xe3, 0x0c, 0xcd, 0xbe, 0x4e, 0x45, 0xd3, 0x69, 0x1a, 0xb7, 0x7f,
    0xce, 0x2d, 0xfe, 0x9b, 0xe7, 0x4c, 0x7c, 0x2c, 0x8c, 0x26, 0x92, 0xdc,
    0x73, 0x71, 0x5f, 0x09, 0x4b, 0x49, 0xbf, 0x86, 0x94, 0xef, 0x3f, 0xf5,
    0x89, 0x8f, 0x12, 0x63, 0xff, 0xf2, 0x61, 0x6a, 0x66, 0xb2, 0xcc, 0x01,
    0x75, 0xef, 0x54, 0xa4, 0xa7, 0x03, 0x49, 0xfd, 0x27, 0xf4, 0x85, 0x00,
    0x77, 0xe6, 0xd3,
};

const size_t kDERRSAPrivate2048Len = sizeof(kDERRSAPrivate2048);

const uint8_t kDERRSAPrivate3072[] = {
    0x30, 0x82, 0x06, 0xe4, 0x02, 0x01, 0x00, 0x02, 0x82, 0x01, 0x81, 0x00,
    0xbf, 0xde, 0x95, 0x71, 0xdf, 0x66, 0xbd, 0x7c, 0x2e, 0xd3, 0x81, 0x66,
    0xcc, 0xd1, 0x3b, 0xb2, 0x37, 0x31, 0x66, 0x34, 0x29, 0x4f, 0x23, 0x6e,
    0xa6, 0x5b, 0x54, 0x17, 0x15, 0xf8, 0x41, 0xc4, 0xeb, 0xb5, 0x26, 0xbd,
    0x20, 0x33, 0x62, 0x6d, 0x5e, 0x9e, 0xcd, 0x78, 0x7e, 0x78, 0xf9, 0xe6,
    0xea, 0xfe, 0x07, 0xa2, 0x7c, 0x39, 0x13, 0x15, 0x57, 0xb3, 0x3d, 0x67,
    0x3d, 0x84, 0x89, 0x07, 0x7c, 0x14, 0xde, 0xd0, 0xe3, 0x40, 0x1e, 0xe5,
    0xc5, 0x1a, 0xdd, 0x72, 0xe2, 0xd6, 0x66, 0x52, 0x0e, 0x4b, 0xfb, 0x22,
    0x20, 0x4e, 0x72, 0xce, 0x74, 0x4f, 0xbb, 0xbe, 0xb2, 0x22, 0xa6, 0x4c,
    0x3e, 0xf7, 0xcb, 0x0c, 0x6f, 0x81, 0x73, 0xcd, 0x4a, 0x2c, 0x3a, 0xe2,
    0x60, 0xc0, 0xe3, 0x85, 0xb7, 0x29, 0x21, 0x67, 0x58, 0x6f, 0x61, 0x68,
    0x63, 0x7b, 0x02, 0x41, 0xcd, 0xf9, 0x08, 0xfa, 0xa2, 0x3c, 0xaf, 0x33,
    0xed, 0x34, 0x89, 0x64, 0x7c, 0x3d, 0x2e, 0xf7, 0xaa, 0x99, 0x0d, 0xca,
    0xb5, 0x80, 0xa3, 0xee, 0x31, 0x88, 0x68, 0xd5, 0x06, 0x9f, 0x8d, 0x49,
    0x88, 0xa5, 0xee, 0x26, 0x43, 0xad, 0x01, 0x32, 0x1c, 0x5a, 0x66, 0x75,
    0xb0, 0x4e, 0xe2, 0x30, 0x5f, 0x71, 0x0e, 0x80, 0x51, 0x30, 0x91, 0xb1,
    0x8a, 0x22, 0xd7, 0x0d, 0x76, 0xa5, 0xcc, 0x66, 0x16, 0x75, 0x3d, 0x5f,
    0xb3, 0x48, 0x0a, 0x10, 0x4b, 0x7e, 0xcb, 0xca, 0x6c, 0x8b, 0x0f, 0xf9,
    0x7c, 0x63, 0xc0, 0x28, 0x8e, 0x76, 0x2f, 0x01, 0xb1, 0x35, 0x25, 0xab,
    0x88, 0x47, 0x80, 0xc0, 0xf2, 0x53, 0x84, 0xc1, 0x91, 0x7e, 0x2a, 0xcf,
    0xb9, 0x31, 0xa0, 0x75, 0x06, 0x2b, 0xfc, 0x77, 0x0e, 0xd3, 0x5b, 0x28,
    0x79, 0x76, 0xce, 0x76, 0xb3, 0x22, 0xa4, 0x87, 0x76, 0x65, 0x82, 0xe1,
    0xc0, 0x75, 0x0e, 0x46, 0x41, 0xf6, 0x3e, 0xcc, 0x92, 0x20, 0x37, 0xf2,
    0x0a, 0xf0, 0xf7, 0x86, 0xd2, 0x89, 0x2e, 0x88, 0x27, 0xb3, 0x39, 0xb8,
    0x26, 0xd0, 0x11, 0x46, 0x8a, 0x56, 0xea, 0xa5, 0xd8, 0xae, 0x83, 0xd6,
    0x79, 0xb8, 0xb8, 0xbf, 0x8d, 0x8f, 0x05, 0x7a, 0x58, 0x31, 0x8a, 0x7d,
    0xcc, 0x43, 0x3e, 0xa6, 0x39, 0xa3, 0x1d, 0xf6, 0x06, 0x87, 0x9c, 0xc2,
    0xa7, 0xd6, 0x17, 0xcf, 0x89, 0x28, 0x49, 0xa1, 0x43, 0xe0, 0xa4, 0xe0,
    0x64, 0x3d, 0x3c, 0xcb, 0xe2, 0x45, 0x4b, 0x30, 0xb9, 0xb7, 0x9a, 0x13,
    0x7c, 0x7e, 0x75, 0xd6, 0xad, 0x7a, 0xc8, 0x81, 0xcd, 0xf8, 0x96, 0x24,
    0x56, 0x07, 0xb2, 0x4a, 0x3c, 0x14, 0x49, 0xdf, 0xa0, 0x12, 0x2f, 0x02,
    0x19, 0x01, 0x74, 0x46, 0x93, 0x08, 0x5e, 0x68, 0xaf, 0x44, 0x36, 0x0f,
    0x5f, 0x6c, 0xfe, 0x94, 0xb0, 0x11, 0xb4, 0xcb, 0xbb, 0x36, 0xa9, 0x9b,
    0x02, 0x03, 0x01, 0x00, 0x01, 0x02, 0x82, 0x01, 0x80, 0x75, 0xe4, 0x01,
    0xd7, 0x31, 0xf9, 0x22, 0xbc, 0x46, 0xd9, 0x56, 0x4d, 0x1f, 0xd3, 0xff,
    0xe6, 0x04, 0xdb, 0xa9, 0x7c, 0xab, 0x55, 0x20, 0xe4, 0x3f, 0xfb, 0x25,
    0xb3, 0xf9, 0x9f, 0xcc, 0x69, 0x7e, 0x9a, 0x93, 0xee, 0xe8, 0xf6, 0x29,
    0xa8, 0x21, 0xd7, 0x59, 0x50, 0x8c, 0x05, 0x31, 0x27, 0x9d, 0x83, 0xf0,
    0x94, 0xf9, 0xd6, 0xe7, 0xce, 0xd9, 0x50, 0x1c, 0x8e, 0x6e, 0xd2, 0x1c,
    0x90, 0x28, 0xc1, 0x7a, 0x16, 0xc7, 0x4b, 0x02, 0xb1, 0x13, 0x66, 0xea,
    0x62, 0x48, 0xd6, 0x8b, 0x90, 0x27, 0x90, 0xb0, 0x01, 0xcb, 0xef, 0xe7,
    0xc2, 0xca, 0xdc, 0xa2, 0xf3, 0x0c, 0xe9, 0x15, 0x5d, 0x0b, 0xe3, 0x9d,
    0x33, 0x4a, 0xe0, 0x33, 0x93, 0x13, 0xdc, 0x11, 0x62, 0x3f, 0x28, 0xc5,
    0xa3, 0xc7, 0x62, 0xd2, 0x4f, 0x79, 0x9b, 0x16, 0x32, 0xd9, 0xcd, 0x1f,
    0x19, 0xe7, 0xc0, 0xf8, 0xaf, 0x67, 0x37, 0xfa, 0x3e, 0xe1, 0xa4, 0xc2,
    0x36, 0xa7, 0xcf, 0xc0, 0x28, 0x14, 0xfe, 0x6d, 0xe6, 0xfb, 0x96, 0xcb,
    0x22, 0xf3, 0xf4, 0x68, 0xd5, 0x5b, 0x78, 0x75, 0x8b, 0x95, 0x16, 0xbf,
    0x39, 0x6b, 0xa3, 0xc5, 0x74, 0x50, 0xcf, 0x8a, 0xdd, 0x0d, 0x33, 0xaa,
    0xef, 0x25, 0xf5, 0x85, 0x7f, 0x7a, 0x63, 0x69, 0x61, 0xb9, 0x0a, 0xa7,
    0x30, 0x72, 0x92, 0x75, 0x00, 0xd5, 0x13, 0xbc, 0x5d, 0x1c, 0x8b, 0xff,
    0xee, 0x77, 0xb3, 0x2c, 0x36, 0x54, 0x56, 0x3c, 0x97, 0x8d, 0x70, 0x21,
    0xa7, 0x76, 0xa6, 0xe2, 0x2e, 0x15, 0xe2, 0x02, 0x7b, 0x32, 0x70, 0xa0,
    0x88, 0x24, 0x14, 0x71, 0x30, 0xb2, 0xfd, 0x67, 0x2b, 0x67, 0x7f, 0x2c,
    0x3a, 0x4a, 0x48, 0xf1, 0x46, 0xc3, 0x28, 0xdd, 0x9e, 0x5c, 0x4c, 0x5d,
    0x5f, 0x51, 0x14, 0x07, 0x96, 0xed, 0xe5, 0x37, 0x97, 0x36, 0xd7, 0x8f,
    0xfd, 0x61, 0x94, 0xdb, 0x75, 0x8e, 0x99, 0xab, 0x2b, 0x18, 0xd5, 0x3b,
    0x84, 0x94, 0x5f, 0xfa, 0x35, 0xd1, 0x08, 0x33, 0x82, 0x38, 0x1a, 0xaa,
    0xdf, 0xf3, 0xd3, 0xa5, 0x6e, 0xc2, 0x22, 0xb6, 0x89, 0xc7, 0x6b, 0x11,
    0xa5, 0xba, 0xc9, 0xdc, 0xeb, 0xd5, 0x8d, 0x91, 0x04, 0xb3, 0x90, 0x7b,
    0xa5, 0x79, 0x40, 0x9c, 0x1e, 0x73, 0x15, 0xfc, 0xd7, 0x2c, 0xfd, 0x5f,
    0xde, 0x06, 0x7d, 0x56, 0x54, 0xfd, 0xf0, 0x1d, 0x72, 0x7c, 0xa9, 0xdd,
    0x5b, 0xad, 0x45, 0xd5, 0xaa, 0xfd, 0xc1, 0x0f, 0x7b, 0x54, 0x0f, 0xf5,
    0x94, 0x3a, 0xb2, 0x9e, 0x36, 0x96, 0xad, 0x5a, 0x22, 0x8b, 0xe5, 0xd7,
    0xee, 0xe6, 0xf3, 0x04, 0x0b, 0x41, 0x3f, 0x32, 0xe7, 0x54, 0x7b, 0x40,
    0x3a, 0x4a, 0x7c, 0xa4, 0x5d, 0x6f, 0xa7, 0xd4, 0x66, 0x02, 0xd5, 0x5b,
    0x53, 0xac, 0xbc, 0x2a, 0x66, 0x9c, 0xf4, 0xb2, 0xe1, 0x02, 0x81, 0xc1,
    0x00, 0xe3, 0x9d, 0xa2, 0x1a, 0x33, 0x60, 0x96, 0xf3, 0xda, 0x5d, 0xe3,
    0x6a, 0x13, 0xd8, 0xf9, 0xb7, 0xd5, 0x92, 0x99, 0x7e, 0x09, 0x1c, 0x67,
    0xb6, 0x17, 0x2d, 0xed, 0x07, 0xce, 0xf9, 0xba, 0xe2, 0xde, 0x09, 0x60,
    0xa4, 0x31, 0x5d, 0x15, 0x5b, 0x07, 0x88, 0xcf, 0x3b, 0x06, 0xc7, 0xfd,
    0x25, 0x1c, 0xc8, 0x40, 0xf8, 0xb7, 0x92, 0x17, 0xe3, 0xac, 0x84, 0xc9,
    0x73, 0x52, 0x2e, 0x68, 0x89, 0x0f, 0x56, 0xff, 0x53, 0xab, 0x63, 0xda,
    0x01, 0x10, 0x18, 0x8a, 0x71, 0x55, 0xa0, 0x7c, 0x72, 0x32, 0x65, 0x25,
    0x36, 0x07, 0x33, 0x7c, 0xd1, 0x01, 0x94, 0x7f, 0x84, 0xd0, 0xb5, 0xed,
    0x01, 0xfe, 0xed, 0x80, 0xa9, 0xdc, 0x36, 0x9a, 0xed, 0x4c, 0x5c, 0x9a,
    0x55, 0xc0, 0xb6, 0xc7, 0xe9, 0xa4, 0xf1, 0x3a, 0x1a, 0x7b, 0x17, 0xbb,
    0xdd, 0xc8, 0xd9, 0xe7, 0xfd, 0x4b, 0xf4, 0x34, 0xae, 0x7c, 0x2a, 0xcb,
    0x49, 0x26, 0x02, 0x50, 0xc3, 0x2c, 0xa1, 0x52, 0x27, 0x22, 0xd5, 0x45,
    0xcd, 0x98, 0x5d, 0xa1, 0x3b, 0xaa, 0x30, 0xb7, 0x54, 0x2b, 0xdb, 0x64,
    0x1a, 0x4d, 0x1a, 0x10, 0x23, 0xd7, 0xf3, 0xd2, 0xf4, 0x7b, 0xb8, 0x50,
    0xd6, 0x77, 0x48, 0xa8, 0xcc, 0x0f, 0xed, 0x35, 0xd7, 0x5c, 0x4e, 0x00,
    0x93, 0x4f, 0x6d, 0x20, 0xe0, 0x11, 0x0a, 0x17, 0x40, 0xc5, 0x44, 0xb5,
    0x9d, 0x02, 0x81, 0xc1, 0x00, 0xd7, 0xcb, 0xca, 0xca, 0x62, 0x0e, 0x91,
    0x57, 0x71, 0xe0, 0x92, 0xfa, 0xb5, 0x5d, 0xf2, 0xd1, 0x4d, 0x4e, 0x89,
    0x26, 0x3a, 0x50, 0xfd, 0x72, 0xe7, 0xdb, 0x7c, 0x04, 0x95, 0x79, 0xa4,
    0xcf, 0xcc, 0x50, 0x21, 0xc5, 0x1b, 0xc9, 0xf0, 0xe3, 0x13, 0x7e, 0x9c,
    0x97, 0xba, 0x55, 0x76, 0xd6, 0x5d, 0x66, 0xe8, 0x26, 0x97, 0x46, 0x3d,
    0x61, 0xdd, 0x95, 0xb9, 0x12, 0x96, 0xc4, 0x88, 0x0e, 0x82, 0xfd, 0xa9,
    0x58, 0x8a, 0xaf, 0x7d, 0x02, 0xee, 0xe4, 0x32, 0xa2, 0x98, 0xfa, 0xcf,
    0x7f, 0x16, 0xce, 0xf4, 0x39, 0x04, 0x0a, 0x50, 0xb2, 0xac, 0xdf, 0x3f,
    0x66, 0x74, 0xed, 0x78, 0xde, 0xeb, 0x36, 0x79, 0x75, 0x8f, 0x45, 0xb3,
    0xac, 0xfe, 0xda, 0x91, 0x30, 0x13, 0xc1, 0x42, 0xbe, 0xfd, 0xae, 0x38,
    0x30, 0x2d, 0xf4, 0x78, 0x10, 0xd3, 0xc4, 0x63, 0x86, 0x02, 0xf2, 0xbf,
    0x76, 0xef, 0xa7, 0x3b, 0x59, 0xe4, 0xb7, 0x35, 0x8a, 0x8f, 0xd7, 0xad,
    0x8e, 0x9d, 0x8b, 0xdc, 0x51, 0xaa, 0xfe, 0x0e, 0xc9, 0x8c, 0x1b, 0xa6,
    0xf9, 0xfa, 0xe3, 0xa4, 0xa0, 0x2f, 0x11, 0xf9, 0x30, 0xd9, 0x8c, 0x71,
    0xf1, 0xff, 0xf2, 0x16, 0xaf, 0x35, 0x60, 0x10, 0xfe, 0x4b, 0xee, 0x3b,
    0x4b, 0xcc, 0xa2, 0x6b, 0x00, 0x94, 0xc5, 0x84, 0x49, 0xd7, 0x82, 0x8c,
    0x35, 0x23, 0xcc, 0x92, 0x97, 0x02, 0x81, 0xc1, 0x00, 0x83, 0x9a, 0x2c,
    0x93, 0x81, 0x89, 0x23, 0x3e, 0x32, 0xcf, 0x7e, 0x21, 0x63, 0x00, 0x5c,
    0xc1, 0xd1, 0x96, 0x45, 0x70, 0xfd, 0xcb, 0x92, 0x9b, 0x51, 0xa3, 0x98,
    0x1c, 0x9f, 0xaa, 0xfc, 0x47, 0x17, 0xa1, 0xcc, 0x62, 0xa2, 0xb7, 0xf3,
    0x15, 0x02, 0xb2, 0x33, 0x3f, 0x29, 0x98, 0x8f, 0xe0, 0xd9, 0x57, 0x5f,
    0x59, 0x6e, 0xa9, 0xe5, 0x6e, 0x19, 0xdd, 0x5c, 0xac, 0x74, 0xa3, 0xa8,
    0x85, 0x36, 0x7d, 0x52, 0x7b, 0x09, 0xe9, 0x5d, 0xae, 0xa7, 0xa3, 0xc8,
    0xc7, 0xe6, 0x7e, 0x37, 0xf5, 0xbe, 0xf5, 0x84, 0x22, 0x4c, 0xdf, 0x94,
    0x17, 0x34, 0x16, 0xab, 0xf4, 0x1a, 0xc8, 0x55, 0x14, 0x86, 0x54, 0xc3,
    0xc3, 0x72, 0x33, 0x90, 0x38, 0x0b, 0xa2, 0xaf, 0x09, 0x4d, 0xb7, 0x60,
    0xb6, 0xd2, 0x4b, 0x37, 0x11, 0x00, 0x82, 0xa4, 0x78, 0x83, 0x1c, 0x9a,
    0x69, 0x75, 0x74, 0xe8, 0xd0, 0xc9, 0xb1, 0xe4, 0x7f, 0x92, 0x9e, 0x5c,
    0x1b, 0xbc, 0xbe, 0x39, 0x45, 0xaf, 0x7a, 0x28, 0x35, 0xcb, 0x16, 0xb7,
    0x96, 0x4b, 0xbc, 0x87, 0x02, 0xff, 0xa8, 0x85, 0xa4, 0x3f, 0x58, 0x06,
    0x64, 0xf3, 0x03, 0x62, 0xc1, 0x40, 0x97, 0x3d, 0x06, 0x03, 0x49, 0xdb,
    0x6e, 0xc0, 0xf6, 0xa1, 0xde, 0xb6, 0xdb, 0xd2, 0xb1, 0x59, 0x86, 0xfb,
    0x2f, 0x12, 0x2b, 0x07, 0x6e, 0xc7, 0xa0, 0x06, 0x71, 0x02, 0x81, 0xc1,
    0x00, 0x91, 0x84, 0x11, 0xe6, 0x71, 0x43, 0x03, 0x8d, 0x24, 0xf4, 0x5c,
    0x08, 0x85, 0x7e, 0xa9, 0xbb, 0xab, 0xd6, 0xb6, 0xb3, 0x39, 0x85, 0xdd,
    0xb2, 0xbb, 0x58, 0x8d, 0x03, 0x86, 0x4c, 0x35, 0xf0, 0x0e, 0x05, 0x47,
    0x10, 0x64, 0x91, 0xc3, 0x47, 0x4c, 0xa1, 0x07, 0x35, 0x65, 0x68, 0x36,
    0x2f, 0x8d, 0x62, 0x54, 0x4f, 0x99, 0x98, 0xba, 0xd1, 0xa0, 0x9b, 0x52,
    0xe6, 0x8f, 0x16, 0x4d, 0xed, 0x03, 0x35, 0xcc, 0x19, 0x31, 0xc3, 0xee,
    0x97, 0xa8, 0xc1, 0xe6, 0xc7, 0x30, 0x43, 0x88, 0xe2, 0x59, 0x5e, 0x0a,
    0xdf, 0xdb, 0xb2, 0x9d, 0x02, 0x2f, 0x82, 0x87, 0x7d, 0x2e, 0x81, 0xe8,
    0x0c, 0xe2, 0x2d, 0xa4, 0xaf, 0xba, 0x82, 0x35, 0x0c, 0x05, 0xfb, 0x1b,
    0x06, 0x81, 0x7b, 0xc3, 0xe7, 0x88, 0xa7, 0x0f, 0xaa, 0xa5, 0x82, 0x81,
    0xe8, 0x4e, 0xf4, 0xd2, 0x6b, 0xce, 0xd7, 0x24, 0x77, 0x2e, 0x59, 0xe5,
    0xb2, 0xd3, 0x81, 0x1b, 0xb0, 0xa9, 0x18, 0xb6, 0x27, 0x42, 0x63, 0xca,
    0x98, 0xa3, 0xa6, 0x98, 0x10, 0x1e, 0xd3, 0x92, 0xc0, 0x65, 0x07, 0x56,
    0xbe, 0xd1, 0x9e, 0xdc, 0x1b, 0xad, 0xc7, 0x80, 0x1a, 0xc1, 0x0d, 0xdd,
    0x70, 0x1e, 0x9c, 0xfe, 0x38, 0x8c, 0xb9, 0x43, 0xf0, 0xf4, 0x37, 0xdd,
    0xd1, 0xd1, 0x80, 0x73, 0x99, 0x5b, 0xa2, 0xe3, 0xaa, 0xfd, 0xcd, 0xf8,
    0x57, 0x02, 0x81, 0xc0, 0x0c, 0xb8, 0x9d, 0x9a, 0xc8, 0xf4, 0x5b, 0xff,
    0x3e, 0x28, 0x31, 0x78, 0x1c, 0x6e, 0x65, 0xdc, 0x6a, 0xae, 0x8c, 0x2e,
    0xec, 0x32, 0x3f, 0x3b, 0xf8, 0x49, 0x43, 0xb4, 0xd8, 0x0d, 0x8d, 0x46,
    0xe4, 0x7d, 0x04, 0xe6, 0xe2, 0xd2, 0x37, 0x79, 0x26, 0x26, 0xc6, 0xd5,
    0x7d, 0xa6, 0xe8, 0xea, 0xfd, 0x6f, 0x07, 0x5d, 0x54, 0xa6, 0x26, 0x6b,
    0xd8, 0x95, 0xdf, 0x38, 0x93, 0x51, 0x22, 0x14, 0x4f, 0x50, 0x01, 0x21,
    0x05, 0x05, 0xbb, 0xd0, 0xd5, 0x4f, 0x3b, 0x1d, 0x52, 0x00, 0xf1, 0xb4,
    0x97, 0x8d, 0x13, 0x74, 0x41, 0x6c, 0xd5, 0x9c, 0xa8, 0x50, 0x35, 0xa7,
    0x2b, 0xad, 0x9b, 0x54, 0x7c, 0x62, 0x74, 0x8d, 0x93, 0x14, 0x25, 0x3a,
    0xf4, 0xc3, 0xe2, 0xb0, 0xb2, 0x77, 0xfd, 0x73, 0x85, 0x2a, 0xa8, 0x46,
    0x8f, 0xa5, 0xee, 0xbc, 0xe1, 0xc6, 0xaa, 0x52, 0x44, 0xde, 0xbe, 0x91,
    0x4b, 0x44, 0x7b, 0x12, 0xb3, 0x17, 0x4e, 0xc4, 0x0b, 0x8b, 0xa8, 0xcd,
    0x01, 0xa9, 0xc9, 0x91, 0x2d, 0xae, 0x66, 0x62, 0xad, 0x06, 0x59, 0x61,
    0x14, 0xf2, 0xc3, 0xde, 0xd1, 0xf9, 0x2c, 0xb8, 0x70, 0x99, 0x36, 0xc8,
    0xc1, 0x87, 0xce, 0x82, 0x37, 0xff, 0x76, 0x30, 0x91, 0xee, 0x40, 0x6f,
    0xd4, 0xaf, 0xd4, 0x2f, 0xdf, 0x51, 0x7c, 0xe1, 0x1b, 0x59, 0xa1, 0x7a,
    0xa4, 0x58, 0x0a, 0x72,
};

const size_t kDERRSAPrivate3072Len = sizeof(kDERRSAPrivate3072);

const uint8_t kDERRSAPrivate4096[] = {
    0x30, 0x82, 0x09, 0x28, 0x02, 0x01, 0x00, 0x02, 0x82, 0x02, 0x01, 0x00,
    0xc3, 0x82, 0x01, 0xda, 0x03, 0xe1, 0x0d, 0x78, 0xf4, 0x86, 0xf1, 0x28,
    0xf0, 0x4c, 0x34, 0xa6, 0x73, 0x0c, 0xfb, 0x22, 0xfa, 0x35, 0xc9, 0x3a,
    0x4c, 0xf1, 0x15, 0xfe, 0x96, 0x4a, 0x64, 0x75, 0xfe, 0x62, 0x5c, 0x77,
    0x76, 0x12, 0x9a, 0x68, 0x63, 0x09, 0x4d, 0x6f, 0x4a, 0xec, 0xc7, 0xac,
    0x17, 0x60, 0x5e, 0xfa, 0xd8, 0xe0, 0xca, 0x3d, 0xfd, 0x0b, 0x5a, 0x88,
    0x4c, 0xe6, 0xbd, 0x99, 0x34, 0x9e, 0x06, 0xc5, 0xf8, 0x33, 0xad, 0x5d,
    0x8d, 0x73, 0x5d, 0x1c, 0xc2, 0xb3, 0xcd, 0x47, 0x2f, 0x41, 0x04, 0xe8,
    0x71, 0x6d, 0xd9, 0x19, 0xf4, 0x56, 0xb8, 0xcf, 0x0f, 0x92, 0x13, 0xb4,
    0x1c, 0x6a, 0x51, 0x4e, 0xdd, 0xd0, 0xc0, 0x20, 0x3f, 0xd9, 0x32, 0x92,
    0xe2, 0xbd, 0x66, 0x33, 0x4b, 0x44, 0xbf, 0xd8, 0x28, 0x3d, 0x51, 0x00,
    0xe3, 0xf8, 0x3b, 0x6c, 0x55, 0x22, 0x71, 0xee, 0xa7, 0x3c, 0xe4, 0x36,
    0xa2, 0xcf, 0x41, 0xeb, 0x64, 0x79, 0xbb, 0x75, 0xe8, 0xc5, 0x29, 0xe1,
    0xa5, 0xd2, 0xf6, 0x84, 0x2c, 0x0e, 0x0c, 0x0f, 0xc2, 0x42, 0xfd, 0xa9,
    0xdb, 0x8f, 0x44, 0xa0, 0xfc, 0xf3, 0x26, 0xd8, 0x6a, 0xc2, 0x14, 0x2d,
    0x3c, 0x09, 0x68, 0x98, 0x67, 0x0e, 0x01, 0xd4, 0x80, 0x02, 0x5c, 0xc0,
    0xb9, 0xd3, 0x12, 0x2e, 0xaa, 0x3c, 0xab, 0x56, 0x8c, 0x96, 0xb3, 0x25,
    0xeb, 0xa7, 0x86, 0xd8, 0xbe, 0x70, 0x01, 0xe9, 0xa7, 0x7b, 0x27, 0x01,
    0xbe, 0x4c, 0x23, 0xf4, 0x19, 0x17, 0x6e, 0x31, 0x69, 0xab, 0x1a, 0x6a,
    0x1f, 0x57, 0xde, 0x9a, 0x8e, 0x1d, 0xfd, 0xd9, 0x5d, 0xce, 0xa0, 0x47,
    0x19, 0x8d, 0x27, 0x33, 0x77, 0xe2, 0xa4, 0x1d, 0x72, 0x72, 0xe6, 0xec,
    0xf3, 0xad, 0x85, 0x50, 0xc0, 0x94, 0xab, 0x78, 0x03, 0x67, 0x1e, 0x48,
    0x45, 0x50, 0x41, 0x7d, 0xb5, 0x62, 0x28, 0x80, 0x41, 0x89, 0xac, 0x99,
    0xe2, 0xd7, 0xe1, 0xc2, 0x54, 0xfc, 0xff, 0xa7, 0xc0, 0x71, 0xc6, 0xd7,
    0xae, 0x05, 0xf2, 0xbc, 0x2a, 0xe8, 0x43, 0x88, 0x4a, 0x0c, 0xb2, 0x61,
    0x2e, 0x9b, 0xac, 0x48, 0x90, 0xaa, 0x7b, 0x24, 0x9b, 0xc2, 0xc5, 0x48,
    0x95, 0x8d, 0x4f, 0x92, 0x6a, 0xb7, 0xcc, 0xb5, 0x9f, 0x06, 0xe4, 0x05,
    0xac, 0x05, 0x81, 0x66, 0xb0, 0x24, 0x04, 0x12, 0xac, 0xac, 0x9a, 0x1e,
    0xea, 0xce, 0x82, 0xfb, 0x27, 0x2e, 0xa1, 0x5e, 0xb8, 0x86, 0x74, 0x1a,
    0x3a, 0xdd, 0x8c, 0x98, 0x3c, 0x23, 0x2b, 0xea, 0x8a, 0xd0, 0x92, 0x43,
    0xbb, 0xec, 0xb3, 0x27, 0x52, 0x2c, 0x7f, 0x07, 0x33, 0xe5, 0x21, 0xa3,
    0xda, 0x4e, 0x65, 0xd2, 0x96, 0xb5, 0x88, 0xcb, 0x9f, 0x0c, 0x21, 0x41,
    0x80, 0x02, 0xb2, 0x9e, 0x78, 0x60, 0x40, 0x18, 0x21, 0x52, 0x4f, 0x09,
    0x5f, 0x75, 0x8b, 0xf3, 0x71, 0x70, 0xab, 0x94, 0x3b, 0xd1, 0xe8, 0x65,
    0x55, 0xf2, 0x76, 0xe3, 0x7c, 0x1d, 0x3a, 0x7c, 0x44, 0xbf, 0xb4, 0x10,
    0x2e, 0x16, 0x7f, 0xdc, 0xd2, 0x37, 0xf3, 0x48, 0x68, 0x80, 0xa9, 0x9d,
    0x56, 0xff, 0x63, 0xed, 0x29, 0x79, 0x39, 0xfa, 0x92, 0x65, 0x22, 0xee,
    0x5c, 0x2a, 0xa9, 0xef, 0x30, 0x82, 0x10, 0xae, 0x46, 0xe2, 0x52, 0xa5,
    0x2e, 0x23, 0xe6, 0x65, 0xb5, 0x54, 0xd8, 0xa1, 0xe8, 0x9c, 0xf1, 0xe3,
    0xf5, 0xc8, 0x4b, 0x54, 0xac, 0x02, 0x4d, 0xdf, 0x01, 0xc2, 0xc7, 0x82,
    0x30, 0x0d, 0x86, 0x17, 0x64, 0x99, 0x7b, 0xfa, 0x46, 0x23, 0x19, 0x6b,
    0x7c, 0x01, 0x61, 0x22, 0xa6, 0x28, 0x17, 0x48, 0xa4, 0x6a, 0x32, 0x00,
    0x16, 0x23, 0x40, 0x0b, 0x51, 0xd7, 0xc7, 0x91, 0x60, 0xd7, 0x32, 0x91,
    0xf5, 0xf7, 0x3c, 0x24, 0xc0, 0x9f, 0x4a, 0xf3, 0x02, 0x03, 0x01, 0x00,
    0x01, 0x02, 0x82, 0x02, 0x00, 0x6b, 0x3d, 0x28, 0x9e, 0xd9, 0x79, 0xdc,
    0xd5, 0xf7, 0xea, 0xfc, 0xe5, 0x23, 0xc9, 0xe9, 0x27, 0x53, 0xfc, 0x4e,
    0xd4, 0xc4, 0xc2, 0x33, 0xfa, 0x92, 0xb1, 0xbb, 0x0a, 0xc6, 0x8d, 0x4f,
    0xc5, 0x99, 0x1f, 0x82, 0xf0, 0xd4, 0x07, 0x28, 0x43, 0x11, 0xef, 0xcc,
    0x55, 0xbb, 0x97, 0x5d, 0x7e, 0xfb, 0xe3, 0x94, 0xb5, 0xab, 0xb8, 0xc1,
    0xb6, 0x76, 0xd2, 0x7f, 0x7a, 0x3c, 0x14, 0x64, 0xf3, 0x60, 0x75, 0x3d,
    0xe9, 0xe1, 0x57, 0x17, 0x45, 0x35, 0x8d, 0x8e, 0x09, 0x74, 0x93, 0x03,
    0x8a, 0x84, 0x54, 0xf9, 0xc8, 0x36, 0x4f, 0xb6, 0xc2, 0x11, 0xd0, 0x6f,
    0xd6, 0xc4, 0x07, 0xb0, 0x5f, 0x1f, 0x27, 0x02, 0x2a, 0x6c, 0x69, 0x50,
    0xb9, 0x5f, 0xcc, 0x57, 0x7d, 0x52, 0x79, 0xe9, 0x51, 0x41, 0x7c, 0x18,
    0x6f, 0x0c, 0xc3, 0x75, 0x67, 0x33, 0xa4, 0xb9, 0x93, 0x96, 0xaf, 0x2a,
    0x27, 0x69, 0xfc, 0x70, 0x81, 0xb7, 0x94, 0x4f, 0xe8, 0x3a, 0x58, 0xbb,
    0x86, 0xd5, 0x83, 0x30, 0x91, 0xe1, 0x4f, 0x72, 0x80, 0xd5, 0x59, 0x6f,
    0x2c, 0x45, 0xb6, 0x51, 0x45, 0x96, 0x75, 0x63, 0x83, 0x9a, 0xbc, 0x15,
    0x16, 0xa8, 0x98, 0x84, 0x50, 0xbb, 0x99, 0xbd, 0x91, 0xbb, 0x15, 0x67,
    0xd3, 0x93, 0xd3, 0xb7, 0xe4, 0xcf, 0x09, 0x03, 0xf4, 0x2c, 0xd4, 0xd2,
    0x76, 0xca, 0xee, 0xee, 0x9d, 0x62, 0x41, 0xa6, 0x29, 0xc5, 0x6b, 0xd2,
    0xe0, 0xc3, 0x49, 0x3e, 0x00, 0x2a, 0xcd, 0xc0, 0xfa, 0xe7, 0xb8, 0x7e,
    0x6d, 0x04, 0x35, 0x22, 0x6c, 0x0b, 0x7d, 0x3b, 0x51, 0x33, 0x9b, 0x27,
    0xde, 0xcf, 0x21, 0xc3, 0xb0, 0xbc, 0x47, 0x3c, 0xb5, 0x72, 0x91, 0x12,
    0xcc, 0x44, 0x36, 0xda, 0x8c, 0x26, 0xad, 0x8b, 0x6e, 0xdb, 0xf3, 0xb0,
    0x8a, 0x47, 0xf3, 0x8c, 0x1c, 0xc0, 0x48, 0x61, 0x63, 0x09, 0x48, 0x08,
    0x4f, 0x3b, 0xb4, 0x90, 0xf7, 0x4b, 0xd7, 0x58, 0x88, 0xfe, 0x3d, 0xe4,
    0x9d, 0xf2, 0xec, 0xf4, 0x6d, 0x70, 0x2c, 0x0f, 0x55, 0x61, 0xdb, 0x62,
    0x3d, 0x75, 0x19, 0x4b, 0x24, 0x02, 0xe3, 0xbd, 0x01, 0xd8, 0xe4, 0x05,
    0x85, 0xda, 0x19, 0xc5, 0x91, 0xda, 0x09, 0xf6, 0xd0, 0xff, 0x7d, 0xae,
    0x68, 0x86, 0x17, 0xac, 0xf7, 0xb9, 0xde, 0xe7, 0x3f, 0x1e, 0xb5, 0x7e,
    0xcd, 0x64, 0xf2, 0x48, 0x61, 0x86, 0x4b, 0x21, 0x5b, 0xe2, 0x3b, 0x69,
    0xfc, 0xeb, 0x17, 0x25, 0x97, 0x6d, 0x6f, 0xd9, 0x7e, 0xce, 0x31, 0xb7,
    0xad, 0x2c, 0xb0, 0x31, 0xaf, 0x89, 0x2d, 0x8d, 0x30, 0x2a, 0x45, 0x69,
    0x0c, 0x8e, 0x96, 0xfa, 0x00, 0xcb, 0x47, 0x32, 0x3c, 0x40, 0xe5, 0x75,
    0xe3, 0xa9, 0x4f, 0xd4, 0xa8, 0x33, 0x76, 0x59, 0xea, 0xbe, 0x09, 0xae,
    0x2c, 0x27, 0x9e, 0x1f, 0xc2, 0xdd, 0x90, 0x38, 0xe6, 0xb8, 0x49, 0x1f,
    0x17, 0x5a, 0x01, 0xa2, 0x73, 0xaa, 0x92, 0xb6, 0xed, 0x26, 0xd7, 0x0d,
    0xa0, 0x39, 0x42, 0xdb, 0xc1, 0xf6, 0xe3, 0x0b, 0x11, 0x4c, 0x3e, 0x40,
    0xba, 0x2a, 0x42, 0xa9, 0x5b, 0x74, 0x0a, 0xcd, 0x0c, 0xae, 0x13, 0x27,
    0x6b, 0x37, 0xfa, 0xdd, 0x08, 0x89, 0xb4, 0xc2, 0x11, 0xda, 0xb2, 0x8d,
    0x44, 0x59, 0x1f, 0x19, 0x1a, 0x7d, 0x0b, 0x70, 0x62, 0x00, 0x8a, 0x4a,
    0x2e, 0xda, 0x44, 0xc6, 0xc6, 0xf9, 0xe6, 0x14, 0xdc, 0xe1, 0x9e, 0xb6,
    0x8e, 0xcf, 0x0d, 0xa2, 0xf4, 0x64, 0x8c, 0x71, 0x4e, 0x0a, 0xf6, 0xa8,
    0xca, 0x2d, 0xe0, 0xd2, 0x5f, 0x78, 0xee, 0x3d, 0x77, 0x13, 0xba, 0x61,
    0xac, 0xe3, 0x0f, 0xb0, 0x5f, 0xd3, 0x28, 0x12, 0x5d, 0xa6, 0xe9, 0x38,
    0xfa, 0x6e, 0xe7, 0xdf, 0xee, 0x65, 0x98, 0x97, 0x48, 0xb7, 0xa9, 0x73,
    0x21, 0x02, 0x82, 0x01, 0x01, 0x00, 0xe7, 0x1b, 0x4c, 0x5c, 0xcc, 0xb7,
    0xae, 0x4b, 0xe8, 0x7d, 0x19, 0xc0, 0x53, 0xc7, 0x17, 0x86, 0xac, 0xef,
    0x79, 0x94, 0x61, 0xc3, 0x17, 0x17, 0xb6, 0x5f, 0x08, 0x7c, 0xc7, 0x96,
    0xf3, 0x69, 0xc4, 0x2b, 0x90, 0xae, 0x35, 0x57, 0x2c, 0x73, 0x10, 0xaa,
    0x59, 0x69, 0x42, 0x21, 0xa3, 0x29, 0x94, 0x35, 0x3c, 0x12, 0x9e, 0xa0,
    0x08, 0x28, 0xad, 0x34, 0x3d, 0x07, 0x23, 0x6d, 0xb8, 0xfa, 0x48, 0x4e,
    0x1a, 0x4b, 0xeb, 0x4c, 0x91, 0xf2, 0xa0, 0x83, 0x75, 0x8c, 0x82, 0x4e,
    0xea, 0x75, 0xfb, 0x39, 0x9e, 0x81, 0xe9, 0xac, 0x8f, 0x1f, 0x7c, 0x59,
    0x4f, 0x8e, 0x99, 0x81, 0x2e, 0xea, 0xb7, 0x77, 0x16, 0xf4, 0xea, 0x9e,
    0x4a, 0x44, 0xa0, 0x5b, 0xc6, 0x22, 0x82, 0xa3, 0x54, 0x1f, 0x9e, 0x07,
    0xfb, 0x8e, 0x92, 0xd0, 0x31, 0x5e, 0x68, 0x26, 0xdf, 0x18, 0xc3, 0x85,
    0xba, 0x43, 0xcb, 0xae, 0x3d, 0x31, 0x03, 0xc6, 0x20, 0xfd, 0x11, 0xb1,
    0x62, 0xdc, 0xa0, 0xb4, 0xef, 0x21, 0x8c, 0x1d, 0x95, 0xfa, 0xf1, 0x79,
    0xba, 0x97, 0x43, 0xf7, 0x45, 0x39, 0x05, 0x54, 0xbf, 0x49, 0xab, 0x99,
    0x00, 0x6a, 0x06, 0x84, 0x9c, 0xb6, 0xf0, 0xdc, 0x46, 0x8e, 0x1c, 0x66,
    0xec, 0x4a, 0xae, 0xc3, 0xba, 0xfb, 0x1b, 0xe7, 0xef, 0x0b, 0xb6, 0xe5,
    0xd7, 0xf1, 0x6c, 0x82, 0xd8, 0xdc, 0xa3, 0xc2, 0x02, 0x17, 0x53, 0xe0,
    0xa0, 0x84, 0x4e, 0xad, 0x4a, 0x9b, 0x07, 0x87, 0x1a, 0x59, 0x21, 0xba,
    0xa0, 0x9b, 0x8f, 0x27, 0xa0, 0x93, 0xf7, 0x51, 0xad, 0x62, 0xc0, 0x6f,
    0x00, 0x37, 0x16, 0x70, 0xa6, 0x30, 0xb7, 0xa9, 0x7b, 0x7f, 0x53, 0x9d,
    0x54, 0x93, 0xba, 0x1f, 0xe1, 0x35, 0x4a, 0x88, 0x45, 0x34, 0x95, 0x24,
    0x64, 0x9a, 0xa5, 0x61, 0x7c, 0xed, 0x83, 0x38, 0xfb, 0x45, 0x02, 0x82,
    0x01, 0x01, 0x00, 0xd8, 0x91, 0x15, 0x00, 0x3f, 0x7f, 0x27, 0x0a, 0x3b,
    0xc4, 0x67, 0x36, 0x1d, 0x13, 0xd1, 0x50, 0x39, 0x1e, 0x26, 0xad, 0x25,
    0x65, 0x6a, 0x1d, 0xf7, 0x5d, 0x6b, 0x4b, 0x26, 0xb0, 0x32, 0x5a, 0x30,
    0x78, 0xb6, 0x11, 0xab, 0x5b, 0x4b, 0x6e, 0xcd, 0xe5, 0x93, 0xb2, 0xa9,
    0xca, 0x4b, 0xe8, 0x61, 0x45, 0xd1, 0xf7, 0x8b, 0x11, 0x77, 0x3a, 0x59,
    0xd6, 0xb3, 0x2a, 0xf3, 0x8a, 0x6a, 0x2e, 0x53, 0xe8, 0x21, 0xda, 0x03,
    0xd5, 0x2d, 0xcc, 0xd2, 0xba, 0xec, 0x11, 0x69, 0xe3, 0xab, 0xd5, 0x9e,
    0xfc, 0x9c, 0xff, 0x90, 0x79, 0x05, 0x3a, 0xb0, 0x5e, 0x43, 0x05, 0xd7,
    0x9b, 0xec, 0xda, 0x22, 0x2c, 0xc4, 0x18, 0x28, 0x26, 0xbb, 0xdb, 0x45,
    0xa0, 0x7d, 0x32, 0x17, 0xc3, 0x14, 0xd8, 0x72, 0x7a, 0x59, 0x33, 0x5e,
    0x02, 0xb2, 0x3c, 0xd8, 0x46, 0x82, 0x5e, 0x9c, 0x06, 0x20, 0x5f, 0x63,
    0xd8, 0x02, 0xda, 0x59, 0x0b, 0x32, 0x89, 0xc4, 0xbd, 0x63, 0x74, 0xbb,
    0x76, 0x34, 0xb9, 0x18, 0x29, 0x6d, 0x79, 0xe6, 0x02, 0x57, 0xab, 0x16,
    0x5a, 0x59, 0xea, 0x22, 0xdc, 0x37, 0x9c, 0x19, 0x7a, 0x2a, 0x40, 0xeb,
    0xa7, 0x2d, 0xef, 0x3d, 0xc5, 0x29, 0x71, 0xa6, 0x4a, 0x2d, 0x62, 0xc4,
    0x85, 0xed, 0x65, 0x88, 0x7a, 0x83, 0x3c, 0x06, 0x9a, 0xac, 0x24, 0x50,
    0xed, 0x27, 0xfc, 0xff, 0x98, 0xdb, 0x8b, 0xf1, 0xf1, 0x6f, 0xa0, 0x89,
    0xc1, 0xfe, 0x82, 0xbb, 0xab, 0xe1, 0xc2, 0x2a, 0xea, 0xd3, 0x73, 0xbf,
    0xe9, 0xb3, 0x4d, 0xd7, 0xf4, 0x3b, 0x66, 0x9f, 0x3b, 0xd4, 0x9b, 0xf9,
    0xad, 0xa0, 0x45, 0xed, 0x58, 0x41, 0xc6, 0xf2, 0x32, 0x0c, 0xbd, 0xc6,
    0x4b, 0x2b, 0xfa, 0x1c, 0x57, 0x49, 0x5d, 0x82, 0x37, 0xba, 0x02, 0x8e,
    0x43, 0x72, 0x1f, 0xdc, 0x55, 0x74, 0xd7, 0x02, 0x82, 0x01, 0x01, 0x00,
    0xc0, 0xcc, 0xc3, 0x4d, 0xff, 0xf3, 0x94, 0xd2, 0xfa, 0xe7, 0xb2, 0xde,
    0x02, 0x86, 0x6b, 0x98, 0x0d, 0x19, 0xd3, 0xa1, 0xf8, 0x55, 0x1b, 0x24,
    0xcb, 0x1e, 0x49, 0x24, 0x60, 0x16, 0x0c, 0x87, 0xc6, 0x02, 0x5a, 0x37,
    0x1b, 0x84, 0xd8, 0x2e, 0x3e, 0x4e, 0xff, 0x3c, 0x92, 0xd1, 0x21, 0x1f,
    0x84, 0xe7, 0x4c, 0x70, 0x74, 0x29, 0x29, 0xe5, 0x55, 0x69, 0xe9, 0x27,
    0xd5, 0x64, 0xaa, 0x17, 0x12, 0xcf, 0x25, 0x9d, 0x04, 0x75, 0xe2, 0xa4,
    0x39, 0x48, 0xb2, 0x7e, 0x40, 0x0f, 0xba, 0x06, 0x27, 0x4a, 0x10, 0x74,
    0x6d, 0x0f, 0x6a, 0x6f, 0x67, 0xfb, 0xd2, 0x25, 0x32, 0xe6, 0xd4, 0xcf,
    0x37, 0xb3, 0x80, 0x51, 0x5e, 0x92, 0x23, 0x7f, 0x51, 0x10, 0x7f, 0x21,
    0x37, 0x3f, 0x2e, 0xe5, 0x19, 0x9f, 0xab, 0x3b, 0x6c, 0x3b, 0x87, 0x94,
    0x2c, 0xeb, 0x90, 0xdf, 0x45, 0xee, 0x80, 0x50, 0x22, 0xd1, 0xff, 0x76,
    0xae, 0xa1, 0x51, 0xd0, 0x0e, 0x3c, 0xa0, 0x2f, 0x53, 0x5a, 0xde, 0xcc,
    0x6b, 0xea, 0x1a, 0xbf, 0x39, 0x48, 0xc6, 0x63, 0x7f, 0x6e, 0x00, 0x2f,
    0xeb, 0xc4, 0xa1, 0xb8, 0xc2, 0x11, 0x68, 0x89, 0x0b, 0x5b, 0x02, 0xaa,
    0x94, 0x12, 0x10, 0x42, 0x6a, 0x6b, 0x6a, 0xe1, 0x7b, 0x1f, 0x0b, 0x14,
    0x86, 0x59, 0x5d, 0xd1, 0xb6, 0x09, 0xd5, 0xb7, 0x31, 0x41, 0x8f, 0xcd,
    0xb2, 0x48, 0x1e, 0x1a, 0x7b, 0xfd, 0x3f, 0xac, 0x61, 0x3e, 0xac, 0xa8,
    0xdd, 0x04, 0xd6, 0xf4, 0x58, 0xf1, 0x2b, 0x1f, 0xdb, 0xb3, 0xc1, 0x80,
    0xef, 0xa9, 0x12, 0x2e, 0xfa, 0x3f, 0x20, 0x3c, 0xd4, 0xd9, 0xb1, 0xab,
    0x9e, 0xed, 0x23, 0x7c, 0x3b, 0xb3, 0x5b, 0x65, 0xca, 0xb6, 0xe1, 0xd8,
    0xe5, 0x8e, 0xfd, 0xbd, 0x3a, 0x57, 0x1c, 0x1e, 0xef, 0xad, 0x7e, 0xdd,
    0x5e, 0xc5, 0xe0, 0xc9, 0x02, 0x82, 0x01, 0x00, 0x28, 0x3d, 0xfd, 0x5b,
    0x08, 0x71, 0x86, 0x3d, 0x9e, 0x91, 0x86, 0x64, 0x45, 0xce, 0xf2, 0xec,
    0x27, 0x50, 0xf4, 0xfa, 0xe3, 0xa2, 0x0e, 0xaf, 0xf6, 0xd1, 0x43, 0x28,
    0xb9, 0xcd, 0xaf, 0xed, 0x96, 0x68, 0x37, 0xdc, 0xdc, 0xac, 0xa0, 0x3d,
    0xbc, 0xc0, 0xd6, 0x4b, 0x32, 0xc5, 0xc6, 0x89, 0x2d, 0xda, 0x1d, 0x84,
    0x14, 0x31, 0x70, 0xa8, 0x45, 0x1d, 0x62, 0x39, 0xae, 0xfb, 0x9f, 0x73,
    0x70, 0x60, 0x08, 0x3a, 0x4c, 0xd0, 0x06, 0x2c, 0xb3, 0x53, 0xcc, 0x9e,
    0x07, 0xc1, 0x28, 0xa3, 0x0f, 0x61, 0xfd, 0x82, 0x77, 0xc4, 0x25, 0x36,
    0x9c, 0xa3, 0x47, 0x6d, 0x04, 0x7d, 0x92, 0xeb, 0x8d, 0xc2, 0x27, 0xc6,
    0x1d, 0x5f, 0xe5, 0x34, 0x7f, 0xa1, 0xac, 0xe1, 0xec, 0x0c, 0x72, 0x09,
    0x2e, 0x6c, 0x91, 0xba, 0xbb, 0xd3, 0x60, 0x6f, 0x71, 0xf8, 0xd8, 0x2c,
    0xe0, 0x6d, 0x3b, 0x02, 0xbe, 0xb8, 0xda, 0xfe, 0xdb, 0xe0, 0xfa, 0xc9,
    0x22, 0xe7, 0xd6, 0x5d, 0x50, 0xa0, 0x4c, 0x77, 0xc0, 0x87, 0xa2, 0x32,
    0x2e, 0x8d, 0x6c, 0xe0, 0xfb, 0xcc, 0x5a, 0x3c, 0xe9, 0xb1, 0x66, 0x1b,
    0xf9, 0x97, 0xfb, 0xd6, 0x08, 0x74, 0x0e, 0x53, 0x10, 0x75, 0x5c, 0x98,
    0x23, 0xc0, 0x50, 0xe2, 0xb3, 0x85, 0xf7, 0x71, 0x10, 0x85, 0x43, 0x71,
    0x9a, 0x00, 0x8f, 0xd0, 0x47, 0xc1, 0x69, 0xd6, 0xd7, 0x5f, 0xfe, 0x1b,
    0xe9, 0x1f, 0x66, 0x10, 0xbc, 0xc8, 0x71, 0x94, 0xb5, 0x6e, 0xe1, 0x0a,
    0x85, 0x93, 0x11, 0x2b, 0xc7, 0x13, 0x94, 0x1f, 0xf8, 0xeb, 0x07, 0x46,
    0xb0, 0x7c, 0x1b, 0xab, 0xc8, 0x1f, 0x7d, 0x52, 0xc1, 0x21, 0xcf, 0x47,
    0x3a, 0xa6, 0x16, 0x3c, 0x05, 0x66, 0xde, 0x8b, 0x21, 0x4d, 0x0e, 0xf2,
    0xf3, 0x49, 0x8b, 0xa5, 0x01, 0xee, 0x82, 0x7c, 0x6d, 0x22, 0xec, 0x0d,
    0x02, 0x82, 0x01, 0x00, 0x39, 0x88, 0xc7, 0x5d, 0x9c, 0x8b, 0xbc, 0xa1,
    0x33, 0xe4, 0x93, 0x24, 0x91, 0x3c, 0xfb, 0x35, 0xf5, 0xaf, 0x61, 0xa3,
    0x06, 0x0e, 0xf5, 0x28, 0x9e, 0x95, 0x21, 0xd8, 0xa3, 0xea, 0x77, 0xc0,
    0x70, 0x28, 0x3f, 0xff, 0x4e, 0x6b, 0x8c, 0x01, 0x83, 0x43, 0xcd, 0x71,
    0xb4, 0xe3, 0xcc, 0xa7, 0x1e, 0xff, 0xbe, 0xf4, 0x78, 0xdc, 0x67, 0xf5,
    0xe9, 0x3d, 0x6d, 0x06, 0x29, 0x53, 0xd5, 0x20, 0x99, 0x4b, 0x03, 0xab,
    0x41, 0x48, 0xe7, 0x13, 0x28, 0x1f, 0x0f, 0x96, 0xea, 0x44, 0x12, 0x6b,
    0x0d, 0x67, 0xfc, 0x3b, 0x7b, 0xbc, 0x2a, 0x2d, 0x2a, 0x8b, 0x31, 0xa5,
    0x81, 0xc8, 0xf4, 0x4d, 0xd2, 0x9f, 0xbf, 0x49, 0x11, 0xd6, 0x05, 0x2b,
    0x68, 0x8f, 0x5a, 0x40, 0x98, 0x0a, 0x3f, 0x3f, 0xd5, 0xae, 0x96, 0x46,
    0xae, 0xd0, 0x66, 0x80, 0xe4, 0x3c, 0x2e, 0x34, 0xde, 0x7d, 0xbc, 0x30,
    0x95, 0xa2, 0x6a, 0x94, 0x4e, 0xa5, 0x4c, 0x55, 0x37, 0xca, 0x0d, 0x70,
    0x6b, 0xae, 0xde, 0x1e, 0xa2, 0xcd, 0x6a, 0xdf, 0xda, 0xa1, 0xa1, 0xd8,
    0xec, 0xd3, 0x9d, 0xde, 0x07, 0xc1, 0xa0, 0xb7, 0xab, 0x52, 0xe4, 0xc8,
    0x3c, 0x1b, 0x55, 0xae, 0xb7, 0x84, 0x9b, 0xd6, 0x90, 0x13, 0x49, 0xed,
    0x65, 0x88, 0x4b, 0x3c, 0x94, 0x55, 0xc8, 0x86, 0x87, 0x5a, 0x0b, 0xa5,
    0x7c, 0x20, 0xec, 0xc5, 0x48, 0x9e, 0xb2, 0x6c, 0x0e, 0x0c, 0xf2, 0x4d,
    0xea, 0x1a, 0x44, 0x8e, 0x66, 0xaa, 0x6e, 0x6c, 0x9a, 0xea, 0x18, 0x02,
    0x7c, 0xaf, 0xf0, 0x5e, 0x63, 0xb7, 0xe2, 0xb1, 0x8e, 0x99, 0x99, 0x32,
    0xa5, 0x0f, 0x0f, 0x35, 0x88, 0x6d, 0xf6, 0xc5, 0x5c, 0x75, 0x70, 0x7f,
    0xab, 0x78, 0xa3, 0x15, 0x43, 0x08, 0x88, 0x58, 0x9d, 0xbb, 0x63, 0xf7,
    0x59, 0x8e, 0xd7, 0x45, 0x87, 0x86, 0x05, 0x9d,
};

const size_t kDERRSAPrivate4096Len = sizeof(kDERRSAPrivate4096);
