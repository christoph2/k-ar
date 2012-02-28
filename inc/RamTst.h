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
#if !defined(__RAMTST_H)
#define __RAMTST_H


#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "K_Ar.h"
#include "Std_Types.h"
#include "RamTst_Cfg.h"

/*
**  Published Information.
*/
#define RAMTST_VENDOR_ID                                AR_VENDOR_ID
#define RAMTST_MODULE_ID                                AR_MODULE_ID_RAMTST
#define RAMTST_AR_MAJOR_VERSION                         3
#define RAMTST_AR_MINOR_VERSION                         1
#define RAMTST_AR_PATCH_VERSION                         0
#define RAMTST_SW_MAJOR_VERSION                         1
#define RAMTST_SW_MINOR_VERSION                         0
#define RAMTST_SW_PATCH_VERSION                         0
#define RAMTST_INSTANCE_ID                              0


/*
**  Service-IDs.
*/
#define AR_SERVICE_RAMTST_INIT                          ((uint8)0x00)
#define AR_SERVICE_RAMTST_MAINFUNCTION                  ((uint8)0x01)
#define AR_SERVICE_RAMTST_STOP                          ((uint8)0x02)
#define AR_SERVICE_RAMTST_ALLOW                         ((uint8)0x03)
#define AR_SERVICE_RAMTST_GETEXECUTIONSTATUS            ((uint8)0x04)
#define AR_SERVICE_RAMTST_GETTESTRESULT                 ((uint8)0x05)
#define AR_SERVICE_RAMTST_GETTESTRESULTPERBLOCK         ((uint8)0x06)
#define AR_SERVICE_RAMTST_GETTESTALGORITHM              ((uint8)0x07)
#define AR_SERVICE_RAMTST_CHANGENUMBEROFTESTEDCELLS     ((uint8)0x08)
#define AR_SERVICE_RAMTST_GETNUMBEROFTESTEDCELLS        ((uint8)0x09)
#define AR_SERVICE_RAMTST_GETVERSIONINFO                ((uint8)0x0a)
#define AR_SERVICE_RAMTST_CHANGETESTALGORITHM           ((uint8)0x0b)
#define AR_SERVICE_RAMTST_DEINIT                        ((uint8)0x0c)
#define AR_SERVICE_RAMTST_SUSPEND                       ((uint8)0x0d)
#define AR_SERVICE_RAMTST_RESUME                        ((uint8)0x0e)
#define AR_SERVICE_RAMTST_CHANGEMAXNUMBEROFTESTEDCELLS  ((uint8)0x0f)    // ?



/*
**  Module-Errors.
*/
#define RAMTST_E_STATUS_FAILURE                         ((uint8)0x01)
#define RAMTST_E_OUT_OF_RANGE                           ((uint8)0x02)
#define RAMTST_E_UNINIT                                 ((uint8)0x03)
#if 0
#define RAMTST_E_RAM_FAILURE    <ASSIGNED BY DEM>
#endif



/*
**  Global Types.
*/

typedef uint16 RamTst_NumberOfBlocksType;
typedef uint32 RamTst_NumberOfTestedCellsType;


/* This is a value returned by the API service RamTst_GetTestAlgorithm(). */
typedef enum tagRamTst_AlgorithmType {
    RAMTST_ALGORITHM_UNDEFINED,
    RAMTST_CHECKERBOARD_TEST,
    RAMTST_MARCH_TEST,
    RAMTST_WALK_PATH_TEST,
    RAMTST_GALPAT_TEST,
    RAMTST_TRANSP_GALPAT_TEST,
    RAMTST_ABRAHAM_TEST
} RamTst_AlgorithmType;


typedef struct tagRamTst_BlockParameterType {
    uint16 RamTst_StartAddress; /* todo: Address-Type ('PlatformTypes.h') */
    uint16 RamTst_EndAddress;
} RamTst_BlockParameterType;


