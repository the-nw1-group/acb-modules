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
    .extern         AppRun_boot                                     @ boot the embedded application, rather than the bootloader

@ vector table

    .section        .isr_vector, "a",  %progbits                    @ don't change this, linker script requires this
    .type           __vectorMap, %object                            @ section name
    .size           __vectorMap, .-__vectorMap

__vectorMap:
    .word           __stack                                         @ first location is the top of the stack
    .word           __resetHandler                                  @ reset handler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           0
    .word           0
    .word           0
    .word           0
    .word           __defaultHandler
    .word           __defaultHandler
    .word           0
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           0
    .word           0
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           0
    .word           0
    .word           0
    .word           0
    .word           0
    .word           0
    .word           0
    .word           __defaultHandler
    .word           0
    .word           __defaultHandler
    .word           0
    .word           0
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           0
    .word           0
    .word           0
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           0
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
    .word           0
    .word           __defaultHandler
    .word           __defaultHandler
    .word           0
    .word           0
    .word           __defaultHandler
    .word           __defaultHandler
    .word           __defaultHandler
__vectorMapEnd:

    public_override(__defaultHandler)

@ default handler

__defaultHandler:                                                   @ drop into an infinite loop
                    b               .

    private_function(__resetHandler)

@ reset handler

__resetHandler:
                    ldr             r0, = #__stack                  @ initialize the Stack Pointer
                    mov             sp, r0

__checkForBootloaderMode:
                    ldr             r6, = #_FLASH_OPTR              @ check boot option byte 0 bit 1
                    ldr             r0, [r6]                        @ to see if we need to go into
                    tst             r0, #(1<<(BOOTLOAD_OPTION_WORD)) @ boot mode
                    beq             __bootloaderBoot
                    bl              AppRun_boot                     @ normal boot

__bootloaderBoot:
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

    .end
