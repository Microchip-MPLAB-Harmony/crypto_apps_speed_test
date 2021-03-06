/*******************************************************************************
  Crypto Speed Test Data File

  Company:
    Microchip Technology Inc.

  File Name:
    cryptoSTD_rsa_CAVS11p2.c

  Summary:
   From the 186-4 RSA Validation System (RSA2VS) as described in
   rsa2vs.pdf (9 July 2014 10:59:36am) with data from files found in
   the companion 186-3rsatestvectors.zip.   

  Description:
   Known-good data for RSA encryption with public key, requiring padding. See also the pdf file.
   https://csrc.nist.gov/presentations/2004/the-rsa-validation-system-(rsavs)
   https://csrc.nist.gov/Projects/Cryptographic-Algorithm-Validation-Program/Component-Testing
 ******************************************************************************
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
#include "configuration.h"
#include <wolfssl/wolfcrypt/settings.h>
#include "./cryptoSpeedTestData.h"
#include "cryptoST/cryptoSTE_print.h" // for BASE_LINE

#define DATA_PACKAGE_NAME "CAVS11p2"
#define ALIGN4 __attribute__((aligned(4)))
#define DATA_CHAR ALIGN4 const uint8_t

#if !defined(NO_RSA) && defined(RSA_WITH_PSS_MODE)
static const CPU_CHAR RSA2VS_source[] = "NIST 186-4 RSA Validation System (RSA2VS.pdf)";
static const CPU_CHAR pedigree[] = "NIST suite SigGenPSS_186-3 (CAVS11p2)";

/* rsa2vs.pdf.6.3 indicates that this field is the "date generated", 
 * but does not elaborate; therefore, it is here but not used.
static DATA_CHAR date[29] = {
0x5a, 0x89, 0xcd, 0xef, 0x77, 0x94, 0x65, 0x7a, 0x40, 0x84, 0x92, 0x09, 0xb0, 0x3b, 0x73, 0xc4, 
0xca, 0xe6, 0xa5, 0xfd, 0x66, 0x3e, 0x43, 0xb3, 0x3e, 0xa3, 0x00, 0x40, 0x89};
*/

/*************************************************************
 * Raw (input) data definitions.
 *************************************************************/
#if defined(WOLFSSL_SHA224)
static const cryptoST_testVector_t sigGenPSS_224_2048_37dd =
{
    .name = "sigGenPSS_224_2048_37dd",
    .source = RSA2VS_source,
    .description = pedigree,
    .vector.length = 128,
    .vector.data = (DATA_CHAR[128]){
0x37, 0xdd, 0xd9, 0x90, 0x14, 0x78, 0xae, 0x5c, 0x16, 0x87, 0x87, 0x02, 0xce, 0xa4, 0xa1, 0x9e, 
0x78, 0x6d, 0x35, 0x58, 0x2d, 0xe4, 0x4a, 0xe6, 0x5a, 0x16, 0xcd, 0x53, 0x70, 0xfb, 0xe3, 0xff, 
0xdd, 0x9e, 0x7e, 0xe8, 0x3c, 0x7d, 0x2f, 0x27, 0xc8, 0x33, 0x3b, 0xbe, 0x17, 0x54, 0xf0, 0x90, 
0x05, 0x99, 0x39, 0xb1, 0xee, 0x3d, 0x71, 0xe0, 0x20, 0xa6, 0x75, 0x52, 0x8f, 0x48, 0xfd, 0xb2, 
0xcb, 0xc7, 0x2c, 0x65, 0x30, 0x5b, 0x65, 0x12, 0x5c, 0x79, 0x61, 0x62, 0xe7, 0xb0, 0x7e, 0x04, 
0x4e, 0xd1, 0x5a, 0xf5, 0x2f, 0x52, 0xa1, 0xfe, 0xbc, 0xf4, 0x23, 0x7e, 0x6a, 0xa4, 0x2a, 0x69, 
0xe9, 0x9f, 0x0a, 0x91, 0x59, 0xda, 0xf9, 0x24, 0xbb, 0xa1, 0x21, 0x76, 0xa5, 0x7e, 0xf4, 0x01, 
0x3a, 0x5c, 0xc0, 0xab, 0x5a, 0xec, 0x83, 0x47, 0x16, 0x48, 0x00, 0x5d, 0x67, 0xd7, 0x12, 0x2e}
};
#endif // SHA224

