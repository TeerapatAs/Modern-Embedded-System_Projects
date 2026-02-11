Implementation of UART serial communication. STM32F103C8T6 (Blue Pill) as a Master device and Arduino UNO as a slave device. 

Blue Pill's PB13(SPI2 CLK), PB13(MOSI), and GND are connected with the Arduino UNO's A13(CLK), A12(MOSI), and GND in order.

**Goal:** Send String Data "A", "B", "C" in loop, from Blue Pill to Arduino UNO through channel SPI2. After receiving the data, UNO prints out the ASCII Code for the character (ex. if it receives "A", it prints "65").

**STM32 Configuration in STM32CubeIDE:**

<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/c654d78d-e4af-44a1-8e86-d2e8d5316b2f" />

^ 1. Enable SPI2, Sys debug, and GPIO(Pin C13) (I used Pin C13 for LED blinking to check if some error might not get caught by the Error_handler() function).

<img width="500" height="350" alt="image" src="https://github.com/user-attachments/assets/56af3f0b-4d18-4d57-ae79-5bdb3d67e7ae" />

^2. Set HSI Clock for 8MHz. (We can also use HSE, but my HSE Oscillator seems to cause the sampling lag.)

<img width="500" height="350" alt="image" src="https://github.com/user-attachments/assets/f64709b3-9b4a-4307-b721-ba42a7066142" />

^ 3. Set SPI2 Mode as "Half-Duplex Master", and Clock Prescaler as 64 for the 125kbps baud rate in SPI. (Note that we can also adjust APB1 Peripheral Clock (PCLK) to change SPI2 baud rate,
ex. if APB1 PCLK  = 4MHz, Prescaler = 16--> Baud rate = $4x10^6/16 bps = 64kbps$).







