#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projectgen_std_func.h"

#define HEADERBUFFER 50

int write_header(char *used_header[], FILE *filename){
	int i = 0;
	char buffer[HEADERBUFFER] = "#include <";
	while (strcmp(used_header[i], "END") != 0){
		strcat(buffer, used_header[i]);
		strcat(buffer, ">\n");
		fputs(buffer, filename);
		buffer[0] = '\0';
		strcat(buffer, "#include <");
		i++;
	}
	return 0;
}

int write_make_command(char *command_name){
	return 0;
}