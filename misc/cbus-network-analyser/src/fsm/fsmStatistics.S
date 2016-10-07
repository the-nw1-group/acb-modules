/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "cbusNetworkAnalyser.inc"

    module(FsmStatistics)

/*
 * Useful constants
 *
 */

defaultUpdateInterval       = 100                                   @ default update interval (0.5s)
dataXOffset                 = 49                                    @ where to show the data on the screen

__updateIntOffset           = 0
__updateCntOffset           = 2
__msgUpdateCntOffset        = 4
__msgTotalCntOffset         = 8
__inputStateOffset          = 12
__tmpBufferOffset           = 14

    private_data(FsmStatistics_privateData)

FsmStatistics_data:
FsmStatistics_updateInterval:                                       @ how often to update the graph
                    .short          defaultUpdateInterval
FsmStatistics_updateCounter:                                        @ current update count
                    .short          0
FsmStatistics_msgUpdateCount:                                       @ number of messages received since last displayed
                    .word           0
FsmStatistics_msgTotalCount:                                        @ total number of messages received
                    .word           0
FsmStatistics_inputState:                                           @ input state, button press, which field is active
                    .short          0                               @ etc.

    .align 4

FsmStatistics_tmpBuffer:                                            @ buffer for number conversions, etc.
                    .space          32, 32

    static_data(FsmStatistics_staticData)
FsmStatistics_staticData:

FsmStatistics_messageLabel:
                    .string         "Messages :"
FsmStatistics_totalLabel:
                    .string         "Total :"
FsmStatistics_lastError:
                    .string         "Last Error :"
FsmStatistics_errorCounter:
                    .string         "Error Count :"
FsmStatistics_busStatusLabel:
                    .string         "Bus Status :"

FsmStatistics_errNoError:
                    .string         "No Error"
FsmStatistics_errStuff:
                    .string         "Stuff Error"
FsmStatistics_errForm:
                    .string         "Form Error"
FsmStatistics_errAck:
                    .string         "Ack Error"
FsmStatistics_errRec:
                    .string         "Bit recessive Error"
FsmStatistics_errDom:
                    .string         "Bit dominant Error"
FsmStatistics_errCRC:
                    .string         "CRC Error"
FsmStatistics_errSoft:
                    .string         "Set by Software"

    .align 4

FsmStatistics_busOff:
                    .byte           'B','O','F','F'                 @ like this to keep word aligned
FsmStatistics_busOn:
                    .byte           'B','o','n',' '
FsmStatistics_busErrPassive:
                    .string         "EPVF "
FsmStatistics_busErrWarn:
                    .string         "EWGF"
FsmStatistics_Rx:
                    .string         " / RX "

    .align  4

FsmStatistics_Tx:
                    .string         "TX "

    .align  2

FsmStatistics_updateTimes:                                          @ possible update times
                    .short          100, 200, 400, 1000, 2000       @ 0.5s, 1s, 2s, 5s, 10s, 20s, 50s, 1m, 2m, 5m
                    .short          4000, 10000, 12000, 24000, 60000

FsmStatistics_resetButton:
                    .string         "RESET"
FsmStatistics_updateButton:
                    .string         "UPDATE:"
FsmStatistics_backButton:
                    .byte           127, 0
FsmStatistics_seconds:
                    .byte           's'
FsmStatistics_minutes:
                    .byte           'm'

    .align 2

FsmStatistics_fractionOfSecond:
                    .string         "0."

    .align 4

FsmStatistics_labelTable:
                    .word           FsmStatistics_messageLabel
                    .word           FsmStatistics_totalLabel
                    .word           FsmStatistics_lastError
                    .word           FsmStatistics_errorCounter
                    .word           FsmStatistics_busStatusLabel
FsmStatistics_endOfLabelTable:
FsmStatistics_errorTable:
                    .word           FsmStatistics_errNoError
                    .word           FsmStatistics_errStuff
                    .word           FsmStatistics_errForm
                    .word           FsmStatistics_errAck
                    .word           FsmStatistics_errRec
                    .word           FsmStatistics_errDom
                    .word           FsmStatistics_errCRC
                    .word           FsmStatistics_errSoft
