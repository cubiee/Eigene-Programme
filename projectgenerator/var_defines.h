#ifndef VARDEFINES_H
#define VARDEFINES_H

char standart_kopfzeile[] = {
	".c\n"
	"<PROGRAMMBESCHREIBUNG>\n"
	"Datum: <DATUM>\n"
	"Autor: <NAME> <VORNAME>\n"
	"Mat.Nr.: <MATRIKELNUMMER>\n"
	"*/\n"
};

char *standard_header[] = {
	"stdio.h",
	"stdlib.h",
	"string.h",
	"END"
};

char standart_main[] = {
	"int main(void){\n"
	"\n"
	"\t/*PROGRAMMCODE*/\n"
	"\n"
	"\treturn 0;\n"
	"}\n"
};

char standart_make_commands[] = {
	"CC = gcc\n"
	"CFLAGS = -Wall -pedantic -std=c99 -c\n"
	"OUTNAME = "
};

char standart_make_all[] = {
	"all: compile clean\n"
};

char standart_make_compile1[] = {
	".o\n"
	"\t$(CC) -o $(OUTNAME) "
};

char standart_make_compile2[] = {
	".c\n"
	"\t$(CC) $(CFLAGS) "
};

char standart_make_clean[] = {
	".c\n"
	"\n"
	"clean:\n"
	"\trm -f *.o\n"
};
#endif