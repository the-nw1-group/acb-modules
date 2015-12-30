/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

    .extern         Setup_setup                                     @ setup hardware and peripherals

@ main code for Signal/Servo Tester

    module(Main)

    private_data(Main_private)

    public_function(main)

@ void main() - doesn't return
@   main code for module


main:

                    bl              Setup_setup

__mainLoop:
                    dsb                                             @ ensure all pending memory operations complete
                    wfi                                             @ before entering sleep
                    b               __mainLoop                      @ do nothing for now

    .end
