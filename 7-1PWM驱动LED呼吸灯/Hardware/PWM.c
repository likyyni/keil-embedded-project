#include "stm32f10x.h"                  // Device header


void PWM_Init(void){
	
	//初始化PA0引脚
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);/*这里开启AFIO时钟来
	来使用GPIO_PinRempConfig()来引脚重映射
	*/
	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);
	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);//关闭PA5的调试服用
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//这里要使用复用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA , &GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
	
		//初始化定时器
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	//打开时钟，
	//选择内部时钟，
	TIM_InternalClockConfig(TIM2);
	
	//初始化时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;
	TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up ;
	TIM_TimeBaseInitStructure.TIM_Period =10000-1 ; //ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200-1; //PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	//初始化比较单元
	//这里使用的是PA0口，对应的是第一个输出比较通道
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity =TIM_OCPolarity_High ;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;  //CCR
	TIM_OC1Init(TIM2 ,&TIM_OCInitStructure);
	
	/*启动定时器 
	PWM频率= PSC/(PSC+1)(ARR+1)
	现在就是输出TIM2的CH1通道的PWM波形，频率1MHz，占空比50%，分辨率1%
	*/
	TIM_Cmd(TIM2,ENABLE);
}

void PWM_SetCompare1(uint16_t Compare){
	TIM_SetCompare1(TIM2,Compare);
}
