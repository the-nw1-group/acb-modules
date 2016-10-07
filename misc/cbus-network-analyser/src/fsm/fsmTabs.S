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

@ Finite State Machine functions for displaying and navigating tabs

    module(FsmTabs)

FsmTabs_numberOfTabs = 5

    static_data(FsmTabs_tab)
FsmTabs_tab:
                    .word           __stat_data
                    .word           __graph_data
                    .word           __msg_data
                    .word           __log_data
                    .word           __tx_data

FsmTabs_selectedTabs:
                    .word           __stat_s_data
                    .word           __graph_s_data
                    .word           __msg_s_data
                    .word           __log_s_data
                    .word           __tx_s_data
FsmTabs_links:
                    .word           FsmStatistics_initStats
                    .word           FsmActivityGraph_initGraph
                    .word           0
                    .word           0
                    .word           0

    public_function(FsmTabs_showTabs)

@ void FsmTabs_showTabs(int selectedTab)
@   display the tab bar along the top "row" of the screen with the supplied tab selected

FsmTabs_showTabs:
                    push            {r3-r7, lr}
                    movs            r7, r0
                    movs            r0, #0                          @ blank the row of tabs out
                    ldr             r1, = #0 | DISPLAY_TAB_FLAG
                    movs            r2, #DISPLAY_BLACK
                    movs            r3, #ACB_DISPLAY_WIDTH
                    bl              Display_fillRow

                    ldr             r6, = #FsmTabs_tab
                    ldr             r5, = #FsmTabs_selectedTabs
                    movs            r4, #0
0:
                    cmp             r4, r7                          @ show normal or selected tab
                    bne             1f
                    movs            r3, r5
                    b               2f
1:
                    movs            r3, r6
2:
                    lsls            r2, r4, #2
                    ldr             r2, [r3, r2]
                    lsls            r0, r4, #4
                    ldr             r1, = #( 0 | DISPLAY_TAB_FLAG)
                    bl              Display_drawBitmap
                    adds            r4, r4, #1
                    cmp             r4, #FsmTabs_numberOfTabs
                    bne             0b

                    movs            r0, #0                          @ draw seperator
                    movs            r1, #(DISPLAY_TAB_HEIGHT-1)
                    movs            r2, #DISPLAY_WHITE
                    movs            r3, #ACB_DISPLAY_WIDTH
                    bl              Display_drawHorizontalLine
                    pop             {r3-r7, pc}


    public_function(FsmTabs_checkInput)

@ int FsmTabs_checkInput(short oldRotEnc, short newRotEnc, int selectedTab)
@   check if the user is adjusted the rotary encoder position and has selected to move to another tab. Returns 0 if
@   trying to move off either end of the tabs, or the new FSM routine for the tabs.

FsmTabs_checkInput:
                    subs            r1, r1, r0                      @ how much has the rotary encoder changed by
                    adds            r1, r1, r2                      @ add on the current position
                    bge             0f                              @ if less than zero, then adjust to just zero
                    movs            r1, #0
                    b               1f
0:
                    cmp             r1, #CBUSNA_MAX_TAB             @ greater than the number of tabs
                    ble             1f                              @ adjust to the number of tabs
                    movs            r1, #CBUSNA_MAX_TAB
1:
                    cmp             r1, r2                          @ if it's not changed, then just return
                    beq             8f
                    ldr             r0, = #FsmTabs_links            @ otherwise load new FSM routine to handle
                    lsls            r1, r1, #2                      @ tab change
                    ldr             r0, [r0, r1]
9:
                    bx              lr
8:
                    movs            r0, #0
                    b               9b

    .end
