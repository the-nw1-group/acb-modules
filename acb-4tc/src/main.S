/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "acb_can.inc"

@ main code for ACB-4TC (4 Turnout control)

    module(Main)

    .extern         Setup_setup                                     @ setup hardware and peripherals

    public_function(main)

@ void main() - doesn't return
@   main code for module

main:
                    bl              Setup_setup
                    b               .                               @ do nothing for now

    .end
