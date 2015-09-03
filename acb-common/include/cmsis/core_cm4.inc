@ Manually converted from core_cm4.h file

/**************************************************************************//**
 * @file     core_cm4.h
 * @brief    CMSIS Cortex-M4 Core Peripheral Access Layer Header File
 * @version  V4.00
 * @date     22. August 2014
 *
 * @note
 *
 ******************************************************************************/
/* Copyright (c) 2009 - 2014 ARM LIMITED

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
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


#ifndef __CORE_CM4_H_GENERIC
#define __CORE_CM4_H_GENERIC

/*  CMSIS CM4 definitions */
#define __CM4_CMSIS_VERSION_MAIN  (0x04)                                   /* [31:16] CMSIS HAL main version */
#define __CM4_CMSIS_VERSION_SUB   (0x00)                                   /* [15:0]  CMSIS HAL sub version */
#define __CM4_CMSIS_VERSION       ((__CM4_CMSIS_VERSION_MAIN << 16) | \
                                    __CM4_CMSIS_VERSION_SUB          )     /* CMSIS HAL version number */

#define __CORTEX_M                (0x04)                                   /* Cortex-M Core */

/** __FPU_USED indicates whether an FPU is used or not.
    For this, __FPU_PRESENT has to be checked prior to making use of FPU specific registers and functions.
*/

  #if defined (__VFP_FP__) && !defined(__SOFTFP__)
    #if (__FPU_PRESENT == 1)
      #define __FPU_USED       1
    #else
      #warning "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
      #define __FPU_USED       0
    #endif
  #else
    #define __FPU_USED         0
  #endif

#endif /* __CORE_CM4_H_GENERIC */

#ifndef __CMSIS_GENERIC

#ifndef __CORE_CM4_H_DEPENDANT
#define __CORE_CM4_H_DEPENDANT

/* check device defines and use defaults */
#if defined __CHECK_DEVICE_DEFINES
  #ifndef __CM4_REV
    #define __CM4_REV               0x0000
    #warning "__CM4_REV not defined in device header file; using default!"
  #endif

  #ifndef __FPU_PRESENT
    #define __FPU_PRESENT             0
    #warning "__FPU_PRESENT not defined in device header file; using default!"
  #endif

  #ifndef __MPU_PRESENT
    #define __MPU_PRESENT             0
    #warning "__MPU_PRESENT not defined in device header file; using default!"
  #endif

  #ifndef __NVIC_PRIO_BITS
    #define __NVIC_PRIO_BITS          4
    #warning "__NVIC_PRIO_BITS not defined in device header file; using default!"
  #endif

  #ifndef __Vendor_SysTickConfig
    #define __Vendor_SysTickConfig    0
    #warning "__Vendor_SysTickConfig not defined in device header file; using default!"
  #endif
#endif

/*******************************************************************************
 *                 Register Abstraction
  Core Register contain:
  - Core Register
  - Core NVIC Register
  - Core SCB Register
  - Core SysTick Register
  - Core Debug Register
  - Core MPU Register
  - Core FPU Register
 ******************************************************************************/

@ APSR Bits

Q = 27
V = 28
C = 29
Z = 30
N = 31

@ IPSR

ISR = 0

@ xPSR

GE = 16
T  = 24
IT = 25

@ CONROL

nPRIV = 0
SPSEL = 1
FPCA  = 2

@ Memory mapping of Cortex-M4 Hardware
SCS_BASE          = (0xE000E000)                                    @ System Control Space Base Address
ITM_BASE          = (0xE0000000)                                    @ ITM Base Address
DWT_BASE          = (0xE0001000)                                    @ DWT Base Address
TPI_BASE          = (0xE0040000)                                    @ TPI Base Address
CoreDebug_BASE    = (0xE000EDF0)                                    @ Core Debug Base Address
SysTick_BASE      = (SCS_BASE +  0x0010)                            @ SysTick Base Address
NVIC_BASE         = (SCS_BASE +  0x0100)                            @ NVIC Base Address
SCB_BASE          = (SCS_BASE +  0x0D00)                            @ System Control Block Base Address

#if (__MPU_PRESENT == 1)
  #define MPU_BASE          (SCS_BASE +  0x0D90)                    @ Memory Protection Unit
#endif

#if (__FPU_PRESENT == 1)
  #define FPU_BASE          (SCS_BASE +  0x0F30)                    @ Floating Point Unit
#endif


@ NVIC registers

NVIC_ISER = NVIC_BASE                                               @ Interrupt Set Enable Registers
NVIC_ICER = NVIC_BASE + 0x080                                       @ Interrupt Clear Enable Registers
NVIC_ISPR = NVIC_BASE + 0x100                                       @ Interrupt Set Pending Registers
NVIC_ICPR = NVIC_BASE + 0x180                                       @ Interrupt Clear Pending Registers
NVIC_IABR = NVIC_BASE + 0x200                                       @ Interrupt Active bit Registers
NVIC_IP   = NVIC_BASE + 0x300                                       @ Interrupt Priority Registers
NVIS_STIR = NVIC_BASE + 0xE00                                       @ Software Trigger Interrupt Register

@ Software Triggered Interrupt Register Definitions
NVIC_STIR_INTID_Pos         = 0                                     @ STIR: INTLINESNUM Position
NVIC_STIR_INTID_Msk         = (0x1FF << NVIC_STIR_INTID_Pos)        @ STIR: INTLINESNUM Mask


@ System Control Block (SCB) Registers

SCB_CPUID = SCB_BASE                                                @ CPUID Base Register
SCB_ICSR  = SCB_BASE + 0x004                                        @ Interrupt Control and State Register
SCB_VTOR  = SCB_BASE + 0x008                                        @ Vector Table Offset Register
SCB_AIRCR = SCB_BASE + 0x00C                                        @ Application Interrupt and Reset Control Register
SCB_SCR   = SCB_BASE + 0x010                                        @ System Control Register
SCB_CCR   = SCB_BASE + 0x014                                        @ Configuration Control Register
SCB_SHP1  = SCB_BASE + 0x018                                        @ System Handlers Priority Register 1
SCB_SHP2  = SCB_BASE + 0x01C                                        @ System Handlers Priority Register 2
SCB_SHP3  = SCB_BASE + 0x020                                        @ System Handlers Priority Register 3
SCB_SHCSR = SCB_BASE + 0x024                                        @ System Handler Control and State Register
SCB_CFSR  = SCB_BASE + 0x028                                        @ Configurable Fault Status Register
SCB_HFSR  = SCB_BASE + 0x02C                                        @ HardFault Status Register
SCB_DFSR  = SCB_BASE + 0x030                                        @ Debug Fault Status Register
SCB_MMFAR = SCB_BASE + 0x034                                        @ MemManage Fault Address Register
SCB_BFAR  = SCB_BASE + 0x038                                        @ BusFault Address Register
SCB_AFSR  = SCB_BASE + 0x03C                                        @ Auxiliary Fault Status Register
SCB_PFR0  = SCB_BASE + 0x040                                        @ Processor Feature Register 0
SCB_PFR1  = SCB_BASE + 0x044                                        @ Processor Feature Register 1
SCB_DFR   = SCB_BASE + 0x048                                        @ Debug Feature Register
SCB_ADR   = SCB_BASE + 0x04C                                        @ Auxiliary Feature Register
SCB_MMFR0 = SCB_BASE + 0x050                                        @ Memory Model Feature Register 0
SCB_MMFR1 = SCB_BASE + 0x054                                        @ Memory Model Feature Register 1
SCB_MMFR2 = SCB_BASE + 0x058                                        @ Memory Model Feature Register 2 
SCB_MMFR3 = SCB_BASE + 0x05C                                        @ Memory Model Feature Register 3
SCB_ISAR0 = SCB_BASE + 0x060                                        @ Instruction Set Attributes Register 0
SCB_ISAR1 = SCB_BASE + 0x064                                        @ Instruction Set Attributes Register 1
SCB_ISAR2 = SCB_BASE + 0x068                                        @ Instruction Set Attributes Register 2
SCB_ISAR3 = SCB_BASE + 0x06C                                        @ Instruction Set Attributes Register 3
SCB_ISAR4 = SCB_BASE + 0x070                                        @ Instruction Set Attributes Register 4
SCB_CPACR = SCB_BASE + 0x088                                        @ Coprocessor Access Control Register

@ SCB CPUID Register Definitions
SCB_CPUID_IMPLEMENTER_Pos   = 24                                    @ SCB CPUID: IMPLEMENTER Position
SCB_CPUID_IMPLEMENTER_Msk   = (0xFF << SCB_CPUID_IMPLEMENTER_Pos)   @ SCB CPUID: IMPLEMENTER Mask
SCB_CPUID_VARIANT_Pos       = 20                                    @ SCB CPUID: VARIANT Position
SCB_CPUID_VARIANT_Msk       = (0xF << SCB_CPUID_VARIANT_Pos)        @ SCB CPUID: VARIANT Mask
SCB_CPUID_ARCHITECTURE_Pos  = 16                                    @ SCB CPUID: ARCHITECTURE Position
SCB_CPUID_ARCHITECTURE_Msk  = (0xF << SCB_CPUID_ARCHITECTURE_Pos)   @ SCB CPUID: ARCHITECTURE Mask
SCB_CPUID_PARTNO_Pos        = 4                                     @ SCB CPUID: PARTNO Position
SCB_CPUID_PARTNO_Msk        = (0xFFF << SCB_CPUID_PARTNO_Pos)       @ SCB CPUID: PARTNO Mask
SCB_CPUID_REVISION_Pos      = 0                                     @ SCB CPUID: REVISION Position
SCB_CPUID_REVISION_Msk      = (0xF << SCB_CPUID_REVISION_Pos)       @ SCB CPUID: REVISION Mask

