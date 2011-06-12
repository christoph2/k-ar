/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__DIO_H)
#define __DIO_H

#include "K_Ar.h"
#include "Std_Types.h"
#include "Mcal_Defines.h"
#include "Dio_Cfg.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Published Information.
*/
#define DIO_VENDOR_ID                       AR_VENDOR_ID
#define DIO_MODULE_ID                       AR_MODULE_ID_DIO
#define DIO_INSTANCE_ID                     0
#define DIO_AR_MAJOR_VERSION                3
#define DIO_AR_MINOR_VERSION                1
#define DIO_AR_PATCH_VERSION                0
#define DIO_SW_MAJOR_VERSION                1
#define DIO_SW_MINOR_VERSION                0
#define DIO_SW_PATCH_VERSION                0
#define DIO_VENDOR_API_INFIX

#define DIO_NUM_CHANNELS                    ((uint8)0x20)   /* todo: nach 'mcal_templates.h' !!! */

/*
**  Service-IDs.
*/
#define AR_SERVICE_DIO_READ_CHANNEL         ((uint8)0x00)
#define AR_SERVICE_DIO_WRITE_CHANNEL        ((uint8)0x01)
#define AR_SERVICE_DIO_READ_PORT            ((uint8)0x02)
#define AR_SERVICE_DIO_WRITE_PORT           ((uint8)0x03)
#define AR_SERVICE_DIO_READ_CHANNEL_GROUP   ((uint8)0x04)
#define AR_SERVICE_DIO_WRITE_CHANNEL_GROUP  ((uint8)0x05)
#define AR_SERVICE_DIO_GET_VERSION_INFO     ((uint8)0x12)

/*
**  Module-Errors.
*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID      ((uint8)10)
#define DIO_E_PARAM_INVALID_PORT_ID         ((uint8)20)
#define DIO_E_PARAM_INVALID_GROUP_ID        ((uint8)31)

#define DIO_DEV_ERROR_DETECT                STD_ON
#define DIO_VERSION_INFO_API                STD_ON

/*
**  Global Types.
*/
typedef uint8   Dio_ChannelType;
typedef uint8   Dio_PortType;

typedef struct tagDio_ChannelGroupType {
    uint8           offset;
    Dio_PortType    port;
    uint8           mask;
} Dio_ChannelGroupType;

typedef enum tagDio_LevelType {
    DIO_LOW,
    DIO_HIGH
} Dio_LevelType;

typedef uint8 Dio_PortLevelType;

typedef struct tagDio_PublicIfType {
    FUNC(void, DIO_CODE) (*Dio_GetVersionInfo)(P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) Versioninfo);
} Dio_PublicIfType;

/*
**  Global Functions.
*/
FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel(Dio_ChannelType ChannelId);
FUNC(void, DIO_CODE) Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort(Dio_PortType PortId);
FUNC(void, DIO_CODE) Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr);
FUNC(void, DIO_CODE) Dio_WriteChannelGroup(P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_DATA) ChannelGroupIdPtr,
                                           Dio_PortLevelType Level);

/*
** Global Function-like Macros.
*/
#if DIO_GET_VERSION_INFO_API == STD_ON
#define Dio_GetVersionInfo(vp) AR_GET_VERSION_INFO(DIO, (vp))
#endif /* DIO_GET_VERSION_INFO_API */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __DIO_H */
