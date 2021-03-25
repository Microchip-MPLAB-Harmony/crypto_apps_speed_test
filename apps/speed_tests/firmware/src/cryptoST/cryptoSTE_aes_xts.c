/*******************************************************************************
  Crypto Speed Test Source File

  Company:
    Microchip Technology Inc.

  File Name:
    cryptoST_aes_xts.c

  Summary:
    AES XTS mode encryption driver

  Description:
    This file contains functions to measure the time required 
    to perform AES XTS encryption. Time is reported in clock ticks.
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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "cryptoSTE_definitions.h"
#include "cryptoSTE_print.h"
#include "cryptoSTE_announce.h"
#include "../test_data/cryptoSpeedTestData.h"
// #include "cryptoSTE_aes_xts.h" -- don't include this

#include "configuration.h"
#include <wolfssl/wolfcrypt/settings.h>
// #include <wolfssl/wolfssl/verion.h>
#ifdef USE_FLAT_TEST_H
    #include "test.h"
#else
   // #include "wolfssl/wolfcrypt/test/test.h"
#endif
#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/des3.h>
#include <wolfssl/wolfcrypt/aes.h>
#include <wolfssl/wolfcrypt/wc_encrypt.h>

#if defined(WOLFSSL_AES_XTS)
#define assert_dbug(X) __conditional_software_breakpoint((X))

#if defined(HAVE_AES_CBC)
// *****************************************************************************
// *****************************************************************************
// Section: Local data structures
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Support routines
// *****************************************************************************
// *****************************************************************************
static void printAll(const char * context,
                     const cryptoST_testDetail_t * td, 
                     const byte * cipher, const byte * plain)
{
    const cryptoST_testVector_t * vector = td->rawData;
    
    printf(CRLF "AES_XTS data (%s)" CRLF, context);
    printf("%s" CRLF, td->source);

    cryptoST_PRINT_hexLine(CRLF "....msg   :", 
            vector->vector.data, vector->vector.length);
    cryptoST_PRINT_hexLine(CRLF "....key   :", 
            td->io.sym.in.key.data, td->io.sym.in.key.length);
    cryptoST_PRINT_hexLine(CRLF "....nonce :", 
            td->io.sym.in.ivNonce.data, td->io.sym.in.ivNonce.length);
    cryptoST_PRINT_hexLine(CRLF "....golden:",
            td->io.sym.out.cipher.data, td->io.sym.out.cipher.length);
    cryptoST_PRINT_hexLine(CRLF "....cipher:", cipher, vector->vector.length);
    if (plain)
        cryptoST_PRINT_hexLine(CRLF "....plain :", plain, vector->vector.length);
    printf(CRLF);
}

/* This is the generic encryption package.
 * The public entry points are defined below.
 *  */
