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

#include "Eep.h"

#if AR_VERSION_CHECK_INTERNAL_FAILS(EEP, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Eep.h' !
#endif

//#if AR_DEV_ERROR_DETECT(EEP) == STD_ON
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
//#endif /* AR_DEV_ERROR_DETECT */

#include "Dem.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(DEM, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Dem.h' !
#endif

#if 0
#include "SchM_Eep.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(SCHM_EEP, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File '"SchM_Eep.h' !
#endif
#endif

#include "MemIf_Types.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(MEMIF_TYPES, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'MemIf_Types.h' !
#endif

/* #include "Eep_Cbk.h" */

#include "K_Ar.h"   // TODO: Nur vorrübergehend!!!

#include "MCALTemplates/Mcal_Templates.h"


/*
**  Local Types.
*/
typedef enum tagEep_JobTypeType {
    EEP_JOB_TYPE_NONE,
    EEP_JOB_TYPE_READ,
    EEP_JOB_TYPE_WRITE,
    EEP_JOB_TYPE_ERASE,
    EEP_JOB_TYPE_COMPARE
} Eep_JobTypeType;


/*
**  Local Variables.
*/
#define EEP_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

KAR_DEFINE_LOCAL_CONFIG_VAR(EEP, Eep);

#if AR_DEV_ERROR_DETECT(EEP) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(Eep);
#endif


#if AR_DEV_ERROR_DETECT(EEP) == STD_ON
/* TODO: 'extern' declaration in header file! */
MemIf_JobResultType Eep_JobResult = MEMIF_JOB_OK;
MemIf_StatusType Eep_Status = MEMIF_UNINIT;
MemIf_ModeType Eep_Mode = MEMIF_MODE_SLOW;
#else
STATIC MemIf_JobResultType Eep_JobResult = MEMIF_JOB_OK;
STATIC MemIf_StatusType Eep_Status = MEMIF_UNINIT;
STATIC MemIf_ModeType Eep_Mode = MEMIF_MODE_SLOW;
#endif

STATIC Eep_JobTypeType Eep_JobType = EEP_JOB_TYPE_NONE;

#if 0
#define EEP_RMW_BUFFER_SIZE 4   // TODO: NUR ZUM TESTEN!!!
static uint8 Eep_RMW_Buffer[EEP_RMW_BUFFER_SIZE];
#endif

#define EEP_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


// EEP_BASE_ADDRESS
// EEP_SIZE

/*
**  Global Functions.
*/
#define EEP_START_SEC_CODE
#include "MemMap.h"

FUNC(void, EEP_CODE) Eep_Init(
    P2CONST(Eep_ConfigType, AUTOMATIC, EEP_APPL_DATA) ConfigPtr
)
{
#if EEP_DEV_ERROR_DETECT == STD_ON
    if (ConfigPtr == NULL /* and VariantPB */) {
        AR_RAISE_DEV_ERROR(EEP, INIT, EEP_E_PARAM_CONFIG);
            return;
    }

    AR_MODULE_INITIALIZE(Eep);
#endif /* EEP_DEV_ERROR_DETECT */

    AR_SAVE_CONFIG_PTR(Eep);

    Eep_Status = MEMIF_IDLE;
    Eep_JobResult = MEMIF_JOB_OK;
}


FUNC(void, EEP_CODE) Eep_SetMode(MemIf_ModeType Mode)
{
#if EEP_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Eep)) {
        AR_RAISE_DEV_ERROR(EEP, SETMODE, EEP_E_UNINIT);
    }

    if (Eep_Status == MEMIF_BUSY) {
        AR_RAISE_DEV_ERROR(EEP, SETMODE, EEP_E_BUSY);
    }
#endif /* EEP_DEV_ERROR_DETECT */

    Eep_Mode = Mode;
}


FUNC(Std_ReturnType, EEP_CODE) Eep_Read(
    Eep_AddressType EepromAddress,
    P2VAR(uint8, AUTOMATIC, EEP_APPL_DATA) DataBufferPtr,
    Eep_LengthType Length
)
{
#if EEP_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Eep)) {
        AR_RAISE_DEV_ERROR(EEP, READ, EEP_E_UNINIT);
        return E_NOT_OK;
    }

    if (Eep_Status == MEMIF_BUSY) {
        AR_RAISE_DEV_ERROR(EEP, READ, EEP_E_BUSY);
        return E_NOT_OK;
    }

    if (DataBufferPtr == NULL) {
        AR_RAISE_DEV_ERROR(EEP, READ, EEP_E_PARAM_DATA);
        return E_NOT_OK;
    }
    /* TODO: Address check! */
    /* TODO: Length check! */
