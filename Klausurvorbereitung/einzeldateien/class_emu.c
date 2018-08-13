#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct name_s NAME;

struct name_s{
	char vorname[100];
	char nachname[100];
};

typedef struct person_s PERSON;

struct person_s{
	int alter;
	NAME name;
	void(*vorstellen)(PERSON *self);
};

void print(PERSON *self){
	printf("Name: %s %s\n", self->name.vorname, self->name.nachname);
	printf("Alter: %d\n", self->alter);
}

PERSON create_new_person(void){
	PERSON neu;
	neu.vorstellen = print;
	neu.alter = 0;
	memset(&(neu.name.vorname), '\0', 100);
	memset(&(neu.name.nachname), '\0', 100);
	return neu;
}

int main(void){
	PERSON test = create_new_person();
	test.alter = 22;
	strcpy(test.name.vorname, "Joshua");
	strcpy(test.name.nachname, "Harig");
	test.vorstellen(&test);
	return 0;
}