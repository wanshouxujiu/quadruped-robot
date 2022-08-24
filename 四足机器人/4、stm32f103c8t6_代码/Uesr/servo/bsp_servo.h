#ifndef __BSP_SERVO_H__
#define __BSP_SERVO_H__

#include "stm32f10x.h"
#include "bsp_GeneralTim.h"

//������(˳ʱ��ΪTIM2��1��2��3��4ͨ��)
//��λ
#define             TIME_DIRECTION_RESET_1                 TIM_CCR1_Val_2
#define             TIME_DIRECTION_RESET_2                 TIM_CCR2_Val_2
#define             TIME_DIRECTION_RESET_3                 TIM_CCR3_Val_2
#define             TIME_DIRECTION_RESET_4                 TIM_CCR4_Val_2

//��ǰ
#define             TIME_DIRECTION_ADVANCE_1               (TIM_CCR1_Val_2 + 4)
#define             TIME_DIRECTION_ADVANCE_2               (TIM_CCR2_Val_2 + 4)
#define             TIME_DIRECTION_ADVANCE_3               (TIM_CCR3_Val_2 - 4)
#define             TIME_DIRECTION_ADVANCE_4               (TIM_CCR4_Val_2 - 4)

//���
#define             TIME_DIRECTION_RETREAT_1               (TIM_CCR1_Val_2 - 4)
#define             TIME_DIRECTION_RETREAT_2               (TIM_CCR2_Val_2 - 4)
#define             TIME_DIRECTION_RETREAT_3               (TIM_CCR3_Val_2 + 4)
#define             TIME_DIRECTION_RETREAT_4               (TIM_CCR4_Val_2 + 4)

//�߶ȶ��(˳ʱ��ΪTIM1��1��2��3��4ͨ��)
//��λ
#define             TIME_HEIGHT_RESET_1                    TIM_CCR1_Val_1
#define             TIME_HEIGHT_RESET_2                    TIM_CCR2_Val_1
#define             TIME_HEIGHT_RESET_3                    TIM_CCR3_Val_1
#define             TIME_HEIGHT_RESET_4                    TIM_CCR4_Val_1

//̧��
#define             TIME_HEIGHT_RAISE_1                    (TIM_CCR1_Val_1 + 3)
#define             TIME_HEIGHT_RAISE_2                    (TIM_CCR2_Val_1 + 2)
#define             TIME_HEIGHT_RAISE_3                    (TIM_CCR3_Val_1 - 2)
#define             TIME_HEIGHT_RAISE_4                    (TIM_CCR4_Val_1 - 3)

//̧�ߣ�ſ����̬��
#define             TIME_HEIGHT_FALL_1                    (TIM_CCR1_Val_1 + 4)
#define             TIME_HEIGHT_FALL_2                    (TIM_CCR2_Val_1 + 4)
#define             TIME_HEIGHT_FALL_3                    (TIM_CCR3_Val_1 - 4)
#define             TIME_HEIGHT_FALL_4                    (TIM_CCR4_Val_1 - 4)

//̧�ߣ������е����̬��
#define             TIME_HEIGHT_FALL_Foot_1               (TIM_CCR1_Val_1 + 10)
#define             TIME_HEIGHT_FALL_Foot_2               (TIM_CCR2_Val_1 + 10)
#define             TIME_HEIGHT_FALL_Foot_3               (TIM_CCR3_Val_1 - 10)
#define             TIME_HEIGHT_FALL_Foot_4               (TIM_CCR4_Val_1 - 10)

//ѹ�ͣ�վ����̬��
#define             TIME_HEIGHT_STAND_1                    (TIM_CCR1_Val_1 - 4)
#define             TIME_HEIGHT_STAND_2                    (TIM_CCR2_Val_1 - 4)
#define             TIME_HEIGHT_STAND_3                    (TIM_CCR3_Val_1 + 4)
#define             TIME_HEIGHT_STAND_4                    (TIM_CCR4_Val_1 + 4)

void Servo_Reset(void);
void Servo_Advance(void);
void Servo_RightTurn(void);
void Servo_LeftTurn(void);
void Servo_Retreat(void);
void Servo_Pose_1(void);
void Servo_Stand(void);
void Servo_Fall(void);

#endif
