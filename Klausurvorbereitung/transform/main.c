#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "transform.h"

#define NMBROFVECTORS 100

int main(int argc, char *argv[])
{
	if (argc == 300)
	{
		printf("not enough arguments!\n");
	}
	else
	{
		FILE *outputFile = fopen("transformed.csv", "w");
		FILE *inputFile = fopen("circle.csv", "r");
		if ((NULL == inputFile) || (NULL == outputFile))
		{
			printf("error opening file!\n");
		}
		else
		{
			MATRIX transformMatrix = ISOMETRIC;

			VECTOR *input = calloc(NMBROFVECTORS , sizeof(VECTOR));
			VECTOR *output = calloc(NMBROFVECTORS , sizeof(VECTOR));

			for (int i = 0; i < NMBROFVECTORS; i++)
			{
				fscanf(inputFile, "%lf %lf", &(input[i][0]), &(input[i][1]));
				input[i][2] = 0;
			}

			for (int i = 0; i < NMBROFVECTORS; i++)
			{
				multiply(transformMatrix, input[i], &output[i]);
			}

			for (int i = 0; i < NMBROFVECTORS; i++)
			{
				writeVectorData(outputFile, output[i]);
			}
		}
	}
	return 0;
}