@ SCB Interrupt Control State Register Definitions
SCB_ICSR_NMIPENDSET_Pos     = 31                                    @ SCB ICSR: NMIPENDSET Position
SCB_ICSR_NMIPENDSET_Msk     = (1 << SCB_ICSR_NMIPENDSET_Pos)        @ SCB ICSR: NMIPENDSET Mask
SCB_ICSR_PENDSVSET_Pos      = 28                                    @ SCB ICSR: PENDSVSET Position
SCB_ICSR_PENDSVSET_Msk      = (1 << SCB_ICSR_PENDSVSET_Pos)         @ SCB ICSR: PENDSVSET Mask
SCB_ICSR_PENDSVCLR_Pos      = 27                                    @ SCB ICSR: PENDSVCLR Position
SCB_ICSR_PENDSVCLR_Msk      = (1 << SCB_ICSR_PENDSVCLR_Pos)         @ SCB ICSR: PENDSVCLR Mask
SCB_ICSR_PENDSTSET_Pos      = 26                                    @ SCB ICSR: PENDSTSET Position
SCB_ICSR_PENDSTSET_Msk      = (1 << SCB_ICSR_PENDSTSET_Pos)         @ SCB ICSR: PENDSTSET Mask
SCB_ICSR_PENDSTCLR_Pos      = 25                                    @ SCB ICSR: PENDSTCLR Position
SCB_ICSR_PENDSTCLR_Msk      = (1 << SCB_ICSR_PENDSTCLR_Pos)         @ SCB ICSR: PENDSTCLR Mask
SCB_ICSR_ISRPREEMPT_Pos     = 23                                    @ SCB ICSR: ISRPREEMPT Position
SCB_ICSR_ISRPREEMPT_Msk     = (1 << SCB_ICSR_ISRPREEMPT_Pos)        @ SCB ICSR: ISRPREEMPT Mask
SCB_ICSR_ISRPENDING_Pos     = 22                                    @ SCB ICSR: ISRPENDING Position
SCB_ICSR_ISRPENDING_Msk     = (1 << SCB_ICSR_ISRPENDING_Pos)        @ SCB ICSR: ISRPENDING Mask
SCB_ICSR_VECTPENDING_Pos    = 12                                    @ SCB ICSR: VECTPENDING Position
SCB_ICSR_VECTPENDING_Msk    = (0x1FF << SCB_ICSR_VECTPENDING_Pos)   @ SCB ICSR: VECTPENDING Mask
SCB_ICSR_RETTOBASE_Pos      = 11                                    @ SCB ICSR: RETTOBASE Position
SCB_ICSR_RETTOBASE_Msk      = (1 << SCB_ICSR_RETTOBASE_Pos)         @ SCB ICSR: RETTOBASE Mask
SCB_ICSR_VECTACTIVE_Pos     = 0                                     @ SCB ICSR: VECTACTIVE Position
SCB_ICSR_VECTACTIVE_Msk     = (0x1FF << SCB_ICSR_VECTACTIVE_Pos)    @ SCB ICSR: VECTACTIVE Mask

@ SCB Vector Table Offset Register Definitions
SCB_VTOR_TBLOFF_Pos         = 7                                     @ SCB VTOR: TBLOFF Position
SCB_VTOR_TBLOFF_Msk         = (0x1FFFFFF << SCB_VTOR_TBLOFF_Pos)    @ SCB VTOR: TBLOFF Mask

@ SCB Application Interrupt and Reset Control Register Definitions
SCB_AIRCR_VECTKEY_Pos       = 16                                    @ SCB AIRCR: VECTKEY Position
SCB_AIRCR_VECTKEY_Msk       = (0xFFFF << SCB_AIRCR_VECTKEY_Pos)     @ SCB AIRCR: VECTKEY Mask
SCB_AIRCR_VECTKEYSTAT_Pos   = 16                                    @ SCB AIRCR: VECTKEYSTAT Position
SCB_AIRCR_VECTKEYSTAT_Msk   = (0xFFFF << SCB_AIRCR_VECTKEYSTAT_Pos) @ SCB AIRCR: VECTKEYSTAT Mask
SCB_AIRCR_ENDIANESS_Pos     = 15                                    @ SCB AIRCR: ENDIANESS Position
SCB_AIRCR_ENDIANESS_Msk     = (1 << SCB_AIRCR_ENDIANESS_Pos)        @ SCB AIRCR: ENDIANESS Mask
SCB_AIRCR_PRIGROUP_Pos      = 8                                     @ SCB AIRCR: PRIGROUP Position
SCB_AIRCR_PRIGROUP_Msk      = (7 << SCB_AIRCR_PRIGROUP_Pos)         @ SCB AIRCR: PRIGROUP Mask
SCB_AIRCR_SYSRESETREQ_Pos   = 2                                     @ SCB AIRCR: SYSRESETREQ Position
SCB_AIRCR_SYSRESETREQ_Msk   = (1 << SCB_AIRCR_SYSRESETREQ_Pos)      @ SCB AIRCR: SYSRESETREQ Mask
SCB_AIRCR_VECTCLRACTIVE_Pos = 1                                     @ SCB AIRCR: VECTCLRACTIVE Position
SCB_AIRCR_VECTCLRACTIVE_Msk = (1 << SCB_AIRCR_VECTCLRACTIVE_Pos)    @ SCB AIRCR: VECTCLRACTIVE Mask
SCB_AIRCR_VECTRESET_Pos     = 0                                     @ SCB AIRCR: VECTRESET Position
SCB_AIRCR_VECTRESET_Msk     = (1 << SCB_AIRCR_VECTRESET_Pos)        @ SCB AIRCR: VECTRESET Mask

@ SCB System Control Register Definitions
SCB_SCR_SEVONPEND_Pos       = 4                                     @ SCB SCR: SEVONPEND Position
SCB_SCR_SEVONPEND_Msk       = (1 << SCB_SCR_SEVONPEND_Pos)          @ SCB SCR: SEVONPEND Mask
SCB_SCR_SLEEPDEEP_Pos       = 2                                     @ SCB SCR: SLEEPDEEP Position
SCB_SCR_SLEEPDEEP_Msk       = (1 << SCB_SCR_SLEEPDEEP_Pos)          @ SCB SCR: SLEEPDEEP Mask
SCB_SCR_SLEEPONEXIT_Pos     = 1                                     @ SCB SCR: SLEEPONEXIT Position
SCB_SCR_SLEEPONEXIT_Msk     = (1 << SCB_SCR_SLEEPONEXIT_Pos)        @ SCB SCR: SLEEPONEXIT Mask

@ SCB Configuration Control Register Definitions
SCB_CCR_STKALIGN_Pos        = 9                                     @ SCB CCR: STKALIGN Position
SCB_CCR_STKALIGN_Msk        = (1 << SCB_CCR_STKALIGN_Pos)           @ SCB CCR: STKALIGN Mask
SCB_CCR_BFHFNMIGN_Pos       = 8                                     @ SCB CCR: BFHFNMIGN Position
SCB_CCR_BFHFNMIGN_Msk       = (1 << SCB_CCR_BFHFNMIGN_Pos)          @ SCB CCR: BFHFNMIGN Mask
SCB_CCR_DIV_0_TRP_Pos       = 4                                     @ SCB CCR: DIV_0_TRP Position
SCB_CCR_DIV_0_TRP_Msk       = (1 << SCB_CCR_DIV_0_TRP_Pos)          @ SCB CCR: DIV_0_TRP Mask
SCB_CCR_UNALIGN_TRP_Pos     = 3                                     @ SCB CCR: UNALIGN_TRP Position
SCB_CCR_UNALIGN_TRP_Msk     = (1 << SCB_CCR_UNALIGN_TRP_Pos)        @ SCB CCR: UNALIGN_TRP Mask
SCB_CCR_USERSETMPEND_Pos    = 1                                     @ SCB CCR: USERSETMPEND Position
SCB_CCR_USERSETMPEND_Msk    = (1 << SCB_CCR_USERSETMPEND_Pos)       @ SCB CCR: USERSETMPEND Mask
SCB_CCR_NONBASETHRDENA_Pos  = 0                                     @ SCB CCR: NONBASETHRDENA Position
SCB_CCR_NONBASETHRDENA_Msk  = (1 << SCB_CCR_NONBASETHRDENA_Pos)     @ SCB CCR: NONBASETHRDENA Mask

@ SCB System Handler Control and State Register Definitions
SCB_SHCSR_USGFAULTENA_Pos    = 18                                   @ SCB SHCSR: USGFAULTENA Position
SCB_SHCSR_USGFAULTENA_Msk    = (1 << SCB_SHCSR_USGFAULTENA_Pos)     @ SCB SHCSR: USGFAULTENA Mask
SCB_SHCSR_BUSFAULTENA_Pos    = 17                                   @ SCB SHCSR: BUSFAULTENA Position
SCB_SHCSR_BUSFAULTENA_Msk    = (1 << SCB_SHCSR_BUSFAULTENA_Pos)     @ SCB SHCSR: BUSFAULTENA Mask
SCB_SHCSR_MEMFAULTENA_Pos    = 16                                   @ SCB SHCSR: MEMFAULTENA Position
SCB_SHCSR_MEMFAULTENA_Msk    = (1 << SCB_SHCSR_MEMFAULTENA_Pos)     @ SCB SHCSR: MEMFAULTENA Mask
SCB_SHCSR_SVCALLPENDED_Pos   = 15                                   @ SCB SHCSR: SVCALLPENDED Position
SCB_SHCSR_SVCALLPENDED_Msk   = (1 << SCB_SHCSR_SVCALLPENDED_Pos)    @ SCB SHCSR: SVCALLPENDED Mask
SCB_SHCSR_BUSFAULTPENDED_Pos = 14                                   @ SCB SHCSR: BUSFAULTPENDED Position
SCB_SHCSR_BUSFAULTPENDED_Msk = (1 << SCB_SHCSR_BUSFAULTPENDED_Pos)  @ SCB SHCSR: BUSFAULTPENDED Mask
SCB_SHCSR_MEMFAULTPENDED_Pos = 13                                   @ SCB SHCSR: MEMFAULTPENDED Position
SCB_SHCSR_MEMFAULTPENDED_Msk = (1 << SCB_SHCSR_MEMFAULTPENDED_Pos)  @ SCB SHCSR: MEMFAULTPENDED Mask
SCB_SHCSR_USGFAULTPENDED_Pos = 12                                   @ SCB SHCSR: USGFAULTPENDED Position
SCB_SHCSR_USGFAULTPENDED_Msk = (1 << SCB_SHCSR_USGFAULTPENDED_Pos)  @ SCB SHCSR: USGFAULTPENDED Mask
SCB_SHCSR_SYSTICKACT_Pos     = 11                                   @ SCB SHCSR: SYSTICKACT Position
SCB_SHCSR_SYSTICKACT_Msk     = (1 << SCB_SHCSR_SYSTICKACT_Pos)      @ SCB SHCSR: SYSTICKACT Mask
SCB_SHCSR_PENDSVACT_Pos      = 10                                   @ SCB SHCSR: PENDSVACT Position
SCB_SHCSR_PENDSVACT_Msk      = (1 << SCB_SHCSR_PENDSVACT_Pos)       @ SCB SHCSR: PENDSVACT Mask
SCB_SHCSR_MONITORACT_Pos     = 8                                    @ SCB SHCSR: MONITORACT Position
SCB_SHCSR_MONITORACT_Msk     = (1 << SCB_SHCSR_MONITORACT_Pos)      @ SCB SHCSR: MONITORACT Mask
SCB_SHCSR_SVCALLACT_Pos      = 7                                    @ SCB SHCSR: SVCALLACT Position
SCB_SHCSR_SVCALLACT_Msk      = (1 << SCB_SHCSR_SVCALLACT_Pos)       @ SCB SHCSR: SVCALLACT Mask
SCB_SHCSR_USGFAULTACT_Pos    = 3                                    @ SCB SHCSR: USGFAULTACT Position
SCB_SHCSR_USGFAULTACT_Msk    = (1 << SCB_SHCSR_USGFAULTACT_Pos)     @ SCB SHCSR: USGFAULTACT Mask
SCB_SHCSR_BUSFAULTACT_Pos    = 1                                    @ SCB SHCSR: BUSFAULTACT Position
SCB_SHCSR_BUSFAULTACT_Msk    = (1 << SCB_SHCSR_BUSFAULTACT_Pos)     @ SCB SHCSR: BUSFAULTACT Mask
SCB_SHCSR_MEMFAULTACT_Pos    = 0                                    @ SCB SHCSR: MEMFAULTACT Position
SCB_SHCSR_MEMFAULTACT_Msk    = (1 << SCB_SHCSR_MEMFAULTACT_Pos)     @ SCB SHCSR: MEMFAULTACT Mask

