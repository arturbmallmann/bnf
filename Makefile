CC=g++
CC_=gcc
CFLAGS= -c -Wall -lm

all: compiler lex #engine #gramma_slr_v1 #bnf

compiler: compiler.o 
	$(CC) compiler.o -o compiler.exec
compiler.o: compiler.cpp
	$(CC) $(CFLAGS) compiler.cpp

lex: re2c lex_an.o
	$(CC_) lex_an.o -o lex.exec
re2c:
	re2c lex_an.re -o lex_an.c
lex_an.o: lex_an.c
	$(CC_) $(CFLAGS) lex_an.c

#gramma_slr_v1: engine.o gramma_slr_v1.o
#	$(CC_) engine.o gramma_slr_v1.o -o compiler.exec
#engine.o: engine.c
#	$(CC_) -c $(CFLAGS) engine.c
#gramma_slr_v1.o: gramma_slr_v1.c
#	$(CC_) $(CFLAGS) gramma_slr_v1.c
	
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
