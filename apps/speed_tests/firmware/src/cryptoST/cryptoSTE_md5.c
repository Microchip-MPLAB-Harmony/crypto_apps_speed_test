/*******************************************************************************
  Crypto Speed Test Source File

  Company:
    Microchip Technology Inc.

  File Name:
    cryptoSTE_md5.c

  Summary:
    MD5 mode hash driver

  Description:
    This file contains functions to measure the time required 
    to perform MD5 hashing. Time is reported in clock ticks.
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

// theory: one of these "fixes" build-time issues with wolfssl
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "cryptoSTE_malloc.h"
#include <wolfssl/wolfcrypt/types.h>

#include "configuration.h"
#include <wolfssl/wolfcrypt/settings.h>

#define assert_dbug(X) __conditional_software_breakpoint((X))

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

#if !defined(NO_MD5)
/* This is the generic encryption package.
 * The public entry points are defined below.
 *  */
static const char * cryptoSTE_md5(const cryptoST_testDetail_t * td,
                                       cryptoSTE_testExecution_t * param,
                                       cryptoSTE_shaOperator_t * hash_operator)
{
    const cryptoST_testVector_t * vector = td->rawData;
    
    if (CSTE_VERBOSE > 2)
    {
        P0_UINT( " data=", vector->vector.length);
        cryptoSTE_announceVector(2, vector);
        cryptoSTE_announceDetails(2, td);
    }
            
    param->results.encryption.size = vector->vector.length;

    // Hold off until the serial port is finished
    PRINT_WAIT_WHILE_BUSY();

    param->results.encryption.iterations = param->parameters.iterationOverride? 
                                    param->parameters.iterationOverride
                                  : td->recommendedRepetitions;

    assert_dbug(0 < td->io.hash.out.hash.length);
    uint32_t hash[td->io.hash.out.hash.length];// room for expected size
    do
    {
        param->results.encryption.start = SYS_TIME_CounterGet();        
        for (int i = param->results.encryption.iterations; i > 0; i--)
        {
            int ret = hash_operator(hash,
                                    vector->vector.data,
                                    vector->vector.length);
            if (0 != ret)
            {
                param->results.errorMessage = "hash operator failed";
                param->results.wolfSSLresult = ret;
                break;
            }
        }
        param->results.encryption.stop = SYS_TIME_CounterGet();
        if (param->results.errorMessage) break; // out of the test routine
        param->results.encryption.startStopIsValid = true;

        if (param->parameters.verifyByGoldenCiphertext)
        {
            if(td->io.hash.out.hash.data == NULL)
                param->results.warningCount++,
                param->results.warningMessage = "can't verify cipher: no golden data"; 
            else if (XMEMCMP(hash, td->io.hash.out.hash.data, td->io.hash.out.hash.length))
            { 
                param->results.errorMessage = "computed hash does not match golden data";
                if (CSTE_VERBOSE)
                {
                    cryptoST_PRINT_hexLine(CRLF "..cipher:", 
                            (uint8_t*)hash, sizeof(hash)/4);//over four: hash is an int array with an int for every byte in the result
                    cryptoST_PRINT_hexLine(CRLF "..golden:",
                            td->io.hash.out.hash.data, td->io.hash.out.hash.length);
                    PRINT_WAIT(CRLF);
                }
                break; 
            }
        }
    } while(0);
    
    return param->results.errorMessage;
}
#endif // !defined(NO_MD5)

/* *********************************************************************
   *********************************************************************
   * WolfCrypt software test drivers
   *********************************************************************
   *********************************************************************
 */
#if !defined(NO_MD5) 
#include "wolfssl/wolfcrypt/hash.h"
static int WC_md5
    (uint32_t hash[128/32], const uint8_t * data, const size_t length)
{    
    return wc_Md5Hash(data, length, (uint8_t*)hash);
}
#endif

// *****************************************************************************
// *****************************************************************************
// Section: External API
// *****************************************************************************
// *****************************************************************************
#if !defined(NO_MD5) 
const char * cryptoSTE_crya_md5_timed(const cryptoST_testDetail_t * td,
                                      cryptoSTE_testExecution_t * param)
{
    param->results.testHandler = "WOLF MD5    ";
    return cryptoSTE_md5(td, param, WC_md5);                                          
                                          
}
#endif