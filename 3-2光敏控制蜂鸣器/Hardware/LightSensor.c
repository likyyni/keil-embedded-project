#include "stm32f10x.h"                  // Device header

void LightSensor_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB , &GPIO_InitStructure);
}
//读取函数端口  就是返回一个端口的数据
uint8_t LightSensor_Get(){
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}
