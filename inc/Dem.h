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

/* #include "Dem_Cfg.h" */
#include "Std_Types.h"
#include "Dem_IntErrId.h"


#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


/*
**  todo: 'Cfg' !!!
*/
#define DEM_DEV_ERROR_DETECT    STD_ON
#define DEM_VERSION_INFO_API    STD_ON


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
**
**  Service-IDs.
**
*/
#define AR_SERVICE_DEM_GETVERSIONINFO                   ((uint8)0)
#define AR_SERVICE_DEM_PREINIT                          ((uint8)1)
#define AR_SERVICE_DEM_INIT                             ((uint8)2)
#define AR_SERVICE_DEM_SHUTDOWN                         ((uint8)3)
#define AR_SERVICE_DEM_SETEVENTSTATUS                   ((uint8)4)
#define AR_SERVICE_DEM_RESETEVENTSTATUS                 ((uint8)5)
#define AR_SERVICE_DEM_PRESTOREFREEZEFRAME              ((uint8)6)
#define AR_SERVICE_DEM_CLEARPRESTOREDFREEZEFRAME        ((uint8)7)
#define AR_SERVICE_DEM_SETOPERATIONCYCLESTATE           ((uint8)8)
#define AR_SERVICE_DEM_SETOPERATIONCYCLECNTVALUE        ((uint8)9)
#define AR_SERVICE_DEM_GETEVENTSTATUS                   ((uint8)10)
#define AR_SERVICE_DEM_GETEVENTFAILED                   ((uint8)11)
#define AR_SERVICE_DEM_GETEVENTTESTED                   ((uint8)12)
#define AR_SERVICE_DEM_GETDTCOFEVENT                    ((uint8)13)
#define AR_SERVICE_DEM_GETSEVERITYOFDTC                 ((uint8)14)
#define AR_SERVICE_DEM_REPORTERRORSTATUS                ((uint8)15)
#define AR_SERVICE_DEM_SETAGINGCYCLESTATE               ((uint8)17)
#define AR_SERVICE_DEM_SETAGINGCYCLECOUNTERVALUE        ((uint8)18)
#define AR_SERVICE_DEM_SETDTCFILTER                     ((uint8)19)
#define AR_SERVICE_DEM_GETSTATUSOFDTC                   ((uint8)21)
#define AR_SERVICE_DEM_GETDTCSTATUSAVAILABILITYMASK     ((uint8)22)
#define AR_SERVICE_DEM_GETNUMBEROFFILTEREDDTC           ((uint8)23)
#define AR_SERVICE_DEM_GETNEXTFILTEREDDTC               ((uint8)24)
#define AR_SERVICE_DEM_GETDTCBYOCCURRENCETIME           ((uint8)25)
#define AR_SERVICE_DEM_DISABLEDTCRECORDUPDATE           ((uint8)26)
#define AR_SERVICE_DEM_ENABLEDTCRECORDUPDATE            ((uint8)27)
#define AR_SERVICE_DEM_GETDTCOFFREEZEFRAMERECORD        ((uint8)28)
#define AR_SERVICE_DEM_GETFREEZEFRAMEDATABYDTC          ((uint8)29)
#define AR_SERVICE_DEM_GETSIZEOFFREEZEFRAME             ((uint8)31)
#define AR_SERVICE_DEM_GETEXTENDEDDATARECORDBYDTC       ((uint8)32)
#define AR_SERVICE_DEM_GETSIZEOFEXTENDEDDATARECORDBYDTC ((uint8)33)
#define AR_SERVICE_DEM_CLEARDTC                         ((uint8)34)
#define AR_SERVICE_DEM_DISABLEDTCSETTING                ((uint8)36)
#define AR_SERVICE_DEM_ENABLEDTCSETTING                 ((uint8)37)
#define AR_SERVICE_DEM_GETINDICATORSTATUS               ((uint8)41)
#define AR_SERVICE_DEM_DCMCANCELOPERATION               ((uint8)42)
#define AR_SERVICE_DEM_GETEVENTEXTENDEDDATARECORD       ((uint8)48)
#define AR_SERVICE_DEM_GETEVENTFREEZEFRAMEDATA          ((uint8)49)
#define AR_SERVICE_DEM_GETEVENTMEMORYOVERFLOW           ((uint8)50)
#define AR_SERVICE_DEM_SETSTORAGECONDITION              ((uint8)56)
#define AR_SERVICE_DEM_SETENABLECONDITION               ((uint8)57)
#define AR_SERVICE_DEM_GETNEXTFILTEREDRECORD            ((uint8)58)
#define AR_SERVICE_DEM_GETNEXTFILTEREDDTCANDFDC         ((uint8)59)
#define AR_SERVICE_DEM_GETTRANSLATIONTYPE               ((uint8)60)
#define AR_SERVICE_DEM_GETNEXTFILTEREDDTCANDSEVERITY    ((uint8)61)
#define AR_SERVICE_DEM_GETFAULTDETECTIONCOUNTER         ((uint8)62)
#define AR_SERVICE_DEM_SETDTCFILTERFORRECORDS           ((uint8)63)
#define AR_SERVICE_DEM_SETEVENTDISABLED                 ((uint8)81)
#define AR_SERVICE_DEM_GETOBDFREEZEFRAMEDATA            ((uint8)82)
#define AR_SERVICE_DEM_MAINFUNCTION                     ((uint8)85)
#define AR_SERVICE_DEM_DCMGETPID01                      ((uint8)97)
#define AR_SERVICE_DEM_DCMGETPID02                      ((uint8)98)
#define AR_SERVICE_DEM_DCMGETPID1C                      ((uint8)99)
#define AR_SERVICE_DEM_DCMGETPID21                      ((uint8)100)
#define AR_SERVICE_DEM_DCMGETPID30                      ((uint8)101)
#define AR_SERVICE_DEM_DCMGETPID31                      ((uint8)102)
#define AR_SERVICE_DEM_DCMGETPID41                      ((uint8)103)
#define AR_SERVICE_DEM_DCMGETPID4D                      ((uint8)104)
#define AR_SERVICE_DEM_DCMGETPID4E                      ((uint8)105)
#define AR_SERVICE_DEM_DCMGETPID5F                      ((uint8)106)
#define AR_SERVICE_DEM_GETINFOTYPEVALUE08               ((uint8)107)
#define AR_SERVICE_DEM_GETINFOTYPEVALUE0B               ((uint8)108)
#define AR_SERVICE_DEM_REPIUMPRDENLOCK                  ((uint8)113)
#define AR_SERVICE_DEM_REPIUMPRDENRELEASE               ((uint8)114)
#define AR_SERVICE_DEM_REPIUMPRFAULTDETECT              ((uint8)115)
#define AR_SERVICE_DEM_SETPTOSTATUS                     ((uint8)121)


