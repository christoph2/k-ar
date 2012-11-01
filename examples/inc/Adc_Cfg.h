/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
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
#if !defined(__ADC__CFG_H)
#define __ADC_CFG_H

#define ADC_DEV_ERROR_DETECT            STD_ON
#define ADC_GET_VERSION_INFO_API        STD_ON

#define ADC_NUMBER_OF_GROUPS            ((uint8)3)  /* Der Parameter heiﬂt anders!? */

#define ADC_DEINIT_API                  STD_ON
#define ADC_ENABLE_LIMIT_CHECK          STD_ON
#define ADC_ENABLE_QUEING               STD_ON
#define ADC_ENABLE_START_STOP_GROUP_API STD_ON
#define ADC_GRP_NOTIF_CAPABILTITY       STD_ON
#define ADC_HW_TRIGGER_API              STD_ON
#define ADC_READ_GROUP_API              STD_ON


#define ADC_PRIORITY_IMPELEMTATION      ADC_PRIORITY_NONE       /* _HW, _HW_SW */
#define ADC_RESULT_ALIGNMENT            ADC_RESULT_ALIGN_LEFT

#endif /* __ADC_CFG_H */
