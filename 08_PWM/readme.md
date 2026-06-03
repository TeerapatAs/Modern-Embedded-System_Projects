# PWM from pin A0

## Files
1. main.c: Our main code.
2. DSMPS.ioc: STM32 Configuration. Can be used with all .c code in this folder.
3. extra_HAL.c: Extra experiment ;). Code that makes the pulse wider over time using HAL
4. extra_LL.c: Extra experiment ;). Code that makes the pulse wider over time using Low-Level in main()

## Goal
To set the pin A0 to be a PWM with a 10% duty cycle. The PWM frequency can be set to whatever one desires.

## Steps
1. **STM32 Configuration in STM32CubeIDE** : Set STM32 as hightlighted in the picture by yellow marker.
<img width="1576" height="827" alt="image" src="https://github.com/user-attachments/assets/7e6a386a-d8aa-4677-bea1-f50465cfcb5d" />


**Why we configure TIM2?**
<img width="976" height="379" alt="image" src="https://github.com/user-attachments/assets/2bec28b7-f089-4fbc-8a4a-a2e99b530723" />

The picture above from the Reference manual in Chapter 15 shows that the Timer peripheral in Blue-pill has 4 channels, CH1 to CH4. As stated in the chapter, each of them is independently doing a task it is assigned to, such as Input Capture, Output Compare, or PWM.

Then we look into the pins related to the TIM2. 

<img width="855" height="267" alt="image" src="https://github.com/user-attachments/assets/378349ae-03cd-4c24-8c86-15fb5fb2d61b" />

The picture above from the Reference manual in Chapter 9.3.7 shows that by default ("no remap column"), the pin A0 can be assigned as an output that delivers the TIM2_CH1 signal to the outside world.

2. **Code**
   To generate PWM, just start TIM2 by using this line of code in main() function.
```c
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
```
3. **Result**
   Using UNO to capture the signal.
<img width="712" height="448" alt="image" src="https://github.com/user-attachments/assets/048c3354-c145-458a-9be6-7bc0c8114e22" />

## Extras
In the file names **extra_HAL.c** and **extra_LL.c**. I wrote code that makes the pulse wider over time using HAL functions and Low-Level(LL).

**Result.**
<img width="971" height="441" alt="image" src="https://github.com/user-attachments/assets/5f863fd5-9963-4952-9b4e-e436935695aa" />

