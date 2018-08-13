#ifndef TRANSFORM_H
#define TRANSFORM_H

#define ISOMETRIC { { 0.866, 0, -0.866 }, { -0.5, 1, -0.5 }, { 0, 0, 0 } }


typedef double VECTOR[3];
typedef double MATRIX[3][3];


void multiply(MATRIX mat, VECTOR vec, VECTOR *erg);

void readVectorData(FILE *datei, VECTOR *vec, int max);
void writeVectorData(FILE *datei, VECTOR vec);

void printVector(VECTOR vec);

#endif