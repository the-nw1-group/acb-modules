/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ main controller code

    module(Controller)

     .extern        Drv8816_on                                      @ turn on the drv8816 device
     .extern        Drv8816_forward                                 @ drive forward on the drv8816
     .extern        Drv8816_reverse                                 @ drive reverse on the drv8816
     .extern        Drv8816_off                                     @ turn off the drv8816 device

     .extern        Configuration_getOption1Value                   @ Get option 1 (current limit option) setting
     .extern        Configuration_getOffValue                       @ Get the center off value

ADC_ONEAMP = 1552                                                   @ ADC value for Vpropi when it's reading 1A and 2A
ADC_TWOAMP = 3103

private_data(Controller_private)

Controller_currentLimit:                                            @ Current limit, set via configuration
                    .short      0
Controller_overCurrentstatus:                                       @ Over current status
                    .short      0
Configuration_overCurrentOverSampleCount:                           @ Number of samples counted over the limit
                    .short      0
Configuration_overCurrentUnderSampleCount:                          @ Number of samples counted under the limit
                    .short      0

    public_function(Controller_init)

@ void Controller_init()
@   Initialise the controller, set up the timers for the POWER and TRACK LED
@   and then check that speed control is in the off position

Controller_init:
                    push            {r7, lr}
                    bl              Controller_setupLEDs
                    movs            r1, #1
                    bl              Controller_waitForCentreOff
                    bl              Controller_offTrack
                    bl              Controller_offPower
                                                                    @ Read and save current limit, based on configuration jumpers
                    bl              Configuration_getOption1Value
                    ldr             r1, =#Controller_currentLimit
                    ldr             r2, =#ADC_ONEAMP                @ if config1=0 use 1A limit
                    cmp             r0, #0
                    beq             0f
                    ldr             r2, =#ADC_TWOAMP
0:
                    strh            r2, [r1]
                    pop             {r7, pc}

    public_function(Controller_run)

@ void Controller_run()
@   Run the main controller run - doesn't return

Controller_run:
                    bl              Controller_onPower              @ turn on the power LED
                    movs            r7, #0                          @ clear flag to say that the track power is off...
                    movs            r4, #0                          @ clear over current flag
                    bl              Configuration_getOffValue       @ set centre off value
                    movs            r6, r0
                    ldr             r5, =#Analog_vpropi
0:
                    bl              Controller_speedOff             @ is the speed pot of?
                    cmp             r0, #0
                    beq             8f
                    cmp             r7, #0                          @ is track off off? if so then turn if on
                    bne             1f
                    bl              Drv8816_on
                    bl              Controller_onTrack
                    movs            r7, #1                          @ set flag to say that the track power is off...
