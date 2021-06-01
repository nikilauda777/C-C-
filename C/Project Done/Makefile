CC=gcc
CFLAGS=-I.
DEPS = randomtrip.h


%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Programm: programm.o randomtrip.o 
	$(CC) -o programm programm.o randomtrip.o



programm : programm.c randomtrip.c
	gcc -o programm programm.c randomtrip.c -I