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
 * s. FLOSS-EXCEPTION.txt
 *
 */

#include "MemIf.h"
#if AR_VERSION_CHECK_FAILS(MEMIF, 3, 1)
    #error Version-Information-Mismatch of Include-File 'MemIf.h' !
#endif


/*
**  Local Function-like Macros.
*/
#if AR_DEV_ERROR_DETECT(MEMIF) == STD_ON
#define CHECK_DEVICE_INDEX(func, index)                             \
    _BEGIN_BLOCK                                                    \
        AR_RAISE_DEV_ERROR(MEMIF, (func), MEMIF_E_PARAM_DEVICE);    \
    _END_BLOCK
#else
#define CHECK_DEVICE_INDEX(func, index)
#endif

/*
**  Local Variables.
*/
#define MEMIF_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

//KAR_DEFINE_LOCAL_CONFIG_VAR(MEMIF, MemIf);

#if AR_DEV_ERROR_DETECT(MEMIF) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(MemIf);
#endif

#define MEMIF_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*
**  Global Functions.
*/
#define MEMIF_START_SEC_CODE
#include "MemMap.h"

/*
    MemIf019: If only one memory abstraction module is configured, the Memory Abstraction Interface
    shall be implemented as a set of macros mapping the Memory Abstraction Interface API to the API
    of the corresponding memory abstraction module.

    Example:
    #define MemIf_Write(DeviceIndex, BlockNumber, DataPtr) \
        Fee_Write(BlockNumber, DataPtr)

    MemIf020: If only one memory abstraction module is configured, the Memory Abstraction Interface
    shall use efficient mechanisms to map the API calls to the appropriate memory abstraction module.

    Note: One solution is to use tables of pointers to functions where the parameter 'DeviceIndex'
    is used as array index.

    Example:

    File MemIf.h
    ---
    extern const MemIf_WriteFctPtr[2];

    #define MemIf_Write(DeviceIndex, BlockNumber, DataPtr) \
        MemIf_WriteFctPtr[DeviceIndex](BlockNumber, DataPtr)

    File MemIf.c
    ---
    #include "Ea.h"
    #include "Fee.h"
    #include "MemIf.h"

    const MemIf_WriteFctPtr[2] = {Ea_Write, Fee_Write};


    Note: The service IDs given in this interface specification are related to service IDs of the
    underlying memory abstraction module(s). For that reason, they may not start with 0.

    MemIf024: If a called function of the Memory Abstraction Interface API has detected an error
    to an illegal parameter DeviceIndex and has a return value, it shall be set as follows:
        MemIf_GetStatus:        MEMIF_UNINIT
        MemIf_GetJobResult:     MEMIF_JOB_FAILED
        All other functions:    E_NOT_OK
    */

// EA_BLOCK_IDENTIFIER/FEE_BLOCK_NUMBER = NvMNvBlockBaseNumber << NvMDatasetSelectionBits.

FUNC(void, MEMIF_CODE) MemIf_SetMode(MemIf_ModeType Mode)
{

}

FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read(uint8 DeviceIndex, uint16 BlockNumber, uint16 BlockOffset,
                                            P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr,
                                            uint16 Length
                                            )
{
    
    return E_OK;
}


FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write(uint8 DeviceIndex, uint16 BlockNumber,
                                             P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr
                                             )
{
    
    return E_OK;
}


FUNC(void, MEMIF_CODE) MemIf_Cancel(uint8 DeviceIndex)
{
    
}


FUNC(MemIf_StatusType, MEMIF_CODE) MemIf_GetStatus(uint8 DeviceIndex)
{
/*
    MemIf035: If the function MemIf_GetStatus is called with the index denoting a broadcast to all
    configured devices (MEMIF_BROADCAST_ID), the memory Abstraction Interface module shall call
    the 'GetStatus' functions of all underlying devices in turn. It shall return the value
        - MEMIF_IDLE   -- if all underlying devices have returned this state.
        - MEMIF_UNINIT -- if at least one device returned this state, all other returned states
                          shall be ignored.
        - MEMIF_BUSY   -- if at least one device returned this state and no other device returned
                          MEMIF_UNINIT.
        - MEMIF_BUSY_INTERNAL -- if at least one device returned this state and no other device returned
                                 MEMIF_BUSY or MEMIF_UNINIT.

    Note: The special "broadcast" device ID in the call to MemIf_GetStatus is used to query whether all
    devices are idle in order to shut down  the ECU.
*/
}


FUNC(MemIf_JobResultType, MEMIF_CODE) MemIf_GetJobResult(uint8 DeviceIndex)
{

}


FUNC(Std_ReturnType, MEMIF_CODE) MemIf_InvalidateBlock(uint8 DeviceIndex, uint16 BlockNumber)
{
    return E_OK;
}


FUNC(Std_ReturnType, MEMIF_CODE) MemIf_EraseImmediateBlock(uint8 DeviceIndex, uint16 BlockNumber)
{
    return E_OK;
}

/*
** Local Functions
*/


#define MEMIF_STOP_SEC_CODE
#include "MemMap.h"
