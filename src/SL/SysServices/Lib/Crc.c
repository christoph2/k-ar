/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
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
#include "Crc.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(CRC, 3, 1, 0, 1, 0)
    #error Version-Information-Mismatch of Include-File 'Crc.h' !
#endif

#if 0
#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET, 3, 1)
    #error Version-Information-Mismatch of Include-File 'Det.h' !
#endif
#endif

#include "Crc_Cfg.h"

#if !defined(CRC_8_MODE)
    #define CRC_8_MODE  CRC_8_TABLE
#endif

#if !defined(CRC_16_MODE)
    #define CRC_16_MODE CRC_16_TABLE
#endif

#if !defined(CRC_32_MODE)
    #define CRC_32_MODE CRC_32_TABLE
#endif

/*
**
**  References:
**  ===========
**  [1] SAE1850:2001 - Class B Data Communication Network Interface.
**
*/

/*
**  Non offical AUTOSAR-Errata:
**  ---------------------------
**  Specification on CRC Routines V3.0.2 R3.1 Rev001, 7.2.1 8-bit CRC calculation ('CRC025'):
**
**                  wrong   right
**  -----------------------------
**  Initial value:  0h      FFh
**  XOR value:      0h      FFh
**  Check:          F4h     59h
**
**  s. [1]-7.4.1 Cyclic Redundancy Check.
**  see also Test-Suite '???.c', the Testcases are taken from [1]-7.4.1 h)./Table 1.
**
*/

void Crc_Test(void);

uint32 Crc_Reflect(sint32 data, uint16 data_len);


static const char Crc_TestVector[] = "123456789";

/*
**  Local Defines.
*/
#define CRC_POLY_8  ((uint8)0x1d)
#define CRC_POLY_16 ((uint16)0x1021U)
#define CRC_POLY_32 ((uint32)0x04c11db7UL)

/*
** 8-Bit-CRC: SAE-J1850 (0x1d).
*/

