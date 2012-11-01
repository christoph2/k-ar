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
 * s. FLOSS-EXCEPTION.txt
 */
#if !defined __NVM_CFG_H
#define __NVM_CFG_H

#include "NvM_Types.h"

typedef uint16 NvM_CrcType;

#define NVM_API_CONFIG_CLASS              NVM_API_CONFIG_CLASS_3
#define NVM_COMPILED_CONFIG_ID            0xbeef
#define NVM_CRC_NUM_OF_BYTES              64
#define NVM_DATASET_SELECTION_BITS        4
#define NVM_REPEAT_MIRROR_OPERATIONS      3
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE      32
#define NVM_SIZE_STANDARD_JOB_QUEUE       32

#define NVM_DEV_ERROR_DETECT              STD_ON
#define NVM_DRV_MODE_SWITCH               STD_ON
#define NVM_DYNAMIC_CONFIGURATION         STD_ON
#define NVM_JOB_PRIORITIZATION            STD_ON
#define NVM_VERSION_INFO_API              STD_ON
#define NVM_SET_RAM_BLOCK_STATUS_API      STD_ON
#define NVM_POLLING_MODE                  STD_ON

#define NVM_MULTI_BLOCK_CALLBACK          // callback

extern const NvM_BlockDescriptor NvM_BlockConfiguration[];

#endif /* __NVM_CFG_H */
