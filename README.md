Another Control Bus
===================

or Accessory Control Bus - a CBUS like control bus for model railway accessories such as control panels, servos,
signals and the like. More details on CBUS can be found on the <http://www.merg.org.uk/merg_resources/cbus.php> website.
These modules should be compatible with CBUS as described in the Developers Guide version 6a to CBUS 4.0 Specification 
Revision 8c. The modules only support FLiM (The Full Layout implementation Model)

Further documentation can be found <http://the-nw1-group.github.io/acb-modules>.

The Modules
-----------

The modules are based around either STM32F042 ARM Cortex-M0 microcontroller, or more powerful STM32F3xxx, or STM32F7xxx 
microontrollers. 

| Module      | Microcontroller  | Description |
| ----------- | ---------------- | ------------------------------------------------------------------------------------------- |
| ACB-1TC     | STM32F042F6      | For 1 turnout, operates 1 servo, 1 relay, and 2 inputs for proving                          |
| ACB-2TC     | STM32F042G6      | For 2 turnouts, operates 2 servos, 2 relays, and 4 inputs for proving, additional 2 outputs |
| ACB-4TC     | STM32F042K6      | For 4 turnouts, operates 4 servos, 4 relays, and 8 inputs for proving                       |
| ACB-6IOMV   | STM32F042F6      | 6 configuration input or outputs, configurable for various voltages and other options       |
| ACB-8IOMV2  | STM32F042F6      | 8 configuration input or outputs, configurable for various voltages and other options       |
| ACB-16LED   | STM32F042F6      | 16 constant current LED outputs                                                             |
| ACB-90LED   | STM32F303CB      | 90 LED driver using Charlie Plexing to drive LEDs                                           |
| ACB-4SND    | STM32F730RB      | 4 Mono sound output, with 8 inputs                                                          |
| ACB-ETH2    | STM32F767V6      | CAN to CAN and Ethernet bridge                                                              |
| ACB-BLE-CAB | STM32L031K6      | Wireless Bluetooth Low Energy DCC Cab                                                       |

Most of the code is written in assembler - yeah I know...  

Other Projects
--------------

Whilst developing the modules listed above, a number of side projects have evolved.

| Module        | Microcontroller  | Description |
| ------------- | ---------------- | --------------------------------------------------------------------------------- |
| Signal Tester | STM32F042F6      | For testing serial RGB LEDs and for testing and positioning Servos                |
| CBUS Monitor  | STM32F042F6      | Display messages on the CAN bus, decode, graph, and send test messages            |
| QUAD-IR       | STM32F030F4      | Based on the MERG "Hector", use reflected IR to detect trains                     | 
| BCO           | STM32F030F4      | Based on the MERG "DCO", Block cutout for DCC                                     |
| 2RELAY        |                  | 2 Relay board for Finder 32.21-x000 type relays                                   |
| 4RELAY        |                  | 4 Relay board for Finder 34.51-x000 type relays                                   |
| DTC1          |                  | Based on the MERG "DTC8", uses current transform to detect trains, 1 input        |
| DTC2          |                  | Based on the MERG "DTC8", uses current transform to detect trains, 2 input        |
| DTC4          |                  | Based on the MERG "DTC8", uses current transform to detect trains, 4 input        |
| PSU4V5        |                  | Simple DC/DC Buck convertor                                                       |
| 8OUT-PP       |                  | 8 Output 5V push/pull addon for ACB-6IOMV/ACB-8IOMV                               |

Building and Debugging
----------------------

You'll need the following tools to build the source code, all version numbers are the versions I'm currently using, not
required versions:
* Visual Studio code - version 1.28.2
  * `ARM Extension` - version 0.3.0
  * `C/C++` - version 0.20.1
  * `Cortex-Debug` - version 0.1.21 
* Pre-built GNU toolchain from ARM Cortex-M & Cortex-R processors - version 7-2018-q2
* OpenOCD - I'm using the one prebuilt by the GNU ARM Eclipse plug-in team - version 0.10.0-10-20181020-0522
* GNU make (for Windows) <http://gnuwin32.sourceforge.net/packages/make.htm>
* Saxon XSLT and XQuery Processor - version Saxon-HE 9-9-0-1J
* CMSIS-SVD-master from <https://github.com/posborne/cmsis-svd>

I have the tools installed into the following folders:  
&nbsp;&nbsp;&nbsp;&nbsp;${DEV_ROOT}  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cmsis-svd-master  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GNU MCU Eclipse/OpenOCD  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GNU Tools ARM Embedded/7-2018-q2  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GnuWin32  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;saxon-he  

You'll need to define DEV_ROOT environment variable to point to the top of the installation - with normal windows path,
and you'll also need to DEV_ROOT_ environment variable to point to the same location but in MINGW64 file path format. I've
also added the following on my PATH:
* `${DEV_ROOT}\GnuWin32\bin`
* `${DEV_ROOT}\GNU Tools ARM Embedded\7-2018-q2\arm-none-eabi\bin`
* `${DEV_ROOT}\GNU Tools ARM Embedded\7-2018-q2\bin`

Finally, at last you say, you'll need the following in your user settings (settings.json) within visual studio code:
```
    {
        "terminal.integrated.env.windows": {
            "SAXON_PATH": "${env:DEV_ROOT_}saxon-he"
        },
        "cortex-debug.openocdPath": "${env:DEV_ROOT}\\GNU MCU Eclipse\\OpenOCD\\0.10.0-10-20181020-0522\\bin\\openocd.exe"
    }
```
I've not tried this on OSX or any form of linux

For debugging and for burning the boot loader, you need:
* ST-LINK/V2  in-circuit debugger/programmer for STM8 and STM32 - either a stand-alone version, 
or from a ST-Discovery board
* STM-32 ST-LINK Utility - I'm using version v4.3.0

For programming via the bootloader, you need:
* A CAN to Serial, or CAN to USB convertor, such as MERG's CAN-USB2, 3 or 4. I'm using CAN-USB2. Details can be found
on the  <http://www.merg.org.uk/kits.php> website

I'm using Gitflow, so the most up-to-date version will be on the `develop` branch, rather than on `master`, which
will only be updated periodically. <http://nvie.com/posts/a-successful-git-branching-model/> has a brilliant description
of working with Gitflow.

Hopefully they should build after a clone from GIT, but if I've missed something, please let me know, and I'll try to 
correct it. 
