#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 100000000

int compare(const void *a, const void *b){
	return *((int*)a) - *((int*)b);
}

int main(void){
	time_t tm;
	time(&tm);
	srand(tm);
	clock_t start, stop;

	start = clock();
	int *arr = malloc(ARRSIZE * sizeof(int));
	for (int i = 0; i < ARRSIZE; i++){
		arr[i] = rand();
	}
	stop = clock();
	printf("Initialisierung in s %f\n", ((float)(stop - start)) / CLOCKS_PER_SEC);
	



	start = clock();
	qsort(arr, ARRSIZE, sizeof(int), compare);
	stop = clock();
	printf("Sortierung in s %f\n", ((float)(stop - start)) / CLOCKS_PER_SEC);

	return 0;
}


