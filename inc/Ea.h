/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
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
 *
 */

#if !defined(__EA_H)
#define __EA_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "K_Ar.h"
#include "Ea_Cfg.h"
#include "kdk/common/Std_Types.h"
#include "Eep.h"


/*
**  Published Information.
*/
#define EA_VENDOR_ID                         AR_VENDOR_ID
#define EA_MODULE_ID                         AR_MODULE_ID_EA
#define EA_INSTANCE_ID                       0
#define EA_AR_MAJOR_VERSION                  3
#define EA_AR_MINOR_VERSION                  1
#define EA_AR_PATCH_VERSION                  0
#define EA_SW_MAJOR_VERSION                  1
#define EA_SW_MINOR_VERSION                  0
#define EA_SW_PATCH_VERSION                  0
#define EA_VENDOR_API_INFIX


/*
**
**  Service-IDs.
**
*/
#define AR_SERVICE_EA_INIT                  ((uint8)0)
#define AR_SERVICE_EA_SETMODE               ((uint8)1)
#define AR_SERVICE_EA_READ                  ((uint8)2)
#define AR_SERVICE_EA_WRITE                 ((uint8)3)
#define AR_SERVICE_EA_CANCEL                ((uint8)4)
#define AR_SERVICE_EA_GETSTATUS             ((uint8)5)
#define AR_SERVICE_EA_GETJOBRESULT          ((uint8)6)
#define AR_SERVICE_EA_INVALIDATEBLOCK       ((uint8)7)
#define AR_SERVICE_EA_GETVERSIONINFO        ((uint8)8)
#define AR_SERVICE_EA_ERASEIMMEDIATEBLOCK   ((uint8)9)
#define AR_SERVICE_EA_JOBENDNOTIFICATION    ((uint8)16)
#define AR_SERVICE_EA_JOBERRORNOTIFICATION  ((uint8)17)
#define AR_SERVICE_EA_MAINFUNCTION          ((uint8)18)


/*
**  Module Errors.
*/
#define EA_E_NOT_INITIALIZED                ((uint8)0x01)
#define EA_E_INVALID_BLOCK_NO               ((uint8)0x02)

/*
**  Global Types
*/
typedef struct tagEa_BlockConfigType {
        uint16 BlockSize;
        boolean ImmidiateData;
        uint16 NumberOfWriteCycles;
        uint8 DeviceIndex;
} Ea_BlockConfigType;


typedef struct tagEa_ConfigType {
    unsigned filler; /* Hardware and/or implementation specific. */
    Ea_BlockConfigType * BlockConfiguration;
} Ea_ConfigType;


/*
**  Global Functions.
*/
FUNC(void, EA_CODE) Ea_Init(P2CONST(Ea_ConfigType, AUTOMATIC, EA_APPL_DATA) ConfigPtr);
FUNC(void, EA_CODE) Ea_SetMode(MemIf_ModeType Mode);
FUNC(Std_ReturnType, EA_CODE) Ea_Read(uint16 BlockNumber, uint16 BlockOffset,
    P2VAR(uint8, AUTOMATIC, EA_APPL_DATA) DataBufferPtr, uint16 Length
);
FUNC(Std_ReturnType, EA_CODE) Ea_Write(uint16 BlockNumber, P2VAR(uint8, AUTOMATIC, EA_APPL_DATA) DataBufferPtr);
FUNC(void, EA_CODE) Ea_Cancel(void);
FUNC(MemIf_StatusType, EA_CODE) Ea_GetStatus(void);
FUNC(MemIf_JobResultType, EA_CODE) Ea_GetJobResult(void);
FUNC(Std_ReturnType, EA_CODE) Ea_InvalidateBlock(uint16 BlockNumber);
FUNC(Std_ReturnType, EA_CODE) Ea_EraseImmediateBlock(uint16 BlockNumber);
FUNC(void, EA_CODE) Ea_JobEndNotification(void);
FUNC(void, EA_CODE) Ea_JobErrorNotification(void);
FUNC(void, EA_CODE) Ea_MainFunction(void);


/*
** Global Function-like Macros.
*/
#if EA_GET_VERSION_INFO_API == STD_ON
#define Ea_GetVersionInfo(vp) AR_GET_VERSION_INFO(EA, vp)
#endif /* EA_GET_VERSION_INFO_API */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __EA_H */

