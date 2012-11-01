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

#include "Ea.h"
#if AR_VERSION_CHECK_FAILS(EA, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Ea.h' !
#endif

#include "Dem.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(DEM, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Dem.h' !
#endif

#if AR_DEV_ERROR_DETECT(EA) == STD_ON
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
#endif /* AR_DEV_ERROR_DETECT */


/*
    1) The Freescale Star12 has an internal EEPROM with 4 byte sector and 2 byte page size. By aligning the
       block start and end addresses to 4 byte boundaries the handling of blocks can be simplified since
       read-modify-write behavior is no longer needed.
    2) Example: The address alignment is set to 4 (bytes). The first logical block gets the block number 1,
       its start address is 0 (a device specific base address is added by the underlying memory driver).
       The block size is 22 bytes, so it takes up 6 4-byte "pages". The next logical block should then get
       not the number 2 but number 7, thus allowing the memory abstraction module to deduce that its 
       start address is 24 ((blockNumber - 1) * pageSize).
*/

// Wear levelling algorithms (um die Lebensdauer eines EEPROMs zu erhöhen)!!!

// Blocknumbers 0x0000 and 0xffff can't be used (BSW14026)!!!

/*
**  Local Types.
*/
typedef enum tagEa_JobTypeType {
    EA_JOB_TYPE_NONE,
    EA_JOB_TYPE_READ,
    EA_JOB_TYPE_WRITE,
    EA_JOB_TYPE_ERASE_IMMEDIATE,
//    EA_JOB_TYPE_COMPARE
} Ea_JobTypeType;


/*
**  Local Variables.
*/
#define EA_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

KAR_DEFINE_LOCAL_CONFIG_VAR(EA, Ea);

//#if AR_DEV_ERROR_DETECT(EA) == STD_ON
//AR_IMPLEMENT_MODULE_STATE_VAR(Ea);
//#endif
static MemIf_StatusType Ea_ModuleState = MEMIF_IDLE;
static MemIf_JobResultType Ea_JobState = MEMIF_JOB_OK;
static Ea_JobTypeType Ea_JobType       = EA_JOB_TYPE_NONE;

#define EA_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/*
**  Global Functions.
*/
#define EA_START_SEC_CODE
#include "MemMap.h"

FUNC(void, EA_CODE) Ea_Init(P2CONST(Ea_ConfigType, AUTOMATIC, EA_APPL_DATA) ConfigPtr)
{
#if EA_DEV_ERROR_DETECT == STD_ON
    if (ConfigPtr == NULL /* and VariantPB */) {
    	//AR_RAISE_DEV_ERROR(EA, INIT, EA_E_PARAM_CONFIG);
	    return;
    }
#endif /* EA_DEV_ERROR_DETECT */

    if ((Ea_ModuleState == MEMIF_BUSY) || (Ea_ModuleState == MEMIF_BUSY_INTERNAL)) {
        return; /* REQ: EA128 (Note) */
    }

    AR_SAVE_CONFIG_PTR(Ea);
    Ea_ModuleState = MEMIF_IDLE;    /* REQ: EA128 */
    Ea_JobState = MEMIF_JOB_OK;
    Ea_JobType = EA_JOB_TYPE_NONE;
}


#if EA_SET_MODE_SUPPORTED == STD_ON /* REQ: EA150 */
FUNC(void, EA_CODE) Ea_SetMode(MemIf_ModeType Mode)
{
#if EA_DEV_ERROR_DETECT == STD_ON
    if (Ea_ModuleState == MEMIF_UNINIT) {
        AR_RAISE_DEV_ERROR(EA, SETMODE, EA_E_NOT_INITIALIZED);
        return; /* REQ: EA129 */
    }
#endif /* EA_DEV_ERROR_DETECT */
    Eep_SetMode(Mode);  /* REQ: EA020 (If supported by the underlying hardware). */
}
#endif /* EA_SET_MODE_SUPPORTED */


