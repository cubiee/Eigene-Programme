#include <stdio.h>
#include <string.h>



struct bitfeld_b{
	unsigned int bit1 : 2;
	unsigned int bit2 : 2;
	unsigned int bit3 : 2;
	unsigned int bit4 : 2;
	unsigned int bit5 : 2;
};

union MyUnion
{
	struct bitfeld_b b;
	unsigned int i;
};


void print_binary(unsigned int b){
	for (int i = 0; i < 32; i++){
		unsigned int mask = 1U << i;
		if ((b & mask) > 0){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
}


int main(void){
	union MyUnion test;

	test.b.bit1 = 0;
	test.b.bit2 = 0;
	test.b.bit3 = 0;
	test.b.bit4 = 0;
	test.b.bit5 = 0;
	print_binary(test.i);

	test.b.bit1 = 1;
	test.b.bit2 = 1;
	test.b.bit3 = 1;
	test.b.bit4 = 1;
	test.b.bit5 = 1;
	print_binary(test.i);


	return 0;
}