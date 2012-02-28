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
#if !defined(__CAN_H)
#define __CAN_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "ComStack_Types.h"
#include "Can_Cfg.h"
#include "K_Ar.h"

/*
**  Published Information.
*/
#define CAN_VENDOR_ID                                   AR_VENDOR_ID
#define CAN_MODULE_ID                                   AR_MODULE_ID_CAN
#define CAN_INSTANCE_ID                                 CAN_INDEX
#define CAN_AR_MAJOR_VERSION                            3
#define CAN_AR_MINOR_VERSION                            1
#define CAN_AR_PATCH_VERSION                            0
#define CAN_SW_MAJOR_VERSION                            1
#define CAN_SW_MINOR_VERSION                            0
#define CAN_SW_PATCH_VERSION                            0
#define CAN_VENDOR_API_INFIX

/*
**  Development Error Codes.
*/
#define CAN_E_PARAM_POINTER                             ((uint8)0x01)
#define CAN_E_PARAM_HANDLE                              ((uint8)0x02)
#define CAN_E_PARAM_DLC                                 ((uint8)0x03)
#define CAN_E_PARAM_CONTROLLER                          ((uint8)0x04)
#define CAN_E_UNINIT                                    ((uint8)0x05)
#define CAN_E_TRANSITION                                ((uint8)0x06)

/*
**  Service-IDs.
*/
#define AR_SERVICE_CAN_INIT                             ((uint8)0x00)
#define AR_SERVICE_CAN_GET_VERSION_INFO                 ((uint8)0x07)
#define AR_SERVICE_CAN_INIT_CONTROLLER                  ((uint8)0x02)
#define AR_SERVICE_CAN_SET_CONTROLLER_MODE              ((uint8)0x03)
#define AR_SERVICE_CAN_DISABLE_CONTROLLER_INTERRUPTS    ((uint8)0x04)
#define AR_SERVICE_CAN_ENABLE_CONTROLLER_INTERRUPTS     ((uint8)0x05)
#define AR_SERVICE_CAN_CBK_CHECK_WAKEUP                 ((uint8)0x0b)
#define AR_SERVICE_CAN_WRITE                            ((uint8)0x06)
#define AR_SERVICE_CAN_MAIN_FUNCTION_WRITE              ((uint8)0x01)
#define AR_SERVICE_CAN_MAIN_FUNCTION_READ               ((uint8)0x08)
#define AR_SERVICE_CAN_MAIN_FUNCTION_BUSOFF             ((uint8)0x09)
#define AR_SERVICE_CAN_MAIN_FUNCTION_WAKEUP             ((uint8)0x0a)

/*
**  Global Defines / Non-AUTOSAR.
*/
#define CAN_SET_EXTENDED_ID(id) ((id)   |=  0x80000000UL)
#define CAN_CLR_EXTENDED_ID(id) ((id)   &= ~0x80000000UL)
#define CAN_IS_EXTENDED_ID(id)  ((((id) &   0x80000000UL) == 0x80000000UL) ? TRUE : FALSE)

#define CAN_SET_RTR(id)         ((id)   |=  0x40000000UL)
#define CAN_CLR_RTR(id)         ((id)   &= ~0x40000000UL)
#define CAN_IS_RTR(id)          ((((id) &   0x40000000UL) == 0x40000000UL) ? TRUE : FALSE)
/* !REQ!AR!CAN237:"The Can module does not support CAN remote Frames.   */
/* The Can module shall not process received remote frames."            */
/*
**
**  Remote Frames are not supported by AUTOSAR, ISO 15765, SAE J1339-21...
**  but needed for CAN Application Layer.
**
*/

/*
**  Convinience macros.
*/
#define CAN_EXTENDED_INDENTIFIER(id)    CAN_SET_EXTENDED_ID((id))
#define CAN_STANDARD_INDENTIFIER(id)    (id) & 0x7ff

