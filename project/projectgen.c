#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "projectgen.h"
#include "makefile.txt"

int generate_makefile(char *name, char **header, int headeranzahl){
	FILE *makef = fopen("Makefile", "w");
	if (NULL == makef){
		return 0;
	}

	char objects[400] = { '\0' };

	if (0 != headeranzahl){
		strcat(objects, "main.o ");
		for (int i = 0; i < headeranzahl; i++){
			strcat(objects, header[i]);
			strcat(objects, ".o ");
		}
		fprintf(makef, makefile, name, objects);
		fclose(makef);
		return 1;
	}
	else{
		strcat(objects, "main.o");
		fprintf(makef, makefile, name, objects);
		fclose(makef);
		return 1;
	}
}

int generate_main(char *name, char **header, int headeranzahl){
	FILE *mainfile = fopen("main.c", "w");
	if (NULL == mainfile){
		return 0;
	}
	else{
		fprintf(mainfile, "#include <stdio.h>\n");
		fprintf(mainfile, "#include <stdlib.h>\n");
		fprintf(mainfile, "#include <string.h>\n");
		fprintf(mainfile, "\n");
		fprintf(mainfile, "#include \"%s.h\"\n", name);
		if (0 != headeranzahl){
			for (int i = 0; i < headeranzahl; i++){
				fprintf(mainfile, "#include \"%s.h\"\n", header[i]);
			}
		}
		fprintf(mainfile, "\n\n\n");
		fprintf(mainfile, "int main(int argc, char *argv[]){\n");
		fprintf(mainfile, "\t\n\t/*code*/\n\t\n\treturn 0;\n}\n");
		fclose(mainfile);
		return 1;
	}
}

int generate_header(char *name){
	char headername_doth[100] = { '\0' };
	char headername_dotc[100] = { '\0' };

	strcat(headername_doth, name);
	strcat(headername_doth, ".h");
	strcat(headername_dotc, name);
	strcat(headername_dotc, ".c");

	FILE *headerfile_doth = fopen(headername_doth, "w");
	FILE *headerfile_dotc = fopen(headername_dotc, "w");

	if (NULL == headerfile_doth || NULL == headerfile_dotc){
		return 0;
	}
	else{
		fprintf(headerfile_dotc, "#include <stdio.h>\n");
		fprintf(headerfile_dotc, "#include <stdlib.h>\n");
		fprintf(headerfile_dotc, "#include <string.h>\n");
		fprintf(headerfile_dotc, "#include \"%s\"\n", headername_doth);

		int i = 0;
		for (i = 0; i < strlen(headername_doth); i++){
			if (headername_doth[i] == '.'){
				headername_doth[i] = '_';
			}
			else{
				headername_doth[i] = toupper(headername_doth[i]);
			}
		}

		fprintf(headerfile_doth, "#ifndef %s\n", headername_doth);
		fprintf(headerfile_doth, "#define %s\n\n\n", headername_doth);
		fprintf(headerfile_doth, "#endif");

		fclose(headerfile_dotc);
		fclose(headerfile_doth);
		return 1;
	}
}

void menue(void){
	printf("./projectgen <projectname> <header> <header> ...\n");
}