FsmStatistics_endOfErrorTable:

    public_function(FsmStatistics_initStats)

@ int FsmStatistics_initStats(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   FSM Routine for the statistics display routines. Returns the next state, or 0 to remain in the same state

FsmStatistics_initStats:
                    push            {r7, lr}
                    bl              Display_clearDisplayBuffer
                    movs            r0, #StatTab
                    bl              FsmTabs_showTabs
                    bl              FsmStatistics_initData
                    bl              FsmStatistics_drawLabels
                    bl              FsmStatistics_drawButtons
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsmStatistics_update
                    pop             {r7, pc}

    public_function(FsmStatistics_waitToUpdate)

@ int FsmStatistics_waitToUpdate(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   FSM Routine for waiting before updating the display. Returns the next state, or 0 to remain in the same state

FsmStatistics_waitToUpdate:
                    push            {r7, lr}
                    bl              FsmStatistics_checkForInput
                    cmp             r0, #0
                    bne             9f
                    ldr             r7, = #FsmStatistics_data
                    bl              CanMessageLog_getLengthAndResetStatus @ update the number of messages received
                    ldr             r1, [r7, #__msgUpdateCntOffset]
                    adds            r1, r1, r0
                    str             r1, [r7, #__msgUpdateCntOffset]
                    ldr             r1, [r7, #__msgTotalCntOffset]
                    adds            r1, r1, r0
                    str             r1, [r7, #__msgTotalCntOffset]
                    ldrh            r1, [r7, #__updateIntOffset]    @ check if the update interval has timed out
                    ldrh            r2, [r7, #__updateCntOffset]
                    adds            r2, r2, #2
                    cmp             r2, r1
                    beq             0f
                    strh            r2, [r7, #__updateCntOffset]
                    movs            r0, #0
9:
                    pop             {r7, pc}
0:
                    movs            r2, #0
                    strh            r2, [r7, #__updateCntOffset]
                    ldr             r0, = #FsmStatistics_update
                    b               9b

    public_function(FsmStatistics_update)

@ int FsmStatistics_update(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   FSM Routine for updating the display with new data. Returns the next state, or 0 to remain in the same state

FsmStatistics_update:
                    push            {r7, lr}
                    bl              FsmStatistics_checkForInput
                    cmp             r0, #0
                    bne             9f
                    bl              FsmStatistics_display           @ display the data
                    ldr             r3, = #FsmStatistics_data       @ reset update count back to zero
                    movs            r0, #0
                    str             r0, [r3, #__msgUpdateCntOffset]
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsmStatistics_waitToUpdate
9:
                    pop             {r7, pc}

    private_function(FsmStatistics_initData)

@ void FsmStatistics_initData()
@   initialise data to initial settings

FsmStatistics_initData:
                    ldr             r3, = #FsmStatistics_data
                    ldr             r0, = #defaultUpdateInterval
                    strh            r0, [r3, #__updateIntOffset]
                    movs            r0, #0
                    strh            r0, [r3, #__updateCntOffset]
                    str             r0, [r3, #__msgUpdateCntOffset]
                    str             r0, [r3, #__msgTotalCntOffset]
                    strh            r0, [r3, #__inputStateOffset]
                    bx              lr

    private_function(FsmStatistics_checkForInput)

@ int FsmStatistics_checkForInput(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   check if the user is adjusted the rotary encoder position, or pressed the button, and take
@   the appropraite action. Returns 0 to keep the same FSM state, or a new FSM state.

__inputStateCaptureInputBit = 0



__inputStateCaptureInput    = 1<<__inputStateCaptureInputBit

FsmStatistics_checkForInput:
                    push            {r5-r7, lr}
                    rev16           r3, r2                          @ check if any user input
                    movs            r7, #FSM_STATE_INPUT
                    tst             r3, r7
                    beq             8f
                    ldr             r6, = #FsmStatistics_inputState
                    ldrh            r5, [r6]
                    movs            r7, #FSM_STATE_ROTENC_CHANGED   @ check if rotary encoder changed
                    tst             r3, r7
                    beq             __cfi_buttonCheck
                    movs            r7, #__inputStateCaptureInput   @ is the user "in" our tab, or just on the tab bar?
                    tst             r5, r7
                    bne             0f
                    movs            r2, #StatTab                    @ if tab bar, then check if user moved off this tab
                    bl              FsmTabs_checkInput
                    b               9f
0:

@ if rotary encoder and doing buttons, do button action on encoder change

__cfi_buttonCheck:
                    movs            r7, #FSM_STATE_BUTTON_CHANGED   @ check if button changed
                    tst             r3, r7
                    beq             8f

@ if button do button action

9:
                    pop             {r5-r7, pc}
8:
                    movs            r0, #0                          @ keep the same state
                    b               9b

    private_function(FsmStatistics_drawLabels)

@ void FsmStatistics_drawLabels()
@   draw the labels onto the display

FsmStatistics_drawLabels:
                    push            {r5-r7, lr}
                    ldr             r7, = #FsmStatistics_labelTable
                    movs            r6, #(FsmStatistics_endOfLabelTable-FsmStatistics_labelTable)/4
                    movs            r5, #0
0:
                    ldr             r1, = #DISPLAY_ROW_FLAG
                    adds            r1, r1, r5
                    adds            r1, r1, #1
                    movs            r2, #DISPLAY_WHITE
                    lsls            r0, r5, #2
                    ldr             r3, [r7, r0]
                    movs            r0, #0
                    bl              Display_drawString
                    adds            r5, r5, #1
                    cmp             r5, r6
                    bne             0b
                    pop             {r5-r7, pc}

    private_function(FsmStatistics_drawButtons)

@ void FsmStatistics_drawButtons()
@   draw the buttons on the button bar (last time on the display)

__resetButtonOffset     = 8
__updateButtonOffset    = 40
__updateValueOffset     = 73
__backButtonOffset      = ACB_DISPLAY_WIDTH-16

FsmStatistics_drawButtons:
                    push            {r7, lr}
                    ldr             r3, = #FsmStatistics_resetButton
                    movs            r0, #__resetButtonOffset
                    ldr             r1, = #(6 | DISPLAY_ROW_FLAG)
                    movs            r2, #DISPLAY_WHITE
                    bl              Display_drawString
                    ldr             r3, = #FsmStatistics_backButton
                    movs            r0, #__backButtonOffset
                    ldr             r1, = #(6 | DISPLAY_ROW_FLAG)
                    movs            r2, #DISPLAY_WHITE
                    bl              Display_drawString
                    ldr             r3, = #FsmStatistics_updateButton
                    movs            r0, #__updateButtonOffset
                    ldr             r1, = #(6 | DISPLAY_ROW_FLAG)
                    movs            r2, #DISPLAY_WHITE
                    bl              Display_drawString

                    ldr             r0, =#FsmStatistics_data
                    ldr             r0, [r0, #__updateIntOffset]
                    movs            r1, #DISPLAY_WHITE
                    bl              FsmStatistics_drawUpdateValue
                    pop             {r7, pc}

    private_function(FsmStatistics_drawUpdateValue)

@ void FsmStatistics_drawUpdateValue(int value, int colour)
@   display the update value on the last line, at __updateValueOffset position, in the supplied colour. If value is
@   less then a second, display as a fraction of a second, and if a minute value, display as a minute.

FsmStatistics_drawUpdateValue:
                    push            {r5-r7, lr}
                    movs            r5, #0                          @ value flag, 0: second
                    ldr             r6, =#FsmStatistics_tmpBuffer
                    movs            r7, r1
                    ldr             r2, = #1000                     @ check if it's less than a second
                    cmp             r0, r2
                    bge             0f
                    ldr             r3, =#FsmStatistics_fractionOfSecond
                    ldrh            r3, [r3]                        @ if so, start the string with 0.
                    strh            r3, [r6]                        @ and adjust the value to be a whole second
                    adds            r6, r6, #2
                    muls            r0, r0, r2
                    movs            r5, #1                          @ value flag, 1: fraction of a second
                    b               1f
0:                                                                  @ check if it's a minute or more
                    ldr             r1, = #(60*1000/MAINLOOP_DELAY)
                    cmp             r0, r1
                    blt             1f                              @ divide by 60, to show just a minute number
                    movs            r1, #60
                    bl              __aeabi_uidiv
                    movs            r5, #2                          @ value flag, 2: minute
1:
                    movs            r1, #MAINLOOP_DELAY
                    muls            r0, r0, r1
                    bl              Math_divu1000                   @ display value as a second
                    movs            r1, r6
                    movs            r2, #10
                    bl              itoa
                    bl              FsmStatistics_toEndOfString
                    cmp             r5, #0
                    beq             2f
                    cmp             r5, #2
                    beq             3f
0:                                                                  @ strip any trailing 0's
                    subs            r0, r0, #1
                    ldrb            r1, [r0]
                    cmp             r1, #'0'
                    bne             1f
                    subs            r0, r0, #1
                    b               0b
1:
                    adds            r0, r0, #1
2:
                    ldr             r1, = #FsmStatistics_seconds    @ add 's' to the end of the string
                    b               4f
3:
                    ldr             r1, = #FsmStatistics_minutes    @ add 'm' to the end of the string
4:
                    ldrb            r1, [r1]
                    strb            r1, [r0]
                    movs            r1, #0
                    strb            r1, [r0, #1]
                    ldr             r3, = #FsmStatistics_tmpBuffer
                    movs            r0, #__updateValueOffset
                    ldr             r1, = #(6 | DISPLAY_ROW_FLAG)
                    movs            r2, r7
                    bl              Display_drawString
                    pop             {r5-r7, pc}

    private_function(FsmStatistics_display)

@ void FsmStatistics_display()
@   display the statistics

FsmStatistics_display:
                    push            {r7, lr}
                    sub             sp, sp, #8                      @ clear existing results from the display
                    movs            r0, #dataXOffset
                    ldr             r1, = #(1 | DISPLAY_ROW_FLAG)
                    movs            r2, #DISPLAY_BLACK
                    movs            r3, #ACB_DISPLAY_WIDTH-dataXOffset
                    movs            r7, #(5 * DISPLAY_ROW_HEIGHT)
                    str             r7, [sp]
                    bl              Display_drawFilledRectangle     @ fill rectangle
                    add             sp, sp, #8

                    ldr             r7, = #FsmStatistics_data       @ output count since last update
                    ldr             r0, [r7, #__msgUpdateCntOffset]
                    mov             r1, r7
                    adds            r1, r1, #__tmpBufferOffset
                    movs            r2, #10
                    bl              itoa
                    movs            r3, r0
                    movs            r0, #dataXOffset
                    ldr             r1, = #(1 | DISPLAY_ROW_FLAG)
                    movs            r2, #DISPLAY_WHITE
                    bl              Display_drawString
                    ldr             r0, [r7, #__msgTotalCntOffset]
                    mov             r1, r7
                    adds            r1, r1, #__tmpBufferOffset
                    movs            r2, #10
                    bl              itoa
                    movs            r3, r0
                    movs            r0, #dataXOffset
                    ldr             r1, = #(2 | DISPLAY_ROW_FLAG)
                    movs            r2, #DISPLAY_WHITE
                    bl              Display_drawString
                    ldr             r0, = #CAN_BASE
                    ldr             r0, [r0, #CAN_ESR_OFFSET]
                    bl              FsmStatistics_displayError
                    pop             {r7, pc}

    private_function(FsmStatistics_displayError)

@ void FsmStatistics_displayError(int esr)
@   display any error information from the supplied data. ESR must be in the same format as the CAN_ESR register

FsmStatistics_displayError:
                    push            {r5-r7, lr}
                    movs            r7, r0
                    rev             r0, r0                          @ display number of receive and transmit errors
                    rev16           r6, r0
                    uxtb            r0, r0
                    uxtb            r6, r6
                    ldr             r1, = #FsmStatistics_tmpBuffer
                    ldr             r2, = #FsmStatistics_Tx         @ show transmit errors firstly
                    ldr             r3, [r2]                        @ as everthing is word aligned here, we can
                    str             r3, [r1]                        @ simply do a word memory copy
                    adds            r1, r1, #3
                    movs            r2, #10
                    bl              itoa
                    bl              FsmStatistics_toEndOfString     @ final trailing 0, then add " / RX" and
                    ldr             r1, = #FsmStatistics_Rx         @ then receive errors
2:
                    ldrb            r2, [r1]
                    cmp             r2, #0
                    beq             3f
                    strb            r2, [r0]
                    adds            r1, r1, #1
                    adds            r0, r0, #1
                    b               2b
3:
                    movs            r1, r0
                    movs            r0, r6                          @ convert RX error count
                    movs            r2, #10
                    bl              itoa
                    movs            r0, #dataXOffset
                    ldr             r1, = #(4 | DISPLAY_ROW_FLAG)
                    movs            r2, #DISPLAY_WHITE
                    ldr             r3, = #FsmStatistics_tmpBuffer
                    bl              Display_drawString

                    movs            r0, #CAN_ESR_LEC                @ display the last error text
                    ands            r0, r0, r7
                    lsrs            r0, #2
                    ldr             r1, = #FsmStatistics_errorTable
                    ldr             r3, [r1, r0]
                    movs            r0, #dataXOffset
                    ldr             r1, = #(3 | DISPLAY_ROW_FLAG)
                    movs            r2, #DISPLAY_WHITE
                    bl              Display_drawString

                    ldr             r6, = #FsmStatistics_tmpBuffer  @ display error/bus state
                    movs            r0, #CAN_ESR_BOFF               @ Bus On or Off
                    tst             r7, r0
                    bne             1f
                    ldr             r2, = #FsmStatistics_busOn
                    b               2f
1:
                    ldr             r2, = #FsmStatistics_busOff
2:
                    ldr             r1, [r2]                        @ text is word aligned, so just do a word copy
                    str             r1, [r6]
                    adds            r6, r6, #4
                    movs            r0, #' '
                    strb            r0, [r6]
                    adds            r6, r6, #1
                    movs            r0, #CAN_ESR_EPVF
                    tst             r0, r7
                    beq             3f
                    ldr             r1, = #FsmStatistics_busErrPassive
                    movs            r0, r6
                    bl              strcpy
                    bl              FsmStatistics_toEndOfString
                    movs            r6, r0

3:
                    movs            r0, #CAN_ESR_EWGF
                    tst             r0, r7
                    beq             4f
                    ldr             r1, = #FsmStatistics_busErrWarn
                    movs            r0, r6
                    bl              strcpy
                    bl              FsmStatistics_toEndOfString
                    movs            r6, r0
4:
                    movs            r1, #0
                    strb            r1, [r6]
                    movs            r0, #dataXOffset
                    ldr             r1, = #(5 | DISPLAY_ROW_FLAG)
                    movs            r2, #DISPLAY_WHITE
                    ldr             r3, = #FsmStatistics_tmpBuffer
                    bl              Display_drawString
                    pop             {r5-r7, pc}

    private_function(FsmStatistics_toEndOfString)

@ char* FsmStatistics_toEndOfString(char* str)
@   find the end of the string. Updates r0, uses r1, other registers are untouched.

FsmStatistics_toEndOfString:
0:                                                                  @ final trailing 0, then add " / RX" and
                    ldrb            r1, [r0]                        @ then receive errors
                    cmp             r1, #0
                    beq             1f
                    adds            r0, r0, #1
                    b               0b
1:
                    bx              lr

    .end
