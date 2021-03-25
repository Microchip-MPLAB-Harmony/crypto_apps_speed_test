/* cryptoSTV_wolfSSL_aes_xts.c

  Crypto Speed Test Data File

  Company:
    Microchip Technology Inc.

  Description:
   This package transliterates test data from the wolfSSL test.c file,
   specifically the data for the AES/XTS tests.
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

#include <stddef.h>
#include <stdint.h>
#include "./cryptoSpeedTestData.h"
#include "cryptoST/cryptoSTE_print.h" // for BASE_LINE
#ifdef HAVE_CONFIG_H
    #include <config.h>
#endif

#define CONST /* as nothing */
#define ALIGN4 __attribute__((aligned(4)))

#if defined(WOLFSSL_AES_128)
static const cryptoST_testVector_t test_vector =
{
    .name = "AES_XTS128",
    .source = "NIST XTSGenAES128.rsp COUNT = 1 (128 hex str)",
    // .description =  NULL,
    .vector.data = (ALIGN4 const uint8_t[]){
        0xeb, 0xab, 0xce, 0x95, 0xb1, 0x4d, 0x3c, 0x8d, 
        0x6f, 0xb3, 0x50, 0x39, 0x07, 0x90, 0x31, 0x1c
    },
    .vector.length = 16,
};
#endif

#if defined(WOLFSSL_AES_256)
static const cryptoST_testVector_t test_vector256 =
{
    .name = "AES_XTS256",
    .source = "NIST XTSMMT256.rsp COUNT = 1 (128 hex str)",
    // .description =  NULL,
    .vector.data = (ALIGN4 const uint8_t[]){
        0x2e, 0xed, 0xea, 0x52, 0xcd, 0x82, 0x15, 0xe1, 
        0xac, 0xc6, 0x47, 0xe8, 0x10, 0xbb, 0xc3, 0x64, 
        0x2e, 0x87, 0x28, 0x7f, 0x8d, 0x2e, 0x57, 0xe3, 
        0x6c, 0x0a, 0x24, 0xfb, 0xc1, 0x2a, 0x20, 0x2e
        },
    .vector.length = 32,
};

#endif
static const cryptoST_testDetail_t test_item[] =
{
    // Keys and results for AES XTS 128, 256
#if defined(WOLFSSL_AES_128)
    {
        .technique = ET_AES_128,
        .mode = EM_XTS,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = "NIST XTSGenAES128.rsp COUNT = 1 (128 hex str)",
        .rawData = &test_vector,//128
        .io.sym.out.cipher = {
            .length = 16,
            .data = (ALIGN4 const uint8_t[]){
                0x77, 0x8a, 0xe8, 0xb4, 0x3c, 0xb9, 0x8d, 0x5a, 
                0x82, 0x50, 0x81, 0xd5, 0xbe, 0x47, 0x1c, 0x63
            }
        },
        .io.sym.in.key = {
            .length = 2*AES128_KEY_SIZE/8,
            .data = (ALIGN4 const uint8_t[]){
                0xa1, 0xb9, 0x0c, 0xba, 0x3f, 0x06, 0xac, 0x35,//aes key 
                0x3b, 0x2c, 0x34, 0x38, 0x76, 0x08, 0x17, 0x62, 
                
                0x09, 0x09, 0x23, 0x02, 0x6e, 0x91, 0x77, 0x18,//tweak key
                0x15, 0xf2, 0x9d, 0xab, 0x01, 0x93, 0x2f, 0x2f
            }
        },
        .io.sym.in.ivNonce = {
            .length = 16,
            .data = (ALIGN4 const uint8_t[]){
                0x4f, 0xae, 0xf7, 0x11, 0x7c, 0xda, 0x59, 0xc6, 
                0x6e, 0x4b, 0x92, 0x01, 0x3e, 0x76, 0x8a, 0xd5
            }
        },
    },
#endif
#if defined(WOLFSSL_AES_256)
    {
        .technique = ET_AES_256,
        .mode = EM_XTS,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = "NIST XTSGenAES256.rsp COUNT = 1 (128 hex str)",
        .rawData = &test_vector256,
        .io.sym.out.cipher = {
            .length = 32,
            .data = (ALIGN4 const uint8_t[]){
                0xcb, 0xaa, 0xd0, 0xe2, 0xf6, 0xce, 0xa3, 0xf5, 
                0x0b, 0x37, 0xf9, 0x34, 0xd4, 0x6a, 0x9b, 0x13, 
                0x0b, 0x9d, 0x54, 0xf0, 0x7e, 0x34, 0xf3, 0x6a, 
                0xf7, 0x93, 0xe8, 0x6f, 0x73, 0xc6, 0xd7, 0xdb
            }
        },
        .io.sym.in.key = {
            .length = 2*AES256_KEY_SIZE/8,
            .data = (ALIGN4 const uint8_t[]){
                0x1e, 0xa6, 0x61, 0xc5, 0x8d, 0x94, 0x3a, 0x0e,//aes key 
                0x48, 0x01, 0xe4, 0x2f, 0x4b, 0x09, 0x47, 0x14, 
                0x9e, 0x7f, 0x9f, 0x8e, 0x3e, 0x68, 0xd0, 0xc7, 
                0x50, 0x52, 0x10, 0xbd, 0x31, 0x1a, 0x0e, 0x7c, 
                
                0xd6, 0xe1, 0x3f, 0xfd, 0xf2, 0x41, 0x8d, 0x8d,//tweak key
                0x19, 0x11, 0xc0, 0x04, 0xcd, 0xa5, 0x8d, 0xa3, 
                0xd6, 0x19, 0xb7, 0xe2, 0xb9, 0x14, 0x1e, 0x58, 
                0x31, 0x8e, 0xea, 0x39, 0x2c, 0xf4, 0x1b, 0x08
            },
        },
        .io.sym.in.ivNonce = {
            .length = 16,
            .data = (ALIGN4 const uint8_t[]){
                0xad, 0xf8, 0xd9, 0x26, 0x27, 0x46, 0x4a, 0xd2, 
                0xf0, 0x42, 0x8e, 0x84, 0xa9, 0xf8, 0x75, 0x64
            },
        }
    },
#endif
    {}
};
#define test_item_count (sizeof(test_item)/sizeof(cryptoST_testDetail_t))

/*************************************************************
 * API handlers
 *************************************************************/
static const cryptoST_testDetail_t * firstTest(void)
{
    return test_item;
}
static const cryptoST_testDetail_t * nextTest(const cryptoST_testDetail_t * old)
{
    // Assume that if its in range, that it is legitimate.
    if (old < test_item) 
        return NULL;
    old++; // repurpose: this is now "new"
    
    // We know that the final (illegitimate) entry has a null name,
    // but we still need to check if "old" is _way_ out of bounds.
    if ((old >= &test_item[test_item_count])
            || (ET_NONE == old->technique))
        return NULL;
    return old;
}

/*************************************************************
 * Declaration of the test manager API
 * Obligatory entry points for executing a test
 *************************************************************/
#include "cryptoSTD_wolfSSL_aes_xts.h"
cryptoST_testAPI_t const wolfSSL_aes_xts =
{
    .name = "AES_XTS",
    .openData = NULL,
    .firstTest = firstTest,
    .nextTest = nextTest,
    .closeData = NULL,
};

