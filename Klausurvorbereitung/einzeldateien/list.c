#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000000

int compare(const void *a, const void *b){
	return *((int *)a) - *((int*)b);
}


int main(void){
	time_t tnow;
	time(&tnow);
	srand(tnow);
	
	int my_array[SIZE];

	int i;
	for (i = 0; i < 100; i++) {
		my_array[i] = rand();
	}
	/*
	clock_t start = clock();
	qsort(arr, SIZE, sizeof(int), compare);
	clock_t end = clock();
	
	printf("%ld", end - start);
	*/
	return 0;
}