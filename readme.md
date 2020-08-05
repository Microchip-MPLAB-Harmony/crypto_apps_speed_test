---
title: Crypto SpeedTest Applications
has_children: true
has_toc: false
nav_order: 1
---

![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)

# MPLAB® Harmony 3 Crypto SpeedTest Application Examples

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating
embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller
and microprocessor devices. Refer to the following links for more information.

- [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
- [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
- [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
- [Microchip MPLAB Harmony](https://www.microchip.com/mplab/mplab-harmony)
- [Microchip MPLAB Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 Cryptography SpeedTest application examples

- [Release Notes](release_notes.md)
- [MPLAB® Harmony License](mplab_harmony_license.md)

To clone or download these application from Github,go to the [main page of this repository](https://bitbucket.microchip.com/projects/MH3/repos/crypto_apps_speed_test) and then click Clone button to clone this repo or download as zip file. This content can also be download using content manager by following [these instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki)

## Contents Summary

| Folder     | Description                             |
| ---        | ---                                     |
| apps       | SpeedTest example applications    |
| docs       | Applications help documentation         |

Building and running a SpeedTest application is described in [these instructions](./apps/speed_tests/readme.md).

# Speed comparison
Selected samples of data determined by the speedTest demo programs. The values shown were obtained by running the demo programs on Xplained or Curiosity hardware and are intended only for the purpose of demonstrating program results. Results realized in any specific application depend on Harmony3 configuration options and package revisions, settings of the compiler, MCU configuration (such as clock speed), and on operational factors such as operating system and interrupt tasking.

||||SAME54|SAME70|SAML11|SAML21||SAME54|SAME70|SAML11|SAML21|
|---|---|---|---|---|---|---|---|---|---|---|---|
||||Software only|||||Hardware accelerated||
|Clock speed||(MHz)|120|300|32|48||120|300|32|48|
|Accelerator||||||||PUKCC,AES256,ICM|AES256,ICM|CRYA|AES256|
|Test|Data size (bytes)|||||||||||
|AES CFB 192|64|(Mbps)|0.7033|4.2764|---|0.1288||4.5554|16.7435|---|0.8479|
|AES CFB 256|64|(Mbps)|0.6235|3.8299|---|0.1585||4.2705|16.2696|---|0.8096|
|AES CTR 128|64|(Mbps)|0.7965|4.5631|---|0.1643||9.0307|11.9741|---|2.5314|
|AES CTR 192|64|(Mbps)|0.6957|4.0551|---|0.1462||8.5626|10.6191|---|2.3776|
|AES CTR 256|64|(Mbps)|0.6176|3.6473|---|0.1317||7.8854|9.2972|---|2.2777|
|AES GCM 128|2944|(Mbps)|0.2903|1.1774|---|0.0677||13.0350|31.8273|---|4.0363|
|SHA 256|3|(Mbps)|0.1083|0.5757|0.0105|0.0239||0.1165|0.3883|0.0176|0.0239|
|SHA 256|112|(Mbps)|1.1633|6.0204|0.1050|0.2390||1.6913|5.0873|0.1769|0.2389|
|SHA 384|3|(Mbps)|0.0887|0.3785|0.2085|0.0127||0.1103|11.0681|0.3755|0.0127|
|SHA 384|112|(Mbps)|0.8621|3.7801|0.0032|0.1235||1.6141|0.0561|0.0032|0.1229|
|SHA 512|3|(Mbps)|0.0788|0.3581|0.0613|0.0120||0.1097|1.1082|0.0613|0.0120|
|SHA 512|112|(Mbps)|0.8091|3.6748|0.0032|0.1199||1.6040|0.0534|0.0032|0.1194|
|AES ECB 128|5120|(Mbps)|0.8406|5.1478|0.0611|0.1772||14.4751|1.0950|0.0611|4.7271|
|DES3 CBC|448|(Mbps)|0.1983|1.1667|0.0458|0.0519||0.1991|1.1674|0.0458|0.0520|
|WOLF RSA VERIFY256|19|(ms)|32.4509|6.8676|---|---||4.5930|6.7060|---|---|
|WOLF RSA SIGN256|19|(ms)|1755.4227|368.1773|---|---||1771.7726|374.3926|---|---|

____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_uart/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/bootloader_apps_uart.svg)](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_uart/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/bootloader_apps_uart.svg)](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_uart/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/bootloader_apps_uart.svg)](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_uart/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/bootloader_apps_uart.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/bootloader_apps_uart.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/bootloader_apps_uart.svg?style=social)]()
