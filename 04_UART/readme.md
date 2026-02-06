Implementation of UART serial communication. STM32F103C8T6 (Blue pill) as a transmitter and Arduino UNO as a receiver. Blue Pill's PA9(TX1) is the TX of the USART1 connection.

**Circuit:**
Connect Blue Pill's PA9(TX1) with the RX pin of the Arduino UNO.

**STM32 CubeIDE Configuration:**
1. Clock Configurations for the appropriate baud rate.
First, I want to send data at a 9600 baud rate to Arduino UNO.
   
<img width="800" height="540" alt="image" src="https://github.com/user-attachments/assets/05a242ef-4dd2-4bf8-bfdb-839ea85d5b24" />

Calculation:
USART1 is connected to the APB2 Bus at 16 MHz Peripheral Clock. By default, USART1 is set to oversampling 16 times. So..

Baud rate = $\frac{APB2 peripheral clock}{Oversampling * USARTDIV}$ => 9600 = $\frac{16*10^6}{16 * USARTDIV}$ => USART_DIV = 104.667

The fraction 0.667*16 = 10 oversampling pulses will be distributed across all sampling pulses. So the baud rate error is 10/(16*104) = 0.6%, this is fine.

2. 

<img width="365" height="271" alt="image" src="https://github.com/user-attachments/assets/34e67bf7-5a5d-494f-88e9-0b501330312a" />