FUNC(Std_ReturnType, EA_CODE) Ea_Read(uint16 BlockNumber, uint16 BlockOffset, 
    P2VAR(uint8, AUTOMATIC, EA_APPL_DATA) DataBufferPtr, uint16 Length
)
{
#if EA_DEV_ERROR_DETECT == STD_ON
    if (Ea_ModuleState == MEMIF_UNINIT) {
        AR_RAISE_DEV_ERROR(EA, READ, EA_E_NOT_INITIALIZED);
        return E_NOT_OK; /* REQ: EA130 */
    }
/*
    if (BlockNumber <INVALID>) {
        AR_RAISE_DEV_ERROR(EA, READ, EA_E_INVALID_BLOCK_NO);
        return E_NOT_OK;  -- REQ: 147
    }
*/
#endif /* EA_DEV_ERROR_DETECT */

    /* TODO: Calculate memory address from block number and offset */   /* REQ: EA021 */
    /* TODO: Copy calculated values to module internal variables and initiate job. */ /* REQ: EA022 */
    Ea_ModuleState = MEMIF_BUSY;
    Ea_JobState = MEMIF_JOB_PENDING;
    Ea_JobType = EA_JOB_TYPE_READ;

    return E_OK;
}


FUNC(Std_ReturnType, EA_CODE) Ea_Write(uint16 BlockNumber, P2VAR(uint8, AUTOMATIC, EA_APPL_DATA) DataBufferPtr)
{
#if EA_DEV_ERROR_DETECT == STD_ON
    if (Ea_ModuleState == MEMIF_UNINIT) {
        AR_RAISE_DEV_ERROR(EA, WRITE, EA_E_NOT_INITIALIZED);
        return E_NOT_OK; /* REQ: EA131 */
    }
/*
    if (BlockNumber <INVALID>) {
        AR_RAISE_DEV_ERROR(EA, WRITE, EA_E_INVALID_BLOCK_NO);
        return E_NOT_OK;  -- REQ: 148
    }
*/
#endif /* EA_DEV_ERROR_DETECT */

    /* TODO: Calculate memory address from block number and offset */   /* REQ: EA024 */
    /* TODO: Set read length = length configured for this logical block. */ /* REQ: EA151 */
    /* TODO: Copy calculated values to module internal variables and initiate job. */ /* REQ: EA025 */
    Ea_ModuleState = MEMIF_BUSY;
    Ea_JobState = MEMIF_JOB_PENDING;
    Ea_JobType = EA_JOB_TYPE_WRITE;

    return E_OK;
}


FUNC(void, EA_CODE) Ea_Cancel(void)
{
#if EA_DEV_ERROR_DETECT == STD_ON
    if (Ea_ModuleState == MEMIF_UNINIT) {
        AR_RAISE_DEV_ERROR(EA, CANCEL, EA_E_NOT_INITIALIZED);
        return; /* REQ: EA132 */
    }
#endif /* EA_DEV_ERROR_DETECT */

    Eep_Cancel();   /* REQ: EA077 */

    /* TODO: Reset module internal variables. */
    Ea_ModuleState = MEMIF_IDLE;
    Ea_JobState = MEMIF_JOB_CANCELED;
    Ea_JobType = EA_JOB_TYPE_NONE;
}


FUNC(MemIf_StatusType, EA_CODE) Ea_GetStatus(void)
{
#if EA_DEV_ERROR_DETECT == STD_ON
    if (Ea_ModuleState == MEMIF_UNINIT) {
        AR_RAISE_DEV_ERROR(EA, GETSTATUS, EA_E_NOT_INITIALIZED);
        return MEMIF_UNINIT; /* REQ: EA133 */
    }
#endif /* EA_DEV_ERROR_DETECT */

    return Ea_ModuleState; /* REQ: EA034, EA156, EA157, EA073 */
}


