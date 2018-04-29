#ifndef VARDEFINES_H
#define VARDEFINES_H

//MAIN FILE
char standart_kopfzeile[] = {
	"/*%s.c\n"
	"<PROGRAMMBESCHREIBUNG>\n"
	"Datum: %s\n"
	"Autor: <NAME> <VORNAME>\n"
	"Mat.Nr.: <MATRIKELNUMMER>\n"
	"*/\n"
};

char *standard_header[] = {
	"stdio.h",
	"stdlib.h",
	"END"
};

char standart_main[] = {
	"int main(void){\n"
	"\n"
	"\t/*PROGRAMMCODE*/\n"
	"\t\n"
	"\treturn 0;\n"
	"}\n"
};


//MAKE FILE
char *compiler = "gcc";
char *commands = "-Wall -pedantic -std=c99 -c";

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
	"clean:\n"
	"\trm -f *.o\n"
};
#endif