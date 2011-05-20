/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
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
 */
#if !defined(__CANTRCV_4711_PCA82C250_H)
#define __CANTRCV_4711_PCA82C250_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


#include "ComStack_Types.h"
#if 0
#include "CanTrcv_Cbk.h"
#endif

/*
**  Published Information.
*/
#define CANTRCV_4711_PCA82C250_VENDOR_ID           AR_VENDOR_ID
#define CANTRCV_4711_PCA82C250_MODULE_ID           AR_MODULE_ID_CANTRCV
#define CANTRCV_4711_PCA82C250_INSTANCE_ID         0
#define CANTRCV_4711_PCA82C250_AR_MAJOR_VERSION    3
#define CANTRCV_4711_PCA82C250_AR_MINOR_VERSION    1
#define CANTRCV_4711_PCA82C250_AR_PATCH_VERSION    0
#define CANTRCV_4711_PCA82C250_SW_MAJOR_VERSION    1
#define CANTRCV_4711_PCA82C250_SW_MINOR_VERSION    0
#define CANTRCV_4711_PCA82C250_SW_PATCH_VERSION    0
#define CANTRCV_4711_PCA82C250_VENDOR_API_INFIX    PCA82C250


/*
**  Error-Codes.
*/
#define CANTRCV_E_INVALID_CAN_NRTWORK       ((uint8)0x01)
#define CANTRCV_E_PARAM_POINTER             ((uint8)0x02)
#define CANTRCV_E_UNINIT                    ((uint8)0x11)
#define CANTRCV_E_TRCV_NOT_STANDBY          ((uint8)0x21)
#define CANTRCV_E_TRCV_NOT_NORMAL           ((uint8)0x22)
#define CANTRCV_E_PARAM_TRCV_WAKEUP_MODE    ((uint8)0x23)
#if 0   /* Error-Code assigned by SG. */
#define CANTRCV_E_NO_TRCV_CONTROL           ((uint8)0x??)
#endif


/*
**  Service-IDs.
*/
#define AR_SERVICE_CANTRCV_INIT             ((uint8)0x00)
#define AR_SERVICE_CANTRCV_SETOPMODE        ((uint8)0x01)
#define AR_SERVICE_CANTRCV_GETOPMODE        ((uint8)0x02)
#define AR_SERVICE_CANTRCV_GETBUSWUREASON   ((uint8)0x03)
#define AR_SERVICE_CANTRCV_GETVERSIONINFO   ((uint8)0x04)
#define AR_SERVICE_CANTRCV_SETWAKEUPMODE    ((uint8)0x05)
#define AR_SERVICE_CANTRCV_MAINFUNCTION     ((uint8)0x06)
#define AR_SERVICE_CANTRCV_CB_WAKEUPBYBUS   ((uint8)0x07)


typedef struct tagCanTrcv_PublicIfType {
    FUNC(void,CANTRCV_CODE) (*CanTrcv_Init)(void);
    FUNC(Std_ReturnType,CANTRCV_CODE) (*CanTrcv_SetOpMode)(CanIf_TransceiverModeType OpMode,uint8 CanNetwork);
    FUNC(Std_ReturnType,CANTRCV_CODE) (*CanTrcv_GetOpMode)(CanIf_TransceiverModeType *OpMode,uint8 CanNetwork);
    FUNC(Std_ReturnType,CANTRCV_CODE) (*CanTrcv_GetBusWuReason)(uint8 CanNetwork,CanIf_TrcvWakeupReasonType *Reason);
    FUNC(void,CANTRCV_CODE) (*CanTrcv_GetVersionInfo)(P2VAR(Std_VersionInfoType,AUTOMATIC,CANTRCV_APPL_DATA) Versioninfo);
    FUNC(Std_ReturnType,CANTRCV_CODE) (*CanTrcv_SetWakeupMode)(CanIf_TrcvWakeupModeType TrcvWakeupMode,uint8 CanNetwork);
    FUNC(void,CANTRCV_CODE) (*CanTrcv_MainFunction)(void);
    FUNC(Std_ReturnType,CANTRCV_CODE) (*CanTrcv_CB_WakeupByBus)(uint8 CanNetwork);
} CanTrcv_PublicIfType;


extern CONST(CanTrcv_PublicIfType,CANTRCV_CONST_UNSPECIFIED) MyCanTrcv_PublicIf;


#define CanTrcv_4711_PCA82C250_Init()                                      MyCanTrcv_PublicIf.CanTrcv_Init()
#define CanTrcv_4711_PCA82C250_SetOpMode(OpMode,CanNetwork)                MyCanTrcv_PublicIf.CanTrcv_SetOpMode(OpMode,CanNetwork)
#define CanTrcv_4711_PCA82C250_GetOpMode(OpMode,CanNetwork)                MyCanTrcv_PublicIf.CanTrcv_GetOpMode(OpMode,CanNetwork)
#define CanTrcv_4711_PCA82C250_GetBusWuReason(CanNetwork,Reason)           MyCanTrcv_PublicIf.CanTrcv_GetBusWuReason(CanNetwork,Reason)
#define CanTrcv_4711_PCA82C250_GetVersionInfo(Versioninfo)                 MyCanTrcv_PublicIf.CanTrcv_GetVersionInfo(Versioninfo)
#define CanTrcv_4711_PCA82C250_SetWakeupMode(TrcvWakeupMode,CanNetwork)    MyCanTrcv_PublicIf.CanTrcv_SetWakeupMode(TrcvWakeupMode,CanNetwork)
#define CanTrcv_4711_PCA82C250_MainFunction()                              MyCanTrcv_PublicIf.CanTrcv_MainFunction()
#define CanTrcv_4711_PCA82C250_CB_WakeupByBus(CanNetwork)                  MyCanTrcv_PublicIf.CanTrcv_CB_WakeupByBus(CanNetwork)


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* CANTRCV_4711_PCA82C250_H */
