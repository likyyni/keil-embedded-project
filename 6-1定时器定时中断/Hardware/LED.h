/*
LED.h用来存放这个驱动程序可以对外提供的函数或变量的声明

.h文件，要添加一个防止头文件重复包含的代码
*/

#ifndef __LED_H
#define __LED_H



void LED_Init(void);

void LED1_ON(void);
void LED1_OFF(void);

void LED2_ON(void);
void LED2_OFF(void);

void LED1_Turn(void);
void LED2_Turn(void);
//封装led的驱动函数模块  然后就可以在主函数里面调用
#endif
