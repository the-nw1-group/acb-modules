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

@ public ACB common routines

    module(Acb)

    public_function(Acb_init)

@ void Acb_init()
@   init the ACB common library, including:
@       setting the LED (green and yellow) as outputs, if ACB_LED_USE is set. Initialises the input for the FLiM Button.
@       Requires the ACB_LED_PORT and ACB_FLIMSW_PORT clocks to be enabled before this is called

Acb_init:
#if ACB_LED_USE
                    ldr             r2, = #ACB_LED_PORT             @ enable bits for green and yellow to be
                    ldr             r1, [r2, #GPIO_MODER_OFFSET]    @ outputs - not in debug mode, otherwise
                    ldr             r3, = #(3<<(ACB_LED_GREEN_BIT<<1))|(3<<(ACB_LED_YELLOW_BIT<<1))
                    bics            r1, r1, r3                      @ we loose access to debug and programming
                    ldr             r3, = #(1<<(ACB_LED_GREEN_BIT<<1))|(1<<(ACB_LED_YELLOW_BIT<<1))
                    orrs            r3, r3, r1
                    str             r3, [r2, #GPIO_MODER_OFFSET]
                    ldr             r1, [r2, #GPIO_OSPEEDR_OFFSET]  @ set low speed for green/yellow
                    ldr             r3, = #(3<<(ACB_LED_GREEN_BIT<<1))|(3<<(ACB_LED_YELLOW_BIT<<1))
                    bics            r1, r1, r3
                    str             r1, [r2, #GPIO_OSPEEDR_OFFSET]
#endif

#if ACB_FLIMSW_USE
                    ldr             r2, = #ACB_FLIMSW_PORT          @ FLiM Switch as an input with a pull up
                    ldr             r1, [r2, #GPIO_PUPDR_OFFSET]    @ Input mode is default, so just enable pullup
                    ldr             r3, = #3<<(ACB_FLIMSW_BIT<<1)
                    bics            r1, r1, r3
                    ldr             r3, = #1<<(ACB_FLIMSW_BIT<<1)
                    orrs            r1, r1, r3
                    str             r1, [r2, #GPIO_PUPDR_OFFSET]
#endif
                    bx              lr

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
