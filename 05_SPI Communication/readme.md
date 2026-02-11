Implementation of UART serial communication. STM32F103C8T6 (Blue Pill) as a Master device and Arduino UNO as a slave device. 

Blue Pill's PB13(SPI2 CLK), PB13(MOSI), and GND are connected with the Arduino UNO's A13(CLK), A12(MOSI), and GND in order.

**Goal:** Send String Data "A", "B", "C" in loop, from Blue Pill to Arduino UNO through channel SPI2. After receiving the data, UNO prints out the ASCII Code for the character (ex. if it receives "A", it prints "65").

**STM32 Configuration in STM32CubeIDE:**

<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/c654d78d-e4af-44a1-8e86-d2e8d5316b2f" />

^ 1. Enable SPI2, Sys debug and GPIO(Pin C13)

<img width="500" height="350" alt="image" src="https://github.com/user-attachments/assets/023d13c4-8243-4df7-a444-b75d4669a4f5" />

^ 2. Enable 