#define CAN_NORMALIZE_DLC(dlc)          (((dlc) & BIT3) == BIT3) ? BIT3 : (dlc)
/* According to [2] 8.4.3 Table 4:                              */
/* if DLC-Bit #3 is set the remaining bits are don't care,      */
/* i.e. every bit combination has to be interpreted as eight.   */

/*
**  Global Types for CAN-Driver-Module.
*/
typedef struct tagCan_ConfigType {
    uint8 dummy;
} Can_ConfigType;

#define CAN_THREE_SAMPLES_PER_BIT STD_ON

#define S12CAN_MAKE_BTR0(sjw, bpr)                                 \
    (((uint8)(sjw) - (uint8)0x01) & (uint8)0x03) << (uint8)0x06) | \
    (((uint8)(bpr) - (uint8)0x01) & (uint8)0x3f)

#define S12CAN_MAKE_BTR1(tsmp, ps, seg1, seg2)                     \
    (((tsmp) == STD_ON) ? (uint8)0x80 : (uint8)0x00) |             \
    ((((uint8)(seg2)  - (uint8)1) & (uint8)0x07) << (uint8)0x04) | \
    (((uint8)(seg1) + (uint8)(ps)   - (uint8)1) & (uint8)0x0f)

#if 0
(Prescaler value)
Bit Time = ----------------------  (1 + TimeSegment1 + TimeSegment2)
           fCANCLK

#endif

#define CAN_USE_BUSOFF_INTERRUPT    ((uint8)0x08)
#define CAN_USE_RX_INTERRUPT        ((uint8)0x04)
#define CAN_USE_TX_INTERRUPT        ((uint8)0x02)
#define CAN_USE_WAKEUP_INTERRUPT    ((uint8)0x01)

typedef struct tagCan_ControllerConfigType {
/*
**
**  todo: Timing-Parameter mit Makros auf  'BRT0' und 'BRT1' reduzieren!!!
**
*/
    uint16 BaseAddr;

    uint8   CanControllerId;            /* CAN_DRIVER_CONTROLLER_ID ; Symbolic-Name-Value. */
    boolean CanControllerActivation;    /* !!! PRE-COMPILE !!! */

    uint16  CanControllerBaudRate;      /* kbps */
    uint8   CanControllerPropSeg;       /* Specifies propagation delay in time quantas. */
    uint8   CanControllerSeg1;          /* CAN_CONTROLLER_PHASE_SEG1 - Specifies phase segment 1 in time quantas. */
    uint8   CanControllerSeg2;          /* CAN_CONTROLLER_PHASE_SEG2 - Specifies phase segment 2 in time quantas. */
    float64 CanControllerTimeQuanta;    /* Specifies the time quanta for the controller. The calculation of the resulting */
                                        /* prescaler value depending on module clocking and time quanta shall be done offline */
                                        /* Hardware specific.*/

    /* Diese Parameter entscheiden, ob Interrupt-Handler oder Main_Functions generiert werden!!! */
    /* Daneben es geht um die Interrupt-Freigaben im CAN-Code. */
    uint8 CanInterruptProcessing;       /* Contains Flags regarding Rx-,Tx-,Busoff-,Wakeup-Processing   */
                                        /* per ISR or Polling.                                          */
#if 0
    uint8   CanBusoffProcessing;        /* INTERRUPT | POLLING  */
    uint8   CanRxProcessing;            /* INTERRUPT | POLLING  */
    uint8   CanTxProcessing;            /* INTERRUPT | POLLING  */
    uint8   CanWakeupProcessing;        /* INTERRUPT | POLLING  */
#endif

#if 0
    /* Global Setting, not per Controller!!?? */
    ClockRef * CanCpuClockRef;              /* CAN_CPU_CLOCK_REFERENCE */
                                            /* Reference to the CPU clock configuration, */
                                            /* which is set in the MCU driver configuration */
    WakeupSource * CanWakeupSourceRef;      /* OPTIONAL - This parameter contains a reference to the Wakeup */
                                            /* Source for this controller as defined in the ECU State Manager. */
                                            /* Implementation Type: reference to EcuM_WakeupSourceType */
#endif
} Can_ControllerConfigType;

