/*
 * MIT License
 *
 * Copyright (c) 2019 Melika Barzegaran <melika.barzegaran.hosseini@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/*
 * title:
 *      HC-05 configuration with Arduino
 *
 * description:
 *      Follow the steps below in order to set the HC-05 module in AT command mode:
 *
 *      Step 1. Disconnect the Arduino from the computer, un-wire the HC-05 module, connect the Arduino to the computer
 *      again, then upload an empty code to the Arduino.
 *
 *      Step 2. Disconnect the Arduino from the computer, wire the HC-05 module, then while pressing the button on the
 *      ZS-040 break-out board, connect the Arduino to the computer again. Now, The red LED on the ZS-040 break-out
 *      board must be blinking in 0.5Hz (one second on, one second off).
 *
 *      Step 3. Upload this code to the Arduino, open the Arduino serial monitor, set baud rate to 38400 and choose
 *      `both NL & CR` for line ending. Type `AT`, then press enter. You should see `OK`. Now, you can configure your
 *      HC-05 module with AT commands.
 *
 * configuration:
 *      +-----------------------+----------------------------+
 *      | Arduino Uno board pin | ZS-040 break-out board pin |
 *      +-----------------------+----------------------------+
 *      |          VCC          |             VCC            |
 *      +-----------------------+----------------------------+
 *      |          GND          |             GND            |
 *      +-----------------------+----------------------------+
 *      |           D2          |             TX             |
 *      +-----------------------+----------------------------+
 *      |           D3          |             RX             | <- Notice: this connection is made via a voltage divider.
 *      +-----------------------+----------------------------+
 *
 * author:
 *      Melika Barzegaran <melika.barzegaran.hosseini@gmail.com>
 *
 * version:
 *      1.0.0
 */

#include "Arduino.h"

/*
 * In order to:
 *
 *      1. program the Arduino,
 *      2. transfer data between the computer and the Arduino,
 *      3. and transfer data between the Arduino and the HC-05 module,
 *
 * and doing them all at the same time, we need to use a software serial library as well as using hardware serial
 * functionality.
 */
#include "SoftwareSerial.h"

/*
 * Software serial receive pin for the Arduino.
 * It should be connected to the hardware serial transfer pin of the HC-05 module, directly.
 */
const int rxPin = 2;

/*
 * Software serial transfer pin for the Arduino.
 * It should be connected to the hardware serial receive pin of the HC-05 module, via a voltage divider.
 */
const int txPin = 3;

/*
 * Software serial object definition.
 * Used to transfer data between the Arduino and the HC-05 module.
 */
SoftwareSerial bluetoothDevice(rxPin, txPin);

void setup() {
    /*
     * Set the hardware serial communication baud rate (between the computer and the Arduino) to 38400.
     */
    Serial.begin(38400);

    /*
     * Set the software serial communication baud rate (between the Arduino and the HC-05 module) to 38400.
     */
    bluetoothDevice.begin(38400);
}

void loop() {
    /*
     * Keep reading from the HC-05 module and send to the Arduino serial monitor.
     */
    if (bluetoothDevice.available()) {
        Serial.write(bluetoothDevice.read());
    }

    /*
     * Keep reading from the Arduino serial monitor and send to the HC-05 module.
     */
    if (Serial.available()) {
        bluetoothDevice.write(static_cast<uint8_t>(Serial.read()));
    }
}