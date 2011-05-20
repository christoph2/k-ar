/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
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
 */

/*
**
**  References:
**  ===========
**  Upgrading Note PCA82C250/251 -> TJA1040, 1050 V1.0 - Phillips Semiconductors Technical Report HAI/TR0126.
*/

/*
**
**  PCA82C250/251-Interfacing:
**  ==========================
**  - Connect Rs (PIN8) thru a 47k (for 125k-Baud) Resistor
**    to a MCU-Port-Pin.
**  - Optional: use Pullup-/Pulldown-Resistor for a desired
**    state after Power-On-Reset.
**
**  DDR | PORT  |  State
**  --------------------------------------------------
**    0 |    X  |  Normal/Highspeed (Rs is left open).
**    1 |    0  |  Slope-Control.
**    1 |    1  |  Standby.
**  --------------------------------------------------
**  Note: TJA1040
**
*/

#include "CanIf.h"
#include "CanTrcv_4711_PCA82C250.h"
#include "Det.h"
#include "Dem.h"
#include "Dio.h"

#if 0
#include "CanIf_Cbk.h"
#include "CanTrcv_Cbk.h"
#include "Spi.h"
#endif

/*
**  Local Functions.
*/
static FUNC(void,CANTRCV_CODE) CanTrcv_Init_Impl(void);
static FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_SetOpMode_Impl(CanIf_TransceiverModeType OpMode,uint8 CanNetwork);
static FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_GetOpMode_Impl(CanIf_TransceiverModeType *OpMode,uint8 CanNetwork);
static FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_GetBusWuReason_Impl(uint8 CanNetwork,CanIf_TrcvWakeupReasonType *Reason);
static FUNC(void,CANTRCV_CODE) CanTrcv_GetVersionInfo_Impl(P2VAR(Std_VersionInfoType,AUTOMATIC,CANTRCV_APPL_DATA) Versioninfo);
static FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_SetWakeupMode_Impl(CanIf_TrcvWakeupModeType TrcvWakeupMode,uint8 CanNetwork);
static FUNC(void,CANTRCV_CODE) CanTrcv_MainFunction_Impl(void);
static FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_CB_WakeupByBus_Impl(uint8 CanNetwork);


/*
**  Local Constants.
*/
CONST(CanTrcv_PublicIfType,CANTRCV_CONST_UNSPECIFIED) MyCanTrcv_PublicIf=
{
    CanTrcv_Init_Impl,
    CanTrcv_SetOpMode_Impl,
    CanTrcv_GetOpMode_Impl,
    CanTrcv_GetBusWuReason_Impl,
    CanTrcv_GetVersionInfo_Impl,
    CanTrcv_SetWakeupMode_Impl,
    CanTrcv_MainFunction_Impl,
    CanTrcv_CB_WakeupByBus_Impl
};


FUNC(void,CANTRCV_CODE) CanTrcv_Init_Impl(void)
{

}


FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_SetOpMode_Impl(CanIf_TransceiverModeType OpMode,uint8 CanNetwork)
{

}


FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_GetOpMode_Impl(CanIf_TransceiverModeType *OpMode,uint8 CanNetwork)
{

}


FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_GetBusWuReason_Impl(uint8 CanNetwork,CanIf_TrcvWakeupReasonType *Reason)
{

}

#define CANTRCV_4711_PCA82C250_CODE

#define foo_name(mod) void GLUE2(mod,_GetVersionInfo) ##(Std_VersionInfoType *Versioninfo)    \
    AR_VERSION_INFO_FUNCTION_MACRO(mod)


/*         GLUE2(mod,_GetVersionInfo) ##(Versioninfo);                         \    */

#define AR_VERSION_INFO_FUNCTION_MACRO(mod)                                 \
    {                                                                       \
        Versioninfo->vendorID=(uint16)GLUE2(mod,_VENDOR_ID);                \
        Versioninfo->moduleID=(uint16)GLUE2(mod,_MODULE_ID);                \
        Versioninfo->instanceID=(uint8)GLUE2(mod,_INSTANCE_ID);             \
        Versioninfo->sw_major_version=(uint8)GLUE2(mod,_SW_MAJOR_VERSION);  \
        Versioninfo->sw_minor_version=(uint8)GLUE2(mod,_SW_MINOR_VERSION);  \
        Versioninfo->sw_patch_version=(uint8)GLUE2(mod,_SW_PATCH_VERSION);  \
    }


#if 0
AR_VERSION_INFO_FUNCTION_DECL(CANTRCV_4711_PCA82C250);
AR_VERSION_INFO_FUNCTION_IMPL(CANTRCV_4711_PCA82C250);
#endif

#if 0
#define AR_VERSION_INFO_FUNCTION_MACRO(v);
#define AR_VERSION_INFO_FUNCTION_MACRO(CANTRCV_4711_PCA82C250);
AR_VERSION_INFO_FUNCTION_MACRO(CANTRCV_4711_PCA82C250);
#endif

void CANTRCV_4711_PCA82C250_GetVersionInfo(Std_VersionInfoType *Versioninfo);

foo_name(CANTRCV_4711_PCA82C250);

/*
**  todo: Makros für die Implementation der VersionInfo-Funktion bzw. des Makros!!!
*/
FUNC(void,CANTRCV_CODE) CanTrcv_GetVersionInfo_Impl(P2VAR(Std_VersionInfoType,AUTOMATIC,CANTRCV_APPL_DATA) Versioninfo)
{
/*    CANTRCV_4711_PCA82C250_GetVersionInfo(Versioninfo);   */

    AR_VERSION_INFO_FUNCTION_MACRO(CANTRCV_4711_PCA82C250);

    CANTRCV_4711_PCA82C250_GetVersionInfo(Versioninfo);
}


FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_SetWakeupMode_Impl(CanIf_TrcvWakeupModeType TrcvWakeupMode,uint8 CanNetwork)
{

}


FUNC(void,CANTRCV_CODE) CanTrcv_MainFunction_Impl(void)
{

}


FUNC(Std_ReturnType,CANTRCV_CODE) CanTrcv_CB_WakeupByBus_Impl(uint8 CanNetwork)
{

}
