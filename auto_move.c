#include "auto_move.h"

void auto_move(char command){
	if(command == 'R'){
		stepMotor(50, 1000, 1);
	}

	else if(command == 'L'){
		stepMotor(50, 1000, -1);
	}

	else if(command == 'U'){
			stepMotor2(50, 1000, 1);
		}

	else if(command == 'D'){
			stepMotor2(50, 1000, -1);
		}

	else if(command == 'C'){

		}
}
