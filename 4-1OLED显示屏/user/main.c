#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "key.h"
#include <stdint.h>   // 标准类型定义



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
	while(1)
	{
	
	}	
}
