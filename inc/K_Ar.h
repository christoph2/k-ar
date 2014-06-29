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
#if !defined(__K_AR_H)
#define __K_AR_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "AR_ModuleIDs.h"
#include "kdk/common/Std_Macros.h"

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

#define __K_AUTOSAR
/*
**  The two basic processing schemes, needed for Code-Generation.
**
*/
#define INTERRUPT       1
#define POLLING         2

#define VERSIONINFO_AS_MACRO
#define VERSIONINFO_AS_FUNCTION

/*
**  Global Types.
*/
typedef enum tagBSW_State {
    BSW_UNINIT,
    BSW_READY
} BSW_State;

/*
**  Global Macros.
*/
#define AR_DEV_ERROR_DETECT(module) GLUE2(module, _DEV_ERROR_DETECT)

#define AR_RAISE_DEV_ERROR(module, api, error) \
    Det_ReportError(module ## _MODULE_ID, module ## _INSTANCE_ID, AR_SERVICE_ ## module ## _ ## api, error)

#define AR_IMPLEMENT_MODULE_STATE_VAR(module) \
    static BSW_State module ## _State = BSW_UNINIT   /* todo: 'P2VAR' !!!    */

#define AR_GET_MODULE_STATE_VAR(module) \
    GLUE2(module, _State)

#define AR_MODULE_INITIALIZE(module) \
    AR_GET_MODULE_STATE_VAR(module) = BSW_READY

#define AR_MODULE_UNINITIALIZE(module) \
    AR_GET_MODULE_STATE_VAR(module) = BSW_UNINIT

#define AR_MODULE_IS_INITIALIZED(module) \
    ((AR_GET_MODULE_STATE_VAR(module) == BSW_READY) ? TRUE : FALSE)

#define AR_ASSERT_MODULE_IS_INITIALIZED(ml, mu, fkt)  \
    _BEGIN_BLOCK                                      \
    if (!AR_MODULE_IS_INITIALIZED(ml)) {              \
        AR_RAISE_DEV_ERROR(mu, fkt, mu ## _E_UNINIT); \
        return;                                       \
    }                                                 \
    _END_BLOCK

#define AR_ASSERT_MODULE_IS_INITIALIZED_RETURN(ml, mu, fkt, value) \
    _BEGIN_BLOCK                                                   \
    if (!AR_MODULE_IS_INITIALIZED(ml)) {                           \
        AR_RAISE_DEV_ERROR(mu, fkt, mu ## _E_UNINIT);              \
        return value;                                              \
    }                                                              \
    _END_BLOCK

#define KAR_DEFINE_LOCAL_CONFIG_VAR(u, l)   P2CONST(l ## _ConfigType, STATIC, u ## _VAR)  l ## _Config

#define AR_SAVE_CONFIG_PTR(module)             module ## _Config = ConfigPtr
#define AR_GET_CONFIG_PTR(module)              module ## _Config

#define AR_VERSION_INFO_FUNCTION_DECL(module)                                           \
    FUNC(void, GLUE2(module, _CODE)) GLUE2(module, _GetVersionInfo) (                   \
        P2VAR(Std_VersionInfoType, AUTOMATIC, GLUE2(module, _APPL_DATA)) Versioninfo    \
        )

#define AR_GET_VERSION_INFO(module, vp)                     \
    _BEGIN_BLOCK                                            \
    (vp)->vendorID     = module ## _VENDOR_ID;              \
    (vp)->moduleID         = module ## _MODULE_ID;          \
    (vp)->instanceID       = module ## _INSTANCE_ID;        \
    (vp)->sw_major_version = module ## _SW_MAJOR_VERSION;   \
    (vp)->sw_minor_version = module ## _SW_MINOR_VERSION;   \
    (vp)->sw_patch_version = module ## _SW_PATCH_VERSION;   \
    _END_BLOCK


/*
**  Macros for Module-Version-Checking ([1] 4.1.6.8 [BSW004] Version check).
*/

#if 0
#define AR_VERSION_CHECK_FAILS(module, ma, mi) \
    (!((ma) == module ## _AR_MAJOR_VERSION && (mi) == module ## _AR_MINOR_VERSION))
#endif

#define AR_VERSION_CHECK_FAILS(module, ma, mi) \
    (!((ma) == GLUE2(module, _AR_MAJOR_VERSION) && (mi) == GLUE2(module, _AR_MINOR_VERSION)))


#define AR_VERSION_CHECK_INTERNAL_FAILS(module, arma, armi, arpa, ma, mi)           \
    (!(                                                                             \
       ((arma) == (module ## _AR_MAJOR_VERSION)) &&                                 \
       ((armi) == (module ## _AR_MINOR_VERSION)) &&                                 \
       ((arpa) == (module ## _AR_PATCH_VERSION)) &&                                 \
       ((ma) ==   (module ## _SW_MAJOR_VERSION)) &&                                 \
       ((mi) ==   (module ## _SW_MINOR_VERSION))                                    \
    ))

#if 0
#define AR_VERSION_CHECK_INTERNAL_FAILS(module, arma, armi, arpa, ma, mi)       \
    (!(                                                                         \
       ((arma) == (GLUE2(module, _AR_MAJOR_VERSION))) &&                        \
       ((armi) == (GLUE2(module, _AR_MINOR_VERSION))) &&                        \
       ((arpa) == (GLUE2(module, _AR_PATCH_VERSION))) &&                        \
       ((ma) ==   (GLUE2(module, _SW_MAJOR_VERSION))) &&                        \
       ((mi) ==   (GLUE2(module, _SW_MINOR_VERSION)))                           \
    ))
#endif

#define AR_VERSION_INFO_FUNCTION_IMPL(module)                                           \
    FUNC(void, GLUE2(module, _CODE)) GLUE2(module, _GetVersionInfo) (                   \
        P2VAR(Std_VersionInfoType, AUTOMATIC, GLUE2(module, _APPL_DATA)) Versioninfo    \
        )                                                                               \
    {                                                                                   \
        Versioninfo->vendorID          = (uint16)GLUE2(module, _VENDOR_ID);             \
        Versioninfo->moduleID          = (uint16)GLUE2(module, _MODULE_ID);             \
        Versioninfo->instanceID        = (uint8)GLUE2(module, _INSTANCE_ID);            \
        Versioninfo->sw_major_version  = (uint8)GLUE2(module, _SW_MAJOR_VERSION);       \
        Versioninfo->sw_minor_version  = (uint8)GLUE2(module, _SW_MINOR_VERSION);       \
        Versioninfo->sw_patch_version  = (uint8)GLUE2(module, _SW_PATCH_VERSION);       \
    }

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __K_AR_H */

