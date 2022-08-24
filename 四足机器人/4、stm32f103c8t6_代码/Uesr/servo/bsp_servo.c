#include "bsp_servo.h"
#include "bsp_GeneralTim.h"

uint16_t State_1_Time;
uint16_t State_2_Time;
uint16_t State_3_Time;
uint16_t State_4_Time;
uint16_t State_5_Time;
uint16_t State_7_Time;


/**
  * @brief  舵机还原到原来的姿势
  * @param  无
  * @retval 无
  */
void Servo_Reset(void)
{
	TIM_SetCompare1(GENERAL_TIM_1, TIM_CCR1_Val_1);
	TIM_SetCompare2(GENERAL_TIM_1, TIM_CCR2_Val_1);
	TIM_SetCompare3(GENERAL_TIM_1, TIM_CCR3_Val_1);
	TIM_SetCompare4(GENERAL_TIM_1, TIM_CCR4_Val_1);
	TIM_SetCompare1(GENERAL_TIM_2, TIM_CCR1_Val_2);
	TIM_SetCompare2(GENERAL_TIM_2, TIM_CCR2_Val_2);
	TIM_SetCompare3(GENERAL_TIM_2, TIM_CCR3_Val_2);
	TIM_SetCompare4(GENERAL_TIM_2, TIM_CCR4_Val_2);
}


/**
  * @brief  前进状态函数，通过扫描当前计数值进行每一个动作，数字代表多少毫秒
  * @param  无
  * @retval 无
  */
void Servo_Advance(void)
{
	if(State_1_Time >= 1 && State_1_Time < 250)
	{
		TIM_SetCompare1(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_1);
		if(TIM_GetCapture2(GENERAL_TIM_2) == TIME_DIRECTION_ADVANCE_2)
		{
			TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_2);
		}
		TIM_SetCompare3(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_3);
		if(TIM_GetCapture4(GENERAL_TIM_2) == TIME_DIRECTION_ADVANCE_4)
		{
			TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_4);
		}

		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_RAISE_1);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_RAISE_3);
	}
	else if(State_1_Time >= 250 && State_1_Time < 350)
	{
		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_RESET_1);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_RESET_3);
	}
	else if(State_1_Time >= 350 && State_1_Time < 600)
	{
		TIM_SetCompare1(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_1);
		TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_2);
		TIM_SetCompare3(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_3);
		TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_4);

		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_RAISE_2);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_RAISE_4);
	}
	else if(State_1_Time >= 600 && State_1_Time < 700)
	{
		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_RESET_2);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_RESET_4);
	}
	else if(State_1_Time >= 700)
	{
		State_1_Time = 0;
	}
}


/**
  * @brief  右转状态函数，通过扫描当前计数值进行每一个动作，数字代表多少毫秒
  * @param  无
  * @retval 无
  */
void Servo_RightTurn(void)
{
	if(State_2_Time >= 1 && State_2_Time < 250)
	{
		TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_2);
		TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_4);

		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_RAISE_2);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_RAISE_4);
	}
	else if(State_2_Time >= 250 && State_2_Time < 350)
	{
		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_RESET_2);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_RESET_4);
	}
	if(State_2_Time >= 350 && State_2_Time < 600)
	{
		TIM_SetCompare1(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_1);
		TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_2);
		TIM_SetCompare3(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_3);
		TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_4);

		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_RAISE_1);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_RAISE_3);
	}
	else if(State_2_Time >= 600 && State_2_Time < 700)
	{
		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_RESET_1);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_RESET_3);
	}
	if(State_2_Time >= 700 && State_2_Time < 1000)
	{
		TIM_SetCompare1(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_1);
		TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_2);
		TIM_SetCompare3(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_3);
		TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_4);
	}
	else if(State_2_Time >= 1000)
	{
		State_2_Time = 0;
	}
}
	

/**
  * @brief  左转状态函数，通过扫描当前计数值进行每一个动作，数字代表多少毫秒
  * @param  无
  * @retval 无
  */
