/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de>
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
#if !defined(__DIO__CFG_H)
#define __DIO_CFG_H

#include "Dio.h"
#define DioVersionInfoApi

#define DiDevErrorDetect    /* Detection of Development Errors. */

#if 0
/*
**  Examples
*/

/* DIO Channels */
#define MOTOR_START_STOP    (DIO_CHANNEL_A_5)
#define	MOTOR_DIRECTION	    (DIO_CHANNEL_A_6)

/* DIO Ports */
#define MOTOR_CTL_PORT	    (DIO_PORT_A)
#define MUX_SEL_PORT	    (DIO_PORT_B)

/* DIO Channel Group */
#define MOTOR_CTL_GRP_PTR   (&DioConfigData[0])
#define MUX_SEL_GRP_PTR	    (&DioConfigData[1])

/* Instatiation of DIO configuration data */
/* (the filename should be 'Dio_Lcfg.c'.) */
const Dio_ChannelGroupType DioConfigData[2]={
    {
	.port=MOTOR_CTL_PORT,
	.offset=5
	.mask=0x60,
    },
    {
	.port=MUX_SEL_PORT,
	.offset=1,
	.mask=0x1e,
    }
};
#endif

#endif /* __DIO_CFG_H */

