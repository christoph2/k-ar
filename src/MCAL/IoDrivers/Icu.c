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
#include "Icu.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(ICU, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Icu.h' !
#endif

#if ICU_DEV_ERROR_DETECT == STD_ON
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
#endif /* ICU_DEV_ERROR_DETECT */

#include "Utl.h"

/* DutyCycle = (HighTime / PeriodTime) * 100% */
/* todo: IRQ und XIRQ (ist ein NMI, deswegen nicht?)!!! */

/*
**
**  Note:
**      - Measurement-Mode 'Timestamp' requires buffer-handling (circular or linear).
**      - Assigned capture register(s) (can also be 'None' for channels which only
**        provide edge detection, like an external IRQ.
**      - Assigned capture timer(s) (can also be 'None' for channels which only
**        provide edge detection, like an external IRQ.
**     - HW-dependent settings can be glitch-filters, prescalers, ...
**
**      callbacks:
**      ==========
**              void Icu_SignalNotification_<Channel>(void); // s. GPT.c
**              void Icu_TimestampNotification_<Channel>(void); // s. GPT.c // depends on 'ICU_TIMESTAMP_API'.
**
*/

/* check: was ist mit den Interrupt-fähigen Ports?! */

/*
**  Local Variables.
*/
#define ICU_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if AR_DEV_ERROR_DETECT(ICU) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(Icu);
#endif

KAR_DEFINE_LOCAL_CONFIG_VAR(ICU, Icu);

static Icu_IndexType Icu_TimeStampIndex[ICU_MAX_CHANNEL];

static Icu_ModeType Icu_ModuleMode;

static Icu_InputStateType Icu_InputState[ICU_MAX_CHANNEL];

static boolean Icu_Notification[ICU_MAX_CHANNEL];

#if defined(ICU_TIMESTAMP_API)  /* NEIN: gehöhrt zu Konfiguration!!! */
static Icu_TimestampBufferType BufferType[ICU_MAX_CHANNEL];
#endif /* ICU_TIMESTAMP_API */

#define ICU_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*
**  Global Functions.
*/
#define GPT_START_SEC_CODE
#include "MemMap.h"

FUNC(void, ICU_CODE) Icu_Init(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_DATA) ConfigPtr)
{
#if ICU_DEV_ERROR_DETECT == STD_ON

    if (AR_MODULE_IS_INITIALIZED(Icu)) {
        AR_RAISE_DEV_ERROR(ICU, INIT, ICU_E_ALREADY_INITIALIZED);
        return;
    }

    /* todo: NULL-Pointer check for 'ConfigPtr' if Variant==PB, then raise 'ICU_E_PARAM_CONFIG'. */
    if (ConfigPtr == NULL) {
        AR_RAISE_DEV_ERROR(ICU, INIT, ICU_E_PARAM_CONFIG);
        return;
    }

    AR_MODULE_INITIALIZE(Icu);
#endif /* ICU_DEV_ERROR_DETECT */
    AR_SAVE_CONFIG_PTR(Icu);

    Icu_ModuleMode = ICU_MODE_NORMAL; /* !REQ!ICU060! The function shall set the module mode to ICU_MODE_NORMAL.*/

    /* !REQ!ICU061! The function shall disable all notifications. */
    Utl_MemSet(Icu_Notification, 0, ICU_MAX_CHANNEL);

    /* !REQ!ICU040! The function shall set all used ICU channels to status ICU_IDLE. */
    Utl_MemSet(Icu_InputState, ICU_IDLE, ICU_MAX_CHANNEL);

    /* Disable all Interrupts. */

    /* ICU121: The function shall disable the wakeup-capability of all channels. */
/* //////////// MCAL_Template */

/* ////////////////////////// */
}

#if defined(ICU_DE_INIT_API)
FUNC(void, ICU_CODE) Icu_DeInit(void)
{
#if ICU_DEV_ERROR_DETECT == STD_ON  /* gilt selbstverständlich für alle Funktionen, außer Init()!!! */

    if (!AR_MODULE_IS_INITIALIZED(Icu)) {
        AR_RAISE_DEV_ERROR(ICU, DEINIT, ICU_E_UNINIT);
        return;
    }

    AR_MODULE_UNINITIALIZE(Icu);    /* ICU035 */
#endif /* ICU_DEV_ERROR_DETECT */
       /* ICU036: The function shall set the state of the peripherals used by cfg. as the same after power on reset. */
       /* ICU037: The function shall disable all used interrupts and notofications. */
/* //////////// MCAL_Template */

/* ////////////////////////// */
}
#endif /* ICU_DE_INIT_API */

#if defined(ICU_SET_MODE_API)
FUNC(void, ICU_CODE) Icu_SetMode(Icu_ModeType Mode)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    AR_RAISE_DEV_ERROR(ICU, SETMODE, ICU_E_PARAM_MODE);   /* Mode is invalid.         */
#endif /* ICU_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */

/* ////////////////////////// */
}
#endif /* ICU_SET_MODE_API */

#if defined(ICU_DISABLE_WAKEUP_API)
FUNC(void, ICU_CODE) Icu_DisableWakeup(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* if 'Channel' not within the allowed  range or statically not configured as wakeup capable. */
    AR_RAISE_DEV_ERROR(ICU, DISABLEWAKEUP, ICU_E_PARAM_CHANNEL);
#endif /* ICU_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */

/* ////////////////////////// */
}
#endif /* ICU_DISABLE_WAKEUP_API */