#if (CRC_8_MODE == CRC_8_TABLE)
static CONST(uint8, CRC_CONST_8BIT) Crc_Table8[] = {
    ((uint8)0x00), ((uint8)0x1d), ((uint8)0x3a), ((uint8)0x27), ((uint8)0x74),
    ((uint8)0x69), ((uint8)0x4e), ((uint8)0x53), ((uint8)0xe8), ((uint8)0xf5),
    ((uint8)0xd2), ((uint8)0xcf), ((uint8)0x9c), ((uint8)0x81), ((uint8)0xa6),
    ((uint8)0xbb), ((uint8)0xcd), ((uint8)0xd0), ((uint8)0xf7), ((uint8)0xea),
    ((uint8)0xb9), ((uint8)0xa4), ((uint8)0x83), ((uint8)0x9e), ((uint8)0x25),
    ((uint8)0x38), ((uint8)0x1f), ((uint8)0x02), ((uint8)0x51), ((uint8)0x4c),
    ((uint8)0x6b), ((uint8)0x76), ((uint8)0x87), ((uint8)0x9a), ((uint8)0xbd),
    ((uint8)0xa0), ((uint8)0xf3), ((uint8)0xee), ((uint8)0xc9), ((uint8)0xd4),
    ((uint8)0x6f), ((uint8)0x72), ((uint8)0x55), ((uint8)0x48), ((uint8)0x1b),
    ((uint8)0x06), ((uint8)0x21), ((uint8)0x3c), ((uint8)0x4a), ((uint8)0x57),
    ((uint8)0x70), ((uint8)0x6d), ((uint8)0x3e), ((uint8)0x23), ((uint8)0x04),
    ((uint8)0x19), ((uint8)0xa2), ((uint8)0xbf), ((uint8)0x98), ((uint8)0x85),
    ((uint8)0xd6), ((uint8)0xcb), ((uint8)0xec), ((uint8)0xf1), ((uint8)0x13),
    ((uint8)0x0e), ((uint8)0x29), ((uint8)0x34), ((uint8)0x67), ((uint8)0x7a),
    ((uint8)0x5d), ((uint8)0x40), ((uint8)0xfb), ((uint8)0xe6), ((uint8)0xc1),
    ((uint8)0xdc), ((uint8)0x8f), ((uint8)0x92), ((uint8)0xb5), ((uint8)0xa8),
    ((uint8)0xde), ((uint8)0xc3), ((uint8)0xe4), ((uint8)0xf9), ((uint8)0xaa),
    ((uint8)0xb7), ((uint8)0x90), ((uint8)0x8d), ((uint8)0x36), ((uint8)0x2b),
    ((uint8)0x0c), ((uint8)0x11), ((uint8)0x42), ((uint8)0x5f), ((uint8)0x78),
    ((uint8)0x65), ((uint8)0x94), ((uint8)0x89), ((uint8)0xae), ((uint8)0xb3),
    ((uint8)0xe0), ((uint8)0xfd), ((uint8)0xda), ((uint8)0xc7), ((uint8)0x7c),
    ((uint8)0x61), ((uint8)0x46), ((uint8)0x5b), ((uint8)0x08), ((uint8)0x15),
    ((uint8)0x32), ((uint8)0x2f), ((uint8)0x59), ((uint8)0x44), ((uint8)0x63),
    ((uint8)0x7e), ((uint8)0x2d), ((uint8)0x30), ((uint8)0x17), ((uint8)0x0a),
    ((uint8)0xb1), ((uint8)0xac), ((uint8)0x8b), ((uint8)0x96), ((uint8)0xc5),
    ((uint8)0xd8), ((uint8)0xff), ((uint8)0xe2), ((uint8)0x26), ((uint8)0x3b),
    ((uint8)0x1c), ((uint8)0x01), ((uint8)0x52), ((uint8)0x4f), ((uint8)0x68),
    ((uint8)0x75), ((uint8)0xce), ((uint8)0xd3), ((uint8)0xf4), ((uint8)0xe9),
    ((uint8)0xba), ((uint8)0xa7), ((uint8)0x80), ((uint8)0x9d), ((uint8)0xeb),
    ((uint8)0xf6), ((uint8)0xd1), ((uint8)0xcc), ((uint8)0x9f), ((uint8)0x82),
    ((uint8)0xa5), ((uint8)0xb8), ((uint8)0x03), ((uint8)0x1e), ((uint8)0x39),
    ((uint8)0x24), ((uint8)0x77), ((uint8)0x6a), ((uint8)0x4d), ((uint8)0x50),
    ((uint8)0xa1), ((uint8)0xbc), ((uint8)0x9b), ((uint8)0x86), ((uint8)0xd5),
    ((uint8)0xc8), ((uint8)0xef), ((uint8)0xf2), ((uint8)0x49), ((uint8)0x54),
    ((uint8)0x73), ((uint8)0x6e), ((uint8)0x3d), ((uint8)0x20), ((uint8)0x07),
    ((uint8)0x1a), ((uint8)0x6c), ((uint8)0x71), ((uint8)0x56), ((uint8)0x4b),
    ((uint8)0x18), ((uint8)0x05), ((uint8)0x22), ((uint8)0x3f), ((uint8)0x84),
    ((uint8)0x99), ((uint8)0xbe), ((uint8)0xa3), ((uint8)0xf0), ((uint8)0xed),
    ((uint8)0xca), ((uint8)0xd7), ((uint8)0x35), ((uint8)0x28), ((uint8)0x0f),
    ((uint8)0x12), ((uint8)0x41), ((uint8)0x5c), ((uint8)0x7b), ((uint8)0x66),
    ((uint8)0xdd), ((uint8)0xc0), ((uint8)0xe7), ((uint8)0xfa), ((uint8)0xa9),
    ((uint8)0xb4), ((uint8)0x93), ((uint8)0x8e), ((uint8)0xf8), ((uint8)0xe5),
    ((uint8)0xc2), ((uint8)0xdf), ((uint8)0x8c), ((uint8)0x91), ((uint8)0xb6),
    ((uint8)0xab), ((uint8)0x10), ((uint8)0x0d), ((uint8)0x2a), ((uint8)0x37),
    ((uint8)0x64), ((uint8)0x79), ((uint8)0x5e), ((uint8)0x43), ((uint8)0xb2),
    ((uint8)0xaf), ((uint8)0x88), ((uint8)0x95), ((uint8)0xc6), ((uint8)0xdb),
    ((uint8)0xfc), ((uint8)0xe1), ((uint8)0x5a), ((uint8)0x47), ((uint8)0x60),
    ((uint8)0x7d), ((uint8)0x2e), ((uint8)0x33), ((uint8)0x14), ((uint8)0x09),
    ((uint8)0x7f), ((uint8)0x62), ((uint8)0x45), ((uint8)0x58), ((uint8)0x0b),
    ((uint8)0x16), ((uint8)0x31), ((uint8)0x2c), ((uint8)0x97), ((uint8)0x8a),
    ((uint8)0xad), ((uint8)0xb0), ((uint8)0xe3), ((uint8)0xfe), ((uint8)0xd9),
    ((uint8)0xc4)
};
#endif

