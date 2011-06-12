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

#if !defined(__MCU_H)
#define __MCU_H

#include "Std_Types.h"
#include "EcuM.h"
#include "Mcu_Cfg.h"

/*
**  Published Information.
*/
#define MCU_VENDOR_ID                       AR_VENDOR_ID
#define MCU_MODULE_ID                       AR_MODULE_ID_MCU
#define MCU_INSTANCE_ID                     0
#define MCU_AR_MAJOR_VERSION                3
#define MCU_AR_MINOR_VERSION                1
#define MCU_AR_PATCH_VERSION                0
#define MCU_SW_MAJOR_VERSION                1
#define MCU_SW_MINOR_VERSION                0
#define MCU_SW_PATCH_VERSION                0
#define MCU_VENDOR_API_INFIX

/*
**  Service-IDs.
*/
#define AR_SERVICE_MCU_INIT                 ((uint8)0x00)
#define AR_SERVICE_MCU_INIT_RAM_SECTION     ((uint8)0x01)
#define AR_SERVICE_MCU_INIT_CLOCK           ((uint8)0x02)
#define AR_SERVICE_MCU_DISTRIBUTE_PLL_CLOCK ((uint8)0x03)
#define AR_SERVICE_MCU_GET_PLL_STATUS       ((uint8)0x04)
#define AR_SERVICE_MCU_GET_RESET_REASON     ((uint8)0x05)
#define AR_SERVICE_MCU_GET_RESET_RAW_VALUE  ((uint8)0x06)
#define AR_SERVICE_MCU_PERFORM_RESET        ((uint8)0x07)
#define AR_SERVICE_MCU_SET_MODE             ((uint8)0x08)
#define AR_SERVICE_MCU_GET_VERSION_INFO     ((uint8)0x09)

/*
**  Module Errors.
*/
#define MCU_E_PARAM_CONFIG                  ((uint8)0x0a)
#define MCU_E_PARAM_CLOCK                   ((uint8)0x0b)
#define MCU_E_PARAM_MODE                    ((uint8)0x0c)
#define MCU_E_PARAM_RAMSECTION              ((uint8)0x0d)
#define MCU_E_PLL_NOT_LOCKED                ((uint8)0x0e)
#define MCU_E_UNINIT                        ((uint8)0x0f)
#if 0
#define MCU_E_CLOCK_FAILURE                 ((uint8)0x ? ?) /* Assigned by DEM */
#endif

/*
**  Global Types.
*/
typedef struct tagMcu_ConfigType {
    uint8 dummy;    /* todo: Implementieren - Hardware-spezifisch !!!   */
    /*
        It shall contain:
        -----------------
        - MCU dependent properties.
        - Reset Configuration.
        - Definition of MCU modes.
        - Definition of Clock settings.
        - Definition of RAM sections.

        MCU054: The Structure 'Mcu_ConfigType' shall provide a configurable
        (enable/disable) clock failure notification if the MCU provides an Interrupt
        for such detection. Error reporting shall follow the DEM procedures. In
        case of other HW detection mechanismns, e.g. the generation of a trap, this
        notification shall be disabled and the failure reporting shall be done
        outside the MCU driver.

        MCU035: The definitions for each MCU mode within the structure 'Mcu_ConfigType'
        shall contain:
        - MCU specific properties
        - Change of CPU clock
        - Change of Periphal clock
        - Change of PLL settings
        - Change of MCU power supply

        MCU031: The definitions for each Clock setting within the structure 'Mcu_ConfigType'
        shall contain:
        - MCU specific properties as, e.g. clock safety features and special clock distribution
          settings.
        - PLL settings/start lock options
        - Internal oscilator setting

        MCU030: The definitions for each RAM section within the structure 'Mcu_ConfigType'
        shall contain:
            - RAM section base address
            - Section size
            - Data pre-setting to be initialized
        Usage of linker symbol instead of scalar value is allowed.



     */
} Mcu_ConfigType;

typedef enum tagMcu_PllStatusType {
    MCU_PLL_LOCKED,
    MCU_PLL_UNLOCKED,
    MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;

typedef uint8 Mcu_ClockType;

typedef enum tagMcu_ResetType {
    MCU_POWER_ON_RESET,
    MCU_WATCHDOG_RESET,
    MCU_SW_RESET,
    MCU_RESET_UNDEFINED
    /* Support at least for 'MCU_POWER_ON_RESET' and 'MCU_RESET_UNDEFINED'. */
} Mcu_ResetType;

typedef uint8   Mcu_RawResetType;
typedef uint8   Mcu_ModeType;
typedef uint8   Mcu_RamSectionType;

/*
**  Global Functions.
*/
FUNC(void, MCU_CODE) Mcu_Init(P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_DATA) ConfigPtr);
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitRamSection(Mcu_RamSectionType RamSection);
FUNC(Std_ReturnType, MCU_CODE) Mcu_InitClock(Mcu_ClockType ClockSetting);
FUNC(void, MCU_CODE) Mcu_DistributePllClock(void);
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus(void);
FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(void);
FUNC(Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue(void);
FUNC(void, MCU_CODE) Mcu_PerformReset(void);
FUNC(void, MCU_CODE) Mcu_SetMode(Mcu_ModeType McuMode);


/*
**  Global Function-like Macros.
*/
#if MCU_GET_VERSION_INFO_API == STD_ON
#define Mcu_GetVersionInfo(vp) AR_GET_VERSION_INFO(MCU, vp)
#endif /* MCU_GET_VERSION_INFO_API */

#endif /* __MCU_H */
