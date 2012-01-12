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
#if !defined(__MCAL_DEFINES__DUMMY_H)
#define __MCAL_DEFINES_DUMMY_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Some demo data for unit-testing.
*/

/*
** DIO-Defines.
*/
#define DIO_PORT_A      ((Dio_PortType)0x00)
#define DIO_PORT_B	((Dio_PortType)0x01)
#define DIO_PORT_C	((Dio_PortType)0x02)


#define DIO_CHANNEL_A_0 ((Dio_ChannelType)0x00)
#define DIO_CHANNEL_A_1 ((Dio_ChannelType)0x01)
#define DIO_CHANNEL_A_2 ((Dio_ChannelType)0x02)
#define DIO_CHANNEL_A_3 ((Dio_ChannelType)0x03)
#define DIO_CHANNEL_A_4 ((Dio_ChannelType)0x04)
#define DIO_CHANNEL_A_5 ((Dio_ChannelType)0x05)
#define DIO_CHANNEL_A_6 ((Dio_ChannelType)0x06)
#define DIO_CHANNEL_A_7 ((Dio_ChannelType)0x07)

#define DIO_CHANNEL_B_0 ((Dio_ChannelType)0x08)
#define DIO_CHANNEL_B_1 ((Dio_ChannelType)0x09)
#define DIO_CHANNEL_B_2 ((Dio_ChannelType)0x0a)
#define DIO_CHANNEL_B_3 ((Dio_ChannelType)0x0b)
#define DIO_CHANNEL_B_4 ((Dio_ChannelType)0x0c)
#define DIO_CHANNEL_B_5 ((Dio_ChannelType)0x0d)
#define DIO_CHANNEL_B_6 ((Dio_ChannelType)0x0e)
#define DIO_CHANNEL_B_7 ((Dio_ChannelType)0x0f)

#define DIO_CHANNEL_C_0 ((Dio_ChannelType)0x10)
#define DIO_CHANNEL_C_1 ((Dio_ChannelType)0x11)
#define DIO_CHANNEL_C_2 ((Dio_ChannelType)0x12)
#define DIO_CHANNEL_C_3 ((Dio_ChannelType)0x13)
#define DIO_CHANNEL_C_4 ((Dio_ChannelType)0x14)
#define DIO_CHANNEL_C_5 ((Dio_ChannelType)0x15)
#define DIO_CHANNEL_C_6 ((Dio_ChannelType)0x16)
#define DIO_CHANNEL_C_7 ((Dio_ChannelType)0x17)

/*
**  PORT-Defines.
*/
#define PORT_A_PIN_0    ((Port_PinType)0x00)
#define PORT_A_PIN_1    ((Port_PinType)0x01)
#define PORT_A_PIN_2    ((Port_PinType)0x02)
#define PORT_A_PIN_3    ((Port_PinType)0x03)
#define PORT_A_PIN_4    ((Port_PinType)0x04)
#define PORT_A_PIN_5    ((Port_PinType)0x05)
#define PORT_A_PIN_6    ((Port_PinType)0x06)
#define PORT_A_PIN_7    ((Port_PinType)0x07)

#define PORT_B_PIN_0    ((Port_PinType)0x08)
#define PORT_B_PIN_1    ((Port_PinType)0x09)
#define PORT_B_PIN_2    ((Port_PinType)0x0a)
#define PORT_B_PIN_3    ((Port_PinType)0x0b)
#define PORT_B_PIN_4    ((Port_PinType)0x0c)
#define PORT_B_PIN_5    ((Port_PinType)0x0d)
#define PORT_B_PIN_6    ((Port_PinType)0x0e)
#define PORT_B_PIN_7    ((Port_PinType)0x0f)

#define PORT_E_PIN_0    ((Port_PinType)0x10)
#define PORT_E_PIN_1    ((Port_PinType)0x11)
#define PORT_E_PIN_2    ((Port_PinType)0x12)
#define PORT_E_PIN_3    ((Port_PinType)0x13)
#define PORT_E_PIN_4    ((Port_PinType)0x14)
#define PORT_E_PIN_5    ((Port_PinType)0x15)
#define PORT_E_PIN_6    ((Port_PinType)0x16)
#define PORT_E_PIN_7    ((Port_PinType)0x17)

#define KAR_DEFINE_HARDWARE_SPECIFIC_CONFIG_PTR(mod)	void const * const mod ## _HardwareSpecificConfigPtr

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __MCAL_DEFINES_DUMMY_H */


