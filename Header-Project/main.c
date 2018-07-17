#include <stdio.h>
#include <string.h>

#include "myheader.h"

int main(int argc, char *argv[]){
	char str[15] = { '\0' };
	while (!get_usr_string("Bitte string eingeben: ", str, sizeof(str) / sizeof(char))){
		printf("Fehler bitte nochmal!\n");
	}
	printf("-->%s<--\n",str);
	return 0;
}