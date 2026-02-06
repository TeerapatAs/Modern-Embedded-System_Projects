Implementation of UART serial communication. STM32F103C8T6 (Blue Pill) as a transmitter and Arduino UNO as a receiver. Blue Pill's PA9(TX1) is the TX of the USART1 connection.

**Goals** Send String Data "Counter: i", where i is the iteration, from Blue Pill to Arduino UNO through USART1 channels.

**Circuit:**
Connect Blue Pill's PA9(TX1) with the RX pin of the Arduino UNO.

**STM32 Configuration in STM32CubeIDE:**
1. Clock Configurations for the appropriate baud rate.
First, I want to send data at a 9600 baud rate to Arduino UNO.
   
<img width="800" height="540" alt="image" src="https://github.com/user-attachments/assets/05a242ef-4dd2-4bf8-bfdb-839ea85d5b24" />

Calculation:
USART1 is connected to the APB2 Bus at 16 MHz Peripheral Clock. By default, USART1 is set to oversampling 16 times. So..

Baud rate = $\frac{APB2 peripheral clock}{Oversampling * USARTDIV}$ => 9600 = $\frac{16*10^6}{16 * USARTDIV}$ => USART_DIV = 104.667

The fraction 0.667*16 = 10 oversampling pulses will be distributed across all bit-stream pulses. So the baud rate error is 10/(16*104) = 0.6%, this is fine.

2. Set USART1 as follows. 

<img width="365" height="271" alt="image" src="https://github.com/user-attachments/assets/34e67bf7-5a5d-494f-88e9-0b501330312a" />

3. Write Code and Debug.
   Looking up **main.c** for code. After compiling and debugging, the results should be as follows.
<img width="446" height="183" alt="image" src="https://github.com/user-attachments/assets/7e336627-7c24-4522-a184-1ba370a193a4" />

**Arduino UNO Configuration in Arduino IDE:**
Looking up **Receiver_Serial.ino** for code. After compiling, the results on the serial monitor should be as follows.
<img width="325" height="283" alt="image" src="https://github.com/user-attachments/assets/d243832b-22ad-498b-82e5-6abc884cb758" />




