/*
 * serial_receive.h
 *
 *  Created on: May 8, 2026
 *      Author: aweso
 */

#ifndef SERIAL_RECEIVE_H
#define SERIAL_RECEIVE_H

#include "stm32f4xx_hal.h" //for UART_HandleTypeDef and uint8_t type definition

extern UART_HandleTypeDef huart2;
extern uint8_t received_char;
void serial_receive();

#endif  /* INC SERIAL_RECEIVE_H*/
