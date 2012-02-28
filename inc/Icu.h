/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__ICU_H)
#define __ICU_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "K_Ar.h"
#include "Std_Types.h"
#include "Icu_Cfg.h"

/*
**  Published Information.
*/
#define ICU_VENDOR_ID                           AR_VENDOR_ID
#define ICU_MODULE_ID                           AR_MODULE_ID_ICU
#define ICU_AR_MAJOR_VERSION                    3
#define ICU_AR_MINOR_VERSION                    1
#define ICU_AR_PATCH_VERSION                    0
#define ICU_SW_MAJOR_VERSION                    1
#define ICU_SW_MINOR_VERSION                    0
#define ICU_SW_PATCH_VERSION                    0
#define ICU_INSTANCE_ID                         0

/*
**  Service-IDs.
*/
#define AR_SERVICE_ICU_INIT                     ((uint8)0x00)
#define AR_SERVICE_ICU_DEINIT                   ((uint8)0x01)
#define AR_SERVICE_ICU_SETMODE                  ((uint8)0x02)
#define AR_SERVICE_ICU_DISABLEWAKEUP            ((uint8)0x03)
#define AR_SERVICE_ICU_ENABLEWAKEUP             ((uint8)0x04)
#define AR_SERVICE_ICU_SETACTIVATIONCONDITION   ((uint8)0x05)
#define AR_SERVICE_ICU_DISABLENOTIFICATION      ((uint8)0x06)
#define AR_SERVICE_ICU_ENABLENOTIFICATION       ((uint8)0x07)
#define AR_SERVICE_ICU_GETINPUTSTATE            ((uint8)0x08)
#define AR_SERVICE_ICU_STARTTIMESTAMP           ((uint8)0x09)
#define AR_SERVICE_ICU_STOPTIMESTAMP            ((uint8)0x0a)
#define AR_SERVICE_ICU_GETTIMESTAMPINDEX        ((uint8)0x0b)
#define AR_SERVICE_ICU_RESETEDGECOUNT           ((uint8)0x0c)
#define AR_SERVICE_ICU_ENABLEEDGECOUNT          ((uint8)0x0d)
#define AR_SERVICE_ICU_DISABLEEDGECOUNT         ((uint8)0x0e)
#define AR_SERVICE_ICU_GETEDGENUMBERS           ((uint8)0x0f)
#define AR_SERVICE_ICU_GETTIMEELAPSED           ((uint8)0x10)
#define AR_SERVICE_ICU_GETDUTYCYCLEVALUES       ((uint8)0x11)
#define AR_SERVICE_ICU_GETVERSIONINFO           ((uint8)0x12)
#define AR_SERVICE_ICU_STARTSIGNALMEASUREMENT   ((uint8)0x13)
#define AR_SERVICE_ICU_STOPSIGNALMEASUREMENT    ((uint8)0x14)
#define AR_SERVICE_ICU_CHECKWAKEUP              ((uint8)0x15)
#define AR_SERVICE_ICU_ENABLEEDGEDETECTION      ((uint8)0x16)
#define AR_SERVICE_ICU_DISABLEEDGEDETECTION     ((uint8)0x17)

/*
**  Module-Errors.
*/
#define ICU_E_PARAM_CONFIG                      ((uint8)0x0a)
#define ICU_E_PARAM_CHANNEL                     ((uint8)0x0b)
#define ICU_E_PARAM_ACTIVATION                  ((uint8)0x0c)
#define ICU_E_PARAM_BUFFER_PTR                  ((uint8)0x0d)
#define ICU_E_PARAM_BUFFER_SIZE                 ((uint8)0x0e)
#define ICU_E_PARAM_MODE                        ((uint8)0x0f)
#define ICU_E_UNINIT                            ((uint8)0x14)
#define ICU_E_NOT_STARTED                       ((uint8)0x15)
#define ICU_E_BUSY_OPERATION                    ((uint8)0x16)
#define ICU_E_ALREADY_INITIALIZED               ((uint8)0x17)

/*
**  Global Types.
*/
typedef uint16  Icu_ValueType;
typedef uint8   Icu_ChannelType;
typedef uint8   Icu_EdgeNumberType;
typedef uint8   Icu_IndexType;

typedef enum tagIcu_ActivationType {
    /* An appropriate action shall be executed when a rising edge occurs on the ICU input signal. */
    ICU_RISING_EDGE,
    /* An appropriate action shall be executed when a falling edge occurs on the ICU input signal. */
    ICU_FALLING_EDGE,
    /* An appropriate action shall be executed when either a rising or falling edge occur on the ICU input signal. */
    ICU_BOTH_EDGES
} Icu_ActivationType;

/* Type which shall contain the values, needed for calculating duty cycles. */
typedef struct tagIcu_DutyCycleType {
    /* This shall be the coherent active-time measured on a channel */
    Icu_ValueType ActiveTime;
    /* This shall be the coherent period-time measured on a channel */
    Icu_ValueType PeriodTime;
} Icu_DutyCycleType;

/* Input state of an ICU channel */
typedef enum tagIcu_InputStateType {
    /* An activation edge has been detected */
    ICU_ACTIVE,
    /* No activation edge has been detected since the last call of Icu_GetInputState() or Icu_Init(). */
    ICU_IDLE
} Icu_InputStateType;

/* Definition of the measurement mode type */
typedef enum tagIcu_MeasurementModeType {
    /* Mode for detecting edges */
    ICU_MODE_SIGNAL_EDGE_DETECT,
    /* Mode for measuring different times between various configurable edges */
    ICU_MODE_SIGNAL_MEASUREMENT,
    /* Mode for capturing timer values on configurable edges */
    ICU_MODE_TIMESTAMP,
    /* Mode for counting edges on configurable edges */
    ICU_MODE_EDGE_COUNTER
} Icu_MeasurementModeType;

