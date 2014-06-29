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
#if !defined(__MCAL_DEFINES_S12_H)
#define __MCAL_DEFINES_S12_H

/*
**  NOTE: This file is handcrafted, future versions will be generated.
*/

#include "mcu/s12/S12_Atd.h"
#include "mcu/s12/S12_Mebi.h"
#include "mcu/s12/S12_Pim.h"
#include "mcu/s12/S12_Pwm.h"
#include "mcu/s12/S12_Spi.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
** DIO-Defines.
*/
#define DIO_PORT_A      ((Dio_PortType)0x00)
#define DIO_PORT_B      ((Dio_PortType)0x01)
#define DIO_PORT_E      ((Dio_PortType)0x02)
#define DIO_PORT_K      ((Dio_PortType)0x03)
#define DIO_PORT_T      ((Dio_PortType)0x04)
#define DIO_PORT_S      ((Dio_PortType)0x05)
#define DIO_PORT_M      ((Dio_PortType)0x06)
#define DIO_PORT_P      ((Dio_PortType)0x07)
#define DIO_PORT_H      ((Dio_PortType)0x08)
#define DIO_PORT_J      ((Dio_PortType)0x09)

#define DIO_CHANNEL_A_0 S12MEBI_CHANNEL_A_0
#define DIO_CHANNEL_A_1 S12MEBI_CHANNEL_A_1
#define DIO_CHANNEL_A_2 S12MEBI_CHANNEL_A_2
#define DIO_CHANNEL_A_3 S12MEBI_CHANNEL_A_3
#define DIO_CHANNEL_A_4 S12MEBI_CHANNEL_A_4
#define DIO_CHANNEL_A_5 S12MEBI_CHANNEL_A_5
#define DIO_CHANNEL_A_6 S12MEBI_CHANNEL_A_6
#define DIO_CHANNEL_A_7 S12MEBI_CHANNEL_A_7

#define DIO_CHANNEL_B_0 S12MEBI_CHANNEL_B_0
#define DIO_CHANNEL_B_1 S12MEBI_CHANNEL_B_1
#define DIO_CHANNEL_B_2 S12MEBI_CHANNEL_B_2
#define DIO_CHANNEL_B_3 S12MEBI_CHANNEL_B_3
#define DIO_CHANNEL_B_4 S12MEBI_CHANNEL_B_4
#define DIO_CHANNEL_B_5 S12MEBI_CHANNEL_B_5
#define DIO_CHANNEL_B_6 S12MEBI_CHANNEL_B_6
#define DIO_CHANNEL_B_7 S12MEBI_CHANNEL_B_7

#define DIO_CHANNEL_E_0 S12MEBI_CHANNEL_E_0
#define DIO_CHANNEL_E_1 S12MEBI_CHANNEL_E_1
#define DIO_CHANNEL_E_2 S12MEBI_CHANNEL_E_2
#define DIO_CHANNEL_E_3 S12MEBI_CHANNEL_E_3
#define DIO_CHANNEL_E_4 S12MEBI_CHANNEL_E_4
#define DIO_CHANNEL_E_5 S12MEBI_CHANNEL_E_5
#define DIO_CHANNEL_E_6 S12MEBI_CHANNEL_E_6
#define DIO_CHANNEL_E_7 S12MEBI_CHANNEL_E_7

#define DIO_CHANNEL_K_0 S12MEBI_CHANNEL_K_0
#define DIO_CHANNEL_K_1 S12MEBI_CHANNEL_K_1
#define DIO_CHANNEL_K_2 S12MEBI_CHANNEL_K_2
#define DIO_CHANNEL_K_3 S12MEBI_CHANNEL_K_3
#define DIO_CHANNEL_K_4 S12MEBI_CHANNEL_K_4
#define DIO_CHANNEL_K_5 S12MEBI_CHANNEL_K_5
#define DIO_CHANNEL_K_6 S12MEBI_CHANNEL_K_6
#define DIO_CHANNEL_K_7 S12MEBI_CHANNEL_K_7

#define DIO_CHANNEL_T_0 (S12PIM_CHANNEL_T_0 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_T_1 (S12PIM_CHANNEL_T_1 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_T_2 (S12PIM_CHANNEL_T_2 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_T_3 (S12PIM_CHANNEL_T_3 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_T_4 (S12PIM_CHANNEL_T_4 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_T_5 (S12PIM_CHANNEL_T_5 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_T_6 (S12PIM_CHANNEL_T_6 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_T_7 (S12PIM_CHANNEL_T_7 + (Kdk_ChannelType)32)

