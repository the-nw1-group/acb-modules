/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "acb/functionHeaders.inc"

#ifdef __STM32F0XX_STARTUP

@ startup file for the stm32f04xx series of microcontrollers

    module(Startup)
                                                                    @ various locations - defined in linker script
    .extern         __stack                                         @ stack top location
    .extern         _sidata                                         @ start address for the initialization values of the .data section
    .extern         _sdata                                          @ start address for the .data section
    .extern         _edata                                          @ end address for the .data section
    .extern         _sbss                                           @ start address for the .bss section
    .extern         _ebss                                           @ end address for the .bss section

    .extern         System_init                                     @ initialise system
    .extern         main                                            @ the main code

@ vector table

    .section        .isr_vector, "a",  %progbits                    @ don't change this, linker script requires this
    .type           __vectorMap, %object                            @ section name
    .size           __vectorMap, .-__vectorMap

__vectorMap:
    .word           __stack                                         @ first location is the top of the stack
    .word           __resetHandler                                  @ reset handler
    .word           __nmiHandler
    .word           __hardFaultHandler
    .word           0
    .word           0
    .word           0
    .word           0
    .word           0
    .word           0
    .word           0
    .word           __svcHandler
    .word           0
    .word           0
    .word           __pendSVHandler
    .word           __sysTickHandler
#if defined(STM32F042)
    .word           __wwdgIRQHandler
    .word           __pvdVddio2IRQHandler
    .word           __rtcIRQHandler
    .word           __flashIRQHandler
    .word           __rccCrsIRQHandler
    .word           __exti01IRQHandler
    .word           __exti23IRQHandler
    .word           __exti415IRQHandler
    .word           __tscIRQHandler
    .word           __dma1Channel1IRQHandler
    .word           __dma1Channel23IRQHandler
    .word           __dma1Channel4567IRQHandler
    .word           __adc1CompIRQHandler
    .word           __tim1BrkUpTrgComIRQHandler
    .word           __tim1CcIRQHandler
    .word           __tim2IRQHandler
    .word           __tim3IRQHandler
    .word           0
    .word           0
    .word           __tim14IRQHandler
    .word           0
    .word           __tim16IRQHandler
    .word           __tim17IRQHandler
    .word           __i2c1IRQHandler
    .word           0
    .word           __spi1IRQHandler
    .word           __spi2IRQHandler
    .word           __usart1IRQHandler
    .word           __usart2IRQHandler
    .word           0
    .word           __cecCanIRQHandler
    .word           __usbIRQHandler
 #elif defined(STM32F072)
    .word           __wwdgIRQHandler
    .word           __pvdVddio2IRQHandler
    .word           __rtcIRQHandler
    .word           __flashIRQHandler
    .word           __rccCrsIRQHandler
    .word           __exti01IRQHandler
    .word           __exti23IRQHandler
    .word           __exti415IRQHandler
    .word           __tscIRQHandler
    .word           __dma1Channel1IRQHandler
    .word           __dma1Channel23IRQHandler
    .word           __dma1Channel4567IRQHandler
    .word           __adc1CompIRQHandler
    .word           __tim1BrkUpTrgComIRQHandler
    .word           __tim1CcIRQHandler
    .word           __tim2IRQHandler
    .word           __tim3IRQHandler
    .word           __tim6DacIRQHandler
    .word           __tim7IRQHandler
    .word           __tim14IRQHandler
    .word           __tim15IRQHandler
    .word           __tim16IRQHandler
    .word           __tim17IRQHandler
    .word           __i2c1IRQHandler
    .word           __i2c2IRQHandler
    .word           __spi1IRQHandler
    .word           __spi2IRQHandler
    .word           __usart1IRQHandler
    .word           __usart2IRQHandler
    .word           __usart34IRQHandler
    .word           __cecCanIRQHandler
    .word           __usbIRQHandler
 #endif
__vectorMapEnd:

