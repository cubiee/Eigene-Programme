#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "inputfunc.h"
#include "Stringfunc.h"

int get_usr_int(char *prompt, int min, int max, int *nmbr){
	int status = 1;
	char BUFFER[INPUTBUFFER_SIZE] = { '\0' };
	int temp;

	printf(prompt);

	if (max < min){
		temp = max;
		max = min;
		min = temp;
	}

	if (NULL == fgets(BUFFER, INPUTBUFFER_SIZE, stdin)){
		status = 0;
	}
	else{
		strtok(BUFFER, "\n");
		if (!check_if_int(BUFFER)){
			status = 0;
		}
		else{
			temp = atoi(BUFFER);
			if ((temp < min) || (temp > max)){
				status = 0;
			}
			else{
				*nmbr = temp;
			}
		}
	}
	return status;
}

int get_usr_float(char *prompt, float min, float max, float *nmbr){
	int status = 1;
	char BUFFER[INPUTBUFFER_SIZE] = { '\0' };
	float temp;

	printf(prompt);

	if (max < min){
		float temp = max;
		max = min;
		min = temp;
	}

	if (NULL == fgets(BUFFER, INPUTBUFFER_SIZE, stdin)){
		status = 0;
	}
	else{
		strtok(BUFFER, "\n");
		if (!check_if_float(BUFFER)){
			status = 0;
		}
		else{
			temp = atof(BUFFER);
			if ((temp < min) || (temp > max)){
				status = 0;
			}
			else{
				*nmbr = temp;
			}
		}
	}
	return status;
}

int get_usr_string(char *prompt, char *buffer, int buffer_size){
	int status = 1;
	int i = 0, j = 0;
	char INPUTBUFFER[INPUTBUFFER_SIZE] = { '\0' };

	printf(prompt);

	if (NULL == fgets(INPUTBUFFER, INPUTBUFFER_SIZE, stdin)){
		status = 0;
	}
	else{
		INPUTBUFFER[strlen(INPUTBUFFER) - 1] = '\0';
		if (0 >= strlen(INPUTBUFFER)){
			status = 0;
		}
		else{
			for (i = 0; i < strlen(INPUTBUFFER); i++){
				if (INPUTBUFFER[i] != ' '){
					j++;
				}
			}
			if (0 == j){
				status = 0;
			}
			else{
				strncpy(buffer, INPUTBUFFER, buffer_size);
				buffer[buffer_size - 1] = '\0';
			}
		}
	}
	return status;
}