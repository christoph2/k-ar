/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
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
#include "Gpt.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(GPT, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Gpt.h' !
#endif

#if GPT_DEV_ERROR_DETECT == STD_ON
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
#endif /* GPT_DEV_ERROR_DETECT */

#include "MCALTemplates/Mcal_Templates.h"

#include "Utl.h"

#define GPT_MAX_CHANNEL ((uint8)12)         /* todo: nach "Mcal_Templates.h"!!! */
                                            /* (außerßem nur konfigurierte Channels berücksichtigen)!!! */

/*
**  Local Types.
*/
typedef enum tagGpt_TimerStateType {
    GPT_T_STATE_STOPPED,
    GPT_T_STATE_STARTED,
    GPT_T_STATE_RUNNING,
    GPT_T_STATE_EXPIRED
} Gpt_TimerStateType;

/*
    Notification-Callback to be implemented by the user (Function-Pointers in the InitStructure).
    If NULL-Pointer, no callback.
    void Gpt_Notification_<channel>(void);
 */

/*
**  Local Variables.
*/
#define DIO_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if AR_DEV_ERROR_DETECT(GPT) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(Gpt);
#endif

KAR_DEFINE_LOCAL_CONFIG_VAR(GPT, Gpt);

static Gpt_TimerStateType   Gpt_TimerState[GPT_MAX_CHANNEL];
static boolean              Gpt_Notification[GPT_MAX_CHANNEL];

#define DIO_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*
** Local Funktion-like Macros.
*/
#define GPT_START_TIMER_CHANNEL(chn)    (Gpt_TimerState |= (1 << (chn)))
#define GPT_STOP_TIMER_CHANNEL(chn)     (Gpt_TimerState &= ~(1 << (chn)))
#define GPT_TIMER_CHANNEL_STARTED(chn)  ((Gpt_TimerState & (1 << (chn))) == (1 << (chn))))

/*
**  Global Functions.
*/
#define GPT_START_SEC_CODE
#include "MemMap.h"

FUNC(void, GPT_CODE) Gpt_Init(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_DATA) ConfigPtr)
{
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, INIT, GPT_E_ALREADY_INITIALIZED);
        return;
    }

    /* todo: NULL-Pointer check for 'ConfigPtr' if Variant==PB, then raise 'GPT_E_PARAM_CONFIG'. */
    if (ConfigPtr == NULL) {
        AR_RAISE_DEV_ERROR(GPT, INIT, GPT_E_PARAM_CONFIG);
        return;
    }

    AR_MODULE_INITIALIZE(Gpt);
#endif /* GPT_DEV_ERROR_DETECT */
    Utl_MemSet(Gpt_TimerState, GPT_T_STATE_STOPPED, sizeof(Gpt_TimerState));
    /* GPT 107: The function 'Gpt_Init' shall disable all notofications. */
    Utl_MemSet(Gpt_Notification, FALSE, sizeof(Gpt_Notification));

    AR_SAVE_CONFIG_PTR(Gpt);
}

#if GPT_DEINIT_API == STD_ON
FUNC(void, GPT_CODE) Gpt_DeInit(void)
{
#if GPT_DEV_ERROR_DETECT == STD_ON
    AR_RAISE_DEV_ERROR(GPT, DEINIT, GPT_E_BUSY);  /* if any channel is running. */

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, DEINIT, GPT_E_UNINIT);
        return;
    }

    AR_MODULE_UNINITIALIZE(Gpt);
#endif /* GPT_DEV_ERROR_DETECT */
       /* GPT 105: The function 'Gpt_Init' shall disable all notofications. */
}
#endif /* GPT_DEINIT_API */

#if defined(GPT_GET_TIME_ELAPSED_API)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    /* GPT 295: if called prior to starting ==> 0 */
    /* GPT 297: if called on a tc in stopped state (init,start,stop) ==> 0*/
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, GETTIMEELAPSED, GPT_E_UNINIT);
        return (Gpt_ValueType)0;
    }

    AR_RAISE_DEV_ERROR(GPT, GETTIMEELAPSED, GPT_E_NOT_STARTED);
#endif /* GPT_DEV_ERROR_DETECT */
    return (Gpt_ValueType)0;
}
#endif /* GPT_GET_TIME_ELAPSED_API */

#if defined(GPT_GET_TIME_REMAINING_API)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    /* GPT 301: if called prior to starting ==> 0 */
    /* GPT 303: if called on a tc in stopped state (init,start,stop) ==> 0*/
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, GETTIMEREMAINING, GPT_E_UNINIT);
        return (Gpt_ValueType)0;
    }

    AR_RAISE_DEV_ERROR(GPT, GETTIMEREMAINING, GPT_E_NOT_STARTED);
