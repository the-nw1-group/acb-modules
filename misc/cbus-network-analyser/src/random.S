/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ simple random number generator

    module(Random)

    public_function(Random_next)

@ uint Random_next (uint limit)
@   returns a random number between 0 and limit

Random_next:
RAND_MAX = 2147483647
                    push            {r5-r7, lr}
                    movs            r7, r0
                    adds            r1, r0, #1
                    ldr             r0, = #RAND_MAX
                    bl              __aeabi_uidiv
                    movs            r6, r0
0:
                    bl              Random_rand
                    movs            r1, r6
                    bl              __aeabi_uidiv
                    cmp             r0, r7
                    bgt             0b
                    pop             {r5-r7, pc}

@ the following is a balant copy of rand.c from newlib-nano, but without the requirement for a heap

    private_data(rand_data)

rand_seed:          .quad           1


    public_function(Random_rand)

@ int Random_rand ()
@   returns a different integer each time it is called,  each integer is chosen by an algorithm designed to be
@   unpredictable

Random_rand:
                    push            {r4, lr}
                    ldr             r4, = #rand_seed
                    ldr             r2, #Random_multiplier
                    ldr             r0, [r4]
                    ldr             r1, [r4, #4]
                    ldr             r3, #Random_multiplier + 4
                    bl              __aeabi_lmul
                    movs            r2, #1
                    movs            r3, #0
                    adds            r0, r0, r2
                    adcs            r1, r1, r3
                    str             r0, [r4]
                    str             r1, [r4, #4]
                    lsls            r0, r1, #1
                    lsrs            r0, r0, #1
                    pop             {r4, pc}

    .align 2

Random_multiplier:
                    .quad           6364136223846793005

    .end
