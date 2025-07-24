#include "stm32f10x.h"                  // Device header

//extern uint16_t Num;

void Timer_Init(){
	//初始化定时器
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	//	TIM_InternalClockConfig(TIM2);    这次不使用内部时钟，用外部时钟
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPU ;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//这个引脚用的是GPIO，所以也需要对该GPIO初始化
	TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x00);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision =TIM_CKD_DIV1 ;
	TIM_TimeBaseInitStructure.TIM_CounterMode =TIM_CounterMode_Up ;
	TIM_TimeBaseInitStructure.TIM_Period =10-1 ;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	TIM_ClearFlag(TIM2,TIM_IT_Update);//这个是手动解决每次重新计数Num值为1的情况
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	//分组中断
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel =TIM2_IRQn  ;
	NVIC_InitStructure.NVIC_IRQChannelCmd =ENABLE ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	//启动定时器
	TIM_Cmd(TIM2,ENABLE);
	
}

uint16_t Timer_GetCounter(void){
	return TIM_GetCounter(TIM2);
}
//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET){
//		
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
