uTroller
========

A small (3S) LiPo battery powered PWM model railway controller. Control is via a centre detent potentiometer which is 
read and averaged by the STM32F042 ADC, which is then used to derive the direction and PWM on-time. The frequency can be
adjusted using config #0 jumper: jumper out low frequency PWM; jumper in high frequency PWM. Config #1 controls the
current limit: jumper out 2A current limit; jumper in 1A current limit. 

Output voltage to the rails is limited to a maximum of 9v.

The board also includes pass through for charging of the battery, without having to remove the front or rear panels of
the box, and a low battery indicator. It is recommended to use LiPo batteries with inbuilt charging and under-voltage 
cut off protection (such as Turnigy 2.2AH 9XR 11.1V transmitter pack)

Power On LED and Track On LED also indicate various error conditions:

| LED   | Status     | Description                                                           |
|:-----:| ---------- | --------------------------------------------------------------------- |
| Power | Off        | Device turned off                                                     |
| Power | On         | Device turned on and functioning normally                             |
| Power | Fast Flash | Unhandled error encountered                                           |
| Power | Slow Flash | Device started with potentiometer in a position other than center/off | 
| Track | Off        | No track output: device off, or potentiometer in center/off position  |
| Track | On         | Track power applied                                                   |
| Track | Slow Flash | 75% of current limit drawn                                            | 
| Track | Fast Flash | Current limit exceeded, track output turned off                       |

Pin functions are

| Pin | Function | Type | Description                |
|:---:| -------- | ---- | -------------------------- |
| 1   | BOOT0    | I/P  | Tied to ground             |
| 2   | PF0      | I/O  | Not Used                   |
| 3   | PF1      | I/O  | (OUT) nSLEEP (DRV8816)     |
| 4   | NRST     | RST  | SWD - RST                  |
| 5   | VDDA     | S    | 3.3v power supply          |
| 6   | PA0      | I/O  | (OUT) PWM IN1 (DRV8816)    |
| 7   | PA1      | I/O  | (OUT) PWM EN1 (DRV8816)    |
| 8   | PA2      | I/O  | (OUT) PWM IN2 (DRV8816)    |
| 9   | PA3      | I/O  | (OUT) PWM EN1 (DRV8816)    |
| 10  | PA4      | I/O  | (Analog) Vpropi (DRV8816)  |
| 11  | PA5      | I/O  | (Analog) Speed Control     |
| 12  | PA6      | I/O  | Tied to analog  ground     |
| 13  | PA7      | I/O  | (OUT) PWM Power LED        |
| 14  | PB1      | I/O  | (OUT) PWM Track LED        |
| 15  | VSS      | S    | Ground                     |
| 16  | VDD      | S    | 3.3v power supply          |
| 17  | PA9      | I/O  | (IN) Config #1             |
| 18  | PA10     | I/O  | (IN) Config #0             |
| 19  | PA13     | I/O  | SWD - SWDIO                |
| 20  | PA14     | I/O  | SWD - SWCLK                |

Other notable IC's/Devices on the board

| Device       | Description                                                                                   |
| -----------  | --------------------------------------------------------------------------------------------- |
| DRV8816      | DMOS Dual 1/2-H-Bridge Motor Drivers                                                          |

