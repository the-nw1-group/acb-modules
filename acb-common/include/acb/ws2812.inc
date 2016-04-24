/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * WS2812x driver include file
 *  define ACB_USE_WS2812 to use this driver
 *  define ACB_WS2812_DRIVER to the timer number used to control the devices. Timer 2 and 3 currently supported
 */

#define ACB_USE_WS2812

#if ACB_WS2812_DRIVER == 2

#define WS2812_RCC_APB1ENR_TIMEN    RCC_APB1ENR_TIM2EN
#define WS2812_TIM_BASE             TIM2_BASE
#define WS2812_TIM_ISR              TIM2_IRQn
#define WS2812_DMA_BASE             DMA1_BASE

#define WS2812_DMA_BASE             DMA1_BASE
#define WS2812_DMA_CHAN0            DMA1_Channel5_BASE
#define WS2812_DMA_CHAN1            DMA1_Channel3_BASE
#define WS2812_DMA_CHAN2            DMA1_Channel1_BASE
#define WS2812_DMA_CHAN3            DMA1_Channel4_BASE
#define WS2812_DMA_IFCR_CHAN0       DMA_IFCR_CGIF5
#define WS2812_DMA_IFCR_CHAN1       DMA_IFCR_CGIF3
#define WS2812_DMA_IFCR_CHAN2       DMA_IFCR_CGIF1
#define WS2812_DMA_IFCR_CHAN3       DMA_IFCR_CGIF4
#define WS2812_DMA_ISR_CHAN0        DMA1_Channel4_5_IRQn
#define WS2812_DMA_ISR_CHAN1        DMA1_Channel2_3_IRQn
#define WS2812_DMA_ISR_CHAN2        DMA1_Channel1_IRQn
#define WS2812_DMA_ISR_CHAN3        DMA1_Channel4_5_IRQn

#elif ACB_WS2812_DRIVER == 3

#define WS2812_RCC_APB1ENR_TIMEN    RCC_APB1ENR_TIM3EN
#define WS2812_TIM_BASE             TIM3_BASE
#define WS2812_TIM_ISR              TIM3_IRQn
#define WS2812_DMA_BASE             DMA1_BASE

#define WS2812_DMA_BASE             DMA1_BASE
#define WS2812_DMA_CHAN0            DMA1_Channel4_BASE
#define WS2812_DMA_CHAN1            0
#define WS2812_DMA_CHAN2            DMA1_Channel2_BASE
#define WS2812_DMA_CHAN3            DMA1_Channel3_BASE
#define WS2812_DMA_IFCR_CHAN0       DMA_IFCR_CGIF4
#define WS2812_DMA_IFCR_CHAN1       0
#define WS2812_DMA_IFCR_CHAN2       DMA_IFCR_CGIF2
#define WS2812_DMA_IFCR_CHAN3       DMA_IFCR_CGIF3
#define WS2812_DMA_ISR_CHAN0        DMA1_Channel4_5_IRQn
#define WS2812_DMA_ISR_CHAN1        0
#define WS2812_DMA_ISR_CHAN2        DMA1_Channel2_3_IRQn
#define WS2812_DMA_ISR_CHAN3        DMA1_Channel2_3_IRQn

#else
#error to use the WS2812 driver you must define ACB_WS2812_DRIVER. See the include file for details
#endif
