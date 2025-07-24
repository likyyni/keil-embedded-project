#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include <stdint.h>   // 标准类型定义

uint16_t Num;


int main(void){ 
	
	OLED_Init();
	//测试
	OLED_ShowChar(1 ,1 , 'A');
	OLED_ShowString(1 , 3 , "hello world!");
	OLED_ShowNum(2,1,12345,5);
	OLED_ShowNum(2,1,12345,6);//会在前面补0
	OLED_ShowNum(2,1,12345,4);//会把前面的1切掉
	Delay_ms(1000);	
	OLED_Clear();//qingping
	
	Timer_Init();
	
	OLED_ShowString(1,1,"Num:");
	OLED_ShowString(2,1,"CNT:");
	
	while(1)
	{
		OLED_ShowNum(1,5,Num,5);
//		OLED_ShowNum(2,5,TIM_GetCounter(TIM2),5);
		OLED_ShowNum(2,5,Timer_GetCounter(),5);
		
	}	
}

void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) == SET){
		Num++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