@ SCB Configurable Fault Status Registers Definitions
SCB_CFSR_USGFAULTSR_Pos     = 16                                    @ SCB CFSR: Usage Fault Status Register Position
SCB_CFSR_USGFAULTSR_Msk     = (0xFFFF << SCB_CFSR_USGFAULTSR_Pos)   @ SCB CFSR: Usage Fault Status Register Mask
SCB_CFSR_BUSFAULTSR_Pos     = 8                                     @ SCB CFSR: Bus Fault Status Register Position
SCB_CFSR_BUSFAULTSR_Msk     = (0xFF << SCB_CFSR_BUSFAULTSR_Pos)     @ SCB CFSR: Bus Fault Status Register Mask
SCB_CFSR_MEMFAULTSR_Pos     = 0                                     @ SCB CFSR: Memory Manage Fault Status Register Position
SCB_CFSR_MEMFAULTSR_Msk     = (0xFF << SCB_CFSR_MEMFAULTSR_Pos)     @ SCB CFSR: Memory Manage Fault Status Register Mask

@ SCB Hard Fault Status Registers Definitions
SCB_HFSR_DEBUGEVT_Pos       = 31                                    @ SCB HFSR: DEBUGEVT Position
SCB_HFSR_DEBUGEVT_Msk       = (1 << SCB_HFSR_DEBUGEVT_Pos)          @ SCB HFSR: DEBUGEVT Mask
SCB_HFSR_FORCED_Pos         = 30                                    @ SCB HFSR: FORCED Position
SCB_HFSR_FORCED_Msk         = (1 << SCB_HFSR_FORCED_Pos)            @ SCB HFSR: FORCED Mask
SCB_HFSR_VECTTBL_Pos        = 1                                     @ SCB HFSR: VECTTBL Position
SCB_HFSR_VECTTBL_Msk        = (1 << SCB_HFSR_VECTTBL_Pos)           @ SCB HFSR: VECTTBL Mask

@ SCB Debug Fault Status Register Definitions
SCB_DFSR_EXTERNAL_Pos       = 4                                     @ SCB DFSR: EXTERNAL Position
SCB_DFSR_EXTERNAL_Msk       = (1 << SCB_DFSR_EXTERNAL_Pos)          @ SCB DFSR: EXTERNAL Mask
SCB_DFSR_VCATCH_Pos         = 3                                     @ SCB DFSR: VCATCH Position
SCB_DFSR_VCATCH_Msk         = (1 << SCB_DFSR_VCATCH_Pos)            @ SCB DFSR: VCATCH Mask
SCB_DFSR_DWTTRAP_Pos        = 2                                     @ SCB DFSR: DWTTRAP Position
SCB_DFSR_DWTTRAP_Msk        = (1 << SCB_DFSR_DWTTRAP_Pos)           @ SCB DFSR: DWTTRAP Mask
SCB_DFSR_BKPT_Pos           = 1                                     @ SCB DFSR: BKPT Position
SCB_DFSR_BKPT_Msk           = (1 << SCB_DFSR_BKPT_Pos)              @ SCB DFSR: BKPT Mask
SCB_DFSR_HALTED_Pos         = 0                                     @ SCB DFSR: HALTED Position
SCB_DFSR_HALTED_Msk         = (1 << SCB_DFSR_HALTED_Pos)            @ SCB DFSR: HALTED Mask

@ System Controls not in SCB (SCnSCB) Registers

SCnSCB_ICTR  = SCS_BASE + 0x004                                     @ Interrupt Controller Type Register
SCnSCB_ACTLR = SCS_BASE + 0x008                                     @ Auxiliary Control Register

@ Interrupt Controller Type Register Definitions
SCnSCB_ICTR_INTLINESNUM_Pos = 0                                     @ ICTR: INTLINESNUM Position
SCnSCB_ICTR_INTLINESNUM_Msk = (0xF << SCnSCB_ICTR_INTLINESNUM_Pos)  @ ICTR: INTLINESNUM Mask

@ Auxiliary Control Register Definitions
SCnSCB_ACTLR_DISOOFP_Pos    = 9                                     @ ACTLR: DISOOFP Position
SCnSCB_ACTLR_DISOOFP_Msk    = (1 << SCnSCB_ACTLR_DISOOFP_Pos)       @ ACTLR: DISOOFP Mask
SCnSCB_ACTLR_DISFPCA_Pos    = 8                                     @ ACTLR: DISFPCA Position
SCnSCB_ACTLR_DISFPCA_Msk    = (1 << SCnSCB_ACTLR_DISFPCA_Pos)       @ ACTLR: DISFPCA Mask
SCnSCB_ACTLR_DISFOLD_Pos    = 2                                     @ ACTLR: DISFOLD Position
SCnSCB_ACTLR_DISFOLD_Msk    = (1 << SCnSCB_ACTLR_DISFOLD_Pos)       @ ACTLR: DISFOLD Mask
SCnSCB_ACTLR_DISDEFWBUF_Pos = 1                                     @ ACTLR: DISDEFWBUF Position
SCnSCB_ACTLR_DISDEFWBUF_Msk = (1 << SCnSCB_ACTLR_DISDEFWBUF_Pos)    @ ACTLR: DISDEFWBUF Mask
SCnSCB_ACTLR_DISMCYCINT_Pos = 0                                     @ ACTLR: DISMCYCINT Position
SCnSCB_ACTLR_DISMCYCINT_Msk = (1 << SCnSCB_ACTLR_DISMCYCINT_Pos)    @ ACTLR: DISMCYCINT Mask

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

@ Instrumentation Trace Macrocell (ITM) Registers

ITM_PORT    = ITM_BASE + 0x000                                      @ ITM Stimulus Port Registers              
ITM_TER     = ITM_BASE + 0xE00                                      @ ITM Trace Enable Register                
ITM_TPR     = ITM_BASE + 0xE40                                      @ ITM Trace Privilege Register             
ITM_TCR     = ITM_BASE + 0xE80                                      @ ITM Trace Control Register               
ITM_IWR     = ITM_BASE + 0xEF8                                      @ ITM Integration Write Register           
ITM_IRR     = ITM_BASE + 0xEFC                                      @ ITM Integration Read Register            
ITM_IMCR    = ITM_BASE + 0xF00                                      @ ITM Integration Mode Control Register    
ITM_LAR     = ITM_BASE + 0xFB0                                      @ ITM Lock Access Register                 
ITM_LSR     = ITM_BASE + 0xFB4                                      @ ITM Lock Status Register                 
ITM_PID4    = ITM_BASE + 0xFD0                                      @ ITM Peripheral Identification Register #4
ITM_PID5    = ITM_BASE + 0xFD4                                      @ ITM Peripheral Identification Register #5
ITM_PID6    = ITM_BASE + 0xFD8                                      @ ITM Peripheral Identification Register #6
ITM_PID7    = ITM_BASE + 0xFDC                                      @ ITM Peripheral Identification Register #7
ITM_PID0    = ITM_BASE + 0xFE0                                      @ ITM Peripheral Identification Register #0
ITM_PID1    = ITM_BASE + 0xFE4                                      @ ITM Peripheral Identification Register #1
ITM_PID2    = ITM_BASE + 0xFE8                                      @ ITM Peripheral Identification Register #2
ITM_PID3    = ITM_BASE + 0xFEC                                      @ ITM Peripheral Identification Register #3
ITM_CID0    = ITM_BASE + 0xFF0                                      @ ITM Component Identification Register #0
ITM_CID1    = ITM_BASE + 0xFF4                                      @ ITM Component Identification Register #1
ITM_CID2    = ITM_BASE + 0xFF8                                      @ ITM Component Identification Register #2
ITM_CID3    = ITM_BASE + 0xFFC                                      @ ITM Component Identification Register #3

@ ITM Trace Privilege Register Definitions
ITM_TPR_PRIVMASK_Pos        = 0                                     @ ITM TPR: PRIVMASK Position
ITM_TPR_PRIVMASK_Msk        = (0xF << ITM_TPR_PRIVMASK_Pos)         @ ITM TPR: PRIVMASK Mask

