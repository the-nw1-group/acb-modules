<?xml version="1.0" encoding="utf-8"?>
<xsl:transform version="3.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                             xmlns:f="http://www.thenw1group.com/xslt/functions">

    <xsl:output method="text" indent="no" omit-xml-declaration="yes"/>

    <xsl:strip-space elements="*"/>

    <xsl:variable name="new-line" select="'&#10;'" />

  <!-- Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

  <!-- copied, with respect, 
    from http://stackoverflow.com/questions/22905134/convert-a-hexadecimal-number-to-an-integer-in-xslt -->
    <xsl:function name="f:hexToDec">
        <xsl:param name="hex"/>
        <xsl:variable name="dec" select="string-length(substring-before('0123456789ABCDEF', substring($hex,1,1)))"/>
        <xsl:choose>
            <xsl:when test="matches($hex, '([0-9]*|[A-F]*)')">
                <xsl:value-of
                    select="if ($hex = '') then 0
                    else $dec * f:power(16, string-length($hex) - 1) + f:hexToDec(substring($hex,2))"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:message>Provided value is not hexadecimal...</xsl:message>
                    <xsl:value-of select="$hex"/>
                </xsl:otherwise>
            </xsl:choose>
    </xsl:function>

    <xsl:function name="f:power">
        <xsl:param name="base"/>
        <xsl:param name="exp"/>
        <xsl:sequence
            select="if ($exp lt 0) then f:power(1.0 div $base, -$exp)
                    else if ($exp eq 0)
                    then 1e0
                    else $base * f:power($base, $exp - 1)"/>
    </xsl:function>

    <xsl:function name="f:decToHex">
        <xsl:param name="dec"/>
        <xsl:if test="$dec > 0">
        <xsl:value-of
            select="f:decToHex(floor($dec div 16)),substring('0123456789ABCDEF', (($dec mod 16) + 1), 1)"
            separator=""/>
        </xsl:if>
    </xsl:function>

    <!-- adapted from http://www.xsltfunctions.com/xsl/functx_pad-string-to-length.html -->
    <xsl:function name="f:string-left-pad">
        <xsl:param name="padString"/>
        <xsl:param name="padChar"/>
        <xsl:param name="padCount"/>
        <xsl:sequence select="concat(string-join((for $i in 1 to $padCount - (string-length($padString)) return $padChar), ''), $padString)"/>
    </xsl:function>

    <!-- from http://www.xsltfunctions.com/xsl/functx_repeat-string.html -->
    <xsl:function name="f:repeat-string">
        <xsl:param name="stringToRepeat"/>
        <xsl:param name="count"/>
        <xsl:sequence select=" string-join((for $i in 1 to $count return $stringToRepeat), '')"/>
    </xsl:function>

    <!-- from http://www.xsltfunctions.com/xsl/functx_lines.html -->
    <xsl:function name="f:lines" >
        <xsl:param name="arg"/>
        <xsl:sequence select="tokenize($arg, '(\r\n?|\n\r?)') "/>
    </xsl:function>

    <xsl:function name="f:cbus-message-size">
        <xsl:param name="opCode"/>
        <xsl:value-of select="floor(f:hexToDec($opCode) div 32)" />
    </xsl:function>

    <xsl:function name="f:cbus-message-size-2">
        <xsl:param name="arg-pattern"/>
        <xsl:value-of select="((count(tokenize($arg-pattern, 'S'))-1) * 2) + count(tokenize($arg-pattern, 'B'))-1" />
    </xsl:function>

    <xsl:function name="f:arg-size">
        <xsl:param name="arg-type"/>
        <xsl:value-of select="if ($arg-type = 'S') then 2 else 1"/>
    </xsl:function>

    <xsl:function name="f:arg-position">
        <xsl:param name="arg-pattern"/>
        <xsl:param name="index"/>
        <xsl:value-of select="if ($index = 0) then 0 else f:cbus-message-size-2(substring($arg-pattern, 1, $index))"/>
    </xsl:function>

    <xsl:function name="f:comment-text">
        <xsl:param name="text"/>
        <xsl:for-each select="f:lines($text)[string-length(normalize-space(.)) &gt; 0]">
            <xsl:sequence select="replace(concat(normalize-space(.),' '), '(.{0,80}) ', '@   $1&#xA;')"/>
        </xsl:for-each>
    </xsl:function>

  <!-- End of Functions  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

  <!-- template /CBUS_Message_List - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template match="/CBUS_Message_List">/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */
  
