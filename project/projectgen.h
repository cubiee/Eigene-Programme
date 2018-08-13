#ifndef PROJECTGEN_H
#define PROJECTGEN_H

int generate_makefile(char *name, char **header, int headeranzahl);

int generate_main(char *name, char **header, int headeranzahl);

int generate_header(char *name);

void menue(void);

#endif