#endif /* GPT_DEV_ERROR_DETECT */
    return (Gpt_ValueType)0;
}
#endif /* GPT_GET_TIME_REMAINING_API */

FUNC(void, GPT_CODE) Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, STARTTIMER, GPT_E_UNINIT);    /* Module not initialized.                      */
        return;
    }

    AR_RAISE_DEV_ERROR(GPT, STARTTIMER, GPT_E_PARAM_CHANNEL);   /* Channel not within the allowed range.        */
    AR_RAISE_DEV_ERROR(GPT, STARTTIMER, GPT_E_PARAM_VALUE);     /* Value not within the allowed range.          */
    AR_RAISE_DEV_ERROR(GPT, STARTTIMER, GPT_E_BUSY);            /* Channel already started and still running.   */
#endif /* GPT_DEV_ERROR_DETECT */

    /* todo: START Hardware. */
    Gpt_TimerState[Channel] = GPT_T_STATE_RUNNING;
}

FUNC(void, GPT_CODE) Gpt_StopTimer(Gpt_ChannelType Channel)
{
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, STOPTIMER, GPT_E_UNINIT);     /* Module not initialized.                  */
        return;
    }

    AR_RAISE_DEV_ERROR(GPT, STOPTIMER, GPT_E_PARAM_CHANNEL);  /* Channel not within the allowed range.    */
#endif /* GPT_DEV_ERROR_DETECT */
       /* todo: STOP Hardware. */
    Gpt_TimerState[Channel] = GPT_T_STATE_STOPPED;
}

#if defined(GPT_ENABLE_DISABLE_NOTIFICATION_API)
FUNC(void, GPT_CODE) Gpt_EnableNotification(Gpt_ChannelType Channel)
{
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, ENABLENOTIFICATION, GPT_E_UNINIT);    /* Module not initialized.                  */
        return;
    }

    AR_RAISE_DEV_ERROR(GPT, ENABLENOTIFICATION, GPT_E_PARAM_CHANNEL); /* Channel not within the allowed range.    */
#endif /* GPT_DEV_ERROR_DETECT */

    Gpt_Notification[Channel] = TRUE;
}

FUNC(void, GPT_CODE) Gpt_DisableNotification(Gpt_ChannelType Channel)
{
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, DISABLENOTIFICATION, GPT_E_UNINIT);       /* Module not initialized.                  */
        return;
    }

    AR_RAISE_DEV_ERROR(GPT, DISABLENOTIFICATION, GPT_E_PARAM_CHANNEL);    /* Channel not within the allowed range.    */
#endif /* GPT_DEV_ERROR_DETECT */

    Gpt_Notification[Channel] = FALSE;
}
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API */

#if defined(GPT_WAKEUP_FUNCTIONALITY_API)
FUNC(void, GPT_CODE) Gpt_SetMode(Gpt_ModeType Mode)
{
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, SETMODE, GPT_E_UNINIT);   /* Module not initialized.  */
        return;
    }

    AR_RAISE_DEV_ERROR(GPT, SETMODE, GPT_E_PARAM_MODE);   /* Mode is invalid.         */
#endif /* GPT_DEV_ERROR_DETECT */
}

FUNC(void, GPT_CODE) Gpt_DisableWakeup(Gpt_ChannelType Channel)
{
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, DISABLEWAKEUP, GPT_E_UNINIT);     /* Module not initialized.                  */
        return;
    }

    AR_RAISE_DEV_ERROR(GPT, DISABLEWAKEUP, GPT_E_PARAM_CHANNEL);  /* Channel not within the allowed range.    */
#endif /* GPT_DEV_ERROR_DETECT */
}

FUNC(void, GPT_CODE) Gpt_EnableWakeup(Gpt_ChannelType Channel)
{
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, ENABLEWAKEUP, GPT_E_UNINIT);      /* Module not initialized.              */
        return;
    }

    AR_RAISE_DEV_ERROR(GPT, ENABLEWAKEUP, GPT_E_PARAM_CHANNEL);  /* Channel not within the allowed range. */
#endif /* GPT_DEV_ERROR_DETECT */
}

#if 0
FUNC(void, GPT_CODE) Gpt_Cbk_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
#if GPT_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Gpt)) {
        AR_RAISE_DEV_ERROR(GPT, CHECKWAKEUP, GPT_E_UNINIT);   /* Module not initialized. */
        return;
    }

#endif /* GPT_DEV_ERROR_DETECT */
}
#endif

#endif /* GPT_WAKEUP_FUNCTIONALITY_API */

#define GPT_STOP_SEC_CODE
#include "MemMap.h"