static const char * cryptoSTE_aes_xts_timed(const cryptoST_testDetail_t * td,
                                      cryptoSTE_testExecution_t * param)
{
    const cryptoST_testVector_t * vector = td->rawData;
    
    if (CSTE_VERBOSE > 2)
    {
        P0_UINT( " data=", vector->vector.length);
        cryptoSTE_announceVector(2, vector);
        cryptoSTE_announceDetails(2, td);
    }
            
    // Data validation
    if ( (NULL == td->io.sym.in.key.data)
      || (NULL == td->io.sym.in.ivNonce.data) )
        return "missing vector, key or initialization data" CRLF
               "     AES XTS test not activated." CRLF;
    
    XtsAes enc;
    int ret;
    byte* cipher = (byte*)malloc(vector->vector.length);
    
    if (NULL == cipher)
        return "cannot allocate memory (" __BASE_FILE__ " line " BASE_LINE ")";
    
    ret = wc_AesXtsSetKey(
        &enc, 
        td->io.sym.in.key.data,         
        td->io.sym.in.key.length,
        AES_ENCRYPTION, 
        NULL, //void* heap 
        0);  // int devId
    if (ret != 0) return "failed to set key";
    
    // Hold off until the serial port is finished
    PRINT_WAIT_WHILE_BUSY();
    
    // Remove any data noise that is in the target buffer
    XMEMSET(cipher, 0, sizeof(cipher));
    param->results.encryption.iterations = param->parameters.iterationOverride? 
                                param->parameters.iterationOverride
                                  : td->recommendedRepetitions;
    param->results.encryption.size = vector->vector.length;
     
    param->results.encryption.start = SYS_TIME_CounterGet();
    for (int i = param->results.encryption.iterations; i > 0; i--)
    {
        ret = wc_AesXtsEncrypt(&enc, cipher, 
            vector->vector.data, 
            vector->vector.length, 
            (const byte*)td->io.sym.in.ivNonce.data, 16);
        
        if (ret != 0) return "encryption failed";
        
    }
    param->results.encryption.stop = SYS_TIME_CounterGet();
    param->results.encryption.startStopIsValid = true;
        
    if (param->parameters.verifyByGoldenCiphertext)
    {
        if ((0 == td->io.sym.out.cipher.data) || (0 == td->io.sym.out.cipher.length))
        { 
            param->results.warningCount++;
            param->results.warningMessage = 
                    "** can't verify cipher: no golden data"; 
        }
        else if (XMEMCMP(cipher, td->io.sym.out.cipher.data, td->io.sym.out.cipher.length))
        { 
            // Note: the test above will fail if iterate!=1.
            if (CSTE_VERBOSE)
                printAll("encrypt (" BASE_LINE ")", td, cipher, ((void*)0));
            return "computed ciphertext does not match golden data (was iterate==1?)";
        }
    }

#ifdef HAVE_AES_DECRYPT
    if (param->parameters.verifyByDecryption)
    {
        if (1 < param->results.encryption.iterations)
        {
            if (CSTE_VERBOSE > 1)
                PRINT_WAIT("-- verification skipped: cannot recover XTS counter" CRLF);
        }
        else
        {
            XtsAes dec;
            
            byte* plain = (byte*)malloc(vector->vector.length);
            if (NULL == plain)
                return "cannot allocate memory (" __BASE_FILE__ " line " BASE_LINE ")";
    
            ret = wc_AesXtsSetKey(
                &dec, 
                td->io.sym.in.key.data,         
                td->io.sym.in.key.length, 
                AES_DECRYPTION, 
                NULL, //void* heap 
                0);  // int devId
            if (ret != 0) return "setting decryption key failed";

            if (CSTE_VERBOSE > 1) 
                PRINT_WAIT("-- decrypting and comparing" CRLF);

            ret = wc_AesXtsDecrypt(&dec, plain, cipher,
                  vector->vector.length, 
                  (const byte*)td->io.sym.in.ivNonce.data, 16);
        
            if (ret != 0)
                return "decryption failed";

            if (XMEMCMP(plain, vector->vector.data, vector->vector.length))
            {
                if (CSTE_VERBOSE)
                    printAll("decrypt (" BASE_LINE ")",
                             td, cipher, plain);
                return "recovered data does not match original";
            }
            free(plain);
        }
    }
#endif /* HAVE_AES_DECRYPT */
    free(cipher);
    return 0;
}

// *****************************************************************************
// *****************************************************************************
// Section: External API
// *****************************************************************************
// *****************************************************************************

#undef TNAME
#define TNAME "WOLF AES XTS 128"
const char * cryptoSTE_aes_xts_128_timed(const cryptoST_testDetail_t * td,
                                   cryptoSTE_testExecution_t * param)
{
    param->results.testHandler = TNAME;
    if (CSTE_VERBOSE > 1) PRINT(CRLF);

    // Data validation
    if (td->io.sym.in.key.length != 2*128/8)
        return "incorrect key length" CRLF
               "     " TNAME " test not activated." CRLF;
    else
        return cryptoSTE_aes_xts_timed(td, param);
}
/*
#undef TNAME
#define TNAME "WOLF AES XTS 192"
const char * cryptoSTE_aes_xts_192_timed(const cryptoST_testDetail_t * td,
                                   cryptoSTE_testExecution_t * param)
{
    param->results.testHandler = TNAME;
    if (CSTE_VERBOSE > 1) PRINT(CRLF);

    // Data validation
    if (td->io.sym.in.key.length != 2*192/8)
        return "incorrect key length" CRLF
               "     " TNAME " test not activated." CRLF;
    else
        return cryptoSTE_aes_xts_timed(td, param);
}
*/
#undef TNAME
#define TNAME "WOLF AES XTS 256"
const char * cryptoSTE_aes_xts_256_timed(const cryptoST_testDetail_t * td,
                                   cryptoSTE_testExecution_t * param)
{
    param->results.testHandler = TNAME;
    if (CSTE_VERBOSE > 1) PRINT(CRLF);

    // Data validation
    if (td->io.sym.in.key.length != 2*256/8)//The AES key and tweak key are one field
        return "incorrect key length" CRLF
               "     " TNAME " test not activated." CRLF;
    else
        return cryptoSTE_aes_xts_timed(td, param);
}

#endif // HAVE_AES_CBC

#endif // WOLFSSL_AES_XTS
