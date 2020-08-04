# Introduction
Extensible crypto module speed test framework.

# Description
This demonstration exercises several cryptographic functions, including TDES, DES, SHA 128-512, AES, and RSA, to verify that the software or hardware is performing correctly and to determine the speed of each function for various data sizes. Data is taken from Microchip example code, NSA test vectors, and other sources.
# Building the Application
To build the application, the project corresponding to the test hardware must be opened in MPLAB X IDE. The following table lists projects and supported configurations. The parent folder for these files is crypto/apps/encrypt_decrypt/firmware.

## MPLAB X IDE Projects
This table lists the name and location of the MPLAB X IDE project folder for the demonstration.

| Project Name | BSP Used | Description |
| --- | --- | ---|
| sam_e54_xplained_pro_hw.X | sam_e54_xplained_pro | SpeedTest project using the SAME54 and hardware cryptography|
| sam_e54_xplained_pro_hwsw.X | sam_e54_xplained_pro | SpeedTest project using the SAME54 and software cryptography|
| sam_e70_xplained_ultra_hw.X | sam_e70_xplained_ultra | SpeedTest project using the SAME70 and hardware cryptography|
| sam_e70_xplained_ultra_sw.X | sam_e70_xplained_ultra | SpeedTest project using the SAME70 and software cryptography|
| sam_l11_xplained_pro_hw.X | sam_l11_xplained_pro | SpeedTest project using the SAML11 and hardware cryptography|
| sam_l11_xplained_pro_hwsw.X | sam_l11_xplained_pro | SpeedTest project using the SAML11 and software cryptography|
| sam_l21_xplained_pro_hw.X | sam_l21_xplained_pro | SpeedTest project using the SAML21 and hardware cryptography|
| sam_l21_xplained_pro_sw.X | sam_l21_xplained_pro | SpeedTest project using the SAML21 and software cryptography|

The application is built by using the standard MPLAB X IDE buttons.

# Configuring the Hardware
Refer to the following pages to configure the hardware:
* [SAM E54 Xplained Pro](../../../crypto/wiki/Configuring-the-SAM-E54-Xplained-Pro-Board)
* [SAM E70 Xplained Ultra](../../../crypto/wiki/Configuring-the-SAM-E70-Xplained-Ultra-Board)
* [SAM L11 Xplained Ultra](../../../crypto/wiki/Configuring-the-SAM-L11-Xplained-Pro-Board)
* [SAM L21 Xplained Pro](../../../crypto/wiki/Configuring-the-SAM-L21-Xplained-Pro-Board)


# Running the Demonstration
1. Connect the board to the PC as described in the 'Configuring the Hardware' section.
2. Configure a terminal application (ex. Tera Term) to access the newly attached serial port:
	* 115,200 bps
	* 8 data bits
	* no parity
	* 1 stop bit
	* no flow control
3. Compile the demonstration using MPLAB X
	* Use the standard MPLAB X IDE Buttons
4. Observe or capture the output from the serial console.

# Application Output

The demonstration runs in two phases. In the first phase, each data set is exercised and the results are checked against known-good cipher text (when available). Encryption drivers also decrypt the cipher and verify against the original plain text. These calculations are not timed.

The second phase repeats each data set multiple times to get a statistical average of run-time, but does not check the results. Most functions are repeated 1000 times, but long-running operations (like RSA) may have as few as 5 or 10 repetitions.

Test results output lines begin with ">>". The 2nd phase output is in CSV file format and can be imported to Excel, including any error or warning messages. Each project will have different timing results.

An example is shown in the following figure. 
![Results (TODO FIXME)](images/EncryptDecryptResults.png)

