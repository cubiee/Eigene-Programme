#include "verwaltung.h"
#include "get_usr_data.h"

#include <stdio.h>


int main(void){
	MITARBEITER test = new_mitarbeiter();

	printf("\n\nVorname: %s\n", test.name.vorname);
	printf("Nachname: %s\n", test.name.nachname);
	printf("Einstelldatum: %d.%d.%d\n", test.einstelldatum.tag, test.einstelldatum.monat, test.einstelldatum.jahr);
	printf("Gehalt: %d\n", test.gehalt);
	return 0;
}