#define DIO_CHANNEL_S_0 (S12PIM_CHANNEL_S_0 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_S_1 (S12PIM_CHANNEL_S_1 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_S_2 (S12PIM_CHANNEL_S_2 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_S_3 (S12PIM_CHANNEL_S_3 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_S_4 (S12PIM_CHANNEL_S_4 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_S_5 (S12PIM_CHANNEL_S_5 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_S_6 (S12PIM_CHANNEL_S_6 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_S_7 (S12PIM_CHANNEL_S_7 + (Kdk_ChannelType)32)

#define DIO_CHANNEL_M_0 (S12PIM_CHANNEL_M_0 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_M_1 (S12PIM_CHANNEL_M_1 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_M_2 (S12PIM_CHANNEL_M_2 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_M_3 (S12PIM_CHANNEL_M_3 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_M_4 (S12PIM_CHANNEL_M_4 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_M_5 (S12PIM_CHANNEL_M_5 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_M_6 (S12PIM_CHANNEL_M_6 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_M_7 (S12PIM_CHANNEL_M_7 + (Kdk_ChannelType)32)

#define DIO_CHANNEL_P_0 (S12PIM_CHANNEL_P_0 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_P_1 (S12PIM_CHANNEL_P_1 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_P_2 (S12PIM_CHANNEL_P_2 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_P_3 (S12PIM_CHANNEL_P_3 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_P_4 (S12PIM_CHANNEL_P_4 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_P_5 (S12PIM_CHANNEL_P_5 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_P_6 (S12PIM_CHANNEL_P_6 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_P_7 (S12PIM_CHANNEL_P_7 + (Kdk_ChannelType)32)

#define DIO_CHANNEL_H_0 (S12PIM_CHANNEL_H_0 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_H_1 (S12PIM_CHANNEL_H_1 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_H_2 (S12PIM_CHANNEL_H_2 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_H_3 (S12PIM_CHANNEL_H_3 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_H_4 (S12PIM_CHANNEL_H_4 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_H_5 (S12PIM_CHANNEL_H_5 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_H_6 (S12PIM_CHANNEL_H_6 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_H_7 (S12PIM_CHANNEL_H_7 + (Kdk_ChannelType)32)

#define DIO_CHANNEL_J_0 (S12PIM_CHANNEL_J_0 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_J_1 (S12PIM_CHANNEL_J_1 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_J_2 (S12PIM_CHANNEL_J_2 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_J_3 (S12PIM_CHANNEL_J_3 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_J_4 (S12PIM_CHANNEL_J_4 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_J_5 (S12PIM_CHANNEL_J_5 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_J_6 (S12PIM_CHANNEL_J_6 + (Kdk_ChannelType)32)
#define DIO_CHANNEL_J_7 (S12PIM_CHANNEL_J_7 + (Kdk_ChannelType)32)

/*
**  PORT-Defines.
*/
#define PORT_A_PIN_0    DIO_CHANNEL_A_0
#define PORT_A_PIN_1    DIO_CHANNEL_A_1
#define PORT_A_PIN_2    DIO_CHANNEL_A_2
#define PORT_A_PIN_3    DIO_CHANNEL_A_3
#define PORT_A_PIN_4    DIO_CHANNEL_A_4
#define PORT_A_PIN_5    DIO_CHANNEL_A_5
#define PORT_A_PIN_6    DIO_CHANNEL_A_6
#define PORT_A_PIN_7    DIO_CHANNEL_A_7

#define PORT_B_PIN_0    DIO_CHANNEL_B_0
#define PORT_B_PIN_1    DIO_CHANNEL_B_1
#define PORT_B_PIN_2    DIO_CHANNEL_B_2
#define PORT_B_PIN_3    DIO_CHANNEL_B_3
#define PORT_B_PIN_4    DIO_CHANNEL_B_4
#define PORT_B_PIN_5    DIO_CHANNEL_B_5
#define PORT_B_PIN_6    DIO_CHANNEL_B_6
#define PORT_B_PIN_7    DIO_CHANNEL_B_7

#define PORT_E_PIN_0    DIO_CHANNEL_E_0
#define PORT_E_PIN_1    DIO_CHANNEL_E_1
#define PORT_E_PIN_2    DIO_CHANNEL_E_2
#define PORT_E_PIN_3    DIO_CHANNEL_E_3
#define PORT_E_PIN_4    DIO_CHANNEL_E_4
#define PORT_E_PIN_5    DIO_CHANNEL_E_5
#define PORT_E_PIN_6    DIO_CHANNEL_E_6
#define PORT_E_PIN_7    DIO_CHANNEL_E_7

