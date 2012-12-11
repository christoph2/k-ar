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

/*
**  TODO: Notifications and trigger!
*/

#include "Adc.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(ADC, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Adc.h' !
#endif

#if ADC_DEV_ERROR_DETECT == STD_ON
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
#endif /* ADC_DEV_ERROR_DETECT */

#if 0
    #include "SchM_Adc.h"
    #if AR_VERSION_CHECK_INTERNAL_FAILS(ADC, 3, 1, 0, 1, 0)
        #error Version-Information-Mismatch of Include-File 'Adc.h' !
    #endif
#endif

#include "MCALTemplates/Mcal_Templates.h"

#define ADC_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

KAR_DEFINE_LOCAL_CONFIG_VAR(ADC, Adc);

#if AR_DEV_ERROR_DETECT(ADC) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(Adc);
#endif

VAR(Adc_StatusType, STATIC) Adc_GroupStatus[ADC_NUMBER_OF_GROUPS];

#define ADC_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define ADC_START_SEC_CODE
#include "MemMap.h"


#if 0
    Group_ResultBuffer[]    - stores the conversion results.
    Group_ResultPtr         - location where to store
    Group_SamplePtr         - used by 'Adc_GetStreamLastPointer'

    s. 7.1.3.3 (p. 29) for Adc_GetStreamLastPointer usage.
#endif


/*
**  Local Function Prototypes.
*/
STATIC void Adc_SetDefaultState(void);


/*
**  Global Functions.
*/

/* Initializes the ADC hardware units and driver. */
FUNC(void, ADC_CODE) Adc_Init(P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_DATA) ConfigPtr)
{
#if ADC_DEV_ERROR_DETECT == STD_ON

    /*!REQ: ADC343!*/
    if (ConfigPtr == NULL_PTR) {
        AR_RAISE_DEV_ERROR(ADC, INIT, ADC_E_PARAM_CONFIG);
        return;
    }

    /*!REQ: ADC107!*/
    if (AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, INIT, ADC_E_ALREADY_INITIALIZED);
        return;
    }

    AR_MODULE_INITIALIZE(Adc);
#endif
    AR_SAVE_CONFIG_PTR(Adc);

    Adc_SetDefaultState();
    /* Fullfills ...*/
    /*!REQ: ADC077 - the function ... shall disable the notifications and hardware trigger capability. */
    /*!REQ: ADC307!*/

    KAR_IMPLEMENT_ADC_INIT(ConfigPtr);
}


#if ADC_DEINIT_API == STD_ON
/* Returns all ADC HW Units to a state comparable to their power on reset state. */
FUNC(void, ADC_CODE) Adc_DeInit (void)
{
    VAR(uint8, AUTOMATIC) idx;
#if ADC_DEV_ERROR_DETECT == STD_ON

    /*!REQ: ADC154!*/
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, DEINIT, ADC_E_UNINIT);
        return;
    }
#endif /* ADC_DEV_ERROR_DETECT */


    /*!REQ: ADC112!*/
    for (idx = (uint8)0x00; idx < ADC_NUMBER_OF_GROUPS; ++idx) {
        if ((Adc_GroupStatus[idx] ==  ADC_IDLE) || (Adc_GroupStatus[idx] == ADC_STREAM_COMPLETED)) {
            #if ADC_DEV_ERROR_DETECT == STD_ON
            AR_RAISE_DEV_ERROR(ADC, DEINIT, ADC_E_BUSY);
            #endif /* ADC_DEV_ERROR_DETECT */
            return;
        }
    }

    #if ADC_DEV_ERROR_DETECT == STD_ON
    AR_MODULE_UNINITIALIZE(Adc);
    #endif /* ADC_DEV_ERROR_DETECT */

    Adc_SetDefaultState();
    /* Fullfills ...*/
    /*!REQ: ADC110! - ...to a state comparable to their power on reset state*/
    /*!REQ: ADC111! - disable all used notifications*/

    /*!REQ: ADC111! - disable all used interrupts*/
    KAR_IMPLEMENT_ADC_DEINIT();
}
#endif /* ADC_DEINIT_API */


