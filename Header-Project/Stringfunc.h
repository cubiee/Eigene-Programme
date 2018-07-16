#ifndef STRINGFUNC_H
#define STRINGFUNC_H
/*
Erweiterung der ctype.h lib auf ganze Strings
*/

/* Ueberpruefen ob String ein integer ist */
int check_if_int(char *str);

/* Ueberpruefen ob String ein float ist */
int check_if_float(char *str);

/* Ueberpruefen ob String nur aus Buchstaben besteht */
int check_if_alpha(char *str);

/* Ueberpruefen ob String nur aus Kleinbuchstaben besteht */
int check_if_lower_alpha(char *str);

/* Ueberpruefen ob String nur aus Grossbuchstaben besteht */
int check_if_upper_alpha(char *str);

/* Setzt alle Grossbuchstaben in str auf Kleinbuchstaben non alphabetic wird ignoriert */
int string_to_lowercase(char *str);

/* Setzt alle Kleinbuchstaben in str auf Grossbuchstaben non alphabetic wird ignoriert */
int string_to_uppercase(char *str);

#endif