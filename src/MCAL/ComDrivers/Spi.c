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
#include "Spi.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(SPI, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Spi.h' !
#endif

#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif

#include "Dem.h"
#if AR_VERSION_CHECK_FAILS(DEM, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Dem.h' !
#endif

#include "SchedM_Spi.h"
#if 0
#if AR_VERSION_CHECK_FAILS(SCHEDM_SPI, 3, 1)
    #error Version-Information-Mismatch of Include-File 'SchedM_Spi.h' !
#endif
#endif

#include "MCALTemplates/Mcal_Templates.h"

/* In terms of RDBMSs Sequences/Jobs/Channels should be the result of some normalisation. */
/*
   To decode a memory-bank consisting of eight ICs 74HC138 chips are often used,
   in this case just three port-pins are required.
 */

/*
   Sequences get superseded by higer prioritized ones
 */

/*
**  Local Functions.
*/
static FUNC(void, SPI_CODE) Spi_SetDriverState(Spi_HWUnitType HWUnit, Spi_StatusType State);
static FUNC(void, SPI_CODE) Spi_SetAllDriversState(Spi_StatusType State);
static FUNC(void, SPI_CODE) Spi_DoSyncJob(Spi_JobType Job);
static FUNC(void, SPI_CODE) Spi_DoSyncChannel(Spi_ChannelType Channel);

/*
   SPI_INTERRUPTIBLE_SEQ_ALLOWED
 */

/*
   SPI_CHANNEL_BUFFERS_ALLOWED
    0   - IB
    1   - EB
    2   - IB/EB
 */

/*
    LEVEL 0 - Simple Synchronous.
    LEVEL 1 - Basic Asynchronous.
    LEVEL 2 - Enhanced.
    LEVEL 2, Enhanced (Synchronous/Asynchronous) SPI Handler/Driver:
    the communication is based on asynchronous behavior or synchronous han-dling, using either
    interrupts or polling mechanism selectable during execution time and with a Priority policy
    to handle multiple accesses. Buffer usage is configurable as for other levels.
    "SPI108: The LEVEL 2 SPI Handler/Driver is specified for microcontrollers that have to provide,
    at least, two SPI busses using separated hardware units. Otherwise, us-ing this level of
    functionality does not make sense."
 */

/*
   Container Definition: SpiDriver
   -------------------------------
   SPI_MAX_CHANNEL - This parameter contains the number of Channels configured. It will be gathered by tools during the configuration stage.
   SPI_MAX_JOB - Total number of Jobs configured.
   SPI_MAX_SEQUENCE - Total number of Sequences configured.
   <SUB-CONTAINERS>
   <!-- Container Definition: SpiChannel -->
   -----------------------------------------
   SpiChannelId SPI_CHANNEL_NAME - SPI Channel ID, used as parameter in SPI API functions.
   SPI_CHANNEL_TYPE - Buffer usage with EB/IB channel.
   SPI_DATA_WIDTH -This parameter is the width of a transmitted data unit.
   SPI_DEFAULT_DATA - This parameter is the default value to transmit.
   SPI_EB_MAX_LENGTH - This parameter contains the maximum size of data buffers in case of EB Channels and only.
   SPI_HW_UNIT_SYNCHRONOUS - SPI bus dedicated for synchronous transfers.
   SPI_IB_N_BUFFERS - This parameter contains the maximum number of data buffers in case of IB Channels and only.
   SPI_TRANSFER_START - This parameter defines the first starting bit for transmission.
   <!-- Container Definition: SpiExternalDevice -->
   ------------------------------------------------
   SPI_BAUDRATE - This parameter is the communication baudrate - This parameter allows using a range of values, from the point of view of configuration tools,
   from Hz up to MHz.
   SPI_CS_IDENTIFIER - This parameter is the symbolic name to identify the Chip Select (CS) allocated to this Job.
   SPI_CS_POLARITY - This parameter defines the active polarity of Chip Select.
   SPI_DATA_SHIFT_EDGE - This parameter defines the SPI data shift edge.

 */

#define SPI_NUM_DRIVERS ((uint8)0x03)

/*
**  Local Variables.
*/
#define SPI_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

static Spi_StatusType Spi_DriverState[SPI_NUM_DRIVERS];

KAR_DEFINE_LOCAL_CONFIG_VAR(SPI, Spi);

#if AR_DEV_ERROR_DETECT(SPI) == STD_ON
AR_IMPLEMENT_MODULE_STATE_VAR(Spi);
#endif

#if (SPI_LEVEL_DELIVERED == 1) || (SPI_LEVEL_DELIVERED == 2)
static Spi_AsyncModeType Spi_AsyncMode = SPI_POLLING_MODE;
#endif

#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0) || (SPI_CHANNEL_BUFFERS_ALLOWED == 2)

