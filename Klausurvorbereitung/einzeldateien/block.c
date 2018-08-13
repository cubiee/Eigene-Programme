#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *data = fopen("data.dat", "w");
	for (int i = 0; i < 1000; i++){
		int buffer = i;
		fwrite(&buffer, sizeof(int), 1, data);
	}
	return 0;
}