/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * Common constants
 *
 */

PENDING         =  2                                                @ Pending status, returned from async calls

/*
 * immediate value to use with the SVC instruction
 *
 */

ACB_FATAL_ERROR = 0x17

/*
 * following defines a ACB MSG structure. Data stored in dataLow is [data3][data2][data1][data0]
 * and data stored in dataHigh is [data7][data6][data5][data4]
 *  struct MSG_INFO
 *  {
 *      unsigned word reserved2 : 10;
 *      struct
 *      {
 *          unsigned byte len : 4;
 *          unsigned byte res : 1;
 *          unsigned byte ide : 1;
 *      } dlc_status;
 *      unsigned byte reserved3;
 *  } ;
 *
 *  struct MSG
 *  {
 *      MSG_INFO info;
 *      unsigned int dataLow;
 *      unsigned int dataHigh;
 *  } ;
 *
 */

#define ACB_MSG_INFO_RES2_OFFSET        0x0000
#define ACB_MSG_INFO_LEN_OFFSET         0x0002
#define ACB_MSG_INFO_RESERVED3_OFFSET   0x0003

#define ACB_MSG_INFO_OFFSET             0x0000
#define ACB_MSG_DATA_OFFSET             0x0004
#define ACB_MSG_DATA_LOW_OFFSET         0x0004
#define ACB_MSG_DATA_HIGH_OFFSET        0x0008

#define ACB_MSG_SIZE                    12

/*
 * following defines a ACB MSG structure for an ACB message
 *  struct MSGEX_INFO
 *  {
 *      unsigned dword reserved2 : 28;
 *      struct
 *      {
 *          unsigned byte len : 4;
 *          unsigned byte res : 1;
 *          unsigned byte ide : 1;
 *      } dlc_status;
 *      unsigned byte  reserved3[3];
 *  } ;
 *
 *  struct MSGEX
 *  {
 *      MSGEX_INFO info;
 *      unsigned int dataLow;
 *      unsigned int dataHigh;
 *  } ;
 *
 */

#define ACB_MSGEX_INFO_RES2_OFFSET      0x0000
#define ACB_MSGEX_INFO_LEN_OFFSET       0x0004
#define ACB_MSGEX_INFO_RESERVED3_OFFSET 0x0005

#define ACB_MSGEX_INFO_OFFSET           0x0000
#define ACB_MSGEX_DATA_OFFSET           0x0008
#define ACB_MSGEX_DATA_LOW_OFFSET       0x0008
#define ACB_MSGEX_DATA_HIGH_OFFSET      0x000C

#define ACB_MSGEX_SIZE                  16

#define ACB_MSG_LEN_OFFSET              0
#define ACB_MSG_RESERVED_OFFSET         4
#define ACB_MSG_IDE_OFFSET              5

#define ACB_MSG_LEN_SIZE                4
#define ACB_MSG_IDE_SIZE                1
#define ACB_MSG_RESERVED_SIZE           1

/*
 * Other useful constants
 *
 */

#define ACB_MSG_LEN_MASK                (1<<(ACB_MSG_LEN_SIZE)-1) << ACB_MSG_LEN_OFFSET
#define ACB_MSG_IDE_MASK                ACB_MSG_IDE_SIZE << ACB_MSG_IDE_OFFSET
#define ACB_MSG_RESERVED_MASK           ACB_MSG_RESERVED_SIZE << ACB_MSG_RESERVED_OFFSET

/*
 * Random other constants
 *
 */

OB_USER_BOOT_SEL =  (1<<23)                                         @ BOOT_SEL bit in the user option byte

#define LOBYTE(b)       ((b)&0xFF)
#define HIBYTE(b)       (((b)>>8)&0xFF)
#define TOPBYTE(b)      (((b)>>16)&0xFF)
#define TOPMOSTBYTE(b)  (((b)>>24)&0xFF)
