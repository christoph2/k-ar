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
#if !defined(__CAL_H)
#define __CAL_H

/*
**
** Calender-Functions.
**
*/

#include "Std_Types.h"

/*
**  Global Defines.
*/
#define CAL_JAN     ((uint8)1)
#define CAL_FEB     ((uint8)2)
#define CAL_MAR     ((uint8)3)
#define CAL_APR     ((uint8)4)
#define CAL_MAY     ((uint8)5)
#define CAL_JUN     ((uint8)6)
#define CAL_JUL     ((uint8)7)
#define CAL_AUG     ((uint8)8)
#define CAL_SEP     ((uint8)9)
#define CAL_OCT     ((uint8)10)
#define CAL_NOV     ((uint8)11)
#define CAL_DEC     ((uint8)12)
/*
**  Global Types.
*/

/*
**  Global Functions.
*/
boolean Cal_IsLeapYear(uint16 year);
uint8 Cal_DaysInMonth(uint16 year,uint8 month);
uint16 Cal_DaysBeforeMonth(uint16 year,uint8 month);

#endif /* __CAL_H */


