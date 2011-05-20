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
#if !defined(__CAN_IF_H)
#define __CAN_IF_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


#include "ComStack_Types.h"
#include "Can.h"

#if 0
#include "CanIf_Cfg.h"
#include "CanIf_Types.h"
#endif


/*
**  Published Information.
*/
#define CANIF_VENDOR_ID           AR_VENDOR_ID
#define CANIF_MODULE_ID           AR_MODULE_ID_CANIF
#define CANIF_INSTANCE_ID         0
#define CANIF_AR_MAJOR_VERSION    3
#define CANIF_AR_MINOR_VERSION    1
#define CANIF_AR_PATCH_VERSION    0
#define CANIF_SW_MAJOR_VERSION    1
#define CANIF_SW_MINOR_VERSION    0
#define CANIF_SW_PATCH_VERSION    0
#define CANIF_VENDOR_API_INFIX


/*
**  Service-IDs.
*/
#define AR_SERVICE_CANIF_INIT                       ((uint8)0x01)
#define AR_SERVICE_CANIF_INIT_CONTROLLER            ((uint8)0x02)
#define AR_SERVICE_CANIF_SETCONTROLLERMODE          ((uint8)0x03)
#define AR_SERVICE_CANIF_GETCONTROLLERMODE          ((uint8)0x04)
#define AR_SERVICE_CANIF_TRANSMIT                   ((uint8)0x05)
#define AR_SERVICE_CANIF_READRXPDUDATA              ((uint8)0x06)
#define AR_SERVICE_CANIF_READTXNOTIFSTATUS          ((uint8)0x07)
#define AR_SERVICE_CANIF_READRXNOTIFSTATUS          ((uint8)0x08)
#define AR_SERVICE_CANIF_SETPDUMODE                 ((uint8)0x09)
#define AR_SERVICE_CANIF_GETPDUMODE                 ((uint8)0x0a)
#define AR_SERVICE_CANIF_GETVERSIONINFO             ((uint8)0x0b)
#define AR_SERVICE_CANIF_SETDYNAMICTXID             ((uint8)0x0c)
#define AR_SERVICE_CANIF_SETTRANSCEIVERMODE         ((uint8)0x0d)
#define AR_SERVICE_CANIF_GETTRANSCEIVERMODE         ((uint8)0x0e)
#define AR_SERVICE_CANIF_GETTRCVWAKEUPREASON        ((uint8)0x0f)
#define AR_SERVICE_CANIF_SETTRANSCEIVERWAKEUPMODE   ((uint8)0x10)
#define AR_SERVICE_CANIF_CHECKWAKEUP                ((uint8)0x11)
#define AR_SERVICE_CANIF_CHECKVALIDATION            ((uint8)0x12)
#define AR_SERVICE_CANIF_TXCONFIRMATION             ((uint8)0x13)
#define AR_SERVICE_CANIF_RXINDICATION               ((uint8)0x14)
#define AR_SERVICE_CANIF_CANCELTXCONFIRMATION       ((uint8)0x15)
#define AR_SERVICE_CANIF_CONTROLLERBUSOFF           ((uint8)0x16)


/*
**  Global Types.
*/
typedef struct tagCanIf_ConfigType {
    uint8 dummy;
/*
    This type of the external data structure shall contain the post build initialization
    data for the CAN interface for all underlying CAN Drivers.

    The definition of the CAN Interface public parameters shall contain:
        - Number of transmit L-PDUs.
        - Number of receive L-PDUs.
        - Number of dynamic transmit L-PDU handles.

    The definition for each L-PDU handles shall contain:
        - Handle for transmit L-PDUs.
        - Handle for receive L-PDUs.
        - Name for transmit L-PDUs.
        - Name for receive L-PDUs.
        - CAN identifier for static and dynamic transmit L-PDUs.
        - CAN identifier for receive L-PDUs.
        - DLC for transmit L-PDUs.
        - DLC for receive L-PDUs.
        - Data buffer for receive L-PDUs in case of polling mode.
        - Network towards each L-PDU belongs to.
        - Transmit L-PDU handle type.
*/
} CanIf_ConfigType;

typedef struct tagCanIf_ControllerConfigType {
    uint8 dummy;
/*
    The contents of the initialization data structure are CAN interface specific
    for initialization of all CAN controllers related to the CAN network.

    This type of the external data structure shall contain the post build initialization
    data for the CAN Interface for all underlying CAN Drivers.

    The definition of CAN interface public parameters shall contain: s. o.

    Attention: Dynamic transmit L-PDUs are not part of this type definition.
*/
} CanIf_ControllerConfigType;

typedef enum tagCanIf_ControllerModeType {
    CANIF_CS_UNINIT,
    CANIF_CS_STOPPED,
    CANIF_CS_STARTED,
    CANIF_CS_SLEEP
} CanIf_ControllerModeType;