@ ITM Trace Control Register Definitions
ITM_TCR_BUSY_Pos            = 23                                    @ ITM TCR: BUSY Position
ITM_TCR_BUSY_Msk            = (1 << ITM_TCR_BUSY_Pos)               @ ITM TCR: BUSY Mask
ITM_TCR_TraceBusID_Pos      = 16                                    @ ITM TCR: ATBID Position
ITM_TCR_TraceBusID_Msk      = (0x7F << ITM_TCR_TraceBusID_Pos)      @ ITM TCR: ATBID Mask
ITM_TCR_GTSFREQ_Pos         = 10                                    @ ITM TCR: Global timestamp frequency Position
ITM_TCR_GTSFREQ_Msk         = (3 << ITM_TCR_GTSFREQ_Pos)            @ ITM TCR: Global timestamp frequency Mask
ITM_TCR_TSPrescale_Pos      = 8                                     @ ITM TCR: TSPrescale Position
ITM_TCR_TSPrescale_Msk      = (3 << ITM_TCR_TSPrescale_Pos)         @ ITM TCR: TSPrescale Mask
ITM_TCR_SWOENA_Pos          = 4                                     @ ITM TCR: SWOENA Position
ITM_TCR_SWOENA_Msk          = (1 << ITM_TCR_SWOENA_Pos)             @ ITM TCR: SWOENA Mask
ITM_TCR_DWTENA_Pos          = 3                                     @ ITM TCR: DWTENA Position
ITM_TCR_DWTENA_Msk          = (1 << ITM_TCR_DWTENA_Pos)             @ ITM TCR: DWTENA Mask
ITM_TCR_SYNCENA_Pos         = 2                                     @ ITM TCR: SYNCENA Position
ITM_TCR_SYNCENA_Msk         = (1 << ITM_TCR_SYNCENA_Pos)            @ ITM TCR: SYNCENA Mask
ITM_TCR_TSENA_Pos           = 1                                     @ ITM TCR: TSENA Position
ITM_TCR_TSENA_Msk           = (1 << ITM_TCR_TSENA_Pos)              @ ITM TCR: TSENA Mask
ITM_TCR_ITMENA_Pos          = 0                                     @ ITM TCR: ITM Enable bit Position
ITM_TCR_ITMENA_Msk          = (1 << ITM_TCR_ITMENA_Pos)             @ ITM TCR: ITM Enable bit Mask

@ ITM Integration Write Register Definitions
ITM_IWR_ATVALIDM_Pos        = 0                                     @ ITM IWR: ATVALIDM Position
ITM_IWR_ATVALIDM_Msk        = (1 << ITM_IWR_ATVALIDM_Pos)           @ ITM IWR: ATVALIDM Mask

@ ITM Integration Read Register Definitions
ITM_IRR_ATREADYM_Pos        = 0                                     @ ITM IRR: ATREADYM Position
ITM_IRR_ATREADYM_Msk        = (1 << ITM_IRR_ATREADYM_Pos)           @ ITM IRR: ATREADYM Mask

@ ITM Integration Mode Control Register Definitions 
ITM_IMCR_INTEGRATION_Pos    = 0                                     @ ITM IMCR: INTEGRATION Position
ITM_IMCR_INTEGRATION_Msk    = (1 << ITM_IMCR_INTEGRATION_Pos)       @ ITM IMCR: INTEGRATION Mask

@ ITM Lock Status Register Definitions 
ITM_LSR_ByteAcc_Pos         = 2                                     @ ITM LSR: ByteAcc Position
ITM_LSR_ByteAcc_Msk         = (1 << ITM_LSR_ByteAcc_Pos)            @ ITM LSR: ByteAcc Mask
ITM_LSR_Access_Pos          = 1                                     @ ITM LSR: Access Position
ITM_LSR_Access_Msk          = (1 << ITM_LSR_Access_Pos)             @ ITM LSR: Access Mask
ITM_LSR_Present_Pos         = 0                                     @ ITM LSR: Present Position
ITM_LSR_Present_Msk         = (1 << ITM_LSR_Present_Pos)            @ ITM LSR: Present Mask

@ Data Watchpoint and Trace (DWT) Registers

DWT_CTRL      = DWT_BASE + 0x000                                    @ Control Register
DWT_CYCCNT    = DWT_BASE + 0x004                                    @ Cycle Count Register
DWT_CPICNT    = DWT_BASE + 0x008                                    @ CPI Count Register
DWT_EXCCNT    = DWT_BASE + 0x00C                                    @ Exception Overhead Count Register
DWT_SLEEPCNT  = DWT_BASE + 0x010                                    @ Sleep Count Register
DWT_LSUCNT    = DWT_BASE + 0x014                                    @ LSU Count Register
DWT_FOLDCNT   = DWT_BASE + 0x018                                    @ Folded-instruction Count Register
DWT_PCSR      = DWT_BASE + 0x01C                                    @ Program Counter Sample Register
DWT_COMP0     = DWT_BASE + 0x020                                    @ Comparator Register 0
DWT_MASK0     = DWT_BASE + 0x024                                    @ Mask Register 0
DWT_FUNCTION0 = DWT_BASE + 0x028                                    @ Function Register 0
DWT_COMP1     = DWT_BASE + 0x030                                    @ Comparator Register 1
DWT_MASK1     = DWT_BASE + 0x034                                    @ Mask Register 1
DWT_FUNCTION1 = DWT_BASE + 0x038                                    @ Function Register 1
DWT_COMP2     = DWT_BASE + 0x040                                    @ Comparator Register 2
DWT_MASK2     = DWT_BASE + 0x044                                    @ Mask Register 2
DWT_FUNCTION2 = DWT_BASE + 0x048                                    @ Function Register 2
DWT_COMP3     = DWT_BASE + 0x050                                    @ Comparator Register 3
DWT_MASK3     = DWT_BASE + 0x054                                    @ Mask Register 3
DWT_FUNCTION3 = DWT_BASE + 0x058                                    @ Function Register 3

@ DWT Control Register Definitions
DWT_CTRL_NUMCOMP_Pos        = 28                                    @ DWT CTRL: NUMCOMP Position
DWT_CTRL_NUMCOMP_Msk        = (0xF << DWT_CTRL_NUMCOMP_Pos)         @ DWT CTRL: NUMCOMP Mask
DWT_CTRL_NOTRCPKT_Pos       = 27                                    @ DWT CTRL: NOTRCPKT Position
DWT_CTRL_NOTRCPKT_Msk       = (0x1 << DWT_CTRL_NOTRCPKT_Pos)        @ DWT CTRL: NOTRCPKT Mask
DWT_CTRL_NOEXTTRIG_Pos      = 26                                    @ DWT CTRL: NOEXTTRIG Position
DWT_CTRL_NOEXTTRIG_Msk      = (0x1 << DWT_CTRL_NOEXTTRIG_Pos)       @ DWT CTRL: NOEXTTRIG Mask
DWT_CTRL_NOCYCCNT_Pos       = 25                                    @ DWT CTRL: NOCYCCNT Position
DWT_CTRL_NOCYCCNT_Msk       = (0x1 << DWT_CTRL_NOCYCCNT_Pos)        @ DWT CTRL: NOCYCCNT Mask
DWT_CTRL_NOPRFCNT_Pos       = 24                                    @ DWT CTRL: NOPRFCNT Position
DWT_CTRL_NOPRFCNT_Msk       = (0x1 << DWT_CTRL_NOPRFCNT_Pos)        @ DWT CTRL: NOPRFCNT Mask
DWT_CTRL_CYCEVTENA_Pos      = 22                                    @ DWT CTRL: CYCEVTENA Position
DWT_CTRL_CYCEVTENA_Msk      = (0x1 << DWT_CTRL_CYCEVTENA_Pos)       @ DWT CTRL: CYCEVTENA Mask
DWT_CTRL_FOLDEVTENA_Pos     = 21                                    @ DWT CTRL: FOLDEVTENA Position
DWT_CTRL_FOLDEVTENA_Msk     = (0x1 << DWT_CTRL_FOLDEVTENA_Pos)      @ DWT CTRL: FOLDEVTENA Mask
DWT_CTRL_LSUEVTENA_Pos      = 20                                    @ DWT CTRL: LSUEVTENA Position
DWT_CTRL_LSUEVTENA_Msk      = (0x1 << DWT_CTRL_LSUEVTENA_Pos)       @ DWT CTRL: LSUEVTENA Mask
DWT_CTRL_SLEEPEVTENA_Pos    = 19                                    @ DWT CTRL: SLEEPEVTENA Position
DWT_CTRL_SLEEPEVTENA_Msk    = (0x1 << DWT_CTRL_SLEEPEVTENA_Pos)     @ DWT CTRL: SLEEPEVTENA Mask
DWT_CTRL_EXCEVTENA_Pos      = 18                                    @ DWT CTRL: EXCEVTENA Position
DWT_CTRL_EXCEVTENA_Msk      = (0x1 << DWT_CTRL_EXCEVTENA_Pos)       @ DWT CTRL: EXCEVTENA Mask
DWT_CTRL_CPIEVTENA_Pos      = 17                                    @ DWT CTRL: CPIEVTENA Position
DWT_CTRL_CPIEVTENA_Msk      = (0x1 << DWT_CTRL_CPIEVTENA_Pos)       @ DWT CTRL: CPIEVTENA Mask
DWT_CTRL_EXCTRCENA_Pos      = 16                                    @ DWT CTRL: EXCTRCENA Position
DWT_CTRL_EXCTRCENA_Msk      = (0x1 << DWT_CTRL_EXCTRCENA_Pos)       @ DWT CTRL: EXCTRCENA Mask
DWT_CTRL_PCSAMPLENA_Pos     = 12                                    @ DWT CTRL: PCSAMPLENA Position
DWT_CTRL_PCSAMPLENA_Msk     = (0x1 << DWT_CTRL_PCSAMPLENA_Pos)      @ DWT CTRL: PCSAMPLENA Mask
DWT_CTRL_SYNCTAP_Pos        = 10                                    @ DWT CTRL: SYNCTAP Position
DWT_CTRL_SYNCTAP_Msk        = (0x3 << DWT_CTRL_SYNCTAP_Pos)         @ DWT CTRL: SYNCTAP Mask
DWT_CTRL_CYCTAP_Pos         = 9                                     @ DWT CTRL: CYCTAP Position
DWT_CTRL_CYCTAP_Msk         = (0x1 << DWT_CTRL_CYCTAP_Pos)          @ DWT CTRL: CYCTAP Mask
DWT_CTRL_POSTINIT_Pos       = 5                                     @ DWT CTRL: POSTINIT Position
DWT_CTRL_POSTINIT_Msk       = (0xF << DWT_CTRL_POSTINIT_Pos)        @ DWT CTRL: POSTINIT Mask
DWT_CTRL_POSTPRESET_Pos     = 1                                     @ DWT CTRL: POSTPRESET Position
DWT_CTRL_POSTPRESET_Msk     = (0xF << DWT_CTRL_POSTPRESET_Pos)      @ DWT CTRL: POSTPRESET Mask
DWT_CTRL_CYCCNTENA_Pos      = 0                                     @ DWT CTRL: CYCCNTENA Position
DWT_CTRL_CYCCNTENA_Msk      = (0x1 << DWT_CTRL_CYCCNTENA_Pos)       @ DWT CTRL: CYCCNTENA Mask

