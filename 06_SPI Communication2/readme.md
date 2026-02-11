**Goal:** Send String Data "A", "B", "C" in loop, from UNO to Blue Pill through channel SPI1. After receiving the data, Blue Pill sends the ASCII Code for the character back to UNO.(ex, if it receives "A", it sends "65").

**STM32 Configuration in STM32CubeIDE:**
Please see the configuration at "05_SPI Communication".

<img width="957" height="436" alt="image" src="https://github.com/user-attachments/assets/e363c3ba-7b9a-4b29-a26c-2b937ab0d9c0" />

^ Note that this **main.c** code uses the SPI1 interrupter (To not be confused, the picture is SPI2), please enable the global interrupter and set the preemption priority bit to 0(First Priority).