typedef struct tagRamTst_AlgorithmParameterType {
    RamTst_NumberOfBlocksType RamTst_NumberOfBlocks;

    RamTst_NumberOfTestedCellsType RamTst_ExtNumberOfTestedCells;
    RamTst_NumberOfTestedCellsType RamTst_MaxNumberOfTestedCells;  /* Initial Value of a RAM variable,
                                                                can be change with 'RamTst_ChangeMaxNumberOfTestedCells'.  */
    RamTst_NumberOfTestedCellsType RamTst_NumberOfTestedCells;  /* Initial Value of a RAM variable,
                                                                can be change with 'RamTst_ChangeNumberOfTestedCells'.  */
    const * const RamTst_BlockParams;

} RamTst_AlgorithmParameterType;

/* This type of the external data structure shall contain the initialization data for the RAM Test */
typedef struct tagRamTst_ConfigType {
    RamTst_AlgorithmParameterType const * const RamTst_AlgParams;
} RamTst_ConfigType;


/* This is a status value returned by the API service RamTst_GetExecutionStatus(). */
typedef enum tagRamTst_ExecutionStatusType {
    RAMTST_EXECUTION_UNINIT,
    RAMTST_EXECUTION_INIT,
    RAMTST_EXECUTION_RUNNING,
    RAMTST_EXECUTION_STOPPED,
    RAMTST_EXECUTION_SUSPENDED,
    RAMTST_EXECUTION_ALLOWED,
    RAMTST_EXECUTION_STATE_UNDEFINED       /* State used for manufacturers white box testing. */
} RamTst_ExecutionStatusType;


/* This is a status value returned by the API service RamTst_GetTestResult(). */
typedef enum tagRamTst_TestResultType {
    RAMTST_RESULT_NOT_TESTED,
    RAMTST_RESULT_OK,
    RAMTST_RESULT_NOT_OK,
    RAMTST_RESULT_UNDEFINED
} RamTst_TestResultType;


/*
**  Global Functions.
*/
FUNC(void,RAMTST_CODE) RamTst_Init(void);
FUNC(void,RAMTST_CODE) RamTst_DeInit(void);
FUNC(void,RAMTST_CODE) RamTst_Stop(void);
FUNC(void,RAMTST_CODE) RamTst_Allow(void);
FUNC(void,RAMTST_CODE) RamTst_Suspend(void);
FUNC(void,RAMTST_CODE) RamTst_Resume(void);
FUNC(RamTst_ExecutionStatusType,RAMTST_CODE) RamTst_GetExecutionStatus(void);
FUNC(RamTst_TestResultType,RAMTST_CODE) RamTst_GetTestResult(void);
FUNC(RamTst_TestResultType,RAMTST_CODE) RamTst_GetTestResultPerBlock(RamTst_NumberOfBlocksType BlockID);
FUNC(RamTst_AlgorithmType,RAMTST_CODE) RamTst_GetTestAlgorithm(void);
FUNC(RamTst_NumberOfTestedCellsType,RAMTST_CODE) RamTst_GetNumberOfTestedCells(void);
FUNC(void,RAMTST_CODE) RamTst_ChangeTestAlgorithm(RamTst_AlgorithmType NewTestAlgorithm);
FUNC(void,RAMTST_CODE) RamTst_ChangeNumberOfTestedCells(RamTst_NumberOfTestedCellsType NewNumberOfTestedCells);
FUNC(void,RAMTST_CODE) RamTst_ChangeMaxNumberOfTestedCells(RamTst_NumberOfTestedCellsType NewNumberOfTestedCells);
FUNC(void,RAMTST_CODE) RamTst_MainFunction(void);


/*
**  Global Function-like Macros.
*/
#if RAMTST_GET_VERSION_INFO_API == STD_ON
#define RamTst_GetVersionInfo(vp) AR_GET_VERSION_INFO(RAMTST, vp)
#endif /* RAMTST_GET_VERSION_INFO_API */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */


#endif  /* __RAMTST_H */
