/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "acb/errorHandler.inc"

    module(ErrorHandler)

#if defined(DEBUG)

    private_data(ErrorHandler_private)

ErrorHandler_stackFrame:
                    .space          4 * 9                           @ stack frame for faults (plus an extra for r0)
#endif

@ override standard ACB error handler as we don't have yellow and green LEDs

    public_function(ErrorHandler_handle)

@ void ErrorHandler_handle(int errorCode)
@   Last chance fatal error handler

ErrorHandler_handle:
                    cpsid           i                               @ disable all configurable interrupts
#if defined(DEBUG)
                    movs            r2, #4                          @ test LR (exception return, which is in r1)
                    tst             r2, r1                          @ check EXC_RETURN to see if PSP or MSP was used
                    beq             0f
                    mrs             r1, psp                         @ PSP was used
                    b               1f
0:
                    mrs             r1, msp                         @ otherwise MSP was used
1:
                    ldr             r2, = #ErrorHandler_stackFrame  @ copy stack contents into private memory
                    str             r0, [r2, #32]                   @ store r0 at the end of the memory, to retreive
                    movs            r3, #7<<2                       @ later
0:
                    ldr             r0, [r1, r3]
                    str             r0, [r2, r3]
                    subs            r3, r3, #4
                    bcs             0b
                    ldr             r0, [r2, #32]                   @ restore r0
                    bkpt            #0                              @ debug break

#endif
                    b               .

   .end
