/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
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

#include "Port.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(PORT, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Port.h' !
#endif

#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif

#include "Mcal_Templates.h"

/*
**  Local Types.
*/
typedef struct tagPort_FunctionsType {
    const Kdk_SetPinDirection_Func SetPinDirection;
} Port_FunctionsType;

typedef struct tagPort_PortMappingType {
    uint8           FunctionIndex;
    Kdk_PortType    HwPort;
} Port_PortMappingType;

/*
**  Local Constants.
*/
#define PORT_START_SEC_CONST_8BIT
#include "MemMap.h"

DEFINE_PORT_PORT_TO_FUNCTIONS();

#define PORT_STOP_SEC_CONST_8BIT
#include "MemMap.h"

#define PORT_START_SEC_CONST_16BIT
#include "MemMap.h"

/* This placement isn't really architecture independent, but for now we only support 16Bit Micros. */
DEFINE_PORT_FUNCTIONS();

#define PORT_STOP_SEC_CONST_16BIT
#include "MemMap.h"

/*
**  Local Variables.
*/
#define PORT_START_SEC_VAR_8BIT
#include "MemMap.h"

#if AR_DEV_ERROR_DETECT(PORT) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(PORT);
#endif

#define PORT_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define PORT_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

P2CONST(Port_ConfigType, STATIC, PORT_VAR)  Port_ConfigurationPtr;

#define PORT_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*
**  Global Functions.
*/
#define PORT_START_SEC_CODE
#include "MemMap.h"

FUNC(void, PORT_CODE) Port_Init(P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_DATA) ConfigPtr)
{
#if AR_DEV_ERROR_DETECT(PORT) == STD_ON
    AR_MODULE_INITIALIZE(PORT);
#endif
    Port_ConfigurationPtr = ConfigPtr;

    IMPLEMENT_PORT_INIT();
}

/* todo: Variante, die 'E_NOT_OK' zurückliefert!!! */
/* todo: 'INITIALIZED' (Rechtschreibung!?) */
#define AR_ASSERT_MODULE_INITIALZATION(mod, service)                         \
    _BEGIN_BLOCK                                                            \
    if (!AR_MODULE_IS_INITIALIZED(mod)) {                               \
        Det_ReportError(GLUE2(mod, _MODULE_ID), GLUE2(mod, _INSTANCE_ID),  \
                        service, GLUE2(mod, _E_UNINIT));                              \
    }                                                                   \
    _END_BLOCK

FUNC(void, PORT_CODE) Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    uint8                           port   = (uint8)Pin / (uint8)8;
    uint8                           bit    = (uint8)Pin % (uint8)8;
    Port_PortMappingType const *    map;

    /* todo: Makro 'AR_ASSERT_MODULE_INITIALZATION()' !!! */
#if AR_DEV_ERROR_DETECT(PORT) == STD_ON
    AR_ASSERT_MODULE_INITIALZATION(PORT, AR_SERVICE_PORT_SET_PIN_DIRECTION);

#if 0

    if (!AR_MODULE_IS_INITIALIZED(PORT)) {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, AR_SERVICE_PORT_SET_PIN_DIRECTION, PORT_E_UNINIT);
    }

#endif

#endif

    map = &Port_Ports_to_Functions[port];
    Port_Functions[map->FunctionIndex].SetPinDirection(map->HwPort, bit, Direction);
}

FUNC(void, PORT_CODE) Port_RefreshPortDirection(void)
{
#if AR_DEV_ERROR_DETECT(PORT) == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(PORT)) {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, AR_SERVICE_PORT_REFRESH_PORT_DIRECTION, PORT_E_UNINIT);
    }

#endif
/*
**  Set configured Port-Directions.
**  PORT061: The function 'Port_RefreshPortDirection' shall exclude those port pins
**  from refreshing that are configured as 'port pin direction changeable during runtime'.
*/
    IMPLEMENT_PORT_REFRESH_DIRECTION();
}


FUNC(void, PORT_CODE) Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
#if AR_DEV_ERROR_DETECT(PORT) == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(PORT)) {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, AR_SERVICE_PORT_SET_PIN_MODE, PORT_E_UNINIT);
    }

#endif
    IMPLEMENT_PORT_SET_MODE();
}

#define PORT_STOP_SEC_CODE
#include "MemMap.h"
