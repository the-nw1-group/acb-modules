CBUS Network Analyser
=====================

CBUS network analyser based around the STM32F042F variant. Displays traffic on a CBUS network, along with any errors
reported by the network or the local interface. In additional, limited messages can be injected onto the network, for 
testing the network and devices on the network. Information is displayed on the OLED display, and control is provided
by the clickable rotary encoder.

Pin functions are

| Pin | Function | Type | Description                |
|:---:| -------- | ---- | -------------------------- | 
| 1   | PB8      | O    | LED 1 Output (Timer 16)    |
| 2   | PF0      | I/O  | 8Mhz Crystal               |
| 3   | PF1      | I/O  | 8Mhz Crystal               |
| 4   | NRST     | RST  | SWD - RST                  |
| 5   | VDDA     | S    | 3V power supply            |
| 6   | PA0      | I    | Rotary Encoder B Input     |
| 7   | PA1      | I    | Rotary Encoder A Input     |
| 8   | PA2      | I    | Rotary Encode Switch Input |
| 9   | PA3      | O    | Display Data/#Command      |
| 10  | PA4      | O    | LED 2 Output (Timer 14)    |
| 11  | PA5      | O    | SPI Clock                  |
| 12  | PA6      | O    | Display #Reset             |
| 13  | PA7      | O    | SPI MOSI                   |
| 14  | PB1      | I/O  | Display #CS                |
| 15  | VSS      | S    | Ground                     |
| 16  | VDD      | S    | 3V power supply            |
| 17  | PA11     | I    | CAN RX                     |
| 18  | PA12     | O    | CAN TX                     |
| 19  | PA13     | I/O  | SWD - SWDIO                |
| 20  | PA14     | I/O  | SWD - SWCLK                |

Other notable IC's/Devices on the board

| Device       | Description                         |
| -----------  | ----------------------------------- |
| MCP2562      | High Speed CAN Transceiver          |
| ER-OLED013-1 | OLED 1.3" Display                   |
