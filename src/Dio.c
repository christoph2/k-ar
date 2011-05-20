/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de>
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
 */
#include "Dio.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(DIO_4711_MEBI,3,1,0,1,0)
    #error Wrong Version-Information of Include-File 'Dio.h' !
#endif

#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET,3,1)
    #error Wrong Version-Information of Include-File 'Det.h' !
#endif

#include "S12_Mebi.h"
#include "Hw_Cfg.h"

/*
**  DIO005: Interruptable read-modify-write sequences are not allowed.
*/

/*
**  todo: Tabellen-basierte Makros 'DIO_CHN(n)' statt 'BIT(n)'!!!
*/

/*
**  Local Variables.
*/
#define DIO_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if 0
#if AR_DEV_ERROR_DETECT(DIO_4711_MEBI)==STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(DIO_4711_MEBI);
#endif
#endif

#define DIO_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/*
**  Local Constants.
*/
#define DIO_START_SEC_CONST_8BIT
#include "MemMap.h"
static const uint8 Dio_Mebi_Ports[]=
{
    PORTA,
    PORTB,
    PORTE,
    PORTK
};
#define DIO_STOP_SEC_CONST_8BIT
#include "MemMap.h"

/*     uint8 state=AR_GET_MODULE_STATE_VAR(DIO_4711_MEBI); */


/*
**  Global Functions.
*/
#define DIO_START_SEC_CODE
#include "MemMap.h"

FUNC(Dio_LevelType,DIO_CODE) Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8 port=(uint8)ChannelId / (uint8)8;
    uint8 channel=(uint8)ChannelId % (uint8)8;

    if (ChannelId>=DIO_4711_MEBI_NUM_CHANNELS) {    /* todo: 'AR_ASSERT_LT()' */
        Det_ReportError(DIO_4711_MEBI_MODULE_ID,DIO_4711_MEBI_INSTANCE_ID,
            AR_SERVICE_DIO_READ_CHANNEL,DIO_E_PARAM_INVALID_CHANNEL_ID);
        return DIO_LOW;
    }

//    return (((S12_REG8(&MEBI,Dio_Mebi_Ports[port]) & BIT(channel,uint8))>>channel)==0x01) ? DIO_HIGH : DIO_LOW;
    return Utl_BitGet(S12_REG8(&MEBI,Dio_Mebi_Ports[port]),channel) ? DIO_HIGH : DIO_LOW;
}


FUNC(void,DIO_CODE) Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
    uint8 port=(uint8)ChannelId / (uint8)8;
    uint8 channel=(uint8)ChannelId % (uint8)8;
    uint8 value;

    if (ChannelId>=DIO_4711_MEBI_NUM_CHANNELS) {
        Det_ReportError(DIO_4711_MEBI_MODULE_ID,DIO_4711_MEBI_INSTANCE_ID,
            AR_SERVICE_DIO_WRITE_CHANNEL,DIO_E_PARAM_INVALID_CHANNEL_ID);
    }

    value=S12_REG8(&MEBI,Dio_Mebi_Ports[port]);
    if (Level==DIO_HIGH) {
        value=Utl_BitSet(value,channel);
    } else {
        value=Utl_BitReset(value,channel);
    }
    S12_REG8(&MEBI,Dio_Mebi_Ports[port])=value;
}


FUNC(Dio_PortLevelType,DIO_CODE) Dio_ReadPort(Dio_PortType PortId)
{
    if (PortId>=DIO_4711_MEBI_NUM_PORTS) {
        Det_ReportError(DIO_4711_MEBI_MODULE_ID,DIO_4711_MEBI_INSTANCE_ID,
            AR_SERVICE_DIO_READ_PORT,DIO_E_PARAM_INVALID_PORT_ID);
        return (Dio_PortLevelType)0;
    }

    return (Dio_PortLevelType)S12_REG8(&MEBI,Dio_Mebi_Ports[PortId]);
}


FUNC(void,DIO_CODE) Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
    if (PortId>=DIO_4711_MEBI_NUM_PORTS) {
        Det_ReportError(DIO_4711_MEBI_MODULE_ID,DIO_4711_MEBI_INSTANCE_ID,
            AR_SERVICE_DIO_WRITE_PORT,DIO_E_PARAM_INVALID_PORT_ID);
    }

    S12_REG8(&MEBI,Dio_Mebi_Ports[PortId])=(uint8)Level;
}


FUNC(Dio_PortLevelType,DIO_CODE) Dio_ReadChannelGroup(P2CONST(Dio_ChannelGroupType,AUTOMATIC,DIO_APLL_DATA) ChannelGroupIdPtr)
{
    /* DIO_E_PARAM_INVALID_GROUP_ID */
}


FUNC(void,DIO_CODE) Dio_WriteChannelGroup(P2CONST(Dio_ChannelGroupType,AUTOMATIC,DIO_APPL_DATA) ChannelGroupIdPtr,
    Dio_PortLevelType Level)
{
    /* DIO_E_PARAM_INVALID_GROUP_ID */
/*
    Port&=(~mask)<<offset    ???
    Port|=(Level & mask)<<offset    ???
*/
}


void Dio_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,DIO_APPL_DATA) VersionInfo)
{

}

#define DIO_STOP_SEC_CODE
#include "MemMap.h"
