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
 */
#include "RamTst.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(RAMTST, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'RamTst.h' !
#endif

#if 0
#include "SchM_RamTst.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'SchM_RamTst' !
#endif
#endif

#if RAMTST_DEV_ERROR_DETECT == STD_ON
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
#endif /* RAMTST_DEV_ERROR_DETECT */

#include "BIST/inc/Kdk_RamTest.h"

/* Implementation must be according to IEC61508-3!!! */

/*

 */

/*
    A.5.1   - RAM test "checkerboard" (or "march).
    Aim: To detect predominatly static bit failures.

    A.5.2   - RAM test "walkpath".
    Aim: To detect static and dynamic bit failures, and cross-talk between memory cells.

    A.5.3   - RAM test "galpat" (or transparent "galpat").
    Aim: To detect static bit failures and a large proportion of dynamic couplings.

    A.5.4   - RAM test "Abraham".
    Aim: To detect all stuck-at and coupling failures between memory cells.

    A.5.5   - One bit redundancy (for example RAM monitoring with a parity bit).
    Aim: To detect 50% of all possible bit failures in the memory range tested.

    A.5.6   - RAM monitoring with a modified Hamming code, or detection of data
    failures with an error-detection-correction codes (EDC).
    Aim: To detect all odd-bit failures, all two-bit failures, some three-bit
    failures and some multi-bit failures.

    A.5.7   - Double RAM with hardware or software comparision and read/write test.
    Aim: To detect all bit failures.


 */

/*
    MainFunction()  - Seite 15
    =============
 * inherently knows:
        - which algorithm it is using;
        - which memory blocks must be tested for this algorithm;
        - start and end address of each block;
        - number of cells to test at each call.
 * Remembers:
        - which block it is in;
        - which address to start at the next call;
        - status of the test;
        - overall test result;
        - test result for each block.
 */

/* Req!RamTst060: if non destructive RAM test is choosen, the RAM test module shall */
/* save the RAM area to be tested before the module modifies it. The RAM test module */
/* shall execute the complete procedure (saving, changing, restoring) without interruption. */

/*
    void RamTst_Completed_Notification(void);
    void RamTst_Error_Notification(void);
 */

#if 0
S .282 March Test Notation.
S .306 Algorithmen - Beschreibung(S .315 Augmented March tests)
------------------------------ -

MARCH C -
--------

MATS + march test algorithm :
-------------------------- -
M0 : { March element up or down(w0) }

for cell : = 0  to n - 1   /* or any other order. */

             do {
    begin
                     write 0 to A[cell];
}

end;

M1: { March element up(r0, w1) }

for cell : = 0 to n - 1

             do {
    begin
    read A[cell];
}

{ Expected value == 0}
write 1 to A[cell];

end;

M2: { March element down(r1, w0) }

for cell : = n - 1 down to 0

             do {
    begin
    read A[cell];
}

{ Expected value == 1}
write 0 to A[cell];

end;
#endif

#define RAMTST_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

RamTst_TestResultType RamTst_TestResult[RAMTST_TOTAL_NUMBER_OF_BLOCKS];

#if AR_DEV_ERROR_DETECT(RAMTST) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(RamTst);
#endif

#define RAMTST_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#if 0
#define RAMTST_E_STATUS_FAILURE 0x01
#define RAMTST_E_OUT_OF_RANGE   0x02
#define RAMTST_E_UNINIT         0x03
#define RAMTST_E_RAM_FAILURE    <ASSIGNED BY DEM>
#endif

/* !Req!RamTst089: The Function RamTst_Init() shall be called first before calling any other... */

#define RAMTST_START_SEC_CODE
#include "MemMap.h"
/*
**  Global Functions.
*/

FUNC(void, RAMTST_CODE) RamTst_Init(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    AR_MODULE_INITIALIZE(RamTst);
#endif /* RAMTST_DEV_ERROR_DETECT */
}

FUNC(void, RAMTST_CODE) RamTst_DeInit(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, DEINIT, RAMTST_E_UNINIT);
        return;
    }

    AR_MODULE_UNINITIALIZE(RamTst);
#endif /* RAMTST_DEV_ERROR_DETECT */
}

#if RAMTST_STOP_API == STD_ON
FUNC(void, RAMTST_CODE) RamTst_Stop(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, STOP, RAMTST_E_UNINIT);
        return;
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_STOP_API */

