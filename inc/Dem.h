/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
 *                                     cpu12.gems@googlemail.com>
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
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined(__DEM_H)
#define __DEM_H

#include "K_Ar.h"
#include "Dem_IntErrId.h"

/*
**  Published Information.
*/
#define DEM_VENDOR_ID           AR_VENDOR_ID
#define DEM_MODULE_ID           AR_MODULE_ID_DEM
#define DEM_INSTANCE_ID         0
#define DEM_AR_MAJOR_VERSION    3
#define DEM_AR_MINOR_VERSION    1
#define DEM_AR_PATCH_VERSION    0
#define DEM_SW_MAJOR_VERSION    1
#define DEM_SW_MINOR_VERSION    0
#define DEM_SW_PATCH_VERSION    0
#define DEM_VENDOR_API_INFIX

/*
**  todo: 'Cfg' !!!
*/
#define DEM_DEV_ERROR_DETECT    STD_ON
#define DEM_VERSION_INFO_API    STD_ON

#endif  /* __DEM_H */