#if ADC_ENABLE_START_STOP_GROUP_API == STD_ON
/* Starts the conversion of all channels of the requested ADC Channel group.  */
FUNC(void, ADC_CODE) Adc_StartGroupConversion(Adc_GroupType Group)
{
#if ADC_DEV_ERROR_DETECT == STD_ON

    /*!REQ: ADC294!*/
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, STARTGROUPCONVERSION, ADC_E_UNINIT);
        return;
    }
#endif
    KAR_IMPLEMENT_ADC_START_GROUP_CONVERSION(Group);
}


/* Stops the conversion of the requested ADC Channel group. */
FUNC(void, ADC_CODE) Adc_StopGroupConversion(Adc_GroupType Group)
{
#if ADC_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, STOPGROUPCONVERSION, ADC_E_UNINIT);
        return;
    }
#endif
    KAR_IMPLEMENT_ADC_STOP_GROUP_CONVERSION(Group);
}
#endif /* ADC_ENABLE_START_STOP_GROUP_API */


#if ADC_READ_GROUP_API == STD_ON
/* Reads the group conversion result of the  last completed conversion round of the */
/* requested group and stores the channel values starting at the DataBufferPtr address. */
/* The group channel values are stored in ascending channel number order ( in contrast */
/* to the storage layout of the result buffer if streaming access is configured). */
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup(Adc_GroupType Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr)
{
#if ADC_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, READGROUP, ADC_E_UNINIT);
        return E_NOT_OK;
    }
#endif

    return KAR_IMPLEMENT_ADC_READ_GROUP(Group, DataBufferPtr);
}
#endif /* ADC_READ_GROUP_API */


#if ADC_HW_TRIGGER_API == STD_ON
/* Enables the hardware trigger for the requested ADC Channel group. */
FUNC(void, ADC_CODE) Adc_EnableHardwareTrigger(Adc_GroupType Group)
{
#if ADC_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, ENABLEHARDWARETRIGGER, ADC_E_UNINIT);
        return;
    }
#endif
    KAR_IMPLEMENT_ADC_ENABLE_HARDWARE_TRIGGER(Group);
}


/* Disables the hardware trigger for the requested ADC Channel group. */
FUNC(void, ADC_CODE) Adc_DisableHardwareTrigger(Adc_GroupType Group)
{
#if ADC_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, DISABLEHARDWARETRIGGER, ADC_E_UNINIT);
        return;
    }
#endif
    KAR_IMPLEMENT_ADC_DISABLE_HARDWARE_TRIGGER(Group);
}
#endif /* ADC_HW_TRIGGER_API */


#if ADC_GRP_NOTIF_CAPABILITY == STD_ON
/* Enables the notification mechanism for the requested ADC Channel group. */
FUNC(void, ADC_CODE) Adc_EnableGroupNotification(Adc_GroupType Group)
{
#if ADC_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, ENABLEGROUPNOTIFICATION, ADC_E_UNINIT);
        return;
    }
#endif
    KAR_IMPLEMENT_ADC_ENABLE_GROUP_NOTIFICATION(Group);
}


/* Disables the notification mechanism for the requested ADC Channel group. */
FUNC(void, ADC_CODE) Adc_DisableGroupNotification(Adc_GroupType Group)
{
#if ADC_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, DISABLEGROUPNOTIFICATION, ADC_E_UNINIT);
        return;
    }
#endif
    KAR_IMPLEMENT_ADC_DISABLE_GROUP_NOTIFICATION(Group);
}
#endif /* ADC_GRP_NOTIF_CAPABILITY */


/* Returns the conversion status of the requested ADC Channel group. */
FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus(Adc_GroupType Group)
{
#if ADC_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, GETGROUPSTATUS, ADC_E_UNINIT);
        return E_NOT_OK;
    }
#endif
    return KAR_IMPLEMENT_ADC_GET_GROUP_STATUS(Group);
}


