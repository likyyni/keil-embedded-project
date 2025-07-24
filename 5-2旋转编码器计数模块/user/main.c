#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"

#include <stdint.h>   // 标准类型定义
#include "Encoder.h"

int16_t Num;
int main(void){ 
	
	OLED_Init();
	
	
	OLED_ShowString(1 , 1 , "Count: ");

	while(1)
	{
		Num +=Encoder_Get();
		OLED_ShowSignedNum(1,5,Num,5);
	}	
}
