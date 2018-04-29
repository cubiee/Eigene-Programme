#ifndef PROJECT_GEN_STD_FUNC_H
#define PROJECT_GEN_STD_FUNC_H

typedef struct makecommands_s{
	char compiler[20];
	char compilerflags[100];
	char outname[20];
}MAKECOMMANDS;

int write_header(char *used_header[], FILE *filename);

int write_make_vars(MAKECOMMANDS parameter, FILE *filename);

int write_make_object_command(char *command_name, FILE *filename);

#endif