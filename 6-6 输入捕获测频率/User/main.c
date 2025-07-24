#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"


int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	PWM_Init();			//PWM初始化
	IC_Init();
	
	PWM_SetPrescaler(720-1);	//计算频率的公式：Freq = 72M/（PSC+1）/100
	PWM_SetCompare1(50);	//计算占空比的公式：Duty = CCR/（ARR+1）
	
	OLED_ShowString(1,1,"Freq:00000Hz");
	
	
	while (1)
	{
		OLED_ShowNum(1,6,IC_GetFrep(),5);
	}
}
