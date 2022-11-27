# miata-ardugauge

An OLED gauge for the Speeduino ECU. Uses UART (secondary serial) for communication.

_NOTE:_ The gauge shares the same Serial port for communcations with Speeduino ECU and USB connection for programming. Disconnect from the ECU if you wish to upload the Arduino sketch.

**Most of the code (and basically 99% of the Comms code) is based on the original Ardugauge project by MielArrojado!**

## Parts List

1. **Arduino Nano** - should work with most 328P arduino boards
2. **Monochrome OLED display** - 128x64 px, SSD1306 driver, I2C interface
3. **Push button**
4. **Connector** of your choice
5. **Oil temperature sensor** (optional) I had a sensor already installed in my car so I added the code to read from it

## Basic Pinout

| Arduino Pin | Connects To   |
| ----------- | ------------- |
| 5V          | Speeduino 5V  |
| D0-RX       | Speeduino TX3 |
| D1-TX       | Speeduino RX3 |
| GND         | Speeduino GND |
| 5V          | OLED 5V       |
| A0          | OilTemp Sens* |
| A5          | OLED SCL      |
| A4          | OLED SDA      |
| GND         | OLED GND      |
| D2          | Push Button   |
| GND         | Push Button   |

\* The temperature sensor for engine oil must be connected between A0 and ground. A bias resistor must be added between 5V and A0.

## Speeduino Settings

Enable `Secondary Serial` only. [Speeduino Manual](https://wiki.speeduino.com/en/Secondary_Serial_IO_interface)
