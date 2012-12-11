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
#if !defined(__ADC_H)
#define __ADC_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "K_Ar.h"
#include "Std_Types.h"
#include "MCALTemplates/Mcal_Defines.h"

#include "Adc_Cfg.h"


/*
**  Published Information.
*/
#define ADC_VENDOR_ID                           AR_VENDOR_ID
#define ADC_MODULE_ID                           AR_MODULE_ID_ADC
#define ADC_AR_MAJOR_VERSION                    3
#define ADC_AR_MINOR_VERSION                    1
#define ADC_AR_PATCH_VERSION                    0
#define ADC_SW_MAJOR_VERSION                    1
#define ADC_SW_MINOR_VERSION                    0
#define ADC_SW_PATCH_VERSION                    0
#define ADC_INSTANCE_ID                         0


/*
**  Service-IDs.
*/
#define AR_SERVICE_ADC_INIT                     ((uint8)0)
#define AR_SERVICE_ADC_DEINIT                   ((uint8)1)
#define AR_SERVICE_ADC_STARTGROUPCONVERSION     ((uint8)2)
#define AR_SERVICE_ADC_STOPGROUPCONVERSION      ((uint8)3)
#define AR_SERVICE_ADC_READGROUP                ((uint8)4)
#define AR_SERVICE_ADC_ENABLEHARDWARETRIGGER    ((uint8)5)
#define AR_SERVICE_ADC_DISABLEHARDWARETRIGGER   ((uint8)6)
#define AR_SERVICE_ADC_ENABLEGROUPNOTIFICATION  ((uint8)7)
#define AR_SERVICE_ADC_DISABLEGROUPNOTIFICATION ((uint8)8)
#define AR_SERVICE_ADC_GETGROUPSTATUS           ((uint8)9)
#define AR_SERVICE_ADC_GETVERSIONINFO           ((uint8)10)
#define AR_SERVICE_ADC_GETSTREAMLASTPOINTER     ((uint8)11)
#define AR_SERVICE_ADC_SETUPRESULTBUFFER        ((uint8)12)


/*
**  Module-Errors.
*/
#define ADC_E_UNINIT                            ((uint8)0x0a)
#define ADC_E_BUSY                              ((uint8)0x0b)
#define ADC_E_IDLE                              ((uint8)0x0c)
#define ADC_E_ALREADY_INITIALIZED               ((uint8)0x0d)
#define ADC_E_PARAM_CONFIG                      ((uint8)0x0e)
#define ADC_E_PARAM_POINTER                     ((uint8)0x14)
#define ADC_E_PARAM_GROUP                       ((uint8)0x15)
#define ADC_E_WRONG_CONV_MODE                   ((uint8)0x16)
#define ADC_E_WRONG_TRIGG_SRC                   ((uint8)0x17)
#define ADC_E_NOTIF_CAPABILITY                  ((uint8)0x18)
#define ADC_E_BUFFER_UNINIT                     ((uint8)0x19)


/*
**  Global Types.
*/
typedef uint8 Adc_ChannelType;

/* Type for reading the converted values of a channel group (raw, without further */
/* scaling, alignment according precompile switch ADC_RESULT_ALIGNMENT). */
typedef uint16 Adc_ValueGroupType;  /* TODO: configureable. */

/* Numeric ID of an ADC channel group. */
typedef uint8 Adc_GroupType;

/* Type of conversion time, i.e. the time during which  the sampled  */
/* analogue value is converted into digital representation. */
typedef uint8 Adc_ConversionTimeType;

/* Type for assignment of channels to a channel group. */
typedef uint8 Adc_GroupDefType;

/* Priority level of the channel. Lowest priority is 0. */
typedef uint8 Adc_GroupPriorityType;

/* Type for the reload value of the ADC module embedded timer (only if supported by the ADC hardware). */
typedef uint8 Adc_HwTriggerTimerType;

/* Type of clock prescaler factor. */
typedef uint8 Adc_PrescaleType;

/* Type of channel resolution in number of bits. */
typedef uint8 Adc_ResolutionType;

/* Type of sampling time, i.e. the time during which the value is sampled, (in clock-cycles). */
typedef uint8 Adc_SamplingTimeType;

/* Type for configuring the number of group conversions in streaming access mode */
/* (in single access mode, parameter is 1).  */
typedef uint8 Adc_StreamNumSampleType;


/* Data structure containing the set of configuration parameters required */
/* for initializing the ADC Driver and ADC HW Unit(s). */
typedef struct tagAdc_ConfigType {
    KAR_DEFINE_HARDWARE_SPECIFIC_CONFIG_PTR_MULT(Adc, 0);
    KAR_DEFINE_HARDWARE_SPECIFIC_CONFIG_PTR_MULT(Adc, 1);
    /* Implementation specific configuration data structure. */
} Adc_ConfigType;

