I tried to set pin C13 by using bit manipulations of the register instead of using the generated set_pin code, such as HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1).

**Methods:**
1. By setting bit 13 of GPIOC_ODR to HIGH.
<img width="1007" height="478" alt="image" src="https://github.com/user-attachments/assets/62cf40c1-5e82-4538-b86d-d4fc33e86bfb" />

2. By setting bit 13 from the GPIOC_ODR Memory Address.
<img width="407" height="285" alt="image" src="https://github.com/user-attachments/assets/cc9092c2-7f7f-4721-947c-5385be1b321f" />


