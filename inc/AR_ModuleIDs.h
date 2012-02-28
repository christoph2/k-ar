/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
 *                                     cpu12.gems@googlemail.com>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined(__AR_MODULE_IDS_H)
#define __AR_MODULE_IDS_H

#define AR_MODULE_ID_OS         1       /* OS                                */

#define AR_MODULE_ID_ECUM       10      /* ECU State Manager                 */
#define AR_MODULE_ID_FIM        11      /* Function Inhibition Manager       */
#define AR_MODULE_ID_COMM       12      /* COM Manager                       */
#define AR_MODULE_ID_WDGM       13      /* Watchdog Manager                  */
#define AR_MODULE_ID_DET        15      /* Development Error Tracer          */

#define AR_MODULE_ID_NVM        20      /* NVRAM Manager                     */
#define AR_MODULE_ID_FEE        21      /* Flash EEPROM Emulation            */
#define AR_MODULE_ID_MEMIF      22      /* Memory Abstraction Interface      */
#define AR_MODULE_ID_NM         29      /* Generic NM Interface              */

#define AR_MODULE_ID_CANNM      31      /* CAN NM                            */
#define AR_MODULE_ID_FRNM       32      /* FlexRay NM                        */
#define AR_MODULE_ID_CANTP      35      /* CAN Transport Layer               */
#define AR_MODULE_ID_FRTP       36      /* FlexRay Transport Layer           */

#define AR_MODULE_ID_EA         40      /* EEPROM Abstraction                */
#define AR_MODULE_ID_WDGIF      43      /* Watchdog Interface                */

#define AR_MODULE_ID_COM        50      /* AUTOSAR COM                       */
#define AR_MODULE_ID_PDUR       51      /* PDU Router                        */
#define AR_MODULE_ID_IPDUM      52      /* IPDU Multiplexer                  */
#define AR_MODULE_ID_DCM        53      /* Diagnostic Communication Manager  */
#define AR_MODULE_ID_DEM        54      /* Diagnostic Event Manager          */

#define AR_MODULE_ID_CANIF      60      /* CAN Interface                     */
#define AR_MODULE_ID_FRIF       61      /* FlexRay Interface                 */
#define AR_MODULE_ID_LINIF      62      /* LIN Interface                     */
#define AR_MODULE_ID_LINNM      63      /* LIN NM                            */

#define AR_MODULE_ID_CANTRCV    70      /* CAN Tranceiver Driver             */
#define AR_MODULE_ID_FRTRCV     71      /* FlexRay Tranceiver Driver         */

#define AR_MODULE_ID_CAN        80      /* Can Driver                        */
#define AR_MODULE_ID_FR         81      /* FlexRay Driver                    */
#define AR_MODULE_ID_LIN        82      /* LIN Driver                        */
#define AR_MODULE_ID_SPI        83      /* SPI Handler Driver                */

#define AR_MODULE_ID_EEP        90      /* Internal/External EEPROM Driver   */
#define AR_MODULE_ID_FLS        92      /* Internal/External FLASH Driver    */
#define AR_MODULE_ID_RAMTST     93      /* RAM Test                          */

#define AR_MODULE_ID_GPT        100     /* GPT Driver                        */
#define AR_MODULE_ID_MCU        101     /* MCU Driver                        */
#define AR_MODULE_ID_WDG        102     /* Internal/External Watchdog Driver */

#define AR_MODULE_ID_DIO        120     /* DIO Driver                        */
#define AR_MODULE_ID_PWM        121     /* PWM Driver                        */
#define AR_MODULE_ID_ICU        122     /* ICU Driver                        */
#define AR_MODULE_ID_ADC        123     /* ADC Driver                        */
#define AR_MODULE_ID_PORT       124     /* Port Driver                       */

#define AR_MODULE_ID_SCHM       130     /* BSW Scheduler Module              */

#define AR_MODULE_ID_CANSM      140     /* CAN State Manager                 */
#define AR_MODULE_ID_LINSM      141     /* LIN State Manager                 */
#define AR_MODULE_ID_FRSM       142     /* FlexRay State Manager             */

#define AR_MODULE_ID_CRC        201     /* CRC Routines                      */

#define AR_MODULE_ID_C2CAN      220     /* CAN                               */
#define AR_MODULE_ID_C2COM      221     /* COM Services                      */
#define AR_MODULE_ID_C2DIAG     222     /* Diagnostic                        */
#define AR_MODULE_ID_C2FW       223     /* ECU Firmware                      */
#define AR_MODULE_ID_C2FR       224     /* Flexray                           */
#define AR_MODULE_ID_C2LIN      225     /* LIN                               */
#define AR_MODULE_ID_C2MMGT     226     /* Mode Management                   */
/*
    I/O Hardware        no prefix           254
    Abstraction         (AUTOSAR Interface)

    Complex Drivers     no prefix           255
                        (AUTOSAR Interface)
 */

#endif  /* __AR_MODULE_IDS_H */
