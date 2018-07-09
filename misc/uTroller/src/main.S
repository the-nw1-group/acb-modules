/*
 * Copyright (c) 2018 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@    .extern         Setup_setup                                     @ setup hardware and peripherals
@    .extern         LowPower_checkEnterStop                         @ check and enter stop mode
@    .extern         Detect_check                                    @ check and perform detection
@    .extern         Detect_checkStartupState                        @ check to see if start in low power mode

@ main code for uTroller

    module(Main)

    public_function(main)

@ void main() - doesn't return
@   main code for module

main:
@                    bl              Setup_setup
@                    bl              Detect_checkStartupState        @ check if we should enter low power straight away
__mainLoop:
@                    bl              LowPower_checkEnterStop         @ see if low power mode has been set
@                    bl              Detect_check
@                    b               __mainLoop

    .end
