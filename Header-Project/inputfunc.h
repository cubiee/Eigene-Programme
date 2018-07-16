#ifndef INPUTFUNC_H
#define INPUTFUNC_H

#define INPUTBUFFER_SIZE 300

int get_usr_int(char *prompt, int min, int max, int *nmbr);

int get_usr_float(char *prompt, float min, float max, float *nmbr);
#endif