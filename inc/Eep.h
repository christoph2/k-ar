/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2014 by Christoph Schueler <github.com/Christoph2,
 *                                      cpu12.gems@googlemail.com>
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
 * s. FLOSS-EXCEPTION.txt
 */

#if !defined(__EEP_H)
#define __EEP_H

#include "kdk/common/Std_Types.h"
#include "Eep_Cfg.h"

#if 0
#include "Spi.h"
#endif


#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Published Information.
*/
#define EEP_VENDOR_ID                   AR_VENDOR_ID
#define EEP_MODULE_ID                   AR_MODULE_ID_EEP
#define EEP_INSTANCE_ID                 0
#define EEP_AR_MAJOR_VERSION            3
#define EEP_AR_MINOR_VERSION            1
#define EEP_AR_PATCH_VERSION            0
#define EEP_SW_MAJOR_VERSION            1
#define EEP_SW_MINOR_VERSION            0
#define EEP_SW_PATCH_VERSION            0
#define EEP_VENDOR_API_INFIX

/* Folgendes nur exemplarisch!!! Die Werte müssen vom entsprechenden Treiber geliefert werden. */
#define EEP_ALLOWED_WRITE_CYCLES        10000
#define EEP_ERASE_TIME                  0.00005
#define EEP_ERASE_UNIT_SIZE             4
#define EEP_ERASE_VALUE                 0xff
#define EEP_MINIMUM_ADDRESS_SIZE        16
#define EEP_MINIMUM_LENGTH_TYPE         8
#define EEP_READ_UNIT_SIZE              1
#define EEP_SPECIFIED_ERASE_CYCLES      10000
#define EEP_TOTAL_SIZE                  0x1000
#define EEP_WRITE_TIME                  0.00003
#define EEP_WRITE_UNIT_SIZE             2


/*
**
**  Service-IDs.
**
*/
#define AR_SERVICE_EEP_INIT             ((uint8)0)
#define AR_SERVICE_EEP_SETMODE          ((uint8)1)
#define AR_SERVICE_EEP_READ             ((uint8)2)
#define AR_SERVICE_EEP_WRITE            ((uint8)3)
#define AR_SERVICE_EEP_ERASE            ((uint8)4)
#define AR_SERVICE_EEP_COMPARE          ((uint8)5)
#define AR_SERVICE_EEP_CANCEL           ((uint8)6)
#define AR_SERVICE_EEP_GETSTATUS        ((uint8)7)
#define AR_SERVICE_EEP_GETJOBRESULT     ((uint8)8)
#define AR_SERVICE_EEP_MAINFUNCTION     ((uint8)9)
#define AR_SERVICE_EEP_GETVERSIONINFO   ((uint8)10)

/*
**  Module-Errors.
*/
#define EEP_E_PARAM_CONFIG              ((uint8)0x10)
#define EEP_E_PARAM_ADDRESS             ((uint8)0x11)
#define EEP_E_PARAM_DATA                ((uint8)0x12)
#define EEP_E_PARAM_LENGTH              ((uint8)0x13)
#define EEP_E_UNINIT                    ((uint8)0x20)
#define EEP_E_BUSY                      ((uint8)0x21)
#if 0
/* assigned by DEM */
#define EEP_E_ERASE_FAILED
#define EEP_E_WRITE_FAILED
#define EEP_E_READ_FAILED
#define EEP_E_COMPARE_FAILED
#endif

/*
**  Global Types.
*/

/* Used as address offset from the configured EEPROM base address to access a certain EEPROM memory area. */
typedef uint16 Eep_AddressType;

/* Specifies the number of bytes to read/write/erase/compare. */
typedef uint16 Eep_LengthType;

/* This is the type of the external data structure containing the initialization data for the EEPROM driver. */
typedef struct tagEep_ConfigType {
    /* The contents of the initialisation data structure are EEPROM specific. */
    uint8 dummy;
} Eep_ConfigType;


typedef struct tagEep_PublicInterface {
    void (*Init)(Eep_ConfigType ConfigPtr);
} Eep_PublicInterface;

/*
**  Global Functions.
*/
FUNC(void, EEP_CODE) Eep_Init(
    P2CONST(Eep_ConfigType, AUTOMATIC, EEP_APPL_DATA) ConfigPtr
);

FUNC(void, EEP_CODE) Eep_SetMode(MemIf_ModeType Mode);

FUNC(Std_ReturnType, EEP_CODE) Eep_Read(
    Eep_AddressType EepromAddress,
    P2VAR(uint8, AUTOMATIC, EEP_APPL_DATA) DataBufferPtr,
    Eep_LengthType Length
);

FUNC(Std_ReturnType, EEP_CODE) Eep_Write(
    Eep_AddressType EepromAddress,
    P2CONST(uint8, AUTOMATIC, EEP_APPL_DATA) DataBufferPtr,
    Eep_LengthType Length
);

FUNC(Std_ReturnType, EEP_CODE) Eep_Erase(
    Eep_AddressType EepromAddress,
    Eep_LengthType Length
);

FUNC(Std_ReturnType, EEP_CODE) Eep_Compare(
    Eep_AddressType EepromAddress,
    P2CONST(uint8, AUTOMATIC, EEP_APPL_DATA) DataBufferPtr,
    Eep_LengthType Length
);

FUNC(void, EEP_CODE) Eep_Cancel(void);

FUNC(MemIf_StatusType, EEP_CODE) Eep_GetStatus(void);

FUNC(MemIf_JobResultType, EEP_CODE) Eep_GetJobResult(void);

FUNC(void, EEP_CODE) Eep_MainFunction(void);

/*
** Global Function-like Macros.
*/
#if EEP_GET_VERSION_INFO_API == STD_ON
#define Eep_GetVersionInfo(vp) AR_GET_VERSION_INFO(EEP, vp)
#endif /* EEP_GET_VERSION_INFO_API */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __EEP_H */
