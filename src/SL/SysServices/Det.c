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

/*
**  Note: There are only vendor-specific configuration parameters.
*/

/*
**
**  TODO: ADJUST TO YOUR NEEDS.
**
*/

#include "Det.h"

/*
**  Local Types.
*/

/*
**  Error-Type for recording, communicating... development errors.
*/
typedef struct tagDet_ErrorType {
    uint16  ModuleId;
    uint8   InstanceId;
    uint8   ApiId;
    uint8   ErrorId;
} Det_ErrorType;

#define NO_OF_ERRORS_TO_RECORD ((uint16)0x10u)

/*
**  Local Variables.
*/
#define DET_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

static Det_ErrorType ErrorBuffer[NO_OF_ERRORS_TO_RECORD];

#define DET_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*
**  Global Functions.
*/
#define DET_START_SEC_CODE
#include "MemMap.h"

FUNC(void, DET_CODE) Det_Init(void)
{
/*
**
**  ... shall reset all error counters and error logging data.
**
*/
}

FUNC(void, DET_CODE) Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId)
{
    uint8 idx;

    idx = (uint8)0;
    // CPU_BREAKPOINT();
/*
**
**  Note: The way the error is handles varies, both in terms of implementation
**        (breakpoint, RAM storage, etc.) and the initialization stage. For example,
**        if the error tracer sends the events via CAN, they can be stored in RAM
**        until 'Det_Start' is called.
**
*/
}

FUNC(void, DET_CODE) Det_Start(void)
{
/*
**
**  Note: In case the DET does not require seperate init calls, e.g. no RAM mirrors
**        are required, the 'Det_Start' function can be empty. This means that both
**        'Det_Init' and 'Det_Start' shall always be available.
**
*/
}

FUNC(void, DET_CODE) Det_GetVersionInfo(Std_VersionInfoType * versioninfo)
{

}

#define DET_STOP_SEC_CODE
#include "MemMap.h"