static const cryptoST_testVector_t sigGenPSS_256_2048_dfc2 =
{
    .name = "sigGenPSS_256_2048_dfc2",
    .source = RSA2VS_source,
    .description = pedigree,
    .vector.length = 128,
    .vector.data = (DATA_CHAR[128]){
0xdf, 0xc2, 0x26, 0x04, 0xb9, 0x5d, 0x15, 0x32, 0x80, 0x59, 0x74, 0x5c, 0x6c, 0x98, 0xeb, 0x9d, 
0xfb, 0x34, 0x7c, 0xf9, 0xf1, 0x70, 0xaf, 0xf1, 0x9d, 0xee, 0xec, 0x55, 0x5f, 0x22, 0x28, 0x5a, 
0x67, 0x06, 0xc4, 0xec, 0xbf, 0x0f, 0xb1, 0x45, 0x8c, 0x60, 0xd9, 0xbf, 0x91, 0x3f, 0xba, 0xe6, 
0xf4, 0xc5, 0x54, 0xd2, 0x45, 0xd9, 0x46, 0xb4, 0xbc, 0x5f, 0x34, 0xae, 0xc2, 0xac, 0x6b, 0xe8, 
0xb3, 0x3d, 0xc8, 0xe0, 0xe3, 0xa9, 0xd6, 0x01, 0xdf, 0xd5, 0x36, 0x78, 0xf5, 0x67, 0x44, 0x43, 
0xf6, 0x7d, 0xf7, 0x8a, 0x3a, 0x9e, 0x09, 0x33, 0xe5, 0xf1, 0x58, 0xb1, 0x69, 0xac, 0x8d, 0x1c, 
0x4c, 0xd0, 0xfb, 0x87, 0x2c, 0x14, 0xca, 0x8e, 0x00, 0x1e, 0x54, 0x2e, 0xa0, 0xf9, 0xcf, 0xda, 
0x88, 0xc4, 0x2d, 0xca, 0xd8, 0xa7, 0x40, 0x97, 0xa0, 0x0c, 0x22, 0x05, 0x5b, 0x0b, 0xd4, 0x1f},
};

#if EMPLOY_ALTERNATIVE_DATA_SETS
static const cryptoST_testVector_t sigGenPSS_2048_5c61 =
{
    .name = "sigGenPSS_2048_5c61",
    .source = RSA2VS_source,
    .description = pedigree,
    .vector.length = 128,
    .vector.data = (DATA_CHAR[128]){
0x5c, 0x61, 0x54, 0x6b, 0x84, 0x8a, 0x36, 0xe8, 0xe5, 0x1f, 0x8b, 0xeb, 0x11, 0x40, 0x82, 0x3d, 
0xbd, 0x95, 0xb0, 0x66, 0x60, 0x92, 0x4d, 0x16, 0xfd, 0xf9, 0xa1, 0xc3, 0x3c, 0xa0, 0xb9, 0x94, 
0xc0, 0x74, 0x5e, 0x7e, 0xb5, 0xbe, 0x48, 0xad, 0xa8, 0xa5, 0x8e, 0x25, 0x9c, 0xf4, 0x61, 0xa9, 
0x5a, 0x1e, 0xfa, 0xdb, 0x08, 0x80, 0xd1, 0xa6, 0xfd, 0xe5, 0x10, 0xd9, 0xd4, 0x4f, 0x47, 0x14, 
0xbf, 0xf5, 0x61, 0xe8, 0x1e, 0x88, 0xd7, 0x3a, 0x51, 0xba, 0x23, 0xe8, 0xca, 0x01, 0x78, 0xb0, 
0x66, 0x98, 0xb0, 0x4d, 0xfd, 0xc8, 0x86, 0xe2, 0x38, 0x65, 0x05, 0x9c, 0xa2, 0x9b, 0x40, 0x93, 
0x02, 0xeb, 0x44, 0xf2, 0xe9, 0x70, 0x4b, 0x58, 0x87, 0x67, 0x32, 0x7e, 0xc2, 0xee, 0x2d, 0x19, 
0x8a, 0x0c, 0xba, 0x02, 0x66, 0xf2, 0xd3, 0x94, 0x53, 0x80, 0x68, 0x55, 0xcf, 0x0b, 0x0c, 0xd9}
};

