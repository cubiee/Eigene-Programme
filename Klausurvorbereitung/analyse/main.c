#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "analyse.h"



int main(int argc, char *argv[]){
	if (argc != 2)
	{
		printf("Wrong arguments\n!");
	}
	else
	{
		FILE *file = fopen(argv[1], "r");
		FILEINFO info;
		if (!analyseFile(file, &info))
		{
			printf("Fehler beim analysieren der datei!\n");
		}
		else
		{
			printFileinfo(info);
		}
	}
	return 0;
}
