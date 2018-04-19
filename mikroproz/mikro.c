#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printBits(size_t const size, void const * const ptr);


int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Fehlende Arugumente\n ./prog <format> <zahl>\n");
		return 0;
	}
	
	if (strcmp("-i", argv[1]) == 0){
		int input = atoi(argv[2]);
		printf("Integer = \t%i\nHexwert = \t0x%x \nBinaer = \t",input,input);
		printBits(sizeof(input), &input);
	}

	if (strcmp("-f", argv[1]) == 0){
		float input = atof(argv[2]);
		printf("Float = \t%f\nHexwert = \t0x%x \nBinaer = \t", input, input);
		printBits(sizeof(input), &input);
	}

	return 0;
}


void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*)ptr;
	unsigned char byte;
	int i, j;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 7; j >= 0; j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}