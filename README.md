Another Control Bus
===================

or Accessory Control Bus - a CBUS like control bus for model railway accessories such as control panels, servos,
signals and the like. More details on CBUS can be found on the <http://www.merg.org.uk/merg_resources/cbus.php> website.
These modules should be compatible with CBUS as described in the Developers Guide version 6a to CBUS 4.0 Specification 
Revision 8c. The modules only support FLiM (The Full Layout implementation Model)

Further documentation can be found <http://the-nw1-group.github.io/acb-modules>.

The Modules
-----------

The modules are based around either STM32F042 ARM Cortex-M0 microcontroller, or various PIC24/dsPIC33 microcontrollers. 
All of the boards have been designed, with only the ACB-16IO requiring the Gerbers to be drawn. 

| Module     | Microcontroller | Description |
| ---------- | --------------- | ------------------------------------------------------------------------------------- |
| ACB-4TC    | STM32F042K6     | For 4 turnouts, operates 4 servos, 4 relays, and 8 inputs for proving                 |
| ACB-8IOMV  | STM32F042F6     | 8 configuration input or outputs, configurable for various voltages and other options |
| ACB-8IO    | STM32F042F6     | 8 configurable open drain inputs or outputs, 5V tolerant                              |
| ACB-16IO   | STM32F042F6     | 16 configurable open drain inputs or outputs, 5V tolerant                             |
| ACB-16LED  | STM32F042F6     | 16 constant current LED outputs                                                       |
| ACB-90LED  | STM32F303CB     | 90 LED driver using Charlie Plexing to drive LEDs                                     |
| ACB-RF     | STM32F042F6     | Wireless link                                                                         |
| ACB-ETH100 | PIC24HJ128GP504 | CAN to Ethernet bridge                                                                |
| ACB-BRIDGE | PIC24EP512GP806 | CAN to CAN bridge                                                                     |
 
Most of the code is written in assembler - yeah I know...  

Building and Debugging
----------------------

You'll need the following tools to build the source code:
* Eclipse CDT - I'm using Eclipse Mars Release (4.5.1) Build id: 20150924-1200
* GNU ARM Eclipse plug-in - I'm using version v2.11.3-201602101653 
* Pre-built GNU toolchain from ARM Cortex-M & Cortex-R processors - I'm using version 5.2-2015-q4-update
* OpenOCD - I'm using the one prebuilt by the GNU ARM Eclipse plug-in team
* GNU build tools (for Windows) - again, I'm using the one prebuilt by the GNU ARM Eclipse plug-in team
* Saxon XSLT and XQuery Processor - I'm using version Saxon-HE 9-6-0-6J

You might need to add the following 2 substitution strings (Windows > Preferences > Run/Debug > String Substitution),
as I think these are workspace, rather than project settings:

| Variable        | Value              | Description            |
| --------------- | ------------------ | ---------------------- |
| saxon_xslt_jar  | saxon9he.jar       | Name of Saxon XSTL Jar |
| saxon_xslt_path | *path to JAR file* | Path to Saxon XSLT Jar |

Note: On Windows systems, in saxon_xslt_path use forward slashes rather than backslashes.

For debugging and for burning the boot loader, you need:
* ST-LINK/V2  in-circuit debugger/programmer for STM8 and STM32 - either a stand-alone version, 
or from a ST-Discovery board
* STM-32 ST-LINK Utility - I'm using version v3.8.0

For programming via the bootloader, you need:
* A CAN to Serial, or CAN to USB convertor, such as MERG's CAN-USB2, 3 or 4. I'm using CAN-USB2. Details can be found
on the  <http://www.merg.org.uk/kits.php> website

I'm using Gitflow, so the most up-to-date version will be on the `develop` branch, rather than on `master`, which
will only be updated periodically. <http://nvie.com/posts/a-successful-git-branching-model/> has a brilliant description
of working with Gitflow.

Hopefully they should build after a clone from GIT, but if I've missed something, please let me know, and I'll try to 
correct it. 
