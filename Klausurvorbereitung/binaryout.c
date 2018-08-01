#include <stdio.h>

union bfloat{
	float f;
	unsigned int u;
};


int main(void){
	union bfloat zahl;
	zahl.f = 3.1415f;

	for (int i = (sizeof(float)* 8) - 1; i >= 0; i--){
		if ((zahl.u & (1U << i)) > 0){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
	printf("%f\n", zahl.f);
}