#endif /* EEP_DEV_ERROR_DETECT */

    /* TODO: Initiate read job. -- SetEvent() */

    Eep_Status = MEMIF_BUSY;
    Eep_JobResult = MEMIF_JOB_PENDING;
    Eep_JobType = EEP_JOB_TYPE_READ;

    return E_OK;
}


FUNC(Std_ReturnType, EEP_CODE) Eep_Write(
    Eep_AddressType EepromAddress,
    P2CONST(uint8, AUTOMATIC, EEP_APPL_DATA) DataBufferPtr,
    Eep_LengthType Length
)
{
#if EEP_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Eep)) {
        AR_RAISE_DEV_ERROR(EEP, WRITE, EEP_E_UNINIT);
        return E_NOT_OK;
    }

    if (Eep_Status == MEMIF_BUSY) {
        AR_RAISE_DEV_ERROR(EEP, WRITE, EEP_E_BUSY);
        return E_NOT_OK;
    }

    if (DataBufferPtr == NULL) {
        AR_RAISE_DEV_ERROR(EEP, WRITE, EEP_E_PARAM_DATA);
        return E_NOT_OK;
    }
    /* TODO: Address check! */
    /* TODO: Length check! */
#endif /* EEP_DEV_ERROR_DETECT */

    /* TODO: Initiate write job -- SetEvent(). */

    Eep_Status = MEMIF_BUSY;
    Eep_JobResult = MEMIF_JOB_PENDING;
    Eep_JobType = EEP_JOB_TYPE_WRITE;

    return E_OK;
}


FUNC(Std_ReturnType, EEP_CODE) Eep_Erase(
    Eep_AddressType EepromAddress,
    Eep_LengthType Length
)
{
#if EEP_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Eep)) {
        AR_RAISE_DEV_ERROR(EEP, ERASE, EEP_E_UNINIT);
        return E_NOT_OK;
    }

    if (Eep_Status == MEMIF_BUSY) {
        AR_RAISE_DEV_ERROR(EEP, ERASE, EEP_E_BUSY);
        return E_NOT_OK;
    }

    /* TODO: Address check! */
    /* TODO: Length check! */
#endif /* EEP_DEV_ERROR_DETECT */

    /* TODO: Initiate erase job -- SetEvent() . */

    Eep_Status = MEMIF_BUSY;
    Eep_JobResult = MEMIF_JOB_PENDING;
    Eep_JobType = EEP_JOB_TYPE_ERASE;

    return E_OK;
}


FUNC(Std_ReturnType, EEP_CODE) Eep_Compare(
    Eep_AddressType EepromAddress,
    P2CONST(uint8, AUTOMATIC, EEP_APPL_DATA) DataBufferPtr,
    Eep_LengthType Length
)
{
#if EEP_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Eep)) {
        AR_RAISE_DEV_ERROR(EEP, COMPARE, EEP_E_UNINIT);
        return E_NOT_OK;
    }

    if (Eep_Status == MEMIF_BUSY) {
        AR_RAISE_DEV_ERROR(EEP, COMPARE, EEP_E_BUSY);
        return E_NOT_OK;
    }

    if (DataBufferPtr == NULL) {
        AR_RAISE_DEV_ERROR(EEP, COMPARE, EEP_E_PARAM_DATA);
        return E_NOT_OK;
    }
    /* TODO: Address check! */
    /* TODO: Length check! */
#endif /* EEP_DEV_ERROR_DETECT */

    /* TODO: Initiate compare job -- SetEvent() . */

    Eep_Status = MEMIF_BUSY;
    Eep_JobResult = MEMIF_JOB_PENDING;
    Eep_JobType = EEP_JOB_TYPE_COMPARE;

    return E_OK;
}


FUNC(void, EEP_CODE) Eep_Cancel(void)
{
    /* TODO: Cancel ongoing job. */

    Eep_Status = MEMIF_IDLE;
    if (Eep_JobResult == MEMIF_JOB_PENDING) {
        Eep_JobResult = MEMIF_JOB_CANCELED;
    }
}


FUNC(MemIf_StatusType, EEP_CODE) Eep_GetStatus(void)
{
    return Eep_Status;
}


FUNC(MemIf_JobResultType, EEP_CODE) Eep_GetJobResult(void)
{
    return Eep_JobResult;
}


FUNC(void, EEP_CODE) Eep_MainFunction(void)
{
    if (Eep_JobType != EEP_JOB_TYPE_NONE) {

    }
}

#define EEP_STOP_SEC_CODE
#include "MemMap.h"

