#ifndef AUTO_MOVER_H
#define AUTO_MOVER_H

#include "stepper_motor.h"

#define CPort GPIOB
#define CPin GPIO_PIN_1

void auto_move(char command);

#endif
