#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include "main.h"

extern TIM_HandleTypeDef htim1;

// Function for a microsecond delay using Timer 1
//With the microcontroller running at 80Mhz, the TIM1 needs to be initialized..
//..with a prescaler of 79 (80-1) and the default maximum counter period of 65535..
//.. so that it can run at 1MHz for us to get the 1 microsecond delay
void microDelay(uint16_t delay);

// Function to set GPIO pins according to step sequence
void setPins(uint8_t step[4]);

// Function to move the motor in either clockwise or counterclockwise direction
void stepMotor(int steps, uint16_t delay, int direction);

#endif
