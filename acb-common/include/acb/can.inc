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

#define ACB_USE_CAN

#if !defined(ACB_CAN_SJW)
#define ACB_CAN_SJW     0
#endif 

#if !defined(ACB_CAN_BS1)
#define ACB_CAN_BS1     10
#endif 

#if !defined(ACB_CAN_BS2)
#define ACB_CAN_BS2     3
#endif 

#if !defined(ACB_CAN_BRP)
#define ACB_CAN_BRP     23
#endif 


/*
 * Port definitions
 *
 * Set ACB_CANPORT to either ACB_CAN_USEPORTA, 0, to use PA11 and PA12
 *                           ACB_CAN_USEPORTB, 1, to use PB8 and PB9
 *                        or ACB_CAN_USEROTHER, 2, and define the constants in your header file
 *
 * Define ACB_CAN_REQUIRES_SYSCONFIG if the device requires PA11/PA12 to be remapped from PA9/PA10
 *
 */

#if ACB_CANPORT == ACB_CAN_USEPORTA
       #define ACB_CAN_AHBENR              RCC_AHBENR_GPIOAEN
       #define ACB_CAN_GPIOBASE            GPIOA_BASE
       #define ACB_CAN_RXPIN               11
       #define ACB_CAN_TXPIN               12
       #define ACB_CAN_GPIO_AFR_OFFSET     (GPIO_AFR_OFFSET+4)
#elif ACB_CANPORT == ACB_CAN_USEPORTB
       #define ACB_CAN_AHBENR              RCC_AHBENR_GPIOBEN
       #define ACB_CAN_GPIOBASE            GPIOB_BASE
       #define ACB_CAN_RXPIN               8
       #define ACB_CAN_TXPIN               9
       #define ACB_CAN_GPIO_AFR_OFFSET     (GPIO_AFR_OFFSET+4)
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

/*
 * Definitions of extra fields in ACB_MSG
 */

#define ACB_MSG_INFO_STID_OFFSET        ACB_MSG_INFO_RES2_OFFSET
#define ACB_MSG_RTR_OFFSET              ACB_MSG_RESERVED_OFFSET
#define ACB_MSG_RTR_SIZE                ACB_MSG_RESERVED_SIZE
#define ACB_MSG_RTR_MASK                ACB_MSG_RESERVED_MASK

/*
 * Definitions of extra fields in ACB_MSGEX
 */

#define ACB_MSGEX_INFO_EXID_OFFSET      ACB_MSGEX_INFO_RES2_OFFSET
#define ACB_MSGEX_RTR_OFFSET            ACB_MSG_RESERVED_OFFSET
#define ACB_MSGEX_RTR_SIZE              ACB_MSG_RESERVED_SIZE
#define ACB_MSGEX_RTR_MASK              ACB_MSG_RESERVED_MASK

/*
 * Define the AcbTransport interface
 */
#define AcbTransport_init                   Can_initForStandardFrames
#define AcbTransport_initConfiguration      Can_initConfiguration
#define AcbTransport_upgradeConfiguration   Can_upgradeConfiguration
#define AcbTransport_sendMessage            Can_sendMessage
#define AcbTransport_postMessage            Can_postMessage
#define AcbTransport_peakMessage            Can_getMsg
