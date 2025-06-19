#include "stepper_motor2.h"

//Setting up the Microcontroller pins (STM32 L432KC pins A1,A2,A3, and A4)
#define IN1_PIN2 GPIO_PIN_6
#define IN1_PORT2 GPIOC
#define IN2_PIN2 GPIO_PIN_7
#define IN2_PORT2 GPIOC
#define IN3_PIN2 GPIO_PIN_8
#define IN3_PORT2 GPIOC
#define IN4_PIN2 GPIO_PIN_9
#define IN4_PORT2 GPIOC


// Function for a microsecond delay using Timer 1
//With the microcontroller running at 80Mhz, the TIM1 needs to be initialized..
//..with a prescaler of 79 (80-1) and the default maximum counter period of 65535..
//.. so that it can run at 1MHz for us to get the 1 microsecond delay
void microDelay2(uint16_t delay) {
    __HAL_TIM_SET_COUNTER(&htim2, 0);
    while (__HAL_TIM_GET_COUNTER(&htim2) < delay);
}

// Function to set GPIO pins according to step sequence
void setPins2(uint8_t step[4]) {
    HAL_GPIO_WritePin(IN1_PORT2, IN1_PIN2, step[0] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN2_PORT2, IN2_PIN2, step[1] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN3_PORT2, IN3_PIN2, step[2] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(IN4_PORT2, IN4_PIN2, step[3] ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

// Function to move the motor in either clockwise or counterclockwise direction
void stepMotor2(int steps, uint16_t delay, int direction) {
    int seq_len = sizeof(step_sequence) / sizeof(step_sequence[0]);
    for (int x = 0; x < steps; x++) {
        int step_index = (direction == 1) ? x % seq_len : (seq_len - (x % seq_len)) % seq_len;
        setPins2((uint8_t*)step_sequence[step_index]);
        microDelay2(delay);
    }
}
