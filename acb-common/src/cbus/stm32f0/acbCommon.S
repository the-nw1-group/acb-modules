/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */


#include "moduleInfo.inc"
#include "acb_common.inc"


@ public ACB common routines

    module(AcbCommon)

    public_function(Acb_init)

@ void Acb_init()
@   init the ACB common library, including:
@       setting the LED (green and yellow) as outputs, if ACB_LED_USE is set

Acb_init:
                    push             {r7, lr}
#if ACB_LED_USE
                    ldr             r0, = #ACB_LED_AHBENR           @ enable LED port
                    orrs            r0, r0, r1
                    str             r0, [r2]
                    ldr             r6, = #ACB_LED_PORT             @ enable bits for green and yellow to be
                    ldr             r1, [r2, #GPIO_MODER_OFFSET]    @ outputs - not in debug mode, otherwise
                    ldr             r0, = #(3<<(ACB_LED_GREEN_BIT<<1))|(3<<(ACB_LED_YELLOW_BIT<<1))
                    bics            r1, r1, r0                      @ we loose access to debug and programming
                    ldr             r0, = #(1<<(ACB_LED_GREEN_BIT<<1))|(1<<(ACB_LED_YELLOW_BIT<<1))
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r1, [r2, #GPIO_OSPEEDR_OFFSET]  @ set low speed for green/yellow
                    ldr             r0, = #(3<<(ACB_LED_GREEN_BIT<<1))|(3<<(ACB_LED_YELLOW_BIT<<1))
                    bics            r0, r0, r1
                    str             r0, [r2, #GPIO_OSPEEDR_OFFSET]
#endif

                    pop             {r7, pc}

    public_function(Acb_showLeds)

@ void Acb_showLeds(uint32 newValue, uint32 mask)
@   show/hide Leds based on supplied parameters. In both newValue and mask:
@       bit 0 is green LED
@       bit 1 is yellow LED
@       other bits unused.
@   does nothing if ACB_LED_USE is not set

Acb_showLeds:
                    push            {r7, lr}
#if ACB_LED_USE
                    movs            r2, #3
                    ands            r0, r0, r2                      @ ensure that we only manipulate the right bits
                    ands            r1, r1, r2
                    tst             r1, r2                          @ if mask is not empty, just return
                    beq             0f

                    ldr             r7, = #ACB_LED_PORT
__acbShowLedsGreen:                                                 @ no easy bit manipulation to set both green/yellow
                    movs            r2, #0                          @ here, as GREEN and YELLOW might not be on adjacent
                    tst             r1, r2                          @ pins
                    beq             __acbShowLedsYellow
                    ldr             r3, = #(1<<ACB_LED_GREEN_BIT)
                    tst             r0, r2                          @ turn the LED on or off?
                    beq             1f
                    str             r3, [r7, #GPIO_BSRR_OFFSET]
                    b               __acbShowLedsYellow
1:
                    str             r3, [r7, #GPIO_BRR_OFFSET]
__acbShowLedsYellow:
                    movs            r2, #1
                    tst             r1, r2
                    beq             0f
                    ldr             r3, = #(1<<ACB_LED_YELLOW_BIT)
                    tst             r0, r2                          @ turn the LED on or off?
                    beq             2f
                    str             r3, [r7, #GPIO_BSRR_OFFSET]
                    b               0f
2:
                    str             r3, [r7, #GPIO_BRR_OFFSET]
#endif
0:
                    pop             {r7, pc}

    .end
