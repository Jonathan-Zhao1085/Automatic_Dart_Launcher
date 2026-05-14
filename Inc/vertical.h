/*
 * vertical.h
 *
 *  Created on: May 9, 2026
 *      Author: aweso
 */

#ifndef INC_VERTICAL_H_
#define INC_VERTICAL_H_

#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim1;
extern uint8_t received_char;
extern uint16_t pulse;
extern uint8_t prev_angle;

void set_angle(uint8_t angle);
void vertical_move();
#endif /* INC_VERTICAL_H_ */
