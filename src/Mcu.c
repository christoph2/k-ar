/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
 *                                     cpu12.gems@googlemail.com>
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
 *  s. FLOSS-EXCEPTION.txt
 */

#include "K_Ar.h"

#include "Mcu.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(MCU, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Mcu.h' !
#endif

#include "Mcu_Cbk.h"
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif

#include "Dem.h"
#if AR_VERSION_CHECK_FAILS(DEM, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Dem.h' !
#endif

#include "SchM_Mcu.h"
#if AR_VERSION_CHECK_FAILS(SCHM_MCU, 3, 1)
    #error Version-Information-Mismatch of Include-File 'SchM_Mcu.h' !
#endif

#include "mcu/s12/inc/S12_Crg.h"
#include "mcu/s12/inc/S12_Mmc.h"

/*
**  Global Functions.
*/
#define MCU_START_SEC_CODE
#include "MemMap.h"

FUNC(void, MCU_CODE) Mcu_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_DATA) ConfigPtr)
{
////////////// MCAL_Template

////////////////////////////
    S12Mmc_Init();
    /*
    ** Hier gehöhrt auf alle Fälle die Timer-Initialisierung hin (ECT), da sich der Timer in GPT und ICU splittet.
    */
    /* enable XIRQ. */

}

FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(Mcu_RamSectionType RamSection)
{
    /* nothing for now (this feature requires customized startup-up code). */
////////////// MCAL_Template

////////////////////////////
}

FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(Mcu_ClockType ClockSetting)
{
////////////// MCAL_Template

////////////////////////////
}

FUNC(void, MCU_CODE) Mcu_DistributePllClock(void)
{
////////////// MCAL_Template

////////////////////////////
}

FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(void)
{
////////////// MCAL_Template

////////////////////////////
    return S12Crg_PLLLocked() ? MCU_PLL_LOCKED : MCU_PLL_UNLOCKED;
}

FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(void)
{
    /* Hinweis: der DUMMY-ISR-entry könnte den Sachverhalt aufzeichen, das ein unexpected Interrupt ausgetreten ist!!! */
////////////// MCAL_Template

////////////////////////////
}

FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue(void)
{

}

FUNC(void, MCU_CODE) Mcu_PerformReset(void)
{
    S12Crg_ResetMCU();
////////////// MCAL_Template

////////////////////////////
}

FUNC(void, MCU_CODE) Mcu_SetMode(Mcu_ModeType McuMode)
{
////////////// MCAL_Template

////////////////////////////
}


#define MCU_STOP_SEC_CODE
#include "MemMap.h"
