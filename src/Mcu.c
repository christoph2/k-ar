/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2010 by Christoph Schueler <chris@konnex-tools.de>
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

#include "K_Ar.h"

#include "Mcu.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(MCU,3,1,0,1,0)
    #error Wrong Version-Information of Include-File 'Mcu.h' !
#endif

#include "Mcu_Cbk.h"
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET,3,1)
    #error Wrong Version-Information of Include-File 'Det.h' !
#endif

#include "Dem.h"
#if AR_VERSION_CHECK_FAILS(DEM,3,1)
    #error Wrong Version-Information of Include-File 'Dem.h' !
#endif

#include "SchM_Mcu.h"
#if AR_VERSION_CHECK_FAILS(SCHM_MCU,3,1)
    #error Wrong Version-Information of Include-File 'SchM_Mcu.h' !
#endif


#include "S12_Crg.h"
#include "S12_Mmc.h"


/*
**  Global Functions.
*/
#define MCU_START_SEC_CODE
#include "MemMap.h"


FUNC(void,MCU_CODE) Mcu_Init(P2CONST(Mcu_ConfigType,AUTOMATIC,MCU_APPL_DATA) ConfigPtr)
{
    S12Mmc_Init();
}


FUNC(Std_ReturnType,MCU_CODE) Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{

}


FUNC(Std_ReturnType,MCU_CODE) Mcu_InitClock(Mcu_ClockType ClockSetting)
{

}


FUNC(void,MCU_CODE) Mcu_DistributePllClock(void)
{

}


FUNC(Mcu_PllStatusType,MCU_CODE) Mcu_GetPllStatus(void)
{
    return S12Crg_PLLLocked() ? MCU_PLL_LOCKED : MCU_PLL_UNLOCKED;
}


FUNC(Mcu_ResetType,MCU_CODE) Mcu_GetResetReason(void)
{

}


FUNC(Mcu_RawResetType,MCU_CODE) Mcu_GetResetRawValue(void)
{

}


FUNC(void,MCU_CODE) Mcu_PerformReset(void)
{
    S12Crg_ResetMCU();
}


FUNC(void,MCU_CODE) Mcu_SetMode(Mcu_ModeType McuMode)
{

}


FUNC(void,MCU_CODE) Mcu_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,MCU_APPL_DATA) versioninfo)
{

}

#define MCU_STOP_SEC_CODE
#include "MemMap.h"
