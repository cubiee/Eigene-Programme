#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUTBUFFERSIZE 500
#define NAMEBUFFERSIZE 50
#define MAXNMBRSTUDENTS 600
#define TRUE 1
#define FALSE 0

typedef struct name_s{
	char vorname[NAMEBUFFERSIZE];
	char nachname[NAMEBUFFERSIZE];
}NAME;

typedef struct student_s{
	NAME name;
	float note;
}STUDENT;

STUDENT new_default_student(void);
void read_new_student(STUDENT *buffer);

int read_string(char *buffer, int max_size, char *prompt);
int read_float(float *buffer, float min, float max, char *prompt);
int read_int(int *buffer, int min, int max, char *prompt);

int main(void){
	int studentenanzahl;
	while (!read_int(&studentenanzahl, 1, MAXNMBRSTUDENTS, "Bitte Studentenanzahl eingeben: ")){
		printf("Ungueltige Eingabe!\n");
	}

	STUDENT *studentendaten = malloc(studentenanzahl * sizeof(STUDENT));

	if (NULL == studentendaten){
		printf("Speicherallokation fehlgeschlagen!\n");
	}
	else{
		int i = 0;
		for (i = 0; i < studentenanzahl; i++){
			studentendaten[i] = new_default_student();
		}
		for (i = 0; i < studentenanzahl; i++){
			read_new_student(&(studentendaten[i]));
		}

		float beste_note = studentendaten[0].note;
		for (i = 0; i < studentenanzahl; i++){
			if (beste_note > studentendaten[i].note){
				beste_note = studentendaten[i].note;
			}
		}

		for (i = 0; i < studentenanzahl; i++){
			if (beste_note == studentendaten[i].note){
				printf("Name: %s %s\n", studentendaten[i].name.vorname, studentendaten[i].name.nachname);
				printf("Note: %.1f\n", studentendaten[i].note);
			}
		}
	}
	return 0;
}

STUDENT new_default_student(void){
	STUDENT neu;
	neu.note = 0.0f;
	memset(&(neu.name.vorname), '\0', NAMEBUFFERSIZE);
	memset(&(neu.name.nachname), '\0', NAMEBUFFERSIZE);
	return neu;
}

void read_new_student(STUDENT *buffer){
	printf("Neuer Student:\n");
	while (!read_string(buffer->name.vorname, NAMEBUFFERSIZE - 1, "Bitte Vorname eingeben: ")){
		printf("Ungueltige Eingabe!\n");
	}
	while (!read_string(buffer->name.nachname, NAMEBUFFERSIZE - 1, "Bitte Nachname eingeben: ")){
		printf("Ungueltige Eingabe!\n");
	}
	while (!read_float(&(buffer->note), 1.0f, 5.0f, "Bitte Note eingeben: ")){
		printf("Ungueltige Eingabe!\n");
	}
}

int read_string(char *buffer, int max_size, char *prompt){
	printf(prompt);
	int status;
	char inputbuffer[INPUTBUFFERSIZE];
	fgets(inputbuffer, INPUTBUFFERSIZE, stdin);
	inputbuffer[strcspn(inputbuffer, "\n")] = '\0';
	if (0 == strlen(inputbuffer)){
		status = FALSE;
	}
	else{
		int whitespace = 0;
		for (int i = 0; i < strlen(inputbuffer); i++){
			if (inputbuffer[i] == ' '){
				whitespace++;
			}
			if (whitespace == strlen(inputbuffer)){
				status = FALSE;
			}
			else{
				strncpy(buffer, inputbuffer, max_size);
				status = TRUE;
			}
		}
	}
	return status;
}

int read_float(float *buffer, float min, float max, char *prompt){
	if (min > max){
		float buffer = 0.0f;
		buffer = min;
		min = max;
		max = buffer;
	}

	int status;
	float number;
	char inputbuffer[INPUTBUFFERSIZE];
	char suchstring[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!\"'$%&'()*,/:;<=>?@[\\]^_`{|}~ "
	};

	printf(prompt);
	fgets(inputbuffer, INPUTBUFFERSIZE, stdin);
	inputbuffer[strcspn(inputbuffer, "\n")] = '\0';
	if ((NULL != strpbrk(inputbuffer, suchstring)) || (0 == strlen(inputbuffer))){
		status = FALSE;
	}
	else{
		number = atof(inputbuffer);
		if (number > max || number < min){
			status = FALSE;
		}
		else{
			*buffer = number;
			status = TRUE;
		}
	}
	return status;
}

int read_int(int *buffer, int min, int max, char *prompt){
	if (min > max){
		int buffer = 0;
		buffer = min;
		min = max;
		max = buffer;
	}

	int status;
	int number;
	char inputbuffer[INPUTBUFFERSIZE];
	char suchstring[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!\"'$%&'()*,./:;<=>?@[\\]^_`{|}~ "
	};

	printf(prompt);
	fgets(inputbuffer, INPUTBUFFERSIZE, stdin);
	inputbuffer[strcspn(inputbuffer, "\n")] = '\0';
	if ((NULL != strpbrk(inputbuffer, suchstring)) || (0 == strlen(inputbuffer))){
		status = FALSE;
	}
	else{
		number = atoi(inputbuffer);
		if (number > max || number < min){
			status = FALSE;
		}
		else{
			*buffer = number;
			status = TRUE;
		}
	}
	return status;
}
