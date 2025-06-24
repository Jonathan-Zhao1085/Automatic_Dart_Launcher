#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

//Setting up the Microcontroller pins (STM32 L432KC pins A1,A2,A3, and A4)
#define S1_PORT GPIOB
#define S1_Pin1 GPIO_PIN_12
#define S1_Pin2 GPIO_PIN_13
#define S1_Pin3 GPIO_PIN_14
#define S1_Pin4 GPIO_PIN_15

#define S2_PORT GPIOC
#define S2_Pin1 GPIO_PIN_6
#define S2_Pin2 GPIO_PIN_7
#define S2_Pin3 GPIO_PIN_8
#define S2_Pin4 GPIO_PIN_9


#include "main.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

// Step sequence for motor control (half-drive)
extern const uint8_t step_sequence[8][4];


// Function for a microsecond delay using Timer 1
//With the microcontroller running at 80Mhz, the TIM1 needs to be initialized..
//..with a prescaler of 79 (80-1) and the default maximum counter period of 65535..
//.. so that it can run at 1MHz for us to get the 1 microsecond delay

// Function to set GPIO pins according to step sequence
void setPins(uint8_t step[4], GPIO_TypeDef *GPIOx, uint16_t Pin_n1, uint16_t Pin_n2, uint16_t Pin_n3, uint16_t Pin_n4);

// Function to move the motor in either clockwise or counterclockwise direction
void stepMotor(int steps, uint16_t delay, int direction, GPIO_TypeDef *GPIOx, uint16_t Pin_n1, uint16_t Pin_n2, uint16_t Pin_n3, uint16_t Pin_n4, TIM_HandleTypeDef *timer);

#endif
