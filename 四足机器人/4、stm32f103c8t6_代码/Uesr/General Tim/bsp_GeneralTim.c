#include "bsp_GeneralTim.h" 

static void EXTI_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InItStruct;
	
	//����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	NVIC_InItStruct.NVIC_IRQChannel = GENERAL_TIM_IRQ_3;     //�ж�Դ��ͨ��������һһ��Ӧ��ֻ��һ����һһ��Ӧ
	NVIC_InItStruct.NVIC_IRQChannelPreemptionPriority = 0;   //��ռ���ȼ�
	NVIC_InItStruct.NVIC_IRQChannelSubPriority = 8;          //�����ȼ�
	NVIC_InItStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InItStruct);
}

static void GENERAL_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
	//TIM1
  // ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK_1, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH1_PORT_1, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��2 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK_1, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN_1;
  GPIO_Init(GENERAL_TIM_CH2_PORT_1, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��3 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK_1, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN_1;
  GPIO_Init(GENERAL_TIM_CH3_PORT_1, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��4 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH4_GPIO_CLK_1, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN_1;
  GPIO_Init(GENERAL_TIM_CH4_PORT_1, &GPIO_InitStructure);
	
	//TIM1
	// ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK_2, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN_2;
  GPIO_Init(GENERAL_TIM_CH1_PORT_2, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��2 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK_2, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN_2;
  GPIO_Init(GENERAL_TIM_CH2_PORT_2, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��3 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK_2, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN_2;
  GPIO_Init(GENERAL_TIM_CH3_PORT_2, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��4 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH4_GPIO_CLK_2, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN_2;
  GPIO_Init(GENERAL_TIM_CH4_PORT_2, &GPIO_InitStructure);
}


///*
// * ע�⣺TIM_TimeBaseInitTypeDef�ṹ��������5����Ա��TIM6��TIM7�ļĴ�������ֻ��
// * TIM_Prescaler��TIM_Period������ʹ��TIM6��TIM7��ʱ��ֻ���ʼ����������Ա���ɣ�
// * ����������Ա��ͨ�ö�ʱ���͸߼���ʱ������.
// *-----------------------------------------------------------------------------
// *typedef struct
// *{ TIM_Prescaler            ����
// *	TIM_CounterMode			     TIMx,x[6,7]û�У���������
// *  TIM_Period               ����
// *  TIM_ClockDivision        TIMx,x[6,7]û�У���������
// *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]����
// *}TIM_TimeBaseInitTypeDef; 
// *-----------------------------------------------------------------------------
// */

/* ----------------   PWM�ź� ���ں�ռ�ձȵļ���--------------- */
// ARR ���Զ���װ�ؼĴ�����ֵ
// CLK_cnt����������ʱ�ӣ����� Fck_int / (psc+1) = 72M/(psc+1)
// PWM �źŵ����� T = ARR * (1/CLK_cnt) = ARR*(PSC+1) / 72M
// ռ�ձ�P=CCR/(ARR+1)

static void GENERAL_TIM_Mode_Config(void)
{
  // ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	GENERAL_TIM_APBxClock_FUN_1(GENERAL_TIM_CLK_1,ENABLE);
	GENERAL_TIM_APBxClock_FUN_2(GENERAL_TIM_CLK_2,ENABLE);
	GENERAL_TIM_APBxClock_FUN_3(GENERAL_TIM_CLK_3,ENABLE);

/*--------------------ʱ���ṹ���ʼ��-------------------------*/
	//TIM1
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period_1;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler_1;	
	// ʱ�ӷ�Ƶ���� ����������ʱ��ʱ��Ҫ�õ�
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(GENERAL_TIM_1, &TIM_TimeBaseStructure);
	
	//TIM2
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period_2;	
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler_2;
	TIM_TimeBaseInit(GENERAL_TIM_2, &TIM_TimeBaseStructure);
	
	//TIM3
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period_3;	
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler_3;
	TIM_TimeBaseInit(GENERAL_TIM_3, &TIM_TimeBaseStructure);

	/*--------------------����ȽϽṹ���ʼ��-------------------*/	
		
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	//TIM1
	// ����Ƚ�ͨ�� 1
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR1_Val_1;
	TIM_OC1Init(GENERAL_TIM_1, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM_1, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 2
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR2_Val_1;
	TIM_OC2Init(GENERAL_TIM_1, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM_1, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 3
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR3_Val_1;
	TIM_OC3Init(GENERAL_TIM_1, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM_1, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 4
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR4_Val_1;
	TIM_OC4Init(GENERAL_TIM_1, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM_1, TIM_OCPreload_Enable);
	
	//TIM2
	// ����Ƚ�ͨ�� 1
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR1_Val_2;
	TIM_OC1Init(GENERAL_TIM_2, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM_2, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 2
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR2_Val_2;
	TIM_OC2Init(GENERAL_TIM_2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM_2, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 3
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR3_Val_2;
	TIM_OC3Init(GENERAL_TIM_2, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM_2, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 4
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR4_Val_2;
	TIM_OC4Init(GENERAL_TIM_2, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM_2, TIM_OCPreload_Enable);
	
	//����жϱ�־λ
	TIM_ClearFlag(GENERAL_TIM_3, TIM_FLAG_Update);
	
	//�����������ж�
	TIM_ITConfig(GENERAL_TIM_3, TIM_IT_Update, ENABLE);
	
	// ʹ�ܼ�����
	TIM_Cmd(GENERAL_TIM_1, ENABLE);
	TIM_Cmd(GENERAL_TIM_2, ENABLE);
	TIM_Cmd(GENERAL_TIM_3, ENABLE);
}

void GENERAL_TIM_Init(void)
{
	GENERAL_TIM_GPIO_Config();
	GENERAL_TIM_Mode_Config();
	EXTI_NVIC_Config();	
}