typedef uint32 Can_IdType;      /* MSB set for extended (29-Bit) Identifiers (s. above). */

typedef struct tagCan_PduType { /* PDU-Definition from AUTOSAR (poor style).    */
                                /* Better: s. [2] 8.2.2.1, Table 3.             */
    uint8 *     sdu;
    Can_IdType  id;
    PduIdType   swPduHandle;
    uint8       len;
} Can_PduType;

typedef enum tagCan_StateTransitionType {
    CAN_T_START,
    CAN_T_STOP,
    CAN_T_SLEEP,
    CAN_T_WAKEUP
} Can_StateTransitionType;

typedef enum tagCan_ReturnType {
    CAN_OK,
    CAN_NOT_OK,
    CAN_BUSY
} Can_ReturnType;

typedef struct tagCan_PublicIfType {
    void (* Can_Init)(const Can_ConfigType * Config);
    void (* Can_GetVersionInfo)(Std_VersionInfoType * versioninfo);
    void (* Can_InitController)(uint8 Controller, const Can_ControllerConfigType * Config);
    Can_ReturnType (* Can_SetControllerMode)(uint8 Controller, Can_StateTransitionType Transition);
    void (* Can_DisableControllerInterrupts)(uint8 Controller);
    void (* Can_EnableControllerInterrupts)(uint8 Controller);
    Std_ReturnType (* Can_Cbk_CheckWakeup)(uint8 Controller);
    Can_ReturnType (* Can_Write)(uint8 Hth, const Can_PduType * PduInfo);
    void (* Can_MainFunction_Write)(void);
    void (* Can_MainFunction_Read)(void);
    void (* Can_MainFunction_BusOff)(void);
    void (* Can_MainFunction_Wakeup)(void);
} Can_PublicIfType;

/*
**  Global Function-Like Makros.
*/

/* todo: Configuration issues, but for now we don't support multiple CAN-Driver Instances. */
extern const Can_PublicIfType Can_PublicIf;

#define Can_Init(Config)                                Can_PublicIf.Can_Init(Config)
#define Can_GetVersionInfo(versioninfo)                 Can_PublicIf.Can_GetVersionInfo(versioninfo)
#define Can_InitController(Controller, Config)          Can_PublicIf.Can_InitController(Controller, Config)
#define Can_SetControllerMode(Controller, Transition)   Can_PublicIf.Can_SetControllerMode(Controller, Transition)

#define Can_DisableControllerInterrupts(Controller)     Can_PublicIf.Can_DisableControllerInterrupts(Controller)
#define Can_EnableControllerInterrupts(Controller)      Can_PublicIf.Can_EnableControllerInterrupts(Controller)

#define Can_Cbk_CheckWakeup(Controller)                 Can_PublicIf.Can_Cbk_CheckWakeup(Controller)
#define Can_Write(Hth, PduInfo)                         Can_PublicIf.Can_Write(Hth, PduInfo)

#define Can_MainFunction_Write()                        Can_PublicIf.Can_MainFunction_Write()
#define Can_MainFunction_Read()                         Can_PublicIf.Can_MainFunction_Read()
#define Can_MainFunction_BusOff()                       Can_PublicIf.Can_MainFunction_BusOff()
#define Can_MainFunction_Wakeup()                       Can_PublicIf.Can_MainFunction_Wakeup()

/*
**
**  Mandantory Interfaces:
**  ======================
**  Dem_ReportErrorStatus
**  CanIf_CheckValidation
**  CanIf_Cbk_CheckTransceiverWakeup
**  CanIf_Cbk_CheckControllerWakeup
**  CanIf_CancelTxConfirmation
**  CanIf_SetWakeupEvent
**  CanIf_RxIndication
**  CanIf_ControllerBusOff
**  CanIf_TxConfirmation
**
**  Optional Interfaces:
**  ====================
**  Det_ReportError
**
*/

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __CAN_H */