/* In case of active limit checking: defines which conversion values are taken into account */
/* related to the boardes defineed with AdcChannelLowLimit and AdcChannelHighLimit. */
typedef enum tagAdc_ChannelRangeSelectType {
    ADC_RANGE_UNDER_LOW,        /* Range below low limit - low limit value included */
    ADC_RANGE_BETWEEN,          /* Range between low limit and high limit - high limit value included */
    ADC_RANGE_OVER_HIGH,        /* Range above high limit */
    ADC_RANGE_ALWAYS,           /* Complete range - independent from channel limit settings */
    ADC_RANGE_NOT_UNDER_LOW,    /* Range above low limit */
    ADC_RANGE_NOT_BETWEEN,      /* Range above high limit or below low limit - low limit value included */
    ADC_RANGE_NOT_OVER_HIGH     /* Range below high limit - high limit value included */
} Adc_ChannelRangeSelectType;

/* Type for configuring the access mode to group conversion results. */
typedef enum tagAdc_GroupAccessModeType {
    ADC_ACCESS_MODE_SINGLE,     /* Single value access mode. */
    ADC_ACCESS_MODE_STREAMING   /* Streaming access mode. */
} Adc_GroupAccessModeType;

/* Type for configuring the conversion mode of an ADC Channel group. */
typedef enum tagAdc_GroupConvModeType {
    /* Exactly one conversion of each channel in an ADC channel group is performed after */
    /* the configured trigger event. In case of ‘group trigger source software’, a started */
    /* One-Shot conversion can be stopped by a software API call. */
    /* In case of ‘group trigger source hardware’, a started One-Shot conversion can be */
    /* stopped by disabling the trigger event (if supported by hardware). */
    ADC_CONV_MODE_ONESHOT,
    /* Repeated conversions of each ADC channel in an ADC channel group are performed. */
    /* ‘Continuous conversion mode’ is only available for ‘group trigger source software’. */
    /*  A started ‘Continuous conversion’ can be stopped by a software API call. */
    ADC_CONV_MODE_CONTINUOUS
} Adc_GroupConvModeType;

/* Replacement mechanism, which is used on ADC group level, if a group conversion is */
/* interrupted by a group which has a higher priority. */
typedef enum tagAdc_GroupReplacementType {
    /* Abort/Restart mechanism is used on group level, if a group is interrupted by a higher */
    /* priority group. The complete conversion round of the interrupted group (all group */
    /* channels)is restarted after the higher priority group conversion is finished. If the */
    /* group is configured in streaming access mode, only the results of the interrupted */
    /* conversion round are discarded. Results of previous conversion rounds which are already */
    /* written to the result buffer are not affected. */
    ADC_GROUP_REPL_ABORT_RESTART,
    /* Suspend/Resume mechanism is used on group level, if a group is interrupted by a higher */
    /* priority group. The conversion round of the interrupted group is completed after the higher */
    /* priority group conversion is finished. Results of previous conversion rounds which are */
    /* already written to the result buffer are not affected. */
    ADC_GROUP_REPL_SUSPEND_RESUME
} Adc_GroupReplacementType;

/* Type for configuring on which edge of the hardware trigger signal the driver should react, */
/* i.e. start the conversion (only if supported by the ADC hardware). */
typedef enum tagAdc_HwTriggerSignalType {
    /* React on the rising edge of the hardware trigger signal (only if supported by the ADC hardware). */
    ADC_HW_TRIG_RISING_EDGE,
    /* React on the falling edge of the hardware trigger signal (only if supported by the ADC hardware). */
    ADC_HW_TRIG_FALLING_EDGE,
    /* React on both edges of the hardware trigger signal (only if supported by the ADC hardware). */
    ADC_HW_TRIG_BOTH_EDGES
} Adc_HwTriggerSignalType;

/* Type for configuring the prioritization mechanism.  */
typedef enum tagAdc_PriorityImplementationType {
    ADC_PRIORITY_NONE,  /* priority mechanism is not available */
    ADC_PRIORITY_HW,    /* Hardware priority mechanism is available only */
    ADC_PRIORITY_HW_SW  /* Hardware and software priority mechanism is available */
} Adc_PriorityImplementationType;

/* Current status of the conversion of the requested ADC Channel group. */
typedef enum tagAdc_StatusType {
    /*  - The conversion of the specified group has not been started.
        - No result is available.
     */
    ADC_IDLE,
    /*  - The conversion of the specified group has been started and is still going on.
        - So far no result is available.
     */
    ADC_BUSY,
    /*  - A conversion round (which is not the final one) of the specified group has been finished.
        - A result is available for all channels of the group.
     */
    ADC_COMPLETED,
    /*  - The result buffer is completely filled
        - For each channel of the selected group the number of samples to be acquired is available
     */
    ADC_STREAM_COMPLETED
} Adc_StatusType;