#if RAMTST_ALLOW_API == STD_ON
FUNC(void, RAMTST_CODE) RamTst_Allow(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, ALLOW, RAMTST_E_UNINIT);
        return;
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_ALLOW_API */

#if RAMTST_SUSPEND_API == STD_ON
FUNC(void, RAMTST_CODE) RamTst_Suspend(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, SUSPEND, RAMTST_E_UNINIT);
        return;
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_SUSPEND_API */

#if RAMTST_RESUME_API == STD_ON
FUNC(void, RAMTST_CODE) RamTst_Resume(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, RESUME, RAMTST_E_UNINIT);
        return;
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_RESUME_API */

#if RAMTST_GET_EXECUTION_STATUS_API == STD_ON
FUNC(RamTst_ExecutionStatusType, RAMTST_CODE) RamTst_GetExecutionStatus(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, GETEXECUTIONSTATUS, RAMTST_E_UNINIT);
        return RAMTST_EXECUTION_UNINIT;
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_GET_EXECUTION_STATUS_API */

#if RAMTST_GET_TEST_RESULT_API == STD_ON
FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResult(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, GETTESTRESULT, RAMTST_E_UNINIT);
        return RAMTST_RESULT_NOT_TESTED;    /* ??? */
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_GET_TEST_RESULT_API */

#if RAMTST_GET_TEST_RESULT_PER_BLOCK_API == STD_ON
FUNC(RamTst_TestResultType, RAMTST_CODE) RamTst_GetTestResultPerBlock(RamTst_NumberOfBlocksType BlockID)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, GETTESTRESULTPERBLOCK, RAMTST_E_UNINIT);
        return RAMTST_RESULT_NOT_TESTED;    /* ??? */
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_GET_TEST_RESULT_PER_BLOCK_API */

#if RAMTST_GET_TEST_ALGORITHM_API == STD_ON
FUNC(RamTst_AlgorithmType, RAMTST_CODE) RamTst_GetTestAlgorithm(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, GETTESTALGORITHM, RAMTST_E_UNINIT);
        return RAMTST_ALGORITHM_UNDEFINED;  /* ??? */
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_GET_TEST_ALGORITHM_API */

#if RAMTST_GET_NUMBER_OF_TESTED_CELLS_API == STD_ON
FUNC(RamTst_NumberOfTestedCellsType, RAMTST_CODE) RamTst_GetNumberOfTestedCells(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, CHANGENUMBEROFTESTEDCELLS, RAMTST_E_UNINIT);
        return (RamTst_NumberOfTestedCellsType)0;   /* ??? */
    }

#endif /* RAMTST_DEV_ERROR_DETECT */
}
#endif

#if RAMTST_CHANGE_TEST_ALGORITHM_API == STD_ON
FUNC(void, RAMTST_CODE) RamTst_ChangeTestAlgorithm(RamTst_AlgorithmType NewTestAlgorithm)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, CHANGETESTALGORITHM, RAMTST_E_UNINIT);
        return;
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_CHANGE_TEST_ALGORITHM_API */

#if RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API == STD_ON
FUNC(void, RAMTST_CODE) RamTst_ChangeNumberOfTestedCells(RamTst_NumberOfTestedCellsType NewNumberOfTestedCells)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, GETNUMBEROFTESTEDCELLS, RAMTST_E_UNINIT);
        return;
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API */

#if RAMTST_CHANGE_MAX_NUMBER_OF_TESTED_CELLS_API == STD_ON
FUNC(void, RAMTST_CODE) RamTst_ChangeMaxNumberOfTestedCells(RamTst_NumberOfTestedCellsType NewNumberOfTestedCells)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, CHANGEMAXNUMBEROFTESTEDCELLS, RAMTST_E_UNINIT);
        return;
    }

#endif  /* RAMTST_DEV_ERROR_DETECT */
}
#endif  /* RAMTST_CHANGE_MAX_NUMBER_OF_TESTED_CELLS_API */

FUNC(void, RAMTST_CODE) RamTst_MainFunction(void)
{
#if RAMTST_DEV_ERROR_DETECT == STD_ON

    if (!AR_MODULE_IS_INITIALIZED(RamTst)) {
        AR_RAISE_DEV_ERROR(RAMTST, MAINFUNCTION, RAMTST_E_UNINIT);
        return;
    }

#endif /* RAMTST_DEV_ERROR_DETECT */
}

#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"
