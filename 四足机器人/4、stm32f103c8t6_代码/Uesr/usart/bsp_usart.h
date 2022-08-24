#ifndef __BSP_USART_H__
#define __BSP_USART_H__

#include "stm32f10x.h"
#include <stdio.h>

//串口1 - USATRT1
#define DEBUG_USARTx_1                        USART1
#define DEBUG_USART_CLK_1                     RCC_APB2Periph_USART1
#define DEBUG_USART_APBxClkCmd_1              RCC_APB2PeriphClockCmd
#define DEBUG_USART_BAUDRATE_1                115200

//USART GPIO 引脚定义
#define DEBUG_USART_GPIO_CLK_1                RCC_APB2Periph_GPIOA
#define DEBUG_USART_GPIO_APBxClkCmd_1         RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PIN_1             GPIO_Pin_9
#define DEBUG_USART_TX_GPIO_PORT_1            GPIOA
#define DEBUG_USART_RX_GPIO_PIN_1             GPIO_Pin_10
#define DEBUG_USART_RX_GPIO_PORT_1            GPIOA

#define DEBUG_USART_IRQ_1                     USART1_IRQn           //中断源
#define DEBUG_USART_IRQHandler_1              USART1_IRQHandler     //中断函数名

//串口3 - USATRT3
#define DEBUG_USARTx_2                        USART3
#define DEBUG_USART_CLK_2                     RCC_APB1Periph_USART3
#define DEBUG_USART_APBxClkCmd_2              RCC_APB1PeriphClockCmd
#define DEBUG_USART_BAUDRATE_2                115200

//USART GPIO 引脚定义
#define DEBUG_USART_GPIO_CLK_2                RCC_APB2Periph_GPIOB
#define DEBUG_USART_GPIO_APBxClkCmd_2         RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PIN_2             GPIO_Pin_10
#define DEBUG_USART_TX_GPIO_PORT_2            GPIOB
#define DEBUG_USART_RX_GPIO_PIN_2             GPIO_Pin_11
#define DEBUG_USART_RX_GPIO_PORT_2            GPIOB

#define DEBUG_USART_IRQ_2                     USART3_IRQn
#define DEBUG_USART_IRQHandler_2              USART3_IRQHandler

void USART_Config(void);
void Usart_SendByte(USART_TypeDef* pUSARTx, uint8_t Data);
void Usart_SendHalfWord(USART_TypeDef* pUSARTx, uint16_t Data);
void Usart_SendArray(USART_TypeDef* pUSARTx, uint8_t* Array, uint16_t Num);
void Usart_Sendstring(USART_TypeDef* pUSARTx, uint8_t* str);

#endif