1:
                    bl              Controller_overCurrentCheck     @ check if we're in over current shutdown...
                    cmp             r0, #1                          @ if it is, then loop back, and start checking again
                    beq             0b

                    ldrh            r0, [r5, #2]                    @ set speed pot value
                    cmp             r0, r6                          @ is it forward or reverse?
                    bgt             2f
                    movs            r1, #0                          @ forward, so speed value is 0-r0+2047
                    subs            r1, r1, r0
                    ldr             r0, = #2047
                    adds            r0, r0, r1
                    bl              Drv8816_forward
                    b               9f
2:
                    ldr             r1, = #2048                     @ reverse, so speed value is r0-248
                    subs            r0, r0, r1
                    bl              Drv8816_reverse
9:
                    b               0b
8:                                                                  @ speed pot had been turned off
                    cmp             r7, #0                          @ is the track power already off?
                    beq             9b
                    bl              Drv8816_off                     @ otherwise turn it off along with the LED
                    bl              Controller_offTrack
                    movs            r7, #0                          @ clear flag to say that the track power is off...
                    b               9b

    private_function(Controller_waitForCentreOff)

@ void Controller_waitForCentreOff(bool flashPowerLed)
@   Wait for the user to set the speed pot to center off

Controller_waitForCentreOff:
                    push            {r7, lr}
                    movs            r7, r0
0:
                    bl              Controller_speedOff
                    cmp             r0, #0
                    beq             2f
                    cmp             r7, #1
                    bne             1f
                    bl              Controller_slowFlashPower
                    bl              Controller_offTrack
1:
                    b               0b
2:                    
                    pop             {r7, pc}

    private_function(Controller_setupLEDs)

@ void Controller_setupLEDs()
@   Setup the LEDs - timer controlled, with a period of 1s initially (for slow flash)

Controller_setupLEDs:

__setupPower:
                    ldr             r0, = #UTROLLER_POWER_GPIOBASE  @ setup power led pwm outputs
                    ldr             r1, [r0, #GPIO_MODER_OFFSET]    @ set AF mode
                    ldr             r2, = #3<<(UTROLLER_POWER<<1)
                    bics            r1, r1, r2
                    ldr             r2, = #2<<(UTROLLER_POWER<<1)
                    orrs            r1, r1, r2
                    str             r1, [r0, #GPIO_MODER_OFFSET]
                    ldr             r1, [r0, #GPIO_OTYPER_OFFSET]   @ set push-pull mode
                    movs            r2, #1<<UTROLLER_POWER
                    bics            r1, r1, r2
                    str             r1, [r0, #GPIO_OTYPER_OFFSET]
                    ldr             r1, [r0, #GPIO_OSPEEDR_OFFSET]  @ set low speed
                    ldr             r2, = #3<<(UTROLLER_POWER<<1)
                    bics            r1, r1, r2
                    str             r1, [r0, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, [r0, #GPIO_AFR_OFFSET]  @ set AF mode (TimerX)
                    ldr             r2, = #0x0f<<((UTROLLER_POWER)<<2)
                    bics            r1, r1, r2
                    ldr             r2, = #UTROLLER_POWER_AF<<((UTROLLER_POWER)<<2)
                    orrs            r1, r1, r2
                    str             r1, [r0, #GPIO_AFR_OFFSET]

                    ldr             r0, = #UTROLLER_POWER_TIMER_BASE @ setup timer so we can fast/slow/steady/off power LED
                    ldr             r1, = #750                      @ timer to 1Hz (Slow Flash), half this for Fast Flash (2Hz)
                    str             r1, [r0, #TIM_PSC_OFFSET]       @ 1Hz/2Hz are approximate 
                    ldr             r1, = #63999                    @ otherwise use high frequency PWM (23.5kHz-ish)
                    str             r1, [r0, #TIM_ARR_OFFSET]
                    lsrs            r1, r1, #1                      @ 50% duty cycle
                    str             r1, [r0, #TIM_CCR1_OFFSET]
                    movs            r1, #(TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1FE | TIM_CCMR1_OC1PE)
                    str             r1, [r0, #TIM_CCMR1_OFFSET]     @ force inactive output, fast update and preload
                    movs            r1, #TIM_CCER_CC1E
                    str             r1, [r0, #TIM_CCER_OFFSET]      @ set output to pin
                    movs            r1, #TIM_CR1_CEN | TIM_CR1_ARPE
                    ldr             r2, [r0, #TIM_CR1_OFFSET]
                    orrs            r2, r2, r1
                    str             r2, [r0, #TIM_CR1_OFFSET]       @ enable timer and enable auto reload preload
                    ldr             r2, [r0, #TIM_EGR_OFFSET]       @ force an update
                    movs            r1, #TIM_EGR_UG
                    orrs            r2, r2, r1
                    str             r2, [r0, #TIM_EGR_OFFSET]

__setupTrack:
                    ldr             r0, = #UTROLLER_TRACK_GPIOBASE  @ setup track led pwm outputs
                    ldr             r1, [r0, #GPIO_MODER_OFFSET]    @ set AF mode
                    ldr             r2, = #3<<(UTROLLER_TRACK<<1)
                    bics            r1, r1, r2
                    ldr             r2, = #2<<(UTROLLER_TRACK<<1)
                    orrs            r1, r1, r2
                    str             r1, [r0, #GPIO_MODER_OFFSET]
                    ldr             r1, [r0, #GPIO_OTYPER_OFFSET]   @ set push-pull mode
                    movs            r2, #1<<UTROLLER_TRACK
                    bics            r1, r1, r2
                    str             r1, [r0, #GPIO_OTYPER_OFFSET]
                    ldr             r1, [r0, #GPIO_OSPEEDR_OFFSET]  @ set low speed
                    ldr             r2, = #3<<(UTROLLER_TRACK<<1)
                    bics            r1, r1, r2
                    str             r1, [r0, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, [r0, #GPIO_AFR_OFFSET]      @ set AF mode (TimerX)
                    ldr             r2, = #0x0f<<((UTROLLER_TRACK)<<2)
                    bics            r1, r1, r2
                    ldr             r2, = #UTROLLER_TRACK_AF<<((UTROLLER_TRACK)<<2)
                    orrs            r1, r1, r2
                    str             r1, [r0, #GPIO_AFR_OFFSET]

                    ldr             r0, = #UTROLLER_TRACK_TIMER_BASE @ setup timer so we can fast/slow/steady/off track LED
                    ldr             r1, = #750                      @ timer to 1Hz (Slow Flash), half this for Fast Flash (2Hz)
                    str             r1, [r0, #TIM_PSC_OFFSET]       @ 1Hz/2Hz are approximate 
                    ldr             r1, = #63999                    @ otherwise use high frequency PWM (23.5kHz-ish)
                    str             r1, [r0, #TIM_ARR_OFFSET]
                    lsrs            r1, r1, #1                      @ 50% duty cycle
                    str             r1, [r0, #TIM_CCR4_OFFSET]
                    ldr             r1, = #(TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4FE | TIM_CCMR2_OC4PE)
                    str             r1, [r0, #TIM_CCMR2_OFFSET]     @ force inactive output, fast update and preload
                    ldr             r1, = #TIM_CCER_CC4E
                    str             r1, [r0, #TIM_CCER_OFFSET]      @ set output to pin
                    movs            r1, #TIM_CR1_CEN | TIM_CR1_ARPE
                    ldr             r2, [r0, #TIM_CR1_OFFSET]
                    orrs            r2, r2, r1
                    str             r2, [r0, #TIM_CR1_OFFSET]       @ enable timer and enable auto reload preload
                    ldr             r2, [r0, #TIM_EGR_OFFSET]       @ force an update
                    movs            r1, #TIM_EGR_UG
                    orrs            r2, r2, r1
                    str             r2, [r0, #TIM_EGR_OFFSET]

                    bx              lr

    private_function(Controller_offPower)

@ void Controller_offPower()
@   turn off the power LED

Controller_offPower:
                    movs            r0, #TIM_CCMR1_OC1M_2
                    ldr             r1, = #750
                    b               Controller_setPowerLed

    private_function(Controller_onPower)

@ void Controller_onPower()
@   turn on power LED, without flashing

Controller_onPower:
                    movs            r0, #TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0
                    ldr             r1, = #750
                    b               Controller_setPowerLed

    private_function(Controller_slowFlashPower)

@ void Controller_slowFlashPower()
@   slow flash the power LED

Controller_slowFlashPower:
                    movs            r0, #TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1
                    ldr             r1, = #750
                    b               Controller_setPowerLed

    private_function(Controller_fastFlashPower)

@ void Controller_fastFlashPower()
@   fast flash the power LED

Controller_fastFlashPower:
                    movs            r0, #TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1
                    ldr             r1, = #375
                    b               Controller_setPowerLed

    private_function(Controller_offTrack)

@ void Controller_offTrack()
@   turn off the track LED

Controller_offTrack:
                    ldr             r0, = #TIM_CCMR2_OC4M_2
                    ldr             r1, = #750
                    b               Controller_setTrackLed

    private_function(Controller_onTrack)

@ void Controller_onTrack()
@   turn on track LED, without flashing

Controller_onTrack:
                    ldr             r0, = #TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_0
                    ldr             r1, = #750
                    b               Controller_setTrackLed

    private_function(Controller_slowFlashTrack)

@ void Controller_slowFlashTrack()
@   slow flash the track LED

Controller_slowFlashTrack:
                    ldr             r0, = #TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1
                    ldr             r1, = #750
                    b               Controller_setTrackLed

    private_function(Controller_fastFlashTrack)

@ void Controller_fastFlashTrack()
@   fast flash the track LED

Controller_fastFlashTrack:
                    ldr             r0, = #TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1
                    ldr             r1, = #375
                    b               Controller_setTrackLed

    private_function(Controller_setPowerLed)

@ void Controller_setPowerLed(uint32_t ccmr_value, uint32_t psc)
@   set the timer output (for the power LED), given the above values

Controller_setPowerLed:
                    ldr             r2, = #UTROLLER_POWER_TIMER_BASE
                    str             r1, [r2, #TIM_PSC_OFFSET]
                    ldr             r1, [r2, #TIM_CCMR1_OFFSET]
                    movs            r3, #TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0
                    bics            r1, r1, r3
                    orrs            r1, r1, r0
                    str             r1, [r2, #TIM_CCMR1_OFFSET]
                    bx              lr

    private_function(Controller_setTrackLed)

@ void Controller_setTrackLed(uint32_t ccmr_value, uint32_t psc)
@   set the timer output (for the track LED), given the above values

Controller_setTrackLed:
                    ldr             r2, = #UTROLLER_TRACK_TIMER_BASE
                    str             r1, [r2, #TIM_PSC_OFFSET]
                    ldr             r1, [r2, #TIM_CCMR2_OFFSET]
                    ldr             r3, = #TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_0
                    bics            r1, r1, r3
                    orrs            r1, r1, r0
                    str             r1, [r2, #TIM_CCMR2_OFFSET]
                    bx              lr


    private_function(Controller_speedOff)

@ bool Controller_speedOff()
@   returns non-zero if the speed pot is set to zero, otherwise returns 0

Controller_speedOff:
                    push            {r7, lr}
OFF_SPAN = 48                    
                    bl              Configuration_getOffValue       @ get the configured off value
                    movs            r3, #OFF_SPAN
                    subs            r1, r0, r3                      @ check between off-SPAN and off+SPAN, to 
                    adds            r2, r0, r3                      @ allow for "not so great" pots
                    ldr             r0, = #Analog_speed
                    ldrh            r0, [r0]
                    cmp             r0, r1
                    blt             2f
                    cmp             r0, r2
                    bgt             2f
                    movs            r0, #0
1:
                    pop             {r7, pc}
2:
                    movs            r0, #1
                    b               1b

    private_function(Controller_overCurrentCheck)

@ bool Controller_overCurrentCheck()
@   returns true if the over current check has been tripped, otherwise false
@   note:   this routine handles all over current processing, i.e. flashing LEDs, getting the user to
@           reset the speed pot. back to zero

OS_NOT_RECORDING            = 0                                     @ Over current status values
OS_RECORDING                = 1
OS_FINISHED_RECORDING       = 5

Controller_overCurrentCheck:
                    push            {r7, lr}
                    ldr             r7, =#Analog_vpropi             @ Get current usage of drv8816
                    ldrh            r7, [r7]

                    ldr             r3, =#Controller_currentLimit   @ Check the status
                    ldrh            r1, [r3]
                    ldrh            r0, [r3, #2]
                    cmp             r0, #OS_FINISHED_RECORDING      @ finished recording?
                    beq             6f

                    cmp             r0, #OS_RECORDING               @ recording?
                    beq             0f
                    cmp             r7, r1                          @ are we over current?
                    ble             7f                              @ no, then just return

                    movs            r0, #OS_RECORDING               @ set up recording...
                    strh            r0, [r3, #2]
                    movs            r0, #AS_CONT_OVERCURRENT_CHECK  @ check current samples for 25ms
                    movs            r1, #25
                    ldr             r2, = #Controller_overCurrentCheckSampleEnd
                    bl              MsCounter_alarmIn
                    b               8f
0:                                                                  @ already recording over current
                    adds            r2, r3, #4
                    cmp             r7, r1                          @ are we over current?
                    bgt             1f                              @ no, then just return
                    adds            r2, r2, #2
1:                                                                  
                    ldrh            r0, [r2]                        @ increment the number of samples for either over/under
                    adds            r0, r0, #1                      @ current
                    strh            r0, [r2]
8:
                    movs            r0, #0                          @ we haven't had a over current and handled it
                    pop             {r7, pc}
9:
                    movs            r0, #1                          @ indicate we have had an over current and we've handled it
                    pop             {r7, pc}
7:                                                                  @ we're not over current, and not recording, but if we're close 
                                                                    @ to over current then start flashing the track led
                    lsrs            r0, r1, #2                      @ (near over current) = limit - (limit >> 2)
                    subs            r1, r1, r0
                    cmp             r7, r1
                    ble             0f
                    bl              Controller_slowFlashTrack
                    b               8b
0:
                    bl              Controller_onTrack
                    b               8b
6:                                                                  @ finished recording samples of current consumption
                    movs            r0, #OS_NOT_RECORDING           @ reset status
                    strh            r0, [r3, #2]
                    ldrh            r1, [r3, #4]                    @ get number of over and under limit samples
                    ldrh            r2, [r3, #6]
                    movs            r0, #0                          @ and reset those as well
                    strh            r0, [r3, #4]
                    strh            r0, [r3, #6]
                    cmp             r1, r2                          @ if the number of under current is greater than over current
                    blt             8b                              @ then just ignore it
                                                                    @ otherwise...
                    bl              Drv8816_off                     @ turn off output
                    bl              Controller_fastFlashTrack       @ fast flash track LED
                    movs            r0, #0
                    bl              Controller_waitForCentreOff     @ wait until the user has centered the speed pot
                    b               9b

    private_function(Controller_overCurrentCheckSampleEnd)

@ void Controller_overCurrentCheckSampleEnd()
@   indicate we've finished sampling for over current condition

Controller_overCurrentCheckSampleEnd:
                    ldr             r1, =#Controller_overCurrentstatus
                    movs            r0, #OS_FINISHED_RECORDING
                    strh            r0, [r1]
                    bx              lr

    .end
