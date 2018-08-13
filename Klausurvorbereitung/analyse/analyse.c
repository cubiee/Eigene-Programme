#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "analyse.h"

int analyseFile(FILE *file, FILEINFO *info)
{
	int status = TRUE;
	if (NULL == file)
	{
		status = FALSE;
	}
	else
	{
		int buffer = 'a';
		int index = 0;
		int i = 0;

		info->zeilenanzahl = 0;
		memset(info->numbers, 0, 10 * sizeof(int));
		memset(info->uppercase, 0, 26 * sizeof(int));
		memset(info->lowercase, 0, 26 * sizeof(int));
		info->special = 0;
		memset(info->mostUsedChar, '\0', 32*sizeof(char));

		
		while ((buffer = getc(file)) != EOF)
		{
			//buchstaben vorkommen testen
			if (isalpha(buffer))
			{
				if (isupper(buffer))
				{
					index = buffer - 'A';
					(info->uppercase[index])++;
				}
				else if (islower(buffer))
				{
					index = buffer - 'a';
					(info->lowercase[index])++;
				}
			}
			else if (isdigit(buffer))
			{
				index = buffer - '0';
				(info->numbers[index])++;
			}
			else if ('\n' == buffer)
			{
				info->zeilenanzahl++;
				info->special++;
			}
			else
			{
				info->special++;
			}
		}
		//meistvorkommende buchstaben finden
		int mostUsedValue = 0; // haufigkeit des vorkommenden buchstaben
		char mostUsedChar[32]; // array in dem die chars gespeichert sind
		int mostUsedIndex = 0;
		memset(mostUsedChar, '\0', 33 * sizeof(char));

		mostUsedValue = info->uppercase[0];
		for (i = 0; i < 26; i++){
			if (info->uppercase[i] > mostUsedValue)
			{
				mostUsedValue = info->uppercase[i];
			}
		}
		for (i = 0; i < 26; i++){
			if (info->lowercase[i] > mostUsedValue)
			{
				mostUsedValue = info->lowercase[i];
			}
		}

		for (i = 0; i < 26; i++){
			if (info->uppercase[i] == mostUsedValue)
			{
				mostUsedChar[mostUsedIndex] = i + 'A';
				mostUsedIndex++;
			}
		}

		for (i = 0; i < 26; i++){
			if (info->lowercase[i] == mostUsedValue)
			{
				mostUsedChar[mostUsedIndex] = i + 'a';
				mostUsedIndex++;
			}
		}
		strncpy(info->mostUsedChar, mostUsedChar, mostUsedIndex + 1);
		info->mostUsedValue = mostUsedValue;
		rewind(file);
	}
	return status;
}

void printFileinfo(FILEINFO info)
{
	for (int i = 0; i < 26; i++)
	{
		printf("%c ", 'A' + i);
	}
	printf("\n");
	for (int i = 0; i < 26; i++)
	{
		printf("%i ", info.uppercase[i]);
	}
	printf("\n");
	printf("\n");

	for (int i = 0; i < 26; i++)
	{
		printf("%c ", 'a' + i);
	}
	printf("\n");
	for (int i = 0; i < 26; i++)
	{
		printf("%i ", info.lowercase[i]);
	}
	printf("\n");
	printf("\n");

	printf("Special Chars: %i\n", info.special);
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%i ", i);
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%i ", info.numbers[i]);
	}
	printf("\n");
	printf("\n");
	printf("Meistvorkommende character: %s\n", info.mostUsedChar);
	printf("Haufigkeit des meisten Zeichen: %d\n", info.mostUsedValue);
	printf("Zeilenanzahl: %i\n", info.zeilenanzahl);
}