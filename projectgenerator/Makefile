CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -c
OUTNAME = projectgen
OBJ = main.o projectgen_std_func.o standard_mode.o

all: compile clean

compile: $(OBJ)
	$(CC) -o $(OUTNAME) $(OBJ)

main.o: main.c standard_mode.h
	$(CC) $(CFLAGS) main.c

projectgen_std_func.o: projectgen_std_func.c projectgen_std_func.h
	$(CC) $(CFLAGS) projectgen_std_func.c

standard_mode.o: standard_mode.c standard_mode.h var_defines.h
	$(CC) $(CFLAGS) standard_mode.c

clean: 
	rm -f *.o