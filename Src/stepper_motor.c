#include "stepper_motor.h"

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


// Function to set GPIO pins according to step sequence
void setPins(uint8_t step[4], GPIO_TypeDef *GPIOx, uint16_t Pin_n1, uint16_t Pin_n2, uint16_t Pin_n3, uint16_t Pin_n4) {
    HAL_GPIO_WritePin(GPIOx, Pin_n1, step[0] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, Pin_n2, step[1] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, Pin_n3, step[2] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOx, Pin_n4, step[3] ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

// Function to move the motor in either clockwise or counterclockwise direction
void stepMotor(int steps, uint16_t delay, int direction, GPIO_TypeDef *GPIOx, uint16_t Pin_n1, uint16_t Pin_n2, uint16_t Pin_n3, uint16_t Pin_n4, TIM_HandleTypeDef *timer) {
    int seq_len = sizeof(step_sequence) / sizeof(step_sequence[0]);
    for (int x = 0; x < steps; x++) {
        int step_index = (direction == 1) ? x % seq_len : (seq_len - (x % seq_len)) % seq_len;
        setPins((uint8_t*)step_sequence[step_index], GPIOx, Pin_n1, Pin_n2, Pin_n3, Pin_n4);
        microDelay(delay, timer);
    }
}
