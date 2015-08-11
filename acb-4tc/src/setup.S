/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

 #include "moduleInfo.inc"

@ setup code for ACB-4TC (4 Turnout control)

    module(Setup)

    public_function(Setup_setup)

@ void Setup_setup() - doesn't return if option bytes updated
@   Change options bytes to use PB8 rather than BOOT0 if required
@   Setup all major peripherals

Setup_setup:
                    push            {r7, lr}
                    pop             {r7, pc}

    .end
