#ifndef ANALYSE_H
#define ANALYSE_H

#define TRUE  1
#define FALSE 0

typedef struct fileinfo_s FILEINFO;

struct fileinfo_s
{
	int zeilenanzahl;
	int uppercase[26];
	int lowercase[26];
	int numbers[10];
	int special;
	char mostUsedChar[33];
	int mostUsedValue;
};

int analyseFile(FILE *file, FILEINFO *info);

void printFileinfo(FILEINFO info);

#endif