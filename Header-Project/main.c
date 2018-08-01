#include <stdio.h>
#include <string.h>

#include "myheader.h"

int main(int argc, char *argv[]){
	float r1, r2, r3;
	int mode;
	while (!get_usr_int("Bitte modus wahlen(1 = s->d ; 2 = d->s): ", 1, 2, &mode)){
		printf("Ungueltige eingabe!\n");
	}
	while (!get_usr_float("Bitte R1 eingeben: ", 0.0f, 1000000.0f, &r1)){
		printf("Ungueltige eingabe!\n");
	}
	while (!get_usr_float("Bitte R2 eingeben: ", 0.0f, 1000000.0f, &r2)){
		printf("Ungueltige eingabe!\n");
	}
	while (!get_usr_float("Bitte R3 eingeben: ", 0.0f, 1000000.0f, &r3)){
		printf("Ungueltige eingabe!\n");
	}
	stern_dreieck_umwandlung(mode, r1, r2, r3);
	return 0;
}