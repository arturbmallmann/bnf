CC = g++
CFLAGS = -g -Wall -Wno-deprecated

main: bnf.o
 $(CC) $(CFLAGS) $< -o $@

bnf.o: bnf.cpp
 $(CC) $(CFLAGS) -c $<

test: 
	./main