static const cryptoST_testVector_t sigGenPSS_2048_dfc2 =
{
    .name = "sigGenPSS_2048_dfc2",
    .source = RSA2VS_source,
    .description = pedigree,
    .vector.length = 128,
    .vector.data = (DATA_CHAR[128]){
0xdf, 0xc2, 0x26, 0x04, 0xb9, 0x5d, 0x15, 0x32, 0x80, 0x59, 0x74, 0x5c, 0x6c, 0x98, 0xeb, 0x9d, 
0xfb, 0x34, 0x7c, 0xf9, 0xf1, 0x70, 0xaf, 0xf1, 0x9d, 0xee, 0xec, 0x55, 0x5f, 0x22, 0x28, 0x5a, 
0x67, 0x06, 0xc4, 0xec, 0xbf, 0x0f, 0xb1, 0x45, 0x8c, 0x60, 0xd9, 0xbf, 0x91, 0x3f, 0xba, 0xe6, 
0xf4, 0xc5, 0x54, 0xd2, 0x45, 0xd9, 0x46, 0xb4, 0xbc, 0x5f, 0x34, 0xae, 0xc2, 0xac, 0x6b, 0xe8, 
0xb3, 0x3d, 0xc8, 0xe0, 0xe3, 0xa9, 0xd6, 0x01, 0xdf, 0xd5, 0x36, 0x78, 0xf5, 0x67, 0x44, 0x43, 
0xf6, 0x7d, 0xf7, 0x8a, 0x3a, 0x9e, 0x09, 0x33, 0xe5, 0xf1, 0x58, 0xb1, 0x69, 0xac, 0x8d, 0x1c, 
0x4c, 0xd0, 0xfb, 0x87, 0x2c, 0x14, 0xca, 0x8e, 0x00, 0x1e, 0x54, 0x2e, 0xa0, 0xf9, 0xcf, 0xda, 
0x88, 0xc4, 0x2d, 0xca, 0xd8, 0xa7, 0x40, 0x97, 0xa0, 0x0c, 0x22, 0x05, 0x5b, 0x0b, 0xd4, 0x1f}
};

static const cryptoST_testVector_t sigGenPSS_2048_fd6a =
{
    .name = "sigGenPSS_2048_fd6a",
    .source = RSA2VS_source,
    .description = pedigree,
    .vector.length = 128,
    .vector.data = (DATA_CHAR[128]){
0xfd, 0x6a, 0x06, 0x3e, 0x61, 0xc2, 0xb3, 0x54, 0xfe, 0x8c, 0xb3, 0x7a, 0x5f, 0x37, 0x88, 0xb5, 
0xc0, 0x1f, 0xf1, 0x5a, 0x72, 0x5f, 0x6b, 0x81, 0x81, 0xe6, 0xf6, 0xb7, 0x95, 0xce, 0x1c, 0xf3, 
0x16, 0xe9, 0x30, 0xcc, 0x93, 0x9c, 0xd4, 0xe8, 0x65, 0xf0, 0xbd, 0xb8, 0x8f, 0xe6, 0xbb, 0x62, 
0xe9, 0x0b, 0xf3, 0xff, 0x7e, 0x4d, 0x6f, 0x07, 0x32, 0x0d, 0xda, 0x09, 0xa8, 0x75, 0x84, 0xa0, 
0x62, 0x0c, 0xad, 0xa2, 0x2a, 0x87, 0xff, 0x9a, 0xb1, 0xe3, 0x5c, 0x79, 0x77, 0xb0, 0xda, 0x88, 
0xea, 0xb0, 0x0c, 0xa1, 0xd2, 0xa0, 0x84, 0x9f, 0xec, 0x56, 0x95, 0x13, 0xd5, 0x0c, 0x5e, 0x39, 
0x2a, 0xfc, 0x03, 0x2a, 0xee, 0x2d, 0x3e, 0x52, 0x2c, 0x8c, 0x17, 0x25, 0xdd, 0x3e, 0xef, 0x0e, 
0x0b, 0x35, 0xc3, 0xa8, 0x37, 0x01, 0xaf, 0x31, 0xf9, 0xe9, 0xb1, 0x3c, 0xe6, 0x3b, 0xb0, 0xa5}
};
#endif

/*************************************************************
 * Keys material
 *************************************************************/
