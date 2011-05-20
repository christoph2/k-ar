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
#if !defined(__K_AR_H)
#define __K_AR_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "AR_ModuleIDs.h"

/*
**
**  REFERENCES:
**  ===========
**  [1] - General Requirements on Basic Software Modules V2.2.2 R3.1 Rev 0001.
**
*/

/*
**  Global Defines.
*/
#define AR_VENDOR_ID    4711

/*
**  The two basic processing schemes, needed for Code-Generation.
**
*/
#define INTERRUPT   1
#define POLLING     2


#define VERSIONINFO_AS_MACRO
#define VERSIONINFO_AS_FUNCTION

/*
**  Global Types.
*/
typedef enum tagBSW_State {
    BSW_UNINIT,
    BSW_READY
} BSW_State ;


/*
**  Global Macros.
*/
#define AR_DEV_ERROR_DETECT(mod)    GLUE2(mod,_DEV_ERROR_DETECT)

#define AR_IMPLEMENT_MODULE_STATE_VAR(mod) \
    static BSW_State mod ## _State=BSW_UNINIT   /* todo: 'P2VAR' !!!    */

#define AR_GET_MODULE_STATE_VAR(mod) \
    GLUE2(mod,_State)


#define AR_MODULE_INITIALIZE(mod)   \
    AR_GET_MODULE_STATE_VAR(mod)=BSW_READY

#define AR_MODULE_IS_INITIALIZED(mod)   \
    ((AR_GET_MODULE_STATE_VAR(mod)==BSW_READY) ? TRUE : FALSE)


#define AR_VERSION_INFO_FUNCTION_DECL(mod)                                      \
FUNC(void,GLUE2(mod,_CODE)) GLUE2(mod,_GetVersionInfo) (                        \
        P2VAR(Std_VersionInfoType,AUTOMATIC,GLUE2(mod,_APPL_DATA)) Versioninfo  \
            )

/*
**  Macros for Module-Version-Checking ([1] 4.1.6.8 [BASW004] Version check).
*/
#define AR_VERSION_CHECK_FAILS(mod,ma,mi) \
    (!((ma)==mod##_AR_MAJOR_VERSION && (mi)==mod##_AR_MINOR_VERSION))

#define AR_VERSION_CHECK_INTERNAL_FAILS(mod,arma,armi,arpa,ma,mi)                                               \
    (!((arma)==mod##_AR_MAJOR_VERSION && (armi)==mod##_AR_MINOR_VERSION && (arpa)==mod##_AR_PATCH_VERSION &&    \
    (ma)==mod##_SW_MAJOR_VERSION && (mi)==mod##_SW_MINOR_VERSION))


#define AR_VERSION_INFO_FUNCTION_IMPL(mod)                                      \
FUNC(void,GLUE2(mod,_CODE)) GLUE2(mod,_GetVersionInfo) (                        \
        P2VAR(Std_VersionInfoType,AUTOMATIC,GLUE2(mod,_APPL_DATA)) Versioninfo  \
)                                                                               \
{                                                                               \
    Versioninfo->vendorID=(uint16)GLUE2(mod,_VENDOR_ID);                        \
    Versioninfo->moduleID=(uint16)GLUE2(mod,_MODULE_ID);                        \
    Versioninfo->instanceID=(uint8)GLUE2(mod,_INSTANCE_ID);                     \
    Versioninfo->sw_major_version=(uint8)GLUE2(mod,_SW_MAJOR_VERSION);          \
    Versioninfo->sw_minor_version=(uint8)GLUE2(mod,_SW_MINOR_VERSION);          \
    Versioninfo->sw_patch_version=(uint8)GLUE2(mod,_SW_PATCH_VERSION);          \
}


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __K_AR_H */
