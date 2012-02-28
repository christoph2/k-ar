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

#include "Can_Irq.h"

/*
**
** Interrupt-Handler.
**
*/

/*
**  CAN-Controller #0
*/
ISR1(CAN0TxVector)
{
    Can_HandleIrqTx(CAN0);
}

ISR1(CAN0RxVector)
{
    Can_HandleIrqRx(CAN0);
}

ISR1(CAN0ErrorVector)
{
    Can_HandleIrqErr(CAN0);
}

ISR1(CAN0WakupVector)
{
    Can_HandleIrqWup(CAN0);
}

/*
**  CAN-Controller #1
*/
ISR1(CAN1TxVector)
{
    Can_HandleIrqTx(CAN1);
}

ISR1(CAN1RxVector)
{
    Can_HandleIrqRx(CAN1);
}

ISR1(CAN1ErrorVector)
{
    Can_HandleIrqErr(CAN1);
}

ISR1(CAN1WakupVector)
{
    Can_HandleIrqWup(CAN1);
}

/*
**  CAN-Controller #2
*/
ISR1(CAN2TxVector)
{
    Can_HandleIrqTx(CAN2);
}

ISR1(CAN2RxVector)
{
    Can_HandleIrqRx(CAN2);
}

ISR1(CAN2ErrorVector)
{
    Can_HandleIrqErr(CAN2);
}

ISR1(CAN2WakupVector)
{
    Can_HandleIrqWup(CAN2);
}

/*
**  CAN-Controller #3
*/
ISR1(CAN3TxVector)
{
    Can_HandleIrqTx(CAN3);
}

ISR1(CAN3RxVector)
{
    Can_HandleIrqRx(CAN3);
}

ISR1(CAN3ErrorVector)
{
    Can_HandleIrqErr(CAN3);
}

ISR1(CAN3WakupVector)
{
    Can_HandleIrqWup(CAN3);
}

/*
**  CAN-Controller #4
*/
ISR1(CAN4TxVector)
{
    Can_HandleIrqTx(CAN4);
}

ISR1(CAN4RxVector)
{
    Can_HandleIrqRx(CAN4);
}

ISR1(CAN4ErrorVector)
{
    Can_HandleIrqErr(CAN4);
}

ISR1(CAN4WakupVector)
{
    Can_HandleIrqWup(CAN4);
}
