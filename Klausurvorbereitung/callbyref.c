#include <stdio.h>
#include <stdlib.h>


void make_array(int **p){
	*p = malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++){
		(*p)[i] = i;
	}
}

int main(void){
	int *pointer;


	make_array(&pointer);
	for (int i = 0; i < 10; i++){
		printf("%d\n", pointer[i]);
	}

	return 0;
}