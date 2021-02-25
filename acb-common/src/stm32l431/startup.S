/*
 * Copyright (c) 2021 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ startup file for the stm32l431 series of microcontrollers

#ifdef __STM32L431XX_STARTUP

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
    .word           __memManageHandler
    .word           __busFaultHandler
    .word           __usageFaultHandler
    .word           0
    .word           0
    .word           0
    .word           0
    .word           __svcHandler
    .word           __debugMonHandler
    .word           0
    .word           __pendSVHandler
    .word           __sysTickHandler
    .word           __wwdgIRQHandler
    .word           __pvdIRQHandler
    .word           __tamperStampIRQHandler
    .word           __rtcWkupIRQHandler
    .word           __flashIRQHandler
    .word           __rccIRQHandler
    .word           __exti0IRQHandler
    .word           __exti1IRQHandler
    .word           __exti2TsIRQHandler
    .word           __exti3IRQHandler
    .word           __exti4IRQHandler
    .word           __dma1Channel1IRQHandler
    .word           __dma1Channel2IRQHandler
    .word           __dma1Channel3IRQHandler
    .word           __dma1Channel4IRQHandler
    .word           __dma1Channel5IRQHandler
    .word           __dma1Channel6IRQHandler
    .word           __dma1Channel7IRQHandler
    .word           __adc1IRQHandler
    .word           __can1TxIRQHandler
    .word           __can1Rx0IRQHandler
    .word           __can1Rx1IRQHandler
    .word           __can1SceIRQHandler
    .word           __exti95IRQHandler
    .word           __tim1BrkTim15IRQHandler
    .word           __tim1UpTim16IRQHandler
    .word           __tim1TrgComIRQHandler
    .word           __tim1CcIRQHandler
    .word           __tim2IRQHandler
    .word           0
    .word           0
    .word           __i2c1EvIRQHandler
    .word           __i2c1ErIRQHandler
    .word           __i2c2EvIRQHandler
    .word           __i2c2EeIRQHandler
    .word           __spi1IRQHandler
    .word           __spi2IRQHandler
    .word           __usart1IRQHandler
    .word           __usart2IRQHandler
    .word           __usart3IRQHandler
    .word           __exti1510IRQHandler
    .word           __rtcAlarmIRQHandler
    .word           0
    .word           0
    .word           0
    .word           0
    .word           0
    .word           0
    .word           0
    .word           __sdmmc1IRQHandler
    .word           0
    .word           __spi3IRQHandler
    .word           0
    .word           0
    .word           __tim6DacIRQHandler
    .word           __tim7IRQHandler
    .word           __dma2Channel1IRQHandler
    .word           __dma2Channel2IRQHandler
    .word           __dma2Channel3IRQHandler
    .word           __dma2Channel4IRQHandler
    .word           __dma2Channel5IRQHandler
    .word           0
    .word           0
    .word           0
    .word           __compIRQHandler
    .word           __lptim1IRQHandler
    .word           __lptim2IRQHandler
    .word           0
    .word           __dma2Channel6IRQHandler
    .word           __dma2Channel7IRQHandler
    .word           __lpuart1IRQHandler
    .word           __quadspiIRQHandler
    .word           __i2c3EvIRQHandler
    .word           __i2c3ErIRQHandler
    .word           __sai1IRQHandler
    .word           0
    .word           __sqpmi1IRQHandler
    .word           __tscIRQHandler
    .word           0
    .word           0
    .word           __rngIRQHandler
    .word           __fpuIRQHandler
    .word           __crsIRQHandler
__vectorMapEnd:

@ provide weak aliases for all the exception handlers

    .weak           __nmiHandler
    .thumb_set      __nmiHandler, __defaultHandler
    .weak           __hardFaultHandler
    .thumb_set      __hardFaultHandler, __defaultHandler
    .weak           __memManageHandler
    .thumb_set      __memManageHandler, __defaultHandler
    .weak           __busFaultHandler
    .thumb_set      __busFaultHandler, __defaultHandler
    .weak           __usageFaultHandler
    .thumb_set      __usageFaultHandler, __defaultHandler
    .weak           __svcHandler
    .thumb_set      __svcHandler, __defaultHandler
    .weak           __debugMonHandler
    .thumb_set      __debugMonHandler, __defaultHandler
    .weak           __pendSVHandler
    .thumb_set      __pendSVHandler, __defaultHandler
    .weak           __sysTickHandler
    .thumb_set      __sysTickHandler, __defaultHandler
    .weak           __wwdgIRQHandler
    .thumb_set      __wwdgIRQHandler, __defaultHandler
    .weak           __pvdIRQHandler
    .thumb_set      __pvdIRQHandler, __defaultHandler
    .weak           __tamperStampIRQHandler
    .thumb_set      __tamperStampIRQHandler, __defaultHandler
    .weak           __rtcWkupIRQHandler
    .thumb_set      __rtcWkupIRQHandler, __defaultHandler
    .weak           __flashIRQHandler
    .thumb_set      __flashIRQHandler, __defaultHandler
    .weak           __rccIRQHandler
    .thumb_set      __rccIRQHandler, __defaultHandler
    .weak           __exti0IRQHandler
    .thumb_set      __exti0IRQHandler, __defaultHandler
    .weak           __exti1IRQHandler
    .thumb_set      __exti1IRQHandler, __defaultHandler
    .weak           __exti2TsIRQHandler
    .thumb_set      __exti2TsIRQHandler, __defaultHandler
    .weak           __exti3IRQHandler
    .thumb_set      __exti3IRQHandler, __defaultHandler
    .weak           __exti4IRQHandler
    .thumb_set      __exti4IRQHandler, __defaultHandler
    .weak           __dma1Channel1IRQHandler
    .thumb_set      __dma1Channel1IRQHandler, __defaultHandler
    .weak           __dma1Channel2IRQHandler
    .thumb_set      __dma1Channel2IRQHandler, __defaultHandler
    .weak           __dma1Channel3IRQHandler
    .thumb_set      __dma1Channel3IRQHandler, __defaultHandler
    .weak           __dma1Channel4IRQHandler
    .thumb_set      __dma1Channel4IRQHandler, __defaultHandler
    .weak           __dma1Channel5IRQHandler
    .thumb_set      __dma1Channel5IRQHandler, __defaultHandler
    .weak           __dma1Channel6IRQHandler
    .thumb_set      __dma1Channel6IRQHandler, __defaultHandler
    .weak           __dma1Channel7IRQHandler
    .thumb_set      __dma1Channel7IRQHandler, __defaultHandler
    .weak           __adc1IRQHandler
    .thumb_set      __adc1IRQHandler, __defaultHandler
    .weak           __can1TxIRQHandler
    .thumb_set      __can1TxIRQHandler, __defaultHandler
    .weak           __can1Rx0IRQHandler
    .thumb_set      __can1Rx0IRQHandler, __defaultHandler
    .weak           __can1Rx1IRQHandler
    .thumb_set      __can1Rx1IRQHandler, __defaultHandler
    .weak           __can1SceIRQHandler
    .thumb_set      __can1SceIRQHandler, __defaultHandler
    .weak           __exti95IRQHandler
    .thumb_set      __exti95IRQHandler, __defaultHandler
    .weak           __tim1BrkTim15IRQHandler
    .thumb_set      __tim1BrkTim15IRQHandler, __defaultHandler
    .weak           __tim1UpTim16IRQHandler
    .thumb_set      __tim1UpTim16IRQHandler, __defaultHandler
    .weak           __tim1TrgComIRQHandler
    .thumb_set      __tim1TrgComIRQHandler, __defaultHandler
    .weak           __tim1CcIRQHandler
    .thumb_set      __tim1CcIRQHandler, __defaultHandler
    .weak           __tim2IRQHandler
    .thumb_set      __tim2IRQHandler, __defaultHandler
    .weak           __sdmmc1IRQHandler
    .thumb_set      __sdmmc1IRQHandler, __defaultHandler
    .weak           __dma2Channel6IRQHandler
    .thumb_set      __dma2Channel6IRQHandler, __defaultHandler
    .weak           __i2c1EvIRQHandler
    .thumb_set      __i2c1EvIRQHandler, __defaultHandler
    .weak           __i2c1ErIRQHandler
    .thumb_set      __i2c1ErIRQHandler, __defaultHandler
    .weak           __i2c2EvIRQHandler
    .thumb_set      __i2c2EvIRQHandler, __defaultHandler
    .weak           __i2c2EeIRQHandler
    .thumb_set      __i2c2EeIRQHandler, __defaultHandler
    .weak           __spi1IRQHandler
    .thumb_set      __spi1IRQHandler, __defaultHandler
    .weak           __spi2IRQHandler
    .thumb_set      __spi2IRQHandler, __defaultHandler
    .weak           __usart1IRQHandler
    .thumb_set      __usart1IRQHandler, __defaultHandler
    .weak           __usart2IRQHandler
    .thumb_set      __usart2IRQHandler, __defaultHandler
    .weak           __usart3IRQHandler
    .thumb_set      __usart3IRQHandler, __defaultHandler
    .weak           __exti1510IRQHandler
    .thumb_set      __exti1510IRQHandler, __defaultHandler
    .weak           __rtcAlarmIRQHandler
    .thumb_set      __rtcAlarmIRQHandler, __defaultHandler
    .weak           __dma2Channel7IRQHandler
    .thumb_set      __dma2Channel7IRQHandler, __defaultHandler
    .weak           __lpuart1IRQHandler
    .thumb_set      __lpuart1IRQHandler, __defaultHandler
    .weak           __quadspiIRQHandler
    .thumb_set      __quadspiIRQHandler, __defaultHandler
    .weak           __i2c3EvIRQHandler
    .thumb_set      __i2c3EvIRQHandler, __defaultHandler
    .weak           __i2c3ErIRQHandler
    .thumb_set      __i2c3ErIRQHandler, __defaultHandler
    .weak           __tscIRQHandler
    .thumb_set      __tscIRQHandler, __defaultHandler
    .weak           __spi3IRQHandler
    .thumb_set      __spi3IRQHandler, __defaultHandler
    .weak           __rngIRQHandler
    .thumb_set      __rngIRQHandler, __defaultHandler
    .weak           __crsIRQHandler
    .thumb_set      __crsIRQHandler, __defaultHandler
    .weak           __tim6DacIRQHandler
    .thumb_set      __tim6DacIRQHandler, __defaultHandler
    .weak           __tim7IRQHandler
    .thumb_set      __tim7IRQHandler, __defaultHandler
    .weak           __dma2Channel1IRQHandler
    .thumb_set      __dma2Channel1IRQHandler, __defaultHandler
    .weak           __dma2Channel2IRQHandler
    .thumb_set      __dma2Channel2IRQHandler, __defaultHandler
    .weak           __dma2Channel3IRQHandler
    .thumb_set      __dma2Channel3IRQHandler, __defaultHandler
    .weak           __dma2Channel4IRQHandler
    .thumb_set      __dma2Channel4IRQHandler, __defaultHandler
    .weak           __dma2Channel5IRQHandler
    .thumb_set      __dma2Channel5IRQHandler, __defaultHandler
    .weak           __compIRQHandler
    .thumb_set      __compIRQHandler, __defaultHandler
    .weak           __lptim1IRQHandler
    .thumb_set      __lptim1IRQHandler, __defaultHandler
    .weak           __lptim2IRQHandler
    .thumb_set      __lptim2IRQHandler, __defaultHandler
    .weak           __sai1IRQHandler
    .thumb_set      __sai1IRQHandler, __defaultHandler
    .weak           __sqpmi1IRQHandler
    .thumb_set      __sqpmi1IRQHandler, __defaultHandler
    .weak           __fpuIRQHandler
    .thumb_set      __fpuIRQHandler, __defaultHandler

    public_override(__defaultHandler)

@ default handler

__defaultHandler:                                                   @ drop into an infinite loop
                    b               .

    private_function(__resetHandler)

@ reset handler

__resetHandler:
                    ldr             r0, = #__stack                  @ initialize the Stack Pointer
                    mov             sp, r0

__copyFlashDataToSRAM:
                    movs            r1, #0
                    b               __copyDataLoop
__copyDataInit:                                                     @ copy data segment initializers from flash to SRAM
                    ldr             r3, = #_sidata
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
                    str             r3, [r2], #4
__zeroFillLoop:
                    ldr             r3, = _ebss
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
