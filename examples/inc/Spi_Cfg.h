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
#if !defined __SPI_CFG_H
#define __SPI_CFG_H

#define SPI_GET_VERSION_INFO_API        STD_OFF
#define SPI_DEV_ERROR_DETECT            STD_ON

#define SPI_LEVEL_DELIVERED             0
#define SPI_CHANNEL_BUFFERS_ALLOWED     2
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED   STD_ON

#define EEP_CMD_CH                      ((Spi_ChannelType)0)
#define EEP_ADR_CH                      ((Spi_ChannelType)1)
#define EEP_DATA_CH                     ((Spi_ChannelType)2)

#define EEP_CMD_JOB                     ((Spi_JobType)0)
#define EEP_DATA_JOB                    ((Spi_JobType)1)

#define EEP_WRITE_SEQ                   ((Spi_SequenceType)0)
#define EEP_READ_SEQ                    ((Spi_SequenceType)1)

/* extern const Spi_ConfigType Spi_Config; */

void    EEP_vidEndOfStartWrJob(void);
void    EEP_vidEndOfWriteSeq(void);
void    EEP_vidEndOfReadSeq(void);


#endif /* __SPI_CFG_H */

