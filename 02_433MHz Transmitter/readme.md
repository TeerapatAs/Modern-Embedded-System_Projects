# 433Mhz RF Module with Blue pill

**Used Library: RadioHead, LiquidCrystal_I2C**

Code in ArduinoIDE. Blink.ino for transmitter, REceiver.ino for receiver.

<img width="500" height="578" alt="image" src="https://github.com/user-attachments/assets/1b6e3f3b-fea1-4af0-afbb-02ce0b35fcca" />

**Processes:**
1. Connect the joystick to the Blue Pill's ADC pins A0 and A1 for reading the x-axis and the y-axis values.
2. Transmit data from Blue pill's pin A9 to the RF Transmitter.
3. Check if the data transmission in 2. is working by connecting the pin A9 to Arduino UNO's pin A0 for the Arduino serial plotter.
   <img width="500" height="578" alt="image" src="https://github.com/user-attachments/assets/9231ae03-51b8-4b2e-89fd-d09f05eb2eb4" />
5. It seems like we're currently transmitting some data, so connect the receiver parts up.

**Results**
Watch in VDO.

