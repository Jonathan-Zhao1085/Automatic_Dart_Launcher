/*
 * vertical.c
 *
 *  Created on: May 9, 2026
 *      Author: aweso
 *
 *      controls the vertical aiming of the dart shooter
 */

#include "vertical.h"

uint16_t pulse;
uint8_t prev_angle = 160;

void set_angle(uint8_t angle) {
    pulse = ((angle/270.0)*6000) + 1500;
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, pulse);
}

void vertical_move() {
    if(received_char == 'q' || received_char == 'w' || received_char == 'e') { //move up
        if(prev_angle < 220 - 1) {
            set_angle(prev_angle + 1);
            prev_angle += 1;
        }
    }
    else if(received_char == 'z' || received_char == 'x' || received_char == 'c') { //move down
        if(prev_angle > 160 + 1) {
            set_angle(prev_angle - 1);
            prev_angle -= 1;
        }
    }
}