@ Generated File (<xsl:value-of select="current-dateTime()"/>
    <xsl:text/>) based on version <xsl:value-of select="version"/>
    <xsl:text> </xsl:text><xsl:value-of select="gendate"/>
@ Revision History<xsl:apply-templates select="revisionHistory/revision"/>

#include "moduleInfo.inc"
#include "acb_common.inc"

    module(cbus_messages)
    <xsl:call-template name="vector-map"/>
    <xsl:call-template name="default-message-handlers"/>
    <xsl:call-template name="handle-cbus-message"/>
    <xsl:call-template name="send-cbus-message"/>
    .end
  </xsl:template>

<!-- template match * (unmatched)  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template match="*"/>
  
<!-- template match revision - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template match="revision">
@ Revision <xsl:value-of select="version"/>
<xsl:value-of select="f:repeat-string(' ', 4 - string-length(version))"/><xsl:value-of select="date"/>
<xsl:value-of select="f:repeat-string(' ', 4)"/><xsl:value-of select="author"/>
<xsl:value-of select="f:repeat-string(' ', 20 - string-length(author))"/><xsl:value-of select="comment"/>
    </xsl:template>
  
<!-- template name vector-map  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template name="vector-map">
    private_function(CBUS_vectorTable)

CBUS_vectorTable:                                                   @ Note: + 1 to ensure the processor stays in thumb mode<xsl:apply-templates select="message" mode="jump-table">
      <xsl:sort select="f:hexToDec(opcode)" order="ascending" data-type="number"/>
    </xsl:apply-templates>

    </xsl:template>

<!-- template name default-message-handlers  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template name="default-message-handlers">

@ provide weak aliases for all the message handlers
        <xsl:for-each select="distinct-values(message/acronym)">
            <xsl:sort select="." order="ascending" data-type="text"/>
    .extern         CBUS_on<xsl:value-of select="."/>
    .weak           CBUS_on<xsl:value-of select="."/>
    .thumb_set      CBUS_on<xsl:value-of select="."/>, CBUS_defaultMessageHandler</xsl:for-each>

    public_override(CBUS_defaultMessageHandler)

@ void CBUS_defaultMessageHandler(MSG* pcbusMessage)
@   the default message handler - which simply returns. Is a weak reference, so can be overridden.

CBUS_defaultMessageHandler:
                    bx              lr                              @ simply return
    </xsl:template>

<!-- template name handle-cbus-message - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template name="handle-cbus-message">
    public_function(CBUS_handleMessage)

@ void CBUS_handleMessage(MSG* pcbusMessage)
@   processes a cbus message by calling the appropriate message handler. If no handler defined then calls the default
@   message handler. Message handlers are called CBUS_on&lt;opcode&gt;, for example: CBUS_onNNULN and CBUS_onPARAMS. 
@   For those messages where the opcode isn't defined an onRESERVED is called, and are supplied with the opCode and any 
@   other parameters as a byte array. Note the supplied ptr to the byte array will *NOT* be word aligned. (See section
@   4.3.3 of the ARM EABI). CBUS_on&lt;opcode&gt; function prototype is:
@
@   void CBUS_on&lt;opcode&gt;(byte opCode, byte[] data)

