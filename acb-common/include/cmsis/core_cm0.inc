@ Manually converted from core_cm0.h file

/**************************************************************************//**
 * @file     core_cm0.h
 * @brief    CMSIS Cortex-M0 Core Peripheral Access Layer Header File
 * @version  V3.20
 * @date     25. February 2013
 *
 * @note
 *
 ******************************************************************************/
/* Copyright (c) 2009 - 2013 ARM LIMITED

All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
- Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
- Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------*/

#ifndef __CORE_CM0_H_GENERIC
#define __CORE_CM0_H_GENERIC

#define __CORE_CM0_GENERIC

/*  CMSIS CM0 definitions */
#define __CM0_CMSIS_VERSION_MAIN  (0x03)                                   /*!< [31:16] CMSIS HAL main version   */
#define __CM0_CMSIS_VERSION_SUB   (0x20)                                   /*!< [15:0]  CMSIS HAL sub version    */
#define __CM0_CMSIS_VERSION       ((__CM0_CMSIS_VERSION_MAIN << 16) | \
                                    __CM0_CMSIS_VERSION_SUB          )     /*!< CMSIS HAL version number         */

#define __CORTEX_M                (0x00)                                   /*!< Cortex-M Core                    */

#define __FPU_USED       0

@ ASPR bits

V = 28                                                              @ Overflow flag
C = 29                                                              @ Carry flag
Z = 30                                                              @ Zero flag
N = 31                                                              @ Negative flag

@ IPSR bits

ISR = 0                                                             @ Exception number

@ ESPR bits

T = 24                                                              @ Thumb state

@ CONTROL bits

SPSEL = 1                                                           @ Stack to be used

#ifndef __NVIC_PRIO_BITS
  #define __NVIC_PRIO_BITS          2
#endif

@ Memory mapping of Cortex-M0 Hardware
SCS_BASE =           (0xE000E000)                                   @ System Control Space Base Address
SysTick_BASE =       (SCS_BASE + 0x0010)                            @ SysTick Base Address
NVIC_BASE =          (SCS_BASE + 0x0100)                            @ NVIC Base Address
SCB_BASE =           (SCS_BASE + 0x0D00)                            @ System Control Block Base Address

@ NVIC registers

NVIC_ISER = NVIC_BASE                                               @ Interrupt Set Enable Register
NVIC_ICER = NVIC_BASE + 0x080                                       @ Interrupt Clear Enable Register
NVIC_ISPR = NVIC_BASE + 0x100                                       @ Interrupt Set Pending Register
NVIC_ICPR = NVIC_BASE + 0x180                                       @ Interrupt Clear Pending Register
NVIC_IP0 =  NVIC_BASE + 0x300                                       @ Interrupt Priority Register 0
NVIC_IP1 =  NVIC_BASE + 0x304                                       @ Interrupt Priority Register 1
NVIC_IP2 =  NVIC_BASE + 0x308                                       @ Interrupt Priority Register 2
NVIC_IP3 =  NVIC_BASE + 0x30C                                       @ Interrupt Priority Register 3
NVIC_IP4 =  NVIC_BASE + 0x310                                       @ Interrupt Priority Register 4
NVIC_IP5 =  NVIC_BASE + 0x314                                       @ Interrupt Priority Register 5
NVIC_IP6 =  NVIC_BASE + 0x318                                       @ Interrupt Priority Register 6
NVIC_IP7 =  NVIC_BASE + 0x31C                                       @ Interrupt Priority Register 7

@ System Control Block (SCB) registers

SCB_CPUID = SCB_BASE                                                @ CPUID Base Register
SCB_ICSR = SCB_BASE + 0x004                                         @ Interrupt Control and State Register
SCB_AIRCR = SCB_BASE + 0x00C                                        @ Application Interrupt and Reset Control Register
SCB_SCR = SCB_BASE + 0x010                                          @ System Control Register
SCB_CCR = SCB_BASE + 0x014                                          @ Configuration Control Register
SCB_SHP2 = SCB_BASE + 0x01C                                         @ System Handlers Priority Register 2
SCB_SHP3 = SCB_BASE + 0x020                                         @ System Handlers Priority Register 3
SCB_SHCSR = SCB_BASE + 0x024                                        @ System Handler Control and State Register

