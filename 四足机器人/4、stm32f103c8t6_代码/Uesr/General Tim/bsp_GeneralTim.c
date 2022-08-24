#include "bsp_GeneralTim.h" 

static void EXTI_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InItStruct;
	
	//分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	NVIC_InItStruct.NVIC_IRQChannel = GENERAL_TIM_IRQ_3;     //中断源，通道并不是一一对应，只有一部分一一对应
	NVIC_InItStruct.NVIC_IRQChannelPreemptionPriority = 0;   //抢占优先级
	NVIC_InItStruct.NVIC_IRQChannelSubPriority = 8;          //子优先级
	NVIC_InItStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InItStruct);
}

static void GENERAL_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
	//TIM1
  // 输出比较通道1 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK_1, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM_CH1_PORT_1, &GPIO_InitStructure);
	
	// 输出比较通道2 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK_1, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN_1;
  GPIO_Init(GENERAL_TIM_CH2_PORT_1, &GPIO_InitStructure);
	
	// 输出比较通道3 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK_1, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN_1;
  GPIO_Init(GENERAL_TIM_CH3_PORT_1, &GPIO_InitStructure);
	
	// 输出比较通道4 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH4_GPIO_CLK_1, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN_1;
  GPIO_Init(GENERAL_TIM_CH4_PORT_1, &GPIO_InitStructure);
	
	//TIM1
	// 输出比较通道1 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH1_GPIO_CLK_2, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH1_PIN_2;
  GPIO_Init(GENERAL_TIM_CH1_PORT_2, &GPIO_InitStructure);
	
	// 输出比较通道2 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH2_GPIO_CLK_2, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH2_PIN_2;
  GPIO_Init(GENERAL_TIM_CH2_PORT_2, &GPIO_InitStructure);
	
	// 输出比较通道3 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH3_GPIO_CLK_2, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH3_PIN_2;
  GPIO_Init(GENERAL_TIM_CH3_PORT_2, &GPIO_InitStructure);
	
	// 输出比较通道4 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM_CH4_GPIO_CLK_2, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM_CH4_PIN_2;
  GPIO_Init(GENERAL_TIM_CH4_PORT_2, &GPIO_InitStructure);
}


///*
// * 注意：TIM_TimeBaseInitTypeDef结构体里面有5个成员，TIM6和TIM7的寄存器里面只有
// * TIM_Prescaler和TIM_Period，所以使用TIM6和TIM7的时候只需初始化这两个成员即可，
// * 另外三个成员是通用定时器和高级定时器才有.
// *-----------------------------------------------------------------------------
// *typedef struct
// *{ TIM_Prescaler            都有
// *	TIM_CounterMode			     TIMx,x[6,7]没有，其他都有
// *  TIM_Period               都有
// *  TIM_ClockDivision        TIMx,x[6,7]没有，其他都有
// *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]才有
// *}TIM_TimeBaseInitTypeDef; 
// *-----------------------------------------------------------------------------
// */

/* ----------------   PWM信号 周期和占空比的计算--------------- */
// ARR ：自动重装载寄存器的值
// CLK_cnt：计数器的时钟，等于 Fck_int / (psc+1) = 72M/(psc+1)
// PWM 信号的周期 T = ARR * (1/CLK_cnt) = ARR*(PSC+1) / 72M
// 占空比P=CCR/(ARR+1)

static void GENERAL_TIM_Mode_Config(void)
{
  // 开启定时器时钟,即内部时钟CK_INT=72M
	GENERAL_TIM_APBxClock_FUN_1(GENERAL_TIM_CLK_1,ENABLE);
	GENERAL_TIM_APBxClock_FUN_2(GENERAL_TIM_CLK_2,ENABLE);
	GENERAL_TIM_APBxClock_FUN_3(GENERAL_TIM_CLK_3,ENABLE);

/*--------------------时基结构体初始化-------------------------*/
	//TIM1
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period_1;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler_1;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(GENERAL_TIM_1, &TIM_TimeBaseStructure);
	
	//TIM2
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period_2;	
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler_2;
	TIM_TimeBaseInit(GENERAL_TIM_2, &TIM_TimeBaseStructure);
	
	//TIM3
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period_3;	
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler_3;
	TIM_TimeBaseInit(GENERAL_TIM_3, &TIM_TimeBaseStructure);

	/*--------------------输出比较结构体初始化-------------------*/	
		
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	//TIM1
	// 输出比较通道 1
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR1_Val_1;
	TIM_OC1Init(GENERAL_TIM_1, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM_1, TIM_OCPreload_Enable);
	
	// 输出比较通道 2
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR2_Val_1;
	TIM_OC2Init(GENERAL_TIM_1, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM_1, TIM_OCPreload_Enable);
	
	// 输出比较通道 3
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR3_Val_1;
	TIM_OC3Init(GENERAL_TIM_1, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM_1, TIM_OCPreload_Enable);
	
	// 输出比较通道 4
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR4_Val_1;
	TIM_OC4Init(GENERAL_TIM_1, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM_1, TIM_OCPreload_Enable);
	
	//TIM2
	// 输出比较通道 1
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR1_Val_2;
	TIM_OC1Init(GENERAL_TIM_2, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM_2, TIM_OCPreload_Enable);
	
	// 输出比较通道 2
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR2_Val_2;
	TIM_OC2Init(GENERAL_TIM_2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(GENERAL_TIM_2, TIM_OCPreload_Enable);
	
	// 输出比较通道 3
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR3_Val_2;
	TIM_OC3Init(GENERAL_TIM_2, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM_2, TIM_OCPreload_Enable);
	
	// 输出比较通道 4
	TIM_OCInitStructure.TIM_Pulse = TIM_CCR4_Val_2;
	TIM_OC4Init(GENERAL_TIM_2, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM_2, TIM_OCPreload_Enable);
	
	//清除中断标志位
	TIM_ClearFlag(GENERAL_TIM_3, TIM_FLAG_Update);
	
	//开启计数器中断
	TIM_ITConfig(GENERAL_TIM_3, TIM_IT_Update, ENABLE);
	
	// 使能计数器
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
