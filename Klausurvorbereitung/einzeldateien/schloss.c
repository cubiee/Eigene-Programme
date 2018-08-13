#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int* abb;
unsigned int versuche = 0;

void generate(void);
int test(unsigned int);
char * toBin(unsigned int);


void setbit(unsigned int *key, int bit);
void clearbit(unsigned int *key, int bit);

int main(void)
{
	generate();
	unsigned int key = 0;
	/* Ab hier kannst du versuchen die Tür mit deinem Schlüssel zu knacken.
	Verändere die Variable "Key" mit den dir bekannten bitweisen Operatoren,
	die du in der Vorlesung kennengelernt hast.
	Du kannst deinen Schlüssel dann mit der Funktion test() überprüfen,
	welcher als Parameter übergeben wird.
	Bitte beachte, dass sowohl Schlüssel als auch Schloss unsigned Integer sind.
	*/
	int rightbits;
	for (int i = 0; i < 32; i++){
		rightbits = test(key);
		setbit(&key, i);
		if (rightbits > test(key)){
			clearbit(&key, i);
		}
	}
	return 0;
}

void setbit(unsigned int *key, int bit){
	unsigned int bitmask = 1U << bit;
	*key = *key | bitmask;
}


void clearbit(unsigned int *key, int bit){
	unsigned int bitmask = ~(1U << bit);
	*key = *key & bitmask;
}


/* Diese Funktion liefert die Anzahl der richtigen Bits des übergebenen Schlüssels zurück.
Falls 32 zurückgeliefert wird, war der Schlüssel richtig und die Tür öffnet sich.
*/
int test(unsigned int toTest)
{
	int rightBits = 0;
	int i = 0;
	for (; i< 32; i++){
		unsigned int x = 1 << i;
		if (!~((toTest & x) ^ (*abb | ~x))){
			rightBits++;
		}
	}
	if (rightBits == 32){
		printf("\nGratulation !\n\n");
		printf("Die Tuer ist offen.\n");
		printf("So sahen Schluessel und Schloss aus \n");
		printf("Schloss    : %32s \n", toBin(*abb));
		printf("Schluessel : %32s \n", toBin(~*abb));
		exit(0);
	}
	else{
		printf("%d . Versuch, %d richtige Bits \n", ++versuche, rightBits);
		return rightBits;
	}
}

/*Hier wird das zufällige Schloss generiert. Bitte nicht veraendern sonst geht der Spaß verloren. */
void generate(void)
{
	printf("\nSchloss wurde erstellt.\nViel Spass beim probieren.\n\n");
	unsigned int secret;
	abb = (unsigned int*)malloc(sizeof(unsigned int));
	srand(time(NULL));
	secret = rand();
	*abb = secret;
}

/*Konvertierungsfunktion zur Ausgabe der Binaerrepraesentation einer Zahl*/
char * toBin(unsigned int num)
{
	static char retbuf[33];
	int i = 0;
	for (; i<33; i++){
		retbuf[i] = '0';
	}
	char *p;
	p = &retbuf[sizeof(retbuf)-1];
	*p = '\0';
	do {
		*--p = "0123456789abcdef"[num % 2];
		num /= 2;
	} while (num != 0);
	return retbuf;
}