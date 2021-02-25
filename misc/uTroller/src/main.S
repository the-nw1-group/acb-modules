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
     .extern        Drv8816_init                                    @ initialise control of DRV8816

@ main code for uTroller

    module(Main)

    public_function(main)

@ void main() - doesn't return
@   main code for module

main:
                    bl              Setup_setup
                    bl              Configuration_isConfigured      @ is this module configured?
                    cmp             r0, #1                          @ yes, then just continue with the application
                    beq             0f
                    b               Configuration_configure         @ otherwise get the user to configure the controller
0:
                    bl              Drv8816_init                    @ initialise the drv8816 (h bridge chip)
                    bl              Controller_init                 @ initialise the controller
__mainLoop:
                    bl              Controller_run                  @ run the main controller code
                    b               __mainLoop

    .end
