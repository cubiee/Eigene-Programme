#ifndef VERWALTUNG_H
#define VERWALTUNG_H

#define NAMEBUFFERSIZE 30
#define GRUNDGEHALT 1000


typedef struct datum_s{
	int tag;
	int monat;
	int jahr;
}DATUM;

typedef struct name_s{
	char vorname[NAMEBUFFERSIZE];
	char nachname[NAMEBUFFERSIZE];
}NAME;

typedef struct mitarbeiter_s{
	NAME name;
	DATUM einstelldatum;
	int gehalt;
}MITARBEITER;

MITARBEITER new_mitarbeiter_default(void);
MITARBEITER new_mitarbeiter(void);


#endif