FUNC(MemIf_JobResultType, EA_CODE) Ea_GetJobResult(void)
{
#if EA_DEV_ERROR_DETECT == STD_ON
    if (Ea_ModuleState == MEMIF_UNINIT) {
        AR_RAISE_DEV_ERROR(EA, GETJOBRESULT, EA_E_NOT_INITIALIZED);
        return MEMIF_JOB_FAILED; /* REQ: EA134 */
    }
#endif /* EA_DEV_ERROR_DETECT */
/*
    Note: The NvM is only interested in the result of those jobs it has requested, not of
    the jobs that the EA module itself has launched in the context of internal management
    operations. To facilitate this, the EA module may have to implement a second set of
    local variables to store data for internal jobs.

    Note: Internal management operations (e.g. "garbage collection") will only be invoked
    in the context of jobs requested from the NvM. Whether they have to be done before
    or after the requested job is the decision of the modules implementor and shall not
    be detailed in this specification.
*/

    return Ea_JobState; /* REQ: EA035 */
}


FUNC(Std_ReturnType, EA_CODE) Ea_InvalidateBlock(uint16 BlockNumber)
{
#if EA_DEV_ERROR_DETECT == STD_ON
    if (Ea_ModuleState == MEMIF_UNINIT) {
        AR_RAISE_DEV_ERROR(EA, INVALIDATEBLOCK, EA_E_NOT_INITIALIZED);
        return E_NOT_OK; /* REQ: EA135 */
    }
/*
    if (BlockNumber <INVALID>) {
        AR_RAISE_DEV_ERROR(EA, INVALIDATEBLOCK, EA_E_INVALID_BLOCK_NO);
        return E_NOT_OK;  -- REQ: 149
    }
*/
#endif /* EA_DEV_ERROR_DETECT */
    
    /* TODO: Calculate correspondending block address from block number. */ /* REQ: EA036 */

    /*
        REQ: EA037:
        Depending on implementation, the function 'Ea_InvalidateBlock' shall invalidate
        the block <BlockNumber> by either calling the erase function of the underlying
        device or changing some module internal management information accordingly.

        Note: This internal managment information has to be stored in NV memory since
        it has to be resistent against resets. What this information is and how it is
        stored is not further detailed in this specification.
    */

    return E_OK;
}


FUNC(Std_ReturnType, EA_CODE) Ea_EraseImmediateBlock(uint16 BlockNumber)
{
#if EA_DEV_ERROR_DETECT == STD_ON
    if (Ea_ModuleState == MEMIF_UNINIT) {
        AR_RAISE_DEV_ERROR(EA, ERASEIMMEDIATEBLOCK, EA_E_NOT_INITIALIZED);
        return E_NOT_OK; /* REQ: EA136 */
    }
/*
    if (BlockNumber <INVALID>) {
        AR_RAISE_DEV_ERROR(EA, ERASEIMMEDIATEBLOCK, EA_E_INVALID_BLOCK_NO);
        return E_NOT_OK;  -- REQ: 152
    }
*/
#endif /* EA_DEV_ERROR_DETECT */

    /* TODO: Copy calculated values to module internal variables and initiate job. 
             The block offset shall fixed to zero for this address calculation */ /* REQ: EA063 */

    /*
        REQ: EA064: The function 'Ea_EraseImmediateBlock' shall ensure that the EA module can
        write immediate data. Whether this involves physically erasing a memory area and therefore
        calling the erase function of the underlying driver depends on the implementation.
    */

    /*
        REQ: EA065: Only erase if this block contains immediate data, otherwise raise 'EA_E_INVALID_BLOCK_NO'.
    */

    /*
        Note: The function 'Ea_EraseImmediateBlock' shall only be called by e.g. diagnostic or similar
        system services to pre-erase the area for immediate data if necassery.
    */

#if 0
    Ea_ModuleState = MEMIF_BUSY;
    Ea_JobState = MEMIF_JOB_PENDING;
    Ea_JobType = EA_JOB_TYPE_ERASE_IMMEDIATE;
#endif

    return E_OK;
}


FUNC(void, EA_CODE) Ea_JobEndNotification(void)
{

}


FUNC(void, EA_CODE) Ea_JobErrorNotification(void)
{

}


FUNC(void, EA_CODE) Ea_MainFunction(void)
{

}


#define EA_STOP_SEC_CODE
#include "MemMap.h"
