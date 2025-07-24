#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void key_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//开启时钟
	//初始化为上拉
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	

}

//读取按键
uint8_t key_GetNum()
{    //unsighed char
	uint8_t keyNum = 0;
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_1) == 0)
		{
		//消除抖
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0)
		Delay_ms(20);
		keyNum = 1;
	
		}
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_11) == 0)
		{
		//消除抖
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0)
		Delay_ms(20);
		keyNum = 2;
		}
		return keyNum;
}	
	