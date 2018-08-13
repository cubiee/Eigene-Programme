#include <stdio.h>
#include "projectgen.h"


int main(int argc, char *argv[]){
	if (argc < 2){
		menue();
	}
	else{
		if (argc > 2){
			generate_makefile(argv[1], &(argv[2]), argc - 2);
			generate_main(argv[1], &(argv[2]), argc - 2);
			generate_header(argv[1]);
			for (int i = 2; i < argc; i++){
				generate_header(argv[i]);
			}
		}
		else{
			generate_makefile(argv[1], NULL, 0);
			generate_main(argv[1], NULL, 0);
			generate_header(argv[1]);
		}
	}
	return 0;
}



 