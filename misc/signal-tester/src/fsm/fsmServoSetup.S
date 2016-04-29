/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Finite State Machine functions for servo operation

    module(FsmServoSetup)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_drawFilledRectangle                     @ draw a filled rectangle
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Display_drawString                              @ draw a string into the display buffer
    .extern         FsmMenus_initMainMenu                           @ init and show the main menu
    .extern         FsmMenus_initServoSaveMenu                      @ show the servo save menu
    .extern         FsmCommon_showInstructions                      @ show instructions
    .extern         FsmCommon_anyKeyPressed                         @ check if any key pressed
    .extern         FsmCommon_enableTimer3Isr                       @ enable timer 3 interrupts
    .extern         FsmCommon_disableTimer3Isr                      @ disable timer 3 interrupts
    .extern         FsmCommon_setTimer3Handler                      @ set the timer 3 interrupt handler
    .extern         itoa                                            @ convert integer to string
    .extern         __aeabi_uidiv                                   @ unsigned integer divide

    public_data(FsmServoSetup_publicData)

FsmServoSetup_start:
                    .byte           0                               @ start position
FsmServoSetup_end:
                    .byte           0                               @ end position
FsmServoSetup_speed:
                    .byte           0                               @ speed

    .global         FsmServoSetup_start, FsmServoSetup_end, FsmServoSetup_speed

    private_data(FsmServoSetup_privateData)

PWM_ARR         = 63999                                             @ ARR value for period of 8ms
PWM_PSC         = 5                                                 @ Presclare value for period of 8ms
PWM_CCR_LOW     = 3999                                              @ CCR value of lowest pulse for servo (0.5ms)
PWM_CCR_HIGH    = 19999                                             @ CCR Value of highest pulse for servo (2.5ms)

FsmServoRun_start:                                                  @ Running parameters: start, end, speed
                    .short          0
FsmServoRun_end:
                    .short          0
FsmServoRun_speed:
                    .short          0
FsmServoRun_delayCount:                                             @ used to delay between reversing direction
                    .short          0
FsmServoRun_state:                                                  @ cheeky state flag
                    .short          0

FsmServoSetup_convertBuffer:
                    .string         "  "                            @ buffer for integer conversion

    static_data(FsmServoSetup_const)

FsmServoSetup_const:

speedTable:         .short          192, 96, 64, 48, 38, 32, 27, 24, 21, 19, 17, 16, 14, 13, 12, 11

title:              .string         "Servo Setup"
instructions1:      .string         "Connect the servo to the"
instructions2:      .string         "connector, ensuring you have"
instructions3:      .string         "it the correct way around."
instructions4:      .string         "Use Red to adjust the start"
instructions5:      .string         "position, Green to adjust the"
instructions6:      .string         "end position and Blue to adjust"
instructions7:      .string         "the speed of travel."
instructions7a:     .string         "The start position can not be"
instructions7b:     .string         "greater than the end position"
instructions7c:     .string         "and vice versa."
instructions7d:     .string         "All values are displayed in"
instructions7e:     .string         "hexadecimal. Positions range"
instructions7f:     .string         "from 0-FF, speed 0-F."
instructions8:      .string         "When happy use the Action"
instructions9:      .string         "button to test the servo. The"
instructions10:     .string         "servo should move from one"
instructions11:     .string         "end of travel to the other and"
instructions12:     .string         "then back again. Use the"
instructions13:     .string         "Forward button to continue,"
instructions14:     .string         "and the Back button to return."
instructions15:     .string         "The refresh interval is fixed at"
instructions16:     .string         "6ms and the lowest pulse width"
instructions17:     .string         "is 0.5ms and the highest is"
instructions18:     .string         "2.5ms."

displayTemplate:    .string         "(R) St:       (G) En:       (B) Sp:       "
runServoLine:       .string         "Testing the servo"

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

instructionTable:
                    .int            instructions1,  instructions2
                    .int            instructions3,  instructions4
                    .int            instructions5,  instructions6
                    .int            instructions7,  instructions7a
                    .int            instructions7b, instructions7c
                    .int            instructions7d, instructions7e
                    .int            instructions7f, instructions8
                    .int            instructions9,  instructions10
                    .int            instructions11, instructions12
                    .int            instructions13, instructions14
                    .int            instructions15, instructions16
                    .int            instructions17, instructions18

instructionTableEnd:

    public_function(FsmServoSetup_initServoSetup)

