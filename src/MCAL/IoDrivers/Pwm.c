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
 *
 */
#include "Pwm.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(PWM, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Pwm.h' !
#endif

#if PWM_DEV_ERROR_DETECT == STD_ON
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
#endif /* PWM_DEV_ERROR_DETECT */

#include "MCALTemplates/Mcal_Templates.h"

static FUNC(uint16, PWM_CODE) Pwm_CalculateAbsoluteDutyCycle(uint16 AbsolutePeriodTime, uint16 RelativeDutyCycle);


#define PWM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

KAR_DEFINE_LOCAL_CONFIG_VAR(PWM, Pwm);

#if AR_DEV_ERROR_DETECT(PWM) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(Pwm);
#endif

#define PWM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define PWM_START_SEC_CODE
#include "MemMap.h"

/*
**  Local Function-like Macros.
*/
#define PWM_ASSERT_VALID_CHANNEL(chn, fkt)                 \
    _BEGIN_BLOCK                                           \
    if ((chn) > PWM_MAX_CHANNEL) {                         \
        AR_RAISE_DEV_ERROR(PWM, fkt, PWM_E_PARAM_CHANNEL); \
        return;                                            \
    }                                                      \
    _END_BLOCK

#define PWM_ASSERT_VALID_CHANNEL_RETURN(chn, fkt, value)   \
    _BEGIN_BLOCK                                           \
    if ((chn) > PWM_MAX_CHANNEL) {                         \
        AR_RAISE_DEV_ERROR(PWM, fkt, PWM_E_PARAM_CHANNEL); \
        return (value);                                    \
    }                                                      \
    _END_BLOCK

/*
**  Global Functions.
*/
FUNC(void, PWM_CODE) Pwm_Init(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_DATA) ConfigPtr)
{
#if PWM_DEV_ERROR_DETECT == STD_ON

    if (AR_MODULE_IS_INITIALIZED(Pwm)) {
        AR_RAISE_DEV_ERROR(PWM, INIT, PWM_E_ALREADY_INITIALIZED);
        return;
    }

    if (ConfigPtr == NULL) {
        AR_RAISE_DEV_ERROR(PWM, INIT, PWM_E_PARAM_CONFIG);
        return;
    }

    AR_MODULE_INITIALIZE(Pwm);
#endif /* PWM_DEV_ERROR_DETECT */
       /*!PWM052! Disable all Notifications. */
       /*!PWM093!  The users of the Pwm module shall not call the function during a running operation. */
    AR_SAVE_CONFIG_PTR(Pwm);

    KAR_IMPLEMENT_PWM_INIT(ConfigPtr);
}

FUNC(void, PWM_CODE) Pwm_DeInit(void)
{
#if PWM_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(Pwm)) {
        AR_RAISE_DEV_ERROR(PWM, DEINIT, PWM_E_UNINIT);
        return;
    }

    AR_MODULE_UNINITIALIZE(Pwm);
#endif /* PWM_DEV_ERROR_DETECT */
    KAR_IMPLEMENT_PWM_DEINIT();
}

#if PWM_SET_DUTY_CYCLE == STD_ON
FUNC(void, PWM_CODE) Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
#if PWM_DEV_ERROR_DETECT == STD_ON
    AR_ASSERT_MODULE_IS_INITIALIZED(Pwm, PWM, SETDUTYCYCLE);

    PWM_ASSERT_VALID_CHANNEL(ChannelNumber, SETDUTYCYCLE);
#endif /* PWM_DEV_ERROR_DETECT */

    /* PWM_MAX_CHANNEL */
/* //////////// MCAL_Template */
    KAR_IMPLEMENT_PWM_SETDUTYCYCLE(ChannelNumber, DutyCycle);
/* ////////////////////////// */
}
#endif /* PWM_SET_DUTY_CYCLE */