/*
**  Module-Errors.
*/
#define DEM_E_PARAM_CONFIG                              ((uint8)0x10)
#define DEM_E_PARAM_ADDRESS                             ((uint8)0x11)
#define DEM_E_PARAM_DATA                                ((uint8)0x12)
#define DEM_E_PARAM_LENGTH                              ((uint8)0x13)
#define DEM_E_UNINIT                                    ((uint8)0x20)
#define DEM_E_NODATAAVAILABLE                           ((uint8)0x30)
#define DEM_E_WRONG_CONDITION                           ((uint8)0x40)


/*
**  Global Types.
*/

/*
**  DEM data types.
*/

typedef uint16 Dem_RatioIdType;
/* Identification of an event by assigned EventId. The EventId is assigned by the DEM. */


typedef uint16 Dem_EventIdType;


typedef struct tagDem_ConfigType {
    uint8 dummy;
} Dem_ConfigType;


/*
 * In this data-type each bit has an individual meaning.  The bit is set to 1 when the condition holds.
 * For example, if the 2nd bit (0x02) is set to 1, this means that the test failed this operation cycle.
 * If the bit is set to 0, it has not yet failed this cycle.
 */
typedef enum tagDem_EventStatusExtendedType {
    testFailed                          = 0x01,
    testFailedThisOperationCycle        = 0x02,
    pendingDTC                          = 0x04,
    confirmedDTC                        = 0x08,
    testNotCompletedSinceLastClear      = 0x10,
    testFailedSinceLastClear            = 0x20,
    testNotCompletedThisOperationCycle  = 0x40,
    warningIndicatorRequested           = 0x80
} Dem_EventStatusExtendedType;



/* Selects a group of DTCs. */
typedef enum tagDem_DTCGroupType {
    DEM_DTC_GROUP_EMISSION_REL_DTCS     = 0x000000, /* selects group of OBD-relevant DTCs */
#if 0
    DEM_DTC_GROUP_BODY_DTCS []                      /* selects group of body DTCs */
    DEM_DTC_GROUP_CHASSIS_DTCS []                   /* selects group of chassis DTCs */
    DEM_DTC_GROUP_NETWORK_COM_DTCS []               /* selects group of network communication DTCs */
    DEM_DTC_GROUP_POWERTRAIN_DTCS []                /* selects group of powertrain DTCs */
#endif
    DEM_DTC_GROUP_ALL_DTCS              = 0xffffff  /* 0xFFFFFF: selects all DTCs */
} Dem_DTCGroupType;