/*
**  16-Bit-CRC: CCITT (0x1021).
*/
#if (CRC_16_MODE == CRC_16_TABLE)
static CONST(uint16, CRC_CONST_16BIT) Crc_Table16[] = {
    0x0000U, 0x1021U, 0x2042U, 0x3063U, 0x4084U, 0x50a5U, 0x60c6U, 0x70e7U,
    0x8108U, 0x9129U, 0xa14aU, 0xb16bU, 0xc18cU, 0xd1adU, 0xe1ceU, 0xf1efU,
    0x1231U, 0x0210U, 0x3273U, 0x2252U, 0x52b5U, 0x4294U, 0x72f7U, 0x62d6U,
    0x9339U, 0x8318U, 0xb37bU, 0xa35aU, 0xd3bdU, 0xc39cU, 0xf3ffU, 0xe3deU,
    0x2462U, 0x3443U, 0x0420U, 0x1401U, 0x64e6U, 0x74c7U, 0x44a4U, 0x5485U,
    0xa56aU, 0xb54bU, 0x8528U, 0x9509U, 0xe5eeU, 0xf5cfU, 0xc5acU, 0xd58dU,
    0x3653U, 0x2672U, 0x1611U, 0x0630U, 0x76d7U, 0x66f6U, 0x5695U, 0x46b4U,
    0xb75bU, 0xa77aU, 0x9719U, 0x8738U, 0xf7dfU, 0xe7feU, 0xd79dU, 0xc7bcU,
    0x48c4U, 0x58e5U, 0x6886U, 0x78a7U, 0x0840U, 0x1861U, 0x2802U, 0x3823U,
    0xc9ccU, 0xd9edU, 0xe98eU, 0xf9afU, 0x8948U, 0x9969U, 0xa90aU, 0xb92bU,
    0x5af5U, 0x4ad4U, 0x7ab7U, 0x6a96U, 0x1a71U, 0x0a50U, 0x3a33U, 0x2a12U,
    0xdbfdU, 0xcbdcU, 0xfbbfU, 0xeb9eU, 0x9b79U, 0x8b58U, 0xbb3bU, 0xab1aU,
    0x6ca6U, 0x7c87U, 0x4ce4U, 0x5cc5U, 0x2c22U, 0x3c03U, 0x0c60U, 0x1c41U,
    0xedaeU, 0xfd8fU, 0xcdecU, 0xddcdU, 0xad2aU, 0xbd0bU, 0x8d68U, 0x9d49U,
    0x7e97U, 0x6eb6U, 0x5ed5U, 0x4ef4U, 0x3e13U, 0x2e32U, 0x1e51U, 0x0e70U,
    0xff9fU, 0xefbeU, 0xdfddU, 0xcffcU, 0xbf1bU, 0xaf3aU, 0x9f59U, 0x8f78U,
    0x9188U, 0x81a9U, 0xb1caU, 0xa1ebU, 0xd10cU, 0xc12dU, 0xf14eU, 0xe16fU,
    0x1080U, 0x00a1U, 0x30c2U, 0x20e3U, 0x5004U, 0x4025U, 0x7046U, 0x6067U,
    0x83b9U, 0x9398U, 0xa3fbU, 0xb3daU, 0xc33dU, 0xd31cU, 0xe37fU, 0xf35eU,
    0x02b1U, 0x1290U, 0x22f3U, 0x32d2U, 0x4235U, 0x5214U, 0x6277U, 0x7256U,
    0xb5eaU, 0xa5cbU, 0x95a8U, 0x8589U, 0xf56eU, 0xe54fU, 0xd52cU, 0xc50dU,
    0x34e2U, 0x24c3U, 0x14a0U, 0x0481U, 0x7466U, 0x6447U, 0x5424U, 0x4405U,
    0xa7dbU, 0xb7faU, 0x8799U, 0x97b8U, 0xe75fU, 0xf77eU, 0xc71dU, 0xd73cU,
    0x26d3U, 0x36f2U, 0x0691U, 0x16b0U, 0x6657U, 0x7676U, 0x4615U, 0x5634U,
    0xd94cU, 0xc96dU, 0xf90eU, 0xe92fU, 0x99c8U, 0x89e9U, 0xb98aU, 0xa9abU,
    0x5844U, 0x4865U, 0x7806U, 0x6827U, 0x18c0U, 0x08e1U, 0x3882U, 0x28a3U,
    0xcb7dU, 0xdb5cU, 0xeb3fU, 0xfb1eU, 0x8bf9U, 0x9bd8U, 0xabbbU, 0xbb9aU,
    0x4a75U, 0x5a54U, 0x6a37U, 0x7a16U, 0x0af1U, 0x1ad0U, 0x2ab3U, 0x3a92U,
    0xfd2eU, 0xed0fU, 0xdd6cU, 0xcd4dU, 0xbdaaU, 0xad8bU, 0x9de8U, 0x8dc9U,
    0x7c26U, 0x6c07U, 0x5c64U, 0x4c45U, 0x3ca2U, 0x2c83U, 0x1ce0U, 0x0cc1U,
    0xef1fU, 0xff3eU, 0xcf5dU, 0xdf7cU, 0xaf9bU, 0xbfbaU, 0x8fd9U, 0x9ff8U,
    0x6e17U, 0x7e36U, 0x4e55U, 0x5e74U, 0x2e93U, 0x3eb2U, 0x0ed1U, 0x1ef0U
};
#endif