/* Type for configuring the streaming access mode buffer type. */
typedef enum tagAdc_StreamBufferModeType {
    /* The ADC Driver stops the conversion as soon as the stream buffer */
    /* is full (number of samples reached). */
    ADC_STREAM_BUFFER_LINEAR,
    /* The ADC Driver continues the conversion even if the stream buffer is full */
    /* (number of samples reached) by wrapping around the stream buffer itself. */
    ADC_STREAM_BUFFER_CIRCULAR
} Adc_StreamBufferModeType;

/* Type for configuring the trigger source for an ADC Channel group. */
typedef enum tagAdc_TriggerSourceType {
    ADC_TRIGG_SRC_SW,   /* Group is triggered by a software API call. */
    ADC_TRIGG_SRC_HW    /* Group is triggered by a hardware event. */
} Adc_TriggerSourceType;

/* Alignment for storing ADC raw results in ADC result buffers. */
typedef enum tagAdc_ResultAlignmentType {
    ADC_RESULT_ALIGN_LEFT,  /* left alignment */
    ADC_RESULT_ALIGN_RIGHT  /* right alignment */
} Adc_ResultAlignmentType;


/*
**  Global Functions.
*/

/* Initializes the ADC hardware units and driver. */
FUNC(void,ADC_CODE) Adc_Init(P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_DATA) ConfigPtr);

/* Returns all ADC HW Units to a state comparable to their power on reset state. */
FUNC(void,ADC_CODE) Adc_DeInit (void);

/* Starts the conversion of all channels of the requested ADC Channel group.  */
FUNC(void,ADC_CODE) Adc_StartGroupConversion(Adc_GroupType Group);

/* Stops the conversion of the requested ADC Channel group. */
FUNC(void,ADC_CODE) Adc_StopGroupConversion(Adc_GroupType Group);

/* Reads the group conversion result of the  last completed conversion round of the */
/* requested group and stores the channel values starting at the DataBufferPtr address. */
/* The group channel values are stored in ascending channel number order ( in contrast */
/* to the storage layout of the result buffer if streaming access is configured). */
FUNC(Std_ReturnType,ADC_CODE) Adc_ReadGroup(Adc_GroupType Group, P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr);

/* Enables the hardware trigger for the requested ADC Channel group. */
FUNC(void,ADC_CODE) Adc_EnableHardwareTrigger(Adc_GroupType Group);

/* Disables the hardware trigger for the requested ADC Channel group. */
FUNC(void,ADC_CODE) Adc_DisableHardwareTrigger(Adc_GroupType Group);

/* Enables the notification mechanism for the requested ADC Channel group. */
FUNC(void,ADC_CODE) Adc_EnableGroupNotification(Adc_GroupType Group);

/* Disables the notification mechanism for the requested ADC Channel group. */
FUNC(void,ADC_CODE) Adc_DisableGroupNotification(Adc_GroupType Group);

/* Returns the conversion status of the requested ADC Channel group. */
FUNC(Adc_StatusType,ADC_CODE) Adc_GetGroupStatus(Adc_GroupType Group);

/* Returns the number of valid samples per channel, stored in the result buffer. */
/* Reads a pointer, pointing to a position in the group result buffer. With the */
/* pointer position, the  results of all group channels of the last completed */
/* conversion round can be accessed. */
/* With the pointer and the return value, all valid group conversion results can */
/* be accessed (the user has to take the layout of the result buffer into account). */
FUNC(Adc_StreamNumSampleType,ADC_CODE) Adc_GetStreamLastPointer(Adc_GroupType Group,
    P2VAR(Adc_ValueGroupType *, AUTOMATIC, ADC_APPL_DATA) PtrToSamplePtr);
/* Initializes ADC driver with the group specific result buffer start address where */
/* the conversion results will be stored. The application has to ensure that the */
/* application  buffer, where DataBufferPtr points to, can hold all the conversion */
/* results of the specified group. The initialization with Adc_SetupResultBuffer is */
/* required after reset, before a group conversion can be started. */
FUNC(Std_ReturnType,ADC_CODE) Adc_SetupResultBuffer(Adc_GroupType Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr);


/*
**  Testing helper functions.
*/
#if UNIT_TESTING
FUNC(Adc_StatusType, ADC_CODE) ADC_Ivis_GetGroupStatus(Adc_GroupType Group);
#endif /* UNIT_TESTING */

/*
**  Global Function-like Macros.
*/
#if ADC_VERSION_INFO_API == STD_ON
#define Adc_GetVersionInfo(vp) AR_GET_VERSION_INFO(ADC, vp)
#endif /* ADC_VERSION_INFO_API */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __ADC_H */