@ DWT CPI Count Register Definitions
DWT_CPICNT_CPICNT_Pos       = 0                                     @ DWT CPICNT: CPICNT Position
DWT_CPICNT_CPICNT_Msk       = (0xFF << DWT_CPICNT_CPICNT_Pos)       @ DWT CPICNT: CPICNT Mask

@ DWT Exception Overhead Count Register Definitions
DWT_EXCCNT_EXCCNT_Pos       = 0                                     @ DWT EXCCNT: EXCCNT Position
DWT_EXCCNT_EXCCNT_Msk       = (0xFF << DWT_EXCCNT_EXCCNT_Pos)       @ DWT EXCCNT: EXCCNT Mask

@ DWT Sleep Count Register Definitions
DWT_SLEEPCNT_SLEEPCNT_Pos   = 0                                     @ DWT SLEEPCNT: SLEEPCNT Position
DWT_SLEEPCNT_SLEEPCNT_Msk   = (0xFF << DWT_SLEEPCNT_SLEEPCNT_Pos)   @ DWT SLEEPCNT: SLEEPCNT Mask

@ DWT LSU Count Register Definitions
DWT_LSUCNT_LSUCNT_Pos       = 0                                     @ DWT LSUCNT: LSUCNT Position
DWT_LSUCNT_LSUCNT_Msk       = (0xFF << DWT_LSUCNT_LSUCNT_Pos)       @ DWT LSUCNT: LSUCNT Mask

@ DWT Folded-instruction Count Register Definitions
DWT_FOLDCNT_FOLDCNT_Pos     = 0                                     @ DWT FOLDCNT: FOLDCNT Position
DWT_FOLDCNT_FOLDCNT_Msk     = (0xFF << DWT_FOLDCNT_FOLDCNT_Pos)     @ DWT FOLDCNT: FOLDCNT Mask

@ DWT Comparator Mask Register Definitions
DWT_MASK_MASK_Pos           = 0                                     @ DWT MASK: MASK Position
DWT_MASK_MASK_Msk           = (0x1F << DWT_MASK_MASK_Pos)           @ DWT MASK: MASK Mask

@ DWT Comparator Function Register Definitions
DWT_FUNCTION_MATCHED_Pos    = 24                                    @ DWT FUNCTION: MATCHED Position
DWT_FUNCTION_MATCHED_Msk    = (0x1 << DWT_FUNCTION_MATCHED_Pos)     @ DWT FUNCTION: MATCHED Mask
DWT_FUNCTION_DATAVADDR1_Pos = 16                                    @ DWT FUNCTION: DATAVADDR1 Position
DWT_FUNCTION_DATAVADDR1_Msk = (0xF << DWT_FUNCTION_DATAVADDR1_Pos)  @ DWT FUNCTION: DATAVADDR1 Mask
DWT_FUNCTION_DATAVADDR0_Pos = 12                                    @ DWT FUNCTION: DATAVADDR0 Position
DWT_FUNCTION_DATAVADDR0_Msk = (0xF << DWT_FUNCTION_DATAVADDR0_Pos)  @ DWT FUNCTION: DATAVADDR0 Mask
DWT_FUNCTION_DATAVSIZE_Pos  = 10                                    @ DWT FUNCTION: DATAVSIZE Position
DWT_FUNCTION_DATAVSIZE_Msk  = (0x3 << DWT_FUNCTION_DATAVSIZE_Pos)   @ DWT FUNCTION: DATAVSIZE Mask
DWT_FUNCTION_LNK1ENA_Pos    = 9                                     @ DWT FUNCTION: LNK1ENA Position
DWT_FUNCTION_LNK1ENA_Msk    = (0x1 << DWT_FUNCTION_LNK1ENA_Pos)     @ DWT FUNCTION: LNK1ENA Mask
DWT_FUNCTION_DATAVMATCH_Pos = 8                                     @ DWT FUNCTION: DATAVMATCH Position
DWT_FUNCTION_DATAVMATCH_Msk = (0x1 << DWT_FUNCTION_DATAVMATCH_Pos)  @ DWT FUNCTION: DATAVMATCH Mask
DWT_FUNCTION_CYCMATCH_Pos   = 7                                     @ DWT FUNCTION: CYCMATCH Position
DWT_FUNCTION_CYCMATCH_Msk   = (0x1 << DWT_FUNCTION_CYCMATCH_Pos)    @ DWT FUNCTION: CYCMATCH Mask
DWT_FUNCTION_EMITRANGE_Pos  = 5                                     @ DWT FUNCTION: EMITRANGE Position
DWT_FUNCTION_EMITRANGE_Msk  = (0x1 << DWT_FUNCTION_EMITRANGE_Pos)   @ DWT FUNCTION: EMITRANGE Mask
DWT_FUNCTION_FUNCTION_Pos   = 0                                     @ DWT FUNCTION: FUNCTION Position
DWT_FUNCTION_FUNCTION_Msk   = (0xF << DWT_FUNCTION_FUNCTION_Pos)    @ DWT FUNCTION: FUNCTION Mask

@ Trace Port Interface (TPI) Registers

TPI_SSPSR     = TPI_BASE + 0x000                                    @ Supported Parallel Port Size Register    
TPI_CSPSR     = TPI_BASE + 0x004                                    @ Current Parallel Port Size Register
TPI_ACPR      = TPI_BASE + 0x010                                    @ Asynchronous Clock Prescaler Register
TPI_SPPR      = TPI_BASE + 0x0F0                                    @ Selected Pin Protocol Register
TPI_FFSR      = TPI_BASE + 0x300                                    @ Formatter and Flush Status Register
TPI_FFCR      = TPI_BASE + 0x304                                    @ Formatter and Flush Control Register
TPI_FSCR      = TPI_BASE + 0x308                                    @ Formatter Synchronization Counter Register
TPI_TRIGGER   = TPI_BASE + 0xEE8                                    @ TRIGGER
TPI_FIFO0     = TPI_BASE + 0xEEC                                    @ Integration ETM Data
TPI_ITATBCTR2 = TPI_BASE + 0xEF0                                    @ ITATBCTR2
TPI_ITATBCTR0 = TPI_BASE + 0xEF8                                    @ ITATBCTR0
TPI_FIFO1     = TPI_BASE + 0xEFC                                    @ Integration ITM Data
TPI_ITCTRL    = TPI_BASE + 0xF00                                    @ Integration Mode Control
TPI_CLAIMSET  = TPI_BASE + 0xFA0                                    @ Claim tag set
TPI_CLAIMCLR  = TPI_BASE + 0xFA4                                    @ Claim tag clear
TPI_DEVID     = TPI_BASE + 0xFC8                                    @ TPIU_DEVID
TPI_DEVTYPE   = TPI_BASE + 0xFCC                                    @ TPIU_DEVTYPE


@ TPI Asynchronous Clock Prescaler Register Definitions
TPI_ACPR_PRESCALER_Pos      = 0                                     @ TPI ACPR: PRESCALER Position
TPI_ACPR_PRESCALER_Msk      = (0x1FFF << TPI_ACPR_PRESCALER_Pos)    @ TPI ACPR: PRESCALER Mask

@ TPI Selected Pin Protocol Register Definitions
TPI_SPPR_TXMODE_Pos         = 0                                     @ TPI SPPR: TXMODE Position
TPI_SPPR_TXMODE_Msk         = (0x3 << TPI_SPPR_TXMODE_Pos)          @ TPI SPPR: TXMODE Mask

@ TPI Formatter and Flush Status Register Definitions
TPI_FFSR_FtNonStop_Pos      = 3                                     @ TPI FFSR: FtNonStop Position
TPI_FFSR_FtNonStop_Msk      = (0x1 << TPI_FFSR_FtNonStop_Pos)       @ TPI FFSR: FtNonStop Mask
TPI_FFSR_TCPresent_Pos      = 2                                     @ TPI FFSR: TCPresent Position
TPI_FFSR_TCPresent_Msk      = (0x1 << TPI_FFSR_TCPresent_Pos)       @ TPI FFSR: TCPresent Mask
TPI_FFSR_FtStopped_Pos      = 1                                     @ TPI FFSR: FtStopped Position
TPI_FFSR_FtStopped_Msk      = (0x1 << TPI_FFSR_FtStopped_Pos)       @ TPI FFSR: FtStopped Mask
TPI_FFSR_FlInProg_Pos       = 0                                     @ TPI FFSR: FlInProg Position
TPI_FFSR_FlInProg_Msk       = (0x1 << TPI_FFSR_FlInProg_Pos)        @ TPI FFSR: FlInProg Mask

@ TPI Formatter and Flush Control Register Definitions
TPI_FFCR_TrigIn_Pos         = 8                                     @ TPI FFCR: TrigIn Position
TPI_FFCR_TrigIn_Msk         = (0x1 << TPI_FFCR_TrigIn_Pos)          @ TPI FFCR: TrigIn Mask
TPI_FFCR_EnFCont_Pos        = 1                                     @ TPI FFCR: EnFCont Position
TPI_FFCR_EnFCont_Msk        = (0x1 << TPI_FFCR_EnFCont_Pos)         @ TPI FFCR: EnFCont Mask

@ TPI TRIGGER Register Definitions
TPI_TRIGGER_TRIGGER_Pos     = 0                                     @ TPI TRIGGER: TRIGGER Position
TPI_TRIGGER_TRIGGER_Msk     = (0x1 << TPI_TRIGGER_TRIGGER_Pos)      @ TPI TRIGGER: TRIGGER Mask

