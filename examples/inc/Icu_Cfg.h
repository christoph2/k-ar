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
#if !defined(__ICU__CFG_H)
#define __ICU_CFG_H

#define ICU_MAX_CHANNEL                 ((uint8)8)

#define ICU_DEV_ERROR_DETECT            STD_ON
#define ICU_REPORT_WAKEUP_SOURCE        STD_OFF
#define ICU_DE_INIT_API                 STD_ON
#define ICU_SET_MODE_API                STD_ON
#define ICU_DISABLE_WAKEUP_API          STD_ON
#define ICU_ENABLE_WAKEUP_API           STD_ON
#define ICU_GET_INPUT_STATE_API         STD_ON
#define ICU_TIMESTAMP_API               STD_ON
#define ICU_EDGE_COUNT_API              STD_ON
#define ICU_SIGNAL_MEASUREMENT_API      STD_ON
#define ICU_GET_TIME_ELAPSED_API        STD_ON
#define ICU_GET_DUTY_CYCLE_VALUES_API   STD_ON
#define ICU_GET_VERSION_INFO_API        STD_ON

#endif /* __ICU_CFG_H */

