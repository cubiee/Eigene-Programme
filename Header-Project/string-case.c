#include "Stringfunc.h"
#include <ctype.h>
#include <string.h>
/*
Erweiterung der ctype.h lib auf ganze Strings
*/

/* Setzt alle Grossbuchstaben in str auf Kleinbuchstaben non alphabetic wird ignoriert */
int string_to_lowercase(char *str){
	int size = strlen(str);
	int status = 0;
	int i = 0;
	for (i = 0; i < size; i++){
		str[i] = tolower(str[i]);
	}
	return status;
}

/* Setzt alle Kleinbuchstaben in str auf Grossbuchstaben non alphabetic wird ignoriert */
int string_to_uppercase(char *str){
	int size = strlen(str);
	int status = 0;
	int i = 0;
	for (i = 0; i < size; i++){
		str[i] = toupper(str[i]);
	}
	return status;
}