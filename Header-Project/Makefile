PROGRAM = headerproj
OBJECTS = main.o 
#--------- ab hier nicht mehr ändern
HEADERPROJECT = stern-dreieck.o check-type.o string-case.o inputfunc.o
DEPENDFILE = .depend
CC=gcc
CFLAGS=-Wall -pedantic 

.PHONY: all
all: dep $(PROGRAM)

$(PROGRAM) : $(OBJECTS) $(HEADERPROJECT)
	$(CC) $(OBJECTS) $(HEADERPROJECT) -o $(PROGRAM)

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