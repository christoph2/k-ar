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
#if !defined(__PORT_H)
#define __PORT_H

#include "K_Ar.h"
#include "EcuM.h"
#include "Std_Types.h"
#include "MCALTemplates/Mcal_Defines.h"
#include "Port_Cfg.h"

/*
**  Published Information.
*/
#define PORT_VENDOR_ID                          AR_VENDOR_ID
#define PORT_MODULE_ID                          AR_MODULE_ID_PORT
#define PORT_INSTANCE_ID                        0
#define PORT_AR_MAJOR_VERSION                   3
#define PORT_AR_MINOR_VERSION                   1
#define PORT_AR_PATCH_VERSION                   0
#define PORT_SW_MAJOR_VERSION                   1
#define PORT_SW_MINOR_VERSION                   0
#define PORT_SW_PATCH_VERSION                   0
#define PORT_VENDOR_API_INFIX

#define PORT_DEV_ERROR_DETECT                   STD_ON
#define PORT_VERSION_INFO_API                   STD_ON

/*
**  Service-IDs.
*/
#define AR_SERVICE_PORT_INIT                    ((uint8)0x00)
#define AR_SERVICE_PORT_SET_PIN_DIRECTION       ((uint8)0x01)
#define AR_SERVICE_PORT_REFRESH_PORT_DIRECTION  ((uint8)0x02)
#define AR_SERVICE_PORT_GET_VERSION_INFO        ((uint8)0x03)
#define AR_SERVICE_PORT_SET_PIN_MODE            ((uint8)0x04)

/*
**  Module-Errors.
*/
#define PORT_E_PARAM_PIN                        ((uint8)0x0a)
#define PORT_E_DIRECTION_UNCHANGEBLE            ((uint8)0x0b)
#define PORT_E_PARAM_CONFIG                     ((uint8)0x0c)
#define PORT_E_PARAM_INVALID_MODE               ((uint8)0x0d)
#define PORT_E_MODE_UNCHANGEABLE                ((uint8)0x0e)
#define PORT_E_UNINIT                           ((uint8)0x0f)

/*
**  Global Types.
*/

/*
    Possible Configurations for the Structure 'Port_ConfigType':
    ------------------------------------------------------------
    - Pin Mode (e.g. DIO,ADC,SPI,...) - this port pin configuration is mandantory unless the port is configured as DIO.
    - Pin Direction (input, output) - this port pin configuration is mandantory when the port pin is to be used  for DIO.
    - Pin level init value -  this port pin configuration is mandantory when the port pin is used for DIO.
    - Pin direction changeable during runtime (STD_ON/STD_OFF) - this port pin configuration is MCU dependent.
    - Pin mode changeable during runtime (STD_ON/STD_OFF) - configuration is MCU dependent.
    Optional Parameters (if supported by Hardware):
    -----------------------------------------------
    - Slew rate control.
    - Activation of internal pullups.
    - Microcontroller specific port pin properties.
 */

typedef struct tagPort_ConfigType {
    KAR_DEFINE_HARDWARE_SPECIFIC_CONFIG_PTR(Port);
} Port_ConfigType;

typedef uint8 Port_PinType;

typedef enum tagPort_PinDirectionType {
    KDK_PIN_IN,
    KDK_PIN_OUT
} Port_PinDirectionType;

#define PORT_PIN_LEVEL_LOW      ((uint8)0x00)
#define PORT_PIN_LEVEL_HIGH     ((uint8)0x01)

/* todo: Port_PinModeType' als 'enum' (implementation specific) !!! */
#define PORT_PIN_MODE_ADC       ((uint8)0x00)
#define PORT_PIN_MODE_CAN       ((uint8)0x01)
#define PORT_PIN_MODE_DIO       ((uint8)0x02)
#define PORT_PIN_MODE_DIO_GPT   ((uint8)0x03)
#define PORT_PIN_MODE_DIO_WDG   ((uint8)0x04)
#define PORT_PIN_MODE_FLEXRAY   ((uint8)0x05)
#define PORT_PIN_MODE_ICU       ((uint8)0x06)
#define PORT_PIN_MODE_LIN       ((uint8)0x07)
#define PORT_PIN_MODE_MEM       ((uint8)0x08)
/* #define PORT_PIN_MODE_MEM    ((uint8)0x09) */
#define PORT_PIN_MODE_PWM       ((uint8)0x0a)
#define PORT_PIN_MODE_SPI       ((uint8)0x0b)

#define PORT_PIN_MODE_IIC       ((uint8)0x0c)
#define PORT_PIN_MODE_OCU       ((uint8)0x0d)
#define PORT_PIN_MODE_SCI       ((uint8)0x0e)

typedef uint8 Port_PinModeType;

/*
**  Global Functions.
*/
FUNC(void, PORT_CODE) Port_Init(P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_DATA) ConfigPtr);
FUNC(void, PORT_CODE) Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
FUNC(void, PORT_CODE) Port_RefreshPortDirection(void);
FUNC(void, PORT_CODE) Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

/*
**  Global Function-like Macros.
*/
#if PORT_GET_VERSION_INFO_API == STD_ON
#define Port_GetVersionInfo(vp) AR_GET_VERSION_INFO(PORT, vp)
#endif  /* PORT_GET_VERSION_INFO_API */

#endif  /* __PORT_H */
