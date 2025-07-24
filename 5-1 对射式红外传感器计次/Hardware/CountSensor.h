#ifndef __COUNT_SENSOR_H
#define __COUNT_SENSOR_H
#include "stdint.h"

void CountSensor_Init();
//中断函数不需要声明，是自动运行的
uint16_t CountSensor_Get();
#endif
