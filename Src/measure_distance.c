/*
 * measure_distance.c
 *
 *  Created on: Jul 6, 2025
 *      Author: aweso
 */

#include "measure_distance.h"

int measure_distance(TIM_HandleTypeDef *timer){
	HAL_GPIO_WritePin(ultrasonic_port, ultrasonic_trig, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	microDelay(10, timer);  // wait for 10 us
	HAL_GPIO_WritePin(ultrasonic_port, ultrasonic_trig, GPIO_PIN_RESET);  // pull the TRIG pin low

	uint8_t pMillis = HAL_GetTick(); // used this to avoid infinite while loop  (for timeout)
	// wait for the echo pin to go high
	while (!(HAL_GPIO_ReadPin (ultrasonic_port, ultrasonic_echo)) && pMillis + 10 >  HAL_GetTick());
	uint8_t Value1 = __HAL_TIM_GET_COUNTER (timer);

	pMillis = HAL_GetTick(); // used this to avoid infinite while loop (for timeout)
	// wait for the echo pin to go low
	while ((HAL_GPIO_ReadPin (ultrasonic_port, ultrasonic_echo)) && pMillis + 50 > HAL_GetTick());
	uint8_t Value2 = __HAL_TIM_GET_COUNTER (timer);

	uint8_t Distance = (Value2-Value1)* 0.034/2;

	return Distance;
}
