/*
 * serial_receive.c
 *
 *  Created on: May 8, 2026
 *      Author: aweso
 *
 *
 *     reads data being trasferred from laptop with uart and returns the value
 */

#include "serial_receive.h"

uint8_t received_char;

void serial_receive() {
    HAL_UART_Receive_IT(&huart2, &received_char, 1);
}
