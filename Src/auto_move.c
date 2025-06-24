#include "auto_move.h"
#include "shoot.h"

void confirmation(){
	while(HAL_GPIO_ReadPin(CPort, CPin) == GPIO_PIN_RESET){}
	shoot();
}


void auto_move(char command){
	if(command == 'R'){
		stepMotor(50, 1000, 1, S1_PORT, S1_Pin1, S1_Pin2, S1_Pin3, S1_Pin4, &htim1);
	}

	else if(command == 'L'){
		stepMotor(50, 1000, -1, S1_PORT, S1_Pin1, S1_Pin2, S1_Pin3, S1_Pin4, &htim1);
	}

	else if(command == 'U'){
			stepMotor(50, 1000, 1, S2_PORT, S2_Pin1, S2_Pin2, S2_Pin3, S2_Pin4, &htim2);
		}

	else if(command == 'D'){
			stepMotor(50, 1000, -1, S2_PORT, S2_Pin1, S2_Pin2, S2_Pin3, S2_Pin4, &htim2);
		}

	else if(command == 'C'){
			HAL_Delay(1000);
			if(commmand == 'C'){
				confirmation();
			}
		}
}
