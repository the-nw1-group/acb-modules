/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * Common defines across the range of ACB modules
  */

/*
 * Define locations of standard Inputs and Outputs on the ACB boards.
 * These are the green and yellow LEDs, generally on SWD pins,
 * and the FLiM Switch, generally on BOOT0 (which changes, per device)
 *
 * Unlike other processors (PICs for example), if the SWD are reassigned away from
 * alternate function/SWD, then you can't debug, so when in debug mode these
 * pins should be left alone
 *
 * For custom LED placement, define ACB_LED_CUSTOM and define the other ACB_LED_*
 * defines. Note, for now, the LEDs must be on the same port.
 *
 * For custom FLiM switch placement, define ACB_FLIM_CUSTOM and define the other ACB_FLIM_*
 * defines.
 *
 */

#if !defined(ACB_LED_CUSTOM)
#define ACB_LED_USE         !DEBUG
#define ACB_LED_AHBENR      RCC_AHBENR_GPIOAEN
#define ACB_LED_PORT        GPIOA_BASE
#define ACB_LED_GREEN_BIT   13
#define ACB_LED_YELLOW_BIT  14
#elif !defined(ACB_LED_USE)
#error You must manually define ACB_LED_USE when ACB_LED_CUSTOM is defined
#elif (ACB_LED_USE==1) && (!defined(ACB_LED_AHBENR) || !defined(ACB_LED_PORT) || !defined(ACB_LED_GREEN_BIT) || !defined(ACB_LED_YELLOW_BIT))
#error You must manually define all of: ACB_LED_AHBENR; ACB_LED_PORT; ACB_LED_GREEN_BIT; ACB_LED_YELLOW_BIT, when ACB_LED_CUSTOM is defined and ACB_LED_USE = 1
#endif

#if !defined(ACB_FLIMSW_CUSTOM)
#define ACB_FLIMSW_USE      1
#define ACB_FLIMSW_AHBENR   RCC_AHBENR_GPIOBEN
#define ACB_FLIMSW_PORT     GPIOB_BASE
#define ACB_FLIMSW_BIT      8
#elif !defined(ACB_FLIMSW_USE)
#error You must manually define ACB_FLIMSW_USE when ACB_FLIMSW_CUSTOM is defined
#elif (ACB_FLIMSW_USE==1) && (!defined(ACB_FLIMSW_AHBENR) || !defined(ACB_FLIMSW_PORT) || !defined(ACB_FLIMSW_BIT))
#error You must manually define all of: ACB_FLIMSW_AHBENR; ACB_FLIMSW_PORT; ACB_FLIMSW_BIT; when ACB_FLIMSW_CUSTOM is defined and ACB_FLIMSW_USE = 1
#endif

/*
 * following defines a ACB MSG structure. Data stored in dataLow is [data3][data2][data1][data0]
 * and data stored in dataHigh is [data7][data6][data5][data4]
 *  struct MSG_INFO
 *  {
 *      unsigned word stid : 10;
 *      struct
 *      {
 *          unsigned byte dlc : 4;
 *          unsigned byte rtr : 1;
 *          unsigned byte ide : 1;
 *      } dlc_status;
 *      unsigned byte reserved;
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

#define ACB_MSG_INFO_STID_OFFSET        0x0000
#define ACB_MSG_INFO_DLC_OFFSET         0x0002
#define ACB_MSG_INFO_RESERVED_OFFSET    0x0003

#define ACB_MSG_INFO_OFFSET             0x0000
#define ACB_MSG_DATA_OFFSET             0x0004
#define ACB_MSG_DATA_LOW_OFFSET         0x0004
#define ACB_MSG_DATA_HIGH_OFFSET        0x0008

#define ACB_MSG_SIZE                    12

/*
 * following defines a ACB MSG structure for an ACB message
 *  struct MSGEX_INFO
 *  {
 *      unsigned dword exid : 28;
 *      struct
 *      {
 *          unsigned byte dlc : 4;
 *          unsigned byte rtr : 1;
 *          unsigned byte ide : 1;
 *      } dlc_status;
 *      unsigned byte  reserved[3];
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

#define ACB_MSGEX_INFO_EXID_OFFSET      0x0000
#define ACB_MSGEX_INFO_DLC_OFFSET       0x0004
#define ACB_MSGEX_INFO_RESERVED_OFFSET  0x0005

#define ACB_MSGEX_INFO_OFFSET           0x0000
#define ACB_MSGEX_DATA_OFFSET           0x0008
#define ACB_MSGEX_DATA_LOW_OFFSET       0x0008
#define ACB_MSGEX_DATA_HIGH_OFFSET      0x000C

#define ACB_MSGEX_SIZE                  16

#define ACB_MSG_DLC_OFFSET              0
#define ACB_MSG_RTR_OFFSET              4
#define ACB_MSG_IDE_OFFSET              5

#define ACB_MSG_DLC_SIZE                4
#define ACB_MSG_IDE_SIZE                1
#define ACB_MSG_RTR_SIZE                1

/*
 * Other useful constants
 *
 */

#define ACB_MSG_DLC_MASK                (1<<(ACB_MSG_DLC_SIZE)-1) << ACB_MSG_DLC_OFFSET
#define ACB_MSG_IDE_MASK                ACB_MSG_IDE_SIZE << ACB_MSG_IDE_OFFSET
#define ACB_MSG_RTR_MASK                ACB_MSG_RTR_SIZE << ACB_MSG_RTR_OFFSET