typedef enum tagDem_DTCKindType {
    DEM_DTC_KIND_ALL_DTCS               = 1,        /* Select all DTCs */
    DEM_DTC_KIND_EMISSION_REL_DTCS      = 2         /* Select OBD-relevant DTCs */
} Dem_DTCKindType;


/* This enum is used to define the location of the events. The definition and use of the different memory types is OEM-specific.  */
typedef enum tagDem_DTCOriginType {
    DEM_DTC_ORIGIN_PRIMARY_MEMORY       = 1,        /* Event information located in the primary memory */
    DEM_DTC_ORIGIN_MIRROR_MEMORY        = 2,        /* Event information located in the mirror memory */
    DEM_DTC_ORIGIN_PERMANENT_MEMORY     = 3,        /* The Event information is located in the permanent memory */
    DEM_DTC_ORIGIN_SECONDARY_MEMORY     = 4         /* Event information located in the secondary memory */
} Dem_DTCOriginType;


typedef enum tagDem_DTCRequestType {
    DEM_FIRST_FAILED_DTC                = 1,        /* first failed DTC requested */
    DEM_MOST_RECENT_FAILED_DTC          = 2,        /* most recent failed DTC requested */
    DEM_FIRST_DET_CONFIRMED_DTC         = 3,        /* first detected confirmed DTC requested */
    DEM_MOST_REC_DET_CONFIRMED_DTC      = 4         /* most recently detected confirmed DTC requested */
} Dem_DTCRequestType;


/* Defines the type of a DTCSeverityMask according to ISO14229-1. */
typedef enum tagDem_DTCSeverityType {
    DEM_SEVERITY_NO_SEVERITY            = 0x00,     /* No severity information available */
    DEM_SEVERITY_MAINTENANCE_ONLY       = 0x20,     /* maintenance required */
    DEM_SEVERITY_CHECK_AT_NEXT_HALT     = 0x40,     /* check at next halt */
    DEM_SEVERITY_CHECK_IMMEDIATELY      = 0x80      /* Check immediately */
} Dem_DTCSeverityType;
/* Pointer to the abnormality information of the reception signal. */


typedef enum tagDem_FilterForFDCType {
    DEM_FILTER_FOR_FDC_YES,                         /* Fault Detection Counter information used */
    DEM_FILTER_FOR_FDC_NO                           /* Fault Detection Counter information not used */
} Dem_FilterForFDCType;


typedef enum tagDem_FilterWithSeverityType {
    DEM_FILTER_WITH_SEVERITY_YES,                   /* Severity information used */
    DEM_FILTER_WITH_SEVERITY_NO                     /* Severity information not used */
} Dem_FilterWithSeverityType;


typedef enum tagDem_FrRxSignalErrorStatusType {
    DEM_REDUNDANCY_NOT_OK_ALL,                      /* All data receptions abnormal */
    DEM_REDUNDANCY_OK_ONE,                          /* One data or more normal */
    DEM_REDUNDANCY_OK_TWO,                          /* Two items of data or more normal */
    DEM_REDUNDANCY_NOT_OK_MATCH                     /* Data discrepancy abnormal */
} Dem_FrRxSignalErrorStatusType;


/*
**  DEM return types.
*/


/* Used to return the status of Dem_GetStatusOfDTC. */
typedef enum tagDem_ReturnGetStatusOfDTCType {
    DEM_STATUS_OK,                                  /* Status of DTC is OK */
    DEM_STATUS_WRONG_DTC,                           /* Wrong DTC */
    DEM_STATUS_WRONG_DTCORIGIN,                     /* Wrong DTC origin */
    DEM_STATUS_WRONG_DTCKIND,                       /* DTC kind wrong */
    DEM_STATUS_FAILED                               /* DTC failed */
} Dem_ReturnGetStatusOfDTCType;


/* Used to return the status of Dem_GetNextFilteredDTC. */
typedef enum tagDem_ReturnGetNextFilteredDTCType {
    DEM_FILTERED_OK,                                /* Returned next filtered DTC */
    DEM_FILTERED_NO_MATCHING_DTC,                   /* No DTC matched */
    DEM_FILTERED_WRONG_DTCKIND,                     /* DTC kind wrong */
    DEM_FILTERED_PENDING                            /* The requested value is currently not available.  The caller can retry later. */
} Dem_ReturnGetNextFilteredDTCType;