#if defined(ICU_ENABLE_WAKEUP_API)
FUNC(void, ICU_CODE) Icu_EnableWakeup(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* if 'Channel' not within the allowed  range or statically not configured as wakeup capable. */
    AR_RAISE_DEV_ERROR(ICU, ENABLEWAKEUP, ICU_E_PARAM_CHANNEL);
#endif /* ICU_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */

/* ////////////////////////// */
}
#endif /* ICU_ENABLE_WAKEUP_API */

FUNC(void, ICU_CODE) Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    AR_RAISE_DEV_ERROR(ICU, SETACTIVATIONCONDITION, ICU_E_PARAM_CHANNEL);
    AR_RAISE_DEV_ERROR(ICU, SETACTIVATIONCONDITION, ICU_E_PARAM_ACTIVATION);
#endif /* ICU_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */

/* ////////////////////////// */
}

FUNC(void, ICU_CODE) Icu_DisableNotification(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    AR_RAISE_DEV_ERROR(ICU, DISABLENOTIFICATION, ICU_E_PARAM_CHANNEL);
#endif /* ICU_DEV_ERROR_DETECT */
}

FUNC(void, ICU_CODE) Icu_EnableNotification(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    AR_RAISE_DEV_ERROR(ICU, ENABLENOTIFICATION, ICU_E_PARAM_CHANNEL);
#endif /* ICU_DEV_ERROR_DETECT */
}

#if defined(ICU_GET_INPUT_STATE_API)
FUNC(Icu_InputStateType, ICU_CODE) Icu_GetInputState(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    AR_RAISE_DEV_ERROR(ICU, GETINPUTSTATE, ICU_E_PARAM_CHANNEL);
    return ICU_IDLE;    /* ICU049: In the case of error. */
                        /* ICU033: If no activation edge has been detected the function shall return ICU_IDLE. */
#endif /* ICU_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */

/* ////////////////////////// */
}
#endif /* ICU_GET_INPUT_STATE_API */

#if defined(ICU_TIMESTAMP_API)
FUNC(void, ICU_CODE) Icu_StartTimestamp(Icu_ChannelType Channel,
                                        P2VAR(Icu_ValueType, AUTOMATIC,
                                              ICU_APPL_DATA) BufferPtr, uint16 BufferSize, uint16 NotifyInterval)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    AR_RAISE_DEV_ERROR(ICU, STARTTIMESTAMP, ICU_E_PARAM_CHANNEL);
    AR_RAISE_DEV_ERROR(ICU, STARTTIMESTAMP, ICU_E_PARAM_BUFFER_PTR);    /* ICU120 */
    AR_RAISE_DEV_ERROR(ICU, STARTTIMESTAMP, ICU_E_PARAM_BUFFER_SIZE);   /* ICU108 */
#endif /* ICU_DEV_ERROR_DETECT */
}

FUNC(void, ICU_CODE) Icu_StopTimestamp(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    AR_RAISE_DEV_ERROR(ICU, STOPTIMESTAMP, ICU_E_PARAM_CHANNEL);
    AR_RAISE_DEV_ERROR(ICU, STOPTIMESTAMP, ICU_E_NOT_STARTED);
#endif /* ICU_DEV_ERROR_DETECT */
}

FUNC(Icu_IndexType, ICU_CODE) Icu_GetTimestampIndex(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    AR_RAISE_DEV_ERROR(ICU, GETTIMESTAMPINDEX, ICU_E_PARAM_CHANNEL);
    return (Icu_IndexType)0;    /* In the case of errors. */
#endif /* ICU_DEV_ERROR_DETECT */
}
#endif /* ICU_TIMESTAMP_API */

#if defined(ICU_EDGE_COUNT_API)
FUNC(void, ICU_CODE) Icu_ResetEdgeCount(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* RESETEDGECOUNT */
#endif /* ICU_DEV_ERROR_DETECT */
}

FUNC(void, ICU_CODE) Icu_EnableEdgeCount(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* ENABLEEDGECOUNT */
#endif /* ICU_DEV_ERROR_DETECT */
}

FUNC(void, ICU_CODE) Icu_DisableEdgeCount(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* DISABLEEDGECOUNT */
#endif  /* ICU_DEV_ERROR_DETECT */
}
#endif  /* ICU_EDGE_COUNT_API */

FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_GetEdgeNumbers(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* GETEDGENUMBERS */
#endif /* ICU_DEV_ERROR_DETECT */
}

#if defined(ICU_SIGNAL_MEASUREMENT_API)
FUNC(void, ICU_CODE) Icu_StartSignalMeasurement(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* STARTSIGNALMEASUREMENT */
#endif /* ICU_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */

/* ////////////////////////// */
}

FUNC(void, ICU_CODE) Icu_StopSignalMeasurement(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* STOPSIGNALMEASUREMENT */
#endif /* ICU_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */

/* ////////////////////////// */
}
#endif /* ICU_SIGNAL_MEASUREMENT_API */

#if defined(ICU_GET_TIME_ELAPSED_API)
FUNC(Icu_ValueType, ICU_CODE) Icu_GetTimeElapsed(Icu_ChannelType Channel)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* GETTIMEELAPSED */
#endif  /* ICU_DEV_ERROR_DETECT */
}
#endif  /* ICU_GET_TIME_ELAPSED_API */

#if defined(ICU_GET_DUTY_CYCLE_VALUES_API)
FUNC(void, ICU_CODE) Icu_GetDutyCycleValues(Icu_ChannelType Channel,
                                            P2VAR(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_DATA) DutyCycleValues)
{
#if ICU_DEV_ERROR_DETECT == STD_ON
    /* GETDUTYCYCLEVALUES */
#endif  /* ICU_DEV_ERROR_DETECT */
}
#endif  /* ICU_GET_DUTY_CYCLE_VALUES_API */

#define ICU_STOP_SEC_CODE
#include "MemMap.h"
