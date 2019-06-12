/*
 * Copyright (c) 2018 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

     .extern        MsCounter_alarmIn                               @ call a function after supplied time (ms)
     .extern        MsCounter_clearAlarm                            @ clear an alarm
     .extern        Flash_unlockWrite                               @ unlock flash writing
     .extern        Flash_erase                                     @ erase a region of flash
     .extern        Flash_enableFlashProgramming                    @ enable writing to flash
     .extern        Flash_waitForOperation                          @ wait for a flash operation to finish

@ configuration code for the uTroller

    module(Configuration)

    eeprom_data(Configuration_eeprom)

Configuration_eeprom:

@ temp setting so we don't need to configure every time...

configStatus:           .short     0x011 @ 0                               @ does the config block contain valid data
configMaxReverseValue:  .short     0xFFD @ 0                               @ ADC value of max reverse (pot. to the left)
configMaxForwardValue:  .short     0x000 @ 0                               @ ADC value of max forward (pot. to the right)
configOffValue:         .short     0x7F5 @ 0                               @ ADC value of off (pot. to the middle)

CONFIG_STATUS_CONFIGURED = 0x01
CONFIG_STATUS_EMPTY      = 0x00
CONFIG_VERSION           = 0x10

    private_data(Configuration_private)

configOptionCache:      .byte       0xFF                            @ Cache of the configuration otions
configStage:            .byte       0x01                            @ Which stage of configuration: 1=left, 3=right, 5=centre
configFlashState:       .byte       0x00                            @ Flash state
configFlags:            .byte       0x00                            @ Flags used during the configuration setup loop:
                                                                    @   bit 0 : value set (i.e. in range for 5s)
                                                                    @   bit 1 : alarm created

configSetupStatus:      .short      0                               @ copies of the configuration data, whilst in setup mode
configSetupMaxRevValue: .short      0
configSetupMaxForValue: .short      0
configSetupOffValue:    .short      0

CONFIG_FLASH_RATE       = 100

    public_function(Configuration_isConfigured)

@ bool Configuration_isConfigured()
@   Checks to see if the "eeprom" contains valid values, and therefore the module is already configured.
@   Returns true if the module is configured, otherwise false

Configuration_isConfigured:
                    ldr             r0, =#configStatus
                    ldrh            r0, [r0]
                    movs            r1, #CONFIG_STATUS_CONFIGURED
                    ands            r0, r0, r1
                    bx              lr

    public_function(Configuration_getMaxReverse)

@ short Configuration_getMaxReverse()
@   Returns the configured max reverse value

Configuration_getMaxReverse:
                    ldr             r0, =#configMaxReverseValue
                    ldrh            r0, [r0]
                    bx              lr

    public_function(Configuration_getMaxForward)

@ short Configuration_getMaxForward()
@   Returns the configured max forward value

Configuration_getMaxForward:
                    ldr             r0, =#configMaxForwardValue
                    ldrh            r0, [r0]
                    bx              lr


    public_function(Configuration_getOffValue)

@ short Configuration_getOffValue()
@   Returns the configured max forward value

Configuration_getOffValue:
                    ldr             r0, =#configOffValue
                    ldrh            r0, [r0]
                    bx              lr

    public_function(Configuration_getOption0Value)

@ bool Configuration_getOption0Value()
@   Returns true if the option #0 value is set, otherwise false

Configuration_getOption0Value:
                    push            {r7, lr}
                    ldr             r7, =#configOptionCache
                    ldrb            r0, [r7]
                    cmp             r0, #0xFF
                    bne             0f
                    bl              Configuration_getOptions
0:
                    movs            r1, #1<<0
                    ands            r0, r0, r1
                    pop             {r7, pc}

    public_function(Configuration_getOption1Value)

@ bool Configuration_getOption1Value()
@   Returns true if the option #1 value is set, otherwise false

Configuration_getOption1Value:
                    push            {r7, lr}
                    ldr             r7, =#configOptionCache
                    ldrb            r0, [r7]
                    cmp             r0, #0xFF
                    bne             0f
                    bl              Configuration_getOptions
0:
                    movs            r1, #1<<1
                    ands            r0, r0, r1
                    pop             {r7, pc}

@ ideal analogue values for left/right/center

CONFIG_SETUP_LEFT   = 0x0FFF
CONFIG_SETUP_RIGHT  = 0x0000
CONFIG_SETUP_CENTER = 0x07FF

@ pragmatic values...

CONFIG_SETUP_LEFT_MIN   = CONFIG_SETUP_LEFT   - 0x0010
CONFIG_SETUP_LEFT_MAX   = CONFIG_SETUP_LEFT
CONFIG_SETUP_RIGHT_MIN  = CONFIG_SETUP_RIGHT
CONFIG_SETUP_RIGHT_MAX  = CONFIG_SETUP_RIGHT  + 0x0010
CONFIG_SETUP_CENTER_MIN = CONFIG_SETUP_CENTER - 0x0020
CONFIG_SETUP_CENTER_MAX = CONFIG_SETUP_CENTER + 0x0020

    static_data(Configuration_setupLimits)
Configuration_setupLimits:
                    .short          CONFIG_SETUP_LEFT_MIN, CONFIG_SETUP_LEFT_MAX
                    .short          CONFIG_SETUP_RIGHT_MIN,  CONFIG_SETUP_RIGHT_MAX
                    .short          CONFIG_SETUP_CENTER_MIN, CONFIG_SETUP_CENTER_MAX

    public_function(Configuration_configure)

@ void Configuration_configure()
@   gets the user to configure the controller, by displaying various combinations of LEDs and the user positioning
@   the speed adjust to max reverse, max forward, and center-off. These ADC values are then stored into "eeprom" 
@   (flash really), and the controller rebooted. 

@   To indicate to the user configuration is required, the Power LED is turned off, and the Track LED flashes using
@   the following:

@   | Flash                          | Description                                                         |
@   |:------------------------------:| ------------------------------------------------------------------- |
@   | One Fast Flash, every 0.8s     | Turn the potentiometer all the way to the left, and leave it there  |
@   | Three Fast Flashes, every 0.8s | Turn the potentiometer all the way to the right, and leave it there |
@   | Two Fast Flashes, every 0.8s   | Turn the potentiometer to the center, and leave it there            |

@   The configuration procedure is for the Track LED to flash once per 0.8, the user must move the potentiometer fully to
@   the left. Once the unit has a stable ADC reading, under a threshold value, typically over 5s, the unit will then
@   flash the Track LED three times per 0.8s, and the user then must move the potentiometer fully to the right. Again, once
@   a stable ADC reading, over a threshold value, typically over 5s, the unit will then flash the Track LED two times per 
@   0.8s. The user then moves the potentiometer to the centre, detent, position, and once a stable ADC reading between two
@   thresholds is achieved, these are stored permanently within the uProcessors flash memory, and the uProcessor rebooted.

Configuration_configure:
                    bl              Configuration_configureSetup

                    ldr             r7, =#configOptionCache
                    ldr             r0, =#Configuration_setupLimits
                    ldrh            r4, [r0]                        @ load min and max expected values
                    ldrh            r5, [r0, #2]
                    ldr             r6, =#Analog_vpropi
__configureLoop:
                    ldrb            r0, [r7, #3]                    @ check if the value has been ok for 5s
                    movs            r1, #1
                    ands            r0, r0, r1
                    bne             __configureValueOK
                    ldrh            r0, [r6, #2]                    @ if the speed analogue value is between
                    cmp             r0, r4                          @ the limits then start an alarm, if not already
                    blt             __configureOutOfRange           @ started, otherwise cancel it...
                    cmp             r0, r5
                    bgt             __configureOutOfRange
                    ldrb            r0, [r7, #3]                    @ start an alarm for 5s, if not already started...
                    movs            r1, #1<<1                       @ when the alarm triggers, we know the value (more or less)
                    ands            r0, r1                          @ is within range...
                    bne             __configureContinue
                    movs            r0, #1                          @ no alarm, so start one
                    ldr             r1, =#5*1000
                    ldr             r2, =#Configuration_configureValueOK
                    bl              MsCounter_alarmIn
                    movs            r0, #1<<1                       @ and set the flag that the alarm has been set
                    strb            r0, [r7, #3]
                    b               __configureContinue
__configureOutOfRange:
                    movs            r0, #1                          @ value out of range, so clear alarm
                    bl              MsCounter_clearAlarm
                    movs            r0, #0                          @ and reset flags
                    strb            r0, [r7, #3]
__configureContinue:                                 
                    b               __configureLoop

__configureValueOK:
                    cpsid           i                               @ disable interrupts
                    movs            r0, #0
                    strb            r0, [r7, #3]                    @ reset flags (no data, as new value to check, and no alarm)
                    strb            r0, [r7, #2]                    @ reset flash state
                    ldrb            r0, [r7, #1]                    @ store value, based on stage
                    adds            r0, r0, #1                      @ add 1 to get offset for below
                    ldr             r1, =#configSetupStatus
                    ldrh            r2, [r6, #2]
                    strh            r2, [r1, r0]
                    cmp             r0, #6                          @ inc the stage, unless already at the end...
                    beq             __configureFinished
                    adds            r0, r0, #1
                    strb            r0, [r7, #1]                    @ store back next offset

                    cpsie           i                               @ re-enable interrupts
                    ldr             r1, =#Configuration_setupLimits
                    subs            r0, r0, #1
                    lsls            r0, r0, #1
                    ldrh            r4, [r1, r0]                    @ load new min and max expected values
                    adds            r0, r0, #2
                    ldrh            r5, [r1, r0]
                    b               __configureLoop
__configureFinished:
                    cpsie           i                               @ re-enable interrupts
                    movs            r0, #CONFIG_STATUS_CONFIGURED | 0x10
                    strb            r0, [r1]                        @ set version number and configuration set
                    bl              Configuration_writeToEeprom     @ write configuration data to eeprom
0:
                    b               NVIC_systemReset                @ restart the device

    private_function(Configuration_getOptions)

@ byte Configuration_getOptions()
@   loads the options from the configuration jumpers (UTROLLER_CONFIG0, UTROLLER_CONFIG1), and stores in
@   configOptionCache. Returns the value stored

Configuration_getOptions:
                    ldr             r2, =#UTROLLER_CONFIG_GPIOBASE
                    ldr             r0, [r2, #GPIO_IDR_OFFSET]
                    ldr             r1, =#(1<<UTROLLER_CONFIG0) | (1<<UTROLLER_CONFIG1)
                    ands            r0, r0, r1
                    lsls            r0, r0, #UTROLLER_CONFIG0
                    ldr             r2, =#configOptionCache
                    strb            r0, [r2]
                    bx              lr

    private_function(Configuration_configureSetup)

@ void Configuration_configureSetup()
@   set up the output LEDs for configuration, and the alarm for flashing them

Configuration_configureSetup:
                    push            {r7, lr}

                    ldr             r2, = #UTROLLER_TRACK_GPIOBASE  @ set track output as output
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r1, = #1<<(UTROLLER_TRACK<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]

                    ldr             r2, = #UTROLLER_POWER_GPIOBASE  @ set power output as output, fast output
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r1, = #1<<(UTROLLER_POWER<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]

                    movs            r0, #0
                    ldr             r1, =#CONFIG_FLASH_RATE
                    ldr             r2, =#Configuration_configureFlashLEDs
                    bl              MsCounter_alarmIn

                    pop             {r7, pc}

    private_function(Configuration_configureFlashLEDs)

@ void Configuration_configureFlashLEDs()
@   flash the LEDs based on which step of the configuration the user is on

Configuration_configureFlashLEDs:
                    push            {r7, lr}
                    ldr             r0, =#configFlashState
                    ldrb            r1, [r0]
                    adds            r2, r1, #1
                    cmp             r2, #8
                    bne             0f
                    movs            r2, #0
0:
                    strb            r2, [r0]
                    ldr             r2, =#configStage
                    ldrb            r2, [r2]
                    cmp             r1, r2
                    bgt             9f

                    ldr             r0, =#UTROLLER_TRACK_GPIOBASE
                    ldr             r1, [r0, #GPIO_ODR_OFFSET]
                    ldr             r2, =#1<<UTROLLER_TRACK
                    tst             r1, r2
                    beq             0f
                    str             r2, [r0, #GPIO_BRR_OFFSET]
                    b               9f
0:
                    str             r2, [r0, #GPIO_BSRR_OFFSET]
9:
                    movs            r0, #0                              @ re-arm the alarm!
                    ldr             r1, =#CONFIG_FLASH_RATE
                    ldr             r2, =#Configuration_configureFlashLEDs
                    bl              MsCounter_alarmIn
                    pop             {r7, pc}


    private_function(Configuration_configureValueOK)

@ void Configuration_configureValueOK()
@   set the value is ok flag

Configuration_configureValueOK:
                    ldr             r0, =#configOptionCache
                    movs            r1, #1
                    strb            r1, [r0, #3]
                    bx              lr

    private_function(Configuration_writeToEeprom)

@ void Configuration_writeToEeprom()
@   write the configuration data to eeprom

Configuration_writeToEeprom:
                    push            {r5-r7, lr}
                    bl              Flash_unlockWrite               @ unlock flash writing
                    ldr             r0, =#Configuration_eeprom
                    movs            r1, #FLASH_CR_PER
                    bl              Flash_erase                     @ erase the configuration data (ALL of it)
                    bl              Flash_enableFlashProgramming    @ enable flash writing

                    ldr             r4, =#Configuration_eeprom
                    ldr             r5, =#configSetupStatus
                    ldrh            r0, [r5, #2]                    @ write configuration data
                    strh            r0, [r4, #2]
                    bl              Flash_waitForOperation
                    ldrh            r0, [r5, #4]
                    strh            r0, [r4, #4]
                    bl              Flash_waitForOperation
                    ldrh            r0, [r5, #6]
                    strh            r0, [r4, #6]
                    bl              Flash_waitForOperation
                    ldrh            r0, [r5]                        @ write status word (last)
                    strh            r0, [r4]
                    bl              Flash_waitForOperation
                    pop             {r5-r7, pc}

    .end
