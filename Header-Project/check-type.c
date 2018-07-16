#include "Stringfunc.h"
#include <ctype.h>
#include <string.h>
/*
Erweiterung der ctype.h lib auf ganze Strings
*/


/* Ueberpruefen ob String ein integer ist */
int check_if_int(char *str){
	int size = strlen(str);
	int status = 1;
	int i = 0;
	for (i = 0; (i < size) && (status == 1); i++){
		if (0 == isdigit(str[i])){
			if ((str[i] != '+') && (str[i] != '-')){
				status = 0;
			}
		}
	}
	return status;
}

/* Ueberpruefen ob String ein float ist */
int check_if_float(char *str){
	int size = strlen(str);
	int status = 1;
	int i = 0;
	for (i = 0; (i < size) && (status == 1); i++){
		if (0 == isdigit(str[i])){
			if ((str[i] != '+') && (str[i] != '-') && (str[i] != '.')){
				status = 0;
			}
		}
	}
	return status;
}

/* Ueberpruefen ob String nur aus Buchstaben besteht */
int check_if_alpha(char *str){
	int size = strlen(str);
	int status = 1;
	int i = 0;
	for (i = 0; (i < size) && (status == 1); i++){
		if (0 == isalpha(str[i])){
			if (str[i] != ' '){
				status = 0;
			}
		}
	}
	return status;
}

/* Ueberpruefen ob String nur aus Kleinbuchstaben besteht */
int check_if_lower_alpha(char *str){
	int size = strlen(str);
	int status = 1;
	int i = 0;
	for (i = 0; (i < size) && (status == 1); i++){
		if (0 == islower(str[i])){
			if (str[i] != ' '){
				status = 0;
			}
		}
	}
	return status;
}

/* Ueberpruefen ob String nur aus Grossbuchstaben besteht */
int check_if_upper_alpha(char *str){
	int size = strlen(str);
	int status = 1;
	int i = 0;
	for (i = 0; (i < size) && (status == 1); i++){
		if (0 == isupper(str[i])){
			if (str[i] != ' '){
				status = 0;
			}
		}
	}
	return status;
}