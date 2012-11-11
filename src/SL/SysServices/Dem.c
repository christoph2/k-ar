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


#define DEM_DEV_ERROR_DETECT            STD_ON

#include "Dem.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(DEM, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Dem.h' !
#endif

#if AR_DEV_ERROR_DETECT(DEM) == STD_ON

#include "Det.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(DET, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
#endif /* AR_DEV_ERROR_DETECT */

#define DEM_DEV_ERROR_DETECT            STD_ON

/*
**  Local Types.
*/


/*
** Local Function Prototypes.
*/


/*
**  Local Variables.
*/
#define DEM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

KAR_DEFINE_LOCAL_CONFIG_VAR(DEM, Dem);

#if AR_DEV_ERROR_DETECT(DEM) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(Dem);
#endif

#define DEM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


/*
**  Global Functions.
*/
#define DEM_START_SEC_CODE
#include "MemMap.h"

FUNC(void, DEM_CODE) Dem_Init(void)
{

}


FUNC(void, DEM_CODE) Dem_PreInit(P2CONST(Dem_ConfigType, AUTOMATIC, DEM_APPL_DATA) ConfigPtr)
{

}


FUNC(void, DEM_CODE) Dem_Shutdown(void)
{

}


FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC(uint32 DTC, Dem_DTCKindType DTCKind, Dem_DTCOriginType DTCOrigin)
{

}


FUNC(void, DEM_CODE) Dem_DcmCancelOperation(void)
{

}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecord(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameData(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication
)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition(uint8 StorageConditionID, boolean ConditionFulfilled)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame(Dem_EventIdType EventId)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DisableDTCRecordUpdate(void)
{
    return E_OK;
}


FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DisableDTCSetting(Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind)
{

}


FUNC(Std_ReturnType, DEM_CODE) Dem_EnableDTCRecordUpdate(void)
{
    return E_OK;
}


FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_EnableDTCSetting(Dem_DTCGroupType DTCGroup, Dem_DTCKindType DTCKind)
{

}


FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE) Dem_GetDTCByOccurrenceTime(
    Dem_DTCRequestType DTCRequest,
    Dem_DTCKindType DTCKind,    
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
)
{

}


FUNC(Dem_ReturnGetDTCOfFreezeFrameRecordType, DEM_CODE) Dem_GetDTCOfFreezeFrameRecord(
    uint8 RecordNumber,
    Dem_DTCOriginType DTCOrigin,
    Dem_DTCKindType DTCKind,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{

}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCStatusAvailabilityMask(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask)
{
    return E_OK;
}


FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_GetExtendedDataRecordByDTC(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{

}


FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_GetFreezeFrameDataByDTC(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{

}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetErrorStatus(uint8 EventInformation, uint8 EventStatus, Dem_EventIdType EventId)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFailed(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventFailed
)
{
    return E_OK;
}


FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredDTC(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{

}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventTested(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventTested
)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter(
    Dem_EventIdType EventId,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
)
{
    return E_OK;
}


FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE) Dem_GetSeverityOfDTC(
    uint32 DTC,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity
)
{

}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus(
    uint8 IndicatorId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
)
{
    return E_OK;
}


FUNC(Dem_ReturnGetSizeOfExtendedDataRecordByDTCType, DEM_CODE) Dem_GetSizeOfExtendedDataRecordByDTC(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
)
{

}


FUNC(Dem_ReturnGetSizeOfFreezeFrameType, DEM_CODE) Dem_GetSizeOfFreezeFrame(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
)
{

}


FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredDTCAndFDC(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter
)
{

}


FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_GetStatusOfDTC(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{

}



FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredDTCAndSeverity(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
)
{

}


FUNC(uint8, DEM_CODE) Dem_GetTranslationType(void)
{

}


FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredRecord(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) SnapshotRecord
)
{

}


FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE) Dem_SetDTCFilter(uint8 DTCStatusMask, Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin, Dem_FilterWithSeverityType FilterWithSeverity, 
    Dem_DTCSeverityType DTCSeverityMask, Dem_FilterForFDCType FilterForFaultDetectionCounter
)
{

}


FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_GetNumberOfFilteredDTC(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
)
{

}


FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE) Dem_SetDTCFilterForRecords(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords
)
{

}


#if 0
FUNC(void, DEM_CODE) Dem_GetRxSignalErrorStatus(Dem_FrRxSignalErrorStatusType Error Status, 
    uint16 Dem_RxSignalSignalId, uint16 Dem_RxSignalPduId, uint16 Dem_RxSignalFrameId,
    uint16 Dem_RxSignalSlotId, uint8 Dem_RxSignalCycle, uint16 Dem_RxSignalChannel
);  // TODO: ÜBERPRÜFEN!!!
#endif

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus(
    Dem_EventIdType EventId,
    P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, DEM_APPL_DATA) EventStatusExtended
)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetInfoTypeValue08(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetInfoTypeValue0B(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID01(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID02(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID02value)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID1C(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1Cvalue)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID21(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value)
{
    return E_OK;
}



FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID30(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID30value)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID31(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID41(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID4D(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID4E(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID5F(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock(Dem_RatioIdType RatioID)
{
    return E_OK;
}



FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease(Dem_RatioIdType RatioID)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect(Dem_RatioIdType RatioID)
{
    return E_OK;
}


FUNC(void, DEM_CODE) Dem_MainFunction(void)
{

}


FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled(Dem_EventIdType EventId)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetOBDFreezeFrameData(
    uint8 PID,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    return E_OK;
}


FUNC(void, DEM_CODE) Dem_ReportErrorStatus(Dem_EventIdType EventId, uint8 EventStatus)
{

}


FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleCounterValue(uint8 CounterValue)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleState(uint8 AgingCycleId)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleCntValue(uint8 OperationCycleId, uint8 CounterValue)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent(
    Dem_EventIdType EventId,
    Dem_DTCKindType DTCKind,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent
)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame(Dem_EventIdType EventId )
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus(Dem_EventIdType EventId)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(Dem_EventIdType EventId, uint8 EventStatus)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition(uint8 EnableConditionID, boolean ConditionFulfilleds)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState(uint8 OperationCycleId, uint8 CycleState)
{
    return E_OK;
}


FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus(boolean PtoStatus)
{
    return E_OK;
}

/*
** Local Functions
*/


#define DEM_STOP_SEC_CODE
#include "MemMap.h"

