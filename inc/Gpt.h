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
#if !defined(__GPT_H)
#define __GPT_H

#include "K_Ar.h"
#include "kdk/common/Std_Types.h"
#include "MCALTemplates/Mcal_Defines.h"
#include "Gpt_Cfg.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Published Information.
*/
#define GPT_VENDOR_ID                       AR_VENDOR_ID
#define GPT_MODULE_ID                       AR_MODULE_ID_GPT
#define GPT_INSTANCE_ID                     0
#define GPT_AR_MAJOR_VERSION                3
#define GPT_AR_MINOR_VERSION                1
#define GPT_AR_PATCH_VERSION                0
#define GPT_SW_MAJOR_VERSION                1
#define GPT_SW_MINOR_VERSION                0
#define GPT_SW_PATCH_VERSION                0
#define GPT_VENDOR_API_INFIX

/*
**  Service-IDs.
*/
#define AR_SERVICE_GPT_GETVERSIONINFO       ((uint8)0x00)
#define AR_SERVICE_GPT_INIT                 ((uint8)0x01)
#define AR_SERVICE_GPT_DEINIT               ((uint8)0x02)
#define AR_SERVICE_GPT_GETTIMEELAPSED       ((uint8)0x03)
#define AR_SERVICE_GPT_GETTIMEREMAINING     ((uint8)0x04)
#define AR_SERVICE_GPT_STARTTIMER           ((uint8)0x05)
#define AR_SERVICE_GPT_STOPTIMER            ((uint8)0x06)
#define AR_SERVICE_GPT_ENABLENOTIFICATION   ((uint8)0x07)
#define AR_SERVICE_GPT_DISABLENOTIFICATION  ((uint8)0x08)
#define AR_SERVICE_GPT_SETMODE              ((uint8)0x09)
#define AR_SERVICE_GPT_DISABLEWAKEUP        ((uint8)0x0a)
#define AR_SERVICE_GPT_ENABLEWAKEUP         ((uint8)0x0b)
#define AR_SERVICE_GPT_CHECKWAKEUP          ((uint8)0x0c)

/*
**  Module-Errors.
*/
#define GPT_E_UNINIT                        ((uint8)0x0a)
#define GPT_E_BUSY                          ((uint8)0x0b)
#define GPT_E_NOT_STARTED                   ((uint8)0x0c)
#define GPT_E_ALREADY_INITIALIZED           ((uint8)0x0d)
#define GPT_E_PARAM_CHANNEL                 ((uint8)0x14)
#define GPT_E_PARAM_VALUE                   ((uint8)0x15)
#define GPT_E_PARAM_CONFIG                  ((uint8)0x15)
#define GPT_E_PARAM_MODE                    ((uint8)0x1f)

/*
**  Global Types.
*/
typedef uint8 Gpt_ChannelType;

typedef enum tagGpt_ModeType {
    /* Normal operation mode of the GPT */
    GPT_MODE_NORMAL,
    /* Operation for reduced power operation mode. In sleep mode only wakeup capable channels are available. */
    GPT_MODE_SLEEP
} Gpt_ModeType;

/* Type for reading and setting the timer values (in number of ticks). */
typedef uint16 Gpt_ValueType;

/* Notification-Callback to be implemented by the user. */
typedef void (*Gpt_NotificationCallbackType)(void);

/* This is the type of the data structure including the configuration set required for initializing the GPT timer unit. */
typedef struct tagGpt_ConfigType {
    /* Implementation specific configuration data structure, see chapter 10 for configurable parameters. */

    Gpt_NotificationCallbackType const * * const NotificationCallback;
} Gpt_ConfigType;

typedef struct tagGpt_PublicIfType {
    FUNC(void, GPT_CODE) (*Gpt_GetVersionInfo)(P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) Versioninfo);
} Gpt_PublicIfType;

/*
**  Global Functions.
*/
FUNC(void, GPT_CODE) Gpt_Init(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_DATA) ConfigPtr);
FUNC(void, GPT_CODE) Gpt_DeInit(void);
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
FUNC(void, GPT_CODE) Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);
FUNC(void, GPT_CODE) Gpt_StopTimer(Gpt_ChannelType Channel);
FUNC(void, GPT_CODE) Gpt_EnableNotification(Gpt_ChannelType Channel);
FUNC(void, GPT_CODE) Gpt_DisableNotification(Gpt_ChannelType Channel);
FUNC(void, GPT_CODE) Gpt_SetMode(Gpt_ModeType Mode);
FUNC(void, GPT_CODE) Gpt_DisableWakeup(Gpt_ChannelType Channel);
FUNC(void, GPT_CODE) Gpt_EnableWakeup(Gpt_ChannelType Channel);
/* FUNC(void, GPT_CODE) Gpt_Cbk_CheckWakeup(EcuM_WakeupSourceType WakeupSource); */

/*
** Global Function-like Macros.
*/
#if GPT_GET_VERSION_INFO_API == STD_ON
#define Gpt_GetVersionInfo(vp) AR_GET_VERSION_INFO(GPT, vp)
#endif /* GPT_GET_VERSION_INFO_API */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __GPT_H */
