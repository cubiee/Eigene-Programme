#include "Elektrotechnik.h"
#include <stdio.h>

#define STERN_DREIECK 1
#define DREIECK_STERN 2

void __stern_dreieck(float R_a, float R_b, float R_c);
void __dreieck_stern(float R_ab, float R_bc, float R_ac);
void __stern_dreieck_menue(void);

void stern_dreieck_umwandlung(int mode, float R_1, float R_2, float R_3){
	if (mode == STERN_DREIECK){
		__stern_dreieck(R_1, R_2, R_3);
	}
	else if (mode == DREIECK_STERN){
		__dreieck_stern(R_1, R_2, R_3);
	}
	else{
		__stern_dreieck_menue();
	}
}

void __stern_dreieck(float R_a, float R_b, float R_c){
	printf("Stern -> Dreieck:\n");
	float R_ab = 0.0f, R_bc = 0.0f, R_ac = 0.0f;
	R_ab = (R_a * R_b + R_b * R_c + R_c * R_a) / R_c;
	R_bc = (R_a * R_b + R_b * R_c + R_c * R_a) / R_a;
	R_ac = (R_a * R_b + R_b * R_c + R_c * R_a) / R_b;
	printf("\tR_ab : %.4f\n", R_ab);
	printf("\tR_bc : %.4f\n", R_bc);
	printf("\tR_ac : %.4f\n", R_ac);
}

void __dreieck_stern(float R_ab, float R_bc, float R_ac){
	printf("Dreieck -> Stern:\n");
	float R_a, R_b, R_c;
	R_a = (R_ac * R_ab) / (R_ab + R_bc + R_ac);
	R_b = (R_ab * R_bc) / (R_ab + R_bc + R_ac);
	R_c = (R_ac * R_bc) / (R_ab + R_bc + R_ac);
	printf("\tR_a : %.4f\n", R_a);
	printf("\tR_b : %.4f\n", R_b);
	printf("\tR_c : %.4f\n", R_c);
}

void __stern_dreieck_menue(void){
	printf("menue\n");
	return;
}