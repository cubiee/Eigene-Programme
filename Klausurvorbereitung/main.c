#include <stdio.h>
#include <stdarg.h>


double average(char *test, int num, ...);

int main(void){
	printf("Average of 2, 3, 4, 5 = %f\n", average("hallo",4, 2, 3, 4, 5));
	printf("Average of 5, 10, 15 = %f\n", average("hallo", 3, 5, 10, 15));
	return 0;
}


double average(char *test, int num, ...){
	printf(test);
	va_list valist;
	double sum = 0.0;
	int i = 0;

	va_start(valist, num);

	for (i = 0; i < num; i++) {
		sum += va_arg(valist, int);
	}

	va_end(valist);

	return sum / num;
}