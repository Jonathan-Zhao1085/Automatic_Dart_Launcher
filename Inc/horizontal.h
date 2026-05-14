/*
 * horizontal.h
 *
 *  Created on: May 8, 2026
 *      Author: aweso
 */

#ifndef INC_HORIZONTAL_H_
#define INC_HORIZONTAL_H_

#include "stm32f4xx_hal.h"

#define step_pin GPIO_PIN_10
#define step_port GPIOB
#define dir_pin GPIO_PIN_4
#define dir_port GPIOB

extern uint8_t received_char;

void step();
void horizontal_move();

#endif /* INC_HORIZONTAL_H_ */
