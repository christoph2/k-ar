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
#if !defined(__STD_TYPES_H)
#define	__STD_TYPES_H

#include "Std_Macros.h"
#include "Platform_Types.h"
#include "Compiler.h"

#if 0   /* todo: HOWTO RESOLVE !?   */
#if !defined(STATUSTYPEDEFINED)
    #define E_OK        ((uint8)0x00)
    typedef uint8 StatusType;
    #define STATUSTYPEDEFINED
#endif /* STATUSTYPEDEFINED */
#endif

#define E_NOT_OK    ((uint8)0x01)

#define STD_HIGH    ((uint8)0x01)
#define STD_LOW     ((uint8)0x00)

#define STD_ACTIVE  ((uint8)0x01)
#define STD_IDLE    ((uint8)0x00)

#define STD_ON      /*((uint8)*/0x01/*)*/
#define STD_OFF     /*((uint8)*/0x00/*)*/


typedef uint8 Std_ReturnType;

typedef struct tagStd_VersionInfoType {
    uint16 vendorID;
    uint16 moduleID;
    uint8 instanceID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
} Std_VersionInfoType;

#if 0
vendorId(<MODULE>_VENDOR_ID)
moduleId(<MODULE>_MODULE_ID)
arMajorVersion(<MODULE>_AR_MAJOR_VERSION)
arMinorVersion(<MODULE>_AR_MINOR_VERSION)
arPatchVersion(<MODULE>_AR_PATCH_VERSION)
swMajorVersion(<MODULE>_SW_MAJOR_VERSION)
swMinorVersion(<MODULE>_SW_MINOR_VERSION)
swPatchVersion(<MODULE>_SW_PATCH_VERSION)
vendorApiInfix(<MODULE>_VENDOR_API_INFIX)
#endif

#endif	/* __STD_TYPES_H  */