/* Allow enabling / disabling of all interrupts which are not required for the ECU wakeup. */
typedef enum tagIcu_ModeType {
    /* Normal operation, all used interrupts are enabled according to the notification requests. */
    ICU_MODE_NORMAL,
    /* Reduced power operation. In sleep mode only those notifications are available which are configured as wakeup capable. */
    ICU_MODE_SLEEP
} Icu_ModeType;

/* Definition of the measurement property type */
typedef enum tagIcu_SignalMeasurementPropertyType {
    /* The channel is configured for reading the elapsed Signal Low Time */
    ICU_LOW_TIME,
    /* The channel is configured for reading the elapsed Signal High Time */
    ICU_HIGH_TIME,
    /* The channel is configured for reading the elapsed Signal Period Time */
    ICU_PERIOD_TIME,
    /* The channel is configured to read values which are needed for calculating the duty cycle (coherent Active and Period Time). */
    ICU_DUTY_CYCLE
} Icu_SignalMeasurementPropertyType;

/* Definition of the timestamp measurement property type */
typedef enum tagIcu_TimestampBufferType {
    /* The buffer will just be filled once */
    ICU_LINEAR_BUFFER,
    /* After reaching the end of the buffer, the driver restarts at the beginning of the buffer */
    ICU_CIRCULAR_BUFFER
} Icu_TimestampBufferType;

/* IcuEdgeCounterMeasurement */
typedef struct tagIcu_EdgeCounterMeasurementType {
    uint8 dummy;
} Icu_EdgeCounterMeasurementType;

/* IcuSignalEdgeDetection */
typedef struct tagIcu_SignalEdgeDetectionType {
    void (* IcuSignalNotification)(void);
} Icu_SignalEdgeDetectionType;

/* IcuSignalMeasurement */
typedef struct tagIcu_SignalMeasurementType {
    Icu_SignalMeasurementPropertyType IcuSignalMeasurementProperty;
} Icu_SignalMeasurementType;

/* IcuTimestampMeasurement */
typedef struct tagIcu_TimestampMeasurementType {
    Icu_TimestampBufferType IcuTimestampMeasurementProperty;
    void (* IcuTimestampNotification)(void);
} Icu_TimestampMeasurementType;

/* per Channel Configuration. */
typedef struct tagIcu_ChannelConfigType {
    Icu_ActivationType      IcuDefaultStartEdge;
    Icu_MeasurementModeType IcuMeasurementMode;
    union {
        Icu_EdgeCounterMeasurementType const * const    IcuEdgeCounterMeasurement;
        Icu_SignalEdgeDetectionType const * const       IcuSignalEdgeDetection;
        Icu_SignalMeasurementType const * const         IcuSignalMeasurement;
        Icu_TimestampMeasurementType const * const      IcuTimestampMeasurement;
    }       IcuMeasurementConfig;
    boolean IcuWakeupCapability;
} Icu_ChannelConfigType;

/* This type contains initialization data. */
typedef struct tagIcu_ConfigType {
    uint8                   IcuMaxChannel; /* Number of Channels. */
    Icu_ChannelConfigType * IcuChannelConfig;
/*
    Hardware and implementation dependent structure.
    The contents of the initialization data structure are microcontroller specific.
 */
} Icu_ConfigType;

/*
**  Global Functions.
*/
FUNC(void, ICU_CODE) Icu_Init(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_DATA) ConfigPtr);
FUNC(void, ICU_CODE) Icu_DeInit(void);
FUNC(void, ICU_CODE) Icu_SetMode(Icu_ModeType Mode);
FUNC(void, ICU_CODE) Icu_DisableWakeup(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_EnableWakeup(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation);
FUNC(void, ICU_CODE) Icu_DisableNotification(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_EnableNotification(Icu_ChannelType Channel);
FUNC(Icu_InputStateType, ICU_CODE) Icu_GetInputState(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_StartTimestamp(Icu_ChannelType Channel, P2VAR(Icu_ValueType, AUTOMATIC,
                                                                       ICU_APPL_DATA) BufferPtr, uint16 BufferSize,
                                        uint16 NotifyInterval);
FUNC(void, ICU_CODE) Icu_StopTimestamp(Icu_ChannelType Channel);
FUNC(Icu_IndexType, ICU_CODE) Icu_GetTimestampIndex(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_ResetEdgeCount(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_EnableEdgeCount(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_DisableEdgeCount(Icu_ChannelType Channel);
FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_GetEdgeNumbers(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_StartSignalMeasurement(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_StopSignalMeasurement(Icu_ChannelType Channel);
FUNC(Icu_ValueType, ICU_CODE) Icu_GetTimeElapsed(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_GetDutyCycleValues(Icu_ChannelType Channel,
                                            P2VAR(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_DATA) DutyCycleValues);

#if 0
FUNC(void, ICU_CODE) Icu_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
FUNC(void, ICU_CODE) Icu_DisableEdgeDetection(Icu_ChannelType Channel);
FUNC(void, ICU_CODE) Icu_EnableEdgeDetection(Icu_ChannelType Channel);
#endif

#if defined(UNIT_TESTING)
Icu_IndexType   GetTimestampIndex();
Icu_ModeType    GetModuleMode(void);


GetInputState(Icu_ChannelType Channel);
#endif /* UNIT_TESTING */

/*
**  Global Function-like Macros.
*/
#if ICU_GET_VERSION_INFO_API == STD_ON
#define Icu_GetVersionInfo(vp) AR_GET_VERSION_INFO(ICU, vp)
#endif /* ICU_GET_VERSION_INFO_API */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __ICU_H */
