#include "systick_delay.h"
#include "hk32f030m.h"

static uint8_t fac_us = 0;
static uint16_t fac_ms = 0;

/*******************************************************************************
 *                           @2017-12-16
 * Function Name  : delay_init
 * Description    : Initializes the delay function
 * Input          : none
 * Output         : none
 * Return         : none
 *                  SYSTICK clock source is set to HCLK divided by 8
 *                  SYSCLK: System Clock
 *******************************************************************************/
void delay_init(void)
{
  SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
  fac_us = SystemCoreClock / 8000000;
  fac_ms = (uint16_t)fac_us * 1000;
}

/*******************************************************************************
 *                           @2017-12-16
 * Function Name  : delay_us
 * Description    : Delays in microseconds
 * Input          : nus - time delay value in microseconds
 * Output         : none
 * Return         : none
 *******************************************************************************/
void delay_us(uint32_t nus)
{
  if (nus > 0)
  {
    uint32_t temp;
    SysTick->LOAD = nus * fac_us;             // Set delay time
    SysTick->VAL = 0x00;                      // Clear current value
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; // Start counting
    do
    {
      temp = SysTick->CTRL;
    } while (temp & 0x01 && !(temp & (1 << 16))); // Wait until time elapsed
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;    // Stop counting
    SysTick->VAL = 0X00;                          // Clear current value
  }
}

/*******************************************************************************
 *                           @2017-12-16
 * Function Name  : delay_ms
 * Description    : Delays in milliseconds
 * Input          : nms - time delay value in milliseconds
 * Output         : none
 * Return         : none
 *******************************************************************************/
void delay_ms(uint16_t nms)
{
  uint32_t temp;

  if (nms > 0)
  {
    SysTick->LOAD = (uint32_t)nms * fac_ms;   // Set delay time (SysTick->LOAD is 24-bit)
    SysTick->VAL = 0x00;                      // Clear current value
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; // Start counting
    do
    {
      temp = SysTick->CTRL;
    } while (temp & 0x01 && !(temp & (1 << 16))); // Wait until time elapsed
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;    // Stop counting
    SysTick->VAL = 0X00;                          // Clear current value
  }
}
