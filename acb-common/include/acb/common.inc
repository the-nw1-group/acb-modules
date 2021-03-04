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

#define ACB_USE_COMMON

#if !defined(ACB_LED_CUSTOM)
#define ACB_LED_USE         !DEBUG
#define ACB_LED_PORT        GPIOA_BASE
/* #define ACB_LED_GREEN_BIT   13
   #define ACB_LED_YELLOW_BIT  14
*/
/* These are TEMP */
#define ACB_LED_GREEN_BIT   3
#define ACB_LED_YELLOW_BIT  2
#elif !defined(ACB_LED_USE)
   #error You must manually define ACB_LED_USE when ACB_LED_CUSTOM is defined
#elif (ACB_LED_USE==1) && (!defined(ACB_LED_PORT) || !defined(ACB_LED_GREEN_BIT) || !defined(ACB_LED_YELLOW_BIT))
   #error You must manually define all of: ACB_LED_PORT; ACB_LED_GREEN_BIT; ACB_LED_YELLOW_BIT, when ACB_LED_CUSTOM is defined and ACB_LED_USE = 1
#endif

#if !defined(ACB_FLIMSW_CUSTOM)
   #define ACB_FLIMSW_USE                      1
   #define ACB_FLIMSW_PORT                     GPIOB_BASE
   #define ACB_FLIMSW_BIT                      8
   /*
   *  These must match the selection ...PORT and ...BIT
   *  i.e PB8 = SYSCFG_EXTICR3[0..3] = 1
   */
   #define ACB_FLIMSW_SYSCFG_EXTI_REG          (_SYSCFG_EXTICR + (3-1) * 4)
   #define ACB_FLIMSW_SYSCFG_EXTI_START_BIT    0
   #define ACB_FLIMSW_SYSCFG_EXTI_VALUE        SYSCFG_EXTICR3_EXTI8_PB
   #define ACB_FLIMSW_SYSCFG_EXTI_ISR          __exti415IRQHandler
   #define ACB_FLIMSW_SYSCFG_EXTI_IRQ          EXTI4_15_IRQn
#elif !defined(ACB_FLIMSW_USE)
   #error You must manually define ACB_FLIMSW_USE when ACB_FLIMSW_CUSTOM is defined
#elif (ACB_FLIMSW_USE==1) && (!defined(ACB_FLIMSW_PORT) || !defined(ACB_FLIMSW_BIT) || !defined(ACB_FLIMSW_SYSCFG_EXTI_REG) || !defined(ACB_FLIMSW_SYSCFG_EXTI_START_BIT) || !defined(ACB_FLIMSW_SYSCFG_EXTI_VALUE) || !defined(ACB_FLIMSW_SYSCFG_EXTI_ISR) || !defined(ACB_FLIMSW_SYSCFG_EXTI_IRQ))
   #error You must manually define all of: ACB_FLIMSW_PORT; ACB_FLIMSW_BIT; ACB_FLIMSW_SYSCFG_EXTI_REG; ACB_FLIMSW_SYSCFG_EXTI_START_BIT; ACB_FLIMSW_SYSCFG_EXTI_VALUE; ACB_FLIMSW_SYSCFG_EXTI_ISR; ACB_FLIMSW_SYSCFG_EXTI_IRQ when ACB_FLIMSW_CUSTOM is defined and ACB_FLIMSW_USE = 1
#endif

/*
 * Default the number of alarm slots, if the application has specified any other value
 */

#if !defined(ACB_ALARM_SLOTS)
   #define ACB_ALARM_SLOTS 8
#endif
