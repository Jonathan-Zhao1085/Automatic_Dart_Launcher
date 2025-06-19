#include "stepper_motor.h"

//Setting up the Microcontroller pins (STM32 L432KC pins A1,A2,A3, and A4)
#define IN1_PIN GPIO_PIN_12
#define IN1_PORT GPIOB
#define IN2_PIN GPIO_PIN_13
#define IN2_PORT GPIOB
#define IN3_PIN GPIO_PIN_14
#define IN3_PORT GPIOB
#define IN4_PIN GPIO_PIN_15
#define IN4_PORT GPIOB

// Step sequence for motor control (half-drive)
const uint8_t step_sequence[8][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1}
};


// Function for a microsecond delay using Timer 1
//With the microcontroller running at 80Mhz, the TIM1 needs to be initialized..
//..with a prescaler of 79 (80-1) and the default maximum counter period of 65535..
//.. so that it can run at 1MHz for us to get the 1 microsecond delay
void microDelay(uint16_t delay) {
    __HAL_TIM_SET_COUNTER(&htim1, 0);
    while (__HAL_TIM_GET_COUNTER(&htim1) < delay);
}

// Function to set GPIO pins according to step sequence
void setPins(uint8_t step[4]) {
    HAL_GPIO_WritePin(IN1_PORT, IN1_PIN, step[0] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN2_PORT, IN2_PIN, step[1] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN3_PORT, IN3_PIN, step[2] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN4_PORT, IN4_PIN, step[3] ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

// Function to move the motor in either clockwise or counterclockwise direction
void stepMotor(int steps, uint16_t delay, int direction) {
    int seq_len = sizeof(step_sequence) / sizeof(step_sequence[0]);
    for (int x = 0; x < steps; x++) {
        int step_index = (direction == 1) ? x % seq_len : (seq_len - (x % seq_len)) % seq_len;
        setPins((uint8_t*)step_sequence[step_index]);
        microDelay(delay);
    }
}
