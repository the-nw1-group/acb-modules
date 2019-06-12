/*
 * Copyright (c) 2018 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

     .extern        Setup_setup                                     @ setup hardware and peripherals
     .extern        Configuration_isConfigured                      @ check if the module is configured
     .extern        Configuration_configure                         @ configure controller

@ main code for uTroller

    module(Main)

    public_function(main)

@ void main() - doesn't return
@   main code for module

main:
                    bl              Setup_setup
                    bl              Configuration_isConfigured      @ is this module configured?
                    cmp             r0, #1                          @ yes, then just continue with the application
                    beq             __mainLoop
                    b               Configuration_configure         @ otherwise get the user to configure the controller

__mainLoop:
                     b               __mainLoop

    .end
