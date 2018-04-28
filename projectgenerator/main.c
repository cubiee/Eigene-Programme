#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var_defines.h"

#define TRUE 1
#define FALSE 0

void menue(void);

int standartmode(char *projectname);
void write_standart_main(char *projectname, FILE *main_file);


void extendetmode(char *projectname);
void konfigfilemode(char *projectname);


int main(int argc, char *argv[]){
	if (argc < 3){
		menue();
	}
	else
	{
		if (strcmp(argv[2], "-s") == 0){
			standartmode(argv[1]);
		}
		else if (strcmp(argv[2], "-e") == 0){
			//extendetmode(argv[1]);
		}
		else if (strcmp(argv[2], "-f") == 0){
			//konfigfilemode(argv[1]);
		}
		else{
			printf("Modus parameter ungueltig\n");
			menue();
		}
	}
	return 0;
}

void menue(void){
	printf("Aufruf durch :\n");
	printf("\t./projectgen <Projektname> <modus>\n");
	printf("Modus:\n");
	printf("\t-s : Standartmodus\n\t-e : Erweiterter modus\n\t-f : Konigurations Datei modus\n");
	return;
}

int standartmode(char *projectname){
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
			status = TRUE;
		}
	}
	return status;
}

void write_standart_main(char *projectname, FILE *main_file){
	fputs("/*", main_file);
	fputs(projectname, main_file);
	fputs(standart_kopfzeile, main_file);
	fputs(standart_header, main_file);
	fputs("\n\n", main_file);
	fputs(standart_main, main_file);
	return;
}