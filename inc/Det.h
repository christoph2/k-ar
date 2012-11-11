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
#if !defined(__DET_H)
#define __DET_H

#include "ComStack_Types.h"
#include "Std_Types.h"

#define DET_VENDOR_ID                   AR_VENDOR_ID
#define DET_MODULE_ID                   AR_MODULE_ID_DET
#define DET_AR_MAJOR_VERSION            3
#define DET_AR_MINOR_VERSION            1
#define DET_AR_PATCH_VERSION            0
#define DET_SW_MAJOR_VERSION            1
#define DET_SW_MINOR_VERSION            0
#define DET_SW_PATCH_VERSION            0
#define DET_VENDOR_API_INFIX

/*
**  Service IDs.
*/
#define AR_SERVICE_DET_INIT             ((uint8)0x00)
#define AR_SERVICE_DET_REPORT_ERROR     ((uint8)0x01)
#define AR_SERVICE_DET_START            ((uint8)0x02)
#define AR_SERVICE_DET_GET_VERSION_INFO ((uint8)0x03)

/*
**  Global Functions.
*/
FUNC(void, DET_CODE) Det_Init(void);
FUNC(void, DET_CODE) Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
FUNC(void, DET_CODE) Det_Start(void);
FUNC(void, DET_CODE) Det_GetVersionInfo(Std_VersionInfoType * versioninfo);

#endif  /* __DET_H */
