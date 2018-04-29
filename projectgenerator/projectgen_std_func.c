#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projectgen_std_func.h"

#define HEADERBUFFER 50

int write_header(char *used_header[], FILE *filename){
	int i = 0;
	while (strcmp(used_header[i], "END") != 0){
		fprintf(filename, "#include <%s>\n", used_header[i]);
		i++;
	}
	fputs("\n", filename);
	return 0;
}

int write_make_vars(MAKECOMMANDS parameter, FILE *filename){
	fprintf(filename, "CC = %s\n", parameter.compiler);
	fprintf(filename, "CFLAGS = %s\n", parameter.compilerflags);
	fprintf(filename, "OUTNAME = %s\n", parameter.outname);
	return 0;
}


int write_make_object_command(char *command_name, FILE *filename){
	fprintf(filename, "%s.o: %s.c\n", command_name, command_name);
	fprintf(filename, "\t$(CC) $(CFLAGS) %s.c\n", command_name);
	return 0;
}