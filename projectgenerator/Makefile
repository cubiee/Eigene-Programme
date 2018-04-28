CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -c
OUTNAME = projectgen

all: compile clean

compile: main.o
	$(CC) -o $(OUTNAME) main.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean: 
	rm -f *.o