/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
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
#if !defined(__CRC_H)
#define __CRC_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/* #include "Crc_Cfg.h" */
#include "K_Ar.h"
#include "kdk/common/Std_Types.h"

/*
**  Published Information.
*/
#define CRC_VENDOR_ID                   AR_VENDOR_ID
#define CRC_MODULE_ID                   AR_MODULE_ID_CRC
#define CRC_AR_MAJOR_VERSION            3
#define CRC_AR_MINOR_VERSION            1
#define CRC_AR_PATCH_VERSION            0
#define CRC_SW_MAJOR_VERSION            1
#define CRC_SW_MINOR_VERSION            0
#define CRC_SW_PATCH_VERSION            0
#define CRC_INSTANCE_ID                 0

#define CRC_INITIAL_VALUE8              ((uint8)0xff)
#define CRC_INITIAL_VALUE16             ((uint16)0xffffU)
#define CRC_INITIAL_VALUE32             ((uint16)0xffffffffUL)

/*
**  Service-IDs.
*/
#define AR_SERVICE_CRC_CALCULATE_CRC8   ((uint8)0x01)
#define AR_SERVICE_CRC_CALCULATE_CRC16  ((uint8)0x02)
#define AR_SERVICE_CRC_CALCULATE_CRC32  ((uint8)0x03)
#define AR_SERVICE_CRC_GETVERSIONINFO   ((uint8)0x04)

/*
**  Global Types.
*/


/*
**  Global Functions.
*/
FUNC(uint8, CRC_CODE) Crc_CalculateCRC8(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8
    );

FUNC(uint16, CRC_CODE) Crc_CalculateCRC16(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue16
    );

FUNC(uint32, CRC_CODE) Crc_CalculateCRC32(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue32
    );


/*
** Global Function-like Macros.
*/
#if CRC_GET_VERSION_INFO_API == STD_ON
#define Crc_GetVersionInfo(vp) AR_GET_VERSION_INFO(Crc, vp)
#endif /* CRC_GET_VERSION_INFO_API */


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __CRC_H */

