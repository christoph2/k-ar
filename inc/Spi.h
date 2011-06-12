/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__SPI_H)
#define __SPI_H

#include "K_Ar.h"
#include "Std_Types.h"
#include "Mcal_Defines.h"

#include "Dio.h"   /* needed for Chipselect functionality. */
#if 0
#if AR_VERSION_CHECK_INTERNAL_FAILS(PORT, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Dio.h' !
#endif
#endif

/*
**  Published Information.
*/
#define SPI_VENDOR_ID                           AR_VENDOR_ID
#define SPI_MODULE_ID                           AR_MODULE_ID_SPI
#define SPI_INSTANCE_ID                         0
#define SPI_AR_MAJOR_VERSION                    3
#define SPI_AR_MINOR_VERSION                    1
#define SPI_AR_PATCH_VERSION                    0
#define SPI_SW_MAJOR_VERSION                    1
#define SPI_SW_MINOR_VERSION                    0
#define SPI_SW_PATCH_VERSION                    0
#define SPI_VENDOR_API_INFIX

/*
**  Service-IDs.
*/
#define AR_SERVICE_SPI_INIT                     ((uint8)0)
#define AR_SERVICE_SPI_DEINIT                   ((uint8)1)
#define AR_SERVICE_SPI_SYNCTRANSMIT             ((uint8)10)
#define AR_SERVICE_SPI_GETHWUNITSTATUS          ((uint8)11)
#define AR_SERVICE_SPI_CANCEL                   ((uint8)12)
#define AR_SERVICE_SPI_SETASYNCMODE             ((uint8)13)
#define AR_SERVICE_SPI_MAINFUNCTION_HANDLING    ((uint8)16)
#define AR_SERVICE_SPI_MAINFUNCTION_DRIVING     ((uint8)17)
#define AR_SERVICE_SPI_WRITEIB                  ((uint8)2)
#define AR_SERVICE_SPI_ASYNCTRANSMIT            ((uint8)3)
#define AR_SERVICE_SPI_READIB                   ((uint8)4)
#define AR_SERVICE_SPI_SETUPEB                  ((uint8)5)
#define AR_SERVICE_SPI_GETSTATUS                ((uint8)6)
#define AR_SERVICE_SPI_GETJOBRESULT             ((uint8)7)
#define AR_SERVICE_SPI_GETSEQUENCERESULT        ((uint8)8)
#define AR_SERVICE_SPI_GETVERSIONINFO           ((uint8)9)

/*
**  Module Errors.
*/
#define SPI_E_PARAM_                            ((uint8)0x0a)
#define SPI_E_PARAM_JOB                         ((uint8)0x0b)
#define SPI_E_PARAM_SEQ                         ((uint8)0x0c)
#define SPI_E_PARAM_LENGTH                      ((uint8)0x0d)
#define SPI_E_PARAM_UINT                        ((uint8)0x0e)
#define SPI_E_UNINIT                            ((uint8)0x1a)
#define SPI_E_SEQ_PENDING                       ((uint8)0x2a)
#define SPI_E_SEQ_IN_PROCESS                    ((uint8)0x3a)
#define SPI_E_ALREADY_INITIALIZED               ((uint8)0x4a)

typedef uint8   Spi_DataType;
typedef uint16  Spi_NumberOfDataType;
typedef uint8   Spi_ChannelType;
typedef uint8   Spi_JobType;
typedef uint8   Spi_SequenceType;
typedef uint8   Spi_HWUnitType;

/*
**  Proprietary Types.
*/
typedef enum tagSpi_BufferUsageType {
    SPI_IB,
    SPI_EB
} Spi_BufferUsageType;

typedef enum tagSpi_ByteOrderType {
    SPI_LSB_FIRST,
    SPI_MSB_FIRST
} Spi_ByteOrderType;

typedef enum tagSpi_ChipSelectPolarityType {
    SPI_CS_POLARITY_LOW,
    SPI_CS_POLARITY_HIGH
} Spi_ChipSelectPolarityType;

