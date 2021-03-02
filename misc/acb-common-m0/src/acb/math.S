/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "acb/functionHeaders.inc"

#ifdef ACB_USE_MATH

    module(math)

@ Simple math routines applicable to the m0 core (mainly around dividing, as the m0 doesn't have a hardware
@ divider)

    public_function(Math_divu1000)

@ uint Math_divu1000(uint n)
@   perform an approximate integer unsigned divide by 1000.
@   Taken from: http://www.hackersdelight.org/divcMore.pdf

Math_divu1000:
                    lsrs            r1, r0, #7                      @ t = (n >> 7) + (n >> 8) + (n >> 12)
                    lsrs            r2, r0, #8                      @ n in r0; r in r1
                    adds            r1, r1, r2
                    lsrs            r2, r0, #12
                    adds            r1, r1, r2

                    lsrs            r2, r0, #1                      @ q = (n >> 1) + t + (n >> 15) + (t >> 11) + (t >> 14)
                    adds            r2, r2, r1                      @ q in r2
                    lsrs            r3, r0, #15
                    adds            r2, r2, r3
                    lsrs            r3, r1, #11
                    adds            r2, r2, r3
                    lsrs            r3, r1, #14
                    adds            r2, r2, r3

                    lsrs            r2, r2, #9                      @ q = q >> 9

                    ldr             r1, = #1000                     @ r = n - q*1000
                    muls            r1, r1, r2                      @ r in r1 - trashes t
                    subs            r1, r0, r1

                    adds            r1, r1, #24                     @ return q + ((r + 24) >> 10)
                    lsrs            r1, r1, #10
                    adds            r0, r2, r1
                    bx              lr

#endif

    .end
