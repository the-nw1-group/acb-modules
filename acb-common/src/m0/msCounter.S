/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "core_cm0.inc"
#include "acb/functionHeaders.inc"

    .extern         Math_divu1000                                   @ unsigned integer divide by 1000
    .extern         SysTick_config                                  @ configure the SysTick core peripheral

    module(MsCounter)

@ public variables

    public_data(MsCounter_globals)
    .global         MsCounter_milliseconds

MsCounter_milliseconds:
                    .word           0


@ A simple millisecond counter - using SysTick to provide the implementation

    public_function(MsCounter_init)

@ void MsCounter_init(uint systemFrequency)
@   initialise the millisecond counter based on the supplied system frequency.

MsCounter_init:
                    push            {r7, lr}
                    bl              Math_divu1000                   @ divide clock frequency by 1000
                    bl              SysTick_config
                    pop             {r7, pc}

    public_function(__sysTickHandler)

@ void __sysTickHandler()
@   interrupt handler for the system tick timer

__sysTickHandler:
                    ldr             r0, = # MsCounter_milliseconds
                    ldr             r1, [r0]
                    adds            r1, r1, #1
                    str             r1, [r0]
                    bx              lr

    .end
