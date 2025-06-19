#include "serial_reader.h"

uint8_t receive[1] = {};

char serial_read(){
	HAL_UART_Receive_IT(&huart2, receive, 1);
	if(receive[0] == 82){
		return 'R';
	}
	else if(receive[0] == 76){
		return 'L';
	}
	else if(receive[0] == 68){
			return 'D';
		}
	else if(receive[0] == 85){
			return 'U';
		}
	else if(receive[0] == 67){
			return 'C';
		}
	return 'X';
}
