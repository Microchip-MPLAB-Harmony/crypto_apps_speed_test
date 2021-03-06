/* cryptoSTD_sha384_sha512

  Crypto Speed Test Data File

  Company:
    Microchip Technology Inc.

  Description:
  This package conditionally provides standard test cases
  for SHA384 and SHA512 encryption.
*/

//DOM-IGNORE-BEGIN
/*****************************************************************************
 Copyright (C) 2013-2020 Microchip Technology Inc. and its subsidiaries.

Microchip Technology Inc. and its subsidiaries.

Subject to your compliance with these terms, you may use Microchip software 
and any derivatives exclusively with Microchip products. It is your 
responsibility to comply with third party license terms applicable to your 
use of third party software (including open source software) that may 
accompany Microchip software.

THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR 
PURPOSE.

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE 
FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN 
ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, 
THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*****************************************************************************/

//DOM-IGNORE-END

#include <stdint.h>
#include "./cryptoSpeedTestData.h"
#include "cryptoST/cryptoSTE_generate.h"
#include "cryptoST/cryptoSTE_print.h"
#include "app.h" // for BASE_LINE

#if !defined(NO_SHA)        \
 || !defined(NO_SHA256)     \
 || defined(WOLFSSL_SHA224) \
 || defined(WOLFSSL_SHA384) \
 || defined(WOLFSSL_SHA512)

#define CONST /* as nothing */
#define DATA_PACKAGE_NAME "SHA_NIST"

/* For SAML11 devices, the built-in encryption routines require
 * that all data be int32-aligned. This macro is applied so that 
 * const data will be correctly positioned. 
 */
#define ALIGN4 __attribute__((aligned(4)))

/*************************************************************
 * Raw (input) data definitions.
 *************************************************************/
static const CPU_CHAR sha_all[] = 
    "http://csrc.nist.gov/groups/ST/toolkit/documents/Examples/SHA_All.pdf";
static const CPU_CHAR sha_all_description[] =
    "NIST Computer Security Division standard test cases.";
#if defined(WOLFSSL_SHA3)
static const CPU_CHAR sha_3[] = 
    "https://www.di-mgt.com.au/sha_testvectors.html";
#endif    
static const cryptoST_testVector_t abc_3 =
{
    .name = DATA_PACKAGE_NAME "_abc3",
    .source = sha_all,
    .description = sha_all_description,
    .vector.data = (ALIGN4 const uint8_t[]){0x61, 0x62, 0x63}, // "abc"
    .vector.length = 3, // 24 bits
};
static const cryptoST_testVector_t abc_56 =
{
    .name = DATA_PACKAGE_NAME "_abc56",
    .source = sha_all,
    .description = sha_all_description,
    .vector.data = (ALIGN4 uint8_t[]){
        "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"},
    .vector.length = 56, // 448 bits
};
static const cryptoST_testVector_t abc_112 =
{
    .name = DATA_PACKAGE_NAME "_abc112",
    .source = sha_all,
    .description = sha_all_description,
    .vector.data = (ALIGN4 const uint8_t[]){
        "abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhi"
        "jklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu"},
    .vector.length = 112, // 896 bits
};

/*************************************************************
 * Golden data definitions.
 *************************************************************/
