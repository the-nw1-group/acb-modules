@ File automatically generated from D:\Model Railways\Electronics\Information\ST-DemoCode\STM32F072B-Discovery_FW_V1.0.1\Libraries\CMSIS\Device\Include\stm32f0xx.h on 15/05/2014 20:42:48
@ by ConvertHeaderFiles (c) The NW1 Group

/**
  ******************************************************************************
  * @file    stm32f0xx.h
  * @author  MCD Application Team
  * @version V1.3.1
  * @date    17-January-2014
  * @brief   CMSIS Cortex-M0 Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for STM32F0xx devices.
  *
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *           - Configuration section that allows to select:
  *              - The device used in the target application
  *              - To use or not the peripheral’s drivers in application code(i.e.
  *                code will be based on direct access to peripheral’s registers
  *                rather than drivers API), this option is controlled by
  *                "#define USE_STDPERIPH_DRIVER"
  *              - To change few application-specific parameters such as the HSE
  *                crystal frequency
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral’s registers hardware
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f0xx
  * @{
  */

#ifndef __STM32F0XX_H
#define __STM32F0XX_H

#ifdef __cplusplus
#endif

#define __STM32F0XX

/** @addtogroup Library_configuration_section
  * @{
  */

/* Uncomment the line below according to the target STM32F0 device used in your
application
  */

#if !defined (STM32F030) && !defined (STM32F031) && !defined (STM32F051) && !defined (STM32F072) && !defined (STM32F042)
#define STM32F072
#endif

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */

#if defined(STM32F0XX) || defined(STM32F0XX_MD)
#define STM32F051
#endif /* STM32F0XX */

#ifdef STM32F0XX_LD
#define     STM32F031
#endif /* STM32F0XX_LD */

#ifdef STM32F0XX_HD
#define   STM32F072
#endif /* STM32F0XX_HD */

#if defined (STM32F030X8) || defined (STM32F030X6)
#define    STM32F030
#endif /* STM32F030X8 or  STM32F030X6 */


#if !defined (STM32F030) && !defined (STM32F031) && !defined (STM32F051) && !defined (STM32F072) && !defined (STM32F042)
#endif

#if !defined  USE_STDPERIPH_DRIVER
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
In this case, these drivers will not be included and the application code will
be based on direct access to peripherals registers
   */
#endif /* USE_STDPERIPH_DRIVER */

/**
 * @brief In the following line adjust the value of External High Speed oscillator (HSE)
used in your application

Tip: To avoid modifying this file each time you need to use different HSE, you
        can define the HSE value in your toolchain compiler preprocessor.
  */
#if !defined  (HSE_VALUE)
#define HSE_VALUE    (8000000) /*!< Value of the External oscillator in Hz*/
#endif /* HSE_VALUE */

/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) Startup
Timeout value
   */
#if !defined  (HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT   (0x5000) /*!< Time out for HSE start up */
#endif /* HSE_STARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the Internal High Speed oscillator (HSI) Startup
Timeout value
   */
#if !defined  (HSI_STARTUP_TIMEOUT)
#define HSI_STARTUP_TIMEOUT   (0x5000) /*!< Time out for HSI start up */
#endif /* HSI_STARTUP_TIMEOUT */

#if !defined  (HSI_VALUE)
#define HSI_VALUE  (8000000) /*!< Value of the Internal High Speed oscillator in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI_VALUE */

#if !defined  (HSI14_VALUE)
#define HSI14_VALUE (14000000) /*!< Value of the Internal High Speed oscillator for ADC in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI14_VALUE */

#if !defined  (HSI48_VALUE)
#define HSI48_VALUE (48000000) /*!< Value of the Internal High Speed oscillator for USB in Hz.
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* HSI48_VALUE */

#if !defined  (LSI_VALUE)
#define LSI_VALUE  (40000)    /*!< Value of the Internal Low Speed oscillator in Hz
                                             The real value may vary depending on the variations
                                             in voltage and temperature.  */
#endif /* LSI_VALUE */

#if !defined  (LSE_VALUE)
#define LSE_VALUE  (32768)    /*!< Value of the External Low Speed oscillator in Hz */
#endif /* LSE_VALUE */

/**
 * @brief STM32F0xx Standard Peripheral Library version number V1.3.1
   */
#define __STM32F0XX_STDPERIPH_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __STM32F0XX_STDPERIPH_VERSION_SUB1   (0x03) /*!< [23:16] sub1 version */
#define __STM32F0XX_STDPERIPH_VERSION_SUB2   (0x01) /*!< [15:8]  sub2 version */
#define __STM32F0XX_STDPERIPH_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __STM32F0XX_STDPERIPH_VERSION        ((__STM32F0XX_STDPERIPH_VERSION_MAIN << 24)\
                                             |(__STM32F0XX_STDPERIPH_VERSION_SUB1 << 16)\
                                             |(__STM32F0XX_STDPERIPH_VERSION_SUB2 << 8)\
                                             |(__STM32F0XX_STDPERIPH_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
 * @brief STM32F0xx Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
#define __CM0_REV                 0 /*!< Core Revision r0p0                            */
#define __MPU_PRESENT             0 /*!< STM32F0xx do not provide MPU                  */
#define __NVIC_PRIO_BITS          2 /*!< STM32F0xx uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0 /*!< Set to 1 if different SysTick Config is used  */

NonMaskableInt_IRQn         = -14    /*!< 2 Non Maskable Interrupt                                */
HardFault_IRQn              = -13    /*!< 3 Cortex-M0 Hard Fault Interrupt                        */
SVC_IRQn                    = -5     /*!< 11 Cortex-M0 SV Call Interrupt                          */
PendSV_IRQn                 = -2     /*!< 14 Cortex-M0 Pend SV Interrupt                          */
SysTick_IRQn                = -1     /*!< 15 Cortex-M0 System Tick Interrupt                      */

#if defined (STM32F051)
WWDG_IRQn                   = 0      /*!< Window WatchDog Interrupt                               */
PVD_IRQn                    = 1      /*!< PVD through EXTI Line detect Interrupt                  */
RTC_IRQn                    = 2      /*!< RTC through EXTI Line Interrupt                         */
FLASH_IRQn                  = 3      /*!< FLASH Interrupt                                         */
RCC_IRQn                    = 4      /*!< RCC Interrupt                                           */
EXTI0_1_IRQn                = 5      /*!< EXTI Line 0 and 1 Interrupts                            */
EXTI2_3_IRQn                = 6      /*!< EXTI Line 2 and 3 Interrupts                            */
EXTI4_15_IRQn               = 7      /*!< EXTI Line 4 to 15 Interrupts                            */
TS_IRQn                     = 8      /*!< Touch sense controller Interrupt                        */
DMA1_Channel1_IRQn          = 9      /*!< DMA1 Channel 1 Interrupt                                */
DMA1_Channel2_3_IRQn        = 10     /*!< DMA1 Channel 2 and Channel 3 Interrupts                 */
DMA1_Channel4_5_IRQn        = 11     /*!< DMA1 Channel 4 and Channel 5 Interrupts                 */
ADC1_COMP_IRQn              = 12     /*!< ADC1 COMP1 and COMP2 Interrupts                        */
TIM1_BRK_UP_TRG_COM_IRQn    = 13     /*!< TIM1 Break Update Trigger and Commutation Interrupts  */
TIM1_CC_IRQn                = 14     /*!< TIM1 Capture Compare Interrupt                          */
TIM2_IRQn                   = 15     /*!< TIM2 Interrupt                                          */
TIM3_IRQn                   = 16     /*!< TIM3 Interrupt                                          */
TIM6_DAC_IRQn               = 17     /*!< TIM6 and DAC Interrupts                                 */
TIM14_IRQn                  = 19     /*!< TIM14 Interrupt                                         */
TIM15_IRQn                  = 20     /*!< TIM15 Interrupt                                         */
TIM16_IRQn                  = 21     /*!< TIM16 Interrupt                                         */
TIM17_IRQn                  = 22     /*!< TIM17 Interrupt                                         */
I2C1_IRQn                   = 23     /*!< I2C1 Interrupt                                          */
I2C2_IRQn                   = 24     /*!< I2C2 Interrupt                                          */
SPI1_IRQn                   = 25     /*!< SPI1 Interrupt                                          */
SPI2_IRQn                   = 26     /*!< SPI2 Interrupt                                          */
USART1_IRQn                 = 27     /*!< USART1 Interrupt                                        */
USART2_IRQn                 = 28     /*!< USART2 Interrupt                                        */
CEC_IRQn                    = 30      /*!< CEC Interrupt                                           */
#elif defined (STM32F031)
WWDG_IRQn                   = 0      /*!< Window WatchDog Interrupt                               */
PVD_IRQn                    = 1      /*!< PVD through EXTI Line detect Interrupt                  */
RTC_IRQn                    = 2      /*!< RTC through EXTI Line Interrupt                         */
FLASH_IRQn                  = 3      /*!< FLASH Interrupt                                         */
RCC_IRQn                    = 4      /*!< RCC Interrupt                                           */
EXTI0_1_IRQn                = 5      /*!< EXTI Line 0 and 1 Interrupts                            */
EXTI2_3_IRQn                = 6      /*!< EXTI Line 2 and 3 Interrupts                            */
EXTI4_15_IRQn               = 7      /*!< EXTI Line 4 to 15 Interrupts                            */
DMA1_Channel1_IRQn          = 9      /*!< DMA1 Channel 1 Interrupt                                */
DMA1_Channel2_3_IRQn        = 10     /*!< DMA1 Channel 2 and Channel 3 Interrupts                 */
DMA1_Channel4_5_IRQn        = 11     /*!< DMA1 Channel 4 and Channel 5 Interrupts                 */
ADC1_IRQn                   = 12     /*!< ADC1 Interrupt                                          */
TIM1_BRK_UP_TRG_COM_IRQn    = 13     /*!< TIM1 Break Update Trigger and Commutation Interrupts  */
TIM1_CC_IRQn                = 14     /*!< TIM1 Capture Compare Interrupt                          */
TIM2_IRQn                   = 15     /*!< TIM2 Interrupt                                          */
TIM3_IRQn                   = 16     /*!< TIM3 Interrupt                                          */
TIM14_IRQn                  = 19     /*!< TIM14 Interrupt                                         */
TIM16_IRQn                  = 21     /*!< TIM16 Interrupt                                         */
TIM17_IRQn                  = 22     /*!< TIM17 Interrupt                                         */
I2C1_IRQn                   = 23     /*!< I2C1 Interrupt                                          */
SPI1_IRQn                   = 25     /*!< SPI1 Interrupt                                          */
USART1_IRQn                 = 27      /*!< USART1 Interrupt                                        */
#elif defined (STM32F030)
WWDG_IRQn                   = 0      /*!< Window WatchDog Interrupt                               */
RTC_IRQn                    = 2      /*!< RTC through EXTI Line Interrupt                         */
FLASH_IRQn                  = 3      /*!< FLASH Interrupt                                         */
RCC_IRQn                    = 4      /*!< RCC Interrupt                                           */
EXTI0_1_IRQn                = 5      /*!< EXTI Line 0 and 1 Interrupts                            */
EXTI2_3_IRQn                = 6      /*!< EXTI Line 2 and 3 Interrupts                            */
EXTI4_15_IRQn               = 7      /*!< EXTI Line 4 to 15 Interrupts                            */
DMA1_Channel1_IRQn          = 9      /*!< DMA1 Channel 1 Interrupt                                */
DMA1_Channel2_3_IRQn        = 10     /*!< DMA1 Channel 2 and Channel 3 Interrupts                 */
DMA1_Channel4_5_IRQn        = 11     /*!< DMA1 Channel 4 and Channel 5 Interrupts                 */
ADC1_IRQn                   = 12     /*!< ADC1 Interrupt                                          */
TIM1_BRK_UP_TRG_COM_IRQn    = 13     /*!< TIM1 Break Update Trigger and Commutation Interrupts  */
TIM1_CC_IRQn                = 14     /*!< TIM1 Capture Compare Interrupt                          */
TIM3_IRQn                   = 16     /*!< TIM3 Interrupt                                          */
TIM14_IRQn                  = 19     /*!< TIM14 Interrupt                                         */
TIM15_IRQn                  = 20     /*!< TIM15 Interrupt                                         */
TIM16_IRQn                  = 21     /*!< TIM16 Interrupt                                         */
TIM17_IRQn                  = 22     /*!< TIM17 Interrupt                                         */
I2C1_IRQn                   = 23     /*!< I2C1 Interrupt                                          */
I2C2_IRQn                   = 24     /*!< I2C2 Interrupt                                          */
SPI1_IRQn                   = 25     /*!< SPI1 Interrupt                                          */
SPI2_IRQn                   = 26     /*!< SPI2 Interrupt                                          */
USART1_IRQn                 = 27     /*!< USART1 Interrupt                                        */
USART2_IRQn                 = 28      /*!< USART2 Interrupt                                        */
#elif defined (STM32F072)
WWDG_IRQn                   = 0      /*!< Window WatchDog Interrupt                                     */
PVD_VDDIO2_IRQn             = 1      /*!< PVD and VDDIO2 supply comparator through EXTI Line detect Interrupt */
RTC_IRQn                    = 2      /*!< RTC through EXTI Line Interrupt                               */
FLASH_IRQn                  = 3      /*!< FLASH Interrupt                                               */
RCC_CRS_IRQn                = 4      /*!< RCC and CRS Interrupts                                        */
EXTI0_1_IRQn                = 5      /*!< EXTI Line 0 and 1 Interrupts                                  */
EXTI2_3_IRQn                = 6      /*!< EXTI Line 2 and 3 Interrupts                                  */
EXTI4_15_IRQn               = 7      /*!< EXTI Line 4 to 15 Interrupts                                  */
TSC_IRQn                    = 8      /*!< TSC Interrupt                                                 */
DMA1_Channel1_IRQn          = 9      /*!< DMA1 Channel 1 Interrupt                                      */
DMA1_Channel2_3_IRQn        = 10     /*!< DMA1 Channel 2 and Channel 3 Interrupts                       */
DMA1_Channel4_5_6_7_IRQn    = 11     /*!< DMA1 Channel 4 Channel 5 Channel 6 and Channel 7 Interrupts */
ADC1_COMP_IRQn              = 12     /*!< ADC1 COMP1 and COMP2 Interrupts                              */
TIM1_BRK_UP_TRG_COM_IRQn    = 13     /*!< TIM1 Break Update Trigger and Commutation Interrupts        */
TIM1_CC_IRQn                = 14     /*!< TIM1 Capture Compare Interrupt                                */
TIM2_IRQn                   = 15     /*!< TIM2 Interrupt                                                */
TIM3_IRQn                   = 16     /*!< TIM3 Interrupt                                                */
TIM6_DAC_IRQn               = 17     /*!< TIM6 and DAC Interrupts                                       */
TIM7_IRQn                   = 18     /*!< TIM7 Interrupts                                               */
TIM14_IRQn                  = 19     /*!< TIM14 Interrupt                                               */
TIM15_IRQn                  = 20     /*!< TIM15 Interrupt                                               */
TIM16_IRQn                  = 21     /*!< TIM16 Interrupt                                               */
TIM17_IRQn                  = 22     /*!< TIM17 Interrupt                                               */
I2C1_IRQn                   = 23     /*!< I2C1 Interrupt                                                */
I2C2_IRQn                   = 24     /*!< I2C2 Interrupt                                                */
SPI1_IRQn                   = 25     /*!< SPI1 Interrupt                                                */
SPI2_IRQn                   = 26     /*!< SPI2 Interrupt                                                */
USART1_IRQn                 = 27     /*!< USART1 Interrupt                                              */
USART2_IRQn                 = 28     /*!< USART2 Interrupt                                              */
USART3_4_IRQn               = 29     /*!< USART3 and USART4 Interrupts                                  */
CEC_CAN_IRQn                = 30     /*!< CEC and CAN Interrupts                                        */
USB_IRQn                    = 31      /*!< USB Low Priority global Interrupt                             */
#elif defined (STM32F042)
WWDG_IRQn                   = 0      /*!< Window WatchDog Interrupt                                     */
PVD_VDDIO2_IRQn             = 1      /*!< PVD and VDDIO2 supply comparator through EXTI Line detect Interrupt */
RTC_IRQn                    = 2      /*!< RTC through EXTI Line Interrupt                               */
FLASH_IRQn                  = 3      /*!< FLASH Interrupt                                               */
RCC_CRS_IRQn                = 4      /*!< RCC and CRS Interrupts                                        */
EXTI0_1_IRQn                = 5      /*!< EXTI Line 0 and 1 Interrupts                                  */
EXTI2_3_IRQn                = 6      /*!< EXTI Line 2 and 3 Interrupts                                  */
EXTI4_15_IRQn               = 7      /*!< EXTI Line 4 to 15 Interrupts                                  */
TSC_IRQn                    = 8      /*!< TSC Interrupt                                                 */
DMA1_Channel1_IRQn          = 9      /*!< DMA1 Channel 1 Interrupt                                      */
DMA1_Channel2_3_IRQn        = 10     /*!< DMA1 Channel 2 and Channel 3 Interrupts                       */
DMA1_Channel4_5_IRQn        = 11     /*!< DMA1 Channel 4 Channel 5 Interrupts                          */
ADC1_IRQn                   = 12     /*!< ADC1 Interrupts                                               */
TIM1_BRK_UP_TRG_COM_IRQn    = 13     /*!< TIM1 Break Update Trigger and Commutation Interrupts        */
TIM1_CC_IRQn                = 14     /*!< TIM1 Capture Compare Interrupt                                */
TIM2_IRQn                   = 15     /*!< TIM2 Interrupt                                                */
TIM3_IRQn                   = 16     /*!< TIM3 Interrupt                                                */
TIM14_IRQn                  = 19     /*!< TIM14 Interrupt                                               */
TIM16_IRQn                  = 21     /*!< TIM16 Interrupt                                               */
TIM17_IRQn                  = 22     /*!< TIM17 Interrupt                                               */
I2C1_IRQn                   = 23     /*!< I2C1 Interrupt                                                */
SPI1_IRQn                   = 25     /*!< SPI1 Interrupt                                                */
SPI2_IRQn                   = 26     /*!< SPI2 Interrupt                                                */
USART1_IRQn                 = 27     /*!< USART1 Interrupt                                              */
USART2_IRQn                 = 28     /*!< USART2 Interrupt                                              */
CEC_CAN_IRQn                = 30     /*!< CEC and CAN Interrupts                                        */
USB_IRQn                    = 31      /*!< USB Low Priority global Interrupt                             */
#endif /* STM32F051 */

/**
  * @}
  */


/** @addtogroup Exported_types
  * @{
  */

RESET = 0
SET = !RESET

DISABLE = 0
ENABLE = !DISABLE
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

ERROR = 0
SUCCESS = !ERROR

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Analog to Digital Converter
  */

#define ADC_ISR_OFFSET          0x0000    /*!< ADC Interrupt and Status register,                          Address offset:0x00 */
#define ADC_IER_OFFSET          0x0004    /*!< ADC Interrupt Enable register,                              Address offset:0x04 */
#define ADC_CR_OFFSET           0x0008    /*!< ADC Control register,                                       Address offset:0x08 */
#define ADC_CFGR1_OFFSET        0x000C    /*!< ADC Configuration register 1,                               Address offset:0x0C */
#define ADC_CFGR2_OFFSET        0x0010    /*!< ADC Configuration register 2,                               Address offset:0x10 */
#define ADC_SMPR_OFFSET         0x0014    /*!< ADC Sampling time register,                                 Address offset:0x14 */
#define ADC_RESERVED1_OFFSET    0x0018    /*!< Reserved,                                                                  0x18 */
#define ADC_RESERVED2_OFFSET    0x001C    /*!< Reserved,                                                                  0x1C */
#define ADC_TR_OFFSET           0x0020    /*!< ADC watchdog threshold register,                            Address offset:0x20 */
#define ADC_RESERVED3_OFFSET    0x0024    /*!< Reserved,                                                                  0x24 */
#define ADC_CHSELR_OFFSET       0x0028    /*!< ADC channel selection register,                             Address offset:0x28 */
#define ADC_RESERVED4_OFFSET    0x002C    /*!< Reserved,                                                                  0x2C */
#define ADC_DR_OFFSET           0x0040    /*!< ADC data register,                                          Address offset:0x40 */

#define ADC_Common_CCR_OFFSET    0x0000


/**
  * @brief Controller Area Network TxMailBox
  */
#define CAN_TxMailBox_TIR_OFFSET     0x0000    /*!< CAN TX mailbox identifier register */
#define CAN_TxMailBox_TDTR_OFFSET    0x0004    /*!< CAN mailbox data length control and time stamp register */
#define CAN_TxMailBox_TDLR_OFFSET    0x0008    /*!< CAN mailbox data low register */
#define CAN_TxMailBox_TDHR_OFFSET    0x000C    /*!< CAN mailbox data high register */

/**
  * @brief Controller Area Network FIFOMailBox
  */
#define CAN_FIFOMailBox_RIR_OFFSET     0x0000    /*!< CAN receive FIFO mailbox identifier register */
#define CAN_FIFOMailBox_RDTR_OFFSET    0x0004    /*!< CAN receive FIFO mailbox data length control and time stamp register */
#define CAN_FIFOMailBox_RDLR_OFFSET    0x0008    /*!< CAN receive FIFO mailbox data low register */
#define CAN_FIFOMailBox_RDHR_OFFSET    0x000C    /*!< CAN receive FIFO mailbox data high register */

/**
  * @brief Controller Area Network FilterRegister
  */
#define CAN_FilterRegister_FR1_OFFSET    0x0000    /*!< CAN Filter bank register 1 */
#define CAN_FilterRegister_FR2_OFFSET    0x0004    /*!< CAN Filter bank register 1 */

/**
  * @brief Controller Area Network
  */
#define CAN_MCR_OFFSET                0x0000    /*!< CAN master control register,         Address offset: 0x00          */
#define CAN_MSR_OFFSET                0x0004    /*!< CAN master status register,          Address offset: 0x04          */
#define CAN_TSR_OFFSET                0x0008    /*!< CAN transmit status register,        Address offset: 0x08          */
#define CAN_RF0R_OFFSET               0x000C    /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
#define CAN_RF1R_OFFSET               0x0010    /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
#define CAN_IER_OFFSET                0x0014    /*!< CAN interrupt enable register,       Address offset: 0x14          */
#define CAN_ESR_OFFSET                0x0018    /*!< CAN error status register,           Address offset: 0x18          */
#define CAN_BTR_OFFSET                0x001C    /*!< CAN bit timing register,             Address offset: 0x1C          */
#define CAN_RESERVED0_OFFSET          0x0020    /*!< Reserved, 0x020 - 0x17F                                            */
#define CAN_sTxMailBox_OFFSET         0x0180    /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
#define CAN_sFIFOMailBox_OFFSET       0x01B0    /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
#define CAN_RESERVED1_OFFSET          0x01D0    /*!< Reserved, 0x1D0 - 0x1FF                                            */
#define CAN_FMR_OFFSET                0x0200    /*!< CAN filter master register,          Address offset: 0x200         */
#define CAN_FM1R_OFFSET               0x0204    /*!< CAN filter mode register,            Address offset: 0x204         */
#define CAN_RESERVED2_OFFSET          0x0208    /*!< Reserved, 0x208                                                    */
#define CAN_FS1R_OFFSET               0x020C    /*!< CAN filter scale register,           Address offset: 0x20C         */
#define CAN_RESERVED3_OFFSET          0x0210    /*!< Reserved, 0x210                                                    */
#define CAN_FFA1R_OFFSET              0x0214    /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
#define CAN_RESERVED4_OFFSET          0x0218    /*!< Reserved, 0x218                                                    */
#define CAN_FA1R_OFFSET               0x021C    /*!< CAN filter activation register,      Address offset: 0x21C         */
#define CAN_RESERVED5_OFFSET          0x0220    /*!< Reserved, 0x220-0x23F                                              */
#define CAN_sFilterRegister_OFFSET    0x0240    /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */

/**
  * @brief HDMI-CEC
  */

#define CEC_CR_OFFSET      0x0000    /*!< CEC control register,                                       Address offset:0x00 */
#define CEC_CFGR_OFFSET    0x0004    /*!< CEC configuration register,                                 Address offset:0x04 */
#define CEC_TXDR_OFFSET    0x0008    /*!< CEC Tx data register ,                                      Address offset:0x08 */
#define CEC_RXDR_OFFSET    0x000C    /*!< CEC Rx Data Register,                                       Address offset:0x0C */
#define CEC_ISR_OFFSET     0x0010    /*!< CEC Interrupt and Status Register,                          Address offset:0x10 */
#define CEC_IER_OFFSET     0x0014    /*!< CEC interrupt enable register,                              Address offset:0x14 */

/**
  * @brief Comparator
  */

#define COMP_CSR_OFFSET    0x0000    /*!< COMP comparator control and status register, Address offset: 0x1C */


/**
  * @brief CRC calculation unit
  */

#define CRC_DR_OFFSET           0x0000    /*!< CRC Data register,                           Address offset: 0x00 */
#define CRC_IDR_OFFSET          0x0004    /*!< CRC Independent data register,               Address offset: 0x04 */
#define CRC_RESERVED0_OFFSET    0x0005    /*!< Reserved,                                                    0x05 */
#define CRC_RESERVED1_OFFSET    0x0006    /*!< Reserved,                                                    0x06 */
#define CRC_CR_OFFSET           0x0008    /*!< CRC Control register,                        Address offset: 0x08 */
#define CRC_RESERVED2_OFFSET    0x000C    /*!< Reserved,                                                    0x0C */
#define CRC_INIT_OFFSET         0x0010    /*!< Initial CRC value register,                  Address offset: 0x10 */
#define CRC_POL_OFFSET          0x0014    /*!< CRC polynomial register,                     Address offset: 0x14 */

/**
  * @brief Clock Recovery System
  */
#define CRS_CR_OFFSET      0x0000    /*!< CRS ccontrol register,              Address offset: 0x00 */
#define CRS_CFGR_OFFSET    0x0004    /*!< CRS configuration register,         Address offset: 0x04 */
#define CRS_ISR_OFFSET     0x0008    /*!< CRS interrupt and status register,  Address offset: 0x08 */
#define CRS_ICR_OFFSET     0x000C    /*!< CRS interrupt flag clear register,  Address offset: 0x0C */

/**
  * @brief Digital to Analog Converter
  */

#define DAC_CR_OFFSET         0x0000    /*!< DAC control register,                                    Address offset: 0x00 */
#define DAC_SWTRIGR_OFFSET    0x0004    /*!< DAC software trigger register,                           Address offset: 0x04 */
#define DAC_DHR12R1_OFFSET    0x0008    /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
#define DAC_DHR12L1_OFFSET    0x000C    /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
#define DAC_DHR8R1_OFFSET     0x0010    /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
#define DAC_DHR12R2_OFFSET    0x0014    /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
#define DAC_DHR12L2_OFFSET    0x0018    /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
#define DAC_DHR8R2_OFFSET     0x001C    /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
#define DAC_DHR12RD_OFFSET    0x0020    /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
#define DAC_DHR12LD_OFFSET    0x0024    /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
#define DAC_DHR8RD_OFFSET     0x0028    /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
#define DAC_DOR1_OFFSET       0x002C    /*!< DAC channel1 data output register,                       Address offset: 0x2C */
#define DAC_DOR2_OFFSET       0x0030    /*!< DAC channel2 data output register,                       Address offset: 0x30 */
#define DAC_SR_OFFSET         0x0034    /*!< DAC status register,                                     Address offset: 0x34 */

/**
  * @brief Debug MCU
  */

#define DBGMCU_IDCODE_OFFSET    0x0000    /*!< MCU device ID code,                          Address offset: 0x00 */
#define DBGMCU_CR_OFFSET        0x0004    /*!< Debug MCU configuration register,            Address offset: 0x04 */
#define DBGMCU_APB1FZ_OFFSET    0x0008    /*!< Debug MCU APB1 freeze register,              Address offset: 0x08 */
#define DBGMCU_APB2FZ_OFFSET    0x000C    /*!< Debug MCU APB2 freeze register,              Address offset: 0x0C */

/**
  * @brief DMA Controller
  */

#define DMA_Channel_CCR_OFFSET      0x0000    /*!< DMA channel x configuration register                                           */
#define DMA_Channel_CNDTR_OFFSET    0x0004    /*!< DMA channel x number of data register                                          */
#define DMA_Channel_CPAR_OFFSET     0x0008    /*!< DMA channel x peripheral address register                                      */
#define DMA_Channel_CMAR_OFFSET     0x000C    /*!< DMA channel x memory address register                                          */

#define DMA_ISR_OFFSET     0x0000    /*!< DMA interrupt status register,                            Address offset: 0x00 */
#define DMA_IFCR_OFFSET    0x0004    /*!< DMA interrupt flag clear register,                        Address offset: 0x04 */

/**
  * @brief External Interrupt/Event Controller
  */

#define EXTI_IMR_OFFSET      0x0000    /*!<EXTI Interrupt mask register,                             Address offset: 0x00 */
#define EXTI_EMR_OFFSET      0x0004    /*!<EXTI Event mask register,                                 Address offset: 0x04 */
#define EXTI_RTSR_OFFSET     0x0008    /*!<EXTI Rising trigger selection register ,                  Address offset: 0x08 */
#define EXTI_FTSR_OFFSET     0x000C    /*!<EXTI Falling trigger selection register,                  Address offset: 0x0C */
#define EXTI_SWIER_OFFSET    0x0010    /*!<EXTI Software interrupt event register,                   Address offset: 0x10 */
#define EXTI_PR_OFFSET       0x0014    /*!<EXTI Pending register,                                    Address offset: 0x14 */

/**
  * @brief FLASH Registers
  */
#define FLASH_ACR_OFFSET         0x0000    /*!<FLASH access control register,                 Address offset: 0x00 */
#define FLASH_KEYR_OFFSET        0x0004    /*!<FLASH key register,                            Address offset: 0x04 */
#define FLASH_OPTKEYR_OFFSET     0x0008    /*!<FLASH OPT key register,                        Address offset: 0x08 */
#define FLASH_SR_OFFSET          0x000C    /*!<FLASH status register,                         Address offset: 0x0C */
#define FLASH_CR_OFFSET          0x0010    /*!<FLASH control register,                        Address offset: 0x10 */
#define FLASH_AR_OFFSET          0x0014    /*!<FLASH address register,                        Address offset: 0x14 */
#define FLASH_RESERVED_OFFSET    0x0018    /*!< Reserved,                                                     0x18 */
#define FLASH_OBR_OFFSET         0x001C    /*!<FLASH option bytes register,                   Address offset: 0x1C */
#define FLASH_WRPR_OFFSET        0x0020    /*!<FLASH option bytes register,                   Address offset: 0x20 */


/**
  * @brief Option Bytes Registers
  */
#define OB_RDP_OFFSET      0x0000    /*!< FLASH option byte Read protection,             Address offset: 0x00 */
#define OB_USER_OFFSET     0x0002    /*!< FLASH option byte user options,                Address offset: 0x02 */
#define OB_DATA0_OFFSET    0x0004    /*!< User data byte 0 (stored in FLASH_OBR[23:16]), Address offset: 0x04 */
#define OB_DATA1_OFFSET    0x0006    /*!< User data byte 1 (stored in FLASH_OBR[31:24]), Address offset: 0x06 */
#define OB_WRP0_OFFSET     0x0008    /*!< FLASH option byte write protection 0,          Address offset: 0x08 */
#define OB_WRP1_OFFSET     0x000A    /*!< FLASH option byte write protection 1,          Address offset: 0x0A */
#define OB_WRP2_OFFSET     0x000C    /*!< FLASH option byte write protection 2,          Address offset: 0x0C */
#define OB_WRP3_OFFSET     0x000E    /*!< FLASH option byte write protection 3,          Address offset: 0x0E */


/**
  * @brief General Purpose IO
  */

#define GPIO_MODER_OFFSET        0x0000    /*!< GPIO port mode register,                                  Address offset: 0x00 */
#define GPIO_OTYPER_OFFSET       0x0004    /*!< GPIO port output type register,                           Address offset: 0x04 */
#define GPIO_RESERVED0_OFFSET    0x0006    /*!< Reserved,                                                                 0x06 */
#define GPIO_OSPEEDR_OFFSET      0x0008    /*!< GPIO port output speed register,                          Address offset: 0x08 */
#define GPIO_PUPDR_OFFSET        0x000C    /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
#define GPIO_IDR_OFFSET          0x0010    /*!< GPIO port input data register,                            Address offset: 0x10 */
#define GPIO_RESERVED1_OFFSET    0x0012    /*!< Reserved,                                                                 0x12 */
#define GPIO_ODR_OFFSET          0x0014    /*!< GPIO port output data register,                           Address offset: 0x14 */
#define GPIO_RESERVED2_OFFSET    0x0016    /*!< Reserved,                                                                 0x16 */
#define GPIO_BSRR_OFFSET         0x0018    /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
#define GPIO_LCKR_OFFSET         0x001C    /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
#define GPIO_AFR_OFFSET          0x0020    /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
#define GPIO_BRR_OFFSET          0x0028    /*!< GPIO bit reset register,                                  Address offset: 0x28 */
#define GPIO_RESERVED3_OFFSET    0x002A    /*!< Reserved,                                                                 0x2A */

/**
  * @brief SysTem Configuration
  */

#define SYSCFG_CFGR1_OFFSET       0x0000    /*!< SYSCFG configuration register 1,                           Address offset: 0x00 */
#define SYSCFG_RESERVED_OFFSET    0x0004    /*!< Reserved,                                                                  0x04 */
#define SYSCFG_EXTICR_OFFSET      0x0008    /*!< SYSCFG external interrupt configuration register,     Address offset: 0x14-0x08 */
#define SYSCFG_CFGR2_OFFSET       0x0018    /*!< SYSCFG configuration register 2,                           Address offset: 0x18 */

/**
  * @brief Inter-integrated Circuit Interface
  */

#define I2C_CR1_OFFSET         0x0000    /*!< I2C Control register 1,            Address offset: 0x00 */
#define I2C_CR2_OFFSET         0x0004    /*!< I2C Control register 2,            Address offset: 0x04 */
#define I2C_OAR1_OFFSET        0x0008    /*!< I2C Own address 1 register,        Address offset: 0x08 */
#define I2C_OAR2_OFFSET        0x000C    /*!< I2C Own address 2 register,        Address offset: 0x0C */
#define I2C_TIMINGR_OFFSET     0x0010    /*!< I2C Timing register,               Address offset: 0x10 */
#define I2C_TIMEOUTR_OFFSET    0x0014    /*!< I2C Timeout register,              Address offset: 0x14 */
#define I2C_ISR_OFFSET         0x0018    /*!< I2C Interrupt and status register, Address offset: 0x18 */
#define I2C_ICR_OFFSET         0x001C    /*!< I2C Interrupt clear register,      Address offset: 0x1C */
#define I2C_PECR_OFFSET        0x0020    /*!< I2C PEC register,                  Address offset: 0x20 */
#define I2C_RXDR_OFFSET        0x0024    /*!< I2C Receive data register,         Address offset: 0x24 */
#define I2C_TXDR_OFFSET        0x0028    /*!< I2C Transmit data register,        Address offset: 0x28 */


/**
  * @brief Independent WATCHDOG
  */
#define IWDG_KR_OFFSET      0x0000    /*!< IWDG Key register,       Address offset: 0x00 */
#define IWDG_PR_OFFSET      0x0004    /*!< IWDG Prescaler register, Address offset: 0x04 */
#define IWDG_RLR_OFFSET     0x0008    /*!< IWDG Reload register,    Address offset: 0x08 */
#define IWDG_SR_OFFSET      0x000C    /*!< IWDG Status register,    Address offset: 0x0C */
#define IWDG_WINR_OFFSET    0x0010    /*!< IWDG Window register,    Address offset: 0x10 */

/**
  * @brief Power Control
  */

#define PWR_CR_OFFSET     0x0000    /*!< PWR power control register,        Address offset: 0x00 */
#define PWR_CSR_OFFSET    0x0004    /*!< PWR power control/status register, Address offset: 0x04 */


/**
  * @brief Reset and Clock Control
  */
#define RCC_CR_OFFSET          0x0000    /*!< RCC clock control register,                                  Address offset: 0x00 */
#define RCC_CFGR_OFFSET        0x0004    /*!< RCC clock configuration register,                            Address offset: 0x04 */
#define RCC_CIR_OFFSET         0x0008    /*!< RCC clock interrupt register,                                Address offset: 0x08 */
#define RCC_APB2RSTR_OFFSET    0x000C    /*!< RCC APB2 peripheral reset register,                          Address offset: 0x0C */
#define RCC_APB1RSTR_OFFSET    0x0010    /*!< RCC APB1 peripheral reset register,                          Address offset: 0x10 */
#define RCC_AHBENR_OFFSET      0x0014    /*!< RCC AHB peripheral clock register,                           Address offset: 0x14 */
#define RCC_APB2ENR_OFFSET     0x0018    /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 */
#define RCC_APB1ENR_OFFSET     0x001C    /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C */
#define RCC_BDCR_OFFSET        0x0020    /*!< RCC Backup domain control register,                          Address offset: 0x20 */
#define RCC_CSR_OFFSET         0x0024    /*!< RCC clock control & status register,                         Address offset: 0x24 */
#define RCC_AHBRSTR_OFFSET     0x0028    /*!< RCC AHB peripheral reset register,                           Address offset: 0x28 */
#define RCC_CFGR2_OFFSET       0x002C    /*!< RCC clock configuration register 2,                          Address offset: 0x2C */
#define RCC_CFGR3_OFFSET       0x0030    /*!< RCC clock configuration register 3,                          Address offset: 0x30 */
#define RCC_CR2_OFFSET         0x0034    /*!< RCC clock control register 2,                                Address offset: 0x34 */

/**
  * @brief Real-Time Clock
  */

#define RTC_TR_OFFSET           0x0000    /*!< RTC time register,                                        Address offset: 0x00 */
#define RTC_DR_OFFSET           0x0004    /*!< RTC date register,                                        Address offset: 0x04 */
#define RTC_CR_OFFSET           0x0008    /*!< RTC control register,                                     Address offset: 0x08 */
#define RTC_ISR_OFFSET          0x000C    /*!< RTC initialization and status register,                   Address offset: 0x0C */
#define RTC_PRER_OFFSET         0x0010    /*!< RTC prescaler register,                                   Address offset: 0x10 */
#define RTC_WUTR_OFFSET         0x0014    /*!< RTC wakeup timer register,(only for STM32F072 devices)    Address offset: 0x14 */
#define RTC_RESERVED1_OFFSET    0x0018    /*!< Reserved,                                                 Address offset: 0x18 */
#define RTC_ALRMAR_OFFSET       0x001C    /*!< RTC alarm A register,                                     Address offset: 0x1C */
#define RTC_RESERVED2_OFFSET    0x0020    /*!< Reserved,                                                 Address offset: 0x20 */
#define RTC_WPR_OFFSET          0x0024    /*!< RTC write protection register,                            Address offset: 0x24 */
#define RTC_SSR_OFFSET          0x0028    /*!< RTC sub second register,                                  Address offset: 0x28 */
#define RTC_SHIFTR_OFFSET       0x002C    /*!< RTC shift control register,                               Address offset: 0x2C */
#define RTC_TSTR_OFFSET         0x0030    /*!< RTC time stamp time register,                             Address offset: 0x30 */
#define RTC_TSDR_OFFSET         0x0034    /*!< RTC time stamp date register,                             Address offset: 0x34 */
#define RTC_TSSSR_OFFSET        0x0038    /*!< RTC time-stamp sub second register,                       Address offset: 0x38 */
#define RTC_CALR_OFFSET         0x003C    /*!< RTC calibration register,                                 Address offset: 0x3C */
#define RTC_TAFCR_OFFSET        0x0040    /*!< RTC tamper and alternate function configuration register, Address offset: 0x40 */
#define RTC_ALRMASSR_OFFSET     0x0044    /*!< RTC alarm A sub second register,                          Address offset: 0x44 */
#define RTC_RESERVED3_OFFSET    0x0048    /*!< Reserved,                                                 Address offset: 0x48 */
#define RTC_RESERVED4_OFFSET    0x004C    /*!< Reserved,                                                 Address offset: 0x4C */
#define RTC_BKP0R_OFFSET        0x0050    /*!< RTC backup register 0,                                    Address offset: 0x50 */
#define RTC_BKP1R_OFFSET        0x0054    /*!< RTC backup register 1,                                    Address offset: 0x54 */
#define RTC_BKP2R_OFFSET        0x0058    /*!< RTC backup register 2,                                    Address offset: 0x58 */
#define RTC_BKP3R_OFFSET        0x005C    /*!< RTC backup register 3,                                    Address offset: 0x5C */
#define RTC_BKP4R_OFFSET        0x0060    /*!< RTC backup register 4,                                    Address offset: 0x60 */

#define CAL   CALR

/**
  * @brief Serial Peripheral Interface
  */

#define SPI_CR1_OFFSET          0x0000    /*!< SPI Control register 1 (not used in I2S mode),       Address offset: 0x00 */
#define SPI_RESERVED0_OFFSET    0x0002    /*!< Reserved, 0x02                                                            */
#define SPI_CR2_OFFSET          0x0004    /*!< SPI Control register 2,                              Address offset: 0x04 */
#define SPI_RESERVED1_OFFSET    0x0006    /*!< Reserved, 0x06                                                            */
#define SPI_SR_OFFSET           0x0008    /*!< SPI Status register,                                 Address offset: 0x08 */
#define SPI_RESERVED2_OFFSET    0x000A    /*!< Reserved, 0x0A                                                            */
#define SPI_DR_OFFSET           0x000C    /*!< SPI data register,                                   Address offset: 0x0C */
#define SPI_RESERVED3_OFFSET    0x000E    /*!< Reserved, 0x0E                                                            */
#define SPI_CRCPR_OFFSET        0x0010    /*!< SPI CRC polynomial register (not used in I2S mode),  Address offset: 0x10 */
#define SPI_RESERVED4_OFFSET    0x0012    /*!< Reserved, 0x12                                                            */
#define SPI_RXCRCR_OFFSET       0x0014    /*!< SPI Rx CRC register (not used in I2S mode),          Address offset: 0x14 */
#define SPI_RESERVED5_OFFSET    0x0016    /*!< Reserved, 0x16                                                            */
#define SPI_TXCRCR_OFFSET       0x0018    /*!< SPI Tx CRC register (not used in I2S mode),          Address offset: 0x18 */
#define SPI_RESERVED6_OFFSET    0x001A    /*!< Reserved, 0x1A                                                            */
#define SPI_I2SCFGR_OFFSET      0x001C    /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
#define SPI_RESERVED7_OFFSET    0x001E    /*!< Reserved, 0x1E                                                            */
#define SPI_I2SPR_OFFSET        0x0020    /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */
#define SPI_RESERVED8_OFFSET    0x0022    /*!< Reserved, 0x22                                                            */


/**
  * @brief TIM
  */
#define TIM_CR1_OFFSET           0x0000    /*!< TIM control register 1,                      Address offset: 0x00 */
#define TIM_RESERVED0_OFFSET     0x0002    /*!< Reserved,                                                    0x02 */
#define TIM_CR2_OFFSET           0x0004    /*!< TIM control register 2,                      Address offset: 0x04 */
#define TIM_RESERVED1_OFFSET     0x0006    /*!< Reserved,                                                    0x06 */
#define TIM_SMCR_OFFSET          0x0008    /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define TIM_RESERVED2_OFFSET     0x000A    /*!< Reserved,                                                    0x0A */
#define TIM_DIER_OFFSET          0x000C    /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define TIM_RESERVED3_OFFSET     0x000E    /*!< Reserved,                                                    0x0E */
#define TIM_SR_OFFSET            0x0010    /*!< TIM status register,                         Address offset: 0x10 */
#define TIM_RESERVED4_OFFSET     0x0012    /*!< Reserved,                                                    0x12 */
#define TIM_EGR_OFFSET           0x0014    /*!< TIM event generation register,               Address offset: 0x14 */
#define TIM_RESERVED5_OFFSET     0x0016    /*!< Reserved,                                                    0x16 */
#define TIM_CCMR1_OFFSET         0x0018    /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define TIM_RESERVED6_OFFSET     0x001A    /*!< Reserved,                                                    0x1A */
#define TIM_CCMR2_OFFSET         0x001C    /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define TIM_RESERVED7_OFFSET     0x001E    /*!< Reserved,                                                    0x1E */
#define TIM_CCER_OFFSET          0x0020    /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define TIM_RESERVED8_OFFSET     0x0022    /*!< Reserved,                                                    0x22 */
#define TIM_CNT_OFFSET           0x0024    /*!< TIM counter register,                        Address offset: 0x24 */
#define TIM_PSC_OFFSET           0x0028    /*!< TIM prescaler register,                      Address offset: 0x28 */
#define TIM_RESERVED10_OFFSET    0x002A    /*!< Reserved,                                                    0x2A */
#define TIM_ARR_OFFSET           0x002C    /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define TIM_RCR_OFFSET           0x0030    /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define TIM_RESERVED12_OFFSET    0x0032    /*!< Reserved,                                                    0x32 */
#define TIM_CCR1_OFFSET          0x0034    /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define TIM_CCR2_OFFSET          0x0038    /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define TIM_CCR3_OFFSET          0x003C    /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define TIM_CCR4_OFFSET          0x0040    /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define TIM_BDTR_OFFSET          0x0044    /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define TIM_RESERVED17_OFFSET    0x0046    /*!< Reserved,                                                    0x26 */
#define TIM_DCR_OFFSET           0x0048    /*!< TIM DMA control register,                    Address offset: 0x48 */
#define TIM_RESERVED18_OFFSET    0x004A    /*!< Reserved,                                                    0x4A */
#define TIM_DMAR_OFFSET          0x004C    /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define TIM_RESERVED19_OFFSET    0x004E    /*!< Reserved,                                                    0x4E */
#define TIM_OR_OFFSET            0x0050    /*!< TIM option register,                         Address offset: 0x50 */
#define TIM_RESERVED20_OFFSET    0x0052    /*!< Reserved,                                                    0x52 */

/**
  * @brief Touch Sensing Controller (TSC)
  */
#define TSC_CR_OFFSET           0x0000    /*!< TSC control register,                                     Address offset: 0x00 */
#define TSC_IER_OFFSET          0x0004    /*!< TSC interrupt enable register,                            Address offset: 0x04 */
#define TSC_ICR_OFFSET          0x0008    /*!< TSC interrupt clear register,                             Address offset: 0x08 */
#define TSC_ISR_OFFSET          0x000C    /*!< TSC interrupt status register,                            Address offset: 0x0C */
#define TSC_IOHCR_OFFSET        0x0010    /*!< TSC I/O hysteresis control register,                      Address offset: 0x10 */
#define TSC_RESERVED1_OFFSET    0x0014    /*!< Reserved,                                                 Address offset: 0x14 */
#define TSC_IOASCR_OFFSET       0x0018    /*!< TSC I/O analog switch control register,                   Address offset: 0x18 */
#define TSC_RESERVED2_OFFSET    0x001C    /*!< Reserved,                                                 Address offset: 0x1C */
#define TSC_IOSCR_OFFSET        0x0020    /*!< TSC I/O sampling control register,                        Address offset: 0x20 */
#define TSC_RESERVED3_OFFSET    0x0024    /*!< Reserved,                                                 Address offset: 0x24 */
#define TSC_IOCCR_OFFSET        0x0028    /*!< TSC I/O channel control register,                         Address offset: 0x28 */
#define TSC_RESERVED4_OFFSET    0x002C    /*!< Reserved,                                                 Address offset: 0x2C */
#define TSC_IOGCSR_OFFSET       0x0030    /*!< TSC I/O group control status register,                    Address offset: 0x30 */
#define TSC_IOGXCR_OFFSET       0x0034    /*!< TSC I/O group x counter register,                         Address offset: 0x34-50 */

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */

#define USART_CR1_OFFSET          0x0000    /*!< USART Control register 1,                 Address offset: 0x00 */
#define USART_CR2_OFFSET          0x0004    /*!< USART Control register 2,                 Address offset: 0x04 */
#define USART_CR3_OFFSET          0x0008    /*!< USART Control register 3,                 Address offset: 0x08 */
#define USART_BRR_OFFSET          0x000C    /*!< USART Baud rate register,                 Address offset: 0x0C */
#define USART_RESERVED1_OFFSET    0x000E    /*!< Reserved, 0x0E                                                 */
#define USART_GTPR_OFFSET         0x0010    /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
#define USART_RESERVED2_OFFSET    0x0012    /*!< Reserved, 0x12                                                 */
#define USART_RTOR_OFFSET         0x0014    /*!< USART Receiver Time Out register,         Address offset: 0x14 */
#define USART_RQR_OFFSET          0x0018    /*!< USART Request register,                   Address offset: 0x18 */
#define USART_RESERVED3_OFFSET    0x001A    /*!< Reserved, 0x1A                                                 */
#define USART_ISR_OFFSET          0x001C    /*!< USART Interrupt and status register,      Address offset: 0x1C */
#define USART_ICR_OFFSET          0x0020    /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
#define USART_RDR_OFFSET          0x0024    /*!< USART Receive Data register,              Address offset: 0x24 */
#define USART_RESERVED4_OFFSET    0x0026    /*!< Reserved, 0x26                                                 */
#define USART_TDR_OFFSET          0x0028    /*!< USART Transmit Data register,             Address offset: 0x28 */
#define USART_RESERVED5_OFFSET    0x002A    /*!< Reserved, 0x2A                                                 */


/**
  * @brief Window WATCHDOG
  */
#define WWDG_CR_OFFSET     0x0000    /*!< WWDG Control register,       Address offset: 0x00 */
#define WWDG_CFR_OFFSET    0x0004    /*!< WWDG Configuration register, Address offset: 0x04 */
#define WWDG_SR_OFFSET     0x0008    /*!< WWDG Status register,        Address offset: 0x08 */


/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE            (0x08000000) /*!< FLASH base address in the alias region */
#define SRAM_BASE             (0x20000000) /*!< SRAM base address in the alias region */
#define PERIPH_BASE           (0x40000000) /*!< Peripheral base address in the alias region */

#define APBPERIPH_BASE        PERIPH_BASE
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000)

#define TIM2_BASE             (APBPERIPH_BASE + 0x00000000)
#define TIM3_BASE             (APBPERIPH_BASE + 0x00000400)
#define TIM6_BASE             (APBPERIPH_BASE + 0x00001000)
#define TIM7_BASE             (APBPERIPH_BASE + 0x00001400)
#define TIM14_BASE            (APBPERIPH_BASE + 0x00002000)
#define RTC_BASE              (APBPERIPH_BASE + 0x00002800)
#define WWDG_BASE             (APBPERIPH_BASE + 0x00002C00)
#define IWDG_BASE             (APBPERIPH_BASE + 0x00003000)
#define SPI2_BASE             (APBPERIPH_BASE + 0x00003800)
#define USART2_BASE           (APBPERIPH_BASE + 0x00004400)
#define USART3_BASE           (APBPERIPH_BASE + 0x00004800)
#define USART4_BASE           (APBPERIPH_BASE + 0x00004C00)
#define I2C1_BASE             (APBPERIPH_BASE + 0x00005400)
#define I2C2_BASE             (APBPERIPH_BASE + 0x00005800)
#define CAN_BASE              (APBPERIPH_BASE + 0x00006400)
#define CRS_BASE              (APBPERIPH_BASE + 0x00006C00)
#define PWR_BASE              (APBPERIPH_BASE + 0x00007000)
#define DAC_BASE              (APBPERIPH_BASE + 0x00007400)
#define CEC_BASE              (APBPERIPH_BASE + 0x00007800)

#define SYSCFG_BASE           (APBPERIPH_BASE + 0x00010000)
#define COMP_BASE             (APBPERIPH_BASE + 0x0001001C)
#define EXTI_BASE             (APBPERIPH_BASE + 0x00010400)
#define ADC1_BASE             (APBPERIPH_BASE + 0x00012400)
#define ADC_BASE              (APBPERIPH_BASE + 0x00012708)
#define TIM1_BASE             (APBPERIPH_BASE + 0x00012C00)
#define SPI1_BASE             (APBPERIPH_BASE + 0x00013000)
#define USART1_BASE           (APBPERIPH_BASE + 0x00013800)
#define TIM15_BASE            (APBPERIPH_BASE + 0x00014000)
#define TIM16_BASE            (APBPERIPH_BASE + 0x00014400)
#define TIM17_BASE            (APBPERIPH_BASE + 0x00014800)
#define DBGMCU_BASE           (APBPERIPH_BASE + 0x00015800)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x00000000)
#define DMA1_Channel1_BASE    (DMA1_BASE + 0x00000008)
#define DMA1_Channel2_BASE    (DMA1_BASE + 0x0000001C)
#define DMA1_Channel3_BASE    (DMA1_BASE + 0x00000030)
#define DMA1_Channel4_BASE    (DMA1_BASE + 0x00000044)
#define DMA1_Channel5_BASE    (DMA1_BASE + 0x00000058)
#define DMA1_Channel6_BASE    (DMA1_BASE + 0x0000006C)
#define DMA1_Channel7_BASE    (DMA1_BASE + 0x00000080)

#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00002000) /*!< FLASH registers base address */
#define OB_BASE               (0x1FFFF800)        /*!< FLASH Option Bytes base address */
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000)
#define TSC_BASE              (AHBPERIPH_BASE + 0x00004000)

#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x00000000)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x00000400)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x00000800)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x00000C00)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x00001000)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x00001400)

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */

#define TIM2                (TIM2_BASE)
#define _TIM2_CR1           (TIM2 + TIM_CR1_OFFSET)           /*!< TIM control register 1,                      Address offset: 0x00 */
#define _TIM2_CR2           (TIM2 + TIM_CR2_OFFSET)           /*!< TIM control register 2,                      Address offset: 0x04 */
#define _TIM2_SMCR          (TIM2 + TIM_SMCR_OFFSET)          /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define _TIM2_DIER          (TIM2 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define _TIM2_SR            (TIM2 + TIM_SR_OFFSET)            /*!< TIM status register,                         Address offset: 0x10 */
#define _TIM2_EGR           (TIM2 + TIM_EGR_OFFSET)           /*!< TIM event generation register,               Address offset: 0x14 */
#define _TIM2_CCMR1         (TIM2 + TIM_CCMR1_OFFSET)         /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define _TIM2_CCMR2         (TIM2 + TIM_CCMR2_OFFSET)         /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define _TIM2_CCER          (TIM2 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define _TIM2_CNT           (TIM2 + TIM_CNT_OFFSET)           /*!< TIM counter register,                        Address offset: 0x24 */
#define _TIM2_PSC           (TIM2 + TIM_PSC_OFFSET)           /*!< TIM prescaler register,                      Address offset: 0x28 */
#define _TIM2_ARR           (TIM2 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define _TIM2_RCR           (TIM2 + TIM_RCR_OFFSET)           /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define _TIM2_CCR1          (TIM2 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define _TIM2_CCR2          (TIM2 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define _TIM2_CCR3          (TIM2 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define _TIM2_CCR4          (TIM2 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define _TIM2_BDTR          (TIM2 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define _TIM2_DCR           (TIM2 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,                    Address offset: 0x48 */
#define _TIM2_DMAR          (TIM2 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define _TIM2_OR            (TIM2 + TIM_OR_OFFSET)            /*!< TIM option register,                         Address offset: 0x50 */

#define TIM3                (TIM3_BASE)
#define _TIM3_CR1           (TIM3 + TIM_CR1_OFFSET)           /*!< TIM control register 1,                      Address offset: 0x00 */
#define _TIM3_CR2           (TIM3 + TIM_CR2_OFFSET)           /*!< TIM control register 2,                      Address offset: 0x04 */
#define _TIM3_SMCR          (TIM3 + TIM_SMCR_OFFSET)          /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define _TIM3_DIER          (TIM3 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define _TIM3_SR            (TIM3 + TIM_SR_OFFSET)            /*!< TIM status register,                         Address offset: 0x10 */
#define _TIM3_EGR           (TIM3 + TIM_EGR_OFFSET)           /*!< TIM event generation register,               Address offset: 0x14 */
#define _TIM3_CCMR1         (TIM3 + TIM_CCMR1_OFFSET)         /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define _TIM3_CCMR2         (TIM3 + TIM_CCMR2_OFFSET)         /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define _TIM3_CCER          (TIM3 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define _TIM3_CNT           (TIM3 + TIM_CNT_OFFSET)           /*!< TIM counter register,                        Address offset: 0x24 */
#define _TIM3_PSC           (TIM3 + TIM_PSC_OFFSET)           /*!< TIM prescaler register,                      Address offset: 0x28 */
#define _TIM3_ARR           (TIM3 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define _TIM3_RCR           (TIM3 + TIM_RCR_OFFSET)           /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define _TIM3_CCR1          (TIM3 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define _TIM3_CCR2          (TIM3 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define _TIM3_CCR3          (TIM3 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define _TIM3_CCR4          (TIM3 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define _TIM3_BDTR          (TIM3 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define _TIM3_DCR           (TIM3 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,                    Address offset: 0x48 */
#define _TIM3_DMAR          (TIM3 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define _TIM3_OR            (TIM3 + TIM_OR_OFFSET)            /*!< TIM option register,                         Address offset: 0x50 */

#define TIM6                (TIM6_BASE)
#define _TIM6_CR1           (TIM6 + TIM_CR1_OFFSET)           /*!< TIM control register 1,                      Address offset: 0x00 */
#define _TIM6_CR2           (TIM6 + TIM_CR2_OFFSET)           /*!< TIM control register 2,                      Address offset: 0x04 */
#define _TIM6_SMCR          (TIM6 + TIM_SMCR_OFFSET)          /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define _TIM6_DIER          (TIM6 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define _TIM6_SR            (TIM6 + TIM_SR_OFFSET)            /*!< TIM status register,                         Address offset: 0x10 */
#define _TIM6_EGR           (TIM6 + TIM_EGR_OFFSET)           /*!< TIM event generation register,               Address offset: 0x14 */
#define _TIM6_CCMR1         (TIM6 + TIM_CCMR1_OFFSET)         /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define _TIM6_CCMR2         (TIM6 + TIM_CCMR2_OFFSET)         /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define _TIM6_CCER          (TIM6 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define _TIM6_CNT           (TIM6 + TIM_CNT_OFFSET)           /*!< TIM counter register,                        Address offset: 0x24 */
#define _TIM6_PSC           (TIM6 + TIM_PSC_OFFSET)           /*!< TIM prescaler register,                      Address offset: 0x28 */
#define _TIM6_ARR           (TIM6 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define _TIM6_RCR           (TIM6 + TIM_RCR_OFFSET)           /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define _TIM6_CCR1          (TIM6 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define _TIM6_CCR2          (TIM6 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define _TIM6_CCR3          (TIM6 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define _TIM6_CCR4          (TIM6 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define _TIM6_BDTR          (TIM6 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define _TIM6_DCR           (TIM6 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,                    Address offset: 0x48 */
#define _TIM6_DMAR          (TIM6 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define _TIM6_OR            (TIM6 + TIM_OR_OFFSET)            /*!< TIM option register,                         Address offset: 0x50 */

#define TIM7                (TIM7_BASE)
#define _TIM7_CR1           (TIM7 + TIM_CR1_OFFSET)           /*!< TIM control register 1,                      Address offset: 0x00 */
#define _TIM7_CR2           (TIM7 + TIM_CR2_OFFSET)           /*!< TIM control register 2,                      Address offset: 0x04 */
#define _TIM7_SMCR          (TIM7 + TIM_SMCR_OFFSET)          /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define _TIM7_DIER          (TIM7 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define _TIM7_SR            (TIM7 + TIM_SR_OFFSET)            /*!< TIM status register,                         Address offset: 0x10 */
#define _TIM7_EGR           (TIM7 + TIM_EGR_OFFSET)           /*!< TIM event generation register,               Address offset: 0x14 */
#define _TIM7_CCMR1         (TIM7 + TIM_CCMR1_OFFSET)         /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define _TIM7_CCMR2         (TIM7 + TIM_CCMR2_OFFSET)         /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define _TIM7_CCER          (TIM7 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define _TIM7_CNT           (TIM7 + TIM_CNT_OFFSET)           /*!< TIM counter register,                        Address offset: 0x24 */
#define _TIM7_PSC           (TIM7 + TIM_PSC_OFFSET)           /*!< TIM prescaler register,                      Address offset: 0x28 */
#define _TIM7_ARR           (TIM7 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define _TIM7_RCR           (TIM7 + TIM_RCR_OFFSET)           /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define _TIM7_CCR1          (TIM7 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define _TIM7_CCR2          (TIM7 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define _TIM7_CCR3          (TIM7 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define _TIM7_CCR4          (TIM7 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define _TIM7_BDTR          (TIM7 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define _TIM7_DCR           (TIM7 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,                    Address offset: 0x48 */
#define _TIM7_DMAR          (TIM7 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define _TIM7_OR            (TIM7 + TIM_OR_OFFSET)            /*!< TIM option register,                         Address offset: 0x50 */

#define TIM14               (TIM14_BASE)
#define _TIM14_CR1           (TIM14 + TIM_CR1_OFFSET)           /*!< TIM control register 1,                      Address offset: 0x00 */
#define _TIM14_CR2           (TIM14 + TIM_CR2_OFFSET)           /*!< TIM control register 2,                      Address offset: 0x04 */
#define _TIM14_SMCR          (TIM14 + TIM_SMCR_OFFSET)          /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define _TIM14_DIER          (TIM14 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define _TIM14_SR            (TIM14 + TIM_SR_OFFSET)            /*!< TIM status register,                         Address offset: 0x10 */
#define _TIM14_EGR           (TIM14 + TIM_EGR_OFFSET)           /*!< TIM event generation register,               Address offset: 0x14 */
#define _TIM14_CCMR1         (TIM14 + TIM_CCMR1_OFFSET)         /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define _TIM14_CCMR2         (TIM14 + TIM_CCMR2_OFFSET)         /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define _TIM14_CCER          (TIM14 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define _TIM14_CNT           (TIM14 + TIM_CNT_OFFSET)           /*!< TIM counter register,                        Address offset: 0x24 */
#define _TIM14_PSC           (TIM14 + TIM_PSC_OFFSET)           /*!< TIM prescaler register,                      Address offset: 0x28 */
#define _TIM14_ARR           (TIM14 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define _TIM14_RCR           (TIM14 + TIM_RCR_OFFSET)           /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define _TIM14_CCR1          (TIM14 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define _TIM14_CCR2          (TIM14 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define _TIM14_CCR3          (TIM14 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define _TIM14_CCR4          (TIM14 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define _TIM14_BDTR          (TIM14 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define _TIM14_DCR           (TIM14 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,                    Address offset: 0x48 */
#define _TIM14_DMAR          (TIM14 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define _TIM14_OR            (TIM14 + TIM_OR_OFFSET)            /*!< TIM option register,                         Address offset: 0x50 */

#define RTC                 (RTC_BASE)
#define _RTC_TR           (RTC + RTC_TR_OFFSET)           /*!< RTC time register,                                        Address offset: 0x00 */
#define _RTC_DR           (RTC + RTC_DR_OFFSET)           /*!< RTC date register,                                        Address offset: 0x04 */
#define _RTC_CR           (RTC + RTC_CR_OFFSET)           /*!< RTC control register,                                     Address offset: 0x08 */
#define _RTC_ISR          (RTC + RTC_ISR_OFFSET)          /*!< RTC initialization and status register,                   Address offset: 0x0C */
#define _RTC_PRER         (RTC + RTC_PRER_OFFSET)         /*!< RTC prescaler register,                                   Address offset: 0x10 */
#define _RTC_WUTR         (RTC + RTC_WUTR_OFFSET)         /*!< RTC wakeup timer register,(only for STM32F072 devices)    Address offset: 0x14 */
#define _RTC_ALRMAR       (RTC + RTC_ALRMAR_OFFSET)       /*!< RTC alarm A register,                                     Address offset: 0x1C */
#define _RTC_WPR          (RTC + RTC_WPR_OFFSET)          /*!< RTC write protection register,                            Address offset: 0x24 */
#define _RTC_SSR          (RTC + RTC_SSR_OFFSET)          /*!< RTC sub second register,                                  Address offset: 0x28 */
#define _RTC_SHIFTR       (RTC + RTC_SHIFTR_OFFSET)       /*!< RTC shift control register,                               Address offset: 0x2C */
#define _RTC_TSTR         (RTC + RTC_TSTR_OFFSET)         /*!< RTC time stamp time register,                             Address offset: 0x30 */
#define _RTC_TSDR         (RTC + RTC_TSDR_OFFSET)         /*!< RTC time stamp date register,                             Address offset: 0x34 */
#define _RTC_TSSSR        (RTC + RTC_TSSSR_OFFSET)        /*!< RTC time-stamp sub second register,                       Address offset: 0x38 */
#define _RTC_CALR         (RTC + RTC_CALR_OFFSET)         /*!< RTC calibration register,                                 Address offset: 0x3C */
#define _RTC_TAFCR        (RTC + RTC_TAFCR_OFFSET)        /*!< RTC tamper and alternate function configuration register, Address offset: 0x40 */
#define _RTC_ALRMASSR     (RTC + RTC_ALRMASSR_OFFSET)     /*!< RTC alarm A sub second register,                          Address offset: 0x44 */
#define _RTC_BKP0R        (RTC + RTC_BKP0R_OFFSET)        /*!< RTC backup register 0,                                    Address offset: 0x50 */
#define _RTC_BKP1R        (RTC + RTC_BKP1R_OFFSET)        /*!< RTC backup register 1,                                    Address offset: 0x54 */
#define _RTC_BKP2R        (RTC + RTC_BKP2R_OFFSET)        /*!< RTC backup register 2,                                    Address offset: 0x58 */
#define _RTC_BKP3R        (RTC + RTC_BKP3R_OFFSET)        /*!< RTC backup register 3,                                    Address offset: 0x5C */
#define _RTC_BKP4R        (RTC + RTC_BKP4R_OFFSET)        /*!< RTC backup register 4,                                    Address offset: 0x60 */

#define WWDG                (WWDG_BASE)
#define _WWDG_CR     (WWDG + WWDG_CR_OFFSET)     /*!< WWDG Control register,       Address offset: 0x00 */
#define _WWDG_CFR    (WWDG + WWDG_CFR_OFFSET)    /*!< WWDG Configuration register, Address offset: 0x04 */
#define _WWDG_SR     (WWDG + WWDG_SR_OFFSET)     /*!< WWDG Status register,        Address offset: 0x08 */

#define IWDG                (IWDG_BASE)
#define _IWDG_KR      (IWDG + IWDG_KR_OFFSET)      /*!< IWDG Key register,       Address offset: 0x00 */
#define _IWDG_PR      (IWDG + IWDG_PR_OFFSET)      /*!< IWDG Prescaler register, Address offset: 0x04 */
#define _IWDG_RLR     (IWDG + IWDG_RLR_OFFSET)     /*!< IWDG Reload register,    Address offset: 0x08 */
#define _IWDG_SR      (IWDG + IWDG_SR_OFFSET)      /*!< IWDG Status register,    Address offset: 0x0C */
#define _IWDG_WINR    (IWDG + IWDG_WINR_OFFSET)    /*!< IWDG Window register,    Address offset: 0x10 */

#define SPI2                (SPI2_BASE)
#define _SPI2_CR1          (SPI2 + SPI_CR1_OFFSET)          /*!< SPI Control register 1 (not used in I2S mode),       Address offset: 0x00 */
#define _SPI2_CR2          (SPI2 + SPI_CR2_OFFSET)          /*!< SPI Control register 2,                              Address offset: 0x04 */
#define _SPI2_SR           (SPI2 + SPI_SR_OFFSET)           /*!< SPI Status register,                                 Address offset: 0x08 */
#define _SPI2_DR           (SPI2 + SPI_DR_OFFSET)           /*!< SPI data register,                                   Address offset: 0x0C */
#define _SPI2_CRCPR        (SPI2 + SPI_CRCPR_OFFSET)        /*!< SPI CRC polynomial register (not used in I2S mode),  Address offset: 0x10 */
#define _SPI2_RXCRCR       (SPI2 + SPI_RXCRCR_OFFSET)       /*!< SPI Rx CRC register (not used in I2S mode),          Address offset: 0x14 */
#define _SPI2_TXCRCR       (SPI2 + SPI_TXCRCR_OFFSET)       /*!< SPI Tx CRC register (not used in I2S mode),          Address offset: 0x18 */
#define _SPI2_I2SCFGR      (SPI2 + SPI_I2SCFGR_OFFSET)      /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
#define _SPI2_I2SPR        (SPI2 + SPI_I2SPR_OFFSET)        /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */

#define USART2              (USART2_BASE)
#define _USART2_CR1          (USART2 + USART_CR1_OFFSET)          /*!< USART Control register 1,                 Address offset: 0x00 */
#define _USART2_CR2          (USART2 + USART_CR2_OFFSET)          /*!< USART Control register 2,                 Address offset: 0x04 */
#define _USART2_CR3          (USART2 + USART_CR3_OFFSET)          /*!< USART Control register 3,                 Address offset: 0x08 */
#define _USART2_BRR          (USART2 + USART_BRR_OFFSET)          /*!< USART Baud rate register,                 Address offset: 0x0C */
#define _USART2_GTPR         (USART2 + USART_GTPR_OFFSET)         /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
#define _USART2_RTOR         (USART2 + USART_RTOR_OFFSET)         /*!< USART Receiver Time Out register,         Address offset: 0x14 */
#define _USART2_RQR          (USART2 + USART_RQR_OFFSET)          /*!< USART Request register,                   Address offset: 0x18 */
#define _USART2_ISR          (USART2 + USART_ISR_OFFSET)          /*!< USART Interrupt and status register,      Address offset: 0x1C */
#define _USART2_ICR          (USART2 + USART_ICR_OFFSET)          /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
#define _USART2_RDR          (USART2 + USART_RDR_OFFSET)          /*!< USART Receive Data register,              Address offset: 0x24 */
#define _USART2_TDR          (USART2 + USART_TDR_OFFSET)          /*!< USART Transmit Data register,             Address offset: 0x28 */

#define USART3              (USART3_BASE)
#define _USART3_CR1          (USART3 + USART_CR1_OFFSET)          /*!< USART Control register 1,                 Address offset: 0x00 */
#define _USART3_CR2          (USART3 + USART_CR2_OFFSET)          /*!< USART Control register 2,                 Address offset: 0x04 */
#define _USART3_CR3          (USART3 + USART_CR3_OFFSET)          /*!< USART Control register 3,                 Address offset: 0x08 */
#define _USART3_BRR          (USART3 + USART_BRR_OFFSET)          /*!< USART Baud rate register,                 Address offset: 0x0C */
#define _USART3_GTPR         (USART3 + USART_GTPR_OFFSET)         /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
#define _USART3_RTOR         (USART3 + USART_RTOR_OFFSET)         /*!< USART Receiver Time Out register,         Address offset: 0x14 */
#define _USART3_RQR          (USART3 + USART_RQR_OFFSET)          /*!< USART Request register,                   Address offset: 0x18 */
#define _USART3_ISR          (USART3 + USART_ISR_OFFSET)          /*!< USART Interrupt and status register,      Address offset: 0x1C */
#define _USART3_ICR          (USART3 + USART_ICR_OFFSET)          /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
#define _USART3_RDR          (USART3 + USART_RDR_OFFSET)          /*!< USART Receive Data register,              Address offset: 0x24 */
#define _USART3_TDR          (USART3 + USART_TDR_OFFSET)          /*!< USART Transmit Data register,             Address offset: 0x28 */

#define USART4              (USART4_BASE)
#define _USART4_CR1          (USART4 + USART_CR1_OFFSET)          /*!< USART Control register 1,                 Address offset: 0x00 */
#define _USART4_CR2          (USART4 + USART_CR2_OFFSET)          /*!< USART Control register 2,                 Address offset: 0x04 */
#define _USART4_CR3          (USART4 + USART_CR3_OFFSET)          /*!< USART Control register 3,                 Address offset: 0x08 */
#define _USART4_BRR          (USART4 + USART_BRR_OFFSET)          /*!< USART Baud rate register,                 Address offset: 0x0C */
#define _USART4_GTPR         (USART4 + USART_GTPR_OFFSET)         /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
#define _USART4_RTOR         (USART4 + USART_RTOR_OFFSET)         /*!< USART Receiver Time Out register,         Address offset: 0x14 */
#define _USART4_RQR          (USART4 + USART_RQR_OFFSET)          /*!< USART Request register,                   Address offset: 0x18 */
#define _USART4_ISR          (USART4 + USART_ISR_OFFSET)          /*!< USART Interrupt and status register,      Address offset: 0x1C */
#define _USART4_ICR          (USART4 + USART_ICR_OFFSET)          /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
#define _USART4_RDR          (USART4 + USART_RDR_OFFSET)          /*!< USART Receive Data register,              Address offset: 0x24 */
#define _USART4_TDR          (USART4 + USART_TDR_OFFSET)          /*!< USART Transmit Data register,             Address offset: 0x28 */

#define I2C1                (I2C1_BASE)
#define _I2C1_CR1         (I2C1 + I2C_CR1_OFFSET)         /*!< I2C Control register 1,            Address offset: 0x00 */
#define _I2C1_CR2         (I2C1 + I2C_CR2_OFFSET)         /*!< I2C Control register 2,            Address offset: 0x04 */
#define _I2C1_OAR1        (I2C1 + I2C_OAR1_OFFSET)        /*!< I2C Own address 1 register,        Address offset: 0x08 */
#define _I2C1_OAR2        (I2C1 + I2C_OAR2_OFFSET)        /*!< I2C Own address 2 register,        Address offset: 0x0C */
#define _I2C1_TIMINGR     (I2C1 + I2C_TIMINGR_OFFSET)     /*!< I2C Timing register,               Address offset: 0x10 */
#define _I2C1_TIMEOUTR    (I2C1 + I2C_TIMEOUTR_OFFSET)    /*!< I2C Timeout register,              Address offset: 0x14 */
#define _I2C1_ISR         (I2C1 + I2C_ISR_OFFSET)         /*!< I2C Interrupt and status register, Address offset: 0x18 */
#define _I2C1_ICR         (I2C1 + I2C_ICR_OFFSET)         /*!< I2C Interrupt clear register,      Address offset: 0x1C */
#define _I2C1_PECR        (I2C1 + I2C_PECR_OFFSET)        /*!< I2C PEC register,                  Address offset: 0x20 */
#define _I2C1_RXDR        (I2C1 + I2C_RXDR_OFFSET)        /*!< I2C Receive data register,         Address offset: 0x24 */
#define _I2C1_TXDR        (I2C1 + I2C_TXDR_OFFSET)        /*!< I2C Transmit data register,        Address offset: 0x28 */

#define I2C2                (I2C2_BASE)
#define _I2C2_CR1         (I2C2 + I2C_CR1_OFFSET)         /*!< I2C Control register 1,            Address offset: 0x00 */
#define _I2C2_CR2         (I2C2 + I2C_CR2_OFFSET)         /*!< I2C Control register 2,            Address offset: 0x04 */
#define _I2C2_OAR1        (I2C2 + I2C_OAR1_OFFSET)        /*!< I2C Own address 1 register,        Address offset: 0x08 */
#define _I2C2_OAR2        (I2C2 + I2C_OAR2_OFFSET)        /*!< I2C Own address 2 register,        Address offset: 0x0C */
#define _I2C2_TIMINGR     (I2C2 + I2C_TIMINGR_OFFSET)     /*!< I2C Timing register,               Address offset: 0x10 */
#define _I2C2_TIMEOUTR    (I2C2 + I2C_TIMEOUTR_OFFSET)    /*!< I2C Timeout register,              Address offset: 0x14 */
#define _I2C2_ISR         (I2C2 + I2C_ISR_OFFSET)         /*!< I2C Interrupt and status register, Address offset: 0x18 */
#define _I2C2_ICR         (I2C2 + I2C_ICR_OFFSET)         /*!< I2C Interrupt clear register,      Address offset: 0x1C */
#define _I2C2_PECR        (I2C2 + I2C_PECR_OFFSET)        /*!< I2C PEC register,                  Address offset: 0x20 */
#define _I2C2_RXDR        (I2C2 + I2C_RXDR_OFFSET)        /*!< I2C Receive data register,         Address offset: 0x24 */
#define _I2C2_TXDR        (I2C2 + I2C_TXDR_OFFSET)        /*!< I2C Transmit data register,        Address offset: 0x28 */

#define CAN                 (CAN_BASE)
#define _CAN_MCR                (CAN + CAN_MCR_OFFSET)                /*!< CAN master control register,         Address offset: 0x00          */
#define _CAN_MSR                (CAN + CAN_MSR_OFFSET)                /*!< CAN master status register,          Address offset: 0x04          */
#define _CAN_TSR                (CAN + CAN_TSR_OFFSET)                /*!< CAN transmit status register,        Address offset: 0x08          */
#define _CAN_RF0R               (CAN + CAN_RF0R_OFFSET)               /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
#define _CAN_RF1R               (CAN + CAN_RF1R_OFFSET)               /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
#define _CAN_IER                (CAN + CAN_IER_OFFSET)                /*!< CAN interrupt enable register,       Address offset: 0x14          */
#define _CAN_ESR                (CAN + CAN_ESR_OFFSET)                /*!< CAN error status register,           Address offset: 0x18          */
#define _CAN_BTR                (CAN + CAN_BTR_OFFSET)                /*!< CAN bit timing register,             Address offset: 0x1C          */
#define _CAN_sTxMailBox         (CAN + CAN_sTxMailBox_OFFSET)         /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
#define _CAN_sFIFOMailBox       (CAN + CAN_sFIFOMailBox_OFFSET)       /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
#define _CAN_FMR                (CAN + CAN_FMR_OFFSET)                /*!< CAN filter master register,          Address offset: 0x200         */
#define _CAN_FM1R               (CAN + CAN_FM1R_OFFSET)               /*!< CAN filter mode register,            Address offset: 0x204         */
#define _CAN_FS1R               (CAN + CAN_FS1R_OFFSET)               /*!< CAN filter scale register,           Address offset: 0x20C         */
#define _CAN_FFA1R              (CAN + CAN_FFA1R_OFFSET)              /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
#define _CAN_FA1R               (CAN + CAN_FA1R_OFFSET)               /*!< CAN filter activation register,      Address offset: 0x21C         */
#define _CAN_sFilterRegister    (CAN + CAN_sFilterRegister_OFFSET)    /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */

#define CRS                 (CRS_BASE)
#define _CRS_CR      (CRS + CRS_CR_OFFSET)      /*!< CRS ccontrol register,              Address offset: 0x00 */
#define _CRS_CFGR    (CRS + CRS_CFGR_OFFSET)    /*!< CRS configuration register,         Address offset: 0x04 */
#define _CRS_ISR     (CRS + CRS_ISR_OFFSET)     /*!< CRS interrupt and status register,  Address offset: 0x08 */
#define _CRS_ICR     (CRS + CRS_ICR_OFFSET)     /*!< CRS interrupt flag clear register,  Address offset: 0x0C */

#define PWR                 (PWR_BASE)
#define _PWR_CR     (PWR + PWR_CR_OFFSET)     /*!< PWR power control register,        Address offset: 0x00 */
#define _PWR_CSR    (PWR + PWR_CSR_OFFSET)    /*!< PWR power control/status register, Address offset: 0x04 */

#define DAC                 (DAC_BASE)
#define _DAC_CR         (DAC + DAC_CR_OFFSET)         /*!< DAC control register,                                    Address offset: 0x00 */
#define _DAC_SWTRIGR    (DAC + DAC_SWTRIGR_OFFSET)    /*!< DAC software trigger register,                           Address offset: 0x04 */
#define _DAC_DHR12R1    (DAC + DAC_DHR12R1_OFFSET)    /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
#define _DAC_DHR12L1    (DAC + DAC_DHR12L1_OFFSET)    /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
#define _DAC_DHR8R1     (DAC + DAC_DHR8R1_OFFSET)     /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
#define _DAC_DHR12R2    (DAC + DAC_DHR12R2_OFFSET)    /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
#define _DAC_DHR12L2    (DAC + DAC_DHR12L2_OFFSET)    /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
#define _DAC_DHR8R2     (DAC + DAC_DHR8R2_OFFSET)     /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
#define _DAC_DHR12RD    (DAC + DAC_DHR12RD_OFFSET)    /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
#define _DAC_DHR12LD    (DAC + DAC_DHR12LD_OFFSET)    /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
#define _DAC_DHR8RD     (DAC + DAC_DHR8RD_OFFSET)     /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
#define _DAC_DOR1       (DAC + DAC_DOR1_OFFSET)       /*!< DAC channel1 data output register,                       Address offset: 0x2C */
#define _DAC_DOR2       (DAC + DAC_DOR2_OFFSET)       /*!< DAC channel2 data output register,                       Address offset: 0x30 */
#define _DAC_SR         (DAC + DAC_SR_OFFSET)         /*!< DAC status register,                                     Address offset: 0x34 */

#define CEC                 (CEC_BASE)
#define _CEC_CR      (CEC + CEC_CR_OFFSET)      /*!< CEC control register,                                       Address offset:0x00 */
#define _CEC_CFGR    (CEC + CEC_CFGR_OFFSET)    /*!< CEC configuration register,                                 Address offset:0x04 */
#define _CEC_TXDR    (CEC + CEC_TXDR_OFFSET)    /*!< CEC Tx data register ,                                      Address offset:0x08 */
#define _CEC_RXDR    (CEC + CEC_RXDR_OFFSET)    /*!< CEC Rx Data Register,                                       Address offset:0x0C */
#define _CEC_ISR     (CEC + CEC_ISR_OFFSET)     /*!< CEC Interrupt and Status Register,                          Address offset:0x10 */
#define _CEC_IER     (CEC + CEC_IER_OFFSET)     /*!< CEC interrupt enable register,                              Address offset:0x14 */


#define SYSCFG              (SYSCFG_BASE)
#define _SYSCFG_CFGR1       (SYSCFG + SYSCFG_CFGR1_OFFSET)       /*!< SYSCFG configuration register 1,                           Address offset: 0x00 */
#define _SYSCFG_EXTICR      (SYSCFG + SYSCFG_EXTICR_OFFSET)      /*!< SYSCFG external interrupt configuration register,     Address offset: 0x14-0x08 */
#define _SYSCFG_CFGR2       (SYSCFG + SYSCFG_CFGR2_OFFSET)       /*!< SYSCFG configuration register 2,                           Address offset: 0x18 */

#define COMP                (COMP_BASE)
#define _COMP_CSR    (COMP + COMP_CSR_OFFSET)    /*!< COMP comparator control and status register, Address offset: 0x1C */

#define EXTI                (EXTI_BASE)
#define _EXTI_IMR      (EXTI + EXTI_IMR_OFFSET)      /*!<EXTI Interrupt mask register,                             Address offset: 0x00 */
#define _EXTI_EMR      (EXTI + EXTI_EMR_OFFSET)      /*!<EXTI Event mask register,                                 Address offset: 0x04 */
#define _EXTI_RTSR     (EXTI + EXTI_RTSR_OFFSET)     /*!<EXTI Rising trigger selection register ,                  Address offset: 0x08 */
#define _EXTI_FTSR     (EXTI + EXTI_FTSR_OFFSET)     /*!<EXTI Falling trigger selection register,                  Address offset: 0x0C */
#define _EXTI_SWIER    (EXTI + EXTI_SWIER_OFFSET)    /*!<EXTI Software interrupt event register,                   Address offset: 0x10 */
#define _EXTI_PR       (EXTI + EXTI_PR_OFFSET)       /*!<EXTI Pending register,                                    Address offset: 0x14 */

#define ADC1                (ADC1_BASE)
#define _ADC1_ISR          (ADC1 + ADC_ISR_OFFSET)          /*!< ADC Interrupt and Status register,                          Address offset:0x00 */
#define _ADC1_IER          (ADC1 + ADC_IER_OFFSET)          /*!< ADC Interrupt Enable register,                              Address offset:0x04 */
#define _ADC1_CR           (ADC1 + ADC_CR_OFFSET)           /*!< ADC Control register,                                       Address offset:0x08 */
#define _ADC1_CFGR1        (ADC1 + ADC_CFGR1_OFFSET)        /*!< ADC Configuration register 1,                               Address offset:0x0C */
#define _ADC1_CFGR2        (ADC1 + ADC_CFGR2_OFFSET)        /*!< ADC Configuration register 2,                               Address offset:0x10 */
#define _ADC1_SMPR         (ADC1 + ADC_SMPR_OFFSET)         /*!< ADC Sampling time register,                                 Address offset:0x14 */
#define _ADC1_TR           (ADC1 + ADC_TR_OFFSET)           /*!< ADC watchdog threshold register,                            Address offset:0x20 */
#define _ADC1_CHSELR       (ADC1 + ADC_CHSELR_OFFSET)       /*!< ADC channel selection register,                             Address offset:0x28 */
#define _ADC1_DR           (ADC1 + ADC_DR_OFFSET)           /*!< ADC data register,                                          Address offset:0x40 */

#define ADC                 (ADC_BASE)
#define _ADC_CCR    (ADC + ADC_Common_CCR_OFFSET)

#define TIM1                (TIM1_BASE)
#define _TIM1_CR1           (TIM1 + TIM_CR1_OFFSET)           /*!< TIM control register 1,                      Address offset: 0x00 */
#define _TIM1_CR2           (TIM1 + TIM_CR2_OFFSET)           /*!< TIM control register 2,                      Address offset: 0x04 */
#define _TIM1_SMCR          (TIM1 + TIM_SMCR_OFFSET)          /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define _TIM1_DIER          (TIM1 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define _TIM1_SR            (TIM1 + TIM_SR_OFFSET)            /*!< TIM status register,                         Address offset: 0x10 */
#define _TIM1_EGR           (TIM1 + TIM_EGR_OFFSET)           /*!< TIM event generation register,               Address offset: 0x14 */
#define _TIM1_CCMR1         (TIM1 + TIM_CCMR1_OFFSET)         /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define _TIM1_CCMR2         (TIM1 + TIM_CCMR2_OFFSET)         /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define _TIM1_CCER          (TIM1 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define _TIM1_CNT           (TIM1 + TIM_CNT_OFFSET)           /*!< TIM counter register,                        Address offset: 0x24 */
#define _TIM1_PSC           (TIM1 + TIM_PSC_OFFSET)           /*!< TIM prescaler register,                      Address offset: 0x28 */
#define _TIM1_ARR           (TIM1 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define _TIM1_RCR           (TIM1 + TIM_RCR_OFFSET)           /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define _TIM1_CCR1          (TIM1 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define _TIM1_CCR2          (TIM1 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define _TIM1_CCR3          (TIM1 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define _TIM1_CCR4          (TIM1 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define _TIM1_BDTR          (TIM1 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define _TIM1_DCR           (TIM1 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,                    Address offset: 0x48 */
#define _TIM1_DMAR          (TIM1 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define _TIM1_OR            (TIM1 + TIM_OR_OFFSET)            /*!< TIM option register,                         Address offset: 0x50 */

#define SPI1                (SPI1_BASE)
#define _SPI1_CR1          (SPI1 + SPI_CR1_OFFSET)          /*!< SPI Control register 1 (not used in I2S mode),       Address offset: 0x00 */
#define _SPI1_CR2          (SPI1 + SPI_CR2_OFFSET)          /*!< SPI Control register 2,                              Address offset: 0x04 */
#define _SPI1_SR           (SPI1 + SPI_SR_OFFSET)           /*!< SPI Status register,                                 Address offset: 0x08 */
#define _SPI1_DR           (SPI1 + SPI_DR_OFFSET)           /*!< SPI data register,                                   Address offset: 0x0C */
#define _SPI1_CRCPR        (SPI1 + SPI_CRCPR_OFFSET)        /*!< SPI CRC polynomial register (not used in I2S mode),  Address offset: 0x10 */
#define _SPI1_RXCRCR       (SPI1 + SPI_RXCRCR_OFFSET)       /*!< SPI Rx CRC register (not used in I2S mode),          Address offset: 0x14 */
#define _SPI1_TXCRCR       (SPI1 + SPI_TXCRCR_OFFSET)       /*!< SPI Tx CRC register (not used in I2S mode),          Address offset: 0x18 */
#define _SPI1_I2SCFGR      (SPI1 + SPI_I2SCFGR_OFFSET)      /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
#define _SPI1_I2SPR        (SPI1 + SPI_I2SPR_OFFSET)        /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */

#define USART1              (USART1_BASE)
#define _USART1_CR1          (USART1 + USART_CR1_OFFSET)          /*!< USART Control register 1,                 Address offset: 0x00 */
#define _USART1_CR2          (USART1 + USART_CR2_OFFSET)          /*!< USART Control register 2,                 Address offset: 0x04 */
#define _USART1_CR3          (USART1 + USART_CR3_OFFSET)          /*!< USART Control register 3,                 Address offset: 0x08 */
#define _USART1_BRR          (USART1 + USART_BRR_OFFSET)          /*!< USART Baud rate register,                 Address offset: 0x0C */
#define _USART1_GTPR         (USART1 + USART_GTPR_OFFSET)         /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
#define _USART1_RTOR         (USART1 + USART_RTOR_OFFSET)         /*!< USART Receiver Time Out register,         Address offset: 0x14 */
#define _USART1_RQR          (USART1 + USART_RQR_OFFSET)          /*!< USART Request register,                   Address offset: 0x18 */
#define _USART1_ISR          (USART1 + USART_ISR_OFFSET)          /*!< USART Interrupt and status register,      Address offset: 0x1C */
#define _USART1_ICR          (USART1 + USART_ICR_OFFSET)          /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
#define _USART1_RDR          (USART1 + USART_RDR_OFFSET)          /*!< USART Receive Data register,              Address offset: 0x24 */
#define _USART1_TDR          (USART1 + USART_TDR_OFFSET)          /*!< USART Transmit Data register,             Address offset: 0x28 */

#define TIM15               (TIM15_BASE)
#define _TIM15_CR1           (TIM15 + TIM_CR1_OFFSET)           /*!< TIM control register 1,                      Address offset: 0x00 */
#define _TIM15_CR2           (TIM15 + TIM_CR2_OFFSET)           /*!< TIM control register 2,                      Address offset: 0x04 */
#define _TIM15_SMCR          (TIM15 + TIM_SMCR_OFFSET)          /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define _TIM15_DIER          (TIM15 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define _TIM15_SR            (TIM15 + TIM_SR_OFFSET)            /*!< TIM status register,                         Address offset: 0x10 */
#define _TIM15_EGR           (TIM15 + TIM_EGR_OFFSET)           /*!< TIM event generation register,               Address offset: 0x14 */
#define _TIM15_CCMR1         (TIM15 + TIM_CCMR1_OFFSET)         /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define _TIM15_CCMR2         (TIM15 + TIM_CCMR2_OFFSET)         /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define _TIM15_CCER          (TIM15 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define _TIM15_CNT           (TIM15 + TIM_CNT_OFFSET)           /*!< TIM counter register,                        Address offset: 0x24 */
#define _TIM15_PSC           (TIM15 + TIM_PSC_OFFSET)           /*!< TIM prescaler register,                      Address offset: 0x28 */
#define _TIM15_ARR           (TIM15 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define _TIM15_RCR           (TIM15 + TIM_RCR_OFFSET)           /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define _TIM15_CCR1          (TIM15 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define _TIM15_CCR2          (TIM15 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define _TIM15_CCR3          (TIM15 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define _TIM15_CCR4          (TIM15 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define _TIM15_BDTR          (TIM15 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define _TIM15_DCR           (TIM15 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,                    Address offset: 0x48 */
#define _TIM15_DMAR          (TIM15 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define _TIM15_OR            (TIM15 + TIM_OR_OFFSET)            /*!< TIM option register,                         Address offset: 0x50 */

#define TIM16               (TIM16_BASE)
#define _TIM16_CR1           (TIM16 + TIM_CR1_OFFSET)           /*!< TIM control register 1,                      Address offset: 0x00 */
#define _TIM16_CR2           (TIM16 + TIM_CR2_OFFSET)           /*!< TIM control register 2,                      Address offset: 0x04 */
#define _TIM16_SMCR          (TIM16 + TIM_SMCR_OFFSET)          /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define _TIM16_DIER          (TIM16 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define _TIM16_SR            (TIM16 + TIM_SR_OFFSET)            /*!< TIM status register,                         Address offset: 0x10 */
#define _TIM16_EGR           (TIM16 + TIM_EGR_OFFSET)           /*!< TIM event generation register,               Address offset: 0x14 */
#define _TIM16_CCMR1         (TIM16 + TIM_CCMR1_OFFSET)         /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define _TIM16_CCMR2         (TIM16 + TIM_CCMR2_OFFSET)         /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define _TIM16_CCER          (TIM16 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define _TIM16_CNT           (TIM16 + TIM_CNT_OFFSET)           /*!< TIM counter register,                        Address offset: 0x24 */
#define _TIM16_PSC           (TIM16 + TIM_PSC_OFFSET)           /*!< TIM prescaler register,                      Address offset: 0x28 */
#define _TIM16_ARR           (TIM16 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define _TIM16_RCR           (TIM16 + TIM_RCR_OFFSET)           /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define _TIM16_CCR1          (TIM16 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define _TIM16_CCR2          (TIM16 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define _TIM16_CCR3          (TIM16 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define _TIM16_CCR4          (TIM16 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define _TIM16_BDTR          (TIM16 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define _TIM16_DCR           (TIM16 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,                    Address offset: 0x48 */
#define _TIM16_DMAR          (TIM16 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define _TIM16_OR            (TIM16 + TIM_OR_OFFSET)            /*!< TIM option register,                         Address offset: 0x50 */

#define TIM17               (TIM17_BASE)
#define _TIM17_CR1           (TIM17 + TIM_CR1_OFFSET)           /*!< TIM control register 1,                      Address offset: 0x00 */
#define _TIM17_CR2           (TIM17 + TIM_CR2_OFFSET)           /*!< TIM control register 2,                      Address offset: 0x04 */
#define _TIM17_SMCR          (TIM17 + TIM_SMCR_OFFSET)          /*!< TIM slave Mode Control register,             Address offset: 0x08 */
#define _TIM17_DIER          (TIM17 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,           Address offset: 0x0C */
#define _TIM17_SR            (TIM17 + TIM_SR_OFFSET)            /*!< TIM status register,                         Address offset: 0x10 */
#define _TIM17_EGR           (TIM17 + TIM_EGR_OFFSET)           /*!< TIM event generation register,               Address offset: 0x14 */
#define _TIM17_CCMR1         (TIM17 + TIM_CCMR1_OFFSET)         /*!< TIM  capture/compare mode register 1,        Address offset: 0x18 */
#define _TIM17_CCMR2         (TIM17 + TIM_CCMR2_OFFSET)         /*!< TIM  capture/compare mode register 2,        Address offset: 0x1C */
#define _TIM17_CCER          (TIM17 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register,         Address offset: 0x20 */
#define _TIM17_CNT           (TIM17 + TIM_CNT_OFFSET)           /*!< TIM counter register,                        Address offset: 0x24 */
#define _TIM17_PSC           (TIM17 + TIM_PSC_OFFSET)           /*!< TIM prescaler register,                      Address offset: 0x28 */
#define _TIM17_ARR           (TIM17 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,                    Address offset: 0x2C */
#define _TIM17_RCR           (TIM17 + TIM_RCR_OFFSET)           /*!< TIM  repetition counter register,            Address offset: 0x30 */
#define _TIM17_CCR1          (TIM17 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,              Address offset: 0x34 */
#define _TIM17_CCR2          (TIM17 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,              Address offset: 0x38 */
#define _TIM17_CCR3          (TIM17 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,              Address offset: 0x3C */
#define _TIM17_CCR4          (TIM17 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,              Address offset: 0x40 */
#define _TIM17_BDTR          (TIM17 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,            Address offset: 0x44 */
#define _TIM17_DCR           (TIM17 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,                    Address offset: 0x48 */
#define _TIM17_DMAR          (TIM17 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer register,  Address offset: 0x4C */
#define _TIM17_OR            (TIM17 + TIM_OR_OFFSET)            /*!< TIM option register,                         Address offset: 0x50 */

#define DBGMCU              (DBGMCU_BASE)
#define _DBGMCU_IDCODE    (DBGMCU + DBGMCU_IDCODE_OFFSET)    /*!< MCU device ID code,                          Address offset: 0x00 */
#define _DBGMCU_CR        (DBGMCU + DBGMCU_CR_OFFSET)        /*!< Debug MCU configuration register,            Address offset: 0x04 */
#define _DBGMCU_APB1FZ    (DBGMCU + DBGMCU_APB1FZ_OFFSET)    /*!< Debug MCU APB1 freeze register,              Address offset: 0x08 */
#define _DBGMCU_APB2FZ    (DBGMCU + DBGMCU_APB2FZ_OFFSET)    /*!< Debug MCU APB2 freeze register,              Address offset: 0x0C */


#define DMA1                (DMA1_BASE)
#define _DMA1_ISR     (DMA1 + DMA_ISR_OFFSET)     /*!< DMA interrupt status register,                            Address offset: 0x00 */
#define _DMA1_IFCR    (DMA1 + DMA_IFCR_OFFSET)    /*!< DMA interrupt flag clear register,                        Address offset: 0x04 */

#define DMA1_Channel1       (DMA1_Channel1_BASE)
#define _DMA1_Channel1_CCR      (DMA1_Channel1 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA1_Channel1_CNDTR    (DMA1_Channel1 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA1_Channel1_CPAR     (DMA1_Channel1 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA1_Channel1_CMAR     (DMA1_Channel1 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA1_Channel2       (DMA1_Channel2_BASE)
#define _DMA1_Channel2_CCR      (DMA1_Channel2 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA1_Channel2_CNDTR    (DMA1_Channel2 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA1_Channel2_CPAR     (DMA1_Channel2 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA1_Channel2_CMAR     (DMA1_Channel2 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA1_Channel3       (DMA1_Channel3_BASE)
#define _DMA1_Channel3_CCR      (DMA1_Channel3 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA1_Channel3_CNDTR    (DMA1_Channel3 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA1_Channel3_CPAR     (DMA1_Channel3 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA1_Channel3_CMAR     (DMA1_Channel3 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA1_Channel4       (DMA1_Channel4_BASE)
#define _DMA1_Channel4_CCR      (DMA1_Channel4 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA1_Channel4_CNDTR    (DMA1_Channel4 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA1_Channel4_CPAR     (DMA1_Channel4 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA1_Channel4_CMAR     (DMA1_Channel4 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA1_Channel5       (DMA1_Channel5_BASE)
#define _DMA1_Channel5_CCR      (DMA1_Channel5 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA1_Channel5_CNDTR    (DMA1_Channel5 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA1_Channel5_CPAR     (DMA1_Channel5 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA1_Channel5_CMAR     (DMA1_Channel5 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA1_Channel6       (DMA1_Channel6_BASE)
#define _DMA1_Channel6_CCR      (DMA1_Channel6 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA1_Channel6_CNDTR    (DMA1_Channel6 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA1_Channel6_CPAR     (DMA1_Channel6 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA1_Channel6_CMAR     (DMA1_Channel6 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA1_Channel7       (DMA1_Channel7_BASE)
#define _DMA1_Channel7_CCR      (DMA1_Channel7 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA1_Channel7_CNDTR    (DMA1_Channel7 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA1_Channel7_CPAR     (DMA1_Channel7 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA1_Channel7_CMAR     (DMA1_Channel7 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define FLASH               (FLASH_R_BASE)
#define _FLASH_ACR         (FLASH + FLASH_ACR_OFFSET)         /*!<FLASH access control register,                 Address offset: 0x00 */
#define _FLASH_KEYR        (FLASH + FLASH_KEYR_OFFSET)        /*!<FLASH key register,                            Address offset: 0x04 */
#define _FLASH_OPTKEYR     (FLASH + FLASH_OPTKEYR_OFFSET)     /*!<FLASH OPT key register,                        Address offset: 0x08 */
#define _FLASH_SR          (FLASH + FLASH_SR_OFFSET)          /*!<FLASH status register,                         Address offset: 0x0C */
#define _FLASH_CR          (FLASH + FLASH_CR_OFFSET)          /*!<FLASH control register,                        Address offset: 0x10 */
#define _FLASH_AR          (FLASH + FLASH_AR_OFFSET)          /*!<FLASH address register,                        Address offset: 0x14 */
#define _FLASH_OBR         (FLASH + FLASH_OBR_OFFSET)         /*!<FLASH option bytes register,                   Address offset: 0x1C */
#define _FLASH_WRPR        (FLASH + FLASH_WRPR_OFFSET)        /*!<FLASH option bytes register,                   Address offset: 0x20 */

#define OB                  (OB_BASE)
#define _OB_RDP      (OB + OB_RDP_OFFSET)      /*!< FLASH option byte Read protection,             Address offset: 0x00 */
#define _OB_USER     (OB + OB_USER_OFFSET)     /*!< FLASH option byte user options,                Address offset: 0x02 */
#define _OB_DATA0    (OB + OB_DATA0_OFFSET)    /*!< User data byte 0 (stored in FLASH_OBR[23:16]), Address offset: 0x04 */
#define _OB_DATA1    (OB + OB_DATA1_OFFSET)    /*!< User data byte 1 (stored in FLASH_OBR[31:24]), Address offset: 0x06 */
#define _OB_WRP0     (OB + OB_WRP0_OFFSET)     /*!< FLASH option byte write protection 0,          Address offset: 0x08 */
#define _OB_WRP1     (OB + OB_WRP1_OFFSET)     /*!< FLASH option byte write protection 1,          Address offset: 0x0A */
#define _OB_WRP2     (OB + OB_WRP2_OFFSET)     /*!< FLASH option byte write protection 2,          Address offset: 0x0C */
#define _OB_WRP3     (OB + OB_WRP3_OFFSET)     /*!< FLASH option byte write protection 3,          Address offset: 0x0E */

#define RCC                 (RCC_BASE)
#define _RCC_CR          (RCC + RCC_CR_OFFSET)          /*!< RCC clock control register,                                  Address offset: 0x00 */
#define _RCC_CFGR        (RCC + RCC_CFGR_OFFSET)        /*!< RCC clock configuration register,                            Address offset: 0x04 */
#define _RCC_CIR         (RCC + RCC_CIR_OFFSET)         /*!< RCC clock interrupt register,                                Address offset: 0x08 */
#define _RCC_APB2RSTR    (RCC + RCC_APB2RSTR_OFFSET)    /*!< RCC APB2 peripheral reset register,                          Address offset: 0x0C */
#define _RCC_APB1RSTR    (RCC + RCC_APB1RSTR_OFFSET)    /*!< RCC APB1 peripheral reset register,                          Address offset: 0x10 */
#define _RCC_AHBENR      (RCC + RCC_AHBENR_OFFSET)      /*!< RCC AHB peripheral clock register,                           Address offset: 0x14 */
#define _RCC_APB2ENR     (RCC + RCC_APB2ENR_OFFSET)     /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 */
#define _RCC_APB1ENR     (RCC + RCC_APB1ENR_OFFSET)     /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C */
#define _RCC_BDCR        (RCC + RCC_BDCR_OFFSET)        /*!< RCC Backup domain control register,                          Address offset: 0x20 */
#define _RCC_CSR         (RCC + RCC_CSR_OFFSET)         /*!< RCC clock control & status register,                         Address offset: 0x24 */
#define _RCC_AHBRSTR     (RCC + RCC_AHBRSTR_OFFSET)     /*!< RCC AHB peripheral reset register,                           Address offset: 0x28 */
#define _RCC_CFGR2       (RCC + RCC_CFGR2_OFFSET)       /*!< RCC clock configuration register 2,                          Address offset: 0x2C */
#define _RCC_CFGR3       (RCC + RCC_CFGR3_OFFSET)       /*!< RCC clock configuration register 3,                          Address offset: 0x30 */
#define _RCC_CR2         (RCC + RCC_CR2_OFFSET)         /*!< RCC clock control register 2,                                Address offset: 0x34 */

#define CRC                 (CRC_BASE)
#define _CRC_DR           (CRC + CRC_DR_OFFSET)           /*!< CRC Data register,                           Address offset: 0x00 */
#define _CRC_IDR          (CRC + CRC_IDR_OFFSET)          /*!< CRC Independent data register,               Address offset: 0x04 */
#define _CRC_CR           (CRC + CRC_CR_OFFSET)           /*!< CRC Control register,                        Address offset: 0x08 */
#define _CRC_INIT         (CRC + CRC_INIT_OFFSET)         /*!< Initial CRC value register,                  Address offset: 0x10 */
#define _CRC_POL          (CRC + CRC_POL_OFFSET)          /*!< CRC polynomial register,                     Address offset: 0x14 */

#define TSC                 (TSC_BASE)
#define _TSC_CR           (TSC + TSC_CR_OFFSET)           /*!< TSC control register,                                     Address offset: 0x00 */
#define _TSC_IER          (TSC + TSC_IER_OFFSET)          /*!< TSC interrupt enable register,                            Address offset: 0x04 */
#define _TSC_ICR          (TSC + TSC_ICR_OFFSET)          /*!< TSC interrupt clear register,                             Address offset: 0x08 */
#define _TSC_ISR          (TSC + TSC_ISR_OFFSET)          /*!< TSC interrupt status register,                            Address offset: 0x0C */
#define _TSC_IOHCR        (TSC + TSC_IOHCR_OFFSET)        /*!< TSC I/O hysteresis control register,                      Address offset: 0x10 */
#define _TSC_IOASCR       (TSC + TSC_IOASCR_OFFSET)       /*!< TSC I/O analog switch control register,                   Address offset: 0x18 */
#define _TSC_IOSCR        (TSC + TSC_IOSCR_OFFSET)        /*!< TSC I/O sampling control register,                        Address offset: 0x20 */
#define _TSC_IOCCR        (TSC + TSC_IOCCR_OFFSET)        /*!< TSC I/O channel control register,                         Address offset: 0x28 */
#define _TSC_IOGCSR       (TSC + TSC_IOGCSR_OFFSET)       /*!< TSC I/O group control status register,                    Address offset: 0x30 */
#define _TSC_IOGXCR       (TSC + TSC_IOGXCR_OFFSET)       /*!< TSC I/O group x counter register,                         Address offset: 0x34-50 */


#define GPIOA               (GPIOA_BASE)
#define _GPIOA_MODER        (GPIOA + GPIO_MODER_OFFSET)        /*!< GPIO port mode register,                                  Address offset: 0x00 */
#define _GPIOA_OTYPER       (GPIOA + GPIO_OTYPER_OFFSET)       /*!< GPIO port output type register,                           Address offset: 0x04 */
#define _GPIOA_OSPEEDR      (GPIOA + GPIO_OSPEEDR_OFFSET)      /*!< GPIO port output speed register,                          Address offset: 0x08 */
#define _GPIOA_PUPDR        (GPIOA + GPIO_PUPDR_OFFSET)        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
#define _GPIOA_IDR          (GPIOA + GPIO_IDR_OFFSET)          /*!< GPIO port input data register,                            Address offset: 0x10 */
#define _GPIOA_ODR          (GPIOA + GPIO_ODR_OFFSET)          /*!< GPIO port output data register,                           Address offset: 0x14 */
#define _GPIOA_BSRR         (GPIOA + GPIO_BSRR_OFFSET)         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
#define _GPIOA_LCKR         (GPIOA + GPIO_LCKR_OFFSET)         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
#define _GPIOA_AFR          (GPIOA + GPIO_AFR_OFFSET)          /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
#define _GPIOA_BRR          (GPIOA + GPIO_BRR_OFFSET)          /*!< GPIO bit reset register,                                  Address offset: 0x28 */

#define GPIOB               (GPIOB_BASE)
#define _GPIOB_MODER        (GPIOB + GPIO_MODER_OFFSET)        /*!< GPIO port mode register,                                  Address offset: 0x00 */
#define _GPIOB_OTYPER       (GPIOB + GPIO_OTYPER_OFFSET)       /*!< GPIO port output type register,                           Address offset: 0x04 */
#define _GPIOB_OSPEEDR      (GPIOB + GPIO_OSPEEDR_OFFSET)      /*!< GPIO port output speed register,                          Address offset: 0x08 */
#define _GPIOB_PUPDR        (GPIOB + GPIO_PUPDR_OFFSET)        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
#define _GPIOB_IDR          (GPIOB + GPIO_IDR_OFFSET)          /*!< GPIO port input data register,                            Address offset: 0x10 */
#define _GPIOB_ODR          (GPIOB + GPIO_ODR_OFFSET)          /*!< GPIO port output data register,                           Address offset: 0x14 */
#define _GPIOB_BSRR         (GPIOB + GPIO_BSRR_OFFSET)         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
#define _GPIOB_LCKR         (GPIOB + GPIO_LCKR_OFFSET)         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
#define _GPIOB_AFR          (GPIOB + GPIO_AFR_OFFSET)          /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
#define _GPIOB_BRR          (GPIOB + GPIO_BRR_OFFSET)          /*!< GPIO bit reset register,                                  Address offset: 0x28 */

#define GPIOC               (GPIOC_BASE)
#define _GPIOC_MODER        (GPIOC + GPIO_MODER_OFFSET)        /*!< GPIO port mode register,                                  Address offset: 0x00 */
#define _GPIOC_OTYPER       (GPIOC + GPIO_OTYPER_OFFSET)       /*!< GPIO port output type register,                           Address offset: 0x04 */
#define _GPIOC_OSPEEDR      (GPIOC + GPIO_OSPEEDR_OFFSET)      /*!< GPIO port output speed register,                          Address offset: 0x08 */
#define _GPIOC_PUPDR        (GPIOC + GPIO_PUPDR_OFFSET)        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
#define _GPIOC_IDR          (GPIOC + GPIO_IDR_OFFSET)          /*!< GPIO port input data register,                            Address offset: 0x10 */
#define _GPIOC_ODR          (GPIOC + GPIO_ODR_OFFSET)          /*!< GPIO port output data register,                           Address offset: 0x14 */
#define _GPIOC_BSRR         (GPIOC + GPIO_BSRR_OFFSET)         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
#define _GPIOC_LCKR         (GPIOC + GPIO_LCKR_OFFSET)         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
#define _GPIOC_AFR          (GPIOC + GPIO_AFR_OFFSET)          /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
#define _GPIOC_BRR          (GPIOC + GPIO_BRR_OFFSET)          /*!< GPIO bit reset register,                                  Address offset: 0x28 */

#define GPIOD               (GPIOD_BASE)
#define _GPIOD_MODER        (GPIOD + GPIO_MODER_OFFSET)        /*!< GPIO port mode register,                                  Address offset: 0x00 */
#define _GPIOD_OTYPER       (GPIOD + GPIO_OTYPER_OFFSET)       /*!< GPIO port output type register,                           Address offset: 0x04 */
#define _GPIOD_OSPEEDR      (GPIOD + GPIO_OSPEEDR_OFFSET)      /*!< GPIO port output speed register,                          Address offset: 0x08 */
#define _GPIOD_PUPDR        (GPIOD + GPIO_PUPDR_OFFSET)        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
#define _GPIOD_IDR          (GPIOD + GPIO_IDR_OFFSET)          /*!< GPIO port input data register,                            Address offset: 0x10 */
#define _GPIOD_ODR          (GPIOD + GPIO_ODR_OFFSET)          /*!< GPIO port output data register,                           Address offset: 0x14 */
#define _GPIOD_BSRR         (GPIOD + GPIO_BSRR_OFFSET)         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
#define _GPIOD_LCKR         (GPIOD + GPIO_LCKR_OFFSET)         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
#define _GPIOD_AFR          (GPIOD + GPIO_AFR_OFFSET)          /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
#define _GPIOD_BRR          (GPIOD + GPIO_BRR_OFFSET)          /*!< GPIO bit reset register,                                  Address offset: 0x28 */

#define GPIOE               (GPIOE_BASE)
#define _GPIOE_MODER        (GPIOE + GPIO_MODER_OFFSET)        /*!< GPIO port mode register,                                  Address offset: 0x00 */
#define _GPIOE_OTYPER       (GPIOE + GPIO_OTYPER_OFFSET)       /*!< GPIO port output type register,                           Address offset: 0x04 */
#define _GPIOE_OSPEEDR      (GPIOE + GPIO_OSPEEDR_OFFSET)      /*!< GPIO port output speed register,                          Address offset: 0x08 */
#define _GPIOE_PUPDR        (GPIOE + GPIO_PUPDR_OFFSET)        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
#define _GPIOE_IDR          (GPIOE + GPIO_IDR_OFFSET)          /*!< GPIO port input data register,                            Address offset: 0x10 */
#define _GPIOE_ODR          (GPIOE + GPIO_ODR_OFFSET)          /*!< GPIO port output data register,                           Address offset: 0x14 */
#define _GPIOE_BSRR         (GPIOE + GPIO_BSRR_OFFSET)         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
#define _GPIOE_LCKR         (GPIOE + GPIO_LCKR_OFFSET)         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
#define _GPIOE_AFR          (GPIOE + GPIO_AFR_OFFSET)          /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
#define _GPIOE_BRR          (GPIOE + GPIO_BRR_OFFSET)          /*!< GPIO bit reset register,                                  Address offset: 0x28 */

#define GPIOF               (GPIOF_BASE)
#define _GPIOF_MODER        (GPIOF + GPIO_MODER_OFFSET)        /*!< GPIO port mode register,                                  Address offset: 0x00 */
#define _GPIOF_OTYPER       (GPIOF + GPIO_OTYPER_OFFSET)       /*!< GPIO port output type register,                           Address offset: 0x04 */
#define _GPIOF_OSPEEDR      (GPIOF + GPIO_OSPEEDR_OFFSET)      /*!< GPIO port output speed register,                          Address offset: 0x08 */
#define _GPIOF_PUPDR        (GPIOF + GPIO_PUPDR_OFFSET)        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
#define _GPIOF_IDR          (GPIOF + GPIO_IDR_OFFSET)          /*!< GPIO port input data register,                            Address offset: 0x10 */
#define _GPIOF_ODR          (GPIOF + GPIO_ODR_OFFSET)          /*!< GPIO port output data register,                           Address offset: 0x14 */
#define _GPIOF_BSRR         (GPIOF + GPIO_BSRR_OFFSET)         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
#define _GPIOF_LCKR         (GPIOF + GPIO_LCKR_OFFSET)         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
#define _GPIOF_AFR          (GPIOF + GPIO_AFR_OFFSET)          /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
#define _GPIOF_BRR          (GPIOF + GPIO_BRR_OFFSET)          /*!< GPIO bit reset register,                                  Address offset: 0x28 */


/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

/** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

#define ADC_ISR_AWD                          (0x00000080)        /*!< Analog watchdog flag */
#define ADC_ISR_OVR                          (0x00000010)        /*!< Overrun flag */
#define ADC_ISR_EOSEQ                        (0x00000008)        /*!< End of Sequence flag */
#define ADC_ISR_EOC                          (0x00000004)        /*!< End of Conversion */
#define ADC_ISR_EOSMP                        (0x00000002)        /*!< End of sampling flag */
#define ADC_ISR_ADRDY                        (0x00000001)        /*!< ADC Ready */

#define ADC_ISR_EOS                          ADC_ISR_EOSEQ

#define ADC_IER_AWDIE                        (0x00000080)        /*!< Analog Watchdog interrupt enable */
#define ADC_IER_OVRIE                        (0x00000010)        /*!< Overrun interrupt enable */
#define ADC_IER_EOSEQIE                      (0x00000008)        /*!< End of Sequence of conversion interrupt enable */
#define ADC_IER_EOCIE                        (0x00000004)        /*!< End of Conversion interrupt enable */
#define ADC_IER_EOSMPIE                      (0x00000002)        /*!< End of sampling interrupt enable */
#define ADC_IER_ADRDYIE                      (0x00000001)        /*!< ADC Ready interrupt enable */

#define ADC_IER_EOSIE                        ADC_IER_EOSEQIE

#define ADC_CR_ADCAL                         (0x80000000)        /*!< ADC calibration */
#define ADC_CR_ADSTP                         (0x00000010)        /*!< ADC stop of conversion command */
#define ADC_CR_ADSTART                       (0x00000004)        /*!< ADC start of conversion */
#define ADC_CR_ADDIS                         (0x00000002)        /*!< ADC disable command */
#define ADC_CR_ADEN                          (0x00000001)        /*!< ADC enable control */

#define  ADC_CFGR1_AWDCH                      (0x7C000000)       /*!< AWDCH[4:0] bits (Analog watchdog channel select bits) */
#define  ADC_CFGR1_AWDCH_0                    (0x04000000)       /*!< Bit 0 */
#define  ADC_CFGR1_AWDCH_1                    (0x08000000)       /*!< Bit 1 */
#define  ADC_CFGR1_AWDCH_2                    (0x10000000)       /*!< Bit 2 */
#define  ADC_CFGR1_AWDCH_3                    (0x20000000)       /*!< Bit 3 */
#define  ADC_CFGR1_AWDCH_4                    (0x40000000)       /*!< Bit 4 */
#define  ADC_CFGR1_AWDEN                      (0x00800000)       /*!< Analog watchdog enable on regular channels */
#define  ADC_CFGR1_AWDSGL                     (0x00400000)       /*!< Enable the watchdog on a single channel or on all channels  */
#define  ADC_CFGR1_DISCEN                     (0x00010000)       /*!< Discontinuous mode on regular channels */
#define  ADC_CFGR1_AUTOFF                     (0x00008000)       /*!< ADC auto power off */
#define  ADC_CFGR1_WAIT                       (0x00004000)       /*!< ADC wait conversion mode */
#define  ADC_CFGR1_CONT                       (0x00002000)       /*!< Continuous Conversion */
#define  ADC_CFGR1_OVRMOD                     (0x00001000)       /*!< Overrun mode */
#define  ADC_CFGR1_EXTEN                      (0x00000C00)       /*!< EXTEN[1:0] bits (External Trigger Conversion mode for regular channels) */
#define  ADC_CFGR1_EXTEN_0                    (0x00000400)       /*!< Bit 0 */
#define  ADC_CFGR1_EXTEN_1                    (0x00000800)       /*!< Bit 1 */
#define  ADC_CFGR1_EXTSEL                     (0x000001C0)       /*!< EXTSEL[2:0] bits (External Event Select for regular group) */
#define  ADC_CFGR1_EXTSEL_0                   (0x00000040)       /*!< Bit 0 */
#define  ADC_CFGR1_EXTSEL_1                   (0x00000080)       /*!< Bit 1 */
#define  ADC_CFGR1_EXTSEL_2                   (0x00000100)       /*!< Bit 2 */
#define  ADC_CFGR1_ALIGN                      (0x00000020)       /*!< Data Alignment */
#define  ADC_CFGR1_RES                        (0x00000018)       /*!< RES[1:0] bits (Resolution) */
#define  ADC_CFGR1_RES_0                      (0x00000008)       /*!< Bit 0 */
#define  ADC_CFGR1_RES_1                      (0x00000010)       /*!< Bit 1 */
#define  ADC_CFGR1_SCANDIR                    (0x00000004)       /*!< Sequence scan direction */
#define  ADC_CFGR1_DMACFG                     (0x00000002)       /*!< Direct memory access configuration */
#define  ADC_CFGR1_DMAEN                      (0x00000001)       /*!< Direct memory access enable */

#define  ADC_CFGR1_AUTDLY                     ADC_CFGR1_WAIT

#define  ADC_CFGR2_CKMODE                     (0xC0000000)       /*!< ADC clock mode */
#define  ADC_CFGR2_CKMODE_1                   (0x80000000)       /*!< ADC clocked by PCLK div4 */
#define  ADC_CFGR2_CKMODE_0                   (0x40000000)       /*!< ADC clocked by PCLK div2 */

#define  ADC_CFGR2_JITOFFDIV4                 ADC_CFGR2_CKMODE_1           /*!< ADC clocked by PCLK div4 */
#define  ADC_CFGR2_JITOFFDIV2                 ADC_CFGR2_CKMODE_0           /*!< ADC clocked by PCLK div2 */

#define  ADC_SMPR_SMP                      (0x00000007)        /*!< SMP[2:0] bits (Sampling time selection) */
#define  ADC_SMPR_SMP_0                    (0x00000001)        /*!< Bit 0 */
#define  ADC_SMPR_SMP_1                    (0x00000002)        /*!< Bit 1 */
#define  ADC_SMPR_SMP_2                    (0x00000004)        /*!< Bit 2 */

#define  ADC_SMPR1_SMPR                      ADC_SMPR_SMP        /*!< SMP[2:0] bits (Sampling time selection) */
#define  ADC_SMPR1_SMPR_0                    ADC_SMPR_SMP_0        /*!< Bit 0 */
#define  ADC_SMPR1_SMPR_1                    ADC_SMPR_SMP_1        /*!< Bit 1 */
#define  ADC_SMPR1_SMPR_2                    ADC_SMPR_SMP_2        /*!< Bit 2 */

#define  ADC_TR_HT                          (0x0FFF0000)        /*!< Analog watchdog high threshold */
#define  ADC_TR_LT                          (0x00000FFF)        /*!< Analog watchdog low threshold */

#define  ADC_HTR_HT                          ADC_TR_HT                    /*!< Analog watchdog high threshold */
#define  ADC_LTR_LT                          ADC_TR_LT                    /*!< Analog watchdog low threshold */

#define  ADC_CHSELR_CHSEL18                   (0x00040000)        /*!< Channel 18 selection */
#define  ADC_CHSELR_CHSEL17                   (0x00020000)        /*!< Channel 17 selection */
#define  ADC_CHSELR_CHSEL16                   (0x00010000)        /*!< Channel 16 selection */
#define  ADC_CHSELR_CHSEL15                   (0x00008000)        /*!< Channel 15 selection */
#define  ADC_CHSELR_CHSEL14                   (0x00004000)        /*!< Channel 14 selection */
#define  ADC_CHSELR_CHSEL13                   (0x00002000)        /*!< Channel 13 selection */
#define  ADC_CHSELR_CHSEL12                   (0x00001000)        /*!< Channel 12 selection */
#define  ADC_CHSELR_CHSEL11                   (0x00000800)        /*!< Channel 11 selection */
#define  ADC_CHSELR_CHSEL10                   (0x00000400)        /*!< Channel 10 selection */
#define  ADC_CHSELR_CHSEL9                    (0x00000200)        /*!< Channel 9 selection */
#define  ADC_CHSELR_CHSEL8                    (0x00000100)        /*!< Channel 8 selection */
#define  ADC_CHSELR_CHSEL7                    (0x00000080)        /*!< Channel 7 selection */
#define  ADC_CHSELR_CHSEL6                    (0x00000040)        /*!< Channel 6 selection */
#define  ADC_CHSELR_CHSEL5                    (0x00000020)        /*!< Channel 5 selection */
#define  ADC_CHSELR_CHSEL4                    (0x00000010)        /*!< Channel 4 selection */
#define  ADC_CHSELR_CHSEL3                    (0x00000008)        /*!< Channel 3 selection */
#define  ADC_CHSELR_CHSEL2                    (0x00000004)        /*!< Channel 2 selection */
#define  ADC_CHSELR_CHSEL1                    (0x00000002)        /*!< Channel 1 selection */
#define  ADC_CHSELR_CHSEL0                    (0x00000001)        /*!< Channel 0 selection */

#define  ADC_DR_DATA                         (0x0000FFFF)        /*!< Regular data */

#define  ADC_CCR_VBATEN                       (0x01000000)       /*!< Voltage battery enable */
#define  ADC_CCR_TSEN                         (0x00800000)       /*!< Tempurature sensore enable */
#define  ADC_CCR_VREFEN                       (0x00400000)       /*!< Vrefint enable */

#define  CAN_MCR_INRQ                        (0x0001)            /*!<Initialization Request */
#define  CAN_MCR_SLEEP                       (0x0002)            /*!<Sleep Mode Request */
#define  CAN_MCR_TXFP                        (0x0004)            /*!<Transmit FIFO Priority */
#define  CAN_MCR_RFLM                        (0x0008)            /*!<Receive FIFO Locked Mode */
#define  CAN_MCR_NART                        (0x0010)            /*!<No Automatic Retransmission */
#define  CAN_MCR_AWUM                        (0x0020)            /*!<Automatic Wakeup Mode */
#define  CAN_MCR_ABOM                        (0x0040)            /*!<Automatic Bus-Off Management */
#define  CAN_MCR_TTCM                        (0x0080)            /*!<Time Triggered Communication Mode */
#define  CAN_MCR_RESET                       (0x8000)            /*!<bxCAN software master reset */

#define  CAN_MSR_INAK                        (0x0001)            /*!<Initialization Acknowledge */
#define  CAN_MSR_SLAK                        (0x0002)            /*!<Sleep Acknowledge */
#define  CAN_MSR_ERRI                        (0x0004)            /*!<Error Interrupt */
#define  CAN_MSR_WKUI                        (0x0008)            /*!<Wakeup Interrupt */
#define  CAN_MSR_SLAKI                       (0x0010)            /*!<Sleep Acknowledge Interrupt */
#define  CAN_MSR_TXM                         (0x0100)            /*!<Transmit Mode */
#define  CAN_MSR_RXM                         (0x0200)            /*!<Receive Mode */
#define  CAN_MSR_SAMP                        (0x0400)            /*!<Last Sample Point */
#define  CAN_MSR_RX                          (0x0800)            /*!<CAN Rx Signal */

#define  CAN_TSR_RQCP0                       (0x00000001)        /*!<Request Completed Mailbox0 */
#define  CAN_TSR_TXOK0                       (0x00000002)        /*!<Transmission OK of Mailbox0 */
#define  CAN_TSR_ALST0                       (0x00000004)        /*!<Arbitration Lost for Mailbox0 */
#define  CAN_TSR_TERR0                       (0x00000008)        /*!<Transmission Error of Mailbox0 */
#define  CAN_TSR_ABRQ0                       (0x00000080)        /*!<Abort Request for Mailbox0 */
#define  CAN_TSR_RQCP1                       (0x00000100)        /*!<Request Completed Mailbox1 */
#define  CAN_TSR_TXOK1                       (0x00000200)        /*!<Transmission OK of Mailbox1 */
#define  CAN_TSR_ALST1                       (0x00000400)        /*!<Arbitration Lost for Mailbox1 */
#define  CAN_TSR_TERR1                       (0x00000800)        /*!<Transmission Error of Mailbox1 */
#define  CAN_TSR_ABRQ1                       (0x00008000)        /*!<Abort Request for Mailbox 1 */
#define  CAN_TSR_RQCP2                       (0x00010000)        /*!<Request Completed Mailbox2 */
#define  CAN_TSR_TXOK2                       (0x00020000)        /*!<Transmission OK of Mailbox 2 */
#define  CAN_TSR_ALST2                       (0x00040000)        /*!<Arbitration Lost for mailbox 2 */
#define  CAN_TSR_TERR2                       (0x00080000)        /*!<Transmission Error of Mailbox 2 */
#define  CAN_TSR_ABRQ2                       (0x00800000)        /*!<Abort Request for Mailbox 2 */
#define  CAN_TSR_CODE                        (0x03000000)        /*!<Mailbox Code */

#define  CAN_TSR_TME                         (0x1C000000)        /*!<TME[2:0] bits */
#define  CAN_TSR_TME0                        (0x04000000)        /*!<Transmit Mailbox 0 Empty */
#define  CAN_TSR_TME1                        (0x08000000)        /*!<Transmit Mailbox 1 Empty */
#define  CAN_TSR_TME2                        (0x10000000)        /*!<Transmit Mailbox 2 Empty */

#define  CAN_TSR_LOW                         (0xE0000000)        /*!<LOW[2:0] bits */
#define  CAN_TSR_LOW0                        (0x20000000)        /*!<Lowest Priority Flag for Mailbox 0 */
#define  CAN_TSR_LOW1                        (0x40000000)        /*!<Lowest Priority Flag for Mailbox 1 */
#define  CAN_TSR_LOW2                        (0x80000000)        /*!<Lowest Priority Flag for Mailbox 2 */

#define  CAN_RF0R_FMP0                       (0x03)               /*!<FIFO 0 Message Pending */
#define  CAN_RF0R_FULL0                      (0x08)               /*!<FIFO 0 Full */
#define  CAN_RF0R_FOVR0                      (0x10)               /*!<FIFO 0 Overrun */
#define  CAN_RF0R_RFOM0                      (0x20)               /*!<Release FIFO 0 Output Mailbox */

#define  CAN_RF1R_FMP1                       (0x03)               /*!<FIFO 1 Message Pending */
#define  CAN_RF1R_FULL1                      (0x08)               /*!<FIFO 1 Full */
#define  CAN_RF1R_FOVR1                      (0x10)               /*!<FIFO 1 Overrun */
#define  CAN_RF1R_RFOM1                      (0x20)               /*!<Release FIFO 1 Output Mailbox */

#define  CAN_IER_TMEIE                       (0x00000001)        /*!<Transmit Mailbox Empty Interrupt Enable */
#define  CAN_IER_FMPIE0                      (0x00000002)        /*!<FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE0                       (0x00000004)        /*!<FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE0                      (0x00000008)        /*!<FIFO Overrun Interrupt Enable */
#define  CAN_IER_FMPIE1                      (0x00000010)        /*!<FIFO Message Pending Interrupt Enable */
#define  CAN_IER_FFIE1                       (0x00000020)        /*!<FIFO Full Interrupt Enable */
#define  CAN_IER_FOVIE1                      (0x00000040)        /*!<FIFO Overrun Interrupt Enable */
#define  CAN_IER_EWGIE                       (0x00000100)        /*!<Error Warning Interrupt Enable */
#define  CAN_IER_EPVIE                       (0x00000200)        /*!<Error Passive Interrupt Enable */
#define  CAN_IER_BOFIE                       (0x00000400)        /*!<Bus-Off Interrupt Enable */
#define  CAN_IER_LECIE                       (0x00000800)        /*!<Last Error Code Interrupt Enable */
#define  CAN_IER_ERRIE                       (0x00008000)        /*!<Error Interrupt Enable */
#define  CAN_IER_WKUIE                       (0x00010000)        /*!<Wakeup Interrupt Enable */
#define  CAN_IER_SLKIE                       (0x00020000)        /*!<Sleep Interrupt Enable */

#define  CAN_ESR_EWGF                        (0x00000001)        /*!<Error Warning Flag */
#define  CAN_ESR_EPVF                        (0x00000002)        /*!<Error Passive Flag */
#define  CAN_ESR_BOFF                        (0x00000004)        /*!<Bus-Off Flag */

#define  CAN_ESR_LEC                         (0x00000070)        /*!<LEC[2:0] bits (Last Error Code) */
#define  CAN_ESR_LEC_0                       (0x00000010)        /*!<Bit 0 */
#define  CAN_ESR_LEC_1                       (0x00000020)        /*!<Bit 1 */
#define  CAN_ESR_LEC_2                       (0x00000040)        /*!<Bit 2 */

#define  CAN_ESR_TEC                         (0x00FF0000)        /*!<Least significant byte of the 9-bit Transmit Error Counter */
#define  CAN_ESR_REC                         (0xFF000000)        /*!<Receive Error Counter */

#define  CAN_BTR_BRP                         (0x000003FF)        /*!<Baud Rate Prescaler */
#define  CAN_BTR_TS1                         (0x000F0000)        /*!<Time Segment 1 */
#define  CAN_BTR_TS2                         (0x00700000)        /*!<Time Segment 2 */
#define  CAN_BTR_SJW                         (0x03000000)        /*!<Resynchronization Jump Width */
#define  CAN_BTR_LBKM                        (0x40000000)        /*!<Loop Back Mode (Debug) */
#define  CAN_BTR_SILM                        (0x80000000)        /*!<Silent Mode */

#define  CAN_TI0R_TXRQ                       (0x00000001)        /*!<Transmit Mailbox Request */
#define  CAN_TI0R_RTR                        (0x00000002)        /*!<Remote Transmission Request */
#define  CAN_TI0R_IDE                        (0x00000004)        /*!<Identifier Extension */
#define  CAN_TI0R_EXID                       (0x001FFFF8)        /*!<Extended Identifier */
#define  CAN_TI0R_STID                       (0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

#define  CAN_TDT0R_DLC                       (0x0000000F)        /*!<Data Length Code */
#define  CAN_TDT0R_TGT                       (0x00000100)        /*!<Transmit Global Time */
#define  CAN_TDT0R_TIME                      (0xFFFF0000)        /*!<Message Time Stamp */

#define  CAN_TDL0R_DATA0                     (0x000000FF)        /*!<Data byte 0 */
#define  CAN_TDL0R_DATA1                     (0x0000FF00)        /*!<Data byte 1 */
#define  CAN_TDL0R_DATA2                     (0x00FF0000)        /*!<Data byte 2 */
#define  CAN_TDL0R_DATA3                     (0xFF000000)        /*!<Data byte 3 */

#define  CAN_TDH0R_DATA4                     (0x000000FF)        /*!<Data byte 4 */
#define  CAN_TDH0R_DATA5                     (0x0000FF00)        /*!<Data byte 5 */
#define  CAN_TDH0R_DATA6                     (0x00FF0000)        /*!<Data byte 6 */
#define  CAN_TDH0R_DATA7                     (0xFF000000)        /*!<Data byte 7 */

#define  CAN_TI1R_TXRQ                       (0x00000001)        /*!<Transmit Mailbox Request */
#define  CAN_TI1R_RTR                        (0x00000002)        /*!<Remote Transmission Request */
#define  CAN_TI1R_IDE                        (0x00000004)        /*!<Identifier Extension */
#define  CAN_TI1R_EXID                       (0x001FFFF8)        /*!<Extended Identifier */
#define  CAN_TI1R_STID                       (0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

#define  CAN_TDT1R_DLC                       (0x0000000F)        /*!<Data Length Code */
#define  CAN_TDT1R_TGT                       (0x00000100)        /*!<Transmit Global Time */
#define  CAN_TDT1R_TIME                      (0xFFFF0000)        /*!<Message Time Stamp */

#define  CAN_TDL1R_DATA0                     (0x000000FF)        /*!<Data byte 0 */
#define  CAN_TDL1R_DATA1                     (0x0000FF00)        /*!<Data byte 1 */
#define  CAN_TDL1R_DATA2                     (0x00FF0000)        /*!<Data byte 2 */
#define  CAN_TDL1R_DATA3                     (0xFF000000)        /*!<Data byte 3 */

#define  CAN_TDH1R_DATA4                     (0x000000FF)        /*!<Data byte 4 */
#define  CAN_TDH1R_DATA5                     (0x0000FF00)        /*!<Data byte 5 */
#define  CAN_TDH1R_DATA6                     (0x00FF0000)        /*!<Data byte 6 */
#define  CAN_TDH1R_DATA7                     (0xFF000000)        /*!<Data byte 7 */

#define  CAN_TI2R_TXRQ                       (0x00000001)        /*!<Transmit Mailbox Request */
#define  CAN_TI2R_RTR                        (0x00000002)        /*!<Remote Transmission Request */
#define  CAN_TI2R_IDE                        (0x00000004)        /*!<Identifier Extension */
#define  CAN_TI2R_EXID                       (0x001FFFF8)        /*!<Extended identifier */
#define  CAN_TI2R_STID                       (0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

#define  CAN_TDT2R_DLC                       (0x0000000F)        /*!<Data Length Code */
#define  CAN_TDT2R_TGT                       (0x00000100)        /*!<Transmit Global Time */
#define  CAN_TDT2R_TIME                      (0xFFFF0000)        /*!<Message Time Stamp */

#define  CAN_TDL2R_DATA0                     (0x000000FF)        /*!<Data byte 0 */
#define  CAN_TDL2R_DATA1                     (0x0000FF00)        /*!<Data byte 1 */
#define  CAN_TDL2R_DATA2                     (0x00FF0000)        /*!<Data byte 2 */
#define  CAN_TDL2R_DATA3                     (0xFF000000)        /*!<Data byte 3 */

#define  CAN_TDH2R_DATA4                     (0x000000FF)        /*!<Data byte 4 */
#define  CAN_TDH2R_DATA5                     (0x0000FF00)        /*!<Data byte 5 */
#define  CAN_TDH2R_DATA6                     (0x00FF0000)        /*!<Data byte 6 */
#define  CAN_TDH2R_DATA7                     (0xFF000000)        /*!<Data byte 7 */

#define  CAN_RI0R_RTR                        (0x00000002)        /*!<Remote Transmission Request */
#define  CAN_RI0R_IDE                        (0x00000004)        /*!<Identifier Extension */
#define  CAN_RI0R_EXID                       (0x001FFFF8)        /*!<Extended Identifier */
#define  CAN_RI0R_STID                       (0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

#define  CAN_RDT0R_DLC                       (0x0000000F)        /*!<Data Length Code */
#define  CAN_RDT0R_FMI                       (0x0000FF00)        /*!<Filter Match Index */
#define  CAN_RDT0R_TIME                      (0xFFFF0000)        /*!<Message Time Stamp */

#define  CAN_RDL0R_DATA0                     (0x000000FF)        /*!<Data byte 0 */
#define  CAN_RDL0R_DATA1                     (0x0000FF00)        /*!<Data byte 1 */
#define  CAN_RDL0R_DATA2                     (0x00FF0000)        /*!<Data byte 2 */
#define  CAN_RDL0R_DATA3                     (0xFF000000)        /*!<Data byte 3 */

#define  CAN_RDH0R_DATA4                     (0x000000FF)        /*!<Data byte 4 */
#define  CAN_RDH0R_DATA5                     (0x0000FF00)        /*!<Data byte 5 */
#define  CAN_RDH0R_DATA6                     (0x00FF0000)        /*!<Data byte 6 */
#define  CAN_RDH0R_DATA7                     (0xFF000000)        /*!<Data byte 7 */

#define  CAN_RI1R_RTR                        (0x00000002)        /*!<Remote Transmission Request */
#define  CAN_RI1R_IDE                        (0x00000004)        /*!<Identifier Extension */
#define  CAN_RI1R_EXID                       (0x001FFFF8)        /*!<Extended identifier */
#define  CAN_RI1R_STID                       (0xFFE00000)        /*!<Standard Identifier or Extended Identifier */

#define  CAN_RDT1R_DLC                       (0x0000000F)        /*!<Data Length Code */
#define  CAN_RDT1R_FMI                       (0x0000FF00)        /*!<Filter Match Index */
#define  CAN_RDT1R_TIME                      (0xFFFF0000)        /*!<Message Time Stamp */

#define  CAN_RDL1R_DATA0                     (0x000000FF)        /*!<Data byte 0 */
#define  CAN_RDL1R_DATA1                     (0x0000FF00)        /*!<Data byte 1 */
#define  CAN_RDL1R_DATA2                     (0x00FF0000)        /*!<Data byte 2 */
#define  CAN_RDL1R_DATA3                     (0xFF000000)        /*!<Data byte 3 */

#define  CAN_RDH1R_DATA4                     (0x000000FF)        /*!<Data byte 4 */
#define  CAN_RDH1R_DATA5                     (0x0000FF00)        /*!<Data byte 5 */
#define  CAN_RDH1R_DATA6                     (0x00FF0000)        /*!<Data byte 6 */
#define  CAN_RDH1R_DATA7                     (0xFF000000)        /*!<Data byte 7 */

#define  CAN_FMR_FINIT                       (0x01)               /*!<Filter Init Mode */

#define  CAN_FM1R_FBM                        (0x3FFF)            /*!<Filter Mode */
#define  CAN_FM1R_FBM0                       (0x0001)            /*!<Filter Init Mode bit 0 */
#define  CAN_FM1R_FBM1                       (0x0002)            /*!<Filter Init Mode bit 1 */
#define  CAN_FM1R_FBM2                       (0x0004)            /*!<Filter Init Mode bit 2 */
#define  CAN_FM1R_FBM3                       (0x0008)            /*!<Filter Init Mode bit 3 */
#define  CAN_FM1R_FBM4                       (0x0010)            /*!<Filter Init Mode bit 4 */
#define  CAN_FM1R_FBM5                       (0x0020)            /*!<Filter Init Mode bit 5 */
#define  CAN_FM1R_FBM6                       (0x0040)            /*!<Filter Init Mode bit 6 */
#define  CAN_FM1R_FBM7                       (0x0080)            /*!<Filter Init Mode bit 7 */
#define  CAN_FM1R_FBM8                       (0x0100)            /*!<Filter Init Mode bit 8 */
#define  CAN_FM1R_FBM9                       (0x0200)            /*!<Filter Init Mode bit 9 */
#define  CAN_FM1R_FBM10                      (0x0400)            /*!<Filter Init Mode bit 10 */
#define  CAN_FM1R_FBM11                      (0x0800)            /*!<Filter Init Mode bit 11 */
#define  CAN_FM1R_FBM12                      (0x1000)            /*!<Filter Init Mode bit 12 */
#define  CAN_FM1R_FBM13                      (0x2000)            /*!<Filter Init Mode bit 13 */

#define  CAN_FS1R_FSC                        (0x3FFF)            /*!<Filter Scale Configuration */
#define  CAN_FS1R_FSC0                       (0x0001)            /*!<Filter Scale Configuration bit 0 */
#define  CAN_FS1R_FSC1                       (0x0002)            /*!<Filter Scale Configuration bit 1 */
#define  CAN_FS1R_FSC2                       (0x0004)            /*!<Filter Scale Configuration bit 2 */
#define  CAN_FS1R_FSC3                       (0x0008)            /*!<Filter Scale Configuration bit 3 */
#define  CAN_FS1R_FSC4                       (0x0010)            /*!<Filter Scale Configuration bit 4 */
#define  CAN_FS1R_FSC5                       (0x0020)            /*!<Filter Scale Configuration bit 5 */
#define  CAN_FS1R_FSC6                       (0x0040)            /*!<Filter Scale Configuration bit 6 */
#define  CAN_FS1R_FSC7                       (0x0080)            /*!<Filter Scale Configuration bit 7 */
#define  CAN_FS1R_FSC8                       (0x0100)            /*!<Filter Scale Configuration bit 8 */
#define  CAN_FS1R_FSC9                       (0x0200)            /*!<Filter Scale Configuration bit 9 */
#define  CAN_FS1R_FSC10                      (0x0400)            /*!<Filter Scale Configuration bit 10 */
#define  CAN_FS1R_FSC11                      (0x0800)            /*!<Filter Scale Configuration bit 11 */
#define  CAN_FS1R_FSC12                      (0x1000)            /*!<Filter Scale Configuration bit 12 */
#define  CAN_FS1R_FSC13                      (0x2000)            /*!<Filter Scale Configuration bit 13 */

#define  CAN_FFA1R_FFA                       (0x3FFF)            /*!<Filter FIFO Assignment */
#define  CAN_FFA1R_FFA0                      (0x0001)            /*!<Filter FIFO Assignment for Filter 0 */
#define  CAN_FFA1R_FFA1                      (0x0002)            /*!<Filter FIFO Assignment for Filter 1 */
#define  CAN_FFA1R_FFA2                      (0x0004)            /*!<Filter FIFO Assignment for Filter 2 */
#define  CAN_FFA1R_FFA3                      (0x0008)            /*!<Filter FIFO Assignment for Filter 3 */
#define  CAN_FFA1R_FFA4                      (0x0010)            /*!<Filter FIFO Assignment for Filter 4 */
#define  CAN_FFA1R_FFA5                      (0x0020)            /*!<Filter FIFO Assignment for Filter 5 */
#define  CAN_FFA1R_FFA6                      (0x0040)            /*!<Filter FIFO Assignment for Filter 6 */
#define  CAN_FFA1R_FFA7                      (0x0080)            /*!<Filter FIFO Assignment for Filter 7 */
#define  CAN_FFA1R_FFA8                      (0x0100)            /*!<Filter FIFO Assignment for Filter 8 */
#define  CAN_FFA1R_FFA9                      (0x0200)            /*!<Filter FIFO Assignment for Filter 9 */
#define  CAN_FFA1R_FFA10                     (0x0400)            /*!<Filter FIFO Assignment for Filter 10 */
#define  CAN_FFA1R_FFA11                     (0x0800)            /*!<Filter FIFO Assignment for Filter 11 */
#define  CAN_FFA1R_FFA12                     (0x1000)            /*!<Filter FIFO Assignment for Filter 12 */
#define  CAN_FFA1R_FFA13                     (0x2000)            /*!<Filter FIFO Assignment for Filter 13 */

#define  CAN_FA1R_FACT                       (0x3FFF)            /*!<Filter Active */
#define  CAN_FA1R_FACT0                      (0x0001)            /*!<Filter 0 Active */
#define  CAN_FA1R_FACT1                      (0x0002)            /*!<Filter 1 Active */
#define  CAN_FA1R_FACT2                      (0x0004)            /*!<Filter 2 Active */
#define  CAN_FA1R_FACT3                      (0x0008)            /*!<Filter 3 Active */
#define  CAN_FA1R_FACT4                      (0x0010)            /*!<Filter 4 Active */
#define  CAN_FA1R_FACT5                      (0x0020)            /*!<Filter 5 Active */
#define  CAN_FA1R_FACT6                      (0x0040)            /*!<Filter 6 Active */
#define  CAN_FA1R_FACT7                      (0x0080)            /*!<Filter 7 Active */
#define  CAN_FA1R_FACT8                      (0x0100)            /*!<Filter 8 Active */
#define  CAN_FA1R_FACT9                      (0x0200)            /*!<Filter 9 Active */
#define  CAN_FA1R_FACT10                     (0x0400)            /*!<Filter 10 Active */
#define  CAN_FA1R_FACT11                     (0x0800)            /*!<Filter 11 Active */
#define  CAN_FA1R_FACT12                     (0x1000)            /*!<Filter 12 Active */
#define  CAN_FA1R_FACT13                     (0x2000)            /*!<Filter 13 Active */

#define  CAN_F0R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F0R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F0R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F0R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F0R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F0R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F0R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F0R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F0R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F0R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F0R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F0R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F0R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F0R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F0R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F0R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F0R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F0R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F0R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F0R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F0R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F0R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F0R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F0R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F0R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F0R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F0R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F0R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F0R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F0R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F0R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F0R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F1R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F1R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F1R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F1R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F1R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F1R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F1R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F1R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F1R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F1R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F1R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F1R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F1R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F1R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F1R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F1R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F1R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F1R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F1R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F1R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F1R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F1R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F1R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F1R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F1R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F1R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F1R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F1R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F1R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F1R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F1R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F1R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F2R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F2R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F2R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F2R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F2R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F2R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F2R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F2R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F2R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F2R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F2R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F2R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F2R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F2R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F2R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F2R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F2R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F2R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F2R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F2R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F2R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F2R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F2R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F2R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F2R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F2R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F2R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F2R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F2R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F2R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F2R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F2R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F3R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F3R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F3R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F3R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F3R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F3R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F3R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F3R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F3R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F3R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F3R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F3R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F3R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F3R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F3R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F3R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F3R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F3R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F3R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F3R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F3R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F3R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F3R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F3R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F3R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F3R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F3R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F3R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F3R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F3R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F3R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F3R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F4R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F4R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F4R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F4R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F4R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F4R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F4R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F4R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F4R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F4R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F4R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F4R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F4R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F4R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F4R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F4R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F4R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F4R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F4R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F4R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F4R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F4R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F4R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F4R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F4R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F4R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F4R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F4R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F4R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F4R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F4R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F4R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F5R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F5R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F5R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F5R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F5R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F5R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F5R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F5R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F5R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F5R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F5R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F5R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F5R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F5R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F5R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F5R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F5R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F5R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F5R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F5R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F5R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F5R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F5R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F5R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F5R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F5R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F5R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F5R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F5R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F5R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F5R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F5R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F6R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F6R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F6R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F6R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F6R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F6R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F6R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F6R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F6R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F6R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F6R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F6R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F6R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F6R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F6R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F6R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F6R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F6R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F6R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F6R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F6R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F6R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F6R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F6R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F6R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F6R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F6R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F6R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F6R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F6R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F6R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F6R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F7R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F7R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F7R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F7R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F7R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F7R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F7R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F7R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F7R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F7R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F7R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F7R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F7R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F7R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F7R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F7R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F7R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F7R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F7R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F7R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F7R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F7R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F7R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F7R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F7R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F7R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F7R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F7R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F7R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F7R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F7R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F7R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F8R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F8R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F8R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F8R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F8R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F8R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F8R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F8R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F8R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F8R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F8R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F8R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F8R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F8R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F8R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F8R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F8R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F8R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F8R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F8R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F8R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F8R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F8R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F8R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F8R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F8R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F8R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F8R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F8R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F8R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F8R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F8R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F9R1_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F9R1_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F9R1_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F9R1_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F9R1_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F9R1_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F9R1_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F9R1_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F9R1_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F9R1_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F9R1_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F9R1_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F9R1_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F9R1_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F9R1_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F9R1_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F9R1_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F9R1_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F9R1_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F9R1_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F9R1_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F9R1_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F9R1_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F9R1_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F9R1_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F9R1_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F9R1_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F9R1_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F9R1_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F9R1_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F9R1_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F9R1_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F10R1_FB0                       (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F10R1_FB1                       (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F10R1_FB2                       (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F10R1_FB3                       (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F10R1_FB4                       (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F10R1_FB5                       (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F10R1_FB6                       (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F10R1_FB7                       (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F10R1_FB8                       (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F10R1_FB9                       (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F10R1_FB10                      (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F10R1_FB11                      (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F10R1_FB12                      (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F10R1_FB13                      (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F10R1_FB14                      (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F10R1_FB15                      (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F10R1_FB16                      (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F10R1_FB17                      (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F10R1_FB18                      (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F10R1_FB19                      (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F10R1_FB20                      (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F10R1_FB21                      (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F10R1_FB22                      (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F10R1_FB23                      (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F10R1_FB24                      (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F10R1_FB25                      (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F10R1_FB26                      (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F10R1_FB27                      (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F10R1_FB28                      (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F10R1_FB29                      (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F10R1_FB30                      (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F10R1_FB31                      (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F11R1_FB0                       (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F11R1_FB1                       (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F11R1_FB2                       (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F11R1_FB3                       (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F11R1_FB4                       (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F11R1_FB5                       (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F11R1_FB6                       (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F11R1_FB7                       (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F11R1_FB8                       (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F11R1_FB9                       (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F11R1_FB10                      (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F11R1_FB11                      (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F11R1_FB12                      (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F11R1_FB13                      (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F11R1_FB14                      (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F11R1_FB15                      (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F11R1_FB16                      (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F11R1_FB17                      (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F11R1_FB18                      (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F11R1_FB19                      (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F11R1_FB20                      (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F11R1_FB21                      (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F11R1_FB22                      (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F11R1_FB23                      (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F11R1_FB24                      (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F11R1_FB25                      (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F11R1_FB26                      (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F11R1_FB27                      (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F11R1_FB28                      (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F11R1_FB29                      (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F11R1_FB30                      (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F11R1_FB31                      (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F12R1_FB0                       (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F12R1_FB1                       (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F12R1_FB2                       (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F12R1_FB3                       (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F12R1_FB4                       (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F12R1_FB5                       (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F12R1_FB6                       (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F12R1_FB7                       (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F12R1_FB8                       (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F12R1_FB9                       (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F12R1_FB10                      (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F12R1_FB11                      (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F12R1_FB12                      (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F12R1_FB13                      (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F12R1_FB14                      (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F12R1_FB15                      (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F12R1_FB16                      (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F12R1_FB17                      (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F12R1_FB18                      (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F12R1_FB19                      (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F12R1_FB20                      (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F12R1_FB21                      (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F12R1_FB22                      (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F12R1_FB23                      (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F12R1_FB24                      (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F12R1_FB25                      (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F12R1_FB26                      (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F12R1_FB27                      (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F12R1_FB28                      (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F12R1_FB29                      (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F12R1_FB30                      (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F12R1_FB31                      (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F13R1_FB0                       (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F13R1_FB1                       (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F13R1_FB2                       (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F13R1_FB3                       (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F13R1_FB4                       (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F13R1_FB5                       (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F13R1_FB6                       (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F13R1_FB7                       (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F13R1_FB8                       (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F13R1_FB9                       (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F13R1_FB10                      (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F13R1_FB11                      (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F13R1_FB12                      (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F13R1_FB13                      (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F13R1_FB14                      (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F13R1_FB15                      (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F13R1_FB16                      (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F13R1_FB17                      (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F13R1_FB18                      (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F13R1_FB19                      (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F13R1_FB20                      (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F13R1_FB21                      (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F13R1_FB22                      (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F13R1_FB23                      (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F13R1_FB24                      (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F13R1_FB25                      (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F13R1_FB26                      (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F13R1_FB27                      (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F13R1_FB28                      (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F13R1_FB29                      (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F13R1_FB30                      (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F13R1_FB31                      (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F0R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F0R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F0R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F0R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F0R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F0R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F0R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F0R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F0R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F0R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F0R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F0R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F0R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F0R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F0R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F0R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F0R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F0R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F0R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F0R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F0R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F0R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F0R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F0R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F0R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F0R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F0R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F0R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F0R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F0R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F0R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F0R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F1R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F1R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F1R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F1R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F1R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F1R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F1R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F1R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F1R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F1R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F1R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F1R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F1R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F1R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F1R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F1R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F1R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F1R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F1R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F1R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F1R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F1R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F1R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F1R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F1R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F1R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F1R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F1R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F1R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F1R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F1R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F1R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F2R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F2R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F2R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F2R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F2R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F2R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F2R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F2R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F2R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F2R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F2R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F2R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F2R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F2R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F2R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F2R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F2R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F2R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F2R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F2R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F2R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F2R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F2R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F2R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F2R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F2R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F2R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F2R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F2R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F2R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F2R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F2R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F3R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F3R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F3R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F3R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F3R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F3R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F3R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F3R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F3R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F3R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F3R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F3R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F3R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F3R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F3R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F3R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F3R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F3R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F3R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F3R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F3R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F3R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F3R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F3R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F3R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F3R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F3R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F3R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F3R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F3R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F3R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F3R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F4R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F4R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F4R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F4R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F4R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F4R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F4R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F4R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F4R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F4R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F4R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F4R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F4R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F4R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F4R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F4R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F4R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F4R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F4R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F4R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F4R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F4R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F4R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F4R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F4R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F4R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F4R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F4R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F4R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F4R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F4R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F4R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F5R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F5R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F5R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F5R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F5R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F5R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F5R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F5R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F5R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F5R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F5R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F5R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F5R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F5R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F5R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F5R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F5R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F5R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F5R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F5R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F5R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F5R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F5R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F5R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F5R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F5R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F5R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F5R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F5R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F5R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F5R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F5R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F6R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F6R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F6R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F6R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F6R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F6R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F6R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F6R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F6R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F6R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F6R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F6R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F6R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F6R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F6R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F6R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F6R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F6R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F6R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F6R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F6R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F6R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F6R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F6R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F6R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F6R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F6R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F6R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F6R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F6R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F6R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F6R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F7R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F7R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F7R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F7R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F7R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F7R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F7R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F7R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F7R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F7R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F7R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F7R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F7R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F7R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F7R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F7R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F7R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F7R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F7R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F7R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F7R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F7R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F7R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F7R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F7R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F7R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F7R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F7R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F7R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F7R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F7R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F7R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F8R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F8R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F8R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F8R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F8R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F8R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F8R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F8R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F8R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F8R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F8R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F8R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F8R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F8R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F8R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F8R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F8R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F8R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F8R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F8R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F8R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F8R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F8R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F8R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F8R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F8R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F8R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F8R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F8R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F8R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F8R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F8R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F9R2_FB0                        (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F9R2_FB1                        (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F9R2_FB2                        (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F9R2_FB3                        (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F9R2_FB4                        (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F9R2_FB5                        (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F9R2_FB6                        (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F9R2_FB7                        (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F9R2_FB8                        (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F9R2_FB9                        (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F9R2_FB10                       (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F9R2_FB11                       (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F9R2_FB12                       (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F9R2_FB13                       (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F9R2_FB14                       (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F9R2_FB15                       (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F9R2_FB16                       (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F9R2_FB17                       (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F9R2_FB18                       (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F9R2_FB19                       (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F9R2_FB20                       (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F9R2_FB21                       (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F9R2_FB22                       (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F9R2_FB23                       (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F9R2_FB24                       (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F9R2_FB25                       (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F9R2_FB26                       (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F9R2_FB27                       (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F9R2_FB28                       (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F9R2_FB29                       (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F9R2_FB30                       (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F9R2_FB31                       (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F10R2_FB0                       (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F10R2_FB1                       (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F10R2_FB2                       (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F10R2_FB3                       (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F10R2_FB4                       (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F10R2_FB5                       (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F10R2_FB6                       (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F10R2_FB7                       (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F10R2_FB8                       (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F10R2_FB9                       (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F10R2_FB10                      (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F10R2_FB11                      (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F10R2_FB12                      (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F10R2_FB13                      (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F10R2_FB14                      (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F10R2_FB15                      (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F10R2_FB16                      (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F10R2_FB17                      (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F10R2_FB18                      (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F10R2_FB19                      (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F10R2_FB20                      (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F10R2_FB21                      (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F10R2_FB22                      (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F10R2_FB23                      (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F10R2_FB24                      (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F10R2_FB25                      (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F10R2_FB26                      (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F10R2_FB27                      (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F10R2_FB28                      (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F10R2_FB29                      (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F10R2_FB30                      (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F10R2_FB31                      (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F11R2_FB0                       (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F11R2_FB1                       (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F11R2_FB2                       (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F11R2_FB3                       (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F11R2_FB4                       (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F11R2_FB5                       (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F11R2_FB6                       (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F11R2_FB7                       (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F11R2_FB8                       (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F11R2_FB9                       (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F11R2_FB10                      (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F11R2_FB11                      (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F11R2_FB12                      (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F11R2_FB13                      (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F11R2_FB14                      (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F11R2_FB15                      (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F11R2_FB16                      (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F11R2_FB17                      (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F11R2_FB18                      (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F11R2_FB19                      (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F11R2_FB20                      (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F11R2_FB21                      (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F11R2_FB22                      (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F11R2_FB23                      (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F11R2_FB24                      (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F11R2_FB25                      (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F11R2_FB26                      (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F11R2_FB27                      (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F11R2_FB28                      (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F11R2_FB29                      (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F11R2_FB30                      (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F11R2_FB31                      (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F12R2_FB0                       (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F12R2_FB1                       (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F12R2_FB2                       (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F12R2_FB3                       (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F12R2_FB4                       (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F12R2_FB5                       (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F12R2_FB6                       (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F12R2_FB7                       (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F12R2_FB8                       (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F12R2_FB9                       (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F12R2_FB10                      (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F12R2_FB11                      (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F12R2_FB12                      (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F12R2_FB13                      (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F12R2_FB14                      (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F12R2_FB15                      (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F12R2_FB16                      (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F12R2_FB17                      (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F12R2_FB18                      (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F12R2_FB19                      (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F12R2_FB20                      (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F12R2_FB21                      (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F12R2_FB22                      (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F12R2_FB23                      (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F12R2_FB24                      (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F12R2_FB25                      (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F12R2_FB26                      (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F12R2_FB27                      (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F12R2_FB28                      (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F12R2_FB29                      (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F12R2_FB30                      (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F12R2_FB31                      (0x80000000)        /*!<Filter bit 31 */

#define  CAN_F13R2_FB0                       (0x00000001)        /*!<Filter bit 0 */
#define  CAN_F13R2_FB1                       (0x00000002)        /*!<Filter bit 1 */
#define  CAN_F13R2_FB2                       (0x00000004)        /*!<Filter bit 2 */
#define  CAN_F13R2_FB3                       (0x00000008)        /*!<Filter bit 3 */
#define  CAN_F13R2_FB4                       (0x00000010)        /*!<Filter bit 4 */
#define  CAN_F13R2_FB5                       (0x00000020)        /*!<Filter bit 5 */
#define  CAN_F13R2_FB6                       (0x00000040)        /*!<Filter bit 6 */
#define  CAN_F13R2_FB7                       (0x00000080)        /*!<Filter bit 7 */
#define  CAN_F13R2_FB8                       (0x00000100)        /*!<Filter bit 8 */
#define  CAN_F13R2_FB9                       (0x00000200)        /*!<Filter bit 9 */
#define  CAN_F13R2_FB10                      (0x00000400)        /*!<Filter bit 10 */
#define  CAN_F13R2_FB11                      (0x00000800)        /*!<Filter bit 11 */
#define  CAN_F13R2_FB12                      (0x00001000)        /*!<Filter bit 12 */
#define  CAN_F13R2_FB13                      (0x00002000)        /*!<Filter bit 13 */
#define  CAN_F13R2_FB14                      (0x00004000)        /*!<Filter bit 14 */
#define  CAN_F13R2_FB15                      (0x00008000)        /*!<Filter bit 15 */
#define  CAN_F13R2_FB16                      (0x00010000)        /*!<Filter bit 16 */
#define  CAN_F13R2_FB17                      (0x00020000)        /*!<Filter bit 17 */
#define  CAN_F13R2_FB18                      (0x00040000)        /*!<Filter bit 18 */
#define  CAN_F13R2_FB19                      (0x00080000)        /*!<Filter bit 19 */
#define  CAN_F13R2_FB20                      (0x00100000)        /*!<Filter bit 20 */
#define  CAN_F13R2_FB21                      (0x00200000)        /*!<Filter bit 21 */
#define  CAN_F13R2_FB22                      (0x00400000)        /*!<Filter bit 22 */
#define  CAN_F13R2_FB23                      (0x00800000)        /*!<Filter bit 23 */
#define  CAN_F13R2_FB24                      (0x01000000)        /*!<Filter bit 24 */
#define  CAN_F13R2_FB25                      (0x02000000)        /*!<Filter bit 25 */
#define  CAN_F13R2_FB26                      (0x04000000)        /*!<Filter bit 26 */
#define  CAN_F13R2_FB27                      (0x08000000)        /*!<Filter bit 27 */
#define  CAN_F13R2_FB28                      (0x10000000)        /*!<Filter bit 28 */
#define  CAN_F13R2_FB29                      (0x20000000)        /*!<Filter bit 29 */
#define  CAN_F13R2_FB30                      (0x40000000)        /*!<Filter bit 30 */
#define  CAN_F13R2_FB31                      (0x80000000)        /*!<Filter bit 31 */



#define  CEC_CR_CECEN                        (0x00000001)       /*!< CEC Enable                         */
#define  CEC_CR_TXSOM                        (0x00000002)       /*!< CEC Tx Start Of Message            */
#define  CEC_CR_TXEOM                        (0x00000004)       /*!< CEC Tx End Of Message              */

#define  CEC_CFGR_SFT                        (0x00000007)       /*!< CEC Signal Free Time               */
#define  CEC_CFGR_RXTOL                      (0x00000008)       /*!< CEC Tolerance                      */
#define  CEC_CFGR_BRESTP                     (0x00000010)       /*!< CEC Rx Stop                        */
#define  CEC_CFGR_BREGEN                     (0x00000020)       /*!< CEC Bit Rising Error generation    */
#define  CEC_CFGR_LREGEN                     (0x00000040)       /*!< CEC Long Period Error generation   */
#define  CEC_CFGR_BRDNOGEN                   (0x00000080)       /*!< CEC Broadcast no Error generation  */
#define  CEC_CFGR_SFTOPT                     (0x00000100)       /*!< CEC Signal Free Time optional      */
#define  CEC_CFGR_OAR                        (0x7FFF0000)       /*!< CEC Own Address                    */
#define  CEC_CFGR_LSTN                       (0x80000000)       /*!< CEC Listen mode                    */

#define  CEC_TXDR_TXD                        (0x000000FF)       /*!< CEC Tx Data                        */

#define  CEC_TXDR_RXD                        (0x000000FF)       /*!< CEC Rx Data                        */

#define  CEC_ISR_RXBR                        (0x00000001)       /*!< CEC Rx-Byte Received                   */
#define  CEC_ISR_RXEND                       (0x00000002)       /*!< CEC End Of Reception                   */
#define  CEC_ISR_RXOVR                       (0x00000004)       /*!< CEC Rx-Overrun                         */
#define  CEC_ISR_BRE                         (0x00000008)       /*!< CEC Rx Bit Rising Error                */
#define  CEC_ISR_SBPE                        (0x00000010)       /*!< CEC Rx Short Bit period Error          */
#define  CEC_ISR_LBPE                        (0x00000020)       /*!< CEC Rx Long Bit period Error           */
#define  CEC_ISR_RXACKE                      (0x00000040)       /*!< CEC Rx Missing Acknowledge             */
#define  CEC_ISR_ARBLST                      (0x00000080)       /*!< CEC Arbitration Lost                   */
#define  CEC_ISR_TXBR                        (0x00000100)       /*!< CEC Tx Byte Request                    */
#define  CEC_ISR_TXEND                       (0x00000200)       /*!< CEC End of Transmission                */
#define  CEC_ISR_TXUDR                       (0x00000400)       /*!< CEC Tx-Buffer Underrun                 */
#define  CEC_ISR_TXERR                       (0x00000800)       /*!< CEC Tx-Error                           */
#define  CEC_ISR_TXACKE                      (0x00001000)       /*!< CEC Tx Missing Acknowledge             */

#define  CEC_IER_RXBRIE                      (0x00000001)       /*!< CEC Rx-Byte Received IT Enable         */
#define  CEC_IER_RXENDIE                     (0x00000002)       /*!< CEC End Of Reception IT Enable         */
#define  CEC_IER_RXOVRIE                     (0x00000004)       /*!< CEC Rx-Overrun IT Enable               */
#define  CEC_IER_BREIEIE                     (0x00000008)       /*!< CEC Rx Bit Rising Error IT Enable      */
#define  CEC_IER_SBPEIE                      (0x00000010)       /*!< CEC Rx Short Bit period Error IT Enable*/
#define  CEC_IER_LBPEIE                      (0x00000020)       /*!< CEC Rx Long Bit period Error IT Enable */
#define  CEC_IER_RXACKEIE                    (0x00000040)       /*!< CEC Rx Missing Acknowledge IT Enable   */
#define  CEC_IER_ARBLSTIE                    (0x00000080)       /*!< CEC Arbitration Lost IT Enable         */
#define  CEC_IER_TXBRIE                      (0x00000100)       /*!< CEC Tx Byte Request  IT Enable         */
#define  CEC_IER_TXENDIE                     (0x00000200)       /*!< CEC End of Transmission IT Enable      */
#define  CEC_IER_TXUDRIE                     (0x00000400)       /*!< CEC Tx-Buffer Underrun IT Enable       */
#define  CEC_IER_TXERRIE                     (0x00000800)       /*!< CEC Tx-Error IT Enable                 */
#define  CEC_IER_TXACKEIE                    (0x00001000)       /*!< CEC Tx Missing Acknowledge IT Enable   */

#define COMP_CSR_COMP1EN               (0x00000001) /*!< COMP1 enable */
#define COMP_CSR_COMP1SW1              (0x00000002) /*!< SW1 switch control */
#define COMP_CSR_COMP1MODE             (0x0000000C) /*!< COMP1 power mode */
#define COMP_CSR_COMP1MODE_0           (0x00000004) /*!< COMP1 power mode bit 0 */
#define COMP_CSR_COMP1MODE_1           (0x00000008) /*!< COMP1 power mode bit 1 */
#define COMP_CSR_COMP1INSEL            (0x00000070) /*!< COMP1 inverting input select */
#define COMP_CSR_COMP1INSEL_0          (0x00000010) /*!< COMP1 inverting input select bit 0 */
#define COMP_CSR_COMP1INSEL_1          (0x00000020) /*!< COMP1 inverting input select bit 1 */
#define COMP_CSR_COMP1INSEL_2          (0x00000040) /*!< COMP1 inverting input select bit 2 */
#define COMP_CSR_COMP1OUTSEL           (0x00000700) /*!< COMP1 output select */
#define COMP_CSR_COMP1OUTSEL_0         (0x00000100) /*!< COMP1 output select bit 0 */
#define COMP_CSR_COMP1OUTSEL_1         (0x00000200) /*!< COMP1 output select bit 1 */
#define COMP_CSR_COMP1OUTSEL_2         (0x00000400) /*!< COMP1 output select bit 2 */
#define COMP_CSR_COMP1POL              (0x00000800) /*!< COMP1 output polarity */
#define COMP_CSR_COMP1HYST             (0x00003000) /*!< COMP1 hysteresis */
#define COMP_CSR_COMP1HYST_0           (0x00001000) /*!< COMP1 hysteresis bit 0 */
#define COMP_CSR_COMP1HYST_1           (0x00002000) /*!< COMP1 hysteresis bit 1 */
#define COMP_CSR_COMP1OUT              (0x00004000) /*!< COMP1 output level */
#define COMP_CSR_COMP1LOCK             (0x00008000) /*!< COMP1 lock */
#define COMP_CSR_COMP2EN               (0x00010000) /*!< COMP2 enable */
#define COMP_CSR_COMP2MODE             (0x000C0000) /*!< COMP2 power mode */
#define COMP_CSR_COMP2MODE_0           (0x00040000) /*!< COMP2 power mode bit 0 */
#define COMP_CSR_COMP2MODE_1           (0x00080000) /*!< COMP2 power mode bit 1 */
#define COMP_CSR_COMP2INSEL            (0x00700000) /*!< COMP2 inverting input select */
#define COMP_CSR_COMP2INSEL_0          (0x00100000) /*!< COMP2 inverting input select bit 0 */
#define COMP_CSR_COMP2INSEL_1          (0x00200000) /*!< COMP2 inverting input select bit 1 */
#define COMP_CSR_COMP2INSEL_2          (0x00400000) /*!< COMP2 inverting input select bit 2 */
#define COMP_CSR_WNDWEN                (0x00800000) /*!< Comparators window mode enable */
#define COMP_CSR_COMP2OUTSEL           (0x07000000) /*!< COMP2 output select */
#define COMP_CSR_COMP2OUTSEL_0         (0x01000000) /*!< COMP2 output select bit 0 */
#define COMP_CSR_COMP2OUTSEL_1         (0x02000000) /*!< COMP2 output select bit 1 */
#define COMP_CSR_COMP2OUTSEL_2         (0x04000000) /*!< COMP2 output select bit 2 */
#define COMP_CSR_COMP2POL              (0x08000000) /*!< COMP2 output polarity */
#define COMP_CSR_COMP2HYST             (0x30000000) /*!< COMP2 hysteresis */
#define COMP_CSR_COMP2HYST_0           (0x10000000) /*!< COMP2 hysteresis bit 0 */
#define COMP_CSR_COMP2HYST_1           (0x20000000) /*!< COMP2 hysteresis bit 1 */
#define COMP_CSR_COMP2OUT              (0x40000000) /*!< COMP2 output level */
#define COMP_CSR_COMP2LOCK             (0x80000000) /*!< COMP2 lock */

#define  CRC_DR_DR                           (0xFFFFFFFF) /*!< Data register bits */

#define  CRC_IDR_IDR                         (0xFF)        /*!< General-purpose 8-bit data register bits */

#define  CRC_CR_RESET                        (0x00000001) /*!< RESET the CRC computation unit bit */
#define  CRC_CR_POLSIZE                      (0x00000018) /*!< Polynomial size bits (only for STM32F072 devices)*/
#define  CRC_CR_POLSIZE_0                    (0x00000008) /*!< Polynomial size bit 0 (only for STM32F072 devices) */
#define  CRC_CR_POLSIZE_1                    (0x00000010) /*!< Polynomial size bit 1 (only for STM32F072 devices) */
#define  CRC_CR_REV_IN                       (0x00000060) /*!< REV_IN Reverse Input Data bits */
#define  CRC_CR_REV_IN_0                     (0x00000020) /*!< REV_IN Bit 0 */
#define  CRC_CR_REV_IN_1                     (0x00000040) /*!< REV_IN Bit 1 */
#define  CRC_CR_REV_OUT                      (0x00000080) /*!< REV_OUT Reverse Output Data bits */

#define  CRC_INIT_INIT                       (0xFFFFFFFF) /*!< Initial CRC value bits */

#define  CRC_POL_POL                         (0xFFFFFFFF) /*!< Coefficients of the polynomial (only for STM32F072 devices) */


#define  CRS_CR_SYNCOKIE                     (0x00000001) /* SYNC event OK interrupt enable        */
#define  CRS_CR_SYNCWARNIE                   (0x00000002) /* SYNC warning interrupt enable         */
#define  CRS_CR_ERRIE                        (0x00000004) /* SYNC error interrupt enable           */
#define  CRS_CR_ESYNCIE                      (0x00000008) /* Expected SYNC(ESYNCF) interrupt Enable*/
#define  CRS_CR_CEN                          (0x00000020) /* Frequency error counter enable        */
#define  CRS_CR_AUTOTRIMEN                   (0x00000040) /* Automatic trimming enable             */
#define  CRS_CR_SWSYNC                       (0x00000080) /* A Software SYNC event is generated    */
#define  CRS_CR_TRIM                         (0x00003F00) /* HSI48 oscillator smooth trimming      */

#define  CRS_CFGR_RELOAD                     (0x0000FFFF) /* Counter reload value               */
#define  CRS_CFGR_FELIM                      (0x00FF0000) /* Frequency error limit              */
#define  CRS_CFGR_SYNCDIV                    (0x07000000) /* SYNC divider                       */
#define  CRS_CFGR_SYNCDIV_0                  (0x01000000) /* Bit 0                              */
#define  CRS_CFGR_SYNCDIV_1                  (0x02000000) /* Bit 1                              */
#define  CRS_CFGR_SYNCDIV_2                  (0x04000000) /* Bit 2                              */
#define  CRS_CFGR_SYNCSRC                    (0x30000000) /* SYNC signal source selection       */
#define  CRS_CFGR_SYNCSRC_0                  (0x10000000) /* Bit 0                              */
#define  CRS_CFGR_SYNCSRC_1                  (0x20000000) /* Bit 1                              */
#define  CRS_CFGR_SYNCPOL                    (0x80000000) /* SYNC polarity selection            */

#define  CRS_ISR_SYNCOKF                     (0x00000001) /* SYNC event OK flag             */
#define  CRS_ISR_SYNCWARNF                   (0x00000002) /* SYNC warning                   */
#define  CRS_ISR_ERRF                        (0x00000004) /* SYNC error flag                */
#define  CRS_ISR_ESYNCF                      (0x00000008) /* Expected SYNC flag             */
#define  CRS_ISR_SYNCERR                     (0x00000100) /* SYNC error                     */
#define  CRS_ISR_SYNCMISS                    (0x00000200) /* SYNC missed                    */
#define  CRS_ISR_TRIMOVF                     (0x00000400) /* Trimming overflow or underflow */
#define  CRS_ISR_FEDIR                       (0x00008000) /* Frequency error direction      */
#define  CRS_ISR_FECAP                       (0xFFFF0000) /* Frequency error capture        */

#define  CRS_ICR_SYNCOKC                     (0x00000001) /* SYNC event OK clear flag     */
#define  CRS_ICR_SYNCWARNC                   (0x00000002) /* SYNC warning clear flag      */
#define  CRS_ICR_ERRC                        (0x00000004) /* Error clear flag        */
#define  CRS_ICR_ESYNCC                      (0x00000008) /* Expected SYNC clear flag     */

#define  DAC_CR_EN1                          (0x00000001)        /*!< DAC channel1 enable */
#define  DAC_CR_BOFF1                        (0x00000002)        /*!< DAC channel1 output buffer disable */
#define  DAC_CR_TEN1                         (0x00000004)        /*!< DAC channel1 Trigger enable */

#define  DAC_CR_TSEL1                        (0x00000038)        /*!< TSEL1[2:0] (DAC channel1 Trigger selection) */
#define  DAC_CR_TSEL1_0                      (0x00000008)        /*!< Bit 0 */
#define  DAC_CR_TSEL1_1                      (0x00000010)        /*!< Bit 1 */
#define  DAC_CR_TSEL1_2                      (0x00000020)        /*!< Bit 2 */

#define  DAC_CR_WAVE1                        (0x000000C0)        /*!< WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable)(only for STM32F072 devices) */
#define  DAC_CR_WAVE1_0                      (0x00000040)        /*!< Bit 0 */
#define  DAC_CR_WAVE1_1                      (0x00000080)        /*!< Bit 1 */

#define  DAC_CR_MAMP1                        (0x00000F00)        /*!< MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) (only for STM32F072 devices) */
#define  DAC_CR_MAMP1_0                      (0x00000100)        /*!< Bit 0 */
#define  DAC_CR_MAMP1_1                      (0x00000200)        /*!< Bit 1 */
#define  DAC_CR_MAMP1_2                      (0x00000400)        /*!< Bit 2 */
#define  DAC_CR_MAMP1_3                      (0x00000800)        /*!< Bit 3 */

#define  DAC_CR_DMAEN1                       (0x00001000)        /*!< DAC channel1 DMA enable */
#define  DAC_CR_DMAUDRIE1                    (0x00002000)        /*!<DAC channel1 DMA Underrun Interrupt enable */
#define  DAC_CR_EN2                          (0x00010000)        /*!< DAC channel2 enable */
#define  DAC_CR_BOFF2                        (0x00020000)        /*!< DAC channel2 output buffer disable */
#define  DAC_CR_TEN2                         (0x00040000)        /*!< DAC channel2 Trigger enable */

#define  DAC_CR_TSEL2                        (0x00380000)        /*!< TSEL2[2:0] (DAC channel2 Trigger selection) */
#define  DAC_CR_TSEL2_0                      (0x00080000)        /*!< Bit 0 */
#define  DAC_CR_TSEL2_1                      (0x00100000)        /*!< Bit 1 */
#define  DAC_CR_TSEL2_2                      (0x00200000)        /*!< Bit 2 */

#define  DAC_CR_WAVE2                        (0x00C00000)        /*!< WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define  DAC_CR_WAVE2_0                      (0x00400000)        /*!< Bit 0 */
#define  DAC_CR_WAVE2_1                      (0x00800000)        /*!< Bit 1 */

#define  DAC_CR_MAMP2                        (0x0F000000)        /*!< MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
#define  DAC_CR_MAMP2_0                      (0x01000000)        /*!< Bit 0 */
#define  DAC_CR_MAMP2_1                      (0x02000000)        /*!< Bit 1 */
#define  DAC_CR_MAMP2_2                      (0x04000000)        /*!< Bit 2 */
#define  DAC_CR_MAMP2_3                      (0x08000000)        /*!< Bit 3 */

#define  DAC_CR_DMAEN2                       (0x10000000)        /*!< DAC channel2 DMA enabled */
#define  DAC_CR_DMAUDRIE2                    (0x20000000)        /*!<DAC channel2 DMA Underrun Interrupt enable */

#define  DAC_SWTRIGR_SWTRIG1                 (0x00000001)        /*!<DAC channel1 software trigger */
#define  DAC_SWTRIGR_SWTRIG2                 (0x00000002)        /*!<DAC channel2 software trigger */

#define  DAC_DHR12R1_DACC1DHR                (0x00000FFF)        /*!<DAC channel1 12-bit Right aligned data */

#define  DAC_DHR12L1_DACC1DHR                (0x0000FFF0)        /*!<DAC channel1 12-bit Left aligned data */

#define  DAC_DHR8R1_DACC1DHR                 (0x000000FF)         /*!<DAC channel1 8-bit Right aligned data */

#define  DAC_DOR1_DACC1DOR                   (0x00000FFF)        /*!<DAC channel1 data output */

#define  DAC_SR_DMAUDR1                      (0x00002000)        /*!< DAC channel1 DMA underrun flag */
#define  DAC_SR_DMAUDR2                      (0x20000000)        /*!< DAC channel2 DMA underrun flag (only for STM32F072 and STM32F042 devices) */


#define  DBGMCU_IDCODE_DEV_ID                (0x00000FFF)        /*!< Device Identifier */

#define  DBGMCU_IDCODE_REV_ID                (0xFFFF0000)        /*!< REV_ID[15:0] bits (Revision Identifier) */
#define  DBGMCU_IDCODE_REV_ID_0              (0x00010000)        /*!< Bit 0 */
#define  DBGMCU_IDCODE_REV_ID_1              (0x00020000)        /*!< Bit 1 */
#define  DBGMCU_IDCODE_REV_ID_2              (0x00040000)        /*!< Bit 2 */
#define  DBGMCU_IDCODE_REV_ID_3              (0x00080000)        /*!< Bit 3 */
#define  DBGMCU_IDCODE_REV_ID_4              (0x00100000)        /*!< Bit 4 */
#define  DBGMCU_IDCODE_REV_ID_5              (0x00200000)        /*!< Bit 5 */
#define  DBGMCU_IDCODE_REV_ID_6              (0x00400000)        /*!< Bit 6 */
#define  DBGMCU_IDCODE_REV_ID_7              (0x00800000)        /*!< Bit 7 */
#define  DBGMCU_IDCODE_REV_ID_8              (0x01000000)        /*!< Bit 8 */
#define  DBGMCU_IDCODE_REV_ID_9              (0x02000000)        /*!< Bit 9 */
#define  DBGMCU_IDCODE_REV_ID_10             (0x04000000)        /*!< Bit 10 */
#define  DBGMCU_IDCODE_REV_ID_11             (0x08000000)        /*!< Bit 11 */
#define  DBGMCU_IDCODE_REV_ID_12             (0x10000000)        /*!< Bit 12 */
#define  DBGMCU_IDCODE_REV_ID_13             (0x20000000)        /*!< Bit 13 */
#define  DBGMCU_IDCODE_REV_ID_14             (0x40000000)        /*!< Bit 14 */
#define  DBGMCU_IDCODE_REV_ID_15             (0x80000000)        /*!< Bit 15 */

#define  DBGMCU_CR_DBG_STOP                  (0x00000002)        /*!< Debug Stop Mode */
#define  DBGMCU_CR_DBG_STANDBY               (0x00000004)        /*!< Debug Standby mode */

#define  DBGMCU_APB1_FZ_DBG_TIM2_STOP        (0x00000001)        /*!< TIM2 counter stopped when core is halted */
#define  DBGMCU_APB1_FZ_DBG_TIM3_STOP        (0x00000002)        /*!< TIM3 counter stopped when core is halted */
#define  DBGMCU_APB1_FZ_DBG_TIM6_STOP        (0x00000010)        /*!< TIM6 counter stopped when core is halted (not available on STM32F042 devices)*/
#define  DBGMCU_APB1_FZ_DBG_TIM7_STOP        (0x00000020)        /*!< TIM7 counter stopped when core is halted (only for STM32F072 devices) */
#define  DBGMCU_APB1_FZ_DBG_TIM14_STOP       (0x00000100)        /*!< TIM14 counter stopped when core is halted */
#define  DBGMCU_APB1_FZ_DBG_RTC_STOP         (0x00000400)        /*!< RTC Calendar frozen when core is halted */
#define  DBGMCU_APB1_FZ_DBG_WWDG_STOP        (0x00000800)        /*!< Debug Window Watchdog stopped when Core is halted */
#define  DBGMCU_APB1_FZ_DBG_IWDG_STOP        (0x00001000)        /*!< Debug Independent Watchdog stopped when Core is halted */
#define  DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT    (0x00200000)   /*!< I2C1 SMBUS timeout mode stopped when Core is halted */
#define  DBGMCU_APB1_FZ_DBG_CAN_STOP         (0x02000000)        /*!< CAN debug stopped when Core is halted (only for STM32F072 devices) */

#define  DBGMCU_APB2_FZ_DBG_TIM1_STOP        (0x00000800)        /*!< TIM1 counter stopped when core is halted */
#define  DBGMCU_APB2_FZ_DBG_TIM15_STOP       (0x00010000)        /*!< TIM15 counter stopped when core is halted (not available on STM32F042 devices) */
#define  DBGMCU_APB2_FZ_DBG_TIM16_STOP       (0x00020000)        /*!< TIM16 counter stopped when core is halted */
#define  DBGMCU_APB2_FZ_DBG_TIM17_STOP       (0x00040000)        /*!< TIM17 counter stopped when core is halted */


#define  DMA_ISR_GIF1                        (0x00000001)        /*!< Channel 1 Global interrupt flag    */
#define  DMA_ISR_TCIF1                       (0x00000002)        /*!< Channel 1 Transfer Complete flag   */
#define  DMA_ISR_HTIF1                       (0x00000004)        /*!< Channel 1 Half Transfer flag       */
#define  DMA_ISR_TEIF1                       (0x00000008)        /*!< Channel 1 Transfer Error flag      */
#define  DMA_ISR_GIF2                        (0x00000010)        /*!< Channel 2 Global interrupt flag    */
#define  DMA_ISR_TCIF2                       (0x00000020)        /*!< Channel 2 Transfer Complete flag   */
#define  DMA_ISR_HTIF2                       (0x00000040)        /*!< Channel 2 Half Transfer flag       */
#define  DMA_ISR_TEIF2                       (0x00000080)        /*!< Channel 2 Transfer Error flag      */
#define  DMA_ISR_GIF3                        (0x00000100)        /*!< Channel 3 Global interrupt flag    */
#define  DMA_ISR_TCIF3                       (0x00000200)        /*!< Channel 3 Transfer Complete flag   */
#define  DMA_ISR_HTIF3                       (0x00000400)        /*!< Channel 3 Half Transfer flag       */
#define  DMA_ISR_TEIF3                       (0x00000800)        /*!< Channel 3 Transfer Error flag      */
#define  DMA_ISR_GIF4                        (0x00001000)        /*!< Channel 4 Global interrupt flag    */
#define  DMA_ISR_TCIF4                       (0x00002000)        /*!< Channel 4 Transfer Complete flag   */
#define  DMA_ISR_HTIF4                       (0x00004000)        /*!< Channel 4 Half Transfer flag       */
#define  DMA_ISR_TEIF4                       (0x00008000)        /*!< Channel 4 Transfer Error flag      */
#define  DMA_ISR_GIF5                        (0x00010000)        /*!< Channel 5 Global interrupt flag    */
#define  DMA_ISR_TCIF5                       (0x00020000)        /*!< Channel 5 Transfer Complete flag   */
#define  DMA_ISR_HTIF5                       (0x00040000)        /*!< Channel 5 Half Transfer flag       */
#define  DMA_ISR_TEIF5                       (0x00080000)        /*!< Channel 5 Transfer Error flag      */
#define  DMA_ISR_GIF6                        (0x00100000)        /*!< Channel 6 Global interrupt flag (only for STM32F072 devices) */
#define  DMA_ISR_TCIF6                       (0x00200000)        /*!< Channel 6 Transfer Complete flag (only for STM32F072 devices) */
#define  DMA_ISR_HTIF6                       (0x00400000)        /*!< Channel 6 Half Transfer flag (only for STM32F072 devices) */
#define  DMA_ISR_TEIF6                       (0x00800000)        /*!< Channel 6 Transfer Error flag (only for STM32F072 devices) */
#define  DMA_ISR_GIF7                        (0x01000000)        /*!< Channel 7 Global interrupt flag (only for STM32F072 devices) */
#define  DMA_ISR_TCIF7                       (0x02000000)        /*!< Channel 7 Transfer Complete flag (only for STM32F072 devices) */
#define  DMA_ISR_HTIF7                       (0x04000000)        /*!< Channel 7 Half Transfer flag (only for STM32F072 devices) */
#define  DMA_ISR_TEIF7                       (0x08000000)        /*!< Channel 7 Transfer Error flag (only for STM32F072 devices) */

#define  DMA_IFCR_CGIF1                      (0x00000001)        /*!< Channel 1 Global interrupt clear    */
#define  DMA_IFCR_CTCIF1                     (0x00000002)        /*!< Channel 1 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF1                     (0x00000004)        /*!< Channel 1 Half Transfer clear       */
#define  DMA_IFCR_CTEIF1                     (0x00000008)        /*!< Channel 1 Transfer Error clear      */
#define  DMA_IFCR_CGIF2                      (0x00000010)        /*!< Channel 2 Global interrupt clear    */
#define  DMA_IFCR_CTCIF2                     (0x00000020)        /*!< Channel 2 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF2                     (0x00000040)        /*!< Channel 2 Half Transfer clear       */
#define  DMA_IFCR_CTEIF2                     (0x00000080)        /*!< Channel 2 Transfer Error clear      */
#define  DMA_IFCR_CGIF3                      (0x00000100)        /*!< Channel 3 Global interrupt clear    */
#define  DMA_IFCR_CTCIF3                     (0x00000200)        /*!< Channel 3 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF3                     (0x00000400)        /*!< Channel 3 Half Transfer clear       */
#define  DMA_IFCR_CTEIF3                     (0x00000800)        /*!< Channel 3 Transfer Error clear      */
#define  DMA_IFCR_CGIF4                      (0x00001000)        /*!< Channel 4 Global interrupt clear    */
#define  DMA_IFCR_CTCIF4                     (0x00002000)        /*!< Channel 4 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF4                     (0x00004000)        /*!< Channel 4 Half Transfer clear       */
#define  DMA_IFCR_CTEIF4                     (0x00008000)        /*!< Channel 4 Transfer Error clear      */
#define  DMA_IFCR_CGIF5                      (0x00010000)        /*!< Channel 5 Global interrupt clear    */
#define  DMA_IFCR_CTCIF5                     (0x00020000)        /*!< Channel 5 Transfer Complete clear   */
#define  DMA_IFCR_CHTIF5                     (0x00040000)        /*!< Channel 5 Half Transfer clear       */
#define  DMA_IFCR_CTEIF5                     (0x00080000)        /*!< Channel 5 Transfer Error clear      */
#define  DMA_IFCR_CGIF6                      (0x00100000)        /*!< Channel 6 Global interrupt clear (only for STM32F072 devices) */
#define  DMA_IFCR_CTCIF6                     (0x00200000)        /*!< Channel 6 Transfer Complete clear (only for STM32F072 devices) */
#define  DMA_IFCR_CHTIF6                     (0x00400000)        /*!< Channel 6 Half Transfer clear (only for STM32F072 devices) */
#define  DMA_IFCR_CTEIF6                     (0x00800000)        /*!< Channel 6 Transfer Error clear (only for STM32F072 devices) */
#define  DMA_IFCR_CGIF7                      (0x01000000)        /*!< Channel 7 Global interrupt clear (only for STM32F072 devices) */
#define  DMA_IFCR_CTCIF7                     (0x02000000)        /*!< Channel 7 Transfer Complete clear (only for STM32F072 devices) */
#define  DMA_IFCR_CHTIF7                     (0x04000000)        /*!< Channel 7 Half Transfer clear (only for STM32F072 devices) */
#define  DMA_IFCR_CTEIF7                     (0x08000000)        /*!< Channel 7 Transfer Error clear (only for STM32F072 devices) */

#define  DMA_CCR_EN                          (0x00000001)        /*!< Channel enable                      */
#define  DMA_CCR_TCIE                        (0x00000002)        /*!< Transfer complete interrupt enable  */
#define  DMA_CCR_HTIE                        (0x00000004)        /*!< Half Transfer interrupt enable      */
#define  DMA_CCR_TEIE                        (0x00000008)        /*!< Transfer error interrupt enable     */
#define  DMA_CCR_DIR                         (0x00000010)        /*!< Data transfer direction             */
#define  DMA_CCR_CIRC                        (0x00000020)        /*!< Circular mode                       */
#define  DMA_CCR_PINC                        (0x00000040)        /*!< Peripheral increment mode           */
#define  DMA_CCR_MINC                        (0x00000080)        /*!< Memory increment mode               */

#define  DMA_CCR_PSIZE                       (0x00000300)        /*!< PSIZE[1:0] bits (Peripheral size)   */
#define  DMA_CCR_PSIZE_0                     (0x00000100)        /*!< Bit 0                               */
#define  DMA_CCR_PSIZE_1                     (0x00000200)        /*!< Bit 1                               */

#define  DMA_CCR_MSIZE                       (0x00000C00)        /*!< MSIZE[1:0] bits (Memory size)       */
#define  DMA_CCR_MSIZE_0                     (0x00000400)        /*!< Bit 0                               */
#define  DMA_CCR_MSIZE_1                     (0x00000800)        /*!< Bit 1                               */

#define  DMA_CCR_PL                          (0x00003000)        /*!< PL[1:0] bits(Channel Priority level)*/
#define  DMA_CCR_PL_0                        (0x00001000)        /*!< Bit 0                               */
#define  DMA_CCR_PL_1                        (0x00002000)        /*!< Bit 1                               */

#define  DMA_CCR_MEM2MEM                     (0x00004000)        /*!< Memory to memory mode               */

#define  DMA_CNDTR_NDT                       (0x0000FFFF)        /*!< Number of data to Transfer          */

#define  DMA_CPAR_PA                         (0xFFFFFFFF)        /*!< Peripheral Address                  */

#define  DMA_CMAR_MA                         (0xFFFFFFFF)        /*!< Memory Address                      */

#define  EXTI_IMR_MR0                        (0x00000001)        /*!< Interrupt Mask on line 0  */
#define  EXTI_IMR_MR1                        (0x00000002)        /*!< Interrupt Mask on line 1  */
#define  EXTI_IMR_MR2                        (0x00000004)        /*!< Interrupt Mask on line 2  */
#define  EXTI_IMR_MR3                        (0x00000008)        /*!< Interrupt Mask on line 3  */
#define  EXTI_IMR_MR4                        (0x00000010)        /*!< Interrupt Mask on line 4  */
#define  EXTI_IMR_MR5                        (0x00000020)        /*!< Interrupt Mask on line 5  */
#define  EXTI_IMR_MR6                        (0x00000040)        /*!< Interrupt Mask on line 6  */
#define  EXTI_IMR_MR7                        (0x00000080)        /*!< Interrupt Mask on line 7  */
#define  EXTI_IMR_MR8                        (0x00000100)        /*!< Interrupt Mask on line 8  */
#define  EXTI_IMR_MR9                        (0x00000200)        /*!< Interrupt Mask on line 9  */
#define  EXTI_IMR_MR10                       (0x00000400)        /*!< Interrupt Mask on line 10 */
#define  EXTI_IMR_MR11                       (0x00000800)        /*!< Interrupt Mask on line 11 */
#define  EXTI_IMR_MR12                       (0x00001000)        /*!< Interrupt Mask on line 12 */
#define  EXTI_IMR_MR13                       (0x00002000)        /*!< Interrupt Mask on line 13 */
#define  EXTI_IMR_MR14                       (0x00004000)        /*!< Interrupt Mask on line 14 */
#define  EXTI_IMR_MR15                       (0x00008000)        /*!< Interrupt Mask on line 15 */
#define  EXTI_IMR_MR16                       (0x00010000)        /*!< Interrupt Mask on line 16 */
#define  EXTI_IMR_MR17                       (0x00020000)        /*!< Interrupt Mask on line 17 */
#define  EXTI_IMR_MR18                       (0x00040000)        /*!< Interrupt Mask on line 18 */
#define  EXTI_IMR_MR19                       (0x00080000)        /*!< Interrupt Mask on line 19 */
#define  EXTI_IMR_MR20                       (0x00100000)        /*!< Interrupt Mask on line 20 */
#define  EXTI_IMR_MR21                       (0x00200000)        /*!< Interrupt Mask on line 21 */
#define  EXTI_IMR_MR22                       (0x00400000)        /*!< Interrupt Mask on line 22 */
#define  EXTI_IMR_MR23                       (0x00800000)        /*!< Interrupt Mask on line 23 */
#define  EXTI_IMR_MR24                       (0x01000000)        /*!< Interrupt Mask on line 24 */
#define  EXTI_IMR_MR25                       (0x02000000)        /*!< Interrupt Mask on line 25 */
#define  EXTI_IMR_MR26                       (0x04000000)        /*!< Interrupt Mask on line 26 */
#define  EXTI_IMR_MR27                       (0x08000000)        /*!< Interrupt Mask on line 27 */
#define  EXTI_IMR_MR28                       (0x10000000)        /*!< Interrupt Mask on line 28 */
#define  EXTI_IMR_MR29                       (0x20000000)        /*!< Interrupt Mask on line 29 */
#define  EXTI_IMR_MR30                       (0x40000000)        /*!< Interrupt Mask on line 30 */
#define  EXTI_IMR_MR31                       (0x80000000)        /*!< Interrupt Mask on line 31 */

#define  EXTI_EMR_MR0                        (0x00000001)        /*!< Event Mask on line 0  */
#define  EXTI_EMR_MR1                        (0x00000002)        /*!< Event Mask on line 1  */
#define  EXTI_EMR_MR2                        (0x00000004)        /*!< Event Mask on line 2  */
#define  EXTI_EMR_MR3                        (0x00000008)        /*!< Event Mask on line 3  */
#define  EXTI_EMR_MR4                        (0x00000010)        /*!< Event Mask on line 4  */
#define  EXTI_EMR_MR5                        (0x00000020)        /*!< Event Mask on line 5  */
#define  EXTI_EMR_MR6                        (0x00000040)        /*!< Event Mask on line 6  */
#define  EXTI_EMR_MR7                        (0x00000080)        /*!< Event Mask on line 7  */
#define  EXTI_EMR_MR8                        (0x00000100)        /*!< Event Mask on line 8  */
#define  EXTI_EMR_MR9                        (0x00000200)        /*!< Event Mask on line 9  */
#define  EXTI_EMR_MR10                       (0x00000400)        /*!< Event Mask on line 10 */
#define  EXTI_EMR_MR11                       (0x00000800)        /*!< Event Mask on line 11 */
#define  EXTI_EMR_MR12                       (0x00001000)        /*!< Event Mask on line 12 */
#define  EXTI_EMR_MR13                       (0x00002000)        /*!< Event Mask on line 13 */
#define  EXTI_EMR_MR14                       (0x00004000)        /*!< Event Mask on line 14 */
#define  EXTI_EMR_MR15                       (0x00008000)        /*!< Event Mask on line 15 */
#define  EXTI_EMR_MR16                       (0x00010000)        /*!< Event Mask on line 16 */
#define  EXTI_EMR_MR17                       (0x00020000)        /*!< Event Mask on line 17 */
#define  EXTI_EMR_MR18                       (0x00040000)        /*!< Event Mask on line 18 */
#define  EXTI_EMR_MR19                       (0x00080000)        /*!< Event Mask on line 19 */
#define  EXTI_EMR_MR20                       (0x00100000)        /*!< Event Mask on line 20 */
#define  EXTI_EMR_MR21                       (0x00200000)        /*!< Event Mask on line 21 */
#define  EXTI_EMR_MR22                       (0x00400000)        /*!< Event Mask on line 22 */
#define  EXTI_EMR_MR23                       (0x00800000)        /*!< Event Mask on line 23 */
#define  EXTI_EMR_MR24                       (0x01000000)        /*!< Event Mask on line 24 */
#define  EXTI_EMR_MR25                       (0x02000000)        /*!< Event Mask on line 25 */
#define  EXTI_EMR_MR26                       (0x04000000)        /*!< Event Mask on line 26 */
#define  EXTI_EMR_MR27                       (0x08000000)        /*!< Event Mask on line 27 */
#define  EXTI_EMR_MR28                       (0x10000000)        /*!< Event Mask on line 28 */
#define  EXTI_EMR_MR29                       (0x20000000)        /*!< Event Mask on line 29 */
#define  EXTI_EMR_MR30                       (0x40000000)        /*!< Event Mask on line 30 */
#define  EXTI_EMR_MR31                       (0x80000000)        /*!< Event Mask on line 31 */

#define  EXTI_RTSR_TR0                       (0x00000001)        /*!< Rising trigger event configuration bit of line 0 */
#define  EXTI_RTSR_TR1                       (0x00000002)        /*!< Rising trigger event configuration bit of line 1 */
#define  EXTI_RTSR_TR2                       (0x00000004)        /*!< Rising trigger event configuration bit of line 2 */
#define  EXTI_RTSR_TR3                       (0x00000008)        /*!< Rising trigger event configuration bit of line 3 */
#define  EXTI_RTSR_TR4                       (0x00000010)        /*!< Rising trigger event configuration bit of line 4 */
#define  EXTI_RTSR_TR5                       (0x00000020)        /*!< Rising trigger event configuration bit of line 5 */
#define  EXTI_RTSR_TR6                       (0x00000040)        /*!< Rising trigger event configuration bit of line 6 */
#define  EXTI_RTSR_TR7                       (0x00000080)        /*!< Rising trigger event configuration bit of line 7 */
#define  EXTI_RTSR_TR8                       (0x00000100)        /*!< Rising trigger event configuration bit of line 8 */
#define  EXTI_RTSR_TR9                       (0x00000200)        /*!< Rising trigger event configuration bit of line 9 */
#define  EXTI_RTSR_TR10                      (0x00000400)        /*!< Rising trigger event configuration bit of line 10 */
#define  EXTI_RTSR_TR11                      (0x00000800)        /*!< Rising trigger event configuration bit of line 11 */
#define  EXTI_RTSR_TR12                      (0x00001000)        /*!< Rising trigger event configuration bit of line 12 */
#define  EXTI_RTSR_TR13                      (0x00002000)        /*!< Rising trigger event configuration bit of line 13 */
#define  EXTI_RTSR_TR14                      (0x00004000)        /*!< Rising trigger event configuration bit of line 14 */
#define  EXTI_RTSR_TR15                      (0x00008000)        /*!< Rising trigger event configuration bit of line 15 */
#define  EXTI_RTSR_TR16                      (0x00010000)        /*!< Rising trigger event configuration bit of line 16 */
#define  EXTI_RTSR_TR17                      (0x00020000)        /*!< Rising trigger event configuration bit of line 17 */
#define  EXTI_RTSR_TR19                      (0x00080000)        /*!< Rising trigger event configuration bit of line 19 */
#define  EXTI_RTSR_TR20                      (0x00100000)        /*!< Rising trigger event configuration bit of line 20 */
#define  EXTI_RTSR_TR21                      (0x00200000)        /*!< Rising trigger event configuration bit of line 21 */
#define  EXTI_RTSR_TR22                      (0x00400000)        /*!< Rising trigger event configuration bit of line 22 */

#define  EXTI_FTSR_TR0                       (0x00000001)        /*!< Falling trigger event configuration bit of line 0 */
#define  EXTI_FTSR_TR1                       (0x00000002)        /*!< Falling trigger event configuration bit of line 1 */
#define  EXTI_FTSR_TR2                       (0x00000004)        /*!< Falling trigger event configuration bit of line 2 */
#define  EXTI_FTSR_TR3                       (0x00000008)        /*!< Falling trigger event configuration bit of line 3 */
#define  EXTI_FTSR_TR4                       (0x00000010)        /*!< Falling trigger event configuration bit of line 4 */
#define  EXTI_FTSR_TR5                       (0x00000020)        /*!< Falling trigger event configuration bit of line 5 */
#define  EXTI_FTSR_TR6                       (0x00000040)        /*!< Falling trigger event configuration bit of line 6 */
#define  EXTI_FTSR_TR7                       (0x00000080)        /*!< Falling trigger event configuration bit of line 7 */
#define  EXTI_FTSR_TR8                       (0x00000100)        /*!< Falling trigger event configuration bit of line 8 */
#define  EXTI_FTSR_TR9                       (0x00000200)        /*!< Falling trigger event configuration bit of line 9 */
#define  EXTI_FTSR_TR10                      (0x00000400)        /*!< Falling trigger event configuration bit of line 10 */
#define  EXTI_FTSR_TR11                      (0x00000800)        /*!< Falling trigger event configuration bit of line 11 */
#define  EXTI_FTSR_TR12                      (0x00001000)        /*!< Falling trigger event configuration bit of line 12 */
#define  EXTI_FTSR_TR13                      (0x00002000)        /*!< Falling trigger event configuration bit of line 13 */
#define  EXTI_FTSR_TR14                      (0x00004000)        /*!< Falling trigger event configuration bit of line 14 */
#define  EXTI_FTSR_TR15                      (0x00008000)        /*!< Falling trigger event configuration bit of line 15 */
#define  EXTI_FTSR_TR16                      (0x00010000)        /*!< Falling trigger event configuration bit of line 16 */
#define  EXTI_FTSR_TR17                      (0x00020000)        /*!< Falling trigger event configuration bit of line 17 */
#define  EXTI_FTSR_TR19                      (0x00080000)        /*!< Falling trigger event configuration bit of line 19 */
#define  EXTI_FTSR_TR20                      (0x00100000)        /*!< Falling trigger event configuration bit of line 20 */
#define  EXTI_FTSR_TR21                      (0x00200000)        /*!< Falling trigger event configuration bit of line 21 */
#define  EXTI_FTSR_TR22                      (0x00400000)        /*!< Falling trigger event configuration bit of line 22 */

#define  EXTI_SWIER_SWIER0                   (0x00000001)        /*!< Software Interrupt on line 0  */
#define  EXTI_SWIER_SWIER1                   (0x00000002)        /*!< Software Interrupt on line 1  */
#define  EXTI_SWIER_SWIER2                   (0x00000004)        /*!< Software Interrupt on line 2  */
#define  EXTI_SWIER_SWIER3                   (0x00000008)        /*!< Software Interrupt on line 3  */
#define  EXTI_SWIER_SWIER4                   (0x00000010)        /*!< Software Interrupt on line 4  */
#define  EXTI_SWIER_SWIER5                   (0x00000020)        /*!< Software Interrupt on line 5  */
#define  EXTI_SWIER_SWIER6                   (0x00000040)        /*!< Software Interrupt on line 6  */
#define  EXTI_SWIER_SWIER7                   (0x00000080)        /*!< Software Interrupt on line 7  */
#define  EXTI_SWIER_SWIER8                   (0x00000100)        /*!< Software Interrupt on line 8  */
#define  EXTI_SWIER_SWIER9                   (0x00000200)        /*!< Software Interrupt on line 9  */
#define  EXTI_SWIER_SWIER10                  (0x00000400)        /*!< Software Interrupt on line 10 */
#define  EXTI_SWIER_SWIER11                  (0x00000800)        /*!< Software Interrupt on line 11 */
#define  EXTI_SWIER_SWIER12                  (0x00001000)        /*!< Software Interrupt on line 12 */
#define  EXTI_SWIER_SWIER13                  (0x00002000)        /*!< Software Interrupt on line 13 */
#define  EXTI_SWIER_SWIER14                  (0x00004000)        /*!< Software Interrupt on line 14 */
#define  EXTI_SWIER_SWIER15                  (0x00008000)        /*!< Software Interrupt on line 15 */
#define  EXTI_SWIER_SWIER16                  (0x00010000)        /*!< Software Interrupt on line 16 */
#define  EXTI_SWIER_SWIER17                  (0x00020000)        /*!< Software Interrupt on line 17 */
#define  EXTI_SWIER_SWIER19                  (0x00080000)        /*!< Software Interrupt on line 19 */
#define  EXTI_SWIER_SWIER20                  (0x00100000)        /*!< Software Interrupt on line 20 */
#define  EXTI_SWIER_SWIER21                  (0x00200000)        /*!< Software Interrupt on line 21 */
#define  EXTI_SWIER_SWIER22                  (0x00400000)        /*!< Software Interrupt on line 22 */

#define  EXTI_PR_PR0                         (0x00000001)        /*!< Pending bit 0  */
#define  EXTI_PR_PR1                         (0x00000002)        /*!< Pending bit 1  */
#define  EXTI_PR_PR2                         (0x00000004)        /*!< Pending bit 2  */
#define  EXTI_PR_PR3                         (0x00000008)        /*!< Pending bit 3  */
#define  EXTI_PR_PR4                         (0x00000010)        /*!< Pending bit 4  */
#define  EXTI_PR_PR5                         (0x00000020)        /*!< Pending bit 5  */
#define  EXTI_PR_PR6                         (0x00000040)        /*!< Pending bit 6  */
#define  EXTI_PR_PR7                         (0x00000080)        /*!< Pending bit 7  */
#define  EXTI_PR_PR8                         (0x00000100)        /*!< Pending bit 8  */
#define  EXTI_PR_PR9                         (0x00000200)        /*!< Pending bit 9  */
#define  EXTI_PR_PR10                        (0x00000400)        /*!< Pending bit 10 */
#define  EXTI_PR_PR11                        (0x00000800)        /*!< Pending bit 11 */
#define  EXTI_PR_PR12                        (0x00001000)        /*!< Pending bit 12 */
#define  EXTI_PR_PR13                        (0x00002000)        /*!< Pending bit 13 */
#define  EXTI_PR_PR14                        (0x00004000)        /*!< Pending bit 14 */
#define  EXTI_PR_PR15                        (0x00008000)        /*!< Pending bit 15 */
#define  EXTI_PR_PR16                        (0x00010000)        /*!< Pending bit 16 */
#define  EXTI_PR_PR17                        (0x00020000)        /*!< Pending bit 17 */
#define  EXTI_PR_PR19                        (0x00080000)        /*!< Pending bit 19 */
#define  EXTI_PR_PR20                        (0x00100000)        /*!< Pending bit 20 */
#define  EXTI_PR_PR21                        (0x00200000)        /*!< Pending bit 21 */
#define  EXTI_PR_PR22                        (0x00400000)        /*!< Pending bit 22 */


#define  FLASH_ACR_LATENCY                   (0x00000001)        /*!< LATENCY bit (Latency) */

#define  FLASH_ACR_PRFTBE                    (0x00000010)        /*!< Prefetch Buffer Enable */
#define  FLASH_ACR_PRFTBS                    (0x00000020)        /*!< Prefetch Buffer Status */

#define  FLASH_KEYR_FKEYR                    (0xFFFFFFFF)        /*!< FPEC Key */

#define  FLASH_OPTKEYR_OPTKEYR               (0xFFFFFFFF)        /*!< Option Byte Key */

#define FLASH_FKEY1                          (0x45670123)        /*!< Flash program erase key1 */
#define FLASH_FKEY2                          (0xCDEF89AB)        /*!< Flash program erase key2: used with FLASH_PEKEY1
                                                                                to unlock the write access to the FPEC. */

#define FLASH_OPTKEY1                        (0x45670123)        /*!< Flash option key1 */
#define FLASH_OPTKEY2                        (0xCDEF89AB)        /*!< Flash option key2: used with FLASH_OPTKEY1 to
                                                                                unlock the write access to the option byte block */

#define  FLASH_SR_BSY                        (0x00000001)        /*!< Busy */
#define  FLASH_SR_PGERR                      (0x00000004)        /*!< Programming Error */
#define  FLASH_SR_WRPRTERR                   (0x00000010)        /*!< Write Protection Error */
#define  FLASH_SR_EOP                        (0x00000020)        /*!< End of operation */
#define  FLASH_SR_WRPERR                     FLASH_SR_WRPRTERR             /*!< Legacy of Write Protection Error */

#define  FLASH_CR_PG                         (0x00000001)        /*!< Programming */
#define  FLASH_CR_PER                        (0x00000002)        /*!< Page Erase */
#define  FLASH_CR_MER                        (0x00000004)        /*!< Mass Erase */
#define  FLASH_CR_OPTPG                      (0x00000010)        /*!< Option Byte Programming */
#define  FLASH_CR_OPTER                      (0x00000020)        /*!< Option Byte Erase */
#define  FLASH_CR_STRT                       (0x00000040)        /*!< Start */
#define  FLASH_CR_LOCK                       (0x00000080)        /*!< Lock */
#define  FLASH_CR_OPTWRE                     (0x00000200)        /*!< Option Bytes Write Enable */
#define  FLASH_CR_ERRIE                      (0x00000400)        /*!< Error Interrupt Enable */
#define  FLASH_CR_EOPIE                      (0x00001000)        /*!< End of operation interrupt enable */
#define  FLASH_CR_OBL_LAUNCH                 (0x00002000)        /*!< Option Bytes Loader Launch */

#define  FLASH_AR_FAR                        (0xFFFFFFFF)        /*!< Flash Address */

#define  FLASH_OBR_OPTERR                    (0x00000001)        /*!< Option Byte Error */
#define  FLASH_OBR_RDPRT1                    (0x00000002)        /*!< Read protection Level bit 1 */
#define  FLASH_OBR_RDPRT2                    (0x00000004)        /*!< Read protection Level bit 2 */

#define  FLASH_OBR_USER                      (0x00003700)        /*!< User Option Bytes */
#define  FLASH_OBR_IWDG_SW                   (0x00000100)        /*!< IWDG SW */
#define  FLASH_OBR_nRST_STOP                 (0x00000200)        /*!< nRST_STOP */
#define  FLASH_OBR_nRST_STDBY                (0x00000400)        /*!< nRST_STDBY */
#define  FLASH_OBR_nBOOT0                    (0x00000800)        /*!< nBOOT0 */
#define  FLASH_OBR_nBOOT1                    (0x00001000)        /*!< nBOOT1 */
#define  FLASH_OBR_VDDA_MONITOR              (0x00002000)        /*!< VDDA power supply supervisor */
#define  FLASH_OBR_RAM_PARITY_CHECK          (0x00004000)        /*!< RAM Parity Check */
#define  FLASH_OBR_nBOOT0_SW                 (0x00008000)        /*!< nBOOT0 SW  (available only in the STM32F042 devices)*/
#define  FLASH_OBR_DATA0                     (0x00FF0000)        /*!< DATA0 */
#define  FLASH_OBR_DATA1                     (0xFF000000)        /*!< DATA0 */

#define FLASH_OBR_BOOT1                      FLASH_OBR_nBOOT1

#define FLASH_OBR_VDDA_ANALOG                FLASH_OBR_VDDA_MONITOR

#define  FLASH_WRPR_WRP                      (0xFFFFFFFF)        /*!< Write Protect */


#define  OB_RDP_RDP                          (0x000000FF)        /*!< Read protection option byte */
#define  OB_RDP_nRDP                         (0x0000FF00)        /*!< Read protection complemented option byte */

#define  OB_USER_USER                        (0x00FF0000)        /*!< User option byte */
#define  OB_USER_nUSER                       (0xFF000000)        /*!< User complemented option byte */

#define  OB_WRP0_WRP0                        (0x000000FF)        /*!< Flash memory write protection option bytes */
#define  OB_WRP0_nWRP0                       (0x0000FF00)        /*!< Flash memory write protection complemented option bytes */

#define  OB_WRP1_WRP1                        (0x00FF0000)        /*!< Flash memory write protection option bytes */
#define  OB_WRP1_nWRP1                       (0xFF000000)        /*!< Flash memory write protection complemented option bytes */

#define  OB_WRP2_WRP2                        (0x000000FF)        /*!< Flash memory write protection option bytes (only for STM32F072 devices) */
#define  OB_WRP2_nWRP2                       (0x0000FF00)        /*!< Flash memory write protection complemented option bytes (only for STM32F072 devices) */

#define  OB_WRP3_WRP3                        (0x00FF0000)        /*!< Flash memory write protection option bytes (only for STM32F072 devices) */
#define  OB_WRP3_nWRP3                       (0xFF000000)        /*!< Flash memory write protection complemented option bytes (only for STM32F072 devices) */

#define GPIO_MODER_MODER0          (0x00000003)
#define GPIO_MODER_MODER0_0        (0x00000001)
#define GPIO_MODER_MODER0_1        (0x00000002)
#define GPIO_MODER_MODER1          (0x0000000C)
#define GPIO_MODER_MODER1_0        (0x00000004)
#define GPIO_MODER_MODER1_1        (0x00000008)
#define GPIO_MODER_MODER2          (0x00000030)
#define GPIO_MODER_MODER2_0        (0x00000010)
#define GPIO_MODER_MODER2_1        (0x00000020)
#define GPIO_MODER_MODER3          (0x000000C0)
#define GPIO_MODER_MODER3_0        (0x00000040)
#define GPIO_MODER_MODER3_1        (0x00000080)
#define GPIO_MODER_MODER4          (0x00000300)
#define GPIO_MODER_MODER4_0        (0x00000100)
#define GPIO_MODER_MODER4_1        (0x00000200)
#define GPIO_MODER_MODER5          (0x00000C00)
#define GPIO_MODER_MODER5_0        (0x00000400)
#define GPIO_MODER_MODER5_1        (0x00000800)
#define GPIO_MODER_MODER6          (0x00003000)
#define GPIO_MODER_MODER6_0        (0x00001000)
#define GPIO_MODER_MODER6_1        (0x00002000)
#define GPIO_MODER_MODER7          (0x0000C000)
#define GPIO_MODER_MODER7_0        (0x00004000)
#define GPIO_MODER_MODER7_1        (0x00008000)
#define GPIO_MODER_MODER8          (0x00030000)
#define GPIO_MODER_MODER8_0        (0x00010000)
#define GPIO_MODER_MODER8_1        (0x00020000)
#define GPIO_MODER_MODER9          (0x000C0000)
#define GPIO_MODER_MODER9_0        (0x00040000)
#define GPIO_MODER_MODER9_1        (0x00080000)
#define GPIO_MODER_MODER10         (0x00300000)
#define GPIO_MODER_MODER10_0       (0x00100000)
#define GPIO_MODER_MODER10_1       (0x00200000)
#define GPIO_MODER_MODER11         (0x00C00000)
#define GPIO_MODER_MODER11_0       (0x00400000)
#define GPIO_MODER_MODER11_1       (0x00800000)
#define GPIO_MODER_MODER12         (0x03000000)
#define GPIO_MODER_MODER12_0       (0x01000000)
#define GPIO_MODER_MODER12_1       (0x02000000)
#define GPIO_MODER_MODER13         (0x0C000000)
#define GPIO_MODER_MODER13_0       (0x04000000)
#define GPIO_MODER_MODER13_1       (0x08000000)
#define GPIO_MODER_MODER14         (0x30000000)
#define GPIO_MODER_MODER14_0       (0x10000000)
#define GPIO_MODER_MODER14_1       (0x20000000)
#define GPIO_MODER_MODER15         (0xC0000000)
#define GPIO_MODER_MODER15_0       (0x40000000)
#define GPIO_MODER_MODER15_1       (0x80000000)

#define GPIO_OTYPER_OT_0           (0x00000001)
#define GPIO_OTYPER_OT_1           (0x00000002)
#define GPIO_OTYPER_OT_2           (0x00000004)
#define GPIO_OTYPER_OT_3           (0x00000008)
#define GPIO_OTYPER_OT_4           (0x00000010)
#define GPIO_OTYPER_OT_5           (0x00000020)
#define GPIO_OTYPER_OT_6           (0x00000040)
#define GPIO_OTYPER_OT_7           (0x00000080)
#define GPIO_OTYPER_OT_8           (0x00000100)
#define GPIO_OTYPER_OT_9           (0x00000200)
#define GPIO_OTYPER_OT_10          (0x00000400)
#define GPIO_OTYPER_OT_11          (0x00000800)
#define GPIO_OTYPER_OT_12          (0x00001000)
#define GPIO_OTYPER_OT_13          (0x00002000)
#define GPIO_OTYPER_OT_14          (0x00004000)
#define GPIO_OTYPER_OT_15          (0x00008000)

#define GPIO_OSPEEDR_OSPEEDR0     (0x00000003)
#define GPIO_OSPEEDR_OSPEEDR0_0   (0x00000001)
#define GPIO_OSPEEDR_OSPEEDR0_1   (0x00000002)
#define GPIO_OSPEEDR_OSPEEDR1     (0x0000000C)
#define GPIO_OSPEEDR_OSPEEDR1_0   (0x00000004)
#define GPIO_OSPEEDR_OSPEEDR1_1   (0x00000008)
#define GPIO_OSPEEDR_OSPEEDR2     (0x00000030)
#define GPIO_OSPEEDR_OSPEEDR2_0   (0x00000010)
#define GPIO_OSPEEDR_OSPEEDR2_1   (0x00000020)
#define GPIO_OSPEEDR_OSPEEDR3     (0x000000C0)
#define GPIO_OSPEEDR_OSPEEDR3_0   (0x00000040)
#define GPIO_OSPEEDR_OSPEEDR3_1   (0x00000080)
#define GPIO_OSPEEDR_OSPEEDR4     (0x00000300)
#define GPIO_OSPEEDR_OSPEEDR4_0   (0x00000100)
#define GPIO_OSPEEDR_OSPEEDR4_1   (0x00000200)
#define GPIO_OSPEEDR_OSPEEDR5     (0x00000C00)
#define GPIO_OSPEEDR_OSPEEDR5_0   (0x00000400)
#define GPIO_OSPEEDR_OSPEEDR5_1   (0x00000800)
#define GPIO_OSPEEDR_OSPEEDR6     (0x00003000)
#define GPIO_OSPEEDR_OSPEEDR6_0   (0x00001000)
#define GPIO_OSPEEDR_OSPEEDR6_1   (0x00002000)
#define GPIO_OSPEEDR_OSPEEDR7     (0x0000C000)
#define GPIO_OSPEEDR_OSPEEDR7_0   (0x00004000)
#define GPIO_OSPEEDR_OSPEEDR7_1   (0x00008000)
#define GPIO_OSPEEDR_OSPEEDR8     (0x00030000)
#define GPIO_OSPEEDR_OSPEEDR8_0   (0x00010000)
#define GPIO_OSPEEDR_OSPEEDR8_1   (0x00020000)
#define GPIO_OSPEEDR_OSPEEDR9     (0x000C0000)
#define GPIO_OSPEEDR_OSPEEDR9_0   (0x00040000)
#define GPIO_OSPEEDR_OSPEEDR9_1   (0x00080000)
#define GPIO_OSPEEDR_OSPEEDR10    (0x00300000)
#define GPIO_OSPEEDR_OSPEEDR10_0  (0x00100000)
#define GPIO_OSPEEDR_OSPEEDR10_1  (0x00200000)
#define GPIO_OSPEEDR_OSPEEDR11    (0x00C00000)
#define GPIO_OSPEEDR_OSPEEDR11_0  (0x00400000)
#define GPIO_OSPEEDR_OSPEEDR11_1  (0x00800000)
#define GPIO_OSPEEDR_OSPEEDR12    (0x03000000)
#define GPIO_OSPEEDR_OSPEEDR12_0  (0x01000000)
#define GPIO_OSPEEDR_OSPEEDR12_1  (0x02000000)
#define GPIO_OSPEEDR_OSPEEDR13    (0x0C000000)
#define GPIO_OSPEEDR_OSPEEDR13_0  (0x04000000)
#define GPIO_OSPEEDR_OSPEEDR13_1  (0x08000000)
#define GPIO_OSPEEDR_OSPEEDR14    (0x30000000)
#define GPIO_OSPEEDR_OSPEEDR14_0  (0x10000000)
#define GPIO_OSPEEDR_OSPEEDR14_1  (0x20000000)
#define GPIO_OSPEEDR_OSPEEDR15    (0xC0000000)
#define GPIO_OSPEEDR_OSPEEDR15_0  (0x40000000)
#define GPIO_OSPEEDR_OSPEEDR15_1  (0x80000000)

#define GPIO_OSPEEDER_OSPEEDR0     GPIO_OSPEEDR_OSPEEDR0
#define GPIO_OSPEEDER_OSPEEDR0_0   GPIO_OSPEEDR_OSPEEDR0_0
#define GPIO_OSPEEDER_OSPEEDR0_1   GPIO_OSPEEDR_OSPEEDR0_1
#define GPIO_OSPEEDER_OSPEEDR1     GPIO_OSPEEDR_OSPEEDR1
#define GPIO_OSPEEDER_OSPEEDR1_0   GPIO_OSPEEDR_OSPEEDR1_0
#define GPIO_OSPEEDER_OSPEEDR1_1   GPIO_OSPEEDR_OSPEEDR1_1
#define GPIO_OSPEEDER_OSPEEDR2     GPIO_OSPEEDR_OSPEEDR2
#define GPIO_OSPEEDER_OSPEEDR2_0   GPIO_OSPEEDR_OSPEEDR2_0
#define GPIO_OSPEEDER_OSPEEDR2_1   GPIO_OSPEEDR_OSPEEDR2_1
#define GPIO_OSPEEDER_OSPEEDR3     GPIO_OSPEEDR_OSPEEDR3
#define GPIO_OSPEEDER_OSPEEDR3_0   GPIO_OSPEEDR_OSPEEDR3_0
#define GPIO_OSPEEDER_OSPEEDR3_1   GPIO_OSPEEDR_OSPEEDR3_1
#define GPIO_OSPEEDER_OSPEEDR4     GPIO_OSPEEDR_OSPEEDR4
#define GPIO_OSPEEDER_OSPEEDR4_0   GPIO_OSPEEDR_OSPEEDR4_0
#define GPIO_OSPEEDER_OSPEEDR4_1   GPIO_OSPEEDR_OSPEEDR4_1
#define GPIO_OSPEEDER_OSPEEDR5     GPIO_OSPEEDR_OSPEEDR5
#define GPIO_OSPEEDER_OSPEEDR5_0   GPIO_OSPEEDR_OSPEEDR5_0
#define GPIO_OSPEEDER_OSPEEDR5_1   GPIO_OSPEEDR_OSPEEDR5_1
#define GPIO_OSPEEDER_OSPEEDR6     GPIO_OSPEEDR_OSPEEDR6
#define GPIO_OSPEEDER_OSPEEDR6_0   GPIO_OSPEEDR_OSPEEDR6_0
#define GPIO_OSPEEDER_OSPEEDR6_1   GPIO_OSPEEDR_OSPEEDR6_1
#define GPIO_OSPEEDER_OSPEEDR7     GPIO_OSPEEDR_OSPEEDR7
#define GPIO_OSPEEDER_OSPEEDR7_0   GPIO_OSPEEDR_OSPEEDR7_0
#define GPIO_OSPEEDER_OSPEEDR7_1   GPIO_OSPEEDR_OSPEEDR7_1
#define GPIO_OSPEEDER_OSPEEDR8     GPIO_OSPEEDR_OSPEEDR8
#define GPIO_OSPEEDER_OSPEEDR8_0   GPIO_OSPEEDR_OSPEEDR8_0
#define GPIO_OSPEEDER_OSPEEDR8_1   GPIO_OSPEEDR_OSPEEDR8_1
#define GPIO_OSPEEDER_OSPEEDR9     GPIO_OSPEEDR_OSPEEDR9
#define GPIO_OSPEEDER_OSPEEDR9_0   GPIO_OSPEEDR_OSPEEDR9_0
#define GPIO_OSPEEDER_OSPEEDR9_1   GPIO_OSPEEDR_OSPEEDR9_1
#define GPIO_OSPEEDER_OSPEEDR10    GPIO_OSPEEDR_OSPEEDR10
#define GPIO_OSPEEDER_OSPEEDR10_0  GPIO_OSPEEDR_OSPEEDR10_0
#define GPIO_OSPEEDER_OSPEEDR10_1  GPIO_OSPEEDR_OSPEEDR10_1
#define GPIO_OSPEEDER_OSPEEDR11    GPIO_OSPEEDR_OSPEEDR11
#define GPIO_OSPEEDER_OSPEEDR11_0  GPIO_OSPEEDR_OSPEEDR11_0
#define GPIO_OSPEEDER_OSPEEDR11_1  GPIO_OSPEEDR_OSPEEDR11_1
#define GPIO_OSPEEDER_OSPEEDR12    GPIO_OSPEEDR_OSPEEDR12
#define GPIO_OSPEEDER_OSPEEDR12_0  GPIO_OSPEEDR_OSPEEDR12_0
#define GPIO_OSPEEDER_OSPEEDR12_1  GPIO_OSPEEDR_OSPEEDR12_1
#define GPIO_OSPEEDER_OSPEEDR13    GPIO_OSPEEDR_OSPEEDR13
#define GPIO_OSPEEDER_OSPEEDR13_0  GPIO_OSPEEDR_OSPEEDR13_0
#define GPIO_OSPEEDER_OSPEEDR13_1  GPIO_OSPEEDR_OSPEEDR13_1
#define GPIO_OSPEEDER_OSPEEDR14    GPIO_OSPEEDR_OSPEEDR14
#define GPIO_OSPEEDER_OSPEEDR14_0  GPIO_OSPEEDR_OSPEEDR14_0
#define GPIO_OSPEEDER_OSPEEDR14_1  GPIO_OSPEEDR_OSPEEDR14_1
#define GPIO_OSPEEDER_OSPEEDR15    GPIO_OSPEEDR_OSPEEDR15
#define GPIO_OSPEEDER_OSPEEDR15_0  GPIO_OSPEEDR_OSPEEDR15_0
#define GPIO_OSPEEDER_OSPEEDR15_1  GPIO_OSPEEDR_OSPEEDR15_1

#define GPIO_PUPDR_PUPDR0          (0x00000003)
#define GPIO_PUPDR_PUPDR0_0        (0x00000001)
#define GPIO_PUPDR_PUPDR0_1        (0x00000002)
#define GPIO_PUPDR_PUPDR1          (0x0000000C)
#define GPIO_PUPDR_PUPDR1_0        (0x00000004)
#define GPIO_PUPDR_PUPDR1_1        (0x00000008)
#define GPIO_PUPDR_PUPDR2          (0x00000030)
#define GPIO_PUPDR_PUPDR2_0        (0x00000010)
#define GPIO_PUPDR_PUPDR2_1        (0x00000020)
#define GPIO_PUPDR_PUPDR3          (0x000000C0)
#define GPIO_PUPDR_PUPDR3_0        (0x00000040)
#define GPIO_PUPDR_PUPDR3_1        (0x00000080)
#define GPIO_PUPDR_PUPDR4          (0x00000300)
#define GPIO_PUPDR_PUPDR4_0        (0x00000100)
#define GPIO_PUPDR_PUPDR4_1        (0x00000200)
#define GPIO_PUPDR_PUPDR5          (0x00000C00)
#define GPIO_PUPDR_PUPDR5_0        (0x00000400)
#define GPIO_PUPDR_PUPDR5_1        (0x00000800)
#define GPIO_PUPDR_PUPDR6          (0x00003000)
#define GPIO_PUPDR_PUPDR6_0        (0x00001000)
#define GPIO_PUPDR_PUPDR6_1        (0x00002000)
#define GPIO_PUPDR_PUPDR7          (0x0000C000)
#define GPIO_PUPDR_PUPDR7_0        (0x00004000)
#define GPIO_PUPDR_PUPDR7_1        (0x00008000)
#define GPIO_PUPDR_PUPDR8          (0x00030000)
#define GPIO_PUPDR_PUPDR8_0        (0x00010000)
#define GPIO_PUPDR_PUPDR8_1        (0x00020000)
#define GPIO_PUPDR_PUPDR9          (0x000C0000)
#define GPIO_PUPDR_PUPDR9_0        (0x00040000)
#define GPIO_PUPDR_PUPDR9_1        (0x00080000)
#define GPIO_PUPDR_PUPDR10         (0x00300000)
#define GPIO_PUPDR_PUPDR10_0       (0x00100000)
#define GPIO_PUPDR_PUPDR10_1       (0x00200000)
#define GPIO_PUPDR_PUPDR11         (0x00C00000)
#define GPIO_PUPDR_PUPDR11_0       (0x00400000)
#define GPIO_PUPDR_PUPDR11_1       (0x00800000)
#define GPIO_PUPDR_PUPDR12         (0x03000000)
#define GPIO_PUPDR_PUPDR12_0       (0x01000000)
#define GPIO_PUPDR_PUPDR12_1       (0x02000000)
#define GPIO_PUPDR_PUPDR13         (0x0C000000)
#define GPIO_PUPDR_PUPDR13_0       (0x04000000)
#define GPIO_PUPDR_PUPDR13_1       (0x08000000)
#define GPIO_PUPDR_PUPDR14         (0x30000000)
#define GPIO_PUPDR_PUPDR14_0       (0x10000000)
#define GPIO_PUPDR_PUPDR14_1       (0x20000000)
#define GPIO_PUPDR_PUPDR15         (0xC0000000)
#define GPIO_PUPDR_PUPDR15_0       (0x40000000)
#define GPIO_PUPDR_PUPDR15_1       (0x80000000)

#define GPIO_IDR_0                 (0x00000001)
#define GPIO_IDR_1                 (0x00000002)
#define GPIO_IDR_2                 (0x00000004)
#define GPIO_IDR_3                 (0x00000008)
#define GPIO_IDR_4                 (0x00000010)
#define GPIO_IDR_5                 (0x00000020)
#define GPIO_IDR_6                 (0x00000040)
#define GPIO_IDR_7                 (0x00000080)
#define GPIO_IDR_8                 (0x00000100)
#define GPIO_IDR_9                 (0x00000200)
#define GPIO_IDR_10                (0x00000400)
#define GPIO_IDR_11                (0x00000800)
#define GPIO_IDR_12                (0x00001000)
#define GPIO_IDR_13                (0x00002000)
#define GPIO_IDR_14                (0x00004000)
#define GPIO_IDR_15                (0x00008000)

#define GPIO_ODR_0                 (0x00000001)
#define GPIO_ODR_1                 (0x00000002)
#define GPIO_ODR_2                 (0x00000004)
#define GPIO_ODR_3                 (0x00000008)
#define GPIO_ODR_4                 (0x00000010)
#define GPIO_ODR_5                 (0x00000020)
#define GPIO_ODR_6                 (0x00000040)
#define GPIO_ODR_7                 (0x00000080)
#define GPIO_ODR_8                 (0x00000100)
#define GPIO_ODR_9                 (0x00000200)
#define GPIO_ODR_10                (0x00000400)
#define GPIO_ODR_11                (0x00000800)
#define GPIO_ODR_12                (0x00001000)
#define GPIO_ODR_13                (0x00002000)
#define GPIO_ODR_14                (0x00004000)
#define GPIO_ODR_15                (0x00008000)

#define GPIO_BSRR_BS_0             (0x00000001)
#define GPIO_BSRR_BS_1             (0x00000002)
#define GPIO_BSRR_BS_2             (0x00000004)
#define GPIO_BSRR_BS_3             (0x00000008)
#define GPIO_BSRR_BS_4             (0x00000010)
#define GPIO_BSRR_BS_5             (0x00000020)
#define GPIO_BSRR_BS_6             (0x00000040)
#define GPIO_BSRR_BS_7             (0x00000080)
#define GPIO_BSRR_BS_8             (0x00000100)
#define GPIO_BSRR_BS_9             (0x00000200)
#define GPIO_BSRR_BS_10            (0x00000400)
#define GPIO_BSRR_BS_11            (0x00000800)
#define GPIO_BSRR_BS_12            (0x00001000)
#define GPIO_BSRR_BS_13            (0x00002000)
#define GPIO_BSRR_BS_14            (0x00004000)
#define GPIO_BSRR_BS_15            (0x00008000)
#define GPIO_BSRR_BR_0             (0x00010000)
#define GPIO_BSRR_BR_1             (0x00020000)
#define GPIO_BSRR_BR_2             (0x00040000)
#define GPIO_BSRR_BR_3             (0x00080000)
#define GPIO_BSRR_BR_4             (0x00100000)
#define GPIO_BSRR_BR_5             (0x00200000)
#define GPIO_BSRR_BR_6             (0x00400000)
#define GPIO_BSRR_BR_7             (0x00800000)
#define GPIO_BSRR_BR_8             (0x01000000)
#define GPIO_BSRR_BR_9             (0x02000000)
#define GPIO_BSRR_BR_10            (0x04000000)
#define GPIO_BSRR_BR_11            (0x08000000)
#define GPIO_BSRR_BR_12            (0x10000000)
#define GPIO_BSRR_BR_13            (0x20000000)
#define GPIO_BSRR_BR_14            (0x40000000)
#define GPIO_BSRR_BR_15            (0x80000000)

#define GPIO_LCKR_LCK0             (0x00000001)
#define GPIO_LCKR_LCK1             (0x00000002)
#define GPIO_LCKR_LCK2             (0x00000004)
#define GPIO_LCKR_LCK3             (0x00000008)
#define GPIO_LCKR_LCK4             (0x00000010)
#define GPIO_LCKR_LCK5             (0x00000020)
#define GPIO_LCKR_LCK6             (0x00000040)
#define GPIO_LCKR_LCK7             (0x00000080)
#define GPIO_LCKR_LCK8             (0x00000100)
#define GPIO_LCKR_LCK9             (0x00000200)
#define GPIO_LCKR_LCK10            (0x00000400)
#define GPIO_LCKR_LCK11            (0x00000800)
#define GPIO_LCKR_LCK12            (0x00001000)
#define GPIO_LCKR_LCK13            (0x00002000)
#define GPIO_LCKR_LCK14            (0x00004000)
#define GPIO_LCKR_LCK15            (0x00008000)
#define GPIO_LCKR_LCKK             (0x00010000)

#define GPIO_AFRL_AFR0            (0x0000000F)
#define GPIO_AFRL_AFR1            (0x000000F0)
#define GPIO_AFRL_AFR2            (0x00000F00)
#define GPIO_AFRL_AFR3            (0x0000F000)
#define GPIO_AFRL_AFR4            (0x000F0000)
#define GPIO_AFRL_AFR5            (0x00F00000)
#define GPIO_AFRL_AFR6            (0x0F000000)
#define GPIO_AFRL_AFR7            (0xF0000000)

#define GPIO_AFRH_AFR8            (0x0000000F)
#define GPIO_AFRH_AFR9            (0x000000F0)
#define GPIO_AFRH_AFR10            (0x00000F00)
#define GPIO_AFRH_AFR11            (0x0000F000)
#define GPIO_AFRH_AFR12            (0x000F0000)
#define GPIO_AFRH_AFR13            (0x00F00000)
#define GPIO_AFRH_AFR14            (0x0F000000)
#define GPIO_AFRH_AFR15            (0xF0000000)

#define GPIO_AFRL_AFRL0            GPIO_AFRL_AFR0
#define GPIO_AFRL_AFRL1            GPIO_AFRL_AFR1
#define GPIO_AFRL_AFRL2            GPIO_AFRL_AFR2
#define GPIO_AFRL_AFRL3            GPIO_AFRL_AFR3
#define GPIO_AFRL_AFRL4            GPIO_AFRL_AFR4
#define GPIO_AFRL_AFRL5            GPIO_AFRL_AFR5
#define GPIO_AFRL_AFRL6            GPIO_AFRL_AFR6
#define GPIO_AFRL_AFRL7            GPIO_AFRL_AFR7

#define GPIO_AFRH_AFRH0            GPIO_AFRH_AFR8
#define GPIO_AFRH_AFRH1            GPIO_AFRH_AFR9
#define GPIO_AFRH_AFRH2            GPIO_AFRH_AFR10
#define GPIO_AFRH_AFRH3            GPIO_AFRH_AFR11
#define GPIO_AFRH_AFRH4            GPIO_AFRH_AFR12
#define GPIO_AFRH_AFRH5            GPIO_AFRH_AFR13
#define GPIO_AFRH_AFRH6            GPIO_AFRH_AFR14
#define GPIO_AFRH_AFRH7            GPIO_AFRH_AFR15

#define GPIO_BRR_BR_0              (0x00000001)
#define GPIO_BRR_BR_1              (0x00000002)
#define GPIO_BRR_BR_2              (0x00000004)
#define GPIO_BRR_BR_3              (0x00000008)
#define GPIO_BRR_BR_4              (0x00000010)
#define GPIO_BRR_BR_5              (0x00000020)
#define GPIO_BRR_BR_6              (0x00000040)
#define GPIO_BRR_BR_7              (0x00000080)
#define GPIO_BRR_BR_8              (0x00000100)
#define GPIO_BRR_BR_9              (0x00000200)
#define GPIO_BRR_BR_10             (0x00000400)
#define GPIO_BRR_BR_11             (0x00000800)
#define GPIO_BRR_BR_12             (0x00001000)
#define GPIO_BRR_BR_13             (0x00002000)
#define GPIO_BRR_BR_14             (0x00004000)
#define GPIO_BRR_BR_15             (0x00008000)


#define  I2C_CR1_PE                          (0x00000001)        /*!< Peripheral enable */
#define  I2C_CR1_TXIE                        (0x00000002)        /*!< TX interrupt enable */
#define  I2C_CR1_RXIE                        (0x00000004)        /*!< RX interrupt enable */
#define  I2C_CR1_ADDRIE                      (0x00000008)        /*!< Address match interrupt enable */
#define  I2C_CR1_NACKIE                      (0x00000010)        /*!< NACK received interrupt enable */
#define  I2C_CR1_STOPIE                      (0x00000020)        /*!< STOP detection interrupt enable */
#define  I2C_CR1_TCIE                        (0x00000040)        /*!< Transfer complete interrupt enable */
#define  I2C_CR1_ERRIE                       (0x00000080)        /*!< Errors interrupt enable */
#define  I2C_CR1_DFN                         (0x00000F00)        /*!< Digital noise filter */
#define  I2C_CR1_ANFOFF                      (0x00001000)        /*!< Analog noise filter OFF */
#define  I2C_CR1_SWRST                       (0x00002000)        /*!< Software reset */
#define  I2C_CR1_TXDMAEN                     (0x00004000)        /*!< DMA transmission requests enable */
#define  I2C_CR1_RXDMAEN                     (0x00008000)        /*!< DMA reception requests enable */
#define  I2C_CR1_SBC                         (0x00010000)        /*!< Slave byte control */
#define  I2C_CR1_NOSTRETCH                   (0x00020000)        /*!< Clock stretching disable */
#define  I2C_CR1_WUPEN                       (0x00040000)        /*!< Wakeup from STOP enable */
#define  I2C_CR1_GCEN                        (0x00080000)        /*!< General call enable */
#define  I2C_CR1_SMBHEN                      (0x00100000)        /*!< SMBus host address enable */
#define  I2C_CR1_SMBDEN                      (0x00200000)        /*!< SMBus device default address enable */
#define  I2C_CR1_ALERTEN                     (0x00400000)        /*!< SMBus alert enable */
#define  I2C_CR1_PECEN                       (0x00800000)        /*!< PEC enable */

#define  I2C_CR2_SADD                        (0x000003FF)        /*!< Slave address (master mode) */
#define  I2C_CR2_RD_WRN                      (0x00000400)        /*!< Transfer direction (master mode) */
#define  I2C_CR2_ADD10                       (0x00000800)        /*!< 10-bit addressing mode (master mode) */
#define  I2C_CR2_HEAD10R                     (0x00001000)        /*!< 10-bit address header only read direction (master mode) */
#define  I2C_CR2_START                       (0x00002000)        /*!< START generation */
#define  I2C_CR2_STOP                        (0x00004000)        /*!< STOP generation (master mode) */
#define  I2C_CR2_NACK                        (0x00008000)        /*!< NACK generation (slave mode) */
#define  I2C_CR2_NBYTES                      (0x00FF0000)        /*!< Number of bytes */
#define  I2C_CR2_RELOAD                      (0x01000000)        /*!< NBYTES reload mode */
#define  I2C_CR2_AUTOEND                     (0x02000000)        /*!< Automatic end mode (master mode) */
#define  I2C_CR2_PECBYTE                     (0x04000000)        /*!< Packet error checking byte */

#define  I2C_OAR1_OA1                        (0x000003FF)        /*!< Interface own address 1 */
#define  I2C_OAR1_OA1MODE                    (0x00000400)        /*!< Own address 1 10-bit mode */
#define  I2C_OAR1_OA1EN                      (0x00008000)        /*!< Own address 1 enable */

#define  I2C_OAR2_OA2                        (0x000000FE)        /*!< Interface own address 2 */
#define  I2C_OAR2_OA2MSK                     (0x00000700)        /*!< Own address 2 masks */
#define  I2C_OAR2_OA2EN                      (0x00008000)        /*!< Own address 2 enable */

#define  I2C_TIMINGR_SCLL                    (0x000000FF)        /*!< SCL low period (master mode) */
#define  I2C_TIMINGR_SCLH                    (0x0000FF00)        /*!< SCL high period (master mode) */
#define  I2C_TIMINGR_SDADEL                  (0x000F0000)        /*!< Data hold time */
#define  I2C_TIMINGR_SCLDEL                  (0x00F00000)        /*!< Data setup time */
#define  I2C_TIMINGR_PRESC                   (0xF0000000)        /*!< Timings prescaler */

#define  I2C_TIMEOUTR_TIMEOUTA               (0x00000FFF)        /*!< Bus timeout A */
#define  I2C_TIMEOUTR_TIDLE                  (0x00001000)        /*!< Idle clock timeout detection */
#define  I2C_TIMEOUTR_TIMOUTEN               (0x00008000)        /*!< Clock timeout enable */
#define  I2C_TIMEOUTR_TIMEOUTB               (0x0FFF0000)        /*!< Bus timeout B*/
#define  I2C_TIMEOUTR_TEXTEN                 (0x80000000)        /*!< Extended clock timeout enable */

#define  I2C_ISR_TXE                         (0x00000001)        /*!< Transmit data register empty */
#define  I2C_ISR_TXIS                        (0x00000002)        /*!< Transmit interrupt status */
#define  I2C_ISR_RXNE                        (0x00000004)        /*!< Receive data register not empty */
#define  I2C_ISR_ADDR                        (0x00000008)        /*!< Address matched (slave mode)*/
#define  I2C_ISR_NACKF                       (0x00000010)        /*!< NACK received flag */
#define  I2C_ISR_STOPF                       (0x00000020)        /*!< STOP detection flag */
#define  I2C_ISR_TC                          (0x00000040)        /*!< Transfer complete (master mode) */
#define  I2C_ISR_TCR                         (0x00000080)        /*!< Transfer complete reload */
#define  I2C_ISR_BERR                        (0x00000100)        /*!< Bus error */
#define  I2C_ISR_ARLO                        (0x00000200)        /*!< Arbitration lost */
#define  I2C_ISR_OVR                         (0x00000400)        /*!< Overrun/Underrun */
#define  I2C_ISR_PECERR                      (0x00000800)        /*!< PEC error in reception */
#define  I2C_ISR_TIMEOUT                     (0x00001000)        /*!< Timeout or Tlow detection flag */
#define  I2C_ISR_ALERT                       (0x00002000)        /*!< SMBus alert */
#define  I2C_ISR_BUSY                        (0x00008000)        /*!< Bus busy */
#define  I2C_ISR_DIR                         (0x00010000)        /*!< Transfer direction (slave mode) */
#define  I2C_ISR_ADDCODE                     (0x00FE0000)        /*!< Address match code (slave mode) */

#define  I2C_ICR_ADDRCF                      (0x00000008)        /*!< Address matched clear flag */
#define  I2C_ICR_NACKCF                      (0x00000010)        /*!< NACK clear flag */
#define  I2C_ICR_STOPCF                      (0x00000020)        /*!< STOP detection clear flag */
#define  I2C_ICR_BERRCF                      (0x00000100)        /*!< Bus error clear flag */
#define  I2C_ICR_ARLOCF                      (0x00000200)        /*!< Arbitration lost clear flag */
#define  I2C_ICR_OVRCF                       (0x00000400)        /*!< Overrun/Underrun clear flag */
#define  I2C_ICR_PECCF                       (0x00000800)        /*!< PAC error clear flag */
#define  I2C_ICR_TIMOUTCF                    (0x00001000)        /*!< Timeout clear flag */
#define  I2C_ICR_ALERTCF                     (0x00002000)        /*!< Alert clear flag */

#define  I2C_PECR_PEC                        (0x000000FF)       /*!< PEC register */

#define  I2C_RXDR_RXDATA                     (0x000000FF)        /*!< 8-bit receive data */

#define  I2C_TXDR_TXDATA                     (0x000000FF)        /*!< 8-bit transmit data */

#define  IWDG_KR_KEY                         (0xFFFF)            /*!< Key value (write only, read 0000h) */

#define  IWDG_PR_PR                          (0x07)               /*!< PR[2:0] (Prescaler divider) */
#define  IWDG_PR_PR_0                        (0x01)               /*!< Bit 0 */
#define  IWDG_PR_PR_1                        (0x02)               /*!< Bit 1 */
#define  IWDG_PR_PR_2                        (0x04)               /*!< Bit 2 */

#define  IWDG_RLR_RL                         (0x0FFF)            /*!< Watchdog counter reload value */

#define  IWDG_SR_PVU                         (0x01)               /*!< Watchdog prescaler value update */
#define  IWDG_SR_RVU                         (0x02)               /*!< Watchdog counter reload value update */
#define  IWDG_SR_WVU                         (0x04)               /*!< Watchdog counter window value update */

#define  IWDG_WINR_WIN                         (0x0FFF)            /*!< Watchdog counter window value */


#define  PWR_CR_LPDS                         (0x0001)     /*!< Low-power deepsleep/sleep */
#define  PWR_CR_PDDS                         (0x0002)     /*!< Power Down Deepsleep */
#define  PWR_CR_CWUF                         (0x0004)     /*!< Clear Wakeup Flag */
#define  PWR_CR_CSBF                         (0x0008)     /*!< Clear Standby Flag */
#define  PWR_CR_PVDE                         (0x0010)     /*!< Power Voltage Detector Enable */

#define  PWR_CR_PLS                          (0x00E0)     /*!< PLS[2:0] bits (PVD Level Selection) */
#define  PWR_CR_PLS_0                        (0x0020)     /*!< Bit 0 */
#define  PWR_CR_PLS_1                        (0x0040)     /*!< Bit 1 */
#define  PWR_CR_PLS_2                        (0x0080)     /*!< Bit 2 */
#define  PWR_CR_PLS_LEV0                     (0x0000)     /*!< PVD level 0 */
#define  PWR_CR_PLS_LEV1                     (0x0020)     /*!< PVD level 1 */
#define  PWR_CR_PLS_LEV2                     (0x0040)     /*!< PVD level 2 */
#define  PWR_CR_PLS_LEV3                     (0x0060)     /*!< PVD level 3 */
#define  PWR_CR_PLS_LEV4                     (0x0080)     /*!< PVD level 4 */
#define  PWR_CR_PLS_LEV5                     (0x00A0)     /*!< PVD level 5 */
#define  PWR_CR_PLS_LEV6                     (0x00C0)     /*!< PVD level 6 */
#define  PWR_CR_PLS_LEV7                     (0x00E0)     /*!< PVD level 7 */

#define  PWR_CR_DBP                          (0x0100)     /*!< Disable Backup Domain write protection */

#define  PWR_CR_LPSDSR                       PWR_CR_LPDS     /*!< Low-power deepsleep */

#define  PWR_CSR_WUF                         (0x0001)     /*!< Wakeup Flag */
#define  PWR_CSR_SBF                         (0x0002)     /*!< Standby Flag */
#define  PWR_CSR_PVDO                        (0x0004)     /*!< PVD Output */
#define  PWR_CSR_VREFINTRDY                  (0x0008)     /*!< Internal voltage reference (VREFINT) ready */

#define  PWR_CSR_EWUP1                       (0x0100)     /*!< Enable WKUP pin 1 */
#define  PWR_CSR_EWUP2                       (0x0200)     /*!< Enable WKUP pin 2 */
#define  PWR_CSR_EWUP3                       (0x0400)     /*!< Enable WKUP pin 3 */
#define  PWR_CSR_EWUP4                       (0x0800)     /*!< Enable WKUP pin 4 */
#define  PWR_CSR_EWUP5                       (0x1000)     /*!< Enable WKUP pin 5 */
#define  PWR_CSR_EWUP6                       (0x2000)     /*!< Enable WKUP pin 6 */
#define  PWR_CSR_EWUP7                       (0x4000)     /*!< Enable WKUP pin 7 */
#define  PWR_CSR_EWUP8                       (0x8000)     /*!< Enable WKUP pin 8 */

#define  PWR_CSR_VREFINTRDYF                 PWR_CSR_VREFINTRDY     /*!< Internal voltage reference (VREFINT) ready flag */

#define  RCC_CR_HSION                        (0x00000001)        /*!< Internal High Speed clock enable */
#define  RCC_CR_HSIRDY                       (0x00000002)        /*!< Internal High Speed clock ready flag */
#define  RCC_CR_HSITRIM                      (0x000000F8)        /*!< Internal High Speed clock trimming */
#define  RCC_CR_HSICAL                       (0x0000FF00)        /*!< Internal High Speed clock Calibration */
#define  RCC_CR_HSEON                        (0x00010000)        /*!< External High Speed clock enable */
#define  RCC_CR_HSERDY                       (0x00020000)        /*!< External High Speed clock ready flag */
#define  RCC_CR_HSEBYP                       (0x00040000)        /*!< External High Speed clock Bypass */
#define  RCC_CR_CSSON                        (0x00080000)        /*!< Clock Security System enable */
#define  RCC_CR_PLLON                        (0x01000000)        /*!< PLL enable */
#define  RCC_CR_PLLRDY                       (0x02000000)        /*!< PLL clock ready flag */

#define  RCC_CFGR_SW                         (0x00000003)        /*!< SW[1:0] bits (System clock Switch) */
#define  RCC_CFGR_SW_0                       (0x00000001)        /*!< Bit 0 */
#define  RCC_CFGR_SW_1                       (0x00000002)        /*!< Bit 1 */
#define  RCC_CFGR_SW_HSI                     (0x00000000)        /*!< HSI selected as system clock */
#define  RCC_CFGR_SW_HSE                     (0x00000001)        /*!< HSE selected as system clock */
#define  RCC_CFGR_SW_PLL                     (0x00000002)        /*!< PLL selected as system clock */
#define  RCC_CFGR_SW_HSI48                   (0x00000003)        /*!< HSI48 selected as system clock */

#define  RCC_CFGR_SWS                        (0x0000000C)        /*!< SWS[1:0] bits (System Clock Switch Status) */
#define  RCC_CFGR_SWS_0                      (0x00000004)        /*!< Bit 0 */
#define  RCC_CFGR_SWS_1                      (0x00000008)        /*!< Bit 1 */
#define  RCC_CFGR_SWS_HSI                    (0x00000000)        /*!< HSI oscillator used as system clock */
#define  RCC_CFGR_SWS_HSE                    (0x00000004)        /*!< HSE oscillator used as system clock */
#define  RCC_CFGR_SWS_PLL                    (0x00000008)        /*!< PLL used as system clock */
#define  RCC_CFGR_SWS_HSI48                  (0x0000000C)        /*!< HSI48 used as system clock */

#define  RCC_CFGR_HPRE                       (0x000000F0)        /*!< HPRE[3:0] bits (AHB prescaler) */
#define  RCC_CFGR_HPRE_0                     (0x00000010)        /*!< Bit 0 */
#define  RCC_CFGR_HPRE_1                     (0x00000020)        /*!< Bit 1 */
#define  RCC_CFGR_HPRE_2                     (0x00000040)        /*!< Bit 2 */
#define  RCC_CFGR_HPRE_3                     (0x00000080)        /*!< Bit 3 */
#define  RCC_CFGR_HPRE_DIV1                  (0x00000000)        /*!< SYSCLK not divided */
#define  RCC_CFGR_HPRE_DIV2                  (0x00000080)        /*!< SYSCLK divided by 2 */
#define  RCC_CFGR_HPRE_DIV4                  (0x00000090)        /*!< SYSCLK divided by 4 */
#define  RCC_CFGR_HPRE_DIV8                  (0x000000A0)        /*!< SYSCLK divided by 8 */
#define  RCC_CFGR_HPRE_DIV16                 (0x000000B0)        /*!< SYSCLK divided by 16 */
#define  RCC_CFGR_HPRE_DIV64                 (0x000000C0)        /*!< SYSCLK divided by 64 */
#define  RCC_CFGR_HPRE_DIV128                (0x000000D0)        /*!< SYSCLK divided by 128 */
#define  RCC_CFGR_HPRE_DIV256                (0x000000E0)        /*!< SYSCLK divided by 256 */
#define  RCC_CFGR_HPRE_DIV512                (0x000000F0)        /*!< SYSCLK divided by 512 */

#define  RCC_CFGR_PPRE                       (0x00000700)        /*!< PRE[2:0] bits (APB prescaler) */
#define  RCC_CFGR_PPRE_0                     (0x00000100)        /*!< Bit 0 */
#define  RCC_CFGR_PPRE_1                     (0x00000200)        /*!< Bit 1 */
#define  RCC_CFGR_PPRE_2                     (0x00000400)        /*!< Bit 2 */
#define  RCC_CFGR_PPRE_DIV1                  (0x00000000)        /*!< HCLK not divided */
#define  RCC_CFGR_PPRE_DIV2                  (0x00000400)        /*!< HCLK divided by 2 */
#define  RCC_CFGR_PPRE_DIV4                  (0x00000500)        /*!< HCLK divided by 4 */
#define  RCC_CFGR_PPRE_DIV8                  (0x00000600)        /*!< HCLK divided by 8 */
#define  RCC_CFGR_PPRE_DIV16                 (0x00000700)        /*!< HCLK divided by 16 */

#define  RCC_CFGR_ADCPRE                     (0x00004000)        /*!< ADC prescaler: Obsolete. Proper ADC clock selection is
                                                                                done inside the ADC_CFGR2 */

#define  RCC_CFGR_PLLSRC                     (0x00018000)        /*!< PLL entry clock source */
#define  RCC_CFGR_PLLSRC_0                   (0x00008000)        /*!< Bit 0 (available only in the STM32F072 devices) */
#define  RCC_CFGR_PLLSRC_1                   (0x00010000)        /*!< Bit 1 */

#define  RCC_CFGR_PLLSRC_PREDIV1             (0x00010000)        /*!< PREDIV1 clock selected as PLL entry clock source;
                                                                                Old PREDIV1 bit definition, maintained for legacy purpose */
#define  RCC_CFGR_PLLSRC_HSI_DIV2            (0x00000000)        /*!< HSI clock divided by 2 selected as PLL entry clock source */
#define  RCC_CFGR_PLLSRC_HSI_PREDIV          (0x00008000)        /*!< HSI PREDIV clock selected as PLL entry clock source
                                                                                (This bit and configuration is only available for STM32F072 devices)*/
#define  RCC_CFGR_PLLSRC_HSE_PREDIV          (0x00010000)        /*!< HSE PREDIV clock selected as PLL entry clock source */
#define  RCC_CFGR_PLLSRC_HSI48_PREDIV        (0x00018000)        /*!< HSI48 PREDIV clock selected as PLL entry clock source */

#define  RCC_CFGR_PLLXTPRE                   (0x00020000)        /*!< HSE divider for PLL entry */
#define  RCC_CFGR_PLLXTPRE_PREDIV1           (0x00000000)        /*!< PREDIV1 clock not divided for PLL entry */
#define  RCC_CFGR_PLLXTPRE_PREDIV1_Div2      (0x00020000)        /*!< PREDIV1 clock divided by 2 for PLL entry */

#define  RCC_CFGR_PLLSRC_HSI_Div2            RCC_CFGR_PLLSRC_HSI_DIV2

#define  RCC_CFGR_PLLMUL                    (0x003C0000)        /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define  RCC_CFGR_PLLMUL_0                  (0x00040000)        /*!< Bit 0 */
#define  RCC_CFGR_PLLMUL_1                  (0x00080000)        /*!< Bit 1 */
#define  RCC_CFGR_PLLMUL_2                  (0x00100000)        /*!< Bit 2 */
#define  RCC_CFGR_PLLMUL_3                  (0x00200000)        /*!< Bit 3 */

#define  RCC_CFGR_PLLMUL2                   (0x00000000)        /*!< PLL input clock*2 */
#define  RCC_CFGR_PLLMUL3                   (0x00040000)        /*!< PLL input clock*3 */
#define  RCC_CFGR_PLLMUL4                   (0x00080000)        /*!< PLL input clock*4 */
#define  RCC_CFGR_PLLMUL5                   (0x000C0000)        /*!< PLL input clock*5 */
#define  RCC_CFGR_PLLMUL6                   (0x00100000)        /*!< PLL input clock*6 */
#define  RCC_CFGR_PLLMUL7                   (0x00140000)        /*!< PLL input clock*7 */
#define  RCC_CFGR_PLLMUL8                   (0x00180000)        /*!< PLL input clock*8 */
#define  RCC_CFGR_PLLMUL9                   (0x001C0000)        /*!< PLL input clock*9 */
#define  RCC_CFGR_PLLMUL10                  (0x00200000)        /*!< PLL input clock10 */
#define  RCC_CFGR_PLLMUL11                  (0x00240000)        /*!< PLL input clock*11 */
#define  RCC_CFGR_PLLMUL12                  (0x00280000)        /*!< PLL input clock*12 */
#define  RCC_CFGR_PLLMUL13                  (0x002C0000)        /*!< PLL input clock*13 */
#define  RCC_CFGR_PLLMUL14                  (0x00300000)        /*!< PLL input clock*14 */
#define  RCC_CFGR_PLLMUL15                  (0x00340000)        /*!< PLL input clock*15 */
#define  RCC_CFGR_PLLMUL16                  (0x00380000)        /*!< PLL input clock*16 */

#define  RCC_CFGR_PLLMULL                    RCC_CFGR_PLLMUL        /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define  RCC_CFGR_PLLMULL_0                  RCC_CFGR_PLLMUL_0        /*!< Bit 0 */
#define  RCC_CFGR_PLLMULL_1                  RCC_CFGR_PLLMUL_1        /*!< Bit 1 */
#define  RCC_CFGR_PLLMULL_2                  RCC_CFGR_PLLMUL_2        /*!< Bit 2 */
#define  RCC_CFGR_PLLMULL_3                  RCC_CFGR_PLLMUL_3       /*!< Bit 3 */

#define  RCC_CFGR_PLLMULL2                   RCC_CFGR_PLLMUL2       /*!< PLL input clock*2 */
#define  RCC_CFGR_PLLMULL3                   RCC_CFGR_PLLMUL3        /*!< PLL input clock*3 */
#define  RCC_CFGR_PLLMULL4                   RCC_CFGR_PLLMUL4        /*!< PLL input clock*4 */
#define  RCC_CFGR_PLLMULL5                   RCC_CFGR_PLLMUL5        /*!< PLL input clock*5 */
#define  RCC_CFGR_PLLMULL6                   RCC_CFGR_PLLMUL6        /*!< PLL input clock*6 */
#define  RCC_CFGR_PLLMULL7                   RCC_CFGR_PLLMUL7        /*!< PLL input clock*7 */
#define  RCC_CFGR_PLLMULL8                   RCC_CFGR_PLLMUL8        /*!< PLL input clock*8 */
#define  RCC_CFGR_PLLMULL9                   RCC_CFGR_PLLMUL9        /*!< PLL input clock*9 */
#define  RCC_CFGR_PLLMULL10                  RCC_CFGR_PLLMUL10        /*!< PLL input clock10 */
#define  RCC_CFGR_PLLMULL11                  RCC_CFGR_PLLMUL11        /*!< PLL input clock*11 */
#define  RCC_CFGR_PLLMULL12                  RCC_CFGR_PLLMUL12        /*!< PLL input clock*12 */
#define  RCC_CFGR_PLLMULL13                  RCC_CFGR_PLLMUL13        /*!< PLL input clock*13 */
#define  RCC_CFGR_PLLMULL14                  RCC_CFGR_PLLMUL14        /*!< PLL input clock*14 */
#define  RCC_CFGR_PLLMULL15                  RCC_CFGR_PLLMUL15        /*!< PLL input clock*15 */
#define  RCC_CFGR_PLLMULL16                  RCC_CFGR_PLLMUL16        /*!< PLL input clock*16 */

#define  RCC_CFGR_MCO                        (0x0F000000)        /*!< MCO[2:0] bits (Microcontroller Clock Output) */
#define  RCC_CFGR_MCO_0                      (0x01000000)        /*!< Bit 0 */
#define  RCC_CFGR_MCO_1                      (0x02000000)        /*!< Bit 1 */
#define  RCC_CFGR_MCO_2                      (0x04000000)        /*!< Bit 2 */
#define  RCC_CFGR_MCO_3                      (0x08000000)        /*!< Bit 3 */
#define  RCC_CFGR_MCO_NOCLOCK                (0x00000000)        /*!< No clock */
#define  RCC_CFGR_MCO_HSI14                  (0x01000000)        /*!< HSI14 clock selected as MCO source */
#define  RCC_CFGR_MCO_LSI                    (0x02000000)        /*!< LSI clock selected as MCO source */
#define  RCC_CFGR_MCO_LSE                    (0x03000000)        /*!< LSE clock selected as MCO source */
#define  RCC_CFGR_MCO_SYSCLK                 (0x04000000)        /*!< System clock selected as MCO source */
#define  RCC_CFGR_MCO_HSI                    (0x05000000)        /*!< HSI clock selected as MCO source */
#define  RCC_CFGR_MCO_HSE                    (0x06000000)        /*!< HSE clock selected as MCO source  */
#define  RCC_CFGR_MCO_PLL                    (0x07000000)        /*!< PLL clock selected as MCO source */
#define  RCC_CFGR_MCO_HSI48                  (0x08000000)        /*!< HSI48 clock selected as MCO source */

#define  RCC_CFGR_MCO_PRE                    (0x70000000)        /*!< MCO prescaler (these bits are not available in the STM32F051 devices)*/
#define  RCC_CFGR_MCO_PRE_1                  (0x00000000)        /*!< MCO is divided by 1 (this bit are not available in the STM32F051 devices)*/
#define  RCC_CFGR_MCO_PRE_2                  (0x10000000)        /*!< MCO is divided by 2 (this bit are not available in the STM32F051 devices)*/
#define  RCC_CFGR_MCO_PRE_4                  (0x20000000)        /*!< MCO is divided by 4 (this bit are not available in the STM32F051 devices)*/
#define  RCC_CFGR_MCO_PRE_8                  (0x30000000)        /*!< MCO is divided by 8 (this bit are not available in the STM32F051 devices)*/
#define  RCC_CFGR_MCO_PRE_16                 (0x40000000)        /*!< MCO is divided by 16 (this bit are not available in the STM32F051 devices)*/
#define  RCC_CFGR_MCO_PRE_32                 (0x50000000)        /*!< MCO is divided by 32 (this bit are not available in the STM32F051 devices)*/
#define  RCC_CFGR_MCO_PRE_64                 (0x60000000)        /*!< MCO is divided by 64 (this bit are not available in the STM32F051 devices)*/
#define  RCC_CFGR_MCO_PRE_128                (0x70000000)        /*!< MCO is divided by 128 (this bit are not available in the STM32F051 devices)*/

#define  RCC_CFGR_PLLNODIV                   (0x80000000)        /*!< PLL is not divided to MCO (this bit are not available in the STM32F051 devices) */

#define  RCC_CIR_LSIRDYF                     (0x00000001)        /*!< LSI Ready Interrupt flag */
#define  RCC_CIR_LSERDYF                     (0x00000002)        /*!< LSE Ready Interrupt flag */
#define  RCC_CIR_HSIRDYF                     (0x00000004)        /*!< HSI Ready Interrupt flag */
#define  RCC_CIR_HSERDYF                     (0x00000008)        /*!< HSE Ready Interrupt flag */
#define  RCC_CIR_PLLRDYF                     (0x00000010)        /*!< PLL Ready Interrupt flag */
#define  RCC_CIR_HSI14RDYF                   (0x00000020)        /*!< HSI14 Ready Interrupt flag */
#define  RCC_CIR_HSI48RDYF                   (0x00000040)        /*!< HSI48 Ready Interrupt flag */
#define  RCC_CIR_CSSF                        (0x00000080)        /*!< Clock Security System Interrupt flag */
#define  RCC_CIR_LSIRDYIE                    (0x00000100)        /*!< LSI Ready Interrupt Enable */
#define  RCC_CIR_LSERDYIE                    (0x00000200)        /*!< LSE Ready Interrupt Enable */
#define  RCC_CIR_HSIRDYIE                    (0x00000400)        /*!< HSI Ready Interrupt Enable */
#define  RCC_CIR_HSERDYIE                    (0x00000800)        /*!< HSE Ready Interrupt Enable */
#define  RCC_CIR_PLLRDYIE                    (0x00001000)        /*!< PLL Ready Interrupt Enable */
#define  RCC_CIR_HSI14RDYIE                  (0x00002000)        /*!< HSI14 Ready Interrupt Enable */
#define  RCC_CIR_HSI48RDYIE                  (0x00004000)        /*!< HSI48 Ready Interrupt Enable */
#define  RCC_CIR_LSIRDYC                     (0x00010000)        /*!< LSI Ready Interrupt Clear */
#define  RCC_CIR_LSERDYC                     (0x00020000)        /*!< LSE Ready Interrupt Clear */
#define  RCC_CIR_HSIRDYC                     (0x00040000)        /*!< HSI Ready Interrupt Clear */
#define  RCC_CIR_HSERDYC                     (0x00080000)        /*!< HSE Ready Interrupt Clear */
#define  RCC_CIR_PLLRDYC                     (0x00100000)        /*!< PLL Ready Interrupt Clear */
#define  RCC_CIR_HSI14RDYC                   (0x00200000)        /*!< HSI14 Ready Interrupt Clear */
#define  RCC_CIR_HSI48RDYC                   (0x00400000)        /*!< HSI48 Ready Interrupt Clear */
#define  RCC_CIR_CSSC                        (0x00800000)        /*!< Clock Security System Interrupt Clear */

#define  RCC_APB2RSTR_SYSCFGRST              (0x00000001)        /*!< SYSCFG clock reset */
#define  RCC_APB2RSTR_ADCRST                 (0x00000200)        /*!< ADC clock reset */
#define  RCC_APB2RSTR_TIM1RST                (0x00000800)        /*!< TIM1 clock reset */
#define  RCC_APB2RSTR_SPI1RST                (0x00001000)        /*!< SPI1 clock reset */
#define  RCC_APB2RSTR_USART1RST              (0x00004000)        /*!< USART1 clock reset */
#define  RCC_APB2RSTR_TIM15RST               (0x00010000)        /*!< TIM15 clock reset */
#define  RCC_APB2RSTR_TIM16RST               (0x00020000)        /*!< TIM16 clock reset */
#define  RCC_APB2RSTR_TIM17RST               (0x00040000)        /*!< TIM17 clock reset */
#define  RCC_APB2RSTR_DBGMCURST              (0x00400000)        /*!< DBGMCU clock reset */

#define  RCC_APB2RSTR_ADC1RST                RCC_APB2RSTR_ADCRST

#define  RCC_APB1RSTR_TIM2RST                (0x00000001)        /*!< Timer 2 clock reset */
#define  RCC_APB1RSTR_TIM3RST                (0x00000002)        /*!< Timer 3 clock reset */
#define  RCC_APB1RSTR_TIM6RST                (0x00000010)        /*!< Timer 6 clock reset */
#define  RCC_APB1RSTR_TIM7RST                (0x00000020)        /*!< Timer 7 clock reset */
#define  RCC_APB1RSTR_TIM14RST               (0x00000100)        /*!< Timer 14 clock reset */
#define  RCC_APB1RSTR_WWDGRST                (0x00000800)        /*!< Window Watchdog clock reset */
#define  RCC_APB1RSTR_SPI2RST                (0x00004000)        /*!< SPI2 clock reset */
#define  RCC_APB1RSTR_USART2RST              (0x00020000)        /*!< USART 2 clock reset */
#define  RCC_APB1RSTR_USART3RST              (0x00040000)        /*!< USART 3 clock reset */
#define  RCC_APB1RSTR_USART4RST              (0x00080000)        /*!< USART 4 clock reset */
#define  RCC_APB1RSTR_I2C1RST                (0x00200000)        /*!< I2C 1 clock reset */
#define  RCC_APB1RSTR_I2C2RST                (0x00400000)        /*!< I2C 2 clock reset */
#define  RCC_APB1RSTR_USBRST                 (0x00800000)        /*!< USB clock reset */
#define  RCC_APB1RSTR_CANRST                 (0x02000000)        /*!< CAN clock reset */
#define  RCC_APB1RSTR_CRSRST                 (0x08000000)        /*!< CRS clock reset */
#define  RCC_APB1RSTR_PWRRST                 (0x10000000)        /*!< PWR clock reset */
#define  RCC_APB1RSTR_DACRST                 (0x20000000)        /*!< DAC clock reset */
#define  RCC_APB1RSTR_CECRST                 (0x40000000)        /*!< CEC clock reset */

#define  RCC_AHBENR_DMAEN                    (0x00000001)        /*!< DMA clock enable */
#define  RCC_AHBENR_SRAMEN                   (0x00000004)        /*!< SRAM interface clock enable */
#define  RCC_AHBENR_FLITFEN                  (0x00000010)        /*!< FLITF clock enable */
#define  RCC_AHBENR_CRCEN                    (0x00000040)        /*!< CRC clock enable */
#define  RCC_AHBENR_GPIOAEN                  (0x00020000)        /*!< GPIOA clock enable */
#define  RCC_AHBENR_GPIOBEN                  (0x00040000)        /*!< GPIOB clock enable */
#define  RCC_AHBENR_GPIOCEN                  (0x00080000)        /*!< GPIOC clock enable */
#define  RCC_AHBENR_GPIODEN                  (0x00100000)        /*!< GPIOD clock enable */
#define  RCC_AHBENR_GPIOEEN                  (0x00200000)        /*!< GPIOE clock enable */
#define  RCC_AHBENR_GPIOFEN                  (0x00400000)        /*!< GPIOF clock enable */
#define  RCC_AHBENR_TSCEN                    (0x01000000)        /*!< TS controller clock enable */

#define  RCC_AHBENR_DMA1EN                   RCC_AHBENR_DMAEN        /*!< DMA1 clock enable */
#define  RCC_AHBENR_TSEN                     RCC_AHBENR_TSCEN        /*!< TS clock enable */

#define  RCC_APB2ENR_SYSCFGCOMPEN            (0x00000001)        /*!< SYSCFG and comparator clock enable */
#define  RCC_APB2ENR_ADCEN                   (0x00000200)        /*!< ADC1 clock enable */
#define  RCC_APB2ENR_TIM1EN                  (0x00000800)        /*!< TIM1 clock enable */
#define  RCC_APB2ENR_SPI1EN                  (0x00001000)        /*!< SPI1 clock enable */
#define  RCC_APB2ENR_USART1EN                (0x00004000)        /*!< USART1 clock enable */
#define  RCC_APB2ENR_TIM15EN                 (0x00010000)        /*!< TIM15 clock enable */
#define  RCC_APB2ENR_TIM16EN                 (0x00020000)        /*!< TIM16 clock enable */
#define  RCC_APB2ENR_TIM17EN                 (0x00040000)        /*!< TIM17 clock enable */
#define  RCC_APB2ENR_DBGMCUEN                (0x00400000)        /*!< DBGMCU clock enable */

#define  RCC_APB2ENR_SYSCFGEN                RCC_APB2ENR_SYSCFGCOMPEN        /*!< SYSCFG clock enable */
#define  RCC_APB2ENR_ADC1EN                  RCC_APB2ENR_ADCEN               /*!< ADC1 clock enable */

#define  RCC_APB1ENR_TIM2EN                  (0x00000001)        /*!< Timer 2 clock enable */
#define  RCC_APB1ENR_TIM3EN                  (0x00000002)        /*!< Timer 3 clock enable */
#define  RCC_APB1ENR_TIM6EN                  (0x00000010)        /*!< Timer 6 clock enable */
#define  RCC_APB1ENR_TIM7EN                  (0x00000020)        /*!< Timer 7 clock enable */
#define  RCC_APB1ENR_TIM14EN                 (0x00000100)        /*!< Timer 14 clock enable */
#define  RCC_APB1ENR_WWDGEN                  (0x00000800)        /*!< Window Watchdog clock enable */
#define  RCC_APB1ENR_SPI2EN                  (0x00004000)        /*!< SPI2 clock enable */
#define  RCC_APB1ENR_USART2EN                (0x00020000)        /*!< USART2 clock enable */
#define  RCC_APB1ENR_USART3EN                (0x00040000)        /*!< USART3 clock enable */
#define  RCC_APB1ENR_USART4EN                (0x00080000)        /*!< USART4 clock enable */
#define  RCC_APB1ENR_I2C1EN                  (0x00200000)        /*!< I2C1 clock enable */
#define  RCC_APB1ENR_I2C2EN                  (0x00400000)        /*!< I2C2 clock enable */
#define  RCC_APB1ENR_USBEN                   (0x00800000)        /*!< USB clock enable */
#define  RCC_APB1ENR_CANEN                   (0x02000000)         /*!< CAN clock enable */
#define  RCC_APB1ENR_CRSEN                   (0x08000000)        /*!< CRS clock enable */
#define  RCC_APB1ENR_PWREN                   (0x10000000)        /*!< PWR clock enable */
#define  RCC_APB1ENR_DACEN                   (0x20000000)        /*!< DAC clock enable */
#define  RCC_APB1ENR_CECEN                   (0x40000000)        /*!< CEC clock enable */

#define  RCC_BDCR_LSEON                      (0x00000001)        /*!< External Low Speed oscillator enable */
#define  RCC_BDCR_LSERDY                     (0x00000002)        /*!< External Low Speed oscillator Ready */
#define  RCC_BDCR_LSEBYP                     (0x00000004)        /*!< External Low Speed oscillator Bypass */

#define  RCC_BDCR_LSEDRV                     (0x00000018)        /*!< LSEDRV[1:0] bits (LSE Osc. drive capability) */
#define  RCC_BDCR_LSEDRV_0                   (0x00000008)        /*!< Bit 0 */
#define  RCC_BDCR_LSEDRV_1                   (0x00000010)        /*!< Bit 1 */

#define  RCC_BDCR_RTCSEL                     (0x00000300)        /*!< RTCSEL[1:0] bits (RTC clock source selection) */
#define  RCC_BDCR_RTCSEL_0                   (0x00000100)        /*!< Bit 0 */
#define  RCC_BDCR_RTCSEL_1                   (0x00000200)        /*!< Bit 1 */

#define  RCC_BDCR_RTCSEL_NOCLOCK             (0x00000000)        /*!< No clock */
#define  RCC_BDCR_RTCSEL_LSE                 (0x00000100)        /*!< LSE oscillator clock used as RTC clock */
#define  RCC_BDCR_RTCSEL_LSI                 (0x00000200)        /*!< LSI oscillator clock used as RTC clock */
#define  RCC_BDCR_RTCSEL_HSE                 (0x00000300)        /*!< HSE oscillator clock divided by 32 used as RTC clock */

#define  RCC_BDCR_RTCEN                      (0x00008000)        /*!< RTC clock enable */
#define  RCC_BDCR_BDRST                      (0x00010000)        /*!< Backup domain software reset  */

#define  RCC_CSR_LSION                       (0x00000001)        /*!< Internal Low Speed oscillator enable */
#define  RCC_CSR_LSIRDY                      (0x00000002)        /*!< Internal Low Speed oscillator Ready */
#define  RCC_CSR_V18PWRRSTF                  (0x00800000)        /*!< V1.8 power domain reset flag */
#define  RCC_CSR_RMVF                        (0x01000000)        /*!< Remove reset flag */
#define  RCC_CSR_OBLRSTF                     (0x02000000)        /*!< OBL reset flag */
#define  RCC_CSR_PINRSTF                     (0x04000000)        /*!< PIN reset flag */
#define  RCC_CSR_PORRSTF                     (0x08000000)        /*!< POR/PDR reset flag */
#define  RCC_CSR_SFTRSTF                     (0x10000000)        /*!< Software Reset flag */
#define  RCC_CSR_IWDGRSTF                    (0x20000000)        /*!< Independent Watchdog reset flag */
#define  RCC_CSR_WWDGRSTF                    (0x40000000)        /*!< Window watchdog reset flag */
#define  RCC_CSR_LPWRRSTF                    (0x80000000)        /*!< Low-Power reset flag */

#define  RCC_CSR_OBL                         RCC_CSR_OBLRSTF        /*!< OBL reset flag */
#define  RCC_AHBRSTR_GPIOARST                (0x00020000)         /*!< GPIOA clock reset */
#define  RCC_AHBRSTR_GPIOBRST                (0x00040000)         /*!< GPIOB clock reset */
#define  RCC_AHBRSTR_GPIOCRST                (0x00080000)         /*!< GPIOC clock reset */
#define  RCC_AHBRSTR_GPIODRST                (0x00010000)         /*!< GPIOD clock reset */
#define  RCC_AHBRSTR_GPIOERST                (0x00020000)         /*!< GPIOE clock reset */
#define  RCC_AHBRSTR_GPIOFRST                (0x00040000)         /*!< GPIOF clock reset */
#define  RCC_AHBRSTR_TSCRST                   (0x00100000)         /*!< TS clock reset */

#define  RCC_AHBRSTR_TSRST                   RCC_AHBRSTR_TSCRST         /*!< TS clock reset */

#define  RCC_CFGR2_PREDIV1                   (0x0000000F)        /*!< PREDIV1[3:0] bits */
#define  RCC_CFGR2_PREDIV1_0                 (0x00000001)        /*!< Bit 0 */
#define  RCC_CFGR2_PREDIV1_1                 (0x00000002)        /*!< Bit 1 */
#define  RCC_CFGR2_PREDIV1_2                 (0x00000004)        /*!< Bit 2 */
#define  RCC_CFGR2_PREDIV1_3                 (0x00000008)        /*!< Bit 3 */

#define  RCC_CFGR2_PREDIV1_DIV1              (0x00000000)        /*!< PREDIV1 input clock not divided */
#define  RCC_CFGR2_PREDIV1_DIV2              (0x00000001)        /*!< PREDIV1 input clock divided by 2 */
#define  RCC_CFGR2_PREDIV1_DIV3              (0x00000002)        /*!< PREDIV1 input clock divided by 3 */
#define  RCC_CFGR2_PREDIV1_DIV4              (0x00000003)        /*!< PREDIV1 input clock divided by 4 */
#define  RCC_CFGR2_PREDIV1_DIV5              (0x00000004)        /*!< PREDIV1 input clock divided by 5 */
#define  RCC_CFGR2_PREDIV1_DIV6              (0x00000005)        /*!< PREDIV1 input clock divided by 6 */
#define  RCC_CFGR2_PREDIV1_DIV7              (0x00000006)        /*!< PREDIV1 input clock divided by 7 */
#define  RCC_CFGR2_PREDIV1_DIV8              (0x00000007)        /*!< PREDIV1 input clock divided by 8 */
#define  RCC_CFGR2_PREDIV1_DIV9              (0x00000008)        /*!< PREDIV1 input clock divided by 9 */
#define  RCC_CFGR2_PREDIV1_DIV10             (0x00000009)        /*!< PREDIV1 input clock divided by 10 */
#define  RCC_CFGR2_PREDIV1_DIV11             (0x0000000A)        /*!< PREDIV1 input clock divided by 11 */
#define  RCC_CFGR2_PREDIV1_DIV12             (0x0000000B)        /*!< PREDIV1 input clock divided by 12 */
#define  RCC_CFGR2_PREDIV1_DIV13             (0x0000000C)        /*!< PREDIV1 input clock divided by 13 */
#define  RCC_CFGR2_PREDIV1_DIV14             (0x0000000D)        /*!< PREDIV1 input clock divided by 14 */
#define  RCC_CFGR2_PREDIV1_DIV15             (0x0000000E)        /*!< PREDIV1 input clock divided by 15 */
#define  RCC_CFGR2_PREDIV1_DIV16             (0x0000000F)        /*!< PREDIV1 input clock divided by 16 */

#define  RCC_CFGR3_USART1SW                  (0x00000003)        /*!< USART1SW[1:0] bits */
#define  RCC_CFGR3_USART1SW_0                (0x00000001)        /*!< Bit 0 */
#define  RCC_CFGR3_USART1SW_1                (0x00000002)        /*!< Bit 1 */
#define  RCC_CFGR3_I2C1SW                    (0x00000010)        /*!< I2C1SW bits */
#define  RCC_CFGR3_CECSW                     (0x00000040)        /*!< CECSW bits */
#define  RCC_CFGR3_USBSW                     (0x00000080)        /*!< USBSW bits */
#define  RCC_CFGR3_ADCSW                     (0x00000100)        /*!< ADCSW bits */
#define  RCC_CFGR3_USART2SW                  (0x00030000)        /*!< USART2SW[1:0] bits */
#define  RCC_CFGR3_USART2SW_0                (0x00010000)        /*!< Bit 0 */
#define  RCC_CFGR3_USART2SW_1                (0x00020000)        /*!< Bit 1 */

#define  RCC_CR2_HSI14ON                     (0x00000001)        /*!< Internal High Speed 14MHz clock enable */
#define  RCC_CR2_HSI14RDY                    (0x00000002)        /*!< Internal High Speed 14MHz clock ready flag */
#define  RCC_CR2_HSI14DIS                    (0x00000004)        /*!< Internal High Speed 14MHz clock disable */
#define  RCC_CR2_HSI14TRIM                   (0x000000F8)        /*!< Internal High Speed 14MHz clock trimming */
#define  RCC_CR2_HSI14CAL                    (0x0000FF00)        /*!< Internal High Speed 14MHz clock Calibration */
#define  RCC_CR2_HSI48ON                     (0x00010000)        /*!< Internal High Speed 48MHz clock enable */
#define  RCC_CR2_HSI48RDY                    (0x00020000)        /*!< Internal High Speed 48MHz clock ready flag */
#define  RCC_CR2_HSI48CAL                    (0xFF000000)        /*!< Internal High Speed 48MHz clock Calibration */

#define RTC_TR_PM                            (0x00400000)
#define RTC_TR_HT                            (0x00300000)
#define RTC_TR_HT_0                          (0x00100000)
#define RTC_TR_HT_1                          (0x00200000)
#define RTC_TR_HU                            (0x000F0000)
#define RTC_TR_HU_0                          (0x00010000)
#define RTC_TR_HU_1                          (0x00020000)
#define RTC_TR_HU_2                          (0x00040000)
#define RTC_TR_HU_3                          (0x00080000)
#define RTC_TR_MNT                           (0x00007000)
#define RTC_TR_MNT_0                         (0x00001000)
#define RTC_TR_MNT_1                         (0x00002000)
#define RTC_TR_MNT_2                         (0x00004000)
#define RTC_TR_MNU                           (0x00000F00)
#define RTC_TR_MNU_0                         (0x00000100)
#define RTC_TR_MNU_1                         (0x00000200)
#define RTC_TR_MNU_2                         (0x00000400)
#define RTC_TR_MNU_3                         (0x00000800)
#define RTC_TR_ST                            (0x00000070)
#define RTC_TR_ST_0                          (0x00000010)
#define RTC_TR_ST_1                          (0x00000020)
#define RTC_TR_ST_2                          (0x00000040)
#define RTC_TR_SU                            (0x0000000F)
#define RTC_TR_SU_0                          (0x00000001)
#define RTC_TR_SU_1                          (0x00000002)
#define RTC_TR_SU_2                          (0x00000004)
#define RTC_TR_SU_3                          (0x00000008)

#define RTC_DR_YT                            (0x00F00000)
#define RTC_DR_YT_0                          (0x00100000)
#define RTC_DR_YT_1                          (0x00200000)
#define RTC_DR_YT_2                          (0x00400000)
#define RTC_DR_YT_3                          (0x00800000)
#define RTC_DR_YU                            (0x000F0000)
#define RTC_DR_YU_0                          (0x00010000)
#define RTC_DR_YU_1                          (0x00020000)
#define RTC_DR_YU_2                          (0x00040000)
#define RTC_DR_YU_3                          (0x00080000)
#define RTC_DR_WDU                           (0x0000E000)
#define RTC_DR_WDU_0                         (0x00002000)
#define RTC_DR_WDU_1                         (0x00004000)
#define RTC_DR_WDU_2                         (0x00008000)
#define RTC_DR_MT                            (0x00001000)
#define RTC_DR_MU                            (0x00000F00)
#define RTC_DR_MU_0                          (0x00000100)
#define RTC_DR_MU_1                          (0x00000200)
#define RTC_DR_MU_2                          (0x00000400)
#define RTC_DR_MU_3                          (0x00000800)
#define RTC_DR_DT                            (0x00000030)
#define RTC_DR_DT_0                          (0x00000010)
#define RTC_DR_DT_1                          (0x00000020)
#define RTC_DR_DU                            (0x0000000F)
#define RTC_DR_DU_0                          (0x00000001)
#define RTC_DR_DU_1                          (0x00000002)
#define RTC_DR_DU_2                          (0x00000004)
#define RTC_DR_DU_3                          (0x00000008)

#define RTC_CR_COE                           (0x00800000)
#define RTC_CR_OSEL                          (0x00600000)
#define RTC_CR_OSEL_0                        (0x00200000)
#define RTC_CR_OSEL_1                        (0x00400000)
#define RTC_CR_POL                           (0x00100000)
#define RTC_CR_COSEL                         (0x00080000)
#define RTC_CR_BKP                           (0x00040000)
#define RTC_CR_SUB1H                         (0x00020000)
#define RTC_CR_ADD1H                         (0x00010000)
#define RTC_CR_TSIE                          (0x00008000)
#define RTC_CR_WUTIE                         (0x00004000)
#define RTC_CR_ALRAIE                        (0x00001000)
#define RTC_CR_TSE                           (0x00000800)
#define RTC_CR_WUTE                          (0x00000400)
#define RTC_CR_ALRAE                         (0x00000100)
#define RTC_CR_FMT                           (0x00000040)
#define RTC_CR_BYPSHAD                       (0x00000020)
#define RTC_CR_REFCKON                       (0x00000010)
#define RTC_CR_TSEDGE                        (0x00000008)
#define RTC_CR_WUCKSEL                       (0x00000007)
#define RTC_CR_WUCKSEL_0                     (0x00000001)
#define RTC_CR_WUCKSEL_1                     (0x00000002)
#define RTC_CR_WUCKSEL_2                     (0x00000004)

#define RTC_CR_BCK                           RTC_CR_BKP
#define RTC_CR_CALSEL                        RTC_CR_COSEL

#define RTC_ISR_RECALPF                      (0x00010000)
#define RTC_ISR_TAMP3F                       (0x00008000)
#define RTC_ISR_TAMP2F                       (0x00004000)
#define RTC_ISR_TAMP1F                       (0x00002000)
#define RTC_ISR_TSOVF                        (0x00001000)
#define RTC_ISR_TSF                          (0x00000800)
#define RTC_ISR_WUTF                         (0x00000400)
#define RTC_ISR_ALRAF                        (0x00000100)
#define RTC_ISR_INIT                         (0x00000080)
#define RTC_ISR_INITF                        (0x00000040)
#define RTC_ISR_RSF                          (0x00000020)
#define RTC_ISR_INITS                        (0x00000010)
#define RTC_ISR_SHPF                         (0x00000008)
#define RTC_ISR_WUTWF                        (0x00000004)
#define RTC_ISR_ALRAWF                       (0x00000001)

#define RTC_PRER_PREDIV_A                    (0x007F0000)
#define RTC_PRER_PREDIV_S                    (0x00007FFF)

#define RTC_WUTR_WUT                         (0x0000FFFF)

#define RTC_ALRMAR_MSK4                      (0x80000000)
#define RTC_ALRMAR_WDSEL                     (0x40000000)
#define RTC_ALRMAR_DT                        (0x30000000)
#define RTC_ALRMAR_DT_0                      (0x10000000)
#define RTC_ALRMAR_DT_1                      (0x20000000)
#define RTC_ALRMAR_DU                        (0x0F000000)
#define RTC_ALRMAR_DU_0                      (0x01000000)
#define RTC_ALRMAR_DU_1                      (0x02000000)
#define RTC_ALRMAR_DU_2                      (0x04000000)
#define RTC_ALRMAR_DU_3                      (0x08000000)
#define RTC_ALRMAR_MSK3                      (0x00800000)
#define RTC_ALRMAR_PM                        (0x00400000)
#define RTC_ALRMAR_HT                        (0x00300000)
#define RTC_ALRMAR_HT_0                      (0x00100000)
#define RTC_ALRMAR_HT_1                      (0x00200000)
#define RTC_ALRMAR_HU                        (0x000F0000)
#define RTC_ALRMAR_HU_0                      (0x00010000)
#define RTC_ALRMAR_HU_1                      (0x00020000)
#define RTC_ALRMAR_HU_2                      (0x00040000)
#define RTC_ALRMAR_HU_3                      (0x00080000)
#define RTC_ALRMAR_MSK2                      (0x00008000)
#define RTC_ALRMAR_MNT                       (0x00007000)
#define RTC_ALRMAR_MNT_0                     (0x00001000)
#define RTC_ALRMAR_MNT_1                     (0x00002000)
#define RTC_ALRMAR_MNT_2                     (0x00004000)
#define RTC_ALRMAR_MNU                       (0x00000F00)
#define RTC_ALRMAR_MNU_0                     (0x00000100)
#define RTC_ALRMAR_MNU_1                     (0x00000200)
#define RTC_ALRMAR_MNU_2                     (0x00000400)
#define RTC_ALRMAR_MNU_3                     (0x00000800)
#define RTC_ALRMAR_MSK1                      (0x00000080)
#define RTC_ALRMAR_ST                        (0x00000070)
#define RTC_ALRMAR_ST_0                      (0x00000010)
#define RTC_ALRMAR_ST_1                      (0x00000020)
#define RTC_ALRMAR_ST_2                      (0x00000040)
#define RTC_ALRMAR_SU                        (0x0000000F)
#define RTC_ALRMAR_SU_0                      (0x00000001)
#define RTC_ALRMAR_SU_1                      (0x00000002)
#define RTC_ALRMAR_SU_2                      (0x00000004)
#define RTC_ALRMAR_SU_3                      (0x00000008)

#define RTC_WPR_KEY                          (0x000000FF)

#define RTC_SSR_SS                           (0x0003FFFF)

#define RTC_SHIFTR_SUBFS                     (0x00007FFF)
#define RTC_SHIFTR_ADD1S                     (0x80000000)

#define RTC_TSTR_PM                          (0x00400000)
#define RTC_TSTR_HT                          (0x00300000)
#define RTC_TSTR_HT_0                        (0x00100000)
#define RTC_TSTR_HT_1                        (0x00200000)
#define RTC_TSTR_HU                          (0x000F0000)
#define RTC_TSTR_HU_0                        (0x00010000)
#define RTC_TSTR_HU_1                        (0x00020000)
#define RTC_TSTR_HU_2                        (0x00040000)
#define RTC_TSTR_HU_3                        (0x00080000)
#define RTC_TSTR_MNT                         (0x00007000)
#define RTC_TSTR_MNT_0                       (0x00001000)
#define RTC_TSTR_MNT_1                       (0x00002000)
#define RTC_TSTR_MNT_2                       (0x00004000)
#define RTC_TSTR_MNU                         (0x00000F00)
#define RTC_TSTR_MNU_0                       (0x00000100)
#define RTC_TSTR_MNU_1                       (0x00000200)
#define RTC_TSTR_MNU_2                       (0x00000400)
#define RTC_TSTR_MNU_3                       (0x00000800)
#define RTC_TSTR_ST                          (0x00000070)
#define RTC_TSTR_ST_0                        (0x00000010)
#define RTC_TSTR_ST_1                        (0x00000020)
#define RTC_TSTR_ST_2                        (0x00000040)
#define RTC_TSTR_SU                          (0x0000000F)
#define RTC_TSTR_SU_0                        (0x00000001)
#define RTC_TSTR_SU_1                        (0x00000002)
#define RTC_TSTR_SU_2                        (0x00000004)
#define RTC_TSTR_SU_3                        (0x00000008)

#define RTC_TSDR_WDU                         (0x0000E000)
#define RTC_TSDR_WDU_0                       (0x00002000)
#define RTC_TSDR_WDU_1                       (0x00004000)
#define RTC_TSDR_WDU_2                       (0x00008000)
#define RTC_TSDR_MT                          (0x00001000)
#define RTC_TSDR_MU                          (0x00000F00)
#define RTC_TSDR_MU_0                        (0x00000100)
#define RTC_TSDR_MU_1                        (0x00000200)
#define RTC_TSDR_MU_2                        (0x00000400)
#define RTC_TSDR_MU_3                        (0x00000800)
#define RTC_TSDR_DT                          (0x00000030)
#define RTC_TSDR_DT_0                        (0x00000010)
#define RTC_TSDR_DT_1                        (0x00000020)
#define RTC_TSDR_DU                          (0x0000000F)
#define RTC_TSDR_DU_0                        (0x00000001)
#define RTC_TSDR_DU_1                        (0x00000002)
#define RTC_TSDR_DU_2                        (0x00000004)
#define RTC_TSDR_DU_3                        (0x00000008)

#define RTC_TSSSR_SS                         (0x0003FFFF)

#define RTC_CALR_CALP                         (0x00008000)
#define RTC_CALR_CALW8                        (0x00004000)
#define RTC_CALR_CALW16                       (0x00002000)
#define RTC_CALR_CALM                         (0x000001FF)
#define RTC_CALR_CALM_0                       (0x00000001)
#define RTC_CALR_CALM_1                       (0x00000002)
#define RTC_CALR_CALM_2                       (0x00000004)
#define RTC_CALR_CALM_3                       (0x00000008)
#define RTC_CALR_CALM_4                       (0x00000010)
#define RTC_CALR_CALM_5                       (0x00000020)
#define RTC_CALR_CALM_6                       (0x00000040)
#define RTC_CALR_CALM_7                       (0x00000080)
#define RTC_CALR_CALM_8                       (0x00000100)

#define RTC_CAL_CALP                         RTC_CALR_CALP
#define RTC_CAL_CALW8                        RTC_CALR_CALW8
#define RTC_CAL_CALW16                       RTC_CALR_CALW16
#define RTC_CAL_CALM                         RTC_CALR_CALM
#define RTC_CAL_CALM_0                       RTC_CALR_CALM_0
#define RTC_CAL_CALM_1                       RTC_CALR_CALM_1
#define RTC_CAL_CALM_2                       RTC_CALR_CALM_2
#define RTC_CAL_CALM_3                       RTC_CALR_CALM_3
#define RTC_CAL_CALM_4                       RTC_CALR_CALM_4
#define RTC_CAL_CALM_5                       RTC_CALR_CALM_5
#define RTC_CAL_CALM_6                       RTC_CALR_CALM_6
#define RTC_CAL_CALM_7                       RTC_CALR_CALM_7
#define RTC_CAL_CALM_8                       RTC_CALR_CALM_8

#define RTC_TAFCR_PC15MODE                   (0x00800000)
#define RTC_TAFCR_PC15VALUE                  (0x00400000)
#define RTC_TAFCR_PC14MODE                   (0x00200000)
#define RTC_TAFCR_PC14VALUE                  (0x00100000)
#define RTC_TAFCR_PC13MODE                   (0x00080000)
#define RTC_TAFCR_PC13VALUE                  (0x00040000)
#define RTC_TAFCR_TAMPPUDIS                  (0x00008000)
#define RTC_TAFCR_TAMPPRCH                   (0x00006000)
#define RTC_TAFCR_TAMPPRCH_0                 (0x00002000)
#define RTC_TAFCR_TAMPPRCH_1                 (0x00004000)
#define RTC_TAFCR_TAMPFLT                    (0x00001800)
#define RTC_TAFCR_TAMPFLT_0                  (0x00000800)
#define RTC_TAFCR_TAMPFLT_1                  (0x00001000)
#define RTC_TAFCR_TAMPFREQ                   (0x00000700)
#define RTC_TAFCR_TAMPFREQ_0                 (0x00000100)
#define RTC_TAFCR_TAMPFREQ_1                 (0x00000200)
#define RTC_TAFCR_TAMPFREQ_2                 (0x00000400)
#define RTC_TAFCR_TAMPTS                     (0x00000080)
#define RTC_TAFCR_TAMP3EDGE                  (0x00000040)
#define RTC_TAFCR_TAMP3E                     (0x00000020)
#define RTC_TAFCR_TAMP2EDGE                  (0x00000010)
#define RTC_TAFCR_TAMP2E                     (0x00000008)
#define RTC_TAFCR_TAMPIE                     (0x00000004)
#define RTC_TAFCR_TAMP1TRG                   (0x00000002)
#define RTC_TAFCR_TAMP1E                     (0x00000001)

#define RTC_TAFCR_ALARMOUTTYPE               RTC_TAFCR_PC13VALUE

#define RTC_ALRMASSR_MASKSS                  (0x0F000000)
#define RTC_ALRMASSR_MASKSS_0                (0x01000000)
#define RTC_ALRMASSR_MASKSS_1                (0x02000000)
#define RTC_ALRMASSR_MASKSS_2                (0x04000000)
#define RTC_ALRMASSR_MASKSS_3                (0x08000000)
#define RTC_ALRMASSR_SS                      (0x00007FFF)

#define RTC_BKP0R                            (0xFFFFFFFF)

#define RTC_BKP1R                            (0xFFFFFFFF)

#define RTC_BKP2R                            (0xFFFFFFFF)

#define RTC_BKP3R                            (0xFFFFFFFF)

#define RTC_BKP4R                            (0xFFFFFFFF)

#define  SPI_CR1_CPHA                        (0x0001)            /*!< Clock Phase */
#define  SPI_CR1_CPOL                        (0x0002)            /*!< Clock Polarity */
#define  SPI_CR1_MSTR                        (0x0004)            /*!< Master Selection */
#define  SPI_CR1_BR                          (0x0038)            /*!< BR[2:0] bits (Baud Rate Control) */
#define  SPI_CR1_BR_0                        (0x0008)            /*!< Bit 0 */
#define  SPI_CR1_BR_1                        (0x0010)            /*!< Bit 1 */
#define  SPI_CR1_BR_2                        (0x0020)            /*!< Bit 2 */
#define  SPI_CR1_SPE                         (0x0040)            /*!< SPI Enable */
#define  SPI_CR1_LSBFIRST                    (0x0080)            /*!< Frame Format */
#define  SPI_CR1_SSI                         (0x0100)            /*!< Internal slave select */
#define  SPI_CR1_SSM                         (0x0200)            /*!< Software slave management */
#define  SPI_CR1_RXONLY                      (0x0400)            /*!< Receive only */
#define  SPI_CR1_CRCL                        (0x0800)            /*!< CRC Length */
#define  SPI_CR1_CRCNEXT                     (0x1000)            /*!< Transmit CRC next */
#define  SPI_CR1_CRCEN                       (0x2000)            /*!< Hardware CRC calculation enable */
#define  SPI_CR1_BIDIOE                      (0x4000)            /*!< Output enable in bidirectional mode */
#define  SPI_CR1_BIDIMODE                    (0x8000)            /*!< Bidirectional data mode enable */

#define  SPI_CR2_RXDMAEN                     (0x0001)            /*!< Rx Buffer DMA Enable */
#define  SPI_CR2_TXDMAEN                     (0x0002)            /*!< Tx Buffer DMA Enable */
#define  SPI_CR2_SSOE                        (0x0004)            /*!< SS Output Enable */
#define  SPI_CR2_NSSP                        (0x0008)            /*!< NSS pulse management Enable */
#define  SPI_CR2_FRF                         (0x0010)            /*!< Frame Format Enable */
#define  SPI_CR2_ERRIE                       (0x0020)            /*!< Error Interrupt Enable */
#define  SPI_CR2_RXNEIE                      (0x0040)            /*!< RX buffer Not Empty Interrupt Enable */
#define  SPI_CR2_TXEIE                       (0x0080)            /*!< Tx buffer Empty Interrupt Enable */
#define  SPI_CR2_DS                          (0x0F00)            /*!< DS[3:0] Data Size */
#define  SPI_CR2_DS_0                        (0x0100)            /*!< Bit 0 */
#define  SPI_CR2_DS_1                        (0x0200)            /*!< Bit 1 */
#define  SPI_CR2_DS_2                        (0x0400)            /*!< Bit 2 */
#define  SPI_CR2_DS_3                        (0x0800)            /*!< Bit 3 */
#define  SPI_CR2_FRXTH                       (0x1000)            /*!< FIFO reception Threshold */
#define  SPI_CR2_LDMARX                      (0x2000)            /*!< Last DMA transfer for reception */
#define  SPI_CR2_LDMATX                      (0x4000)            /*!< Last DMA transfer for transmission */

#define  SPI_SR_RXNE                         (0x0001)            /*!< Receive buffer Not Empty */
#define  SPI_SR_TXE                          (0x0002)            /*!< Transmit buffer Empty */
#define  SPI_SR_CHSIDE                       (0x0004)            /*!< Channel side */
#define  SPI_SR_UDR                          (0x0008)            /*!< Underrun flag */
#define  SPI_SR_CRCERR                       (0x0010)            /*!< CRC Error flag */
#define  SPI_SR_MODF                         (0x0020)            /*!< Mode fault */
#define  SPI_SR_OVR                          (0x0040)            /*!< Overrun flag */
#define  SPI_SR_BSY                          (0x0080)            /*!< Busy flag */
#define  SPI_SR_FRE                          (0x0100)            /*!< TI frame format error */
#define  SPI_SR_FRLVL                        (0x0600)            /*!< FIFO Reception Level */
#define  SPI_SR_FRLVL_0                      (0x0200)            /*!< Bit 0 */
#define  SPI_SR_FRLVL_1                      (0x0400)            /*!< Bit 1 */
#define  SPI_SR_FTLVL                        (0x1800)            /*!< FIFO Transmission Level */
#define  SPI_SR_FTLVL_0                      (0x0800)            /*!< Bit 0 */
#define  SPI_SR_FTLVL_1                      (0x1000)            /*!< Bit 1 */

#define  SPI_DR_DR                           (0xFFFF)            /*!< Data Register */

#define  SPI_CRCPR_CRCPOLY                   (0xFFFF)            /*!< CRC polynomial register */

#define  SPI_RXCRCR_RXCRC                    (0xFFFF)            /*!< Rx CRC Register */

#define  SPI_TXCRCR_TXCRC                    (0xFFFF)            /*!< Tx CRC Register */

#define  SPI_I2SCFGR_CHLEN                   (0x0001)            /*!<Channel length (number of bits per audio channel) */
#define  SPI_I2SCFGR_DATLEN                  (0x0006)            /*!<DATLEN[1:0] bits (Data length to be transferred) */
#define  SPI_I2SCFGR_DATLEN_0                (0x0002)            /*!<Bit 0 */
#define  SPI_I2SCFGR_DATLEN_1                (0x0004)            /*!<Bit 1 */
#define  SPI_I2SCFGR_CKPOL                   (0x0008)            /*!<steady state clock polarity */
#define  SPI_I2SCFGR_I2SSTD                  (0x0030)            /*!<I2SSTD[1:0] bits (I2S standard selection) */
#define  SPI_I2SCFGR_I2SSTD_0                (0x0010)            /*!<Bit 0 */
#define  SPI_I2SCFGR_I2SSTD_1                (0x0020)            /*!<Bit 1 */
#define  SPI_I2SCFGR_PCMSYNC                 (0x0080)            /*!<PCM frame synchronization */
#define  SPI_I2SCFGR_I2SCFG                  (0x0300)            /*!<I2SCFG[1:0] bits (I2S configuration mode) */
#define  SPI_I2SCFGR_I2SCFG_0                (0x0100)            /*!<Bit 0 */
#define  SPI_I2SCFGR_I2SCFG_1                (0x0200)            /*!<Bit 1 */
#define  SPI_I2SCFGR_I2SE                    (0x0400)            /*!<I2S Enable */
#define  SPI_I2SCFGR_I2SMOD                  (0x0800)            /*!<I2S mode selection */

#define  SPI_I2SPR_I2SDIV                    (0x00FF)            /*!<I2S Linear prescaler */
#define  SPI_I2SPR_ODD                       (0x0100)            /*!<Odd factor for the prescaler */
#define  SPI_I2SPR_MCKOE                     (0x0200)            /*!<Master Clock Output Enable */

#define SYSCFG_CFGR1_MEM_MODE               (0x00000003) /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0             (0x00000001) /*!< SYSCFG_Memory Remap Config Bit 0 */
#define SYSCFG_CFGR1_MEM_MODE_1             (0x00000002) /*!< SYSCFG_Memory Remap Config Bit 1 */
#define SYSCFG_CFGR1_PA11_PA12_RMP          (0x00000010) /*!< PA11 and PA12 remap on QFN28 and TSSOP20 packages (only for STM32F042 devices)*/
#define SYSCFG_CFGR1_ADC_DMA_RMP            (0x00000100) /*!< ADC DMA remap */
#define SYSCFG_CFGR1_USART1TX_DMA_RMP       (0x00000200) /*!< USART1 TX DMA remap */
#define SYSCFG_CFGR1_USART1RX_DMA_RMP       (0x00000400) /*!< USART1 RX DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP          (0x00000800) /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP          (0x00001000) /*!< Timer 17 DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP2         (0x00002000) /*!< Timer 16 DMA remap 2 (only for STM32F072) */
#define SYSCFG_CFGR1_TIM17_DMA_RMP2         (0x00004000) /*!< Timer 17 DMA remap 2 (only for STM32F072) */
#define SYSCFG_CFGR1_I2C_FMP_PB6            (0x00010000) /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB7            (0x00020000) /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB8            (0x00040000) /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_PB9            (0x00080000) /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C_FMP_I2C1           (0x00100000) /*!< Enable Fast Mode Plus on PB10, PB11, PF6 and PF7(only for STM32F030, STM32F031 and STM32F072 devices) */
#define SYSCFG_CFGR1_I2C_FMP_I2C2           (0x00200000) /*!< Enable I2C2 Fast mode plus (only for STM32F072) */
#define SYSCFG_CFGR1_I2C_FMP_PA9            (0x00400000) /*!< Enable Fast Mode Plus on PA9 (only for STM32F030, STM32F031, STM32F042 and STM32F072 devices) */
#define SYSCFG_CFGR1_I2C_FMP_PA10           (0x00800000) /*!< Enable Fast Mode Plus on PA10(only for STM32F030, STM32F031, STM32F042 and STM32F072 devices) */
#define SYSCFG_CFGR1_SPI2_DMA_RMP           (0x01000000) /*!< SPI2 DMA remap (only for STM32F072) */
#define SYSCFG_CFGR1_USART2_DMA_RMP         (0x02000000) /*!< USART2 DMA remap (only for STM32F072) */
#define SYSCFG_CFGR1_USART3_DMA_RMP         (0x04000000) /*!< USART3 DMA remap (only for STM32F072) */
#define SYSCFG_CFGR1_I2C1_DMA_RMP           (0x08000000) /*!< I2C1 DMA remap (only for STM32F072) */
#define SYSCFG_CFGR1_TIM1_DMA_RMP           (0x10000000) /*!< TIM1 DMA remap (only for STM32F072) */
#define SYSCFG_CFGR1_TIM2_DMA_RMP           (0x20000000) /*!< TIM2 DMA remap (only for STM32F072) */
#define SYSCFG_CFGR1_TIM3_DMA_RMP           (0x40000000) /*!< TIM3 DMA remap (only for STM32F072) */

#define SYSCFG_EXTICR1_EXTI0            (0x000F) /*!< EXTI 0 configuration */
#define SYSCFG_EXTICR1_EXTI1            (0x00F0) /*!< EXTI 1 configuration */
#define SYSCFG_EXTICR1_EXTI2            (0x0F00) /*!< EXTI 2 configuration */
#define SYSCFG_EXTICR1_EXTI3            (0xF000) /*!< EXTI 3 configuration */

/**
  * @brief  EXTI0 configuration
  */
#define SYSCFG_EXTICR1_EXTI0_PA         (0x0000) /*!< PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB         (0x0001) /*!< PB[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PC         (0x0002) /*!< PC[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PD         (0x0003) /*!< PD[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PE         (0x0004) /*!< PE[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PF         (0x0005) /*!< PF[0] pin */

/**
  * @brief  EXTI1 configuration
  */
#define SYSCFG_EXTICR1_EXTI1_PA         (0x0000) /*!< PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB         (0x0010) /*!< PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC         (0x0020) /*!< PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD         (0x0030) /*!< PD[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PE         (0x0040) /*!< PE[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PF         (0x0050) /*!< PF[1] pin */

/**
  * @brief  EXTI2 configuration
  */
#define SYSCFG_EXTICR1_EXTI2_PA         (0x0000) /*!< PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB         (0x0100) /*!< PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC         (0x0200) /*!< PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD         (0x0300) /*!< PD[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PE         (0x0400) /*!< PE[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PF         (0x0500) /*!< PF[2] pin */

/**
  * @brief  EXTI3 configuration
  */
#define SYSCFG_EXTICR1_EXTI3_PA         (0x0000) /*!< PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB         (0x1000) /*!< PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC         (0x2000) /*!< PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD         (0x3000) /*!< PD[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PE         (0x4000) /*!< PE[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PF         (0x5000) /*!< PF[3] pin */

#define SYSCFG_EXTICR2_EXTI4            (0x000F) /*!< EXTI 4 configuration */
#define SYSCFG_EXTICR2_EXTI5            (0x00F0) /*!< EXTI 5 configuration */
#define SYSCFG_EXTICR2_EXTI6            (0x0F00) /*!< EXTI 6 configuration */
#define SYSCFG_EXTICR2_EXTI7            (0xF000) /*!< EXTI 7 configuration */

/**
  * @brief  EXTI4 configuration
  */
#define SYSCFG_EXTICR2_EXTI4_PA         (0x0000) /*!< PA[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PB         (0x0001) /*!< PB[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PC         (0x0002) /*!< PC[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PD         (0x0003) /*!< PD[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PE         (0x0004) /*!< PE[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PF         (0x0005) /*!< PF[4] pin */

/**
  * @brief  EXTI5 configuration
  */
#define SYSCFG_EXTICR2_EXTI5_PA         (0x0000) /*!< PA[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PB         (0x0010) /*!< PB[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PC         (0x0020) /*!< PC[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PD         (0x0030) /*!< PD[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PE         (0x0040) /*!< PE[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PF         (0x0050) /*!< PF[5] pin */

/**
  * @brief  EXTI6 configuration
  */
#define SYSCFG_EXTICR2_EXTI6_PA         (0x0000) /*!< PA[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PB         (0x0100) /*!< PB[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PC         (0x0200) /*!< PC[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PD         (0x0300) /*!< PD[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PE         (0x0400) /*!< PE[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PF         (0x0500) /*!< PF[6] pin */

/**
  * @brief  EXTI7 configuration
  */
#define SYSCFG_EXTICR2_EXTI7_PA         (0x0000) /*!< PA[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PB         (0x1000) /*!< PB[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PC         (0x2000) /*!< PC[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PD         (0x3000) /*!< PD[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PE         (0x4000) /*!< PE[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PF         (0x5000) /*!< PF[7] pin */

#define SYSCFG_EXTICR3_EXTI8            (0x000F) /*!< EXTI 8 configuration */
#define SYSCFG_EXTICR3_EXTI9            (0x00F0) /*!< EXTI 9 configuration */
#define SYSCFG_EXTICR3_EXTI10           (0x0F00) /*!< EXTI 10 configuration */
#define SYSCFG_EXTICR3_EXTI11           (0xF000) /*!< EXTI 11 configuration */

/**
  * @brief  EXTI8 configuration
  */
#define SYSCFG_EXTICR3_EXTI8_PA         (0x0000) /*!< PA[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PB         (0x0001) /*!< PB[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PC         (0x0002) /*!< PC[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PD         (0x0003) /*!< PD[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PE         (0x0004) /*!< PE[8] pin */

/**
  * @brief  EXTI9 configuration
  */
#define SYSCFG_EXTICR3_EXTI9_PA         (0x0000) /*!< PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB         (0x0010) /*!< PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC         (0x0020) /*!< PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD         (0x0030) /*!< PD[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PE         (0x0040) /*!< PE[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PF         (0x0050) /*!< PF[9] pin */

/**
  * @brief  EXTI10 configuration
  */
#define SYSCFG_EXTICR3_EXTI10_PA        (0x0000) /*!< PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB        (0x0100) /*!< PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC        (0x0200) /*!< PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD        (0x0300) /*!< PE[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PE        (0x0400) /*!< PD[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PF        (0x0500) /*!< PF[10] pin */

/**
  * @brief  EXTI11 configuration
  */
#define SYSCFG_EXTICR3_EXTI11_PA        (0x0000) /*!< PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB        (0x1000) /*!< PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC        (0x2000) /*!< PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD        (0x3000) /*!< PD[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PE        (0x4000) /*!< PE[11] pin */

#define SYSCFG_EXTICR4_EXTI12           (0x000F) /*!< EXTI 12 configuration */
#define SYSCFG_EXTICR4_EXTI13           (0x00F0) /*!< EXTI 13 configuration */
#define SYSCFG_EXTICR4_EXTI14           (0x0F00) /*!< EXTI 14 configuration */
#define SYSCFG_EXTICR4_EXTI15           (0xF000) /*!< EXTI 15 configuration */

/**
  * @brief  EXTI12 configuration
  */
#define SYSCFG_EXTICR4_EXTI12_PA        (0x0000) /*!< PA[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PB        (0x0001) /*!< PB[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PC        (0x0002) /*!< PC[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PD        (0x0003) /*!< PD[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PE        (0x0004) /*!< PE[12] pin */

/**
  * @brief  EXTI13 configuration
  */
#define SYSCFG_EXTICR4_EXTI13_PA        (0x0000) /*!< PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB        (0x0010) /*!< PB[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PC        (0x0020) /*!< PC[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PD        (0x0030) /*!< PD[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PE        (0x0040) /*!< PE[13] pin */

/**
  * @brief  EXTI14 configuration
  */
#define SYSCFG_EXTICR4_EXTI14_PA        (0x0000) /*!< PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB        (0x0100) /*!< PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC        (0x0200) /*!< PC[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PD        (0x0300) /*!< PD[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PE        (0x0400) /*!< PE[14] pin */

/**
  * @brief  EXTI15 configuration
  */
#define SYSCFG_EXTICR4_EXTI15_PA        (0x0000) /*!< PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB        (0x1000) /*!< PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC        (0x2000) /*!< PC[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PD        (0x3000) /*!< PD[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PE        (0x4000) /*!< PE[15] pin */

#define SYSCFG_CFGR2_LOCKUP_LOCK               (0x00000001) /*!< Enables and locks the PVD connection with Timer1 Break Input and also the PVD_EN and PVDSEL[2:0] bits of the Power Control Interface */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK          (0x00000002) /*!< Enables and locks the SRAM_PARITY error signal with Break Input of TIMER1 */
#define SYSCFG_CFGR2_PVD_LOCK                  (0x00000004) /*!< Enables and locks the LOCKUP (Hardfault) output of CortexM0 with Break Input of TIMER1 */
#define SYSCFG_CFGR2_SRAM_PEF                  (0x00000100) /*!< SRAM Parity error flag */

#define SYSCFG_CFGR2_SRAM_PE                   SYSCFG_CFGR2_SRAM_PEF
#define  TIM_CR1_CEN                         (0x0001)            /*!<Counter enable */
#define  TIM_CR1_UDIS                        (0x0002)            /*!<Update disable */
#define  TIM_CR1_URS                         (0x0004)            /*!<Update request source */
#define  TIM_CR1_OPM                         (0x0008)            /*!<One pulse mode */
#define  TIM_CR1_DIR                         (0x0010)            /*!<Direction */

#define  TIM_CR1_CMS                         (0x0060)            /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define  TIM_CR1_CMS_0                       (0x0020)            /*!<Bit 0 */
#define  TIM_CR1_CMS_1                       (0x0040)            /*!<Bit 1 */

#define  TIM_CR1_ARPE                        (0x0080)            /*!<Auto-reload preload enable */

#define  TIM_CR1_CKD                         (0x0300)            /*!<CKD[1:0] bits (clock division) */
#define  TIM_CR1_CKD_0                       (0x0100)            /*!<Bit 0 */
#define  TIM_CR1_CKD_1                       (0x0200)            /*!<Bit 1 */

#define  TIM_CR2_CCPC                        (0x0001)            /*!<Capture/Compare Preloaded Control */
#define  TIM_CR2_CCUS                        (0x0004)            /*!<Capture/Compare Control Update Selection */
#define  TIM_CR2_CCDS                        (0x0008)            /*!<Capture/Compare DMA Selection */

#define  TIM_CR2_MMS                         (0x0070)            /*!<MMS[2:0] bits (Master Mode Selection) */
#define  TIM_CR2_MMS_0                       (0x0010)            /*!<Bit 0 */
#define  TIM_CR2_MMS_1                       (0x0020)            /*!<Bit 1 */
#define  TIM_CR2_MMS_2                       (0x0040)            /*!<Bit 2 */

#define  TIM_CR2_TI1S                        (0x0080)            /*!<TI1 Selection */
#define  TIM_CR2_OIS1                        (0x0100)            /*!<Output Idle state 1 (OC1 output) */
#define  TIM_CR2_OIS1N                       (0x0200)            /*!<Output Idle state 1 (OC1N output) */
#define  TIM_CR2_OIS2                        (0x0400)            /*!<Output Idle state 2 (OC2 output) */
#define  TIM_CR2_OIS2N                       (0x0800)            /*!<Output Idle state 2 (OC2N output) */
#define  TIM_CR2_OIS3                        (0x1000)            /*!<Output Idle state 3 (OC3 output) */
#define  TIM_CR2_OIS3N                       (0x2000)            /*!<Output Idle state 3 (OC3N output) */
#define  TIM_CR2_OIS4                        (0x4000)            /*!<Output Idle state 4 (OC4 output) */

#define  TIM_SMCR_SMS                        (0x0007)            /*!<SMS[2:0] bits (Slave mode selection) */
#define  TIM_SMCR_SMS_0                      (0x0001)            /*!<Bit 0 */
#define  TIM_SMCR_SMS_1                      (0x0002)            /*!<Bit 1 */
#define  TIM_SMCR_SMS_2                      (0x0004)            /*!<Bit 2 */

#define  TIM_SMCR_OCCS                       (0x0008)            /*!< OCREF clear selection */

#define  TIM_SMCR_TS                         (0x0070)            /*!<TS[2:0] bits (Trigger selection) */
#define  TIM_SMCR_TS_0                       (0x0010)            /*!<Bit 0 */
#define  TIM_SMCR_TS_1                       (0x0020)            /*!<Bit 1 */
#define  TIM_SMCR_TS_2                       (0x0040)            /*!<Bit 2 */

#define  TIM_SMCR_MSM                        (0x0080)            /*!<Master/slave mode */

#define  TIM_SMCR_ETF                        (0x0F00)            /*!<ETF[3:0] bits (External trigger filter) */
#define  TIM_SMCR_ETF_0                      (0x0100)            /*!<Bit 0 */
#define  TIM_SMCR_ETF_1                      (0x0200)            /*!<Bit 1 */
#define  TIM_SMCR_ETF_2                      (0x0400)            /*!<Bit 2 */
#define  TIM_SMCR_ETF_3                      (0x0800)            /*!<Bit 3 */

#define  TIM_SMCR_ETPS                       (0x3000)            /*!<ETPS[1:0] bits (External trigger prescaler) */
#define  TIM_SMCR_ETPS_0                     (0x1000)            /*!<Bit 0 */
#define  TIM_SMCR_ETPS_1                     (0x2000)            /*!<Bit 1 */

#define  TIM_SMCR_ECE                        (0x4000)            /*!<External clock enable */
#define  TIM_SMCR_ETP                        (0x8000)            /*!<External trigger polarity */

#define  TIM_DIER_UIE                        (0x0001)            /*!<Update interrupt enable */
#define  TIM_DIER_CC1IE                      (0x0002)            /*!<Capture/Compare 1 interrupt enable */
#define  TIM_DIER_CC2IE                      (0x0004)            /*!<Capture/Compare 2 interrupt enable */
#define  TIM_DIER_CC3IE                      (0x0008)            /*!<Capture/Compare 3 interrupt enable */
#define  TIM_DIER_CC4IE                      (0x0010)            /*!<Capture/Compare 4 interrupt enable */
#define  TIM_DIER_COMIE                      (0x0020)            /*!<COM interrupt enable */
#define  TIM_DIER_TIE                        (0x0040)            /*!<Trigger interrupt enable */
#define  TIM_DIER_BIE                        (0x0080)            /*!<Break interrupt enable */
#define  TIM_DIER_UDE                        (0x0100)            /*!<Update DMA request enable */
#define  TIM_DIER_CC1DE                      (0x0200)            /*!<Capture/Compare 1 DMA request enable */
#define  TIM_DIER_CC2DE                      (0x0400)            /*!<Capture/Compare 2 DMA request enable */
#define  TIM_DIER_CC3DE                      (0x0800)            /*!<Capture/Compare 3 DMA request enable */
#define  TIM_DIER_CC4DE                      (0x1000)            /*!<Capture/Compare 4 DMA request enable */
#define  TIM_DIER_COMDE                      (0x2000)            /*!<COM DMA request enable */
#define  TIM_DIER_TDE                        (0x4000)            /*!<Trigger DMA request enable */

#define  TIM_SR_UIF                          (0x0001)            /*!<Update interrupt Flag */
#define  TIM_SR_CC1IF                        (0x0002)            /*!<Capture/Compare 1 interrupt Flag */
#define  TIM_SR_CC2IF                        (0x0004)            /*!<Capture/Compare 2 interrupt Flag */
#define  TIM_SR_CC3IF                        (0x0008)            /*!<Capture/Compare 3 interrupt Flag */
#define  TIM_SR_CC4IF                        (0x0010)            /*!<Capture/Compare 4 interrupt Flag */
#define  TIM_SR_COMIF                        (0x0020)            /*!<COM interrupt Flag */
#define  TIM_SR_TIF                          (0x0040)            /*!<Trigger interrupt Flag */
#define  TIM_SR_BIF                          (0x0080)            /*!<Break interrupt Flag */
#define  TIM_SR_CC1OF                        (0x0200)            /*!<Capture/Compare 1 Overcapture Flag */
#define  TIM_SR_CC2OF                        (0x0400)            /*!<Capture/Compare 2 Overcapture Flag */
#define  TIM_SR_CC3OF                        (0x0800)            /*!<Capture/Compare 3 Overcapture Flag */
#define  TIM_SR_CC4OF                        (0x1000)            /*!<Capture/Compare 4 Overcapture Flag */

#define  TIM_EGR_UG                          (0x01)               /*!<Update Generation */
#define  TIM_EGR_CC1G                        (0x02)               /*!<Capture/Compare 1 Generation */
#define  TIM_EGR_CC2G                        (0x04)               /*!<Capture/Compare 2 Generation */
#define  TIM_EGR_CC3G                        (0x08)               /*!<Capture/Compare 3 Generation */
#define  TIM_EGR_CC4G                        (0x10)               /*!<Capture/Compare 4 Generation */
#define  TIM_EGR_COMG                        (0x20)               /*!<Capture/Compare Control Update Generation */
#define  TIM_EGR_TG                          (0x40)               /*!<Trigger Generation */
#define  TIM_EGR_BG                          (0x80)               /*!<Break Generation */

#define  TIM_CCMR1_CC1S                      (0x0003)            /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define  TIM_CCMR1_CC1S_0                    (0x0001)            /*!<Bit 0 */
#define  TIM_CCMR1_CC1S_1                    (0x0002)            /*!<Bit 1 */

#define  TIM_CCMR1_OC1FE                     (0x0004)            /*!<Output Compare 1 Fast enable */
#define  TIM_CCMR1_OC1PE                     (0x0008)            /*!<Output Compare 1 Preload enable */

#define  TIM_CCMR1_OC1M                      (0x0070)            /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define  TIM_CCMR1_OC1M_0                    (0x0010)            /*!<Bit 0 */
#define  TIM_CCMR1_OC1M_1                    (0x0020)            /*!<Bit 1 */
#define  TIM_CCMR1_OC1M_2                    (0x0040)            /*!<Bit 2 */

#define  TIM_CCMR1_OC1CE                     (0x0080)            /*!<Output Compare 1Clear Enable */

#define  TIM_CCMR1_CC2S                      (0x0300)            /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define  TIM_CCMR1_CC2S_0                    (0x0100)            /*!<Bit 0 */
#define  TIM_CCMR1_CC2S_1                    (0x0200)            /*!<Bit 1 */

#define  TIM_CCMR1_OC2FE                     (0x0400)            /*!<Output Compare 2 Fast enable */
#define  TIM_CCMR1_OC2PE                     (0x0800)            /*!<Output Compare 2 Preload enable */

#define  TIM_CCMR1_OC2M                      (0x7000)            /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define  TIM_CCMR1_OC2M_0                    (0x1000)            /*!<Bit 0 */
#define  TIM_CCMR1_OC2M_1                    (0x2000)            /*!<Bit 1 */
#define  TIM_CCMR1_OC2M_2                    (0x4000)            /*!<Bit 2 */

#define  TIM_CCMR1_OC2CE                     (0x8000)            /*!<Output Compare 2 Clear Enable */


#define  TIM_CCMR1_IC1PSC                    (0x000C)            /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define  TIM_CCMR1_IC1PSC_0                  (0x0004)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1PSC_1                  (0x0008)            /*!<Bit 1 */

#define  TIM_CCMR1_IC1F                      (0x00F0)            /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define  TIM_CCMR1_IC1F_0                    (0x0010)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1F_1                    (0x0020)            /*!<Bit 1 */
#define  TIM_CCMR1_IC1F_2                    (0x0040)            /*!<Bit 2 */
#define  TIM_CCMR1_IC1F_3                    (0x0080)            /*!<Bit 3 */

#define  TIM_CCMR1_IC2PSC                    (0x0C00)            /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define  TIM_CCMR1_IC2PSC_0                  (0x0400)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2PSC_1                  (0x0800)            /*!<Bit 1 */

#define  TIM_CCMR1_IC2F                      (0xF000)            /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define  TIM_CCMR1_IC2F_0                    (0x1000)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2F_1                    (0x2000)            /*!<Bit 1 */
#define  TIM_CCMR1_IC2F_2                    (0x4000)            /*!<Bit 2 */
#define  TIM_CCMR1_IC2F_3                    (0x8000)            /*!<Bit 3 */

#define  TIM_CCMR2_CC3S                      (0x0003)            /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define  TIM_CCMR2_CC3S_0                    (0x0001)            /*!<Bit 0 */
#define  TIM_CCMR2_CC3S_1                    (0x0002)            /*!<Bit 1 */

#define  TIM_CCMR2_OC3FE                     (0x0004)            /*!<Output Compare 3 Fast enable */
#define  TIM_CCMR2_OC3PE                     (0x0008)            /*!<Output Compare 3 Preload enable */

#define  TIM_CCMR2_OC3M                      (0x0070)            /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define  TIM_CCMR2_OC3M_0                    (0x0010)            /*!<Bit 0 */
#define  TIM_CCMR2_OC3M_1                    (0x0020)            /*!<Bit 1 */
#define  TIM_CCMR2_OC3M_2                    (0x0040)            /*!<Bit 2 */

#define  TIM_CCMR2_OC3CE                     (0x0080)            /*!<Output Compare 3 Clear Enable */

#define  TIM_CCMR2_CC4S                      (0x0300)            /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define  TIM_CCMR2_CC4S_0                    (0x0100)            /*!<Bit 0 */
#define  TIM_CCMR2_CC4S_1                    (0x0200)            /*!<Bit 1 */

#define  TIM_CCMR2_OC4FE                     (0x0400)            /*!<Output Compare 4 Fast enable */
#define  TIM_CCMR2_OC4PE                     (0x0800)            /*!<Output Compare 4 Preload enable */

#define  TIM_CCMR2_OC4M                      (0x7000)            /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define  TIM_CCMR2_OC4M_0                    (0x1000)            /*!<Bit 0 */
#define  TIM_CCMR2_OC4M_1                    (0x2000)            /*!<Bit 1 */
#define  TIM_CCMR2_OC4M_2                    (0x4000)            /*!<Bit 2 */

#define  TIM_CCMR2_OC4CE                     (0x8000)            /*!<Output Compare 4 Clear Enable */


#define  TIM_CCMR2_IC3PSC                    (0x000C)            /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define  TIM_CCMR2_IC3PSC_0                  (0x0004)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3PSC_1                  (0x0008)            /*!<Bit 1 */

#define  TIM_CCMR2_IC3F                      (0x00F0)            /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define  TIM_CCMR2_IC3F_0                    (0x0010)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3F_1                    (0x0020)            /*!<Bit 1 */
#define  TIM_CCMR2_IC3F_2                    (0x0040)            /*!<Bit 2 */
#define  TIM_CCMR2_IC3F_3                    (0x0080)            /*!<Bit 3 */

#define  TIM_CCMR2_IC4PSC                    (0x0C00)            /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define  TIM_CCMR2_IC4PSC_0                  (0x0400)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4PSC_1                  (0x0800)            /*!<Bit 1 */

#define  TIM_CCMR2_IC4F                      (0xF000)            /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define  TIM_CCMR2_IC4F_0                    (0x1000)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4F_1                    (0x2000)            /*!<Bit 1 */
#define  TIM_CCMR2_IC4F_2                    (0x4000)            /*!<Bit 2 */
#define  TIM_CCMR2_IC4F_3                    (0x8000)            /*!<Bit 3 */

#define  TIM_CCER_CC1E                       (0x0001)            /*!<Capture/Compare 1 output enable */
#define  TIM_CCER_CC1P                       (0x0002)            /*!<Capture/Compare 1 output Polarity */
#define  TIM_CCER_CC1NE                      (0x0004)            /*!<Capture/Compare 1 Complementary output enable */
#define  TIM_CCER_CC1NP                      (0x0008)            /*!<Capture/Compare 1 Complementary output Polarity */
#define  TIM_CCER_CC2E                       (0x0010)            /*!<Capture/Compare 2 output enable */
#define  TIM_CCER_CC2P                       (0x0020)            /*!<Capture/Compare 2 output Polarity */
#define  TIM_CCER_CC2NE                      (0x0040)            /*!<Capture/Compare 2 Complementary output enable */
#define  TIM_CCER_CC2NP                      (0x0080)            /*!<Capture/Compare 2 Complementary output Polarity */
#define  TIM_CCER_CC3E                       (0x0100)            /*!<Capture/Compare 3 output enable */
#define  TIM_CCER_CC3P                       (0x0200)            /*!<Capture/Compare 3 output Polarity */
#define  TIM_CCER_CC3NE                      (0x0400)            /*!<Capture/Compare 3 Complementary output enable */
#define  TIM_CCER_CC3NP                      (0x0800)            /*!<Capture/Compare 3 Complementary output Polarity */
#define  TIM_CCER_CC4E                       (0x1000)            /*!<Capture/Compare 4 output enable */
#define  TIM_CCER_CC4P                       (0x2000)            /*!<Capture/Compare 4 output Polarity */
#define  TIM_CCER_CC4NP                      (0x8000)            /*!<Capture/Compare 4 Complementary output Polarity */

#define  TIM_CNT_CNT                         (0xFFFF)            /*!<Counter Value */

#define  TIM_PSC_PSC                         (0xFFFF)            /*!<Prescaler Value */

#define  TIM_ARR_ARR                         (0xFFFF)            /*!<actual auto-reload Value */

#define  TIM_RCR_REP                         (0xFF)               /*!<Repetition Counter Value */

#define  TIM_CCR1_CCR1                       (0xFFFF)            /*!<Capture/Compare 1 Value */

#define  TIM_CCR2_CCR2                       (0xFFFF)            /*!<Capture/Compare 2 Value */

#define  TIM_CCR3_CCR3                       (0xFFFF)            /*!<Capture/Compare 3 Value */

#define  TIM_CCR4_CCR4                       (0xFFFF)            /*!<Capture/Compare 4 Value */

#define  TIM_BDTR_DTG                        (0x00FF)            /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define  TIM_BDTR_DTG_0                      (0x0001)            /*!<Bit 0 */
#define  TIM_BDTR_DTG_1                      (0x0002)            /*!<Bit 1 */
#define  TIM_BDTR_DTG_2                      (0x0004)            /*!<Bit 2 */
#define  TIM_BDTR_DTG_3                      (0x0008)            /*!<Bit 3 */
#define  TIM_BDTR_DTG_4                      (0x0010)            /*!<Bit 4 */
#define  TIM_BDTR_DTG_5                      (0x0020)            /*!<Bit 5 */
#define  TIM_BDTR_DTG_6                      (0x0040)            /*!<Bit 6 */
#define  TIM_BDTR_DTG_7                      (0x0080)            /*!<Bit 7 */

#define  TIM_BDTR_LOCK                       (0x0300)            /*!<LOCK[1:0] bits (Lock Configuration) */
#define  TIM_BDTR_LOCK_0                     (0x0100)            /*!<Bit 0 */
#define  TIM_BDTR_LOCK_1                     (0x0200)            /*!<Bit 1 */

#define  TIM_BDTR_OSSI                       (0x0400)            /*!<Off-State Selection for Idle mode */
#define  TIM_BDTR_OSSR                       (0x0800)            /*!<Off-State Selection for Run mode */
#define  TIM_BDTR_BKE                        (0x1000)            /*!<Break enable */
#define  TIM_BDTR_BKP                        (0x2000)            /*!<Break Polarity */
#define  TIM_BDTR_AOE                        (0x4000)            /*!<Automatic Output enable */
#define  TIM_BDTR_MOE                        (0x8000)            /*!<Main Output enable */

#define  TIM_DCR_DBA                         (0x001F)            /*!<DBA[4:0] bits (DMA Base Address) */
#define  TIM_DCR_DBA_0                       (0x0001)            /*!<Bit 0 */
#define  TIM_DCR_DBA_1                       (0x0002)            /*!<Bit 1 */
#define  TIM_DCR_DBA_2                       (0x0004)            /*!<Bit 2 */
#define  TIM_DCR_DBA_3                       (0x0008)            /*!<Bit 3 */
#define  TIM_DCR_DBA_4                       (0x0010)            /*!<Bit 4 */

#define  TIM_DCR_DBL                         (0x1F00)            /*!<DBL[4:0] bits (DMA Burst Length) */
#define  TIM_DCR_DBL_0                       (0x0100)            /*!<Bit 0 */
#define  TIM_DCR_DBL_1                       (0x0200)            /*!<Bit 1 */
#define  TIM_DCR_DBL_2                       (0x0400)            /*!<Bit 2 */
#define  TIM_DCR_DBL_3                       (0x0800)            /*!<Bit 3 */
#define  TIM_DCR_DBL_4                       (0x1000)            /*!<Bit 4 */

#define  TIM_DMAR_DMAB                       (0xFFFF)            /*!<DMA register for burst accesses */

#define TIM14_OR_TI1_RMP                       (0x0003)            /*!<TI1_RMP[1:0] bits (TIM14 Input 4 remap) */
#define TIM14_OR_TI1_RMP_0                     (0x0001)            /*!<Bit 0 */
#define TIM14_OR_TI1_RMP_1                     (0x0002)            /*!<Bit 1 */


#define  USART_CR1_UE                        (0x00000001)            /*!< USART Enable */
#define  USART_CR1_UESM                      (0x00000002)            /*!< USART Enable in STOP Mode */
#define  USART_CR1_RE                        (0x00000004)            /*!< Receiver Enable */
#define  USART_CR1_TE                        (0x00000008)            /*!< Transmitter Enable */
#define  USART_CR1_IDLEIE                    (0x00000010)            /*!< IDLE Interrupt Enable */
#define  USART_CR1_RXNEIE                    (0x00000020)            /*!< RXNE Interrupt Enable */
#define  USART_CR1_TCIE                      (0x00000040)            /*!< Transmission Complete Interrupt Enable */
#define  USART_CR1_TXEIE                     (0x00000080)            /*!< TXE Interrupt Enable */
#define  USART_CR1_PEIE                      (0x00000100)            /*!< PE Interrupt Enable */
#define  USART_CR1_PS                        (0x00000200)            /*!< Parity Selection */
#define  USART_CR1_PCE                       (0x00000400)            /*!< Parity Control Enable */
#define  USART_CR1_WAKE                      (0x00000800)            /*!< Receiver Wakeup method */
#define  USART_CR1_M                         (0x00001000)            /*!< Word length */
#define  USART_CR1_MME                       (0x00002000)            /*!< Mute Mode Enable */
#define  USART_CR1_CMIE                      (0x00004000)            /*!< Character match interrupt enable */
#define  USART_CR1_OVER8                     (0x00008000)            /*!< Oversampling by 8-bit or 16-bit mode */
#define  USART_CR1_DEDT                      (0x001F0000)            /*!< DEDT[4:0] bits (Driver Enable Deassertion Time) */
#define  USART_CR1_DEDT_0                    (0x00010000)            /*!< Bit 0 */
#define  USART_CR1_DEDT_1                    (0x00020000)            /*!< Bit 1 */
#define  USART_CR1_DEDT_2                    (0x00040000)            /*!< Bit 2 */
#define  USART_CR1_DEDT_3                    (0x00080000)            /*!< Bit 3 */
#define  USART_CR1_DEDT_4                    (0x00100000)            /*!< Bit 4 */
#define  USART_CR1_DEAT                      (0x03E00000)            /*!< DEAT[4:0] bits (Driver Enable Assertion Time) */
#define  USART_CR1_DEAT_0                    (0x00200000)            /*!< Bit 0 */
#define  USART_CR1_DEAT_1                    (0x00400000)            /*!< Bit 1 */
#define  USART_CR1_DEAT_2                    (0x00800000)            /*!< Bit 2 */
#define  USART_CR1_DEAT_3                    (0x01000000)            /*!< Bit 3 */
#define  USART_CR1_DEAT_4                    (0x02000000)            /*!< Bit 4 */
#define  USART_CR1_RTOIE                     (0x04000000)            /*!< Receive Time Out interrupt enable */
#define  USART_CR1_EOBIE                     (0x08000000)            /*!< End of Block interrupt enable */

#define  USART_CR2_ADDM7                     (0x00000010)            /*!< 7-bit or 4-bit Address Detection */
#define  USART_CR2_LBDL                      (0x00000020)            /*!< LIN Break Detection Length */
#define  USART_CR2_LBDIE                     (0x00000040)            /*!< LIN Break Detection Interrupt Enable */
#define  USART_CR2_LBCL                      (0x00000100)            /*!< Last Bit Clock pulse */
#define  USART_CR2_CPHA                      (0x00000200)            /*!< Clock Phase */
#define  USART_CR2_CPOL                      (0x00000400)            /*!< Clock Polarity */
#define  USART_CR2_CLKEN                     (0x00000800)            /*!< Clock Enable */
#define  USART_CR2_STOP                      (0x00003000)            /*!< STOP[1:0] bits (STOP bits) */
#define  USART_CR2_STOP_0                    (0x00001000)            /*!< Bit 0 */
#define  USART_CR2_STOP_1                    (0x00002000)            /*!< Bit 1 */
#define  USART_CR2_LINEN                     (0x00004000)            /*!< LIN mode enable */
#define  USART_CR2_SWAP                      (0x00008000)            /*!< SWAP TX/RX pins */
#define  USART_CR2_RXINV                     (0x00010000)            /*!< RX pin active level inversion */
#define  USART_CR2_TXINV                     (0x00020000)            /*!< TX pin active level inversion */
#define  USART_CR2_DATAINV                   (0x00040000)            /*!< Binary data inversion */
#define  USART_CR2_MSBFIRST                  (0x00080000)            /*!< Most Significant Bit First */
#define  USART_CR2_ABREN                     (0x00100000)            /*!< Auto Baud-Rate Enable*/
#define  USART_CR2_ABRMODE                   (0x00600000)            /*!< ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
#define  USART_CR2_ABRMODE_0                 (0x00200000)            /*!< Bit 0 */
#define  USART_CR2_ABRMODE_1                 (0x00400000)            /*!< Bit 1 */
#define  USART_CR2_RTOEN                     (0x00800000)            /*!< Receiver Time-Out enable */
#define  USART_CR2_ADD                       (0xFF000000)            /*!< Address of the USART node */

#define  USART_CR3_EIE                       (0x00000001)            /*!< Error Interrupt Enable */
#define  USART_CR3_IREN                      (0x00000002)            /*!< IrDA mode Enable */
#define  USART_CR3_IRLP                      (0x00000004)            /*!< IrDA Low-Power */
#define  USART_CR3_HDSEL                     (0x00000008)            /*!< Half-Duplex Selection */
#define  USART_CR3_NACK                      (0x00000010)            /*!< SmartCard NACK enable */
#define  USART_CR3_SCEN                      (0x00000020)            /*!< SmartCard mode enable */
#define  USART_CR3_DMAR                      (0x00000040)            /*!< DMA Enable Receiver */
#define  USART_CR3_DMAT                      (0x00000080)            /*!< DMA Enable Transmitter */
#define  USART_CR3_RTSE                      (0x00000100)            /*!< RTS Enable */
#define  USART_CR3_CTSE                      (0x00000200)            /*!< CTS Enable */
#define  USART_CR3_CTSIE                     (0x00000400)            /*!< CTS Interrupt Enable */
#define  USART_CR3_ONEBIT                    (0x00000800)            /*!< One sample bit method enable */
#define  USART_CR3_OVRDIS                    (0x00001000)            /*!< Overrun Disable */
#define  USART_CR3_DDRE                      (0x00002000)            /*!< DMA Disable on Reception Error */
#define  USART_CR3_DEM                       (0x00004000)            /*!< Driver Enable Mode */
#define  USART_CR3_DEP                       (0x00008000)            /*!< Driver Enable Polarity Selection */
#define  USART_CR3_SCARCNT                   (0x000E0000)            /*!< SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
#define  USART_CR3_SCARCNT_0                 (0x00020000)            /*!< Bit 0 */
#define  USART_CR3_SCARCNT_1                 (0x00040000)            /*!< Bit 1 */
#define  USART_CR3_SCARCNT_2                 (0x00080000)            /*!< Bit 2 */
#define  USART_CR3_WUS                       (0x00300000)            /*!< WUS[1:0] bits (Wake UP Interrupt Flag Selection) */
#define  USART_CR3_WUS_0                     (0x00100000)            /*!< Bit 0 */
#define  USART_CR3_WUS_1                     (0x00200000)            /*!< Bit 1 */
#define  USART_CR3_WUFIE                     (0x00400000)            /*!< Wake Up Interrupt Enable */

#define  USART_BRR_DIV_FRACTION              (0x000F)                /*!< Fraction of USARTDIV */
#define  USART_BRR_DIV_MANTISSA              (0xFFF0)                /*!< Mantissa of USARTDIV */

#define  USART_GTPR_PSC                      (0x00FF)                /*!< PSC[7:0] bits (Prescaler value) */
#define  USART_GTPR_GT                       (0xFF00)                /*!< GT[7:0] bits (Guard time value) */


#define  USART_RTOR_RTO                      (0x00FFFFFF)            /*!< Receiver Time Out Value */
#define  USART_RTOR_BLEN                     (0xFF000000)            /*!< Block Length */

#define  USART_RQR_ABRRQ                    (0x0001)                /*!< Auto-Baud Rate Request */
#define  USART_RQR_SBKRQ                    (0x0002)                /*!< Send Break Request */
#define  USART_RQR_MMRQ                     (0x0004)                /*!< Mute Mode Request */
#define  USART_RQR_RXFRQ                    (0x0008)                /*!< Receive Data flush Request */
#define  USART_RQR_TXFRQ                    (0x0010)                /*!< Transmit data flush Request */

#define  USART_ISR_PE                        (0x00000001)            /*!< Parity Error */
#define  USART_ISR_FE                        (0x00000002)            /*!< Framing Error */
#define  USART_ISR_NE                        (0x00000004)            /*!< Noise detected Flag */
#define  USART_ISR_ORE                       (0x00000008)            /*!< OverRun Error */
#define  USART_ISR_IDLE                      (0x00000010)            /*!< IDLE line detected */
#define  USART_ISR_RXNE                      (0x00000020)            /*!< Read Data Register Not Empty */
#define  USART_ISR_TC                        (0x00000040)            /*!< Transmission Complete */
#define  USART_ISR_TXE                       (0x00000080)            /*!< Transmit Data Register Empty */
#define  USART_ISR_LBD                       (0x00000100)            /*!< LIN Break Detection Flag */
#define  USART_ISR_CTSIF                     (0x00000200)            /*!< CTS interrupt flag */
#define  USART_ISR_CTS                       (0x00000400)            /*!< CTS flag */
#define  USART_ISR_RTOF                      (0x00000800)            /*!< Receiver Time Out */
#define  USART_ISR_EOBF                      (0x00001000)            /*!< End Of Block Flag */
#define  USART_ISR_ABRE                      (0x00004000)            /*!< Auto-Baud Rate Error */
#define  USART_ISR_ABRF                      (0x00008000)            /*!< Auto-Baud Rate Flag */
#define  USART_ISR_BUSY                      (0x00010000)            /*!< Busy Flag */
#define  USART_ISR_CMF                       (0x00020000)            /*!< Character Match Flag */
#define  USART_ISR_SBKF                      (0x00040000)            /*!< Send Break Flag */
#define  USART_ISR_RWU                       (0x00080000)            /*!< Receive Wake Up from mute mode Flag */
#define  USART_ISR_WUF                       (0x00100000)            /*!< Wake Up from stop mode Flag */
#define  USART_ISR_TEACK                     (0x00200000)            /*!< Transmit Enable Acknowledge Flag */
#define  USART_ISR_REACK                     (0x00400000)            /*!< Receive Enable Acknowledge Flag */

#define  USART_ICR_PECF                      (0x00000001)            /*!< Parity Error Clear Flag */
#define  USART_ICR_FECF                      (0x00000002)            /*!< Framing Error Clear Flag */
#define  USART_ICR_NCF                      (0x00000004)             /*!< Noise detected Clear Flag */
#define  USART_ICR_ORECF                     (0x00000008)            /*!< OverRun Error Clear Flag */
#define  USART_ICR_IDLECF                    (0x00000010)            /*!< IDLE line detected Clear Flag */
#define  USART_ICR_TCCF                      (0x00000040)            /*!< Transmission Complete Clear Flag */
#define  USART_ICR_LBDCF                     (0x00000100)            /*!< LIN Break Detection Clear Flag */
#define  USART_ICR_CTSCF                     (0x00000200)            /*!< CTS Interrupt Clear Flag */
#define  USART_ICR_RTOCF                     (0x00000800)            /*!< Receiver Time Out Clear Flag */
#define  USART_ICR_EOBCF                     (0x00001000)            /*!< End Of Block Clear Flag */
#define  USART_ICR_CMCF                      (0x00020000)            /*!< Character Match Clear Flag */
#define  USART_ICR_WUCF                      (0x00100000)            /*!< Wake Up from stop mode Clear Flag */

#define  USART_RDR_RDR                       (0x01FF)                /*!< RDR[8:0] bits (Receive Data value) */

#define  USART_TDR_TDR                       (0x01FF)                /*!< TDR[8:0] bits (Transmit Data value) */


#define  WWDG_CR_T                           (0x7F)               /*!< T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define  WWDG_CR_T0                          (0x01)               /*!< Bit 0 */
#define  WWDG_CR_T1                          (0x02)               /*!< Bit 1 */
#define  WWDG_CR_T2                          (0x04)               /*!< Bit 2 */
#define  WWDG_CR_T3                          (0x08)               /*!< Bit 3 */
#define  WWDG_CR_T4                          (0x10)               /*!< Bit 4 */
#define  WWDG_CR_T5                          (0x20)               /*!< Bit 5 */
#define  WWDG_CR_T6                          (0x40)               /*!< Bit 6 */

#define  WWDG_CR_WDGA                        (0x80)               /*!< Activation bit */

#define  WWDG_CFR_W                          (0x007F)            /*!< W[6:0] bits (7-bit window value) */
#define  WWDG_CFR_W0                         (0x0001)            /*!< Bit 0 */
#define  WWDG_CFR_W1                         (0x0002)            /*!< Bit 1 */
#define  WWDG_CFR_W2                         (0x0004)            /*!< Bit 2 */
#define  WWDG_CFR_W3                         (0x0008)            /*!< Bit 3 */
#define  WWDG_CFR_W4                         (0x0010)            /*!< Bit 4 */
#define  WWDG_CFR_W5                         (0x0020)            /*!< Bit 5 */
#define  WWDG_CFR_W6                         (0x0040)            /*!< Bit 6 */

#define  WWDG_CFR_WDGTB                      (0x0180)            /*!< WDGTB[1:0] bits (Timer Base) */
#define  WWDG_CFR_WDGTB0                     (0x0080)            /*!< Bit 0 */
#define  WWDG_CFR_WDGTB1                     (0x0100)            /*!< Bit 1 */

#define  WWDG_CFR_EWI                        (0x0200)            /*!< Early Wakeup Interrupt */

#define  WWDG_SR_EWIF                        (0x01)               /*!< Early Wakeup Interrupt Flag */

/**
  * @}
  */

/**
  * @}
  */

#ifdef USE_STDPERIPH_DRIVER
#endif

/** @addtogroup Exported_macro
  * @{
  */
/**
  * @}
  */

#ifdef __cplusplus
#endif

#endif /* __STM32F0XX_H */

/**
  * @}
  */

/**
  * @}
  */

