#include "get_usr_data.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_usr_string(char *buffer, int buffersize, char *prompt){
	char stringbuffer[STRINGBUFFERSIZE] = { '\0' };
	printf(prompt);
	fgets(stringbuffer, STRINGBUFFERSIZE, stdin);
	if (NULL == strchr(stringbuffer, '\n')){
		clear_inputbuffer();
	}
	
	if (strlen(stringbuffer) <= 1){
		return FALSE;
	}

	strtok(stringbuffer, "\n");

	int whitespace = 0;
	for (int i = 0; i < strlen(stringbuffer); i++){
		if (stringbuffer[i] == ' '){
			whitespace++;
		}
	}

	if (whitespace == strlen(stringbuffer)){
		return FALSE;
	}

	strncpy(buffer, stringbuffer, buffersize - 1);
	return TRUE;
}

int get_usr_int(int *buffer, int min, int max, char *prompt){
	if (max < min){
		int c = max;
		max = min;
		min = c;
	}

	char stringbuffer[STRINGBUFFERSIZE] = { '\0' };
	int zahl = 0;
	char suchstring[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!\"'$%&'()*+,./:;<=>?@[\\]^_`{|}~ "
	};

	printf(prompt);
	fgets(stringbuffer, STRINGBUFFERSIZE, stdin);

	if (NULL == strchr(stringbuffer, '\n')){
		clear_inputbuffer();
	}
	else{
		strtok(stringbuffer, "\n");
	}

	if (strlen(stringbuffer) == 0){
		return FALSE;
	}


	int whitespace = 0;
	for (int i = 0; i < strlen(stringbuffer); i++){
		if (stringbuffer[i] == ' '){
			whitespace++;
		}
	}

	if (whitespace == strlen(stringbuffer)){
		return FALSE;
	}
	if (NULL != strpbrk(stringbuffer, suchstring)){
		//eingabe keine zahl
		return FALSE;
	}
	else{
		zahl = atoi(stringbuffer);
		if ((zahl < min) || (zahl > max)){
			//ausserhalb der grenzen
			return FALSE;
		}
		else{
			*buffer = zahl;
			return TRUE;
		}
	}
}

void clear_inputbuffer(void){
	int buff;
	while ((buff = getchar()) != '\n' && buff != EOF){}
}