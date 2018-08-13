#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MINUTES 5


int get_temp(float *t);

int main(void){
	float temp = 0;
	FILE *csv = fopen("data.csv", "w");
	if (NULL == csv){
		return 1;
	}
	else{
		time_t t, start;
		struct tm *tm_now;
		time(&start);

		char str[40];
		int i = 0, j = 0;

		int stop = 0;
		while (!stop){
			time(&t);
			tm_now = localtime(&t);
			
			if ((t - start) > MINUTES * 60){
				stop = 1;
			}
			else{
				if (60 == i){
					j++;
					i = 0;
					printf("Minute %d vorbei\n", j);
				}
				memset(str, '\0', 40);
				strftime(str, 40, "%H:%M:%S ", tm_now);
				strcat(str, "%f\n");
				get_temp(&temp);
				fprintf(csv, str, temp);
				i++;
				sleep(1);
			}
		}
		return 0;
	}
}

int get_temp(float *t){
	FILE *temp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
	if (NULL == temp){
		fclose(temp);
		return 0;
	}
	else{
		char buffer[20];
		fgets(buffer, 20, temp);
		float temperatur = atof(buffer);
		temperatur /= 1000;
		*t = temperatur;
		fclose(temp);
		return 1;
	}
}