@ TPI Integration ETM Data Register Definitions (FIFO0)
TPI_FIFO0_ITM_ATVALID_Pos   = 29                                    @ TPI FIFO0: ITM_ATVALID Position
TPI_FIFO0_ITM_ATVALID_Msk   = (0x3 << TPI_FIFO0_ITM_ATVALID_Pos)    @ TPI FIFO0: ITM_ATVALID Mask
TPI_FIFO0_ITM_bytecount_Pos = 27                                    @ TPI FIFO0: ITM_bytecount Position
TPI_FIFO0_ITM_bytecount_Msk = (0x3 << TPI_FIFO0_ITM_bytecount_Pos)  @ TPI FIFO0: ITM_bytecount Mask
TPI_FIFO0_ETM_ATVALID_Pos   = 26                                    @ TPI FIFO0: ETM_ATVALID Position
TPI_FIFO0_ETM_ATVALID_Msk   = (0x3 << TPI_FIFO0_ETM_ATVALID_Pos)    @ TPI FIFO0: ETM_ATVALID Mask
TPI_FIFO0_ETM_bytecount_Pos = 24                                    @ TPI FIFO0: ETM_bytecount Position
TPI_FIFO0_ETM_bytecount_Msk = (0x3 << TPI_FIFO0_ETM_bytecount_Pos)  @ TPI FIFO0: ETM_bytecount Mask
TPI_FIFO0_ETM2_Pos          = 16                                    @ TPI FIFO0: ETM2 Position
TPI_FIFO0_ETM2_Msk          = (0xFF << TPI_FIFO0_ETM2_Pos)          @ TPI FIFO0: ETM2 Mask
TPI_FIFO0_ETM1_Pos          = 8                                     @ TPI FIFO0: ETM1 Position
TPI_FIFO0_ETM1_Msk          = (0xFF << TPI_FIFO0_ETM1_Pos)          @ TPI FIFO0: ETM1 Mask
TPI_FIFO0_ETM0_Pos          = 0                                     @ TPI FIFO0: ETM0 Position
TPI_FIFO0_ETM0_Msk          = (0xFF << TPI_FIFO0_ETM0_Pos)          @ TPI FIFO0: ETM0 Mask

@ TPI ITATBCTR2 Register Definitions
TPI_ITATBCTR2_ATREADY_Pos   = 0                                     @ TPI ITATBCTR2: ATREADY Position
TPI_ITATBCTR2_ATREADY_Msk   = (0x1 << TPI_ITATBCTR2_ATREADY_Pos)    @ TPI ITATBCTR2: ATREADY Mask

@ TPI Integration ITM Data Register Definitions (FIFO1)
TPI_FIFO1_ITM_ATVALID_Pos   = 29                                    @ TPI FIFO1: ITM_ATVALID Position
TPI_FIFO1_ITM_ATVALID_Msk   = (0x3 << TPI_FIFO1_ITM_ATVALID_Pos)    @ TPI FIFO1: ITM_ATVALID Mask
TPI_FIFO1_ITM_bytecount_Pos = 27                                    @ TPI FIFO1: ITM_bytecount Position
TPI_FIFO1_ITM_bytecount_Msk = (0x3 << TPI_FIFO1_ITM_bytecount_Pos)  @ TPI FIFO1: ITM_bytecount Mask
TPI_FIFO1_ETM_ATVALID_Pos   = 26                                    @ TPI FIFO1: ETM_ATVALID Position
TPI_FIFO1_ETM_ATVALID_Msk   = (0x3 << TPI_FIFO1_ETM_ATVALID_Pos)    @ TPI FIFO1: ETM_ATVALID Mask
TPI_FIFO1_ETM_bytecount_Pos = 24                                    @ TPI FIFO1: ETM_bytecount Position
TPI_FIFO1_ETM_bytecount_Msk = (0x3 << TPI_FIFO1_ETM_bytecount_Pos)  @ TPI FIFO1: ETM_bytecount Mask
TPI_FIFO1_ITM2_Pos          = 16                                    @ TPI FIFO1: ITM2 Position
TPI_FIFO1_ITM2_Msk          = (0xFF << TPI_FIFO1_ITM2_Pos)          @ TPI FIFO1: ITM2 Mask
TPI_FIFO1_ITM1_Pos          = 8                                     @ TPI FIFO1: ITM1 Position
TPI_FIFO1_ITM1_Msk          = (0xFF << TPI_FIFO1_ITM1_Pos)          @ TPI FIFO1: ITM1 Mask
TPI_FIFO1_ITM0_Pos          = 0                                     @ TPI FIFO1: ITM0 Position
TPI_FIFO1_ITM0_Msk          = (0xFF << TPI_FIFO1_ITM0_Pos)          @ TPI FIFO1: ITM0 Mask

@ TPI ITATBCTR0 Register Definitions
TPI_ITATBCTR0_ATREADY_Pos   = 0                                     @ TPI ITATBCTR0: ATREADY Position
TPI_ITATBCTR0_ATREADY_Msk   = (0x1 << TPI_ITATBCTR0_ATREADY_Pos)    @ TPI ITATBCTR0: ATREADY Mask

@ TPI Integration Mode Control Register Definitions
TPI_ITCTRL_Mode_Pos         = 0                                     @ TPI ITCTRL: Mode Position
TPI_ITCTRL_Mode_Msk         = (0x1 << TPI_ITCTRL_Mode_Pos)          @ TPI ITCTRL: Mode Mask

@ TPI DEVID Register Definitions
TPI_DEVID_NRZVALID_Pos      = 11                                    @ TPI DEVID: NRZVALID Position
TPI_DEVID_NRZVALID_Msk      = (0x1 << TPI_DEVID_NRZVALID_Pos)       @ TPI DEVID: NRZVALID Mask
TPI_DEVID_MANCVALID_Pos     = 10                                    @ TPI DEVID: MANCVALID Position
TPI_DEVID_MANCVALID_Msk     = (0x1 << TPI_DEVID_MANCVALID_Pos)      @ TPI DEVID: MANCVALID Mask
TPI_DEVID_PTINVALID_Pos     = 9                                     @ TPI DEVID: PTINVALID Position
TPI_DEVID_PTINVALID_Msk     = (0x1 << TPI_DEVID_PTINVALID_Pos)      @ TPI DEVID: PTINVALID Mask
TPI_DEVID_MinBufSz_Pos      = 6                                     @ TPI DEVID: MinBufSz Position
TPI_DEVID_MinBufSz_Msk      = (0x7 << TPI_DEVID_MinBufSz_Pos)       @ TPI DEVID: MinBufSz Mask
TPI_DEVID_AsynClkIn_Pos     = 5                                     @ TPI DEVID: AsynClkIn Position
TPI_DEVID_AsynClkIn_Msk     = (0x1 << TPI_DEVID_AsynClkIn_Pos)      @ TPI DEVID: AsynClkIn Mask
TPI_DEVID_NrTraceInput_Pos  = 0                                     @ TPI DEVID: NrTraceInput Position
TPI_DEVID_NrTraceInput_Msk  = (0x1F << TPI_DEVID_NrTraceInput_Pos)  @ TPI DEVID: NrTraceInput Mask

@ TPI DEVTYPE Register Definitions
TPI_DEVTYPE_SubType_Pos     = 0                                     @ TPI DEVTYPE: SubType Position
TPI_DEVTYPE_SubType_Msk     = (0xF << TPI_DEVTYPE_SubType_Pos)      @ TPI DEVTYPE: SubType Mask
TPI_DEVTYPE_MajorType_Pos   = 4                                     @ TPI DEVTYPE: MajorType Position
TPI_DEVTYPE_MajorType_Msk   = (0xF << TPI_DEVTYPE_MajorType_Pos)    @ TPI DEVTYPE: MajorType Mask

#if (__MPU_PRESENT == 1)

@ Memory Protection Unit (MPU) Registers
MPU_TYPE    = MPU_BASE + 0x000                                      @ MPU Type Register
MPU_CTRL    = MPU_BASE + 0x004                                      @ MPU Control Register
MPU_RNR     = MPU_BASE + 0x008                                      @ MPU Region RNRber Register
MPU_RBAR    = MPU_BASE + 0x00C                                      @ MPU Region Base Address Register
MPU_RASR    = MPU_BASE + 0x010                                      @ MPU Region Attribute and Size Register
MPU_RBAR_A1 = MPU_BASE + 0x014                                      @ MPU Alias 1 Region Base Address Register
MPU_RASR_A1 = MPU_BASE + 0x018                                      @ MPU Alias 1 Region Attribute and Size Register
MPU_RBAR_A2 = MPU_BASE + 0x01C                                      @ MPU Alias 2 Region Base Address Register
MPU_RASR_A2 = MPU_BASE + 0x020                                      @ MPU Alias 2 Region Attribute and Size Register
MPU_RBAR_A3 = MPU_BASE + 0x024                                      @ MPU Alias 3 Region Base Address Register
MPU_RASR_A3 = MPU_BASE + 0x028                                      @ MPU Alias 3 Region Attribute and Size Register

@ MPU Type Register
MPU_TYPE_IREGION_Pos        = 16                                    @ MPU TYPE: IREGION Position
MPU_TYPE_IREGION_Msk        = (0xFF << MPU_TYPE_IREGION_Pos)        @ MPU TYPE: IREGION Mask
MPU_TYPE_DREGION_Pos        = 8                                     @ MPU TYPE: DREGION Position
MPU_TYPE_DREGION_Msk        = (0xFF << MPU_TYPE_DREGION_Pos)        @ MPU TYPE: DREGION Mask
MPU_TYPE_SEPARATE_Pos       = 0                                     @ MPU TYPE: SEPARATE Position
MPU_TYPE_SEPARATE_Msk       = (1 << MPU_TYPE_SEPARATE_Pos)          @ MPU TYPE: SEPARATE Mask

@ MPU Control Register
MPU_CTRL_PRIVDEFENA_Pos     = 2                                     @ MPU CTRL: PRIVDEFENA Position
MPU_CTRL_PRIVDEFENA_Msk     = (1 << MPU_CTRL_PRIVDEFENA_Pos)        @ MPU CTRL: PRIVDEFENA Mask
MPU_CTRL_HFNMIENA_Pos       = 1                                     @ MPU CTRL: HFNMIENA Position
MPU_CTRL_HFNMIENA_Msk       = (1 << MPU_CTRL_HFNMIENA_Pos)          @ MPU CTRL: HFNMIENA Mask
MPU_CTRL_ENABLE_Pos         = 0                                     @ MPU CTRL: ENABLE Position
MPU_CTRL_ENABLE_Msk         = (1 << MPU_CTRL_ENABLE_Pos)            @ MPU CTRL: ENABLE Mask

@ MPU Region Number Register
MPU_RNR_REGION_Pos          = 0                                     @ MPU RNR: REGION Position
MPU_RNR_REGION_Msk          = (0xFF << MPU_RNR_REGION_Pos)          @ MPU RNR: REGION Mask