/* Returns the number of valid samples per channel, stored in the result buffer. */
/* Reads a pointer, pointing to a position in the group result buffer. With the */
/* pointer position, the  results of all group channels of the last completed */
/* conversion round can be accessed. */
/* With the pointer and the return value, all valid group conversion results can */
/* be accessed (the user has to take the layout of the result buffer into account). */
FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_GetStreamLastPointer(Adc_GroupType Group,
    P2VAR(Adc_ValueGroupType *, AUTOMATIC, ADC_APPL_DATA) PtrToSamplePtr)
{
#if ADC_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, GETSTREAMLASTPOINTER, ADC_E_UNINIT);
        return (Adc_StreamNumSampleType)0;
    }
#endif
    return KAR_IMPLEMENT_ADC_GET_STREAM_LAST_POINTER(Group, PtrToSamplePtr);
}


/* Initializes ADC driver with the group specific result buffer start address where */
/* the conversion results will be stored. The application has to ensure that the */
/* application  buffer, where DataBufferPtr points to, can hold all the conversion */
/* results of the specified group. The initialization with Adc_SetupResultBuffer is */
/* required after reset, before a group conversion can be started. */
FUNC(Std_ReturnType, ADC_CODE) Adc_SetupResultBuffer(Adc_GroupType Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr)
{
#if ADC_DEV_ERROR_DETECT == STD_ON
    /*!REQ: ADC434!*/
    if (!AR_MODULE_IS_INITIALIZED(Adc)) {
        AR_RAISE_DEV_ERROR(ADC, SETUPRESULTBUFFER, ADC_E_UNINIT);
        return E_NOT_OK;
    }

    /*!REQ: ADC423!*/
    if (Group >= ADC_NUMBER_OF_GROUPS) {
        AR_RAISE_DEV_ERROR(ADC, SETUPRESULTBUFFER, ADC_E_PARAM_GROUP);
        return E_NOT_OK;
    }

    /*!REQ: ADC433!*/
    if (Adc_GroupStatus[Group] != ADC_IDLE) {
        AR_RAISE_DEV_ERROR(ADC, SETUPRESULTBUFFER, ADC_E_BUSY);
        return E_NOT_OK;
    }

    /*!REQ: ADC457!*/
    if (DataBufferPtr == NULL_PTR) {
        AR_RAISE_DEV_ERROR(ADC, SETUPRESULTBUFFER, ADC_E_PARAM_POINTER);
        return E_NOT_OK;
    }
#endif

    return KAR_IMPLEMENT_ADC_SETUP_RESULT_BUFFER(Group, DataBufferPtr);
}


/*
**  Local Function Prototypes.
*/
STATIC void Adc_SetDefaultState(void)
{
    VAR(uint8, AUTOMATIC) idx;

    for (idx = (uint8)0; idx < ADC_NUMBER_OF_GROUPS; ++idx) {
        Adc_GroupStatus[idx] = ADC_IDLE;
    }

}


/*
**  Testing helper functions.
*/
#if defined(UNIT_TESTING)
////////////////////////
FUNC(Adc_StatusType, ADC_CODE) ADC_Ivis_GetGroupStatus(Adc_GroupType Group)
{
    return Adc_GroupStatus[Group];
}
#endif


#define ADC_STOP_SEC_CODE
#include "MemMap.h"

/*
    Desired Functionality       ADC Driver Function                         Example: C16x DerivateWording
    ====================================================================================================================
    Just one conversion of      Software triggered one-shot conversion      Fixed channel, single conversion,
    a single channel.           where the converted group consists of       software trigger.
                                exactly one channel.

    Cyclic conversion of a      Hardware triggered one-shot conversion      Fixed channel, single conversion,
    single channel.             where the converted group consists of       hardware trigger.
                                exactly one channel.

    Repeated conversion of      Continious conversion where the converted   Fixed channel, continious
    a single channel.           group consists of exactly one channel.      conversion.


    Just one conversion         Software triggered one-shot conversion      Auto scan, single conversion,
    result of each channel      where the converted group consists of       software trigger.
    within a group.             more than one channel.

    Cyclic conversion of        Hardware triggered one-shot conversion      Auto scan, single conversion,
    each channel within         where the converted group consists of       hardware trigger.
    a group.                    more than one channel.

    Repeated conversion of      Continious conversion where the converted   Auto scan, continious
    each channel within a       group consists of more than one channel.    conversion.
    group.
*/

