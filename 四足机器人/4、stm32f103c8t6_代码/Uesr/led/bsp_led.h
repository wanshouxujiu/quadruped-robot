#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f10x.h"

#define LED_GPIO_Green_PIN         GPIO_Pin_0
#define LED_GPIO_Green_PORT        GPIOB
#define LED_GPIO_Green_CLK         RCC_APB2Periph_GPIOB

#define LED_GPIO_Blue_PIN          GPIO_Pin_1
#define LED_GPIO_Blue_PORT         GPIOB
#define LED_GPIO_Blue_CLK          RCC_APB2Periph_GPIOB

#define LED_GPIO_Red_PIN           GPIO_Pin_5
#define LED_GPIO_Red_PORT          GPIOB
#define LED_GPIO_Red_CLK           RCC_APB2Periph_GPIOB

#define open        1
#define close       0

#define LED_GREEN(command)	if (!command)	\
					GPIO_SetBits(LED_GPIO_Green_PORT,LED_GPIO_Green_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_Green_PORT,LED_GPIO_Green_PIN)

#define LED_BLUE(command)	if (!command)	\
					GPIO_SetBits(LED_GPIO_Blue_PORT,LED_GPIO_Blue_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_Blue_PORT,LED_GPIO_Blue_PIN)

#define LED_RED(command)	if (!command)	\
					GPIO_SetBits(LED_GPIO_Red_PORT,LED_GPIO_Red_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_Red_PORT,LED_GPIO_Red_PIN)

/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 //输出低电平
#define digitalToggle(p,i) {p->ODR ^=i;} //输出反转状态


/* 定义控制IO的宏 */
#define LED_GREEN_TOGGLE		  digitalToggle(LED_GPIO_Green_PORT,LED_GPIO_Green_PIN)
#define LED_GREEN_OFF		      digitalHi(LED_GPIO_Green_PORT,LED_GPIO_Green_PIN)
#define LED_GREEN_ON			    digitalLo(LED_GPIO_Green_PORT,LED_GPIO_Green_PIN)

#define LED_BLUE_TOGGLE		    digitalToggle(LED_GPIO_Blue_PORT,LED_GPIO_Blue_PIN)
#define LED_BLUE_OFF		      digitalHi(LED_GPIO_Blue_PORT,LED_GPIO_Blue_PIN)
#define LED_BLUE_ON			      digitalLo(LED_GPIO_Blue_PORT,LED_GPIO_Blue_PIN)

#define LED_RED_TOGGLE		    digitalToggle(LED_GPIO_Red_PORT,LED_GPIO_Red_PIN)
#define LED_RED_OFF		        digitalHi(LED_GPIO_Red_PORT,LED_GPIO_Red_PIN)
#define LED_RED_ON			      digitalLo(LED_GPIO_Red_PORT,LED_GPIO_Red_PIN)

void LED_GPIO_Config(void);

#endif
