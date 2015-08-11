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

@ void CBUS_defaultMessageHandler(cbusMessage* pcbusMessage)
@   the default message handler - which simply returns. Is a weak reference, so can be overridden.

CBUS_defaultMessageHandler:
                    bx              lr                              @ simply return
    </xsl:template>

<!-- template name handle-cbus-message - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template name="handle-cbus-message">

    public_function(CBUS_handleMessage)

@ void CBUS_handleMessage(cbusMessage* pcbusMessage)
@   processes a cbus message by calling the appropriate message handler. If no handler defined then calls the default
@   message handler. Message handlers are called on&lt;opcode&gt;, for example: onNNULN and on onPARAMS. For those messages
@   where the opcode isn't defined an onRESERVED is called, and are supplied with the opCode and any other parameters.

CBUS_handleMessage:                                                 @ handle a cbus message
@ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO
    </xsl:template>

<!-- template name send-cbus-message - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

    <xsl:template name="send-cbus-message">
        <xsl:apply-templates select="message[compare(acronym,'RESERVED')!=0]" mode="send-message">
            <xsl:sort select="f:hexToDec(opcode)" order="ascending" data-type="number"/>
        </xsl:apply-templates>

@ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO

        @ TODO: supply a default send_RESERVED here
        
    private_function(CBUS_sendMessage0)        

@ void CBUS_sendMessage0(byte OPC)
@   Sends a no-data CBUS message. First parameter is the opcode of the message to send

CBUS_sendMessage0:

    private_function(CBUS_sendMessage1)        

@ void CBUS_sendMessage1(byte data1, byte OPC)
@   Sends a 1 data byte CBUS message. Second parameter is the opcode of the message to send

CBUS_sendMessage1:

    private_function(CBUS_sendMessage2)        

@ void CBUS_sendMessage2(byte data1, byte data2, byte OPC)
@   Sends a 2 data byte CBUS message. Last parameter is the opcode of the message to send

CBUS_sendMessage2:

    private_function(CBUS_sendMessage3)        

@ void CBUS_sendMessage3(byte data1, byte data2, byte data3, byte OPC)
@   Sends a 3 data byte CBUS message. Last parameter is the opcode of the message to send

CBUS_sendMessage3:

    private_function(CBUS_sendMessage4)        

@ void CBUS_sendMessage4(byte data1, byte data2, byte data3, byte data4, byte OPC)
@   Sends a 4 data byte CBUS message. Last parameter is the opcode of the message to send

CBUS_sendMessage4:

    private_function(CBUS_sendMessage5)        

@ void CBUS_sendMessage5(byte data1, byte data2, byte data3, byte data4, byte data5, byte OPC)
@   Sends a 5 data byte CBUS message. Last parameter is the opcode of the message to send

CBUS_sendMessage5:

    private_function(CBUS_sendMessage6)        

@ void CBUS_sendMessage6(byte data1, byte data2, byte data3, byte data4, byte data5, byte data6, byte OPC)
@   Sends a 6 data byte CBUS message. Last parameter is the opcode of the message to send

CBUS_sendMessage6:

    private_function(CBUS_sendMessage7)        

@ void CBUS_sendMessage7(byte data1, byte data2, byte data3, byte data4, byte data5, byte data6, byte data7, byte OPC)
@   Sends a 7 data byte CBUS message. Last parameter is the opcode of the message to send

CBUS_sendMessage7:
        
    private_function(CBUS_sendMessage_S)        