/*
**  32-Bit-CRC: IEEE 802.3/Ethernet (0x04c11db7).
*/
#if (CRC_32_MODE == CRC_32_TABLE)
static CONST(uint32, CRC_CONST_32BIT) Crc_Table32[] = {
    0x00000000UL, 0x77073096UL, 0xee0e612cUL, 0x990951baUL, 0x076dc419UL,
    0x706af48fUL, 0xe963a535UL, 0x9e6495a3UL, 0x0edb8832UL, 0x79dcb8a4UL,
    0xe0d5e91eUL, 0x97d2d988UL, 0x09b64c2bUL, 0x7eb17cbdUL, 0xe7b82d07UL,
    0x90bf1d91UL, 0x1db71064UL, 0x6ab020f2UL, 0xf3b97148UL, 0x84be41deUL,
    0x1adad47dUL, 0x6ddde4ebUL, 0xf4d4b551UL, 0x83d385c7UL, 0x136c9856UL,
    0x646ba8c0UL, 0xfd62f97aUL, 0x8a65c9ecUL, 0x14015c4fUL, 0x63066cd9UL,
    0xfa0f3d63UL, 0x8d080df5UL, 0x3b6e20c8UL, 0x4c69105eUL, 0xd56041e4UL,
    0xa2677172UL, 0x3c03e4d1UL, 0x4b04d447UL, 0xd20d85fdUL, 0xa50ab56bUL,
    0x35b5a8faUL, 0x42b2986cUL, 0xdbbbc9d6UL, 0xacbcf940UL, 0x32d86ce3UL,
    0x45df5c75UL, 0xdcd60dcfUL, 0xabd13d59UL, 0x26d930acUL, 0x51de003aUL,
    0xc8d75180UL, 0xbfd06116UL, 0x21b4f4b5UL, 0x56b3c423UL, 0xcfba9599UL,
    0xb8bda50fUL, 0x2802b89eUL, 0x5f058808UL, 0xc60cd9b2UL, 0xb10be924UL,
    0x2f6f7c87UL, 0x58684c11UL, 0xc1611dabUL, 0xb6662d3dUL, 0x76dc4190UL,
    0x01db7106UL, 0x98d220bcUL, 0xefd5102aUL, 0x71b18589UL, 0x06b6b51fUL,
    0x9fbfe4a5UL, 0xe8b8d433UL, 0x7807c9a2UL, 0x0f00f934UL, 0x9609a88eUL,
    0xe10e9818UL, 0x7f6a0dbbUL, 0x086d3d2dUL, 0x91646c97UL, 0xe6635c01UL,
    0x6b6b51f4UL, 0x1c6c6162UL, 0x856530d8UL, 0xf262004eUL, 0x6c0695edUL,
    0x1b01a57bUL, 0x8208f4c1UL, 0xf50fc457UL, 0x65b0d9c6UL, 0x12b7e950UL,
    0x8bbeb8eaUL, 0xfcb9887cUL, 0x62dd1ddfUL, 0x15da2d49UL, 0x8cd37cf3UL,
    0xfbd44c65UL, 0x4db26158UL, 0x3ab551ceUL, 0xa3bc0074UL, 0xd4bb30e2UL,
    0x4adfa541UL, 0x3dd895d7UL, 0xa4d1c46dUL, 0xd3d6f4fbUL, 0x4369e96aUL,
    0x346ed9fcUL, 0xad678846UL, 0xda60b8d0UL, 0x44042d73UL, 0x33031de5UL,
    0xaa0a4c5fUL, 0xdd0d7cc9UL, 0x5005713cUL, 0x270241aaUL, 0xbe0b1010UL,
    0xc90c2086UL, 0x5768b525UL, 0x206f85b3UL, 0xb966d409UL, 0xce61e49fUL,
    0x5edef90eUL, 0x29d9c998UL, 0xb0d09822UL, 0xc7d7a8b4UL, 0x59b33d17UL,
    0x2eb40d81UL, 0xb7bd5c3bUL, 0xc0ba6cadUL, 0xedb88320UL, 0x9abfb3b6UL,
    0x03b6e20cUL, 0x74b1d29aUL, 0xead54739UL, 0x9dd277afUL, 0x04db2615UL,
    0x73dc1683UL, 0xe3630b12UL, 0x94643b84UL, 0x0d6d6a3eUL, 0x7a6a5aa8UL,
    0xe40ecf0bUL, 0x9309ff9dUL, 0x0a00ae27UL, 0x7d079eb1UL, 0xf00f9344UL,
    0x8708a3d2UL, 0x1e01f268UL, 0x6906c2feUL, 0xf762575dUL, 0x806567cbUL,
    0x196c3671UL, 0x6e6b06e7UL, 0xfed41b76UL, 0x89d32be0UL, 0x10da7a5aUL,
    0x67dd4accUL, 0xf9b9df6fUL, 0x8ebeeff9UL, 0x17b7be43UL, 0x60b08ed5UL,
    0xd6d6a3e8UL, 0xa1d1937eUL, 0x38d8c2c4UL, 0x4fdff252UL, 0xd1bb67f1UL,
    0xa6bc5767UL, 0x3fb506ddUL, 0x48b2364bUL, 0xd80d2bdaUL, 0xaf0a1b4cUL,
    0x36034af6UL, 0x41047a60UL, 0xdf60efc3UL, 0xa867df55UL, 0x316e8eefUL,
    0x4669be79UL, 0xcb61b38cUL, 0xbc66831aUL, 0x256fd2a0UL, 0x5268e236UL,
    0xcc0c7795UL, 0xbb0b4703UL, 0x220216b9UL, 0x5505262fUL, 0xc5ba3bbeUL,
    0xb2bd0b28UL, 0x2bb45a92UL, 0x5cb36a04UL, 0xc2d7ffa7UL, 0xb5d0cf31UL,
    0x2cd99e8bUL, 0x5bdeae1dUL, 0x9b64c2b0UL, 0xec63f226UL, 0x756aa39cUL,
    0x026d930aUL, 0x9c0906a9UL, 0xeb0e363fUL, 0x72076785UL, 0x05005713UL,
    0x95bf4a82UL, 0xe2b87a14UL, 0x7bb12baeUL, 0x0cb61b38UL, 0x92d28e9bUL,
    0xe5d5be0dUL, 0x7cdcefb7UL, 0x0bdbdf21UL, 0x86d3d2d4UL, 0xf1d4e242UL,
    0x68ddb3f8UL, 0x1fda836eUL, 0x81be16cdUL, 0xf6b9265bUL, 0x6fb077e1UL,
    0x18b74777UL, 0x88085ae6UL, 0xff0f6a70UL, 0x66063bcaUL, 0x11010b5cUL,
    0x8f659effUL, 0xf862ae69UL, 0x616bffd3UL, 0x166ccf45UL, 0xa00ae278UL,
    0xd70dd2eeUL, 0x4e048354UL, 0x3903b3c2UL, 0xa7672661UL, 0xd06016f7UL,
    0x4969474dUL, 0x3e6e77dbUL, 0xaed16a4aUL, 0xd9d65adcUL, 0x40df0b66UL,
    0x37d83bf0UL, 0xa9bcae53UL, 0xdebb9ec5UL, 0x47b2cf7fUL, 0x30b5ffe9UL,
    0xbdbdf21cUL, 0xcabac28aUL, 0x53b39330UL, 0x24b4a3a6UL, 0xbad03605UL,
    0xcdd70693UL, 0x54de5729UL, 0x23d967bfUL, 0xb3667a2eUL, 0xc4614ab8UL,
    0x5d681b02UL, 0x2a6f2b94UL, 0xb40bbe37UL, 0xc30c8ea1UL, 0x5a05df1bUL,
    0x2d02ef8dUL
};
#endif

