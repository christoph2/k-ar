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
 */
#if !defined(__PWM__CFG_H)
#define __PWM_CFG_H

#define PWM_MAX_CHANNEL             ((uint8)4)

#define PWM_DEV_ERROR_DETECT        STD_ON
#define PWM_GET_VERSION_INFO_API    STD_ON

#define PWM_SET_DUTY_CYCLE          STD_ON
#define PWM_SET_PERIOD_AND_DUTY     STD_ON
#define PWM_SET_OUTPUT_TO_IDLE      STD_ON
#define PWM_GET_OUTPUT_STATE        STD_ON
#define PWM_NOTIFICATION_SUPPORTED  STD_ON

#endif /* __PWM_CFG_H */

