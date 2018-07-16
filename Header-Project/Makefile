PROGRAM = headerproj
OBJECTS = main.o stern-dreieck.o check-type.o string-case.o inputfunc.o
#--------- ab hier nicht mehr ändern
DEPENDFILE = .depend
CC=gcc
CFLAGS=-Wall -pedantic 

.PHONY: all
all: dep $(PROGRAM)

$(PROGRAM) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: dep
dep: *.c
	gcc -MM *.c > $(DEPENDFILE)

-include $(DEPENDFILE)

.PHONY: clean
clean:
	rm  -rf *.o
	rm  -rf .depend