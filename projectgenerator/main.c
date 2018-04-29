#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "standard_mode.h"


void menue(void);

int main(int argc, char *argv[]){
	if (argc < 3){
		menue();
	}
	else
	{
		if (strcmp(argv[2], "-s") == 0){
			standard_mode(argv[1]);
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