void Servo_LeftTurn(void)
{
	if(State_3_Time >= 1 && State_3_Time < 250)
	{
		TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_2);
		TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_4);

		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_RAISE_2);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_RAISE_4);
	}
	else if(State_3_Time >= 250 && State_3_Time < 350)
	{
		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_RESET_2);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_RESET_4);
	}
	if(State_3_Time >= 350 && State_3_Time < 600)
	{
		TIM_SetCompare1(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_1);
		TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_2);
		TIM_SetCompare3(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_3);
		TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_4);

		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_RAISE_1);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_RAISE_3);
	}
	else if(State_3_Time >= 600 && State_3_Time < 700)
	{
		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_RESET_1);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_RESET_3);
	}
	if(State_3_Time >= 700 && State_3_Time < 1000)
	{
		TIM_SetCompare1(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_1);
		TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_2);
		TIM_SetCompare3(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_3);
		TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_4);
	}
	else if(State_3_Time >= 1000)
	{
		State_3_Time = 0;
	}
}


/**
  * @brief  后退状态函数，通过扫描当前计数值进行每一个动作，数字代表多少毫秒
  * @param  无
  * @retval 无
  */
void Servo_Retreat(void)
{
	if(State_4_Time >= 1 && State_4_Time < 250)
	{
		TIM_SetCompare1(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_1);
		if(TIM_GetCapture2(GENERAL_TIM_2) == TIME_DIRECTION_RETREAT_2)
		{
			TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_2);
		}
		TIM_SetCompare3(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_3);
		if(TIM_GetCapture4(GENERAL_TIM_2) == TIME_DIRECTION_RETREAT_4)
		{
			TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_4);
		}

		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_RAISE_1);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_RAISE_3);
	}
	else if(State_4_Time >= 250 && State_4_Time < 350)
	{
		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_RESET_1);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_RESET_3);
	}
	else if(State_4_Time >= 350 && State_4_Time < 600)
	{
		TIM_SetCompare1(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_1);
		TIM_SetCompare2(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_2);
		TIM_SetCompare3(GENERAL_TIM_2, TIME_DIRECTION_ADVANCE_3);
		TIM_SetCompare4(GENERAL_TIM_2, TIME_DIRECTION_RETREAT_4);

		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_RAISE_2);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_RAISE_4);
	}
	else if(State_4_Time >= 600 && State_4_Time < 700)
	{
		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_RESET_2);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_RESET_4);
	}
	else if(State_4_Time >= 700)
	{
		State_4_Time = 0;
	}
}


/**
  * @brief  pose1，左右摇摆
  * @param  无
  * @retval 无
  */
void Servo_Pose_1(void)
{
	if(State_5_Time >= 1 && State_5_Time < 250)
	{
		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_FALL_1);
		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_FALL_2);
		if(TIM_GetCapture3(GENERAL_TIM_1) == TIME_HEIGHT_FALL_3)
		{
			TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_STAND_3);
		}
		if(TIM_GetCapture4(GENERAL_TIM_1) == TIME_HEIGHT_FALL_4)
		{
			TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_STAND_4);
		}
	}
	if(State_5_Time >= 250 && State_5_Time < 500)
	{
		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_STAND_1);
		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_STAND_2);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_FALL_3);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_FALL_4);
	}
	else if(State_5_Time >= 500)
	{
		State_5_Time = 0;
	}
}


/**
  * @brief  站立姿态
  * @param  无
  * @retval 无
  */
void Servo_Stand(void)
{
	TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_STAND_1);
	TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_STAND_2);
	TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_STAND_3);
	TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_STAND_4);
	TIM_SetCompare1(GENERAL_TIM_2, TIM_CCR1_Val_2);
	TIM_SetCompare2(GENERAL_TIM_2, TIM_CCR2_Val_2);
	TIM_SetCompare3(GENERAL_TIM_2, TIM_CCR3_Val_2);
	TIM_SetCompare4(GENERAL_TIM_2, TIM_CCR4_Val_2);
}


/**
  * @brief  趴下姿态
  * @param  无
  * @retval 无
  */