#if PWM_SET_PERIOD_AND_DUTY == STD_ON
FUNC(void, PWM_CODE) Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle)
{
#if PWM_DEV_ERROR_DETECT == STD_ON
    AR_ASSERT_MODULE_IS_INITIALIZED(Pwm, PWM, SETPERIODANDDUTY);

    PWM_ASSERT_VALID_CHANNEL(ChannelNumber, SETPERIODANDDUTY);

    /* PWM_E_PERIOD_UNCHANGEABLE */

#endif /* PWM_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */
    KAR_IMPLEMENT_PWM_SETPERIODANDDUTY(ChannelNumber, Period, DutyCycle);
/* ////////////////////////// */
}
#endif /* PWM_SET_PERIOD_AND_DUTY */

#if PWM_SET_OUTPUT_TO_IDLE == STD_ON
FUNC(void, PWM_CODE) Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
{
#if PWM_DEV_ERROR_DETECT == STD_ON
    AR_ASSERT_MODULE_IS_INITIALIZED(Pwm, PWM, SETOUTPUTTOIDLE);

    PWM_ASSERT_VALID_CHANNEL(ChannelNumber, SETOUTPUTTOIDLE);
#endif /* PWM_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */
    KAR_IMPLEMENT_PWM_SETOUPUTOIDLE(ChannelNumber);
/* ////////////////////////// */
}
#endif /* PWM_SET_OUTPUT_TO_IDLE */

#if PWM_GET_OUTPUT_STATE == STD_ON
FUNC(Pwm_OutputStateType, PWM_CODE) Pwm_GetOutputState(Pwm_ChannelType ChannelNumber)
{
#if PWM_DEV_ERROR_DETECT == STD_ON
    AR_ASSERT_MODULE_IS_INITIALIZED_RETURN(Pwm, PWM, GETOUTPUTSTATE, PWM_LOW);

    PWM_ASSERT_VALID_CHANNEL_RETURN(ChannelNumber, GETOUTPUTSTATE, PWM_LOW);

#endif /* PWM_DEV_ERROR_DETECT */
/* //////////// MCAL_Template */
    KAR_IMPLEMENT_PWM_GETOUTPUTSTATE(ChannelNumber);
/* ////////////////////////// */
}
#endif /* PWM_GET_OUTPUT_STATE */

#if PWM_NOTIFICATION_SUPPORTED == STD_ON
FUNC(void, PWM_CODE) Pwm_DisableNotification(Pwm_ChannelType ChannelNumber)
{
#if PWM_DEV_ERROR_DETECT == STD_ON
    AR_ASSERT_MODULE_IS_INITIALIZED(Pwm, PWM, DISABLENOTIFICATION);

    PWM_ASSERT_VALID_CHANNEL(ChannelNumber, DISABLENOTIFICATION);
#endif /* PWM_DEV_ERROR_DETECT */
    KAR_IMPLEMENT_PWM_DISABLENOTIFICATION(ChannelNumber);
}

FUNC(void, PWM_CODE) Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification)
{
#if PWM_DEV_ERROR_DETECT == STD_ON
    AR_ASSERT_MODULE_IS_INITIALIZED(Pwm, PWM, ENABLENOTIFICATION);

    PWM_ASSERT_VALID_CHANNEL(ChannelNumber, ENABLENOTIFICATION);

#endif  /* PWM_DEV_ERROR_DETECT */
    KAR_IMPLEMENT_PWM_ENABLENOTIFICATION(ChannelNumber, Notification);
}
#endif  /* PWM_NOTIFICATION_SUPPORTED */

/*
**  Local Functions.
*/

/*
** Scale duty-cycle to [0x0000 .. 0x8000]
*/
static FUNC(uint16, PWM_CODE) Pwm_CalculateAbsoluteDutyCycle(uint16 AbsolutePeriodTime, uint16 RelativeDutyCycle)
{
    return (uint16)(HIWORD(((uint32)(AbsolutePeriodTime) * (RelativeDutyCycle)))) << 1;
}


#define PWM_STOP_SEC_CODE
#include "MemMap.h"