static const cryptoST_testData_t sigGenPSS_2048n = {
    .length = 256,
    .data = (DATA_CHAR[256]){
0xc5, 0x06, 0x2b, 0x58, 0xd8, 0x53, 0x9c, 0x76, 0x5e, 0x1e, 0x5d, 0xba, 0xf1, 0x4c, 0xf7, 0x5d, 
0xd5, 0x6c, 0x2e, 0x13, 0x10, 0x5f, 0xec, 0xfd, 0x1a, 0x93, 0x0b, 0xbb, 0x59, 0x48, 0xff, 0x32, 
0x8f, 0x12, 0x6a, 0xbe, 0x77, 0x93, 0x59, 0xca, 0x59, 0xbc, 0xa7, 0x52, 0xc3, 0x08, 0xd2, 0x81, 
0x57, 0x3b, 0xc6, 0x17, 0x8b, 0x6c, 0x0f, 0xef, 0x7d, 0xc4, 0x45, 0xe4, 0xf8, 0x26, 0x43, 0x04, 
0x37, 0xb9, 0xf9, 0xd7, 0x90, 0x58, 0x1d, 0xe5, 0x74, 0x9c, 0x2c, 0xb9, 0xcb, 0x26, 0xd4, 0x2b, 
0x2f, 0xee, 0x15, 0xb6, 0xb2, 0x6f, 0x09, 0xc9, 0x96, 0x70, 0x33, 0x64, 0x23, 0xb8, 0x6b, 0xc5, 
0xbe, 0xc7, 0x11, 0x13, 0x15, 0x7b, 0xe2, 0xd9, 0x44, 0xd7, 0xff, 0x3e, 0xeb, 0xff, 0xb2, 0x84, 
0x13, 0x14, 0x3e, 0xa3, 0x67, 0x55, 0xdb, 0x0a, 0xe6, 0x2f, 0xf5, 0xb7, 0x24, 0xee, 0xcb, 0x3d, 
0x31, 0x6b, 0x6b, 0xac, 0x67, 0xe8, 0x9c, 0xac, 0xd8, 0x17, 0x19, 0x37, 0xe2, 0xab, 0x19, 0xbd, 
0x35, 0x3a, 0x89, 0xac, 0xea, 0x8c, 0x36, 0xf8, 0x1c, 0x89, 0xa6, 0x20, 0xd5, 0xfd, 0x2e, 0xff, 
0xea, 0x89, 0x66, 0x01, 0xc7, 0xf9, 0xda, 0xca, 0x7f, 0x03, 0x3f, 0x63, 0x5a, 0x3a, 0x94, 0x33, 
0x31, 0xd1, 0xb1, 0xb4, 0xf5, 0x28, 0x87, 0x90, 0xb5, 0x3a, 0xf3, 0x52, 0xf1, 0x12, 0x1c, 0xa1, 
0xbe, 0xf2, 0x05, 0xf4, 0x0d, 0xc0, 0x12, 0xc4, 0x12, 0xb4, 0x0b, 0xdd, 0x27, 0x58, 0x5b, 0x94, 
0x64, 0x66, 0xd7, 0x5f, 0x7e, 0xe0, 0xa7, 0xf9, 0xd5, 0x49, 0xb4, 0xbe, 0xce, 0x6f, 0x43, 0xac, 
0x3e, 0xe6, 0x5f, 0xe7, 0xfd, 0x37, 0x12, 0x33, 0x59, 0xd9, 0xf1, 0xa8, 0x50, 0xad, 0x45, 0x0a, 
0xaf, 0x5c, 0x94, 0xeb, 0x11, 0xde, 0xa3, 0xfc, 0x0f, 0xc6, 0xe9, 0x85, 0x6b, 0x18, 0x05, 0xef
}
};

static const cryptoST_testData_t sigGenPSS_2048e = {
    .length = 256,
    .data = (DATA_CHAR[256]){
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0xc9, 0x4f
}
};

