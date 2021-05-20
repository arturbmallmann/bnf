CC=gcc
CFLAGS= -c -Wall -lm

all: Example1 

Example1: engine.o Example1.o
	$(CC) engine.o Example1.o -o Example1.exec
Example1.o: Example1.c
	$(CC) $(CFLAGS) Example1.c
engine.o: engine.c
	$(CC) -c $(CFLAGS) engine.c
clean:
	rm -rf *.o *.exec