/* Used to return the status of Dem_GetNumberOfFilteredDTC. */
typedef enum tagDem_ReturnGetNumberOfFilteredDTCType {
    DEM_NUMBER_OK,                                  /* get of number of DTC was successful */
    DEM_NUMBER_FAILED,                              /* get of number of DTC failed */
    DEM_NUMBER_PENDING                              /* get of number of DTC is pending */
} Dem_ReturnGetNumberOfFilteredDTCType;


/* Used to return the status of Dem_ClearDTC. */
typedef enum tagDem_ReturnClearDTCType {
    DEM_CLEAR_OK,                                   /* DTC successfully cleared */
    DEM_CLEAR_WRONG_DTC,                            /* Wrong DTC */
    DEM_CLEAR_WRONG_DTCORIGIN,                      /* Wrong DTC origin */
    DEM_CLEAR_WRONG_DTCKIND,                        /* DTC kind wrong */
    DEM_CLEAR_FAILED,                               /* DTC not cleared */
    DEM_CLEAR_PENDING                               /* Clearing of DTC is pending */
} Dem_ReturnClearDTCType;


/* Used to return the status of Dem_DisableDTCSetting and Dem_EnableDTCSetting. */
typedef enum tagDem_ReturnControlDTCSettingType {
    DEM_CONTROL_DTC_SETTING_OK,                     /* DTC setting control successful */
    DEM_CONTROL_DTC_SETTING_N_OK,                   /* DTC setting control not successful */
    DEM_CONTROL_DTC_WRONG_DTCGROUP                  /* DTC setting control not successful because group of DTC was wrong */
} Dem_ReturnControlDTCSettingType;


/* Used to return the status of Dem_GetDTCOfFreezeFrameRecord. */
typedef enum tagDem_ReturnGetDTCOfFreezeFrameRecordType {
    DEM_GET_DTCOFFF_OK,                             /* DTC successfully returned */
    DEM_GET_DTCOFFF_WRONG_RECORD,                   /* Wrong record */
    DEM_GET_DTCOFFF_NO_DTC_FOR_RECORD,              /* No DTC for record available */
    DEM_GET_DTCOFFF_WRONG_DTCKIND                   /* DTC kind wrong */
} Dem_ReturnGetDTCOfFreezeFrameRecordType;


/* Used to return the status of Dem_GetExtendedDataRecordByDTC. */
typedef enum tagDem_ReturnGetExtendedDataRecordByDTCType {
    DEM_RECORD_OK,                                  /* Extended data record successfully returned */
    DEM_RECORD_WRONG_DTC,                           /* Wrong DTC */
    DEM_RECORD_WRONG_DTCORIGIN,                     /* Origin wrong */
    DEM_RECORD_WRONG_DTCKIND,                       /* DTC kind wrong */
    DEM_RECORD_WRONG_NUMBER,                        /* Record number wrong */
    DEM_RECORD_WRONG_BUFFERSIZE,                    /* Provided buffer to small  */
    DEM_RECORD_PENDING                              /* The requested value is currently not available.  The caller can retry later. */
} Dem_ReturnGetExtendedDataRecordByDTCType;


/* Status of the operation of type Dem_ReturnGetDTCByOccurrenceTime. */
typedef enum tagDem_ReturnGetDTCByOccurrenceTimeType {
    DEM_OCCURR_OK,                                  /* Status of DTC was OK */
    DEM_OCCURR_WRONG_DTCKIND,                       /* DTC kind wrong */
    DEM_OCCURR_FAILED                               /* DTC failed */
} Dem_ReturnGetDTCByOccurrenceTimeType;


/* Used to return the status of Dem_GetFreezeFrameDataByDTC. */
typedef enum tagDem_ReturnGetFreezeFrameDataByDTCType {
    DEM_GET_FFDATABYDTC_OK,                         /* Size successfully returned. */
    DEM_GET_FFDATABYDTC_WRONG_DTC,                  /* Wrong DTC */
    DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN,            /* Wrong DTC origin */
    DEM_GET_FFDATABYDTC_WRONG_DTCKIND,              /* DTC kind wrong */
    DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER,         /* Wrong Record Number */
    DEM_GET_FFDATABYDTC_WRONG_BUFFERSIZE,           /* provided buffer size to small */
    DEM_GET_FFDATABYDTC_PENDING                     /* The requested value is currently not available.  The caller can retry later. */
} Dem_ReturnGetFreezeFrameDataByDTCType;


