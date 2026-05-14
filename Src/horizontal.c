/*
 * horizontal.c
 *
 *  Created on: May 8, 2026
 *      Author: aweso
 * 
 *    controls the horizontal movement of the dart shooter
 */

#include "horizontal.h"

void step() {
	for(int i = 0; i < 2; i++){
		 HAL_GPIO_WritePin(step_port, step_pin, GPIO_PIN_SET);
		 HAL_Delay(5);
		 HAL_GPIO_WritePin(step_port, step_pin, GPIO_PIN_RESET);
		 HAL_Delay(5);
	}

}


void horizontal_move() {
    if(received_char == 'a' || received_char == 'q' || received_char == 'z') { //move left
        HAL_GPIO_WritePin(dir_port, dir_pin, GPIO_PIN_SET);
        step();
    }
    else if(received_char == 'd' || received_char == 'e' || received_char == 'c') { //move right
        HAL_GPIO_WritePin(dir_port, dir_pin, GPIO_PIN_RESET);
        step();
    }
}
