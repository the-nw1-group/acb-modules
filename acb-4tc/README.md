ACB-4TC
=======

Another Control Bus module to primarily designed to control 4 turnouts. It connects up to 4 servos for controlling
the switches, 4 relays for switching the power at the crossing, and 8 inputs for detecting the switch positions. It
uses an STM32F042K which is a LQFP32 device and is all fitted onto a board 10cm x 5cm.

Pin functions are

| Pin | Function | Type | Description               |
|:---:| -------- | ---- | ------------------------- | 
| 1   | VDD      | S    | 3.3v power supply         |
| 2   | OSC_IN   | I/O  | 8Mhz Oscillator           |
| 3   | OSC_OUT  | I/O  | 8Mhz Oscillator           |
| 4   | NRST     | RST  | SWD - RST                 |
| 5   | VDDA     | S    | 3.3v power supply         |
| 6   | PA0      | I/O  | (IN) Detect 1a            |
| 7   | PA1      | I/O  | (IN) Detect 1b            |
| 8   | PA2      | I/O  | (IN) Detect 2a            |
| 9   | PA3      | I/O  | (IN) Detect 2b            |
| 10  | PA4      | I/O  | (IN) Detect 3a            |
| 11  | PA5      | I/O  | (IN) Detect 3b            |
| 12  | PA6      | I/O  | (IN) Detect 4a            |
| 13  | PA7      | I/O  | (IN) Detect 4B            |
| 14  | PB0      | I/O  | (OUT) Servo 3             |
| 15  | PB1      | I/O  | (OUT) Servo 4             |
| 16  | VSS      | S    | Ground                    |
| 17  | VDDIO2   | S    | 3.3v power supply         |
| 18  | PA8      | I/O  | (OUT) Relay 1             |
| 19  | PA9      | I/O  | (OUT) Relay 2             |
| 20  | PA10     | I/O  | (OUT) Relay 3             |
| 21  | PA11     | I/O  | (IN) CANRX                |
| 22  | PA12     | I/O  | (OUT) CANTX               |
| 23  | PA13     | I/O  | SWD - SWDIO               |
| 24  | PA14     | I/O  | SWD - SWCLK               |
| 25  | PA15     | I/O  | (OUT) Relay 4             |
| 26  | PB3      | I/O  | (OUT) Servo Power Enable* |
| 27  | PB4      | I/O  | (OUT) Servo 1             |
| 28  | PB5      | I/O  | (OUT) Servo 2             |
| 29  | PB6      | I/O  | I2C SCL - EEPROM          |
| 30  | PB7      | I/O  | I2C SDA - EEPROM          |
| 31  | PB8      | I/O  | (IN) FLiM Switch          |
| 32  | VSS      | S    | Ground                    |

\* This isn't present on revision 1.0 of the boards

Other notable IC's on the board

| Device      | Description                                                                                    |
| ----------- | ---------------------------------------------------------------------------------------------- |
| MCP2562     | High-Speed CAN Transceiver                                                                     |
| 24AA16      | 16K I2C Serial EEPROM                                                                          |
| TPS62160    | 3-17V 1A Step-Down Converter                                                                   |
| SN74LVC2T45 | Dual-Bit Dual-Supply Bus Transceiver With Configurable Voltage Translation and 3-State Outputs |
| PMGD175XN   | 30 V, dual N-channel Trench MOSFET                                                             | 
 
