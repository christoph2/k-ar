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
#include "Dio.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(DIO, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Dio.h' !
#endif

#if AR_DEV_ERROR_DETECT(DIO) == STD_ON
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
#endif /* AR_DEV_ERROR_DETECT */

#include "MCALTemplates/Mcal_Templates.h"

/*
**  DIO005: Interruptable read-modify-write sequences are not allowed. - Must be satisfied by HW-Drivers.
*/

/*
   // 257 bytes of CODE  memory
   //  44 bytes of CONST memory
 */

/*
**  Local Types.
*/
typedef struct tagDio_FunctionsType {
    const Kdk_WritePort_Func            WritePort;
    const Kdk_ReadPort_Func             ReadPort;
    const Kdk_WriteChannel_Func         WriteChannel;
    const Kdk_ReadChannel_Func          ReadChannel;
    const Kdk_WriteChannelGroup_Func    WriteChannelGroup;
    const Kdk_ReadChannelGroup_Func     ReadChannelGroup;
} Dio_FunctionsType;

typedef struct tagDio_PortMappingType {
    uint8           FunctionIndex;
    Kdk_PortType    HwPort;
} Dio_PortMappingType;

/*
**  Local Variables.
*/
#define DIO_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if AR_DEV_ERROR_DETECT(DIO) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(DIO);
#endif

#define DIO_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*
**  Local Constants.
*/
#define DIO_START_SEC_CONST_8BIT
#include "MemMap.h"

DEFINE_DIO_PORT_TO_FUNCTIONS();

#define DIO_STOP_SEC_CONST_8BIT
#include "MemMap.h"

#define DIO_START_SEC_CONST_16BIT
#include "MemMap.h"

/* This placement isn't really architecture independent, but for now we only support 16Bit Micros. */
DEFINE_DIO_FUNCTIONS();

#define DIO_STOP_SEC_CONST_16BIT
#include "MemMap.h"

/*
**  Global Functions.
*/
#define DIO_START_SEC_CODE
#include "MemMap.h"

FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    VAR(uint8, AUTOMATIC)       port   = (uint8)ChannelId / (uint8)8;
    VAR(uint8, AUTOMATIC)       bit    = (uint8)ChannelId % (uint8)8;
    P2CONST(Dio_PortMappingType, AUTOMATIC, ADC_APPL_DATA) map;

    if (ChannelId >= DIO_NUM_CHANNELS) {    /* todo: 'AR_ASSERT_LT()' */
        AR_RAISE_DEV_ERROR(DIO, READ_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
        return DIO_LOW;
    }

    map = &Dio_Ports_to_Functions[port];
    return Dio_Functions[map->FunctionIndex].ReadChannel(map->HwPort, bit);
}

FUNC(void, DIO_CODE) Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    VAR(uint8, AUTOMATIC)       port   = (uint8)ChannelId / (uint8)8;
    VAR(uint8, AUTOMATIC)       bit    = (uint8)ChannelId % (uint8)8;
    P2CONST(Dio_PortMappingType, AUTOMATIC, ADC_APPL_DATA) map;

    if (ChannelId >= DIO_NUM_CHANNELS) {
        AR_RAISE_DEV_ERROR(DIO, WRITE_CHANNEL, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }

    map = &Dio_Ports_to_Functions[port];
    Dio_Functions[map->FunctionIndex].WriteChannel(map->HwPort, bit, Level);
}

FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort(Dio_PortType PortId)
{
    P2CONST(Dio_PortMappingType, AUTOMATIC, ADC_APPL_DATA) map;

    if (PortId >= DIO_NUM_PORTS) {
        AR_RAISE_DEV_ERROR(DIO, READ_PORT, DIO_E_PARAM_INVALID_PORT_ID);
        return (Dio_PortLevelType)0;
    }

    map = &Dio_Ports_to_Functions[PortId];
    return Dio_Functions[map->FunctionIndex].ReadPort(map->HwPort);
}

FUNC(void, DIO_CODE) Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    P2CONST(Dio_PortMappingType, AUTOMATIC, ADC_APPL_DATA) map;

    if (PortId >= DIO_NUM_PORTS) {
        AR_RAISE_DEV_ERROR(DIO, WRITE_PORT, DIO_E_PARAM_INVALID_PORT_ID);
    }

    map = &Dio_Ports_to_Functions[PortId];
    Dio_Functions[map->FunctionIndex].WritePort(map->HwPort, Level);
}

FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APLL_DATA) ChannelGroupIdPtr)
{
    P2CONST(Dio_PortMappingType, AUTOMATIC, ADC_APPL_DATA) map;

    /* DIO_E_PARAM_INVALID_GROUP_ID */

    map = &Dio_Ports_to_Functions[ChannelGroupIdPtr->port];
    return Dio_Functions[map->FunctionIndex].ReadPort(map->HwPort);
}

FUNC(void, DIO_CODE) Dio_WriteChannelGroup(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr,
                                           Dio_PortLevelType Level)
{
    P2CONST(Dio_PortMappingType, AUTOMATIC, ADC_APPL_DATA) map;

    /* DIO_E_PARAM_INVALID_GROUP_ID */

    map = &Dio_Ports_to_Functions[ChannelGroupIdPtr->port];
    Dio_Functions[map->FunctionIndex].WritePort(map->HwPort, Level);
}

#define DIO_STOP_SEC_CODE
#include "MemMap.h"
