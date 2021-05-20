CC=g++
CFLAGS= -c -Wall -lm

all: compiler lex #bnf

compiler: compiler.o 
	$(CC) compiler.o -o compiler.exec
compiler.o: compiler.cpp
	$(CC) $(CFLAGS) compiler.cpp

lex: re2c lex_an.o
	$(CC) lex_an.o -o lex.exec
re2c:
	re2c lex_an.re -o lex_an.c
lex_an.o: lex_an.c
	$(CC) $(CFLAGS) lex_an.c
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
	rm -rf *.o *.exec