static __attribute__((unused)) const cryptoST_testDetail_t test_item[] =
{
#if !defined(NO_SHA) // SHA1
    {
        .technique = ET_SHA_1,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_3,
        .io.hash.out.hash = {
            .length = 20,
            .data = (uint8_t[]){ "\xA9\x99\x3E\x36" 
                                 "\x47\x06\x81\x6A" 
                                 "\xBA\x3E\x25\x71"
                                 "\x78\x50\xC2\x6C"
                                 "\x9C\xD0\xD8\x9D"
            },
        },
    },
    {
        .technique = ET_SHA_1,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_56,
        .io.hash.out.hash = {
            .length = 20,
            .data = (uint8_t[]){ "\x84\x98\x3E\x44" 
                                 "\x1C\x3B\xD2\x6E"
                                 "\xBA\xAE\x4A\xA1"
                                 "\xF9\x51\x29\xE5"
                                 "\xE5\x46\x70\xF1"
            },
        },
    },
#endif // !NO_SHA(1)
#if defined(WOLFSSL_SHA224)
    {
        .technique = ET_SHA_224,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_3,
        .io.hash.out.hash = {
            .length = 28,
            .data = (uint8_t[]){ "\x23\x09\x7D\x22"
                                 "\x34\x05\xD8\x22"
                                 "\x86\x42\xA4\x77"
                                 "\xBD\xA2\x55\xB3"
                                 "\x2A\xAD\xBC\xE4"
                                 "\xBD\xA0\xB3\xF7"
                                 "\xE3\x6C\x9D\xA7",
            },
        },
    },
    {
        .technique = ET_SHA_224,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_56,
        .io.hash.out.hash = {
            .length = 28,
            .data = (uint8_t[]){ "\x75\x38\x8B\x16"
                                 "\x51\x27\x76\xCC"
                                 "\x5D\xBA\x5D\xA1"
                                 "\xFD\x89\x01\x50"
                                 "\xB0\xC6\x45\x5C"
                                 "\xB4\xF5\x8B\x19"
                                 "\x52\x52\x25\x25",
            },
        },
    },
#endif // !NO_SHA224
#if !defined(NO_SHA256)
    {
        .technique = ET_SHA_256,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_3,
        .io.hash.out.hash = {
            .length = 32,
            .data = (ALIGN4 const uint8_t[]){
                0xba, 0x78, 0x16, 0xbf, 0x8f, 0x01, 0xcf, 0xea, 
                0x41, 0x41, 0x40, 0xde, 0x5d, 0xae, 0x22, 0x23,
                0xb0, 0x03, 0x61, 0xa3, 0x96, 0x17, 0x7a, 0x9c,
                0xb4, 0x10, 0xff, 0x61, 0xf2, 0x00, 0x15, 0xad
                // 0xba7816bf, 0x8f01cfea, 0x414140de, 0x5dae2223, 
                // 0xb00361a3, 0x96177a9c, 0xb410ff61, 0xf20015ad
            },
        },
    },
    {
        .technique = ET_SHA_256,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_56,
        .io.hash.out.hash = {
            .length = 32,
            .data = (const uint8_t[]){
                0x24, 0x8d, 0x6a, 0x61, 0xd2, 0x06, 0x38, 0xb8, 
                0xe5, 0xc0, 0x26, 0x93, 0x0c, 0x3e, 0x60, 0x39,
                0xa3, 0x3c, 0xe4, 0x59, 0x64, 0xff, 0x21, 0x67,
                0xf6, 0xec, 0xed, 0xd4, 0x19, 0xdb, 0x06, 0xc1 
                // 0x248d6a61, 0xd20638b8, 0xe5c02693, 0x0c3e6039, 
                // 0xa33ce459, 0x64ff2167, 0xf6ecedd4, 0x19db06c1
            },
        },
    },
    {
        .technique = ET_SHA_256,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_112,
        .io.hash.out.hash = {
            .length = 32,
            .data = (const uint8_t[]){
                0xcf, 0x5b, 0x16, 0xa7, 0x78, 0xaf, 0x83, 0x80,
                0x03, 0x6c, 0xe5, 0x9e, 0x7b, 0x04, 0x92, 0x37,
                0x0b, 0x24, 0x9b, 0x11, 0xe8, 0xf0, 0x7a, 0x51,
                0xaf, 0xac, 0x45, 0x03, 0x7a, 0xfe, 0xe9, 0xd1
                // 0xcf5b16a7, 0x78af8380, 0x036ce59e, 0x7b049237, 
                // 0x0b249b11, 0xe8f07a51, 0xafac4503, 0x7afee9d1
            },
        },
    },
#endif // !NO_SHA256
#if defined(WOLFSSL_SHA384)
    {
        .technique = ET_SHA_384,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_3,
        .io.hash.out.hash = {
            .length = 48,
            .data = (const uint8_t[]){
                0xCB, 0x00, 0x75, 0x3F, 0x45, 0xA3, 0x5E, 0x8B,
                0xB5, 0xA0, 0x3D, 0x69, 0x9A, 0xC6, 0x50, 0x07,
                0x27, 0x2C, 0x32, 0xAB, 0x0E, 0xDE, 0xD1, 0x63,
                0x1A, 0x8B, 0x60, 0x5A, 0x43, 0xFF, 0x5B, 0xED,
                0x80, 0x86, 0x07, 0x2B, 0xA1, 0xE7, 0xCC, 0x23,
                0x58, 0xBA, 0xEC, 0xA1, 0x34, 0xC8, 0x25, 0xA7
            // CB00753F 45A35E8B B5A03D69 9AC65007 272C32AB 0EDED163
            // 1A8B605A 43FF5BED 8086072B A1E7CC23 58BAECA1 34C825A7
            },
        },
    },
    {
        .technique = ET_SHA_384,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_112,
        .io.hash.out.hash = {
            .length = 48,
            .data = (const uint8_t[]){
                0x09, 0x33, 0x0C, 0x33, 0xF7, 0x11, 0x47, 0xE8,
                0x3D, 0x19, 0x2F, 0xC7, 0x82, 0xCD, 0x1B, 0x47,
                0x53, 0x11, 0x1B, 0x17, 0x3B, 0x3B, 0x05, 0xD2,
                0x2F, 0xA0, 0x80, 0x86, 0xE3, 0xB0, 0xF7, 0x12, 
                0xFC, 0xC7, 0xC7, 0x1A, 0x55, 0x7E, 0x2D, 0xB9, 
                0x66, 0xC3, 0xE9, 0xFA, 0x91, 0x74, 0x60, 0x39
            // 09330C33 F71147E8 3D192FC7 82CD1B47 53111B17 3B3B05D2
            // 2FA08086 E3B0F712 FCC7C71A 557E2DB9 66C3E9FA 91746039
            },
        },
    },
#endif // SHA384
#if defined(WOLFSSL_SHA512)
    {
        .technique = ET_SHA_512,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_3,
        .io.hash.out.hash = {
            .length = 64,
            .data = (const uint8_t[]){
                0xDD, 0xAF, 0x35, 0xA1, 0x93, 0x61, 0x7A, 0xBA,
                0xCC, 0x41, 0x73, 0x49, 0xAE, 0x20, 0x41, 0x31,
                0x12, 0xE6, 0xFA, 0x4E, 0x89, 0xA9, 0x7E, 0xA2,
                0x0A, 0x9E, 0xEE, 0xE6, 0x4B, 0x55, 0xD3, 0x9A,
                0x21, 0x92, 0x99, 0x2A, 0x27, 0x4F, 0xC1, 0xA8,
                0x36, 0xBA, 0x3C, 0x23, 0xA3, 0xFE, 0xEB, 0xBD,
                0x45, 0x4D, 0x44, 0x23, 0x64, 0x3C, 0xE8, 0x0E,
                0x2A, 0x9A, 0xC9, 0x4F, 0xA5, 0x4C, 0xA4, 0x9F
            // DDAF35A1 93617ABA CC417349 AE204131
            // 12E6FA4E 89A97EA2 0A9EEEE6 4B55D39A 2192992A 274FC1A8
            // 36BA3C23 A3FEEBBD 454D4423 643CE80E 2A9AC94F A54CA49F
            },
        },
    },
    {
        .technique = ET_SHA_512,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_all,
        .rawData = &abc_112,
        .io.hash.out.hash = {
            .length = 64,
            .data = (const uint8_t[]){
                0x8E, 0x95, 0x9B, 0x75, 0xDA, 0xE3, 0x13, 0xDA,
                0x8C, 0xF4, 0xF7, 0x28, 0x14, 0xFC, 0x14, 0x3F,
                0x8F, 0x77, 0x79, 0xC6, 0xEB, 0x9F, 0x7F, 0xA1, 
                0x72, 0x99, 0xAE, 0xAD, 0xB6, 0x88, 0x90, 0x18,
                0x50, 0x1D, 0x28, 0x9E, 0x49, 0x00, 0xF7, 0xE4,
                0x33, 0x1B, 0x99, 0xDE, 0xC4, 0xB5, 0x43, 0x3A,
                0xC7, 0xD3, 0x29, 0xEE, 0xB6, 0xDD, 0x26, 0x54,
                0x5E, 0x96, 0xE5, 0x5B, 0x87, 0x4B, 0xE9, 0x09
            // 8E959B75 DAE313DA 8CF4F728 14FC143F
            // 8F7779C6 EB9F7FA1 7299AEAD B6889018 501D289E 4900F7E4
            // 331B99DE C4B5433A C7D329EE B6DD2654 5E96E55B 874BE909
            },
        },
    },
#endif // SHA512
#if defined(WOLFSSL_SHA3)
    {
        .technique = ET_SHA3_224,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_3,
        .io.hash.out.hash = {
            .length = 28,
            .data = (uint8_t[]){ "\xe6\x42\x82\x4c"
                                 "\x3f\x8c\xf2\x4a"
                                 "\xd0\x92\x34\xee"
                                 "\x7d\x3c\x76\x6f"
                                 "\xc9\xa3\xa5\x16"
                                 "\x8d\x0c\x94\xad"
                                 "\x73\xb4\x6f\xdf",
            },
        },
    },
    {
        .technique = ET_SHA3_224,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_56,
        .io.hash.out.hash = {
            .length = 28,
            .data = (uint8_t[]){ "\x8a\x24\x10\x8b"
                                 "\x15\x4a\xda\x21"
                                 "\xc9\xfd\x55\x74"
                                 "\x49\x44\x79\xba"
                                 "\x5c\x7e\x7a\xb7"
                                 "\x6e\xf2\x64\xea"
                                 "\xd0\xfc\xce\x33",
            },
        },
    },    
    
    {
        .technique = ET_SHA3_224,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_112,
        .io.hash.out.hash = {
            .length = 28,
            .data = (const uint8_t[]){
                0x54, 0x3e, 0x68, 0x68, 0xe1, 0x66, 0x6c, 0x1a, 
                0x64, 0x36, 0x30, 0xdf, 0x77, 0x36, 0x7a, 0xe5, 
                0xa6, 0x2a, 0x85, 0x07, 0x0a, 0x51, 0xc1, 0x4c, 
                0xbf, 0x66, 0x5c, 0xbc,
            },
        },
    },
#if !defined(NO_SHA3_256)
    {
        .technique = ET_SHA3_256,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_3,
        .io.hash.out.hash = {
            .length = 32,
            .data = (ALIGN4 const uint8_t[]){
                0x3a, 0x98, 0x5d, 0xa7, 0x4f, 0xe2, 0x25, 0xb2, 
                0x04, 0x5c, 0x17, 0x2d, 0x6b, 0xd3, 0x90, 0xbd, 
                0x85, 0x5f, 0x08, 0x6e, 0x3e, 0x9d, 0x52, 0x5b, 
                0x46, 0xbf, 0xe2, 0x45, 0x11, 0x43, 0x15, 0x32
            },
        },
    },
    {
        .technique = ET_SHA3_256,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_56,
        .io.hash.out.hash = {
            .length = 32,
            .data = (const uint8_t[]){
                0x41, 0xc0, 0xdb, 0xa2, 0xa9, 0xd6, 0x24, 0x08, 
                0x49, 0x10, 0x03, 0x76, 0xa8, 0x23, 0x5e, 0x2c, 
                0x82, 0xe1, 0xb9, 0x99, 0x8a, 0x99, 0x9e, 0x21, 
                0xdb, 0x32, 0xdd, 0x97, 0x49, 0x6d, 0x33, 0x76
            },
        },
    },
    {
        .technique = ET_SHA3_256,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_112,
        .io.hash.out.hash = {
            .length = 32,
            .data = (const uint8_t[]){
                0x91, 0x6f, 0x60, 0x61, 0xfe, 0x87, 0x97, 0x41, 
                0xca, 0x64, 0x69, 0xb4, 0x39, 0x71, 0xdf, 0xdb, 
                0x28, 0xb1, 0xa3, 0x2d, 0xc3, 0x6c, 0xb3, 0x25, 
                0x4e, 0x81, 0x2b, 0xe2, 0x7a, 0xad, 0x1d, 0x18
            },
        },
    },
#endif // !NO_SHA256
#if defined(WOLFSSL_SHA3_384)
    {
        .technique = ET_SHA3_384,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_3,
        .io.hash.out.hash = {
            .length = 48,
            .data = (const uint8_t[]){
                0xec, 0x01, 0x49, 0x82, 0x88, 0x51, 0x6f, 0xc9, 
                0x26, 0x45, 0x9f, 0x58, 0xe2, 0xc6, 0xad, 0x8d, 
                0xf9, 0xb4, 0x73, 0xcb, 0x0f, 0xc0, 0x8c, 0x25, 
                0x96, 0xda, 0x7c, 0xf0, 0xe4, 0x9b, 0xe4, 0xb2, 
                0x98, 0xd8, 0x8c, 0xea, 0x92, 0x7a, 0xc7, 0xf5, 
                0x39, 0xf1, 0xed, 0xf2, 0x28, 0x37, 0x6d, 0x25
            },
        },
    },
    {
        .technique = ET_SHA3_384,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_56,
        .io.hash.out.hash = {
            .length = 48,
            .data = (const uint8_t[]){
                0x99, 0x1c, 0x66, 0x57, 0x55, 0xeb, 0x3a, 0x4b, 
                0x6b, 0xbd, 0xfb, 0x75, 0xc7, 0x8a, 0x49, 0x2e, 
                0x8c, 0x56, 0xa2, 0x2c, 0x5c, 0x4d, 0x7e, 0x42, 
                0x9b, 0xfd, 0xbc, 0x32, 0xb9, 0xd4, 0xad, 0x5a, 
                0xa0, 0x4a, 0x1f, 0x07, 0x6e, 0x62, 0xfe, 0xa1, 
                0x9e, 0xef, 0x51, 0xac, 0xd0, 0x65, 0x7c, 0x22
            },
        },
    },
    {
        .technique = ET_SHA3_384,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_112,
        .io.hash.out.hash = {
            .length = 48,
            .data = (const uint8_t[]){
                0x79, 0x40, 0x7d, 0x3b, 0x59, 0x16, 0xb5, 0x9c, 
                0x3e, 0x30, 0xb0, 0x98, 0x22, 0x97, 0x47, 0x91, 
                0xc3, 0x13, 0xfb, 0x9e, 0xcc, 0x84, 0x9e, 0x40, 
                0x6f, 0x23, 0x59, 0x2d, 0x04, 0xf6, 0x25, 0xdc, 
                0x8c, 0x70, 0x9b, 0x98, 0xb4, 0x3b, 0x38, 0x52, 
                0xb3, 0x37, 0x21, 0x61, 0x79, 0xaa, 0x7f, 0xc7
            },
        },
    },
#endif // SHA384    
    {
        .technique = ET_SHA3_512,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_3,
        .io.hash.out.hash = {
            .length = 64,
            .data = (const uint8_t[]){
                0xb7, 0x51, 0x85, 0x0b, 0x1a, 0x57, 0x16, 0x8a, 
                0x56, 0x93, 0xcd, 0x92, 0x4b, 0x6b, 0x09, 0x6e, 
                0x08, 0xf6, 0x21, 0x82, 0x74, 0x44, 0xf7, 0x0d, 
                0x88, 0x4f, 0x5d, 0x02, 0x40, 0xd2, 0x71, 0x2e, 
                0x10, 0xe1, 0x16, 0xe9, 0x19, 0x2a, 0xf3, 0xc9, 
                0x1a, 0x7e, 0xc5, 0x76, 0x47, 0xe3, 0x93, 0x40, 
                0x57, 0x34, 0x0b, 0x4c, 0xf4, 0x08, 0xd5, 0xa5, 
                0x65, 0x92, 0xf8, 0x27, 0x4e, 0xec, 0x53, 0xf0
            },
        },
    },
    {
        .technique = ET_SHA3_512,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_56,
        .io.hash.out.hash = {
            .length = 64,
            .data = (const uint8_t[]){
                0x04, 0xa3, 0x71, 0xe8, 0x4e, 0xcf, 0xb5, 0xb8, 
                0xb7, 0x7c, 0xb4, 0x86, 0x10, 0xfc, 0xa8, 0x18, 
                0x2d, 0xd4, 0x57, 0xce, 0x6f, 0x32, 0x6a, 0x0f, 
                0xd3, 0xd7, 0xec, 0x2f, 0x1e, 0x91, 0x63, 0x6d, 
                0xee, 0x69, 0x1f, 0xbe, 0x0c, 0x98, 0x53, 0x02, 
                0xba, 0x1b, 0x0d, 0x8d, 0xc7, 0x8c, 0x08, 0x63, 
                0x46, 0xb5, 0x33, 0xb4, 0x9c, 0x03, 0x0d, 0x99, 
                0xa2, 0x7d, 0xaf, 0x11, 0x39, 0xd6, 0xe7, 0x5e
            },
        },
    },
    {
        .technique = ET_SHA3_512,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = sha_3,
        .rawData = &abc_112,
        .io.hash.out.hash = {
            .length = 64,
            .data = (const uint8_t[]){
                0xaf, 0xeb, 0xb2, 0xef, 0x54, 0x2e, 0x65, 0x79, 
                0xc5, 0x0c, 0xad, 0x06, 0xd2, 0xe5, 0x78, 0xf9, 
                0xf8, 0xdd, 0x68, 0x81, 0xd7, 0xdc, 0x82, 0x4d, 
                0x26, 0x36, 0x0f, 0xee, 0xbf, 0x18, 0xa4, 0xfa, 
                0x73, 0xe3, 0x26, 0x11, 0x22, 0x94, 0x8e, 0xfc, 
                0xfd, 0x49, 0x2e, 0x74, 0xe8, 0x2e, 0x21, 0x89, 
                0xed, 0x0f, 0xb4, 0x40, 0xd1, 0x87, 0xf3, 0x82, 
                0x27, 0x0c, 0xb4, 0x55, 0xf2, 0x1d, 0xd1, 0x85
            },
        },
    },
#endif // SHA3


    {}
};
#define test_item_count ALENGTH(test_item)

/*************************************************************
 * Helper functions
 *************************************************************/

/*************************************************************
 * API handlers
 *************************************************************/
static const cryptoST_testDetail_t * firstTest(void)
{
    return &test_item[0];
}

static const cryptoST_testDetail_t * nextTest(const cryptoST_testDetail_t * old)
{
    // Assume that if the pointer is in range, that it is legitimate.
    if (old < test_item) 
        ;
    
    // We know that the final (illegitimate) entry has a null technique,
    // but we still need to check if "old" is _way_ out of bounds.
    else if ((++old >= &test_item[test_item_count])
            || (ET_NONE == old->technique))
        ;
    else return old;

    return NULL;
}

#define openData_func      NULL
#define closeData_func     NULL

/*************************************************************
 * Declaration of the test manager API
 * Obligatory entry points for executing a test
 *************************************************************/
cryptoST_testAPI_t const microchip_sha_nist =
{
    .name = DATA_PACKAGE_NAME,
    .openData = openData_func,
    .firstTest = firstTest,
    .nextTest = nextTest,
    .closeData = closeData_func,
};

#endif // Any SHA
