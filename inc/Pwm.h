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
#if !defined(__PWM_H)
#define __PWM_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "K_Ar.h"
#include "Std_Types.h"
#include "MCALTemplates/Mcal_Defines.h"
#include "Pwm_Cfg.h"

/* #include "mcu/s12/inc/S12_Pwm.h" */

/*
**  Published Information.
*/
#define PWM_VENDOR_ID                       AR_VENDOR_ID
#define PWM_MODULE_ID                       AR_MODULE_ID_PWM
#define PWM_AR_MAJOR_VERSION                3
#define PWM_AR_MINOR_VERSION                1
#define PWM_AR_PATCH_VERSION                0
#define PWM_SW_MAJOR_VERSION                1
#define PWM_SW_MINOR_VERSION                0
#define PWM_SW_PATCH_VERSION                0
#define PWM_INSTANCE_ID                     0

/*
**  Service-IDs.
*/
#define AR_SERVICE_PWM_INIT                 ((uint8)0x00)
#define AR_SERVICE_PWM_DEINIT               ((uint8)0x01)
#define AR_SERVICE_PWM_SETDUTYCYCLE         ((uint8)0x02)
#define AR_SERVICE_PWM_SETPERIODANDDUTY     ((uint8)0x03)
#define AR_SERVICE_PWM_SETOUTPUTTOIDLE      ((uint8)0x04)
#define AR_SERVICE_PWM_GETOUTPUTSTATE       ((uint8)0x05)
#define AR_SERVICE_PWM_DISABLENOTIFICATION  ((uint8)0x06)
#define AR_SERVICE_PWM_ENABLENOTIFICATION   ((uint8)0x07)
#define AR_SERVICE_PWM_GETVERSIONINFO       ((uint8)0x08)

/*
**  Module-Errors.
*/
#define PWM_E_PARAM_CONFIG                  ((uint8)0x10)
#define PWM_E_UNINIT                        ((uint8)0x11)
#define PWM_E_PARAM_CHANNEL                 ((uint8)0x12)
#define PWM_E_PERIOD_UNCHANGEABLE           ((uint8)0x13)
#define PWM_E_ALREADY_INITIALIZED           ((uint8)0x14)

/*
**  Global Types.
*/
/* Numeric identifier of a PWM channel. */
typedef uint8 Pwm_ChannelType;

/* Definition of the period of a PWM channel. */
typedef uint16 Pwm_PeriodType;

/* Defines the class of a PWM channel */
typedef enum tagPwm_ChannelClassType {
    PWM_VARIABLE_PERIOD,
    PWM_FIXED_PERIOD,
    PWM_FIXED_PERIOD_SHIFTED
} Pwm_ChannelClassType;

/* This is the type of data structure containing the initialization data for the PWM driver. */
typedef struct tagPwm_ConfigType {
    /* The contents of the initialization data structure are hardware specific. */

    KAR_DEFINE_HARDWARE_SPECIFIC_CONFIG_PTR(Pwm);
} Pwm_ConfigType;

/* Definition of the type of edge notification of a PWM channel. */
typedef enum tagPwm_EdgeNotificationType {
    PWM_RISING_EDGE,
    PWM_FALLING_EDGE,
    PWM_BOTH_EDGES
} Pwm_EdgeNotificationType;

/* Output state of a PWM channel. */
typedef enum tagPwm_OutputStateType {
    PWM_HIGH,
    PWM_LOW
} Pwm_OutputStateType;

/*
**  Global Functions.
*/

FUNC(void, PWM_CODE) Pwm_Init(P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_DATA) ConfigPtr);
FUNC(void, PWM_CODE) Pwm_DeInit(void);
FUNC(void, PWM_CODE) Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);
FUNC(void, PWM_CODE) Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle);
FUNC(void, PWM_CODE) Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber);
FUNC(Pwm_OutputStateType, PWM_CODE) Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);
FUNC(void, PWM_CODE) Pwm_DisableNotification(Pwm_ChannelType ChannelNumber);
FUNC(void, PWM_CODE) Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification);

/*
**  Global Function-like Macros.
*/
#if PWM_GET_VERSION_INFO_API == STD_ON
#define Pwm_GetVersionInfo(vp) AR_GET_VERSION_INFO(PWM, vp)
#endif /* PWM_GET_VERSION_INFO_API */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __PWM_H */
