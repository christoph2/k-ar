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
 *
 */
#if !defined(__EEP_CFG_H)
#define __EEP_CFG_H

#include "MemIf_Types.h"

#define EEP_DEV_ERROR_DETECT        STD_ON        
#define EEP_GET_VERSION_INFO_API    STD_ON

#define EEP_BASE_ADDRESS	        ((Eep_AdressType)0x400U)
#define EEP_DEFAULT_MODE	        MEMIF_MODE_FAST
#define EEP_FAST_READ_BLOCK_SIZE    2
#define EEP_FAST_WRITE_BLOCK_SIZE   2
#define EEP_JOB_CALL_CYCLE	        0.005
#define EEP_JOB_END_NOTOFICATION    STD_ON
#define EEP_JOB_ERROR_NOTIFICATION  STD_ON
#define EEP_NORMAL_READ_BLOCK_SIZE  2
#define EEP_NORMAL_WRITE_BLOCK_SIZE 2
#define EEP_SIZE		            ((Eep_LengthType)0x1000U)

#if 0
/* DEM Event Parameter Refs. */
#define EEP_E_COMPARE_FAILED
#define EEP_E_ERASE_FAILED
#define EEP_READ_FAILED
#define EEP_WRITE_FAILED
#endif

/* External Driver. */
#if 0
#define EEP_SPI_REFERENCE
#endif

#endif  /* __EEP_CFG_H */