@ SCB bit defintions

@ SCB CPUID Register Definitions
SCB_CPUID_IMPLEMENTER_Pos =  24                                     @ SCB CPUID: IMPLEMENTER Position
SCB_CPUID_IMPLEMENTER_Msk =  (0xFF << SCB_CPUID_IMPLEMENTER_Pos)    @ SCB CPUID: IMPLEMENTER Mask
SCB_CPUID_VARIANT_Pos =      20                                     @ SCB CPUID: VARIANT Position
SCB_CPUID_VARIANT_Msk =      (0xF << SCB_CPUID_VARIANT_Pos)         @ SCB CPUID: VARIANT Mask
SCB_CPUID_ARCHITECTURE_Pos = 16                                     @ SCB CPUID: ARCHITECTURE Position
SCB_CPUID_ARCHITECTURE_Msk = (0xF << SCB_CPUID_ARCHITECTURE_Pos)    @ SCB CPUID: ARCHITECTURE Mask
SCB_CPUID_PARTNO_Pos =       4                                      @ SCB CPUID: PARTNO Position
SCB_CPUID_PARTNO_Msk =       (0xFFF << SCB_CPUID_PARTNO_Pos)        @ SCB CPUID: PARTNO Mask
SCB_CPUID_REVISION_Pos =     0                                      @ SCB CPUID: REVISION Position
SCB_CPUID_REVISION_Msk =     (0xF << SCB_CPUID_REVISION_Pos)        @ SCB CPUID: REVISION Mask

@ SCB Interrupt Control State Register Definitions
SCB_ICSR_NMIPENDSET_Pos =  31                                       @ SCB ICSR: NMIPENDSET Position
SCB_ICSR_NMIPENDSET_Msk =  (1 << SCB_ICSR_NMIPENDSET_Pos)           @ SCB ICSR: NMIPENDSET Mask
SCB_ICSR_PENDSVSET_Pos =   28                                       @ SCB ICSR: PENDSVSET Position
SCB_ICSR_PENDSVSET_Msk =   (1 << SCB_ICSR_PENDSVSET_Pos)            @ SCB ICSR: PENDSVSET Mask
SCB_ICSR_PENDSVCLR_Pos =   27                                       @ SCB ICSR: PENDSVCLR Position
SCB_ICSR_PENDSVCLR_Msk =   (1 << SCB_ICSR_PENDSVCLR_Pos)            @ SCB ICSR: PENDSVCLR Mask
SCB_ICSR_PENDSTSET_Pos =   26                                       @ SCB ICSR: PENDSTSET Position
SCB_ICSR_PENDSTSET_Msk =   (1 << SCB_ICSR_PENDSTSET_Pos)            @ SCB ICSR: PENDSTSET Mask
SCB_ICSR_PENDSTCLR_Pos =   25                                       @ SCB ICSR: PENDSTCLR Position
SCB_ICSR_PENDSTCLR_Msk =   (1 << SCB_ICSR_PENDSTCLR_Pos)            @ SCB ICSR: PENDSTCLR Mask
SCB_ICSR_ISRPREEMPT_Pos =  23                                       @ SCB ICSR: ISRPREEMPT Position
SCB_ICSR_ISRPREEMPT_Msk =  (1 << SCB_ICSR_ISRPREEMPT_Pos)           @ SCB ICSR: ISRPREEMPT Mask
SCB_ICSR_ISRPENDING_Pos =  22                                       @ SCB ICSR: ISRPENDING Position
SCB_ICSR_ISRPENDING_Msk =  (1 << SCB_ICSR_ISRPENDING_Pos)           @ SCB ICSR: ISRPENDING Mask
SCB_ICSR_VECTPENDING_Pos = 12                                       @ SCB ICSR: VECTPENDING Position
SCB_ICSR_VECTPENDING_Msk = (0x1FF << SCB_ICSR_VECTPENDING_Pos)      @ SCB ICSR: VECTPENDING Mask
SCB_ICSR_VECTACTIVE_Pos =  0                                        @ SCB ICSR: VECTACTIVE Position
SCB_ICSR_VECTACTIVE_Msk =  (0x1FF << SCB_ICSR_VECTACTIVE_Pos)       @ SCB ICSR: VECTACTIVE Mask

