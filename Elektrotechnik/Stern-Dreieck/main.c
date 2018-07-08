#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STERN_DREIECK 1
#define DREIECK_STERN 2
#define TRUE 1
#define FALSE 0

void menue(void);
int check_input(char **input, int *mode, float checked[3]);

void stern_dreieck(float R_a, float R_b, float R_c);
void dreieck_stern(float R_ab, float R_bc, float R_ac);

int main(int argc, char *argv[]){
	float input[3];
	int mode;

	if (argc != 5){
		menue();
	}
	else if (!check_input(argv, &mode, input)){
		printf("Ungueltige eingabe!\n");
		menue();
	}
	else{
		if (mode == STERN_DREIECK){
			stern_dreieck(input[0], input[1], input[2]);
		}
		else if(mode == DREIECK_STERN){
			dreieck_stern(input[0], input[1], input[2]);
		}
		else{
			menue();
		}
	}
	return 0;
}

void menue(void){
	printf("Aufruf durch:\n");
	printf("\t./stern_dreieck s <R_a> <R_b> <R_c>\n");
	printf("\t./stern_dreieck d <R_ab> <R_bc> <R_ac>\n");
}

int check_input(char **input, int *mode, float checked[3]){
	char suchstring[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!\"'$%&'()*+-,/:;<=>?@[\\]^_`{|}~"
	};
	int status;

	if ((strcmp(input[1], "d") && strcmp(input[1], "s")) == 1){
		status = FALSE;
	}
	else if ((strpbrk(input[2], suchstring) != NULL) || (atof(input[2]) == 0.0f)){
		status = FALSE;
	}
	else if ((strpbrk(input[3], suchstring) != NULL) || (atof(input[3]) == 0.0f)){
		status = FALSE;
	}
	else if ((strpbrk(input[4], suchstring) != NULL) || (atof(input[4]) == 0.0f)){
		status = FALSE;
	}
	else{
		checked[0] = atof(input[2]);
		checked[1] = atof(input[3]);
		checked[2] = atof(input[4]);
		
		if (!strcmp(input[1], "d")){
			*mode = DREIECK_STERN;
		}
		else if (!strcmp(input[1], "s")){
			*mode = STERN_DREIECK;
		}
		status = TRUE;
	}
	return status;
}

void stern_dreieck(float R_a, float R_b, float R_c){
	printf("Stern -> Dreieck:\n");
	float R_ab = 0.0f, R_bc = 0.0f, R_ac = 0.0f;
	R_ab = (R_a * R_b + R_b * R_c + R_c * R_a) / R_c;
	R_bc = (R_a * R_b + R_b * R_c + R_c * R_a) / R_a;
	R_ac = (R_a * R_b + R_b * R_c + R_c * R_a) / R_b;
	printf("\tR_ab : %.4f\n", R_ab);
	printf("\tR_bc : %.4f\n", R_bc);
	printf("\tR_ac : %.4f\n", R_ac);
}

void dreieck_stern(float R_ab, float R_bc, float R_ac){
	printf("Dreieck -> Stern:\n");
	float R_a, R_b, R_c;
	R_a = (R_ac * R_ab) / (R_ab + R_bc + R_ac);
	R_b = (R_ab * R_bc) / (R_ab + R_bc + R_ac);
	R_c = (R_ac * R_bc) / (R_ab + R_bc + R_ac);
	printf("\tR_a : %.4f\n", R_a);
	printf("\tR_b : %.4f\n", R_b);
	printf("\tR_c : %.4f\n", R_c);
}