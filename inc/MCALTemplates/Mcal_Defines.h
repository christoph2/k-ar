/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2014 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__MCAL_DEFINES_H)
#define __MCAL_DEFINES_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#if defined(KAR_DUMMY_TARGET)
/* dummy target */
    #include "MCALTemplates/dummy/Mcal_Defines_dummy.h"
#else
    #if CPU_FAMILY == CPU12_HC12
/* hc12 */
        #include "MCALTemplates/hc12/MCAL_Defines_hc12.h"
    #elif CPU_FAMILY == CPU12_S12
/** s12 */
        #include "MCALTemplates/s12/MCAL_Defines_s12.h"
    #elif CPU_FAMILY == CPU12_S12X
        #error CPU12X not supported yet!
    #elif CPU_FAMILY == COLDFIRE
        #include "MCALTemplates/mcf5255/MCAL_Defines_mcf5255.h"
    #endif
#endif


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __MCAL_DEFINES_H */

