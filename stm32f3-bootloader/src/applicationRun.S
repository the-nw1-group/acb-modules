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

    public_function(AppRun_boot)

@ void ApplicationRun() - doesn't return
@   tell the processor wherer the application's vector table is, and jump to it's reset handler

AppRun_boot:
                    ldr             r0, = #_application_orgin       @ location of the app vector table
                    ldr             r1, = #SCB_VTOR
                    str             r0, [r1]
                    dsb                                             @ ensure new vector table is used in subsequent exceptions

                    adds            r0, r0, #4                      @ get the reset vector
                    ldr             r0, [r0]
                    bx              r0                              @ ...and branch to the user code reset vector

    .end

