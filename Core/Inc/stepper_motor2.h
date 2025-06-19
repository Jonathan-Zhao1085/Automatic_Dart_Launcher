#ifndef STEPPER_MOTOR2_H
#define STEPPER_MOTOR2_H

#include "main.h"

extern TIM_HandleTypeDef htim2;
extern const uint8_t step_sequence[8][4];
// Function for a microsecond delay using Timer 1
//With the microcontroller running at 80Mhz, the TIM1 needs to be initialized..
//..with a prescaler of 79 (80-1) and the default maximum counter period of 65535..
//.. so that it can run at 1MHz for us to get the 1 microsecond delay
void microDelay2(uint16_t delay);

// Function to set GPIO pins according to step sequence
void setPins2(uint8_t step[4]);

// Function to move the motor in either clockwise or counterclockwise direction
void stepMotor2(int steps, uint16_t delay, int direction);

#endif
