# HC-05 Configuration with Arduino
Follow the steps below in order to set the HC-05 module in AT command mode:

## Step 1
Connect the Arduino (without HC-05 module) to the computer and run empty code.

## Step 2
Disconnect the Arduino from the computer, wire the HC-05 module according the diagram below, then while pressing the 
button on the ZS-040 break-out board, connect the Arduino to the computer again. Now, The red LED on the ZS-040 break-out board must be 
blinking in 0.5Hz (one second on, one second off).

![diagram](diagram/hc05-configuration_bb.jpg)
 
## Step 3
Run the sketch. Open the Arduino serial monitor, set baud rate to `38400` and choose `both NL & CR` for line ending. 
Type `AT`, then press enter. You should see `OK`. Now, you can configure your HC-05 module with AT commands. :tada:

__Note 1.__ I've used `Clion` + `PlatformIO` as IDE. But using the official Arduino IDE would be ok as well.

__Note 2.__ To make the HC-05 module respond to all AT commands, keep the button on the ZS-040 break-out board pressed 
while entering commands.