@ void CBUS_sendMessage_XXXXX(variable, byte OPC)
@   Sends a CBUS data message, where the parameters are made up of variable numbers of B bytes and S shorts.
@   Last parameter is the opcode of the message to send (and isn't included in the method name)

CBUS_sendMessage_S:

    private_function(CBUS_sendMessage_SS)

CBUS_sendMessage_SS:

    private_function(CBUS_sendMessage_SSS)

CBUS_sendMessage_SSS:

    private_function(CBUS_sendMessage_SB)        

CBUS_sendMessage_SB:

    private_function(CBUS_sendMessage_SBB)        

CBUS_sendMessage_SBB:

    private_function(CBUS_sendMessage_SBBB)        

CBUS_sendMessage_SBBB:

    private_function(CBUS_sendMessage_SBBBBB)        

CBUS_sendMessage_SBBBBB:

    private_function(CBUS_sendMessage_SSB)

CBUS_sendMessage_SSB:

    private_function(CBUS_sendMessage_SSBB)

CBUS_sendMessage_SSBB:

    private_function(CBUS_sendMessage_SSBBB)

CBUS_sendMessage_SSBBB:

    private_function(CBUS_sendMessage_BSB)        

CBUS_sendMessage_BSB:

    private_function(CBUS_sendMessage_BSBB)        

CBUS_sendMessage_BSBB:

    private_function(CBUS_sendMessage_BSBBBB)        

CBUS_sendMessage_BSBBBB:

@ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO

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
    
    <xsl:variable name="suffix"><xsl:if test="count(*[paramType != 'other']) &gt; 0">_raw</xsl:if></xsl:variable>
        
    public_override(CBUS_send<xsl:value-of select="concat(acronym,$suffix)"/>) 

@ void CBUS_send<xsl:value-of select="concat(acronym,$suffix)"/>(<xsl:for-each select="*[starts-with(name(), 'data')]">
            <xsl:sort select="name()" order="ascending" data-type="text"/>byte <xsl:value-of select="bytecont"/><xsl:if test="position() != last()">, </xsl:if></xsl:for-each>)
@   Sends a <xsl:value-of select="description"/> (<xsl:value-of select="acronym"/>) message, blocking until the message is on a transmission queue.
<xsl:value-of select="f:comment-text(documentation)"/><xsl:if test="string-length(annotation) &gt; 0">
<xsl:value-of select="f:comment-text(annotation)"/></xsl:if><xsl:for-each select="*[starts-with(name(), 'data')]">
        <xsl:sort select="name()" order="ascending" data-type="text"/>
@       <xsl:value-of select="bytecont"/><xsl:value-of select="f:repeat-string(' ', 20 - string-length(bytecont))"/><xsl:value-of select="bytedesc"/>        
    </xsl:for-each>
    <xsl:if test="compare($suffix, '_raw')=0">
    
@    Note: "raw" version of method, supply all arguments as bytes. Use CBUS_send<xsl:value-of select="acronym"/> to supply multi-byte values as single arguments.
    </xsl:if>
CBUS_send<xsl:value-of select="concat(acronym,$suffix)"/>:
OPC_<xsl:value-of select="acronym"/> = <xsl:value-of select="opcode"/>
            <xsl:choose>
                <xsl:when test="f:cbus-message-size(opcode) &lt; 4">
                    movs            r<xsl:value-of select="f:cbus-message-size(opcode)"/>, OPC_<xsl:value-of select="acronym"/><xsl:value-of select="f:repeat-string(' ', 24 - string-length(acronym))"/>@ Add OPC to end of arguments
                </xsl:when>
                <xsl:otherwise>
                    sub             sp, sp, #4                      @ reserve space on the stack for the OPC parameter
                    mov             r12, r0                         @ save off r0 into interframe scratch register
                    movs            r0, OPC_<xsl:value-of select="acronym"/><xsl:value-of select="f:repeat-string(' ', 24 - string-length(acronym))"/>@ Add OPC to end of arguments
                    str             r0, [sp]                        @ put OPC onto the top of the stack
                    mov             r0, r12                         @ restore r0
                </xsl:otherwise>
        </xsl:choose>    b               CBUS_sendMessage<xsl:value-of select="f:cbus-message-size(opcode)"/>               @ call method to send message<xsl:if test="compare($suffix, '_raw')=0">

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
                    mov             r12, r0                         @ save off r0 into interframe scratch register
                    movs            r0, OPC_<xsl:value-of select="acronym"/><xsl:value-of select="f:repeat-string(' ', 24 - string-length(acronym))"/>@ Add OPC to end of arguments
                    str             r0, [sp]                        @ put OPC onto the top of the stack
                    mov             r0, r12                         @ restore r0
                </xsl:otherwise>
        </xsl:choose>    b               CBUS_sendMessage_<xsl:value-of select="$callPattern"/><xsl:value-of select="f:repeat-string(' ', 15 - string-length($callPattern))"/>@ call method to send message</xsl:if>
    </xsl:template>
    
</xsl:transform>
