#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include"LED.h"
#include "key.h"

uint8_t keyNum;//定义一个全局变量

int main(void){ 
	//使用库函数  Define内定义USE_STDPERIPH_DRIVER(keil自动声明
	
	
	LED_Init();//默认低电平
	key_Init();
	
	while(1)
	{
		//LED1_ON();
		//LED2_OFF();
		//Delay_ms(500);
		
		//LED1_OFF();
		//LED2_ON();
		//Delay_ms(500);
		
		
		//下面两个if演示得按一下熄灭，按一下点亮
		keyNum = key_GetNum();
		if(keyNum == 1)
		{
			LED1_Turn();
			
		}
		if(keyNum == 2)
		{
			LED2_Turn();
			
		}
	}
}
