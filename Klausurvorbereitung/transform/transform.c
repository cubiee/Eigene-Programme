#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transform.h"

void multiply(MATRIX mat, VECTOR vec, VECTOR *erg)
{
	(*erg)[0] = mat[0][0] * vec[0] + mat[0][1] * vec[1] + mat[0][2] * vec[2];

	(*erg)[1] = mat[1][0] * vec[0] + mat[1][1] * vec[1] + mat[1][2] * vec[2];

	(*erg)[2] = mat[2][0] * vec[0] + mat[2][1] * vec[1] + mat[2][2] * vec[2];
}


void readVectorData(FILE *datei, VECTOR *vec, int max)
{
	for (int i = 0; i < max; i++)
	{
		fscanf(datei, "%lf %lf %lf\n", &(vec[i][0]), &(vec[i][1]), &(vec[i][2]));
	}
}

void writeVectorData(FILE *datei, VECTOR vec)
{
	fprintf(datei, "%.3lf %.3lf %.3lf\n", vec[0], vec[1], vec[2]);
}

void printVector(VECTOR vec)
{
	printf("(%.3lf ; %.3lf ; %.3lf)\n", vec[0], vec[1], vec[2]);
}

