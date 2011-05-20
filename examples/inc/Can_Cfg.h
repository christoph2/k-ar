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
#if !defined(__CAN_CFG_H)
#define __CAN_CFG_H


#define CAN_DEV_ERROR_DETECT                STD_ON
#define CAN_HW_TRANSMIT_CANCELLATION        STD_ON
#define CAN_INDEX                           ((uint8)0x00)       /* Specifies the InstanceId of this module instance. */
                                                                /* If only one instance is present it shall have the Id 0. */
#define CAN_MAIN_FUNCTION_BUSOFF_PERIOD     ((float64)(0.01)    /* This parameter describes the period for cyclic call */
                                                                /* to Can_MainFunction_Busoff. Unit is seconds. */
#define CAN_MAIN_FUNCTION_READ_PERIOD       ((float64)(0.01)    /* This parameter describes the period for cyclic call */
                                                                /* to Can_MainFunction_Read. Unit is seconds. */
#define CAN_MAIN_FUNCTION_WAKEUP_PERIOD     ((float64)(0.01)    /* This parameter describes the period for cyclic call */
                                                                /* to Can_MainFunction_Wakeup. Unit is seconds. */
#define CAN_MAIN_FUNCTION_WRITE_PERIOD      ((float64)(0.01)    /* This parameter describes the period for cyclic call */
                                                                /* to Can_MainFunction_Write. Unit is seconds. */
#define CAN_MULTIPLEXED_TRANSMISSION        STD_ON
#define CAN_TIMEOUT_DURATION                ((uint8)10)         /* Specifies the maximum number of loops for blocking function */
                                                                /* until a timeout is raised in short term wait loops. */
                                                                /* Bad naming - better: retry count */
#define CAN_VERSION_INFO_API                STD_ON
#define CAN_WAKEUP_SUPPORT                  STD_ON


#endif  /* __CAN_CFG_H */
