#ifndef MEASURE_DISTANCE_H
#define MEASURE_DISTANCE_H

#define ultrasonic_port GPIOA
#define ultrasonic_trig GPIO_PIN_8
#define ultrasonic_echo GPIO_PIN_9

#include "main.h"

extern TIM_HandleTypeDef htim4;

int measure_distance(TIM_HandleTypeDef *timer);

#endif