@ SCB Application Interrupt and Reset Control Register Definitions
SCB_AIRCR_VECTKEY_Pos =       16                                    @ SCB AIRCR: VECTKEY Position
SCB_AIRCR_VECTKEY_Msk =       (0xFFFF << SCB_AIRCR_VECTKEY_Pos)     @ SCB AIRCR: VECTKEY Mask
SCB_AIRCR_VECTKEYSTAT_Pos =   16                                    @ SCB AIRCR: VECTKEYSTAT Position
SCB_AIRCR_VECTKEYSTAT_Msk =   (0xFFFF << SCB_AIRCR_VECTKEYSTAT_Pos) @ SCB AIRCR: VECTKEYSTAT Mask
SCB_AIRCR_ENDIANESS_Pos =     15                                    @ SCB AIRCR: ENDIANESS Position
SCB_AIRCR_ENDIANESS_Msk =     (1 << SCB_AIRCR_ENDIANESS_Pos)        @ SCB AIRCR: ENDIANESS Mask
SCB_AIRCR_SYSRESETREQ_Pos =   2                                     @ SCB AIRCR: SYSRESETREQ Position
SCB_AIRCR_SYSRESETREQ_Msk =   (1 << SCB_AIRCR_SYSRESETREQ_Pos)      @ SCB AIRCR: SYSRESETREQ Mask
SCB_AIRCR_VECTCLRACTIVE_Pos = 1                                     @ SCB AIRCR: VECTCLRACTIVE Position
SCB_AIRCR_VECTCLRACTIVE_Msk = (1 << SCB_AIRCR_VECTCLRACTIVE_Pos)    @ SCB AIRCR: VECTCLRACTIVE Mask

@ SCB System Control Register Definitions
SCB_SCR_SEVONPEND_Pos =   4                                         @ SCB SCR: SEVONPEND Position
SCB_SCR_SEVONPEND_Msk =   (1 << SCB_SCR_SEVONPEND_Pos)              @ SCB SCR: SEVONPEND Mask
SCB_SCR_SLEEPDEEP_Pos =   2                                         @ SCB SCR: SLEEPDEEP Position
SCB_SCR_SLEEPDEEP_Msk =   (1 << SCB_SCR_SLEEPDEEP_Pos)              @ SCB SCR: SLEEPDEEP Mask
SCB_SCR_SLEEPONEXIT_Pos = 1                                         @ SCB SCR: SLEEPONEXIT Position
SCB_SCR_SLEEPONEXIT_Msk = (1 << SCB_SCR_SLEEPONEXIT_Pos)            @ SCB SCR: SLEEPONEXIT Mask

@ SCB Configuration Control Register Definitions
SCB_CCR_STKALIGN_Pos =    9                                         @ SCB CCR: STKALIGN Position
SCB_CCR_STKALIGN_Msk =    (1 << SCB_CCR_STKALIGN_Pos)               @ SCB CCR: STKALIGN Mask
SCB_CCR_UNALIGN_TRP_Pos = 3                                         @ SCB CCR: UNALIGN_TRP Position
SCB_CCR_UNALIGN_TRP_Msk = (1 << SCB_CCR_UNALIGN_TRP_Pos)            @ SCB CCR: UNALIGN_TRP Mask

