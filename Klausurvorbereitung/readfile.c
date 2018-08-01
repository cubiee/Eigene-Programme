#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[]){
	if (argc == 2){
		FILE *datafile = fopen(argv[1], "r");
		int nmbr_of_datapoints = 0;
		float buffer;
		while (fscanf(datafile,"%f\n",&buffer) == 1){
			nmbr_of_datapoints++;
		}
		rewind(datafile);
		if (nmbr_of_datapoints > 0){
			printf("%d datensaetze gefunden\n", nmbr_of_datapoints);
			float sum;
			float mean;
			buffer = 0;
			for (int i = 0; i < nmbr_of_datapoints; i++){
				fscanf(datafile, "%f", &buffer);
				sum += buffer;
			}
			mean = sum / nmbr_of_datapoints;

			printf("Summe : %f\n", sum);
			printf("Mitte : %f\n", mean);
		}
		else{
			printf("Keine datensaetze gefunden\n");
		}
	}
	return 0;
}