#ifndef __BSP_GENERALTIM_H__
#define __BSP_GENERALTIM_H__

#include "stm32f10x.h"

/************ͨ�ö�ʱ��TIM�������壬ֻ��TIM2��3��4��5************/
// ��ʹ�ò�ͬ�Ķ�ʱ����ʱ�򣬶�Ӧ��GPIO�ǲ�һ���ģ����Ҫע��

#define            GENERAL_TIM_1                   TIM2
#define            GENERAL_TIM_APBxClock_FUN_1     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK_1               RCC_APB1Periph_TIM2
#define            GENERAL_TIM_Period_1            (200-1)
#define            GENERAL_TIM_Prescaler_1         (7200-1)

#define            GENERAL_TIM_2                   TIM3
#define            GENERAL_TIM_APBxClock_FUN_2     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK_2               RCC_APB1Periph_TIM3
#define            GENERAL_TIM_Period_2            (200-1)
#define            GENERAL_TIM_Prescaler_2         (7200-1)

#define            GENERAL_TIM_3                   TIM4
#define            GENERAL_TIM_APBxClock_FUN_3     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM_CLK_3               RCC_APB1Periph_TIM4
#define            GENERAL_TIM_Period_3            (1000-1)
#define            GENERAL_TIM_Prescaler_3         (72-1)
#define            GENERAL_TIM_IRQ_3               TIM4_IRQn
#define            GENERAL_TIM_IRQHandler_3        TIM4_IRQHandler

// TIM2 ����Ƚ�ͨ��1
#define            GENERAL_TIM_CH1_GPIO_CLK_1       RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH1_PORT_1           GPIOA
#define            GENERAL_TIM_CH1_PIN_1            GPIO_Pin_0

// TIM2 ����Ƚ�ͨ��2
#define            GENERAL_TIM_CH2_GPIO_CLK_1       RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH2_PORT_1           GPIOA
#define            GENERAL_TIM_CH2_PIN_1            GPIO_Pin_1

// TIM2 ����Ƚ�ͨ��3
#define            GENERAL_TIM_CH3_GPIO_CLK_1       RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH3_PORT_1           GPIOA
#define            GENERAL_TIM_CH3_PIN_1            GPIO_Pin_2

// TIM2 ����Ƚ�ͨ��4
#define            GENERAL_TIM_CH4_GPIO_CLK_1       RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH4_PORT_1           GPIOA
#define            GENERAL_TIM_CH4_PIN_1            GPIO_Pin_3


/***************************/

// TIM3 ����Ƚ�ͨ��1
#define            GENERAL_TIM_CH1_GPIO_CLK_2       RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH1_PORT_2           GPIOA
#define            GENERAL_TIM_CH1_PIN_2            GPIO_Pin_6

// TIM3 ����Ƚ�ͨ��2
#define            GENERAL_TIM_CH2_GPIO_CLK_2       RCC_APB2Periph_GPIOA
#define            GENERAL_TIM_CH2_PORT_2           GPIOA
#define            GENERAL_TIM_CH2_PIN_2            GPIO_Pin_7

// TIM3 ����Ƚ�ͨ��3
#define            GENERAL_TIM_CH3_GPIO_CLK_2       RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH3_PORT_2           GPIOB
#define            GENERAL_TIM_CH3_PIN_2            GPIO_Pin_0

// TIM3 ����Ƚ�ͨ��4
#define            GENERAL_TIM_CH4_GPIO_CLK_2       RCC_APB2Periph_GPIOB
#define            GENERAL_TIM_CH4_PORT_2           GPIOB
#define            GENERAL_TIM_CH4_PIN_2            GPIO_Pin_1

//��ʼΪ15��90�㣩+ �Ż���װ����
#define TIM_CCR1_Val_1         15
#define TIM_CCR2_Val_1         15
#define TIM_CCR3_Val_1         15
#define TIM_CCR4_Val_1         15
#define TIM_CCR1_Val_2         (15+2)
#define TIM_CCR2_Val_2         (15-1)
#define TIM_CCR3_Val_2         (15+1)
#define TIM_CCR4_Val_2         (15-1)

/**************************��������********************************/

void GENERAL_TIM_Init(void);


#endif
