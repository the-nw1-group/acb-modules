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

    module(FsmActivityGraph)

    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         FsmCommon_showTabs                              @ show the tab row

/*
 * Useful constants
 *
 */

graphStartX = 1
graphStartY = 2 + DISPLAY_TAB_HEIGHT @ (3 * DISPLAY_TAB_HEIGHT)/2
graphHeight = graphDataHeight + graphAxisScaleWidthHeight
graphWidth  = ACB_DISPLAY_WIDTH - 1 * graphStartX

graphDataStartX     = 3
graphDataStartY     = graphStartY
graphDataHeight     = 32
graphDataWidth      = graphWidth - 2

graphYScaleChange           = 32
graphYTickSpacing           = 8

graphAxisScaleWidthHeight   = 2
defaultXScaleSpacing        = 8
defaultUpdateInterval       = 30 @ 600

    private_data(FsmActivityGraph_privateData)

FsmActivityGraph_data:
FsmActivityGraph_yScale:                                            @ y scaling factor
                    .byte           graphYScaleChange / graphYScaleChange
FsmActivityGraph_xScaleOffset:                                      @ how far is the x scale offset from 0 (0 to 8 value)
                    .byte           defaultXScaleSpacing
FsmActivityGraph_xPosition:                                         @ current X position
                    .byte           0
FsmActivityGraph_dataInsertPoint:                                   @ where to insert next data point
                    .byte           0
FsmActivityGraph_updateInterval:                                    @ how often to update the graph
                    .short          defaultUpdateInterval
FsmActivityGraph_updateCounter:                                     @ current update count
                    .short          0
FsmActivityGraph_thisUpdate:
                    .word           0
FsmActivityGraph_total:
                    .word           0
FsmActivityGraph_dataPoints:                                        @ the data points. Y scalling applied as data is
                    .space          graphDataWidth * 2, 0           @ drawn, not stored
FsmActivityGraph_buffer:
                    .string         "    "


__yScaleOffset      = 0
__xScaleOffset      = 1
__xPosOffset        = 2
__dataInsertOffset  = 3
__updateIntOffset   = 4
__updateCntOffset   = 6
__thisUpdateOffset  = 8
__totalOffset       = 12
__dataPointsOffset  = 16


    static_data(FsmActivityGraph_staticData)
FsmActivityGraph_staticData:
__testLabel1:       .string         "Test Label #1yy"
__testLabel2:       .string         "Test Label #2jj"

    public_function(FsmActivityGraph_initGraph)

