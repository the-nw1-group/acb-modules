STM32F0x2 CAN Based Bootloader
==============================

A Cortex-M0 CAN based bootloader, that uses less than 3K. It's based on the AN247
application note, now withdrawn, from Microchip. The bootloader has also been
modified to work in a similar manner to the MERG version of the bootloader for PIC18F devices.
The changes are:

* Add a new opcode (4) which queries if the device is in bootloader mode (response is 2),
  or not (no response)
* RESET command clears bootloading mode, and resets the device regardless of whether
  the bootloading process was successful or not

Changes on top of the MERG bootloader are:

* Program data must be supplied in multiples of half-words (16-bits), and there is no requirement
  for 8 bytes to be supplied
* The bootloading process doesn't rely on the address being at the start of a page boundary to
  trigger the auto erase process, un-erased pages are tracked as the bootloading process continues
* The bootloader protects areas below the application start, and after the end of memory, but continues
  to calculate the checksum for any program data supplied for these regions
* The application base is 0x08000C00

Protocol
-------- 

Bootloader is based on extended frames, put commands received from source (Master --> Slave), and the count (DLC) can 
vary. It has the following structure:  


   
| Standard ID     | Length | Extended ID       | D1    | D2    | D3    | D4    | D5    | D6    | D7    | D8    | 
| --------------- | ------ | ----------------- | ----  | ----  | ----  | ----  | ----  | ----  | ----  | ----- |
| XXXXXXXXXXX 0 0 | 8      | XXXXXXXX XXXXXX00 | ADDRL | ADDRH | ADDRU | ADDRT | CTLBT | SPCMD | CPDTL | CPDTH | 
| XXXXXXXXXXX 0 0 | 8      | XXXXXXXX XXXXXX01 | DATA0 | DATA1 | DATA2 | DATA3 | DATA4 | DATA5 | DATA6 | DATA7 |
  
 
Key

| Item  | Description                           |
| ----- | ------------------------------------- |
| ADDRL | Bits 0 to 7 of the memory pointer     |
| ADDRH | Bits 8 - 15 of the memory pointer     |
| ADDRU | Bits 16 - 23 of the memory pointer    |
| ADDRT | Bits 24 - 32 of the memory pointer    |
| CTLBT | Control bits                          |
| SPCMD | Special command                       |
| CPDTL | Bits 0 - 7 of 2s complement checksum  |
| CPDTH | Bits 8 - 15 of 2s complement checksum |
| DATAx | General data |
 

Control bits, bolded items are enabled by default

| Item                 | Bit | Description                                                       |
| -------------------- | --- | ----------------------------------------------------------------- |
| MODE\_WRT_UNLCK      |  0  | Set this to allow write and erase operations to memory            |
| MODE\_ERASE_ONLY     |  1  | Set this to only erase Program Memory on a put command            |
| **MODE\_AUTO_ERASE** |  2  | Set this to automatically erase Program Memory while writing data | 
| **MODE\_AUTO_INC**   |  3  | Set this to automatically increment the pointer after writing     |
| **MODE\_ACK**        |  4  | Set this to generate an acknowledge after a 'put' NOT SUPPORTED   |

Checksum is 16 bit addition of all programmable bytes. User sends 2s complement of addition at end of program in
command `0x03` (16 bits only)
 
Special Commands
 
| Command        | Value | Description                                               |
| -------------- | ----- | --------------------------------------------------------- |
| CMD_NOP        | 0x00  | Do nothing                                                |
| CMD_RESET      | 0x01  | Issue a soft reset                                        |
| CMD\_RST_CHKSM | 0x02  | Reset the checksum counter and verify                     |
| CMD\_CHK_RUN   | 0x03  | Add checksum to special data, if verify and zero checksum |
| CMD\_BOOT_TEST | 0x04  | Just sends a message frame back to verify boot mode       |
 
Responses to CMD\_CHK_RUN and CMD\_BOOT_TEST

| Response | Value | Response To    | Description                                  |
| -------- | ----- | -------------- | -------------------------------------------- |
| nOK      | 0x00  | CMD\_CHK_RUN   | Self Verification or checksum match failure  |
| OK       | 0x01  | CMD\_CHK_RUN   | Self Verficiation and checksum match success |
| BOOTMODE | 0x02  | CMD\_BOOT_TEST | Module is in waiting in boot loader "mode"   |


Only writing to FLASH is supported, specifically writing to configuration/option bytes and EEPROM is not supported.

The user program must start at address `0x08000C00` and the size reduced by 3K, and the RAM region must start from 
`0x200000C0` and the size reduced by 192 bytes
