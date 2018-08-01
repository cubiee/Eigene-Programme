#include "verwaltung.h"
#include "get_usr_data.h"
#include <stdio.h>
#include <string.h>

MITARBEITER new_mitarbeiter_default(void){
	MITARBEITER neu;
	
	neu.einstelldatum.tag = 1;
	neu.einstelldatum.monat = 1;
	neu.einstelldatum.jahr = 1900;

	memset(&(neu.name.vorname), '\0', NAMEBUFFERSIZE);
	memset(&(neu.name.nachname), '\0', NAMEBUFFERSIZE);

	neu.gehalt = GRUNDGEHALT;
	return neu;
}

MITARBEITER new_mitarbeiter(void){
	MITARBEITER neu = new_mitarbeiter_default();
	while (!get_usr_string(neu.name.vorname, NAMEBUFFERSIZE, "Vorname bitte: ")){
		printf("Ungueltige eingabe!\n");
	}
	while (!get_usr_string(neu.name.nachname, NAMEBUFFERSIZE, "Nachname bitte: ")){
		printf("Ungueltige eingabe!\n");
	}
	while (!get_usr_int(&(neu.einstelldatum.tag), 1, 31, "Einstelltag bitte: ")){
		printf("Ungueltige eingabe!\n");
	}
	while (!get_usr_int(&(neu.einstelldatum.monat), 1, 12, "Einstellmonat bitte: ")){
		printf("Ungueltige eingabe!\n");
	}
	while (!get_usr_int(&(neu.einstelldatum.jahr), 1900, 2100, "Einstelltag bitte: ")){
		printf("Ungueltige eingabe!\n");
	}
	while (!get_usr_int(&(neu.gehalt), GRUNDGEHALT, GRUNDGEHALT + 1000, "Gehalt bitte: ")){
		printf("Ungueltige eingabe!\n");
	}
	return neu;
}