@ MPU Region Base Address Register
MPU_RBAR_ADDR_Pos           = 5                                     @ MPU RBAR: ADDR Position
MPU_RBAR_ADDR_Msk           = (0x7FFFFFF << MPU_RBAR_ADDR_Pos)      @ MPU RBAR: ADDR Mask
MPU_RBAR_VALID_Pos          = 4                                     @ MPU RBAR: VALID Position
MPU_RBAR_VALID_Msk          = (1 << MPU_RBAR_VALID_Pos)             @ MPU RBAR: VALID Mask
MPU_RBAR_REGION_Pos         = 0                                     @ MPU RBAR: REGION Position
MPU_RBAR_REGION_Msk         = (0xF << MPU_RBAR_REGION_Pos)          @ MPU RBAR: REGION Mask

@ MPU Region Attribute and Size Register
MPU_RASR_ATTRS_Pos          = 16                                    @ MPU RASR: MPU Region Attribute field Position
MPU_RASR_ATTRS_Msk          = (0xFFFF << MPU_RASR_ATTRS_Pos)        @ MPU RASR: MPU Region Attribute field Mask
MPU_RASR_XN_Pos             = 28                                    @ MPU RASR: ATTRS.XN Position
MPU_RASR_XN_Msk             = (1 << MPU_RASR_XN_Pos)                @ MPU RASR: ATTRS.XN Mask
MPU_RASR_AP_Pos             = 24                                    @ MPU RASR: ATTRS.AP Position
MPU_RASR_AP_Msk             = (0x7 << MPU_RASR_AP_Pos)              @ MPU RASR: ATTRS.AP Mask
MPU_RASR_TEX_Pos            = 19                                    @ MPU RASR: ATTRS.TEX Position
MPU_RASR_TEX_Msk            = (0x7 << MPU_RASR_TEX_Pos)             @ MPU RASR: ATTRS.TEX Mask
MPU_RASR_S_Pos              = 18                                    @ MPU RASR: ATTRS.S Position
MPU_RASR_S_Msk              = (1 << MPU_RASR_S_Pos)                 @ MPU RASR: ATTRS.S Mask
MPU_RASR_C_Pos              = 17                                    @ MPU RASR: ATTRS.C Position
MPU_RASR_C_Msk              = (1 << MPU_RASR_C_Pos)                 @ MPU RASR: ATTRS.C Mask
MPU_RASR_B_Pos              = 16                                    @ MPU RASR: ATTRS.B Position
MPU_RASR_B_Msk              = (1 << MPU_RASR_B_Pos)                 @ MPU RASR: ATTRS.B Mask
MPU_RASR_SRD_Pos            = 8                                     @ MPU RASR: Sub-Region Disable Position
MPU_RASR_SRD_Msk            = (0xFF << MPU_RASR_SRD_Pos)            @ MPU RASR: Sub-Region Disable Mask
MPU_RASR_SIZE_Pos           = 1                                     @ MPU RASR: Region Size Field Position
MPU_RASR_SIZE_Msk           = (0x1F << MPU_RASR_SIZE_Pos)           @ MPU RASR: Region Size Field Mask
MPU_RASR_ENABLE_Pos         = 0                                     @ MPU RASR: Region enable bit Position
MPU_RASR_ENABLE_Msk         = (1 << MPU_RASR_ENABLE_Pos)            @ MPU RASR: Region enable bit Disable Mask

#endif

#if (__FPU_PRESENT == 1)

@ Floating Point Unit (FPU) Registers

FPU_FPCCR  = FPU_BASE + 0x004                                       @ Floating-Point Context Control Register               
FPU_FPCAR  = FPU_BASE + 0x008                                       @ Floating-Point Context Address Register               
FPU_FPDSCR = FPU_BASE + 0x00C                                       @ Floating-Point Default Status Control Register        
FPU_MVFR0  = FPU_BASE + 0x010                                       @ Media and FP Feature Register 0                       
FPU_MVFR1  = FPU_BASE + 0x014                                       @ Media and FP Feature Register 1                       

@ Floating-Point Context Control Register 
FPU_FPCCR_ASPEN_Pos         = 31                                    @ FPCCR: ASPEN bit Position
FPU_FPCCR_ASPEN_Msk         = (1 << FPU_FPCCR_ASPEN_Pos)            @ FPCCR: ASPEN bit Mask
FPU_FPCCR_LSPEN_Pos         = 30                                    @ FPCCR: LSPEN Position
FPU_FPCCR_LSPEN_Msk         = (1 << FPU_FPCCR_LSPEN_Pos)            @ FPCCR: LSPEN bit Mask
FPU_FPCCR_MONRDY_Pos        = 8                                     @ FPCCR: MONRDY Position
FPU_FPCCR_MONRDY_Msk        = (1 << FPU_FPCCR_MONRDY_Pos)           @ FPCCR: MONRDY bit Mask
FPU_FPCCR_BFRDY_Pos         = 6                                     @ FPCCR: BFRDY Position
FPU_FPCCR_BFRDY_Msk         = (1 << FPU_FPCCR_BFRDY_Pos)            @ FPCCR: BFRDY bit Mask
FPU_FPCCR_MMRDY_Pos         = 5                                     @ FPCCR: MMRDY Position
FPU_FPCCR_MMRDY_Msk         = (1 << FPU_FPCCR_MMRDY_Pos)            @ FPCCR: MMRDY bit Mask
FPU_FPCCR_HFRDY_Pos         = 4                                     @ FPCCR: HFRDY Position
FPU_FPCCR_HFRDY_Msk         = (1 << FPU_FPCCR_HFRDY_Pos)            @ FPCCR: HFRDY bit Mask
FPU_FPCCR_THREAD_Pos        = 3                                     @ FPCCR: processor mode bit Position
FPU_FPCCR_THREAD_Msk        = (1 << FPU_FPCCR_THREAD_Pos)           @ FPCCR: processor mode active bit Mask
FPU_FPCCR_USER_Pos          = 1                                     @ FPCCR: privilege level bit Position
FPU_FPCCR_USER_Msk          = (1 << FPU_FPCCR_USER_Pos)             @ FPCCR: privilege level bit Mask
FPU_FPCCR_LSPACT_Pos        = 0                                     @ FPCCR: Lazy state preservation active bit Position
FPU_FPCCR_LSPACT_Msk        = (1 << FPU_FPCCR_LSPACT_Pos)           @ FPCCR: Lazy state preservation active bit Mask

@ Floating-Point Context Address Register 
FPU_FPCAR_ADDRESS_Pos       = 3                                     @ FPCAR: ADDRESS bit Position
FPU_FPCAR_ADDRESS_Msk       = (0x1FFFFFFF << FPU_FPCAR_ADDRESS_Pos) @ FPCAR: ADDRESS bit Mask

@ Floating-Point Default Status Control Register 
FPU_FPDSCR_AHP_Pos          = 26                                    @ FPDSCR: AHP bit Position
FPU_FPDSCR_AHP_Msk          = (1 << FPU_FPDSCR_AHP_Pos)             @ FPDSCR: AHP bit Mask
FPU_FPDSCR_DN_Pos           = 25                                    @ FPDSCR: DN bit Position
FPU_FPDSCR_DN_Msk           = (1 << FPU_FPDSCR_DN_Pos)              @ FPDSCR: DN bit Mask
FPU_FPDSCR_FZ_Pos           = 24                                    @ FPDSCR: FZ bit Position
FPU_FPDSCR_FZ_Msk           = (1 << FPU_FPDSCR_FZ_Pos)              @ FPDSCR: FZ bit Mask
FPU_FPDSCR_RMode_Pos        = 22                                    @ FPDSCR: RMode bit Position
FPU_FPDSCR_RMode_Msk        = (3 << FPU_FPDSCR_RMode_Pos)           @ FPDSCR: RMode bit Mask

@ Media and FP Feature Register 0 
FPU_MVFR0_FP_rounding_modes_Pos = 28                                       @ MVFR0: FP rounding modes bits Position
FPU_MVFR0_FP_rounding_modes_Msk = (0xF << FPU_MVFR0_FP_rounding_modes_Pos) @ MVFR0: FP rounding modes bits Mask
FPU_MVFR0_Short_vectors_Pos     = 24                                       @ MVFR0: Short vectors bits Position
FPU_MVFR0_Short_vectors_Msk     = (0xF << FPU_MVFR0_Short_vectors_Pos)     @ MVFR0: Short vectors bits Mask
FPU_MVFR0_Square_root_Pos       = 20                                       @ MVFR0: Square root bits Position
FPU_MVFR0_Square_root_Msk       = (0xF << FPU_MVFR0_Square_root_Pos)       @ MVFR0: Square root bits Mask
FPU_MVFR0_Divide_Pos            = 16                                       @ MVFR0: Divide bits Position
FPU_MVFR0_Divide_Msk            = (0xF << FPU_MVFR0_Divide_Pos)            @ MVFR0: Divide bits Mask
FPU_MVFR0_FP_excep_trapping_Pos = 12                                       @ MVFR0: FP exception trapping bits Position
FPU_MVFR0_FP_excep_trapping_Msk = (0xF << FPU_MVFR0_FP_excep_trapping_Pos) @ MVFR0: FP exception trapping bits Mask
FPU_MVFR0_Double_precision_Pos  = 8                                        @ MVFR0: Double-precision bits Position
FPU_MVFR0_Double_precision_Msk  = (0xF << FPU_MVFR0_Double_precision_Pos)  @ MVFR0: Double-precision bits Mask
FPU_MVFR0_Single_precision_Pos  = 4                                        @ MVFR0: Single-precision bits Position
FPU_MVFR0_Single_precision_Msk  = (0xF << FPU_MVFR0_Single_precision_Pos)  @ MVFR0: Single-precision bits Mask
FPU_MVFR0_A_SIMD_registers_Pos  = 0                                        @ MVFR0: A_SIMD registers bits Position
FPU_MVFR0_A_SIMD_registers_Msk  = (0xF << FPU_MVFR0_A_SIMD_registers_Pos)  @ MVFR0: A_SIMD registers bits Mask

