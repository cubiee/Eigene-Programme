#include <stdio.h>
#include <stdio.h>
#include <ctype.h>

#define KEY(k) ((k)%26)




int main(void){
	int key = 10;
	FILE *klartext = fopen("klartext.txt", "r");
	FILE *chiffre = fopen("chiffre.txt", "w");
	if ((NULL == klartext) || (NULL == chiffre)){
		return 1;
	}

	fseek(klartext, 0, SEEK_END);
	int filesize = ftell(klartext);
	rewind(klartext);

	char buffer;
	for (int i = 0; i < filesize; i++){
		buffer = fgetc(klartext);
		if (0 != isupper(buffer)){
			fputc(((buffer - 'A') + KEY(key)) % 26 + 'A', chiffre);
		}
		else if (0 != islower(buffer)){
			fputc(((buffer - 'a') + KEY(key)) % 26 + 'a', chiffre);
		}
		else{
			fputc(buffer, chiffre);
		}
	}
	return 0;
}