@ void FsmCommon_dispatch(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   FSM Routine for the Activity Graph routines. Returns the next state, or 0 to remain in the same state

FsmActivityGraph_initGraph:
                    push            {r7, lr}

                    bl              Display_clearDisplayBuffer
                    movs            r0, #ActivityGraphTab
                    bl              FsmTabs_showTabs
                    bl              FsmActivityGraph_initData
                    bl              FsmActivityGraph_drawAxis
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsmActivityGraph_waitToUpdate @ todo, change to update once written
                    pop             {r7, pc}

    public_function(FsmActivityGraph_waitToUpdate)

@ void FsmActivityGraph_waitToUpdate(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   FSM Routine for waiting before updating the display. Returns the next state, or 0 to remain in the same state

FsmActivityGraph_waitToUpdate:
                    push            {r7, lr}

    @ display encoder value ... temp ...

    movs            r0, #0
    ldr             r1, = #(5 | DISPLAY_ROW_FLAG)
    movs            r2, #DISPLAY_BLACK
    movs            r3, #ACB_DISPLAY_WIDTH
    bl              Display_fillRow

    ldr             r0, = #CBUSNA_ROTENC_TIMBASE
    ldr             r0, [r0, #TIM_CNT_OFFSET]
    ldr             r1, = #FsmActivityGraph_buffer
    movs            r2, #10
    bl              itoa
    movs            r3, r0
    movs            r0, #0
    ldr             r1, = #(5 | DISPLAY_ROW_FLAG)
    movs            r2, #DISPLAY_WHITE
    bl              Display_drawString
    bl              Display_blitDisplayBuffer

    @ check for activity on encoder, or button here...

                    ldr             r7, = #FsmActivityGraph_data
                    bl              CanMessageLog_getLength
                    ldr             r1, [r7, #__thisUpdateOffset]
                    adds            r1, r1, r0
                    str             r1, [r7, #__thisUpdateOffset]
                    ldr             r1, [r7, #__totalOffset]
                    adds            r1, r1, r0
                    str             r1, [r7, #__totalOffset]
                    bl              CanMessageLog_resetStatus
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
                    ldr             r0, = #FsmActivityGraph_update

                    b               9b

    public_function(FsmActivityGraph_update)

@ void FsmActivityGraph_update(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   FSM Routine for updating the graph with new data. Returns the next state, or 0 to remain in the same state

FsmActivityGraph_update:
                    push            {r4-r7, lr}
                    ldr             r7, = #FsmActivityGraph_data
                    ldr             r0, [r7, #__thisUpdateOffset]
                    movs            r1, #0
                    str             r1, [r7, #__thisUpdateOffset]
                    ldrb            r4, [r7, #__dataInsertOffset]   @ get where to put new sample
                    cmp             r4, #(2*graphDataWidth)-2
                    bgt             8f
                    adds            r2, r4, #2
                    strb            r2, [r7, #__dataInsertOffset]
                    adds            r7, r7, #__dataPointsOffset
                    strh            r0, [r7, r4]

                    ldr             r6, =#FsmActivityGraph_data
                    ldrb            r1, [r6, #__yScaleOffset]
                    cmp             r1, #1
                    beq             0f
                    bl              __aeabi_uidiv
0:
                    movs            r2, #graphDataHeight            @ get y-position of data on graph
                    subs            r2, r2, r0
                    adds            r2, r2, #graphDataStartY

                    lsrs            r0, r4, #1                      @ get x-position of new data point on graph
                    adds            r0, r0, #graphDataStartX
                    movs            r1, r2
                    movs            r2, #DISPLAY_WHITE
                    bl              Display_drawPixel
9:
                    bl              FsmActivityGraph_checkAndReScaleGraph
                    cmp             r0, #TRUE                       @ if we rescaled, then redraw the scale and the
                    bne             7f                              @ graph
                    bl              FsmActivityGraph_drawAxisScale
                    bl              FsmActivityGraph_redrawGraph
7:
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsmActivityGraph_waitToUpdate @ wait for next update
                    pop             {r4-r7, pc}
8:                                                                  @ at the end of data, so shift data back, and
                                                                    @ redraw the whole graph
                    ldrb            r2, [r7, #__xScaleOffset]       @ move the x scale back one
                    subs            r2, r2, #1
                    bne             1f
                    movs            r2, #defaultXScaleSpacing
1:
                    strb            r2, [r7, #__xScaleOffset]
                    adds            r7, r7, #(__dataPointsOffset)
                    movs            r3, r0
                    movs            r1, #2
0:
                    ldrh            r0, [r7, r1]                    @ shift existing sample to the left
                    subs            r2, r1, #2
                    strh            r0, [r7, r2]
                    adds            r1, r1, #2
                    cmp             r1, #(2*graphDataWidth)
                    bne             0b
                    subs            r1, r1, #2
                    strh            r3, [r7, r1]                    @ store latest sample
                    bl              FsmActivityGraph_checkAndReScaleGraph
                    bl              FsmActivityGraph_redrawGraph
                    bl              FsmActivityGraph_drawAxisScale
                    b               9b

    private_function(FsmActivityGraph_initData)

@ void FsmActivityGraph_initData()
@   initialise data to initial settings

FsmActivityGraph_initData:
                    ldr             r3, = #FsmActivityGraph_data
                    movs            r0, #defaultXScaleSpacing
                    strb            r0, [r3, #__xScaleOffset]
                    movs            r0, #(graphYScaleChange/graphYScaleChange)
                    strb            r0, [r3, #__yScaleOffset]
                    ldr             r0, = #defaultUpdateInterval
                    strh            r0, [r3, #__updateIntOffset]
                    movs            r0, #0
                    strh            r0, [r3, #__xPosOffset]         @ put zero in __dataInsertOffset as well
                    strh            r0, [r3, #__updateCntOffset]
                    str             r0, [r3, #__thisUpdateOffset]
                    str             r0, [r3, #__totalOffset]
                    movs            r1, #(2*graphDataWidth)-2
                    adds            r3, r3, #__dataPointsOffset
0:
                    strh            r0, [r3, r1]
                    subs            r1, r1, #2
                    bcc             0b
                    bx              lr

    private_function(FsmActivityGraph_drawAxis)

@ void FsmActivityGraph_drawAxis()
@   draws the activity graph axis and scale. The scale is based on x position, and y scale. Marks are at nominally at 8,
@   until the y scale becomes such, that each row would be 8, and then they are scaled appropriately.

FsmActivityGraph_drawAxis:
                    push            {r7, lr}
                    movs            r0, #(graphStartX + graphAxisScaleWidthHeight/2)
                    movs            r1, #graphStartY
                    movs            r2, #DISPLAY_WHITE
                    movs            r3, #graphHeight
                    bl              Display_drawVerticalLine
                    movs            r0, #graphStartX
                    movs            r1, #graphStartY + graphHeight - graphAxisScaleWidthHeight
                    movs            r2, #DISPLAY_WHITE
                    movs            r3, #graphWidth
                    bl              Display_drawHorizontalLine
                    bl              FsmActivityGraph_drawAxisScale
                    pop             {r7, pc}

    private_function(FsmActivityGraph_drawAxisScale)

@ void FsmActivityGraph_drawAxisScale()
@   draws the activity graph scale. The scale is based on x position, and y scale. Marks are at nominally at 8,
@   until the y scale becomes such, that each row would be 8, and then they are scaled appropriately.

FsmActivityGraph_drawAxisScale:
                    push            {r5-r7, lr}
                    movs            r0, #graphStartX
                    movs            r1, #graphStartY
                    movs            r2, #DISPLAY_BLACK
                    movs            r3, #graphDataHeight
                    bl              Display_drawVerticalLine        @ clear existing y scale tick marks
                    movs            r0, #graphDataStartX
                    movs            r1, #graphStartY + graphHeight - graphAxisScaleWidthHeight/2
                    movs            r2, #DISPLAY_BLACK
                    movs            r3, #graphDataWidth
                    bl              Display_drawHorizontalLine      @ clear existing x scale tick marks

                    movs            r5, #0                          @ draw vertical scale
                    bl              FsmActivityGraph_getYTickSpacing
                    movs            r6, r0
                    ldr             r7, = #FsmActivityGraph_data
0:
                    movs            r0, #graphStartX
                    movs            r1, #graphStartY + graphHeight - graphAxisScaleWidthHeight
                    subs            r1, r1, r5
                    bl              Display_setPixel
                    add             r5, r5, r6
                    cmp             r5, #graphDataHeight
                    ble             0b

                    movs            r5, #0                          @ draw horizontal scale
                    ldrb            r6, [r7, #__xScaleOffset]
1:
                    mov             r0, r6
                    adds            r0, r0, #graphDataStartX - graphAxisScaleWidthHeight/2
                    adds            r0, r0, r5
                    movs            r1, #graphStartY + graphHeight - graphAxisScaleWidthHeight/2
                    bl              Display_setPixel
                    adds            r5, r5, #defaultXScaleSpacing
                    cmp             r5, #graphWidth
                    ble             1b
                    pop             {r5-r7, pc}

    private_function(FsmActivityGraph_getYTickSpacing)

@ int FsmActivityGraph_getYTickSpacing(void)
@   calculate and return the tick mark spacing for the Y axis

FsmActivityGraph_getYTickSpacing:
                    push            {r3-r7, lr}
                    ldr             r7, = #FsmActivityGraph_data
                    ldrb            r4, [r7, #__yScaleOffset]
                    movs            r0, #graphYScaleChange
                    muls            r4, r4, r0
                    movs            r5, #graphDataHeight
                    movs            r6, #graphYTickSpacing
                    cmp             r4, #graphDataHeight
                    ble             8f
0:
                    muls            r5, r5, r6
                    movs            r0, r5
                    movs            r1, r4
                    bl              __aeabi_uidiv
                    cmp             r0, #1
                    bgt             9f
                    lsls            r6, r6, #1
                    b               0b
9:
                    pop             {r3-r7, pc}
8:
                    movs            r0, r6
                    b               9b

    private_function(FsmActivityGraph_redrawGraph)

@ void FsmActivityGraph_redrawGraph(void)
@   redraw the graph based on the stored data

FsmActivityGraph_redrawGraph:
                    push            {r4-r7, lr}
                    mov             r7, r8                          @ save R8
                    push            {r6-r7}

                    sub             sp, sp, #8
                    movs            r0, #graphDataStartX
                    movs            r1, #graphDataStartY
                    movs            r2, #DISPLAY_BLACK
                    movs            r3, #graphDataWidth
                    movs            r7, #graphDataHeight
                    str             r7, [sp]
                    bl              Display_drawFilledRectangle     @ fill rectangle
                    add             sp, sp, #8

                    ldr             r7, = #FsmActivityGraph_data
                    ldrb            r6, [r7, #__yScaleOffset]
                    mov             r8, r6

                    adds            r7, r7, #__dataPointsOffset
                    ldr             r6, = #graphDataWidth
                    lsls            r6, r6, #1                      @ data is stored in half words
                    movs            r5, #graphDataStartX
                    movs            r4, #graphDataStartY
0:
                    ldrh            r0, [r7, r6]
                    mov             r1, r8
                    cmp             r1, #1
                    beq             1f
                    bl              __aeabi_uidiv
1:
                    movs            r1, #graphDataHeight            @ get y-position of data on graph
                    subs            r1, r1, r0
                    adds            r1, r1, r4
                    lsrs            r0, r6, #1                      @ get x-position of data on the graph
                    adds            r0, r0, r5
                    movs            r2, #DISPLAY_WHITE
                    bl              Display_drawPixel
                    subs            r6, r6, #2
                    bcs             0b

                    pop             {r6-r7}
                    mov             r8, r7                          @ restore R8
                    pop             {r4-r7, pc}

    private_function(FsmActivityGraph_checkAndReScaleGraph)

@ int FsmActivityGraph_checkAndReScaleGraph(void)
@   check all the data points and see if the yScale needs modifying.
@   Returns TRUE if the yScale is modified, otherwise FALSE.

FsmActivityGraph_checkAndReScaleGraph:
                    push            {r7, lr}
                    ldr             r3, = #FsmActivityGraph_dataPoints
                    ldr             r2, = #(graphDataWidth * 2)-2   @ find the maximum data point
                    movs            r1, #0
0:
                    ldrh            r0, [r3, r2]
                    cmp             r0, r1
                    ble             1f
                    mov             r1, r0
1:
                    subs            r2, r2, #2
                    bcs             0b

                    subs            r0, r1, #1                      @ get nearest graphYScaleChange value, rounding up
                    movs            r1, #graphYScaleChange
                    bl              __aeabi_uidiv
                    adds            r0, r0, #1
                    cmp             r0, #1
                    bge             2f
                    movs            r0, #1                          @ ensure it's always at least a scale of 1
2:
                    ldr             r3, = #FsmActivityGraph_data
                    ldrb            r1, [r3, #__yScaleOffset]
                    strb            r0, [r3, #__yScaleOffset]
                    movs            r2, #FALSE
                    cmp             r0, r1
                    beq             9f
                    movs            r2, #TRUE
9:
                    movs            r0, r2
                    pop             {r7, pc}

    .end
