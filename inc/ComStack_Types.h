/*
   k_os (Konnex Operating-System based on the OSEK/VDX-Standard).

   (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
                                       cpu12.gems@googlemail.com>

   All Rights Reserved

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   s. FLOSS-EXCEPTION.txt
 */
#if !defined(__COMSTACK_TYPES_H)
#define __COMSTACK_TYPES_H

#include "Std_Types.h"

#define COMSTACK_TYPES_VENDOR_ID        1
#define COMSTACK_TYPES_MODULE_ID        80
#define COMSTACK_TYPES_AR_MAJOR_VERSION 1
#define COMSTACK_TYPES_AR_MINOR_VERSION 0
#define COMSTACK_TYPES_AR_PATCH_VERSION 0
#define COMSTACK_TYPES_SW_MAJOR_VERSION 1
#define COMSTACK_TYPES_SW_MINOR_VERSION 0
#define COMSTACK_TYPES_SW_PATCH_VERSION 0
#define COMSTACK_VENDOR_API_INFIX       0

typedef uint8 PduIdType;

typedef uint16 PduLengthType;    /* if no Segmentation is used, this can be 'uint8'. */

typedef struct tagPduInfoType {
    /*
    ** Basic Information about PDUs of any Type.
    */
    uint8 *         SduDataPtr; /* todo: replace with 'P2VAR(uint8,AUTOMATIC,AUTOSAR_COMSTACKDATA) SduDataPtr,'     */
    PduLengthType   SduLength;
} PduInfoType;

typedef enum tagBufReq_ReturnType {
    BUFREQ_OK,
    BUFREQ_E_NOT_OK,
    BUFREQ_E_BUSY,
    BUFREQ_E_OVFL
} BufReq_ReturnType;

typedef uint8 NotifResultType;
/*
**
**  Result Status of a Notification (Confirmation or Indication).
**  -------------------------------------------------------------
**  0x00-0x1e   -   General return codes (s. below).
**  0x1f-0x3c   -   CanTp Error Notification Codes.
**  0x3d-0x5a   -   LinTp Error Notification Codes.
**  0x5b-0x78   -   FrTp Error Notification Codes.
**  > 0x78      -   Currently invalid, reserved for future usage.
**
*/
/* 0x00,0x01 - General Return Codes.                */
    #define NTFRSLT_OK                      ((uint8)0x00)
    #define NTFRSLT_E_NOT_OK                ((uint8)0x01)
/* 0x02-0x09 - Related to ISO 15765.                */
    #define NTFRSLT_E_TIMEOUT_A             ((uint8)0x02)
    #define NTFRSLT_E_TIMEOUT_BS            ((uint8)0x03)
    #define NTFRSLT_E_TIMEOUT_CR            ((uint8)0x04)
    #define NTFRSLT_E_WRONG_SN              ((uint8)0x05)
    #define NTFRSLT_E_INVALID_FS            ((uint8)0x06)
    #define NTFRSLT_E_UNEXP_PDU             ((uint8)0x07)
    #define NTFRSLT_E_WFT_OVRN              ((uint8)0x08)
    #define NTFRSLT_E_NO_BUFFER             ((uint8)0x09)
/* Cancelation API.                                 */
    #define NTFRSLT_E_CANCELATION_OK        ((uint8)0x0a)
    #define NTFRSLT_E_CANCELATION_NOT_OK    ((uint8)0x0b)
/*  0x0c-0x01e - Reserved values for future usage.  */

typedef uint8 BusTrcvErrorType;
/*
**
**  Bus Status evaluated by a Transceiver.
**  -------------------------------------------------------------
**  0x00-0x1e   -   General return codes (s. below).
**  0x1f-0x3c   -   CanTrcv Error Notification Codes.
**  0x3d-0x5a   -   LinTrcv Error Notification Codes.
**  0x5b-0x78   -   FrTrcv Error Notification Codes.
**  > 0x78      -   Currently invalid, reserved for future usage.
**
*/
    #define BUSTRCV_NO_ERROR                ((uint8)0x00)
    #define BUSTRCV_E_ERROR                 ((uint8)0x01)
/* 0x02-0x1e - Reserved values for future usage.    */

typedef uint8 NetworkHandleType;

#endif  /* __COMSTACK_TYPES_H */