/* Used to return the status of Dem_GetSizeOfExtendedDataRecordByDTC. */
typedef enum tagDem_ReturnGetSizeOfExtendedDataRecordByDTCType {
    DEM_GET_SIZEOFEDRBYDTC_OK,                      /* Size successfully returned. */
    DEM_GET_SIZEOFEDRBYDTC_W_DTC,                   /* Wrong DTC */
    DEM_GET_SIZEOFEDRBYDTC_W_DTCOR,                 /* Wrong DTC origin */
    DEM_GET_SIZEOFEDRBYDTC_W_DTCKI,                 /* DTC kind wrong */
    DEM_GET_SIZEOFEDRBYDTC_W_RNUM,                  /* Wrong Record Number */
    DEM_GET_SIZEOFEDRBYDTC_PENDING                  /* The requested value is currently not available.  The caller can retry later. */
} Dem_ReturnGetSizeOfExtendedDataRecordByDTCType;


/* Used to return the status of Dem_GetSizeOfFreezeFrame. */
typedef enum tagDem_ReturnGetSizeOfFreezeFrameType {
    DEM_GET_SIZEOFFF_OK,                            /* Size successfully returned. */
    DEM_GET_SIZEOFFF_WRONG_DTC,                     /* Wrong DTC */
    DEM_GET_SIZEOFFF_WRONG_DTCOR,                   /* Wrong DTC origin */
    DEM_GET_SIZEOFFF_WRONG_DTCKIND,                 /* DTC kind wrong */
    DEM_GET_SIZEOFFF_WRONG_RNUM,                    /* Wrong Record Number */
    DEM_GET_SIZEOFFF_PENDING                        /* The requested value is currently not available.  The caller can retry later. */
} Dem_ReturnGetSizeOfFreezeFrameType;


/* Used to return the status of Dem_GetSeverityOfDTC. */
typedef enum tagDem_ReturnGetSeverityOfDTCType {
    DEM_GET_SEVERITYOFDTC_OK,                       /* Severity successfully returned. */
    DEM_GET_SEVERITYOFDTC_WRONG_DTC,                /* Wrong DTC */
    DEM_GET_SEVERITYOFDTC_WRONG_DTCORIGIN,          /* Wrong DTC origin */
    DEM_GET_SEVERITYOFDTC_NOSEVERITY                /* Severity information is not available */
} Dem_ReturnGetSeverityOfDTCType;


/* Used to return the status of updating the DTC filter. */
typedef enum tagDem_ReturnSetDTCFilterType {
    DEM_FILTER_ACCEPTED,                            /* Filter was accepted */
    DEM_WRONG_FILTER                                /* Wrong filter selected */
} Dem_ReturnSetDTCFilterType;


/*
**  Global Functions.
*/
FUNC(void, DEM_CODE) Dem_Init(void);

FUNC(void, DEM_CODE) Dem_PreInit(P2CONST(Dem_ConfigType, AUTOMATIC, DEM_APPL_DATA) ConfigPtr);

FUNC(void, DEM_CODE) Dem_Shutdown(void);

FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_ClearDTC(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin
);

