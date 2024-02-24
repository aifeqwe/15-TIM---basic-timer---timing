// TIM6 time base initialization

#include "bsp_TiMbase.h"

// NVIC configuration function
static void BASIC_TIM_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  // Set interrupt source
  NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM_IRQ;
  // Set priority level
  NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

/*
 * Note: TIM_TimeBaseInitTypeDef structure has 5 members. Only TIM6's register
 * related members, TIM_Prescaler and TIM_Period, are used for TIM6 time base initialization.
 * Other members are used for advanced timer functionalities.
 *-----------------------------------------------------------------------------
 *typedef struct
 *{
 *    TIM_Prescaler            Prescaler
 *    TIM_CounterMode          Not used for TIMx,x[6]
 *    TIM_Period               Period
 *    TIM_ClockDivision        Not used for TIMx,x[6]
 *    TIM_RepetitionCounter    Used only for TIMx,x[1]
 *}TIM_TimeBaseInitTypeDef;
 *-----------------------------------------------------------------------------
 */

static void BASIC_TIM_Mode_Config(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

  // Enable the clock for the timer, internal clock CK_INT=32M
  BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK, ENABLE);

  // Load the auto-reload register value, add 1 to TIM_Period to avoid zero value and generate an update interrupt
  TIM_TimeBaseStructure.TIM_Period = BASIC_TIM_Period + 1;

  // Set the prescaler value
  TIM_TimeBaseStructure.TIM_Prescaler = BASIC_TIM_Prescaler;

  // Clock division is not used, commented out
  // TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;

  // Counter mode is not used, commented out
  // TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;

  // Repetition counter is not used, commented out
  // TIM_TimeBaseStructure.TIM_RepetitionCounter=0;

  // Initialize the timer
  TIM_TimeBaseInit(BASIC_TIM, &TIM_TimeBaseStructure);

  // Clear the update interrupt flag
  TIM_ClearFlag(BASIC_TIM, TIM_FLAG_Update);

  // Enable the update interrupt
  TIM_ITConfig(BASIC_TIM, TIM_IT_Update, ENABLE);

  // Enable the timer
  TIM_Cmd(BASIC_TIM, ENABLE);
}

void BASIC_TIM_Init(void)
{
  BASIC_TIM_NVIC_Config();
  BASIC_TIM_Mode_Config();
}
/*********************************************END OF FILE**********************/
