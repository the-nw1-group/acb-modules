/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "acb/common.inc"
#include "acb/errorHandler.inc"

@ override standard ACB error handler as we don't have yellow and green LEDs

    public_function(ErrorHandler_handle)

@ void ErrorHandler_handle(int errorCode)
@   Last chance fatal error handler
@   TODO: in release flash GREEN and YELLOW, otherwise just hang. This assumes that at least
@   Acb_init has been called successfully.

ErrorHandler_handle:
                    cpsid           i                               @ disable all configurable interrupts
#if defined(DEBUG)
                    nop                                             @ in debug we don't have access to GREEN and YELLOW
                    nop                                             @ so just hang
                    bkpt            #0                              @ or try to breakpoint any debugger
                    b               .
#endif
                    b               .

   .end
