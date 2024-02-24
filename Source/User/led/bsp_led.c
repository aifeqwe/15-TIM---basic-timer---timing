/**
 ******************************************************************************
 * @file    bsp_led.c
 * @author  Alexander
 * @version V1.0
 * @date    2022-xx-xx
 * @brief   LED Application Interface
 ******************************************************************************
 * @attention
 *
 * Platform: HK32F030M Development Board
 * Forum: https://bbs.21ic.com/iclist-1010-1.html
 *
 ******************************************************************************
 */

#include "bsp_led.h"

/**
 * @brief  Initialize LED GPIO
 * @param  None
 * @retval None
 */
void LED_GPIO_Config(void)
{
	/* Initialize GPIO_InitTypeDef structure */
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable LED GPIO clock */
	RCC_AHBPeriphClockCmd(LED1_GPIO_CLK | LED2_GPIO_CLK | LED3_GPIO_CLK, ENABLE);
	/* Select GPIO pins to initialize LED */
	GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;

	/* Configure GPIO mode as output */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

	/* Configure GPIO speed as 10MHz */
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;

	/* Initialize GPIO for LED1 */
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);

	/* Select GPIO pins to initialize LED2 */
	GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;

	/* Initialize GPIO for LED2 */
	GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);

	/* Select GPIO pins to initialize LED3 */
	GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;

	/* Initialize GPIO for LED3 */
	GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);

	/* Turn off LED1 */
	GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);

	/* Turn off LED2 */
	GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);

	/* Turn off LED3 */
	GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}

/*********************************************END OF FILE**********************/
