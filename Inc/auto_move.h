#ifndef AUTO_MOVER_H
#define AUTO_MOVER_H

#include "stepper_motor.h"

#define CPort GPIOC
#define CPin GPIO_PIN_0

void auto_move(char command);

#endif
