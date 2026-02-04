**Purpose: Get 3 inputs of Joysticks (Rx, Ry, SWs) from ADC channels**

<img width="162" height="148" alt="image" src="https://github.com/user-attachments/assets/ca9ec892-f91d-412e-a195-df16f99ce078" />

Start Polling by Config ADC Channel -> Start ADC -> Polling CPU -> Read -> Stop

Snippet:
```
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */

  // Initialize : polling = CPU waits for each steps---------------------------------------------
  // Data is 12 bits -> 16 bits are enough
  uint16_t readValue[2] = {0U, 0U};
  // Initialize Configs ADC Channel
  ADC_ChannelConfTypeDef sysConfig = {0};

  HAL_ResumeTick(); // Ensure the tick timer is running
  __enable_irq();   // Ensure interrupts are globally enabled
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  // Figure out IN0---------------------------------------------
	  sysConfig.Channel = ADC_CHANNEL_0;
	  sysConfig.Rank = ADC_REGULAR_RANK_1;
	  sysConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5; // Set sampling time 1.5 Cycle
	  // Tconv = Tsampling + 12.5 cycles = 14 cycles
	  // Tconv= 14 cycles * (1/ freq_ADC ) sec = 14 * (1 / 4MHz) = 5.25 uS
	  // Blue pill has maximum smallest converse time limits at 1 us, it should be ok I guess.

	  // Config -> start -> poll -> read -> stop---------------------------------------------
	  HAL_ADC_ConfigChannel(&hadc1, &sysConfig);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000); // Poll for 1 second
	  readValue[0] = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);

	  // Figure Out IN1---------------------------------------------
	  sysConfig.Channel = ADC_CHANNEL_1;
	  // sysConfig.Rank = ADC_REGULAR_RANK_1;
	  // sysConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;

	  // Config -> start -> poll -> read -> stop---------------------------------------------
	  HAL_ADC_ConfigChannel(&hadc1, &sysConfig);
	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1,1000); // Poll for 1 second
	  readValue[1] = HAL_ADC_GetValue(&hadc1);
	  HAL_ADC_Stop(&hadc1);

	  HAL_Delay(500);

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
```
