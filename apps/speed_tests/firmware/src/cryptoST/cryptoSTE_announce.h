/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    cryptoSTE_announce.h

  Summary:
    Public information for the BenchMark suite test logic.

  Description:
    Public entry points and data structures for the CryptoST test suite.
*******************************************************************************/

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

#ifndef CRYPTOST_ANNOUNCE_H
#define	CRYPTOST_ANNOUNCE_H

#ifdef	__cplusplus
extern "C" {
#endif

// #include "../test_data/cryptoSpeedTestData.h"
#include "cryptoSTE_definitions.h"

void cryptoSTE_announceDetails(int level, const cryptoST_testDetail_t *);
void cryptoSTE_announceVector(int level, const cryptoST_testVector_t *);
void cryptoSTE_announceSuite(const cryptoST_testAPI_t *);
void cryptoSTE_announceAll(cryptoSTE_localData_t *);

void cryptoSTE_announceParameters(cryptoSTE_testExecution_t * config);

#ifdef	__cplusplus
}
#endif

#endif	/* CRYPTOST_ANNOUNCE_H */

