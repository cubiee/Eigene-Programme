#ifndef STANDARD_MODE_H
#define STANDARD_MODE_H

#define TRUE 1
#define FALSE 0

int standartmode(char *projectname);
void write_standart_main(char *projectname, FILE *main_file);
void write_standart_makefile(char *projectname, FILE *make_file);

#endif