/*
**  Global Functions.
*/
#define CRC_START_SEC_CODE
#include "MemMap.h"

FUNC(uint8, CRC_CODE) Crc_CalculateCRC8(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint8 Crc_StartValue8)
{
#if CRC_8_MODE == CRC_8_RUNTIME
    uint16  idx;
    boolean bit;
    uint8   c;
    uint8   crc;

    crc = Crc_StartValue8;

    while (Crc_Length--) {
        c = *Crc_DataPtr++;

        for (idx = ((uint8)0x80); idx > ((uint8)0x00); idx >>= 1) {
            bit = (crc & (uint8)0x80) == (uint8)0x80;

            if (c & idx) {
                bit = !bit;
            }

            crc <<= 1;

            if (bit) {
                crc ^= CRC_POLY_8;
            }
        }
    }

    return ~crc;
#elif CRC_8_MODE == CRC_8_TABLE
    uint16  idx; /* check: faster? */    /* uint8 idx; */
    uint8   crc;

    crc = Crc_StartValue8;

    while (Crc_Length--) {
        idx    = ((crc) ^ *Crc_DataPtr) & (uint16)0x00ffu;
        crc    = (Crc_Table8[idx] ^ (crc << 8));
        Crc_DataPtr++;
    }

    return ~crc;
#endif
}