FUNC(void, DEM_CODE) Dem_DcmCancelOperation(void);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecord(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameData(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication
);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition(uint8 StorageConditionID, boolean ConditionFulfilled);

FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame(Dem_EventIdType EventId);

FUNC(Std_ReturnType, DEM_CODE) Dem_DisableDTCRecordUpdate(void);

FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_DisableDTCSetting(
    Dem_DTCGroupType DTCGroup,
    Dem_DTCKindType DTCKind
);

FUNC(Std_ReturnType, DEM_CODE) Dem_EnableDTCRecordUpdate(void);

FUNC(Dem_ReturnControlDTCSettingType, DEM_CODE) Dem_EnableDTCSetting(
    Dem_DTCGroupType DTCGroup,
    Dem_DTCKindType DTCKind
);

FUNC(Dem_ReturnGetDTCByOccurrenceTimeType, DEM_CODE) Dem_GetDTCByOccurrenceTime(
    Dem_DTCRequestType DTCRequest,
    Dem_DTCKindType DTCKind,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
);

FUNC(Dem_ReturnGetDTCOfFreezeFrameRecordType, DEM_CODE) Dem_GetDTCOfFreezeFrameRecord(
    uint8 RecordNumber,
    Dem_DTCOriginType DTCOrigin,
    Dem_DTCKindType DTCKind,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCStatusAvailabilityMask(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask
);

FUNC(Dem_ReturnGetExtendedDataRecordByDTCType, DEM_CODE) Dem_GetExtendedDataRecordByDTC(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) ExtendedDataNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize
);

FUNC(Dem_ReturnGetFreezeFrameDataByDTCType, DEM_CODE) Dem_GetFreezeFrameDataByDTC(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetErrorStatus(
    uint8 EventInformation,
    uint8 EventStatus,
    Dem_EventIdType EventId
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFailed(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventFailed
);

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredDTC(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventTested(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventTested
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter(
    Dem_EventIdType EventId,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
);

FUNC(Dem_ReturnGetSeverityOfDTCType, DEM_CODE) Dem_GetSeverityOfDTC(
    uint32 DTC,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus(
    uint8 IndicatorId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
);

FUNC(Dem_ReturnGetSizeOfExtendedDataRecordByDTCType, DEM_CODE) Dem_GetSizeOfExtendedDataRecordByDTC(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
);

FUNC(Dem_ReturnGetSizeOfFreezeFrameType, DEM_CODE) Dem_GetSizeOfFreezeFrame(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    uint8 RecordNumber,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
);

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredDTCAndFDC(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter
);

FUNC(Dem_ReturnGetStatusOfDTCType, DEM_CODE) Dem_GetStatusOfDTC(
    uint32 DTC,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);


FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredDTCAndSeverity(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
);

FUNC(uint8, DEM_CODE) Dem_GetTranslationType(void);

FUNC(Dem_ReturnGetNextFilteredDTCType, DEM_CODE) Dem_GetNextFilteredRecord(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) SnapshotRecord
);

FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE) Dem_SetDTCFilter(
    uint8 DTCStatusMask,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    Dem_FilterWithSeverityType FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    Dem_FilterForFDCType FilterForFaultDetectionCounter
);

FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE) Dem_GetNumberOfFilteredDTC(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
);

FUNC(Dem_ReturnSetDTCFilterType, DEM_CODE) Dem_SetDTCFilterForRecords(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords
);

#if 0
FUNC(void, DEM_CODE) Dem_GetRxSignalErrorStatus(Dem_FrRxSignalErrorStatusType Error Status,
    uint16 Dem_RxSignalSignalId, uint16 Dem_RxSignalPduId, uint16 Dem_RxSignalFrameId,
    uint16 Dem_RxSignalSlotId, uint8 Dem_RxSignalCycle, uint16 Dem_RxSignalChannel
);  // TODO: ÜBERPRÜFEN!!!
#endif

FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStatus(
    Dem_EventIdType EventId,
    P2VAR(Dem_EventStatusExtendedType, AUTOMATIC, DEM_APPL_DATA) EventStatusExtended
);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetInfoTypeValue08(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetInfoTypeValue0B(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID01(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID02(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID02value);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID1C(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1Cvalue);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID21(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value);


FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID30(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID30value);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID31(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID41(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID4D(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID4E(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue);

FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetPID5F(P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue);

FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock(Dem_RatioIdType RatioID);


FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease(Dem_RatioIdType RatioID);

FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect(Dem_RatioIdType RatioID);

FUNC(void, DEM_CODE) Dem_MainFunction(void);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled(Dem_EventIdType EventId);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetOBDFreezeFrameData(
    uint8 PID,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) BufSize
);

FUNC(void, DEM_CODE) Dem_ReportErrorStatus(Dem_EventIdType EventId, uint8 EventStatus);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleCounterValue(uint8 CounterValue);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleState(uint8 AgingCycleId);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleCntValue(uint8 OperationCycleId, uint8 CounterValue);

FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent(
    Dem_EventIdType EventId,
    Dem_DTCKindType DTCKind,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent
);

FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame(Dem_EventIdType EventId );

FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus(Dem_EventIdType EventId);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(Dem_EventIdType EventId, uint8 EventStatus);


FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition(uint8 EnableConditionID, boolean ConditionFulfilleds);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetOperationCycleState(uint8 OperationCycleId, uint8 CycleState);

FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus(boolean PtoStatus);


/*
** Global Function-like Macros.
*/
#if DEM_GET_VERSION_INFO_API == STD_ON
#define Dem_GetVersionInfo(vp) AR_GET_VERSION_INFO(DEM, vp)
#endif /* DEM_GET_VERSION_INFO_API */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */


#endif  /* __DEM_H */

