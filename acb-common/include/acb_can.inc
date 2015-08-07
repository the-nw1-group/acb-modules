/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * standard CAN settings for cortex m0 based devices - specifically the STM32F042x series of microcontroller
 * for the ACB modules.
 *
 * CAN is configured for 125 kbits/s, with the following parameters
 *      sync jump width = 1*Tq
 *      PROP_SEQ+PHASE_SEG1 = 11*Tq
 *      PHASE_SEG2 = 4*Tq
 *      Baud rate prescale = 24/Fosc (based on a clock speed of 48Mhz)
 *
 */

#define ACB_CAN_SJW     0
#define ACB_CAN_BS1     10
#define ACB_CAN_BS2     3
#define ACB_CAN_BRP     23

/*
 * following defines a MSG structure for a CAN message. Data stored in dataLow is [data3][data2][data1][data0]
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
 * following defines a MSG structure for an extended CAN message
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

/*
 * Port definitions
 *
 * Set ACB_CANPORT to either ACB_CAN_USEPORTA, 0, to use PA11 and PA12
 *                           ACB_CAN_USEPORTB, 1, to use PB8 and PB9
 *                        or ACB_CAN_USEROTHER, 2, and define the constants in your header file
 *
 */

#if ACB_CANPORT == ACB_CAN_USEPORTA

#define ACB_CAN_AHBENR              RCC_AHBENR_GPIOAEN
#define ACB_CAN_GPIOBASE            GPIOA_BASE
#define ACB_CAN_RXPIN               11
#define ACB_CAN_TXPIN               12
#define ACB_CAN_GPIO_AFR_OFFSET     (GPIO_AFR_OFFSET+4)
#define ACB_CAN_REQUIRES_SYSCONFIG  1

#elif ACB_CANPORT == ACB_CAN_USEPORTB

#define ACB_CAN_AHBENR              RCC_AHBENR_GPIOBEN
#define ACB_CAN_GPIOBASE            GPIOB_BASE
#define ACB_CAN_RXPIN               8
#define ACB_CAN_TXPIN               9
#define ACB_CAN_GPIO_AFR_OFFSET     (GPIO_AFR_OFFSET+4)
#define ACB_CAN_REQUIRES_SYSCONFIG  0

#elif (ACB_CANPORT == ACB_CAN_USEOTHER) && (!defined(ACB_CAN_AHBENR) || !defined(ACB_CAN_GPIOBASE) || !defined(ACB_CAN_RXPIN) ||\
       !defined(ACB_CAN_TXPIN) || !defined(ACB_CAN_GPIO_AFR_OFFSET) || !defined(ACB_CAN_REQUIRES_SYSCONFIG))
#error You must manually define the CAN/PIN settings for this usage
#else
#error You must define ACB_CANPORT to be either ACB_CAN_USEPORTA, ACB_CAN_USEPORTB or ACB_CAN_USEOTHER
#endif

#if ACB_CAN_RXPIN > 7
#define ACB_CAN_AFR_RXPIN (ACB_CAN_RXPIN-8)
#else
#define ACB_CAN_AFR_RXPIN (ACB_CAN_RXPIN)
#endif

#if ACB_CAN_TXPIN > 7
#define ACB_CAN_AFR_TXPIN (ACB_CAN_TXPIN-8)
#else
#define ACB_CAN_AFR_TXPIN (ACB_CAN_TXPIN)
#endif