@ SCB System Handler Control and State Register Definitions
SCB_SHCSR_SVCALLPENDED_Pos = 15                                     @ SCB SHCSR: SVCALLPENDED Position
SCB_SHCSR_SVCALLPENDED_Msk = (1 << SCB_SHCSR_SVCALLPENDED_Pos)      @ SCB SHCSR: SVCALLPENDED Mask

@ System Timer (SysTick) registers

SysTick_CTRL_OFFSET = 0x000
SysTick_LOAD_OFFSET = 0x004
SysTick_VA_OFFSET   = 0x008
SysTick_CALIB       = 0x00C

SysTick_CTRL  = SysTick_BASE + SysTick_CTRL_OFFSET                  @ SysTick Control and Status Register
SysTick_LOAD  = SysTick_BASE + SysTick_LOAD_OFFSET                  @ SysTick Reload Value Register
SysTick_VA    = SysTick_BASE + SysTick_VA_OFFSET                    @ SysTick Current Value Register
SysTick_CALIB = SysTick_BASE + SysTick_CALIB                        @ SysTick Calibration Register

@ SysTick bit defintions

@ SysTick Control / Status Register Definitions
SysTick_CTRL_COUNTFLAG_Pos = 16                                     @ SysTick CTRL: COUNTFLAG Position
SysTick_CTRL_COUNTFLAG_Msk = (1 << SysTick_CTRL_COUNTFLAG_Pos)      @ SysTick CTRL: COUNTFLAG Mask
SysTick_CTRL_CLKSOURCE_Pos = 2                                      @ SysTick CTRL: CLKSOURCE Position
SysTick_CTRL_CLKSOURCE_Msk = (1 << SysTick_CTRL_CLKSOURCE_Pos)      @ SysTick CTRL: CLKSOURCE Mask
SysTick_CTRL_TICKINT_Pos =   1                                      @ SysTick CTRL: TICKINT Position
SysTick_CTRL_TICKINT_Msk =   (1 << SysTick_CTRL_TICKINT_Pos)        @ SysTick CTRL: TICKINT Mask
SysTick_CTRL_ENABLE_Pos =    0                                      @ SysTick CTRL: ENABLE Position
SysTick_CTRL_ENABLE_Msk =    (1 << SysTick_CTRL_ENABLE_Pos)         @ SysTick CTRL: ENABLE Mask

@ SysTick Reload Register Definitions
SysTick_LOAD_RELOAD_Pos = 0                                         @ SysTick LOAD: RELOAD Position
SysTick_LOAD_RELOAD_Msk = (0xFFFFFF << SysTick_LOAD_RELOAD_Pos)     @ SysTick LOAD: RELOAD Mask

@ SysTick Current Register Definitions
SysTick_VAL_CURRENT_Pos = 0                                         @ SysTick VAL: CURRENT Position
SysTick_VAL_CURRENT_Msk = (0xFFFFFF << SysTick_VAL_CURRENT_Pos)     @ SysTick VAL: CURRENT Mask

@ SysTick Calibration Register Definitions
SysTick_CALIB_NOREF_Pos = 31                                        @ SysTick CALIB: NOREF Position
SysTick_CALIB_NOREF_Msk = (1 << SysTick_CALIB_NOREF_Pos)            @ SysTick CALIB: NOREF Mask
SysTick_CALIB_SKEW_Pos =  30                                        @ SysTick CALIB: SKEW Position
SysTick_CALIB_SKEW_Msk =  (1 << SysTick_CALIB_SKEW_Pos)             @ SysTick CALIB: SKEW Mask
SysTick_CALIB_TENMS_Pos = 0                                         @ SysTick CALIB: TENMS Position
SysTick_CALIB_TENMS_Msk = (0xFFFFFF << SysTick_VAL_CURRENT_Pos)     @ SysTick CALIB: TENMS Mask


#endif
