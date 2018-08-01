#ifndef GET_USR_DATA_H
#define GET_USR_DATA_H

#define TRUE  1
#define FALSE 0

#define STRINGBUFFERSIZE 200


int get_usr_string(char *buffer, int buffersize, char *prompt);
int get_usr_int(int *buffer, int min, int max, char *prompt);

void clear_inputbuffer(void);



#endif