@ int FsmServoSetup_initServoSetup(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the Servo Setup routines. Returns the next state, or 0 to remain in the same state

FsmServoSetup_initServoSetup:
                    push            {r7, lr}
                    bl              Display_clearDisplayBuffer      @ display title
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #title
                    bl              Display_drawAlignedString

                    ldr             r0, = #instructionTable         @ show the instructions
                    movs            r1, #(instructionTableEnd-instructionTable)
                    ldr             r2, = #FsmServoSetup_setupServo
                    bl              FsmCommon_showInstructions
                    pop             {r7, pc}

    private_function(FsmServoSetup_setupServo)

@ int FsmServoSetup_setupServo(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for setting up a servo. Returns the next state, or 0 to remain in the same state

FsmServoSetup_setupServo:
                    push            {r7, lr}
                    bl              FsmServoSetup_setServoValues    @ set and display values
                    ldr             r0, = #FsmServoSetup_adjustServoParameters
                    pop             {r7, pc}

    private_function(FsmServoSetup_adjustServoParameters)

@ int FsmServoSetup_adjustServoParameters(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for adjusting the servo parameters. Returns the next state, or 0 to remain in the same state

FsmServoSetup_adjustServoParameters:
                    push            {r5-r7, lr}
                    movs            r5, #FSM_STATE_ANALOG_CHANGED   @ if the analog state hasn't changed, then
                    rev16           r6, r3                          @ just check for any button press
                    tst             r5, r6
                    beq             0f
                    movs            r7, r3
                    bl              FsmServoSetup_setServoValues    @ set and display servo values
                    movs            r3, r7
0:
                    movs            r5, #FSM_STATE_BUTTONS_CHANGED  @ if the digital state hasn't changed, then
                    tst             r5, r6                          @ just return
                    beq             8f
                    movs            r5, #FSM_BUTTON_LEFT            @ Left/Back pressed?
                    tst             r3, r5
                    beq             1f
                    ldr             r0, = #FsmMenus_initMainMenu    @ yes, return to the main menu
                    b               9f
1:
                    movs            r5, #FSM_BUTTON_ACTION          @ action button pressed?
                    tst             r3, r5
                    beq             2f
                    ldr             r0, = #FsmServoSetup_runServo   @ yes, test the servo
                    b               9f
2:
                    movs            r5, #FSM_BUTTON_RIGHT           @ Next/Forward button pressed?
                    tst             r3, r5
                    beq             8f
                    ldr             r0, = #FsmMenus_initServoSaveMenu  @ yes, then show save menu
                    b               9f
8:
                    movs            r0, #0
9:
                    pop             {r5-r7, pc}

    private_function(FsmServoSetup_runServo)

@ int FsmServoSetup_runServo(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for running the servo based on the parameters set . Returns the next state, or 0 to remain in the same
@   state

FsmServoSetup_runServo:
                    push            {r5-r7, lr}
                    ldr             r7, = #FsmServoRun_start
                    ldr             r6, = #FsmServoSetup_start
                    ldr             r5, = #(PWM_CCR_HIGH - PWM_CCR_LOW)
                    ldr             r4, = #PWM_CCR_LOW
                    ldrb            r0, [r6]                        @ convert setup start (0-FF), to a CCR value between
                    muls            r0, r0, r5                      @ PWM_CCR_HIGH and PWM_CCR_LOW
                    movs            r1, #255
                    bl              __aeabi_uidiv
                    adds            r0, r0, r4
                    strh            r0, [r7]
                    ldrb            r0, [r6, #1]                    @ convert setup end (0-FF), to a CCR value between
                    muls            r0, r0, r5                      @ PWM_CCR_HIGH and PWM_CCR_LOW
                    movs            r1, #255
                    bl              __aeabi_uidiv
                    adds            r0, r0, r4
                    strh            r0, [r7, #2]
                    ldr             r5, = #speedTable               @ convert the speed 0-F into a linear value from
                    ldrb            r0, [r6, #2]                    @ a predefined speedtable
                    lsls            r0, r0, #1
                    ldrh            r0, [r5, r0]
                    strh            r0, [r7, #4]
                    movs            r0, #0                          @ reset state flag
                    strh            r0, [r7, #8]

                    movs            r0, #0                          @ display a line to the user that we are testing
                    ldr             r1, = #(1 | DISPLAY_ROW)        @ the servo
                    movs            r2, #0
                    movs            r3, #ACB_DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0                          @ draw the text
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #runServoLine
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer

                    ldr             r2, = #TIM3_BASE                @ setup TIMER3 to be PWM with output of OC4
                    ldr             r0, = #(TIM_CCMR2_OC4FE | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2)
                    str             r0, [r2, #TIM_CCMR2_OFFSET]
                    ldr             r0, = #(TIM_CCER_CC4E)
                    str             r0, [r2, #TIM_CCER_OFFSET]
                    ldr             r0, = #PWM_ARR
                    str             r0, [r2, #TIM_ARR_OFFSET]
                    ldr             r0, [r7]                        @ set the initial CCR value
                    str             r0, [r2, #TIM_CCR4_OFFSET]
                    movs            r0, #PWM_PSC
                    str             r0, [r2, #TIM_PSC_OFFSET]

                    ldrh            r0, [r7]                        @ if start < end then start fowards, otherwise
                    ldrh            r1, [r7, #2]                    @ backwards
                    cmp             r0, r1
                    bge             0f
                    ldr             r1, = #FsmServoSetup_timer3ForwardIsr
                    b               1f
0:
                    ldr             r1, = #FsmServoSetup_timer3BackwardsIsr
1:
                    movs            r0, #TIM_DIER_CC4IE             @ Timer3 interrupt on CC4 event (hopefully more
                    bl              FsmCommon_enableTimer3Isr       @ gitter free than using the update event)
                    movs            r0, #TIM_CR1_CEN                @ enable the timer...
                    str             r0, [r2, #TIM_CR1_OFFSET]

                    ldr             r0, = #FsmServoSetup_waitForServo
                    pop             {r5-r7, pc}

    private_function(FsmServoSetup_waitForServo)

@ int FsmServoSetup_waitForServo(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for running the servo based on the parameters set . Returns the next state, or 0 to remain in the same
@   state

FsmServoSetup_waitForServo:
                    ldr             r1, = #TIM3_BASE                @ check to see if the test has finished, when timer
                    ldr             r0, [r1, #TIM_CR1_OFFSET]       @ 3 has been stopped
                    cmp             r0, #0
                    bne             9f
                    push            {r7, lr}
                    bne             9f
                    bl              FsmCommon_disableTimer3Isr
                    ldr             r0, = #FsmServoSetup_setupServo
                    pop             {r7, pc}
9:
                    movs            r0, #0
                    bx              lr

    private_function(FsmServoSetup_setServoValues)

@ void FsmServoSetup_setServoValues(short redValue, short blueValue, short greenValue)
@   Set and display the new servo values

FsmServoSetup_setServoValues:
                    push            {r3-r7, lr}
                    movs            r4, r0                          @ save parameters
                    movs            r5, r1
                    movs            r6, r2
                    movs            r0, #0                          @ clear row, and display the template
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #ACB_DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #displayTemplate
                    bl              Display_drawString

                    lsrs            r4, r4, #4                      @ shift to the right, to it's an 8 bit value
                    lsrs            r5, r5, #4
                    lsrs            r6, r6, #8                      @ and speed is 0-15 (4 bit value)
                    ldr             r7, = #FsmServoSetup_start
                    strb            r6, [r7, #2]                    @ store speed
                    strb            r4, [r7, #0]
                    strb            r5, [r7, #1]
0:
                    movs            r0, r4                          @ display the start value
                    movs            r1, #25
                    bl              FsmServoSetup_displayValue
                    movs            r0, r5                          @ display the end value
                    movs            r1, #65
                    bl              FsmServoSetup_displayValue
                    movs            r0, r6                          @ display the speed value
                    movs            r1, #104
                    bl              FsmServoSetup_displayValue
                    bl              Display_blitDisplayBuffer
                    pop             {r3-r7, pc}

    private_function(FsmServoSetup_displayValue)

@ void FsmServoSetup_displayValue(byte value, short xOffset)
@   Display the supplied value. in hex, on the last row on the display at the x offset. Assumes the display is
@   blank at the appropriate place.

FsmServoSetup_displayValue:
                    push            {r7, lr}
                    movs            r7, r1                          @ save off offset
                    ldr             r1, = #FsmServoSetup_convertBuffer
                    movs            r2, #16
                    bl              itoa
                    movs            r3, r0
                    movs            r0, r7                          @ write value on the display
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    bl              Display_drawString
                    pop             {r7, pc}

    private_function(FsmServoSetup_timer3ForwardIsr)

@ void FsmServoSetup_timer3ForwardIsr(void)
@   Handles the timer 3 update interrupt for move the servo forwards (start>end)

FsmServoSetup_timer3ForwardIsr:
                    push            {r5-r7, lr}
                    ldr             r1, = #TIM3_BASE                @ acknowledge the interrupt
                    movs            r0, #0
                    str             r0, [r1, #TIM_SR_OFFSET]

                    ldr             r7, = #FsmServoRun_start        @ get increment and end stop
                    ldrh            r0, [r7, #2]
                    ldrh            r1, [r7, #4]
                    ldr             r5, = #TIM3_BASE                @ current position
                    ldr             r6, [r5, #TIM_CCR4_OFFSET]
                    adds            r6, r6, r1
                    cmp             r6, r0                          @ if the setting is past the end stop
                    ble             0f                              @ set it to the endstop
                    movs            r6, r0
                    ldr             r1, = #(1000/6)
                    strh            r1, [r7, #6]
                    ldr             r0, = #FsmServoSetup_timer3DelayIsr @ setup for 0.5s delay
                    bl              FsmCommon_setTimer3Handler
0:
                    str             r6, [r5, #TIM_CCR4_OFFSET]
                    pop             {r5-r7, pc}

    private_function(FsmServoSetup_timer3BackwardsIsr)

@ void FsmServoSetup_timer3BackwardsIsr(void)
@   Handles the timer 3 update interrupt for move the servo backwards (end>start)

FsmServoSetup_timer3BackwardsIsr:
                    push            {r5-r7, lr}
                    ldr             r1, = #TIM3_BASE                @ acknowledge the interrupt
                    movs            r0, #0
                    str             r0, [r1, #TIM_SR_OFFSET]

                    ldr             r7, = #FsmServoRun_start        @ get increment and end stop
                    ldrh            r0, [r7, #2]
                    ldrh            r1, [r7, #4]
                    ldr             r5, = #TIM3_BASE                @ current position
                    ldr             r6, [r5, #TIM_CCR4_OFFSET]
                    subs            r6, r6, r1
                    cmp             r6, r0                          @ if the setting is past the end stop
                    bge             0f                              @ set it to the endstop
                    movs            r6, r0
                    ldr             r1, = #(1000/6)
                    strh            r1, [r7, #6]
                    ldr             r0, = #FsmServoSetup_timer3DelayIsr @ setup for 0.5s delay
                    bl              FsmCommon_setTimer3Handler
0:
                    str             r6, [r5, #TIM_CCR4_OFFSET]
                    pop             {r5-r7, pc}

    private_function(FsmServoSetup_timer3DelayIsr)

@ void FsmServoSetup_timer3DelayIsr(void)
@   Handles the timer 3 update interrupt for delaying for 05.s

FsmServoSetup_timer3DelayIsr:
                    push            {r7, lr}
                    ldr             r1, = #TIM3_BASE                @ acknowledge the interrupt
                    movs            r0, #0
                    str             r0, [r1, #TIM_SR_OFFSET]

                    ldr             r0, =#FsmServoRun_delayCount
                    ldrh            r1, [r0]
                    subs            r1, r1, #1
                    beq             0f
                    strh            r1, [r0]
                    b               9f
0:
                    ldr             r0, = #FsmServoSetup_timer3SwapEndsIsr  @ end of delay so swap the ends over
                    bl              FsmCommon_setTimer3Handler
9:
                    pop             {r7, pc}

    private_function(FsmServoSetup_timer3SwapEndsIsr)

@ void FsmServoSetup_timer3SwapEndsIsr(void)
@   Handles the timer 3 update interrupt for swapping ends

FsmServoSetup_timer3SwapEndsIsr:
                    push            {r7, lr}
                    ldr             r1, = #TIM3_BASE                @ acknowledge the interrupt
                    movs            r0, #0
                    str             r0, [r1, #TIM_SR_OFFSET]

                    ldr             r7, = #FsmServoRun_start        @ get the two ends
                    ldrh            r3, [r7, #8]                    @ check to see if we've already swapped ends
                    cmp             r3, #1
                    bne             0f
                    ldr             r0, = #FsmServoSetup_timer3EndIsr
                    b               2f
0:
                    ldrh            r1, [r7]
                    ldrh            r2, [r7, #2]
                    strh            r1, [r7, #2]                    @ and swap them!
                    strh            r2, [r7]
                    movs            r3, #1                          @ set the state flag to indicate we've done this
                                                                    @ already... (yes wrong, but it cuts down on the
                                                                    @ number of handlers
                    strh            r3, [r7, #8]
                    cmp             r1, r2                          @ is start > end now ?
                    ble             1f                              @ then go fowards
                    ldr             r0, = #FsmServoSetup_timer3ForwardIsr
                    b               2f
1:                                                                  @ otherwise backwards
                    ldr             r0, = #FsmServoSetup_timer3BackwardsIsr @ then go fowards
2:
                    bl              FsmCommon_setTimer3Handler
                    pop             {r7, pc}


    private_function(FsmServoSetup_timer3EndIsr)

@ void FsmServoSetup_timer3EndIsr(void)
@   Handles the timer 3 update interrupt for ending the operation

FsmServoSetup_timer3EndIsr:
                    ldr             r0, = #TIM3_BASE                @ turn off the timer...
                    movs            r1, #0                          @ the main FSM picks up on this, and then ends...
                    str             r1, [r0, #TIM_SR_OFFSET]
                    str             r1, [r0, #TIM_CCER_OFFSET]
                    str             r1, [r0, #TIM_CR1_OFFSET]
                    bx              lr

    .end
