#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"


int main(void){
	
	
	Buzzer_Init();//初始化蜂鸣器
	LightSensor_Init();
	
	
	while(1)
	{
		//测试Buzzer
		Buzzer_ON();
		Delay_ms(500);
		Buzzer_OFF();
		Delay_ms(500);
		Buzzer_Turn();
		Delay_ms(500);
		Buzzer_Turn();
		Delay_ms(500);
//		if(LightSensor_Get() == 1){
//			Buzzer_ON();
//		}
//		else{
//			Buzzer_OFF();
//		}	
	}
}//main的}