static const cryptoST_testData_t sigGenPSS_2048d = {
    .length = 256,
    .data = (DATA_CHAR[256]){
0x49, 0xe5, 0x78, 0x6b, 0xb4, 0xd3, 0x32, 0xf9, 0x45, 0x86, 0x32, 0x7b, 0xde, 0x08, 0x88, 0x75, 
0x37, 0x9b, 0x75, 0xd1, 0x28, 0x48, 0x8f, 0x08, 0xe5, 0x74, 0xab, 0x47, 0x15, 0x30, 0x2a, 0x87, 
0xee, 0xa5, 0x2d, 0x4c, 0x4a, 0x23, 0xd8, 0xb9, 0x7a, 0xf7, 0x94, 0x48, 0x04, 0x33, 0x7c, 0x5f, 
0x55, 0xe1, 0x6b, 0xa9, 0xff, 0xaf, 0xc0, 0xc9, 0xfd, 0x9b, 0x88, 0xec, 0xa4, 0x43, 0xf3, 0x9b, 
0x79, 0x67, 0x17, 0x0d, 0xdb, 0x8c, 0xe7, 0xdd, 0xb9, 0x3c, 0x60, 0x87, 0xc8, 0x06, 0x6c, 0x4a, 
0x95, 0x53, 0x8a, 0x44, 0x1b, 0x9d, 0xc8, 0x0d, 0xc9, 0xf7, 0x81, 0x00, 0x54, 0xfd, 0x1e, 0x5c, 
0x9d, 0x02, 0x50, 0xc9, 0x78, 0xbb, 0x2d, 0x74, 0x8a, 0xbe, 0x1e, 0x94, 0x65, 0xd7, 0x1a, 0x81, 
0x65, 0xd3, 0x12, 0x6d, 0xce, 0x5d, 0xb2, 0xad, 0xac, 0xc0, 0x03, 0xe9, 0x06, 0x2b, 0xa3, 0x7a, 
0x54, 0xb6, 0x3e, 0x5f, 0x49, 0xa4, 0xea, 0xfe, 0xbd, 0x7e, 0x4b, 0xf5, 0xb0, 0xa7, 0x96, 0xc2, 
0xb3, 0xa9, 0x50, 0xfa, 0x09, 0xc7, 0x98, 0xd3, 0xfa, 0x3e, 0x86, 0xc4, 0xb6, 0x2c, 0x33, 0xba, 
0x93, 0x65, 0xed, 0xa0, 0x54, 0xe5, 0xfe, 0x74, 0xa4, 0x1f, 0x21, 0xb5, 0x95, 0x02, 0x6a, 0xcf, 
0x10, 0x93, 0xc9, 0x0a, 0x8c, 0x71, 0x72, 0x2f, 0x91, 0xaf, 0x1e, 0xd2, 0x9a, 0x41, 0xa2, 0x44, 
0x9a, 0x32, 0x0f, 0xc7, 0xba, 0x31, 0x20, 0xe3, 0xe8, 0xc3, 0xe4, 0x24, 0x0c, 0x04, 0x92, 0x5c, 
0xc6, 0x98, 0xec, 0xd6, 0x6c, 0x7c, 0x90, 0x6b, 0xdf, 0x24, 0x0a, 0xda, 0xd9, 0x72, 0xb4, 0xdf, 
0xf4, 0x86, 0x9d, 0x40, 0x0b, 0x5d, 0x13, 0xe3, 0x3e, 0xeb, 0xa3, 0x8e, 0x07, 0x5e, 0x87, 0x2b, 
0x0e, 0xd3, 0xe9, 0x1c, 0xc9, 0xc2, 0x83, 0x86, 0x7a, 0x4f, 0xfc, 0x39, 0x01, 0xd2, 0x06, 0x9f}
};
#endif // NO_RSA

/*************************************************************
 * Key, nonce and AAD inputs and golden data and tag result definitions.
 *************************************************************/