@ provide weak aliases for all the exception handlers

    .weak           __nmiHandler
    .thumb_set      __nmiHandler, __defaultHandler
    .weak           __hardFaultHandler
    .thumb_set      __hardFaultHandler, __defaultHandler
    .weak           __svcHandler
    .thumb_set      __svcHandler, __defaultHandler
    .weak           __pendSVHandler
    .thumb_set      __pendSVHandler, __defaultHandler
    .weak           __sysTickHandler
    .thumb_set      __sysTickHandler, __defaultHandler

    .weak           __wwdgIRQHandler
    .thumb_set      __wwdgIRQHandler, __defaultHandler
    .weak           __pvdVddio2IRQHandler
    .thumb_set      __pvdVddio2IRQHandler, __defaultHandler
    .weak           __rtcIRQHandler
    .thumb_set      __rtcIRQHandler, __defaultHandler
    .weak           __flashIRQHandler
    .thumb_set      __flashIRQHandler, __defaultHandler
    .weak           __rccCrsIRQHandler
    .thumb_set      __rccCrsIRQHandler, __defaultHandler
    .weak           __exti01IRQHandler
    .thumb_set      __exti01IRQHandler, __defaultHandler
    .weak           __exti23IRQHandler
    .thumb_set      __exti23IRQHandler, __defaultHandler
    .weak           __exti415IRQHandler
    .thumb_set      __exti415IRQHandler, __defaultHandler
    .weak           __tscIRQHandler
    .thumb_set      __tscIRQHandler, __defaultHandler
    .weak           __dma1Channel1IRQHandler
    .thumb_set      __dma1Channel1IRQHandler, __defaultHandler
    .weak           __dma1Channel23IRQHandler
    .thumb_set      __dma1Channel23IRQHandler, __defaultHandler
    .weak           __dma1Channel4567IRQHandler
    .thumb_set      __dma1Channel4567IRQHandler, __defaultHandler
    .weak           __adc1CompIRQHandler
    .thumb_set      __adc1CompIRQHandler, __defaultHandler
    .weak           __tim1BrkUpTrgComIRQHandler
    .thumb_set      __tim1BrkUpTrgComIRQHandler, __defaultHandler
    .weak           __tim1CcIRQHandler
    .thumb_set      __tim1CcIRQHandler, __defaultHandler
    .weak           __tim2IRQHandler
    .thumb_set      __tim2IRQHandler, __defaultHandler
    .weak           __tim3IRQHandler
    .thumb_set      __tim3IRQHandler, __defaultHandler
    .weak           __tim6DacIRQHandler
    .thumb_set      __tim6DacIRQHandler, __defaultHandler
    .weak           __tim7IRQHandler
    .thumb_set      __tim7IRQHandler, __defaultHandler
    .weak           __tim14IRQHandler
    .thumb_set      __tim14IRQHandler, __defaultHandler
    .weak           __tim15IRQHandler
    .thumb_set      __tim15IRQHandler, __defaultHandler
    .weak           __tim16IRQHandler
    .thumb_set      __tim16IRQHandler, __defaultHandler
    .weak           __tim17IRQHandler
    .thumb_set      __tim17IRQHandler, __defaultHandler
    .weak           __i2c1IRQHandler
    .thumb_set      __i2c1IRQHandler, __defaultHandler
    .weak           __i2c2IRQHandler
    .thumb_set      __i2c2IRQHandler, __defaultHandler
    .weak           __spi1IRQHandler
    .thumb_set      __spi1IRQHandler, __defaultHandler
    .weak           __spi2IRQHandler
    .thumb_set      __spi2IRQHandler, __defaultHandler
    .weak           __usart1IRQHandler
    .thumb_set      __usart1IRQHandler, __defaultHandler
    .weak           __usart2IRQHandler
    .thumb_set      __usart2IRQHandler, __defaultHandler
    .weak           __usart34IRQHandler
    .thumb_set      __usart34IRQHandler, __defaultHandler
    .weak           __cecCanIRQHandler
    .thumb_set      __cecCanIRQHandler, __defaultHandler
    .weak           __usbIRQHandler
    .thumb_set      __usbIRQHandler, __defaultHandler

    av_public_override(__defaultHandler)

@ default handler

__defaultHandler:                                                   @ drop into an infinite loop
                    b               .

    av_private_function(__resetHandler)

@ reset handler

__resetHandler:
                    ldr             r0, = #__stack                  @ initialize the Stack Pointer
                    mov             sp, r0

__copyFlashDataToSRAM:
                    movs            r1, #0
                    b               __copyDataLoop
__copyDataInit:                                                     @ copy data segment initializers from flash to SRAM
                    ldr             r3, =_sidata
                    ldr             r3, [r3, r1]
                    str             r3, [r0, r1]
                    adds            r1, r1, #4
__copyDataLoop:
                    ldr             r0, = #_sdata
                    ldr             r3, = #_edata
                    adds            r2, r0, r1
                    cmp             r2, r3
                    bcc             __copyDataInit

                    ldr             r2, = #_sbss                    @ zero fill the BSS section
                    b               __zeroFillLoop
__zeroFillBSS:
                    movs            r3, #0
                    str             r3, [r2]
                    adds            r2, r2, #4
__zeroFillLoop:
                    ldr             r3, = #_ebss
                    cmp             r2, r3
                    bcc             __zeroFillBSS

__initSystemClocks:
                    bl              System_init                     @ initialise system clock, flash interface, etc..
__runProgram:
                    bl              main
1:
                    b               1b                              @ loop forever

#endif

    .end
