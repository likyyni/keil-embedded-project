#include "stm32f10x.h"                  // Device header

int main(void){ 
	//使用库函数  Define内定义USE_STDPERIPH_DRIVER(keil自动声明
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	GPIO_SetBits(GPIOC,GPIO_Pin_13);  
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	while(1)
	{
	}
}