static const cryptoST_testDetail_t test_item[] =
{
#if !defined(NO_RSA) && defined(RSA_WITH_PSS_MODE)
#if !defined(NO_SHA256)
    {
        .technique = ET_PK_RSA_SIGN,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = pedigree,
        .rawData = &sigGenPSS_256_2048_dfc2,

        .io.rsav.in.hashmode = ET_SHA_256,
        .io.rsav.in.n = &sigGenPSS_2048n,
        .io.rsav.in.e = &sigGenPSS_2048e,
        .io.rsav.in.d = &sigGenPSS_2048d,
        .io.rsav.out.cipher.length = 256,
        .io.rsav.out.cipher.data = (DATA_CHAR[256]){
0x8b, 0x46, 0xf2, 0xc8, 0x89, 0xd8, 0x19, 0xf8, 0x60, 0xaf, 0x0a, 0x6c, 0x4c, 0x88, 0x9e, 0x4d, 
0x14, 0x36, 0xc6, 0xca, 0x17, 0x44, 0x64, 0xd2, 0x2a, 0xe1, 0x1b, 0x9c, 0xcc, 0x26, 0x5d, 0x74, 
0x3c, 0x67, 0xe5, 0x69, 0xac, 0xcb, 0xc5, 0xa8, 0x0d, 0x4d, 0xd5, 0xf1, 0xbf, 0x40, 0x39, 0xe2, 
0x3d, 0xe5, 0x2a, 0xec, 0xe4, 0x02, 0x91, 0xc7, 0x5f, 0x89, 0x36, 0xc5, 0x8c, 0x9a, 0x2f, 0x77, 
0xa7, 0x80, 0xbb, 0xe7, 0xad, 0x31, 0xeb, 0x76, 0x74, 0x2f, 0x7b, 0x2b, 0x8b, 0x14, 0xca, 0x1a, 
0x71, 0x96, 0xaf, 0x7e, 0x67, 0x3a, 0x3c, 0xfc, 0x23, 0x7d, 0x50, 0xf6, 0x15, 0xb7, 0x5c, 0xf4, 
0xa7, 0xea, 0x78, 0xa9, 0x48, 0xbe, 0xda, 0xf9, 0x24, 0x24, 0x94, 0xb4, 0x1e, 0x1d, 0xb5, 0x1f, 
0x43, 0x7f, 0x15, 0xfd, 0x25, 0x51, 0xbb, 0x5d, 0x24, 0xee, 0xfb, 0x1c, 0x3e, 0x60, 0xf0, 0x36, 
0x94, 0xd0, 0x03, 0x3a, 0x1e, 0x0a, 0x9b, 0x9f, 0x5e, 0x4a, 0xb9, 0x7d, 0x45, 0x7d, 0xff, 0x9b, 
0x9d, 0xa5, 0x16, 0xdc, 0x22, 0x6d, 0x6d, 0x65, 0x29, 0x50, 0x03, 0x08, 0xed, 0x74, 0xa2, 0xe6, 
0xd9, 0xf3, 0xc1, 0x05, 0x95, 0x78, 0x8a, 0x52, 0xa1, 0xbc, 0x06, 0x64, 0xae, 0xdf, 0x33, 0xef, 
0xc8, 0xba, 0xdd, 0x03, 0x7e, 0xb7, 0xb8, 0x80, 0x77, 0x2b, 0xdb, 0x04, 0xa6, 0x04, 0x6e, 0x9e, 
0xde, 0xee, 0x41, 0x97, 0xc2, 0x55, 0x07, 0xfb, 0x0f, 0x11, 0xab, 0x1c, 0x9f, 0x63, 0xf5, 0x3c, 
0x88, 0x20, 0xea, 0x84, 0x05, 0xcf, 0xd7, 0x72, 0x16, 0x92, 0x47, 0x5b, 0x4d, 0x72, 0x35, 0x5f, 
0xa9, 0xa3, 0x80, 0x4f, 0x29, 0xe6, 0xb6, 0xa7, 0xb0, 0x59, 0xc4, 0x44, 0x1d, 0x54, 0xb2, 0x8e, 
0x4e, 0xed, 0x25, 0x29, 0xc6, 0x10, 0x3b, 0x54, 0x32, 0xc7, 0x13, 0x32, 0xce, 0x74, 0x2b, 0xcc}
    },
#endif // sha256 hash data
#if defined(WOLFSSL_SHA224)
    {
        .technique = ET_PK_RSA_SIGN,
        .mode = EM_NONE,
        .recommendedRepetitions = 1000,

        .source = __BASE_FILE__ "(" BASE_LINE ")",
        .pedigree = pedigree,
        .rawData = &sigGenPSS_224_2048_37dd,

        .io.rsav.in.hashmode = ET_SHA_224,
        .io.rsav.in.n = &sigGenPSS_2048n,
        .io.rsav.in.e = &sigGenPSS_2048e,
        .io.rsav.in.d = &sigGenPSS_2048d,
        .io.rsav.out.cipher.length = 256,
        .io.rsav.out.cipher.data = (DATA_CHAR[256]){
0x7e, 0x62, 0x8b, 0xcb, 0xe6, 0xff, 0x83, 0xa9, 0x37, 0xb8, 0x96, 0x11, 0x97, 0xd8, 0xbd, 0xbb, 
0x32, 0x28, 0x18, 0xaa, 0x8b, 0xdf, 0x30, 0xcd, 0xfb, 0x67, 0xca, 0x6b, 0xf0, 0x25, 0xef, 0x6f, 
0x09, 0xa9, 0x9d, 0xba, 0x4c, 0x3e, 0xe2, 0x80, 0x7d, 0x0b, 0x7c, 0x77, 0x77, 0x6c, 0xfe, 0xff, 
0x33, 0xb6, 0x8d, 0x7e, 0x3f, 0xa8, 0x59, 0xc4, 0x68, 0x86, 0x26, 0xb2, 0x44, 0x18, 0x97, 0xd2, 
0x6e, 0x5d, 0x6b, 0x55, 0x9d, 0xd7, 0x2a, 0x59, 0x6e, 0x7d, 0xad, 0x7d, 0xef, 0x92, 0x78, 0x41, 
0x9d, 0xb3, 0x75, 0xf7, 0xc6, 0x7c, 0xee, 0x07, 0x40, 0x39, 0x45, 0x02, 0x21, 0x2e, 0xbd, 0xd4, 
0xa6, 0xc8, 0xd3, 0xaf, 0x6e, 0xe2, 0xfd, 0x69, 0x6d, 0x85, 0x23, 0xde, 0x69, 0x08, 0x49, 0x2b, 
0x7c, 0xbf, 0x22, 0x54, 0xf1, 0x5a, 0x34, 0x89, 0x56, 0xc1, 0x98, 0x40, 0xdc, 0x15, 0xa3, 0xd7, 
0x32, 0xef, 0x86, 0x2b, 0x62, 0xed, 0xe0, 0x22, 0x29, 0x0d, 0xe3, 0xaf, 0x11, 0xca, 0x5e, 0x79, 
0xa3, 0x39, 0x2f, 0xff, 0x06, 0xf7, 0x5a, 0xca, 0x8c, 0x88, 0xa2, 0xde, 0x18, 0x58, 0xb3, 0x5a, 
0x21, 0x6d, 0x8f, 0x73, 0xfd, 0x70, 0xe9, 0xd6, 0x79, 0x58, 0xed, 0x39, 0xa6, 0xf8, 0x97, 0x6f, 
0xb9, 0x4e, 0xc6, 0xe6, 0x1f, 0x23, 0x8a, 0x52, 0xf9, 0xd4, 0x22, 0x41, 0xe8, 0x35, 0x4f, 0x89, 
0xe3, 0xec, 0xe9, 0x4d, 0x6f, 0xa5, 0xbf, 0xbb, 0xa1, 0xee, 0xb7, 0x0e, 0x16, 0x98, 0xbf, 0xf3, 
0x1a, 0x68, 0x5f, 0xbe, 0x79, 0x9f, 0xb4, 0x4e, 0xfe, 0x21, 0x33, 0x8e, 0xd6, 0xee, 0xa2, 0x12, 
0x91, 0x55, 0xaa, 0xbc, 0x09, 0x43, 0xbc, 0x9f, 0x69, 0xa8, 0xe5, 0x88, 0x97, 0xdb, 0x6a, 0x8a, 
0xbc, 0xc2, 0x87, 0x9d, 0x5d, 0x0c, 0x5d, 0x3e, 0x6d, 0xc5, 0xeb, 0x48, 0xcf, 0x16, 0xda, 0xc8},
    },
#endif // sha224 hash data
#endif // NO_RSA
    {}
};
#define test_item_count (sizeof(test_item)/sizeof(cryptoST_testDetail_t))

/*************************************************************
 * Helper functions
 *************************************************************/

/*************************************************************
 * API handlers
 *************************************************************/
/* This handles the case with the empty test_item. */ 
static const cryptoST_testDetail_t * nextTest
                (const cryptoST_testDetail_t * old)
{
    // Assume that if the pointer is in range, that it is legitimate.
    if (old >= test_item) 
    {
        old++; // repurpose: this is now "new"
        if (old >= &test_item[test_item_count-1])
            return old;
    }
    return NULL;
}

static const cryptoST_testDetail_t * firstTest(void)
{ return nextTest(test_item); }

static const char * openData(void)
{ return (test_item_count > 1)? 0 : "no data for RSA-PSS operation"; }

/*************************************************************
 * Declaration of the test manager API
 * Obligatory entry points for executing a test
 *************************************************************/
cryptoST_testAPI_t const CAVS11p2_sigGenPSS =
{
    .name = "RSA_" DATA_PACKAGE_NAME,
    .openData = openData,
    .firstTest = firstTest,
    .nextTest = nextTest,
    .closeData = ((void*)0),
};
