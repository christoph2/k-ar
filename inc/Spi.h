/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de>
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
 */
#if !defined(__SPI_H)
#define __SPI_H

#include "Std_Types.h"
#include "Spi_Cfg.h"

#define SPI_E_PARAM_                ((uint8)0x0a)
#define SPI_E_PARAM_JOB             ((uint8)0x0b)
#define SPI_E_PARAM_SEQ             ((uint8)0x0c)
#define SPI_E_PARAM_LENGTH          ((uint8)0x0d)
#define SPI_E_PARAM_UINT            ((uint8)0x0e)
#define SPI_E_UNINIT                ((uint8)0x1a)
#define SPI_E_SEQ_PENDING           ((uint8)0x2a)
#define SPI_E_SEQ_IN_PROCESS        ((uint8)0x3a)
#define SPI_E_ALREADY_INITIALIZED   ((uint8)0x4a)

typedef struct tagSpi_ConfigType {
    /* Implementation Specific */
    uint8 dummy;
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

typedef uint8 Spi_DataType;
typedef uint16 Spi_NumberOfDataType;
typedef uint8 Spi_ChannelType;
typedef uint8 Spi_JobType;
typedef uint8 Spi_SequenceType;
typedef uint8 Spi_HWUnitType;

typedef enum tagSpi_AsyncModeType {
    SPI_POLLING_MODE,
    SPI_INTERRUPT_MODE
} Spi_AsyncModeType;

void Spi_Init(const Spi_ConfigType *ConfigPtr);
Std_ReturnType Spi_Uninit(void);
Std_ReturnType Spi_WriteIB(Spi_ChannelType Channel,const Spi_DataType *DataBufferPtr);
Std_ReturnType Spi_AsyncTransmit(Spi_SequenceType Sequence);
Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel,Spi_DataType *DataBufferPtr);
Std_ReturnType Spi_SetupEB(Spi_ChannelType Channel,const Spi_DataType *SrcDataBufferPtr,
                           const Spi_DataType *DesDataBufferPtr,Spi_NumberOfDataType Length);
Spi_StatusType Spi_GetStatus(void);
Spi_JobResultType Spi_GetJobResult(Spi_JobType Job);
Spi_SeqResultType Spi_GetSequenceResult(Spi_SequenceType Sequence);
/* void Spi_GetVersionInfo(Std_VersionInfoType *versioninfo); */
Std_ReturnType Spi_SyncTransmit(Spi_SequenceType Sequence);
Spi_StatusType Spi_GetHWUnitStatus(Spi_HWUnitType HWUnit);
void Spi_Cancel(Spi_SequenceType SequenceType);
Std_ReturnType Spi_SetAsyncMode(Spi_AsyncModeType Mode);

void Spi_MainFunction_Handling(void);
void Spi_MainFunction_Driving(void);

#endif /* __SPI_H */