#endif

#define SPI_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define SPI_START_SEC_CODE
#include "MemMap.h"

FUNC(void, SPI_CODE) Spi_SetDriverState(Spi_HWUnitType HWUnit, Spi_StatusType State)
{
    Spi_DriverState[HWUnit] = State;
}

FUNC(void, SPI_CODE) Spi_SetAllDriversState(Spi_StatusType State)
{
    Spi_HWUnitType hwunit;

    for (hwunit = 0; hwunit < SPI_NUM_DRIVERS; ++hwunit) {
        Spi_SetDriverState(hwunit, State);
    }
}

FUNC(void, SPI_CODE) Spi_Init(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_DATA) ConfigPtr)
{
#if SPI_DEV_ERROR_DETECT == STD_ON

    if (AR_MODULE_IS_INITIALIZED(Spi)) {
        AR_RAISE_DEV_ERROR(SPI, INIT, SPI_E_ALREADY_INITIALIZED);
        return;
    }

    if (ConfigPtr == NULL) {
        AR_RAISE_DEV_ERROR(SPI, INIT, SPI_E_PARAM_CONFIG);
        return;
    }

    AR_MODULE_INITIALIZE(Spi);
#endif /* SPI_DEV_ERROR_DETECT */
    AR_SAVE_CONFIG_PTR(Spi);

    /* Spi_ConfigPtr = ConfigPtr; */
    Spi_SetAllDriversState(SPI_IDLE);
    KAR_IMPLEMENT_SPI_INIT();

}

FUNC(Std_ReturnType, SPI_CODE) Spi_Uninit(void)
{
#if SPI_DEV_ERROR_DETECT == STD_ON
    if (!AR_MODULE_IS_INITIALIZED(Spi)) {
        AR_RAISE_DEV_ERROR(SPI, UNINIT, SPI_E_UNINIT);
        return E_NOT_OK;
    }

    AR_MODULE_UNINITIALIZE(Spi);
#endif /* SPI_DEV_ERROR_DETECT */

    Spi_SetAllDriversState(SPI_UNINIT);

    return E_OK;
}

FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB(Spi_ChannelType Channel, P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr)
{

}

#if (SPI_LEVEL_DELIVERED == 1) || (SPI_LEVEL_DELIVERED == 2)
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(Spi_SequenceType Sequence)
{

}
#endif

#if (SPI_LEVEL_DELIVERED == 0) || (SPI_LEVEL_DELIVERED == 2)
FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit(Spi_SequenceType Sequence)
{
    Spi_SequenceConfigType const * const    Ptr2Sequence = &Spi_Config->Sequences[Sequence];
    Spi_JobType                             Job;

    for (Job = (Spi_JobType)0; Job < Ptr2Sequence->NumberOfJobs; ++Job) {
        Spi_DoSyncJob(Ptr2Sequence->Jobs[Job]);
    }
}
#endif

FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB(Spi_ChannelType Channel, P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr)
{

}

FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
    Spi_NumberOfDataType Length
    )
{

}

FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void)
{

}

FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult(Spi_JobType Job)
{

}

FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult(Spi_SequenceType Sequence)
{

}

/* void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo); */

FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit)
{
    return Spi_DriverState[HWUnit];
}

FUNC(void, SPI_CODE) Spi_Cancel(Spi_SequenceType SequenceType)
{

}

#if (SPI_LEVEL_DELIVERED == 1) || (SPI_LEVEL_DELIVERED == 2)
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(Spi_AsyncModeType Mode)
{
    Spi_AsyncMode = Mode;
}
#endif

/*
**  Local functions, synchronous driver.
*/

/* BSW12099 Asynchronous Read Functionality (Read async a given length of bytes). */
/* BSW12101 Asynchronous Write Functionality (same as above). */
/* BSW12103 Asynchronous Read/Write Functionality. */

/* SPI028, SPI030 - Null pointers to generate dummy transmissions. */

#if (SPI_LEVEL_DELIVERED == 0) || (SPI_LEVEL_DELIVERED == 2)
FUNC(void, SPI_CODE) Spi_DoSyncJob(Spi_JobType Job)
{
    Spi_JobConfigType const * const Ptr2Job = &Spi_Config->Jobs[Job];
    Spi_ChannelType                 Channel;

    for (Channel = (Spi_ChannelType)0; Channel < Ptr2Job->NumberOfChannels; ++Channel) {
        Spi_DoSyncChannel(Ptr2Job->Channels[Channel]);
    }
}

FUNC(void, SPI_CODE) Spi_DoSyncChannel(Spi_ChannelType Channel)
{
    Spi_ChannelConfigType const * const Ptr2Channel = &Spi_Config->Channels[Channel];

}
#endif

#define SPI_STOP_SEC_CODE
#include "MemMap.h"
