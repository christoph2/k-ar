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
#if !defined(__CPU_PRIMITIVES_H)
#define __CPU_PRIMITIVES_H

#if defined(__CSMC__)               /* Cosmic               */
    #define CP_COMP             "cosmic/"
    #define CP_TARGET		"cpu12/cosmic/cpri.h"
#elif defined(__GNUC__)             /* GNU GCC              */

    #if defined(__arm__)
        #define CP_TARGET       "arm/gcc/cpri.h"
    #elif defined(__AVR__)
        #define CP_TARGET       "avr/gcc/cpri.h"
    #elif defined(MC6812)
        #define CP_TARGET       "cpu12/gcc/cpri.h"
    #elif defined(__MSP430__)
        #define CP_TARGET       "msp430/gcc/cpri.h"
    #elif defined( __CYGWIN32__) && defined(__I386__)
        /* Dummy-Target */
        #define CP_TARGET       "cygwin/gcc/cpri.h"
    #else
        #error Unsupported Target for GCC.
    #endif

#elif defined(__HIWARE__)           /* Metrowerks/Freescale */

    #if defined(__HC12__)
        #define CP_TARGET       "cpu12/codewarrior/cpri.h"
    #else
        #error Unsupported Target for Metrowerks.
    #endif

#elif defined(__IAR_SYSTEMS_ICC__)  /* IAR Systems          */

    #if defined(__ICCARM__)
        #define CP_TARGET       "arm/iar/cpri.h"
    #elif defined(__ICCHCS12__)
        #define CP_TARGET       "cpu12/iar/cpri.h"
    #else
        #error Unsupported Target for IAR-ICC.
    #endif

#elif defined(__IMAGECRAFT__)       /* Imagecraft           */
    #define CP_COMP             "imagecraft/"
#else                               /* todo: Add Support    */
    #error Unsupported Compiler.
#endif

#include    CP_TARGET
#undef      CP_TARGET

#endif /* __CPU_PRIMITIVES_H */

