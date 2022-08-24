#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_GeneralTim.h"
#include "bsp_servo.h"

uint8_t state;

//void Delay(uint32_t count)
//{
//	for(; count != 0; count--);
//}

int main()
{
	USART_Config();
	LED_GPIO_Config();
	
	printf("四足机器人初始化中!\r\n");
	
	GENERAL_TIM_Init();

	while(1)
	{
		if(USART_GetFlagStatus(DEBUG_USARTx_2,USART_FLAG_RXNE) != RESET)
		{
			state = USART_ReceiveData(DEBUG_USARTx_2);
			Usart_SendByte(DEBUG_USARTx_1, state);
		}
		
		//机器人的动作通过扫描串口的值进行选择进入
		//蓝牙主机设置为：按下发送01、02、03...，松手发送00
		switch(state)
		{
			case 0:
				//暂停状态
				break;
			case 1:
				//前进
				Servo_Advance();
				break;
			case 2:
				//右转
				Servo_RightTurn();
				break;
			case 3:
				//左转
				Servo_LeftTurn();
				break;
			case 4:
				//后退
				Servo_Retreat();
				break;
			case 5:
				//特殊姿势1，左右摆动
				Servo_Pose_1();
				break;
			case 6:
				//站立
				Servo_Stand();
				break;
			case 7:
				//趴下
				Servo_Fall();
				break;
			case 8:
				//复位姿态
				Servo_Reset();
				break;
			default:
				printf("无任何状态指示！\r\n");
				break;
		}
	}
}
