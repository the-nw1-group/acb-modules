@ File automatically generated from D:\Model Railways\Electronics\Information\ST-DemoCode\STM32F30x_DSP_StdPeriph_Lib\Libraries\CMSIS\Device\ST\STM32F30x\Include\stm32f30x.h on 30/08/2015 18:09:23
@ by ConvertHeaderFiles (c) The NW1 Group

/**
  ******************************************************************************
  * @file    stm32f30x.h
  * @author  MCD Application Team
  * @version V1.2.2
  * @date    27-February-2015
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer Header File. 
  *          This file contains all the peripheral registers definitions, bits 
  *          definitions and memory mapping for STM32F30x devices.
  *            
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *           - Configuration section that allows to select:
  *              - The device used in the target application
  *              - To use or not the peripheral�s drivers in application code(i.e. 
  *                code will be based on direct access to peripheral�s registers 
  *                rather than drivers API), this option is controlled by 
  *                "#define USE_STDPERIPH_DRIVER"
  *              - To change few application-specific parameters such as the HSE 
  *                crystal frequency
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral registers declarations and bits definition
  *           - Macros to access peripheral registers hardware
  *  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
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

/** @addtogroup stm32f30x
  * @{
  */

#ifndef __STM32F30x_H
#define __STM32F30x_H

#ifdef __cplusplus
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/* Uncomment the line below according to the target STM32 device used in your
   application 
  */

#if defined(STM32F30X) 
  #define STM32F303xC
#endif /* STM32F30X */

#if !defined (STM32F303xC) && !defined (STM32F334x8) && !defined (STM32F302x8) && !defined (STM32F303xE)
#endif /* STM32F303xC  || STM32F334x8 || STM32F302x8 || STM32F303xE */


/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */

#if !defined (STM32F303xC) && !defined (STM32F334x8) && !defined (STM32F302x8) && !defined (STM32F303xE)
#endif

#if !defined  (USE_STDPERIPH_DRIVER)
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
 #define HSE_VALUE            (8000000) /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

/**
 * @brief In the following line adjust the External High Speed oscillator (HSE) Startup 
   Timeout value 
   */
#if !defined  (HSE_STARTUP_TIMEOUT) 
 #define HSE_STARTUP_TIMEOUT  (0x5000)   /*!< Time out for HSE start up */
#endif /* HSE_STARTUP_TIMEOUT */

/**
 * @brief In the following line adjust the Internal High Speed oscillator (HSI) Startup 
   Timeout value 
   */
#if !defined  (HSI_STARTUP_TIMEOUT) 
 #define HSI_STARTUP_TIMEOUT   (0x5000) /*!< Time out for HSI start up */
#endif /* HSI_STARTUP_TIMEOUT */  

#if !defined  (HSI_VALUE) 
 #define HSI_VALUE  (8000000)
#endif /* HSI_VALUE */                      /*!< Value of the Internal High Speed oscillator in Hz.
#if !defined  (LSI_VALUE) 
 #define LSI_VALUE  (40000)    
#endif /* LSI_VALUE */                      /*!< Value of the Internal Low Speed oscillator in Hz
#if !defined  (LSE_VALUE)
 #define LSE_VALUE  (32768)    /*!< Value of the External Low Speed oscillator in Hz */
#endif /* LSE_VALUE */     


/**
 * @brief STM32F30x Standard Peripherals Library version number V1.2.2
   */
#define __STM32F30X_STDPERIPH_VERSION_MAIN   (0x01) /*!< [31:24] main version */                                  
#define __STM32F30X_STDPERIPH_VERSION_SUB1   (0x02) /*!< [23:16] sub1 version */
#define __STM32F30X_STDPERIPH_VERSION_SUB2   (0x02) /*!< [15:8]  sub2 version */
#define __STM32F30X_STDPERIPH_VERSION_RC     (0x00) /*!< [7:0]  release candidate */ 
#define __STM32F30X_STDPERIPH_VERSION       ( (__STM32F30X_STDPERIPH_VERSION_MAIN << 24)\
                                             |(__STM32F30X_STDPERIPH_VERSION_SUB1 << 16)\
                                             |(__STM32F30X_STDPERIPH_VERSION_SUB2 << 8)\
                                             |(__STM32F30X_STDPERIPH_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
 * @brief Configuration of the Cortex-M4 Processor and Core Peripherals 
 */
#define __CM4_REV                 0x0001  /*!< Core revision r0p1                            */
#define __MPU_PRESENT             1         /*!< STM32F30X provide an MPU */
#define __NVIC_PRIO_BITS          4         /*!< STM32F30X uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1         /*!< STM32F30X provide an FPU */


/**
 * @brief STM32F30X Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */
  NonMaskableInt_IRQn         = -14    /*!< 2 Non Maskable Interrupt                                          */
  MemoryManagement_IRQn       = -12    /*!< 4 Cortex-M4 Memory Management Interrupt                           */
  BusFault_IRQn               = -11    /*!< 5 Cortex-M4 Bus Fault Interrupt                                   */
  UsageFault_IRQn             = -10    /*!< 6 Cortex-M4 Usage Fault Interrupt                                 */
  SVCall_IRQn                 = -5     /*!< 11 Cortex-M4 SV Call Interrupt                                    */
  DebugMonitor_IRQn           = -4     /*!< 12 Cortex-M4 Debug Monitor Interrupt                              */
  PendSV_IRQn                 = -2     /*!< 14 Cortex-M4 Pend SV Interrupt                                    */
  SysTick_IRQn                = -1     /*!< 15 Cortex-M4 System Tick Interrupt                                */
#ifdef STM32F303xC 
  WWDG_IRQn                   = 0      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMPER_STAMP_IRQn           = 2      /*!< Tamper and TimeStamp interrupts                                   */
  RTC_WKUP_IRQn               = 3      /*!< RTC Wakeup interrupt through the EXTI lines 17 19 & 20           */
  FLASH_IRQn                  = 4      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_TS_IRQn               = 8      /*!< EXTI Line2 Interrupt and Touch Sense Interrupt                    */
  EXTI3_IRQn                  = 9      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Channel1_IRQn          = 11     /*!< DMA1 Channel 1 Interrupt                                          */
  DMA1_Channel2_IRQn          = 12     /*!< DMA1 Channel 2 Interrupt                                          */
  DMA1_Channel3_IRQn          = 13     /*!< DMA1 Channel 3 Interrupt                                          */
  DMA1_Channel4_IRQn          = 14     /*!< DMA1 Channel 4 Interrupt                                          */
  DMA1_Channel5_IRQn          = 15     /*!< DMA1 Channel 5 Interrupt                                          */
  DMA1_Channel6_IRQn          = 16     /*!< DMA1 Channel 6 Interrupt                                          */
  DMA1_Channel7_IRQn          = 17     /*!< DMA1 Channel 7 Interrupt                                          */
  ADC1_2_IRQn                 = 18     /*!< ADC1 & ADC2 Interrupts                                            */
  USB_HP_CAN1_TX_IRQn         = 19     /*!< USB Device High Priority or CAN1 TX Interrupts                    */
  USB_LP_CAN1_RX0_IRQn        = 20     /*!< USB Device Low Priority or CAN1 RX0 Interrupts                    */  
  CAN1_RX1_IRQn               = 21     /*!< CAN1 RX1 Interrupt                                                */
  CAN1_SCE_IRQn               = 22     /*!< CAN1 SCE Interrupt                                                */
  EXTI9_5_IRQn                = 23     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM15_IRQn         = 24     /*!< TIM1 Break and TIM15 Interrupts                                   */
  TIM1_UP_TIM16_IRQn          = 25     /*!< TIM1 Update and TIM16 Interrupts                                  */
  TIM1_TRG_COM_TIM17_IRQn     = 26     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt                  */
  TIM1_CC_IRQn                = 27     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29     /*!< TIM3 global Interrupt                                             */
  TIM4_IRQn                   = 30     /*!< TIM4 global Interrupt                                             */
  I2C1_EV_IRQn                = 31     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32     /*!< I2C1 Error Interrupt                                              */ 
  I2C2_EV_IRQn                = 33     /*!< I2C2 Event Interrupt                                              */  
  I2C2_ER_IRQn                = 34     /*!< I2C2 Error Interrupt                                              */
  SPI1_IRQn                   = 35     /*!< SPI1 global Interrupt                                             */
  SPI2_IRQn                   = 36     /*!< SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37     /*!< USART1 global Interrupt                                           */
  USART2_IRQn                 = 38     /*!< USART2 global Interrupt                                           */
  USART3_IRQn                 = 39     /*!< USART3 global Interrupt                                           */  
  EXTI15_10_IRQn              = 40     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  USBWakeUp_IRQn              = 42     /*!< USB Wakeup Interrupt                                              */
  TIM8_BRK_IRQn               = 43     /*!< TIM8 Break Interrupt                                              */
  TIM8_UP_IRQn                = 44     /*!< TIM8 Update Interrupt                                             */
  TIM8_TRG_COM_IRQn           = 45     /*!< TIM8 Trigger and Commutation Interrupt                            */
  TIM8_CC_IRQn                = 46     /*!< TIM8 Capture Compare Interrupt                                    */
  ADC3_IRQn                   = 47     /*!< ADC3 global Interrupt                                             */
  SPI3_IRQn                   = 51     /*!< SPI3 global Interrupt                                             */
  UART4_IRQn                  = 52     /*!< UART4 global Interrupt                                            */
  UART5_IRQn                  = 53     /*!< UART5 global Interrupt                                            */
  TIM6_DAC_IRQn               = 54     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
  TIM7_IRQn                   = 55     /*!< TIM7 global Interrupt                                             */
  DMA2_Channel1_IRQn          = 56     /*!< DMA2 Channel 1 global Interrupt                                   */
  DMA2_Channel2_IRQn          = 57     /*!< DMA2 Channel 2 global Interrupt                                   */
  DMA2_Channel3_IRQn          = 58     /*!< DMA2 Channel 3 global Interrupt                                   */
  DMA2_Channel4_IRQn          = 59     /*!< DMA2 Channel 4 global Interrupt                                   */
  DMA2_Channel5_IRQn          = 60     /*!< DMA2 Channel 5 global Interrupt                                   */
  ADC4_IRQn                   = 61     /*!< ADC4  global Interrupt                                            */
  COMP1_2_3_IRQn              = 64     /*!< COMP1 COMP2 and COMP3 global Interrupt                           */
  COMP4_5_6_IRQn              = 65     /*!< COMP5 COMP6 and COMP4 global Interrupt                           */
  COMP7_IRQn                  = 66     /*!< COMP7 global Interrupt                                            */
  USB_HP_IRQn                 = 74     /*!< USB High Priority global Interrupt remap                          */
  USB_LP_IRQn                 = 75     /*!< USB Low Priority global Interrupt  remap                          */
  USBWakeUp_RMP_IRQn          = 76     /*!< USB Wakeup Interrupt remap                                        */
  FPU_IRQn                    = 81      /*!< Floating point Interrupt                                          */
#endif /* STM32F303xC */
#ifdef STM32F334x8 
  WWDG_IRQn                   = 0      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMPER_STAMP_IRQn           = 2      /*!< Tamper and TimeStamp interrupts                                   */
  RTC_WKUP_IRQn               = 3      /*!< RTC Wakeup interrupt through the EXTI lines 17 19 & 20           */
  FLASH_IRQn                  = 4      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_TS_IRQn               = 8      /*!< EXTI Line2 Interrupt and Touch Sense Interrupt                    */
  EXTI3_IRQn                  = 9      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Channel1_IRQn          = 11     /*!< DMA1 Channel 1 Interrupt                                          */
  DMA1_Channel2_IRQn          = 12     /*!< DMA1 Channel 2 Interrupt                                          */
  DMA1_Channel3_IRQn          = 13     /*!< DMA1 Channel 3 Interrupt                                          */
  DMA1_Channel4_IRQn          = 14     /*!< DMA1 Channel 4 Interrupt                                          */
  DMA1_Channel5_IRQn          = 15     /*!< DMA1 Channel 5 Interrupt                                          */
  DMA1_Channel6_IRQn          = 16     /*!< DMA1 Channel 6 Interrupt                                          */
  DMA1_Channel7_IRQn          = 17     /*!< DMA1 Channel 7 Interrupt                                          */
  ADC1_2_IRQn                 = 18     /*!< ADC1 & ADC2 Interrupts                                            */
  CAN1_TX_IRQn                = 19     /*!< CAN1 TX Interrupts                                                */
  CAN1_RX0_IRQn               = 20     /*!< CAN1 RX0 Interrupts                                               */
  CAN1_RX1_IRQn               = 21     /*!< CAN1 RX1 Interrupt                                                */
  CAN1_SCE_IRQn               = 22     /*!< CAN1 SCE Interrupt                                                */
  EXTI9_5_IRQn                = 23     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM15_IRQn         = 24     /*!< TIM1 Break and TIM15 Interrupts                                   */
  TIM1_UP_TIM16_IRQn          = 25     /*!< TIM1 Update and TIM16 Interrupts                                  */
  TIM1_TRG_COM_TIM17_IRQn     = 26     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt                  */
  TIM1_CC_IRQn                = 27     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29     /*!< TIM3 global Interrupt                                             */
  I2C1_EV_IRQn                = 31     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32     /*!< I2C1 Error Interrupt                                              */ 
  SPI1_IRQn                   = 35     /*!< SPI1 global Interrupt                                             */
  USART1_IRQn                 = 37     /*!< USART1 global Interrupt                                           */
  USART2_IRQn                 = 38     /*!< USART2 global Interrupt                                           */
  USART3_IRQn                 = 39     /*!< USART3 global Interrupt                                           */  
  EXTI15_10_IRQn              = 40     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  TIM6_DAC1_IRQn              = 54     /*!< TIM6 global and DAC1 underrun error  interrupts                   */
  TIM7_DAC2_IRQn              = 55     /*!< TIM7 global and DAC2 underrun error Interrupt                      */
  COMP2_IRQn                  = 64     /*!< COMP2 global Interrupt                                            */
  COMP4_6_IRQn                = 65     /*!< COMP6 and COMP4 global Interrupt                                  */  
  HRTIM1_Master_IRQn          = 67     /*!< HRTIM Master Timer global Interrupts                              */
  HRTIM1_TIMA_IRQn            = 68     /*!< HRTIM Timer A global Interrupt                                    */
  HRTIM1_TIMB_IRQn            = 69     /*!< HRTIM Timer B global Interrupt                                    */
  HRTIM1_TIMC_IRQn            = 70     /*!< HRTIM Timer C global Interrupt                                    */
  HRTIM1_TIMD_IRQn            = 71     /*!< HRTIM Timer D global Interrupt                                    */
  HRTIM1_TIME_IRQn            = 72     /*!< HRTIM Timer E global Interrupt                                    */
  HRTIM1_FLT_IRQn             = 73     /*!< HRTIM Fault global Interrupt                                      */
  FPU_IRQn                    = 81      /*!< Floating point Interrupt                                          */
#endif /* STM32F334x8 */
#ifdef STM32F302x8 
  WWDG_IRQn                   = 0      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMPER_STAMP_IRQn           = 2      /*!< Tamper and TimeStamp interrupts                                   */
  RTC_WKUP_IRQn               = 3      /*!< RTC Wakeup interrupt through the EXTI lines 20           */
  FLASH_IRQn                  = 4      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_TS_IRQn               = 8      /*!< EXTI Line2 Interrupt and Touch Sense Interrupt                    */
  EXTI3_IRQn                  = 9      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Channel1_IRQn          = 11     /*!< DMA1 Channel 1 Interrupt                                          */
  DMA1_Channel2_IRQn          = 12     /*!< DMA1 Channel 2 Interrupt                                          */
  DMA1_Channel3_IRQn          = 13     /*!< DMA1 Channel 3 Interrupt                                          */
  DMA1_Channel4_IRQn          = 14     /*!< DMA1 Channel 4 Interrupt                                          */
  DMA1_Channel5_IRQn          = 15     /*!< DMA1 Channel 5 Interrupt                                          */
  DMA1_Channel6_IRQn          = 16     /*!< DMA1 Channel 6 Interrupt                                          */
  DMA1_Channel7_IRQn          = 17     /*!< DMA1 Channel 7 Interrupt                                          */
  ADC1_IRQn                   = 18     /*!< ADC1 Interrupts                                            */
  USB_HP_CAN1_TX_IRQn         = 19     /*!< USB Device High Priority or CAN1 TX Interrupts                    */
  USB_LP_CAN1_RX0_IRQn        = 20     /*!< USB Device Low Priority or CAN1 RX0 Interrupts                    */  
  CAN1_RX1_IRQn               = 21     /*!< CAN1 RX1 Interrupt                                                */
  CAN1_SCE_IRQn               = 22     /*!< CAN1 SCE Interrupt                                                */
  EXTI9_5_IRQn                = 23     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM15_IRQn         = 24     /*!< TIM1 Break and TIM15 Interrupts                                   */
  TIM1_UP_TIM16_IRQn          = 25     /*!< TIM1 Update and TIM16 Interrupts                                  */
  TIM1_TRG_COM_TIM17_IRQn     = 26     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt                  */
  TIM1_CC_IRQn                = 27     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28     /*!< TIM2 global Interrupt                                             */
  I2C1_EV_IRQn                = 31     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32     /*!< I2C1 Error Interrupt                                              */ 
  I2C2_EV_IRQn                = 33     /*!< I2C2 Event Interrupt                                              */  
  I2C2_ER_IRQn                = 34     /*!< I2C2 Error Interrupt                                              */
  SPI2_IRQn                   = 36     /*!< SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37     /*!< USART1 global Interrupt                                           */
  USART2_IRQn                 = 38     /*!< USART2 global Interrupt                                           */
  USART3_IRQn                 = 39     /*!< USART3 global Interrupt                                           */  
  EXTI15_10_IRQn              = 40     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  USBWakeUp_IRQn              = 42     /*!< USB Wakeup Interrupt                                              */
  SPI3_IRQn                   = 51     /*!< SPI3 global Interrupt                                             */
  TIM6_DAC_IRQn               = 54     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
  COMP2_IRQn                  = 64     /*!< COMP2 global Interrupt                           */
  COMP4_6_IRQn                = 65     /*!< COMP5 COMP6 and COMP4 global Interrupt                           */
  COMP7_IRQn                  = 66     /*!< COMP7 global Interrupt                                            */
  I2C3_EV_IRQn                = 72     /*!< I2C3 Event Interrupt                                              */
  I2C3_ER_IRQn                = 73     /*!< I2C3 Error Interrupt                                              */ 
  USB_HP_IRQn                 = 74     /*!< USB High Priority global Interrupt remap                          */
  USB_LP_IRQn                 = 75     /*!< USB Low Priority global Interrupt  remap                          */
  USBWakeUp_RMP_IRQn          = 76     /*!< USB Wakeup Interrupt remap                                        */
  FPU_IRQn                    = 81      /*!< Floating point Interrupt                                          */
#endif /* STM32F302x8 */
#ifdef STM32F303xE 
  WWDG_IRQn                   = 0      /*!< Window WatchDog Interrupt                                         */
  PVD_IRQn                    = 1      /*!< PVD through EXTI Line detection Interrupt                         */
  TAMPER_STAMP_IRQn           = 2      /*!< Tamper and TimeStamp interrupts                                   */
  RTC_WKUP_IRQn               = 3      /*!< RTC Wakeup interrupt through the EXTI lines 17 19 & 20           */
  FLASH_IRQn                  = 4      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 5      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 6      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 7      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_TS_IRQn               = 8      /*!< EXTI Line2 Interrupt and Touch Sense Interrupt                    */
  EXTI3_IRQn                  = 9      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 10     /*!< EXTI Line4 Interrupt                                              */
  DMA1_Channel1_IRQn          = 11     /*!< DMA1 Channel 1 Interrupt                                          */
  DMA1_Channel2_IRQn          = 12     /*!< DMA1 Channel 2 Interrupt                                          */
  DMA1_Channel3_IRQn          = 13     /*!< DMA1 Channel 3 Interrupt                                          */
  DMA1_Channel4_IRQn          = 14     /*!< DMA1 Channel 4 Interrupt                                          */
  DMA1_Channel5_IRQn          = 15     /*!< DMA1 Channel 5 Interrupt                                          */
  DMA1_Channel6_IRQn          = 16     /*!< DMA1 Channel 6 Interrupt                                          */
  DMA1_Channel7_IRQn          = 17     /*!< DMA1 Channel 7 Interrupt                                          */
  ADC1_2_IRQn                 = 18     /*!< ADC1 & ADC2 Interrupts                                            */
  USB_HP_CAN1_TX_IRQn         = 19     /*!< USB Device High Priority or CAN1 TX Interrupts                    */
  USB_LP_CAN1_RX0_IRQn        = 20     /*!< USB Device Low Priority or CAN1 RX0 Interrupts                    */  
  CAN1_RX1_IRQn               = 21     /*!< CAN1 RX1 Interrupt                                                */
  CAN1_SCE_IRQn               = 22     /*!< CAN1 SCE Interrupt                                                */
  EXTI9_5_IRQn                = 23     /*!< External Line[9:5] Interrupts                                     */
  TIM1_BRK_TIM15_IRQn         = 24     /*!< TIM1 Break and TIM15 Interrupts                                   */
  TIM1_UP_TIM16_IRQn          = 25     /*!< TIM1 Update and TIM16 Interrupts                                  */
  TIM1_TRG_COM_TIM17_IRQn     = 26     /*!< TIM1 Trigger and Commutation and TIM17 Interrupt                  */
  TIM1_CC_IRQn                = 27     /*!< TIM1 Capture Compare Interrupt                                    */
  TIM2_IRQn                   = 28     /*!< TIM2 global Interrupt                                             */
  TIM3_IRQn                   = 29     /*!< TIM3 global Interrupt                                             */
  TIM4_IRQn                   = 30     /*!< TIM4 global Interrupt                                             */
  I2C1_EV_IRQn                = 31     /*!< I2C1 Event Interrupt                                              */
  I2C1_ER_IRQn                = 32     /*!< I2C1 Error Interrupt                                              */ 
  I2C2_EV_IRQn                = 33     /*!< I2C2 Event Interrupt                                              */  
  I2C2_ER_IRQn                = 34     /*!< I2C2 Error Interrupt                                              */
  SPI1_IRQn                   = 35     /*!< SPI1 global Interrupt                                             */
  SPI2_IRQn                   = 36     /*!< SPI2 global Interrupt                                             */
  USART1_IRQn                 = 37     /*!< USART1 global Interrupt                                           */
  USART2_IRQn                 = 38     /*!< USART2 global Interrupt                                           */
  USART3_IRQn                 = 39     /*!< USART3 global Interrupt                                           */  
  EXTI15_10_IRQn              = 40     /*!< External Line[15:10] Interrupts                                   */
  RTC_Alarm_IRQn              = 41     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  USBWakeUp_IRQn              = 42     /*!< USB Wakeup Interrupt                                              */
  TIM8_BRK_IRQn               = 43     /*!< TIM8 Break Interrupt                                              */
  TIM8_UP_IRQn                = 44     /*!< TIM8 Update Interrupt                                             */
  TIM8_TRG_COM_IRQn           = 45     /*!< TIM8 Trigger and Commutation Interrupt                            */
  TIM8_CC_IRQn                = 46     /*!< TIM8 Capture Compare Interrupt                                    */
  ADC3_IRQn                   = 47     /*!< ADC3 global Interrupt                                             */
  FMC_IRQn                    = 48     /*!< FMC global Interrupt                                              */
  SPI3_IRQn                   = 51     /*!< SPI3 global Interrupt                                             */
  UART4_IRQn                  = 52     /*!< UART4 global Interrupt                                            */
  UART5_IRQn                  = 53     /*!< UART5 global Interrupt                                            */
  TIM6_DAC_IRQn               = 54     /*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
  TIM7_IRQn                   = 55     /*!< TIM7 global Interrupt                                             */
  DMA2_Channel1_IRQn          = 56     /*!< DMA2 Channel 1 global Interrupt                                   */
  DMA2_Channel2_IRQn          = 57     /*!< DMA2 Channel 2 global Interrupt                                   */
  DMA2_Channel3_IRQn          = 58     /*!< DMA2 Channel 3 global Interrupt                                   */
  DMA2_Channel4_IRQn          = 59     /*!< DMA2 Channel 4 global Interrupt                                   */
  DMA2_Channel5_IRQn          = 60     /*!< DMA2 Channel 5 global Interrupt                                   */
  ADC4_IRQn                   = 61     /*!< ADC4  global Interrupt                                            */
  COMP1_2_3_IRQn              = 64     /*!< COMP1 COMP2 and COMP3 global Interrupt                           */
  COMP4_5_6_IRQn              = 65     /*!< COMP5 COMP6 and COMP4 global Interrupt                           */
  COMP7_IRQn                  = 66     /*!< COMP7 global Interrupt                                            */
  I2C3_EV_IRQn                = 72     /*!< I2C3 event interrupt                                              */
  I2C3_ER_IRQn                = 73     /*!< I2C3 error interrupt                                              */
  USB_HP_IRQn                 = 74     /*!< USB High Priority global Interrupt remap                          */
  USB_LP_IRQn                 = 75     /*!< USB Low Priority global Interrupt  remap                          */
  USBWakeUp_RMP_IRQn          = 76     /*!< USB Wakeup Interrupt remap                                        */
  TIM20_BRK_IRQn              = 77     /*!< TIM20 Break Interrupt                                             */
  TIM20_UP_IRQn               = 78     /*!< TIM20 Update Interrupt                                            */
  TIM20_TRG_COM_IRQn          = 79     /*!< TIM20 Trigger and Commutation Interrupt                           */
  TIM20_CC_IRQn               = 80     /*!< TIM20 Capture Compare Interrupt                                   */
  FPU_IRQn                    = 81     /*!< Floating point Interrupt                                          */
  SPI4_IRQn                   = 84      /*!< SPI4 global Interrupt                                             */ 
#endif /* STM32F303xE */

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

/**
  * @}
  */

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief Analog to Digital Converter  
  */


#define ADC_ISR_OFFSET          0x0000    /*!< ADC Interrupt and Status Register,                 Address offset: 0x00 */
#define ADC_IER_OFFSET          0x0004    /*!< ADC Interrupt Enable Register,                     Address offset: 0x04 */
#define ADC_CR_OFFSET           0x0008    /*!< ADC control register,                              Address offset: 0x08 */
#define ADC_CFGR_OFFSET         0x000C    /*!< ADC Configuration register,                        Address offset: 0x0C */
#define ADC_RESERVED0_OFFSET    0x0010    /*!< Reserved, 0x010                                                         */
#define ADC_SMPR1_OFFSET        0x0014    /*!< ADC sample time register 1,                        Address offset: 0x14 */
#define ADC_SMPR2_OFFSET        0x0018    /*!< ADC sample time register 2,                        Address offset: 0x18 */
#define ADC_RESERVED1_OFFSET    0x001C    /*!< Reserved, 0x01C                                                         */
#define ADC_TR1_OFFSET          0x0020    /*!< ADC watchdog threshold register 1,                 Address offset: 0x20 */
#define ADC_TR2_OFFSET          0x0024    /*!< ADC watchdog threshold register 2,                 Address offset: 0x24 */
#define ADC_TR3_OFFSET          0x0028    /*!< ADC watchdog threshold register 3,                 Address offset: 0x28 */
#define ADC_RESERVED2_OFFSET    0x002C    /*!< Reserved, 0x02C                                                         */
#define ADC_SQR1_OFFSET         0x0030    /*!< ADC regular sequence register 1,                   Address offset: 0x30 */
#define ADC_SQR2_OFFSET         0x0034    /*!< ADC regular sequence register 2,                   Address offset: 0x34 */
#define ADC_SQR3_OFFSET         0x0038    /*!< ADC regular sequence register 3,                   Address offset: 0x38 */
#define ADC_SQR4_OFFSET         0x003C    /*!< ADC regular sequence register 4,                   Address offset: 0x3C */
#define ADC_DR_OFFSET           0x0040    /*!< ADC regular data register,                         Address offset: 0x40 */
#define ADC_RESERVED3_OFFSET    0x0044    /*!< Reserved, 0x044                                                         */
#define ADC_RESERVED4_OFFSET    0x0048    /*!< Reserved, 0x048                                                         */
#define ADC_JSQR_OFFSET         0x004C    /*!< ADC injected sequence register,                    Address offset: 0x4C */
#define ADC_RESERVED5_OFFSET    0x0050    /*!< Reserved, 0x050 - 0x05C                                                 */
#define ADC_OFR1_OFFSET         0x0060    /*!< ADC offset register 1,                             Address offset: 0x60 */
#define ADC_OFR2_OFFSET         0x0064    /*!< ADC offset register 2,                             Address offset: 0x64 */
#define ADC_OFR3_OFFSET         0x0068    /*!< ADC offset register 3,                             Address offset: 0x68 */
#define ADC_OFR4_OFFSET         0x006C    /*!< ADC offset register 4,                             Address offset: 0x6C */
#define ADC_RESERVED6_OFFSET    0x0070    /*!< Reserved, 0x070 - 0x07C                                                 */
#define ADC_JDR1_OFFSET         0x0080    /*!< ADC injected data register 1,                      Address offset: 0x80 */
#define ADC_JDR2_OFFSET         0x0084    /*!< ADC injected data register 2,                      Address offset: 0x84 */
#define ADC_JDR3_OFFSET         0x0088    /*!< ADC injected data register 3,                      Address offset: 0x88 */
#define ADC_JDR4_OFFSET         0x008C    /*!< ADC injected data register 4,                      Address offset: 0x8C */
#define ADC_RESERVED7_OFFSET    0x0090    /*!< Reserved, 0x090 - 0x09C                                                 */
#define ADC_AWD2CR_OFFSET       0x00A0    /*!< ADC  Analog Watchdog 2 Configuration Register,     Address offset: 0xA0 */
#define ADC_AWD3CR_OFFSET       0x00A4    /*!< ADC  Analog Watchdog 3 Configuration Register,     Address offset: 0xA4 */
#define ADC_RESERVED8_OFFSET    0x00A8    /*!< Reserved, 0x0A8                                                         */
#define ADC_RESERVED9_OFFSET    0x00AC    /*!< Reserved, 0x0AC                                                         */
#define ADC_DIFSEL_OFFSET       0x00B0    /*!< ADC  Differential Mode Selection Register,         Address offset: 0xB0 */
#define ADC_CALFACT_OFFSET      0x00B4    /*!< ADC  Calibration Factors,                          Address offset: 0xB4 */

  __IO uint32_t CDR;            /*!< ADC common regular data register for dual
                                     modes,                                       Address offset: ADC1/3 base address + 0x30A */
#define ADC_Common_CSR_OFFSET         0x0000    /*!< ADC Common status register,                  Address offset: ADC1/3 base address + 0x300 */
#define ADC_Common_RESERVED_OFFSET    0x0004    /*!< Reserved, ADC1/3 base address + 0x304                                                    */
#define ADC_Common_CCR_OFFSET         0x0008    /*!< ADC common control register,                 Address offset: ADC1/3 base address + 0x308 */
#define ADC_Common_CDR_OFFSET         0x000C    /*!< ADC common regular data register for dual


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
  * @brief Analog Comparators 
  */

#define COMP_CSR_OFFSET    0x0000    /*!< Comparator control Status register, Address offset: 0x00 */

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

#define DBGMCU_IDCODE_OFFSET    0x0000    /*!< MCU device ID code,               Address offset: 0x00 */
#define DBGMCU_CR_OFFSET        0x0004    /*!< Debug MCU configuration register, Address offset: 0x04 */
#define DBGMCU_APB1FZ_OFFSET    0x0008    /*!< Debug MCU APB1 freeze register,   Address offset: 0x08 */
#define DBGMCU_APB2FZ_OFFSET    0x000C    /*!< Debug MCU APB2 freeze register,   Address offset: 0x0C */

/** 
  * @brief DMA Controller
  */

#define DMA_Channel_CCR_OFFSET      0x0000    /*!< DMA channel x configuration register                                           */
#define DMA_Channel_CNDTR_OFFSET    0x0004    /*!< DMA channel x number of data register                                          */
#define DMA_Channel_CPAR_OFFSET     0x0008    /*!< DMA channel x peripheral address register                                      */
#define DMA_Channel_CMAR_OFFSET     0x000C    /*!< DMA channel x memory address register                                          */

#define DMA_ISR_OFFSET     0x0000    /*!< DMA interrupt status register,      Address offset: 0x00 */
#define DMA_IFCR_OFFSET    0x0004    /*!< DMA interrupt clear flag register,  Address offset: 0x04 */

/** 
  * @brief External Interrupt/Event Controller
  */

#define EXTI_IMR_OFFSET          0x0000    /*!< EXTI Interrupt mask register,                Address offset: 0x00 */
#define EXTI_EMR_OFFSET          0x0004    /*!< EXTI Event mask register,                    Address offset: 0x04 */
#define EXTI_RTSR_OFFSET         0x0008    /*!< EXTI Rising trigger selection register,      Address offset: 0x08 */
#define EXTI_FTSR_OFFSET         0x000C    /*!< EXTI Falling trigger selection register,     Address offset: 0x0C */
#define EXTI_SWIER_OFFSET        0x0010    /*!< EXTI Software interrupt event register,      Address offset: 0x10 */
#define EXTI_PR_OFFSET           0x0014    /*!< EXTI Pending register,                       Address offset: 0x14 */
#define EXTI_RESERVED1_OFFSET    0x0018    /*!< Reserved, 0x18                                                    */
#define EXTI_RESERVED2_OFFSET    0x001C    /*!< Reserved, 0x1C                                                    */
#define EXTI_IMR2_OFFSET         0x0020    /*!< EXTI Interrupt mask register,                Address offset: 0x20 */
#define EXTI_EMR2_OFFSET         0x0024    /*!< EXTI Event mask register,                    Address offset: 0x24 */
#define EXTI_RTSR2_OFFSET        0x0028    /*!< EXTI Rising trigger selection register,      Address offset: 0x28 */
#define EXTI_FTSR2_OFFSET        0x002C    /*!< EXTI Falling trigger selection register,     Address offset: 0x2C */
#define EXTI_SWIER2_OFFSET       0x0030    /*!< EXTI Software interrupt event register,      Address offset: 0x30 */
#define EXTI_PR2_OFFSET          0x0034    /*!< EXTI Pending register,                       Address offset: 0x34 */

/** 
  * @brief FLASH Registers
  */


#define FLASH_ACR_OFFSET         0x0000    /*!< FLASH access control register,              Address offset: 0x00 */
#define FLASH_KEYR_OFFSET        0x0004    /*!< FLASH key register,                         Address offset: 0x04 */
#define FLASH_OPTKEYR_OFFSET     0x0008    /*!< FLASH option key register,                  Address offset: 0x08 */
#define FLASH_SR_OFFSET          0x000C    /*!< FLASH status register,                      Address offset: 0x0C */
#define FLASH_CR_OFFSET          0x0010    /*!< FLASH control register,                     Address offset: 0x10 */
#define FLASH_AR_OFFSET          0x0014    /*!< FLASH address register,                     Address offset: 0x14 */
#define FLASH_RESERVED_OFFSET    0x0018    /*!< Reserved, 0x18                                                   */
#define FLASH_OBR_OFFSET         0x001C    /*!< FLASH Option byte register,                 Address offset: 0x1C */
#define FLASH_WRPR_OFFSET        0x0020    /*!< FLASH Write register,                       Address offset: 0x20 */

/** 
  * @brief Flexible Memory Controller
  */

#define FMC_Bank1_BTCR_OFFSET    0x0000    /*!< NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C */

/** 
  * @brief Flexible Memory Controller Bank1E
  */

#define FMC_Bank1E_BWTR_OFFSET    0x0000    /*!< NOR/PSRAM write timing registers, Address offset: 0x104-0x11C */

/** 
  * @brief Flexible Memory Controller Bank2
  */

#define FMC_Bank2_PCR2_OFFSET         0x0000    /*!< NAND Flash control register 2,                       Address offset: 0x60 */
#define FMC_Bank2_SR2_OFFSET          0x0004    /*!< NAND Flash FIFO status and interrupt register 2,     Address offset: 0x64 */
#define FMC_Bank2_PMEM2_OFFSET        0x0008    /*!< NAND Flash Common memory space timing register 2,    Address offset: 0x68 */
#define FMC_Bank2_PATT2_OFFSET        0x000C    /*!< NAND Flash Attribute memory space timing register 2, Address offset: 0x6C */
#define FMC_Bank2_RESERVED0_OFFSET    0x0010    /*!< Reserved, 0x70                                                            */
#define FMC_Bank2_ECCR2_OFFSET        0x0014    /*!< NAND Flash ECC result registers 2,                   Address offset: 0x74 */

/** 
  * @brief Flexible Memory Controller Bank3
  */

#define FMC_Bank3_PCR3_OFFSET         0x0000    /*!< NAND Flash control register 3,                       Address offset: 0x80 */
#define FMC_Bank3_SR3_OFFSET          0x0004    /*!< NAND Flash FIFO status and interrupt register 3,     Address offset: 0x84 */
#define FMC_Bank3_PMEM3_OFFSET        0x0008    /*!< NAND Flash Common memory space timing register 3,    Address offset: 0x88 */
#define FMC_Bank3_PATT3_OFFSET        0x000C    /*!< NAND Flash Attribute memory space timing register 3, Address offset: 0x8C */
#define FMC_Bank3_RESERVED0_OFFSET    0x0010    /*!< Reserved, 0x90                                                            */
#define FMC_Bank3_ECCR3_OFFSET        0x0014    /*!< NAND Flash ECC result registers 3,                   Address offset: 0x94 */

/** 
  * @brief Flexible Memory Controller Bank4
  */

#define FMC_Bank4_PCR4_OFFSET     0x0000    /*!< PC Card  control register 4,                       Address offset: 0xA0 */
#define FMC_Bank4_SR4_OFFSET      0x0004    /*!< PC Card  FIFO status and interrupt register 4,     Address offset: 0xA4 */
#define FMC_Bank4_PMEM4_OFFSET    0x0008    /*!< PC Card  Common memory space timing register 4,    Address offset: 0xA8 */
#define FMC_Bank4_PATT4_OFFSET    0x000C    /*!< PC Card  Attribute memory space timing register 4, Address offset: 0xAC */
#define FMC_Bank4_PIO4_OFFSET     0x0010    /*!< PC Card  I/O space timing register 4,              Address offset: 0xB0 */

/** 
  * @brief Option Bytes Registers
  */
#define OB_RDP_OFFSET          0x0000    /*!<FLASH option byte Read protection,             Address offset: 0x00 */
#define OB_USER_OFFSET         0x0002    /*!<FLASH option byte user options,                Address offset: 0x02 */
#define OB_RESERVED0_OFFSET    0x0004    /*!< Reserved,                                                     0x04 */
#define OB_RESERVED1_OFFSET    0x0006    /*!< Reserved,                                                     0x06 */
#define OB_WRP0_OFFSET         0x0008    /*!<FLASH option byte write protection 0,          Address offset: 0x08 */
#define OB_WRP1_OFFSET         0x000A    /*!<FLASH option byte write protection 1,          Address offset: 0x0C */
#define OB_WRP2_OFFSET         0x000C    /*!<FLASH option byte write protection 2,          Address offset: 0x10 */
#define OB_WRP3_OFFSET         0x000E    /*!<FLASH option byte write protection 3,          Address offset: 0x12 */

/** 
  * @brief General Purpose I/O
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
  * @brief High resolution Timer (HRTIM)
  */
#define HRTIM_Master_MCR_OFFSET          0x0000    /*!< HRTIM Master Timer control register,                     Address offset: 0x00 */
#define HRTIM_Master_MISR_OFFSET         0x0004    /*!< HRTIM Master Timer interrupt status register,            Address offset: 0x04 */
#define HRTIM_Master_MICR_OFFSET         0x0008    /*!< HRTIM Master Timer interrupt clear register,              Address offset: 0x08 */
#define HRTIM_Master_MDIER_OFFSET        0x000C    /*!< HRTIM Master Timer DMA/interrupt enable register         Address offset: 0x0C */
#define HRTIM_Master_MCNTR_OFFSET        0x0010    /*!< HRTIM Master Timer counter register,                     Address offset: 0x10 */
#define HRTIM_Master_MPER_OFFSET         0x0014    /*!< HRTIM Master Timer period register,                      Address offset: 0x14 */
#define HRTIM_Master_MREP_OFFSET         0x0018    /*!< HRTIM Master Timer repetition register,                  Address offset: 0x18 */
#define HRTIM_Master_MCMP1R_OFFSET       0x001C    /*!< HRTIM Master Timer compare 1 register,                   Address offset: 0x1C */
#define HRTIM_Master_RESERVED0_OFFSET    0x0020    /*!< Reserved,                                                                0x20 */
#define HRTIM_Master_MCMP2R_OFFSET       0x0024    /*!< HRTIM Master Timer compare 2 register,                   Address offset: 0x24 */
#define HRTIM_Master_MCMP3R_OFFSET       0x0028    /*!< HRTIM Master Timer compare 3 register,                   Address offset: 0x28 */
#define HRTIM_Master_MCMP4R_OFFSET       0x002C    /*!< HRTIM Master Timer compare 4 register,                   Address offset: 0x2C */

#define HRTIM_Timerx_TIMxCR_OFFSET       0x0000    /*!< HRTIM Timerx control register,                              Address offset: 0x00  */
#define HRTIM_Timerx_TIMxISR_OFFSET      0x0004    /*!< HRTIM Timerx interrupt status register,                     Address offset: 0x04  */
#define HRTIM_Timerx_TIMxICR_OFFSET      0x0008    /*!< HRTIM Timerx interrupt clear register,                      Address offset: 0x08  */
#define HRTIM_Timerx_TIMxDIER_OFFSET     0x000C    /*!< HRTIM Timerx DMA/interrupt enable register,                 Address offset: 0x0C  */
#define HRTIM_Timerx_CNTxR_OFFSET        0x0010    /*!< HRTIM Timerx counter register,                              Address offset: 0x10  */
#define HRTIM_Timerx_PERxR_OFFSET        0x0014    /*!< HRTIM Timerx period register,                               Address offset: 0x14  */
#define HRTIM_Timerx_REPxR_OFFSET        0x0018    /*!< HRTIM Timerx repetition register,                           Address offset: 0x18  */
#define HRTIM_Timerx_CMP1xR_OFFSET       0x001C    /*!< HRTIM Timerx compare 1 register,                            Address offset: 0x1C  */
#define HRTIM_Timerx_CMP1CxR_OFFSET      0x0020    /*!< HRTIM Timerx compare 1 compound register,                   Address offset: 0x20  */
#define HRTIM_Timerx_CMP2xR_OFFSET       0x0024    /*!< HRTIM Timerx compare 2 register,                            Address offset: 0x24  */
#define HRTIM_Timerx_CMP3xR_OFFSET       0x0028    /*!< HRTIM Timerx compare 3 register,                            Address offset: 0x28  */
#define HRTIM_Timerx_CMP4xR_OFFSET       0x002C    /*!< HRTIM Timerx compare 4 register,                            Address offset: 0x2C  */
#define HRTIM_Timerx_CPT1xR_OFFSET       0x0030    /*!< HRTIM Timerx capture 1 register,                            Address offset: 0x30  */
#define HRTIM_Timerx_CPT2xR_OFFSET       0x0034    /*!< HRTIM Timerx capture 2 register,                            Address offset: 0x34 */
#define HRTIM_Timerx_DTxR_OFFSET         0x0038    /*!< HRTIM Timerx dead time register,                            Address offset: 0x38 */
#define HRTIM_Timerx_SETx1R_OFFSET       0x003C    /*!< HRTIM Timerx output 1 set register,                         Address offset: 0x3C */
#define HRTIM_Timerx_RSTx1R_OFFSET       0x0040    /*!< HRTIM Timerx output 1 reset register,                       Address offset: 0x40 */
#define HRTIM_Timerx_SETx2R_OFFSET       0x0044    /*!< HRTIM Timerx output 2 set register,                         Address offset: 0x44 */
#define HRTIM_Timerx_RSTx2R_OFFSET       0x0048    /*!< HRTIM Timerx output 2 reset register,                       Address offset: 0x48 */
#define HRTIM_Timerx_EEFxR1_OFFSET       0x004C    /*!< HRTIM Timerx external event filtering 1 register,           Address offset: 0x4C */
#define HRTIM_Timerx_EEFxR2_OFFSET       0x0050    /*!< HRTIM Timerx external event filtering 2 register,           Address offset: 0x50 */
#define HRTIM_Timerx_RSTxR_OFFSET        0x0054    /*!< HRTIM Timerx Reset register,                                Address offset: 0x54 */
#define HRTIM_Timerx_CHPxR_OFFSET        0x0058    /*!< HRTIM Timerx Chopper register,                              Address offset: 0x58 */
#define HRTIM_Timerx_CPT1xCR_OFFSET      0x005C    /*!< HRTIM Timerx Capture 1 register,                            Address offset: 0x5C */
#define HRTIM_Timerx_CPT2xCR_OFFSET      0x0060    /*!< HRTIM Timerx Capture 2 register,                            Address offset: 0x60 */
#define HRTIM_Timerx_OUTxR_OFFSET        0x0064    /*!< HRTIM Timerx Output register,                               Address offset: 0x64 */
#define HRTIM_Timerx_FLTxR_OFFSET        0x0068    /*!< HRTIM Timerx Fault register,                                Address offset: 0x68 */
#define HRTIM_Timerx_RESERVED0_OFFSET    0x006C    /*!< Reserved,                                                                       */

#define HRTIM_Common_CR1_OFFSET         0x0000    /*!< HRTIM control register1,                                    Address offset: 0x00 */
#define HRTIM_Common_CR2_OFFSET         0x0004    /*!< HRTIM control register2,                                    Address offset: 0x04 */
#define HRTIM_Common_ISR_OFFSET         0x0008    /*!< HRTIM interrupt status register,                            Address offset: 0x08 */
#define HRTIM_Common_ICR_OFFSET         0x000C    /*!< HRTIM interrupt clear register,                             Address offset: 0x0C */
#define HRTIM_Common_IER_OFFSET         0x0010    /*!< HRTIM interrupt enable register,                            Address offset: 0x10 */
#define HRTIM_Common_OENR_OFFSET        0x0014    /*!< HRTIM Output enable register,                               Address offset: 0x14 */
#define HRTIM_Common_DISR_OFFSET        0x0018    /*!< HRTIM Output disable register,                              Address offset: 0x18 */
#define HRTIM_Common_ODSR_OFFSET        0x001C    /*!< HRTIM Output disable status register,                       Address offset: 0x1C */
#define HRTIM_Common_BMCR_OFFSET        0x0020    /*!< HRTIM Burst mode control register,                          Address offset: 0x20 */
#define HRTIM_Common_BMTRGR_OFFSET      0x0024    /*!< HRTIM Busrt mode trigger register,                          Address offset: 0x24 */
#define HRTIM_Common_BMCMPR_OFFSET      0x0028    /*!< HRTIM Burst mode compare register,                          Address offset: 0x28 */
#define HRTIM_Common_BMPER_OFFSET       0x002C    /*!< HRTIM Burst mode period register,                           Address offset: 0x2C */
#define HRTIM_Common_EECR1_OFFSET       0x0030    /*!< HRTIM Timer external event control register1,               Address offset: 0x30 */
#define HRTIM_Common_EECR2_OFFSET       0x0034    /*!< HRTIM Timer external event control register2,               Address offset: 0x34 */
#define HRTIM_Common_EECR3_OFFSET       0x0038    /*!< HRTIM Timer external event control register3,               Address offset: 0x38 */
#define HRTIM_Common_ADC1R_OFFSET       0x003C    /*!< HRTIM ADC Trigger 1 register,                               Address offset: 0x3C */
#define HRTIM_Common_ADC2R_OFFSET       0x0040    /*!< HRTIM ADC Trigger 2 register,                               Address offset: 0x40 */
#define HRTIM_Common_ADC3R_OFFSET       0x0044    /*!< HRTIM ADC Trigger 3 register,                               Address offset: 0x44 */
#define HRTIM_Common_ADC4R_OFFSET       0x0048    /*!< HRTIM ADC Trigger 4 register,                               Address offset: 0x48 */
#define HRTIM_Common_DLLCR_OFFSET       0x004C    /*!< HRTIM DLL control register,                                 Address offset: 0x4C */
#define HRTIM_Common_FLTINxR1_OFFSET    0x0050    /*!< HRTIM Fault input register1,                                Address offset: 0x50 */
#define HRTIM_Common_FLTINxR2_OFFSET    0x0054    /*!< HRTIM Fault input register2,                                Address offset: 0x54 */
#define HRTIM_Common_BDMUPDR_OFFSET     0x0058    /*!< HRTIM Burst DMA Master Timer update register,               Address offset: 0x58 */
#define HRTIM_Common_BDTAUPR_OFFSET     0x005C    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x5C */
#define HRTIM_Common_BDTBUPR_OFFSET     0x0060    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x60 */
#define HRTIM_Common_BDTCUPR_OFFSET     0x0064    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x64 */
#define HRTIM_Common_BDTDUPR_OFFSET     0x0068    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x68 */
#define HRTIM_Common_BDTEUPR_OFFSET     0x006C    /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x6C */
#define HRTIM_Common_BDMADR_OFFSET      0x0070    /*!< HRTIM Burst DMA Master Data register,                       Address offset: 0x70 */

#define HRTIM_HRTIM_MASTER_OFFSET    0x0000    
#define HRTIM_RESERVED0_OFFSET       0x0030    
#define HRTIM_HRTIM_TIMERx_OFFSET    0x0080    
#define HRTIM_RESERVED1_OFFSET       0x0300    
#define HRTIM_HRTIM_COMMON_OFFSET    0x0380    

/** 
  * @brief Operational Amplifier (OPAMP)
  */

#define OPAMP_CSR_OFFSET    0x0000    /*!< OPAMP control and status register,            Address offset: 0x00 */


/** 
  * @brief System configuration controller
  */

#define SYSCFG_CFGR1_OFFSET         0x0000    /*!< SYSCFG configuration register 1,                   Address offset: 0x00 */
#define SYSCFG_RCR_OFFSET           0x0004    /*!< SYSCFG CCM SRAM protection register,               Address offset: 0x04 */
#define SYSCFG_EXTICR_OFFSET        0x0008    /*!< SYSCFG external interrupt configuration registers, Address offset: 0x14-0x08 */
#define SYSCFG_CFGR2_OFFSET         0x0018    /*!< SYSCFG configuration register 2,                    Address offset: 0x18 */
#define SYSCFG_RESERVED0_OFFSET     0x001C    /*!< Reserved,                                                           0x1C */
#define SYSCFG_RESERVED1_OFFSET     0x0020    /*!< Reserved,                                                          0x20 */
#define SYSCFG_RESERVED2_OFFSET     0x0024    /*!< Reserved,                                                          0x24 */
#define SYSCFG_RESERVED4_OFFSET     0x0028    /*!< Reserved,                                                          0x28 */
#define SYSCFG_RESERVED5_OFFSET     0x002C    /*!< Reserved,                                                          0x2C */
#define SYSCFG_RESERVED6_OFFSET     0x0030    /*!< Reserved,                                                          0x30 */
#define SYSCFG_RESERVED7_OFFSET     0x0034    /*!< Reserved,                                                          0x34 */
#define SYSCFG_RESERVED8_OFFSET     0x0038    /*!< Reserved,                                                          0x38 */
#define SYSCFG_RESERVED9_OFFSET     0x003C    /*!< Reserved,                                                          0x3C */
#define SYSCFG_RESERVED10_OFFSET    0x0040    /*!< Reserved,                                                          0x40 */
#define SYSCFG_RESERVED11_OFFSET    0x0044    /*!< Reserved,                                                          0x44 */
#define SYSCFG_CFGR4_OFFSET         0x0048    /*!< SYSCFG configuration register 4,                   Address offset: 0x48 */
#define SYSCFG_RESERVED13_OFFSET    0x004C    /*!< Reserved,                                                          0x4C */
#define SYSCFG_CFGR3_OFFSET         0x0050    /*!< SYSCFG configuration register 3,                   Address offset: 0x50 */

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

/**
  * @brief Real-Time Clock
  */

#define RTC_TR_OFFSET           0x0000    /*!< RTC time register,                                        Address offset: 0x00 */
#define RTC_DR_OFFSET           0x0004    /*!< RTC date register,                                        Address offset: 0x04 */
#define RTC_CR_OFFSET           0x0008    /*!< RTC control register,                                     Address offset: 0x08 */
#define RTC_ISR_OFFSET          0x000C    /*!< RTC initialization and status register,                   Address offset: 0x0C */
#define RTC_PRER_OFFSET         0x0010    /*!< RTC prescaler register,                                   Address offset: 0x10 */
#define RTC_WUTR_OFFSET         0x0014    /*!< RTC wakeup timer register,                                Address offset: 0x14 */
#define RTC_RESERVED0_OFFSET    0x0018    /*!< Reserved, 0x18                                                                 */
#define RTC_ALRMAR_OFFSET       0x001C    /*!< RTC alarm A register,                                     Address offset: 0x1C */
#define RTC_ALRMBR_OFFSET       0x0020    /*!< RTC alarm B register,                                     Address offset: 0x20 */
#define RTC_WPR_OFFSET          0x0024    /*!< RTC write protection register,                            Address offset: 0x24 */
#define RTC_SSR_OFFSET          0x0028    /*!< RTC sub second register,                                  Address offset: 0x28 */
#define RTC_SHIFTR_OFFSET       0x002C    /*!< RTC shift control register,                               Address offset: 0x2C */
#define RTC_TSTR_OFFSET         0x0030    /*!< RTC time stamp time register,                             Address offset: 0x30 */
#define RTC_TSDR_OFFSET         0x0034    /*!< RTC time stamp date register,                             Address offset: 0x34 */
#define RTC_TSSSR_OFFSET        0x0038    /*!< RTC time-stamp sub second register,                       Address offset: 0x38 */
#define RTC_CALR_OFFSET         0x003C    /*!< RTC calibration register,                                 Address offset: 0x3C */
#define RTC_TAFCR_OFFSET        0x0040    /*!< RTC tamper and alternate function configuration register, Address offset: 0x40 */
#define RTC_ALRMASSR_OFFSET     0x0044    /*!< RTC alarm A sub second register,                          Address offset: 0x44 */
#define RTC_ALRMBSSR_OFFSET     0x0048    /*!< RTC alarm B sub second register,                          Address offset: 0x48 */
#define RTC_RESERVED7_OFFSET    0x004C    /*!< Reserved, 0x4C                                                                 */
#define RTC_BKP0R_OFFSET        0x0050    /*!< RTC backup register 0,                                    Address offset: 0x50 */
#define RTC_BKP1R_OFFSET        0x0054    /*!< RTC backup register 1,                                    Address offset: 0x54 */
#define RTC_BKP2R_OFFSET        0x0058    /*!< RTC backup register 2,                                    Address offset: 0x58 */
#define RTC_BKP3R_OFFSET        0x005C    /*!< RTC backup register 3,                                    Address offset: 0x5C */
#define RTC_BKP4R_OFFSET        0x0060    /*!< RTC backup register 4,                                    Address offset: 0x60 */
#define RTC_BKP5R_OFFSET        0x0064    /*!< RTC backup register 5,                                    Address offset: 0x64 */
#define RTC_BKP6R_OFFSET        0x0068    /*!< RTC backup register 6,                                    Address offset: 0x68 */
#define RTC_BKP7R_OFFSET        0x006C    /*!< RTC backup register 7,                                    Address offset: 0x6C */
#define RTC_BKP8R_OFFSET        0x0070    /*!< RTC backup register 8,                                    Address offset: 0x70 */
#define RTC_BKP9R_OFFSET        0x0074    /*!< RTC backup register 9,                                    Address offset: 0x74 */
#define RTC_BKP10R_OFFSET       0x0078    /*!< RTC backup register 10,                                   Address offset: 0x78 */
#define RTC_BKP11R_OFFSET       0x007C    /*!< RTC backup register 11,                                   Address offset: 0x7C */
#define RTC_BKP12R_OFFSET       0x0080    /*!< RTC backup register 12,                                   Address offset: 0x80 */
#define RTC_BKP13R_OFFSET       0x0084    /*!< RTC backup register 13,                                   Address offset: 0x84 */
#define RTC_BKP14R_OFFSET       0x0088    /*!< RTC backup register 14,                                   Address offset: 0x88 */
#define RTC_BKP15R_OFFSET       0x008C    /*!< RTC backup register 15,                                   Address offset: 0x8C */


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
#define TIM_CR1_OFFSET           0x0000    /*!< TIM control register 1,              Address offset: 0x00 */
#define TIM_RESERVED0_OFFSET     0x0002    /*!< Reserved, 0x02                                            */
#define TIM_CR2_OFFSET           0x0004    /*!< TIM control register 2,              Address offset: 0x04 */
#define TIM_SMCR_OFFSET          0x0008    /*!< TIM slave mode control register,     Address offset: 0x08 */
#define TIM_DIER_OFFSET          0x000C    /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define TIM_SR_OFFSET            0x0010    /*!< TIM status register,                 Address offset: 0x10 */
#define TIM_EGR_OFFSET           0x0014    /*!< TIM event generation register,       Address offset: 0x14 */
#define TIM_CCMR1_OFFSET         0x0018    /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define TIM_CCMR2_OFFSET         0x001C    /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define TIM_CCER_OFFSET          0x0020    /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define TIM_CNT_OFFSET           0x0024    /*!< TIM counter register,                Address offset: 0x24 */
#define TIM_PSC_OFFSET           0x0028    /*!< TIM prescaler,                       Address offset: 0x28 */
#define TIM_RESERVED9_OFFSET     0x002A    /*!< Reserved, 0x2A                                            */
#define TIM_ARR_OFFSET           0x002C    /*!< TIM auto-reload register,            Address offset: 0x2C */
#define TIM_RCR_OFFSET           0x0030    /*!< TIM repetition counter register,     Address offset: 0x30 */
#define TIM_RESERVED10_OFFSET    0x0032    /*!< Reserved, 0x32                                            */
#define TIM_CCR1_OFFSET          0x0034    /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define TIM_CCR2_OFFSET          0x0038    /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define TIM_CCR3_OFFSET          0x003C    /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define TIM_CCR4_OFFSET          0x0040    /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define TIM_BDTR_OFFSET          0x0044    /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define TIM_DCR_OFFSET           0x0048    /*!< TIM DMA control register,            Address offset: 0x48 */
#define TIM_RESERVED12_OFFSET    0x004A    /*!< Reserved, 0x4A                                            */
#define TIM_DMAR_OFFSET          0x004C    /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define TIM_RESERVED13_OFFSET    0x004E    /*!< Reserved, 0x4E                                            */
#define TIM_OR_OFFSET            0x0050    /*!< TIM option register,                 Address offset: 0x50 */
#define TIM_CCMR3_OFFSET         0x0052    /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define TIM_CCR5_OFFSET          0x0056    /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define TIM_CCR6_OFFSET          0x005A    /*!< TIM capture/compare register 4,      Address offset: 0x5C */


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


/** @addtogroup Peripheral_memory_map
  * @{
  */
#define FLASH_BASE            (0x08000000) /*!< FLASH base address in the alias region                                       */
#define CCMDATARAM_BASE       (0x10000000) /*!< CCM(core coupled memory) data RAM(16 KB) base address in the alias region    */
#define SRAM_BASE             (0x20000000) /*!< SRAM base address in the alias region                                        */
#define PERIPH_BASE           (0x40000000) /*!< Peripheral base address in the alias region                                  */
#define FMC_R_BASE            (0xA0000000) /*!< FMC registers base address                                                   */

#define CCMDATARAM_BB_BASE    (0x12000000) /*!< CCM(core coupled memory) data RAM base address in the bit-band region        */
#define SRAM_BB_BASE          (0x22000000) /*!< SRAM base address in the bit-band region                                     */
#define PERIPH_BB_BASE        (0x42000000) /*!< Peripheral base address in the bit-band region                               */

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000)
#define AHB3PERIPH_BASE       (PERIPH_BASE + 0x10000000)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x00000000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x00000400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x00000800)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x00001000)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x00001400)
#define RTC_BASE              (APB1PERIPH_BASE + 0x00002800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x00002C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x00003000)
#define I2S2ext_BASE          (APB1PERIPH_BASE + 0x00003400)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x00003800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x00003C00)
#define I2S3ext_BASE          (APB1PERIPH_BASE + 0x00004000)
#define USART2_BASE           (APB1PERIPH_BASE + 0x00004400)
#define USART3_BASE           (APB1PERIPH_BASE + 0x00004800)
#define UART4_BASE            (APB1PERIPH_BASE + 0x00004C00)
#define UART5_BASE            (APB1PERIPH_BASE + 0x00005000)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x00005400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x00005800)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x00006400)
#define PWR_BASE              (APB1PERIPH_BASE + 0x00007000)
#define DAC1_BASE             (APB1PERIPH_BASE + 0x00007400)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x00007800)
#define DAC2_BASE             (APB1PERIPH_BASE + 0x00009800)
#define DAC_BASE               DAC1_BASE

#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x00000000)
#define COMP_BASE             (APB2PERIPH_BASE + 0x0000001C)
#define COMP1_BASE            (APB2PERIPH_BASE + 0x0000001C)
#define COMP2_BASE            (APB2PERIPH_BASE + 0x00000020)
#define COMP3_BASE            (APB2PERIPH_BASE + 0x00000024)
#define COMP4_BASE            (APB2PERIPH_BASE + 0x00000028)
#define COMP5_BASE            (APB2PERIPH_BASE + 0x0000002C)
#define COMP6_BASE            (APB2PERIPH_BASE + 0x00000030)
#define COMP7_BASE            (APB2PERIPH_BASE + 0x00000034)
#define OPAMP_BASE            (APB2PERIPH_BASE + 0x00000038)
#define OPAMP1_BASE           (APB2PERIPH_BASE + 0x00000038)
#define OPAMP2_BASE           (APB2PERIPH_BASE + 0x0000003C)
#define OPAMP3_BASE           (APB2PERIPH_BASE + 0x00000040)
#define OPAMP4_BASE           (APB2PERIPH_BASE + 0x00000044)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x00000400)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x00002C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x00003000)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x00003400)
#define USART1_BASE           (APB2PERIPH_BASE + 0x00003800)
#define SPI4_BASE             (APB2PERIPH_BASE + 0x00003C00)
#define TIM15_BASE            (APB2PERIPH_BASE + 0x00004000)
#define TIM16_BASE            (APB2PERIPH_BASE + 0x00004400)
#define TIM17_BASE            (APB2PERIPH_BASE + 0x00004800)
#define TIM20_BASE            (APB2PERIPH_BASE + 0x00005000)
#define HRTIM1_BASE           (APB2PERIPH_BASE + 0x00007400)
#define HRTIM1_TIMA_BASE      (HRTIM1_BASE + 0x00000080)
#define HRTIM1_TIMB_BASE      (HRTIM1_BASE + 0x00000100)
#define HRTIM1_TIMC_BASE      (HRTIM1_BASE + 0x00000180)
#define HRTIM1_TIMD_BASE      (HRTIM1_BASE + 0x00000200)
#define HRTIM1_TIME_BASE      (HRTIM1_BASE + 0x00000280)
#define HRTIM1_COMMON_BASE    (HRTIM1_BASE + 0x00000380)

#define DMA1_BASE             (AHB1PERIPH_BASE + 0x00000000)
#define DMA1_Channel1_BASE    (AHB1PERIPH_BASE + 0x00000008)
#define DMA1_Channel2_BASE    (AHB1PERIPH_BASE + 0x0000001C)
#define DMA1_Channel3_BASE    (AHB1PERIPH_BASE + 0x00000030)
#define DMA1_Channel4_BASE    (AHB1PERIPH_BASE + 0x00000044)
#define DMA1_Channel5_BASE    (AHB1PERIPH_BASE + 0x00000058)
#define DMA1_Channel6_BASE    (AHB1PERIPH_BASE + 0x0000006C)
#define DMA1_Channel7_BASE    (AHB1PERIPH_BASE + 0x00000080)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x00000400)
#define DMA2_Channel1_BASE    (AHB1PERIPH_BASE + 0x00000408)
#define DMA2_Channel2_BASE    (AHB1PERIPH_BASE + 0x0000041C)
#define DMA2_Channel3_BASE    (AHB1PERIPH_BASE + 0x00000430)
#define DMA2_Channel4_BASE    (AHB1PERIPH_BASE + 0x00000444)
#define DMA2_Channel5_BASE    (AHB1PERIPH_BASE + 0x00000458)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x00001000)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x00002000) /*!< Flash registers base address */
#define OB_BASE               (0x1FFFF800)     /*!< Flash Option Bytes base address */
#define CRC_BASE              (AHB1PERIPH_BASE + 0x00003000)
#define TSC_BASE              (AHB1PERIPH_BASE + 0x00004000)

#define GPIOA_BASE            (AHB2PERIPH_BASE + 0x0000)
#define GPIOB_BASE            (AHB2PERIPH_BASE + 0x0400)
#define GPIOC_BASE            (AHB2PERIPH_BASE + 0x0800)
#define GPIOD_BASE            (AHB2PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x1000)
#define GPIOF_BASE            (AHB2PERIPH_BASE + 0x1400)
#define GPIOG_BASE            (AHB2PERIPH_BASE + 0x00001800)
#define GPIOH_BASE            (AHB2PERIPH_BASE + 0x00001C00)

#define ADC1_BASE             (AHB3PERIPH_BASE + 0x0000)
#define ADC2_BASE             (AHB3PERIPH_BASE + 0x0100)
#define ADC1_2_BASE           (AHB3PERIPH_BASE + 0x0300)
#define ADC3_BASE             (AHB3PERIPH_BASE + 0x0400)
#define ADC4_BASE             (AHB3PERIPH_BASE + 0x0500)
#define ADC3_4_BASE           (AHB3PERIPH_BASE + 0x0700)

#define FMC_Bank1_R_BASE      (FMC_R_BASE + 0x0000)
#define FMC_Bank1E_R_BASE     (FMC_R_BASE + 0x0104)
#define FMC_Bank2_R_BASE      (FMC_R_BASE + 0x0060)
#define FMC_Bank3_R_BASE      (FMC_R_BASE + 0x0080)
#define FMC_Bank4_R_BASE      (FMC_R_BASE + 0x00A0)

#define DBGMCU_BASE          (0xE0042000) /*!< Debug MCU registers base address */
/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */  
#define TIM2                (TIM2_BASE)
#define _TIM2_CR1           (TIM2 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM2_CR2           (TIM2 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM2_SMCR          (TIM2 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM2_DIER          (TIM2 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM2_SR            (TIM2 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM2_EGR           (TIM2 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM2_CCMR1         (TIM2 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM2_CCMR2         (TIM2 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM2_CCER          (TIM2 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM2_CNT           (TIM2 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM2_PSC           (TIM2 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM2_ARR           (TIM2 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM2_RCR           (TIM2 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM2_CCR1          (TIM2 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM2_CCR2          (TIM2 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM2_CCR3          (TIM2 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM2_CCR4          (TIM2 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM2_BDTR          (TIM2 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM2_DCR           (TIM2 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM2_DMAR          (TIM2 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM2_OR            (TIM2 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM2_CCMR3         (TIM2 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM2_CCR5          (TIM2 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM2_CCR6          (TIM2 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

#define TIM3                (TIM3_BASE)
#define _TIM3_CR1           (TIM3 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM3_CR2           (TIM3 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM3_SMCR          (TIM3 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM3_DIER          (TIM3 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM3_SR            (TIM3 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM3_EGR           (TIM3 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM3_CCMR1         (TIM3 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM3_CCMR2         (TIM3 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM3_CCER          (TIM3 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM3_CNT           (TIM3 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM3_PSC           (TIM3 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM3_ARR           (TIM3 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM3_RCR           (TIM3 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM3_CCR1          (TIM3 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM3_CCR2          (TIM3 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM3_CCR3          (TIM3 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM3_CCR4          (TIM3 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM3_BDTR          (TIM3 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM3_DCR           (TIM3 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM3_DMAR          (TIM3 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM3_OR            (TIM3 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM3_CCMR3         (TIM3 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM3_CCR5          (TIM3 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM3_CCR6          (TIM3 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

#define TIM4                (TIM4_BASE)
#define _TIM4_CR1           (TIM4 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM4_CR2           (TIM4 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM4_SMCR          (TIM4 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM4_DIER          (TIM4 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM4_SR            (TIM4 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM4_EGR           (TIM4 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM4_CCMR1         (TIM4 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM4_CCMR2         (TIM4 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM4_CCER          (TIM4 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM4_CNT           (TIM4 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM4_PSC           (TIM4 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM4_ARR           (TIM4 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM4_RCR           (TIM4 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM4_CCR1          (TIM4 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM4_CCR2          (TIM4 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM4_CCR3          (TIM4 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM4_CCR4          (TIM4 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM4_BDTR          (TIM4 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM4_DCR           (TIM4 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM4_DMAR          (TIM4 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM4_OR            (TIM4 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM4_CCMR3         (TIM4 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM4_CCR5          (TIM4 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM4_CCR6          (TIM4 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

#define TIM6                (TIM6_BASE)
#define _TIM6_CR1           (TIM6 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM6_CR2           (TIM6 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM6_SMCR          (TIM6 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM6_DIER          (TIM6 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM6_SR            (TIM6 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM6_EGR           (TIM6 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM6_CCMR1         (TIM6 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM6_CCMR2         (TIM6 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM6_CCER          (TIM6 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM6_CNT           (TIM6 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM6_PSC           (TIM6 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM6_ARR           (TIM6 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM6_RCR           (TIM6 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM6_CCR1          (TIM6 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM6_CCR2          (TIM6 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM6_CCR3          (TIM6 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM6_CCR4          (TIM6 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM6_BDTR          (TIM6 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM6_DCR           (TIM6 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM6_DMAR          (TIM6 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM6_OR            (TIM6 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM6_CCMR3         (TIM6 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM6_CCR5          (TIM6 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM6_CCR6          (TIM6 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

#define TIM7                (TIM7_BASE)
#define _TIM7_CR1           (TIM7 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM7_CR2           (TIM7 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM7_SMCR          (TIM7 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM7_DIER          (TIM7 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM7_SR            (TIM7 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM7_EGR           (TIM7 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM7_CCMR1         (TIM7 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM7_CCMR2         (TIM7 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM7_CCER          (TIM7 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM7_CNT           (TIM7 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM7_PSC           (TIM7 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM7_ARR           (TIM7 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM7_RCR           (TIM7 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM7_CCR1          (TIM7 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM7_CCR2          (TIM7 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM7_CCR3          (TIM7 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM7_CCR4          (TIM7 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM7_BDTR          (TIM7 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM7_DCR           (TIM7 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM7_DMAR          (TIM7 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM7_OR            (TIM7 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM7_CCMR3         (TIM7 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM7_CCR5          (TIM7 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM7_CCR6          (TIM7 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

#define RTC                 (RTC_BASE)
#define _RTC_TR           (RTC + RTC_TR_OFFSET)           /*!< RTC time register,                                        Address offset: 0x00 */
#define _RTC_DR           (RTC + RTC_DR_OFFSET)           /*!< RTC date register,                                        Address offset: 0x04 */
#define _RTC_CR           (RTC + RTC_CR_OFFSET)           /*!< RTC control register,                                     Address offset: 0x08 */
#define _RTC_ISR          (RTC + RTC_ISR_OFFSET)          /*!< RTC initialization and status register,                   Address offset: 0x0C */
#define _RTC_PRER         (RTC + RTC_PRER_OFFSET)         /*!< RTC prescaler register,                                   Address offset: 0x10 */
#define _RTC_WUTR         (RTC + RTC_WUTR_OFFSET)         /*!< RTC wakeup timer register,                                Address offset: 0x14 */
#define _RTC_ALRMAR       (RTC + RTC_ALRMAR_OFFSET)       /*!< RTC alarm A register,                                     Address offset: 0x1C */
#define _RTC_ALRMBR       (RTC + RTC_ALRMBR_OFFSET)       /*!< RTC alarm B register,                                     Address offset: 0x20 */
#define _RTC_WPR          (RTC + RTC_WPR_OFFSET)          /*!< RTC write protection register,                            Address offset: 0x24 */
#define _RTC_SSR          (RTC + RTC_SSR_OFFSET)          /*!< RTC sub second register,                                  Address offset: 0x28 */
#define _RTC_SHIFTR       (RTC + RTC_SHIFTR_OFFSET)       /*!< RTC shift control register,                               Address offset: 0x2C */
#define _RTC_TSTR         (RTC + RTC_TSTR_OFFSET)         /*!< RTC time stamp time register,                             Address offset: 0x30 */
#define _RTC_TSDR         (RTC + RTC_TSDR_OFFSET)         /*!< RTC time stamp date register,                             Address offset: 0x34 */
#define _RTC_TSSSR        (RTC + RTC_TSSSR_OFFSET)        /*!< RTC time-stamp sub second register,                       Address offset: 0x38 */
#define _RTC_CALR         (RTC + RTC_CALR_OFFSET)         /*!< RTC calibration register,                                 Address offset: 0x3C */
#define _RTC_TAFCR        (RTC + RTC_TAFCR_OFFSET)        /*!< RTC tamper and alternate function configuration register, Address offset: 0x40 */
#define _RTC_ALRMASSR     (RTC + RTC_ALRMASSR_OFFSET)     /*!< RTC alarm A sub second register,                          Address offset: 0x44 */
#define _RTC_ALRMBSSR     (RTC + RTC_ALRMBSSR_OFFSET)     /*!< RTC alarm B sub second register,                          Address offset: 0x48 */
#define _RTC_BKP0R        (RTC + RTC_BKP0R_OFFSET)        /*!< RTC backup register 0,                                    Address offset: 0x50 */
#define _RTC_BKP1R        (RTC + RTC_BKP1R_OFFSET)        /*!< RTC backup register 1,                                    Address offset: 0x54 */
#define _RTC_BKP2R        (RTC + RTC_BKP2R_OFFSET)        /*!< RTC backup register 2,                                    Address offset: 0x58 */
#define _RTC_BKP3R        (RTC + RTC_BKP3R_OFFSET)        /*!< RTC backup register 3,                                    Address offset: 0x5C */
#define _RTC_BKP4R        (RTC + RTC_BKP4R_OFFSET)        /*!< RTC backup register 4,                                    Address offset: 0x60 */
#define _RTC_BKP5R        (RTC + RTC_BKP5R_OFFSET)        /*!< RTC backup register 5,                                    Address offset: 0x64 */
#define _RTC_BKP6R        (RTC + RTC_BKP6R_OFFSET)        /*!< RTC backup register 6,                                    Address offset: 0x68 */
#define _RTC_BKP7R        (RTC + RTC_BKP7R_OFFSET)        /*!< RTC backup register 7,                                    Address offset: 0x6C */
#define _RTC_BKP8R        (RTC + RTC_BKP8R_OFFSET)        /*!< RTC backup register 8,                                    Address offset: 0x70 */
#define _RTC_BKP9R        (RTC + RTC_BKP9R_OFFSET)        /*!< RTC backup register 9,                                    Address offset: 0x74 */
#define _RTC_BKP10R       (RTC + RTC_BKP10R_OFFSET)       /*!< RTC backup register 10,                                   Address offset: 0x78 */
#define _RTC_BKP11R       (RTC + RTC_BKP11R_OFFSET)       /*!< RTC backup register 11,                                   Address offset: 0x7C */
#define _RTC_BKP12R       (RTC + RTC_BKP12R_OFFSET)       /*!< RTC backup register 12,                                   Address offset: 0x80 */
#define _RTC_BKP13R       (RTC + RTC_BKP13R_OFFSET)       /*!< RTC backup register 13,                                   Address offset: 0x84 */
#define _RTC_BKP14R       (RTC + RTC_BKP14R_OFFSET)       /*!< RTC backup register 14,                                   Address offset: 0x88 */
#define _RTC_BKP15R       (RTC + RTC_BKP15R_OFFSET)       /*!< RTC backup register 15,                                   Address offset: 0x8C */

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

#define I2S2ext             (I2S2ext_BASE)
#define _I2S2ext_CR1          (I2S2ext + SPI_CR1_OFFSET)          /*!< SPI Control register 1 (not used in I2S mode),       Address offset: 0x00 */
#define _I2S2ext_CR2          (I2S2ext + SPI_CR2_OFFSET)          /*!< SPI Control register 2,                              Address offset: 0x04 */
#define _I2S2ext_SR           (I2S2ext + SPI_SR_OFFSET)           /*!< SPI Status register,                                 Address offset: 0x08 */
#define _I2S2ext_DR           (I2S2ext + SPI_DR_OFFSET)           /*!< SPI data register,                                   Address offset: 0x0C */
#define _I2S2ext_CRCPR        (I2S2ext + SPI_CRCPR_OFFSET)        /*!< SPI CRC polynomial register (not used in I2S mode),  Address offset: 0x10 */
#define _I2S2ext_RXCRCR       (I2S2ext + SPI_RXCRCR_OFFSET)       /*!< SPI Rx CRC register (not used in I2S mode),          Address offset: 0x14 */
#define _I2S2ext_TXCRCR       (I2S2ext + SPI_TXCRCR_OFFSET)       /*!< SPI Tx CRC register (not used in I2S mode),          Address offset: 0x18 */
#define _I2S2ext_I2SCFGR      (I2S2ext + SPI_I2SCFGR_OFFSET)      /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
#define _I2S2ext_I2SPR        (I2S2ext + SPI_I2SPR_OFFSET)        /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */

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

#define SPI3                (SPI3_BASE)
#define _SPI3_CR1          (SPI3 + SPI_CR1_OFFSET)          /*!< SPI Control register 1 (not used in I2S mode),       Address offset: 0x00 */
#define _SPI3_CR2          (SPI3 + SPI_CR2_OFFSET)          /*!< SPI Control register 2,                              Address offset: 0x04 */
#define _SPI3_SR           (SPI3 + SPI_SR_OFFSET)           /*!< SPI Status register,                                 Address offset: 0x08 */
#define _SPI3_DR           (SPI3 + SPI_DR_OFFSET)           /*!< SPI data register,                                   Address offset: 0x0C */
#define _SPI3_CRCPR        (SPI3 + SPI_CRCPR_OFFSET)        /*!< SPI CRC polynomial register (not used in I2S mode),  Address offset: 0x10 */
#define _SPI3_RXCRCR       (SPI3 + SPI_RXCRCR_OFFSET)       /*!< SPI Rx CRC register (not used in I2S mode),          Address offset: 0x14 */
#define _SPI3_TXCRCR       (SPI3 + SPI_TXCRCR_OFFSET)       /*!< SPI Tx CRC register (not used in I2S mode),          Address offset: 0x18 */
#define _SPI3_I2SCFGR      (SPI3 + SPI_I2SCFGR_OFFSET)      /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
#define _SPI3_I2SPR        (SPI3 + SPI_I2SPR_OFFSET)        /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */

#define I2S3ext             (I2S3ext_BASE)
#define _I2S3ext_CR1          (I2S3ext + SPI_CR1_OFFSET)          /*!< SPI Control register 1 (not used in I2S mode),       Address offset: 0x00 */
#define _I2S3ext_CR2          (I2S3ext + SPI_CR2_OFFSET)          /*!< SPI Control register 2,                              Address offset: 0x04 */
#define _I2S3ext_SR           (I2S3ext + SPI_SR_OFFSET)           /*!< SPI Status register,                                 Address offset: 0x08 */
#define _I2S3ext_DR           (I2S3ext + SPI_DR_OFFSET)           /*!< SPI data register,                                   Address offset: 0x0C */
#define _I2S3ext_CRCPR        (I2S3ext + SPI_CRCPR_OFFSET)        /*!< SPI CRC polynomial register (not used in I2S mode),  Address offset: 0x10 */
#define _I2S3ext_RXCRCR       (I2S3ext + SPI_RXCRCR_OFFSET)       /*!< SPI Rx CRC register (not used in I2S mode),          Address offset: 0x14 */
#define _I2S3ext_TXCRCR       (I2S3ext + SPI_TXCRCR_OFFSET)       /*!< SPI Tx CRC register (not used in I2S mode),          Address offset: 0x18 */
#define _I2S3ext_I2SCFGR      (I2S3ext + SPI_I2SCFGR_OFFSET)      /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
#define _I2S3ext_I2SPR        (I2S3ext + SPI_I2SPR_OFFSET)        /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */

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

#define UART4               (UART4_BASE)
#define _UART4_CR1          (UART4 + USART_CR1_OFFSET)          /*!< USART Control register 1,                 Address offset: 0x00 */
#define _UART4_CR2          (UART4 + USART_CR2_OFFSET)          /*!< USART Control register 2,                 Address offset: 0x04 */
#define _UART4_CR3          (UART4 + USART_CR3_OFFSET)          /*!< USART Control register 3,                 Address offset: 0x08 */
#define _UART4_BRR          (UART4 + USART_BRR_OFFSET)          /*!< USART Baud rate register,                 Address offset: 0x0C */
#define _UART4_GTPR         (UART4 + USART_GTPR_OFFSET)         /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
#define _UART4_RTOR         (UART4 + USART_RTOR_OFFSET)         /*!< USART Receiver Time Out register,         Address offset: 0x14 */
#define _UART4_RQR          (UART4 + USART_RQR_OFFSET)          /*!< USART Request register,                   Address offset: 0x18 */
#define _UART4_ISR          (UART4 + USART_ISR_OFFSET)          /*!< USART Interrupt and status register,      Address offset: 0x1C */
#define _UART4_ICR          (UART4 + USART_ICR_OFFSET)          /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
#define _UART4_RDR          (UART4 + USART_RDR_OFFSET)          /*!< USART Receive Data register,              Address offset: 0x24 */
#define _UART4_TDR          (UART4 + USART_TDR_OFFSET)          /*!< USART Transmit Data register,             Address offset: 0x28 */

#define UART5               (UART5_BASE)
#define _UART5_CR1          (UART5 + USART_CR1_OFFSET)          /*!< USART Control register 1,                 Address offset: 0x00 */
#define _UART5_CR2          (UART5 + USART_CR2_OFFSET)          /*!< USART Control register 2,                 Address offset: 0x04 */
#define _UART5_CR3          (UART5 + USART_CR3_OFFSET)          /*!< USART Control register 3,                 Address offset: 0x08 */
#define _UART5_BRR          (UART5 + USART_BRR_OFFSET)          /*!< USART Baud rate register,                 Address offset: 0x0C */
#define _UART5_GTPR         (UART5 + USART_GTPR_OFFSET)         /*!< USART Guard time and prescaler register,  Address offset: 0x10 */
#define _UART5_RTOR         (UART5 + USART_RTOR_OFFSET)         /*!< USART Receiver Time Out register,         Address offset: 0x14 */
#define _UART5_RQR          (UART5 + USART_RQR_OFFSET)          /*!< USART Request register,                   Address offset: 0x18 */
#define _UART5_ISR          (UART5 + USART_ISR_OFFSET)          /*!< USART Interrupt and status register,      Address offset: 0x1C */
#define _UART5_ICR          (UART5 + USART_ICR_OFFSET)          /*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
#define _UART5_RDR          (UART5 + USART_RDR_OFFSET)          /*!< USART Receive Data register,              Address offset: 0x24 */
#define _UART5_TDR          (UART5 + USART_TDR_OFFSET)          /*!< USART Transmit Data register,             Address offset: 0x28 */

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

#define I2C3                (I2C3_BASE)
#define _I2C3_CR1         (I2C3 + I2C_CR1_OFFSET)         /*!< I2C Control register 1,            Address offset: 0x00 */
#define _I2C3_CR2         (I2C3 + I2C_CR2_OFFSET)         /*!< I2C Control register 2,            Address offset: 0x04 */
#define _I2C3_OAR1        (I2C3 + I2C_OAR1_OFFSET)        /*!< I2C Own address 1 register,        Address offset: 0x08 */
#define _I2C3_OAR2        (I2C3 + I2C_OAR2_OFFSET)        /*!< I2C Own address 2 register,        Address offset: 0x0C */
#define _I2C3_TIMINGR     (I2C3 + I2C_TIMINGR_OFFSET)     /*!< I2C Timing register,               Address offset: 0x10 */
#define _I2C3_TIMEOUTR    (I2C3 + I2C_TIMEOUTR_OFFSET)    /*!< I2C Timeout register,              Address offset: 0x14 */
#define _I2C3_ISR         (I2C3 + I2C_ISR_OFFSET)         /*!< I2C Interrupt and status register, Address offset: 0x18 */
#define _I2C3_ICR         (I2C3 + I2C_ICR_OFFSET)         /*!< I2C Interrupt clear register,      Address offset: 0x1C */
#define _I2C3_PECR        (I2C3 + I2C_PECR_OFFSET)        /*!< I2C PEC register,                  Address offset: 0x20 */
#define _I2C3_RXDR        (I2C3 + I2C_RXDR_OFFSET)        /*!< I2C Receive data register,         Address offset: 0x24 */
#define _I2C3_TXDR        (I2C3 + I2C_TXDR_OFFSET)        /*!< I2C Transmit data register,        Address offset: 0x28 */

#define CAN1                (CAN1_BASE)
#define _CAN1_MCR                (CAN1 + CAN_MCR_OFFSET)                /*!< CAN master control register,         Address offset: 0x00          */
#define _CAN1_MSR                (CAN1 + CAN_MSR_OFFSET)                /*!< CAN master status register,          Address offset: 0x04          */
#define _CAN1_TSR                (CAN1 + CAN_TSR_OFFSET)                /*!< CAN transmit status register,        Address offset: 0x08          */
#define _CAN1_RF0R               (CAN1 + CAN_RF0R_OFFSET)               /*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
#define _CAN1_RF1R               (CAN1 + CAN_RF1R_OFFSET)               /*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
#define _CAN1_IER                (CAN1 + CAN_IER_OFFSET)                /*!< CAN interrupt enable register,       Address offset: 0x14          */
#define _CAN1_ESR                (CAN1 + CAN_ESR_OFFSET)                /*!< CAN error status register,           Address offset: 0x18          */
#define _CAN1_BTR                (CAN1 + CAN_BTR_OFFSET)                /*!< CAN bit timing register,             Address offset: 0x1C          */
#define _CAN1_sTxMailBox         (CAN1 + CAN_sTxMailBox_OFFSET)         /*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
#define _CAN1_sFIFOMailBox       (CAN1 + CAN_sFIFOMailBox_OFFSET)       /*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
#define _CAN1_FMR                (CAN1 + CAN_FMR_OFFSET)                /*!< CAN filter master register,          Address offset: 0x200         */
#define _CAN1_FM1R               (CAN1 + CAN_FM1R_OFFSET)               /*!< CAN filter mode register,            Address offset: 0x204         */
#define _CAN1_FS1R               (CAN1 + CAN_FS1R_OFFSET)               /*!< CAN filter scale register,           Address offset: 0x20C         */
#define _CAN1_FFA1R              (CAN1 + CAN_FFA1R_OFFSET)              /*!< CAN filter FIFO assignment register, Address offset: 0x214         */
#define _CAN1_FA1R               (CAN1 + CAN_FA1R_OFFSET)               /*!< CAN filter activation register,      Address offset: 0x21C         */
#define _CAN1_sFilterRegister    (CAN1 + CAN_sFilterRegister_OFFSET)    /*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */

#define PWR                 (PWR_BASE)
#define _PWR_CR     (PWR + PWR_CR_OFFSET)     /*!< PWR power control register,        Address offset: 0x00 */
#define _PWR_CSR    (PWR + PWR_CSR_OFFSET)    /*!< PWR power control/status register, Address offset: 0x04 */

#define DAC1                (DAC1_BASE)
#define _DAC1_CR         (DAC1 + DAC_CR_OFFSET)         /*!< DAC control register,                                    Address offset: 0x00 */
#define _DAC1_SWTRIGR    (DAC1 + DAC_SWTRIGR_OFFSET)    /*!< DAC software trigger register,                           Address offset: 0x04 */
#define _DAC1_DHR12R1    (DAC1 + DAC_DHR12R1_OFFSET)    /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
#define _DAC1_DHR12L1    (DAC1 + DAC_DHR12L1_OFFSET)    /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
#define _DAC1_DHR8R1     (DAC1 + DAC_DHR8R1_OFFSET)     /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
#define _DAC1_DHR12R2    (DAC1 + DAC_DHR12R2_OFFSET)    /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
#define _DAC1_DHR12L2    (DAC1 + DAC_DHR12L2_OFFSET)    /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
#define _DAC1_DHR8R2     (DAC1 + DAC_DHR8R2_OFFSET)     /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
#define _DAC1_DHR12RD    (DAC1 + DAC_DHR12RD_OFFSET)    /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
#define _DAC1_DHR12LD    (DAC1 + DAC_DHR12LD_OFFSET)    /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
#define _DAC1_DHR8RD     (DAC1 + DAC_DHR8RD_OFFSET)     /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
#define _DAC1_DOR1       (DAC1 + DAC_DOR1_OFFSET)       /*!< DAC channel1 data output register,                       Address offset: 0x2C */
#define _DAC1_DOR2       (DAC1 + DAC_DOR2_OFFSET)       /*!< DAC channel2 data output register,                       Address offset: 0x30 */
#define _DAC1_SR         (DAC1 + DAC_SR_OFFSET)         /*!< DAC status register,                                     Address offset: 0x34 */

#define DAC2                (DAC2_BASE)
#define _DAC2_CR         (DAC2 + DAC_CR_OFFSET)         /*!< DAC control register,                                    Address offset: 0x00 */
#define _DAC2_SWTRIGR    (DAC2 + DAC_SWTRIGR_OFFSET)    /*!< DAC software trigger register,                           Address offset: 0x04 */
#define _DAC2_DHR12R1    (DAC2 + DAC_DHR12R1_OFFSET)    /*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
#define _DAC2_DHR12L1    (DAC2 + DAC_DHR12L1_OFFSET)    /*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
#define _DAC2_DHR8R1     (DAC2 + DAC_DHR8R1_OFFSET)     /*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
#define _DAC2_DHR12R2    (DAC2 + DAC_DHR12R2_OFFSET)    /*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
#define _DAC2_DHR12L2    (DAC2 + DAC_DHR12L2_OFFSET)    /*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
#define _DAC2_DHR8R2     (DAC2 + DAC_DHR8R2_OFFSET)     /*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
#define _DAC2_DHR12RD    (DAC2 + DAC_DHR12RD_OFFSET)    /*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
#define _DAC2_DHR12LD    (DAC2 + DAC_DHR12LD_OFFSET)    /*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
#define _DAC2_DHR8RD     (DAC2 + DAC_DHR8RD_OFFSET)     /*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
#define _DAC2_DOR1       (DAC2 + DAC_DOR1_OFFSET)       /*!< DAC channel1 data output register,                       Address offset: 0x2C */
#define _DAC2_DOR2       (DAC2 + DAC_DOR2_OFFSET)       /*!< DAC channel2 data output register,                       Address offset: 0x30 */
#define _DAC2_SR         (DAC2 + DAC_SR_OFFSET)         /*!< DAC status register,                                     Address offset: 0x34 */

#define DAC                  DAC1
#define SYSCFG              (SYSCFG_BASE)
#define _SYSCFG_CFGR1         (SYSCFG + SYSCFG_CFGR1_OFFSET)         /*!< SYSCFG configuration register 1,                   Address offset: 0x00 */
#define _SYSCFG_RCR           (SYSCFG + SYSCFG_RCR_OFFSET)           /*!< SYSCFG CCM SRAM protection register,               Address offset: 0x04 */
#define _SYSCFG_EXTICR        (SYSCFG + SYSCFG_EXTICR_OFFSET)        /*!< SYSCFG external interrupt configuration registers, Address offset: 0x14-0x08 */
#define _SYSCFG_CFGR2         (SYSCFG + SYSCFG_CFGR2_OFFSET)         /*!< SYSCFG configuration register 2,                    Address offset: 0x18 */
#define _SYSCFG_CFGR4         (SYSCFG + SYSCFG_CFGR4_OFFSET)         /*!< SYSCFG configuration register 4,                   Address offset: 0x48 */
#define _SYSCFG_CFGR3         (SYSCFG + SYSCFG_CFGR3_OFFSET)         /*!< SYSCFG configuration register 3,                   Address offset: 0x50 */

#define COMP                (COMP_BASE)
#define _COMP_CSR    (COMP + COMP_CSR_OFFSET)    /*!< Comparator control Status register, Address offset: 0x00 */

#define COMP1               (COMP1_BASE)
#define _COMP1_CSR    (COMP1 + COMP_CSR_OFFSET)    /*!< Comparator control Status register, Address offset: 0x00 */

#define COMP2               (COMP2_BASE)
#define _COMP2_CSR    (COMP2 + COMP_CSR_OFFSET)    /*!< Comparator control Status register, Address offset: 0x00 */

#define COMP3               (COMP3_BASE)
#define _COMP3_CSR    (COMP3 + COMP_CSR_OFFSET)    /*!< Comparator control Status register, Address offset: 0x00 */

#define COMP4               (COMP4_BASE)
#define _COMP4_CSR    (COMP4 + COMP_CSR_OFFSET)    /*!< Comparator control Status register, Address offset: 0x00 */

#define COMP5               (COMP5_BASE)
#define _COMP5_CSR    (COMP5 + COMP_CSR_OFFSET)    /*!< Comparator control Status register, Address offset: 0x00 */

#define COMP6               (COMP6_BASE)
#define _COMP6_CSR    (COMP6 + COMP_CSR_OFFSET)    /*!< Comparator control Status register, Address offset: 0x00 */

#define COMP7               (COMP7_BASE)
#define _COMP7_CSR    (COMP7 + COMP_CSR_OFFSET)    /*!< Comparator control Status register, Address offset: 0x00 */

#define OPAMP               (OPAMP_BASE)
#define _OPAMP_CSR    (OPAMP + OPAMP_CSR_OFFSET)    /*!< OPAMP control and status register,            Address offset: 0x00 */

#define OPAMP1              (OPAMP1_BASE)
#define _OPAMP1_CSR    (OPAMP1 + OPAMP_CSR_OFFSET)    /*!< OPAMP control and status register,            Address offset: 0x00 */

#define OPAMP2              (OPAMP2_BASE)
#define _OPAMP2_CSR    (OPAMP2 + OPAMP_CSR_OFFSET)    /*!< OPAMP control and status register,            Address offset: 0x00 */

#define OPAMP3              (OPAMP3_BASE)
#define _OPAMP3_CSR    (OPAMP3 + OPAMP_CSR_OFFSET)    /*!< OPAMP control and status register,            Address offset: 0x00 */

#define OPAMP4              (OPAMP4_BASE)
#define _OPAMP4_CSR    (OPAMP4 + OPAMP_CSR_OFFSET)    /*!< OPAMP control and status register,            Address offset: 0x00 */

#define EXTI                (EXTI_BASE)
#define _EXTI_IMR          (EXTI + EXTI_IMR_OFFSET)          /*!< EXTI Interrupt mask register,                Address offset: 0x00 */
#define _EXTI_EMR          (EXTI + EXTI_EMR_OFFSET)          /*!< EXTI Event mask register,                    Address offset: 0x04 */
#define _EXTI_RTSR         (EXTI + EXTI_RTSR_OFFSET)         /*!< EXTI Rising trigger selection register,      Address offset: 0x08 */
#define _EXTI_FTSR         (EXTI + EXTI_FTSR_OFFSET)         /*!< EXTI Falling trigger selection register,     Address offset: 0x0C */
#define _EXTI_SWIER        (EXTI + EXTI_SWIER_OFFSET)        /*!< EXTI Software interrupt event register,      Address offset: 0x10 */
#define _EXTI_PR           (EXTI + EXTI_PR_OFFSET)           /*!< EXTI Pending register,                       Address offset: 0x14 */
#define _EXTI_IMR2         (EXTI + EXTI_IMR2_OFFSET)         /*!< EXTI Interrupt mask register,                Address offset: 0x20 */
#define _EXTI_EMR2         (EXTI + EXTI_EMR2_OFFSET)         /*!< EXTI Event mask register,                    Address offset: 0x24 */
#define _EXTI_RTSR2        (EXTI + EXTI_RTSR2_OFFSET)        /*!< EXTI Rising trigger selection register,      Address offset: 0x28 */
#define _EXTI_FTSR2        (EXTI + EXTI_FTSR2_OFFSET)        /*!< EXTI Falling trigger selection register,     Address offset: 0x2C */
#define _EXTI_SWIER2       (EXTI + EXTI_SWIER2_OFFSET)       /*!< EXTI Software interrupt event register,      Address offset: 0x30 */
#define _EXTI_PR2          (EXTI + EXTI_PR2_OFFSET)          /*!< EXTI Pending register,                       Address offset: 0x34 */

#define TIM1                (TIM1_BASE)
#define _TIM1_CR1           (TIM1 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM1_CR2           (TIM1 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM1_SMCR          (TIM1 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM1_DIER          (TIM1 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM1_SR            (TIM1 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM1_EGR           (TIM1 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM1_CCMR1         (TIM1 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM1_CCMR2         (TIM1 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM1_CCER          (TIM1 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM1_CNT           (TIM1 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM1_PSC           (TIM1 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM1_ARR           (TIM1 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM1_RCR           (TIM1 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM1_CCR1          (TIM1 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM1_CCR2          (TIM1 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM1_CCR3          (TIM1 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM1_CCR4          (TIM1 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM1_BDTR          (TIM1 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM1_DCR           (TIM1 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM1_DMAR          (TIM1 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM1_OR            (TIM1 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM1_CCMR3         (TIM1 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM1_CCR5          (TIM1 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM1_CCR6          (TIM1 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

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

#define TIM8                (TIM8_BASE)
#define _TIM8_CR1           (TIM8 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM8_CR2           (TIM8 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM8_SMCR          (TIM8 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM8_DIER          (TIM8 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM8_SR            (TIM8 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM8_EGR           (TIM8 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM8_CCMR1         (TIM8 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM8_CCMR2         (TIM8 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM8_CCER          (TIM8 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM8_CNT           (TIM8 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM8_PSC           (TIM8 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM8_ARR           (TIM8 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM8_RCR           (TIM8 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM8_CCR1          (TIM8 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM8_CCR2          (TIM8 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM8_CCR3          (TIM8 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM8_CCR4          (TIM8 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM8_BDTR          (TIM8 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM8_DCR           (TIM8 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM8_DMAR          (TIM8 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM8_OR            (TIM8 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM8_CCMR3         (TIM8 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM8_CCR5          (TIM8 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM8_CCR6          (TIM8 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

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

#define SPI4                (SPI4_BASE)
#define _SPI4_CR1          (SPI4 + SPI_CR1_OFFSET)          /*!< SPI Control register 1 (not used in I2S mode),       Address offset: 0x00 */
#define _SPI4_CR2          (SPI4 + SPI_CR2_OFFSET)          /*!< SPI Control register 2,                              Address offset: 0x04 */
#define _SPI4_SR           (SPI4 + SPI_SR_OFFSET)           /*!< SPI Status register,                                 Address offset: 0x08 */
#define _SPI4_DR           (SPI4 + SPI_DR_OFFSET)           /*!< SPI data register,                                   Address offset: 0x0C */
#define _SPI4_CRCPR        (SPI4 + SPI_CRCPR_OFFSET)        /*!< SPI CRC polynomial register (not used in I2S mode),  Address offset: 0x10 */
#define _SPI4_RXCRCR       (SPI4 + SPI_RXCRCR_OFFSET)       /*!< SPI Rx CRC register (not used in I2S mode),          Address offset: 0x14 */
#define _SPI4_TXCRCR       (SPI4 + SPI_TXCRCR_OFFSET)       /*!< SPI Tx CRC register (not used in I2S mode),          Address offset: 0x18 */
#define _SPI4_I2SCFGR      (SPI4 + SPI_I2SCFGR_OFFSET)      /*!< SPI_I2S configuration register,                      Address offset: 0x1C */
#define _SPI4_I2SPR        (SPI4 + SPI_I2SPR_OFFSET)        /*!< SPI_I2S prescaler register,                          Address offset: 0x20 */

#define TIM15               (TIM15_BASE)
#define _TIM15_CR1           (TIM15 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM15_CR2           (TIM15 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM15_SMCR          (TIM15 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM15_DIER          (TIM15 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM15_SR            (TIM15 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM15_EGR           (TIM15 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM15_CCMR1         (TIM15 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM15_CCMR2         (TIM15 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM15_CCER          (TIM15 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM15_CNT           (TIM15 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM15_PSC           (TIM15 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM15_ARR           (TIM15 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM15_RCR           (TIM15 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM15_CCR1          (TIM15 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM15_CCR2          (TIM15 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM15_CCR3          (TIM15 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM15_CCR4          (TIM15 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM15_BDTR          (TIM15 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM15_DCR           (TIM15 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM15_DMAR          (TIM15 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM15_OR            (TIM15 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM15_CCMR3         (TIM15 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM15_CCR5          (TIM15 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM15_CCR6          (TIM15 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

#define TIM16               (TIM16_BASE)
#define _TIM16_CR1           (TIM16 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM16_CR2           (TIM16 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM16_SMCR          (TIM16 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM16_DIER          (TIM16 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM16_SR            (TIM16 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM16_EGR           (TIM16 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM16_CCMR1         (TIM16 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM16_CCMR2         (TIM16 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM16_CCER          (TIM16 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM16_CNT           (TIM16 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM16_PSC           (TIM16 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM16_ARR           (TIM16 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM16_RCR           (TIM16 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM16_CCR1          (TIM16 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM16_CCR2          (TIM16 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM16_CCR3          (TIM16 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM16_CCR4          (TIM16 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM16_BDTR          (TIM16 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM16_DCR           (TIM16 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM16_DMAR          (TIM16 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM16_OR            (TIM16 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM16_CCMR3         (TIM16 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM16_CCR5          (TIM16 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM16_CCR6          (TIM16 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

#define TIM17               (TIM17_BASE)
#define _TIM17_CR1           (TIM17 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM17_CR2           (TIM17 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM17_SMCR          (TIM17 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM17_DIER          (TIM17 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM17_SR            (TIM17 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM17_EGR           (TIM17 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM17_CCMR1         (TIM17 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM17_CCMR2         (TIM17 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM17_CCER          (TIM17 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM17_CNT           (TIM17 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM17_PSC           (TIM17 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM17_ARR           (TIM17 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM17_RCR           (TIM17 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM17_CCR1          (TIM17 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM17_CCR2          (TIM17 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM17_CCR3          (TIM17 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM17_CCR4          (TIM17 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM17_BDTR          (TIM17 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM17_DCR           (TIM17 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM17_DMAR          (TIM17 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM17_OR            (TIM17 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM17_CCMR3         (TIM17 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM17_CCR5          (TIM17 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM17_CCR6          (TIM17 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

#define TIM20               (TIM20_BASE)
#define _TIM20_CR1           (TIM20 + TIM_CR1_OFFSET)           /*!< TIM control register 1,              Address offset: 0x00 */
#define _TIM20_CR2           (TIM20 + TIM_CR2_OFFSET)           /*!< TIM control register 2,              Address offset: 0x04 */
#define _TIM20_SMCR          (TIM20 + TIM_SMCR_OFFSET)          /*!< TIM slave mode control register,     Address offset: 0x08 */
#define _TIM20_DIER          (TIM20 + TIM_DIER_OFFSET)          /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
#define _TIM20_SR            (TIM20 + TIM_SR_OFFSET)            /*!< TIM status register,                 Address offset: 0x10 */
#define _TIM20_EGR           (TIM20 + TIM_EGR_OFFSET)           /*!< TIM event generation register,       Address offset: 0x14 */
#define _TIM20_CCMR1         (TIM20 + TIM_CCMR1_OFFSET)         /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
#define _TIM20_CCMR2         (TIM20 + TIM_CCMR2_OFFSET)         /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
#define _TIM20_CCER          (TIM20 + TIM_CCER_OFFSET)          /*!< TIM capture/compare enable register, Address offset: 0x20 */
#define _TIM20_CNT           (TIM20 + TIM_CNT_OFFSET)           /*!< TIM counter register,                Address offset: 0x24 */
#define _TIM20_PSC           (TIM20 + TIM_PSC_OFFSET)           /*!< TIM prescaler,                       Address offset: 0x28 */
#define _TIM20_ARR           (TIM20 + TIM_ARR_OFFSET)           /*!< TIM auto-reload register,            Address offset: 0x2C */
#define _TIM20_RCR           (TIM20 + TIM_RCR_OFFSET)           /*!< TIM repetition counter register,     Address offset: 0x30 */
#define _TIM20_CCR1          (TIM20 + TIM_CCR1_OFFSET)          /*!< TIM capture/compare register 1,      Address offset: 0x34 */
#define _TIM20_CCR2          (TIM20 + TIM_CCR2_OFFSET)          /*!< TIM capture/compare register 2,      Address offset: 0x38 */
#define _TIM20_CCR3          (TIM20 + TIM_CCR3_OFFSET)          /*!< TIM capture/compare register 3,      Address offset: 0x3C */
#define _TIM20_CCR4          (TIM20 + TIM_CCR4_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x40 */
#define _TIM20_BDTR          (TIM20 + TIM_BDTR_OFFSET)          /*!< TIM break and dead-time register,    Address offset: 0x44 */
#define _TIM20_DCR           (TIM20 + TIM_DCR_OFFSET)           /*!< TIM DMA control register,            Address offset: 0x48 */
#define _TIM20_DMAR          (TIM20 + TIM_DMAR_OFFSET)          /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
#define _TIM20_OR            (TIM20 + TIM_OR_OFFSET)            /*!< TIM option register,                 Address offset: 0x50 */
#define _TIM20_CCMR3         (TIM20 + TIM_CCMR3_OFFSET)         /*!< TIM capture/compare mode register 3, Address offset: 0x54 */
#define _TIM20_CCR5          (TIM20 + TIM_CCR5_OFFSET)          /*!< TIM capture/compare register5,      Address offset: 0x58 */
#define _TIM20_CCR6          (TIM20 + TIM_CCR6_OFFSET)          /*!< TIM capture/compare register 4,      Address offset: 0x5C */

#define HRTIM1              (HRTIM1_BASE)
#define _HRTIM1_HRTIM_MASTER    (HRTIM1 + HRTIM_HRTIM_MASTER_OFFSET)    
#define _HRTIM1_HRTIM_TIMERx    (HRTIM1 + HRTIM_HRTIM_TIMERx_OFFSET)    
#define _HRTIM1_HRTIM_COMMON    (HRTIM1 + HRTIM_HRTIM_COMMON_OFFSET)    

#define HRTIM1_TIMA         (HRTIM1_TIMA_BASE)
#define HRTIM1_TIMB         (HRTIM1_TIMB_BASE)
#define HRTIM1_TIMC         (HRTIM1_TIMC_BASE)
#define HRTIM1_TIMD         (HRTIM1_TIMD_BASE)
#define HRTIM1_TIME         (HRTIM1_TIME_BASE)
#define HRTIM1_COMMON       (HRTIM1_COMMON_BASE)
#define _HRTIM1_COMMON_CR1         (HRTIM1_COMMON + HRTIM_Common_CR1_OFFSET)         /*!< HRTIM control register1,                                    Address offset: 0x00 */
#define _HRTIM1_COMMON_CR2         (HRTIM1_COMMON + HRTIM_Common_CR2_OFFSET)         /*!< HRTIM control register2,                                    Address offset: 0x04 */
#define _HRTIM1_COMMON_ISR         (HRTIM1_COMMON + HRTIM_Common_ISR_OFFSET)         /*!< HRTIM interrupt status register,                            Address offset: 0x08 */
#define _HRTIM1_COMMON_ICR         (HRTIM1_COMMON + HRTIM_Common_ICR_OFFSET)         /*!< HRTIM interrupt clear register,                             Address offset: 0x0C */
#define _HRTIM1_COMMON_IER         (HRTIM1_COMMON + HRTIM_Common_IER_OFFSET)         /*!< HRTIM interrupt enable register,                            Address offset: 0x10 */
#define _HRTIM1_COMMON_OENR        (HRTIM1_COMMON + HRTIM_Common_OENR_OFFSET)        /*!< HRTIM Output enable register,                               Address offset: 0x14 */
#define _HRTIM1_COMMON_DISR        (HRTIM1_COMMON + HRTIM_Common_DISR_OFFSET)        /*!< HRTIM Output disable register,                              Address offset: 0x18 */
#define _HRTIM1_COMMON_ODSR        (HRTIM1_COMMON + HRTIM_Common_ODSR_OFFSET)        /*!< HRTIM Output disable status register,                       Address offset: 0x1C */
#define _HRTIM1_COMMON_BMCR        (HRTIM1_COMMON + HRTIM_Common_BMCR_OFFSET)        /*!< HRTIM Burst mode control register,                          Address offset: 0x20 */
#define _HRTIM1_COMMON_BMTRGR      (HRTIM1_COMMON + HRTIM_Common_BMTRGR_OFFSET)      /*!< HRTIM Busrt mode trigger register,                          Address offset: 0x24 */
#define _HRTIM1_COMMON_BMCMPR      (HRTIM1_COMMON + HRTIM_Common_BMCMPR_OFFSET)      /*!< HRTIM Burst mode compare register,                          Address offset: 0x28 */
#define _HRTIM1_COMMON_BMPER       (HRTIM1_COMMON + HRTIM_Common_BMPER_OFFSET)       /*!< HRTIM Burst mode period register,                           Address offset: 0x2C */
#define _HRTIM1_COMMON_EECR1       (HRTIM1_COMMON + HRTIM_Common_EECR1_OFFSET)       /*!< HRTIM Timer external event control register1,               Address offset: 0x30 */
#define _HRTIM1_COMMON_EECR2       (HRTIM1_COMMON + HRTIM_Common_EECR2_OFFSET)       /*!< HRTIM Timer external event control register2,               Address offset: 0x34 */
#define _HRTIM1_COMMON_EECR3       (HRTIM1_COMMON + HRTIM_Common_EECR3_OFFSET)       /*!< HRTIM Timer external event control register3,               Address offset: 0x38 */
#define _HRTIM1_COMMON_ADC1R       (HRTIM1_COMMON + HRTIM_Common_ADC1R_OFFSET)       /*!< HRTIM ADC Trigger 1 register,                               Address offset: 0x3C */
#define _HRTIM1_COMMON_ADC2R       (HRTIM1_COMMON + HRTIM_Common_ADC2R_OFFSET)       /*!< HRTIM ADC Trigger 2 register,                               Address offset: 0x40 */
#define _HRTIM1_COMMON_ADC3R       (HRTIM1_COMMON + HRTIM_Common_ADC3R_OFFSET)       /*!< HRTIM ADC Trigger 3 register,                               Address offset: 0x44 */
#define _HRTIM1_COMMON_ADC4R       (HRTIM1_COMMON + HRTIM_Common_ADC4R_OFFSET)       /*!< HRTIM ADC Trigger 4 register,                               Address offset: 0x48 */
#define _HRTIM1_COMMON_DLLCR       (HRTIM1_COMMON + HRTIM_Common_DLLCR_OFFSET)       /*!< HRTIM DLL control register,                                 Address offset: 0x4C */
#define _HRTIM1_COMMON_FLTINxR1    (HRTIM1_COMMON + HRTIM_Common_FLTINxR1_OFFSET)    /*!< HRTIM Fault input register1,                                Address offset: 0x50 */
#define _HRTIM1_COMMON_FLTINxR2    (HRTIM1_COMMON + HRTIM_Common_FLTINxR2_OFFSET)    /*!< HRTIM Fault input register2,                                Address offset: 0x54 */
#define _HRTIM1_COMMON_BDMUPDR     (HRTIM1_COMMON + HRTIM_Common_BDMUPDR_OFFSET)     /*!< HRTIM Burst DMA Master Timer update register,               Address offset: 0x58 */
#define _HRTIM1_COMMON_BDTAUPR     (HRTIM1_COMMON + HRTIM_Common_BDTAUPR_OFFSET)     /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x5C */
#define _HRTIM1_COMMON_BDTBUPR     (HRTIM1_COMMON + HRTIM_Common_BDTBUPR_OFFSET)     /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x60 */
#define _HRTIM1_COMMON_BDTCUPR     (HRTIM1_COMMON + HRTIM_Common_BDTCUPR_OFFSET)     /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x64 */
#define _HRTIM1_COMMON_BDTDUPR     (HRTIM1_COMMON + HRTIM_Common_BDTDUPR_OFFSET)     /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x68 */
#define _HRTIM1_COMMON_BDTEUPR     (HRTIM1_COMMON + HRTIM_Common_BDTEUPR_OFFSET)     /*!< HRTIM Burst DMA Timerx update register,                     Address offset: 0x6C */
#define _HRTIM1_COMMON_BDMADR      (HRTIM1_COMMON + HRTIM_Common_BDMADR_OFFSET)      /*!< HRTIM Burst DMA Master Data register,                       Address offset: 0x70 */

#define DBGMCU              (DBGMCU_BASE)
#define _DBGMCU_IDCODE    (DBGMCU + DBGMCU_IDCODE_OFFSET)    /*!< MCU device ID code,               Address offset: 0x00 */
#define _DBGMCU_CR        (DBGMCU + DBGMCU_CR_OFFSET)        /*!< Debug MCU configuration register, Address offset: 0x04 */
#define _DBGMCU_APB1FZ    (DBGMCU + DBGMCU_APB1FZ_OFFSET)    /*!< Debug MCU APB1 freeze register,   Address offset: 0x08 */
#define _DBGMCU_APB2FZ    (DBGMCU + DBGMCU_APB2FZ_OFFSET)    /*!< Debug MCU APB2 freeze register,   Address offset: 0x0C */

#define DMA1                (DMA1_BASE)
#define _DMA1_ISR     (DMA1 + DMA_ISR_OFFSET)     /*!< DMA interrupt status register,      Address offset: 0x00 */
#define _DMA1_IFCR    (DMA1 + DMA_IFCR_OFFSET)    /*!< DMA interrupt clear flag register,  Address offset: 0x04 */

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

#define DMA2                (DMA2_BASE)
#define _DMA2_ISR     (DMA2 + DMA_ISR_OFFSET)     /*!< DMA interrupt status register,      Address offset: 0x00 */
#define _DMA2_IFCR    (DMA2 + DMA_IFCR_OFFSET)    /*!< DMA interrupt clear flag register,  Address offset: 0x04 */

#define DMA2_Channel1       (DMA2_Channel1_BASE)
#define _DMA2_Channel1_CCR      (DMA2_Channel1 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA2_Channel1_CNDTR    (DMA2_Channel1 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA2_Channel1_CPAR     (DMA2_Channel1 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA2_Channel1_CMAR     (DMA2_Channel1 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA2_Channel2       (DMA2_Channel2_BASE)
#define _DMA2_Channel2_CCR      (DMA2_Channel2 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA2_Channel2_CNDTR    (DMA2_Channel2 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA2_Channel2_CPAR     (DMA2_Channel2 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA2_Channel2_CMAR     (DMA2_Channel2 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA2_Channel3       (DMA2_Channel3_BASE)
#define _DMA2_Channel3_CCR      (DMA2_Channel3 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA2_Channel3_CNDTR    (DMA2_Channel3 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA2_Channel3_CPAR     (DMA2_Channel3 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA2_Channel3_CMAR     (DMA2_Channel3 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA2_Channel4       (DMA2_Channel4_BASE)
#define _DMA2_Channel4_CCR      (DMA2_Channel4 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA2_Channel4_CNDTR    (DMA2_Channel4 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA2_Channel4_CPAR     (DMA2_Channel4 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA2_Channel4_CMAR     (DMA2_Channel4 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

#define DMA2_Channel5       (DMA2_Channel5_BASE)
#define _DMA2_Channel5_CCR      (DMA2_Channel5 + DMA_Channel_CCR_OFFSET)      /*!< DMA channel x configuration register                                           */
#define _DMA2_Channel5_CNDTR    (DMA2_Channel5 + DMA_Channel_CNDTR_OFFSET)    /*!< DMA channel x number of data register                                          */
#define _DMA2_Channel5_CPAR     (DMA2_Channel5 + DMA_Channel_CPAR_OFFSET)     /*!< DMA channel x peripheral address register                                      */
#define _DMA2_Channel5_CMAR     (DMA2_Channel5 + DMA_Channel_CMAR_OFFSET)     /*!< DMA channel x memory address register                                          */

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

#define FLASH               (FLASH_R_BASE)
#define _FLASH_ACR         (FLASH + FLASH_ACR_OFFSET)         /*!< FLASH access control register,              Address offset: 0x00 */
#define _FLASH_KEYR        (FLASH + FLASH_KEYR_OFFSET)        /*!< FLASH key register,                         Address offset: 0x04 */
#define _FLASH_OPTKEYR     (FLASH + FLASH_OPTKEYR_OFFSET)     /*!< FLASH option key register,                  Address offset: 0x08 */
#define _FLASH_SR          (FLASH + FLASH_SR_OFFSET)          /*!< FLASH status register,                      Address offset: 0x0C */
#define _FLASH_CR          (FLASH + FLASH_CR_OFFSET)          /*!< FLASH control register,                     Address offset: 0x10 */
#define _FLASH_AR          (FLASH + FLASH_AR_OFFSET)          /*!< FLASH address register,                     Address offset: 0x14 */
#define _FLASH_OBR         (FLASH + FLASH_OBR_OFFSET)         /*!< FLASH Option byte register,                 Address offset: 0x1C */
#define _FLASH_WRPR        (FLASH + FLASH_WRPR_OFFSET)        /*!< FLASH Write register,                       Address offset: 0x20 */

#define OB                  (OB_BASE)
#define _OB_RDP          (OB + OB_RDP_OFFSET)          /*!<FLASH option byte Read protection,             Address offset: 0x00 */
#define _OB_USER         (OB + OB_USER_OFFSET)         /*!<FLASH option byte user options,                Address offset: 0x02 */
#define _OB_WRP0         (OB + OB_WRP0_OFFSET)         /*!<FLASH option byte write protection 0,          Address offset: 0x08 */
#define _OB_WRP1         (OB + OB_WRP1_OFFSET)         /*!<FLASH option byte write protection 1,          Address offset: 0x0C */
#define _OB_WRP2         (OB + OB_WRP2_OFFSET)         /*!<FLASH option byte write protection 2,          Address offset: 0x10 */
#define _OB_WRP3         (OB + OB_WRP3_OFFSET)         /*!<FLASH option byte write protection 3,          Address offset: 0x12 */

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

#define GPIOG               (GPIOG_BASE)
#define _GPIOG_MODER        (GPIOG + GPIO_MODER_OFFSET)        /*!< GPIO port mode register,                                  Address offset: 0x00 */
#define _GPIOG_OTYPER       (GPIOG + GPIO_OTYPER_OFFSET)       /*!< GPIO port output type register,                           Address offset: 0x04 */
#define _GPIOG_OSPEEDR      (GPIOG + GPIO_OSPEEDR_OFFSET)      /*!< GPIO port output speed register,                          Address offset: 0x08 */
#define _GPIOG_PUPDR        (GPIOG + GPIO_PUPDR_OFFSET)        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
#define _GPIOG_IDR          (GPIOG + GPIO_IDR_OFFSET)          /*!< GPIO port input data register,                            Address offset: 0x10 */
#define _GPIOG_ODR          (GPIOG + GPIO_ODR_OFFSET)          /*!< GPIO port output data register,                           Address offset: 0x14 */
#define _GPIOG_BSRR         (GPIOG + GPIO_BSRR_OFFSET)         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
#define _GPIOG_LCKR         (GPIOG + GPIO_LCKR_OFFSET)         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
#define _GPIOG_AFR          (GPIOG + GPIO_AFR_OFFSET)          /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
#define _GPIOG_BRR          (GPIOG + GPIO_BRR_OFFSET)          /*!< GPIO bit reset register,                                  Address offset: 0x28 */

#define GPIOH               (GPIOH_BASE)
#define _GPIOH_MODER        (GPIOH + GPIO_MODER_OFFSET)        /*!< GPIO port mode register,                                  Address offset: 0x00 */
#define _GPIOH_OTYPER       (GPIOH + GPIO_OTYPER_OFFSET)       /*!< GPIO port output type register,                           Address offset: 0x04 */
#define _GPIOH_OSPEEDR      (GPIOH + GPIO_OSPEEDR_OFFSET)      /*!< GPIO port output speed register,                          Address offset: 0x08 */
#define _GPIOH_PUPDR        (GPIOH + GPIO_PUPDR_OFFSET)        /*!< GPIO port pull-up/pull-down register,                     Address offset: 0x0C */
#define _GPIOH_IDR          (GPIOH + GPIO_IDR_OFFSET)          /*!< GPIO port input data register,                            Address offset: 0x10 */
#define _GPIOH_ODR          (GPIOH + GPIO_ODR_OFFSET)          /*!< GPIO port output data register,                           Address offset: 0x14 */
#define _GPIOH_BSRR         (GPIOH + GPIO_BSRR_OFFSET)         /*!< GPIO port bit set/reset registerBSRR,                     Address offset: 0x18 */
#define _GPIOH_LCKR         (GPIOH + GPIO_LCKR_OFFSET)         /*!< GPIO port configuration lock register,                    Address offset: 0x1C */
#define _GPIOH_AFR          (GPIOH + GPIO_AFR_OFFSET)          /*!< GPIO alternate function low register,                Address offset: 0x20-0x24 */
#define _GPIOH_BRR          (GPIOH + GPIO_BRR_OFFSET)          /*!< GPIO bit reset register,                                  Address offset: 0x28 */

#define ADC1                (ADC1_BASE)
#define _ADC1_ISR          (ADC1 + ADC_ISR_OFFSET)          /*!< ADC Interrupt and Status Register,                 Address offset: 0x00 */
#define _ADC1_IER          (ADC1 + ADC_IER_OFFSET)          /*!< ADC Interrupt Enable Register,                     Address offset: 0x04 */
#define _ADC1_CR           (ADC1 + ADC_CR_OFFSET)           /*!< ADC control register,                              Address offset: 0x08 */
#define _ADC1_CFGR         (ADC1 + ADC_CFGR_OFFSET)         /*!< ADC Configuration register,                        Address offset: 0x0C */
#define _ADC1_SMPR1        (ADC1 + ADC_SMPR1_OFFSET)        /*!< ADC sample time register 1,                        Address offset: 0x14 */
#define _ADC1_SMPR2        (ADC1 + ADC_SMPR2_OFFSET)        /*!< ADC sample time register 2,                        Address offset: 0x18 */
#define _ADC1_TR1          (ADC1 + ADC_TR1_OFFSET)          /*!< ADC watchdog threshold register 1,                 Address offset: 0x20 */
#define _ADC1_TR2          (ADC1 + ADC_TR2_OFFSET)          /*!< ADC watchdog threshold register 2,                 Address offset: 0x24 */
#define _ADC1_TR3          (ADC1 + ADC_TR3_OFFSET)          /*!< ADC watchdog threshold register 3,                 Address offset: 0x28 */
#define _ADC1_SQR1         (ADC1 + ADC_SQR1_OFFSET)         /*!< ADC regular sequence register 1,                   Address offset: 0x30 */
#define _ADC1_SQR2         (ADC1 + ADC_SQR2_OFFSET)         /*!< ADC regular sequence register 2,                   Address offset: 0x34 */
#define _ADC1_SQR3         (ADC1 + ADC_SQR3_OFFSET)         /*!< ADC regular sequence register 3,                   Address offset: 0x38 */
#define _ADC1_SQR4         (ADC1 + ADC_SQR4_OFFSET)         /*!< ADC regular sequence register 4,                   Address offset: 0x3C */
#define _ADC1_DR           (ADC1 + ADC_DR_OFFSET)           /*!< ADC regular data register,                         Address offset: 0x40 */
#define _ADC1_JSQR         (ADC1 + ADC_JSQR_OFFSET)         /*!< ADC injected sequence register,                    Address offset: 0x4C */
#define _ADC1_OFR1         (ADC1 + ADC_OFR1_OFFSET)         /*!< ADC offset register 1,                             Address offset: 0x60 */
#define _ADC1_OFR2         (ADC1 + ADC_OFR2_OFFSET)         /*!< ADC offset register 2,                             Address offset: 0x64 */
#define _ADC1_OFR3         (ADC1 + ADC_OFR3_OFFSET)         /*!< ADC offset register 3,                             Address offset: 0x68 */
#define _ADC1_OFR4         (ADC1 + ADC_OFR4_OFFSET)         /*!< ADC offset register 4,                             Address offset: 0x6C */
#define _ADC1_JDR1         (ADC1 + ADC_JDR1_OFFSET)         /*!< ADC injected data register 1,                      Address offset: 0x80 */
#define _ADC1_JDR2         (ADC1 + ADC_JDR2_OFFSET)         /*!< ADC injected data register 2,                      Address offset: 0x84 */
#define _ADC1_JDR3         (ADC1 + ADC_JDR3_OFFSET)         /*!< ADC injected data register 3,                      Address offset: 0x88 */
#define _ADC1_JDR4         (ADC1 + ADC_JDR4_OFFSET)         /*!< ADC injected data register 4,                      Address offset: 0x8C */
#define _ADC1_AWD2CR       (ADC1 + ADC_AWD2CR_OFFSET)       /*!< ADC  Analog Watchdog 2 Configuration Register,     Address offset: 0xA0 */
#define _ADC1_AWD3CR       (ADC1 + ADC_AWD3CR_OFFSET)       /*!< ADC  Analog Watchdog 3 Configuration Register,     Address offset: 0xA4 */
#define _ADC1_DIFSEL       (ADC1 + ADC_DIFSEL_OFFSET)       /*!< ADC  Differential Mode Selection Register,         Address offset: 0xB0 */
#define _ADC1_CALFACT      (ADC1 + ADC_CALFACT_OFFSET)      /*!< ADC  Calibration Factors,                          Address offset: 0xB4 */

#define ADC2                (ADC2_BASE)
#define _ADC2_ISR          (ADC2 + ADC_ISR_OFFSET)          /*!< ADC Interrupt and Status Register,                 Address offset: 0x00 */
#define _ADC2_IER          (ADC2 + ADC_IER_OFFSET)          /*!< ADC Interrupt Enable Register,                     Address offset: 0x04 */
#define _ADC2_CR           (ADC2 + ADC_CR_OFFSET)           /*!< ADC control register,                              Address offset: 0x08 */
#define _ADC2_CFGR         (ADC2 + ADC_CFGR_OFFSET)         /*!< ADC Configuration register,                        Address offset: 0x0C */
#define _ADC2_SMPR1        (ADC2 + ADC_SMPR1_OFFSET)        /*!< ADC sample time register 1,                        Address offset: 0x14 */
#define _ADC2_SMPR2        (ADC2 + ADC_SMPR2_OFFSET)        /*!< ADC sample time register 2,                        Address offset: 0x18 */
#define _ADC2_TR1          (ADC2 + ADC_TR1_OFFSET)          /*!< ADC watchdog threshold register 1,                 Address offset: 0x20 */
#define _ADC2_TR2          (ADC2 + ADC_TR2_OFFSET)          /*!< ADC watchdog threshold register 2,                 Address offset: 0x24 */
#define _ADC2_TR3          (ADC2 + ADC_TR3_OFFSET)          /*!< ADC watchdog threshold register 3,                 Address offset: 0x28 */
#define _ADC2_SQR1         (ADC2 + ADC_SQR1_OFFSET)         /*!< ADC regular sequence register 1,                   Address offset: 0x30 */
#define _ADC2_SQR2         (ADC2 + ADC_SQR2_OFFSET)         /*!< ADC regular sequence register 2,                   Address offset: 0x34 */
#define _ADC2_SQR3         (ADC2 + ADC_SQR3_OFFSET)         /*!< ADC regular sequence register 3,                   Address offset: 0x38 */
#define _ADC2_SQR4         (ADC2 + ADC_SQR4_OFFSET)         /*!< ADC regular sequence register 4,                   Address offset: 0x3C */
#define _ADC2_DR           (ADC2 + ADC_DR_OFFSET)           /*!< ADC regular data register,                         Address offset: 0x40 */
#define _ADC2_JSQR         (ADC2 + ADC_JSQR_OFFSET)         /*!< ADC injected sequence register,                    Address offset: 0x4C */
#define _ADC2_OFR1         (ADC2 + ADC_OFR1_OFFSET)         /*!< ADC offset register 1,                             Address offset: 0x60 */
#define _ADC2_OFR2         (ADC2 + ADC_OFR2_OFFSET)         /*!< ADC offset register 2,                             Address offset: 0x64 */
#define _ADC2_OFR3         (ADC2 + ADC_OFR3_OFFSET)         /*!< ADC offset register 3,                             Address offset: 0x68 */
#define _ADC2_OFR4         (ADC2 + ADC_OFR4_OFFSET)         /*!< ADC offset register 4,                             Address offset: 0x6C */
#define _ADC2_JDR1         (ADC2 + ADC_JDR1_OFFSET)         /*!< ADC injected data register 1,                      Address offset: 0x80 */
#define _ADC2_JDR2         (ADC2 + ADC_JDR2_OFFSET)         /*!< ADC injected data register 2,                      Address offset: 0x84 */
#define _ADC2_JDR3         (ADC2 + ADC_JDR3_OFFSET)         /*!< ADC injected data register 3,                      Address offset: 0x88 */
#define _ADC2_JDR4         (ADC2 + ADC_JDR4_OFFSET)         /*!< ADC injected data register 4,                      Address offset: 0x8C */
#define _ADC2_AWD2CR       (ADC2 + ADC_AWD2CR_OFFSET)       /*!< ADC  Analog Watchdog 2 Configuration Register,     Address offset: 0xA0 */
#define _ADC2_AWD3CR       (ADC2 + ADC_AWD3CR_OFFSET)       /*!< ADC  Analog Watchdog 3 Configuration Register,     Address offset: 0xA4 */
#define _ADC2_DIFSEL       (ADC2 + ADC_DIFSEL_OFFSET)       /*!< ADC  Differential Mode Selection Register,         Address offset: 0xB0 */
#define _ADC2_CALFACT      (ADC2 + ADC_CALFACT_OFFSET)      /*!< ADC  Calibration Factors,                          Address offset: 0xB4 */

#define ADC3                (ADC3_BASE)
#define _ADC3_ISR          (ADC3 + ADC_ISR_OFFSET)          /*!< ADC Interrupt and Status Register,                 Address offset: 0x00 */
#define _ADC3_IER          (ADC3 + ADC_IER_OFFSET)          /*!< ADC Interrupt Enable Register,                     Address offset: 0x04 */
#define _ADC3_CR           (ADC3 + ADC_CR_OFFSET)           /*!< ADC control register,                              Address offset: 0x08 */
#define _ADC3_CFGR         (ADC3 + ADC_CFGR_OFFSET)         /*!< ADC Configuration register,                        Address offset: 0x0C */
#define _ADC3_SMPR1        (ADC3 + ADC_SMPR1_OFFSET)        /*!< ADC sample time register 1,                        Address offset: 0x14 */
#define _ADC3_SMPR2        (ADC3 + ADC_SMPR2_OFFSET)        /*!< ADC sample time register 2,                        Address offset: 0x18 */
#define _ADC3_TR1          (ADC3 + ADC_TR1_OFFSET)          /*!< ADC watchdog threshold register 1,                 Address offset: 0x20 */
#define _ADC3_TR2          (ADC3 + ADC_TR2_OFFSET)          /*!< ADC watchdog threshold register 2,                 Address offset: 0x24 */
#define _ADC3_TR3          (ADC3 + ADC_TR3_OFFSET)          /*!< ADC watchdog threshold register 3,                 Address offset: 0x28 */
#define _ADC3_SQR1         (ADC3 + ADC_SQR1_OFFSET)         /*!< ADC regular sequence register 1,                   Address offset: 0x30 */
#define _ADC3_SQR2         (ADC3 + ADC_SQR2_OFFSET)         /*!< ADC regular sequence register 2,                   Address offset: 0x34 */
#define _ADC3_SQR3         (ADC3 + ADC_SQR3_OFFSET)         /*!< ADC regular sequence register 3,                   Address offset: 0x38 */
#define _ADC3_SQR4         (ADC3 + ADC_SQR4_OFFSET)         /*!< ADC regular sequence register 4,                   Address offset: 0x3C */
#define _ADC3_DR           (ADC3 + ADC_DR_OFFSET)           /*!< ADC regular data register,                         Address offset: 0x40 */
#define _ADC3_JSQR         (ADC3 + ADC_JSQR_OFFSET)         /*!< ADC injected sequence register,                    Address offset: 0x4C */
#define _ADC3_OFR1         (ADC3 + ADC_OFR1_OFFSET)         /*!< ADC offset register 1,                             Address offset: 0x60 */
#define _ADC3_OFR2         (ADC3 + ADC_OFR2_OFFSET)         /*!< ADC offset register 2,                             Address offset: 0x64 */
#define _ADC3_OFR3         (ADC3 + ADC_OFR3_OFFSET)         /*!< ADC offset register 3,                             Address offset: 0x68 */
#define _ADC3_OFR4         (ADC3 + ADC_OFR4_OFFSET)         /*!< ADC offset register 4,                             Address offset: 0x6C */
#define _ADC3_JDR1         (ADC3 + ADC_JDR1_OFFSET)         /*!< ADC injected data register 1,                      Address offset: 0x80 */
#define _ADC3_JDR2         (ADC3 + ADC_JDR2_OFFSET)         /*!< ADC injected data register 2,                      Address offset: 0x84 */
#define _ADC3_JDR3         (ADC3 + ADC_JDR3_OFFSET)         /*!< ADC injected data register 3,                      Address offset: 0x88 */
#define _ADC3_JDR4         (ADC3 + ADC_JDR4_OFFSET)         /*!< ADC injected data register 4,                      Address offset: 0x8C */
#define _ADC3_AWD2CR       (ADC3 + ADC_AWD2CR_OFFSET)       /*!< ADC  Analog Watchdog 2 Configuration Register,     Address offset: 0xA0 */
#define _ADC3_AWD3CR       (ADC3 + ADC_AWD3CR_OFFSET)       /*!< ADC  Analog Watchdog 3 Configuration Register,     Address offset: 0xA4 */
#define _ADC3_DIFSEL       (ADC3 + ADC_DIFSEL_OFFSET)       /*!< ADC  Differential Mode Selection Register,         Address offset: 0xB0 */
#define _ADC3_CALFACT      (ADC3 + ADC_CALFACT_OFFSET)      /*!< ADC  Calibration Factors,                          Address offset: 0xB4 */

#define ADC4                (ADC4_BASE)
#define _ADC4_ISR          (ADC4 + ADC_ISR_OFFSET)          /*!< ADC Interrupt and Status Register,                 Address offset: 0x00 */
#define _ADC4_IER          (ADC4 + ADC_IER_OFFSET)          /*!< ADC Interrupt Enable Register,                     Address offset: 0x04 */
#define _ADC4_CR           (ADC4 + ADC_CR_OFFSET)           /*!< ADC control register,                              Address offset: 0x08 */
#define _ADC4_CFGR         (ADC4 + ADC_CFGR_OFFSET)         /*!< ADC Configuration register,                        Address offset: 0x0C */
#define _ADC4_SMPR1        (ADC4 + ADC_SMPR1_OFFSET)        /*!< ADC sample time register 1,                        Address offset: 0x14 */
#define _ADC4_SMPR2        (ADC4 + ADC_SMPR2_OFFSET)        /*!< ADC sample time register 2,                        Address offset: 0x18 */
#define _ADC4_TR1          (ADC4 + ADC_TR1_OFFSET)          /*!< ADC watchdog threshold register 1,                 Address offset: 0x20 */
#define _ADC4_TR2          (ADC4 + ADC_TR2_OFFSET)          /*!< ADC watchdog threshold register 2,                 Address offset: 0x24 */
#define _ADC4_TR3          (ADC4 + ADC_TR3_OFFSET)          /*!< ADC watchdog threshold register 3,                 Address offset: 0x28 */
#define _ADC4_SQR1         (ADC4 + ADC_SQR1_OFFSET)         /*!< ADC regular sequence register 1,                   Address offset: 0x30 */
#define _ADC4_SQR2         (ADC4 + ADC_SQR2_OFFSET)         /*!< ADC regular sequence register 2,                   Address offset: 0x34 */
#define _ADC4_SQR3         (ADC4 + ADC_SQR3_OFFSET)         /*!< ADC regular sequence register 3,                   Address offset: 0x38 */
#define _ADC4_SQR4         (ADC4 + ADC_SQR4_OFFSET)         /*!< ADC regular sequence register 4,                   Address offset: 0x3C */
#define _ADC4_DR           (ADC4 + ADC_DR_OFFSET)           /*!< ADC regular data register,                         Address offset: 0x40 */
#define _ADC4_JSQR         (ADC4 + ADC_JSQR_OFFSET)         /*!< ADC injected sequence register,                    Address offset: 0x4C */
#define _ADC4_OFR1         (ADC4 + ADC_OFR1_OFFSET)         /*!< ADC offset register 1,                             Address offset: 0x60 */
#define _ADC4_OFR2         (ADC4 + ADC_OFR2_OFFSET)         /*!< ADC offset register 2,                             Address offset: 0x64 */
#define _ADC4_OFR3         (ADC4 + ADC_OFR3_OFFSET)         /*!< ADC offset register 3,                             Address offset: 0x68 */
#define _ADC4_OFR4         (ADC4 + ADC_OFR4_OFFSET)         /*!< ADC offset register 4,                             Address offset: 0x6C */
#define _ADC4_JDR1         (ADC4 + ADC_JDR1_OFFSET)         /*!< ADC injected data register 1,                      Address offset: 0x80 */
#define _ADC4_JDR2         (ADC4 + ADC_JDR2_OFFSET)         /*!< ADC injected data register 2,                      Address offset: 0x84 */
#define _ADC4_JDR3         (ADC4 + ADC_JDR3_OFFSET)         /*!< ADC injected data register 3,                      Address offset: 0x88 */
#define _ADC4_JDR4         (ADC4 + ADC_JDR4_OFFSET)         /*!< ADC injected data register 4,                      Address offset: 0x8C */
#define _ADC4_AWD2CR       (ADC4 + ADC_AWD2CR_OFFSET)       /*!< ADC  Analog Watchdog 2 Configuration Register,     Address offset: 0xA0 */
#define _ADC4_AWD3CR       (ADC4 + ADC_AWD3CR_OFFSET)       /*!< ADC  Analog Watchdog 3 Configuration Register,     Address offset: 0xA4 */
#define _ADC4_DIFSEL       (ADC4 + ADC_DIFSEL_OFFSET)       /*!< ADC  Differential Mode Selection Register,         Address offset: 0xB0 */
#define _ADC4_CALFACT      (ADC4 + ADC_CALFACT_OFFSET)      /*!< ADC  Calibration Factors,                          Address offset: 0xB4 */

#define ADC1_2              (ADC1_2_BASE)
#define _ADC1_2_CSR         (ADC1_2 + ADC_Common_CSR_OFFSET)         /*!< ADC Common status register,                  Address offset: ADC1/3 base address + 0x300 */
#define _ADC1_2_CCR         (ADC1_2 + ADC_Common_CCR_OFFSET)         /*!< ADC common control register,                 Address offset: ADC1/3 base address + 0x308 */
#define _ADC1_2_CDR         (ADC1_2 + ADC_Common_CDR_OFFSET)         /*!< ADC common regular data register for dual

#define ADC3_4              (ADC3_4_BASE)
#define _ADC3_4_CSR         (ADC3_4 + ADC_Common_CSR_OFFSET)         /*!< ADC Common status register,                  Address offset: ADC1/3 base address + 0x300 */
#define _ADC3_4_CCR         (ADC3_4 + ADC_Common_CCR_OFFSET)         /*!< ADC common control register,                 Address offset: ADC1/3 base address + 0x308 */
#define _ADC3_4_CDR         (ADC3_4 + ADC_Common_CDR_OFFSET)         /*!< ADC common regular data register for dual

#define FMC_Bank1           (FMC_Bank1_R_BASE)
#define _FMC_Bank1_BTCR    (FMC_Bank1 + FMC_Bank1_BTCR_OFFSET)    /*!< NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C */

#define FMC_Bank1E          (FMC_Bank1E_R_BASE)
#define _FMC_Bank1E_BWTR    (FMC_Bank1E + FMC_Bank1E_BWTR_OFFSET)    /*!< NOR/PSRAM write timing registers, Address offset: 0x104-0x11C */

#define FMC_Bank2           (FMC_Bank2_R_BASE)
#define _FMC_Bank2_PCR2         (FMC_Bank2 + FMC_Bank2_PCR2_OFFSET)         /*!< NAND Flash control register 2,                       Address offset: 0x60 */
#define _FMC_Bank2_SR2          (FMC_Bank2 + FMC_Bank2_SR2_OFFSET)          /*!< NAND Flash FIFO status and interrupt register 2,     Address offset: 0x64 */
#define _FMC_Bank2_PMEM2        (FMC_Bank2 + FMC_Bank2_PMEM2_OFFSET)        /*!< NAND Flash Common memory space timing register 2,    Address offset: 0x68 */
#define _FMC_Bank2_PATT2        (FMC_Bank2 + FMC_Bank2_PATT2_OFFSET)        /*!< NAND Flash Attribute memory space timing register 2, Address offset: 0x6C */
#define _FMC_Bank2_ECCR2        (FMC_Bank2 + FMC_Bank2_ECCR2_OFFSET)        /*!< NAND Flash ECC result registers 2,                   Address offset: 0x74 */

#define FMC_Bank3           (FMC_Bank3_R_BASE)
#define _FMC_Bank3_PCR3         (FMC_Bank3 + FMC_Bank3_PCR3_OFFSET)         /*!< NAND Flash control register 3,                       Address offset: 0x80 */
#define _FMC_Bank3_SR3          (FMC_Bank3 + FMC_Bank3_SR3_OFFSET)          /*!< NAND Flash FIFO status and interrupt register 3,     Address offset: 0x84 */
#define _FMC_Bank3_PMEM3        (FMC_Bank3 + FMC_Bank3_PMEM3_OFFSET)        /*!< NAND Flash Common memory space timing register 3,    Address offset: 0x88 */
#define _FMC_Bank3_PATT3        (FMC_Bank3 + FMC_Bank3_PATT3_OFFSET)        /*!< NAND Flash Attribute memory space timing register 3, Address offset: 0x8C */
#define _FMC_Bank3_ECCR3        (FMC_Bank3 + FMC_Bank3_ECCR3_OFFSET)        /*!< NAND Flash ECC result registers 3,                   Address offset: 0x94 */

#define FMC_Bank4           (FMC_Bank4_R_BASE)
#define _FMC_Bank4_PCR4     (FMC_Bank4 + FMC_Bank4_PCR4_OFFSET)     /*!< PC Card  control register 4,                       Address offset: 0xA0 */
#define _FMC_Bank4_SR4      (FMC_Bank4 + FMC_Bank4_SR4_OFFSET)      /*!< PC Card  FIFO status and interrupt register 4,     Address offset: 0xA4 */
#define _FMC_Bank4_PMEM4    (FMC_Bank4 + FMC_Bank4_PMEM4_OFFSET)    /*!< PC Card  Common memory space timing register 4,    Address offset: 0xA8 */
#define _FMC_Bank4_PATT4    (FMC_Bank4 + FMC_Bank4_PATT4_OFFSET)    /*!< PC Card  Attribute memory space timing register 4, Address offset: 0xAC */
#define _FMC_Bank4_PIO4     (FMC_Bank4 + FMC_Bank4_PIO4_OFFSET)     /*!< PC Card  I/O space timing register 4,              Address offset: 0xB0 */

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

#define HRTIM_MCR_CK_PSC     (0x00000007)   /*!< Prescaler mask */
#define HRTIM_MCR_CK_PSC_0   (0x00000001)   /*!< Prescaler bit 0 */ 
#define HRTIM_MCR_CK_PSC_1   (0x00000002)   /*!< Prescaler bit 1 */ 
#define HRTIM_MCR_CK_PSC_2   (0x00000004)   /*!< Prescaler bit 2 */ 

#define HRTIM_MCR_CONT       (0x00000008)   /*!< Continuous mode */
#define HRTIM_MCR_RETRIG     (0x00000010)   /*!< Rettrigreable mode */
#define HRTIM_MCR_HALF       (0x00000020)   /*!< Half mode */

#define HRTIM_MCR_SYNC_IN    (0x00000300)   /*!< Synchronization input master */
#define HRTIM_MCR_SYNC_IN_0  (0x00000100)   /*!< Synchronization input bit 0 */
#define HRTIM_MCR_SYNC_IN_1  (0x00000200)   /*!< Synchronization input bit 1 */
#define HRTIM_MCR_SYNCRSTM   (0x00000400)   /*!< Synchronization reset master */
#define HRTIM_MCR_SYNCSTRTM  (0x00000800)   /*!< Synchronization start master */
#define HRTIM_MCR_SYNC_OUT   (0x00003000)   /*!< Synchronization output master */
#define HRTIM_MCR_SYNC_OUT_0 (0x00001000)   /*!< Synchronization output bit 0 */
#define HRTIM_MCR_SYNC_OUT_1 (0x00002000)   /*!< Synchronization output bit 1 */
#define HRTIM_MCR_SYNC_SRC   (0x0000C000)   /*!< Synchronization source */
#define HRTIM_MCR_SYNC_SRC_0 (0x00004000)   /*!< Synchronization source bit 0 */
#define HRTIM_MCR_SYNC_SRC_1 (0x00008000)   /*!< Synchronization source bit 1 */

#define HRTIM_MCR_MCEN       (0x00010000)   /*!< Master counter enable */
#define HRTIM_MCR_TACEN      (0x00020000)   /*!< Timer A counter enable */
#define HRTIM_MCR_TBCEN      (0x00040000)   /*!< Timer B counter enable */
#define HRTIM_MCR_TCCEN      (0x00080000)   /*!< Timer C counter enable */
#define HRTIM_MCR_TDCEN      (0x00100000)   /*!< Timer D counter enable */
#define HRTIM_MCR_TECEN      (0x00200000)   /*!< Timer E counter enable */

#define HRTIM_MCR_DACSYNC    (0x06000000)   /*!< DAC synchronization mask */
#define HRTIM_MCR_DACSYNC_0  (0x02000000)   /*!< DAC synchronization bit 0 */
#define HRTIM_MCR_DACSYNC_1  (0x04000000)   /*!< DAC synchronization bit 1 */

#define HRTIM_MCR_PREEN      (0x08000000)   /*!< Master preload enable */
#define HRTIM_MCR_MREPU      (0x20000000)   /*!< Master repetition update */

#define HRTIM_MCR_BRSTDMA    (0xC0000000)   /*!< Burst DMA update */
#define HRTIM_MCR_BRSTDMA_0  (0x40000000)   /*!< Burst DMA update bit 0*/
#define HRTIM_MCR_BRSTDMA_1  (0x80000000)   /*!< Burst DMA update bit 1 */

#define HRTIM_MISR_MCMP1    (0x00000001)  /*!< Master compare 1 interrupt flag */
#define HRTIM_MISR_MCMP2    (0x00000002)  /*!< Master compare 2 interrupt flag */
#define HRTIM_MISR_MCMP3    (0x00000004)  /*!< Master compare 3 interrupt flag */
#define HRTIM_MISR_MCMP4    (0x00000008)  /*!< Master compare 4 interrupt flag */
#define HRTIM_MISR_MREP     (0x00000010)  /*!< Master Repetition interrupt flag */
#define HRTIM_MISR_SYNC     (0x00000020)  /*!< Synchronization input interrupt flag */
#define HRTIM_MISR_MUPD     (0x00000040)  /*!< Master update interrupt flag */

#define HRTIM_MICR_MCMP1    (0x00000001)  /*!< Master compare 1 interrupt flag clear */
#define HRTIM_MICR_MCMP2    (0x00000002)  /*!< Master compare 2 interrupt flag clear */
#define HRTIM_MICR_MCMP3    (0x00000004)  /*!< Master compare 3 interrupt flag clear */
#define HRTIM_MICR_MCMP4    (0x00000008)  /*!< Master compare 4 interrupt flag clear */
#define HRTIM_MICR_MREP     (0x00000010)  /*!< Master Repetition interrupt flag clear */
#define HRTIM_MICR_SYNC     (0x00000020)  /*!< Synchronization input interrupt flag clear */
#define HRTIM_MICR_MUPD     (0x00000040)  /*!< Master update interrupt flag clear */

#define HRTIM_MDIER_MCMP1IE    (0x00000001)  /*!< Master compare 1 interrupt enable */
#define HRTIM_MDIER_MCMP2IE    (0x00000002)  /*!< Master compare 2 interrupt enable */
#define HRTIM_MDIER_MCMP3IE    (0x00000004)  /*!< Master compare 3 interrupt enable */
#define HRTIM_MDIER_MCMP4IE    (0x00000008)  /*!< Master compare 4 interrupt enable */
#define HRTIM_MDIER_MREPIE     (0x00000010)  /*!< Master Repetition interrupt enable */
#define HRTIM_MDIER_SYNCIE     (0x00000020)  /*!< Synchronization input interrupt enable */
#define HRTIM_MDIER_MUPDIE     (0x00000040)  /*!< Master update interrupt enable */

#define HRTIM_MDIER_MCMP1DE    (0x00010000)  /*!< Master compare 1 DMA enable */
#define HRTIM_MDIER_MCMP2DE    (0x00020000)  /*!< Master compare 2 DMA enable */
#define HRTIM_MDIER_MCMP3DE    (0x00040000)  /*!< Master compare 3 DMA enable */
#define HRTIM_MDIER_MCMP4DE    (0x00080000)  /*!< Master compare 4 DMA enable */
#define HRTIM_MDIER_MREPDE     (0x00100000)  /*!< Master Repetition DMA enable */
#define HRTIM_MDIER_SYNCDE     (0x00200000)  /*!< Synchronization input DMA enable */
#define HRTIM_MDIER_MUPDDE     (0x00400000)  /*!< Master update DMA enable */

#define  HRTIM_MCNTR_MCNTR     (0xFFFFFFFF)       /*!<Counter Value */

#define  HRTIM_MPER_MPER      (0xFFFFFFFF)        /*!< Period Value */

#define  HRTIM_MREP_MREP     (0xFFFFFFFF)        /*!<Repetition Value */

#define  HRTIM_MCMP1R_MCMP1R     (0xFFFFFFFF)     /*!<Compare Value */

#define  HRTIM_MCMP1R_MCMP2R     (0xFFFFFFFF)     /*!<Compare Value */

#define  HRTIM_MCMP1R_MCMP3R     (0xFFFFFFFF)     /*!<Compare Value */

#define  HRTIM_MCMP1R_MCMP4R     (0xFFFFFFFF)     /*!<Compare Value */

#define HRTIM_TIMCR_CK_PSC      (0x00000007) /*!< Slave prescaler mask*/
#define HRTIM_TIMCR_CK_PSC_0    (0x00000001) /*!< prescaler bit 0 */
#define HRTIM_TIMCR_CK_PSC_1    (0x00000002) /*!< prescaler bit 1 */
#define HRTIM_TIMCR_CK_PSC_2    (0x00000004) /*!< prescaler bit 2 */

#define HRTIM_TIMCR_CONT        (0x00000008) /*!< Slave continuous mode */
#define HRTIM_TIMCR_RETRIG      (0x00000010) /*!< Slave Retrigreable mode */
#define HRTIM_TIMCR_HALF        (0x00000020) /*!< Slave Half mode */
#define HRTIM_TIMCR_PSHPLL      (0x00000040) /*!< Slave push-pull mode */

#define HRTIM_TIMCR_SYNCRST     (0x00000400) /*!< Slave synchronization resets */
#define HRTIM_TIMCR_SYNCSTRT    (0x00000800) /*!< Slave synchronization starts */

#define HRTIM_TIMCR_DELCMP2     (0x00003000) /*!< Slave delayed comparator 2 mode mask */
#define HRTIM_TIMCR_DELCMP2_0   (0x00001000) /*!< Slave delayed comparator 2 bit 0 */
#define HRTIM_TIMCR_DELCMP2_1   (0x00002000) /*!< Slave delayed comparator 2 bit 1 */
#define HRTIM_TIMCR_DELCMP4     (0x0000C000) /*!< Slave delayed comparator 4 mode mask */
#define HRTIM_TIMCR_DELCMP4_0   (0x00004000) /*!< Slave delayed comparator 4 bit 0 */
#define HRTIM_TIMCR_DELCMP4_1   (0x00008000) /*!< Slave delayed comparator 4 bit 1 */

#define HRTIM_TIMCR_TREPU       (0x00020000) /*!< Slave repetition update */
#define HRTIM_TIMCR_TRSTU       (0x00040000) /*!< Slave reset update */
#define HRTIM_TIMCR_TAU         (0x00080000) /*!< Slave Timer A update reserved for TIM A */
#define HRTIM_TIMCR_TBU         (0x00100000) /*!< Slave Timer B update reserved for TIM B */
#define HRTIM_TIMCR_TCU         (0x00200000) /*!< Slave Timer C update reserved for TIM C */
#define HRTIM_TIMCR_TDU         (0x00400000) /*!< Slave Timer D update reserved for TIM D */
#define HRTIM_TIMCR_TEU         (0x00800000) /*!< Slave Timer E update reserved for TIM E */
#define HRTIM_TIMCR_MSTU        (0x01000000) /*!< Master Update */

#define HRTIM_TIMCR_DACSYNC    (0x06000000)   /*!< DAC synchronization mask */
#define HRTIM_TIMCR_DACSYNC_0  (0x02000000)   /*!< DAC synchronization bit 0 */
#define HRTIM_TIMCR_DACSYNC_1  (0x04000000)   /*!< DAC synchronization bit 1 */
#define HRTIM_TIMCR_PREEN      (0x08000000)   /*!< Slave preload enable */

#define HRTIM_TIMCR_UPDGAT     (0xF0000000)   /*!< Slave update gating mask */
#define HRTIM_TIMCR_UPDGAT_0   (0x10000000)   /*!< Update gating bit 0 */
#define HRTIM_TIMCR_UPDGAT_1   (0x20000000)   /*!< Update gating bit 1 */
#define HRTIM_TIMCR_UPDGAT_2   (0x40000000)   /*!< Update gating bit 2 */
#define HRTIM_TIMCR_UPDGAT_3   (0x80000000)   /*!< Update gating bit 3 */

#define HRTIM_TIMISR_CMP1       (0x00000001)   /*!< Slave compare 1 interrupt flag */
#define HRTIM_TIMISR_CMP2       (0x00000002)   /*!< Slave compare 2 interrupt flag */
#define HRTIM_TIMISR_CMP3       (0x00000004)   /*!< Slave compare 3 interrupt flag */
#define HRTIM_TIMISR_CMP4       (0x00000008)   /*!< Slave compare 4 interrupt flag */
#define HRTIM_TIMISR_REP        (0x00000010)   /*!< Slave repetition interrupt flag */
#define HRTIM_TIMISR_UPD        (0x00000040)   /*!< Slave update interrupt flag */
#define HRTIM_TIMISR_CPT1       (0x00000080)   /*!< Slave capture 1 interrupt flag */
#define HRTIM_TIMISR_CPT2       (0x00000100)   /*!< Slave capture 2 interrupt flag */
#define HRTIM_TIMISR_SET1       (0x00000200)   /*!< Slave output 1 set interrupt flag */
#define HRTIM_TIMISR_RST1       (0x00000400)   /*!< Slave output 1 reset interrupt flag */
#define HRTIM_TIMISR_SET2       (0x00000800)   /*!< Slave output 2 set interrupt flag */
#define HRTIM_TIMISR_RST2       (0x00001000)   /*!< Slave output 2 reset interrupt flag */
#define HRTIM_TIMISR_RST        (0x00002000)   /*!< Slave reset interrupt flag */
#define HRTIM_TIMISR_DLYPRT     (0x00004000)   /*!< Slave output 1 delay protection interrupt flag */
#define HRTIM_TIMISR_CPPSTAT    (0x00010000)   /*!< Slave current push-pull flag */
#define HRTIM_TIMISR_IPPSTAT    (0x00020000)   /*!< Slave idle push-pull flag */
#define HRTIM_TIMISR_O1STAT     (0x00040000)   /*!< Slave output 1 state flag */
#define HRTIM_TIMISR_O2STAT     (0x00080000)   /*!< Slave output 2 state flag */
#define HRTIM_TIMISR_O1CPY      (0x00100000)   /*!< Slave output 1 copy flag */
#define HRTIM_TIMISR_O2CPY      (0x00200000)   /*!< Slave output 2 copy flag */

#define HRTIM_TIMICR_CMP1C       (0x00000001)   /*!< Slave compare 1 clear flag */
#define HRTIM_TIMICR_CMP2C       (0x00000002)   /*!< Slave compare 2 clear flag */
#define HRTIM_TIMICR_CMP3C       (0x00000004)   /*!< Slave compare 3 clear flag */
#define HRTIM_TIMICR_CMP4C       (0x00000008)   /*!< Slave compare 4 clear flag */
#define HRTIM_TIMICR_REPC        (0x00000010)   /*!< Slave repetition clear flag */
#define HRTIM_TIMICR_UPDC        (0x00000040)   /*!< Slave update clear flag */
#define HRTIM_TIMICR_CPT1C       (0x00000080)   /*!< Slave capture 1 clear flag */
#define HRTIM_TIMICR_CPT2C       (0x00000100)   /*!< Slave capture 2 clear flag */
#define HRTIM_TIMICR_SET1C       (0x00000200)   /*!< Slave output 1 set clear flag */
#define HRTIM_TIMICR_RST1C       (0x00000400)   /*!< Slave output 1 reset clear flag */
#define HRTIM_TIMICR_SET2C       (0x00000800)   /*!< Slave output 2 set clear flag */
#define HRTIM_TIMICR_RST2C       (0x00001000)   /*!< Slave output 2 reset clear flag */
#define HRTIM_TIMICR_RSTC        (0x00002000)   /*!< Slave reset clear flag */
#define HRTIM_TIMICR_DLYPRT1C    (0x00004000)   /*!< Slave output 1 delay protection clear flag */
#define HRTIM_TIMICR_DLYPRT2C    (0x00008000)   /*!< Slave output 2 delay protection clear flag */

#define HRTIM_TIMDIER_CMP1IE       (0x00000001)   /*!< Slave compare 1 interrupt enable */
#define HRTIM_TIMDIER_CMP2IE       (0x00000002)   /*!< Slave compare 2 interrupt enable */
#define HRTIM_TIMDIER_CMP3IE       (0x00000004)   /*!< Slave compare 3 interrupt enable */
#define HRTIM_TIMDIER_CMP4IE       (0x00000008)   /*!< Slave compare 4 interrupt enable */
#define HRTIM_TIMDIER_REPIE        (0x00000010)   /*!< Slave repetition interrupt enable */
#define HRTIM_TIMDIER_UPDIE        (0x00000040)   /*!< Slave update interrupt enable */
#define HRTIM_TIMDIER_CPT1IE       (0x00000080)   /*!< Slave capture 1 interrupt enable */
#define HRTIM_TIMDIER_CPT2IE       (0x00000100)   /*!< Slave capture 2 interrupt enable */
#define HRTIM_TIMDIER_SET1IE       (0x00000200)   /*!< Slave output 1 set interrupt enable */
#define HRTIM_TIMDIER_RST1IE       (0x00000400)   /*!< Slave output 1 reset interrupt enable */
#define HRTIM_TIMDIER_SET2IE       (0x00000800)   /*!< Slave output 2 set interrupt enable */
#define HRTIM_TIMDIER_RST2IE       (0x00001000)   /*!< Slave output 2 reset interrupt enable */
#define HRTIM_TIMDIER_RSTIE        (0x00002000)   /*!< Slave reset interrupt enable */
#define HRTIM_TIMDIER_DLYPRTIE     (0x00004000)   /*!< Slave delay protection interrupt enable */

#define HRTIM_TIMDIER_CMP1DE       (0x00010000)   /*!< Slave compare 1 request enable */
#define HRTIM_TIMDIER_CMP2DE       (0x00020000)   /*!< Slave compare 2 request enable */
#define HRTIM_TIMDIER_CMP3DE       (0x00040000)   /*!< Slave compare 3 request enable */
#define HRTIM_TIMDIER_CMP4DE       (0x00080000)   /*!< Slave compare 4 request enable */
#define HRTIM_TIMDIER_REPDE        (0x00100000)   /*!< Slave repetition request enable */
#define HRTIM_TIMDIER_UPDDE        (0x00400000)   /*!< Slave update request enable */
#define HRTIM_TIMDIER_CPT1DE       (0x00800000)   /*!< Slave capture 1 request enable */
#define HRTIM_TIMDIER_CPT2DE       (0x01000000)   /*!< Slave capture 2 request enable */
#define HRTIM_TIMDIER_SET1DE       (0x02000000)   /*!< Slave output 1 set request enable */
#define HRTIM_TIMDIER_RST1DE       (0x04000000)   /*!< Slave output 1 reset request enable */
#define HRTIM_TIMDIER_SET2DE       (0x08000000)   /*!< Slave output 2 set request enable */
#define HRTIM_TIMDIER_RST2DE       (0x10000000)   /*!< Slave output 2 reset request enable */
#define HRTIM_TIMDIER_RSTDE        (0x20000000)   /*!< Slave reset request enable */
#define HRTIM_TIMDIER_DLYPRTDE     (0x40000000)   /*!< Slave delay protection request enable */

#define  HRTIM_CNTR_CNTR      (0xFFFFFFFF)       /*!< Counter Value */

#define  HRTIM_PER_PER       (0xFFFFFFFF)        /*!< Period Value */

#define  HRTIM_REP_REP      (0xFFFFFFFF)        /*!< Repetition Value */

#define  HRTIM_CMP1R_CMP1R     (0xFFFFFFFF)     /*!< Compare Value */

#define  HRTIM_CMP1CR_CMP1CR     (0xFFFFFFFF)     /*!< Compare Value */

#define  HRTIM_CMP2R_CMP2R     (0xFFFFFFFF)     /*!< Compare Value */

#define  HRTIM_CMP3R_CMP3R     (0xFFFFFFFF)     /*!< Compare Value */

#define  HRTIM_CMP4R_CMP4R     (0xFFFFFFFF)     /*!< Compare Value */

#define  HRTIM_CPT1R_CPT1R     (0xFFFFFFFF)     /*!< Capture Value */

#define  HRTIM_CPT2R_CPT2R     (0xFFFFFFFF)     /*!< Capture Value */

#define HRTIM_DTR_DTR           (0x000001FF)    /*!< Dead time rising value */
#define HRTIM_DTR_DTR_0         (0x00000001)    /*!< Dead time rising bit 0 */
#define HRTIM_DTR_DTR_1         (0x00000002)    /*!< Dead time rising bit 1 */
#define HRTIM_DTR_DTR_2         (0x00000004)    /*!< Dead time rising bit 2 */
#define HRTIM_DTR_DTR_3         (0x00000008)    /*!< Dead time rising bit 3 */
#define HRTIM_DTR_DTR_4         (0x00000010)    /*!< Dead time rising bit 4 */
#define HRTIM_DTR_DTR_5         (0x00000020)    /*!< Dead time rising bit 5 */
#define HRTIM_DTR_DTR_6         (0x00000040)    /*!< Dead time rising bit 6 */
#define HRTIM_DTR_DTR_7         (0x00000080)    /*!< Dead time rising bit 7 */
#define HRTIM_DTR_DTR_8         (0x00000100)    /*!< Dead time rising bit 8 */
#define HRTIM_DTR_SDTR          (0x00000200)    /*!< Sign dead time rising value */
#define HRTIM_DTR_DTPRSC        (0x00001C00)    /*!< Dead time prescaler */
#define HRTIM_DTR_DTPRSC_0      (0x00000400)    /*!< Dead time prescaler bit 0 */
#define HRTIM_DTR_DTPRSC_1      (0x00000800)    /*!< Dead time prescaler bit 1 */
#define HRTIM_DTR_DTPRSC_2      (0x00001000)    /*!< Dead time prescaler bit 2 */
#define HRTIM_DTR_DTRSLK        (0x00004000)    /*!< Dead time rising sign lock */
#define HRTIM_DTR_DTRLK         (0x00008000)    /*!< Dead time rising lock */
#define HRTIM_DTR_DTF           (0x01FF0000)    /*!< Dead time falling value */
#define HRTIM_DTR_DTF_0         (0x00010000)    /*!< Dead time falling bit 0 */
#define HRTIM_DTR_DTF_1         (0x00020000)    /*!< Dead time falling bit 1 */
#define HRTIM_DTR_DTF_2         (0x00040000)    /*!< Dead time falling bit 2 */
#define HRTIM_DTR_DTF_3         (0x00080000)    /*!< Dead time falling bit 3 */
#define HRTIM_DTR_DTF_4         (0x00100000)    /*!< Dead time falling bit 4 */
#define HRTIM_DTR_DTF_5         (0x00200000)    /*!< Dead time falling bit 5 */
#define HRTIM_DTR_DTF_6         (0x00400000)    /*!< Dead time falling bit 6 */
#define HRTIM_DTR_DTF_7         (0x00800000)    /*!< Dead time falling bit 7 */
#define HRTIM_DTR_DTF_8         (0x01000000)    /*!< Dead time falling bit 8 */
#define HRTIM_DTR_SDTF          (0x02000000)    /*!< Sign dead time falling value */
#define HRTIM_DTR_DTFSLK        (0x40000000)    /*!< Dead time falling sign lock */
#define HRTIM_DTR_DTFLK         (0x80000000)    /*!< Dead time falling lock */

#define HRTIM_SET1R_SST         (0x00000001)    /*!< software set trigger */
#define HRTIM_SET1R_RESYNC      (0x00000002)    /*!< Timer A resynchronization */
#define HRTIM_SET1R_PER         (0x00000004)    /*!< Timer A period */
#define HRTIM_SET1R_CMP1        (0x00000008)    /*!< Timer A compare 1 */
#define HRTIM_SET1R_CMP2        (0x00000010)    /*!< Timer A compare 2 */
#define HRTIM_SET1R_CMP3        (0x00000020)    /*!< Timer A compare 3 */
#define HRTIM_SET1R_CMP4        (0x00000040)    /*!< Timer A compare 4 */

#define HRTIM_SET1R_MSTPER      (0x00000080)    /*!< Master period */
#define HRTIM_SET1R_MSTCMP1     (0x00000100)    /*!< Master compare 1 */
#define HRTIM_SET1R_MSTCMP2     (0x00000200)    /*!< Master compare 2 */
#define HRTIM_SET1R_MSTCMP3     (0x00000400)    /*!< Master compare 3 */
#define HRTIM_SET1R_MSTCMP4     (0x00000800)    /*!< Master compare 4 */

#define HRTIM_SET1R_TIMEVNT1   (0x00001000)    /*!< Timer event 1 */
#define HRTIM_SET1R_TIMEVNT2   (0x00002000)    /*!< Timer event 2 */
#define HRTIM_SET1R_TIMEVNT3   (0x00004000)    /*!< Timer event 3 */
#define HRTIM_SET1R_TIMEVNT4   (0x00008000)    /*!< Timer event 4 */
#define HRTIM_SET1R_TIMEVNT5   (0x00010000)    /*!< Timer event 5 */
#define HRTIM_SET1R_TIMEVNT6   (0x00020000)    /*!< Timer event 6 */
#define HRTIM_SET1R_TIMEVNT7   (0x00040000)    /*!< Timer event 7 */
#define HRTIM_SET1R_TIMEVNT8   (0x00080000)    /*!< Timer event 8 */
#define HRTIM_SET1R_TIMEVNT9   (0x00100000)    /*!< Timer event 9 */

#define HRTIM_SET1R_EXTVNT1   (0x00200000)    /*!< External event 1 */
#define HRTIM_SET1R_EXTVNT2   (0x00400000)    /*!< External event 2 */
#define HRTIM_SET1R_EXTVNT3   (0x00800000)    /*!< External event 3 */
#define HRTIM_SET1R_EXTVNT4   (0x01000000)    /*!< External event 4 */
#define HRTIM_SET1R_EXTVNT5   (0x02000000)    /*!< External event 5 */
#define HRTIM_SET1R_EXTVNT6   (0x04000000)    /*!< External event 6 */
#define HRTIM_SET1R_EXTVNT7   (0x08000000)    /*!< External event 7 */
#define HRTIM_SET1R_EXTVNT8   (0x10000000)    /*!< External event 8 */
#define HRTIM_SET1R_EXTVNT9   (0x20000000)    /*!< External event 9 */
#define HRTIM_SET1R_EXTVNT10  (0x40000000)    /*!< External event 10 */

#define HRTIM_SET1R_UPDATE    (0x80000000)    /*!< Register update (transfer preload to active) */

#define HRTIM_RST1R_SRT         (0x00000001)    /*!< software reset trigger */
#define HRTIM_RST1R_RESYNC      (0x00000002)    /*!< Timer A resynchronization */
#define HRTIM_RST1R_PER         (0x00000004)    /*!< Timer A period */
#define HRTIM_RST1R_CMP1        (0x00000008)    /*!< Timer A compare 1 */
#define HRTIM_RST1R_CMP2        (0x00000010)    /*!< Timer A compare 2 */
#define HRTIM_RST1R_CMP3        (0x00000020)    /*!< Timer A compare 3 */
#define HRTIM_RST1R_CMP4        (0x00000040)    /*!< Timer A compare 4 */

#define HRTIM_RST1R_MSTPER      (0x00000080)    /*!< Master period */
#define HRTIM_RST1R_MSTCMP1     (0x00000100)    /*!< Master compare 1 */
#define HRTIM_RST1R_MSTCMP2     (0x00000200)    /*!< Master compare 2 */
#define HRTIM_RST1R_MSTCMP3     (0x00000400)    /*!< Master compare 3 */
#define HRTIM_RST1R_MSTCMP4     (0x00000800)    /*!< Master compare 4 */

#define HRTIM_RST1R_TIMEVNT1   (0x00001000)    /*!< Timer event 1 */
#define HRTIM_RST1R_TIMEVNT2   (0x00002000)    /*!< Timer event 2 */
#define HRTIM_RST1R_TIMEVNT3   (0x00004000)    /*!< Timer event 3 */
#define HRTIM_RST1R_TIMEVNT4   (0x00008000)    /*!< Timer event 4 */
#define HRTIM_RST1R_TIMEVNT5   (0x00010000)    /*!< Timer event 5 */
#define HRTIM_RST1R_TIMEVNT6   (0x00020000)    /*!< Timer event 6 */
#define HRTIM_RST1R_TIMEVNT7   (0x00040000)    /*!< Timer event 7 */
#define HRTIM_RST1R_TIMEVNT8   (0x00080000)    /*!< Timer event 8 */
#define HRTIM_RST1R_TIMEVNT9   (0x00100000)    /*!< Timer event 9 */

#define HRTIM_RST1R_EXTVNT1   (0x00200000)    /*!< External event 1 */
#define HRTIM_RST1R_EXTVNT2   (0x00400000)    /*!< External event 2 */
#define HRTIM_RST1R_EXTVNT3   (0x00800000)    /*!< External event 3 */
#define HRTIM_RST1R_EXTVNT4   (0x01000000)    /*!< External event 4 */
#define HRTIM_RST1R_EXTVNT5   (0x02000000)    /*!< External event 5 */
#define HRTIM_RST1R_EXTVNT6   (0x04000000)    /*!< External event 6 */
#define HRTIM_RST1R_EXTVNT7   (0x08000000)    /*!< External event 7 */
#define HRTIM_RST1R_EXTVNT8   (0x10000000)    /*!< External event 8 */
#define HRTIM_RST1R_EXTVNT9   (0x20000000)    /*!< External event 9 */
#define HRTIM_RST1R_EXTVNT10  (0x40000000)    /*!< External event 10 */

#define HRTIM_RST1R_UPDATE    (0x80000000)    /*!< Register update (transfer preload to active) */


#define HRTIM_SET2R_SST         (0x00000001)    /*!< software set trigger */
#define HRTIM_SET2R_RESYNC      (0x00000002)    /*!< Timer A resynchronization */
#define HRTIM_SET2R_PER         (0x00000004)    /*!< Timer A period */
#define HRTIM_SET2R_CMP1        (0x00000008)    /*!< Timer A compare 1 */
#define HRTIM_SET2R_CMP2        (0x00000010)    /*!< Timer A compare 2 */
#define HRTIM_SET2R_CMP3        (0x00000020)    /*!< Timer A compare 3 */
#define HRTIM_SET2R_CMP4        (0x00000040)    /*!< Timer A compare 4 */

#define HRTIM_SET2R_MSTPER      (0x00000080)    /*!< Master period */
#define HRTIM_SET2R_MSTCMP1     (0x00000100)    /*!< Master compare 1 */
#define HRTIM_SET2R_MSTCMP2     (0x00000200)    /*!< Master compare 2 */
#define HRTIM_SET2R_MSTCMP3     (0x00000400)    /*!< Master compare 3 */
#define HRTIM_SET2R_MSTCMP4     (0x00000800)    /*!< Master compare 4 */

#define HRTIM_SET2R_TIMEVNT1   (0x00001000)    /*!< Timer event 1 */
#define HRTIM_SET2R_TIMEVNT2   (0x00002000)    /*!< Timer event 2 */
#define HRTIM_SET2R_TIMEVNT3   (0x00004000)    /*!< Timer event 3 */
#define HRTIM_SET2R_TIMEVNT4   (0x00008000)    /*!< Timer event 4 */
#define HRTIM_SET2R_TIMEVNT5   (0x00010000)    /*!< Timer event 5 */
#define HRTIM_SET2R_TIMEVNT6   (0x00020000)    /*!< Timer event 6 */
#define HRTIM_SET2R_TIMEVNT7   (0x00040000)    /*!< Timer event 7 */
#define HRTIM_SET2R_TIMEVNT8   (0x00080000)    /*!< Timer event 8 */
#define HRTIM_SET2R_TIMEVNT9   (0x00100000)    /*!< Timer event 9 */

#define HRTIM_SET2R_EXTVNT1   (0x00200000)    /*!< External event 1 */
#define HRTIM_SET2R_EXTVNT2   (0x00400000)    /*!< External event 2 */
#define HRTIM_SET2R_EXTVNT3   (0x00800000)    /*!< External event 3 */
#define HRTIM_SET2R_EXTVNT4   (0x01000000)    /*!< External event 4 */
#define HRTIM_SET2R_EXTVNT5   (0x02000000)    /*!< External event 5 */
#define HRTIM_SET2R_EXTVNT6   (0x04000000)    /*!< External event 6 */
#define HRTIM_SET2R_EXTVNT7   (0x08000000)    /*!< External event 7 */
#define HRTIM_SET2R_EXTVNT8   (0x10000000)    /*!< External event 8 */
#define HRTIM_SET2R_EXTVNT9   (0x20000000)    /*!< External event 9 */
#define HRTIM_SET2R_EXTVNT10  (0x40000000)    /*!< External event 10 */

#define HRTIM_SET2R_UPDATE    (0x80000000)    /*!< Register update (transfer preload to active) */

#define HRTIM_RST2R_SRT         (0x00000001)    /*!< software reset trigger */
#define HRTIM_RST2R_RESYNC      (0x00000002)    /*!< Timer A resynchronization */
#define HRTIM_RST2R_PER         (0x00000004)    /*!< Timer A period */
#define HRTIM_RST2R_CMP1        (0x00000008)    /*!< Timer A compare 1 */
#define HRTIM_RST2R_CMP2        (0x00000010)    /*!< Timer A compare 2 */
#define HRTIM_RST2R_CMP3        (0x00000020)    /*!< Timer A compare 3 */
#define HRTIM_RST2R_CMP4        (0x00000040)    /*!< Timer A compare 4 */

#define HRTIM_RST2R_MSTPER      (0x00000080)    /*!< Master period */
#define HRTIM_RST2R_MSTCMP1     (0x00000100)    /*!< Master compare 1 */
#define HRTIM_RST2R_MSTCMP2     (0x00000200)    /*!< Master compare 2 */
#define HRTIM_RST2R_MSTCMP3     (0x00000400)    /*!< Master compare 3 */
#define HRTIM_RST2R_MSTCMP4     (0x00000800)    /*!< Master compare 4 */

#define HRTIM_RST2R_TIMEVNT1   (0x00001000)    /*!< Timer event 1 */
#define HRTIM_RST2R_TIMEVNT2   (0x00002000)    /*!< Timer event 2 */
#define HRTIM_RST2R_TIMEVNT3   (0x00004000)    /*!< Timer event 3 */
#define HRTIM_RST2R_TIMEVNT4   (0x00008000)    /*!< Timer event 4 */
#define HRTIM_RST2R_TIMEVNT5   (0x00010000)    /*!< Timer event 5 */
#define HRTIM_RST2R_TIMEVNT6   (0x00020000)    /*!< Timer event 6 */
#define HRTIM_RST2R_TIMEVNT7   (0x00040000)    /*!< Timer event 7 */
#define HRTIM_RST2R_TIMEVNT8   (0x00080000)    /*!< Timer event 8 */
#define HRTIM_RST2R_TIMEVNT9   (0x00100000)    /*!< Timer event 9 */

#define HRTIM_RST2R_EXTVNT1   (0x00200000)    /*!< External event 1 */
#define HRTIM_RST2R_EXTVNT2   (0x00400000)    /*!< External event 2 */
#define HRTIM_RST2R_EXTVNT3   (0x00800000)    /*!< External event 3 */
#define HRTIM_RST2R_EXTVNT4   (0x01000000)    /*!< External event 4 */
#define HRTIM_RST2R_EXTVNT5   (0x02000000)    /*!< External event 5 */
#define HRTIM_RST2R_EXTVNT6   (0x04000000)    /*!< External event 6 */
#define HRTIM_RST2R_EXTVNT7   (0x08000000)    /*!< External event 7 */
#define HRTIM_RST2R_EXTVNT8   (0x10000000)    /*!< External event 8 */
#define HRTIM_RST2R_EXTVNT9   (0x20000000)    /*!< External event 9 */
#define HRTIM_RST2R_EXTVNT10  (0x40000000)    /*!< External event 10 */

#define HRTIM_RST2R_UPDATE    (0x80000000)    /*!< Register update (transfer preload to active) */

#define HRTIM_EEFR1_EE1LTCH    (0x00000001)    /*!< External Event 1 latch */
#define HRTIM_EEFR1_EE1FLTR    (0x0000001E)    /*!< External Event 1 filter mask */
#define HRTIM_EEFR1_EE1FLTR_0  (0x00000002)    /*!< External Event 1 bit 0  */
#define HRTIM_EEFR1_EE1FLTR_1  (0x00000004)    /*!< External Event 1 bit 1*/
#define HRTIM_EEFR1_EE1FLTR_2  (0x00000008)    /*!< External Event 1 bit 2 */
#define HRTIM_EEFR1_EE1FLTR_3  (0x00000010)    /*!< External Event 1 bit 3 */

#define HRTIM_EEFR1_EE2LTCH    (0x00000040)    /*!< External Event 2 latch */
#define HRTIM_EEFR1_EE2FLTR    (0x00000780)    /*!< External Event 2 filter mask */
#define HRTIM_EEFR1_EE2FLTR_0  (0x00000080)    /*!< External Event 2 bit 0  */
#define HRTIM_EEFR1_EE2FLTR_1  (0x00000100)    /*!< External Event 2 bit 1*/
#define HRTIM_EEFR1_EE2FLTR_2  (0x00000200)    /*!< External Event 2 bit 2 */
#define HRTIM_EEFR1_EE2FLTR_3  (0x00000400)    /*!< External Event 2 bit 3 */

#define HRTIM_EEFR1_EE3LTCH    (0x00001000)    /*!< External Event 3 latch */
#define HRTIM_EEFR1_EE3FLTR    (0x0001E000)    /*!< External Event 3 filter mask */
#define HRTIM_EEFR1_EE3FLTR_0  (0x00002000)    /*!< External Event 3 bit 0  */
#define HRTIM_EEFR1_EE3FLTR_1  (0x00004000)    /*!< External Event 3 bit 1*/
#define HRTIM_EEFR1_EE3FLTR_2  (0x00008000)    /*!< External Event 3 bit 2 */
#define HRTIM_EEFR1_EE3FLTR_3  (0x00010000)    /*!< External Event 3 bit 3 */

#define HRTIM_EEFR1_EE4LTCH    (0x00040000)    /*!< External Event 4 latch */
#define HRTIM_EEFR1_EE4FLTR    (0x00780000)    /*!< External Event 4 filter mask */
#define HRTIM_EEFR1_EE4FLTR_0  (0x00080000)    /*!< External Event 4 bit 0  */
#define HRTIM_EEFR1_EE4FLTR_1  (0x00100000)    /*!< External Event 4 bit 1*/
#define HRTIM_EEFR1_EE4FLTR_2  (0x00200000)    /*!< External Event 4 bit 2 */
#define HRTIM_EEFR1_EE4FLTR_3  (0x00400000)    /*!< External Event 4 bit 3 */

#define HRTIM_EEFR1_EE5LTCH    (0x01000000)   /*!< External Event 5 latch */
#define HRTIM_EEFR1_EE5FLTR    (0x1E000000)    /*!< External Event 5 filter mask */
#define HRTIM_EEFR1_EE5FLTR_0  (0x02000000)    /*!< External Event 5 bit 0  */
#define HRTIM_EEFR1_EE5FLTR_1  (0x04000000)    /*!< External Event 5 bit 1*/
#define HRTIM_EEFR1_EE5FLTR_2  (0x08000000)    /*!< External Event 5 bit 2 */
#define HRTIM_EEFR1_EE5FLTR_3  (0x10000000)    /*!< External Event 5 bit 3 */

#define HRTIM_EEFR2_EE6LTCH    (0x00000001)    /*!< External Event 6 latch */
#define HRTIM_EEFR2_EE6FLTR    (0x0000001E)    /*!< External Event 6 filter mask */
#define HRTIM_EEFR2_EE6FLTR_0  (0x00000002)    /*!< External Event 6 bit 0  */
#define HRTIM_EEFR2_EE6FLTR_1  (0x00000004)    /*!< External Event 6 bit 1*/
#define HRTIM_EEFR2_EE6FLTR_2  (0x00000008)    /*!< External Event 6 bit 2 */
#define HRTIM_EEFR2_EE6FLTR_3  (0x00000010)    /*!< External Event 6 bit 3 */

#define HRTIM_EEFR2_EE7LTCH    (0x00000040)    /*!< External Event 7 latch */
#define HRTIM_EEFR2_EE7FLTR    (0x00000780)    /*!< External Event 7 filter mask */
#define HRTIM_EEFR2_EE7FLTR_0  (0x00000080)    /*!< External Event 7 bit 0  */
#define HRTIM_EEFR2_EE7FLTR_1  (0x00000100)    /*!< External Event 7 bit 1*/
#define HRTIM_EEFR2_EE7FLTR_2  (0x00000200)    /*!< External Event 7 bit 2 */
#define HRTIM_EEFR2_EE7FLTR_3  (0x00000400)    /*!< External Event 7 bit 3 */

#define HRTIM_EEFR2_EE8LTCH    (0x00001000)    /*!< External Event 8 latch */
#define HRTIM_EEFR2_EE8FLTR    (0x0001E000)    /*!< External Event 8 filter mask */
#define HRTIM_EEFR2_EE8FLTR_0  (0x00002000)    /*!< External Event 8 bit 0  */
#define HRTIM_EEFR2_EE8FLTR_1  (0x00004000)    /*!< External Event 8 bit 1*/
#define HRTIM_EEFR2_EE8FLTR_2  (0x00008000)    /*!< External Event 8 bit 2 */
#define HRTIM_EEFR2_EE8FLTR_3  (0x00010000)    /*!< External Event 8 bit 3 */

#define HRTIM_EEFR2_EE9LTCH    (0x00040000)    /*!< External Event 9 latch */
#define HRTIM_EEFR2_EE9FLTR    (0x00780000)    /*!< External Event 9 filter mask */
#define HRTIM_EEFR2_EE9FLTR_0  (0x00080000)    /*!< External Event 9 bit 0  */
#define HRTIM_EEFR2_EE9FLTR_1  (0x00100000)    /*!< External Event 9 bit 1*/
#define HRTIM_EEFR2_EE9FLTR_2  (0x00200000)    /*!< External Event 9 bit 2 */
#define HRTIM_EEFR2_EE9FLTR_3  (0x00400000)    /*!< External Event 9 bit 3 */

#define HRTIM_EEFR2_EE10LTCH    (0x01000000)   /*!< External Event 10 latch */
#define HRTIM_EEFR2_EE10FLTR    (0x1E000000)    /*!< External Event 10 filter mask */
#define HRTIM_EEFR2_EE10FLTR_0  (0x02000000)    /*!< External Event 10 bit 0  */
#define HRTIM_EEFR2_EE10FLTR_1  (0x04000000)    /*!< External Event 10 bit 1*/
#define HRTIM_EEFR2_EE10FLTR_2  (0x08000000)    /*!< External Event 10 bit 2 */
#define HRTIM_EEFR2_EE10FLTR_3  (0x10000000)    /*!< External Event 10 bit 3 */

#define HRTIM_RSTR_UPDATE     (0x00000002)   /*!< Timer update */
#define HRTIM_RSTR_CMP2       (0x00000004)   /*!< Timer compare2 */
#define HRTIM_RSTR_CMP4       (0x00000008)   /*!< Timer compare4 */

#define HRTIM_RSTR_MSTPER     (0x00000010)   /*!< Master period */
#define HRTIM_RSTR_MSTCMP1    (0x00000020)   /*!< Master compare1 */
#define HRTIM_RSTR_MSTCMP2    (0x00000040)   /*!< Master compare2 */
#define HRTIM_RSTR_MSTCMP3    (0x00000080)   /*!< Master compare3 */
#define HRTIM_RSTR_MSTCMP4    (0x00000100)   /*!< Master compare4 */

#define HRTIM_RSTR_EXTEVNT1   (0x00000200)   /*!< External event 1 */
#define HRTIM_RSTR_EXTEVNT2   (0x00000400)   /*!< External event 2 */
#define HRTIM_RSTR_EXTEVNT3   (0x00000800)   /*!< External event 3 */
#define HRTIM_RSTR_EXTEVNT4   (0x00001000)   /*!< External event 4 */
#define HRTIM_RSTR_EXTEVNT5   (0x00002000)   /*!< External event 5 */
#define HRTIM_RSTR_EXTEVNT6   (0x00004000)   /*!< External event 6 */
#define HRTIM_RSTR_EXTEVNT7   (0x00008000)   /*!< External event 7 */
#define HRTIM_RSTR_EXTEVNT8   (0x00010000)   /*!< External event 8 */
#define HRTIM_RSTR_EXTEVNT9   (0x00020000)   /*!< External event 9 */
#define HRTIM_RSTR_EXTEVNT10  (0x00040000)   /*!< External event 10 */

#define HRTIM_RSTR_TIMBCMP1   (0x00080000)   /*!< Timer B compare 1 */
#define HRTIM_RSTR_TIMBCMP2   (0x00100000)   /*!< Timer B compare 2 */
#define HRTIM_RSTR_TIMBCMP4   (0x00200000)   /*!< Timer B compare 4 */

#define HRTIM_RSTR_TIMCCMP1   (0x00400000)   /*!< Timer C compare 1 */
#define HRTIM_RSTR_TIMCCMP2   (0x00800000)   /*!< Timer C compare 2 */
#define HRTIM_RSTR_TIMCCMP4   (0x01000000)   /*!< Timer C compare 4 */

#define HRTIM_RSTR_TIMDCMP1   (0x02000000)   /*!< Timer D compare 1 */
#define HRTIM_RSTR_TIMDCMP2   (0x04000000)   /*!< Timer D compare 2 */
#define HRTIM_RSTR_TIMDCMP4   (0x08000000)   /*!< Timer D compare 4 */

#define HRTIM_RSTR_TIMECMP1   (0x10000000)   /*!< Timer E compare 1 */
#define HRTIM_RSTR_TIMECMP2   (0x20000000)   /*!< Timer E compare 2 */
#define HRTIM_RSTR_TIMECMP4   (0x40000000)   /*!< Timer E compare 4 */

#define HRTIM_CHPR_CARFRQ    (0x0000000F)   /*!< Timer carrier frequency value */
#define HRTIM_CHPR_CARFRQ_0  (0x00000001)   /*!< Timer carrier frequency value bit 0 */
#define HRTIM_CHPR_CARFRQ_1  (0x00000002)   /*!< Timer carrier frequency value bit 1 */
#define HRTIM_CHPR_CARFRQ_2  (0x00000004)   /*!< Timer carrier frequency value bit 2 */
#define HRTIM_CHPR_CARFRQ_3  (0x00000008)   /*!< Timer carrier frequency value bit 3 */

#define HRTIM_CHPR_CARDTY    (0x00000070)   /*!< Timer chopper duty cycle value */
#define HRTIM_CHPR_CARDTY_0  (0x00000010)   /*!< Timer chopper duty cycle value bit 0 */
#define HRTIM_CHPR_CARDTY_1  (0x00000020)   /*!< Timer chopper duty cycle value bit 1 */
#define HRTIM_CHPR_CARDTY_2  (0x00000040)   /*!< Timer chopper duty cycle value bit 2 */

#define HRTIM_CHPR_STRPW     (0x00000780)   /*!< Timer start pulse width value */
#define HRTIM_CHPR_STRPW_0   (0x00000080)   /*!< Timer start pulse width value bit 0 */
#define HRTIM_CHPR_STRPW_1   (0x00000100)   /*!< Timer start pulse width value bit 1 */
#define HRTIM_CHPR_STRPW_2   (0x00000200)   /*!< Timer start pulse width value bit 2 */
#define HRTIM_CHPR_STRPW_3   (0x00000400)   /*!< Timer start pulse width value bit 3 */

#define HRTIM_CPT1CR_SWCPT       (0x00000001)   /*!< Software capture */
#define HRTIM_CPT1CR_UPDCPT      (0x00000002)   /*!< Update capture */
#define HRTIM_CPT1CR_EXEV1CPT    (0x00000004)   /*!< External event 1 capture */
#define HRTIM_CPT1CR_EXEV2CPT    (0x00000008)   /*!< External event 2 capture */
#define HRTIM_CPT1CR_EXEV3CPT    (0x00000010)   /*!< External event 3 capture */
#define HRTIM_CPT1CR_EXEV4CPT    (0x00000020)   /*!< External event 4 capture */
#define HRTIM_CPT1CR_EXEV5CPT    (0x00000040)   /*!< External event 5 capture */
#define HRTIM_CPT1CR_EXEV6CPT    (0x00000080)   /*!< External event 6 capture */
#define HRTIM_CPT1CR_EXEV7CPT    (0x00000100)   /*!< External event 7 capture */
#define HRTIM_CPT1CR_EXEV8CPT    (0x00000200)   /*!< External event 8 capture */
#define HRTIM_CPT1CR_EXEV9CPT    (0x00000400)   /*!< External event 9 capture */
#define HRTIM_CPT1CR_EXEV10CPT   (0x00000800)   /*!< External event 10 capture */

#define HRTIM_CPT1CR_TA1SET      (0x00001000)   /*!< Timer A output 1 set */
#define HRTIM_CPT1CR_TA1RST      (0x00002000)   /*!< Timer A output 1 reset */
#define HRTIM_CPT1CR_TA1CMP1     (0x00004000)   /*!< Timer A compare 1 */
#define HRTIM_CPT1CR_TA1CMP2     (0x00008000)   /*!< Timer A compare 2 */

#define HRTIM_CPT1CR_TB1SET      (0x00010000)   /*!< Timer B output 1 set */
#define HRTIM_CPT1CR_TB1RST      (0x00020000)   /*!< Timer B output 1 reset */
#define HRTIM_CPT1CR_TB1CMP1     (0x00040000)   /*!< Timer B compare 1 */
#define HRTIM_CPT1CR_TB1CMP2     (0x00080000)   /*!< Timer B compare 2 */

#define HRTIM_CPT1CR_TC1SET      (0x00100000)   /*!< Timer C output 1 set */
#define HRTIM_CPT1CR_TC1RST      (0x00200000)   /*!< Timer C output 1 reset */
#define HRTIM_CPT1CR_TC1CMP1     (0x00400000)   /*!< Timer C compare 1 */
#define HRTIM_CPT1CR_TC1CMP2     (0x00800000)   /*!< Timer C compare 2 */

#define HRTIM_CPT1CR_TD1SET      (0x01000000)   /*!< Timer D output 1 set */
#define HRTIM_CPT1CR_TD1RST      (0x02000000)   /*!< Timer D output 1 reset */
#define HRTIM_CPT1CR_TD1CMP1     (0x04000000)   /*!< Timer D compare 1 */
#define HRTIM_CPT1CR_TD1CMP2     (0x08000000)   /*!< Timer D compare 2 */

#define HRTIM_CPT1CR_TE1SET      (0x10000000)   /*!< Timer E output 1 set */
#define HRTIM_CPT1CR_TE1RST      (0x20000000)   /*!< Timer E output 1 reset */
#define HRTIM_CPT1CR_TE1CMP1     (0x40000000)   /*!< Timer E compare 1 */
#define HRTIM_CPT1CR_TE1CMP2     (0x80000000)   /*!< Timer E compare 2 */

#define HRTIM_CPT2CR_SWCPT       (0x00000001)   /*!< Software capture */
#define HRTIM_CPT2CR_UPDCPT      (0x00000002)   /*!< Update capture */
#define HRTIM_CPT2CR_EXEV1CPT    (0x00000004)   /*!< External event 1 capture */
#define HRTIM_CPT2CR_EXEV2CPT    (0x00000008)   /*!< External event 2 capture */
#define HRTIM_CPT2CR_EXEV3CPT    (0x00000010)   /*!< External event 3 capture */
#define HRTIM_CPT2CR_EXEV4CPT    (0x00000020)   /*!< External event 4 capture */
#define HRTIM_CPT2CR_EXEV5CPT    (0x00000040)   /*!< External event 5 capture */
#define HRTIM_CPT2CR_EXEV6CPT    (0x00000080)   /*!< External event 6 capture */
#define HRTIM_CPT2CR_EXEV7CPT    (0x00000100)   /*!< External event 7 capture */
#define HRTIM_CPT2CR_EXEV8CPT    (0x00000200)   /*!< External event 8 capture */
#define HRTIM_CPT2CR_EXEV9CPT    (0x00000400)   /*!< External event 9 capture */
#define HRTIM_CPT2CR_EXEV10CPT   (0x00000800)   /*!< External event 10 capture */

#define HRTIM_CPT2CR_TA1SET      (0x00001000)   /*!< Timer A output 1 set */
#define HRTIM_CPT2CR_TA1RST      (0x00002000)   /*!< Timer A output 1 reset */
#define HRTIM_CPT2CR_TA1CMP1     (0x00004000)   /*!< Timer A compare 1 */
#define HRTIM_CPT2CR_TA1CMP2     (0x00008000)   /*!< Timer A compare 2 */

#define HRTIM_CPT2CR_TB1SET      (0x00010000)   /*!< Timer B output 1 set */
#define HRTIM_CPT2CR_TB1RST      (0x00020000)   /*!< Timer B output 1 reset */
#define HRTIM_CPT2CR_TB1CMP1     (0x00040000)   /*!< Timer B compare 1 */
#define HRTIM_CPT2CR_TB1CMP2     (0x00080000)   /*!< Timer B compare 2 */

#define HRTIM_CPT2CR_TC1SET      (0x00100000)   /*!< Timer C output 1 set */
#define HRTIM_CPT2CR_TC1RST      (0x00200000)   /*!< Timer C output 1 reset */
#define HRTIM_CPT2CR_TC1CMP1     (0x00400000)   /*!< Timer C compare 1 */
#define HRTIM_CPT2CR_TC1CMP2     (0x00800000)   /*!< Timer C compare 2 */

#define HRTIM_CPT2CR_TD1SET      (0x01000000)   /*!< Timer D output 1 set */
#define HRTIM_CPT2CR_TD1RST      (0x02000000)   /*!< Timer D output 1 reset */
#define HRTIM_CPT2CR_TD1CMP1     (0x04000000)   /*!< Timer D compare 1 */
#define HRTIM_CPT2CR_TD1CMP2     (0x08000000)   /*!< Timer D compare 2 */

#define HRTIM_CPT2CR_TE1SET      (0x10000000)   /*!< Timer E output 1 set */
#define HRTIM_CPT2CR_TE1RST      (0x20000000)   /*!< Timer E output 1 reset */
#define HRTIM_CPT2CR_TE1CMP1     (0x40000000)   /*!< Timer E compare 1 */
#define HRTIM_CPT2CR_TE1CMP2     (0x80000000)   /*!< Timer E compare 2 */

#define HRTIM_OUTR_POL1       (0x00000002)    /*!< Slave output 1 polarity */
#define HRTIM_OUTR_IDLM1      (0x00000004)   /*!< Slave output 1 idle mode */
#define HRTIM_OUTR_IDLES1     (0x00000008)   /*!< Slave output 1 idle state */
#define HRTIM_OUTR_FAULT1     (0x00000030)   /*!< Slave output 1 fault state */
#define HRTIM_OUTR_FAULT1_0   (0x00000010)   /*!< Slave output 1 fault state bit 0 */
#define HRTIM_OUTR_FAULT1_1   (0x00000020)   /*!< Slave output 1 fault state bit 1 */
#define HRTIM_OUTR_CHP1       (0x00000040)   /*!< Slave output 1 chopper enable */
#define HRTIM_OUTR_DIDL1      (0x00000080)   /*!< Slave output 1 dead time idle */

#define HRTIM_OUTR_DTEN      (0x00000100)   /*!< Slave output deadtime enable */
#define HRTIM_OUTR_DLYPRTEN  (0x00000200)   /*!< Slave output delay protection enable */
#define HRTIM_OUTR_DLYPRT    (0x00001C00)   /*!< Slave output delay protection */
#define HRTIM_OUTR_DLYPRT_0  (0x00000400)   /*!< Slave output delay protection bit 0 */
#define HRTIM_OUTR_DLYPRT_1  (0x00000800)   /*!< Slave output delay protection bit 1 */
#define HRTIM_OUTR_DLYPRT_2  (0x00001000)   /*!< Slave output delay protection bit 2 */

#define HRTIM_OUTR_POL2      (0x00020000)   /*!< Slave output 2 polarity */
#define HRTIM_OUTR_IDLM2     (0x00040000)   /*!< Slave output 2 idle mode */
#define HRTIM_OUTR_IDLES2    (0x00080000)   /*!< Slave output 2 idle state */
#define HRTIM_OUTR_FAULT2    (0x00300000)   /*!< Slave output 2 fault state */
#define HRTIM_OUTR_FAULT2_0  (0x00100000)   /*!< Slave output 2 fault state bit 0 */
#define HRTIM_OUTR_FAULT2_1  (0x00200000)   /*!< Slave output 2 fault state bit 1 */
#define HRTIM_OUTR_CHP2      (0x00400000)   /*!< Slave output 2 chopper enable */
#define HRTIM_OUTR_DIDL2     (0x00800000)   /*!< Slave output 2 dead time idle */

#define HRTIM_FLTR_FLT1EN     (0x00000001)   /*!< Fault 1 enable */
#define HRTIM_FLTR_FLT2EN     (0x00000002)   /*!< Fault 2 enable */
#define HRTIM_FLTR_FLT3EN     (0x00000004)   /*!< Fault 3 enable */
#define HRTIM_FLTR_FLT4EN     (0x00000008)   /*!< Fault 4 enable */
#define HRTIM_FLTR_FLT5EN     (0x00000010)   /*!< Fault 5 enable */
#define HRTIM_FLTR_FLTCLK     (0x80000000)   /*!< Fault sources lock */

#define HRTIM_CR1_MUDIS       (0x00000001)   /*!< Master update disable*/
#define HRTIM_CR1_TAUDIS      (0x00000002)   /*!< Timer A update disable*/
#define HRTIM_CR1_TBUDIS      (0x00000004)   /*!< Timer B update disable*/
#define HRTIM_CR1_TCUDIS      (0x00000008)   /*!< Timer C update disable*/
#define HRTIM_CR1_TDUDIS      (0x00000010)   /*!< Timer D update disable*/
#define HRTIM_CR1_TEUDIS      (0x00000020)   /*!< Timer E update disable*/
#define HRTIM_CR1_ADC1USRC    (0x00070000)   /*!< ADC Trigger 1 update source */
#define HRTIM_CR1_ADC1USRC_0  (0x00010000)   /*!< ADC Trigger 1 update source bit 0 */
#define HRTIM_CR1_ADC1USRC_1  (0x00020000)   /*!< ADC Trigger 1 update source bit 1 */
#define HRTIM_CR1_ADC1USRC_2  (0x00040000)   /*!< ADC Trigger 1 update source bit 2 */
#define HRTIM_CR1_ADC2USRC    (0x00380000)   /*!< ADC Trigger 2 update source */
#define HRTIM_CR1_ADC2USRC_0  (0x00080000)   /*!< ADC Trigger 2 update source bit 0 */
#define HRTIM_CR1_ADC2USRC_1  (0x00100000)   /*!< ADC Trigger 2 update source bit 1 */
#define HRTIM_CR1_ADC2USRC_2  (0x00200000)   /*!< ADC Trigger 2 update source bit 2 */
#define HRTIM_CR1_ADC3USRC    (0x01C00000)   /*!< ADC Trigger 3 update source */
#define HRTIM_CR1_ADC3USRC_0  (0x00400000)   /*!< ADC Trigger 3 update source bit 0 */
#define HRTIM_CR1_ADC3USRC_1  (0x00800000)   /*!< ADC Trigger 3 update source bit 1 */
#define HRTIM_CR1_ADC3USRC_2  (0x01000000)   /*!< ADC Trigger 3 update source bit 2 */
#define HRTIM_CR1_ADC4USRC    (0x0E000000)   /*!< ADC Trigger 4 update source */
#define HRTIM_CR1_ADC4USRC_0  (0x02000000)   /*!< ADC Trigger 4 update source bit 0 */
#define HRTIM_CR1_ADC4USRC_1  (0x04000000)   /*!< ADC Trigger 4 update source bit 1 */
#define HRTIM_CR1_ADC4USRC_2  (0x0800000)   /*!< ADC Trigger 4 update source bit 2 */

#define HRTIM_CR2_MSWU   (0x00000001)        /*!< Master software update */
#define HRTIM_CR2_TASWU  (0x00000002)        /*!< Timer A software update */
#define HRTIM_CR2_TBSWU  (0x00000004)        /*!< Timer B software update */
#define HRTIM_CR2_TCSWU  (0x00000008)        /*!< Timer C software update */
#define HRTIM_CR2_TDSWU  (0x00000010)        /*!< Timer D software update */
#define HRTIM_CR2_TESWU  (0x00000020)        /*!< Timer E software update */
#define HRTIM_CR2_MRST   (0x00000100)        /*!< Master count software reset */
#define HRTIM_CR2_TARST  (0x00000200)        /*!< Timer A count software reset */
#define HRTIM_CR2_TBRST  (0x00000400)        /*!< Timer B count software reset */
#define HRTIM_CR2_TCRST  (0x00000800)        /*!< Timer C count software reset */
#define HRTIM_CR2_TDRST  (0x00001000)        /*!< Timer D count software reset */
#define HRTIM_CR2_TERST  (0x00002000)        /*!< Timer E count software reset */

#define HRTIM_ISR_FLT1    (0x00000001)   /*!< Fault 1 interrupt flag */
#define HRTIM_ISR_FLT2    (0x00000002)   /*!< Fault 2 interrupt flag */
#define HRTIM_ISR_FLT3    (0x00000004)   /*!< Fault 3 interrupt flag */
#define HRTIM_ISR_FLT4    (0x00000008)   /*!< Fault 4 interrupt flag */
#define HRTIM_ISR_FLT5    (0x00000010)   /*!< Fault 5 interrupt flag */
#define HRTIM_ISR_SYSFLT  (0x00000020)   /*!< System Fault interrupt flag */
#define HRTIM_ISR_DLLRDY  (0x00010000)   /*!< DLL ready interrupt flag */
#define HRTIM_ISR_BMPER   (0x00020000)   /*!<  Burst mode period interrupt flag */

#define HRTIM_ICR_FLT1C    (0x00000001)   /*!< Fault 1 interrupt flag clear */
#define HRTIM_ICR_FLT2C    (0x00000002)   /*!< Fault 2 interrupt flag clear */
#define HRTIM_ICR_FLT3C    (0x00000004)   /*!< Fault 3 interrupt flag clear */
#define HRTIM_ICR_FLT4C    (0x00000008)   /*!< Fault 4 interrupt flag clear */
#define HRTIM_ICR_FLT5C    (0x00000010)   /*!< Fault 5 interrupt flag clear */
#define HRTIM_ICR_SYSFLTC  (0x00000020)   /*!< System Fault interrupt flag clear */
#define HRTIM_ICR_DLLRDYC  (0x00010000)   /*!< DLL ready interrupt flag clear */
#define HRTIM_ICR_BMPERC   (0x00020000)   /*!<  Burst mode period interrupt flag clear */

#define HRTIM_IER_FLT1    (0x00000001)   /*!< Fault 1 interrupt enable */
#define HRTIM_IER_FLT2    (0x00000002)   /*!< Fault 2 interrupt enable */
#define HRTIM_IER_FLT3    (0x00000004)   /*!< Fault 3 interrupt enable */
#define HRTIM_IER_FLT4    (0x00000008)   /*!< Fault 4 interrupt enable */
#define HRTIM_IER_FLT5    (0x00000010)   /*!< Fault 5 interrupt enable */
#define HRTIM_IER_SYSFLT  (0x00000020)   /*!< System Fault interrupt enable */
#define HRTIM_IER_DLLRDY  (0x00010000)   /*!< DLL ready interrupt enable */
#define HRTIM_IER_BMPER   (0x00020000)   /*!<  Burst mode period interrupt enable */

#define HRTIM_OENR_TA1OEN    (0x00000001)   /*!< Timer A Output 1 enable */
#define HRTIM_OENR_TA2OEN    (0x00000002)   /*!< Timer A Output 2 enable */
#define HRTIM_OENR_TB1OEN    (0x00000004)   /*!< Timer B Output 1 enable */
#define HRTIM_OENR_TB2OEN    (0x00000008)   /*!< Timer B Output 2 enable */
#define HRTIM_OENR_TC1OEN    (0x00000010)   /*!< Timer C Output 1 enable */
#define HRTIM_OENR_TC2OEN    (0x00000020)   /*!< Timer C Output 2 enable */
#define HRTIM_OENR_TD1OEN    (0x00000040)   /*!< Timer D Output 1 enable */
#define HRTIM_OENR_TD2OEN    (0x00000080)   /*!< Timer D Output 2 enable */
#define HRTIM_OENR_TE1OEN    (0x00000100)   /*!< Timer E Output 1 enable */
#define HRTIM_OENR_TE2OEN    (0x00000200)   /*!< Timer E Output 2 enable */

#define HRTIM_ODISR_TA1ODIS    (0x00000001)   /*!< Timer A Output 1 disable */
#define HRTIM_ODISR_TA2ODIS    (0x00000002)   /*!< Timer A Output 2 disable */
#define HRTIM_ODISR_TB1ODIS    (0x00000004)   /*!< Timer B Output 1 disable */
#define HRTIM_ODISR_TB2ODIS    (0x00000008)   /*!< Timer B Output 2 disable */
#define HRTIM_ODISR_TC1ODIS    (0x00000010)   /*!< Timer C Output 1 disable */
#define HRTIM_ODISR_TC2ODIS    (0x00000020)   /*!< Timer C Output 2 disable */
#define HRTIM_ODISR_TD1ODIS    (0x00000040)   /*!< Timer D Output 1 disable */
#define HRTIM_ODISR_TD2ODIS    (0x00000080)   /*!< Timer D Output 2 disable */
#define HRTIM_ODISR_TE1ODIS    (0x00000100)   /*!< Timer E Output 1 disable */
#define HRTIM_ODISR_TE2ODIS    (0x00000200)   /*!< Timer E Output 2 disable */

#define HRTIM_ODSR_TA1ODS    (0x00000001)   /*!< Timer A Output 1 disable status */
#define HRTIM_ODSR_TA2ODS    (0x00000002)   /*!< Timer A Output 2 disable status */
#define HRTIM_ODSR_TB1ODS    (0x00000004)   /*!< Timer B Output 1 disable status */
#define HRTIM_ODSR_TB2ODS    (0x00000008)   /*!< Timer B Output 2 disable status */
#define HRTIM_ODSR_TC1ODS    (0x00000010)   /*!< Timer C Output 1 disable status */
#define HRTIM_ODSR_TC2ODS    (0x00000020)   /*!< Timer C Output 2 disable status */
#define HRTIM_ODSR_TD1ODS    (0x00000040)   /*!< Timer D Output 1 disable status */
#define HRTIM_ODSR_TD2ODS    (0x00000080)   /*!< Timer D Output 2 disable status */
#define HRTIM_ODSR_TE1ODS    (0x00000100)   /*!< Timer E Output 1 disable status */
#define HRTIM_ODSR_TE2ODS    (0x00000200)   /*!< Timer E Output 2 disable status */

#define HRTIM_BMCR_BME       (0x00000001)    /*!< Burst mode enable */
#define HRTIM_BMCR_BMOM      (0x00000002)    /*!< Burst mode operating mode */
#define HRTIM_BMCR_BMCLK     (0x0000003C)    /*!< Burst mode clock source */
#define HRTIM_BMCR_BMCLK_0   (0x00000004)    /*!< Burst mode clock source bit 0 */
#define HRTIM_BMCR_BMCLK_1   (0x00000008)    /*!< Burst mode clock source bit 1 */
#define HRTIM_BMCR_BMCLK_2   (0x00000010)    /*!< Burst mode clock source bit 2 */
#define HRTIM_BMCR_BMCLK_3   (0x00000020)    /*!< Burst mode clock source bit 3 */
#define HRTIM_BMCR_BMPSC     (0x000003C0)    /*!< Burst mode prescaler */
#define HRTIM_BMCR_BMPSC_0   (0x00000040)    /*!< Burst mode prescaler bit 0 */
#define HRTIM_BMCR_BMPSC_1   (0x00000080)    /*!< Burst mode prescaler bit 1 */
#define HRTIM_BMCR_BMPSC_2   (0x00000100)    /*!< Burst mode prescaler bit 2 */
#define HRTIM_BMCR_BMPSC_3   (0x00000200)    /*!< Burst mode prescaler bit 3 */
#define HRTIM_BMCR_BMPREN    (0x00000400)    /*!< Burst mode Preload bit */
#define HRTIM_BMCR_MTBM      (0x00010000)    /*!< Master Timer Burst mode */
#define HRTIM_BMCR_TABM      (0x00020000)    /*!< Timer A Burst mode */
#define HRTIM_BMCR_TBBM      (0x00040000)    /*!< Timer B Burst mode */
#define HRTIM_BMCR_TCBM      (0x00080000)    /*!< Timer C Burst mode */
#define HRTIM_BMCR_TDBM      (0x00100000)    /*!< Timer D Burst mode */
#define HRTIM_BMCR_TEBM      (0x00200000)    /*!< Timer E Burst mode */
#define HRTIM_BMCR_BMSTAT    (0x80000000)    /*!< Burst mode status */

#define HRTIM_BMTRGR_SW       (0x00000001)    /*!< Software start */
#define HRTIM_BMTRGR_MSTRST   (0x00000002)    /*!<  Master reset */
#define HRTIM_BMTRGR_MSTREP   (0x00000004)    /*!<  Master repetition */
#define HRTIM_BMTRGR_MSTCMP1  (0x00000008)    /*!<  Master compare 1 */
#define HRTIM_BMTRGR_MSTCMP2  (0x00000010)    /*!< Master compare 2  */
#define HRTIM_BMTRGR_MSTCMP3  (0x00000020)    /*!< Master compare 3 */
#define HRTIM_BMTRGR_MSTCMP4  (0x00000040)    /*!< Master compare 4 */
#define HRTIM_BMTRGR_TARST    (0x00000080)    /*!< Timer A reset  */
#define HRTIM_BMTRGR_TAREP    (0x00000100)    /*!< Timer A repetition  */
#define HRTIM_BMTRGR_TACMP1   (0x00000200)    /*!< Timer A compare 1  */
#define HRTIM_BMTRGR_TACMP2   (0x00000400)    /*!< Timer A compare 2  */
#define HRTIM_BMTRGR_TBRST    (0x00000800)    /*!< Timer B reset  */
#define HRTIM_BMTRGR_TBREP    (0x00001000)    /*!< Timer B repetition  */
#define HRTIM_BMTRGR_TBCMP1   (0x00002000)    /*!< Timer B compare 1 */
#define HRTIM_BMTRGR_TBCMP2   (0x00004000)    /*!< Timer B compare 2 */
#define HRTIM_BMTRGR_TCRST    (0x00008000)    /*!< Timer C reset  */
#define HRTIM_BMTRGR_TCREP    (0x00010000)    /*!< Timer C repetition */
#define HRTIM_BMTRGR_TCCMP1   (0x00020000)    /*!< Timer C compare 1 */
#define HRTIM_BMTRGR_TCCMP2   (0x00040000)    /*!< Timer C compare 2 */
#define HRTIM_BMTRGR_TDRST    (0x00080000)    /*!< Timer D reset  */
#define HRTIM_BMTRGR_TDREP    (0x00100000)    /*!< Timer D repetition  */
#define HRTIM_BMTRGR_TDCMP1   (0x00200000)    /*!< Timer D compare 1 */
#define HRTIM_BMTRGR_TDCMP2   (0x00400000)    /*!< Timer D compare 2 */
#define HRTIM_BMTRGR_TERST    (0x00800000)    /*!< Timer E reset  */
#define HRTIM_BMTRGR_TEREP    (0x01000000)    /*!< Timer E repetition  */
#define HRTIM_BMTRGR_TECMP1   (0x02000000)    /*!< Timer E compare 1 */
#define HRTIM_BMTRGR_TECMP2   (0x04000000)    /*!< Timer E compare 2 */
#define HRTIM_BMTRGR_TAEEV7   (0x08000000)    /*!< Timer A period following External Event7  */
#define HRTIM_BMTRGR_TDEEV8   (0x10000000)    /*!< Timer D period following External Event8  */
#define HRTIM_BMTRGR_EEV7     (0x20000000)    /*!< External Event 7 */
#define HRTIM_BMTRGR_EEV8     (0x40000000)    /*!< External Event 8 */
#define HRTIM_BMTRGR_OCHPEV   (0x80000000)    /*!< on-chip Event */

#define  HRTIM_BMCMPR_BMCMPR     (0x0000FFFF)     /*!<!<Burst Compare Value */

#define  HRTIM_BMPER_BMPER     (0x0000FFFF)     /*!<!<Burst period Value */

#define HRTIM_EECR1_EE1SRC    (0x00000003)    /*!< External event 1 source */
#define HRTIM_EECR1_EE1SRC_0  (0x00000001)    /*!< External event 1 source bit 0 */
#define HRTIM_EECR1_EE1SRC_1  (0x00000002)    /*!< External event 1 source bit 1 */
#define HRTIM_EECR1_EE1POL    (0x00000004)    /*!< External event 1 Polarity */
#define HRTIM_EECR1_EE1SNS    (0x00000018)    /*!< External event 1 sensitivity */
#define HRTIM_EECR1_EE1SNS_0  (0x00000008)    /*!< External event 1 sensitivity bit 0 */
#define HRTIM_EECR1_EE1SNS_1  (0x00000010)    /*!< External event 1 sensitivity bit 1 */
#define HRTIM_EECR1_EE1FAST   (0x00000020)    /*!< External event 1 Fast mode */

#define HRTIM_EECR1_EE2SRC    (0x000000C0)    /*!< External event 2 source */
#define HRTIM_EECR1_EE2SRC_0  (0x00000040)    /*!< External event 2 source bit 0 */
#define HRTIM_EECR1_EE2SRC_1  (0x00000080)    /*!< External event 2 source bit 1 */
#define HRTIM_EECR1_EE2POL    (0x00000100)    /*!< External event 2 Polarity */
#define HRTIM_EECR1_EE2SNS    (0x00000600)    /*!< External event 2 sensitivity */
#define HRTIM_EECR1_EE2SNS_0  (0x00000200)    /*!< External event 2 sensitivity bit 0 */
#define HRTIM_EECR1_EE2SNS_1  (0x00000400)    /*!< External event 2 sensitivity bit 1 */
#define HRTIM_EECR1_EE2FAST   (0x00000800)    /*!< External event 2 Fast mode */

#define HRTIM_EECR1_EE3SRC    (0x00003000)    /*!< External event 3 source */
#define HRTIM_EECR1_EE3SRC_0  (0x00001000)    /*!< External event 3 source bit 0 */
#define HRTIM_EECR1_EE3SRC_1  (0x00002000)    /*!< External event 3 source bit 1 */
#define HRTIM_EECR1_EE3POL    (0x00004000)    /*!< External event 3 Polarity */
#define HRTIM_EECR1_EE3SNS    (0x00018000)    /*!< External event 3 sensitivity */
#define HRTIM_EECR1_EE3SNS_0  (0x00008000)    /*!< External event 3 sensitivity bit 0 */
#define HRTIM_EECR1_EE3SNS_1  (0x00010000)    /*!< External event 3 sensitivity bit 1 */
#define HRTIM_EECR1_EE3FAST   (0x00020000)    /*!< External event 3 Fast mode */

#define HRTIM_EECR1_EE4SRC    (0x000C0000)    /*!< External event 4 source */
#define HRTIM_EECR1_EE4SRC_0  (0x00040000)    /*!< External event 4 source bit 0 */
#define HRTIM_EECR1_EE4SRC_1  (0x00080000)    /*!< External event 4 source bit 1 */
#define HRTIM_EECR1_EE4POL    (0x00100000)    /*!< External event 4 Polarity */
#define HRTIM_EECR1_EE4SNS    (0x00600000)    /*!< External event 4 sensitivity */
#define HRTIM_EECR1_EE4SNS_0  (0x00200000)    /*!< External event 4 sensitivity bit 0 */
#define HRTIM_EECR1_EE4SNS_1  (0x00400000)    /*!< External event 4 sensitivity bit 1 */
#define HRTIM_EECR1_EE4FAST   (0x00800000)    /*!< External event 4 Fast mode */

#define HRTIM_EECR1_EE5SRC    (0x03000000)    /*!< External event 5 source */
#define HRTIM_EECR1_EE5SRC_0  (0x01000000)    /*!< External event 5 source bit 0 */
#define HRTIM_EECR1_EE5SRC_1  (0x02000000)    /*!< External event 5 source bit 1 */
#define HRTIM_EECR1_EE5POL    (0x04000000)    /*!< External event 5 Polarity */
#define HRTIM_EECR1_EE5SNS    (0x18000000)    /*!< External event 5 sensitivity */
#define HRTIM_EECR1_EE5SNS_0  (0x08000000)    /*!< External event 5 sensitivity bit 0 */
#define HRTIM_EECR1_EE5SNS_1  (0x10000000)    /*!< External event 5 sensitivity bit 1 */
#define HRTIM_EECR1_EE5FAST   (0x20000000)    /*!< External event 5 Fast mode */

#define HRTIM_EECR2_EE6SRC    (0x00000003)    /*!< External event 6 source */
#define HRTIM_EECR2_EE6SRC_0  (0x00000001)    /*!< External event 6 source bit 0 */
#define HRTIM_EECR2_EE6SRC_1  (0x00000002)    /*!< External event 6 source bit 1 */
#define HRTIM_EECR2_EE6POL    (0x00000004)    /*!< External event 6 Polarity */
#define HRTIM_EECR2_EE6SNS    (0x00000018)    /*!< External event 6 sensitivity */
#define HRTIM_EECR2_EE6SNS_0  (0x00000008)    /*!< External event 6 sensitivity bit 0 */
#define HRTIM_EECR2_EE6SNS_1  (0x00000010)    /*!< External event 6 sensitivity bit 1 */

#define HRTIM_EECR2_EE7SRC    (0x000000C0)    /*!< External event 7 source */
#define HRTIM_EECR2_EE7SRC_0  (0x00000040)    /*!< External event 7 source bit 0 */
#define HRTIM_EECR2_EE7SRC_1  (0x00000080)    /*!< External event 7 source bit 1 */
#define HRTIM_EECR2_EE7POL    (0x00000100)    /*!< External event 7 Polarity */
#define HRTIM_EECR2_EE7SNS    (0x00000600)    /*!< External event 7 sensitivity */
#define HRTIM_EECR2_EE7SNS_0  (0x00000200)    /*!< External event 7 sensitivity bit 0 */
#define HRTIM_EECR2_EE7SNS_1  (0x00000400)    /*!< External event 7 sensitivity bit 1 */

#define HRTIM_EECR2_EE8SRC    (0x00003000)    /*!< External event 8 source */
#define HRTIM_EECR2_EE8SRC_0  (0x00001000)    /*!< External event 8 source bit 0 */
#define HRTIM_EECR2_EE8SRC_1  (0x00002000)    /*!< External event 8 source bit 1 */
#define HRTIM_EECR2_EE8POL    (0x00004000)    /*!< External event 8 Polarity */
#define HRTIM_EECR2_EE8SNS    (0x00018000)    /*!< External event 8 sensitivity */
#define HRTIM_EECR2_EE8SNS_0  (0x00008000)    /*!< External event 8 sensitivity bit 0 */
#define HRTIM_EECR2_EE8SNS_1  (0x00010000)    /*!< External event 8 sensitivity bit 1 */

#define HRTIM_EECR2_EE9SRC    (0x000C0000)    /*!< External event 9 source */
#define HRTIM_EECR2_EE9SRC_0  (0x00040000)    /*!< External event 9 source bit 0 */
#define HRTIM_EECR2_EE9SRC_1  (0x00080000)    /*!< External event 9 source bit 1 */
#define HRTIM_EECR2_EE9POL    (0x00100000)    /*!< External event 9 Polarity */
#define HRTIM_EECR2_EE9SNS    (0x00600000)    /*!< External event 9 sensitivity */
#define HRTIM_EECR2_EE9SNS_0  (0x00200000)    /*!< External event 9 sensitivity bit 0 */
#define HRTIM_EECR2_EE9SNS_1  (0x00400000)    /*!< External event 9 sensitivity bit 1 */

#define HRTIM_EECR2_EE10SRC    (0x03000000)    /*!< External event 10 source */
#define HRTIM_EECR2_EE10SRC_0  (0x01000000)    /*!< External event 10 source bit 0 */
#define HRTIM_EECR2_EE10SRC_1  (0x02000000)    /*!< External event 10 source bit 1 */
#define HRTIM_EECR2_EE10POL    (0x04000000)    /*!< External event 10 Polarity */
#define HRTIM_EECR2_EE10SNS    (0x18000000)    /*!< External event 10 sensitivity */
#define HRTIM_EECR2_EE10SNS_0  (0x08000000)    /*!< External event 10 sensitivity bit 0 */
#define HRTIM_EECR2_EE10SNS_1  (0x10000000)    /*!< External event 10 sensitivity bit 1 */

#define HRTIM_EECR3_EE6F    (0x0000000F)    /*!< External event 6 filter */
#define HRTIM_EECR3_EE6F_0  (0x00000001)    /*!< External event 6 filter bit 0 */
#define HRTIM_EECR3_EE6F_1  (0x00000002)    /*!< External event 6 filter bit 1  */
#define HRTIM_EECR3_EE6F_2  (0x00000004)    /*!< External event 6 filter bit 2   */
#define HRTIM_EECR3_EE6F_3  (0x00000008)    /*!< External event 6 filter bit 3   */
#define HRTIM_EECR3_EE7F    (0x000003C0)    /*!< External event 7 filter */
#define HRTIM_EECR3_EE7F_0  (0x00000040)    /*!< External event 7 filter bit 0  */
#define HRTIM_EECR3_EE7F_1  (0x00000080)    /*!< External event 7 filter bit 1  */
#define HRTIM_EECR3_EE7F_2  (0x00000100)    /*!< External event 7 filter bit 2  */
#define HRTIM_EECR3_EE7F_3  (0x00000200)    /*!< External event 7 filter bit 3  */
#define HRTIM_EECR3_EE8F    (0x0000F000)    /*!< External event 8 filter */
#define HRTIM_EECR3_EE8F_0  (0x00001000)    /*!< External event 8 filter bit 0 */
#define HRTIM_EECR3_EE8F_1  (0x00002000)    /*!< External event 8 filter bit 1 */
#define HRTIM_EECR3_EE8F_2  (0x00004000)    /*!< External event 8 filter bit 2 */
#define HRTIM_EECR3_EE8F_3  (0x00008000)    /*!< External event 8 filter bit 3 */
#define HRTIM_EECR3_EE9F    (0x003C0000)    /*!< External event 9 filter */
#define HRTIM_EECR3_EE9F_0  (0x00040000)    /*!< External event 9 filter bit 0 */
#define HRTIM_EECR3_EE9F_1  (0x00080000)    /*!< External event 9 filter bit 1 */
#define HRTIM_EECR3_EE9F_2  (0x00100000)    /*!< External event 9 filter bit 2 */
#define HRTIM_EECR3_EE9F_3  (0x00200000)    /*!< External event 9 filter bit 3 */
#define HRTIM_EECR3_EE10F   (0x0F000000)    /*!< External event 10 filter */
#define HRTIM_EECR3_EE10F_0 (0x01000000)    /*!< External event 10 filter bit 0 */
#define HRTIM_EECR3_EE10F_1 (0x02000000)    /*!< External event 10 filter bit 1 */
#define HRTIM_EECR3_EE10F_2 (0x04000000)    /*!< External event 10 filter bit 2 */
#define HRTIM_EECR3_EE10F_3 (0x08000000)    /*!< External event 10 filter bit 3 */
#define HRTIM_EECR3_EEVSD   (0xC0000000)    /*!< External event sampling clock division */
#define HRTIM_EECR3_EEVSD_0 (0x40000000)    /*!< External event sampling clock division bit 0 */
#define HRTIM_EECR3_EEVSD_1 (0x80000000)    /*!< External event sampling clock division bit 1 */

#define HRTIM_ADC1R_AD1MC1     (0x00000001)    /*!< ADC Trigger 1 on master compare 1 */
#define HRTIM_ADC1R_AD1MC2     (0x00000002)    /*!< ADC Trigger 1 on master compare 2 */
#define HRTIM_ADC1R_AD1MC3     (0x00000004)    /*!< ADC Trigger 1 on master compare 3 */
#define HRTIM_ADC1R_AD1MC4     (0x00000008)    /*!< ADC Trigger 1 on master compare 4 */
#define HRTIM_ADC1R_AD1MPER    (0x00000010)    /*!< ADC Trigger 1 on master period */
#define HRTIM_ADC1R_AD1EEV1    (0x00000020)    /*!< ADC Trigger 1 on external event 1 */
#define HRTIM_ADC1R_AD1EEV2    (0x00000040)    /*!< ADC Trigger 1 on external event 2 */
#define HRTIM_ADC1R_AD1EEV3    (0x00000080)    /*!< ADC Trigger 1 on external event 3 */
#define HRTIM_ADC1R_AD1EEV4    (0x00000100)    /*!< ADC Trigger 1 on external event 4 */
#define HRTIM_ADC1R_AD1EEV5    (0x00000200)    /*!< ADC Trigger 1 on external event 5 */
#define HRTIM_ADC1R_AD1TAC2    (0x00000400)    /*!< ADC Trigger 1 on Timer A compare 2 */
#define HRTIM_ADC1R_AD1TAC3    (0x00000800)    /*!< ADC Trigger 1 on Timer A compare 3 */
#define HRTIM_ADC1R_AD1TAC4    (0x00001000)    /*!< ADC Trigger 1 on Timer A compare 4 */
#define HRTIM_ADC1R_AD1TAPER   (0x00002000)    /*!< ADC Trigger 1 on Timer A period */
#define HRTIM_ADC1R_AD1TARST   (0x00004000)    /*!< ADC Trigger 1 on Timer A reset */
#define HRTIM_ADC1R_AD1TBC2    (0x00008000)    /*!< ADC Trigger 1 on Timer B compare 2 */
#define HRTIM_ADC1R_AD1TBC3    (0x00010000)    /*!< ADC Trigger 1 on Timer B compare 3 */
#define HRTIM_ADC1R_AD1TBC4    (0x00020000)    /*!< ADC Trigger 1 on Timer B compare 4 */
#define HRTIM_ADC1R_AD1TBPER   (0x00040000)    /*!< ADC Trigger 1 on Timer B period */
#define HRTIM_ADC1R_AD1TBRST   (0x00080000)    /*!< ADC Trigger 1 on Timer B reset */
#define HRTIM_ADC1R_AD1TCC2    (0x00100000)    /*!< ADC Trigger 1 on Timer C compare 2 */
#define HRTIM_ADC1R_AD1TCC3    (0x00200000)    /*!< ADC Trigger 1 on Timer C compare 3 */
#define HRTIM_ADC1R_AD1TCC4    (0x00400000)    /*!< ADC Trigger 1 on Timer C compare 4 */
#define HRTIM_ADC1R_AD1TCPER   (0x00800000)    /*!< ADC Trigger 1 on Timer C period */
#define HRTIM_ADC1R_AD1TDC2    (0x01000000)    /*!< ADC Trigger 1 on Timer D compare 2 */
#define HRTIM_ADC1R_AD1TDC3    (0x02000000)    /*!< ADC Trigger 1 on Timer D compare 3 */
#define HRTIM_ADC1R_AD1TDC4    (0x04000000)    /*!< ADC Trigger 1 on Timer D compare 4 */
#define HRTIM_ADC1R_AD1TDPER   (0x08000000)    /*!< ADC Trigger 1 on Timer D period */
#define HRTIM_ADC1R_AD1TEC2    (0x10000000)    /*!< ADC Trigger 1 on Timer E compare 2 */
#define HRTIM_ADC1R_AD1TEC3    (0x20000000)    /*!< ADC Trigger 1 on Timer E compare 3 */
#define HRTIM_ADC1R_AD1TEC4    (0x40000000)    /*!< ADC Trigger 1 on Timer E compare 4 */
#define HRTIM_ADC1R_AD1TEPER   (0x80000000)    /*!< ADC Trigger 1 on Timer E period */

#define HRTIM_ADC2R_AD2MC1      (0x00000001)    /*!< ADC Trigger 2 on master compare 1 */
#define HRTIM_ADC2R_AD2MC2      (0x00000002)    /*!< ADC Trigger 2 on master compare 2 */
#define HRTIM_ADC2R_AD2MC3      (0x00000004)    /*!< ADC Trigger 2 on master compare 3 */
#define HRTIM_ADC2R_AD2MC4      (0x00000008)    /*!< ADC Trigger 2 on master compare 4 */
#define HRTIM_ADC2R_AD2MPER     (0x00000010)    /*!< ADC Trigger 2 on master period */
#define HRTIM_ADC2R_AD2EEV6     (0x00000020)    /*!< ADC Trigger 2 on external event 6 */
#define HRTIM_ADC2R_AD2EEV7     (0x00000040)    /*!< ADC Trigger 2 on external event 7 */
#define HRTIM_ADC2R_AD2EEV8     (0x00000080)    /*!< ADC Trigger 2 on external event 8 */
#define HRTIM_ADC2R_AD2EEV9     (0x00000100)    /*!< ADC Trigger 2 on external event 9 */
#define HRTIM_ADC2R_AD2EEV10    (0x00000200)    /*!< ADC Trigger 2 on external event 10 */
#define HRTIM_ADC2R_AD2TAC2     (0x00000400)    /*!< ADC Trigger 2 on Timer A compare 2 */
#define HRTIM_ADC2R_AD2TAC3     (0x00000800)    /*!< ADC Trigger 2 on Timer A compare 3 */
#define HRTIM_ADC2R_AD2TAC4     (0x00001000)    /*!< ADC Trigger 2 on Timer A compare 4*/
#define HRTIM_ADC2R_AD2TAPER    (0x00002000)    /*!< ADC Trigger 2 on Timer A period */
#define HRTIM_ADC2R_AD2TBC2     (0x00004000)    /*!< ADC Trigger 2 on Timer B compare 2 */
#define HRTIM_ADC2R_AD2TBC3     (0x00008000)    /*!< ADC Trigger 2 on Timer B compare 3 */
#define HRTIM_ADC2R_AD2TBC4     (0x00010000)    /*!< ADC Trigger 2 on Timer B compare 4 */
#define HRTIM_ADC2R_AD2TBPER    (0x00020000)    /*!< ADC Trigger 2 on Timer B period */
#define HRTIM_ADC2R_AD2TCC2     (0x00040000)    /*!< ADC Trigger 2 on Timer C compare 2 */
#define HRTIM_ADC2R_AD2TCC3     (0x00080000)    /*!< ADC Trigger 2 on Timer C compare 3 */
#define HRTIM_ADC2R_AD2TCC4     (0x00100000)    /*!< ADC Trigger 2 on Timer C compare 4 */
#define HRTIM_ADC2R_AD2TCPER    (0x00200000)    /*!< ADC Trigger 2 on Timer C period */
#define HRTIM_ADC2R_AD2TCRST    (0x00400000)    /*!< ADC Trigger 2 on Timer C reset */
#define HRTIM_ADC2R_AD2TDC2     (0x00800000)    /*!< ADC Trigger 2 on Timer D compare 2 */
#define HRTIM_ADC2R_AD2TDC3     (0x01000000)    /*!< ADC Trigger 2 on Timer D compare 3 */
#define HRTIM_ADC2R_AD2TDC4     (0x02000000)    /*!< ADC Trigger 2 on Timer D compare 4*/
#define HRTIM_ADC2R_AD2TDPER    (0x04000000)    /*!< ADC Trigger 2 on Timer D period */
#define HRTIM_ADC2R_AD2TDRST    (0x08000000)    /*!< ADC Trigger 2 on Timer D reset */
#define HRTIM_ADC2R_AD2TEC2     (0x10000000)    /*!< ADC Trigger 2 on Timer E compare 2 */
#define HRTIM_ADC2R_AD2TEC3     (0x20000000)    /*!< ADC Trigger 2 on Timer E compare 3 */
#define HRTIM_ADC2R_AD2TEC4     (0x40000000)    /*!< ADC Trigger 2 on Timer E compare 4 */
#define HRTIM_ADC2R_AD2TERST    (0x80000000)    /*!< ADC Trigger 2 on Timer E reset */

#define HRTIM_ADC3R_AD3MC1     (0x00000001)    /*!< ADC Trigger 3 on master compare 1 */
#define HRTIM_ADC3R_AD3MC2     (0x00000002)    /*!< ADC Trigger 3 on master compare 2 */
#define HRTIM_ADC3R_AD3MC3     (0x00000004)    /*!< ADC Trigger 3 on master compare 3 */
#define HRTIM_ADC3R_AD3MC4     (0x00000008)    /*!< ADC Trigger 3 on master compare 4 */
#define HRTIM_ADC3R_AD3MPER    (0x00000010)    /*!< ADC Trigger 3 on master period */
#define HRTIM_ADC3R_AD3EEV1    (0x00000020)    /*!< ADC Trigger 3 on external event 1 */
#define HRTIM_ADC3R_AD3EEV2    (0x00000040)    /*!< ADC Trigger 3 on external event 2 */
#define HRTIM_ADC3R_AD3EEV3    (0x00000080)    /*!< ADC Trigger 3 on external event 3 */
#define HRTIM_ADC3R_AD3EEV4    (0x00000100)    /*!< ADC Trigger 3 on external event 4 */
#define HRTIM_ADC3R_AD3EEV5    (0x00000200)    /*!< ADC Trigger 3 on external event 5 */
#define HRTIM_ADC3R_AD3TAC2    (0x00000400)    /*!< ADC Trigger 3 on Timer A compare 2 */
#define HRTIM_ADC3R_AD3TAC3    (0x00000800)    /*!< ADC Trigger 3 on Timer A compare 3 */
#define HRTIM_ADC3R_AD3TAC4    (0x00001000)    /*!< ADC Trigger 3 on Timer A compare 4 */
#define HRTIM_ADC3R_AD3TAPER   (0x00002000)    /*!< ADC Trigger 3 on Timer A period */
#define HRTIM_ADC3R_AD3TARST   (0x00004000)    /*!< ADC Trigger 3 on Timer A reset */
#define HRTIM_ADC3R_AD3TBC2    (0x00008000)    /*!< ADC Trigger 3 on Timer B compare 2 */
#define HRTIM_ADC3R_AD3TBC3    (0x00010000)    /*!< ADC Trigger 3 on Timer B compare 3 */
#define HRTIM_ADC3R_AD3TBC4    (0x00020000)    /*!< ADC Trigger 3 on Timer B compare 4 */
#define HRTIM_ADC3R_AD3TBPER   (0x00040000)    /*!< ADC Trigger 3 on Timer B period */
#define HRTIM_ADC3R_AD3TBRST   (0x00080000)    /*!< ADC Trigger 3 on Timer B reset */
#define HRTIM_ADC3R_AD3TCC2    (0x00100000)    /*!< ADC Trigger 3 on Timer C compare 2 */
#define HRTIM_ADC3R_AD3TCC3    (0x00200000)    /*!< ADC Trigger 3 on Timer C compare 3 */
#define HRTIM_ADC3R_AD3TCC4    (0x00400000)    /*!< ADC Trigger 3 on Timer C compare 4 */
#define HRTIM_ADC3R_AD3TCPER   (0x00800000)    /*!< ADC Trigger 3 on Timer C period */
#define HRTIM_ADC3R_AD3TDC2    (0x01000000)    /*!< ADC Trigger 3 on Timer D compare 2 */
#define HRTIM_ADC3R_AD3TDC3    (0x02000000)    /*!< ADC Trigger 3 on Timer D compare 3 */
#define HRTIM_ADC3R_AD3TDC4    (0x04000000)    /*!< ADC Trigger 3 on Timer D compare 4 */
#define HRTIM_ADC3R_AD3TDPER   (0x08000000)    /*!< ADC Trigger 3 on Timer D period */
#define HRTIM_ADC3R_AD3TEC2    (0x10000000)    /*!< ADC Trigger 3 on Timer E compare 2 */
#define HRTIM_ADC3R_AD3TEC3    (0x20000000)    /*!< ADC Trigger 3 on Timer E compare 3 */
#define HRTIM_ADC3R_AD3TEC4    (0x40000000)    /*!< ADC Trigger 3 on Timer E compare 4 */
#define HRTIM_ADC3R_AD3TEPER   (0x80000000)    /*!< ADC Trigger 3 on Timer E period */

#define HRTIM_ADC4R_AD4MC1      (0x00000001)    /*!< ADC Trigger 4 on master compare 1 */
#define HRTIM_ADC4R_AD4MC2      (0x00000002)    /*!< ADC Trigger 4 on master compare 2 */
#define HRTIM_ADC4R_AD4MC3      (0x00000004)    /*!< ADC Trigger 4 on master compare 3 */
#define HRTIM_ADC4R_AD4MC4      (0x00000008)    /*!< ADC Trigger 4 on master compare 4 */
#define HRTIM_ADC4R_AD4MPER     (0x00000010)    /*!< ADC Trigger 4 on master period */
#define HRTIM_ADC4R_AD4EEV6     (0x00000020)    /*!< ADC Trigger 4 on external event 6 */
#define HRTIM_ADC4R_AD4EEV7     (0x00000040)    /*!< ADC Trigger 4 on external event 7 */
#define HRTIM_ADC4R_AD4EEV8     (0x00000080)    /*!< ADC Trigger 4 on external event 8 */
#define HRTIM_ADC4R_AD4EEV9     (0x00000100)    /*!< ADC Trigger 4 on external event 9 */
#define HRTIM_ADC4R_AD4EEV10    (0x00000200)    /*!< ADC Trigger 4 on external event 10 */
#define HRTIM_ADC4R_AD4TAC2     (0x00000400)    /*!< ADC Trigger 4 on Timer A compare 2 */
#define HRTIM_ADC4R_AD4TAC3     (0x00000800)    /*!< ADC Trigger 4 on Timer A compare 3 */
#define HRTIM_ADC4R_AD4TAC4     (0x00001000)    /*!< ADC Trigger 4 on Timer A compare 4*/
#define HRTIM_ADC4R_AD4TAPER    (0x00002000)    /*!< ADC Trigger 4 on Timer A period */
#define HRTIM_ADC4R_AD4TBC2     (0x00004000)    /*!< ADC Trigger 4 on Timer B compare 2 */
#define HRTIM_ADC4R_AD4TBC3     (0x00008000)    /*!< ADC Trigger 4 on Timer B compare 3 */
#define HRTIM_ADC4R_AD4TBC4     (0x00010000)    /*!< ADC Trigger 4 on Timer B compare 4 */
#define HRTIM_ADC4R_AD4TBPER    (0x00020000)    /*!< ADC Trigger 4 on Timer B period */
#define HRTIM_ADC4R_AD4TCC2     (0x00040000)    /*!< ADC Trigger 4 on Timer C compare 2 */
#define HRTIM_ADC4R_AD4TCC3     (0x00080000)    /*!< ADC Trigger 4 on Timer C compare 3 */
#define HRTIM_ADC4R_AD4TCC4     (0x00100000)    /*!< ADC Trigger 4 on Timer C compare 4 */
#define HRTIM_ADC4R_AD4TCPER    (0x00200000)    /*!< ADC Trigger 4 on Timer C period */
#define HRTIM_ADC4R_AD4TCRST    (0x00400000)    /*!< ADC Trigger 4 on Timer C reset */
#define HRTIM_ADC4R_AD4TDC2     (0x00800000)    /*!< ADC Trigger 4 on Timer D compare 2 */
#define HRTIM_ADC4R_AD4TDC3     (0x01000000)    /*!< ADC Trigger 4 on Timer D compare 3 */
#define HRTIM_ADC4R_AD4TDC4     (0x02000000)    /*!< ADC Trigger 4 on Timer D compare 4*/
#define HRTIM_ADC4R_AD4TDPER    (0x04000000)    /*!< ADC Trigger 4 on Timer D period */
#define HRTIM_ADC4R_AD4TDRST    (0x08000000)    /*!< ADC Trigger 4 on Timer D reset */
#define HRTIM_ADC4R_AD4TEC2     (0x10000000)    /*!< ADC Trigger 4 on Timer E compare 2 */
#define HRTIM_ADC4R_AD4TEC3     (0x20000000)    /*!< ADC Trigger 4 on Timer E compare 3 */
#define HRTIM_ADC4R_AD4TEC4     (0x40000000)    /*!< ADC Trigger 4 on Timer E compare 4 */
#define HRTIM_ADC4R_AD4TERST    (0x80000000)    /*!< ADC Trigger 4 on Timer E reset */

#define HRTIM_DLLCR_CAL         (0x00000001)    /*!< DLL calibration start */ 
#define HRTIM_DLLCR_CALEN       (0x00000002)    /*!< DLL calibration enable */  
#define HRTIM_DLLCR_CALRTE      (0x0000000C)    /*!< DLL calibration rate */
#define HRTIM_DLLCR_CALRTE_0    (0x00000004)    /*!< DLL calibration rate bit 0 */
#define HRTIM_DLLCR_CALRTE_1    (0x00000008)    /*!< DLL calibration rate bit 1 */  

#define HRTIM_FLTINR1_FLT1E      (0x00000001)    /*!< Fault 1 enable */ 
#define HRTIM_FLTINR1_FLT1P      (0x00000002)    /*!< Fault 1 polarity */
#define HRTIM_FLTINR1_FLT1SRC    (0x00000004)    /*!< Fault 1 source */
#define HRTIM_FLTINR1_FLT1F      (0x00000078)    /*!< Fault 1 filter */
#define HRTIM_FLTINR1_FLT1F_0    (0x00000008)    /*!< Fault 1 filter bit 0 */
#define HRTIM_FLTINR1_FLT1F_1    (0x00000010)    /*!< Fault 1 filter bit 1 */
#define HRTIM_FLTINR1_FLT1F_2    (0x00000020)    /*!< Fault 1 filter bit 2 */
#define HRTIM_FLTINR1_FLT1F_3    (0x00000040)    /*!< Fault 1 filter bit 3 */
#define HRTIM_FLTINR1_FLT1LCK    (0x00000080)    /*!< Fault 1 lock */ 

#define HRTIM_FLTINR1_FLT2E      (0x00000100)    /*!< Fault 2 enable */ 
#define HRTIM_FLTINR1_FLT2P      (0x00000200)    /*!< Fault 2 polarity */
#define HRTIM_FLTINR1_FLT2SRC    (0x00000400)    /*!< Fault 2 source */
#define HRTIM_FLTINR1_FLT2F      (0x00007800)    /*!< Fault 2 filter */
#define HRTIM_FLTINR1_FLT2F_0    (0x00000800)    /*!< Fault 2 filter bit 0 */
#define HRTIM_FLTINR1_FLT2F_1    (0x00001000)    /*!< Fault 2 filter bit 1 */
#define HRTIM_FLTINR1_FLT2F_2    (0x00002000)    /*!< Fault 2 filter bit 2 */
#define HRTIM_FLTINR1_FLT2F_3    (0x00004000)    /*!< Fault 2 filter bit 3 */
#define HRTIM_FLTINR1_FLT2LCK    (0x00008000)    /*!< Fault 2 lock */ 

#define HRTIM_FLTINR1_FLT3E      (0x00010000)    /*!< Fault 3 enable */ 
#define HRTIM_FLTINR1_FLT3P      (0x00020000)    /*!< Fault 3 polarity */
#define HRTIM_FLTINR1_FLT3SRC    (0x00040000)    /*!< Fault 3 source */
#define HRTIM_FLTINR1_FLT3F      (0x00780000)    /*!< Fault 3 filter */
#define HRTIM_FLTINR1_FLT3F_0    (0x00080000)    /*!< Fault 3 filter bit 0 */
#define HRTIM_FLTINR1_FLT3F_1    (0x00100000)    /*!< Fault 3 filter bit 1 */
#define HRTIM_FLTINR1_FLT3F_2    (0x00200000)    /*!< Fault 3 filter bit 2 */
#define HRTIM_FLTINR1_FLT3F_3    (0x00400000)    /*!< Fault 3 filter bit 3 */
#define HRTIM_FLTINR1_FLT3LCK    (0x00800000)    /*!< Fault 3 lock */ 

#define HRTIM_FLTINR1_FLT4E      (0x01000000)    /*!< Fault 4 enable */ 
#define HRTIM_FLTINR1_FLT4P      (0x02000000)    /*!< Fault 4 polarity */
#define HRTIM_FLTINR1_FLT4SRC    (0x04000000)    /*!< Fault 4 source */
#define HRTIM_FLTINR1_FLT4F      (0x78000000)    /*!< Fault 4 filter */
#define HRTIM_FLTINR1_FLT4F_0    (0x08000000)    /*!< Fault 4 filter bit 0 */
#define HRTIM_FLTINR1_FLT4F_1    (0x10000000)    /*!< Fault 4 filter bit 1 */
#define HRTIM_FLTINR1_FLT4F_2    (0x20000000)    /*!< Fault 4 filter bit 2 */
#define HRTIM_FLTINR1_FLT4F_3    (0x40000000)    /*!< Fault 4 filter bit 3 */
#define HRTIM_FLTINR1_FLT4LCK    (0x80000000)    /*!< Fault 4 lock */

#define HRTIM_FLTINR2_FLT5E      (0x00000001)    /*!< Fault 5 enable */ 
#define HRTIM_FLTINR2_FLT5P      (0x00000002)    /*!< Fault 5 polarity */
#define HRTIM_FLTINR2_FLT5SRC    (0x00000004)    /*!< Fault 5 source */
#define HRTIM_FLTINR2_FLT5F      (0x00000078)    /*!< Fault 5 filter */
#define HRTIM_FLTINR2_FLT5F_0    (0x00000008)    /*!< Fault 5 filter bit 0 */
#define HRTIM_FLTINR2_FLT5F_1    (0x00000010)    /*!< Fault 5 filter bit 1 */
#define HRTIM_FLTINR2_FLT5F_2    (0x00000020)    /*!< Fault 5 filter bit 2 */
#define HRTIM_FLTINR2_FLT5F_3    (0x00000040)    /*!< Fault 5 filter bit 3 */
#define HRTIM_FLTINR2_FLT5LCK    (0x00000080)    /*!< Fault 5 lock */
#define HRTIM_FLTINR2_FLTSD      (0x03000000)    /*!< Fault sampling clock division */
#define HRTIM_FLTINR2_FLTSD_0    (0x01000000)    /*!< Fault sampling clock division bit 0 */
#define HRTIM_FLTINR2_FLTSD_1    (0x02000000)    /*!< Fault sampling clock division bit 1 */

#define HRTIM_BDMUPR_MCR      (0x00000001)    /*!< MCR register update enable */ 
#define HRTIM_BDMUPR_MICR     (0x00000002)    /*!< MICR register update enable */ 
#define HRTIM_BDMUPR_MDIER    (0x00000004)    /*!< MDIER register update enable */ 
#define HRTIM_BDMUPR_MCNT     (0x00000008)    /*!< MCNT register update enable */ 
#define HRTIM_BDMUPR_MPER     (0x00000010)    /*!< MPER register update enable */ 
#define HRTIM_BDMUPR_MREP     (0x00000020)    /*!< MREP register update enable */ 
#define HRTIM_BDMUPR_MCMP1    (0x00000040)    /*!< MCMP1 register update enable */ 
#define HRTIM_BDMUPR_MCMP2    (0x00000080)    /*!< MCMP2 register update enable */ 
#define HRTIM_BDMUPR_MCMP3    (0x00000100)    /*!< MCMP3 register update enable */ 
#define HRTIM_BDMUPR_MCMP4    (0x00000200)    /*!< MPCMP4 register update enable */ 

#define HRTIM_BDTUPR_TIMCR      (0x00000001)    /*!<  TIMCR register update enable */ 
#define HRTIM_BDTUPR_TIMICR     (0x00000002)    /*!<  TIMICR register update enable */ 
#define HRTIM_BDTUPR_TIMDIER    (0x00000004)    /*!<  TIMDIER register update enable */ 
#define HRTIM_BDTUPR_TIMCNT     (0x00000008)    /*!<  TIMCNT register update enable */ 
#define HRTIM_BDTUPR_TIMPER     (0x00000010)    /*!<  TIMPER register update enable */ 
#define HRTIM_BDTUPR_TIMREP     (0x00000020)    /*!<  TIMREP register update enable */ 
#define HRTIM_BDTUPR_TIMCMP1    (0x00000040)    /*!<  TIMCMP1 register update enable */ 
#define HRTIM_BDTUPR_TIMCMP2    (0x00000080)    /*!<  TIMCMP2 register update enable */ 
#define HRTIM_BDTUPR_TIMCMP3    (0x00000100)    /*!<  TIMCMP3 register update enable */ 
#define HRTIM_BDTUPR_TIMCMP4    (0x00000200)    /*!<  TIMCMP4 register update enable */ 
#define HRTIM_BDTUPR_TIMDTR     (0x00000400)    /*!<  TIMDTR register update enable */ 
#define HRTIM_BDTUPR_TIMSET1R   (0x00000800)    /*!<  TIMSET1R register update enable */ 
#define HRTIM_BDTUPR_TIMRST1R   (0x00001000)    /*!<  TIMRST1R register update enable */ 
#define HRTIM_BDTUPR_TIMSET2R   (0x00002000)    /*!<  TIMSET2R register update enable */ 
#define HRTIM_BDTUPR_TIMRST2R   (0x00004000)    /*!<  TIMRST2R register update enable */ 
#define HRTIM_BDTUPR_TIMEEFR1   (0x00008000)    /*!<  TIMEEFR1 register update enable */ 
#define HRTIM_BDTUPR_TIMEEFR2   (0x00010000)    /*!<  TIMEEFR2 register update enable */ 
#define HRTIM_BDTUPR_TIMRSTR    (0x00020000)    /*!<  TIMRSTR register update enable */ 
#define HRTIM_BDTUPR_TIMCHPR    (0x00040000)    /*!<  TIMCHPR register update enable */ 
#define HRTIM_BDTUPR_TIMOUTR    (0x00080000)    /*!<  TIMOUTR register update enable */ 
#define HRTIM_BDTUPR_TIMFLTR    (0x00100000)    /*!<  TIMFLTR register update enable */ 

#define HRTIM_BDMADR_BDMADR      (0xFFFFFFFF)    /*!<  Burst DMA Data register */ 

#define ADC_ISR_ADRD          (0x00000001) /*!< ADC Ready (ADRDY) flag  */
#define ADC_ISR_EOSMP         (0x00000002) /*!< ADC End of Sampling flag */
#define ADC_ISR_EOC           (0x00000004) /*!< ADC End of Regular Conversion flag */
#define ADC_ISR_EOS           (0x00000008) /*!< ADC End of Regular sequence of Conversions flag */
#define ADC_ISR_OVR           (0x00000010) /*!< ADC overrun flag */
#define ADC_ISR_JEOC          (0x00000020) /*!< ADC End of Injected Conversion flag */
#define ADC_ISR_JEOS          (0x00000040) /*!< ADC End of Injected sequence of Conversions flag */
#define ADC_ISR_AWD1          (0x00000080) /*!< ADC Analog watchdog 1 flag */
#define ADC_ISR_AWD2          (0x00000100) /*!< ADC Analog watchdog 2 flag */
#define ADC_ISR_AWD3          (0x00000200) /*!< ADC Analog watchdog 3 flag */
#define ADC_ISR_JQOVF         (0x00000400) /*!< ADC Injected Context Queue Overflow flag */

#define ADC_IER_RDY           (0x00000001) /*!< ADC Ready (ADRDY) interrupt source */
#define ADC_IER_EOSMP         (0x00000002) /*!< ADC End of Sampling interrupt source */
#define ADC_IER_EOC           (0x00000004) /*!< ADC End of Regular Conversion interrupt source */
#define ADC_IER_EOS           (0x00000008) /*!< ADC End of Regular sequence of Conversions interrupt source */
#define ADC_IER_OVR           (0x00000010) /*!< ADC overrun interrupt source */
#define ADC_IER_JEOC          (0x00000020) /*!< ADC End of Injected Conversion interrupt source */
#define ADC_IER_JEOS          (0x00000040) /*!< ADC End of Injected sequence of Conversions interrupt source */
#define ADC_IER_AWD1          (0x00000080) /*!< ADC Analog watchdog 1 interrupt source */
#define ADC_IER_AWD2          (0x00000100) /*!< ADC Analog watchdog 2 interrupt source */
#define ADC_IER_AWD3          (0x00000200) /*!< ADC Analog watchdog 3 interrupt source */
#define ADC_IER_JQOVF         (0x00000400) /*!< ADC Injected Context Queue Overflow interrupt source */

#define ADC_CR_ADEN          (0x00000001) /*!< ADC Enable control */
#define ADC_CR_ADDIS         (0x00000002) /*!< ADC Disable command */
#define ADC_CR_ADSTART       (0x00000004) /*!< ADC Start of Regular conversion */
#define ADC_CR_JADSTART      (0x00000008) /*!< ADC Start of injected conversion */
#define ADC_CR_ADSTP         (0x00000010) /*!< ADC Stop of Regular conversion */
#define ADC_CR_JADSTP        (0x00000020) /*!< ADC Stop of injected conversion */
#define ADC_CR_ADVREGEN      (0x30000000) /*!< ADC Voltage regulator Enable */
#define ADC_CR_ADVREGEN_0    (0x10000000) /*!< ADC ADVREGEN bit 0 */
#define ADC_CR_ADVREGEN_1    (0x20000000) /*!< ADC ADVREGEN bit 1 */
#define ADC_CR_ADCALDIF      (0x40000000) /*!< ADC Differential Mode for calibration */
#define ADC_CR_ADCAL         (0x80000000) /*!< ADC Calibration */

#define ADC_CFGR_DMAEN     (0x00000001) /*!< ADC DMA Enable */
#define ADC_CFGR_DMACFG    (0x00000002) /*!< ADC DMA configuration */

#define ADC_CFGR_RES       (0x00000018) /*!< ADC Data resolution */
#define ADC_CFGR_RES_0     (0x00000008) /*!< ADC RES bit 0 */
#define ADC_CFGR_RES_1     (0x00000010) /*!< ADC RES bit 1 */

#define ADC_CFGR_ALIGN     (0x00000020) /*!< ADC Data Alignment */

#define ADC_CFGR_EXTSEL   (0x000003C0) /*!< ADC External trigger selection for regular group */
#define ADC_CFGR_EXTSEL_0 (0x00000040) /*!< ADC EXTSEL bit 0 */
#define ADC_CFGR_EXTSEL_1 (0x00000080) /*!< ADC EXTSEL bit 1 */
#define ADC_CFGR_EXTSEL_2 (0x00000100) /*!< ADC EXTSEL bit 2 */
#define ADC_CFGR_EXTSEL_3 (0x00000200) /*!< ADC EXTSEL bit 3 */

#define ADC_CFGR_EXTEN     (0x00000C00) /*!< ADC External trigger enable and polarity selection for regular channels */
#define ADC_CFGR_EXTEN_0   (0x00000400) /*!< ADC EXTEN bit 0 */
#define ADC_CFGR_EXTEN_1   (0x00000800) /*!< ADC EXTEN bit 1 */

#define ADC_CFGR_OVRMOD    (0x00001000) /*!< ADC overrun mode */
#define ADC_CFGR_CONT      (0x00002000) /*!< ADC Single/continuous conversion mode for regular conversion */
#define ADC_CFGR_AUTDLY    (0x00004000) /*!< ADC Delayed conversion mode */
#define ADC_CFGR_DISCEN    (0x00010000) /*!< ADC Discontinuous mode for regular channels */

#define ADC_CFGR_DISCNUM   (0x000E0000) /*!< ADC Discontinuous mode channel count */
#define ADC_CFGR_DISCNUM_0 (0x00020000) /*!< ADC DISCNUM bit 0 */
#define ADC_CFGR_DISCNUM_1 (0x00040000) /*!< ADC DISCNUM bit 1 */
#define ADC_CFGR_DISCNUM_2 (0x00080000) /*!< ADC DISCNUM bit 2 */

#define ADC_CFGR_JDISCEN   (0x00100000) /*!< ADC Discontinuous mode on injected channels */
#define ADC_CFGR_JQM       (0x00200000) /*!< ADC JSQR Queue mode */
#define ADC_CFGR_AWD1SGL   (0x00400000) /*!< Enable the watchdog 1 on a single channel or on all channels */
#define ADC_CFGR_AWD1EN    (0x00800000) /*!< ADC Analog watchdog 1 enable on regular Channels */
#define ADC_CFGR_JAWD1EN   (0x01000000) /*!< ADC Analog watchdog 1 enable on injected Channels */
#define ADC_CFGR_JAUTO     (0x02000000) /*!< ADC Automatic injected group conversion */

#define ADC_CFGR_AWD1CH    (0x7C000000) /*!< ADC Analog watchdog 1 Channel selection */
#define ADC_CFGR_AWD1CH_0  (0x04000000) /*!< ADC AWD1CH bit 0 */
#define ADC_CFGR_AWD1CH_1  (0x08000000) /*!< ADC AWD1CH bit 1  */
#define ADC_CFGR_AWD1CH_2  (0x10000000) /*!< ADC AWD1CH bit 2  */
#define ADC_CFGR_AWD1CH_3  (0x20000000) /*!< ADC AWD1CH bit 3  */
#define ADC_CFGR_AWD1CH_4  (0x40000000) /*!< ADC AWD1CH bit 4  */

#define ADC_SMPR1_SMP0     (0x00000007) /*!< ADC Channel 0 Sampling time selection  */
#define ADC_SMPR1_SMP0_0   (0x00000001) /*!< ADC SMP0 bit 0 */
#define ADC_SMPR1_SMP0_1   (0x00000002) /*!< ADC SMP0 bit 1 */
#define ADC_SMPR1_SMP0_2   (0x00000004) /*!< ADC SMP0 bit 2 */

#define ADC_SMPR1_SMP1     (0x00000038) /*!< ADC Channel 1 Sampling time selection  */
#define ADC_SMPR1_SMP1_0   (0x00000008) /*!< ADC SMP1 bit 0 */
#define ADC_SMPR1_SMP1_1   (0x00000010) /*!< ADC SMP1 bit 1 */
#define ADC_SMPR1_SMP1_2   (0x00000020) /*!< ADC SMP1 bit 2 */

#define ADC_SMPR1_SMP2     (0x000001C0) /*!< ADC Channel 2 Sampling time selection  */
#define ADC_SMPR1_SMP2_0   (0x00000040) /*!< ADC SMP2 bit 0 */
#define ADC_SMPR1_SMP2_1   (0x00000080) /*!< ADC SMP2 bit 1 */
#define ADC_SMPR1_SMP2_2   (0x00000100) /*!< ADC SMP2 bit 2 */

#define ADC_SMPR1_SMP3     (0x00000E00) /*!< ADC Channel 3 Sampling time selection  */
#define ADC_SMPR1_SMP3_0   (0x00000200) /*!< ADC SMP3 bit 0 */
#define ADC_SMPR1_SMP3_1   (0x00000400) /*!< ADC SMP3 bit 1 */
#define ADC_SMPR1_SMP3_2   (0x00000800) /*!< ADC SMP3 bit 2 */

#define ADC_SMPR1_SMP4     (0x00007000) /*!< ADC Channel 4 Sampling time selection  */
#define ADC_SMPR1_SMP4_0   (0x00001000) /*!< ADC SMP4 bit 0 */
#define ADC_SMPR1_SMP4_1   (0x00002000) /*!< ADC SMP4 bit 1 */
#define ADC_SMPR1_SMP4_2   (0x00004000) /*!< ADC SMP4 bit 2 */

#define ADC_SMPR1_SMP5     (0x00038000) /*!< ADC Channel 5 Sampling time selection  */
#define ADC_SMPR1_SMP5_0   (0x00008000) /*!< ADC SMP5 bit 0 */
#define ADC_SMPR1_SMP5_1   (0x00010000) /*!< ADC SMP5 bit 1 */
#define ADC_SMPR1_SMP5_2   (0x00020000) /*!< ADC SMP5 bit 2 */

#define ADC_SMPR1_SMP6     (0x001C0000) /*!< ADC Channel 6 Sampling time selection  */
#define ADC_SMPR1_SMP6_0   (0x00040000) /*!< ADC SMP6 bit 0 */
#define ADC_SMPR1_SMP6_1   (0x00080000) /*!< ADC SMP6 bit 1 */
#define ADC_SMPR1_SMP6_2   (0x00100000) /*!< ADC SMP6 bit 2 */

#define ADC_SMPR1_SMP7     (0x00E00000) /*!< ADC Channel 7 Sampling time selection  */
#define ADC_SMPR1_SMP7_0   (0x00200000) /*!< ADC SMP7 bit 0 */
#define ADC_SMPR1_SMP7_1   (0x00400000) /*!< ADC SMP7 bit 1 */
#define ADC_SMPR1_SMP7_2   (0x00800000) /*!< ADC SMP7 bit 2 */

#define ADC_SMPR1_SMP8     (0x07000000) /*!< ADC Channel 8 Sampling time selection  */
#define ADC_SMPR1_SMP8_0   (0x01000000) /*!< ADC SMP8 bit 0 */
#define ADC_SMPR1_SMP8_1   (0x02000000) /*!< ADC SMP8 bit 1 */
#define ADC_SMPR1_SMP8_2   (0x04000000) /*!< ADC SMP8 bit 2 */

#define ADC_SMPR1_SMP9     (0x38000000) /*!< ADC Channel 9 Sampling time selection  */
#define ADC_SMPR1_SMP9_0   (0x08000000) /*!< ADC SMP9 bit 0 */
#define ADC_SMPR1_SMP9_1   (0x10000000) /*!< ADC SMP9 bit 1 */
#define ADC_SMPR1_SMP9_2   (0x20000000) /*!< ADC SMP9 bit 2 */

#define ADC_SMPR2_SMP10     (0x00000007) /*!< ADC Channel 10 Sampling time selection  */
#define ADC_SMPR2_SMP10_0   (0x00000001) /*!< ADC SMP10 bit 0 */
#define ADC_SMPR2_SMP10_1   (0x00000002) /*!< ADC SMP10 bit 1 */
#define ADC_SMPR2_SMP10_2   (0x00000004) /*!< ADC SMP10 bit 2 */

#define ADC_SMPR2_SMP11     (0x00000038) /*!< ADC Channel 11 Sampling time selection  */
#define ADC_SMPR2_SMP11_0   (0x00000008) /*!< ADC SMP11 bit 0 */
#define ADC_SMPR2_SMP11_1   (0x00000010) /*!< ADC SMP11 bit 1 */
#define ADC_SMPR2_SMP11_2   (0x00000020) /*!< ADC SMP11 bit 2 */

#define ADC_SMPR2_SMP12     (0x000001C0) /*!< ADC Channel 12 Sampling time selection  */
#define ADC_SMPR2_SMP12_0   (0x00000040) /*!< ADC SMP12 bit 0 */
#define ADC_SMPR2_SMP12_1   (0x00000080) /*!< ADC SMP12 bit 1 */
#define ADC_SMPR2_SMP12_2   (0x00000100) /*!< ADC SMP12 bit 2 */

#define ADC_SMPR2_SMP13     (0x00000E00) /*!< ADC Channel 13 Sampling time selection  */
#define ADC_SMPR2_SMP13_0   (0x00000200) /*!< ADC SMP13 bit 0 */
#define ADC_SMPR2_SMP13_1   (0x00000400) /*!< ADC SMP13 bit 1 */
#define ADC_SMPR2_SMP13_2   (0x00000800) /*!< ADC SMP13 bit 2 */

#define ADC_SMPR2_SMP14     (0x00007000) /*!< ADC Channel 14 Sampling time selection  */
#define ADC_SMPR2_SMP14_0   (0x00001000) /*!< ADC SMP14 bit 0 */
#define ADC_SMPR2_SMP14_1   (0x00002000) /*!< ADC SMP14 bit 1 */
#define ADC_SMPR2_SMP14_2   (0x00004000) /*!< ADC SMP14 bit 2 */

#define ADC_SMPR2_SMP15     (0x00038000) /*!< ADC Channel 15 Sampling time selection  */
#define ADC_SMPR2_SMP15_0   (0x00008000) /*!< ADC SMP15 bit 0 */
#define ADC_SMPR2_SMP15_1   (0x00010000) /*!< ADC SMP15 bit 1 */
#define ADC_SMPR2_SMP15_2   (0x00020000) /*!< ADC SMP15 bit 2 */

#define ADC_SMPR2_SMP16     (0x001C0000) /*!< ADC Channel 16 Sampling time selection  */
#define ADC_SMPR2_SMP16_0   (0x00040000) /*!< ADC SMP16 bit 0 */
#define ADC_SMPR2_SMP16_1   (0x00080000) /*!< ADC SMP16 bit 1 */
#define ADC_SMPR2_SMP16_2   (0x00100000) /*!< ADC SMP16 bit 2 */

#define ADC_SMPR2_SMP17     (0x00E00000) /*!< ADC Channel 17 Sampling time selection  */
#define ADC_SMPR2_SMP17_0   (0x00200000) /*!< ADC SMP17 bit 0 */
#define ADC_SMPR2_SMP17_1   (0x00400000) /*!< ADC SMP17 bit 1 */
#define ADC_SMPR2_SMP17_2   (0x00800000) /*!< ADC SMP17 bit 2 */

#define ADC_SMPR2_SMP18     (0x07000000) /*!< ADC Channel 18 Sampling time selection  */
#define ADC_SMPR2_SMP18_0   (0x01000000) /*!< ADC SMP18 bit 0 */
#define ADC_SMPR2_SMP18_1   (0x02000000) /*!< ADC SMP18 bit 1 */
#define ADC_SMPR2_SMP18_2   (0x04000000) /*!< ADC SMP18 bit 2 */

#define ADC_TR1_LT1         (0x00000FFF) /*!< ADC Analog watchdog 1 lower threshold */
#define ADC_TR1_LT1_0       (0x00000001) /*!< ADC LT1 bit 0 */
#define ADC_TR1_LT1_1       (0x00000002) /*!< ADC LT1 bit 1 */
#define ADC_TR1_LT1_2       (0x00000004) /*!< ADC LT1 bit 2 */
#define ADC_TR1_LT1_3       (0x00000008) /*!< ADC LT1 bit 3 */
#define ADC_TR1_LT1_4       (0x00000010) /*!< ADC LT1 bit 4 */
#define ADC_TR1_LT1_5       (0x00000020) /*!< ADC LT1 bit 5 */
#define ADC_TR1_LT1_6       (0x00000040) /*!< ADC LT1 bit 6 */
#define ADC_TR1_LT1_7       (0x00000080) /*!< ADC LT1 bit 7 */
#define ADC_TR1_LT1_8       (0x00000100) /*!< ADC LT1 bit 8 */
#define ADC_TR1_LT1_9       (0x00000200) /*!< ADC LT1 bit 9 */
#define ADC_TR1_LT1_10      (0x00000400) /*!< ADC LT1 bit 10 */
#define ADC_TR1_LT1_11      (0x00000800) /*!< ADC LT1 bit 11 */

#define ADC_TR1_HT1         (0x0FFF0000) /*!< ADC Analog watchdog 1 higher threshold */
#define ADC_TR1_HT1_0       (0x00010000) /*!< ADC HT1 bit 0 */
#define ADC_TR1_HT1_1       (0x00020000) /*!< ADC HT1 bit 1 */
#define ADC_TR1_HT1_2       (0x00040000) /*!< ADC HT1 bit 2 */
#define ADC_TR1_HT1_3       (0x00080000) /*!< ADC HT1 bit 3 */
#define ADC_TR1_HT1_4       (0x00100000) /*!< ADC HT1 bit 4 */
#define ADC_TR1_HT1_5       (0x00200000) /*!< ADC HT1 bit 5 */
#define ADC_TR1_HT1_6       (0x00400000) /*!< ADC HT1 bit 6 */
#define ADC_TR1_HT1_7       (0x00800000) /*!< ADC HT1 bit 7 */
#define ADC_TR1_HT1_8       (0x01000000) /*!< ADC HT1 bit 8 */
#define ADC_TR1_HT1_9       (0x02000000) /*!< ADC HT1 bit 9 */
#define ADC_TR1_HT1_10      (0x04000000) /*!< ADC HT1 bit 10 */
#define ADC_TR1_HT1_11      (0x08000000) /*!< ADC HT1 bit 11 */

#define ADC_TR2_LT2         (0x000000FF) /*!< ADC Analog watchdog 2 lower threshold */
#define ADC_TR2_LT2_0       (0x00000001) /*!< ADC LT2 bit 0 */
#define ADC_TR2_LT2_1       (0x00000002) /*!< ADC LT2 bit 1 */
#define ADC_TR2_LT2_2       (0x00000004) /*!< ADC LT2 bit 2 */
#define ADC_TR2_LT2_3       (0x00000008) /*!< ADC LT2 bit 3 */
#define ADC_TR2_LT2_4       (0x00000010) /*!< ADC LT2 bit 4 */
#define ADC_TR2_LT2_5       (0x00000020) /*!< ADC LT2 bit 5 */
#define ADC_TR2_LT2_6       (0x00000040) /*!< ADC LT2 bit 6 */
#define ADC_TR2_LT2_7       (0x00000080) /*!< ADC LT2 bit 7 */

#define ADC_TR2_HT2         (0x00FF0000) /*!< ADC Analog watchdog 2 higher threshold */
#define ADC_TR2_HT2_0       (0x00010000) /*!< ADC HT2 bit 0 */
#define ADC_TR2_HT2_1       (0x00020000) /*!< ADC HT2 bit 1 */
#define ADC_TR2_HT2_2       (0x00040000) /*!< ADC HT2 bit 2 */
#define ADC_TR2_HT2_3       (0x00080000) /*!< ADC HT2 bit 3 */
#define ADC_TR2_HT2_4       (0x00100000) /*!< ADC HT2 bit 4 */
#define ADC_TR2_HT2_5       (0x00200000) /*!< ADC HT2 bit 5 */
#define ADC_TR2_HT2_6       (0x00400000) /*!< ADC HT2 bit 6 */
#define ADC_TR2_HT2_7       (0x00800000) /*!< ADC HT2 bit 7 */

#define ADC_TR3_LT3         (0x000000FF) /*!< ADC Analog watchdog 3 lower threshold */
#define ADC_TR3_LT3_0       (0x00000001) /*!< ADC LT3 bit 0 */
#define ADC_TR3_LT3_1       (0x00000002) /*!< ADC LT3 bit 1 */
#define ADC_TR3_LT3_2       (0x00000004) /*!< ADC LT3 bit 2 */
#define ADC_TR3_LT3_3       (0x00000008) /*!< ADC LT3 bit 3 */
#define ADC_TR3_LT3_4       (0x00000010) /*!< ADC LT3 bit 4 */
#define ADC_TR3_LT3_5       (0x00000020) /*!< ADC LT3 bit 5 */
#define ADC_TR3_LT3_6       (0x00000040) /*!< ADC LT3 bit 6 */
#define ADC_TR3_LT3_7       (0x00000080) /*!< ADC LT3 bit 7 */

#define ADC_TR3_HT3         (0x00FF0000) /*!< ADC Analog watchdog 3 higher threshold */
#define ADC_TR3_HT3_0       (0x00010000) /*!< ADC HT3 bit 0 */
#define ADC_TR3_HT3_1       (0x00020000) /*!< ADC HT3 bit 1 */
#define ADC_TR3_HT3_2       (0x00040000) /*!< ADC HT3 bit 2 */
#define ADC_TR3_HT3_3       (0x00080000) /*!< ADC HT3 bit 3 */
#define ADC_TR3_HT3_4       (0x00100000) /*!< ADC HT3 bit 4 */
#define ADC_TR3_HT3_5       (0x00200000) /*!< ADC HT3 bit 5 */
#define ADC_TR3_HT3_6       (0x00400000) /*!< ADC HT3 bit 6 */
#define ADC_TR3_HT3_7       (0x00800000) /*!< ADC HT3 bit 7 */

#define ADC_SQR1_L          (0x0000000F) /*!< ADC regular channel sequence length */
#define ADC_SQR1_L_0        (0x00000001) /*!< ADC L bit 0 */
#define ADC_SQR1_L_1        (0x00000002) /*!< ADC L bit 1 */
#define ADC_SQR1_L_2        (0x00000004) /*!< ADC L bit 2 */
#define ADC_SQR1_L_3        (0x00000008) /*!< ADC L bit 3 */

#define ADC_SQR1_SQ1        (0x000007C0) /*!< ADC 1st conversion in regular sequence */
#define ADC_SQR1_SQ1_0      (0x00000040) /*!< ADC SQ1 bit 0 */
#define ADC_SQR1_SQ1_1      (0x00000080) /*!< ADC SQ1 bit 1 */
#define ADC_SQR1_SQ1_2      (0x00000100) /*!< ADC SQ1 bit 2 */
#define ADC_SQR1_SQ1_3      (0x00000200) /*!< ADC SQ1 bit 3 */
#define ADC_SQR1_SQ1_4      (0x00000400) /*!< ADC SQ1 bit 4 */

#define ADC_SQR1_SQ2        (0x0001F000) /*!< ADC 2nd conversion in regular sequence */
#define ADC_SQR1_SQ2_0      (0x00001000) /*!< ADC SQ2 bit 0 */
#define ADC_SQR1_SQ2_1      (0x00002000) /*!< ADC SQ2 bit 1 */
#define ADC_SQR1_SQ2_2      (0x00004000) /*!< ADC SQ2 bit 2 */
#define ADC_SQR1_SQ2_3      (0x00008000) /*!< ADC SQ2 bit 3 */
#define ADC_SQR1_SQ2_4      (0x00010000) /*!< ADC SQ2 bit 4 */

#define ADC_SQR1_SQ3        (0x007C0000) /*!< ADC 3rd conversion in regular sequence */
#define ADC_SQR1_SQ3_0      (0x00040000) /*!< ADC SQ3 bit 0 */
#define ADC_SQR1_SQ3_1      (0x00080000) /*!< ADC SQ3 bit 1 */
#define ADC_SQR1_SQ3_2      (0x00100000) /*!< ADC SQ3 bit 2 */
#define ADC_SQR1_SQ3_3      (0x00200000) /*!< ADC SQ3 bit 3 */
#define ADC_SQR1_SQ3_4      (0x00400000) /*!< ADC SQ3 bit 4 */

#define ADC_SQR1_SQ4        (0x1F000000) /*!< ADC 4th conversion in regular sequence */
#define ADC_SQR1_SQ4_0      (0x01000000) /*!< ADC SQ4 bit 0 */
#define ADC_SQR1_SQ4_1      (0x02000000) /*!< ADC SQ4 bit 1 */
#define ADC_SQR1_SQ4_2      (0x04000000) /*!< ADC SQ4 bit 2 */
#define ADC_SQR1_SQ4_3      (0x08000000) /*!< ADC SQ4 bit 3 */
#define ADC_SQR1_SQ4_4      (0x10000000) /*!< ADC SQ4 bit 4 */

#define ADC_SQR2_SQ5        (0x0000001F) /*!< ADC 5th conversion in regular sequence */
#define ADC_SQR2_SQ5_0      (0x00000001) /*!< ADC SQ5 bit 0 */
#define ADC_SQR2_SQ5_1      (0x00000002) /*!< ADC SQ5 bit 1 */
#define ADC_SQR2_SQ5_2      (0x00000004) /*!< ADC SQ5 bit 2 */
#define ADC_SQR2_SQ5_3      (0x00000008) /*!< ADC SQ5 bit 3 */
#define ADC_SQR2_SQ5_4      (0x00000010) /*!< ADC SQ5 bit 4 */

#define ADC_SQR2_SQ6        (0x000007C0) /*!< ADC 6th conversion in regular sequence */
#define ADC_SQR2_SQ6_0      (0x00000040) /*!< ADC SQ6 bit 0 */
#define ADC_SQR2_SQ6_1      (0x00000080) /*!< ADC SQ6 bit 1 */
#define ADC_SQR2_SQ6_2      (0x00000100) /*!< ADC SQ6 bit 2 */
#define ADC_SQR2_SQ6_3      (0x00000200) /*!< ADC SQ6 bit 3 */
#define ADC_SQR2_SQ6_4      (0x00000400) /*!< ADC SQ6 bit 4 */

#define ADC_SQR2_SQ7        (0x0001F000) /*!< ADC 7th conversion in regular sequence */
#define ADC_SQR2_SQ7_0      (0x00001000) /*!< ADC SQ7 bit 0 */
#define ADC_SQR2_SQ7_1      (0x00002000) /*!< ADC SQ7 bit 1 */
#define ADC_SQR2_SQ7_2      (0x00004000) /*!< ADC SQ7 bit 2 */
#define ADC_SQR2_SQ7_3      (0x00008000) /*!< ADC SQ7 bit 3 */
#define ADC_SQR2_SQ7_4      (0x00010000) /*!< ADC SQ7 bit 4 */

#define ADC_SQR2_SQ8        (0x007C0000) /*!< ADC 8th conversion in regular sequence */
#define ADC_SQR2_SQ8_0      (0x00040000) /*!< ADC SQ8 bit 0 */
#define ADC_SQR2_SQ8_1      (0x00080000) /*!< ADC SQ8 bit 1 */
#define ADC_SQR2_SQ8_2      (0x00100000) /*!< ADC SQ8 bit 2 */
#define ADC_SQR2_SQ8_3      (0x00200000) /*!< ADC SQ8 bit 3 */
#define ADC_SQR2_SQ8_4      (0x00400000) /*!< ADC SQ8 bit 4 */

#define ADC_SQR2_SQ9        (0x1F000000) /*!< ADC 9th conversion in regular sequence */
#define ADC_SQR2_SQ9_0      (0x01000000) /*!< ADC SQ9 bit 0 */
#define ADC_SQR2_SQ9_1      (0x02000000) /*!< ADC SQ9 bit 1 */
#define ADC_SQR2_SQ9_2      (0x04000000) /*!< ADC SQ9 bit 2 */
#define ADC_SQR2_SQ9_3      (0x08000000) /*!< ADC SQ9 bit 3 */
#define ADC_SQR2_SQ9_4      (0x10000000) /*!< ADC SQ9 bit 4 */

#define ADC_SQR3_SQ10       (0x0000001F) /*!< ADC 10th conversion in regular sequence */
#define ADC_SQR3_SQ10_0     (0x00000001) /*!< ADC SQ10 bit 0 */
#define ADC_SQR3_SQ10_1     (0x00000002) /*!< ADC SQ10 bit 1 */
#define ADC_SQR3_SQ10_2     (0x00000004) /*!< ADC SQ10 bit 2 */
#define ADC_SQR3_SQ10_3     (0x00000008) /*!< ADC SQ10 bit 3 */
#define ADC_SQR3_SQ10_4     (0x00000010) /*!< ADC SQ10 bit 4 */

#define ADC_SQR3_SQ11       (0x000007C0) /*!< ADC 11th conversion in regular sequence */
#define ADC_SQR3_SQ11_0     (0x00000040) /*!< ADC SQ11 bit 0 */
#define ADC_SQR3_SQ11_1     (0x00000080) /*!< ADC SQ11 bit 1 */
#define ADC_SQR3_SQ11_2     (0x00000100) /*!< ADC SQ11 bit 2 */
#define ADC_SQR3_SQ11_3     (0x00000200) /*!< ADC SQ11 bit 3 */
#define ADC_SQR3_SQ11_4     (0x00000400) /*!< ADC SQ11 bit 4 */

#define ADC_SQR3_SQ12       (0x0001F000) /*!< ADC 12th conversion in regular sequence */
#define ADC_SQR3_SQ12_0     (0x00001000) /*!< ADC SQ12 bit 0 */
#define ADC_SQR3_SQ12_1     (0x00002000) /*!< ADC SQ12 bit 1 */
#define ADC_SQR3_SQ12_2     (0x00004000) /*!< ADC SQ12 bit 2 */
#define ADC_SQR3_SQ12_3     (0x00008000) /*!< ADC SQ12 bit 3 */
#define ADC_SQR3_SQ12_4     (0x00010000) /*!< ADC SQ12 bit 4 */

#define ADC_SQR3_SQ13       (0x007C0000) /*!< ADC 13th conversion in regular sequence */
#define ADC_SQR3_SQ13_0     (0x00040000) /*!< ADC SQ13 bit 0 */
#define ADC_SQR3_SQ13_1     (0x00080000) /*!< ADC SQ13 bit 1 */
#define ADC_SQR3_SQ13_2     (0x00100000) /*!< ADC SQ13 bit 2 */
#define ADC_SQR3_SQ13_3     (0x00200000) /*!< ADC SQ13 bit 3 */
#define ADC_SQR3_SQ13_4     (0x00400000) /*!< ADC SQ13 bit 4 */

#define ADC_SQR3_SQ14       (0x1F000000) /*!< ADC 14th conversion in regular sequence */
#define ADC_SQR3_SQ14_0     (0x01000000) /*!< ADC SQ14 bit 0 */
#define ADC_SQR3_SQ14_1     (0x02000000) /*!< ADC SQ14 bit 1 */
#define ADC_SQR3_SQ14_2     (0x04000000) /*!< ADC SQ14 bit 2 */
#define ADC_SQR3_SQ14_3     (0x08000000) /*!< ADC SQ14 bit 3 */
#define ADC_SQR3_SQ14_4     (0x10000000) /*!< ADC SQ14 bit 4 */

#define ADC_SQR4_SQ15       (0x0000001F) /*!< ADC 15th conversion in regular sequence */
#define ADC_SQR4_SQ15_0     (0x00000001) /*!< ADC SQ15 bit 0 */
#define ADC_SQR4_SQ15_1     (0x00000002) /*!< ADC SQ15 bit 1 */
#define ADC_SQR4_SQ15_2     (0x00000004) /*!< ADC SQ15 bit 2 */
#define ADC_SQR4_SQ15_3     (0x00000008) /*!< ADC SQ15 bit 3 */
#define ADC_SQR4_SQ15_4     (0x00000010) /*!< ADC SQ105 bit 4 */

#define ADC_SQR4_SQ16       (0x000007C0) /*!< ADC 16th conversion in regular sequence */
#define ADC_SQR4_SQ16_0     (0x00000040) /*!< ADC SQ16 bit 0 */
#define ADC_SQR4_SQ16_1     (0x00000080) /*!< ADC SQ16 bit 1 */
#define ADC_SQR4_SQ16_2     (0x00000100) /*!< ADC SQ16 bit 2 */
#define ADC_SQR4_SQ16_3     (0x00000200) /*!< ADC SQ16 bit 3 */
#define ADC_SQR4_SQ16_4     (0x00000400) /*!< ADC SQ16 bit 4 */

#define ADC_SQR3_SQ15       ADC_SQR4_SQ15 /*!< ADC 15th conversion in regular sequence */
#define ADC_SQR3_SQ15_0     ADC_SQR4_SQ15_0 /*!< ADC SQ15 bit 0 */
#define ADC_SQR3_SQ15_1     ADC_SQR4_SQ15_1 /*!< ADC SQ15 bit 1 */
#define ADC_SQR3_SQ15_2     ADC_SQR4_SQ15_2 /*!< ADC SQ15 bit 2 */
#define ADC_SQR3_SQ15_3     ADC_SQR4_SQ15_3 /*!< ADC SQ15 bit 3 */
#define ADC_SQR3_SQ15_4     ADC_SQR4_SQ15_4 /*!< ADC SQ105 bit 4 */

#define ADC_SQR3_SQ16       ADC_SQR4_SQ16 /*!< ADC 16th conversion in regular sequence */
#define ADC_SQR3_SQ16_0     ADC_SQR4_SQ16_0 /*!< ADC SQ16 bit 0 */
#define ADC_SQR3_SQ16_1     ADC_SQR4_SQ16_1 /*!< ADC SQ16 bit 1 */
#define ADC_SQR3_SQ16_2     ADC_SQR4_SQ16_2 /*!< ADC SQ16 bit 2 */
#define ADC_SQR3_SQ16_3     ADC_SQR4_SQ16_3 /*!< ADC SQ16 bit 3 */
#define ADC_SQR3_SQ16_4     ADC_SQR4_SQ16_4 /*!< ADC SQ16 bit 4 */
#define ADC_DR_RDATA        (0x0000FFFF) /*!< ADC regular Data converted */
#define ADC_DR_RDATA_0      (0x00000001) /*!< ADC RDATA bit 0 */
#define ADC_DR_RDATA_1      (0x00000002) /*!< ADC RDATA bit 1 */
#define ADC_DR_RDATA_2      (0x00000004) /*!< ADC RDATA bit 2 */
#define ADC_DR_RDATA_3      (0x00000008) /*!< ADC RDATA bit 3 */
#define ADC_DR_RDATA_4      (0x00000010) /*!< ADC RDATA bit 4 */
#define ADC_DR_RDATA_5      (0x00000020) /*!< ADC RDATA bit 5 */
#define ADC_DR_RDATA_6      (0x00000040) /*!< ADC RDATA bit 6 */
#define ADC_DR_RDATA_7      (0x00000080) /*!< ADC RDATA bit 7 */
#define ADC_DR_RDATA_8      (0x00000100) /*!< ADC RDATA bit 8 */
#define ADC_DR_RDATA_9      (0x00000200) /*!< ADC RDATA bit 9 */
#define ADC_DR_RDATA_10     (0x00000400) /*!< ADC RDATA bit 10 */
#define ADC_DR_RDATA_11     (0x00000800) /*!< ADC RDATA bit 11 */
#define ADC_DR_RDATA_12     (0x00001000) /*!< ADC RDATA bit 12 */
#define ADC_DR_RDATA_13     (0x00002000) /*!< ADC RDATA bit 13 */
#define ADC_DR_RDATA_14     (0x00004000) /*!< ADC RDATA bit 14 */
#define ADC_DR_RDATA_15     (0x00008000) /*!< ADC RDATA bit 15 */

#define ADC_JSQR_JL         (0x00000003) /*!< ADC injected channel sequence length */
#define ADC_JSQR_JL_0       (0x00000001) /*!< ADC JL bit 0 */
#define ADC_JSQR_JL_1       (0x00000002) /*!< ADC JL bit 1 */

#define ADC_JSQR_JEXTSEL    (0x0000003C) /*!< ADC external trigger selection for injected group */
#define ADC_JSQR_JEXTSEL_0  (0x00000004) /*!< ADC JEXTSEL bit 0 */
#define ADC_JSQR_JEXTSEL_1  (0x00000008) /*!< ADC JEXTSEL bit 1 */
#define ADC_JSQR_JEXTSEL_2  (0x00000010) /*!< ADC JEXTSEL bit 2 */
#define ADC_JSQR_JEXTSEL_3  (0x00000020) /*!< ADC JEXTSEL bit 3 */

#define ADC_JSQR_JEXTEN     (0x000000C0) /*!< ADC external trigger enable and polarity selection for injected channels */
#define ADC_JSQR_JEXTEN_0   (0x00000040) /*!< ADC JEXTEN bit 0 */
#define ADC_JSQR_JEXTEN_1   (0x00000080) /*!< ADC JEXTEN bit 1 */

#define ADC_JSQR_JSQ1       (0x00001F00) /*!< ADC 1st conversion in injected sequence */
#define ADC_JSQR_JSQ1_0     (0x00000100) /*!< ADC JSQ1 bit 0 */
#define ADC_JSQR_JSQ1_1     (0x00000200) /*!< ADC JSQ1 bit 1 */
#define ADC_JSQR_JSQ1_2     (0x00000400) /*!< ADC JSQ1 bit 2 */
#define ADC_JSQR_JSQ1_3     (0x00000800) /*!< ADC JSQ1 bit 3 */
#define ADC_JSQR_JSQ1_4     (0x00001000) /*!< ADC JSQ1 bit 4 */

#define ADC_JSQR_JSQ2       (0x0007C000) /*!< ADC 2nd conversion in injected sequence */
#define ADC_JSQR_JSQ2_0     (0x00004000) /*!< ADC JSQ2 bit 0 */
#define ADC_JSQR_JSQ2_1     (0x00008000) /*!< ADC JSQ2 bit 1 */
#define ADC_JSQR_JSQ2_2     (0x00010000) /*!< ADC JSQ2 bit 2 */
#define ADC_JSQR_JSQ2_3     (0x00020000) /*!< ADC JSQ2 bit 3 */
#define ADC_JSQR_JSQ2_4     (0x00040000) /*!< ADC JSQ2 bit 4 */

#define ADC_JSQR_JSQ3       (0x01F00000) /*!< ADC 3rd conversion in injected sequence */
#define ADC_JSQR_JSQ3_0     (0x00100000) /*!< ADC JSQ3 bit 0 */
#define ADC_JSQR_JSQ3_1     (0x00200000) /*!< ADC JSQ3 bit 1 */
#define ADC_JSQR_JSQ3_2     (0x00400000) /*!< ADC JSQ3 bit 2 */
#define ADC_JSQR_JSQ3_3     (0x00800000) /*!< ADC JSQ3 bit 3 */
#define ADC_JSQR_JSQ3_4     (0x01000000) /*!< ADC JSQ3 bit 4 */

#define ADC_JSQR_JSQ4       (0x7C000000) /*!< ADC 4th conversion in injected sequence */
#define ADC_JSQR_JSQ4_0     (0x04000000) /*!< ADC JSQ4 bit 0 */
#define ADC_JSQR_JSQ4_1     (0x08000000) /*!< ADC JSQ4 bit 1 */
#define ADC_JSQR_JSQ4_2     (0x10000000) /*!< ADC JSQ4 bit 2 */
#define ADC_JSQR_JSQ4_3     (0x20000000) /*!< ADC JSQ4 bit 3 */
#define ADC_JSQR_JSQ4_4     (0x40000000) /*!< ADC JSQ4 bit 4 */

#define ADC_OFR1_OFFSET1    (0x00000FFF) /*!< ADC data offset 1 for channel programmed into bits OFFSET1_CH[4:0] */
#define ADC_OFR1_OFFSET1_0  (0x00000001) /*!< ADC OFFSET1 bit 0 */
#define ADC_OFR1_OFFSET1_1  (0x00000002) /*!< ADC OFFSET1 bit 1 */
#define ADC_OFR1_OFFSET1_2  (0x00000004) /*!< ADC OFFSET1 bit 2 */
#define ADC_OFR1_OFFSET1_3  (0x00000008) /*!< ADC OFFSET1 bit 3 */
#define ADC_OFR1_OFFSET1_4  (0x00000010) /*!< ADC OFFSET1 bit 4 */
#define ADC_OFR1_OFFSET1_5  (0x00000020) /*!< ADC OFFSET1 bit 5 */
#define ADC_OFR1_OFFSET1_6  (0x00000040) /*!< ADC OFFSET1 bit 6 */
#define ADC_OFR1_OFFSET1_7  (0x00000080) /*!< ADC OFFSET1 bit 7 */
#define ADC_OFR1_OFFSET1_8  (0x00000100) /*!< ADC OFFSET1 bit 8 */
#define ADC_OFR1_OFFSET1_9  (0x00000200) /*!< ADC OFFSET1 bit 9 */
#define ADC_OFR1_OFFSET1_10 (0x00000400) /*!< ADC OFFSET1 bit 10 */
#define ADC_OFR1_OFFSET1_11 (0x00000800) /*!< ADC OFFSET1 bit 11 */

#define ADC_OFR1_OFFSET1_CH     (0x7C000000) /*!< ADC Channel selection for the data offset 1 */
#define ADC_OFR1_OFFSET1_CH_0  (0x04000000) /*!< ADC OFFSET1_CH bit 0 */
#define ADC_OFR1_OFFSET1_CH_1  (0x08000000) /*!< ADC OFFSET1_CH bit 1 */
#define ADC_OFR1_OFFSET1_CH_2  (0x10000000) /*!< ADC OFFSET1_CH bit 2 */
#define ADC_OFR1_OFFSET1_CH_3  (0x20000000) /*!< ADC OFFSET1_CH bit 3 */
#define ADC_OFR1_OFFSET1_CH_4  (0x40000000) /*!< ADC OFFSET1_CH bit 4 */

#define ADC_OFR1_OFFSET1_EN (0x80000000) /*!< ADC offset 1 enable */

#define ADC_OFR2_OFFSET2    (0x00000FFF) /*!< ADC data offset 2 for channel programmed into bits OFFSET2_CH[4:0] */
#define ADC_OFR2_OFFSET2_0  (0x00000001) /*!< ADC OFFSET2 bit 0 */
#define ADC_OFR2_OFFSET2_1  (0x00000002) /*!< ADC OFFSET2 bit 1 */
#define ADC_OFR2_OFFSET2_2  (0x00000004) /*!< ADC OFFSET2 bit 2 */
#define ADC_OFR2_OFFSET2_3  (0x00000008) /*!< ADC OFFSET2 bit 3 */
#define ADC_OFR2_OFFSET2_4  (0x00000010) /*!< ADC OFFSET2 bit 4 */
#define ADC_OFR2_OFFSET2_5  (0x00000020) /*!< ADC OFFSET2 bit 5 */
#define ADC_OFR2_OFFSET2_6  (0x00000040) /*!< ADC OFFSET2 bit 6 */
#define ADC_OFR2_OFFSET2_7  (0x00000080) /*!< ADC OFFSET2 bit 7 */
#define ADC_OFR2_OFFSET2_8  (0x00000100) /*!< ADC OFFSET2 bit 8 */
#define ADC_OFR2_OFFSET2_9  (0x00000200) /*!< ADC OFFSET2 bit 9 */
#define ADC_OFR2_OFFSET2_10 (0x00000400) /*!< ADC OFFSET2 bit 10 */
#define ADC_OFR2_OFFSET2_11 (0x00000800) /*!< ADC OFFSET2 bit 11 */

#define ADC_OFR2_OFFSET2_CH     (0x7C000000) /*!< ADC Channel selection for the data offset 2 */
#define ADC_OFR2_OFFSET2_CH_0  (0x04000000) /*!< ADC OFFSET2_CH bit 0 */
#define ADC_OFR2_OFFSET2_CH_1  (0x08000000) /*!< ADC OFFSET2_CH bit 1 */
#define ADC_OFR2_OFFSET2_CH_2  (0x10000000) /*!< ADC OFFSET2_CH bit 2 */
#define ADC_OFR2_OFFSET2_CH_3  (0x20000000) /*!< ADC OFFSET2_CH bit 3 */
#define ADC_OFR2_OFFSET2_CH_4  (0x40000000) /*!< ADC OFFSET2_CH bit 4 */

#define ADC_OFR2_OFFSET2_EN (0x80000000) /*!< ADC offset 2 enable */

#define ADC_OFR3_OFFSET3    (0x00000FFF) /*!< ADC data offset 3 for channel programmed into bits OFFSET3_CH[4:0] */
#define ADC_OFR3_OFFSET3_0  (0x00000001) /*!< ADC OFFSET3 bit 0 */
#define ADC_OFR3_OFFSET3_1  (0x00000002) /*!< ADC OFFSET3 bit 1 */
#define ADC_OFR3_OFFSET3_2  (0x00000004) /*!< ADC OFFSET3 bit 2 */
#define ADC_OFR3_OFFSET3_3  (0x00000008) /*!< ADC OFFSET3 bit 3 */
#define ADC_OFR3_OFFSET3_4  (0x00000010) /*!< ADC OFFSET3 bit 4 */
#define ADC_OFR3_OFFSET3_5  (0x00000020) /*!< ADC OFFSET3 bit 5 */
#define ADC_OFR3_OFFSET3_6  (0x00000040) /*!< ADC OFFSET3 bit 6 */
#define ADC_OFR3_OFFSET3_7  (0x00000080) /*!< ADC OFFSET3 bit 7 */
#define ADC_OFR3_OFFSET3_8  (0x00000100) /*!< ADC OFFSET3 bit 8 */
#define ADC_OFR3_OFFSET3_9  (0x00000200) /*!< ADC OFFSET3 bit 9 */
#define ADC_OFR3_OFFSET3_10 (0x00000400) /*!< ADC OFFSET3 bit 10 */
#define ADC_OFR3_OFFSET3_11 (0x00000800) /*!< ADC OFFSET3 bit 11 */

#define ADC_OFR3_OFFSET3_CH     (0x7C000000) /*!< ADC Channel selection for the data offset 3 */
#define ADC_OFR3_OFFSET3_CH_0  (0x04000000) /*!< ADC OFFSET3_CH bit 0 */
#define ADC_OFR3_OFFSET3_CH_1  (0x08000000) /*!< ADC OFFSET3_CH bit 1 */
#define ADC_OFR3_OFFSET3_CH_2  (0x10000000) /*!< ADC OFFSET3_CH bit 2 */
#define ADC_OFR3_OFFSET3_CH_3  (0x20000000) /*!< ADC OFFSET3_CH bit 3 */
#define ADC_OFR3_OFFSET3_CH_4  (0x40000000) /*!< ADC OFFSET3_CH bit 4 */

#define ADC_OFR3_OFFSET3_EN (0x80000000) /*!< ADC offset 3 enable */

#define ADC_OFR4_OFFSET4    (0x00000FFF) /*!< ADC data offset 4 for channel programmed into bits OFFSET4_CH[4:0] */
#define ADC_OFR4_OFFSET4_0  (0x00000001) /*!< ADC OFFSET4 bit 0 */
#define ADC_OFR4_OFFSET4_1  (0x00000002) /*!< ADC OFFSET4 bit 1 */
#define ADC_OFR4_OFFSET4_2  (0x00000004) /*!< ADC OFFSET4 bit 2 */
#define ADC_OFR4_OFFSET4_3  (0x00000008) /*!< ADC OFFSET4 bit 3 */
#define ADC_OFR4_OFFSET4_4  (0x00000010) /*!< ADC OFFSET4 bit 4 */
#define ADC_OFR4_OFFSET4_5  (0x00000020) /*!< ADC OFFSET4 bit 5 */
#define ADC_OFR4_OFFSET4_6  (0x00000040) /*!< ADC OFFSET4 bit 6 */
#define ADC_OFR4_OFFSET4_7  (0x00000080) /*!< ADC OFFSET4 bit 7 */
#define ADC_OFR4_OFFSET4_8  (0x00000100) /*!< ADC OFFSET4 bit 8 */
#define ADC_OFR4_OFFSET4_9  (0x00000200) /*!< ADC OFFSET4 bit 9 */
#define ADC_OFR4_OFFSET4_10 (0x00000400) /*!< ADC OFFSET4 bit 10 */
#define ADC_OFR4_OFFSET4_11 (0x00000800) /*!< ADC OFFSET4 bit 11 */

#define ADC_OFR4_OFFSET4_CH     (0x7C000000) /*!< ADC Channel selection for the data offset 4 */
#define ADC_OFR4_OFFSET4_CH_0  (0x04000000) /*!< ADC OFFSET4_CH bit 0 */
#define ADC_OFR4_OFFSET4_CH_1  (0x08000000) /*!< ADC OFFSET4_CH bit 1 */
#define ADC_OFR4_OFFSET4_CH_2  (0x10000000) /*!< ADC OFFSET4_CH bit 2 */
#define ADC_OFR4_OFFSET4_CH_3  (0x20000000) /*!< ADC OFFSET4_CH bit 3 */
#define ADC_OFR4_OFFSET4_CH_4  (0x40000000) /*!< ADC OFFSET4_CH bit 4 */

#define ADC_OFR4_OFFSET4_EN (0x80000000) /*!< ADC offset 4 enable */

#define ADC_JDR1_JDATA      (0x0000FFFF) /*!< ADC Injected DATA */
#define ADC_JDR1_JDATA_0    (0x00000001) /*!< ADC JDATA bit 0 */
#define ADC_JDR1_JDATA_1    (0x00000002) /*!< ADC JDATA bit 1 */
#define ADC_JDR1_JDATA_2    (0x00000004) /*!< ADC JDATA bit 2 */
#define ADC_JDR1_JDATA_3    (0x00000008) /*!< ADC JDATA bit 3 */
#define ADC_JDR1_JDATA_4    (0x00000010) /*!< ADC JDATA bit 4 */
#define ADC_JDR1_JDATA_5    (0x00000020) /*!< ADC JDATA bit 5 */
#define ADC_JDR1_JDATA_6    (0x00000040) /*!< ADC JDATA bit 6 */
#define ADC_JDR1_JDATA_7    (0x00000080) /*!< ADC JDATA bit 7 */
#define ADC_JDR1_JDATA_8    (0x00000100) /*!< ADC JDATA bit 8 */
#define ADC_JDR1_JDATA_9    (0x00000200) /*!< ADC JDATA bit 9 */
#define ADC_JDR1_JDATA_10   (0x00000400) /*!< ADC JDATA bit 10 */
#define ADC_JDR1_JDATA_11   (0x00000800) /*!< ADC JDATA bit 11 */
#define ADC_JDR1_JDATA_12   (0x00001000) /*!< ADC JDATA bit 12 */
#define ADC_JDR1_JDATA_13   (0x00002000) /*!< ADC JDATA bit 13 */
#define ADC_JDR1_JDATA_14   (0x00004000) /*!< ADC JDATA bit 14 */
#define ADC_JDR1_JDATA_15   (0x00008000) /*!< ADC JDATA bit 15 */

#define ADC_JDR2_JDATA      (0x0000FFFF) /*!< ADC Injected DATA */
#define ADC_JDR2_JDATA_0    (0x00000001) /*!< ADC JDATA bit 0 */
#define ADC_JDR2_JDATA_1    (0x00000002) /*!< ADC JDATA bit 1 */
#define ADC_JDR2_JDATA_2    (0x00000004) /*!< ADC JDATA bit 2 */
#define ADC_JDR2_JDATA_3    (0x00000008) /*!< ADC JDATA bit 3 */
#define ADC_JDR2_JDATA_4    (0x00000010) /*!< ADC JDATA bit 4 */
#define ADC_JDR2_JDATA_5    (0x00000020) /*!< ADC JDATA bit 5 */
#define ADC_JDR2_JDATA_6    (0x00000040) /*!< ADC JDATA bit 6 */
#define ADC_JDR2_JDATA_7    (0x00000080) /*!< ADC JDATA bit 7 */
#define ADC_JDR2_JDATA_8    (0x00000100) /*!< ADC JDATA bit 8 */
#define ADC_JDR2_JDATA_9    (0x00000200) /*!< ADC JDATA bit 9 */
#define ADC_JDR2_JDATA_10   (0x00000400) /*!< ADC JDATA bit 10 */
#define ADC_JDR2_JDATA_11   (0x00000800) /*!< ADC JDATA bit 11 */
#define ADC_JDR2_JDATA_12   (0x00001000) /*!< ADC JDATA bit 12 */
#define ADC_JDR2_JDATA_13   (0x00002000) /*!< ADC JDATA bit 13 */
#define ADC_JDR2_JDATA_14   (0x00004000) /*!< ADC JDATA bit 14 */
#define ADC_JDR2_JDATA_15   (0x00008000) /*!< ADC JDATA bit 15 */

#define ADC_JDR3_JDATA      (0x0000FFFF) /*!< ADC Injected DATA */
#define ADC_JDR3_JDATA_0    (0x00000001) /*!< ADC JDATA bit 0 */
#define ADC_JDR3_JDATA_1    (0x00000002) /*!< ADC JDATA bit 1 */
#define ADC_JDR3_JDATA_2    (0x00000004) /*!< ADC JDATA bit 2 */
#define ADC_JDR3_JDATA_3    (0x00000008) /*!< ADC JDATA bit 3 */
#define ADC_JDR3_JDATA_4    (0x00000010) /*!< ADC JDATA bit 4 */
#define ADC_JDR3_JDATA_5    (0x00000020) /*!< ADC JDATA bit 5 */
#define ADC_JDR3_JDATA_6    (0x00000040) /*!< ADC JDATA bit 6 */
#define ADC_JDR3_JDATA_7    (0x00000080) /*!< ADC JDATA bit 7 */
#define ADC_JDR3_JDATA_8    (0x00000100) /*!< ADC JDATA bit 8 */
#define ADC_JDR3_JDATA_9    (0x00000200) /*!< ADC JDATA bit 9 */
#define ADC_JDR3_JDATA_10   (0x00000400) /*!< ADC JDATA bit 10 */
#define ADC_JDR3_JDATA_11   (0x00000800) /*!< ADC JDATA bit 11 */
#define ADC_JDR3_JDATA_12   (0x00001000) /*!< ADC JDATA bit 12 */
#define ADC_JDR3_JDATA_13   (0x00002000) /*!< ADC JDATA bit 13 */
#define ADC_JDR3_JDATA_14   (0x00004000) /*!< ADC JDATA bit 14 */
#define ADC_JDR3_JDATA_15   (0x00008000) /*!< ADC JDATA bit 15 */

#define ADC_JDR4_JDATA      (0x0000FFFF) /*!< ADC Injected DATA */
#define ADC_JDR4_JDATA_0    (0x00000001) /*!< ADC JDATA bit 0 */
#define ADC_JDR4_JDATA_1    (0x00000002) /*!< ADC JDATA bit 1 */
#define ADC_JDR4_JDATA_2    (0x00000004) /*!< ADC JDATA bit 2 */
#define ADC_JDR4_JDATA_3    (0x00000008) /*!< ADC JDATA bit 3 */
#define ADC_JDR4_JDATA_4    (0x00000010) /*!< ADC JDATA bit 4 */
#define ADC_JDR4_JDATA_5    (0x00000020) /*!< ADC JDATA bit 5 */
#define ADC_JDR4_JDATA_6    (0x00000040) /*!< ADC JDATA bit 6 */
#define ADC_JDR4_JDATA_7    (0x00000080) /*!< ADC JDATA bit 7 */
#define ADC_JDR4_JDATA_8    (0x00000100) /*!< ADC JDATA bit 8 */
#define ADC_JDR4_JDATA_9    (0x00000200) /*!< ADC JDATA bit 9 */
#define ADC_JDR4_JDATA_10   (0x00000400) /*!< ADC JDATA bit 10 */
#define ADC_JDR4_JDATA_11   (0x00000800) /*!< ADC JDATA bit 11 */
#define ADC_JDR4_JDATA_12   (0x00001000) /*!< ADC JDATA bit 12 */
#define ADC_JDR4_JDATA_13   (0x00002000) /*!< ADC JDATA bit 13 */
#define ADC_JDR4_JDATA_14   (0x00004000) /*!< ADC JDATA bit 14 */
#define ADC_JDR4_JDATA_15   (0x00008000) /*!< ADC JDATA bit 15 */

#define ADC_AWD2CR_AWD2CH    (0x0007FFFE) /*!< ADC Analog watchdog 2 channel selection */
#define ADC_AWD2CR_AWD2CH_0  (0x00000002) /*!< ADC AWD2CH bit 0 */
#define ADC_AWD2CR_AWD2CH_1  (0x00000004) /*!< ADC AWD2CH bit 1 */
#define ADC_AWD2CR_AWD2CH_2  (0x00000008) /*!< ADC AWD2CH bit 2 */
#define ADC_AWD2CR_AWD2CH_3  (0x00000010) /*!< ADC AWD2CH bit 3 */
#define ADC_AWD2CR_AWD2CH_4  (0x00000020) /*!< ADC AWD2CH bit 4 */
#define ADC_AWD2CR_AWD2CH_5  (0x00000040) /*!< ADC AWD2CH bit 5 */
#define ADC_AWD2CR_AWD2CH_6  (0x00000080) /*!< ADC AWD2CH bit 6 */
#define ADC_AWD2CR_AWD2CH_7  (0x00000100) /*!< ADC AWD2CH bit 7 */
#define ADC_AWD2CR_AWD2CH_8  (0x00000200) /*!< ADC AWD2CH bit 8 */
#define ADC_AWD2CR_AWD2CH_9  (0x00000400) /*!< ADC AWD2CH bit 9 */
#define ADC_AWD2CR_AWD2CH_10 (0x00000800) /*!< ADC AWD2CH bit 10 */
#define ADC_AWD2CR_AWD2CH_11 (0x00001000) /*!< ADC AWD2CH bit 11 */
#define ADC_AWD2CR_AWD2CH_12 (0x00002000) /*!< ADC AWD2CH bit 12 */
#define ADC_AWD2CR_AWD2CH_13 (0x00004000) /*!< ADC AWD2CH bit 13 */
#define ADC_AWD2CR_AWD2CH_14 (0x00008000) /*!< ADC AWD2CH bit 14 */
#define ADC_AWD2CR_AWD2CH_15 (0x00010000) /*!< ADC AWD2CH bit 15 */
#define ADC_AWD2CR_AWD2CH_16 (0x00020000) /*!< ADC AWD2CH bit 16 */
#define ADC_AWD2CR_AWD2CH_17 (0x00030000) /*!< ADC AWD2CH bit 17 */

#define ADC_AWD3CR_AWD3CH    (0x0007FFFE) /*!< ADC Analog watchdog 2 channel selection */
#define ADC_AWD3CR_AWD3CH_0  (0x00000002) /*!< ADC AWD3CH bit 0 */
#define ADC_AWD3CR_AWD3CH_1  (0x00000004) /*!< ADC AWD3CH bit 1 */
#define ADC_AWD3CR_AWD3CH_2  (0x00000008) /*!< ADC AWD3CH bit 2 */
#define ADC_AWD3CR_AWD3CH_3  (0x00000010) /*!< ADC AWD3CH bit 3 */
#define ADC_AWD3CR_AWD3CH_4  (0x00000020) /*!< ADC AWD3CH bit 4 */
#define ADC_AWD3CR_AWD3CH_5  (0x00000040) /*!< ADC AWD3CH bit 5 */
#define ADC_AWD3CR_AWD3CH_6  (0x00000080) /*!< ADC AWD3CH bit 6 */
#define ADC_AWD3CR_AWD3CH_7  (0x00000100) /*!< ADC AWD3CH bit 7 */
#define ADC_AWD3CR_AWD3CH_8  (0x00000200) /*!< ADC AWD3CH bit 8 */
#define ADC_AWD3CR_AWD3CH_9  (0x00000400) /*!< ADC AWD3CH bit 9 */
#define ADC_AWD3CR_AWD3CH_10 (0x00000800) /*!< ADC AWD3CH bit 10 */
#define ADC_AWD3CR_AWD3CH_11 (0x00001000) /*!< ADC AWD3CH bit 11 */
#define ADC_AWD3CR_AWD3CH_12 (0x00002000) /*!< ADC AWD3CH bit 12 */
#define ADC_AWD3CR_AWD3CH_13 (0x00004000) /*!< ADC AWD3CH bit 13 */
#define ADC_AWD3CR_AWD3CH_14 (0x00008000) /*!< ADC AWD3CH bit 14 */
#define ADC_AWD3CR_AWD3CH_15 (0x00010000) /*!< ADC AWD3CH bit 15 */
#define ADC_AWD3CR_AWD3CH_16 (0x00020000) /*!< ADC AWD3CH bit 16 */
#define ADC_AWD3CR_AWD3CH_17 (0x00030000) /*!< ADC AWD3CH bit 17 */

#define ADC_DIFSEL_DIFSEL    (0x0007FFFE) /*!< ADC differential modes for channels 1 to 18 */
#define ADC_DIFSEL_DIFSEL_0  (0x00000002) /*!< ADC DIFSEL bit 0 */
#define ADC_DIFSEL_DIFSEL_1  (0x00000004) /*!< ADC DIFSEL bit 1 */
#define ADC_DIFSEL_DIFSEL_2  (0x00000008) /*!< ADC DIFSEL bit 2 */
#define ADC_DIFSEL_DIFSEL_3  (0x00000010) /*!< ADC DIFSEL bit 3 */
#define ADC_DIFSEL_DIFSEL_4  (0x00000020) /*!< ADC DIFSEL bit 4 */
#define ADC_DIFSEL_DIFSEL_5  (0x00000040) /*!< ADC DIFSEL bit 5 */
#define ADC_DIFSEL_DIFSEL_6  (0x00000080) /*!< ADC DIFSEL bit 6 */
#define ADC_DIFSEL_DIFSEL_7  (0x00000100) /*!< ADC DIFSEL bit 7 */
#define ADC_DIFSEL_DIFSEL_8  (0x00000200) /*!< ADC DIFSEL bit 8 */
#define ADC_DIFSEL_DIFSEL_9  (0x00000400) /*!< ADC DIFSEL bit 9 */
#define ADC_DIFSEL_DIFSEL_10 (0x00000800) /*!< ADC DIFSEL bit 10 */
#define ADC_DIFSEL_DIFSEL_11 (0x00001000) /*!< ADC DIFSEL bit 11 */
#define ADC_DIFSEL_DIFSEL_12 (0x00002000) /*!< ADC DIFSEL bit 12 */
#define ADC_DIFSEL_DIFSEL_13 (0x00004000) /*!< ADC DIFSEL bit 13 */
#define ADC_DIFSEL_DIFSEL_14 (0x00008000) /*!< ADC DIFSEL bit 14 */
#define ADC_DIFSEL_DIFSEL_15 (0x00010000) /*!< ADC DIFSEL bit 15 */
#define ADC_DIFSEL_DIFSEL_16 (0x00020000) /*!< ADC DIFSEL bit 16 */
#define ADC_DIFSEL_DIFSEL_17 (0x00030000) /*!< ADC DIFSEL bit 17 */

#define ADC_CALFACT_CALFACT_S   (0x0000007F) /*!< ADC calibration factors in single-ended mode */
#define ADC_CALFACT_CALFACT_S_0 (0x00000001) /*!< ADC CALFACT_S bit 0 */
#define ADC_CALFACT_CALFACT_S_1 (0x00000002) /*!< ADC CALFACT_S bit 1 */
#define ADC_CALFACT_CALFACT_S_2 (0x00000004) /*!< ADC CALFACT_S bit 2 */
#define ADC_CALFACT_CALFACT_S_3 (0x00000008) /*!< ADC CALFACT_S bit 3 */
#define ADC_CALFACT_CALFACT_S_4 (0x00000010) /*!< ADC CALFACT_S bit 4 */
#define ADC_CALFACT_CALFACT_S_5 (0x00000020) /*!< ADC CALFACT_S bit 5 */
#define ADC_CALFACT_CALFACT_S_6 (0x00000040) /*!< ADC CALFACT_S bit 6 */
#define ADC_CALFACT_CALFACT_D   (0x007F0000) /*!< ADC calibration factors in differential mode */
#define ADC_CALFACT_CALFACT_D_0 (0x00010000) /*!< ADC CALFACT_D bit 0 */
#define ADC_CALFACT_CALFACT_D_1 (0x00020000) /*!< ADC CALFACT_D bit 1 */
#define ADC_CALFACT_CALFACT_D_2 (0x00040000) /*!< ADC CALFACT_D bit 2 */
#define ADC_CALFACT_CALFACT_D_3 (0x00080000) /*!< ADC CALFACT_D bit 3 */
#define ADC_CALFACT_CALFACT_D_4 (0x00100000) /*!< ADC CALFACT_D bit 4 */
#define ADC_CALFACT_CALFACT_D_5 (0x00200000) /*!< ADC CALFACT_D bit 5 */
#define ADC_CALFACT_CALFACT_D_6 (0x00400000) /*!< ADC CALFACT_D bit 6 */

#define ADC12_CSR_ADRDY_MST         (0x00000001) /*!< Master ADC ready */
#define ADC12_CSR_ADRDY_EOSMP_MST   (0x00000002) /*!< End of sampling phase flag of the master ADC */
#define ADC12_CSR_ADRDY_EOC_MST     (0x00000004) /*!< End of regular conversion of the master ADC */
#define ADC12_CSR_ADRDY_EOS_MST     (0x00000008) /*!< End of regular sequence flag of the master ADC */
#define ADC12_CSR_ADRDY_OVR_MST     (0x00000010) /*!< Overrun flag of the master ADC */
#define ADC12_CSR_ADRDY_JEOC_MST    (0x00000020) /*!< End of injected conversion of the master ADC */
#define ADC12_CSR_ADRDY_JEOS_MST    (0x00000040) /*!< End of injected sequence flag of the master ADC */
#define ADC12_CSR_AWD1_MST          (0x00000080) /*!< Analog watchdog 1 flag of the master ADC */
#define ADC12_CSR_AWD2_MST          (0x00000100) /*!< Analog watchdog 2 flag of the master ADC */
#define ADC12_CSR_AWD3_MST          (0x00000200) /*!< Analog watchdog 3 flag of the master ADC */
#define ADC12_CSR_JQOVF_MST         (0x00000400) /*!< Injected context queue overflow flag of the master ADC */
#define ADC12_CSR_ADRDY_SLV         (0x00010000) /*!< Slave ADC ready */
#define ADC12_CSR_ADRDY_EOSMP_SLV   (0x00020000) /*!< End of sampling phase flag of the slave ADC */
#define ADC12_CSR_ADRDY_EOC_SLV     (0x00040000) /*!< End of regular conversion of the slave ADC */
#define ADC12_CSR_ADRDY_EOS_SLV     (0x00080000) /*!< End of regular sequence flag of the slave ADC */
#define ADC12_CSR_ADRDY_OVR_SLV     (0x00100000) /*!< Overrun flag of the slave ADC */
#define ADC12_CSR_ADRDY_JEOC_SLV    (0x00200000) /*!< End of injected conversion of the slave ADC */
#define ADC12_CSR_ADRDY_JEOS_SLV    (0x00400000) /*!< End of injected sequence flag of the slave ADC */
#define ADC12_CSR_AWD1_SLV          (0x00800000) /*!< Analog watchdog 1 flag of the slave ADC */
#define ADC12_CSR_AWD2_SLV          (0x01000000) /*!< Analog watchdog 2 flag of the slave ADC */
#define ADC12_CSR_AWD3_SLV          (0x02000000) /*!< Analog watchdog 3 flag of the slave ADC */
#define ADC12_CSR_JQOVF_SLV         (0x04000000) /*!< Injected context queue overflow flag of the slave ADC */

#define ADC34_CSR_ADRDY_MST         (0x00000001) /*!< Master ADC ready */
#define ADC34_CSR_ADRDY_EOSMP_MST   (0x00000002) /*!< End of sampling phase flag of the master ADC */
#define ADC34_CSR_ADRDY_EOC_MST     (0x00000004) /*!< End of regular conversion of the master ADC */
#define ADC34_CSR_ADRDY_EOS_MST     (0x00000008) /*!< End of regular sequence flag of the master ADC */
#define ADC34_CSR_ADRDY_OVR_MST     (0x00000010) /*!< Overrun flag of the master ADC */
#define ADC34_CSR_ADRDY_JEOC_MST    (0x00000020) /*!< End of injected conversion of the master ADC */
#define ADC34_CSR_ADRDY_JEOS_MST    (0x00000040) /*!< End of injected sequence flag of the master ADC */
#define ADC34_CSR_AWD1_MST          (0x00000080) /*!< Analog watchdog 1 flag of the master ADC */
#define ADC34_CSR_AWD2_MST          (0x00000100) /*!< Analog watchdog 2 flag of the master ADC */
#define ADC34_CSR_AWD3_MST          (0x00000200) /*!< Analog watchdog 3 flag of the master ADC */
#define ADC34_CSR_JQOVF_MST         (0x00000400) /*!< Injected context queue overflow flag of the master ADC */
#define ADC34_CSR_ADRDY_SLV         (0x00010000) /*!< Slave ADC ready */
#define ADC34_CSR_ADRDY_EOSMP_SLV   (0x00020000) /*!< End of sampling phase flag of the slave ADC */
#define ADC34_CSR_ADRDY_EOC_SLV     (0x00040000) /*!< End of regular conversion of the slave ADC */
#define ADC34_CSR_ADRDY_EOS_SLV     (0x00080000) /*!< End of regular sequence flag of the slave ADC */
#define ADC12_CSR_ADRDY_OVR_SLV     (0x00100000) /*!< Overrun flag of the slave ADC */
#define ADC34_CSR_ADRDY_JEOC_SLV    (0x00200000) /*!< End of injected conversion of the slave ADC */
#define ADC34_CSR_ADRDY_JEOS_SLV    (0x00400000) /*!< End of injected sequence flag of the slave ADC */
#define ADC34_CSR_AWD1_SLV          (0x00800000) /*!< Analog watchdog 1 flag of the slave ADC */
#define ADC34_CSR_AWD2_SLV          (0x01000000) /*!< Analog watchdog 2 flag of the slave ADC */
#define ADC34_CSR_AWD3_SLV          (0x02000000) /*!< Analog watchdog 3 flag of the slave ADC */
#define ADC34_CSR_JQOVF_SLV         (0x04000000) /*!< Injected context queue overflow flag of the slave ADC */

#define ADC12_CCR_MULTI             (0x0000001F) /*!< Multi ADC mode selection */
#define ADC12_CCR_MULTI_0           (0x00000001) /*!< MULTI bit 0 */
#define ADC12_CCR_MULTI_1           (0x00000002) /*!< MULTI bit 1 */
#define ADC12_CCR_MULTI_2           (0x00000004) /*!< MULTI bit 2 */
#define ADC12_CCR_MULTI_3           (0x00000008) /*!< MULTI bit 3 */
#define ADC12_CCR_MULTI_4           (0x00000010) /*!< MULTI bit 4 */
#define ADC12_CCR_DELAY             (0x00000F00) /*!< Delay between 2 sampling phases */
#define ADC12_CCR_DELAY_0           (0x00000100) /*!< DELAY bit 0 */
#define ADC12_CCR_DELAY_1           (0x00000200) /*!< DELAY bit 1 */
#define ADC12_CCR_DELAY_2           (0x00000400) /*!< DELAY bit 2 */
#define ADC12_CCR_DELAY_3           (0x00000800) /*!< DELAY bit 3 */
#define ADC12_CCR_DMACFG            (0x00002000) /*!< DMA configuration for multi-ADC mode */
#define ADC12_CCR_MDMA              (0x0000C000) /*!< DMA mode for multi-ADC mode */
#define ADC12_CCR_MDMA_0            (0x00004000) /*!< MDMA bit 0 */
#define ADC12_CCR_MDMA_1            (0x00008000) /*!< MDMA bit 1 */
#define ADC12_CCR_CKMODE            (0x00030000) /*!< ADC clock mode */
#define ADC12_CCR_CKMODE_0          (0x00010000) /*!< CKMODE bit 0 */
#define ADC12_CCR_CKMODE_1          (0x00020000) /*!< CKMODE bit 1 */
#define ADC12_CCR_VREFEN            (0x00400000) /*!< VREFINT enable */
#define ADC12_CCR_TSEN              (0x00800000) /*!< Temperature sensor enable */
#define ADC12_CCR_VBATEN            (0x01000000) /*!< VBAT enable */

#define ADC34_CCR_MULTI             (0x0000001F) /*!< Multi ADC mode selection */
#define ADC34_CCR_MULTI_0           (0x00000001) /*!< MULTI bit 0 */
#define ADC34_CCR_MULTI_1           (0x00000002) /*!< MULTI bit 1 */
#define ADC34_CCR_MULTI_2           (0x00000004) /*!< MULTI bit 2 */
#define ADC34_CCR_MULTI_3           (0x00000008) /*!< MULTI bit 3 */
#define ADC34_CCR_MULTI_4           (0x00000010) /*!< MULTI bit 4 */

#define ADC34_CCR_DELAY             (0x00000F00) /*!< Delay between 2 sampling phases */
#define ADC34_CCR_DELAY_0           (0x00000100) /*!< DELAY bit 0 */
#define ADC34_CCR_DELAY_1           (0x00000200) /*!< DELAY bit 1 */
#define ADC34_CCR_DELAY_2           (0x00000400) /*!< DELAY bit 2 */
#define ADC34_CCR_DELAY_3           (0x00000800) /*!< DELAY bit 3 */

#define ADC34_CCR_DMACFG            (0x00002000) /*!< DMA configuration for multi-ADC mode */
#define ADC34_CCR_MDMA              (0x0000C000) /*!< DMA mode for multi-ADC mode */
#define ADC34_CCR_MDMA_0            (0x00004000) /*!< MDMA bit 0 */
#define ADC34_CCR_MDMA_1            (0x00008000) /*!< MDMA bit 1 */

#define ADC34_CCR_CKMODE            (0x00030000) /*!< ADC clock mode */
#define ADC34_CCR_CKMODE_0          (0x00010000) /*!< CKMODE bit 0 */
#define ADC34_CCR_CKMODE_1          (0x00020000) /*!< CKMODE bit 1 */

#define ADC34_CCR_VREFEN            (0x00400000) /*!< VREFINT enable */

#define ADC12_CDR_RDATA_MST         (0x0000FFFF) /*!< Regular Data of the master ADC */
#define ADC12_CDR_RDATA_MST_0       (0x00000001) /*!< RDATA_MST bit 0 */
#define ADC12_CDR_RDATA_MST_1       (0x00000002) /*!< RDATA_MST bit 1 */
#define ADC12_CDR_RDATA_MST_2       (0x00000004) /*!< RDATA_MST bit 2 */
#define ADC12_CDR_RDATA_MST_3       (0x00000008) /*!< RDATA_MST bit 3 */
#define ADC12_CDR_RDATA_MST_4       (0x00000010) /*!< RDATA_MST bit 4 */
#define ADC12_CDR_RDATA_MST_5       (0x00000020) /*!< RDATA_MST bit 5 */
#define ADC12_CDR_RDATA_MST_6       (0x00000040) /*!< RDATA_MST bit 6 */
#define ADC12_CDR_RDATA_MST_7       (0x00000080) /*!< RDATA_MST bit 7 */
#define ADC12_CDR_RDATA_MST_8       (0x00000100) /*!< RDATA_MST bit 8 */
#define ADC12_CDR_RDATA_MST_9       (0x00000200) /*!< RDATA_MST bit 9 */
#define ADC12_CDR_RDATA_MST_10      (0x00000400) /*!< RDATA_MST bit 10 */
#define ADC12_CDR_RDATA_MST_11      (0x00000800) /*!< RDATA_MST bit 11 */
#define ADC12_CDR_RDATA_MST_12      (0x00001000) /*!< RDATA_MST bit 12 */
#define ADC12_CDR_RDATA_MST_13      (0x00002000) /*!< RDATA_MST bit 13 */
#define ADC12_CDR_RDATA_MST_14      (0x00004000) /*!< RDATA_MST bit 14 */
#define ADC12_CDR_RDATA_MST_15      (0x00008000) /*!< RDATA_MST bit 15 */

#define ADC12_CDR_RDATA_SLV         (0xFFFF0000) /*!< Regular Data of the master ADC */
#define ADC12_CDR_RDATA_SLV_0       (0x00010000) /*!< RDATA_SLV bit 0 */
#define ADC12_CDR_RDATA_SLV_1       (0x00020000) /*!< RDATA_SLV bit 1 */
#define ADC12_CDR_RDATA_SLV_2       (0x00040000) /*!< RDATA_SLV bit 2 */
#define ADC12_CDR_RDATA_SLV_3       (0x00080000) /*!< RDATA_SLV bit 3 */
#define ADC12_CDR_RDATA_SLV_4       (0x00100000) /*!< RDATA_SLV bit 4 */
#define ADC12_CDR_RDATA_SLV_5       (0x00200000) /*!< RDATA_SLV bit 5 */
#define ADC12_CDR_RDATA_SLV_6       (0x00400000) /*!< RDATA_SLV bit 6 */
#define ADC12_CDR_RDATA_SLV_7       (0x00800000) /*!< RDATA_SLV bit 7 */
#define ADC12_CDR_RDATA_SLV_8       (0x01000000) /*!< RDATA_SLV bit 8 */
#define ADC12_CDR_RDATA_SLV_9       (0x02000000) /*!< RDATA_SLV bit 9 */
#define ADC12_CDR_RDATA_SLV_10      (0x04000000) /*!< RDATA_SLV bit 10 */
#define ADC12_CDR_RDATA_SLV_11      (0x08000000) /*!< RDATA_SLV bit 11 */
#define ADC12_CDR_RDATA_SLV_12      (0x10000000) /*!< RDATA_SLV bit 12 */
#define ADC12_CDR_RDATA_SLV_13      (0x20000000) /*!< RDATA_SLV bit 13 */
#define ADC12_CDR_RDATA_SLV_14      (0x40000000) /*!< RDATA_SLV bit 14 */
#define ADC12_CDR_RDATA_SLV_15      (0x80000000) /*!< RDATA_SLV bit 15 */

#define ADC34_CDR_RDATA_MST         (0x0000FFFF) /*!< Regular Data of the master ADC */
#define ADC34_CDR_RDATA_MST_0       (0x00000001) /*!< RDATA_MST bit 0 */
#define ADC34_CDR_RDATA_MST_1       (0x00000002) /*!< RDATA_MST bit 1 */
#define ADC34_CDR_RDATA_MST_2       (0x00000004) /*!< RDATA_MST bit 2 */
#define ADC34_CDR_RDATA_MST_3       (0x00000008) /*!< RDATA_MST bit 3 */
#define ADC34_CDR_RDATA_MST_4       (0x00000010) /*!< RDATA_MST bit 4 */
#define ADC34_CDR_RDATA_MST_5       (0x00000020) /*!< RDATA_MST bit 5 */
#define ADC34_CDR_RDATA_MST_6       (0x00000040) /*!< RDATA_MST bit 6 */
#define ADC34_CDR_RDATA_MST_7       (0x00000080) /*!< RDATA_MST bit 7 */
#define ADC34_CDR_RDATA_MST_8       (0x00000100) /*!< RDATA_MST bit 8 */
#define ADC34_CDR_RDATA_MST_9       (0x00000200) /*!< RDATA_MST bit 9 */
#define ADC34_CDR_RDATA_MST_10      (0x00000400) /*!< RDATA_MST bit 10 */
#define ADC34_CDR_RDATA_MST_11      (0x00000800) /*!< RDATA_MST bit 11 */
#define ADC34_CDR_RDATA_MST_12      (0x00001000) /*!< RDATA_MST bit 12 */
#define ADC34_CDR_RDATA_MST_13      (0x00002000) /*!< RDATA_MST bit 13 */
#define ADC34_CDR_RDATA_MST_14      (0x00004000) /*!< RDATA_MST bit 14 */
#define ADC34_CDR_RDATA_MST_15      (0x00008000) /*!< RDATA_MST bit 15 */

#define ADC34_CDR_RDATA_SLV         (0xFFFF0000) /*!< Regular Data of the master ADC */
#define ADC34_CDR_RDATA_SLV_0       (0x00010000) /*!< RDATA_SLV bit 0 */
#define ADC34_CDR_RDATA_SLV_1       (0x00020000) /*!< RDATA_SLV bit 1 */
#define ADC34_CDR_RDATA_SLV_2       (0x00040000) /*!< RDATA_SLV bit 2 */
#define ADC34_CDR_RDATA_SLV_3       (0x00080000) /*!< RDATA_SLV bit 3 */
#define ADC34_CDR_RDATA_SLV_4       (0x00100000) /*!< RDATA_SLV bit 4 */
#define ADC34_CDR_RDATA_SLV_5       (0x00200000) /*!< RDATA_SLV bit 5 */
#define ADC34_CDR_RDATA_SLV_6       (0x00400000) /*!< RDATA_SLV bit 6 */
#define ADC34_CDR_RDATA_SLV_7       (0x00800000) /*!< RDATA_SLV bit 7 */
#define ADC34_CDR_RDATA_SLV_8       (0x01000000) /*!< RDATA_SLV bit 8 */
#define ADC34_CDR_RDATA_SLV_9       (0x02000000) /*!< RDATA_SLV bit 9 */
#define ADC34_CDR_RDATA_SLV_10      (0x04000000) /*!< RDATA_SLV bit 10 */
#define ADC34_CDR_RDATA_SLV_11      (0x08000000) /*!< RDATA_SLV bit 11 */
#define ADC34_CDR_RDATA_SLV_12      (0x10000000) /*!< RDATA_SLV bit 12 */
#define ADC34_CDR_RDATA_SLV_13      (0x20000000) /*!< RDATA_SLV bit 13 */
#define ADC34_CDR_RDATA_SLV_14      (0x40000000) /*!< RDATA_SLV bit 14 */
#define ADC34_CDR_RDATA_SLV_15      (0x80000000) /*!< RDATA_SLV bit 15 */

#define COMP1_CSR_COMP1EN               (0x00000001) /*!< COMP1 enable */
#define COMP1_CSR_COMP1SW1              (0x00000002) /*!< COMP1 SW1 switch control */
#define COMP1_CSR_COMP1MODE             (0x0000000C) /*!< COMP1 power mode */
#define COMP1_CSR_COMP1MODE_0           (0x00000004) /*!< COMP1 power mode bit 0 */
#define COMP1_CSR_COMP1MODE_1           (0x00000008) /*!< COMP1 power mode bit 1 */
#define COMP1_CSR_COMP1INSEL            (0x00000070) /*!< COMP1 inverting input select */
#define COMP1_CSR_COMP1INSEL_0          (0x00000010) /*!< COMP1 inverting input select bit 0 */
#define COMP1_CSR_COMP1INSEL_1          (0x00000020) /*!< COMP1 inverting input select bit 1 */
#define COMP1_CSR_COMP1INSEL_2          (0x00000040) /*!< COMP1 inverting input select bit 2 */
#define COMP1_CSR_COMP1NONINSEL         (0x00000080) /*!< COMP1 non inverting input select */
#define COMP1_CSR_COMP1OUTSEL           (0x00003C00) /*!< COMP1 output select */
#define COMP1_CSR_COMP1OUTSEL_0         (0x00000400) /*!< COMP1 output select bit 0 */
#define COMP1_CSR_COMP1OUTSEL_1         (0x00000800) /*!< COMP1 output select bit 1 */
#define COMP1_CSR_COMP1OUTSEL_2         (0x00001000) /*!< COMP1 output select bit 2 */
#define COMP1_CSR_COMP1OUTSEL_3         (0x00002000) /*!< COMP1 output select bit 3 */
#define COMP1_CSR_COMP1POL              (0x00008000) /*!< COMP1 output polarity */
#define COMP1_CSR_COMP1HYST             (0x00030000) /*!< COMP1 hysteresis */
#define COMP1_CSR_COMP1HYST_0           (0x00010000) /*!< COMP1 hysteresis bit 0 */
#define COMP1_CSR_COMP1HYST_1           (0x00020000) /*!< COMP1 hysteresis bit 1 */
#define COMP1_CSR_COMP1BLANKING         (0x000C0000) /*!< COMP1 blanking */
#define COMP1_CSR_COMP1BLANKING_0       (0x00040000) /*!< COMP1 blanking bit 0 */
#define COMP1_CSR_COMP1BLANKING_1       (0x00080000) /*!< COMP1 blanking bit 1 */
#define COMP1_CSR_COMP1BLANKING_2       (0x00100000) /*!< COMP1 blanking bit 2 */
#define COMP1_CSR_COMP1OUT              (0x40000000) /*!< COMP1 output level */
#define COMP1_CSR_COMP1LOCK             (0x80000000) /*!< COMP1 lock */

#define COMP2_CSR_COMP2EN               (0x00000001) /*!< COMP2 enable */
#define COMP2_CSR_COMP2MODE             (0x0000000C) /*!< COMP2 power mode */
#define COMP2_CSR_COMP2MODE_0           (0x00000004) /*!< COMP2 power mode bit 0 */
#define COMP2_CSR_COMP2MODE_1           (0x00000008) /*!< COMP2 power mode bit 1 */
#define COMP2_CSR_COMP2INSEL            (0x00000070) /*!< COMP2 inverting input select */
#define COMP2_CSR_COMP2INSEL_0          (0x00000010) /*!< COMP2 inverting input select bit 0 */
#define COMP2_CSR_COMP2INSEL_1          (0x00000020) /*!< COMP2 inverting input select bit 1 */
#define COMP2_CSR_COMP2INSEL_2          (0x00000040) /*!< COMP2 inverting input select bit 2 */
#define COMP2_CSR_COMP2NONINSEL         (0x00000080) /*!< COMP2 non inverting input select */
#define COMP2_CSR_COMP2WNDWEN           (0x00000200) /*!< COMP2 window mode enable */
#define COMP2_CSR_COMP2OUTSEL           (0x00003C00) /*!< COMP2 output select */
#define COMP2_CSR_COMP2OUTSEL_0         (0x00000400) /*!< COMP2 output select bit 0 */
#define COMP2_CSR_COMP2OUTSEL_1         (0x00000800) /*!< COMP2 output select bit 1 */
#define COMP2_CSR_COMP2OUTSEL_2         (0x00001000) /*!< COMP2 output select bit 2 */
#define COMP2_CSR_COMP2OUTSEL_3         (0x00002000) /*!< COMP2 output select bit 3 */
#define COMP2_CSR_COMP2POL              (0x00008000) /*!< COMP2 output polarity */
#define COMP2_CSR_COMP2HYST             (0x00030000) /*!< COMP2 hysteresis */
#define COMP2_CSR_COMP2HYST_0           (0x00010000) /*!< COMP2 hysteresis bit 0 */
#define COMP2_CSR_COMP2HYST_1           (0x00020000) /*!< COMP2 hysteresis bit 1 */
#define COMP2_CSR_COMP2BLANKING         (0x000C0000) /*!< COMP2 blanking */
#define COMP2_CSR_COMP2BLANKING_0       (0x00040000) /*!< COMP2 blanking bit 0 */
#define COMP2_CSR_COMP2BLANKING_1       (0x00080000) /*!< COMP2 blanking bit 1 */
#define COMP2_CSR_COMP2BLANKING_2       (0x00100000) /*!< COMP2 blanking bit 2 */
#define COMP2_CSR_COMP2OUT              (0x40000000) /*!< COMP2 output level */
#define COMP2_CSR_COMP2LOCK             (0x80000000) /*!< COMP2 lock */

#define COMP3_CSR_COMP3EN               (0x00000001) /*!< COMP3 enable */
#define COMP3_CSR_COMP3MODE             (0x0000000C) /*!< COMP3 power mode */
#define COMP3_CSR_COMP3MODE_0           (0x00000004) /*!< COMP3 power mode bit 0 */
#define COMP3_CSR_COMP3MODE_1           (0x00000008) /*!< COMP3 power mode bit 1 */
#define COMP3_CSR_COMP3INSEL            (0x00000070) /*!< COMP3 inverting input select */
#define COMP3_CSR_COMP3INSEL_0          (0x00000010) /*!< COMP3 inverting input select bit 0 */
#define COMP3_CSR_COMP3INSEL_1          (0x00000020) /*!< COMP3 inverting input select bit 1 */
#define COMP3_CSR_COMP3INSEL_2          (0x00000040) /*!< COMP3 inverting input select bit 2 */
#define COMP3_CSR_COMP3NONINSEL         (0x00000080) /*!< COMP3 non inverting input select */
#define COMP3_CSR_COMP3OUTSEL           (0x00003C00) /*!< COMP3 output select */
#define COMP3_CSR_COMP3OUTSEL_0         (0x00000400) /*!< COMP3 output select bit 0 */
#define COMP3_CSR_COMP3OUTSEL_1         (0x00000800) /*!< COMP3 output select bit 1 */
#define COMP3_CSR_COMP3OUTSEL_2         (0x00001000) /*!< COMP3 output select bit 2 */
#define COMP3_CSR_COMP3OUTSEL_3         (0x00002000) /*!< COMP3 output select bit 3 */
#define COMP3_CSR_COMP3POL              (0x00008000) /*!< COMP3 output polarity */
#define COMP3_CSR_COMP3HYST             (0x00030000) /*!< COMP3 hysteresis */
#define COMP3_CSR_COMP3HYST_0           (0x00010000) /*!< COMP3 hysteresis bit 0 */
#define COMP3_CSR_COMP3HYST_1           (0x00020000) /*!< COMP3 hysteresis bit 1 */
#define COMP3_CSR_COMP3BLANKING         (0x000C0000) /*!< COMP3 blanking */
#define COMP3_CSR_COMP3BLANKING_0       (0x00040000) /*!< COMP3 blanking bit 0 */
#define COMP3_CSR_COMP3BLANKING_1       (0x00080000) /*!< COMP3 blanking bit 1 */
#define COMP3_CSR_COMP3BLANKING_2       (0x00100000) /*!< COMP3 blanking bit 2 */
#define COMP3_CSR_COMP3OUT              (0x40000000) /*!< COMP3 output level */
#define COMP3_CSR_COMP3LOCK             (0x80000000) /*!< COMP3 lock */

#define COMP4_CSR_COMP4EN               (0x00000001) /*!< COMP4 enable */
#define COMP4_CSR_COMP4MODE             (0x0000000C) /*!< COMP4 power mode */
#define COMP4_CSR_COMP4MODE_0           (0x00000004) /*!< COMP4 power mode bit 0 */
#define COMP4_CSR_COMP4MODE_1           (0x00000008) /*!< COMP4 power mode bit 1 */
#define COMP4_CSR_COMP4INSEL            (0x00000070) /*!< COMP4 inverting input select */
#define COMP4_CSR_COMP4INSEL_0          (0x00000010) /*!< COMP4 inverting input select bit 0 */
#define COMP4_CSR_COMP4INSEL_1          (0x00000020) /*!< COMP4 inverting input select bit 1 */
#define COMP4_CSR_COMP4INSEL_2          (0x00000040) /*!< COMP4 inverting input select bit 2 */
#define COMP4_CSR_COMP4NONINSEL         (0x00000080) /*!< COMP4 non inverting input select */
#define COMP4_CSR_COMP4WNDWEN           (0x00000200) /*!< COMP4 window mode enable */
#define COMP4_CSR_COMP4OUTSEL           (0x00003C00) /*!< COMP4 output select */
#define COMP4_CSR_COMP4OUTSEL_0         (0x00000400) /*!< COMP4 output select bit 0 */
#define COMP4_CSR_COMP4OUTSEL_1         (0x00000800) /*!< COMP4 output select bit 1 */
#define COMP4_CSR_COMP4OUTSEL_2         (0x00001000) /*!< COMP4 output select bit 2 */
#define COMP4_CSR_COMP4OUTSEL_3         (0x00002000) /*!< COMP4 output select bit 3 */
#define COMP4_CSR_COMP4POL              (0x00008000) /*!< COMP4 output polarity */
#define COMP4_CSR_COMP4HYST             (0x00030000) /*!< COMP4 hysteresis */
#define COMP4_CSR_COMP4HYST_0           (0x00010000) /*!< COMP4 hysteresis bit 0 */
#define COMP4_CSR_COMP4HYST_1           (0x00020000) /*!< COMP4 hysteresis bit 1 */
#define COMP4_CSR_COMP4BLANKING         (0x000C0000) /*!< COMP4 blanking */
#define COMP4_CSR_COMP4BLANKING_0       (0x00040000) /*!< COMP4 blanking bit 0 */
#define COMP4_CSR_COMP4BLANKING_1       (0x00080000) /*!< COMP4 blanking bit 1 */
#define COMP4_CSR_COMP4BLANKING_2       (0x00100000) /*!< COMP4 blanking bit 2 */
#define COMP4_CSR_COMP4OUT              (0x40000000) /*!< COMP4 output level */
#define COMP4_CSR_COMP4LOCK             (0x80000000) /*!< COMP4 lock */

#define COMP5_CSR_COMP5EN               (0x00000001) /*!< COMP5 enable */
#define COMP5_CSR_COMP5MODE             (0x0000000C) /*!< COMP5 power mode */
#define COMP5_CSR_COMP5MODE_0           (0x00000004) /*!< COMP5 power mode bit 0 */
#define COMP5_CSR_COMP5MODE_1           (0x00000008) /*!< COMP5 power mode bit 1 */
#define COMP5_CSR_COMP5INSEL            (0x00000070) /*!< COMP5 inverting input select */
#define COMP5_CSR_COMP5INSEL_0          (0x00000010) /*!< COMP5 inverting input select bit 0 */
#define COMP5_CSR_COMP5INSEL_1          (0x00000020) /*!< COMP5 inverting input select bit 1 */
#define COMP5_CSR_COMP5INSEL_2          (0x00000040) /*!< COMP5 inverting input select bit 2 */
#define COMP5_CSR_COMP5NONINSEL         (0x00000080) /*!< COMP5 non inverting input select */
#define COMP5_CSR_COMP5OUTSEL           (0x00003C00) /*!< COMP5 output select */
#define COMP5_CSR_COMP5OUTSEL_0         (0x00000400) /*!< COMP5 output select bit 0 */
#define COMP5_CSR_COMP5OUTSEL_1         (0x00000800) /*!< COMP5 output select bit 1 */
#define COMP5_CSR_COMP5OUTSEL_2         (0x00001000) /*!< COMP5 output select bit 2 */
#define COMP5_CSR_COMP5OUTSEL_3         (0x00002000) /*!< COMP5 output select bit 3 */
#define COMP5_CSR_COMP5POL              (0x00008000) /*!< COMP5 output polarity */
#define COMP5_CSR_COMP5HYST             (0x00030000) /*!< COMP5 hysteresis */
#define COMP5_CSR_COMP5HYST_0           (0x00010000) /*!< COMP5 hysteresis bit 0 */
#define COMP5_CSR_COMP5HYST_1           (0x00020000) /*!< COMP5 hysteresis bit 1 */
#define COMP5_CSR_COMP5BLANKING         (0x000C0000) /*!< COMP5 blanking */
#define COMP5_CSR_COMP5BLANKING_0       (0x00040000) /*!< COMP5 blanking bit 0 */
#define COMP5_CSR_COMP5BLANKING_1       (0x00080000) /*!< COMP5 blanking bit 1 */
#define COMP5_CSR_COMP5BLANKING_2       (0x00100000) /*!< COMP5 blanking bit 2 */
#define COMP5_CSR_COMP5OUT              (0x40000000) /*!< COMP5 output level */
#define COMP5_CSR_COMP5LOCK             (0x80000000) /*!< COMP5 lock */

#define COMP6_CSR_COMP6EN               (0x00000001) /*!< COMP6 enable */
#define COMP6_CSR_COMP6MODE             (0x0000000C) /*!< COMP6 power mode */
#define COMP6_CSR_COMP6MODE_0           (0x00000004) /*!< COMP6 power mode bit 0 */
#define COMP6_CSR_COMP6MODE_1           (0x00000008) /*!< COMP6 power mode bit 1 */
#define COMP6_CSR_COMP6INSEL            (0x00000070) /*!< COMP6 inverting input select */
#define COMP6_CSR_COMP6INSEL_0          (0x00000010) /*!< COMP6 inverting input select bit 0 */
#define COMP6_CSR_COMP6INSEL_1          (0x00000020) /*!< COMP6 inverting input select bit 1 */
#define COMP6_CSR_COMP6INSEL_2          (0x00000040) /*!< COMP6 inverting input select bit 2 */
#define COMP6_CSR_COMP6NONINSEL         (0x00000080) /*!< COMP6 non inverting input select */
#define COMP6_CSR_COMP6WNDWEN           (0x00000200) /*!< COMP6 window mode enable */
#define COMP6_CSR_COMP6OUTSEL           (0x00003C00) /*!< COMP6 output select */
#define COMP6_CSR_COMP6OUTSEL_0         (0x00000400) /*!< COMP6 output select bit 0 */
#define COMP6_CSR_COMP6OUTSEL_1         (0x00000800) /*!< COMP6 output select bit 1 */
#define COMP6_CSR_COMP6OUTSEL_2         (0x00001000) /*!< COMP6 output select bit 2 */
#define COMP6_CSR_COMP6OUTSEL_3         (0x00002000) /*!< COMP6 output select bit 3 */
#define COMP6_CSR_COMP6POL              (0x00008000) /*!< COMP6 output polarity */
#define COMP6_CSR_COMP6HYST             (0x00030000) /*!< COMP6 hysteresis */
#define COMP6_CSR_COMP6HYST_0           (0x00010000) /*!< COMP6 hysteresis bit 0 */
#define COMP6_CSR_COMP6HYST_1           (0x00020000) /*!< COMP6 hysteresis bit 1 */
#define COMP6_CSR_COMP6BLANKING         (0x000C0000) /*!< COMP6 blanking */
#define COMP6_CSR_COMP6BLANKING_0       (0x00040000) /*!< COMP6 blanking bit 0 */
#define COMP6_CSR_COMP6BLANKING_1       (0x00080000) /*!< COMP6 blanking bit 1 */
#define COMP6_CSR_COMP6BLANKING_2       (0x00100000) /*!< COMP6 blanking bit 2 */
#define COMP6_CSR_COMP6OUT              (0x40000000) /*!< COMP6 output level */
#define COMP6_CSR_COMP6LOCK             (0x80000000) /*!< COMP6 lock */

#define COMP7_CSR_COMP7EN               (0x00000001) /*!< COMP7 enable */
#define COMP7_CSR_COMP7MODE             (0x0000000C) /*!< COMP7 power mode */
#define COMP7_CSR_COMP7MODE_0           (0x00000004) /*!< COMP7 power mode bit 0 */
#define COMP7_CSR_COMP7MODE_1           (0x00000008) /*!< COMP7 power mode bit 1 */
#define COMP7_CSR_COMP7INSEL            (0x00000070) /*!< COMP7 inverting input select */
#define COMP7_CSR_COMP7INSEL_0          (0x00000010) /*!< COMP7 inverting input select bit 0 */
#define COMP7_CSR_COMP7INSEL_1          (0x00000020) /*!< COMP7 inverting input select bit 1 */
#define COMP7_CSR_COMP7INSEL_2          (0x00000040) /*!< COMP7 inverting input select bit 2 */
#define COMP7_CSR_COMP7NONINSEL         (0x00000080) /*!< COMP7 non inverting input select */
#define COMP7_CSR_COMP7OUTSEL           (0x00003C00) /*!< COMP7 output select */
#define COMP7_CSR_COMP7OUTSEL_0         (0x00000400) /*!< COMP7 output select bit 0 */
#define COMP7_CSR_COMP7OUTSEL_1         (0x00000800) /*!< COMP7 output select bit 1 */
#define COMP7_CSR_COMP7OUTSEL_2         (0x00001000) /*!< COMP7 output select bit 2 */
#define COMP7_CSR_COMP7OUTSEL_3         (0x00002000) /*!< COMP7 output select bit 3 */
#define COMP7_CSR_COMP7POL              (0x00008000) /*!< COMP7 output polarity */
#define COMP7_CSR_COMP7HYST             (0x00030000) /*!< COMP7 hysteresis */
#define COMP7_CSR_COMP7HYST_0           (0x00010000) /*!< COMP7 hysteresis bit 0 */
#define COMP7_CSR_COMP7HYST_1           (0x00020000) /*!< COMP7 hysteresis bit 1 */
#define COMP7_CSR_COMP7BLANKING         (0x000C0000) /*!< COMP7 blanking */
#define COMP7_CSR_COMP7BLANKING_0       (0x00040000) /*!< COMP7 blanking bit 0 */
#define COMP7_CSR_COMP7BLANKING_1       (0x00080000) /*!< COMP7 blanking bit 1 */
#define COMP7_CSR_COMP7BLANKING_2       (0x00100000) /*!< COMP7 blanking bit 2 */
#define COMP7_CSR_COMP7OUT              (0x40000000) /*!< COMP7 output level */
#define COMP7_CSR_COMP7LOCK             (0x80000000) /*!< COMP7 lock */

#define COMP_CSR_COMPxEN               (0x00000001) /*!< COMPx enable */
#define COMP_CSR_COMP1SW1              (0x00000002) /*!< COMP1 SW1 switch control */
#define COMP_CSR_COMPxMODE             (0x0000000C) /*!< COMPx power mode */
#define COMP_CSR_COMPxMODE_0           (0x00000004) /*!< COMPx power mode bit 0 */
#define COMP_CSR_COMPxMODE_1           (0x00000008) /*!< COMPx power mode bit 1 */
#define COMP_CSR_COMPxINSEL            (0x00000070) /*!< COMPx inverting input select */
#define COMP_CSR_COMPxINSEL_0          (0x00000010) /*!< COMPx inverting input select bit 0 */
#define COMP_CSR_COMPxINSEL_1          (0x00000020) /*!< COMPx inverting input select bit 1 */
#define COMP_CSR_COMPxINSEL_2          (0x00000040) /*!< COMPx inverting input select bit 2 */
#define COMP_CSR_COMPxNONINSEL         (0x00000080) /*!< COMPx non inverting input select */
#define COMP_CSR_COMPxWNDWEN           (0x00000200) /*!< COMPx window mode enable */
#define COMP_CSR_COMPxOUTSEL           (0x00003C00) /*!< COMPx output select */
#define COMP_CSR_COMPxOUTSEL_0         (0x00000400) /*!< COMPx output select bit 0 */
#define COMP_CSR_COMPxOUTSEL_1         (0x00000800) /*!< COMPx output select bit 1 */
#define COMP_CSR_COMPxOUTSEL_2         (0x00001000) /*!< COMPx output select bit 2 */
#define COMP_CSR_COMPxOUTSEL_3         (0x00002000) /*!< COMPx output select bit 3 */
#define COMP_CSR_COMPxPOL              (0x00008000) /*!< COMPx output polarity */
#define COMP_CSR_COMPxHYST             (0x00030000) /*!< COMPx hysteresis */
#define COMP_CSR_COMPxHYST_0           (0x00010000) /*!< COMPx hysteresis bit 0 */
#define COMP_CSR_COMPxHYST_1           (0x00020000) /*!< COMPx hysteresis bit 1 */
#define COMP_CSR_COMPxBLANKING         (0x000C0000) /*!< COMPx blanking */
#define COMP_CSR_COMPxBLANKING_0       (0x00040000) /*!< COMPx blanking bit 0 */
#define COMP_CSR_COMPxBLANKING_1       (0x00080000) /*!< COMPx blanking bit 1 */
#define COMP_CSR_COMPxBLANKING_2       (0x00100000) /*!< COMPx blanking bit 2 */
#define COMP_CSR_COMPxINSEL_3          (0x00400000) /*!< COMPx inverting input select bit 3 */
#define COMP_CSR_COMPxOUT              (0x40000000) /*!< COMPx output level */
#define COMP_CSR_COMPxLOCK             (0x80000000) /*!< COMPx lock */

#define OPAMP1_CSR_OPAMP1EN               (0x00000001) /*!< OPAMP1 enable */
#define OPAMP1_CSR_FORCEVP                (0x00000002) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP1_CSR_VPSEL                  (0x0000000C) /*!< Non inverting input selection */
#define OPAMP1_CSR_VPSEL_0                (0x00000004) /*!< Bit 0 */
#define OPAMP1_CSR_VPSEL_1                (0x00000008) /*!< Bit 1 */
#define OPAMP1_CSR_VMSEL                  (0x00000060) /*!< Inverting input selection */
#define OPAMP1_CSR_VMSEL_0                (0x00000020) /*!< Bit 0 */
#define OPAMP1_CSR_VMSEL_1                (0x00000040) /*!< Bit 1 */
#define OPAMP1_CSR_TCMEN                  (0x00000080) /*!< Timer-Controlled Mux mode enable */
#define OPAMP1_CSR_VMSSEL                 (0x00000100) /*!< Inverting input secondary selection */
#define OPAMP1_CSR_VPSSEL                 (0x00000600) /*!< Non inverting input secondary selection */
#define OPAMP1_CSR_VPSSEL_0               (0x00000200) /*!< Bit 0 */
#define OPAMP1_CSR_VPSSEL_1               (0x00000400) /*!< Bit 1 */
#define OPAMP1_CSR_CALON                  (0x00000800) /*!< Calibration mode enable */
#define OPAMP1_CSR_CALSEL                 (0x00003000) /*!< Calibration selection */
#define OPAMP1_CSR_CALSEL_0               (0x00001000) /*!< Bit 0 */
#define OPAMP1_CSR_CALSEL_1               (0x00002000) /*!< Bit 1 */
#define OPAMP1_CSR_PGGAIN                 (0x0003C000) /*!< Gain in PGA mode */
#define OPAMP1_CSR_PGGAIN_0               (0x00004000) /*!< Bit 0 */
#define OPAMP1_CSR_PGGAIN_1               (0x00008000) /*!< Bit 1 */
#define OPAMP1_CSR_PGGAIN_2               (0x00010000) /*!< Bit 2 */
#define OPAMP1_CSR_PGGAIN_3               (0x00020000) /*!< Bit 3 */
#define OPAMP1_CSR_USERTRIM               (0x00040000) /*!< User trimming enable */
#define OPAMP1_CSR_TRIMOFFSETP            (0x00F80000) /*!< Offset trimming value (PMOS) */
#define OPAMP1_CSR_TRIMOFFSETN            (0x1F000000) /*!< Offset trimming value (NMOS) */
#define OPAMP1_CSR_TSTREF                 (0x20000000) /*!< It enables the switch to put out the internal reference */
#define OPAMP1_CSR_OUTCAL                 (0x40000000) /*!< OPAMP output status flag */
#define OPAMP1_CSR_LOCK                   (0x80000000) /*!< OPAMP lock */

#define OPAMP2_CSR_OPAMP2EN               (0x00000001) /*!< OPAMP2 enable */
#define OPAMP2_CSR_FORCEVP                (0x00000002) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP2_CSR_VPSEL                  (0x0000000C) /*!< Non inverting input selection */
#define OPAMP2_CSR_VPSEL_0                (0x00000004) /*!< Bit 0 */
#define OPAMP2_CSR_VPSEL_1                (0x00000008) /*!< Bit 1 */
#define OPAMP2_CSR_VMSEL                  (0x00000060) /*!< Inverting input selection */
#define OPAMP2_CSR_VMSEL_0                (0x00000020) /*!< Bit 0 */
#define OPAMP2_CSR_VMSEL_1                (0x00000040) /*!< Bit 1 */
#define OPAMP2_CSR_TCMEN                  (0x00000080) /*!< Timer-Controlled Mux mode enable */
#define OPAMP2_CSR_VMSSEL                 (0x00000100) /*!< Inverting input secondary selection */
#define OPAMP2_CSR_VPSSEL                 (0x00000600) /*!< Non inverting input secondary selection */
#define OPAMP2_CSR_VPSSEL_0               (0x00000200) /*!< Bit 0 */
#define OPAMP2_CSR_VPSSEL_1               (0x00000400) /*!< Bit 1 */
#define OPAMP2_CSR_CALON                  (0x00000800) /*!< Calibration mode enable */
#define OPAMP2_CSR_CALSEL                 (0x00003000) /*!< Calibration selection */
#define OPAMP2_CSR_CALSEL_0               (0x00001000) /*!< Bit 0 */
#define OPAMP2_CSR_CALSEL_1               (0x00002000) /*!< Bit 1 */
#define OPAMP2_CSR_PGGAIN                 (0x0003C000) /*!< Gain in PGA mode */
#define OPAMP2_CSR_PGGAIN_0               (0x00004000) /*!< Bit 0 */
#define OPAMP2_CSR_PGGAIN_1               (0x00008000) /*!< Bit 1 */
#define OPAMP2_CSR_PGGAIN_2               (0x00010000) /*!< Bit 2 */
#define OPAMP2_CSR_PGGAIN_3               (0x00020000) /*!< Bit 3 */
#define OPAMP2_CSR_USERTRIM               (0x00040000) /*!< User trimming enable */
#define OPAMP2_CSR_TRIMOFFSETP            (0x00F80000) /*!< Offset trimming value (PMOS) */
#define OPAMP2_CSR_TRIMOFFSETN            (0x1F000000) /*!< Offset trimming value (NMOS) */
#define OPAMP2_CSR_TSTREF                 (0x20000000) /*!< It enables the switch to put out the internal reference */
#define OPAMP2_CSR_OUTCAL                 (0x40000000) /*!< OPAMP output status flag */
#define OPAMP2_CSR_LOCK                   (0x80000000) /*!< OPAMP lock */

#define OPAMP3_CSR_OPAMP3EN               (0x00000001) /*!< OPAMP3 enable */
#define OPAMP3_CSR_FORCEVP                (0x00000002) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP3_CSR_VPSEL                  (0x0000000C) /*!< Non inverting input selection */
#define OPAMP3_CSR_VPSEL_0                (0x00000004) /*!< Bit 0 */
#define OPAMP3_CSR_VPSEL_1                (0x00000008) /*!< Bit 1 */
#define OPAMP3_CSR_VMSEL                  (0x00000060) /*!< Inverting input selection */
#define OPAMP3_CSR_VMSEL_0                (0x00000020) /*!< Bit 0 */
#define OPAMP3_CSR_VMSEL_1                (0x00000040) /*!< Bit 1 */
#define OPAMP3_CSR_TCMEN                  (0x00000080) /*!< Timer-Controlled Mux mode enable */
#define OPAMP3_CSR_VMSSEL                 (0x00000100) /*!< Inverting input secondary selection */
#define OPAMP3_CSR_VPSSEL                 (0x00000600) /*!< Non inverting input secondary selection */
#define OPAMP3_CSR_VPSSEL_0               (0x00000200) /*!< Bit 0 */
#define OPAMP3_CSR_VPSSEL_1               (0x00000400) /*!< Bit 1 */
#define OPAMP3_CSR_CALON                  (0x00000800) /*!< Calibration mode enable */
#define OPAMP3_CSR_CALSEL                 (0x00003000) /*!< Calibration selection */
#define OPAMP3_CSR_CALSEL_0               (0x00001000) /*!< Bit 0 */
#define OPAMP3_CSR_CALSEL_1               (0x00002000) /*!< Bit 1 */
#define OPAMP3_CSR_PGGAIN                 (0x0003C000) /*!< Gain in PGA mode */
#define OPAMP3_CSR_PGGAIN_0               (0x00004000) /*!< Bit 0 */
#define OPAMP3_CSR_PGGAIN_1               (0x00008000) /*!< Bit 1 */
#define OPAMP3_CSR_PGGAIN_2               (0x00010000) /*!< Bit 2 */
#define OPAMP3_CSR_PGGAIN_3               (0x00020000) /*!< Bit 3 */
#define OPAMP3_CSR_USERTRIM               (0x00040000) /*!< User trimming enable */
#define OPAMP3_CSR_TRIMOFFSETP            (0x00F80000) /*!< Offset trimming value (PMOS) */
#define OPAMP3_CSR_TRIMOFFSETN            (0x1F000000) /*!< Offset trimming value (NMOS) */
#define OPAMP3_CSR_TSTREF                 (0x20000000) /*!< It enables the switch to put out the internal reference */
#define OPAMP3_CSR_OUTCAL                 (0x40000000) /*!< OPAMP output status flag */
#define OPAMP3_CSR_LOCK                   (0x80000000) /*!< OPAMP lock */

#define OPAMP4_CSR_OPAMP4EN               (0x00000001) /*!< OPAMP4 enable */
#define OPAMP4_CSR_FORCEVP                (0x00000002) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP4_CSR_VPSEL                  (0x0000000C) /*!< Non inverting input selection */
#define OPAMP4_CSR_VPSEL_0                (0x00000004) /*!< Bit 0 */
#define OPAMP4_CSR_VPSEL_1                (0x00000008) /*!< Bit 1 */
#define OPAMP4_CSR_VMSEL                  (0x00000060) /*!< Inverting input selection */
#define OPAMP4_CSR_VMSEL_0                (0x00000020) /*!< Bit 0 */
#define OPAMP4_CSR_VMSEL_1                (0x00000040) /*!< Bit 1 */
#define OPAMP4_CSR_TCMEN                  (0x00000080) /*!< Timer-Controlled Mux mode enable */
#define OPAMP4_CSR_VMSSEL                 (0x00000100) /*!< Inverting input secondary selection */
#define OPAMP4_CSR_VPSSEL                 (0x00000600) /*!< Non inverting input secondary selection */
#define OPAMP4_CSR_VPSSEL_0               (0x00000200) /*!< Bit 0 */
#define OPAMP4_CSR_VPSSEL_1               (0x00000400) /*!< Bit 1 */
#define OPAMP4_CSR_CALON                  (0x00000800) /*!< Calibration mode enable */
#define OPAMP4_CSR_CALSEL                 (0x00003000) /*!< Calibration selection */
#define OPAMP4_CSR_CALSEL_0               (0x00001000) /*!< Bit 0 */
#define OPAMP4_CSR_CALSEL_1               (0x00002000) /*!< Bit 1 */
#define OPAMP4_CSR_PGGAIN                 (0x0003C000) /*!< Gain in PGA mode */
#define OPAMP4_CSR_PGGAIN_0               (0x00004000) /*!< Bit 0 */
#define OPAMP4_CSR_PGGAIN_1               (0x00008000) /*!< Bit 1 */
#define OPAMP4_CSR_PGGAIN_2               (0x00010000) /*!< Bit 2 */
#define OPAMP4_CSR_PGGAIN_3               (0x00020000) /*!< Bit 3 */
#define OPAMP4_CSR_USERTRIM               (0x00040000) /*!< User trimming enable */
#define OPAMP4_CSR_TRIMOFFSETP            (0x00F80000) /*!< Offset trimming value (PMOS) */
#define OPAMP4_CSR_TRIMOFFSETN            (0x1F000000) /*!< Offset trimming value (NMOS) */
#define OPAMP4_CSR_TSTREF                 (0x20000000) /*!< It enables the switch to put out the internal reference */
#define OPAMP4_CSR_OUTCAL                 (0x40000000) /*!< OPAMP output status flag */
#define OPAMP4_CSR_LOCK                   (0x80000000) /*!< OPAMP lock */

#define OPAMP_CSR_OPAMPxEN               (0x00000001) /*!< OPAMP enable */
#define OPAMP_CSR_FORCEVP                (0x00000002) /*!< Connect the internal references to the plus input of the OPAMPX */
#define OPAMP_CSR_VPSEL                  (0x0000000C) /*!< Non inverting input selection */
#define OPAMP_CSR_VPSEL_0                (0x00000004) /*!< Bit 0 */
#define OPAMP_CSR_VPSEL_1                (0x00000008) /*!< Bit 1 */
#define OPAMP_CSR_VMSEL                  (0x00000060) /*!< Inverting input selection */
#define OPAMP_CSR_VMSEL_0                (0x00000020) /*!< Bit 0 */
#define OPAMP_CSR_VMSEL_1                (0x00000040) /*!< Bit 1 */
#define OPAMP_CSR_TCMEN                  (0x00000080) /*!< Timer-Controlled Mux mode enable */
#define OPAMP_CSR_VMSSEL                 (0x00000100) /*!< Inverting input secondary selection */
#define OPAMP_CSR_VPSSEL                 (0x00000600) /*!< Non inverting input secondary selection */
#define OPAMP_CSR_VPSSEL_0               (0x00000200) /*!< Bit 0 */
#define OPAMP_CSR_VPSSEL_1               (0x00000400) /*!< Bit 1 */
#define OPAMP_CSR_CALON                  (0x00000800) /*!< Calibration mode enable */
#define OPAMP_CSR_CALSEL                 (0x00003000) /*!< Calibration selection */
#define OPAMP_CSR_CALSEL_0               (0x00001000) /*!< Bit 0 */
#define OPAMP_CSR_CALSEL_1               (0x00002000) /*!< Bit 1 */
#define OPAMP_CSR_PGGAIN                 (0x0003C000) /*!< Gain in PGA mode */
#define OPAMP_CSR_PGGAIN_0               (0x00004000) /*!< Bit 0 */
#define OPAMP_CSR_PGGAIN_1               (0x00008000) /*!< Bit 1 */
#define OPAMP_CSR_PGGAIN_2               (0x00010000) /*!< Bit 2 */
#define OPAMP_CSR_PGGAIN_3               (0x00020000) /*!< Bit 3 */
#define OPAMP_CSR_USERTRIM               (0x00040000) /*!< User trimming enable */
#define OPAMP_CSR_TRIMOFFSETP            (0x00F80000) /*!< Offset trimming value (PMOS) */
#define OPAMP_CSR_TRIMOFFSETN            (0x1F000000) /*!< Offset trimming value (NMOS) */
#define OPAMP_CSR_TSTREF                 (0x20000000) /*!< It enables the switch to put out the internal reference */
#define OPAMP_CSR_OUTCAL                 (0x40000000) /*!< OPAMP output status flag */
#define OPAMP_CSR_LOCK                   (0x80000000) /*!< OPAMP lock */


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

#define  CRC_DR_DR                           (0xFFFFFFFF) /*!< Data register bits */

#define  CRC_IDR_IDR                         (0xFF)        /*!< General-purpose 8-bit data register bits */

#define  CRC_CR_RESET                        (0x00000001) /*!< RESET the CRC computation unit bit */
#define  CRC_CR_POLSIZE                      (0x00000018) /*!< Polynomial size bits */
#define  CRC_CR_POLSIZE_0                    (0x00000008) /*!< Polynomial size bit 0 */
#define  CRC_CR_POLSIZE_1                    (0x00000010) /*!< Polynomial size bit 1 */
#define  CRC_CR_REV_IN                       (0x00000060) /*!< REV_IN Reverse Input Data bits */
#define  CRC_CR_REV_IN_0                     (0x00000020) /*!< Bit 0 */
#define  CRC_CR_REV_IN_1                     (0x00000040) /*!< Bit 1 */
#define  CRC_CR_REV_OUT                      (0x00000080) /*!< REV_OUT Reverse Output Data bits */

#define  CRC_INIT_INIT                       (0xFFFFFFFF) /*!< Initial CRC value bits */

#define  CRC_POL_POL                         (0xFFFFFFFF) /*!< Coefficients of the polynomial */
#define  DAC_CR_EN1                          (0x00000001)        /*!< DAC channel1 enable */
#define  DAC_CR_BOFF1                        (0x00000002)        /*!< DAC channel1 output buffer disable */
#define  DAC_CR_TEN1                         (0x00000004)        /*!< DAC channel1 Trigger enable */

#define  DAC_CR_TSEL1                        (0x00000038)        /*!< TSEL1[2:0] (DAC channel1 Trigger selection) */
#define  DAC_CR_TSEL1_0                      (0x00000008)        /*!< Bit 0 */
#define  DAC_CR_TSEL1_1                      (0x00000010)        /*!< Bit 1 */
#define  DAC_CR_TSEL1_2                      (0x00000020)        /*!< Bit 2 */

#define  DAC_CR_WAVE1                        (0x000000C0)        /*!< WAVE1[1:0] (DAC channel1 noise/triangle wave generation enable) */
#define  DAC_CR_WAVE1_0                      (0x00000040)        /*!< Bit 0 */
#define  DAC_CR_WAVE1_1                      (0x00000080)        /*!< Bit 1 */

#define  DAC_CR_MAMP1                        (0x00000F00)        /*!< MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) */
#define  DAC_CR_MAMP1_0                      (0x00000100)        /*!< Bit 0 */
#define  DAC_CR_MAMP1_1                      (0x00000200)        /*!< Bit 1 */
#define  DAC_CR_MAMP1_2                      (0x00000400)        /*!< Bit 2 */
#define  DAC_CR_MAMP1_3                      (0x00000800)        /*!< Bit 3 */

#define  DAC_CR_DMAEN1                       (0x00001000)        /*!< DAC channel1 DMA enable */
#define  DAC_CR_DMAUDRIE1                    (0x00002000)        /*!< DAC channel1 DMA underrun IT enable */ 
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
#define  DAC_CR_DMAUDRIE2                    (0x20000000)        /*!< DAC channel2 DMA underrun IT enable */ 

#define  DAC_SWTRIGR_SWTRIG1                 (0x01)               /*!< DAC channel1 software trigger */
#define  DAC_SWTRIGR_SWTRIG2                 (0x02)               /*!< DAC channel2 software trigger */

#define  DAC_DHR12R1_DACC1DHR                (0x0FFF)            /*!< DAC channel1 12-bit Right aligned data */

#define  DAC_DHR12L1_DACC1DHR                (0xFFF0)            /*!< DAC channel1 12-bit Left aligned data */

#define  DAC_DHR8R1_DACC1DHR                 (0xFF)               /*!< DAC channel1 8-bit Right aligned data */

#define  DAC_DHR12R2_DACC2DHR                (0x0FFF)            /*!< DAC channel2 12-bit Right aligned data */

#define  DAC_DHR12L2_DACC2DHR                (0xFFF0)            /*!< DAC channel2 12-bit Left aligned data */

#define  DAC_DHR8R2_DACC2DHR                 (0xFF)               /*!< DAC channel2 8-bit Right aligned data */

#define  DAC_DHR12RD_DACC1DHR                (0x00000FFF)        /*!< DAC channel1 12-bit Right aligned data */
#define  DAC_DHR12RD_DACC2DHR                (0x0FFF0000)        /*!< DAC channel2 12-bit Right aligned data */

#define  DAC_DHR12LD_DACC1DHR                (0x0000FFF0)        /*!< DAC channel1 12-bit Left aligned data */
#define  DAC_DHR12LD_DACC2DHR                (0xFFF00000)        /*!< DAC channel2 12-bit Left aligned data */

#define  DAC_DHR8RD_DACC1DHR                 (0x00FF)            /*!< DAC channel1 8-bit Right aligned data */
#define  DAC_DHR8RD_DACC2DHR                 (0xFF00)            /*!< DAC channel2 8-bit Right aligned data */

#define  DAC_DOR1_DACC1DOR                   (0x0FFF)            /*!< DAC channel1 data output */

#define  DAC_DOR2_DACC2DOR                   (0x0FFF)            /*!< DAC channel2 data output */

#define  DAC_SR_DMAUDR1                      (0x00002000)        /*!< DAC channel1 DMA underrun flag */
#define  DAC_SR_DMAUDR2                      (0x20000000)        /*!< DAC channel2 DMA underrun flag */

#define  DBGMCU_IDCODE_DEV_ID                (0x00000FFF)
#define  DBGMCU_IDCODE_REV_ID                (0xFFFF0000)

#define  DBGMCU_CR_DBG_SLEEP                 (0x00000001)
#define  DBGMCU_CR_DBG_STOP                  (0x00000002)
#define  DBGMCU_CR_DBG_STANDBY               (0x00000004)
#define  DBGMCU_CR_TRACE_IOEN                (0x00000020)

#define  DBGMCU_CR_TRACE_MODE                (0x000000C0)
#define  DBGMCU_CR_TRACE_MODE_0              (0x00000040)/*!<Bit 0 */
#define  DBGMCU_CR_TRACE_MODE_1              (0x00000080)/*!<Bit 1 */

#define  DBGMCU_APB1_FZ_DBG_TIM2_STOP          (0x00000001)
#define  DBGMCU_APB1_FZ_DBG_TIM3_STOP          (0x00000002)
#define  DBGMCU_APB1_FZ_DBG_TIM4_STOP          (0x00000004)
#define  DBGMCU_APB1_FZ_DBG_TIM6_STOP          (0x00000010)
#define  DBGMCU_APB1_FZ_DBG_TIM7_STOP          (0x00000020)
#define  DBGMCU_APB1_FZ_DBG_RTC_STOP           (0x00000400)
#define  DBGMCU_APB1_FZ_DBG_WWDG_STOP          (0x00000800)
#define  DBGMCU_APB1_FZ_DBG_IWDG_STOP          (0x00001000)
#define  DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT (0x00200000)
#define  DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT (0x00400000)
#define  DBGMCU_APB1_FZ_DBG_CAN1_STOP          (0x02000000)
#define  DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT (0x04000000)

#define  DBGMCU_APB2_FZ_DBG_TIM1_STOP        (0x00000001)
#define  DBGMCU_APB2_FZ_DBG_TIM8_STOP        (0x00000002)
#define  DBGMCU_APB2_FZ_DBG_TIM15_STOP       (0x00000004)
#define  DBGMCU_APB2_FZ_DBG_TIM16_STOP       (0x00000008)
#define  DBGMCU_APB2_FZ_DBG_TIM17_STOP       (0x00000010)
#define  DBGMCU_APB2_FZ_DBG_TIM20_STOP       (0x00000020)

#define  DMA_ISR_GIF1                        (0x00000001)        /*!< Channel 1 Global interrupt flag */
#define  DMA_ISR_TCIF1                       (0x00000002)        /*!< Channel 1 Transfer Complete flag */
#define  DMA_ISR_HTIF1                       (0x00000004)        /*!< Channel 1 Half Transfer flag */
#define  DMA_ISR_TEIF1                       (0x00000008)        /*!< Channel 1 Transfer Error flag */
#define  DMA_ISR_GIF2                        (0x00000010)        /*!< Channel 2 Global interrupt flag */
#define  DMA_ISR_TCIF2                       (0x00000020)        /*!< Channel 2 Transfer Complete flag */
#define  DMA_ISR_HTIF2                       (0x00000040)        /*!< Channel 2 Half Transfer flag */
#define  DMA_ISR_TEIF2                       (0x00000080)        /*!< Channel 2 Transfer Error flag */
#define  DMA_ISR_GIF3                        (0x00000100)        /*!< Channel 3 Global interrupt flag */
#define  DMA_ISR_TCIF3                       (0x00000200)        /*!< Channel 3 Transfer Complete flag */
#define  DMA_ISR_HTIF3                       (0x00000400)        /*!< Channel 3 Half Transfer flag */
#define  DMA_ISR_TEIF3                       (0x00000800)        /*!< Channel 3 Transfer Error flag */
#define  DMA_ISR_GIF4                        (0x00001000)        /*!< Channel 4 Global interrupt flag */
#define  DMA_ISR_TCIF4                       (0x00002000)        /*!< Channel 4 Transfer Complete flag */
#define  DMA_ISR_HTIF4                       (0x00004000)        /*!< Channel 4 Half Transfer flag */
#define  DMA_ISR_TEIF4                       (0x00008000)        /*!< Channel 4 Transfer Error flag */
#define  DMA_ISR_GIF5                        (0x00010000)        /*!< Channel 5 Global interrupt flag */
#define  DMA_ISR_TCIF5                       (0x00020000)        /*!< Channel 5 Transfer Complete flag */
#define  DMA_ISR_HTIF5                       (0x00040000)        /*!< Channel 5 Half Transfer flag */
#define  DMA_ISR_TEIF5                       (0x00080000)        /*!< Channel 5 Transfer Error flag */
#define  DMA_ISR_GIF6                        (0x00100000)        /*!< Channel 6 Global interrupt flag */
#define  DMA_ISR_TCIF6                       (0x00200000)        /*!< Channel 6 Transfer Complete flag */
#define  DMA_ISR_HTIF6                       (0x00400000)        /*!< Channel 6 Half Transfer flag */
#define  DMA_ISR_TEIF6                       (0x00800000)        /*!< Channel 6 Transfer Error flag */
#define  DMA_ISR_GIF7                        (0x01000000)        /*!< Channel 7 Global interrupt flag */
#define  DMA_ISR_TCIF7                       (0x02000000)        /*!< Channel 7 Transfer Complete flag */
#define  DMA_ISR_HTIF7                       (0x04000000)        /*!< Channel 7 Half Transfer flag */
#define  DMA_ISR_TEIF7                       (0x08000000)        /*!< Channel 7 Transfer Error flag */

#define  DMA_IFCR_CGIF1                      (0x00000001)        /*!< Channel 1 Global interrupt clear */
#define  DMA_IFCR_CTCIF1                     (0x00000002)        /*!< Channel 1 Transfer Complete clear */
#define  DMA_IFCR_CHTIF1                     (0x00000004)        /*!< Channel 1 Half Transfer clear */
#define  DMA_IFCR_CTEIF1                     (0x00000008)        /*!< Channel 1 Transfer Error clear */
#define  DMA_IFCR_CGIF2                      (0x00000010)        /*!< Channel 2 Global interrupt clear */
#define  DMA_IFCR_CTCIF2                     (0x00000020)        /*!< Channel 2 Transfer Complete clear */
#define  DMA_IFCR_CHTIF2                     (0x00000040)        /*!< Channel 2 Half Transfer clear */
#define  DMA_IFCR_CTEIF2                     (0x00000080)        /*!< Channel 2 Transfer Error clear */
#define  DMA_IFCR_CGIF3                      (0x00000100)        /*!< Channel 3 Global interrupt clear */
#define  DMA_IFCR_CTCIF3                     (0x00000200)        /*!< Channel 3 Transfer Complete clear */
#define  DMA_IFCR_CHTIF3                     (0x00000400)        /*!< Channel 3 Half Transfer clear */
#define  DMA_IFCR_CTEIF3                     (0x00000800)        /*!< Channel 3 Transfer Error clear */
#define  DMA_IFCR_CGIF4                      (0x00001000)        /*!< Channel 4 Global interrupt clear */
#define  DMA_IFCR_CTCIF4                     (0x00002000)        /*!< Channel 4 Transfer Complete clear */
#define  DMA_IFCR_CHTIF4                     (0x00004000)        /*!< Channel 4 Half Transfer clear */
#define  DMA_IFCR_CTEIF4                     (0x00008000)        /*!< Channel 4 Transfer Error clear */
#define  DMA_IFCR_CGIF5                      (0x00010000)        /*!< Channel 5 Global interrupt clear */
#define  DMA_IFCR_CTCIF5                     (0x00020000)        /*!< Channel 5 Transfer Complete clear */
#define  DMA_IFCR_CHTIF5                     (0x00040000)        /*!< Channel 5 Half Transfer clear */
#define  DMA_IFCR_CTEIF5                     (0x00080000)        /*!< Channel 5 Transfer Error clear */
#define  DMA_IFCR_CGIF6                      (0x00100000)        /*!< Channel 6 Global interrupt clear */
#define  DMA_IFCR_CTCIF6                     (0x00200000)        /*!< Channel 6 Transfer Complete clear */
#define  DMA_IFCR_CHTIF6                     (0x00400000)        /*!< Channel 6 Half Transfer clear */
#define  DMA_IFCR_CTEIF6                     (0x00800000)        /*!< Channel 6 Transfer Error clear */
#define  DMA_IFCR_CGIF7                      (0x01000000)        /*!< Channel 7 Global interrupt clear */
#define  DMA_IFCR_CTCIF7                     (0x02000000)        /*!< Channel 7 Transfer Complete clear */
#define  DMA_IFCR_CHTIF7                     (0x04000000)        /*!< Channel 7 Half Transfer clear */
#define  DMA_IFCR_CTEIF7                     (0x08000000)        /*!< Channel 7 Transfer Error clear */

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

#define  EXTI_IMR_MR0                        (0x00000001)        /*!< Interrupt Mask on line 0 */
#define  EXTI_IMR_MR1                        (0x00000002)        /*!< Interrupt Mask on line 1 */
#define  EXTI_IMR_MR2                        (0x00000004)        /*!< Interrupt Mask on line 2 */
#define  EXTI_IMR_MR3                        (0x00000008)        /*!< Interrupt Mask on line 3 */
#define  EXTI_IMR_MR4                        (0x00000010)        /*!< Interrupt Mask on line 4 */
#define  EXTI_IMR_MR5                        (0x00000020)        /*!< Interrupt Mask on line 5 */
#define  EXTI_IMR_MR6                        (0x00000040)        /*!< Interrupt Mask on line 6 */
#define  EXTI_IMR_MR7                        (0x00000080)        /*!< Interrupt Mask on line 7 */
#define  EXTI_IMR_MR8                        (0x00000100)        /*!< Interrupt Mask on line 8 */
#define  EXTI_IMR_MR9                        (0x00000200)        /*!< Interrupt Mask on line 9 */
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
#define  EXTI_EMR_MR0                        (0x00000001)        /*!< Event Mask on line 0 */
#define  EXTI_EMR_MR1                        (0x00000002)        /*!< Event Mask on line 1 */
#define  EXTI_EMR_MR2                        (0x00000004)        /*!< Event Mask on line 2 */
#define  EXTI_EMR_MR3                        (0x00000008)        /*!< Event Mask on line 3 */
#define  EXTI_EMR_MR4                        (0x00000010)        /*!< Event Mask on line 4 */
#define  EXTI_EMR_MR5                        (0x00000020)        /*!< Event Mask on line 5 */
#define  EXTI_EMR_MR6                        (0x00000040)        /*!< Event Mask on line 6 */
#define  EXTI_EMR_MR7                        (0x00000080)        /*!< Event Mask on line 7 */
#define  EXTI_EMR_MR8                        (0x00000100)        /*!< Event Mask on line 8 */
#define  EXTI_EMR_MR9                        (0x00000200)        /*!< Event Mask on line 9 */
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
#define  EXTI_RTSR_TR18                      (0x00040000)        /*!< Rising trigger event configuration bit of line 18 */
#define  EXTI_RTSR_TR19                      (0x00080000)        /*!< Rising trigger event configuration bit of line 19 */
#define  EXTI_RTSR_TR20                      (0x00100000)        /*!< Rising trigger event configuration bit of line 20 */
#define  EXTI_RTSR_TR21                      (0x00200000)        /*!< Rising trigger event configuration bit of line 21 */
#define  EXTI_RTSR_TR22                      (0x00400000)        /*!< Rising trigger event configuration bit of line 22 */
#define  EXTI_RTSR_TR23                      (0x00800000)        /*!< Rising trigger event configuration bit of line 23 */
#define  EXTI_RTSR_TR24                      (0x01000000)        /*!< Rising trigger event configuration bit of line 24 */
#define  EXTI_RTSR_TR25                      (0x02000000)        /*!< Rising trigger event configuration bit of line 25 */
#define  EXTI_RTSR_TR26                      (0x04000000)        /*!< Rising trigger event configuration bit of line 26 */
#define  EXTI_RTSR_TR27                      (0x08000000)        /*!< Rising trigger event configuration bit of line 27 */
#define  EXTI_RTSR_TR28                      (0x10000000)        /*!< Rising trigger event configuration bit of line 28 */
#define  EXTI_RTSR_TR29                      (0x20000000)        /*!< Rising trigger event configuration bit of line 29 */
#define  EXTI_RTSR_TR30                      (0x40000000)        /*!< Rising trigger event configuration bit of line 30 */
#define  EXTI_RTSR_TR31                      (0x80000000)        /*!< Rising trigger event configuration bit of line 31 */
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
#define  EXTI_FTSR_TR18                      (0x00040000)        /*!< Falling trigger event configuration bit of line 18 */
#define  EXTI_FTSR_TR19                      (0x00080000)        /*!< Falling trigger event configuration bit of line 19 */
#define  EXTI_FTSR_TR20                      (0x00100000)        /*!< Falling trigger event configuration bit of line 20 */
#define  EXTI_FTSR_TR21                      (0x00200000)        /*!< Falling trigger event configuration bit of line 21 */
#define  EXTI_FTSR_TR22                      (0x00400000)        /*!< Falling trigger event configuration bit of line 22 */
#define  EXTI_FTSR_TR23                      (0x00800000)        /*!< Falling trigger event configuration bit of line 23 */
#define  EXTI_FTSR_TR24                      (0x01000000)        /*!< Falling trigger event configuration bit of line 24 */
#define  EXTI_FTSR_TR25                      (0x02000000)        /*!< Falling trigger event configuration bit of line 25 */
#define  EXTI_FTSR_TR26                      (0x04000000)        /*!< Falling trigger event configuration bit of line 26 */
#define  EXTI_FTSR_TR27                      (0x08000000)        /*!< Falling trigger event configuration bit of line 27 */
#define  EXTI_FTSR_TR28                      (0x10000000)        /*!< Falling trigger event configuration bit of line 28 */
#define  EXTI_FTSR_TR29                      (0x20000000)        /*!< Falling trigger event configuration bit of line 29 */
#define  EXTI_FTSR_TR30                      (0x40000000)        /*!< Falling trigger event configuration bit of line 30 */
#define  EXTI_FTSR_TR31                      (0x80000000)        /*!< Falling trigger event configuration bit of line 31 */
#define  EXTI_SWIER_SWIER0                   (0x00000001)        /*!< Software Interrupt on line 0 */
#define  EXTI_SWIER_SWIER1                   (0x00000002)        /*!< Software Interrupt on line 1 */
#define  EXTI_SWIER_SWIER2                   (0x00000004)        /*!< Software Interrupt on line 2 */
#define  EXTI_SWIER_SWIER3                   (0x00000008)        /*!< Software Interrupt on line 3 */
#define  EXTI_SWIER_SWIER4                   (0x00000010)        /*!< Software Interrupt on line 4 */
#define  EXTI_SWIER_SWIER5                   (0x00000020)        /*!< Software Interrupt on line 5 */
#define  EXTI_SWIER_SWIER6                   (0x00000040)        /*!< Software Interrupt on line 6 */
#define  EXTI_SWIER_SWIER7                   (0x00000080)        /*!< Software Interrupt on line 7 */
#define  EXTI_SWIER_SWIER8                   (0x00000100)        /*!< Software Interrupt on line 8 */
#define  EXTI_SWIER_SWIER9                   (0x00000200)        /*!< Software Interrupt on line 9 */
#define  EXTI_SWIER_SWIER10                  (0x00000400)        /*!< Software Interrupt on line 10 */
#define  EXTI_SWIER_SWIER11                  (0x00000800)        /*!< Software Interrupt on line 11 */
#define  EXTI_SWIER_SWIER12                  (0x00001000)        /*!< Software Interrupt on line 12 */
#define  EXTI_SWIER_SWIER13                  (0x00002000)        /*!< Software Interrupt on line 13 */
#define  EXTI_SWIER_SWIER14                  (0x00004000)        /*!< Software Interrupt on line 14 */
#define  EXTI_SWIER_SWIER15                  (0x00008000)        /*!< Software Interrupt on line 15 */
#define  EXTI_SWIER_SWIER16                  (0x00010000)        /*!< Software Interrupt on line 16 */
#define  EXTI_SWIER_SWIER17                  (0x00020000)        /*!< Software Interrupt on line 17 */
#define  EXTI_SWIER_SWIER18                  (0x00040000)        /*!< Software Interrupt on line 18 */
#define  EXTI_SWIER_SWIER19                  (0x00080000)        /*!< Software Interrupt on line 19 */
#define  EXTI_SWIER_SWIER20                  (0x00100000)        /*!< Software Interrupt on line 20 */
#define  EXTI_SWIER_SWIER21                  (0x00200000)        /*!< Software Interrupt on line 21 */
#define  EXTI_SWIER_SWIER22                  (0x00400000)        /*!< Software Interrupt on line 22 */
#define  EXTI_SWIER_SWIER23                  (0x00800000)        /*!< Software Interrupt on line 23 */
#define  EXTI_SWIER_SWIER24                  (0x01000000)        /*!< Software Interrupt on line 24 */
#define  EXTI_SWIER_SWIER25                  (0x02000000)        /*!< Software Interrupt on line 25 */
#define  EXTI_SWIER_SWIER26                  (0x04000000)        /*!< Software Interrupt on line 26 */
#define  EXTI_SWIER_SWIER27                  (0x08000000)        /*!< Software Interrupt on line 27 */
#define  EXTI_SWIER_SWIER28                  (0x10000000)        /*!< Software Interrupt on line 28 */
#define  EXTI_SWIER_SWIER29                  (0x20000000)        /*!< Software Interrupt on line 29 */
#define  EXTI_SWIER_SWIER30                  (0x40000000)        /*!< Software Interrupt on line 30 */
#define  EXTI_SWIER_SWIER31                  (0x80000000)        /*!< Software Interrupt on line 31 */
#define  EXTI_PR_PR0                         (0x00000001)        /*!< Pending bit for line 0 */
#define  EXTI_PR_PR1                         (0x00000002)        /*!< Pending bit for line 1 */
#define  EXTI_PR_PR2                         (0x00000004)        /*!< Pending bit for line 2 */
#define  EXTI_PR_PR3                         (0x00000008)        /*!< Pending bit for line 3 */
#define  EXTI_PR_PR4                         (0x00000010)        /*!< Pending bit for line 4 */
#define  EXTI_PR_PR5                         (0x00000020)        /*!< Pending bit for line 5 */
#define  EXTI_PR_PR6                         (0x00000040)        /*!< Pending bit for line 6 */
#define  EXTI_PR_PR7                         (0x00000080)        /*!< Pending bit for line 7 */
#define  EXTI_PR_PR8                         (0x00000100)        /*!< Pending bit for line 8 */
#define  EXTI_PR_PR9                         (0x00000200)        /*!< Pending bit for line 9 */
#define  EXTI_PR_PR10                        (0x00000400)        /*!< Pending bit for line 10 */
#define  EXTI_PR_PR11                        (0x00000800)        /*!< Pending bit for line 11 */
#define  EXTI_PR_PR12                        (0x00001000)        /*!< Pending bit for line 12 */
#define  EXTI_PR_PR13                        (0x00002000)        /*!< Pending bit for line 13 */
#define  EXTI_PR_PR14                        (0x00004000)        /*!< Pending bit for line 14 */
#define  EXTI_PR_PR15                        (0x00008000)        /*!< Pending bit for line 15 */
#define  EXTI_PR_PR16                        (0x00010000)        /*!< Pending bit for line 16 */
#define  EXTI_PR_PR17                        (0x00020000)        /*!< Pending bit for line 17 */
#define  EXTI_PR_PR18                        (0x00040000)        /*!< Pending bit for line 18 */
#define  EXTI_PR_PR19                        (0x00080000)        /*!< Pending bit for line 19 */
#define  EXTI_PR_PR20                        (0x00100000)        /*!< Pending bit for line 20 */
#define  EXTI_PR_PR21                        (0x00200000)        /*!< Pending bit for line 21 */
#define  EXTI_PR_PR22                        (0x00400000)        /*!< Pending bit for line 22 */
#define  EXTI_PR_PR23                        (0x00800000)        /*!< Pending bit for line 23 */
#define  EXTI_PR_PR24                        (0x01000000)        /*!< Pending bit for line 24 */
#define  EXTI_PR_PR25                        (0x02000000)        /*!< Pending bit for line 25 */
#define  EXTI_PR_PR26                        (0x04000000)        /*!< Pending bit for line 26 */
#define  EXTI_PR_PR27                        (0x08000000)        /*!< Pending bit for line 27 */
#define  EXTI_PR_PR28                        (0x10000000)        /*!< Pending bit for line 28 */
#define  EXTI_PR_PR29                        (0x20000000)        /*!< Pending bit for line 29 */
#define  EXTI_PR_PR30                        (0x40000000)        /*!< Pending bit for line 30 */
#define  EXTI_PR_PR31                        (0x80000000)        /*!< Pending bit for line 31 */
#define  EXTI_IMR2_MR32                      (0x00000001)        /*!< Interrupt Mask on line 32 */
#define  EXTI_IMR2_MR33                      (0x00000002)        /*!< Interrupt Mask on line 33 */
#define  EXTI_IMR2_MR34                      (0x00000004)        /*!< Interrupt Mask on line 34 */
#define  EXTI_IMR2_MR35                      (0x00000008)        /*!< Interrupt Mask on line 35 */
#define  EXTI_EMR2_MR32                      (0x00000001)        /*!< Event Mask on line 32 */
#define  EXTI_EMR2_MR33                      (0x00000002)        /*!< Event Mask on line 33 */
#define  EXTI_EMR2_MR34                      (0x00000004)        /*!< Event Mask on line 34 */
#define  EXTI_EMR2_MR35                      (0x00000008)        /*!< Event Mask on line 35 */
#define  EXTI_RTSR2_TR32                     (0x00000001)        /*!< Rising trigger event configuration bit of line 32 */
#define  EXTI_RTSR2_TR33                     (0x00000002)        /*!< Rising trigger event configuration bit of line 33 */
#define  EXTI_FTSR2_TR32                     (0x00000001)        /*!< Falling trigger event configuration bit of line 32 */
#define  EXTI_FTSR2_TR33                     (0x00000002)        /*!< Falling trigger event configuration bit of line 32 */
#define  EXTI_SWIER2_SWIER32                 (0x00000001)        /*!< Software Interrupt on line 32 */
#define  EXTI_SWIER2_SWIER33                 (0x00000002)        /*!< Software Interrupt on line 32 */
#define  EXTI_PR2_PR32                       (0x00000001)        /*!< Pending bit for line 32 */
#define  EXTI_PR2_PR33                       (0x00000002)        /*!< Pending bit for line 32 */

#define  FLASH_ACR_LATENCY                   (0x03)               /*!< LATENCY[2:0] bits (Latency) */
#define  FLASH_ACR_LATENCY_0                 (0x01)               /*!< Bit 0 */
#define  FLASH_ACR_LATENCY_1                 (0x02)               /*!< Bit 1 */

#define  FLASH_ACR_HLFCYA                    (0x08)               /*!< Flash Half Cycle Access Enable */
#define  FLASH_ACR_PRFTBE                    (0x10)               /*!< Prefetch Buffer Enable */
#define  FLASH_ACR_PRFTBS                    (0x20)  

#define  FLASH_KEYR_FKEYR                    (0xFFFFFFFF)        /*!< FPEC Key */

#define  RDP_KEY                             (0x00A5)            /*!< RDP Key */
#define  FLASH_KEY1                          (0x45670123)        /*!< FPEC Key1 */
#define  FLASH_KEY2                          (0xCDEF89AB)        /*!< FPEC Key2 */

#define  FLASH_OPTKEYR_OPTKEYR               (0xFFFFFFFF)        /*!< Option Byte Key */

#define  FLASH_OPTKEY1                       FLASH_KEY1                    /*!< Option Byte Key1 */
#define  FLASH_OPTKEY2                       FLASH_KEY2                    /*!< Option Byte Key2 */

#define  FLASH_SR_BSY                        (0x00000001)        /*!< Busy */
#define  FLASH_SR_PGERR                      (0x00000004)        /*!< Programming Error */
#define  FLASH_SR_WRPERR                     (0x00000010)        /*!< Write Protection Error */
#define  FLASH_SR_EOP                        (0x00000020)        /*!< End of operation */

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
#define  FLASH_CR_OBL_LAUNCH                 (0x00002000)        /*!< OptionBytes Loader Launch */

#define  FLASH_AR_FAR                        (0xFFFFFFFF)        /*!< Flash Address */

#define  FLASH_OBR_OPTERR                    (0x00000001)        /*!< Option Byte Error */
#define  FLASH_OBR_RDPRT1                    (0x00000002)        /*!< Read protection Level 1 */
#define  FLASH_OBR_RDPRT2                    (0x00000004)        /*!< Read protection Level 2 */

#ifdef STM32F303xE
#define  FLASH_OBR_USER                      (0x00007700)        /*!< User Option Bytes */
#else
#define  FLASH_OBR_USER                      (0x00003700)        /*!< User Option Bytes */
#endif /* STM32F303xE */

#define  FLASH_OBR_IWDG_SW                   (0x00000100)        /*!< IWDG SW */
#define  FLASH_OBR_nRST_STOP                 (0x00000200)        /*!< nRST_STOP */
#define  FLASH_OBR_nRST_STDBY                (0x00000400)        /*!< nRST_STDBY */
#define  FLASH_OBR_nBOOT1                    (0x00001000)        /*!< nBOOT1 */
#define  FLASH_OBR_VDDA_MONITOR              (0x00002000)        /*!< VDDA_MONITOR */
#define  FLASH_OBR_SRAM_PE                   (0x00004000)        /*!< SRAM_PE */


#define  FLASH_WRPR_WRP                        (0xFFFFFFFF)      /*!< Write Protect */


#define  OB_RDP_RDP                          (0x000000FF)        /*!< Read protection option byte */
#define  OB_RDP_nRDP                         (0x0000FF00)        /*!< Read protection complemented option byte */

#define  OB_USER_USER                        (0x00FF0000)        /*!< User option byte */
#define  OB_USER_nUSER                       (0xFF000000)        /*!< User complemented option byte */

#define  OB_WRP0_WRP0                        (0x000000FF)        /*!< Flash memory write protection option bytes */
#define  OB_WRP0_nWRP0                       (0x0000FF00)        /*!< Flash memory write protection complemented option bytes */

#define  OB_WRP1_WRP1                        (0x00FF0000)        /*!< Flash memory write protection option bytes */
#define  OB_WRP1_nWRP1                       (0xFF000000)        /*!< Flash memory write protection complemented option bytes */

#define  OB_WRP2_WRP2                        (0x000000FF)        /*!< Flash memory write protection option bytes */
#define  OB_WRP2_nWRP2                       (0x0000FF00)        /*!< Flash memory write protection complemented option bytes */

#define  OB_WRP3_WRP3                        (0x00FF0000)        /*!< Flash memory write protection option bytes */
#define  OB_WRP3_nWRP3                       (0xFF000000)        /*!< Flash memory write protection complemented option bytes */

#define  FMC_BCR1_MBKEN                     (0x00000001)        /*!<Memory bank enable bit                 */
#define  FMC_BCR1_MUXEN                     (0x00000002)        /*!<Address/data multiplexing enable bit   */

#define  FMC_BCR1_MTYP                      (0x0000000C)        /*!<MTYP[1:0] bits (Memory type)           */
#define  FMC_BCR1_MTYP_0                    (0x00000004)        /*!<Bit 0 */
#define  FMC_BCR1_MTYP_1                    (0x00000008)        /*!<Bit 1 */

#define  FMC_BCR1_MWID                      (0x00000030)        /*!<MWID[1:0] bits (Memory data bus width) */
#define  FMC_BCR1_MWID_0                    (0x00000010)        /*!<Bit 0 */
#define  FMC_BCR1_MWID_1                    (0x00000020)        /*!<Bit 1 */

#define  FMC_BCR1_FACCEN                    (0x00000040)        /*!<Flash access enable        */
#define  FMC_BCR1_BURSTEN                   (0x00000100)        /*!<Burst enable bit           */
#define  FMC_BCR1_WAITPOL                   (0x00000200)        /*!<Wait signal polarity bit   */
#define  FMC_BCR1_WRAPMOD                   (0x00000400)        /*!<Wrapped burst mode support */
#define  FMC_BCR1_WAITCFG                   (0x00000800)        /*!<Wait timing configuration  */
#define  FMC_BCR1_WREN                      (0x00001000)        /*!<Write enable bit           */
#define  FMC_BCR1_WAITEN                    (0x00002000)        /*!<Wait enable bit            */
#define  FMC_BCR1_EXTMOD                    (0x00004000)        /*!<Extended mode enable       */
#define  FMC_BCR1_ASYNCWAIT                 (0x00008000)        /*!<Asynchronous wait          */
#define  FMC_BCR1_CBURSTRW                  (0x00080000)        /*!<Write burst enable         */
#define  FMC_BCR1_CCLKEN                    (0x00100000)        /*!<Conitnuous clock enable     */

#define  FMC_BCR2_MBKEN                     (0x00000001)        /*!<Memory bank enable bit                 */
#define  FMC_BCR2_MUXEN                     (0x00000002)        /*!<Address/data multiplexing enable bit   */

#define  FMC_BCR2_MTYP                      (0x0000000C)        /*!<MTYP[1:0] bits (Memory type)           */
#define  FMC_BCR2_MTYP_0                    (0x00000004)        /*!<Bit 0 */
#define  FMC_BCR2_MTYP_1                    (0x00000008)        /*!<Bit 1 */

#define  FMC_BCR2_MWID                      (0x00000030)        /*!<MWID[1:0] bits (Memory data bus width) */
#define  FMC_BCR2_MWID_0                    (0x00000010)        /*!<Bit 0 */
#define  FMC_BCR2_MWID_1                    (0x00000020)        /*!<Bit 1 */

#define  FMC_BCR2_FACCEN                    (0x00000040)        /*!<Flash access enable        */
#define  FMC_BCR2_BURSTEN                   (0x00000100)        /*!<Burst enable bit           */
#define  FMC_BCR2_WAITPOL                   (0x00000200)        /*!<Wait signal polarity bit   */
#define  FMC_BCR2_WRAPMOD                   (0x00000400)        /*!<Wrapped burst mode support */
#define  FMC_BCR2_WAITCFG                   (0x00000800)        /*!<Wait timing configuration  */
#define  FMC_BCR2_WREN                      (0x00001000)        /*!<Write enable bit           */
#define  FMC_BCR2_WAITEN                    (0x00002000)        /*!<Wait enable bit            */
#define  FMC_BCR2_EXTMOD                    (0x00004000)        /*!<Extended mode enable       */
#define  FMC_BCR2_ASYNCWAIT                 (0x00008000)        /*!<Asynchronous wait          */
#define  FMC_BCR2_CBURSTRW                  (0x00080000)        /*!<Write burst enable         */

#define  FMC_BCR3_MBKEN                     (0x00000001)        /*!<Memory bank enable bit                 */
#define  FMC_BCR3_MUXEN                     (0x00000002)        /*!<Address/data multiplexing enable bit   */

#define  FMC_BCR3_MTYP                      (0x0000000C)        /*!<MTYP[1:0] bits (Memory type)           */
#define  FMC_BCR3_MTYP_0                    (0x00000004)        /*!<Bit 0 */
#define  FMC_BCR3_MTYP_1                    (0x00000008)        /*!<Bit 1 */

#define  FMC_BCR3_MWID                      (0x00000030)        /*!<MWID[1:0] bits (Memory data bus width) */
#define  FMC_BCR3_MWID_0                    (0x00000010)        /*!<Bit 0 */
#define  FMC_BCR3_MWID_1                    (0x00000020)        /*!<Bit 1 */

#define  FMC_BCR3_FACCEN                    (0x00000040)        /*!<Flash access enable        */
#define  FMC_BCR3_BURSTEN                   (0x00000100)        /*!<Burst enable bit           */
#define  FMC_BCR3_WAITPOL                   (0x00000200)        /*!<Wait signal polarity bit   */
#define  FMC_BCR3_WRAPMOD                   (0x00000400)        /*!<Wrapped burst mode support */
#define  FMC_BCR3_WAITCFG                   (0x00000800)        /*!<Wait timing configuration  */
#define  FMC_BCR3_WREN                      (0x00001000)        /*!<Write enable bit           */
#define  FMC_BCR3_WAITEN                    (0x00002000)        /*!<Wait enable bit            */
#define  FMC_BCR3_EXTMOD                    (0x00004000)        /*!<Extended mode enable       */
#define  FMC_BCR3_ASYNCWAIT                 (0x00008000)        /*!<Asynchronous wait          */
#define  FMC_BCR3_CBURSTRW                  (0x00080000)        /*!<Write burst enable         */

#define  FMC_BCR4_MBKEN                     (0x00000001)        /*!<Memory bank enable bit                 */
#define  FMC_BCR4_MUXEN                     (0x00000002)        /*!<Address/data multiplexing enable bit   */

#define  FMC_BCR4_MTYP                      (0x0000000C)        /*!<MTYP[1:0] bits (Memory type)           */
#define  FMC_BCR4_MTYP_0                    (0x00000004)        /*!<Bit 0 */
#define  FMC_BCR4_MTYP_1                    (0x00000008)        /*!<Bit 1 */

#define  FMC_BCR4_MWID                      (0x00000030)        /*!<MWID[1:0] bits (Memory data bus width) */
#define  FMC_BCR4_MWID_0                    (0x00000010)        /*!<Bit 0 */
#define  FMC_BCR4_MWID_1                    (0x00000020)        /*!<Bit 1 */

#define  FMC_BCR4_FACCEN                    (0x00000040)        /*!<Flash access enable        */
#define  FMC_BCR4_BURSTEN                   (0x00000100)        /*!<Burst enable bit           */
#define  FMC_BCR4_WAITPOL                   (0x00000200)        /*!<Wait signal polarity bit   */
#define  FMC_BCR4_WRAPMOD                   (0x00000400)        /*!<Wrapped burst mode support */
#define  FMC_BCR4_WAITCFG                   (0x00000800)        /*!<Wait timing configuration  */
#define  FMC_BCR4_WREN                      (0x00001000)        /*!<Write enable bit           */
#define  FMC_BCR4_WAITEN                    (0x00002000)        /*!<Wait enable bit            */
#define  FMC_BCR4_EXTMOD                    (0x00004000)        /*!<Extended mode enable       */
#define  FMC_BCR4_ASYNCWAIT                 (0x00008000)        /*!<Asynchronous wait          */
#define  FMC_BCR4_CBURSTRW                  (0x00080000)        /*!<Write burst enable         */

#define  FMC_BTR1_ADDSET                    (0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BTR1_ADDSET_0                  (0x00000001)        /*!<Bit 0 */
#define  FMC_BTR1_ADDSET_1                  (0x00000002)        /*!<Bit 1 */
#define  FMC_BTR1_ADDSET_2                  (0x00000004)        /*!<Bit 2 */
#define  FMC_BTR1_ADDSET_3                  (0x00000008)        /*!<Bit 3 */

#define  FMC_BTR1_ADDHLD                    (0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration)  */
#define  FMC_BTR1_ADDHLD_0                  (0x00000010)        /*!<Bit 0 */
#define  FMC_BTR1_ADDHLD_1                  (0x00000020)        /*!<Bit 1 */
#define  FMC_BTR1_ADDHLD_2                  (0x00000040)        /*!<Bit 2 */
#define  FMC_BTR1_ADDHLD_3                  (0x00000080)        /*!<Bit 3 */

#define  FMC_BTR1_DATAST                    (0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BTR1_DATAST_0                  (0x00000100)        /*!<Bit 0 */
#define  FMC_BTR1_DATAST_1                  (0x00000200)        /*!<Bit 1 */
#define  FMC_BTR1_DATAST_2                  (0x00000400)        /*!<Bit 2 */
#define  FMC_BTR1_DATAST_3                  (0x00000800)        /*!<Bit 3 */
#define  FMC_BTR1_DATAST_4                  (0x00001000)        /*!<Bit 4 */
#define  FMC_BTR1_DATAST_5                  (0x00002000)        /*!<Bit 5 */
#define  FMC_BTR1_DATAST_6                  (0x00004000)        /*!<Bit 6 */
#define  FMC_BTR1_DATAST_7                  (0x00008000)        /*!<Bit 7 */

#define  FMC_BTR1_BUSTURN                   (0x000F0000)        /*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FMC_BTR1_BUSTURN_0                 (0x00010000)        /*!<Bit 0 */
#define  FMC_BTR1_BUSTURN_1                 (0x00020000)        /*!<Bit 1 */
#define  FMC_BTR1_BUSTURN_2                 (0x00040000)        /*!<Bit 2 */
#define  FMC_BTR1_BUSTURN_3                 (0x00080000)        /*!<Bit 3 */

#define  FMC_BTR1_CLKDIV                    (0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BTR1_CLKDIV_0                  (0x00100000)        /*!<Bit 0 */
#define  FMC_BTR1_CLKDIV_1                  (0x00200000)        /*!<Bit 1 */
#define  FMC_BTR1_CLKDIV_2                  (0x00400000)        /*!<Bit 2 */
#define  FMC_BTR1_CLKDIV_3                  (0x00800000)        /*!<Bit 3 */

#define  FMC_BTR1_DATLAT                    (0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BTR1_DATLAT_0                  (0x01000000)        /*!<Bit 0 */
#define  FMC_BTR1_DATLAT_1                  (0x02000000)        /*!<Bit 1 */
#define  FMC_BTR1_DATLAT_2                  (0x04000000)        /*!<Bit 2 */
#define  FMC_BTR1_DATLAT_3                  (0x08000000)        /*!<Bit 3 */

#define  FMC_BTR1_ACCMOD                    (0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BTR1_ACCMOD_0                  (0x10000000)        /*!<Bit 0 */
#define  FMC_BTR1_ACCMOD_1                  (0x20000000)        /*!<Bit 1 */

#define  FMC_BTR2_ADDSET                    (0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BTR2_ADDSET_0                  (0x00000001)        /*!<Bit 0 */
#define  FMC_BTR2_ADDSET_1                  (0x00000002)        /*!<Bit 1 */
#define  FMC_BTR2_ADDSET_2                  (0x00000004)        /*!<Bit 2 */
#define  FMC_BTR2_ADDSET_3                  (0x00000008)        /*!<Bit 3 */

#define  FMC_BTR2_ADDHLD                    (0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BTR2_ADDHLD_0                  (0x00000010)        /*!<Bit 0 */
#define  FMC_BTR2_ADDHLD_1                  (0x00000020)        /*!<Bit 1 */
#define  FMC_BTR2_ADDHLD_2                  (0x00000040)        /*!<Bit 2 */
#define  FMC_BTR2_ADDHLD_3                  (0x00000080)        /*!<Bit 3 */

#define  FMC_BTR2_DATAST                    (0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BTR2_DATAST_0                  (0x00000100)        /*!<Bit 0 */
#define  FMC_BTR2_DATAST_1                  (0x00000200)        /*!<Bit 1 */
#define  FMC_BTR2_DATAST_2                  (0x00000400)        /*!<Bit 2 */
#define  FMC_BTR2_DATAST_3                  (0x00000800)        /*!<Bit 3 */
#define  FMC_BTR2_DATAST_4                  (0x00001000)        /*!<Bit 4 */
#define  FMC_BTR2_DATAST_5                  (0x00002000)        /*!<Bit 5 */
#define  FMC_BTR2_DATAST_6                  (0x00004000)        /*!<Bit 6 */
#define  FMC_BTR2_DATAST_7                  (0x00008000)        /*!<Bit 7 */

#define  FMC_BTR2_BUSTURN                   (0x000F0000)        /*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FMC_BTR2_BUSTURN_0                 (0x00010000)        /*!<Bit 0 */
#define  FMC_BTR2_BUSTURN_1                 (0x00020000)        /*!<Bit 1 */
#define  FMC_BTR2_BUSTURN_2                 (0x00040000)        /*!<Bit 2 */
#define  FMC_BTR2_BUSTURN_3                 (0x00080000)        /*!<Bit 3 */

#define  FMC_BTR2_CLKDIV                    (0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BTR2_CLKDIV_0                  (0x00100000)        /*!<Bit 0 */
#define  FMC_BTR2_CLKDIV_1                  (0x00200000)        /*!<Bit 1 */
#define  FMC_BTR2_CLKDIV_2                  (0x00400000)        /*!<Bit 2 */
#define  FMC_BTR2_CLKDIV_3                  (0x00800000)        /*!<Bit 3 */

#define  FMC_BTR2_DATLAT                    (0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BTR2_DATLAT_0                  (0x01000000)        /*!<Bit 0 */
#define  FMC_BTR2_DATLAT_1                  (0x02000000)        /*!<Bit 1 */
#define  FMC_BTR2_DATLAT_2                  (0x04000000)        /*!<Bit 2 */
#define  FMC_BTR2_DATLAT_3                  (0x08000000)        /*!<Bit 3 */

#define  FMC_BTR2_ACCMOD                    (0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BTR2_ACCMOD_0                  (0x10000000)        /*!<Bit 0 */
#define  FMC_BTR2_ACCMOD_1                  (0x20000000)        /*!<Bit 1 */

#define  FMC_BTR3_ADDSET                    (0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BTR3_ADDSET_0                  (0x00000001)        /*!<Bit 0 */
#define  FMC_BTR3_ADDSET_1                  (0x00000002)        /*!<Bit 1 */
#define  FMC_BTR3_ADDSET_2                  (0x00000004)        /*!<Bit 2 */
#define  FMC_BTR3_ADDSET_3                  (0x00000008)        /*!<Bit 3 */

#define  FMC_BTR3_ADDHLD                    (0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BTR3_ADDHLD_0                  (0x00000010)        /*!<Bit 0 */
#define  FMC_BTR3_ADDHLD_1                  (0x00000020)        /*!<Bit 1 */
#define  FMC_BTR3_ADDHLD_2                  (0x00000040)        /*!<Bit 2 */
#define  FMC_BTR3_ADDHLD_3                  (0x00000080)        /*!<Bit 3 */

#define  FMC_BTR3_DATAST                    (0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BTR3_DATAST_0                  (0x00000100)        /*!<Bit 0 */
#define  FMC_BTR3_DATAST_1                  (0x00000200)        /*!<Bit 1 */
#define  FMC_BTR3_DATAST_2                  (0x00000400)        /*!<Bit 2 */
#define  FMC_BTR3_DATAST_3                  (0x00000800)        /*!<Bit 3 */
#define  FMC_BTR3_DATAST_4                  (0x00001000)        /*!<Bit 4 */
#define  FMC_BTR3_DATAST_5                  (0x00002000)        /*!<Bit 5 */
#define  FMC_BTR3_DATAST_6                  (0x00004000)        /*!<Bit 6 */
#define  FMC_BTR3_DATAST_7                  (0x00008000)        /*!<Bit 7 */

#define  FMC_BTR3_BUSTURN                   (0x000F0000)        /*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FMC_BTR3_BUSTURN_0                 (0x00010000)        /*!<Bit 0 */
#define  FMC_BTR3_BUSTURN_1                 (0x00020000)        /*!<Bit 1 */
#define  FMC_BTR3_BUSTURN_2                 (0x00040000)        /*!<Bit 2 */
#define  FMC_BTR3_BUSTURN_3                 (0x00080000)        /*!<Bit 3 */

#define  FMC_BTR3_CLKDIV                    (0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BTR3_CLKDIV_0                  (0x00100000)        /*!<Bit 0 */
#define  FMC_BTR3_CLKDIV_1                  (0x00200000)        /*!<Bit 1 */
#define  FMC_BTR3_CLKDIV_2                  (0x00400000)        /*!<Bit 2 */
#define  FMC_BTR3_CLKDIV_3                  (0x00800000)        /*!<Bit 3 */

#define  FMC_BTR3_DATLAT                    (0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BTR3_DATLAT_0                  (0x01000000)        /*!<Bit 0 */
#define  FMC_BTR3_DATLAT_1                  (0x02000000)        /*!<Bit 1 */
#define  FMC_BTR3_DATLAT_2                  (0x04000000)        /*!<Bit 2 */
#define  FMC_BTR3_DATLAT_3                  (0x08000000)        /*!<Bit 3 */

#define  FMC_BTR3_ACCMOD                    (0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BTR3_ACCMOD_0                  (0x10000000)        /*!<Bit 0 */
#define  FMC_BTR3_ACCMOD_1                  (0x20000000)        /*!<Bit 1 */

#define  FMC_BTR4_ADDSET                    (0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BTR4_ADDSET_0                  (0x00000001)        /*!<Bit 0 */
#define  FMC_BTR4_ADDSET_1                  (0x00000002)        /*!<Bit 1 */
#define  FMC_BTR4_ADDSET_2                  (0x00000004)        /*!<Bit 2 */
#define  FMC_BTR4_ADDSET_3                  (0x00000008)        /*!<Bit 3 */

#define  FMC_BTR4_ADDHLD                    (0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BTR4_ADDHLD_0                  (0x00000010)        /*!<Bit 0 */
#define  FMC_BTR4_ADDHLD_1                  (0x00000020)        /*!<Bit 1 */
#define  FMC_BTR4_ADDHLD_2                  (0x00000040)        /*!<Bit 2 */
#define  FMC_BTR4_ADDHLD_3                  (0x00000080)        /*!<Bit 3 */

#define  FMC_BTR4_DATAST                    (0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BTR4_DATAST_0                  (0x00000100)        /*!<Bit 0 */
#define  FMC_BTR4_DATAST_1                  (0x00000200)        /*!<Bit 1 */
#define  FMC_BTR4_DATAST_2                  (0x00000400)        /*!<Bit 2 */
#define  FMC_BTR4_DATAST_3                  (0x00000800)        /*!<Bit 3 */
#define  FMC_BTR4_DATAST_4                  (0x00001000)        /*!<Bit 4 */
#define  FMC_BTR4_DATAST_5                  (0x00002000)        /*!<Bit 5 */
#define  FMC_BTR4_DATAST_6                  (0x00004000)        /*!<Bit 6 */
#define  FMC_BTR4_DATAST_7                  (0x00008000)        /*!<Bit 7 */

#define  FMC_BTR4_BUSTURN                   (0x000F0000)        /*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define  FMC_BTR4_BUSTURN_0                 (0x00010000)        /*!<Bit 0 */
#define  FMC_BTR4_BUSTURN_1                 (0x00020000)        /*!<Bit 1 */
#define  FMC_BTR4_BUSTURN_2                 (0x00040000)        /*!<Bit 2 */
#define  FMC_BTR4_BUSTURN_3                 (0x00080000)        /*!<Bit 3 */

#define  FMC_BTR4_CLKDIV                    (0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BTR4_CLKDIV_0                  (0x00100000)        /*!<Bit 0 */
#define  FMC_BTR4_CLKDIV_1                  (0x00200000)        /*!<Bit 1 */
#define  FMC_BTR4_CLKDIV_2                  (0x00400000)        /*!<Bit 2 */
#define  FMC_BTR4_CLKDIV_3                  (0x00800000)        /*!<Bit 3 */

#define  FMC_BTR4_DATLAT                    (0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BTR4_DATLAT_0                  (0x01000000)        /*!<Bit 0 */
#define  FMC_BTR4_DATLAT_1                  (0x02000000)        /*!<Bit 1 */
#define  FMC_BTR4_DATLAT_2                  (0x04000000)        /*!<Bit 2 */
#define  FMC_BTR4_DATLAT_3                  (0x08000000)        /*!<Bit 3 */

#define  FMC_BTR4_ACCMOD                    (0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BTR4_ACCMOD_0                  (0x10000000)        /*!<Bit 0 */
#define  FMC_BTR4_ACCMOD_1                  (0x20000000)        /*!<Bit 1 */

#define  FMC_BWTR1_ADDSET                   (0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BWTR1_ADDSET_0                 (0x00000001)        /*!<Bit 0 */
#define  FMC_BWTR1_ADDSET_1                 (0x00000002)        /*!<Bit 1 */
#define  FMC_BWTR1_ADDSET_2                 (0x00000004)        /*!<Bit 2 */
#define  FMC_BWTR1_ADDSET_3                 (0x00000008)        /*!<Bit 3 */

#define  FMC_BWTR1_ADDHLD                   (0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BWTR1_ADDHLD_0                 (0x00000010)        /*!<Bit 0 */
#define  FMC_BWTR1_ADDHLD_1                 (0x00000020)        /*!<Bit 1 */
#define  FMC_BWTR1_ADDHLD_2                 (0x00000040)        /*!<Bit 2 */
#define  FMC_BWTR1_ADDHLD_3                 (0x00000080)        /*!<Bit 3 */

#define  FMC_BWTR1_DATAST                   (0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BWTR1_DATAST_0                 (0x00000100)        /*!<Bit 0 */
#define  FMC_BWTR1_DATAST_1                 (0x00000200)        /*!<Bit 1 */
#define  FMC_BWTR1_DATAST_2                 (0x00000400)        /*!<Bit 2 */
#define  FMC_BWTR1_DATAST_3                 (0x00000800)        /*!<Bit 3 */
#define  FMC_BWTR1_DATAST_4                 (0x00001000)        /*!<Bit 4 */
#define  FMC_BWTR1_DATAST_5                 (0x00002000)        /*!<Bit 5 */
#define  FMC_BWTR1_DATAST_6                 (0x00004000)        /*!<Bit 6 */
#define  FMC_BWTR1_DATAST_7                 (0x00008000)        /*!<Bit 7 */

#define  FMC_BWTR1_CLKDIV                   (0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BWTR1_CLKDIV_0                 (0x00100000)        /*!<Bit 0 */
#define  FMC_BWTR1_CLKDIV_1                 (0x00200000)        /*!<Bit 1 */
#define  FMC_BWTR1_CLKDIV_2                 (0x00400000)        /*!<Bit 2 */
#define  FMC_BWTR1_CLKDIV_3                 (0x00800000)        /*!<Bit 3 */

#define  FMC_BWTR1_DATLAT                   (0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BWTR1_DATLAT_0                 (0x01000000)        /*!<Bit 0 */
#define  FMC_BWTR1_DATLAT_1                 (0x02000000)        /*!<Bit 1 */
#define  FMC_BWTR1_DATLAT_2                 (0x04000000)        /*!<Bit 2 */
#define  FMC_BWTR1_DATLAT_3                 (0x08000000)        /*!<Bit 3 */

#define  FMC_BWTR1_ACCMOD                   (0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BWTR1_ACCMOD_0                 (0x10000000)        /*!<Bit 0 */
#define  FMC_BWTR1_ACCMOD_1                 (0x20000000)        /*!<Bit 1 */

#define  FMC_BWTR2_ADDSET                   (0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BWTR2_ADDSET_0                 (0x00000001)        /*!<Bit 0 */
#define  FMC_BWTR2_ADDSET_1                 (0x00000002)        /*!<Bit 1 */
#define  FMC_BWTR2_ADDSET_2                 (0x00000004)        /*!<Bit 2 */
#define  FMC_BWTR2_ADDSET_3                 (0x00000008)        /*!<Bit 3 */

#define  FMC_BWTR2_ADDHLD                   (0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BWTR2_ADDHLD_0                 (0x00000010)        /*!<Bit 0 */
#define  FMC_BWTR2_ADDHLD_1                 (0x00000020)        /*!<Bit 1 */
#define  FMC_BWTR2_ADDHLD_2                 (0x00000040)        /*!<Bit 2 */
#define  FMC_BWTR2_ADDHLD_3                 (0x00000080)        /*!<Bit 3 */

#define  FMC_BWTR2_DATAST                   (0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BWTR2_DATAST_0                 (0x00000100)        /*!<Bit 0 */
#define  FMC_BWTR2_DATAST_1                 (0x00000200)        /*!<Bit 1 */
#define  FMC_BWTR2_DATAST_2                 (0x00000400)        /*!<Bit 2 */
#define  FMC_BWTR2_DATAST_3                 (0x00000800)        /*!<Bit 3 */
#define  FMC_BWTR2_DATAST_4                 (0x00001000)        /*!<Bit 4 */
#define  FMC_BWTR2_DATAST_5                 (0x00002000)        /*!<Bit 5 */
#define  FMC_BWTR2_DATAST_6                 (0x00004000)        /*!<Bit 6 */
#define  FMC_BWTR2_DATAST_7                 (0x00008000)        /*!<Bit 7 */

#define  FMC_BWTR2_CLKDIV                   (0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BWTR2_CLKDIV_0                 (0x00100000)        /*!<Bit 0 */
#define  FMC_BWTR2_CLKDIV_1                 (0x00200000)        /*!<Bit 1*/
#define  FMC_BWTR2_CLKDIV_2                 (0x00400000)        /*!<Bit 2 */
#define  FMC_BWTR2_CLKDIV_3                 (0x00800000)        /*!<Bit 3 */

#define  FMC_BWTR2_DATLAT                   (0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BWTR2_DATLAT_0                 (0x01000000)        /*!<Bit 0 */
#define  FMC_BWTR2_DATLAT_1                 (0x02000000)        /*!<Bit 1 */
#define  FMC_BWTR2_DATLAT_2                 (0x04000000)        /*!<Bit 2 */
#define  FMC_BWTR2_DATLAT_3                 (0x08000000)        /*!<Bit 3 */

#define  FMC_BWTR2_ACCMOD                   (0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BWTR2_ACCMOD_0                 (0x10000000)        /*!<Bit 0 */
#define  FMC_BWTR2_ACCMOD_1                 (0x20000000)        /*!<Bit 1 */

#define  FMC_BWTR3_ADDSET                   (0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BWTR3_ADDSET_0                 (0x00000001)        /*!<Bit 0 */
#define  FMC_BWTR3_ADDSET_1                 (0x00000002)        /*!<Bit 1 */
#define  FMC_BWTR3_ADDSET_2                 (0x00000004)        /*!<Bit 2 */
#define  FMC_BWTR3_ADDSET_3                 (0x00000008)        /*!<Bit 3 */

#define  FMC_BWTR3_ADDHLD                   (0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BWTR3_ADDHLD_0                 (0x00000010)        /*!<Bit 0 */
#define  FMC_BWTR3_ADDHLD_1                 (0x00000020)        /*!<Bit 1 */
#define  FMC_BWTR3_ADDHLD_2                 (0x00000040)        /*!<Bit 2 */
#define  FMC_BWTR3_ADDHLD_3                 (0x00000080)        /*!<Bit 3 */

#define  FMC_BWTR3_DATAST                   (0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BWTR3_DATAST_0                 (0x00000100)        /*!<Bit 0 */
#define  FMC_BWTR3_DATAST_1                 (0x00000200)        /*!<Bit 1 */
#define  FMC_BWTR3_DATAST_2                 (0x00000400)        /*!<Bit 2 */
#define  FMC_BWTR3_DATAST_3                 (0x00000800)        /*!<Bit 3 */
#define  FMC_BWTR3_DATAST_4                 (0x00001000)        /*!<Bit 4 */
#define  FMC_BWTR3_DATAST_5                 (0x00002000)        /*!<Bit 5 */
#define  FMC_BWTR3_DATAST_6                 (0x00004000)        /*!<Bit 6 */
#define  FMC_BWTR3_DATAST_7                 (0x00008000)        /*!<Bit 7 */

#define  FMC_BWTR3_CLKDIV                   (0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BWTR3_CLKDIV_0                 (0x00100000)        /*!<Bit 0 */
#define  FMC_BWTR3_CLKDIV_1                 (0x00200000)        /*!<Bit 1 */
#define  FMC_BWTR3_CLKDIV_2                 (0x00400000)        /*!<Bit 2 */
#define  FMC_BWTR3_CLKDIV_3                 (0x00800000)        /*!<Bit 3 */

#define  FMC_BWTR3_DATLAT                   (0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BWTR3_DATLAT_0                 (0x01000000)        /*!<Bit 0 */
#define  FMC_BWTR3_DATLAT_1                 (0x02000000)        /*!<Bit 1 */
#define  FMC_BWTR3_DATLAT_2                 (0x04000000)        /*!<Bit 2 */
#define  FMC_BWTR3_DATLAT_3                 (0x08000000)        /*!<Bit 3 */

#define  FMC_BWTR3_ACCMOD                   (0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BWTR3_ACCMOD_0                 (0x10000000)        /*!<Bit 0 */
#define  FMC_BWTR3_ACCMOD_1                 (0x20000000)        /*!<Bit 1 */

#define  FMC_BWTR4_ADDSET                   (0x0000000F)        /*!<ADDSET[3:0] bits (Address setup phase duration) */
#define  FMC_BWTR4_ADDSET_0                 (0x00000001)        /*!<Bit 0 */
#define  FMC_BWTR4_ADDSET_1                 (0x00000002)        /*!<Bit 1 */
#define  FMC_BWTR4_ADDSET_2                 (0x00000004)        /*!<Bit 2 */
#define  FMC_BWTR4_ADDSET_3                 (0x00000008)        /*!<Bit 3 */

#define  FMC_BWTR4_ADDHLD                   (0x000000F0)        /*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define  FMC_BWTR4_ADDHLD_0                 (0x00000010)        /*!<Bit 0 */
#define  FMC_BWTR4_ADDHLD_1                 (0x00000020)        /*!<Bit 1 */
#define  FMC_BWTR4_ADDHLD_2                 (0x00000040)        /*!<Bit 2 */
#define  FMC_BWTR4_ADDHLD_3                 (0x00000080)        /*!<Bit 3 */

#define  FMC_BWTR4_DATAST                   (0x0000FF00)        /*!<DATAST [3:0] bits (Data-phase duration) */
#define  FMC_BWTR4_DATAST_0                 (0x00000100)        /*!<Bit 0 */
#define  FMC_BWTR4_DATAST_1                 (0x00000200)        /*!<Bit 1 */
#define  FMC_BWTR4_DATAST_2                 (0x00000400)        /*!<Bit 2 */
#define  FMC_BWTR4_DATAST_3                 (0x00000800)        /*!<Bit 3 */
#define  FMC_BWTR4_DATAST_4                 (0x00001000)        /*!<Bit 4 */
#define  FMC_BWTR4_DATAST_5                 (0x00002000)        /*!<Bit 5 */
#define  FMC_BWTR4_DATAST_6                 (0x00004000)        /*!<Bit 6 */
#define  FMC_BWTR4_DATAST_7                 (0x00008000)        /*!<Bit 7 */

#define  FMC_BWTR4_CLKDIV                   (0x00F00000)        /*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define  FMC_BWTR4_CLKDIV_0                 (0x00100000)        /*!<Bit 0 */
#define  FMC_BWTR4_CLKDIV_1                 (0x00200000)        /*!<Bit 1 */
#define  FMC_BWTR4_CLKDIV_2                 (0x00400000)        /*!<Bit 2 */
#define  FMC_BWTR4_CLKDIV_3                 (0x00800000)        /*!<Bit 3 */

#define  FMC_BWTR4_DATLAT                   (0x0F000000)        /*!<DATLA[3:0] bits (Data latency) */
#define  FMC_BWTR4_DATLAT_0                 (0x01000000)        /*!<Bit 0 */
#define  FMC_BWTR4_DATLAT_1                 (0x02000000)        /*!<Bit 1 */
#define  FMC_BWTR4_DATLAT_2                 (0x04000000)        /*!<Bit 2 */
#define  FMC_BWTR4_DATLAT_3                 (0x08000000)        /*!<Bit 3 */

#define  FMC_BWTR4_ACCMOD                   (0x30000000)        /*!<ACCMOD[1:0] bits (Access mode) */
#define  FMC_BWTR4_ACCMOD_0                 (0x10000000)        /*!<Bit 0 */
#define  FMC_BWTR4_ACCMOD_1                 (0x20000000)        /*!<Bit 1 */

#define  FMC_PCR2_PWAITEN                   (0x00000002)        /*!<Wait feature enable bit                   */
#define  FMC_PCR2_PBKEN                     (0x00000004)        /*!<PC Card/NAND Flash memory bank enable bit */
#define  FMC_PCR2_PTYP                      (0x00000008)        /*!<Memory type                               */

#define  FMC_PCR2_PWID                      (0x00000030)        /*!<PWID[1:0] bits (NAND Flash databus width) */
#define  FMC_PCR2_PWID_0                    (0x00000010)        /*!<Bit 0 */
#define  FMC_PCR2_PWID_1                    (0x00000020)        /*!<Bit 1 */

#define  FMC_PCR2_ECCEN                     (0x00000040)        /*!<ECC computation logic enable bit          */

#define  FMC_PCR2_TCLR                      (0x00001E00)        /*!<TCLR[3:0] bits (CLE to RE delay)          */
#define  FMC_PCR2_TCLR_0                    (0x00000200)        /*!<Bit 0 */
#define  FMC_PCR2_TCLR_1                    (0x00000400)        /*!<Bit 1 */
#define  FMC_PCR2_TCLR_2                    (0x00000800)        /*!<Bit 2 */
#define  FMC_PCR2_TCLR_3                    (0x00001000)        /*!<Bit 3 */

#define  FMC_PCR2_TAR                       (0x0001E000)        /*!<TAR[3:0] bits (ALE to RE delay)           */
#define  FMC_PCR2_TAR_0                     (0x00002000)        /*!<Bit 0 */
#define  FMC_PCR2_TAR_1                     (0x00004000)        /*!<Bit 1 */
#define  FMC_PCR2_TAR_2                     (0x00008000)        /*!<Bit 2 */
#define  FMC_PCR2_TAR_3                     (0x00010000)        /*!<Bit 3 */

#define  FMC_PCR2_ECCPS                     (0x000E0000)        /*!<ECCPS[1:0] bits (ECC page size)           */
#define  FMC_PCR2_ECCPS_0                   (0x00020000)        /*!<Bit 0 */
#define  FMC_PCR2_ECCPS_1                   (0x00040000)        /*!<Bit 1 */
#define  FMC_PCR2_ECCPS_2                   (0x00080000)        /*!<Bit 2 */

#define  FMC_PCR3_PWAITEN                   (0x00000002)        /*!<Wait feature enable bit                   */
#define  FMC_PCR3_PBKEN                     (0x00000004)        /*!<PC Card/NAND Flash memory bank enable bit */
#define  FMC_PCR3_PTYP                      (0x00000008)        /*!<Memory type                               */

#define  FMC_PCR3_PWID                      (0x00000030)        /*!<PWID[1:0] bits (NAND Flash databus width) */
#define  FMC_PCR3_PWID_0                    (0x00000010)        /*!<Bit 0 */
#define  FMC_PCR3_PWID_1                    (0x00000020)        /*!<Bit 1 */

#define  FMC_PCR3_ECCEN                     (0x00000040)        /*!<ECC computation logic enable bit          */

#define  FMC_PCR3_TCLR                      (0x00001E00)        /*!<TCLR[3:0] bits (CLE to RE delay)          */
#define  FMC_PCR3_TCLR_0                    (0x00000200)        /*!<Bit 0 */
#define  FMC_PCR3_TCLR_1                    (0x00000400)        /*!<Bit 1 */
#define  FMC_PCR3_TCLR_2                    (0x00000800)        /*!<Bit 2 */
#define  FMC_PCR3_TCLR_3                    (0x00001000)        /*!<Bit 3 */

#define  FMC_PCR3_TAR                       (0x0001E000)        /*!<TAR[3:0] bits (ALE to RE delay)           */
#define  FMC_PCR3_TAR_0                     (0x00002000)        /*!<Bit 0 */
#define  FMC_PCR3_TAR_1                     (0x00004000)        /*!<Bit 1 */
#define  FMC_PCR3_TAR_2                     (0x00008000)        /*!<Bit 2 */
#define  FMC_PCR3_TAR_3                     (0x00010000)        /*!<Bit 3 */

#define  FMC_PCR3_ECCPS                     (0x000E0000)        /*!<ECCPS[2:0] bits (ECC page size)           */
#define  FMC_PCR3_ECCPS_0                   (0x00020000)        /*!<Bit 0 */
#define  FMC_PCR3_ECCPS_1                   (0x00040000)        /*!<Bit 1 */
#define  FMC_PCR3_ECCPS_2                   (0x00080000)        /*!<Bit 2 */

#define  FMC_PCR4_PWAITEN                   (0x00000002)        /*!<Wait feature enable bit                   */
#define  FMC_PCR4_PBKEN                     (0x00000004)        /*!<PC Card/NAND Flash memory bank enable bit */
#define  FMC_PCR4_PTYP                      (0x00000008)        /*!<Memory type                               */

#define  FMC_PCR4_PWID                      (0x00000030)        /*!<PWID[1:0] bits (NAND Flash databus width) */
#define  FMC_PCR4_PWID_0                    (0x00000010)        /*!<Bit 0 */
#define  FMC_PCR4_PWID_1                    (0x00000020)        /*!<Bit 1 */

#define  FMC_PCR4_ECCEN                     (0x00000040)        /*!<ECC computation logic enable bit          */

#define  FMC_PCR4_TCLR                      (0x00001E00)        /*!<TCLR[3:0] bits (CLE to RE delay)          */
#define  FMC_PCR4_TCLR_0                    (0x00000200)        /*!<Bit 0 */
#define  FMC_PCR4_TCLR_1                    (0x00000400)        /*!<Bit 1 */
#define  FMC_PCR4_TCLR_2                    (0x00000800)        /*!<Bit 2 */
#define  FMC_PCR4_TCLR_3                    (0x00001000)        /*!<Bit 3 */

#define  FMC_PCR4_TAR                       (0x0001E000)        /*!<TAR[3:0] bits (ALE to RE delay)           */
#define  FMC_PCR4_TAR_0                     (0x00002000)        /*!<Bit 0 */
#define  FMC_PCR4_TAR_1                     (0x00004000)        /*!<Bit 1 */
#define  FMC_PCR4_TAR_2                     (0x00008000)        /*!<Bit 2 */
#define  FMC_PCR4_TAR_3                     (0x00010000)        /*!<Bit 3 */

#define  FMC_PCR4_ECCPS                     (0x000E0000)        /*!<ECCPS[2:0] bits (ECC page size)           */
#define  FMC_PCR4_ECCPS_0                   (0x00020000)        /*!<Bit 0 */
#define  FMC_PCR4_ECCPS_1                   (0x00040000)        /*!<Bit 1 */
#define  FMC_PCR4_ECCPS_2                   (0x00080000)        /*!<Bit 2 */

#define  FMC_SR2_IRS                        (0x01)               /*!<Interrupt Rising Edge status                */
#define  FMC_SR2_ILS                        (0x02)               /*!<Interrupt Level status                      */
#define  FMC_SR2_IFS                        (0x04)               /*!<Interrupt Falling Edge status               */
#define  FMC_SR2_IREN                       (0x08)               /*!<Interrupt Rising Edge detection Enable bit  */
#define  FMC_SR2_ILEN                       (0x10)               /*!<Interrupt Level detection Enable bit        */
#define  FMC_SR2_IFEN                       (0x20)               /*!<Interrupt Falling Edge detection Enable bit */
#define  FMC_SR2_FEMPT                      (0x40)               /*!<FIFO empty                                  */

#define  FMC_SR3_IRS                        (0x01)               /*!<Interrupt Rising Edge status                */
#define  FMC_SR3_ILS                        (0x02)               /*!<Interrupt Level status                      */
#define  FMC_SR3_IFS                        (0x04)               /*!<Interrupt Falling Edge status               */
#define  FMC_SR3_IREN                       (0x08)               /*!<Interrupt Rising Edge detection Enable bit  */
#define  FMC_SR3_ILEN                       (0x10)               /*!<Interrupt Level detection Enable bit        */
#define  FMC_SR3_IFEN                       (0x20)               /*!<Interrupt Falling Edge detection Enable bit */
#define  FMC_SR3_FEMPT                      (0x40)               /*!<FIFO empty                                  */

#define  FMC_SR4_IRS                        (0x01)               /*!<Interrupt Rising Edge status                */
#define  FMC_SR4_ILS                        (0x02)               /*!<Interrupt Level status                      */
#define  FMC_SR4_IFS                        (0x04)               /*!<Interrupt Falling Edge status               */
#define  FMC_SR4_IREN                       (0x08)               /*!<Interrupt Rising Edge detection Enable bit  */
#define  FMC_SR4_ILEN                       (0x10)               /*!<Interrupt Level detection Enable bit        */
#define  FMC_SR4_IFEN                       (0x20)               /*!<Interrupt Falling Edge detection Enable bit */
#define  FMC_SR4_FEMPT                      (0x40)               /*!<FIFO empty                                  */

#define  FMC_PMEM2_MEMSET2                  (0x000000FF)        /*!<MEMSET2[7:0] bits (Common memory 2 setup time) */
#define  FMC_PMEM2_MEMSET2_0                (0x00000001)        /*!<Bit 0 */
#define  FMC_PMEM2_MEMSET2_1                (0x00000002)        /*!<Bit 1 */
#define  FMC_PMEM2_MEMSET2_2                (0x00000004)        /*!<Bit 2 */
#define  FMC_PMEM2_MEMSET2_3                (0x00000008)        /*!<Bit 3 */
#define  FMC_PMEM2_MEMSET2_4                (0x00000010)        /*!<Bit 4 */
#define  FMC_PMEM2_MEMSET2_5                (0x00000020)        /*!<Bit 5 */
#define  FMC_PMEM2_MEMSET2_6                (0x00000040)        /*!<Bit 6 */
#define  FMC_PMEM2_MEMSET2_7                (0x00000080)        /*!<Bit 7 */

#define  FMC_PMEM2_MEMWAIT2                 (0x0000FF00)        /*!<MEMWAIT2[7:0] bits (Common memory 2 wait time) */
#define  FMC_PMEM2_MEMWAIT2_0               (0x00000100)        /*!<Bit 0 */
#define  FMC_PMEM2_MEMWAIT2_1               (0x00000200)        /*!<Bit 1 */
#define  FMC_PMEM2_MEMWAIT2_2               (0x00000400)        /*!<Bit 2 */
#define  FMC_PMEM2_MEMWAIT2_3               (0x00000800)        /*!<Bit 3 */
#define  FMC_PMEM2_MEMWAIT2_4               (0x00001000)        /*!<Bit 4 */
#define  FMC_PMEM2_MEMWAIT2_5               (0x00002000)        /*!<Bit 5 */
#define  FMC_PMEM2_MEMWAIT2_6               (0x00004000)        /*!<Bit 6 */
#define  FMC_PMEM2_MEMWAIT2_7               (0x00008000)        /*!<Bit 7 */

#define  FMC_PMEM2_MEMHOLD2                 (0x00FF0000)        /*!<MEMHOLD2[7:0] bits (Common memory 2 hold time) */
#define  FMC_PMEM2_MEMHOLD2_0               (0x00010000)        /*!<Bit 0 */
#define  FMC_PMEM2_MEMHOLD2_1               (0x00020000)        /*!<Bit 1 */
#define  FMC_PMEM2_MEMHOLD2_2               (0x00040000)        /*!<Bit 2 */
#define  FMC_PMEM2_MEMHOLD2_3               (0x00080000)        /*!<Bit 3 */
#define  FMC_PMEM2_MEMHOLD2_4               (0x00100000)        /*!<Bit 4 */
#define  FMC_PMEM2_MEMHOLD2_5               (0x00200000)        /*!<Bit 5 */
#define  FMC_PMEM2_MEMHOLD2_6               (0x00400000)        /*!<Bit 6 */
#define  FMC_PMEM2_MEMHOLD2_7               (0x00800000)        /*!<Bit 7 */

#define  FMC_PMEM2_MEMHIZ2                  (0xFF000000)        /*!<MEMHIZ2[7:0] bits (Common memory 2 databus HiZ time) */
#define  FMC_PMEM2_MEMHIZ2_0                (0x01000000)        /*!<Bit 0 */
#define  FMC_PMEM2_MEMHIZ2_1                (0x02000000)        /*!<Bit 1 */
#define  FMC_PMEM2_MEMHIZ2_2                (0x04000000)        /*!<Bit 2 */
#define  FMC_PMEM2_MEMHIZ2_3                (0x08000000)        /*!<Bit 3 */
#define  FMC_PMEM2_MEMHIZ2_4                (0x10000000)        /*!<Bit 4 */
#define  FMC_PMEM2_MEMHIZ2_5                (0x20000000)        /*!<Bit 5 */
#define  FMC_PMEM2_MEMHIZ2_6                (0x40000000)        /*!<Bit 6 */
#define  FMC_PMEM2_MEMHIZ2_7                (0x80000000)        /*!<Bit 7 */

#define  FMC_PMEM3_MEMSET3                  (0x000000FF)        /*!<MEMSET3[7:0] bits (Common memory 3 setup time) */
#define  FMC_PMEM3_MEMSET3_0                (0x00000001)        /*!<Bit 0 */
#define  FMC_PMEM3_MEMSET3_1                (0x00000002)        /*!<Bit 1 */
#define  FMC_PMEM3_MEMSET3_2                (0x00000004)        /*!<Bit 2 */
#define  FMC_PMEM3_MEMSET3_3                (0x00000008)        /*!<Bit 3 */
#define  FMC_PMEM3_MEMSET3_4                (0x00000010)        /*!<Bit 4 */
#define  FMC_PMEM3_MEMSET3_5                (0x00000020)        /*!<Bit 5 */
#define  FMC_PMEM3_MEMSET3_6                (0x00000040)        /*!<Bit 6 */
#define  FMC_PMEM3_MEMSET3_7                (0x00000080)        /*!<Bit 7 */

#define  FMC_PMEM3_MEMWAIT3                 (0x0000FF00)        /*!<MEMWAIT3[7:0] bits (Common memory 3 wait time) */
#define  FMC_PMEM3_MEMWAIT3_0               (0x00000100)        /*!<Bit 0 */
#define  FMC_PMEM3_MEMWAIT3_1               (0x00000200)        /*!<Bit 1 */
#define  FMC_PMEM3_MEMWAIT3_2               (0x00000400)        /*!<Bit 2 */
#define  FMC_PMEM3_MEMWAIT3_3               (0x00000800)        /*!<Bit 3 */
#define  FMC_PMEM3_MEMWAIT3_4               (0x00001000)        /*!<Bit 4 */
#define  FMC_PMEM3_MEMWAIT3_5               (0x00002000)        /*!<Bit 5 */
#define  FMC_PMEM3_MEMWAIT3_6               (0x00004000)        /*!<Bit 6 */
#define  FMC_PMEM3_MEMWAIT3_7               (0x00008000)        /*!<Bit 7 */

#define  FMC_PMEM3_MEMHOLD3                 (0x00FF0000)        /*!<MEMHOLD3[7:0] bits (Common memory 3 hold time) */
#define  FMC_PMEM3_MEMHOLD3_0               (0x00010000)        /*!<Bit 0 */
#define  FMC_PMEM3_MEMHOLD3_1               (0x00020000)        /*!<Bit 1 */
#define  FMC_PMEM3_MEMHOLD3_2               (0x00040000)        /*!<Bit 2 */
#define  FMC_PMEM3_MEMHOLD3_3               (0x00080000)        /*!<Bit 3 */
#define  FMC_PMEM3_MEMHOLD3_4               (0x00100000)        /*!<Bit 4 */
#define  FMC_PMEM3_MEMHOLD3_5               (0x00200000)        /*!<Bit 5 */
#define  FMC_PMEM3_MEMHOLD3_6               (0x00400000)        /*!<Bit 6 */
#define  FMC_PMEM3_MEMHOLD3_7               (0x00800000)        /*!<Bit 7 */

#define  FMC_PMEM3_MEMHIZ3                  (0xFF000000)        /*!<MEMHIZ3[7:0] bits (Common memory 3 databus HiZ time) */
#define  FMC_PMEM3_MEMHIZ3_0                (0x01000000)        /*!<Bit 0 */
#define  FMC_PMEM3_MEMHIZ3_1                (0x02000000)        /*!<Bit 1 */
#define  FMC_PMEM3_MEMHIZ3_2                (0x04000000)        /*!<Bit 2 */
#define  FMC_PMEM3_MEMHIZ3_3                (0x08000000)        /*!<Bit 3 */
#define  FMC_PMEM3_MEMHIZ3_4                (0x10000000)        /*!<Bit 4 */
#define  FMC_PMEM3_MEMHIZ3_5                (0x20000000)        /*!<Bit 5 */
#define  FMC_PMEM3_MEMHIZ3_6                (0x40000000)        /*!<Bit 6 */
#define  FMC_PMEM3_MEMHIZ3_7                (0x80000000)        /*!<Bit 7 */

#define  FMC_PMEM4_MEMSET4                  (0x000000FF)        /*!<MEMSET4[7:0] bits (Common memory 4 setup time) */
#define  FMC_PMEM4_MEMSET4_0                (0x00000001)        /*!<Bit 0 */
#define  FMC_PMEM4_MEMSET4_1                (0x00000002)        /*!<Bit 1 */
#define  FMC_PMEM4_MEMSET4_2                (0x00000004)        /*!<Bit 2 */
#define  FMC_PMEM4_MEMSET4_3                (0x00000008)        /*!<Bit 3 */
#define  FMC_PMEM4_MEMSET4_4                (0x00000010)        /*!<Bit 4 */
#define  FMC_PMEM4_MEMSET4_5                (0x00000020)        /*!<Bit 5 */
#define  FMC_PMEM4_MEMSET4_6                (0x00000040)        /*!<Bit 6 */
#define  FMC_PMEM4_MEMSET4_7                (0x00000080)        /*!<Bit 7 */

#define  FMC_PMEM4_MEMWAIT4                 (0x0000FF00)        /*!<MEMWAIT4[7:0] bits (Common memory 4 wait time) */
#define  FMC_PMEM4_MEMWAIT4_0               (0x00000100)        /*!<Bit 0 */
#define  FMC_PMEM4_MEMWAIT4_1               (0x00000200)        /*!<Bit 1 */
#define  FMC_PMEM4_MEMWAIT4_2               (0x00000400)        /*!<Bit 2 */
#define  FMC_PMEM4_MEMWAIT4_3               (0x00000800)        /*!<Bit 3 */
#define  FMC_PMEM4_MEMWAIT4_4               (0x00001000)        /*!<Bit 4 */
#define  FMC_PMEM4_MEMWAIT4_5               (0x00002000)        /*!<Bit 5 */
#define  FMC_PMEM4_MEMWAIT4_6               (0x00004000)        /*!<Bit 6 */
#define  FMC_PMEM4_MEMWAIT4_7               (0x00008000)        /*!<Bit 7 */

#define  FMC_PMEM4_MEMHOLD4                 (0x00FF0000)        /*!<MEMHOLD4[7:0] bits (Common memory 4 hold time) */
#define  FMC_PMEM4_MEMHOLD4_0               (0x00010000)        /*!<Bit 0 */
#define  FMC_PMEM4_MEMHOLD4_1               (0x00020000)        /*!<Bit 1 */
#define  FMC_PMEM4_MEMHOLD4_2               (0x00040000)        /*!<Bit 2 */
#define  FMC_PMEM4_MEMHOLD4_3               (0x00080000)        /*!<Bit 3 */
#define  FMC_PMEM4_MEMHOLD4_4               (0x00100000)        /*!<Bit 4 */
#define  FMC_PMEM4_MEMHOLD4_5               (0x00200000)        /*!<Bit 5 */
#define  FMC_PMEM4_MEMHOLD4_6               (0x00400000)        /*!<Bit 6 */
#define  FMC_PMEM4_MEMHOLD4_7               (0x00800000)        /*!<Bit 7 */

#define  FMC_PMEM4_MEMHIZ4                  (0xFF000000)        /*!<MEMHIZ4[7:0] bits (Common memory 4 databus HiZ time) */
#define  FMC_PMEM4_MEMHIZ4_0                (0x01000000)        /*!<Bit 0 */
#define  FMC_PMEM4_MEMHIZ4_1                (0x02000000)        /*!<Bit 1 */
#define  FMC_PMEM4_MEMHIZ4_2                (0x04000000)        /*!<Bit 2 */
#define  FMC_PMEM4_MEMHIZ4_3                (0x08000000)        /*!<Bit 3 */
#define  FMC_PMEM4_MEMHIZ4_4                (0x10000000)        /*!<Bit 4 */
#define  FMC_PMEM4_MEMHIZ4_5                (0x20000000)        /*!<Bit 5 */
#define  FMC_PMEM4_MEMHIZ4_6                (0x40000000)        /*!<Bit 6 */
#define  FMC_PMEM4_MEMHIZ4_7                (0x80000000)        /*!<Bit 7 */

#define  FMC_PATT2_ATTSET2                  (0x000000FF)        /*!<ATTSET2[7:0] bits (Attribute memory 2 setup time) */
#define  FMC_PATT2_ATTSET2_0                (0x00000001)        /*!<Bit 0 */
#define  FMC_PATT2_ATTSET2_1                (0x00000002)        /*!<Bit 1 */
#define  FMC_PATT2_ATTSET2_2                (0x00000004)        /*!<Bit 2 */
#define  FMC_PATT2_ATTSET2_3                (0x00000008)        /*!<Bit 3 */
#define  FMC_PATT2_ATTSET2_4                (0x00000010)        /*!<Bit 4 */
#define  FMC_PATT2_ATTSET2_5                (0x00000020)        /*!<Bit 5 */
#define  FMC_PATT2_ATTSET2_6                (0x00000040)        /*!<Bit 6 */
#define  FMC_PATT2_ATTSET2_7                (0x00000080)        /*!<Bit 7 */

#define  FMC_PATT2_ATTWAIT2                 (0x0000FF00)        /*!<ATTWAIT2[7:0] bits (Attribute memory 2 wait time) */
#define  FMC_PATT2_ATTWAIT2_0               (0x00000100)        /*!<Bit 0 */
#define  FMC_PATT2_ATTWAIT2_1               (0x00000200)        /*!<Bit 1 */
#define  FMC_PATT2_ATTWAIT2_2               (0x00000400)        /*!<Bit 2 */
#define  FMC_PATT2_ATTWAIT2_3               (0x00000800)        /*!<Bit 3 */
#define  FMC_PATT2_ATTWAIT2_4               (0x00001000)        /*!<Bit 4 */
#define  FMC_PATT2_ATTWAIT2_5               (0x00002000)        /*!<Bit 5 */
#define  FMC_PATT2_ATTWAIT2_6               (0x00004000)        /*!<Bit 6 */
#define  FMC_PATT2_ATTWAIT2_7               (0x00008000)        /*!<Bit 7 */

#define  FMC_PATT2_ATTHOLD2                 (0x00FF0000)        /*!<ATTHOLD2[7:0] bits (Attribute memory 2 hold time) */
#define  FMC_PATT2_ATTHOLD2_0               (0x00010000)        /*!<Bit 0 */
#define  FMC_PATT2_ATTHOLD2_1               (0x00020000)        /*!<Bit 1 */
#define  FMC_PATT2_ATTHOLD2_2               (0x00040000)        /*!<Bit 2 */
#define  FMC_PATT2_ATTHOLD2_3               (0x00080000)        /*!<Bit 3 */
#define  FMC_PATT2_ATTHOLD2_4               (0x00100000)        /*!<Bit 4 */
#define  FMC_PATT2_ATTHOLD2_5               (0x00200000)        /*!<Bit 5 */
#define  FMC_PATT2_ATTHOLD2_6               (0x00400000)        /*!<Bit 6 */
#define  FMC_PATT2_ATTHOLD2_7               (0x00800000)        /*!<Bit 7 */

#define  FMC_PATT2_ATTHIZ2                  (0xFF000000)        /*!<ATTHIZ2[7:0] bits (Attribute memory 2 databus HiZ time) */
#define  FMC_PATT2_ATTHIZ2_0                (0x01000000)        /*!<Bit 0 */
#define  FMC_PATT2_ATTHIZ2_1                (0x02000000)        /*!<Bit 1 */
#define  FMC_PATT2_ATTHIZ2_2                (0x04000000)        /*!<Bit 2 */
#define  FMC_PATT2_ATTHIZ2_3                (0x08000000)        /*!<Bit 3 */
#define  FMC_PATT2_ATTHIZ2_4                (0x10000000)        /*!<Bit 4 */
#define  FMC_PATT2_ATTHIZ2_5                (0x20000000)        /*!<Bit 5 */
#define  FMC_PATT2_ATTHIZ2_6                (0x40000000)        /*!<Bit 6 */
#define  FMC_PATT2_ATTHIZ2_7                (0x80000000)        /*!<Bit 7 */

#define  FMC_PATT3_ATTSET3                  (0x000000FF)        /*!<ATTSET3[7:0] bits (Attribute memory 3 setup time) */
#define  FMC_PATT3_ATTSET3_0                (0x00000001)        /*!<Bit 0 */
#define  FMC_PATT3_ATTSET3_1                (0x00000002)        /*!<Bit 1 */
#define  FMC_PATT3_ATTSET3_2                (0x00000004)        /*!<Bit 2 */
#define  FMC_PATT3_ATTSET3_3                (0x00000008)        /*!<Bit 3 */
#define  FMC_PATT3_ATTSET3_4                (0x00000010)        /*!<Bit 4 */
#define  FMC_PATT3_ATTSET3_5                (0x00000020)        /*!<Bit 5 */
#define  FMC_PATT3_ATTSET3_6                (0x00000040)        /*!<Bit 6 */
#define  FMC_PATT3_ATTSET3_7                (0x00000080)        /*!<Bit 7 */

#define  FMC_PATT3_ATTWAIT3                 (0x0000FF00)        /*!<ATTWAIT3[7:0] bits (Attribute memory 3 wait time) */
#define  FMC_PATT3_ATTWAIT3_0               (0x00000100)        /*!<Bit 0 */
#define  FMC_PATT3_ATTWAIT3_1               (0x00000200)        /*!<Bit 1 */
#define  FMC_PATT3_ATTWAIT3_2               (0x00000400)        /*!<Bit 2 */
#define  FMC_PATT3_ATTWAIT3_3               (0x00000800)        /*!<Bit 3 */
#define  FMC_PATT3_ATTWAIT3_4               (0x00001000)        /*!<Bit 4 */
#define  FMC_PATT3_ATTWAIT3_5               (0x00002000)        /*!<Bit 5 */
#define  FMC_PATT3_ATTWAIT3_6               (0x00004000)        /*!<Bit 6 */
#define  FMC_PATT3_ATTWAIT3_7               (0x00008000)        /*!<Bit 7 */

#define  FMC_PATT3_ATTHOLD3                 (0x00FF0000)        /*!<ATTHOLD3[7:0] bits (Attribute memory 3 hold time) */
#define  FMC_PATT3_ATTHOLD3_0               (0x00010000)        /*!<Bit 0 */
#define  FMC_PATT3_ATTHOLD3_1               (0x00020000)        /*!<Bit 1 */
#define  FMC_PATT3_ATTHOLD3_2               (0x00040000)        /*!<Bit 2 */
#define  FMC_PATT3_ATTHOLD3_3               (0x00080000)        /*!<Bit 3 */
#define  FMC_PATT3_ATTHOLD3_4               (0x00100000)        /*!<Bit 4 */
#define  FMC_PATT3_ATTHOLD3_5               (0x00200000)        /*!<Bit 5 */
#define  FMC_PATT3_ATTHOLD3_6               (0x00400000)        /*!<Bit 6 */
#define  FMC_PATT3_ATTHOLD3_7               (0x00800000)        /*!<Bit 7 */

#define  FMC_PATT3_ATTHIZ3                  (0xFF000000)        /*!<ATTHIZ3[7:0] bits (Attribute memory 3 databus HiZ time) */
#define  FMC_PATT3_ATTHIZ3_0                (0x01000000)        /*!<Bit 0 */
#define  FMC_PATT3_ATTHIZ3_1                (0x02000000)        /*!<Bit 1 */
#define  FMC_PATT3_ATTHIZ3_2                (0x04000000)        /*!<Bit 2 */
#define  FMC_PATT3_ATTHIZ3_3                (0x08000000)        /*!<Bit 3 */
#define  FMC_PATT3_ATTHIZ3_4                (0x10000000)        /*!<Bit 4 */
#define  FMC_PATT3_ATTHIZ3_5                (0x20000000)        /*!<Bit 5 */
#define  FMC_PATT3_ATTHIZ3_6                (0x40000000)        /*!<Bit 6 */
#define  FMC_PATT3_ATTHIZ3_7                (0x80000000)        /*!<Bit 7 */

#define  FMC_PATT4_ATTSET4                  (0x000000FF)        /*!<ATTSET4[7:0] bits (Attribute memory 4 setup time) */
#define  FMC_PATT4_ATTSET4_0                (0x00000001)        /*!<Bit 0 */
#define  FMC_PATT4_ATTSET4_1                (0x00000002)        /*!<Bit 1 */
#define  FMC_PATT4_ATTSET4_2                (0x00000004)        /*!<Bit 2 */
#define  FMC_PATT4_ATTSET4_3                (0x00000008)        /*!<Bit 3 */
#define  FMC_PATT4_ATTSET4_4                (0x00000010)        /*!<Bit 4 */
#define  FMC_PATT4_ATTSET4_5                (0x00000020)        /*!<Bit 5 */
#define  FMC_PATT4_ATTSET4_6                (0x00000040)        /*!<Bit 6 */
#define  FMC_PATT4_ATTSET4_7                (0x00000080)        /*!<Bit 7 */

#define  FMC_PATT4_ATTWAIT4                 (0x0000FF00)        /*!<ATTWAIT4[7:0] bits (Attribute memory 4 wait time) */
#define  FMC_PATT4_ATTWAIT4_0               (0x00000100)        /*!<Bit 0 */
#define  FMC_PATT4_ATTWAIT4_1               (0x00000200)        /*!<Bit 1 */
#define  FMC_PATT4_ATTWAIT4_2               (0x00000400)        /*!<Bit 2 */
#define  FMC_PATT4_ATTWAIT4_3               (0x00000800)        /*!<Bit 3 */
#define  FMC_PATT4_ATTWAIT4_4               (0x00001000)        /*!<Bit 4 */
#define  FMC_PATT4_ATTWAIT4_5               (0x00002000)        /*!<Bit 5 */
#define  FMC_PATT4_ATTWAIT4_6               (0x00004000)        /*!<Bit 6 */
#define  FMC_PATT4_ATTWAIT4_7               (0x00008000)        /*!<Bit 7 */

#define  FMC_PATT4_ATTHOLD4                 (0x00FF0000)        /*!<ATTHOLD4[7:0] bits (Attribute memory 4 hold time) */
#define  FMC_PATT4_ATTHOLD4_0               (0x00010000)        /*!<Bit 0 */
#define  FMC_PATT4_ATTHOLD4_1               (0x00020000)        /*!<Bit 1 */
#define  FMC_PATT4_ATTHOLD4_2               (0x00040000)        /*!<Bit 2 */
#define  FMC_PATT4_ATTHOLD4_3               (0x00080000)        /*!<Bit 3 */
#define  FMC_PATT4_ATTHOLD4_4               (0x00100000)        /*!<Bit 4 */
#define  FMC_PATT4_ATTHOLD4_5               (0x00200000)        /*!<Bit 5 */
#define  FMC_PATT4_ATTHOLD4_6               (0x00400000)        /*!<Bit 6 */
#define  FMC_PATT4_ATTHOLD4_7               (0x00800000)        /*!<Bit 7 */

#define  FMC_PATT4_ATTHIZ4                  (0xFF000000)        /*!<ATTHIZ4[7:0] bits (Attribute memory 4 databus HiZ time) */
#define  FMC_PATT4_ATTHIZ4_0                (0x01000000)        /*!<Bit 0 */
#define  FMC_PATT4_ATTHIZ4_1                (0x02000000)        /*!<Bit 1 */
#define  FMC_PATT4_ATTHIZ4_2                (0x04000000)        /*!<Bit 2 */
#define  FMC_PATT4_ATTHIZ4_3                (0x08000000)        /*!<Bit 3 */
#define  FMC_PATT4_ATTHIZ4_4                (0x10000000)        /*!<Bit 4 */
#define  FMC_PATT4_ATTHIZ4_5                (0x20000000)        /*!<Bit 5 */
#define  FMC_PATT4_ATTHIZ4_6                (0x40000000)        /*!<Bit 6 */
#define  FMC_PATT4_ATTHIZ4_7                (0x80000000)        /*!<Bit 7 */

#define  FMC_PIO4_IOSET4                    (0x000000FF)        /*!<IOSET4[7:0] bits (I/O 4 setup time) */
#define  FMC_PIO4_IOSET4_0                  (0x00000001)        /*!<Bit 0 */
#define  FMC_PIO4_IOSET4_1                  (0x00000002)        /*!<Bit 1 */
#define  FMC_PIO4_IOSET4_2                  (0x00000004)        /*!<Bit 2 */
#define  FMC_PIO4_IOSET4_3                  (0x00000008)        /*!<Bit 3 */
#define  FMC_PIO4_IOSET4_4                  (0x00000010)        /*!<Bit 4 */
#define  FMC_PIO4_IOSET4_5                  (0x00000020)        /*!<Bit 5 */
#define  FMC_PIO4_IOSET4_6                  (0x00000040)        /*!<Bit 6 */
#define  FMC_PIO4_IOSET4_7                  (0x00000080)        /*!<Bit 7 */

#define  FMC_PIO4_IOWAIT4                   (0x0000FF00)        /*!<IOWAIT4[7:0] bits (I/O 4 wait time) */
#define  FMC_PIO4_IOWAIT4_0                 (0x00000100)        /*!<Bit 0 */
#define  FMC_PIO4_IOWAIT4_1                 (0x00000200)        /*!<Bit 1 */
#define  FMC_PIO4_IOWAIT4_2                 (0x00000400)        /*!<Bit 2 */
#define  FMC_PIO4_IOWAIT4_3                 (0x00000800)        /*!<Bit 3 */
#define  FMC_PIO4_IOWAIT4_4                 (0x00001000)        /*!<Bit 4 */
#define  FMC_PIO4_IOWAIT4_5                 (0x00002000)        /*!<Bit 5 */
#define  FMC_PIO4_IOWAIT4_6                 (0x00004000)        /*!<Bit 6 */
#define  FMC_PIO4_IOWAIT4_7                 (0x00008000)        /*!<Bit 7 */

#define  FMC_PIO4_IOHOLD4                   (0x00FF0000)        /*!<IOHOLD4[7:0] bits (I/O 4 hold time) */
#define  FMC_PIO4_IOHOLD4_0                 (0x00010000)        /*!<Bit 0 */
#define  FMC_PIO4_IOHOLD4_1                 (0x00020000)        /*!<Bit 1 */
#define  FMC_PIO4_IOHOLD4_2                 (0x00040000)        /*!<Bit 2 */
#define  FMC_PIO4_IOHOLD4_3                 (0x00080000)        /*!<Bit 3 */
#define  FMC_PIO4_IOHOLD4_4                 (0x00100000)        /*!<Bit 4 */
#define  FMC_PIO4_IOHOLD4_5                 (0x00200000)        /*!<Bit 5 */
#define  FMC_PIO4_IOHOLD4_6                 (0x00400000)        /*!<Bit 6 */
#define  FMC_PIO4_IOHOLD4_7                 (0x00800000)        /*!<Bit 7 */

#define  FMC_PIO4_IOHIZ4                    (0xFF000000)        /*!<IOHIZ4[7:0] bits (I/O 4 databus HiZ time) */
#define  FMC_PIO4_IOHIZ4_0                  (0x01000000)        /*!<Bit 0 */
#define  FMC_PIO4_IOHIZ4_1                  (0x02000000)        /*!<Bit 1 */
#define  FMC_PIO4_IOHIZ4_2                  (0x04000000)        /*!<Bit 2 */
#define  FMC_PIO4_IOHIZ4_3                  (0x08000000)        /*!<Bit 3 */
#define  FMC_PIO4_IOHIZ4_4                  (0x10000000)        /*!<Bit 4 */
#define  FMC_PIO4_IOHIZ4_5                  (0x20000000)        /*!<Bit 5 */
#define  FMC_PIO4_IOHIZ4_6                  (0x40000000)        /*!<Bit 6 */
#define  FMC_PIO4_IOHIZ4_7                  (0x80000000)        /*!<Bit 7 */

#define  FMC_ECCR2_ECC2                     (0xFFFFFFFF)        /*!<ECC result */

#define  FMC_ECCR3_ECC3                     (0xFFFFFFFF)        /*!<ECC result */

#define  FMC_SDCR1_NC                       (0x00000003)        /*!<NC[1:0] bits (Number of column bits) */
#define  FMC_SDCR1_NC_0                     (0x00000001)        /*!<Bit 0 */
#define  FMC_SDCR1_NC_1                     (0x00000002)        /*!<Bit 1 */

#define  FMC_SDCR1_NR                       (0x0000000C)        /*!<NR[1:0] bits (Number of row bits) */
#define  FMC_SDCR1_NR_0                     (0x00000004)        /*!<Bit 0 */
#define  FMC_SDCR1_NR_1                     (0x00000008)        /*!<Bit 1 */

#define  FMC_SDCR1_MWID                     (0x00000030)        /*!<NR[1:0] bits (Number of row bits) */
#define  FMC_SDCR1_MWID_0                   (0x00000010)        /*!<Bit 0 */
#define  FMC_SDCR1_MWID_1                   (0x00000020)        /*!<Bit 1 */

#define  FMC_SDCR1_NB                       (0x00000040)        /*!<Number of internal bank */

#define  FMC_SDCR1_CAS                      (0x00000180)        /*!<CAS[1:0] bits (CAS latency) */
#define  FMC_SDCR1_CAS_0                    (0x00000080)        /*!<Bit 0 */
#define  FMC_SDCR1_CAS_1                    (0x00000100)        /*!<Bit 1 */

#define  FMC_SDCR1_WP                       (0x00000200)        /*!<Write protection */

#define  FMC_SDCR1_SDCLK                    (0x00000C00)        /*!<SDRAM clock configuration */
#define  FMC_SDCR1_SDCLK_0                  (0x00000400)        /*!<Bit 0 */
#define  FMC_SDCR1_SDCLK_1                  (0x00000800)        /*!<Bit 1 */

#define  FMC_SDCR1_RBURST                   (0x00001000)        /*!<Read burst */

#define  FMC_SDCR1_RPIPE                    (0x00006000)        /*!<Write protection */
#define  FMC_SDCR1_RPIPE_0                  (0x00002000)        /*!<Bit 0 */
#define  FMC_SDCR1_RPIPE_1                  (0x00004000)        /*!<Bit 1 */

#define  FMC_SDCR2_NC                       (0x00000003)        /*!<NC[1:0] bits (Number of column bits) */
#define  FMC_SDCR2_NC_0                     (0x00000001)        /*!<Bit 0 */
#define  FMC_SDCR2_NC_1                     (0x00000002)        /*!<Bit 1 */

#define  FMC_SDCR2_NR                       (0x0000000C)        /*!<NR[1:0] bits (Number of row bits) */
#define  FMC_SDCR2_NR_0                     (0x00000004)        /*!<Bit 0 */
#define  FMC_SDCR2_NR_1                     (0x00000008)        /*!<Bit 1 */

#define  FMC_SDCR2_MWID                     (0x00000030)        /*!<NR[1:0] bits (Number of row bits) */
#define  FMC_SDCR2_MWID_0                   (0x00000010)        /*!<Bit 0 */
#define  FMC_SDCR2_MWID_1                   (0x00000020)        /*!<Bit 1 */

#define  FMC_SDCR2_NB                       (0x00000040)        /*!<Number of internal bank */

#define  FMC_SDCR2_CAS                      (0x00000180)        /*!<CAS[1:0] bits (CAS latency) */
#define  FMC_SDCR2_CAS_0                    (0x00000080)        /*!<Bit 0 */
#define  FMC_SDCR2_CAS_1                    (0x00000100)        /*!<Bit 1 */

#define  FMC_SDCR2_WP                       (0x00000200)        /*!<Write protection */

#define  FMC_SDCR2_SDCLK                    (0x00000C00)        /*!<SDCLK[1:0] (SDRAM clock configuration) */
#define  FMC_SDCR2_SDCLK_0                  (0x00000400)        /*!<Bit 0 */
#define  FMC_SDCR2_SDCLK_1                  (0x00000800)        /*!<Bit 1 */

#define  FMC_SDCR2_RBURST                   (0x00001000)        /*!<Read burst */

#define  FMC_SDCR2_RPIPE                    (0x00006000)        /*!<RPIPE[1:0](Read pipe) */
#define  FMC_SDCR2_RPIPE_0                  (0x00002000)        /*!<Bit 0 */
#define  FMC_SDCR2_RPIPE_1                  (0x00004000)        /*!<Bit 1 */

#define  FMC_SDTR1_TMRD                     (0x0000000F)        /*!<TMRD[3:0] bits (Load mode register to active) */
#define  FMC_SDTR1_TMRD_0                   (0x00000001)        /*!<Bit 0 */
#define  FMC_SDTR1_TMRD_1                   (0x00000002)        /*!<Bit 1 */
#define  FMC_SDTR1_TMRD_2                   (0x00000004)        /*!<Bit 2 */
#define  FMC_SDTR1_TMRD_3                   (0x00000008)        /*!<Bit 3 */

#define  FMC_SDTR1_TXSR                     (0x000000F0)        /*!<TXSR[3:0] bits (Exit self refresh) */
#define  FMC_SDTR1_TXSR_0                   (0x00000010)        /*!<Bit 0 */
#define  FMC_SDTR1_TXSR_1                   (0x00000020)        /*!<Bit 1 */
#define  FMC_SDTR1_TXSR_2                   (0x00000040)        /*!<Bit 2 */
#define  FMC_SDTR1_TXSR_3                   (0x00000080)        /*!<Bit 3 */

#define  FMC_SDTR1_TRAS                     (0x00000F00)        /*!<TRAS[3:0] bits (Self refresh time) */
#define  FMC_SDTR1_TRAS_0                   (0x00000100)        /*!<Bit 0 */
#define  FMC_SDTR1_TRAS_1                   (0x00000200)        /*!<Bit 1 */
#define  FMC_SDTR1_TRAS_2                   (0x00000400)        /*!<Bit 2 */
#define  FMC_SDTR1_TRAS_3                   (0x00000800)        /*!<Bit 3 */

#define  FMC_SDTR1_TRC                      (0x0000F000)        /*!<TRC[2:0] bits (Row cycle delay) */
#define  FMC_SDTR1_TRC_0                    (0x00001000)        /*!<Bit 0 */
#define  FMC_SDTR1_TRC_1                    (0x00002000)        /*!<Bit 1 */
#define  FMC_SDTR1_TRC_2                    (0x00004000)        /*!<Bit 2 */

#define  FMC_SDTR1_TWR                      (0x000F0000)        /*!<TRC[2:0] bits (Write recovery delay) */
#define  FMC_SDTR1_TWR_0                    (0x00010000)        /*!<Bit 0 */
#define  FMC_SDTR1_TWR_1                    (0x00020000)        /*!<Bit 1 */
#define  FMC_SDTR1_TWR_2                    (0x00040000)        /*!<Bit 2 */

#define  FMC_SDTR1_TRP                      (0x00F00000)        /*!<TRP[2:0] bits (Row precharge delay) */
#define  FMC_SDTR1_TRP_0                    (0x00100000)        /*!<Bit 0 */
#define  FMC_SDTR1_TRP_1                    (0x00200000)        /*!<Bit 1 */
#define  FMC_SDTR1_TRP_2                    (0x00400000)        /*!<Bit 2 */

#define  FMC_SDTR1_TRCD                     (0x0F000000)        /*!<TRP[2:0] bits (Row to column delay) */
#define  FMC_SDTR1_TRCD_0                   (0x01000000)        /*!<Bit 0 */
#define  FMC_SDTR1_TRCD_1                   (0x02000000)        /*!<Bit 1 */
#define  FMC_SDTR1_TRCD_2                   (0x04000000)        /*!<Bit 2 */

#define  FMC_SDTR2_TMRD                     (0x0000000F)        /*!<TMRD[3:0] bits (Load mode register to active) */
#define  FMC_SDTR2_TMRD_0                   (0x00000001)        /*!<Bit 0 */
#define  FMC_SDTR2_TMRD_1                   (0x00000002)        /*!<Bit 1 */
#define  FMC_SDTR2_TMRD_2                   (0x00000004)        /*!<Bit 2 */
#define  FMC_SDTR2_TMRD_3                   (0x00000008)        /*!<Bit 3 */

#define  FMC_SDTR2_TXSR                     (0x000000F0)        /*!<TXSR[3:0] bits (Exit self refresh) */
#define  FMC_SDTR2_TXSR_0                   (0x00000010)        /*!<Bit 0 */
#define  FMC_SDTR2_TXSR_1                   (0x00000020)        /*!<Bit 1 */
#define  FMC_SDTR2_TXSR_2                   (0x00000040)        /*!<Bit 2 */
#define  FMC_SDTR2_TXSR_3                   (0x00000080)        /*!<Bit 3 */

#define  FMC_SDTR2_TRAS                     (0x00000F00)        /*!<TRAS[3:0] bits (Self refresh time) */
#define  FMC_SDTR2_TRAS_0                   (0x00000100)        /*!<Bit 0 */
#define  FMC_SDTR2_TRAS_1                   (0x00000200)        /*!<Bit 1 */
#define  FMC_SDTR2_TRAS_2                   (0x00000400)        /*!<Bit 2 */
#define  FMC_SDTR2_TRAS_3                   (0x00000800)        /*!<Bit 3 */

#define  FMC_SDTR2_TRC                      (0x0000F000)        /*!<TRC[2:0] bits (Row cycle delay) */
#define  FMC_SDTR2_TRC_0                    (0x00001000)        /*!<Bit 0 */
#define  FMC_SDTR2_TRC_1                    (0x00002000)        /*!<Bit 1 */
#define  FMC_SDTR2_TRC_2                    (0x00004000)        /*!<Bit 2 */

#define  FMC_SDTR2_TWR                      (0x000F0000)        /*!<TRC[2:0] bits (Write recovery delay) */
#define  FMC_SDTR2_TWR_0                    (0x00010000)        /*!<Bit 0 */
#define  FMC_SDTR2_TWR_1                    (0x00020000)        /*!<Bit 1 */
#define  FMC_SDTR2_TWR_2                    (0x00040000)        /*!<Bit 2 */

#define  FMC_SDTR2_TRP                      (0x00F00000)        /*!<TRP[2:0] bits (Row precharge delay) */
#define  FMC_SDTR2_TRP_0                    (0x00100000)        /*!<Bit 0 */
#define  FMC_SDTR2_TRP_1                    (0x00200000)        /*!<Bit 1 */
#define  FMC_SDTR2_TRP_2                    (0x00400000)        /*!<Bit 2 */

#define  FMC_SDTR2_TRCD                     (0x0F000000)        /*!<TRP[2:0] bits (Row to column delay) */
#define  FMC_SDTR2_TRCD_0                   (0x01000000)        /*!<Bit 0 */
#define  FMC_SDTR2_TRCD_1                   (0x02000000)        /*!<Bit 1 */
#define  FMC_SDTR2_TRCD_2                   (0x04000000)        /*!<Bit 2 */

#define  FMC_SDCMR_MODE                     (0x00000007)        /*!<MODE[2:0] bits (Command mode) */
#define  FMC_SDCMR_MODE_0                   (0x00000001)        /*!<Bit 0 */
#define  FMC_SDCMR_MODE_1                   (0x00000002)        /*!<Bit 1 */
#define  FMC_SDCMR_MODE_2                   (0x00000003)        /*!<Bit 2 */

#define  FMC_SDCMR_CTB2                     (0x00000008)        /*!<Command target 2 */

#define  FMC_SDCMR_CTB1                     (0x00000010)        /*!<Command target 1 */

#define  FMC_SDCMR_NRFS                     (0x000001E0)        /*!<NRFS[3:0] bits (Number of auto-refresh) */
#define  FMC_SDCMR_NRFS_0                   (0x00000020)        /*!<Bit 0 */
#define  FMC_SDCMR_NRFS_1                   (0x00000040)        /*!<Bit 1 */
#define  FMC_SDCMR_NRFS_2                   (0x00000080)        /*!<Bit 2 */
#define  FMC_SDCMR_NRFS_3                   (0x00000100)        /*!<Bit 3 */

#define  FMC_SDCMR_MRD                      (0x003FFE00)        /*!<MRD[12:0] bits (Mode register definition) */

#define  FMC_SDRTR_CRE                      (0x00000001)        /*!<Clear refresh error flag */

#define  FMC_SDRTR_COUNT                    (0x00003FFE)        /*!<COUNT[12:0] bits (Refresh timer count) */

#define  FMC_SDRTR_REIE                     (0x00004000)        /*!<RES interrupt enable */

#define  FMC_SDSR_RE                        (0x00000001)        /*!<Refresh error flag */

#define  FMC_SDSR_MODES1                    (0x00000006)        /*!<MODES1[1:0]bits (Status mode for bank 1) */
#define  FMC_SDSR_MODES1_0                  (0x00000002)        /*!<Bit 0 */
#define  FMC_SDSR_MODES1_1                  (0x00000004)        /*!<Bit 1 */

#define  FMC_SDSR_MODES2                    (0x00000018)        /*!<MODES2[1:0]bits (Status mode for bank 2) */
#define  FMC_SDSR_MODES2_0                  (0x00000008)        /*!<Bit 0 */
#define  FMC_SDSR_MODES2_1                  (0x00000010)        /*!<Bit 1 */
#define  FMC_SDSR_BUSY                      (0x00000020)        /*!<Busy status */

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


#define GPIO_OSPEEDER_OSPEEDR0     (0x00000003)
#define GPIO_OSPEEDER_OSPEEDR0_0   (0x00000001)
#define GPIO_OSPEEDER_OSPEEDR0_1   (0x00000002)
#define GPIO_OSPEEDER_OSPEEDR1     (0x0000000C)
#define GPIO_OSPEEDER_OSPEEDR1_0   (0x00000004)
#define GPIO_OSPEEDER_OSPEEDR1_1   (0x00000008)
#define GPIO_OSPEEDER_OSPEEDR2     (0x00000030)
#define GPIO_OSPEEDER_OSPEEDR2_0   (0x00000010)
#define GPIO_OSPEEDER_OSPEEDR2_1   (0x00000020)
#define GPIO_OSPEEDER_OSPEEDR3     (0x000000C0)
#define GPIO_OSPEEDER_OSPEEDR3_0   (0x00000040)
#define GPIO_OSPEEDER_OSPEEDR3_1   (0x00000080)
#define GPIO_OSPEEDER_OSPEEDR4     (0x00000300)
#define GPIO_OSPEEDER_OSPEEDR4_0   (0x00000100)
#define GPIO_OSPEEDER_OSPEEDR4_1   (0x00000200)
#define GPIO_OSPEEDER_OSPEEDR5     (0x00000C00)
#define GPIO_OSPEEDER_OSPEEDR5_0   (0x00000400)
#define GPIO_OSPEEDER_OSPEEDR5_1   (0x00000800)
#define GPIO_OSPEEDER_OSPEEDR6     (0x00003000)
#define GPIO_OSPEEDER_OSPEEDR6_0   (0x00001000)
#define GPIO_OSPEEDER_OSPEEDR6_1   (0x00002000)
#define GPIO_OSPEEDER_OSPEEDR7     (0x0000C000)
#define GPIO_OSPEEDER_OSPEEDR7_0   (0x00004000)
#define GPIO_OSPEEDER_OSPEEDR7_1   (0x00008000)
#define GPIO_OSPEEDER_OSPEEDR8     (0x00030000)
#define GPIO_OSPEEDER_OSPEEDR8_0   (0x00010000)
#define GPIO_OSPEEDER_OSPEEDR8_1   (0x00020000)
#define GPIO_OSPEEDER_OSPEEDR9     (0x000C0000)
#define GPIO_OSPEEDER_OSPEEDR9_0   (0x00040000)
#define GPIO_OSPEEDER_OSPEEDR9_1   (0x00080000)
#define GPIO_OSPEEDER_OSPEEDR10    (0x00300000)
#define GPIO_OSPEEDER_OSPEEDR10_0  (0x00100000)
#define GPIO_OSPEEDER_OSPEEDR10_1  (0x00200000)
#define GPIO_OSPEEDER_OSPEEDR11    (0x00C00000)
#define GPIO_OSPEEDER_OSPEEDR11_0  (0x00400000)
#define GPIO_OSPEEDER_OSPEEDR11_1  (0x00800000)
#define GPIO_OSPEEDER_OSPEEDR12    (0x03000000)
#define GPIO_OSPEEDER_OSPEEDR12_0  (0x01000000)
#define GPIO_OSPEEDER_OSPEEDR12_1  (0x02000000)
#define GPIO_OSPEEDER_OSPEEDR13    (0x0C000000)
#define GPIO_OSPEEDER_OSPEEDR13_0  (0x04000000)
#define GPIO_OSPEEDER_OSPEEDR13_1  (0x08000000)
#define GPIO_OSPEEDER_OSPEEDR14    (0x30000000)
#define GPIO_OSPEEDER_OSPEEDR14_0  (0x10000000)
#define GPIO_OSPEEDER_OSPEEDR14_1  (0x20000000)
#define GPIO_OSPEEDER_OSPEEDR15    (0xC0000000)
#define GPIO_OSPEEDER_OSPEEDR15_0  (0x40000000)
#define GPIO_OSPEEDER_OSPEEDR15_1  (0x80000000)                       

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

#define GPIO_AFRL_AFRL0            (0x0000000F)
#define GPIO_AFRL_AFRL1            (0x000000F0)
#define GPIO_AFRL_AFRL2            (0x00000F00)
#define GPIO_AFRL_AFRL3            (0x0000F000)
#define GPIO_AFRL_AFRL4            (0x000F0000)
#define GPIO_AFRL_AFRL5            (0x00F00000)
#define GPIO_AFRL_AFRL6            (0x0F000000)
#define GPIO_AFRL_AFRL7            (0xF0000000)

#define GPIO_AFRH_AFRH0            (0x0000000F)
#define GPIO_AFRH_AFRH1            (0x000000F0)
#define GPIO_AFRH_AFRH2            (0x00000F00)
#define GPIO_AFRH_AFRH3            (0x0000F000)
#define GPIO_AFRH_AFRH4            (0x000F0000)
#define GPIO_AFRH_AFRH5            (0x00F00000)
#define GPIO_AFRH_AFRH6            (0x0F000000)
#define GPIO_AFRH_AFRH7            (0xF0000000)

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

#define  I2C_PECR_PEC                        (0x000000FF)        /*!< PEC register */

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

#define  IWDG_WINR_WIN                       (0x0FFF)            /*!< Watchdog counter window value */

#define  PWR_CR_LPSDSR                       (0x0001)     /*!< Low-power deepsleep/sleep/low power run */
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

#define  PWR_CSR_WUF                         (0x0001)     /*!< Wakeup Flag */
#define  PWR_CSR_SBF                         (0x0002)     /*!< Standby Flag */
#define  PWR_CSR_PVDO                        (0x0004)     /*!< PVD Output */
#define  PWR_CSR_VREFINTRDYF                 (0x0008)     /*!< Internal voltage reference (VREFINT) ready flag */

#define  PWR_CSR_EWUP1                       (0x0100)     /*!< Enable WKUP pin 1 */
#define  PWR_CSR_EWUP2                       (0x0200)     /*!< Enable WKUP pin 2 */
#define  PWR_CSR_EWUP3                       (0x0400)     /*!< Enable WKUP pin 3 */

#define  RCC_CR_HSION                        (0x00000001)
#define  RCC_CR_HSIRDY                       (0x00000002)

#define  RCC_CR_HSITRIM                      (0x000000F8)
#define  RCC_CR_HSITRIM_0                    (0x00000008)/*!<Bit 0 */
#define  RCC_CR_HSITRIM_1                    (0x00000010)/*!<Bit 1 */
#define  RCC_CR_HSITRIM_2                    (0x00000020)/*!<Bit 2 */
#define  RCC_CR_HSITRIM_3                    (0x00000040)/*!<Bit 3 */
#define  RCC_CR_HSITRIM_4                    (0x00000080)/*!<Bit 4 */

#define  RCC_CR_HSICAL                       (0x0000FF00)
#define  RCC_CR_HSICAL_0                     (0x00000100)/*!<Bit 0 */
#define  RCC_CR_HSICAL_1                     (0x00000200)/*!<Bit 1 */
#define  RCC_CR_HSICAL_2                     (0x00000400)/*!<Bit 2 */
#define  RCC_CR_HSICAL_3                     (0x00000800)/*!<Bit 3 */
#define  RCC_CR_HSICAL_4                     (0x00001000)/*!<Bit 4 */
#define  RCC_CR_HSICAL_5                     (0x00002000)/*!<Bit 5 */
#define  RCC_CR_HSICAL_6                     (0x00004000)/*!<Bit 6 */
#define  RCC_CR_HSICAL_7                     (0x00008000)/*!<Bit 7 */

#define  RCC_CR_HSEON                        (0x00010000)
#define  RCC_CR_HSERDY                       (0x00020000)
#define  RCC_CR_HSEBYP                       (0x00040000)
#define  RCC_CR_CSSON                        (0x00080000)

#define  RCC_CR_PLLON                        (0x01000000)
#define  RCC_CR_PLLRDY                       (0x02000000)

#define  RCC_CFGR_SW                         (0x00000003)        /*!< SW[1:0] bits (System clock Switch) */
#define  RCC_CFGR_SW_0                       (0x00000001)        /*!< Bit 0 */
#define  RCC_CFGR_SW_1                       (0x00000002)        /*!< Bit 1 */

#define  RCC_CFGR_SW_HSI                     (0x00000000)        /*!< HSI selected as system clock */
#define  RCC_CFGR_SW_HSE                     (0x00000001)        /*!< HSE selected as system clock */
#define  RCC_CFGR_SW_PLL                     (0x00000002)        /*!< PLL selected as system clock */

#define  RCC_CFGR_SWS                        (0x0000000C)        /*!< SWS[1:0] bits (System Clock Switch Status) */
#define  RCC_CFGR_SWS_0                      (0x00000004)        /*!< Bit 0 */
#define  RCC_CFGR_SWS_1                      (0x00000008)        /*!< Bit 1 */

#define  RCC_CFGR_SWS_HSI                    (0x00000000)        /*!< HSI oscillator used as system clock */
#define  RCC_CFGR_SWS_HSE                    (0x00000004)        /*!< HSE oscillator used as system clock */
#define  RCC_CFGR_SWS_PLL                    (0x00000008)        /*!< PLL used as system clock */

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

#define  RCC_CFGR_PPRE1                      (0x00000700)        /*!< PRE1[2:0] bits (APB1 prescaler) */
#define  RCC_CFGR_PPRE1_0                    (0x00000100)        /*!< Bit 0 */
#define  RCC_CFGR_PPRE1_1                    (0x00000200)        /*!< Bit 1 */
#define  RCC_CFGR_PPRE1_2                    (0x00000400)        /*!< Bit 2 */

#define  RCC_CFGR_PPRE1_DIV1                 (0x00000000)        /*!< HCLK not divided */
#define  RCC_CFGR_PPRE1_DIV2                 (0x00000400)        /*!< HCLK divided by 2 */
#define  RCC_CFGR_PPRE1_DIV4                 (0x00000500)        /*!< HCLK divided by 4 */
#define  RCC_CFGR_PPRE1_DIV8                 (0x00000600)        /*!< HCLK divided by 8 */
#define  RCC_CFGR_PPRE1_DIV16                (0x00000700)        /*!< HCLK divided by 16 */

#define  RCC_CFGR_PPRE2                      (0x00003800)        /*!< PRE2[2:0] bits (APB2 prescaler) */
#define  RCC_CFGR_PPRE2_0                    (0x00000800)        /*!< Bit 0 */
#define  RCC_CFGR_PPRE2_1                    (0x00001000)        /*!< Bit 1 */
#define  RCC_CFGR_PPRE2_2                    (0x00002000)        /*!< Bit 2 */

#define  RCC_CFGR_PPRE2_DIV1                 (0x00000000)        /*!< HCLK not divided */
#define  RCC_CFGR_PPRE2_DIV2                 (0x00002000)        /*!< HCLK divided by 2 */
#define  RCC_CFGR_PPRE2_DIV4                 (0x00002800)        /*!< HCLK divided by 4 */
#define  RCC_CFGR_PPRE2_DIV8                 (0x00003000)        /*!< HCLK divided by 8 */
#define  RCC_CFGR_PPRE2_DIV16                (0x00003800)        /*!< HCLK divided by 16 */

#define  RCC_CFGR_PLLSRC                     (0x00010000)        /*!< PLL entry clock source */

#define  RCC_CFGR_PLLXTPRE                   (0x00020000)        /*!< HSE divider for PLL entry */

#define  RCC_CFGR_PLLMULL                    (0x003C0000)        /*!< PLLMUL[3:0] bits (PLL multiplication factor) */
#define  RCC_CFGR_PLLMULL_0                  (0x00040000)        /*!< Bit 0 */
#define  RCC_CFGR_PLLMULL_1                  (0x00080000)        /*!< Bit 1 */
#define  RCC_CFGR_PLLMULL_2                  (0x00100000)        /*!< Bit 2 */
#define  RCC_CFGR_PLLMULL_3                  (0x00200000)        /*!< Bit 3 */

#define  RCC_CFGR_PLLSRC_HSI_Div2            (0x00000000)        /*!< HSI clock divided by 2 selected as PLL entry clock source */
#define  RCC_CFGR_PLLSRC_HSI_PREDIV          (0x00008000)        /*!< HSI PREDIV clock selected as PLL entry clock source 
                                                                                (This bit and configuration is only available for STM32F303xE devices)*/

#define  RCC_CFGR_PLLSRC_PREDIV1             (0x00010000)        /*!< PREDIV1 clock selected as PLL entry clock source */

#define  RCC_CFGR_PLLXTPRE_PREDIV1           (0x00000000)        /*!< PREDIV1 clock not divided for PLL entry */
#define  RCC_CFGR_PLLXTPRE_PREDIV1_Div2      (0x00020000)        /*!< PREDIV1 clock divided by 2 for PLL entry */

#define  RCC_CFGR_PLLMULL2                   (0x00000000)        /*!< PLL input clock*2 */
#define  RCC_CFGR_PLLMULL3                   (0x00040000)        /*!< PLL input clock*3 */
#define  RCC_CFGR_PLLMULL4                   (0x00080000)        /*!< PLL input clock*4 */
#define  RCC_CFGR_PLLMULL5                   (0x000C0000)        /*!< PLL input clock*5 */
#define  RCC_CFGR_PLLMULL6                   (0x00100000)        /*!< PLL input clock*6 */
#define  RCC_CFGR_PLLMULL7                   (0x00140000)        /*!< PLL input clock*7 */
#define  RCC_CFGR_PLLMULL8                   (0x00180000)        /*!< PLL input clock*8 */
#define  RCC_CFGR_PLLMULL9                   (0x001C0000)        /*!< PLL input clock*9 */
#define  RCC_CFGR_PLLMULL10                  (0x00200000)        /*!< PLL input clock10 */
#define  RCC_CFGR_PLLMULL11                  (0x00240000)        /*!< PLL input clock*11 */
#define  RCC_CFGR_PLLMULL12                  (0x00280000)        /*!< PLL input clock*12 */
#define  RCC_CFGR_PLLMULL13                  (0x002C0000)        /*!< PLL input clock*13 */
#define  RCC_CFGR_PLLMULL14                  (0x00300000)        /*!< PLL input clock*14 */
#define  RCC_CFGR_PLLMULL15                  (0x00340000)        /*!< PLL input clock*15 */
#define  RCC_CFGR_PLLMULL16                  (0x00380000)        /*!< PLL input clock*16 */

#define  RCC_CFGR_USBPRE                     (0x00400000)        /*!< USB prescaler */

#define  RCC_CFGR_I2SSRC                     (0x00800000)        /*!< I2S external clock source selection */

#define  RCC_CFGR_MCO                        (0x07000000)        /*!< MCO[2:0] bits (Microcontroller Clock Output) */
#define  RCC_CFGR_MCO_0                      (0x01000000)        /*!< Bit 0 */
#define  RCC_CFGR_MCO_1                      (0x02000000)        /*!< Bit 1 */
#define  RCC_CFGR_MCO_2                      (0x04000000)        /*!< Bit 2 */

#define  RCC_CFGR_MCO_NOCLOCK                (0x00000000)        /*!< No clock */
#define  RCC_CFGR_MCO_LSI                    (0x02000000)        /*!< LSI clock selected as MCO source */
#define  RCC_CFGR_MCO_LSE                    (0x03000000)        /*!< LSE clock selected as MCO source */
#define  RCC_CFGR_MCO_SYSCLK                 (0x04000000)        /*!< System clock selected as MCO source */
#define  RCC_CFGR_MCO_HSI                    (0x05000000)        /*!< HSI clock selected as MCO source */
#define  RCC_CFGR_MCO_HSE                    (0x06000000)        /*!< HSE clock selected as MCO source  */
#define  RCC_CFGR_MCO_PLL                    (0x07000000)        /*!< PLL clock divided by 2 selected as MCO source */

#define  RCC_CFGR_MCOF                       (0x10000000)        /*!< Microcontroller Clock Output Flag */

#define  RCC_CFGR_MCO_PRE                    (0x70000000)        /*!< MCO prescaler */
#define  RCC_CFGR_MCO_PRE_1                  (0x00000000)        /*!< MCO is divided by 1 */
#define  RCC_CFGR_MCO_PRE_2                  (0x10000000)        /*!< MCO is divided by 2 */
#define  RCC_CFGR_MCO_PRE_4                  (0x20000000)        /*!< MCO is divided by 4 */
#define  RCC_CFGR_MCO_PRE_8                  (0x30000000)        /*!< MCO is divided by 8 */
#define  RCC_CFGR_MCO_PRE_16                 (0x40000000)        /*!< MCO is divided by 16 */
#define  RCC_CFGR_MCO_PRE_32                 (0x50000000)        /*!< MCO is divided by 32 */
#define  RCC_CFGR_MCO_PRE_64                 (0x60000000)        /*!< MCO is divided by 64 */
#define  RCC_CFGR_MCO_PRE_128                (0x70000000)        /*!< MCO is divided by 128 */

#define  RCC_CFGR_PLLNODIV                   (0x80000000)        /*!< PLL is not divided to MCO */

#define  RCC_CIR_LSIRDYF                     (0x00000001)        /*!< LSI Ready Interrupt flag */
#define  RCC_CIR_LSERDYF                     (0x00000002)        /*!< LSE Ready Interrupt flag */
#define  RCC_CIR_HSIRDYF                     (0x00000004)        /*!< HSI Ready Interrupt flag */
#define  RCC_CIR_HSERDYF                     (0x00000008)        /*!< HSE Ready Interrupt flag */
#define  RCC_CIR_PLLRDYF                     (0x00000010)        /*!< PLL Ready Interrupt flag */
#define  RCC_CIR_CSSF                        (0x00000080)        /*!< Clock Security System Interrupt flag */
#define  RCC_CIR_LSIRDYIE                    (0x00000100)        /*!< LSI Ready Interrupt Enable */
#define  RCC_CIR_LSERDYIE                    (0x00000200)        /*!< LSE Ready Interrupt Enable */
#define  RCC_CIR_HSIRDYIE                    (0x00000400)        /*!< HSI Ready Interrupt Enable */
#define  RCC_CIR_HSERDYIE                    (0x00000800)        /*!< HSE Ready Interrupt Enable */
#define  RCC_CIR_PLLRDYIE                    (0x00001000)        /*!< PLL Ready Interrupt Enable */
#define  RCC_CIR_LSIRDYC                     (0x00010000)        /*!< LSI Ready Interrupt Clear */
#define  RCC_CIR_LSERDYC                     (0x00020000)        /*!< LSE Ready Interrupt Clear */
#define  RCC_CIR_HSIRDYC                     (0x00040000)        /*!< HSI Ready Interrupt Clear */
#define  RCC_CIR_HSERDYC                     (0x00080000)        /*!< HSE Ready Interrupt Clear */
#define  RCC_CIR_PLLRDYC                     (0x00100000)        /*!< PLL Ready Interrupt Clear */
#define  RCC_CIR_CSSC                        (0x00800000)        /*!< Clock Security System Interrupt Clear */

#define  RCC_APB2RSTR_SYSCFGRST              (0x00000001)        /*!< SYSCFG reset */
#define  RCC_APB2RSTR_TIM1RST                (0x00000200)        /*!< TIM1 reset */
#define  RCC_APB2RSTR_SPI1RST                (0x00001000)        /*!< SPI1 reset */
#define  RCC_APB2RSTR_TIM8RST                (0x00002000)        /*!< TIM8 reset */
#define  RCC_APB2RSTR_USART1RST              (0x00004000)        /*!< USART1 reset */
#define  RCC_APB2RSTR_SPI4RST                (0x00008000)        /*!< SPI4 reset */
#define  RCC_APB2RSTR_TIM15RST               (0x00010000)        /*!< TIM15 reset */
#define  RCC_APB2RSTR_TIM16RST               (0x00020000)        /*!< TIM16 reset */
#define  RCC_APB2RSTR_TIM17RST               (0x00040000)        /*!< TIM17 reset */
#define  RCC_APB2RSTR_TIM20RST               (0x00100000)        /*!< TIM20 reset */
#define  RCC_APB2RSTR_HRTIM1RST              (0x20000000)        /*!< HRTIM1 reset */

#define  RCC_APB1RSTR_TIM2RST                (0x00000001)        /*!< Timer 2 reset */
#define  RCC_APB1RSTR_TIM3RST                (0x00000002)        /*!< Timer 3 reset */
#define  RCC_APB1RSTR_TIM4RST                (0x00000004)        /*!< Timer 4 reset */
#define  RCC_APB1RSTR_TIM6RST                (0x00000010)        /*!< Timer 6 reset */
#define  RCC_APB1RSTR_TIM7RST                (0x00000020)        /*!< Timer 7 reset */
#define  RCC_APB1RSTR_WWDGRST                (0x00000800)        /*!< Window Watchdog reset */
#define  RCC_APB1RSTR_SPI2RST                (0x00004000)        /*!< SPI2 reset */
#define  RCC_APB1RSTR_SPI3RST                (0x00008000)        /*!< SPI3 reset */
#define  RCC_APB1RSTR_USART2RST              (0x00020000)        /*!< USART 2 reset */
#define  RCC_APB1RSTR_USART3RST              (0x00040000)        /*!< USART 3 reset */
#define  RCC_APB1RSTR_UART4RST               (0x00080000)        /*!< UART 4 reset */
#define  RCC_APB1RSTR_UART5RST               (0x00100000)        /*!< UART 5 reset */
#define  RCC_APB1RSTR_I2C1RST                (0x00200000)        /*!< I2C 1 reset */
#define  RCC_APB1RSTR_I2C2RST                (0x00400000)        /*!< I2C 2 reset */
#define  RCC_APB1RSTR_USBRST                 (0x00800000)        /*!< USB reset */
#define  RCC_APB1RSTR_CAN1RST                (0x02000000)        /*!< CAN reset */
#define  RCC_APB1RSTR_PWRRST                 (0x10000000)        /*!< PWR reset */
#define  RCC_APB1RSTR_DAC1RST                (0x20000000)        /*!< DAC 1 reset */
#define  RCC_APB1RSTR_I2C3RST                (0x40000000)        /*!< I2C 3 reset */
#define  RCC_APB1RSTR_DAC2RST                (0x04000000)        /*!< DAC 2 reset */
#define  RCC_APB1RSTR_DACRST                 RCC_APB1RSTR_DAC1RST          /*!< DAC reset */

#define  RCC_AHBENR_DMA1EN                   (0x00000001)        /*!< DMA1 clock enable */
#define  RCC_AHBENR_DMA2EN                   (0x00000002)        /*!< DMA2 clock enable */
#define  RCC_AHBENR_SRAMEN                   (0x00000004)        /*!< SRAM interface clock enable */
#define  RCC_AHBENR_FLITFEN                  (0x00000010)        /*!< FLITF clock enable */
#define  RCC_AHBENR_FMCEN                    (0x00000020)        /*!< FMC clock enable */
#define  RCC_AHBENR_CRCEN                    (0x00000040)        /*!< CRC clock enable */
#define  RCC_AHBENR_GPIOHEN                  (0x00010000)        /*!< GPIOH clock enable */
#define  RCC_AHBENR_GPIOAEN                  (0x00020000)        /*!< GPIOA clock enable */
#define  RCC_AHBENR_GPIOBEN                  (0x00040000)        /*!< GPIOB clock enable */
#define  RCC_AHBENR_GPIOCEN                  (0x00080000)        /*!< GPIOC clock enable */
#define  RCC_AHBENR_GPIODEN                  (0x00100000)        /*!< GPIOD clock enable */
#define  RCC_AHBENR_GPIOEEN                  (0x00200000)        /*!< GPIOE clock enable */
#define  RCC_AHBENR_GPIOFEN                  (0x00400000)        /*!< GPIOF clock enable */
#define  RCC_AHBENR_GPIOGEN                  (0x00800000)        /*!< GPIOG clock enable */
#define  RCC_AHBENR_TSEN                     (0x01000000)        /*!< TS clock enable */
#define  RCC_AHBENR_ADC12EN                  (0x10000000)        /*!< ADC1/ ADC2 clock enable */
#define  RCC_AHBENR_ADC34EN                  (0x20000000)        /*!< ADC1/ ADC2 clock enable */

#define  RCC_APB2ENR_SYSCFGEN                (0x00000001)        /*!< SYSCFG clock enable */
#define  RCC_APB2ENR_TIM1EN                  (0x00000800)        /*!< TIM1 clock enable */
#define  RCC_APB2ENR_SPI1EN                  (0x00001000)        /*!< SPI1 clock enable */
#define  RCC_APB2ENR_TIM8EN                  (0x00002000)        /*!< TIM8 clock enable */ 
#define  RCC_APB2ENR_USART1EN                (0x00004000)        /*!< USART1 clock enable */
#define  RCC_APB2ENR_SPI4EN                  (0x00008000)        /*!< SPI4 clock enable */
#define  RCC_APB2ENR_TIM15EN                 (0x00010000)        /*!< TIM15 clock enable */
#define  RCC_APB2ENR_TIM16EN                 (0x00020000)        /*!< TIM16 clock enable */
#define  RCC_APB2ENR_TIM17EN                 (0x00040000)        /*!< TIM17 clock enable */
#define  RCC_APB2ENR_TIM20EN                 (0x00100000)        /*!< TIM20 clock enable */
#define  RCC_APB2ENR_HRTIM1                  (0x20000000)        /*!< HRTIM1 clock enable */

#define  RCC_APB1ENR_TIM2EN                  (0x00000001)        /*!< Timer 2 clock enable */
#define  RCC_APB1ENR_TIM3EN                  (0x00000002)        /*!< Timer 3 clock enable */
#define  RCC_APB1ENR_TIM4EN                  (0x00000004)        /*!< Timer 4 clock enable */
#define  RCC_APB1ENR_TIM6EN                  (0x00000010)        /*!< Timer 6 clock enable */
#define  RCC_APB1ENR_TIM7EN                  (0x00000020)        /*!< Timer 7 clock enable */
#define  RCC_APB1ENR_WWDGEN                  (0x00000800)        /*!< Window Watchdog clock enable */
#define  RCC_APB1ENR_SPI2EN                  (0x00004000)        /*!< SPI2 clock enable */
#define  RCC_APB1ENR_SPI3EN                  (0x00008000)        /*!< SPI3 clock enable */
#define  RCC_APB1ENR_USART2EN                (0x00020000)        /*!< USART 2 clock enable */
#define  RCC_APB1ENR_USART3EN                (0x00040000)        /*!< USART 3 clock enable */
#define  RCC_APB1ENR_UART4EN                 (0x00080000)        /*!< UART 4 clock enable */
#define  RCC_APB1ENR_UART5EN                 (0x00100000)        /*!< UART 5 clock enable */
#define  RCC_APB1ENR_I2C1EN                  (0x00200000)        /*!< I2C 1 clock enable */
#define  RCC_APB1ENR_I2C2EN                  (0x00400000)        /*!< I2C 2 clock enable */
#define  RCC_APB1ENR_USBEN                   (0x00800000)        /*!< USB clock enable */
#define  RCC_APB1ENR_CAN1EN                  (0x02000000)        /*!< CAN clock enable */
#define  RCC_APB1ENR_DAC2EN                  (0x04000000)        /*!< DAC 2 clock enable */
#define  RCC_APB1ENR_PWREN                   (0x10000000)        /*!< PWR clock enable */
#define  RCC_APB1ENR_DAC1EN                  (0x20000000)        /*!< DAC clock enable */
#define  RCC_APB1ENR_I2C3EN                  (0x40000000)        /*!< I2C 3 clock enable */
#define  RCC_APB1ENR_DACEN                   RCC_APB1ENR_DAC1EN

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
#define  RCC_CSR_RMVF                        (0x01000000)        /*!< Remove reset flag */
#define  RCC_CSR_OBLRSTF                     (0x02000000)        /*!< OBL reset flag */
#define  RCC_CSR_PINRSTF                     (0x04000000)        /*!< PIN reset flag */
#define  RCC_CSR_PORRSTF                     (0x08000000)        /*!< POR/PDR reset flag */
#define  RCC_CSR_SFTRSTF                     (0x10000000)        /*!< Software Reset flag */
#define  RCC_CSR_IWDGRSTF                    (0x20000000)        /*!< Independent Watchdog reset flag */
#define  RCC_CSR_WWDGRSTF                    (0x40000000)        /*!< Window watchdog reset flag */
#define  RCC_CSR_LPWRRSTF                    (0x80000000)        /*!< Low-Power reset flag */

#define  RCC_AHBRSTR_FMCRST                  (0x00000020)         /*!< FMC reset */
#define  RCC_AHBRSTR_GPIOHRST                (0x00010000)         /*!< GPIOH reset */
#define  RCC_AHBRSTR_GPIOARST                (0x00020000)         /*!< GPIOA reset */
#define  RCC_AHBRSTR_GPIOBRST                (0x00040000)         /*!< GPIOB reset */
#define  RCC_AHBRSTR_GPIOCRST                (0x00080000)         /*!< GPIOC reset */
#define  RCC_AHBRSTR_GPIODRST                (0x00010000)         /*!< GPIOD reset */
#define  RCC_AHBRSTR_GPIOERST                (0x00200000)         /*!< GPIOE reset */
#define  RCC_AHBRSTR_GPIOFRST                (0x00400000)         /*!< GPIOF reset */
#define  RCC_AHBRSTR_GPIOGRST                (0x00800000)         /*!< GPIOG reset */
#define  RCC_AHBRSTR_TSRST                   (0x00100000)         /*!< TS reset */
#define  RCC_AHBRSTR_ADC12RST                (0x01000000)         /*!< ADC1 & ADC2 reset */
#define  RCC_AHBRSTR_ADC34RST                (0x02000000)         /*!< ADC3 & ADC4 reset */

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

#define  RCC_CFGR2_ADCPRE12                  (0x000001F0)        /*!< ADCPRE12[8:4] bits */
#define  RCC_CFGR2_ADCPRE12_0                (0x00000010)        /*!< Bit 0 */
#define  RCC_CFGR2_ADCPRE12_1                (0x00000020)        /*!< Bit 1 */
#define  RCC_CFGR2_ADCPRE12_2                (0x00000040)        /*!< Bit 2 */
#define  RCC_CFGR2_ADCPRE12_3                (0x00000080)        /*!< Bit 3 */
#define  RCC_CFGR2_ADCPRE12_4                (0x00000100)        /*!< Bit 4 */

#define  RCC_CFGR2_ADCPRE12_NO               (0x00000000)        /*!< ADC12 clock disabled, ADC12 can use AHB clock */
#define  RCC_CFGR2_ADCPRE12_DIV1             (0x00000100)        /*!< ADC12 PLL clock divided by 1 */
#define  RCC_CFGR2_ADCPRE12_DIV2             (0x00000110)        /*!< ADC12 PLL clock divided by 2 */
#define  RCC_CFGR2_ADCPRE12_DIV4             (0x00000120)        /*!< ADC12 PLL clock divided by 4 */
#define  RCC_CFGR2_ADCPRE12_DIV6             (0x00000130)        /*!< ADC12 PLL clock divided by 6 */
#define  RCC_CFGR2_ADCPRE12_DIV8             (0x00000140)        /*!< ADC12 PLL clock divided by 8 */
#define  RCC_CFGR2_ADCPRE12_DIV10            (0x00000150)        /*!< ADC12 PLL clock divided by 10 */
#define  RCC_CFGR2_ADCPRE12_DIV12            (0x00000160)        /*!< ADC12 PLL clock divided by 12 */
#define  RCC_CFGR2_ADCPRE12_DIV16            (0x00000170)        /*!< ADC12 PLL clock divided by 16 */
#define  RCC_CFGR2_ADCPRE12_DIV32            (0x00000180)        /*!< ADC12 PLL clock divided by 32 */
#define  RCC_CFGR2_ADCPRE12_DIV64            (0x00000190)        /*!< ADC12 PLL clock divided by 64 */
#define  RCC_CFGR2_ADCPRE12_DIV128           (0x000001A0)        /*!< ADC12 PLL clock divided by 128 */
#define  RCC_CFGR2_ADCPRE12_DIV256           (0x000001B0)        /*!< ADC12 PLL clock divided by 256 */

#define  RCC_CFGR2_ADCPRE34                  (0x00003E00)        /*!< ADCPRE34[13:5] bits */
#define  RCC_CFGR2_ADCPRE34_0                (0x00000200)        /*!< Bit 0 */
#define  RCC_CFGR2_ADCPRE34_1                (0x00000400)        /*!< Bit 1 */
#define  RCC_CFGR2_ADCPRE34_2                (0x00000800)        /*!< Bit 2 */
#define  RCC_CFGR2_ADCPRE34_3                (0x00001000)        /*!< Bit 3 */
#define  RCC_CFGR2_ADCPRE34_4                (0x00002000)        /*!< Bit 4 */

#define  RCC_CFGR2_ADCPRE34_NO               (0x00000000)        /*!< ADC34 clock disabled, ADC34 can use AHB clock */
#define  RCC_CFGR2_ADCPRE34_DIV1             (0x00002000)        /*!< ADC34 PLL clock divided by 1 */
#define  RCC_CFGR2_ADCPRE34_DIV2             (0x00002200)        /*!< ADC34 PLL clock divided by 2 */
#define  RCC_CFGR2_ADCPRE34_DIV4             (0x00002400)        /*!< ADC34 PLL clock divided by 4 */
#define  RCC_CFGR2_ADCPRE34_DIV6             (0x00002600)        /*!< ADC34 PLL clock divided by 6 */
#define  RCC_CFGR2_ADCPRE34_DIV8             (0x00002800)        /*!< ADC34 PLL clock divided by 8 */
#define  RCC_CFGR2_ADCPRE34_DIV10            (0x00002A00)        /*!< ADC34 PLL clock divided by 10 */
#define  RCC_CFGR2_ADCPRE34_DIV12            (0x00002C00)        /*!< ADC34 PLL clock divided by 12 */
#define  RCC_CFGR2_ADCPRE34_DIV16            (0x00002E00)        /*!< ADC34 PLL clock divided by 16 */
#define  RCC_CFGR2_ADCPRE34_DIV32            (0x00003000)        /*!< ADC34 PLL clock divided by 32 */
#define  RCC_CFGR2_ADCPRE34_DIV64            (0x00003200)        /*!< ADC34 PLL clock divided by 64 */
#define  RCC_CFGR2_ADCPRE34_DIV128           (0x00003400)        /*!< ADC34 PLL clock divided by 128 */
#define  RCC_CFGR2_ADCPRE34_DIV256           (0x00003600)        /*!< ADC34 PLL clock divided by 256 */

#define  RCC_CFGR3_USART1SW                  (0x00000003)        /*!< USART1SW[1:0] bits */
#define  RCC_CFGR3_USART1SW_0                (0x00000001)        /*!< Bit 0 */
#define  RCC_CFGR3_USART1SW_1                (0x00000002)        /*!< Bit 1 */

#define  RCC_CFGR3_I2CSW                     (0x00000070)        /*!< I2CSW bits */
#define  RCC_CFGR3_I2C1SW                    (0x00000010)        /*!< I2C1SW bits */ 
#define  RCC_CFGR3_I2C2SW                    (0x00000020)        /*!< I2C2SW bits */
#define  RCC_CFGR3_I2C3SW                    (0x00000040)        /*!< I2C3SW bits */

#define  RCC_CFGR3_TIMSW                     (0x00002F00)        /*!< TIMSW bits */
#define  RCC_CFGR3_TIM1SW                    (0x00000100)        /*!< TIM1SW bits */ 
#define  RCC_CFGR3_TIM8SW                    (0x00000200)        /*!< TIM8SW bits */
#define  RCC_CFGR3_TIM15SW                   (0x00000400)        /*!< TIM15SW bits */
#define  RCC_CFGR3_TIM16SW                   (0x00000800)        /*!< TIM16SW bits */
#define  RCC_CFGR3_TIM17SW                   (0x00002000)        /*!< TIM17SW bits */
#define  RCC_CFGR3_TIM20SW                   (0x00008000)        /*!< TIM20SW bits */
#define  RCC_CFGR3_TIM2SW                    (0x01000000)        /*!< TIM3SW bits */
#define  RCC_CFGR3_TIM3SW                    (0x02000000)        /*!< TIM2SW bits */


#define  RCC_CFGR3_HRTIM1SW                  (0x00001000)        /*!< HRTIM1SW bits */

#define  RCC_CFGR3_USART2SW                  (0x00030000)        /*!< USART2SW[1:0] bits */
#define  RCC_CFGR3_USART2SW_0                (0x00010000)        /*!< Bit 0 */
#define  RCC_CFGR3_USART2SW_1                (0x00020000)        /*!< Bit 1 */

#define  RCC_CFGR3_USART3SW                  (0x000C0000)        /*!< USART3SW[1:0] bits */
#define  RCC_CFGR3_USART3SW_0                (0x00040000)        /*!< Bit 0 */
#define  RCC_CFGR3_USART3SW_1                (0x00080000)        /*!< Bit 1 */

#define  RCC_CFGR3_UART4SW                   (0x00300000)        /*!< UART4SW[1:0] bits */
#define  RCC_CFGR3_UART4SW_0                 (0x00100000)        /*!< Bit 0 */
#define  RCC_CFGR3_UART4SW_1                 (0x00200000)        /*!< Bit 1 */

#define  RCC_CFGR3_UART5SW                   (0x00C00000)        /*!< UART5SW[1:0] bits */
#define  RCC_CFGR3_UART5SW_0                 (0x00400000)        /*!< Bit 0 */
#define  RCC_CFGR3_UART5SW_1                 (0x00800000)        /*!< Bit 1 */

#define  RCC_CFGR3_TIM2SW                    (0x01000000)        /*!< TIM3SW bits */
#define  RCC_CFGR3_TIM3SW                    (0x02000000)        /*!< TIM2SW bits */

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
#define RTC_CR_BCK                           (0x00040000)
#define RTC_CR_SUB1H                         (0x00020000)
#define RTC_CR_ADD1H                         (0x00010000)
#define RTC_CR_TSIE                          (0x00008000)
#define RTC_CR_WUTIE                         (0x00004000)
#define RTC_CR_ALRBIE                        (0x00002000)
#define RTC_CR_ALRAIE                        (0x00001000)
#define RTC_CR_TSE                           (0x00000800)
#define RTC_CR_WUTE                          (0x00000400)
#define RTC_CR_ALRBE                         (0x00000200)
#define RTC_CR_ALRAE                         (0x00000100)
#define RTC_CR_FMT                           (0x00000040)
#define RTC_CR_BYPSHAD                       (0x00000020)
#define RTC_CR_REFCKON                       (0x00000010)
#define RTC_CR_TSEDGE                        (0x00000008)
#define RTC_CR_WUCKSEL                       (0x00000007)
#define RTC_CR_WUCKSEL_0                     (0x00000001)
#define RTC_CR_WUCKSEL_1                     (0x00000002)
#define RTC_CR_WUCKSEL_2                     (0x00000004)

#define RTC_ISR_RECALPF                      (0x00010000)
#define RTC_ISR_TAMP3F                       (0x00008000)
#define RTC_ISR_TAMP2F                       (0x00004000)
#define RTC_ISR_TAMP1F                       (0x00002000)
#define RTC_ISR_TSOVF                        (0x00001000)
#define RTC_ISR_TSF                          (0x00000800)
#define RTC_ISR_WUTF                         (0x00000400)
#define RTC_ISR_ALRBF                        (0x00000200)
#define RTC_ISR_ALRAF                        (0x00000100)
#define RTC_ISR_INIT                         (0x00000080)
#define RTC_ISR_INITF                        (0x00000040)
#define RTC_ISR_RSF                          (0x00000020)
#define RTC_ISR_INITS                        (0x00000010)
#define RTC_ISR_SHPF                         (0x00000008)
#define RTC_ISR_WUTWF                        (0x00000004)
#define RTC_ISR_ALRBWF                       (0x00000002)
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

#define RTC_ALRMBR_MSK4                      (0x80000000)
#define RTC_ALRMBR_WDSEL                     (0x40000000)
#define RTC_ALRMBR_DT                        (0x30000000)
#define RTC_ALRMBR_DT_0                      (0x10000000)
#define RTC_ALRMBR_DT_1                      (0x20000000)
#define RTC_ALRMBR_DU                        (0x0F000000)
#define RTC_ALRMBR_DU_0                      (0x01000000)
#define RTC_ALRMBR_DU_1                      (0x02000000)
#define RTC_ALRMBR_DU_2                      (0x04000000)
#define RTC_ALRMBR_DU_3                      (0x08000000)
#define RTC_ALRMBR_MSK3                      (0x00800000)
#define RTC_ALRMBR_PM                        (0x00400000)
#define RTC_ALRMBR_HT                        (0x00300000)
#define RTC_ALRMBR_HT_0                      (0x00100000)
#define RTC_ALRMBR_HT_1                      (0x00200000)
#define RTC_ALRMBR_HU                        (0x000F0000)
#define RTC_ALRMBR_HU_0                      (0x00010000)
#define RTC_ALRMBR_HU_1                      (0x00020000)
#define RTC_ALRMBR_HU_2                      (0x00040000)
#define RTC_ALRMBR_HU_3                      (0x00080000)
#define RTC_ALRMBR_MSK2                      (0x00008000)
#define RTC_ALRMBR_MNT                       (0x00007000)
#define RTC_ALRMBR_MNT_0                     (0x00001000)
#define RTC_ALRMBR_MNT_1                     (0x00002000)
#define RTC_ALRMBR_MNT_2                     (0x00004000)
#define RTC_ALRMBR_MNU                       (0x00000F00)
#define RTC_ALRMBR_MNU_0                     (0x00000100)
#define RTC_ALRMBR_MNU_1                     (0x00000200)
#define RTC_ALRMBR_MNU_2                     (0x00000400)
#define RTC_ALRMBR_MNU_3                     (0x00000800)
#define RTC_ALRMBR_MSK1                      (0x00000080)
#define RTC_ALRMBR_ST                        (0x00000070)
#define RTC_ALRMBR_ST_0                      (0x00000010)
#define RTC_ALRMBR_ST_1                      (0x00000020)
#define RTC_ALRMBR_ST_2                      (0x00000040)
#define RTC_ALRMBR_SU                        (0x0000000F)
#define RTC_ALRMBR_SU_0                      (0x00000001)
#define RTC_ALRMBR_SU_1                      (0x00000002)
#define RTC_ALRMBR_SU_2                      (0x00000004)
#define RTC_ALRMBR_SU_3                      (0x00000008)

#define RTC_WPR_KEY                          (0x000000FF)

#define RTC_SSR_SS                           (0x0000FFFF)

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

#define RTC_TSSSR_SS                         (0x0000FFFF)

#define RTC_CALR_CALP                        (0x00008000)
#define RTC_CALR_CALW8                       (0x00004000)
#define RTC_CALR_CALW16                      (0x00002000)
#define RTC_CALR_CALM                        (0x000001FF)
#define RTC_CALR_CALM_0                      (0x00000001)
#define RTC_CALR_CALM_1                      (0x00000002)
#define RTC_CALR_CALM_2                      (0x00000004)
#define RTC_CALR_CALM_3                      (0x00000008)
#define RTC_CALR_CALM_4                      (0x00000010)
#define RTC_CALR_CALM_5                      (0x00000020)
#define RTC_CALR_CALM_6                      (0x00000040)
#define RTC_CALR_CALM_7                      (0x00000080)
#define RTC_CALR_CALM_8                      (0x00000100)

#define RTC_TAFCR_ALARMOUTTYPE               (0x00040000)
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
#define RTC_TAFCR_TAMP3TRG                   (0x00000040)
#define RTC_TAFCR_TAMP3E                     (0x00000020)
#define RTC_TAFCR_TAMP2TRG                   (0x00000010)
#define RTC_TAFCR_TAMP2E                     (0x00000008)
#define RTC_TAFCR_TAMPIE                     (0x00000004)
#define RTC_TAFCR_TAMP1TRG                   (0x00000002)
#define RTC_TAFCR_TAMP1E                     (0x00000001)

#define RTC_ALRMASSR_MASKSS                  (0x0F000000)
#define RTC_ALRMASSR_MASKSS_0                (0x01000000)
#define RTC_ALRMASSR_MASKSS_1                (0x02000000)
#define RTC_ALRMASSR_MASKSS_2                (0x04000000)
#define RTC_ALRMASSR_MASKSS_3                (0x08000000)
#define RTC_ALRMASSR_SS                      (0x00007FFF)

#define RTC_ALRMBSSR_MASKSS                  (0x0F000000)
#define RTC_ALRMBSSR_MASKSS_0                (0x01000000)
#define RTC_ALRMBSSR_MASKSS_1                (0x02000000)
#define RTC_ALRMBSSR_MASKSS_2                (0x04000000)
#define RTC_ALRMBSSR_MASKSS_3                (0x08000000)
#define RTC_ALRMBSSR_SS                      (0x00007FFF)

#define RTC_BKP0R                            (0xFFFFFFFF)

#define RTC_BKP1R                            (0xFFFFFFFF)

#define RTC_BKP2R                            (0xFFFFFFFF)

#define RTC_BKP3R                            (0xFFFFFFFF)

#define RTC_BKP4R                            (0xFFFFFFFF)

#define RTC_BKP5R                            (0xFFFFFFFF)

#define RTC_BKP6R                            (0xFFFFFFFF)

#define RTC_BKP7R                            (0xFFFFFFFF)

#define RTC_BKP8R                            (0xFFFFFFFF)

#define RTC_BKP9R                            (0xFFFFFFFF)

#define RTC_BKP10R                           (0xFFFFFFFF)

#define RTC_BKP11R                           (0xFFFFFFFF)

#define RTC_BKP12R                           (0xFFFFFFFF)

#define RTC_BKP13R                           (0xFFFFFFFF)

#define RTC_BKP14R                           (0xFFFFFFFF)

#define RTC_BKP15R                           (0xFFFFFFFF)

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

#define SYSCFG_CFGR1_MEM_MODE               (0x00000007) /*!< SYSCFG_Memory Remap Config */
#define SYSCFG_CFGR1_MEM_MODE_0             (0x00000001) /*!< Bit 0 */
#define SYSCFG_CFGR1_MEM_MODE_1             (0x00000002) /*!< Bit 1 */
#define SYSCFG_CFGR1_MEM_MODE_2             (0x00000004) /*!< Bit 2 */
#define SYSCFG_CFGR1_USB_IT_RMP             (0x00000020) /*!< USB interrupt remap */
#define SYSCFG_CFGR1_TIM1_ITR3_RMP          (0x00000040) /*!< Timer 1 ITR3 selection */
#define SYSCFG_CFGR1_DAC1_TRIG1_RMP         (0x00000080) /*!< DAC1 Trigger1 remap */
#define SYSCFG_CFGR1_ADC24_DMA_RMP          (0x00000100) /*!< ADC2 and ADC4 DMA remap */
#define SYSCFG_CFGR1_TIM16_DMA_RMP          (0x00000800) /*!< Timer 16 DMA remap */
#define SYSCFG_CFGR1_TIM17_DMA_RMP          (0x00001000) /*!< Timer 17 DMA remap */
#define SYSCFG_CFGR1_TIM6DAC1Ch1_DMA_RMP    (0x00002000) /*!< Timer 6 / DAC1 CH1 DMA remap */
#define SYSCFG_CFGR1_TIM7DAC1Ch2_DMA_RMP    (0x00004000) /*!< Timer 7 / DAC1 CH2 DMA remap */
#define SYSCFG_CFGR1_DAC2Ch1_DMA_RMP        (0x00008000) /*!< DAC2 CH1 DMA remap */
#define SYSCFG_CFGR1_I2C_PB6_FMP            (0x00010000) /*!< I2C PB6 Fast mode plus */
#define SYSCFG_CFGR1_I2C_PB7_FMP            (0x00020000) /*!< I2C PB7 Fast mode plus */
#define SYSCFG_CFGR1_I2C_PB8_FMP            (0x00040000) /*!< I2C PB8 Fast mode plus */
#define SYSCFG_CFGR1_I2C_PB9_FMP            (0x00080000) /*!< I2C PB9 Fast mode plus */
#define SYSCFG_CFGR1_I2C1_FMP               (0x00100000) /*!< I2C1 Fast mode plus */
#define SYSCFG_CFGR1_I2C2_FMP               (0x00200000) /*!< I2C2 Fast mode plus */
#define SYSCFG_CFGR1_ENCODER_MODE           (0x00C00000) /*!< Encoder Mode */
#define SYSCFG_CFGR1_ENCODER_MODE_0         (0x00400000) /*!< Encoder Mode 0 */
#define SYSCFG_CFGR1_ENCODER_MODE_1         (0x00800000) /*!< Encoder Mode 1 */
#define SYSCFG_CFGR1_I2C3_FMP               (0x01000000) /*!< I2C3 Fast mode plus */
#define SYSCFG_CFGR1_FPU_IE                 (0xFC000000) /*!< Floating Point Unit Interrupt Enable */
#define SYSCFG_CFGR1_FPU_IE_0               (0x04000000) /*!< Floating Point Unit Interrupt Enable 0 */
#define SYSCFG_CFGR1_FPU_IE_1               (0x08000000) /*!< Floating Point Unit Interrupt Enable 1 */
#define SYSCFG_CFGR1_FPU_IE_2               (0x10000000) /*!< Floating Point Unit Interrupt Enable 2 */
#define SYSCFG_CFGR1_FPU_IE_3               (0x20000000) /*!< Floating Point Unit Interrupt Enable 3 */
#define SYSCFG_CFGR1_FPU_IE_4               (0x40000000) /*!< Floating Point Unit Interrupt Enable 4 */
#define SYSCFG_CFGR1_FPU_IE_5               (0x80000000) /*!< Floating Point Unit Interrupt Enable 5 */
#define SYSCFG_CFGR1_DAC_TRIG_RMP           SYSCFG_CFGR1_DAC1_TRIG1_RMP  /*!< Old define maintained for legacy purpose */
#define SYSCFG_CFGR1_TIM6DAC1               SYSCFG_CFGR1_TIM6DAC1Ch1_DMA_RMP /*!< Old define maintained for legacy purpose */
#define SYSCFG_CFGR1_TIM7DAC2               SYSCFG_CFGR1_TIM7DAC1Ch2_DMA_RMP /*!< Old define maintained for legacy purpose */
#define SYSCFG_RCR_PAGE0          (0x00000001) /*!< ICODE SRAM Write protection page 0 */
#define SYSCFG_RCR_PAGE1          (0x00000002) /*!< ICODE SRAM Write protection page 1 */
#define SYSCFG_RCR_PAGE2          (0x00000004) /*!< ICODE SRAM Write protection page 2 */
#define SYSCFG_RCR_PAGE3          (0x00000008) /*!< ICODE SRAM Write protection page 3 */
#define SYSCFG_RCR_PAGE4          (0x00000010) /*!< ICODE SRAM Write protection page 4 */
#define SYSCFG_RCR_PAGE5          (0x00000020) /*!< ICODE SRAM Write protection page 5 */
#define SYSCFG_RCR_PAGE6          (0x00000040) /*!< ICODE SRAM Write protection page 6 */
#define SYSCFG_RCR_PAGE7          (0x00000080) /*!< ICODE SRAM Write protection page 7 */
#define SYSCFG_RCR_PAGE8          (0x00000100) /*!< ICODE SRAM Write protection page 8 */
#define SYSCFG_RCR_PAGE9          (0x00000200) /*!< ICODE SRAM Write protection page 9 */
#define SYSCFG_RCR_PAGE10         (0x00000400) /*!< ICODE SRAM Write protection page 10 */
#define SYSCFG_RCR_PAGE11         (0x00000800) /*!< ICODE SRAM Write protection page 11 */
#define SYSCFG_RCR_PAGE12         (0x00001000) /*!< ICODE SRAM Write protection page 12 */
#define SYSCFG_RCR_PAGE13         (0x00002000) /*!< ICODE SRAM Write protection page 13 */
#define SYSCFG_RCR_PAGE14         (0x00004000) /*!< ICODE SRAM Write protection page 14 */
#define SYSCFG_RCR_PAGE15         (0x00008000) /*!< ICODE SRAM Write protection page 15 */


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
#define SYSCFG_EXTICR1_EXTI0_PG         (0x0006) /*!< PG[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PH         (0x0007) /*!< PH[0] pin */


/** 
  * @brief  EXTI1 configuration  
  */ 
#define SYSCFG_EXTICR1_EXTI1_PA         (0x0000) /*!< PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB         (0x0010) /*!< PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC         (0x0020) /*!< PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD         (0x0030) /*!< PD[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PE         (0x0040) /*!< PE[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PF         (0x0050) /*!< PF[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PG         (0x0060) /*!< PG[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PH         (0x0070) /*!< PH[1] pin */

/** 
  * @brief  EXTI2 configuration  
  */ 
#define SYSCFG_EXTICR1_EXTI2_PA         (0x0000) /*!< PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB         (0x0100) /*!< PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC         (0x0200) /*!< PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD         (0x0300) /*!< PD[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PE         (0x0400) /*!< PE[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PF         (0x0500) /*!< PF[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PG         (0x0600) /*!< PG[2] pin */

/** 
  * @brief  EXTI3 configuration  
  */ 
#define SYSCFG_EXTICR1_EXTI3_PA         (0x0000) /*!< PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB         (0x1000) /*!< PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC         (0x2000) /*!< PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD         (0x3000) /*!< PD[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PE         (0x4000) /*!< PE[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PF         (0x5000) /*!< PE[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PG         (0x6000) /*!< PG[3] pin */

#define SYSCFG_EXTIRCR_EXTI4            (0x000F) /*!< EXTI 4 configuration */
#define SYSCFG_EXTIRCR_EXTI5            (0x00F0) /*!< EXTI 5 configuration */
#define SYSCFG_EXTIRCR_EXTI6            (0x0F00) /*!< EXTI 6 configuration */
#define SYSCFG_EXTIRCR_EXTI7            (0xF000) /*!< EXTI 7 configuration */

/** 
  * @brief  EXTI4 configuration  
  */ 
#define SYSCFG_EXTIRCR_EXTI4_PA         (0x0000) /*!< PA[4] pin */
#define SYSCFG_EXTIRCR_EXTI4_PB         (0x0001) /*!< PB[4] pin */
#define SYSCFG_EXTIRCR_EXTI4_PC         (0x0002) /*!< PC[4] pin */
#define SYSCFG_EXTIRCR_EXTI4_PD         (0x0003) /*!< PD[4] pin */
#define SYSCFG_EXTIRCR_EXTI4_PE         (0x0004) /*!< PE[4] pin */
#define SYSCFG_EXTIRCR_EXTI4_PF         (0x0005) /*!< PF[4] pin */
#define SYSCFG_EXTIRCR_EXTI4_PG         (0x0006) /*!< PG[4] pin */
#define SYSCFG_EXTIRCR_EXTI4_PH         (0x0007) /*!< PH[4] pin */

/** 
  * @brief  EXTI5 configuration  
  */ 
#define SYSCFG_EXTIRCR_EXTI5_PA         (0x0000) /*!< PA[5] pin */
#define SYSCFG_EXTIRCR_EXTI5_PB         (0x0010) /*!< PB[5] pin */
#define SYSCFG_EXTIRCR_EXTI5_PC         (0x0020) /*!< PC[5] pin */
#define SYSCFG_EXTIRCR_EXTI5_PD         (0x0030) /*!< PD[5] pin */
#define SYSCFG_EXTIRCR_EXTI5_PE         (0x0040) /*!< PE[5] pin */
#define SYSCFG_EXTIRCR_EXTI5_PF         (0x0050) /*!< PF[5] pin */
#define SYSCFG_EXTIRCR_EXTI5_PG         (0x0060) /*!< PG[5] pin */

/** 
  * @brief  EXTI6 configuration  
  */ 
#define SYSCFG_EXTIRCR_EXTI6_PA         (0x0000) /*!< PA[6] pin */
#define SYSCFG_EXTIRCR_EXTI6_PB         (0x0100) /*!< PB[6] pin */
#define SYSCFG_EXTIRCR_EXTI6_PC         (0x0200) /*!< PC[6] pin */
#define SYSCFG_EXTIRCR_EXTI6_PD         (0x0300) /*!< PD[6] pin */
#define SYSCFG_EXTIRCR_EXTI6_PE         (0x0400) /*!< PE[6] pin */
#define SYSCFG_EXTIRCR_EXTI6_PF         (0x0500) /*!< PF[6] pin */
#define SYSCFG_EXTIRCR_EXTI6_PG         (0x0600) /*!< PG[6] pin */

/** 
  * @brief  EXTI7 configuration  
  */ 
#define SYSCFG_EXTIRCR_EXTI7_PA         (0x0000) /*!< PA[7] pin */
#define SYSCFG_EXTIRCR_EXTI7_PB         (0x1000) /*!< PB[7] pin */
#define SYSCFG_EXTIRCR_EXTI7_PC         (0x2000) /*!< PC[7] pin */
#define SYSCFG_EXTIRCR_EXTI7_PD         (0x3000) /*!< PD[7] pin */
#define SYSCFG_EXTIRCR_EXTI7_PE         (0x4000) /*!< PE[7] pin */
#define SYSCFG_EXTIRCR_EXTI7_PF         (0x5000) /*!< PF[7] pin */
#define SYSCFG_EXTIRCR_EXTI7_PG         (0x6000) /*!< PG[7] pin */

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
#define SYSCFG_EXTICR3_EXTI8_PF         (0x0005) /*!< PF[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PG         (0x0006) /*!< PG[8] pin */
/** 
  * @brief  EXTI9 configuration  
  */ 
#define SYSCFG_EXTICR3_EXTI9_PA         (0x0000) /*!< PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB         (0x0010) /*!< PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC         (0x0020) /*!< PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD         (0x0030) /*!< PD[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PE         (0x0040) /*!< PE[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PF         (0x0050) /*!< PF[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PG         (0x0060) /*!< PG[9] pin */

/** 
  * @brief  EXTI10 configuration  
  */ 
#define SYSCFG_EXTICR3_EXTI10_PA        (0x0000) /*!< PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB        (0x0100) /*!< PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC        (0x0200) /*!< PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD        (0x0300) /*!< PD[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PE        (0x0400) /*!< PE[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PF        (0x0500) /*!< PF[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PG        (0x0600) /*!< PG[10] pin */

/** 
  * @brief  EXTI11 configuration  
  */ 
#define SYSCFG_EXTICR3_EXTI11_PA        (0x0000) /*!< PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB        (0x1000) /*!< PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC        (0x2000) /*!< PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD        (0x3000) /*!< PD[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PE        (0x4000) /*!< PE[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PF        (0x5000) /*!< PF[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PG        (0x6000) /*!< PG[11] pin */

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
#define SYSCFG_EXTICR4_EXTI12_PF        (0x0005) /*!< PF[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PG        (0x0006) /*!< PG[12] pin */

/** 
  * @brief  EXTI13 configuration  
  */ 
#define SYSCFG_EXTICR4_EXTI13_PA        (0x0000) /*!< PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB        (0x0010) /*!< PB[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PC        (0x0020) /*!< PC[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PD        (0x0030) /*!< PD[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PE        (0x0040) /*!< PE[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PF        (0x0050) /*!< PF[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PG        (0x0060) /*!< PG[13] pin */

/** 
  * @brief  EXTI14 configuration  
  */ 
#define SYSCFG_EXTICR4_EXTI14_PA        (0x0000) /*!< PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB        (0x0100) /*!< PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC        (0x0200) /*!< PC[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PD        (0x0300) /*!< PD[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PE        (0x0400) /*!< PE[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PF        (0x0500) /*!< PF[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PG        (0x0600) /*!< PG[14] pin */

/** 
  * @brief  EXTI15 configuration  
  */ 
#define SYSCFG_EXTICR4_EXTI15_PA        (0x0000) /*!< PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB        (0x1000) /*!< PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC        (0x2000) /*!< PC[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PD        (0x3000) /*!< PD[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PE        (0x4000) /*!< PE[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PF        (0x5000) /*!< PF[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PG        (0x6000) /*!< PG[15] pin */

#define SYSCFG_CFGR2_LOCKUP_LOCK               (0x00000001) /*!< Enables and locks the PVD connection with Timer1/8/15/16/17 Break Input and also the PVD_EN and PVDSEL[2:0] bits of the Power Control Interface */
#define SYSCFG_CFGR2_SRAM_PARITY_LOCK          (0x00000002) /*!< Enables and locks the SRAM_PARITY error signal with Break Input of TIMER1/8/15/16/17 */
#define SYSCFG_CFGR2_PVD_LOCK                  (0x00000004) /*!< Enables and locks the LOCKUP (Hardfault) output of CortexM4 with Break Input of TIMER1/8/15/16/17 */
#define SYSCFG_CFGR2_BYP_ADDR_PAR              (0x00000010) /*!< Disables the address parity check on RAM */
#define SYSCFG_CFGR2_SRAM_PE                   (0x00000100) /*!< SRAM Parity error flag */

#define SYSCFG_CFGR3_SPI1_RX_DMA_RMP           (0x00000003) /*!< SPI1 RX DMA remap */
#define SYSCFG_CFGR3_SPI1_RX_DMA_RMP_0         (0x00000001) /*!< SPI1 RX DMA remap bit 0 */
#define SYSCFG_CFGR3_SPI1_RX_DMA_RMP_1         (0x00000002) /*!< SPI1 RX DMA remap bit 1 */
#define SYSCFG_CFGR3_SPI1_TX_DMA_RMP           (0x0000000C) /*!< SPI1 TX DMA remap */
#define SYSCFG_CFGR3_SPI1_TX_DMA_RMP_0         (0x00000004) /*!< SPI1 TX DMA remap bit 0 */
#define SYSCFG_CFGR3_SPI1_TX_DMA_RMP_1         (0x00000008) /*!< SPI1 TX DMA remap bit 1 */
#define SYSCFG_CFGR3_I2C1_RX_DMA_RMP           (0x00000030) /*!< I2C1 RX DMA remap */
#define SYSCFG_CFGR3_I2C1_RX_DMA_RMP_0         (0x00000010) /*!< I2C1 RX DMA remap bit 0 */
#define SYSCFG_CFGR3_I2C1_RX_DMA_RMP_1         (0x00000020) /*!< I2C1 RX DMA remap bit 1 */
#define SYSCFG_CFGR3_I2C1_TX_DMA_RMP           (0x000000C0) /*!< I2C1 RX DMA remap */
#define SYSCFG_CFGR3_I2C1_TX_DMA_RMP_0         (0x00000040) /*!< I2C1 TX DMA remap bit 0 */
#define SYSCFG_CFGR3_I2C1_TX_DMA_RMP_1         (0x00000080) /*!< I2C1 TX DMA remap bit 1 */
#define SYSCFG_CFGR3_ADC2_DMA_RMP              (0x00000300) /*!< ADC2 DMA remap */
#define SYSCFG_CFGR3_ADC2_DMA_RMP_0            (0x00000100) /*!< ADC2 DMA remap bit 0 */
#define SYSCFG_CFGR3_ADC2_DMA_RMP_1            (0x00000200) /*!< ADC2 DMA remap bit 1 */
#define SYSCFG_CFGR3_DAC1_TRG3_RMP             (0x00010000) /*!< DAC1 TRG3 remap */
#define SYSCFG_CFGR3_DAC1_TRG5_RMP             (0x00020000) /*!< DAC1 TRG5 remap */

#define SYSCFG_CFGR4_ADC12_EXT2_RMP            (0x00000001) /*!< ADC12 regular channel EXT2 remap */
#define SYSCFG_CFGR4_ADC12_EXT3_RMP            (0x00000002) /*!< ADC12 regular channel EXT3 remap */
#define SYSCFG_CFGR4_ADC12_EXT5_RMP            (0x00000004) /*!< ADC12 regular channel EXT5 remap */
#define SYSCFG_CFGR4_ADC12_EXT13_RMP           (0x00000008) /*!< ADC12 regular channel EXT13 remap */
#define SYSCFG_CFGR4_ADC12_EXT15_RMP           (0x00000010) /*!< ADC12 regular channel EXT15 remap */
#define SYSCFG_CFGR4_ADC12_JEXT3_RMP           (0x00000020) /*!< ADC12 injected channel JEXT3 remap */
#define SYSCFG_CFGR4_ADC12_JEXT6_RMP           (0x00000040) /*!< ADC12 injected channel JEXT6 remap */
#define SYSCFG_CFGR4_ADC12_JEXT13_RMP          (0x00000080) /*!< ADC12 injected channel JEXT13 remap */
#define SYSCFG_CFGR4_ADC34_EXT5_RMP            (0x00000100) /*!< ADC34 regular channel EXT5 remap */
#define SYSCFG_CFGR4_ADC34_EXT6_RMP            (0x00000200) /*!< ADC34 regular channel EXT6 remap */
#define SYSCFG_CFGR4_ADC34_EXT15_RMP           (0x00000400) /*!< ADC34 regular channel EXT15 remap */
#define SYSCFG_CFGR4_ADC34_JEXT5_RMP           (0x00000800) /*!< ADC34 injected channel JEXT5 remap */
#define SYSCFG_CFGR4_ADC34_JEXT11_RMP          (0x00001000) /*!< ADC34 injected channel JEXT11 remap */
#define SYSCFG_CFGR4_ADC34_JEXT14_RMP          (0x00002000) /*!< ADC34 injected channel JEXT14 remap */

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

#define  TIM_CR1_UIFREMAP                    (0x0800)            /*!<Update interrupt flag remap */

#define  TIM_CR2_CCPC                        (0x00000001)            /*!<Capture/Compare Preloaded Control */
#define  TIM_CR2_CCUS                        (0x00000004)            /*!<Capture/Compare Control Update Selection */
#define  TIM_CR2_CCDS                        (0x00000008)            /*!<Capture/Compare DMA Selection */

#define  TIM_CR2_MMS                         (0x00000070)            /*!<MMS[2:0] bits (Master Mode Selection) */
#define  TIM_CR2_MMS_0                       (0x00000010)            /*!<Bit 0 */
#define  TIM_CR2_MMS_1                       (0x00000020)            /*!<Bit 1 */
#define  TIM_CR2_MMS_2                       (0x00000040)            /*!<Bit 2 */

#define  TIM_CR2_TI1S                        (0x00000080)            /*!<TI1 Selection */
#define  TIM_CR2_OIS1                        (0x00000100)            /*!<Output Idle state 1 (OC1 output) */
#define  TIM_CR2_OIS1N                       (0x00000200)            /*!<Output Idle state 1 (OC1N output) */
#define  TIM_CR2_OIS2                        (0x00000400)            /*!<Output Idle state 2 (OC2 output) */
#define  TIM_CR2_OIS2N                       (0x00000800)            /*!<Output Idle state 2 (OC2N output) */
#define  TIM_CR2_OIS3                        (0x00001000)            /*!<Output Idle state 3 (OC3 output) */
#define  TIM_CR2_OIS3N                       (0x00002000)            /*!<Output Idle state 3 (OC3N output) */
#define  TIM_CR2_OIS4                        (0x00004000)            /*!<Output Idle state 4 (OC4 output) */
#define  TIM_CR2_OIS5                        (0x00010000)            /*!<Output Idle state 4 (OC4 output) */
#define  TIM_CR2_OIS6                        (0x00020000)            /*!<Output Idle state 4 (OC4 output) */

#define  TIM_CR2_MMS2                        (0x00F00000)            /*!<MMS[2:0] bits (Master Mode Selection) */
#define  TIM_CR2_MMS2_0                      (0x00100000)            /*!<Bit 0 */
#define  TIM_CR2_MMS2_1                      (0x00200000)            /*!<Bit 1 */
#define  TIM_CR2_MMS2_2                      (0x00400000)            /*!<Bit 2 */
#define  TIM_CR2_MMS2_3                      (0x00800000)            /*!<Bit 2 */

#define  TIM_SMCR_SMS                        (0x00010007)            /*!<SMS[2:0] bits (Slave mode selection) */
#define  TIM_SMCR_SMS_0                      (0x00000001)            /*!<Bit 0 */
#define  TIM_SMCR_SMS_1                      (0x00000002)            /*!<Bit 1 */
#define  TIM_SMCR_SMS_2                      (0x00000004)            /*!<Bit 2 */
#define  TIM_SMCR_SMS_3                      (0x00010000)            /*!<Bit 3 */

#define  TIM_SMCR_OCCS                       (0x00000008)            /*!< OCREF clear selection */

#define  TIM_SMCR_TS                         (0x00000070)            /*!<TS[2:0] bits (Trigger selection) */
#define  TIM_SMCR_TS_0                       (0x00000010)            /*!<Bit 0 */
#define  TIM_SMCR_TS_1                       (0x00000020)            /*!<Bit 1 */
#define  TIM_SMCR_TS_2                       (0x00000040)            /*!<Bit 2 */

#define  TIM_SMCR_MSM                        (0x00000080)            /*!<Master/slave mode */

#define  TIM_SMCR_ETF                        (0x00000F00)            /*!<ETF[3:0] bits (External trigger filter) */
#define  TIM_SMCR_ETF_0                      (0x00000100)            /*!<Bit 0 */
#define  TIM_SMCR_ETF_1                      (0x00000200)            /*!<Bit 1 */
#define  TIM_SMCR_ETF_2                      (0x00000400)            /*!<Bit 2 */
#define  TIM_SMCR_ETF_3                      (0x00000800)            /*!<Bit 3 */

#define  TIM_SMCR_ETPS                       (0x00003000)            /*!<ETPS[1:0] bits (External trigger prescaler) */
#define  TIM_SMCR_ETPS_0                     (0x00001000)            /*!<Bit 0 */
#define  TIM_SMCR_ETPS_1                     (0x00002000)            /*!<Bit 1 */

#define  TIM_SMCR_ECE                        (0x00004000)            /*!<External clock enable */
#define  TIM_SMCR_ETP                        (0x00008000)            /*!<External trigger polarity */

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

#define  TIM_SR_UIF                          (0x00000001)            /*!<Update interrupt Flag */
#define  TIM_SR_CC1IF                        (0x00000002)            /*!<Capture/Compare 1 interrupt Flag */
#define  TIM_SR_CC2IF                        (0x00000004)            /*!<Capture/Compare 2 interrupt Flag */
#define  TIM_SR_CC3IF                        (0x00000008)            /*!<Capture/Compare 3 interrupt Flag */
#define  TIM_SR_CC4IF                        (0x00000010)            /*!<Capture/Compare 4 interrupt Flag */
#define  TIM_SR_COMIF                        (0x00000020)            /*!<COM interrupt Flag */
#define  TIM_SR_TIF                          (0x00000040)            /*!<Trigger interrupt Flag */
#define  TIM_SR_BIF                          (0x00000080)            /*!<Break interrupt Flag */
#define  TIM_SR_B2IF                         (0x00000100)            /*!<Break2 interrupt Flag */
#define  TIM_SR_CC1OF                        (0x00000200)            /*!<Capture/Compare 1 Over capture Flag */
#define  TIM_SR_CC2OF                        (0x00000400)            /*!<Capture/Compare 2 Over capture Flag */
#define  TIM_SR_CC3OF                        (0x00000800)            /*!<Capture/Compare 3 Over capture Flag */
#define  TIM_SR_CC4OF                        (0x00001000)            /*!<Capture/Compare 4 Over capture Flag */
#define  TIM_SR_CC5IF                        (0x00010000)            /*!<Capture/Compare 5 interrupt Flag */
#define  TIM_SR_CC6IF                        (0x00020000)            /*!<Capture/Compare 6 interrupt Flag */


#define  TIM_EGR_UG                          (0x0001)               /*!<Update Generation */
#define  TIM_EGR_CC1G                        (0x0002)               /*!<Capture/Compare 1 Generation */
#define  TIM_EGR_CC2G                        (0x0004)               /*!<Capture/Compare 2 Generation */
#define  TIM_EGR_CC3G                        (0x0008)               /*!<Capture/Compare 3 Generation */
#define  TIM_EGR_CC4G                        (0x0010)               /*!<Capture/Compare 4 Generation */
#define  TIM_EGR_COMG                        (0x0020)               /*!<Capture/Compare Control Update Generation */
#define  TIM_EGR_TG                          (0x0040)               /*!<Trigger Generation */
#define  TIM_EGR_BG                          (0x0080)               /*!<Break Generation */
#define  TIM_EGR_B2G                         (0x0100)               /*!<Break Generation */


#define  TIM_CCMR1_CC1S                      (0x00000003)            /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define  TIM_CCMR1_CC1S_0                    (0x00000001)            /*!<Bit 0 */
#define  TIM_CCMR1_CC1S_1                    (0x00000002)            /*!<Bit 1 */

#define  TIM_CCMR1_OC1FE                     (0x00000004)            /*!<Output Compare 1 Fast enable */
#define  TIM_CCMR1_OC1PE                     (0x00000008)            /*!<Output Compare 1 Preload enable */

#define  TIM_CCMR1_OC1M                      (0x00010070)            /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define  TIM_CCMR1_OC1M_0                    (0x00000010)            /*!<Bit 0 */
#define  TIM_CCMR1_OC1M_1                    (0x00000020)            /*!<Bit 1 */
#define  TIM_CCMR1_OC1M_2                    (0x00000040)            /*!<Bit 2 */
#define  TIM_CCMR1_OC1M_3                    (0x00010000)            /*!<Bit 3 */

#define  TIM_CCMR1_OC1CE                     (0x00000080)            /*!<Output Compare 1Clear Enable */

#define  TIM_CCMR1_CC2S                      (0x00000300)            /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define  TIM_CCMR1_CC2S_0                    (0x00000100)            /*!<Bit 0 */
#define  TIM_CCMR1_CC2S_1                    (0x00000200)            /*!<Bit 1 */

#define  TIM_CCMR1_OC2FE                     (0x00000400)            /*!<Output Compare 2 Fast enable */
#define  TIM_CCMR1_OC2PE                     (0x00000800)            /*!<Output Compare 2 Preload enable */

#define  TIM_CCMR1_OC2M                      (0x01007000)            /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define  TIM_CCMR1_OC2M_0                    (0x00001000)            /*!<Bit 0 */
#define  TIM_CCMR1_OC2M_1                    (0x00002000)            /*!<Bit 1 */
#define  TIM_CCMR1_OC2M_2                    (0x00004000)            /*!<Bit 2 */
#define  TIM_CCMR1_OC2M_3                    (0x01000000)            /*!<Bit 3 */

#define  TIM_CCMR1_OC2CE                     (0x00008000)            /*!<Output Compare 2 Clear Enable */


#define  TIM_CCMR1_IC1PSC                    (0x0000000C)            /*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define  TIM_CCMR1_IC1PSC_0                  (0x00000004)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1PSC_1                  (0x00000008)            /*!<Bit 1 */

#define  TIM_CCMR1_IC1F                      (0x000000F0)            /*!<IC1F[3:0] bits (Input Capture 1 Filter) */
#define  TIM_CCMR1_IC1F_0                    (0x00000010)            /*!<Bit 0 */
#define  TIM_CCMR1_IC1F_1                    (0x00000020)            /*!<Bit 1 */
#define  TIM_CCMR1_IC1F_2                    (0x00000040)            /*!<Bit 2 */
#define  TIM_CCMR1_IC1F_3                    (0x00000080)            /*!<Bit 3 */

#define  TIM_CCMR1_IC2PSC                    (0x00000C00)            /*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler) */
#define  TIM_CCMR1_IC2PSC_0                  (0x00000400)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2PSC_1                  (0x00000800)            /*!<Bit 1 */

#define  TIM_CCMR1_IC2F                      (0x0000F000)            /*!<IC2F[3:0] bits (Input Capture 2 Filter) */
#define  TIM_CCMR1_IC2F_0                    (0x00001000)            /*!<Bit 0 */
#define  TIM_CCMR1_IC2F_1                    (0x00002000)            /*!<Bit 1 */
#define  TIM_CCMR1_IC2F_2                    (0x00004000)            /*!<Bit 2 */
#define  TIM_CCMR1_IC2F_3                    (0x00008000)            /*!<Bit 3 */

#define  TIM_CCMR2_CC3S                      (0x00000003)            /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define  TIM_CCMR2_CC3S_0                    (0x00000001)            /*!<Bit 0 */
#define  TIM_CCMR2_CC3S_1                    (0x00000002)            /*!<Bit 1 */

#define  TIM_CCMR2_OC3FE                     (0x00000004)            /*!<Output Compare 3 Fast enable */
#define  TIM_CCMR2_OC3PE                     (0x00000008)            /*!<Output Compare 3 Preload enable */

#define  TIM_CCMR2_OC3M                      (0x00000070)            /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define  TIM_CCMR2_OC3M_0                    (0x00000010)            /*!<Bit 0 */
#define  TIM_CCMR2_OC3M_1                    (0x00000020)            /*!<Bit 1 */
#define  TIM_CCMR2_OC3M_2                    (0x00000040)            /*!<Bit 2 */
#define  TIM_CCMR2_OC3M_3                    (0x00010000)            /*!<Bit 3 */

#define  TIM_CCMR2_OC3CE                     (0x00000080)            /*!<Output Compare 3 Clear Enable */

#define  TIM_CCMR2_CC4S                      (0x00000300)            /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define  TIM_CCMR2_CC4S_0                    (0x00000100)            /*!<Bit 0 */
#define  TIM_CCMR2_CC4S_1                    (0x00000200)            /*!<Bit 1 */

#define  TIM_CCMR2_OC4FE                     (0x00000400)            /*!<Output Compare 4 Fast enable */
#define  TIM_CCMR2_OC4PE                     (0x00000800)            /*!<Output Compare 4 Preload enable */

#define  TIM_CCMR2_OC4M                      (0x00007000)            /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define  TIM_CCMR2_OC4M_0                    (0x00001000)            /*!<Bit 0 */
#define  TIM_CCMR2_OC4M_1                    (0x00002000)            /*!<Bit 1 */
#define  TIM_CCMR2_OC4M_2                    (0x00004000)            /*!<Bit 2 */
#define  TIM_CCMR2_OC4M_3                    (0x00100000)            /*!<Bit 3 */

#define  TIM_CCMR2_OC4CE                     (0x00008000)            /*!<Output Compare 4 Clear Enable */


#define  TIM_CCMR2_IC3PSC                    (0x0000000C)            /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define  TIM_CCMR2_IC3PSC_0                  (0x00000004)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3PSC_1                  (0x00000008)            /*!<Bit 1 */

#define  TIM_CCMR2_IC3F                      (0x000000F0)            /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define  TIM_CCMR2_IC3F_0                    (0x00000010)            /*!<Bit 0 */
#define  TIM_CCMR2_IC3F_1                    (0x00000020)            /*!<Bit 1 */
#define  TIM_CCMR2_IC3F_2                    (0x00000040)            /*!<Bit 2 */
#define  TIM_CCMR2_IC3F_3                    (0x00000080)            /*!<Bit 3 */

#define  TIM_CCMR2_IC4PSC                    (0x00000C00)            /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define  TIM_CCMR2_IC4PSC_0                  (0x00000400)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4PSC_1                  (0x00000800)            /*!<Bit 1 */

#define  TIM_CCMR2_IC4F                      (0x0000F000)            /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define  TIM_CCMR2_IC4F_0                    (0x00001000)            /*!<Bit 0 */
#define  TIM_CCMR2_IC4F_1                    (0x00002000)            /*!<Bit 1 */
#define  TIM_CCMR2_IC4F_2                    (0x00004000)            /*!<Bit 2 */
#define  TIM_CCMR2_IC4F_3                    (0x00008000)            /*!<Bit 3 */

#define  TIM_CCER_CC1E                       (0x00000001)            /*!<Capture/Compare 1 output enable */
#define  TIM_CCER_CC1P                       (0x00000002)            /*!<Capture/Compare 1 output Polarity */
#define  TIM_CCER_CC1NE                      (0x00000004)            /*!<Capture/Compare 1 Complementary output enable */
#define  TIM_CCER_CC1NP                      (0x00000008)            /*!<Capture/Compare 1 Complementary output Polarity */
#define  TIM_CCER_CC2E                       (0x00000010)            /*!<Capture/Compare 2 output enable */
#define  TIM_CCER_CC2P                       (0x00000020)            /*!<Capture/Compare 2 output Polarity */
#define  TIM_CCER_CC2NE                      (0x00000040)            /*!<Capture/Compare 2 Complementary output enable */
#define  TIM_CCER_CC2NP                      (0x00000080)            /*!<Capture/Compare 2 Complementary output Polarity */
#define  TIM_CCER_CC3E                       (0x00000100)            /*!<Capture/Compare 3 output enable */
#define  TIM_CCER_CC3P                       (0x00000200)            /*!<Capture/Compare 3 output Polarity */
#define  TIM_CCER_CC3NE                      (0x00000400)            /*!<Capture/Compare 3 Complementary output enable */
#define  TIM_CCER_CC3NP                      (0x00000800)            /*!<Capture/Compare 3 Complementary output Polarity */
#define  TIM_CCER_CC4E                       (0x00001000)            /*!<Capture/Compare 4 output enable */
#define  TIM_CCER_CC4P                       (0x00002000)            /*!<Capture/Compare 4 output Polarity */
#define  TIM_CCER_CC4NP                      (0x00008000)            /*!<Capture/Compare 4 Complementary output Polarity */
#define  TIM_CCER_CC5E                       (0x00010000)            /*!<Capture/Compare 5 output enable */
#define  TIM_CCER_CC5P                       (0x00020000)            /*!<Capture/Compare 5 output Polarity */
#define  TIM_CCER_CC6E                       (0x00100000)            /*!<Capture/Compare 6 output enable */
#define  TIM_CCER_CC6P                       (0x00200000)            /*!<Capture/Compare 6 output Polarity */
#define  TIM_CNT_CNT                         (0xFFFFFFFF)            /*!<Counter Value */
#define  TIM_CNT_UIFCPY                      (0x80000000)            /*!<Update interrupt flag copy */
#define  TIM_PSC_PSC                         (0xFFFF)            /*!<Prescaler Value */

#define  TIM_ARR_ARR                         (0xFFFFFFFF)            /*!<actual auto-reload Value */

#define  TIM_RCR_REP                         (0xFF)               /*!<Repetition Counter Value */

#define  TIM_CCR1_CCR1                       (0xFFFF)            /*!<Capture/Compare 1 Value */

#define  TIM_CCR2_CCR2                       (0xFFFF)            /*!<Capture/Compare 2 Value */

#define  TIM_CCR3_CCR3                       (0xFFFF)            /*!<Capture/Compare 3 Value */

#define  TIM_CCR4_CCR4                       (0xFFFF)            /*!<Capture/Compare 4 Value */

#define  TIM_CCR5_CCR5                       (0xFFFFFFFF)        /*!<Capture/Compare 5 Value */
#define  TIM_CCR5_GC5C1                      (0x20000000)        /*!<Group Channel 5 and Channel 1 */
#define  TIM_CCR5_GC5C2                      (0x40000000)        /*!<Group Channel 5 and Channel 2 */
#define  TIM_CCR5_GC5C3                      (0x80000000)        /*!<Group Channel 5 and Channel 3 */

#define  TIM_CCR6_CCR6                       (0xFFFF)            /*!<Capture/Compare 6 Value */

#define  TIM_BDTR_DTG                        (0x000000FF)            /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define  TIM_BDTR_DTG_0                      (0x00000001)            /*!<Bit 0 */
#define  TIM_BDTR_DTG_1                      (0x00000002)            /*!<Bit 1 */
#define  TIM_BDTR_DTG_2                      (0x00000004)            /*!<Bit 2 */
#define  TIM_BDTR_DTG_3                      (0x00000008)            /*!<Bit 3 */
#define  TIM_BDTR_DTG_4                      (0x00000010)            /*!<Bit 4 */
#define  TIM_BDTR_DTG_5                      (0x00000020)            /*!<Bit 5 */
#define  TIM_BDTR_DTG_6                      (0x00000040)            /*!<Bit 6 */
#define  TIM_BDTR_DTG_7                      (0x00000080)            /*!<Bit 7 */

#define  TIM_BDTR_LOCK                       (0x00000300)            /*!<LOCK[1:0] bits (Lock Configuration) */
#define  TIM_BDTR_LOCK_0                     (0x00000100)            /*!<Bit 0 */
#define  TIM_BDTR_LOCK_1                     (0x00000200)            /*!<Bit 1 */

#define  TIM_BDTR_OSSI                       (0x00000400)            /*!<Off-State Selection for Idle mode */
#define  TIM_BDTR_OSSR                       (0x00000800)            /*!<Off-State Selection for Run mode */
#define  TIM_BDTR_BKE                        (0x00001000)            /*!<Break enable for Break1 */
#define  TIM_BDTR_BKP                        (0x00002000)            /*!<Break Polarity for Break1 */
#define  TIM_BDTR_AOE                        (0x00004000)            /*!<Automatic Output enable */
#define  TIM_BDTR_MOE                        (0x00008000)            /*!<Main Output enable */

#define  TIM_BDTR_BKF                        (0x000F0000)            /*!<Break Filter for Break1 */
#define  TIM_BDTR_BK2F                       (0x00F00000)            /*!<Break Filter for Break2 */

#define  TIM_BDTR_BK2E                       (0x01000000)            /*!<Break enable for Break2 */
#define  TIM_BDTR_BK2P                       (0x02000000)            /*!<Break Polarity for Break2 */

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

#define TIM16_OR_TI1_RMP                     (0x00C0)            /*!<TI1_RMP[1:0] bits (TIM16 Input 1 remap) */
#define TIM16_OR_TI1_RMP_0                   (0x0040)            /*!<Bit 0 */
#define TIM16_OR_TI1_RMP_1                   (0x0080)            /*!<Bit 1 */

#define TIM1_OR_ETR_RMP                      (0x000F)            /*!<ETR_RMP[3:0] bits (TIM1 ETR remap) */
#define TIM1_OR_ETR_RMP_0                    (0x0001)            /*!<Bit 0 */
#define TIM1_OR_ETR_RMP_1                    (0x0002)            /*!<Bit 1 */
#define TIM1_OR_ETR_RMP_2                    (0x0004)            /*!<Bit 2 */
#define TIM1_OR_ETR_RMP_3                    (0x0008)            /*!<Bit 3 */

#define TIM8_OR_ETR_RMP                      (0x000F)            /*!<ETR_RMP[3:0] bits (TIM8 ETR remap) */
#define TIM8_OR_ETR_RMP_0                    (0x0001)            /*!<Bit 0 */
#define TIM8_OR_ETR_RMP_1                    (0x0002)            /*!<Bit 1 */
#define TIM8_OR_ETR_RMP_2                    (0x0004)            /*!<Bit 2 */
#define TIM8_OR_ETR_RMP_3                    (0x0008)            /*!<Bit 3 */

#define TIM20_OR_ETR_RMP                     (0x0000000F)            /*!<ETR_RMP[3:0] bits (TIM20 ETR remap) */
#define TIM20_OR_ETR_RMP_0                   (0x00000001)            /*!<Bit 0 */
#define TIM20_OR_ETR_RMP_1                   (0x00000002)            /*!<Bit 1 */
#define TIM20_OR_ETR_RMP_2                   (0x00000004)            /*!<Bit 2 */
#define TIM20_OR_ETR_RMP_3                   (0x00000008)            /*!<Bit 3 */

#define  TIM_CCMR3_OC5FE                     (0x00000004)            /*!<Output Compare 5 Fast enable */
#define  TIM_CCMR3_OC5PE                     (0x00000008)            /*!<Output Compare 5 Preload enable */

#define  TIM_CCMR3_OC5M                      (0x00000070)            /*!<OC5M[2:0] bits (Output Compare 5 Mode) */
#define  TIM_CCMR3_OC5M_0                    (0x00000010)            /*!<Bit 0 */
#define  TIM_CCMR3_OC5M_1                    (0x00000020)            /*!<Bit 1 */
#define  TIM_CCMR3_OC5M_2                    (0x00000040)            /*!<Bit 2 */
#define  TIM_CCMR3_OC5M_3                    (0x00010000)            /*!<Bit 3 */

#define  TIM_CCMR3_OC5CE                     (0x00000080)            /*!<Output Compare 5 Clear Enable */

#define  TIM_CCMR3_OC6FE                     (0x00000400)            /*!<Output Compare 4 Fast enable */
#define  TIM_CCMR3_OC6PE                     (0x00000800)            /*!<Output Compare 4 Preload enable */

#define  TIM_CCMR3_OC6M                      (0x00007000)            /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define  TIM_CCMR3_OC6M_0                    (0x00001000)            /*!<Bit 0 */
#define  TIM_CCMR3_OC6M_1                    (0x00002000)            /*!<Bit 1 */
#define  TIM_CCMR3_OC6M_2                    (0x00004000)            /*!<Bit 2 */
#define  TIM_CCMR3_OC6M_3                    (0x00100000)            /*!<Bit 3 */

#define  TIM_CCMR3_OC6CE                     (0x00008000)            /*!<Output Compare 4 Clear Enable */

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

#define  USART_RQR_ABRRQ                     (0x0001)                /*!< Auto-Baud Rate Request */
#define  USART_RQR_SBKRQ                     (0x0002)                /*!< Send Break Request */
#define  USART_RQR_MMRQ                      (0x0004)                /*!< Mute Mode Request */
#define  USART_RQR_RXFRQ                     (0x0008)                /*!< Receive Data flush Request */
#define  USART_RQR_TXFRQ                     (0x0010)                /*!< Transmit data flush Request */

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
#define  USART_ICR_NCF                       (0x00000004)            /*!< Noise detected Clear Flag */
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

#define  WWDG_CR_T                           (0x7F)               /*!<T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define  WWDG_CR_T0                          (0x01)               /*!<Bit 0 */
#define  WWDG_CR_T1                          (0x02)               /*!<Bit 1 */
#define  WWDG_CR_T2                          (0x04)               /*!<Bit 2 */
#define  WWDG_CR_T3                          (0x08)               /*!<Bit 3 */
#define  WWDG_CR_T4                          (0x10)               /*!<Bit 4 */
#define  WWDG_CR_T5                          (0x20)               /*!<Bit 5 */
#define  WWDG_CR_T6                          (0x40)               /*!<Bit 6 */

#define  WWDG_CR_WDGA                        (0x80)               /*!<Activation bit */

#define  WWDG_CFR_W                          (0x007F)            /*!<W[6:0] bits (7-bit window value) */
#define  WWDG_CFR_W0                         (0x0001)            /*!<Bit 0 */
#define  WWDG_CFR_W1                         (0x0002)            /*!<Bit 1 */
#define  WWDG_CFR_W2                         (0x0004)            /*!<Bit 2 */
#define  WWDG_CFR_W3                         (0x0008)            /*!<Bit 3 */
#define  WWDG_CFR_W4                         (0x0010)            /*!<Bit 4 */
#define  WWDG_CFR_W5                         (0x0020)            /*!<Bit 5 */
#define  WWDG_CFR_W6                         (0x0040)            /*!<Bit 6 */

#define  WWDG_CFR_WDGTB                      (0x0180)            /*!<WDGTB[1:0] bits (Timer Base) */
#define  WWDG_CFR_WDGTB0                     (0x0080)            /*!<Bit 0 */
#define  WWDG_CFR_WDGTB1                     (0x0100)            /*!<Bit 1 */

#define  WWDG_CFR_EWI                        (0x0200)            /*!<Early Wakeup Interrupt */

#define  WWDG_SR_EWIF                        (0x01)               /*!<Early Wakeup Interrupt Flag */

#if defined (STM32F303xC)
#define ADC1_IRQn                         ADC1_2_IRQn                       
#define CAN1_TX_IRQn                      USB_HP_CAN1_TX_IRQn               
#define CAN1_RX0_IRQn                     USB_LP_CAN1_RX0_IRQn              
#define TIM6_DAC1_IRQn                    TIM6_DAC_IRQn                     
#define TIM7_DAC2_IRQn                    TIM7_IRQn                         
#define COMP2_IRQn                        COMP1_2_3_IRQn                    
#define COMP4_6_IRQn                      COMP4_5_6_IRQn                    

#define ADC1_IRQHandler                   ADC1_2_IRQHandler                 
#define CAN1_TX_IRQHandler                USB_HP_CAN1_TX_IRQHandler         
#define CAN1_RX0_IRQHandler               USB_LP_CAN1_RX0_IRQHandler        
#define TIM6_DAC1_IRQHandler              TIM6_DAC_IRQHandler               
#define TIM7_DAC2_IRQHandler              TIM7_IRQHandler                   
#define COMP2_IRQHandler                  COMP1_2_3_IRQHandler              
#define COMP4_6_IRQHandler                COMP4_5_6_IRQHandler              

#elif defined (STM32F334x8)
#define ADC1_IRQn                         ADC1_2_IRQn                       
#define USB_HP_CAN1_TX_IRQn               CAN1_TX_IRQn                                     
#define USB_LP_CAN1_RX0_IRQn              CAN1_RX0_IRQn                                   
#define TIM6_DAC_IRQn                     TIM6_DAC1_IRQn                                         
#define TIM7_IRQn                         TIM7_DAC2_IRQn                                             
#define COMP1_2_3_IRQn                    COMP2_IRQn                                            
#define COMP4_5_6_IRQn                    COMP4_6_IRQn                                          

#define ADC1_IRQHandler                   ADC1_2_IRQHandler                 
#define USB_HP_CAN1_TX_IRQHandler         CAN1_TX_IRQHandler                               
#define USB_LP_CAN1_RX0_IRQHandler        CAN1_RX0_IRQHandler                             
#define TIM6_DAC_IRQHandler               TIM6_DAC1_IRQHandler                                   
#define TIM7_IRQHandler                   TIM7_DAC2_IRQHandler                                       
#define COMP1_2_3_IRQHandler              COMP2_IRQHandler                                     
#define COMP4_5_6_IRQHandler              COMP4_6_IRQHandler                

#elif defined (STM32F302x8)
#define ADC1_2_IRQn                       ADC1_IRQn                           
#define CAN1_TX_IRQn                      USB_HP_CAN1_TX_IRQn               
#define CAN1_RX0_IRQn                     USB_LP_CAN1_RX0_IRQn               
#define TIM6_DAC1_IRQn                    TIM6_DAC_IRQn                       
#define COMP1_2_3_IRQn                    COMP2_IRQn                                            
#define COMP4_5_6_IRQn                    COMP4_6_IRQn                       

#define ADC1_2_IRQHandler                 ADC1_IRQHandler                     
#define CAN1_TX_IRQHandler                USB_HP_CAN1_TX_IRQHandler         
#define CAN1_RX0_IRQHandler               USB_LP_CAN1_RX0_IRQHandler         
#define TIM6_DAC1_IRQHandler              TIM6_DAC_IRQHandler                 
#define COMP1_2_3_IRQHandler              COMP2_IRQHandler                                      
#define COMP4_5_6_IRQHandler              COMP4_6_IRQHandler                   

#elif defined (STM32F303xE)   
#define ADC1_IRQn                         ADC1_2_IRQn                       
#define CAN1_TX_IRQn                      USB_HP_CAN1_TX_IRQn               
#define CAN1_RX0_IRQn                     USB_LP_CAN1_RX0_IRQn              
#define TIM6_DAC1_IRQn                    TIM6_DAC_IRQn                     
#define TIM7_DAC2_IRQn                    TIM7_IRQn                         
#define COMP2_IRQn                        COMP1_2_3_IRQn                    
#define COMP4_6_IRQn                      COMP4_5_6_IRQn                    

#define ADC1_IRQHandler                   ADC1_2_IRQHandler                 
#define CAN1_TX_IRQHandler                USB_HP_CAN1_TX_IRQHandler         
#define CAN1_RX0_IRQHandler               USB_LP_CAN1_RX0_IRQHandler        
#define TIM6_DAC1_IRQHandler              TIM6_DAC_IRQHandler               
#define TIM7_DAC2_IRQHandler              TIM7_IRQHandler                   
#define COMP2_IRQHandler                  COMP1_2_3_IRQHandler              
#define COMP4_6_IRQHandler                COMP4_5_6_IRQHandler              

#endif /* STM32F303xC */        
/**
  * @}
  */

 /**
  * @}
  */ 

#ifdef USE_STDPERIPH_DRIVER
#endif /*!< USE_STDPERIPH_DRIVER */

/** @addtogroup Exported_macro
  * @{
  */

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
  * @}
  */

#ifdef __cplusplus
#endif /* __cplusplus */

#endif /* __STM32F30x_H */

/**
  * @}
  */

  /**
  * @}
  */