void Servo_Fall(void)
{
	if(State_7_Time >= 1 && State_7_Time < 250)
	{
		if(TIM_GetCapture1(GENERAL_TIM_1) != TIME_HEIGHT_FALL_1 ||
			 TIM_GetCapture2(GENERAL_TIM_1) != TIME_HEIGHT_FALL_2 ||
			 TIM_GetCapture3(GENERAL_TIM_1) != TIME_HEIGHT_FALL_3 ||
			 TIM_GetCapture4(GENERAL_TIM_1) != TIME_HEIGHT_FALL_4)
		{
			//趴下，为减轻撞击而不碰到底板
			TIM_SetCompare1(GENERAL_TIM_1, (TIME_HEIGHT_FALL_1 - 3));
			TIM_SetCompare2(GENERAL_TIM_1, (TIME_HEIGHT_FALL_2 - 3));
			TIM_SetCompare3(GENERAL_TIM_1, (TIME_HEIGHT_FALL_3 + 3));
			TIM_SetCompare4(GENERAL_TIM_1, (TIME_HEIGHT_FALL_4 + 3));
			TIM_SetCompare1(GENERAL_TIM_2, TIM_CCR1_Val_2);
			TIM_SetCompare2(GENERAL_TIM_2, TIM_CCR2_Val_2);
			TIM_SetCompare3(GENERAL_TIM_2, TIM_CCR3_Val_2);
			TIM_SetCompare4(GENERAL_TIM_2, TIM_CCR4_Val_2);
		}
	}
	if(State_7_Time >= 250 && State_7_Time < 500)
	{
		if(TIM_GetCapture1(GENERAL_TIM_1) != TIME_HEIGHT_FALL_1 ||
			 TIM_GetCapture2(GENERAL_TIM_1) != TIME_HEIGHT_FALL_2 ||
			 TIM_GetCapture3(GENERAL_TIM_1) != TIME_HEIGHT_FALL_3 ||
			 TIM_GetCapture4(GENERAL_TIM_1) != TIME_HEIGHT_FALL_4)
		{
			//趴下，为减轻撞击而不碰到底板
			TIM_SetCompare1(GENERAL_TIM_1, (TIME_HEIGHT_FALL_1 - 2));
			TIM_SetCompare2(GENERAL_TIM_1, (TIME_HEIGHT_FALL_2 - 2));
			TIM_SetCompare3(GENERAL_TIM_1, (TIME_HEIGHT_FALL_3 + 2));
			TIM_SetCompare4(GENERAL_TIM_1, (TIME_HEIGHT_FALL_4 + 2));
			TIM_SetCompare1(GENERAL_TIM_2, TIM_CCR1_Val_2);
			TIM_SetCompare2(GENERAL_TIM_2, TIM_CCR2_Val_2);
			TIM_SetCompare3(GENERAL_TIM_2, TIM_CCR3_Val_2);
			TIM_SetCompare4(GENERAL_TIM_2, TIM_CCR4_Val_2);
		}
	}
	if(State_7_Time >= 500 && State_7_Time < 750)
	{
		if(TIM_GetCapture1(GENERAL_TIM_1) != TIME_HEIGHT_FALL_1 ||
			 TIM_GetCapture2(GENERAL_TIM_1) != TIME_HEIGHT_FALL_2 ||
			 TIM_GetCapture3(GENERAL_TIM_1) != TIME_HEIGHT_FALL_3 ||
			 TIM_GetCapture4(GENERAL_TIM_1) != TIME_HEIGHT_FALL_4)
		{
			//趴下，为减轻撞击而不碰到底板
			TIM_SetCompare1(GENERAL_TIM_1, (TIME_HEIGHT_FALL_1 - 1));
			TIM_SetCompare2(GENERAL_TIM_1, (TIME_HEIGHT_FALL_2 - 1));
			TIM_SetCompare3(GENERAL_TIM_1, (TIME_HEIGHT_FALL_3 + 1));
			TIM_SetCompare4(GENERAL_TIM_1, (TIME_HEIGHT_FALL_4 + 1));
			TIM_SetCompare1(GENERAL_TIM_2, TIM_CCR1_Val_2);
			TIM_SetCompare2(GENERAL_TIM_2, TIM_CCR2_Val_2);
			TIM_SetCompare3(GENERAL_TIM_2, TIM_CCR3_Val_2);
			TIM_SetCompare4(GENERAL_TIM_2, TIM_CCR4_Val_2);
		}
	}
	if(State_7_Time >= 750 && State_7_Time < 1000)
	{
		//完全趴下
		TIM_SetCompare1(GENERAL_TIM_1, TIME_HEIGHT_FALL_1);
		TIM_SetCompare2(GENERAL_TIM_1, TIME_HEIGHT_FALL_2);
		TIM_SetCompare3(GENERAL_TIM_1, TIME_HEIGHT_FALL_3);
		TIM_SetCompare4(GENERAL_TIM_1, TIME_HEIGHT_FALL_4);
	}
	if(State_7_Time >= 1000)
	{
		State_7_Time = 0;
	}
}
