#include <stdio.h>

#include "myheader.h"

int main(int argc, char *argv[]){
	if (check_if_alpha(argv[1])){
		printf("alphabetic\n");
		if (check_if_lower_alpha(argv[1])){
			printf("only lower\n");
		}
		else if (check_if_upper_alpha(argv[1])){
			printf("only upper\n");
		}
		else{
			printf("mixed\n");
		}
	}
	else{
		printf("not alphabetic\n");
	}

	float test;
	while (!get_usr_float("Bitte float eingeben:", 10.0f, 20.0f, &test)){
		printf("Ungueltige eingabe!\n");
	}
	printf("Eingabe: %f\n", test);
	return 0;
}