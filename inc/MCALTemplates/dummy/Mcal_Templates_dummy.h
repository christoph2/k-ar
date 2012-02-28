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
#if !defined(__MCAL_TEMPLATES_DUMMY_H)
#define __MCAL_TEMPLATES_DUMMY_H

/*
**  NOTE: This file is handcrafted, future versions will be generated.
*/


#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


/*
** todo: Must be configurable, we don't want to link unused Modules!!!
*/
#define DEFINE_DIO_FUNCTIONS()			
#if 0
						    \
    const Dio_FunctionsType Dio_Functions[] = {     \
        {                                           \
            S12Mebi_WritePort,                      \
            S12Mebi_ReadPort,                       \
            S12Mebi_WriteChannel,                   \
            S12Mebi_ReadChannel,                    \
            S12Mebi_WriteChannelGroup,              \
            S12Mebi_ReadChannelGroup,               \
        },                                          \
        {                                           \
            S12Pim_WritePort,                       \
            S12Pim_ReadPort,                        \
            S12Pim_WriteChannel,                    \
            S12Pim_ReadChannel,                     \
            S12Pim_WriteChannelGroup,               \
            S12Pim_ReadChannelGroup,                \
        },                                          \
    }
#endif						

#define DEFINE_DIO_PORT_TO_FUNCTIONS()
#if 0						
							    \
    static const Dio_PortMappingType Dio_Ports_to_Functions[] =  \
    {                                                           \
        {0, S12MEBI_PORT_A},                                     \
        {0, S12MEBI_PORT_B},                                     \
        {0, S12MEBI_PORT_E},                                     \
        {0, S12MEBI_PORT_K},                                     \
        {1, S12PIM_PORT_T },                                      \
        {1, S12PIM_PORT_S },                                      \
        {1, S12PIM_PORT_M },                                      \
        {1, S12PIM_PORT_P },                                      \
        {1, S12PIM_PORT_H },                                      \
        {1, S12PIM_PORT_J },                                      \
    }
#endif
							
#define DIO_NUM_PORTS SIZEOF_ARRAY(Dio_Ports_to_Functions)

#define DEFINE_PORT_FUNCTIONS()
#if 0							
						\
    const Port_FunctionsType Port_Functions[] = { \
        {                                       \
            S12Mebi_SetPinDirection,            \
        },                                      \
        {                                       \
            S12Pim_SetPinDirection,             \
        },                                      \
    }
#endif

#define DEFINE_PORT_PORT_TO_FUNCTIONS()
#if 0						
								\
    static const Port_PortMappingType Port_Ports_to_Functions[] =    \
    {                                                               \
        {0, S12MEBI_PORT_A},                                         \
        {0, S12MEBI_PORT_B},                                         \
        {0, S12MEBI_PORT_E},                                         \
        {0, S12MEBI_PORT_K},                                         \
        {1, S12PIM_PORT_T },                                          \
        {1, S12PIM_PORT_S },                                          \
        {1, S12PIM_PORT_M },                                          \
        {1, S12PIM_PORT_P },                                          \
        {1, S12PIM_PORT_H },                                          \
        {1, S12PIM_PORT_J },                                          \
    }
#endif								


/*
**  PORT.
*/								
#define KAR_IMPLEMENT_PORT_INIT()
#define KAR_IMPLEMENT_PORT_REFRESH_DIRECTION()
#define KAR_IMPLEMENT_PORT_SET_MODE()

/*
**  PWM.
*/
#define KAR_IMPLEMENT_PWM_INIT(ConfigPtr)
#define KAR_IMPLEMENT_PWM_DEINIT()
#define KAR_IMPLEMENT_PWM_SETDUTYCYCLE(chn, dc)
#define KAR_IMPLEMENT_PWM_SETPERIODANDDUTY(chn, per, dc)
#define KAR_IMPLEMENT_PWM_SETOUPUTOIDLE(chn)
#define KAR_IMPLEMENT_PWM_GETOUTPUTSTATE(chn)
#define KAR_IMPLEMENT_PWM_DISABLENOTIFICATION(chn)
#define KAR_IMPLEMENT_PWM_ENABLENOTIFICATION(chn, notif)

/*
**  SPI.
*/
#define KAR_IMPLEMENT_SPI_INIT()

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __MCAL_TEMPLATES_DUMMY_H */

