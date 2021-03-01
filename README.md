Another Control Bus 2.0
=======================

or Accessory Control Bus - a CBUS like control bus for model railway accessories such as control panels, servos,
signals and the like. More details on CBUS can be found on the <http://www.merg.org.uk/merg_resources/cbus.php> website.
These modules should be compatible with CBUS as described in the Developers Guide version 6a to CBUS 4.0 Specification 
Revision 8c. The modules only support FLiM (The Full Layout implementation Model)

Further documentation can be found <http://the-nw1-group.github.io/acb-modules>.

The Modules
-----------

The modules are based around either STM32L431 ARM Cortex-M0 microcontroller, or more powerful STM32H7xxx 
microontrollers. 

| Module         | Microcontroller  | Description |
| -------------- | ---------------- | ------------------------------------------------------------------------------------------- |
| ACB-2TC        | STM32L431K       | For 2 turnouts, operates 2 servos, 2 relays, and 4 inputs for proving                       |
| ACB-4DTC       | STM32L431K       | Detection of 4 DCC block occupancy, using current transformers                              |
| ACB-4IR-DETECT | STM32L431K       | Detection of 4 DCC block occupancy, using reflection of IR LEDs                             |
| ACB-4RELAY     | STM32L431K       | 4 channel solid-state relay output module                                                   |
| ACB-4SIG       | STM32L431K       | 4 WS2812 based signal driver, and 4 low(-ish) power LED output                              |
| ACB-4SND       | STM32L431R       | 4 Channel mono-sound output                                                                 |
| ACB-4TC        | STM32L431C       | For 4 turnouts, operates 4 servos, 4 relays, and 8 inputs for proving                       |
| ACB-8IO        | STM32L431K       | Generic 8 input/output module                                                               |
| ACB-16LED      | STM32L431K       | 16 constant current LED outputs                                                             |
| ACB-110LED     | STM32L431C       | 110 LED driver using Charlie Plexing to drive LEDs                                          |
| ACB-ETHERNET   | STM32H723V       | CAN to Ethernet bridge

Most of the code is written in assembler - yeah I know...  

Other Projects
--------------

Whilst developing the modules listed above, a number of side projects have evolved.

| Module        | Microcontroller  | Description |
| ------------- | ---------------- | --------------------------------------------------------------------------------- |
| Signal Tester | STM32F042F6      | For testing serial RGB LEDs and for testing and positioning Servos                |
| QUAD-IR       | STM32F030F4      | Based on the MERG "Hector", use reflected IR to detect trains                     | 
| uTroller      | STM32F042F6      | Simple DC model railway controller                                                |

Building and Debugging
----------------------

You'll need the following tools to build the source code, all version numbers are the versions I'm currently using, not
required versions:

* Visual Studio code - version 1.53.2
  * `ARM Extension` - version 1.5.0
  * `C/C++` - version 1.2.2
  * `Cortex-Debug` - version 0.3.12
* Pre-built GNU toolchain from ARM Cortex-M & Cortex-R processors - version 9-2020-q2
* OpenOCD - I'm using the one prebuilt by the GNU ARM Eclipse plug-in team - version 0.10.0-13
* GNU make (for Windows) <http://gnuwin32.sourceforge.net/packages/make.htm>
* Saxon XSLT and XQuery Processor - version Saxon-HE 10.2
* CMSIS-SVD-master from <https://github.com/posborne/cmsis-svd>

I have the tools installed into the following folders:  
&nbsp;&nbsp;&nbsp;&nbsp;${DEV_ROOT}  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cmsis-svd-master  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GNU MCU Eclipse/OpenOCD  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GNU Tools ARM Embedded/9-2019-q4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;GnuWin32  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;saxon-he  

You'll need to define DEV_ROOT environment variable to point to the top of the installation - with normal windows path,
and you'll also need to DEV_ROOT_ environment variable to point to the same location but in MINGW64 file path format. I've
also added the following on my PATH:

* `${DEV_ROOT}\GnuWin32\bin`
* `${DEV_ROOT}\GNU Tools ARM Embedded\9-2019-q4\arm-none-eabi\bin`
* `${DEV_ROOT}\GNU Tools ARM Embedded\9-2019-q4\bin`

Finally, at last you say, you'll need the following in your user settings (settings.json) within visual studio code:

```json
    {
        "terminal.integrated.env.windows": {
            "SAXON_PATH": "${env:DEV_ROOT_}saxon-he"
        },
        "cortex-debug.openocdPath": "${env:DEV_ROOT}\\GNU MCU Eclipse\\OpenOCD\\0.10.0-13\\bin\\openocd.exe"
    }
```

I've not tried this on OSX or any form of linux

For debugging and for burning the boot loader, you need:

* ST-LINK/V2  in-circuit debugger/programmer for STM8 and STM32 - either a stand-alone version, 
or from a ST-Discovery board
* STM-32 ST-LINK Utility - I'm using version v4.5.0

For programming via the bootloader, you need:

* A CAN to Serial, or CAN to USB convertor, such as MERG's CAN-USB2, 3 or 4. I'm using CAN-USB4. Details can be found
on the  <http://www.merg.org.uk/kits.php> website

I'm using Gitflow, so the most up-to-date version will be on the `develop` branch, rather than on `master`, which
will only be updated periodically. <http://nvie.com/posts/a-successful-git-branching-model/> has a brilliant description
of working with Gitflow.

Hopefully they should build after a clone from GIT, but if I've missed something, please let me know, and I'll try to 
correct it. 
