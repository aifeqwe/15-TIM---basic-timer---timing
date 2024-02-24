/**
 ******************************************************************************
 * @file    main.c
 * @author  Alexander
 * @version V1.0
 * @date    2022-xx-xx
 * @brief   System timing
 ******************************************************************************
 * @attention
 *
 * Platform: HK32F030M Microcontroller
 * Forum: https://bbs.21ic.com/iclist-1010-1.html
 *
 ******************************************************************************
 */
#include "hk32f030m.h"
#include "bsp_led.h"
#include "bsp_TimBase.h"

volatile uint32_t time = 0; // Timing variable in milliseconds

/**
 * @brief  Main function
 * @param  None
 * @retval None
 */

int main(void)
{
  /* Initialize LED GPIO */
  LED_GPIO_Config();

  BASIC_TIM_Init();

  while (1)
  {
    if (time == 1000) /* Reached 1 second */
    {
      time = 0;
      /* Toggle LED1 */
      LED1_TOGGLE;
    }
  }
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(char *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     for example: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */

  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */
