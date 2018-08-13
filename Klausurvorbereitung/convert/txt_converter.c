#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFERSIZE 400

void write_string_to_file(FILE *file, char *str);

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("zu wenige argumente!\n");
	}
	else{
		FILE *text = fopen(argv[1], "r");
		char filename[BUFFERSIZE] = { '\0' };
		sprintf(filename, "%s.txt", argv[1]);
		FILE *convert = fopen(filename, "w");
		if (NULL == text || NULL == convert){
			printf("konnte datei nicht oeffnen!\n");
		}
		else{
			char puffer[BUFFERSIZE] = { '\0' };
			fprintf(convert, "char %s[] = {\n", argv[1]);
			while (NULL != fgets(puffer, BUFFERSIZE, text)){
				fprintf(convert, "\t\"");
				write_string_to_file(convert, puffer);
				fprintf(convert, "\"\n");
			}
			fprintf(convert, "};\n");
		}
	}
	return 0;
}

void write_string_to_file(FILE *file, char *str){
	int stringsize = strlen(str);
	for (int i = 0; i < stringsize; i++){
		if (str[i] == '\n'){
			fputc('\\', file);
			fputc('n', file);
		}
		else if (str[i] == '\t'){
			fputc('\\', file);
			fputc('t', file);
		}
		else if (str[i] == '\\'){
			fputc('\\', file);
			fputc('\\', file);
		}
		else if (str[i] == '\''){
			fputc('\\', file);
			fputc('\'', file);
		}
		else if (str[i] == '\?'){
			fputc('\\', file);
			fputc('\?', file);
		}
		else if (str[i] == '%'){
			fputc('%', file);
			fputc('%', file);
		}
		else{
			fputc(str[i], file);
		}
	}
	return;
}