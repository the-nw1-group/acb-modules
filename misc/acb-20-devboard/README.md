acb-2.0-devboard
================

A small development board to test if it's possible to home solder QFN/DFN devices
that form the backbone of the ACB (Another Control Bus) 2.0 boards. The board has
2 digital inputs, 2 analog inputs, and 2 LED outputs, as well as then ACB 2.0
standard arrangement of 3 status LEDs (Red=Power, Yellow=#1, Green=#2), User button.

Pin functions are

| Pin | Function  | Type             | Description                 |
|:---:| --------- | ---------------- | --------------------------- |
| 1   | VDD       | S   - PWR        | 3.3v power supply           |
| 4   | NRST      | RST - RST        | SWD - RST                   |
| 5   | VDDA      | S   - PWR        | 3.3v power supply           |
| 6   | PA0       | I   - RCC_CLK_IN | Clock In (12mhz Oscillator) |
| 7   | PA1       | I/O - Analog     | ADC1_IN6 - ADC1             |
| 8   | PA2       | I/O - Analog     | ADC1_IN7 - ADC2             |
| 12  | PA6       | I/O - IN         | IN1                         |
| 13  | PA7       | I/O - IN         | IN2                         |
| 16  | VSS       | S   - PWR        | Ground                      |
| 17  | VDD       | S   - PWR        | 3.3v power supply           |
| 18  | PA8       | I/O - OUT        | TIM1_CH1 - OUT1             |
| 19  | PA9       | I/O - OUT        | TIM1_CH2 - OUT2             |
| 21  | PA11      | I/O - IN         | CAN1_RX                     |
| 22  | PA12      | I/O - OUT        | CAN1_TX                     |
| 23  | PA13      | I/O - DBG        | SWD - SWDIO                 |
| 24  | PA14      | I/O - DBG        | SWD - SWCLK                 |
| 25  | PA15      | I/O - OUT        | EEPROM nCS                  |
| 26  | PB3       | I/O - OUT        | SPI3_CLK - EEPROM SPI Clock |
| 27  | PB4       | I/O - IN         | SPI3_MISO - EEPROM MISO     |
| 28  | PB5       | I/O - OUT        | SPI3_MOSI - EEPROM MOSI     |
| 31  | PH3-BOOT0 | I/O - IN         | User Switch                 |
| 32  | VSS       | S   - PWR        | Ground                      |

Others are unused.

Other notable IC's/Devices on the board

| Device       | Description                                                                                   |
| -----------  | --------------------------------------------------------------------------------------------- |
| TPS62160DSG  | Buck Convertor (12V to 5V)                                                                    |
| MIC5538-3.3  | LDO Power Regulator (5V-3.3V)                                                                 |
| M95320-R     | 4K (32x8 bit) EEPROM                                                                          |
| MCP2462FD    | Can Transceiver                                                                               |
