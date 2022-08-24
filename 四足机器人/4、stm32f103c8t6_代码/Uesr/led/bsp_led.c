//bsp:board support package    板级支持包
#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//开启GPIO时钟
	RCC_APB2PeriphClockCmd(LED_GPIO_Green_CLK | LED_GPIO_Blue_CLK | LED_GPIO_Red_CLK, ENABLE);
	
	//分别初始化
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_Green_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO_Green_PORT,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_Blue_PIN;
	GPIO_Init(LED_GPIO_Blue_PORT,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LED_GPIO_Red_PIN;
	GPIO_Init(LED_GPIO_Red_PORT,&GPIO_InitStruct);
	
	//关闭LED
	GPIO_SetBits(LED_GPIO_Green_PORT, LED_GPIO_Green_PIN);
	GPIO_SetBits(LED_GPIO_Blue_PORT, LED_GPIO_Blue_PIN);
	GPIO_SetBits(LED_GPIO_Red_PORT, LED_GPIO_Red_PIN);
}
