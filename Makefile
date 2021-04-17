CC=g++
CFLAGS= -c -Wall -lm

all: bnf

bnf: bnf.o 
	$(CC) bnf.o -o bnf.exec
bnf.o: bnf.cpp
	$(CC) $(CFLAGS) bnf.cpp
test:
	exec ./bnf.exec arquivo.txt
debug:
	CFLAGS=${CFLAGS} -g
	all	
clean:
	rm -rf *.o bnf.exec