@ Media and FP Feature Register 1 
FPU_MVFR1_FP_fused_MAC_Pos  = 28                                    @ MVFR1: FP fused MAC bits Position
FPU_MVFR1_FP_fused_MAC_Msk  = (0xF << FPU_MVFR1_FP_fused_MAC_Pos)   @ MVFR1: FP fused MAC bits Mask
FPU_MVFR1_FP_HPFP_Pos       = 24                                    @ MVFR1: FP HPFP bits Position
FPU_MVFR1_FP_HPFP_Msk       = (0xF << FPU_MVFR1_FP_HPFP_Pos)        @ MVFR1: FP HPFP bits Mask
FPU_MVFR1_D_NaN_mode_Pos    = 4                                     @ MVFR1: D_NaN mode bits Position
FPU_MVFR1_D_NaN_mode_Msk    = (0xF << FPU_MVFR1_D_NaN_mode_Pos)     @ MVFR1: D_NaN mode bits Mask
FPU_MVFR1_FtZ_mode_Pos      = 0                                     @ MVFR1: FtZ mode bits Position
FPU_MVFR1_FtZ_mode_Msk      = (0xF << FPU_MVFR1_FtZ_mode_Pos)       @ MVFR1: FtZ mode bits Mask

#endif

@ Core Debug Registers (CoreDebug) Registers

CoreDebug_DHCSR = CoreDebugBase + 0x000                             @ Debug Halting Control and Status Register
CoreDebug_DCRSR = CoreDebugBase + 0x004                             @ Debug Core Register Selector Register
CoreDebug_DCRDR = CoreDebugBase + 0x008                             @ Debug Core Register Data Register
CoreDebug_DEMCR = CoreDebugBase + 0x00C                             @ Debug Exception and Monitor Control Register

@ Debug Halting Control and Status Register
CoreDebug_DHCSR_DBGKEY_Pos      = 16                                     @ CoreDebug DHCSR: DBGKEY Position
CoreDebug_DHCSR_DBGKEY_Msk      = (0xFFFF << CoreDebug_DHCSR_DBGKEY_Pos) @ CoreDebug DHCSR: DBGKEY Mask
CoreDebug_DHCSR_S_RESET_ST_Pos  = 25                                     @ CoreDebug DHCSR: S_RESET_ST Position
CoreDebug_DHCSR_S_RESET_ST_Msk  = (1 << CoreDebug_DHCSR_S_RESET_ST_Pos)  @ CoreDebug DHCSR: S_RESET_ST Mask
CoreDebug_DHCSR_S_RETIRE_ST_Pos = 24                                     @ CoreDebug DHCSR: S_RETIRE_ST Position
CoreDebug_DHCSR_S_RETIRE_ST_Msk = (1 << CoreDebug_DHCSR_S_RETIRE_ST_Pos) @ CoreDebug DHCSR: S_RETIRE_ST Mask
CoreDebug_DHCSR_S_LOCKUP_Pos    = 19                                     @ CoreDebug DHCSR: S_LOCKUP Position
CoreDebug_DHCSR_S_LOCKUP_Msk    = (1 << CoreDebug_DHCSR_S_LOCKUP_Pos)    @ CoreDebug DHCSR: S_LOCKUP Mask
CoreDebug_DHCSR_S_SLEEP_Pos     = 18                                     @ CoreDebug DHCSR: S_SLEEP Position
CoreDebug_DHCSR_S_SLEEP_Msk     = (1 << CoreDebug_DHCSR_S_SLEEP_Pos)     @ CoreDebug DHCSR: S_SLEEP Mask
CoreDebug_DHCSR_S_HALT_Pos      = 17                                     @ CoreDebug DHCSR: S_HALT Position
CoreDebug_DHCSR_S_HALT_Msk      = (1 << CoreDebug_DHCSR_S_HALT_Pos)      @ CoreDebug DHCSR: S_HALT Mask
CoreDebug_DHCSR_S_REGRDY_Pos    = 16                                     @ CoreDebug DHCSR: S_REGRDY Position
CoreDebug_DHCSR_S_REGRDY_Msk    = (1 << CoreDebug_DHCSR_S_REGRDY_Pos)    @ CoreDebug DHCSR: S_REGRDY Mask
CoreDebug_DHCSR_C_SNAPSTALL_Pos = 5                                      @ CoreDebug DHCSR: C_SNAPSTALL Position
CoreDebug_DHCSR_C_SNAPSTALL_Msk = (1 << CoreDebug_DHCSR_C_SNAPSTALL_Pos) @ CoreDebug DHCSR: C_SNAPSTALL Mask
CoreDebug_DHCSR_C_MASKINTS_Pos  = 3                                      @ CoreDebug DHCSR: C_MASKINTS Position
CoreDebug_DHCSR_C_MASKINTS_Msk  = (1 << CoreDebug_DHCSR_C_MASKINTS_Pos)  @ CoreDebug DHCSR: C_MASKINTS Mask
CoreDebug_DHCSR_C_STEP_Pos      = 2                                      @ CoreDebug DHCSR: C_STEP Position
CoreDebug_DHCSR_C_STEP_Msk      = (1 << CoreDebug_DHCSR_C_STEP_Pos)      @ CoreDebug DHCSR: C_STEP Mask
CoreDebug_DHCSR_C_HALT_Pos      = 1                                      @ CoreDebug DHCSR: C_HALT Position
CoreDebug_DHCSR_C_HALT_Msk      = (1 << CoreDebug_DHCSR_C_HALT_Pos)      @ CoreDebug DHCSR: C_HALT Mask
CoreDebug_DHCSR_C_DEBUGEN_Pos   = 0                                      @ CoreDebug DHCSR: C_DEBUGEN Position
CoreDebug_DHCSR_C_DEBUGEN_Msk   = (1 << CoreDebug_DHCSR_C_DEBUGEN_Pos)   @ CoreDebug DHCSR: C_DEBUGEN Mask

@ Debug Core Register Selector Register
CoreDebug_DCRSR_REGWnR_Pos  = 16                                    @ CoreDebug DCRSR: REGWnR Position
CoreDebug_DCRSR_REGWnR_Msk  = (1 << CoreDebug_DCRSR_REGWnR_Pos)     @ CoreDebug DCRSR: REGWnR Mask
CoreDebug_DCRSR_REGSEL_Pos  = 0                                     @ CoreDebug DCRSR: REGSEL Position
CoreDebug_DCRSR_REGSEL_Msk  = (0x1F << CoreDebug_DCRSR_REGSEL_Pos)  @ CoreDebug DCRSR: REGSEL Mask

@ Debug Exception and Monitor Control Register
CoreDebug_DEMCR_TRCENA_Pos       = 24                                      @ CoreDebug DEMCR: TRCENA Position
CoreDebug_DEMCR_TRCENA_Msk       = (1 << CoreDebug_DEMCR_TRCENA_Pos)       @ CoreDebug DEMCR: TRCENA Mask
CoreDebug_DEMCR_MON_REQ_Pos      = 19                                      @ CoreDebug DEMCR: MON_REQ Position
CoreDebug_DEMCR_MON_REQ_Msk      = (1 << CoreDebug_DEMCR_MON_REQ_Pos)      @ CoreDebug DEMCR: MON_REQ Mask
CoreDebug_DEMCR_MON_STEP_Pos     = 18                                      @ CoreDebug DEMCR: MON_STEP Position
CoreDebug_DEMCR_MON_STEP_Msk     = (1 << CoreDebug_DEMCR_MON_STEP_Pos)     @ CoreDebug DEMCR: MON_STEP Mask
CoreDebug_DEMCR_MON_PEND_Pos     = 17                                      @ CoreDebug DEMCR: MON_PEND Position
CoreDebug_DEMCR_MON_PEND_Msk     = (1 << CoreDebug_DEMCR_MON_PEND_Pos)     @ CoreDebug DEMCR: MON_PEND Mask
CoreDebug_DEMCR_MON_EN_Pos       = 16                                      @ CoreDebug DEMCR: MON_EN Position
CoreDebug_DEMCR_MON_EN_Msk       = (1 << CoreDebug_DEMCR_MON_EN_Pos)       @ CoreDebug DEMCR: MON_EN Mask
CoreDebug_DEMCR_VC_HARDERR_Pos   = 10                                      @ CoreDebug DEMCR: VC_HARDERR Position
CoreDebug_DEMCR_VC_HARDERR_Msk   = (1 << CoreDebug_DEMCR_VC_HARDERR_Pos)   @ CoreDebug DEMCR: VC_HARDERR Mask
CoreDebug_DEMCR_VC_INTERR_Pos    = 9                                       @ CoreDebug DEMCR: VC_INTERR Position
CoreDebug_DEMCR_VC_INTERR_Msk    = (1 << CoreDebug_DEMCR_VC_INTERR_Pos)    @ CoreDebug DEMCR: VC_INTERR Mask
CoreDebug_DEMCR_VC_BUSERR_Pos    = 8                                       @ CoreDebug DEMCR: VC_BUSERR Position
CoreDebug_DEMCR_VC_BUSERR_Msk    = (1 << CoreDebug_DEMCR_VC_BUSERR_Pos)    @ CoreDebug DEMCR: VC_BUSERR Mask
CoreDebug_DEMCR_VC_STATERR_Pos   = 7                                       @ CoreDebug DEMCR: VC_STATERR Position
CoreDebug_DEMCR_VC_STATERR_Msk   = (1 << CoreDebug_DEMCR_VC_STATERR_Pos)   @ CoreDebug DEMCR: VC_STATERR Mask
CoreDebug_DEMCR_VC_CHKERR_Pos    = 6                                       @ CoreDebug DEMCR: VC_CHKERR Position
CoreDebug_DEMCR_VC_CHKERR_Msk    = (1 << CoreDebug_DEMCR_VC_CHKERR_Pos)    @ CoreDebug DEMCR: VC_CHKERR Mask
CoreDebug_DEMCR_VC_NOCPERR_Pos   = 5                                       @ CoreDebug DEMCR: VC_NOCPERR Position
CoreDebug_DEMCR_VC_NOCPERR_Msk   = (1 << CoreDebug_DEMCR_VC_NOCPERR_Pos)   @ CoreDebug DEMCR: VC_NOCPERR Mask
CoreDebug_DEMCR_VC_MMERR_Pos     = 4                                       @ CoreDebug DEMCR: VC_MMERR Position
CoreDebug_DEMCR_VC_MMERR_Msk     = (1 << CoreDebug_DEMCR_VC_MMERR_Pos)     @ CoreDebug DEMCR: VC_MMERR Mask
CoreDebug_DEMCR_VC_CORERESET_Pos = 0                                       @ CoreDebug DEMCR: VC_CORERESET Position
CoreDebug_DEMCR_VC_CORERESET_Msk = (1 << CoreDebug_DEMCR_VC_CORERESET_Pos) @ CoreDebug DEMCR: VC_CORERESET Mask

#endif /* __CORE_CM4_H_DEPENDANT */

#endif /* __CMSIS_GENERIC */
