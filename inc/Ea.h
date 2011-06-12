/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
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
 */
#if !defined(__EA_H)
#define __EA_H

#include <Ea_Cfg.h>
#include <Eep.h>

typedef struct tagEa_ConfigType {
    unsigned filler; /* Hardware and/or implementation specific. */
} Ea_ConfigType;

void                Ea_Init(const Ea_ConfigType * ConfigPtr);
void                Ea_SetMode(MemIf_ModeType Mode);
Std_ReturnType      Ea_Read(uint16 BlockNumber, uint16 BlockOffset, uint8 * DataBufferPtr, uint16 Length);
Std_ReturnType      Ea_Write(uint16 BlockNumber, uint8 * DataBufferPtr);
void                Ea_Cancel(void);
MemIf_StatusType    Ea_GetStatus(void);
MemIf_JobResultType Ea_GetJobResult(void);
Std_ReturnType      Ea_InvalidateBlock(uint16 BlockNumber);
void                Ea_GetVersionInfo(Std_VersionInfotype * VersionInfoPtr);
Std_ReturnType      Ea_EraseImmediateBlock(uint16 BlockNumber);

#endif  /* __EA_H */
