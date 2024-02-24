#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "hk32f030m.h"

/* Define LED GPIO Ports, users only need to modify the relevant definitions to change LED pins */
// Red Color
#define LED1_GPIO_PORT GPIOD			  /* GPIO Port */
#define LED1_GPIO_CLK RCC_AHBPeriph_GPIOD /* GPIO Port Clock */
#define LED1_GPIO_PIN GPIO_Pin_1		  /* GPIO Pin connected to the LED */

// Green Color
#define LED2_GPIO_PORT GPIOC			  /* GPIO Port */
#define LED2_GPIO_CLK RCC_AHBPeriph_GPIOC /* GPIO Port Clock */
#define LED2_GPIO_PIN GPIO_Pin_7		  /* GPIO Pin connected to the LED */

// Blue Color
#define LED3_GPIO_PORT GPIOA			  /* GPIO Port */
#define LED3_GPIO_CLK RCC_AHBPeriph_GPIOA /* GPIO Port Clock */
#define LED3_GPIO_PIN GPIO_Pin_2		  /* GPIO Pin connected to the LED */

/** Macro definition to trigger the LED on or off
 * 1 - off
 * 0 - on
 */
#define ON 0
#define OFF 1

/* Macros to control individual LEDs */
#define LED1(a)                                      \
	if (a)                                           \
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN); \
	else                                             \
		GPIO_ResetBits(LED1_GPIO_PORT, LED1_GPIO_PIN)

#define LED2(a)                                      \
	if (a)                                           \
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN); \
	else                                             \
		GPIO_ResetBits(LED2_GPIO_PORT, LED2_GPIO_PIN)

#define LED3(a)                                      \
	if (a)                                           \
		GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN); \
	else                                             \
		GPIO_ResetBits(LED3_GPIO_PORT, LED3_GPIO_PIN)

/* Direct manipulation of GPIO registers for IO */
#define digitalHi(p, i) \
	{                   \
		p->BSRR = i;    \
	} // Set to high level
#define digitalLo(p, i) \
	{                   \
		p->BRR = i;     \
	} // Set to low level
#define digitalToggle(p, i) \
	{                       \
		p->ODR ^= i;        \
	} // Toggle state

/* LED control macros */
#define LED1_TOGGLE digitalToggle(LED1_GPIO_PORT, LED1_GPIO_PIN)
#define LED1_OFF digitalHi(LED1_GPIO_PORT, LED1_GPIO_PIN)
#define LED1_ON digitalLo(LED1_GPIO_PORT, LED1_GPIO_PIN)

#define LED2_TOGGLE digitalToggle(LED2_GPIO_PORT, LED2_GPIO_PIN)
#define LED2_OFF digitalHi(LED2_GPIO_PORT, LED2_GPIO_PIN)
#define LED2_ON digitalLo(LED2_GPIO_PORT, LED2_GPIO_PIN)

#define LED3_TOGGLE digitalToggle(LED3_GPIO_PORT, LED3_GPIO_PIN)
#define LED3_OFF digitalHi(LED3_GPIO_PORT, LED3_GPIO_PIN)
#define LED3_ON digitalLo(LED3_GPIO_PORT, LED3_GPIO_PIN)

void LED_GPIO_Config(void);

#endif /* __BSP_LED_H */
