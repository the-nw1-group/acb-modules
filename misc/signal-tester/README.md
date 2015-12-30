Signal/Servo - Tester
=====================

Signal and Servo tester based around the STM32F042F variant. Tests WS2182B based signals allowing the user to
set the red, green and blue levels. These can be stored within the EEPROM for reading back later. Similar with
servos, the start and end stop and speed can be set and tested, and the values stored within the EEPROM.

Pin functions are

| Pin | Function | Type | Description               |
|:---:| -------- | ---- | ------------------------- | 
| 1   | BOOT0    | I/P  | Tied to ground            |
| 2   | PF0      | I/O  | I2C SDA                   |
| 3   | PF1      | I/O  | I2C SCL                   |
| 4   | NRST     | RST  | SWD - RST                 |
| 5   | VDDA     | S    | 3.3v power supply         |
| 6   | PA0      | I/O  | (Analog) Red Input        |
| 7   | PA1      | I/O  | (Analog) Green Input      |
| 8   | PA2      | I/O  | (Analog) Blue Input       |
| 9   | PA3      | I/O  | Not Used                  |
| 10  | PA4      | I/O  | (OUT) Display #RESET      |
| 11  | PA5      | I/O  | Not Used                  |
| 12  | PA6      | I/O  | Not Used                  |
| 13  | PA7      | I/O  | (IN) Button Back          |
| 14  | PB1      | I/O  | (OUT) Signa/Servo Output  |
| 15  | VSS      | S    | Ground                    |
| 16  | VDD      | S    | 3.3v power supply         |
| 17  | PA9      | I/O  | (IN) Button Action        |
| 18  | PA10     | I/O  | (IN) Button Forward       |
| 19  | PA13     | I/O  | SWD - SWDIO               |
| 20  | PA14     | I/O  | SWD - SWCLK               |

Other notable IC's/Devices on the board

| Device       | Description                                                                                   |
| -----------  | --------------------------------------------------------------------------------------------- |
| 24AA16       | 16K I2C Serial EEPROM                                                                         |
| ER-OLED010-1 | OLED 1" Display                                                                               |
