/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
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
#if !defined(__MEMIF_TYPES_H)
#define __MEMIF_TYPES_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

	
/*
**  Published Information.
*/
#define MEMIF_TYPES_VENDOR_ID           AR_VENDOR_ID
#define MEMIF_TYPES_MODULE_ID           AR_MODULE_ID_MEMIF_TYPES
#define MEMIF_TYPES_INSTANCE_ID         0
#define MEMIF_TYPES_AR_MAJOR_VERSION	3
#define MEMIF_TYPES_AR_MINOR_VERSION	1
#define MEMIF_TYPES_AR_PATCH_VERSION	0
#define MEMIF_TYPES_SW_MAJOR_VERSION	1
#define MEMIF_TYPES_SW_MINOR_VERSION	0
#define MEMIF_TYPES_SW_PATCH_VERSION	0
#define MEMIF_TYPES_VENDOR_API_INFIX	

/*
** Global Types.
*/    
/* Denotes the current status of the underlying abstraction module and device drive. */
typedef enum tagMemIf_StatusType {
    /* The underlying abstraction module or device driver has not been initialized (yet). */
    MEMIF_UNINIT,
    /* The underlying abstraction module or device driver is currently idle. */
    MEMIF_IDLE,
    /* The underlying abstraction module or device driver is currently busy. */
    MEMIF_BUSY,
    /* The underlying abstraction module is busy with internal management operations. The underlying device driver can be busy or idle. */
    MEMIF_BUSY_INTERNAL
} MemIf_StatusType;

/* Denotes the result of the last job. */
typedef enum tagMemIf_JobResultType {
    /* The job has been finished successfully. */
    MEMIF_JOB_OK,
    /* The job has not been finished successfully. */
    MEMIF_JOB_FAILED,
    /* The job has not yet been finished. */
    MEMIF_JOB_PENDING,
    /* The job has been canceled. */
    MEMIF_JOB_CANCELED,
    /* The requested block is inconsistent, it may contain corrupted data. */
    MEMIF_BLOCK_INCONSISTENT,
    /* The requested block has been marked as invalid, the requested operation can not be performed. */
    MEMIF_BLOCK_INVALID
} MemIf_JobResultType;

/* Denotes the operation mode of the underlying abstraction modules and device drivers. */
typedef enum tagMemIf_ModeType {
    /* The underlying memory abstraction modules and drivers are working in slow mode. */
    MEMIF_MODE_SLOW,
    /* The underlying memory abstraction modules and drivers are working in fast mode. */
    MEMIF_MODE_FAST
} MemIf_ModeType;

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __MEMIF_TYPES_H */

