CC=gcc
CFLAGS=-I.
DEPS = handler.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Programm: programm.o handler.o 
	$(CC) -o programm programm.o handler.o



programm : programm.c handler.c
	gcc -o programm programm.c handler.c -I