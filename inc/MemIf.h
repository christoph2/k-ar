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
#if !defined(__MEMIF_H)
#define __MEMIF_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "kdk/common/Std_Types.h"
#include "MemIf_Cfg.h"

/* TODO: Config!!! */
#include "Ea.h"
#if 0
#include "Fee.h"
#endif

/*
**  Published Information.
*/
#define MEMIF_VENDOR_ID                         AR_VENDOR_ID
#define MEMIF_MODULE_ID                         AR_MODULE_ID_MEMIF
#define MEMIF_INSTANCE_ID                       0
#define MEMIF_AR_MAJOR_VERSION                  3
#define MEMIF_AR_MINOR_VERSION                  1
#define MEMIF_AR_PATCH_VERSION                  0
#define MEMIF_SW_MAJOR_VERSION                  1
#define MEMIF_SW_MINOR_VERSION                  0
#define MEMIF_SW_PATCH_VERSION                  0
#define MEMIF_VENDOR_API_INFIX

/*
**
**  Service-IDs.
**
*/
#define AR_SERVICE_MEMIF_SETMODE                ((uint8)1)
#define AR_SERVICE_MEMIF_READ                   ((uint8)2)
#define AR_SERVICE_MEMIF_WRITE                  ((uint8)3)
#define AR_SERVICE_MEMIF_CANCEL                 ((uint8)4)
#define AR_SERVICE_MEMIF_GETSTATUS              ((uint8)5)
#define AR_SERVICE_MEMIF_GETJOBRESULT           ((uint8)6)
#define AR_SERVICE_MEMIF_INVALIDATEBLOCK        ((uint8)7)
#define AR_SERVICE_MEMIF_GETVERSIONINFO         ((uint8)8)
#define AR_SERVICE_MEMIF_ERASEIMMEDIATEBLOCK    ((uint8)9)

/*
**  Module-Errors.
*/
#define MEMIF_E_PARAM_DEVICE                    ((uint8)0x01)

/*
**  Global Constants.
*/
#define MEMIF_BROADCAST_ID                      ((uint8)0xff)

/*
**  Global Functions.
*/
FUNC(void, MEMIF_CODE) MemIf_SetMode(MemIf_ModeType Mode);

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read(uint8 DeviceIndex, uint16 BlockNumber, uint16 BlockOffset,
                                            P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr,
                                            uint16 Length
                                            );

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write(uint8 DeviceIndex, uint16 BlockNumber,
                                             P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr
                                             );

FUNC(void, MEMIF_CODE) MemIf_Cancel(uint8 DeviceIndex);

FUNC(MemIf_StatusType, MEMIF_CODE) MemIf_GetStatus(uint8 DeviceIndex);

FUNC(MemIf_JobResultType, MEMIF_CODE) MemIf_GetJobResult(uint8 DeviceIndex);

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_InvalidateBlock(uint8 DeviceIndex, uint16 BlockNumber);

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_EraseImmediateBlock(uint8 DeviceIndex, uint16 BlockNumber);

/*
** Global Function-like Macros.
*/
#if MEMIF_GET_VERSION_INFO_API == STD_ON
#define MemIf_GetVersionInfo(vp) AR_GET_VERSION_INFO(MEMIF, vp)
#endif /* MEMIF_GET_VERSION_INFO_API */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __MEMIF_H */