FUNC(uint16, CRC_CODE) Crc_CalculateCRC16(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint16 Crc_StartValue16
    )
{
#if CRC_16_MODE == CRC_16_RUNTIME
    uint16  idx;
    boolean bit;
    uint8   c;
    uint16  crc;

    crc = Crc_StartValue16;

    while (Crc_Length--) {
        c = *Crc_DataPtr++;

        for (idx = 0x0080U; idx > 0x0000U; idx >>= 1) {
            bit = (crc & 0x8000) == 0x8000U;

            if (c & idx) {
                bit = !bit;
            }

            crc <<= 1;

            if (bit) {
                crc ^= CRC_POLY_16;
            }
        }
    }

    return crc;
#elif CRC_16_MODE == CRC_16_TABLE
    uint16  idx;
    uint16  crc;

    crc = Crc_StartValue16;

    while (Crc_Length--) {
        idx    = ((crc >> 8) ^ *Crc_DataPtr) & 0xff;
        crc    = (Crc_Table16[idx] ^ (crc << 8)) & 0xffffU;

        Crc_DataPtr++;
    }

    return crc;
#endif
}

FUNC(uint32, CRC_CODE) Crc_CalculateCRC32(
    P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataPtr,
    uint32 Crc_Length,
    uint32 Crc_StartValue32
    )
{
#if CRC_32_MODE == CRC_32_RUNTIME
    uint16  idx;
    boolean bit;
    uint8   c;
    uint32  crc;

    crc = Crc_StartValue32;

    while (Crc_Length--) {
        c = *Crc_DataPtr++;

        for (idx = 0x01; idx &0xff; idx <<= 1) {
            bit = (crc & 0x80000000UL) == 0x80000000UL;

            if (c & idx) {
                bit = !bit;
            }

            crc <<= 1;

            if (bit) {
                crc ^= CRC_POLY_32; /* crc ^= 0xEDB88320UL; */ /* crc ^= 0xDB710641UL; */
            }
        }
    }

    return ~Crc_Reflect(crc, 32);
#elif CRC_32_MODE == CRC_32_TABLE
    uint16  idx;
    uint32  crc;

    crc = Crc_StartValue32;

    while (Crc_Length--) {
        idx    = (crc ^ *Crc_DataPtr) & 0xff;
        crc    = (Crc_Table32[idx] ^ (crc >> 8)) & 0xffffffffUL;
        Crc_DataPtr++;
    }

    return ~crc;
#endif
}


#if CRC_32_MODE == CRC_32_RUNTIME
uint32 Crc_Reflect(sint32 data, uint16 data_len)
{
    uint16  i;
    sint32  ret;

    ret = data & 0x01;

    for (i = 1; i < data_len; i++) {
        data >>= 1;
        ret    = (ret << 1) | (data & 0x01);
    }

    return ret;
}
#endif

#define CRC_STOP_SEC_CODE
#include "MemMap.h"

