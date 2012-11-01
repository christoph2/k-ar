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
 */
#if !defined(__RAMTST__CFG_H)
#define __RAMTST_CFG_H

#define RAMTST_GET_VERSION_INFO_API                     STD_ON
#define RAMTST_DEV_ERROR_DETECT                         STD_ON
#define RAMTST_STOP_API                                 STD_ON
#define RAMTST_START_API                                STD_ON
#define RAMTST_ALLOW_API                                STD_ON
#define RAMTST_SUSPEND_API                              STD_ON
#define RAMTST_RESUME_API                               STD_ON
#define RAMTST_RUN_FULL_TEST_API                        STD_ON
#define RAMTST_RUN_PARTIAL_TEST_API                     STD_ON
#define RAMTST_GET_EXECUTION_STATUS_API                 STD_ON
#define RAMTST_GET_TEST_RESULT_API                      STD_ON
#define RAMTST_GET_TEST_RESULT_PER_BLOCK_API            STD_ON
#define RAMTST_GET_TEST_ALGORITHM_API                   STD_ON
#define RAMTST_GET_NUMBER_OF_TESTED_CELLS_API           STD_ON
#define RAMTST_CHANGE_TEST_ALGORITHM_API                STD_ON
#define RAMTST_CHANGE_NUMBER_OF_TESTED_CELLS_API        STD_ON
#define RAMTST_CHANGE_MAX_NUMBER_OF_TESTED_CELLS_API    STD_ON
#define RAMTST_SELECT_TEST_BLOCK_API                    STD_ON

/*
**  Available Algorithms.
*/
#define RAMTST_NUMBER_OF_ALGORITHMS                     ((uint8)6)

#define RAMTST_ABRAHAM_TEST_SELECTED                    STD_ON
#define RAMTST_CHECKERBOARD_TEST_SELECTED               STD_ON
#define RAMTST_GALPAT_TEST_SELECTED                     STD_ON
#define RAMTST_MARCH_TEST_SELECTED                      STD_ON
#define RAMTST_TRANSP_GALPAT_TEST_SELECTED              STD_ON
#define RAMTST_WALK_PATH_TEST_SELECTED                  STD_ON

/*
** Blocks
*/
#define RAMTST_TOTAL_NUMBER_OF_BLOCKS                   ((uint8)6)
#endif /* __PWM_RAMTST_H */

