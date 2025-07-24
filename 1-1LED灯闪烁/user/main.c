#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void){ 
	//使用库函数  Define内定义USE_STDPERIPH_DRIVER(keil自动声明
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA , &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);//让灯亮起来
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);//让灯灭
	GPIO_WriteBit(GPIOA, GPIO_Pin_0,Bit_RESET);
	
	
	while(1)
	{
		
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		Delay_ms(500);
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		Delay_ms(500);
		
		GPIO_WriteBit(GPIOA, GPIO_Pin_0,Bit_RESET);
		//中间延时 形成闪烁
		Delay_ms(500);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0,Bit_SET);
		Delay_ms(500);
	}
}
