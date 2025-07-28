#include "auto_move.h"
#include "shoot.h"

void confirmation(){
	while(HAL_GPIO_ReadPin(CPort, CPin) == GPIO_PIN_RESET){}
	while(HAL_GPIO_ReadPin(CPort, CPin) == GPIO_PIN_SET){}
	shoot();
}


void auto_move(char command){
	if(command == 'R'){
		stepMotor(100, 1000, 1, S1_PORT, S1_Pin1, S1_Pin2, S1_Pin3, S1_Pin4, &htim1);
	}

	else if(command == 'L'){
		stepMotor(100, 1000, -1, S1_PORT, S1_Pin1, S1_Pin2, S1_Pin3, S1_Pin4, &htim1);
	}

	else if(command == 'U'){
			stepMotor(100, 1000, 1, S2_PORT, S2_Pin1, S2_Pin2, S2_Pin3, S2_Pin4, &htim1);
		}

	else if(command == 'D'){
			stepMotor(100, 1000, -1, S2_PORT, S2_Pin1, S2_Pin2, S2_Pin3, S2_Pin4, &htim1);
		}

	else if(command == 'C'){
			HAL_Delay(1000);
			if(command == 'C'){
				//blink to symbolize ready for shooting
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
				HAL_Delay(1000);
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
				HAL_Delay(1000);
				confirmation();
			}
		}
}
