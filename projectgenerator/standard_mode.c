#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "projectgen_std_func.h"
#include "standard_mode.h"
#include "var_defines.h"

#define TRUE 1
#define FALSE 0

void write_standart_main(char *projectname, FILE *main_file);
void write_standart_makefile(char *projectname, FILE *make_file);

int standard_mode(char *projectname){
	FILE *main_file;
	FILE *makefile;

	char mainfile_name[30] = "";
	strcat(mainfile_name, projectname);
	strcat(mainfile_name, ".c");

	int status;
	if (NULL != (main_file = fopen(mainfile_name, "r"))){
		printf("main.c existiert in diesem verzeichnis bereits!\n");
		status = FALSE;
		fclose(main_file);
	}
	else if (NULL != (makefile = fopen("Makefile", "r"))){
		printf("Makefile existiert in diesem verzeichnis bereits!\n");
		status = FALSE;
		fclose(makefile);
	}
	else{
		if (NULL == (main_file = fopen(mainfile_name, "w"))){
			printf("main.c konnte nicht erstellt werden!\n");
			status = FALSE;
		}
		else if (NULL == (makefile = fopen("Makefile", "w"))){
			printf("Makefile konnte nicht erstellt werden!\n");
			status = FALSE;
		}
		else{
			write_standart_main(projectname, main_file);
			write_standart_makefile(projectname, makefile);
			status = TRUE;
		}
	}
	return status;
}

void write_standart_main(char *projectname, FILE *main_file){
	fputs("/*", main_file);
	fputs(projectname, main_file);
	fputs(standart_kopfzeile, main_file);
	write_header(standard_header, main_file);
	fputs("\n\n", main_file);
	fputs(standart_main, main_file);
	return;
}

void write_standart_makefile(char *projectname, FILE *make_file){
	fputs(standart_make_commands, make_file);
	fputs(projectname, make_file);
	fputs("\n", make_file);
	fputs("\n", make_file);
	fputs(standart_make_all, make_file);
	fputs("\n", make_file);
	fputs("compile: ", make_file);
	fputs(projectname, make_file);
	fputs(standart_make_compile1, make_file);
	fputs(projectname, make_file);
	fputs(".o\n", make_file);
	fputs("\n", make_file);
	fputs(projectname, make_file);
	fputs(".o: ", make_file);
	fputs(projectname, make_file);
	fputs(standart_make_compile2, make_file);
	fputs(projectname, make_file);
	fputs(standart_make_clean, make_file);
}