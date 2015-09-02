/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ copy the application program vector table to the start of the SRAM, tell the controller to use that vector table
@ and redirect to the applications reset handler

    module(ApplicationRun)

    .extern         _application_orgin                              @ where the application main code resides (from linker script)
    .extern         _boot_ram_orgin                                 @ where the boot ram starts (from linker script)
    .extern         _boot_ram_length                                @ boot ram size aka vector table size, (from linker script)

    public_function(AppRun_boot)

@ void ApplicationRun() - doesn't return
@   copy the vector table and reset to the user reset handler
@   uses a copy of http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0204j/Cacbiccc.html
@   but adapted to copy 4 bytes at a time, not 8 bytes

AppRun_boot:
                    ldr             r0, = #_application_orgin       @ location of alt vector map
                    ldr             r1, = #_boot_ram_orgin          @ where to copy into memory
                    ldr             r2, = #_boot_ram_length         @ number of 4 words to copy
                    lsrs            r2, #4                          @ (can't >> on a value from the linker)
0:
                    ldm             r0!, {r3-r6}                    @ load 4 words from source
                    stm             r1!, {r3-r6}                    @ save them to the destination
                    dsb                                             @ sync memory
                    subs            r2, r2, #1
                    bne             0b

                    ldr             r6, = #_RCC_APB2ENR             @ enable SYSCFG peripheral clock
                    ldr             r0, [r6]                        @ which is mildly odd to have to
                    movs            r1, #RCC_APB2ENR_SYSCFGCOMPEN   @ enable...
                    orrs            r0, r0, r1
                    str             r0, [r6]

                    ldr             r6, = #_SYSCFG_CFGR1            @ map memory to SRAM
                    ldr             r0, [r6]
                    movs            r1, #SYSCFG_CFGR1_MEM_MODE
                    orrs            r0, r0, r1
                    str             r0, [r6]

                    ldr             r0, = #(_boot_ram_orgin + 4)    @ get reset vector...
                    ldr             r0, [r0]
                    bx              r0                              @ ...and branch to the user code reset vector

    .end