typedef enum tagSpi_ClockIdleType {
    SPI_CLOCK_IDLE_LOW,
    SPI_CLOCK_IDLE_HIGH
} Spi_ClockIdleType;

typedef enum tagSpi_ClockPhaseType {
    SPI_CLOCK_PHASE_0,
    SPI_CLOCK_PHASE_180
} Spi_ClockPhaseType;

typedef enum tagSpi_InterruptableType {
    SPI_INTERRUPTABLE,
    SPI_NOT_INTERRUPTABLE
} Spi_InterruptableType;

typedef struct tagSpi_ChannelConfigType {
    Spi_BufferUsageType BufferUsage;
    uint8               TransmitDataWidth;
    uint8               NumberOfDataToTx;
    Spi_ByteOrderType   ByteOrder;
    uint32              DefaultValue;
} Spi_ChannelConfigType;

typedef struct tagSpi_JobConfigType {
    Spi_HWUnitType  AssignedHWUnit;
    Dio_ChannelType AssignedChipSelectPin;
    boolean         CsOn;
    /* boolean CsHw; */
    Spi_ChipSelectPolarityType  CsPolarity;
    uint32                      BaudRate;
    uint16                      CsToClk;
    Spi_ClockIdleType           ClockIdle;
    Spi_ClockPhaseType          ClockPhase;
    uint8                       Priority;
    void (* JobFinishedNotification)(void);
    uint8                           NumberOfChannels;
    Spi_ChannelType const * const   Channels;
} Spi_JobConfigType;

typedef struct tagSpi_SequenceConfigType {
    uint8                       NumberOfJobs;
    Spi_JobType const * const   Jobs;
    Spi_InterruptableType       Interruptable;
    void (* SequenceFinishedNotification)(void);
} Spi_SequenceConfigType;

/*
**  Global Types.
*/
typedef struct tagSpi_ConfigType {
    /* Implementation Specific */
    S12Spi_ConfigType const * const Cfg;

    Spi_SequenceConfigType const * const    Sequences;
    Spi_JobConfigType const * const         Jobs;
    Spi_ChannelConfigType const * const     Channels;
} Spi_ConfigType;

typedef enum tagSpi_StatusType {
    SPI_UNINIT,
    SPI_IDLE,
    SPI_BUSY
} Spi_StatusType;

typedef enum tagSpi_JobResultType {
    SPI_JOB_OK,
    SPI_JOB_PENDING,
    SPI_JOB_FAILED
} Spi_JobResultType;

typedef enum tagSpi_SeqResultType {
    SPI_SEQ_OK,
    SPI_SEQ_PENDING,
    SPI_SEQ_FAILED,
    SPI_SEQ_CANCELLED
} Spi_SeqResultType;

typedef enum tagSpi_AsyncModeType {
    SPI_POLLING_MODE,
    SPI_INTERRUPT_MODE
} Spi_AsyncModeType;

/*
**  Global Functions.
*/
FUNC(void, SPI_CODE) Spi_Init(P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_DATA) ConfigPtr);
FUNC(Std_ReturnType, SPI_CODE) Spi_Uninit(void);
FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB(Spi_ChannelType Channel, P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr);
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit(Spi_SequenceType Sequence);
FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB(Spi_ChannelType Channel, P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DataBufferPtr);
FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB(
    Spi_ChannelType Channel,
    P2CONST(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) SrcDataBufferPtr,
    P2VAR(Spi_DataType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
    Spi_NumberOfDataType Length
    );
FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void);
FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult(Spi_JobType Job);
FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult(Spi_SequenceType Sequence);

/* void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo); */

FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit(Spi_SequenceType Sequence);
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit);
FUNC(void, SPI_CODE) Spi_Cancel(Spi_SequenceType SequenceType);
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode(Spi_AsyncModeType Mode);

FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void);
FUNC(void, SPI_CODE) Spi_MainFunction_Driving(void);

#include "Spi_Cfg.h"

#endif /* __SPI_H */
