#include "usart_printf.h"

/* ע�⣺�˷�ʽ��printf�����ض�����Ҫ��Keil�ﹴѡ Use MicroLIB,�������Ῠ��printf�����ϡ�
 */
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)

/*******************************************************************************
 *                           @2017-12-16
 * Function Name  : Usart1_Printf_Init
 * Description    : printf�ض����ʼ��
 * Input          : baudrate -- ���ڲ�����ֵ
 * Output         : none
 * Return         : none
 *******************************************************************************/
void Usart1_Printf_Init(uint32_t baudrate)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;

  /* Enable GPIO clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOD, ENABLE);

  /* Enable USART1 Clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); // ʹ��USART1ʱ��

  /* USART1 Pins configuration */
  /* Connect pin to Perihp */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1); // TX
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_1); // RX

  /* Configure pins as AF pushpull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  USART_InitStructure.USART_BaudRate = baudrate;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;                     // �ֳ�Ϊ8λ���ݸ�ʽ
  USART_InitStructure.USART_StopBits = USART_StopBits_1;                          // һ��ֹͣλ
  USART_InitStructure.USART_Parity = USART_Parity_No;                             // ����żУ��λ
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // ��Ӳ������������
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;                 // �շ�ģʽ
  USART_Init(USART1, &USART_InitStructure);                                       // ��ʼ������

  USART_Cmd(USART1, ENABLE); // ʹ�ܴ���
}

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART */
  USART_SendData(USART1, (uint8_t)ch);

  /* Loop until transmit data register is empty */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
  {
  }

  return ch;
}
