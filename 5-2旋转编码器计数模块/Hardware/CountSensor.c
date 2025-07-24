#include "stm32f10x.h"                  // Device header


uint16_t CountSensor_Count;

void CountSensor_Init(){
	//RCC开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO ,ENABLE);
	
	//NVIC也不需要开启时钟
	//配置GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPU ;//上拉输入，默认为高电平的输入方式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//配置AFIO   详细在GPIO.h函数里面
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
	//配置EXTI
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line14;
	EXTI_InitStructure.EXTI_LineCmd =ENABLE ;
	EXTI_InitStructure.EXTI_Mode =EXTI_Mode_Interrupt ;//使用中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//这里也可以改成上升沿触发Rising
	EXTI_Init(&EXTI_InitStructure);
	
	//配置NVIC  在misc.h文件中
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =1 ;
	NVIC_Init(&NVIC_InitStructure);
	
	/*外部中断信号从GPIO 到AFIO ，再到EXTI ，最后到NVIC
最终通向CPU，这样才能让CPU由主程序跳转到中断程序执行*/

}
void EXTI15_10_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line14)==SET){
		
		CountSensor_Count ++;
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}

uint16_t CountSensor_Get(){
	return CountSensor_Count;
}
