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

#if !defined(__KDK_CPUS_H)
#define __KDK_CPUS_H

/*
**  Supported CPU-Families.
*/
#define CPU12_HC12          1
#define CPU12_S12           2
#define CPU12_S12X          3

/*
**  HC12-Family-Members.
*/
#define CPU12_HC12B32       1
#define CPU12_HC12BC32      2
#define CPU12_HC12DG128A    3
#define CPU12_HC12DT128A    4

/*
**  S12-Family-Members.
*/
#define CPU12_S12DP256B     1

#endif /* __KDK_CPUS_H */
