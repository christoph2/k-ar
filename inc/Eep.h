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
#if !defined(__EEP_H)
#define	__EEP_H

#include "Std_Types.h"
#include "Eep_Cfg.h"
#include "EcuM.h"

#define EEP_E_PARAM_CONFIG  ((uint8)0x10)
#define EEP_E_PARAM_ADDRESS ((uint8)0x11)
#define EEP_E_PARAM_DATA    ((uint8)0x12)
#define EEP_E_PARAM_LENGTH  ((uint8)0x13)
#define EEP_E_UNINIT        ((uint8)0x20)
#define EEP_E_BUSY          ((uint8)0x21)
#if 0
#define EEP_E_COM_FAILURE       /* assigned externally */
#endif


#endif	/* __EEP_H */