typedef enum tagCanIf_ChannelSetModeType {
    CANIF_SET_OFFLINE,
    CANIF_SET_RX_OFFLINE,
    CANIF_SET_RX_ONLINE,
    CANIF_SET_TX_OFFLINE,
    CANIF_SET_TX_ONLINE,
    CANIF_SET_ONLINE,
    CANIF_SET_TX_OFFLINE_ACTIVE
} CanIf_ChannelSetModeType;

typedef enum tagCanIf_PduGetModeType {
    CANIF_GET_OFFLINE,
    CANIF_GET_RX_ONLINE,
    CANIF_GET_TX_ONLINE,
    CANIF_GET_ONLINE,
    CANIF_GET_OFFLINE_ACTIVE,
    CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE
} CanIf_PduGetModeType;

typedef enum tagCanIf_NotifStatusType {
    CANIF_NO_NOTIFICATION,
    CANIF_TX_RX_NOTIFICATION
} CanIf_NotifStatusType;

typedef enum tagCanIf_TransceiverModeType {
    CANIF_TRCV_MODE_NORMAL,
    CANIF_TRCV_MODE_STANDBY,
    CANIF_TRCV_MODE_SLEEP
} CanIf_TransceiverModeType;

typedef enum tagCanIf_TrcvWakeupReasonType {
    CANIF_TRCV_WU_ERROR,
    CANIF_TRCV_WU_NOT_SUPPORTED,
    CANIF_TRCV_WU_BY_BUS,
    CANIF_TRCV_WU_INTERNALLY,
    CANIF_TRCV_WU_RESET,
    CANIF_TRCV_WU_POWER_ON
} CanIf_TrcvWakeupReasonType;

typedef enum tagCanIf_TrcvWakeupModeType {
    CANIF_TRCV_WU_ENABLE,
    CANIF_TRCV_WU_DISABLE,
    CANIF_TRCV_WU_CLEAR
} CanIf_TrcvWakeupModeType;


/*
**  Global Functions.
*/
FUNC(void,CANIF_CODE) CanIf_Init(P2CONST(CanIf_ConfigType,AUTOMATIC,CANIF_APPL_DATA) ConfigPtr);
FUNC(void,CANIF_CODE) CanIf_InitController(uint8 Controller,uint8 ConfigurationIndex);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_SetControllerMode(uint8 Controller,CanIf_ControllerModeType ControllerMode);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_GetControllerMode(uint8 Controller,
    P2VAR(CanIf_ControllerModeType,AUTOMATIC,CANIF_APPL_DATA) ControllerModePtr);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_Transmit(PduIdType CanTxPduId,P2CONST(PduInfoType,AUTOMATIC,CANIF_APPL_DATA) PduInfoPtr);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_ReadRxPduData(PduIdType CanRxPduId,P2VAR(PduInfoType,AUTOMATIC,CANIF_APPL_DATA) PduInfoPtr);
FUNC(CanIf_NotifStatusType,CANIF_CODE) CanIf_ReadTxNotifStatus(PduIdType CanTxPduId);
FUNC(CanIf_NotifStatusType,CANIF_CODE) CanIf_ReadRxNotifStatus(PduIdType CanRxPduId);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_SetPduMode(uint8 Controller,CanIf_ChannelSetModeType PduModeRequest);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_GetPduMode(uint8 Controller,P2VAR(CanIf_PduGetModeType,AUTOMATIC,CANIF_APPL_DATA) PduModePtr);

FUNC(void,CANIF_CODE) CanIf_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,CANIF_APPL_DATA) VersionInfo);

FUNC(void,CANIF_CODE) CanIf_SetDynamicTxId(PduIdType CanTxPduId,Can_IdType CanId);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_SetTransceiverMode(uint8 Transceiver,CanIf_TransceiverModeType TransceiverMode);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_GetTransceiverMode(uint8 Transceiver,
    P2VAR(CanIf_TransceiverModeType,AUTOMATIC,CANIF_APPL_DATA) TransceiverModePtr);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_GetTrcvWakeupReason(uint8 Transceiver,
    P2VAR(CanIf_TrcvWakeupReasonType,AUTOMATIC,CANIF_APPL_DATA) TrcvWuReasonPtr);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_SetTransceiverWakeupMode(uint8 Transceiver,CanIf_TrcvWakeupModeType TrcvWakeupMode);
#if 0
FUNC(Std_ReturnType,CANIF_CODE) CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
FUNC(Std_ReturnType,CANIF_CODE) CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource);
#endif
FUNC(void,CANIF_CODE) CanIf_TxConfirmation(PduIdType CanTxPduId);
FUNC(void,CANIF_CODE) CanIf_RxIndication(uint8 Hrh,Can_IdType CanId,uint8 CanDlc,
    P2CONST(uint8,AUTOMATIC,CANIF_APPL_DATA) CanSduPtr);
FUNC(void,CANIF_CODE) CanIf_CancelTxConfirmation(P2CONST(Can_PduType,AUTOMATIC,CANIF_APPL_DATA) PduInfoPtr);
FUNC(void,CANIF_CODE) CanIf_ControllerBusOff(uint8 Controller);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __CAN_IF_H */
