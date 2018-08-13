#include <stdio.h>
#include "makefile.txt"


int main(void){
	FILE *data = fopen("Makefile", "w");
	fprintf(data, makefile, "prog", "main.o");
	return 0;
}