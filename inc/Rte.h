/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2014 by Christoph Schueler <chris@konnex-tools.de>
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
#if !defined(__RTE_H)
#define __RTE_H

#if defined(__cplusplus)
extern "C" {
#endif  /* __cplusplus */

#include "kdk/common/Std_Types.h"

#define RTE_E_OK                ((Std_ReturnType)0)
#define RTE_E_INVALID           ((Std_ReturnType)1)
#define RTE_E_COM_STOPPED       ((Std_ReturnType)128)
#define RTE_E_TIMEOUT           ((Std_ReturnType)129)
#define RTE_E_LIMIT             ((Std_ReturnType)130)
#define RTE_E_NO_DATA           ((Std_ReturnType)131)
#define RTE_E_TRANSMIT_ACK      ((Std_ReturnType)132)
#define RTE_E_LOST_DATA         ((Std_ReturnType)64)
#define RTE_E_MAX_AGE_EXCEEDED  ((Std_ReturnType)64)

#if defined(__cplusplus)
}       /* extern "C" */
#endif  /* __cplusplus */

#endif /* __RTE_H */