CBUS_handleMessage:                                                 @ handle a cbus message
                    adds            r1, r0, #ACB_MSG_DATA_LOW_OFFSET + 1
                    ldrb            r0, [r0, #ACB_MSG_DATA_LOW_OFFSET]

                    ldr             r2, = #CBUS_vectorTable
                    movs            r3, #1                          @ clear the THUMB bit in the location address
                    bics            r2, r2, r3
                    lsls            r3, r0, #2
                    adds            r2, r2, r3
                    ldr             r2, [r2]

                    bx              r2
    </xsl:template>

<!-- template name send-cbus-message - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template name="send-cbus-message">
        <xsl:apply-templates select="message[compare(acronym,'RESERVED')!=0]" mode="send-message">
            <xsl:sort select="f:hexToDec(opcode)" order="ascending" data-type="number"/>
        </xsl:apply-templates>

    @ All CBUS_sendMessageX are private functions as they are possibly called with only word aligned stacks (in the case
    @ where X=4..7) This is corrected in the following functions before calling any public functions. If you need
    @ to send an arbitrary CBUS message, use CBUS_sendMessage instead.
        <xsl:for-each select="for $i in 0 to 7 return $i">
    private_function(CBUS_sendMessage<xsl:value-of select="."/>)        

@ void CBUS_sendMessage<xsl:value-of select="."/>(<xsl:for-each select="for $j in 1 to . return $j">byte data<xsl:value-of select="."/>, </xsl:for-each>byte OPC)<xsl:choose><xsl:when test=". = 0">
@   Sends a no-data CBUS message. First parameter is the opcode of the message to send</xsl:when><xsl:otherwise>
@   Sends a <xsl:value-of select="."/> data byte CBUS message. Last parameter is the opcode of the message to send</xsl:otherwise>
            </xsl:choose>
        
CBUS_sendMessage<xsl:value-of select="."/>:
                    push            {r4-r6, lr}
                    sub             sp, sp, #ACB_MSG_SIZE<xsl:value-of select="if (number(.) &lt; 4) then ' + 4' else '    '"/>       @ reserve space for the message; keep 8-byte alignment 
                    add             r5, sp, #0
                    movs            r6, #<xsl:value-of select="number(.) + 1"/>                          @ message length, <xsl:value-of select="number(.) + 1"/> byte(s)
                    strb            r6, [r5, #ACB_MSG_INFO_LEN_OFFSET]<xsl:variable name="opc-arg" select="if (number(.) &lt; 4) then . else 6"/><xsl:if test="number(.) &gt; 3">
                    ldrb            r6, [r5, #(ACB_MSG_SIZE + 16)]  @ load OPC from stacked parameters into r6</xsl:if>                   
                    <xsl:for-each select="for $j in 1 to min( (., 3) ) return $j"><xsl:variable name="arg" select="number(.)-1"/>
                    lsls            r<xsl:value-of select="$arg"/>, r<xsl:value-of select="$arg"/>, #<xsl:value-of select="number(.) * 8"/>
                    orrs            r<xsl:value-of select="$opc-arg"/>, r<xsl:value-of select="$opc-arg"/>, r<xsl:value-of select="$arg"/></xsl:for-each>
                    str             r<xsl:value-of select="$opc-arg"/>, [r5, #ACB_MSG_DATA_LOW_OFFSET]<xsl:if test="number(.) &gt; 3">
                    movs            r6, r5
                    adds            r6, r6, #ACB_MSG_SIZE + 20      @ r6 is ptr to parameter supplied on the stack<xsl:for-each select="for $j in 4 to . - 1 return $j">
                    ldrb            r0, [r6, #<xsl:value-of select="(. - 4) * 4"/>]
                    lsls            r0, r0, #<xsl:value-of select="(. - 3) * 8"/>
                    orrs            r3, r3, r0</xsl:for-each>
                    str             r3, [r5, #ACB_MSG_DATA_HIGH_OFFSET]</xsl:if>
                    movs            r0, r5
                    bl              Can_sendMessage
                    add             sp, sp, #ACB_MSG_SIZE<xsl:value-of select="if (number(.) &lt; 4) then ' + 4' else '    '"/>       @ restore stack (collapse stack frame)<xsl:choose>
                        <xsl:when test="number(.) &gt; 3">
                    movs            r1, r7                          @ save r7
                    pop             {r4-r7}                         @ need to remove OPC from stack before returning, so pop lr into r7
                    pop             {r0}                            @ pop off OPC (can't do this in the above statement, as the registers
                                                                    @ are popped off in numerical order, and we can only use r0-r3 here...),
                    movs            r0, r7
                    movs            r7, r1                          @ restore r7
                    bx              r0                              @ and return
                        </xsl:when>
                        <xsl:otherwise>
                    pop             {r4-r6, pc}
                        </xsl:otherwise>
                    </xsl:choose>
        </xsl:for-each>

@ void CBUS_sendMessage_XXXXX(variable, byte OPC)
@   Sends a CBUS data message, where the parameters are made up of variable numbers of B bytes and S shorts.
@   Last parameter is the opcode of the message to send (and isn't included in the method name)
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'BSB'"/></xsl:call-template>
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'BSBB'"/></xsl:call-template>
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'BSBBBB'"/></xsl:call-template> <!-- broken for the time being -->

        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'S'"/></xsl:call-template>
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'SS'"/></xsl:call-template>
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'SSS'"/></xsl:call-template>

        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'SB'"/></xsl:call-template>
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'SBB'"/></xsl:call-template>
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'SBBB'"/></xsl:call-template>
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'SBBBBB'"/></xsl:call-template> <!-- broken for the time being -->

        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'SSB'"/></xsl:call-template>
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'SSBB'"/></xsl:call-template>
        <xsl:call-template name="message-opt-params"><xsl:with-param name="arg-format" select="'SSBBB'"/></xsl:call-template>  <!-- broken for the time being -->

    public_function(CBUS_sendMessage)        

@ void CBUS_sendMessage(byte opCode, byte[] data)
@   Sends a arbitrary CBUS message. The first parameter is the opCode, the 2nd is the array of bytes to send which must
@   be the same length as the message length defined in the opCode (top 3 bits).

CBUS_sendMessage:
                    push            {r7, lr}
                    lsrs            r2, r0, #5                      @ get message length
                    adds            r3, r2, #1
                    sub             sp, sp, #ACB_MSG_SIZE + 4       @ reserve space for message; keep 8 byte alignment
                    mov             r7, sp
                    strb            r3, [r7, #ACB_MSG_INFO_LEN_OFFSET]
                    strb            r0, [r7, #ACB_MSG_DATA_LOW_OFFSET]   @ store opCode as first data byte of message
                    cmp             r2, #0
                    beq             0f
                    subs            r1, r1, #1
                    adds            r3, r7, #ACB_MSG_DATA_LOW_OFFSET
1:
                    ldrb            r0, [r1, r2]                    @ copy data bytes from supplied data array
                    strb            r0, [r3, r2]
                    subs            r2, r2, #1
                    bne             1b
0:
                    movs            r0, r7
                    bl              Can_sendMessage
                    add             sp, sp, #ACB_MSG_SIZE + 4
                    pop             {r7, pc}

    </xsl:template>

<!-- template match message (jump table) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template match="message" mode="jump-table"><xsl:choose>
        <xsl:when test="compare(acronym,'RESERVED')=0">
    .word           CBUS_on<xsl:value-of select="acronym"/> + 1<xsl:value-of select="f:repeat-string(' ', 37 - string-length(acronym))"/>@ Reserved for future use (<xsl:value-of select="opcode"/>)</xsl:when>
      <xsl:otherwise>
    .word           CBUS_on<xsl:value-of select="acronym"/> + 1<xsl:value-of select="f:repeat-string(' ', 37 - string-length(acronym))"/>@ <xsl:value-of select="description"/> (<xsl:value-of select="opcode"/>)</xsl:otherwise>
        </xsl:choose>
    <!-- test that we have all opcodes from 0x00 to 0xFF -->
        <xsl:choose>
            <xsl:when test="compare(opcode, '0x00')=0">
                <xsl:if test="exists(parent::node()/message[compare(opcode, '0x01')=0])=false()">
                    <xsl:message terminate="yes">Missing opcode 0x01. Please check source XML document</xsl:message>
                </xsl:if>
            </xsl:when>
            <xsl:when test="compare(opcode, '0xFF')=0">
                <xsl:if test="exists(parent::node()/message[compare(opcode, '0xFE')=0])=false()">
                    <xsl:message terminate="yes">Missing opcode 0xFE. Please check source XML document</xsl:message>
                </xsl:if>
            </xsl:when>
            <xsl:otherwise>
                <xsl:variable name="next-opcode" select="concat('0x', f:string-left-pad(f:decToHex(f:hexToDec(opcode)+1), '0', 2))"/>
                <xsl:variable name="prev-opcode" select="concat('0x', f:string-left-pad(f:decToHex(f:hexToDec(opcode)-1), '0', 2))"/>
                <xsl:if test="exists(parent::node()/message[compare(opcode, $prev-opcode)=0])=false()">
                    <xsl:message terminate="yes">Missing opcode <xsl:value-of select="$prev-opcode"/>. Please check source XML document</xsl:message>
                </xsl:if>
                <xsl:if test="exists(parent::node()/message[compare(opcode, $next-opcode)=0])=false()">
                    <xsl:message terminate="yes">Missing opcode <xsl:value-of select="$next-opcode"/>. Please check source XML document</xsl:message>
                </xsl:if>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>

<!-- template match message (send message) - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template match="message" mode="send-message">
    
    <xsl:variable name="suffix"><xsl:if test="count(*[paramType != 'other']) &gt; 0">Ex</xsl:if></xsl:variable>
        
    public_override(CBUS_send<xsl:value-of select="concat(acronym,$suffix)"/>) 

@ void CBUS_send<xsl:value-of select="concat(acronym,$suffix)"/>(<xsl:for-each select="*[starts-with(name(), 'data')]">
            <xsl:sort select="name()" order="ascending" data-type="text"/>byte <xsl:value-of select="bytecont"/><xsl:if test="position() != last()">, </xsl:if></xsl:for-each>)
@   Sends a <xsl:value-of select="description"/> (<xsl:value-of select="acronym"/>) message, blocking until the message is on a transmission queue.
<xsl:value-of select="string-join(f:comment-text(documentation), '')"/><xsl:if test="string-length(annotation) &gt; 0">
<xsl:value-of select="string-join(f:comment-text(annotation), '')"/></xsl:if><xsl:for-each select="*[starts-with(name(), 'data')]">
        <xsl:sort select="name()" order="ascending" data-type="text"/>
@       <xsl:value-of select="bytecont"/><xsl:value-of select="f:repeat-string(' ', 20 - string-length(bytecont))"/><xsl:value-of select="bytedesc"/>        
    </xsl:for-each>
    <xsl:if test="compare($suffix, 'Ex')=0">
    
@    Note: "Ex" version of method, supply all arguments as bytes. Use CBUS_send<xsl:value-of select="acronym"/> to supply multi-byte values as single arguments.</xsl:if>

CBUS_send<xsl:value-of select="concat(acronym,$suffix)"/>:
OPC_<xsl:value-of select="acronym"/> = <xsl:value-of select="opcode"/>
            <xsl:choose>
                <xsl:when test="f:cbus-message-size(opcode) &lt; 4">
                    movs            r<xsl:value-of select="f:cbus-message-size(opcode)"/>, OPC_<xsl:value-of select="acronym"/><xsl:value-of select="f:repeat-string(' ', 24 - string-length(acronym))"/>@ Add OPC to end of arguments
                </xsl:when>
                <xsl:otherwise>
                    sub             sp, sp, #4                      @ reserve space on the stack for the OPC parameter
                                                                    @ NOTE: this word aligns the stack, only private/leaf functions can be called
                    mov             r12, r0                         @ save off r0 into interframe scratch register
                    movs            r0, OPC_<xsl:value-of select="acronym"/><xsl:value-of select="f:repeat-string(' ', 24 - string-length(acronym))"/>@ Add OPC to end of arguments
                    str             r0, [sp]                        @ put OPC onto the top of the stack
                    mov             r0, r12                         @ restore r0
                </xsl:otherwise>
        </xsl:choose>    b               CBUS_sendMessage<xsl:value-of select="f:cbus-message-size(opcode)"/>               @ call method to send message<xsl:if test="compare($suffix, 'Ex')=0">

    public_override(CBUS_send<xsl:value-of select="acronym"/>) 
    
@ void CBUS_send<xsl:value-of select="acronym"/>(<xsl:for-each select="*[starts-with(name(), 'data')][paramByte != 'LO']">
                <xsl:sort select="name()" order="ascending" data-type="text"/><xsl:choose>
                <xsl:when test="paramType = 'other'">byte <xsl:value-of select="bytecont"/></xsl:when><xsl:otherwise>short <xsl:value-of select="paramType"/></xsl:otherwise>
                </xsl:choose><xsl:if test="position() != last()">, </xsl:if></xsl:for-each>)
@   Sends a <xsl:value-of select="description"/> (<xsl:value-of select="acronym"/>) message, blocking until the message is on a transmission queue.
<xsl:value-of select="f:comment-text(documentation)"/><xsl:if test="string-length(annotation) &gt; 0">
<xsl:value-of select="f:comment-text(annotation)"/></xsl:if><xsl:for-each select="*[starts-with(name(), 'data')][paramByte != 'LO']">
                <xsl:sort select="name()" order="ascending" data-type="text"/><xsl:variable name="argName" select="if(paramType = 'other') then bytecont else paramType"/>
@       <xsl:value-of select="$argName"/><xsl:value-of select="f:repeat-string(' ', 20 - string-length($argName))"/><xsl:value-of select="bytedesc"/>        
            </xsl:for-each>

            <xsl:variable name="argCount" select="count(*[starts-with(name(), 'data')][paramByte != 'LO'])"/>
            <xsl:variable name="callPattern"><xsl:for-each select="*[starts-with(name(), 'data')][paramByte != 'LO']"><xsl:value-of select="if(paramType='other') then 'B' else 'S'"/></xsl:for-each></xsl:variable>
            
CBUS_send<xsl:value-of select="acronym"/>:<xsl:choose>
                <xsl:when test="$argCount &lt; 4">
                    movs            r<xsl:value-of select="$argCount"/>, OPC_<xsl:value-of select="acronym"/><xsl:value-of select="f:repeat-string(' ', 24 - string-length(acronym))"/>@ Add OPC to end of arguments
                </xsl:when>
                <xsl:otherwise>
                    sub             sp, sp, #4                      @ reserve space on the stack for the OPC parameter
                                                                    @ NOTE: this word aligns the stack, only private/leaf functions can be called
                    mov             r12, r0                         @ save off r0 into interframe scratch register
                    movs            r0, OPC_<xsl:value-of select="acronym"/><xsl:value-of select="f:repeat-string(' ', 24 - string-length(acronym))"/>@ Add OPC to end of arguments
                    str             r0, [sp]                        @ put OPC onto the top of the stack
                    mov             r0, r12                         @ restore r0
                </xsl:otherwise>
        </xsl:choose>    b               CBUS_sendMessage_<xsl:value-of select="$callPattern"/><xsl:value-of select="f:repeat-string(' ', 15 - string-length($callPattern))"/>@ call method to send message</xsl:if>
    </xsl:template>

<!-- template name message-opt-params  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template name="message-opt-params" >
        <xsl:param name="arg-format"/>
    private_function(CBUS_sendMessage_<xsl:value-of select="$arg-format"/>)        

CBUS_sendMessage_<xsl:value-of select="$arg-format"/>:
                    push            {r4-r6, lr}
                    sub             sp, sp, #ACB_MSG_SIZE<xsl:value-of select="if (string-length($arg-format) &lt; 4) then ' + 4' else '    '"/>       @ reserve space for the message; keep 8-byte alignment
                    mov             r5, sp 
                    movs            r6, #<xsl:value-of select="f:cbus-message-size-2($arg-format) + 1"/>                          @ message length
                    strb            r6, [r5, #ACB_MSG_INFO_LEN_OFFSET]<xsl:variable name="opc-arg" select="if (string-length($arg-format) &lt; 4) then string-length($arg-format) else 4"/>
        <xsl:if test="string-length($arg-format) &gt; 3">
                    add             r6, sp, #ACB_MSG_SIZE           @ overcomes ldrb offset limitation
                    ldrb            r4, [r6, #16]</xsl:if>
        <xsl:for-each select="for $i in 1 to string-length($arg-format) return $i">
            <xsl:variable name="arg-pos" select="(f:arg-position($arg-format, number(.) - 1) * 8) + 8"/>
            <xsl:variable name="arg-size" select="f:arg-size(substring($arg-format, ., 1)) * 8"/>
            <xsl:variable name="arg-shift" select="if ($arg-pos &lt;= 24) then $arg-pos else $arg-pos - 32"/>
            <xsl:if test="($arg-pos = 32) or ($arg-pos = 24 and $arg-size = 16)">
                <xsl:if test="($arg-pos = 24 and $arg-size = 16)">
                    rev16           r<xsl:value-of select=". - 1"/>, r<xsl:value-of select=". - 1"/>                          @ CBUS messages are big-endian
                    lsls            r<xsl:value-of select=". - 2"/>, r<xsl:value-of select=". - 1"/>, #<xsl:value-of select="$arg-shift"/>
                    orrs            r<xsl:value-of select="$opc-arg"/>, r<xsl:value-of select="$opc-arg"/>, r<xsl:value-of select=". - 2"/></xsl:if>
                    str             r<xsl:value-of select="$opc-arg"/>, [r5, #ACB_MSG_DATA_LOW_OFFSET]
                    movs            r<xsl:value-of select="$opc-arg"/>, #0<xsl:if test="($arg-pos = 24 and $arg-size = 16)">
                    lsrs            r<xsl:value-of select=". - 1"/>, r<xsl:value-of select=". - 1"/>, #8
                    orrs            r<xsl:value-of select="$opc-arg"/>, r<xsl:value-of select="$opc-arg"/>, r<xsl:value-of select=". - 1"/>
                </xsl:if>
            </xsl:if>
                <xsl:if test="not($arg-pos = 24 and $arg-size = 16)"><xsl:variable name="reg" select="if (. &gt; 4) then . - 5 else . - 1"/><xsl:if test=". &gt; 4">
                    ldrb            r<xsl:value-of select="$reg"/>, [r6, #16 + <xsl:value-of select="(.-4) * 4"/>]</xsl:if><xsl:if test="substring($arg-format, ., 1) = 'S'">
                    rev16           r<xsl:value-of select="$reg"/>, r<xsl:value-of select="$reg"/>                          @ CBUS messages are big-endian</xsl:if><xsl:if test="$arg-shift != 0">
                    lsls            r<xsl:value-of select="$reg"/>, r<xsl:value-of select="$reg"/>, #<xsl:value-of select="$arg-shift"/></xsl:if>
                    orrs            r<xsl:value-of select="$opc-arg"/>, r<xsl:value-of select="$opc-arg"/>, r<xsl:value-of select="$reg"/>
            </xsl:if>
        </xsl:for-each>
                    str             r<xsl:value-of select="$opc-arg"/>, [r5, #<xsl:value-of select="if (((1 + f:cbus-message-size-2($arg-format)) * 8) &lt;= 32) then 'ACB_MSG_DATA_LOW_OFFSET' else 'ACB_MSG_DATA_HIGH_OFFSET'"/>]
                    movs            r0, r5
                    bl              Can_sendMessage
                    add             sp, sp, #ACB_MSG_SIZE<xsl:value-of select="if (string-length($arg-format) &lt; 4) then ' + 4' else '    '"/>       @ restore stack<xsl:choose>
        <xsl:when test="string-length($arg-format) &lt; 4"> 
                    pop             {r4-r6, pc}
        </xsl:when><xsl:otherwise>
                    movs            r1, r7                          @ save r7
                    pop             {r4-r7}                         @ need to remove OPC from stack before returning, so pop lr into r7
                    pop             {r0}                            @ pop off OPC (can't do this in the above statement, as the registers
                                                                    @ are popped off in numerical order, and we can only use r0-r3 here...),
                    movs            r0, r7
                    movs            r7, r1                          @ restore r7
                    bx              r0                              @ and return
        </xsl:otherwise></xsl:choose>
                    
    </xsl:template>
    
</xsl:transform>
