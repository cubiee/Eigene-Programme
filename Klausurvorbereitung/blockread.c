#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *data = fopen("data.dat", "r");
	int buffer;
	for (int i = 0; i < 1000; i++){
		fread(&buffer, sizeof(int), 1, data);
		printf("%d\n", buffer);
	}
	return 0;
}