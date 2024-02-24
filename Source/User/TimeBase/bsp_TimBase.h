#ifndef __BSP_TIMEBASE_H
#define __BSP_TIMEBASE_H

#include "hk32f030m.h"

/******************** Timer Configuration, only TIM6 ***************/
#define BASIC_TIM TIM6
#define BASIC_TIM_APBxClock_FUN RCC_APB1PeriphClockCmd
#define BASIC_TIM_CLK RCC_APB1Periph_TIM6
#define BASIC_TIM_Period (1000 - 1)
#define BASIC_TIM_Prescaler 31
#define BASIC_TIM_IRQ TIM6_IRQn
#define BASIC_TIM_IRQHandler TIM6_IRQHandler

/************************** Function Prototype ********************************/

void BASIC_TIM_Init(void);

#endif /* __BSP_TIMEBASE_H */
