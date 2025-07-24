#include "stm32f10x.h"                  // Device header

void Buzzer_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	//可以按位或|来同时选中多个引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB , &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
}

void Buzzer_ON(){
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
}
void Buzzer_OFF(){
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}
void Buzzer_Turn(){
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_13)==0){
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
	}
	else{
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	}
}