#define PORT_K_PIN_0    DIO_CHANNEL_K_0
#define PORT_K_PIN_1    DIO_CHANNEL_K_1
#define PORT_K_PIN_2    DIO_CHANNEL_K_2
#define PORT_K_PIN_3    DIO_CHANNEL_K_3
#define PORT_K_PIN_4    DIO_CHANNEL_K_4
#define PORT_K_PIN_5    DIO_CHANNEL_K_5
#define PORT_K_PIN_6    DIO_CHANNEL_K_6
#define PORT_K_PIN_7    DIO_CHANNEL_K_7

#define PORT_T_PIN_0    DIO_CHANNEL_T_0
#define PORT_T_PIN_1    DIO_CHANNEL_T_1
#define PORT_T_PIN_2    DIO_CHANNEL_T_2
#define PORT_T_PIN_3    DIO_CHANNEL_T_3
#define PORT_T_PIN_4    DIO_CHANNEL_T_4
#define PORT_T_PIN_5    DIO_CHANNEL_T_5
#define PORT_T_PIN_6    DIO_CHANNEL_T_6
#define PORT_T_PIN_7    DIO_CHANNEL_T_7

#define PORT_S_PIN_0    DIO_CHANNEL_S_0
#define PORT_S_PIN_1    DIO_CHANNEL_S_1
#define PORT_S_PIN_2    DIO_CHANNEL_S_2
#define PORT_S_PIN_3    DIO_CHANNEL_S_3
#define PORT_S_PIN_4    DIO_CHANNEL_S_4
#define PORT_S_PIN_5    DIO_CHANNEL_S_5
#define PORT_S_PIN_6    DIO_CHANNEL_S_6
#define PORT_S_PIN_7    DIO_CHANNEL_S_7

#define PORT_M_PIN_0    DIO_CHANNEL_M_0
#define PORT_M_PIN_1    DIO_CHANNEL_M_1
#define PORT_M_PIN_2    DIO_CHANNEL_M_2
#define PORT_M_PIN_3    DIO_CHANNEL_M_3
#define PORT_M_PIN_4    DIO_CHANNEL_M_4
#define PORT_M_PIN_5    DIO_CHANNEL_M_5
#define PORT_M_PIN_6    DIO_CHANNEL_M_6
#define PORT_M_PIN_7    DIO_CHANNEL_M_7

#define PORT_P_PIN_0    DIO_CHANNEL_P_0
#define PORT_P_PIN_1    DIO_CHANNEL_P_1
#define PORT_P_PIN_2    DIO_CHANNEL_P_2
#define PORT_P_PIN_3    DIO_CHANNEL_P_3
#define PORT_P_PIN_4    DIO_CHANNEL_P_4
#define PORT_P_PIN_5    DIO_CHANNEL_P_5
#define PORT_P_PIN_6    DIO_CHANNEL_P_6
#define PORT_P_PIN_7    DIO_CHANNEL_P_7

#define PORT_H_PIN_0    DIO_CHANNEL_H_0
#define PORT_H_PIN_1    DIO_CHANNEL_H_1
#define PORT_H_PIN_2    DIO_CHANNEL_H_2
#define PORT_H_PIN_3    DIO_CHANNEL_H_3
#define PORT_H_PIN_4    DIO_CHANNEL_H_4
#define PORT_H_PIN_5    DIO_CHANNEL_H_5
#define PORT_H_PIN_6    DIO_CHANNEL_H_6
#define PORT_H_PIN_7    DIO_CHANNEL_H_7

#define PORT_J_PIN_0    DIO_CHANNEL_J_0
#define PORT_J_PIN_1    DIO_CHANNEL_J_1
#define PORT_J_PIN_2    DIO_CHANNEL_J_2
#define PORT_J_PIN_3    DIO_CHANNEL_J_3
#define PORT_J_PIN_4    DIO_CHANNEL_J_4
#define PORT_J_PIN_5    DIO_CHANNEL_J_5
#define PORT_J_PIN_6    DIO_CHANNEL_J_6
#define PORT_J_PIN_7    DIO_CHANNEL_J_7

/*
**  Hardware-specific config pointers.
*/
#define KAR_DEFINE_HARDWARE_SPECIFIC_CONFIG_PTR(mod) \
    S12 ## mod ## _ConfigType const * const mod ## _HardwareSpecificConfigPtr

#define KAR_DEFINE_HARDWARE_SPECIFIC_CONFIG_PTR_MULT(mod, inst) \
    S12 ## mod ## _ConfigType const * const mod ## _HardwareSpecificConfigPtr ## inst

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __MCAL_DEFINES_S12_H */
