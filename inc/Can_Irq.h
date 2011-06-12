/*
   k_os (Konnex Operating-System based on the OSEK/VDX-Standard).

   (C) 2007-2010 by Christoph Schueler <chris@konnex-tools.de,
                                       cpu12.gems@googlemail.com>

   All Rights Reserved

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   s. FLOSS-EXCEPTION.txt
 */
#if !defined(__CAN_IRQ_H)
#define __CAN_IRQ_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "S12_Can.h"
#include "Hw_Cfg.h"
#include "InstallISR/ISR.h"

#if 0
/*
**  Declaration of ISRs.
*/
DECLARE_ISR1_VECTOR(CAN0TxVector);
DECLARE_ISR1_VECTOR(CAN0RxVector);
DECLARE_ISR1_VECTOR(CAN0ErrorVector);
DECLARE_ISR1_VECTOR(CAN0WakupVector);

DECLARE_ISR1_VECTOR(CAN1TxVector);
DECLARE_ISR1_VECTOR(CAN1RxVector);
DECLARE_ISR1_VECTOR(CAN1ErrorVector);
DECLARE_ISR1_VECTOR(CAN1WakupVector);

DECLARE_ISR1_VECTOR(CAN2TxVector);
DECLARE_ISR1_VECTOR(CAN2RxVector);
DECLARE_ISR1_VECTOR(CAN2ErrorVector);
DECLARE_ISR1_VECTOR(CAN2WakupVector);

DECLARE_ISR1_VECTOR(CAN3TxVector);
DECLARE_ISR1_VECTOR(CAN3RxVector);
DECLARE_ISR1_VECTOR(CAN3ErrorVector);
DECLARE_ISR1_VECTOR(CAN3WakupVector);

DECLARE_ISR1_VECTOR(CAN4TxVector);
DECLARE_ISR1_VECTOR(CAN4RxVector);
DECLARE_ISR1_VECTOR(CAN4ErrorVector);
DECLARE_ISR1_VECTOR(CAN4WakupVector);

#endif

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __CAN_IRQ_H */
