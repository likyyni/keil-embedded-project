#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void){ 
	//使用库函数  Define内定义USE_STDPERIPH_DRIVER(keil自动声明
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//连接的是GPIOA的端口 
	//流水灯用的是0-7的端口，所以需要添加对应的端口
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA , &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);//让灯亮起来  好像是因为低电平驱动的这个IO口
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);//让灯灭
	GPIO_WriteBit(GPIOA, GPIO_Pin_0,Bit_RESET);
	
	
	
	
	//让蜂鸣器响的
	//初始化那里要设置成GPIOB，PIN口要设置成Pin12
	while(1)
	{
		
		GPIO_Write(GPIOA,~0x0001);//0000 0000 0000 0001最右边对应PA0，依次从左往右对应
		//16个端口，PA1，PA2，一直到PA15   且这个为低电平点亮
		//所以0x0001前面加上一个按位取反的符号“~”
		Delay_ms(100);
		
		GPIO_Write(GPIOA,~0x0002);//0000 0000 0000 0010
		Delay_ms(100);
		
		GPIO_Write(GPIOA,~0x0004);//0000 0000 0000 0100
		Delay_ms(100);
		
		GPIO_Write(GPIOA,~0x0008);//0000 0000 0000 1000
		Delay_ms(500);
		
		GPIO_Write(GPIOA,~0x0010);//0000 0000 0001 0000
		Delay_ms(100);
		
		GPIO_Write(GPIOA,~0x0020);//0000 0000 0010 0000
		Delay_ms(100);
		
		GPIO_Write(GPIOA,~0x0040);//0000 0000 0100 0000
		Delay_ms(100);
		
		GPIO_Write(GPIOA,~0x0080);//0000 0000 1000 0000
		Delay_ms(100);
	}
}
