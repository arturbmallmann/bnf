/* Generated by re2c 2.0.3 on Thu May 20 01:27:51 2021 */
#line 1 "lex_an.re"
#include "lex_an.h"

void write_ts(const char * ident, char * label, int line, TS * ts,int value){
	entries_t entrie;
	strcpy(entrie.ident, ident);
	strcpy(entrie.label, label);
	entrie.line = line;
	entrie.value = value;
	ts->entries[ts->qnt_entries++] = entrie;
}

static int lex(const char *YYCURSOR, const int line, TS * ts)
{
//	fprintf(stderr,"%s\n",YYCURSOR);
//	const char *YYMARKER;
	const char * saved = YYCURSOR;
    loop:
		saved = YYCURSOR;
    
#line 23 "lex_an.c"
{
	char yych;
	yych = *YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy2;
	case '"':	goto yy6;
	case '(':	goto yy8;
	case ')':	goto yy10;
	case '.':	goto yy12;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy14;
	case ';':	goto yy17;
	case '=':	goto yy19;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'g':
	case 'h':
	case 'j':
	case 'k':
	case 'm':
	case 'n':
	case 'o':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy21;
	case 'e':	goto yy24;
	case 'f':	goto yy25;
	case 'i':	goto yy26;
	case 'l':	goto yy27;
	case 'p':	goto yy28;
	case '{':	goto yy29;
	case '}':	goto yy31;
	default:	goto yy4;
	}
yy2:
	++YYCURSOR;
#line 45 "lex_an.re"
	{ return 0; }
#line 105 "lex_an.c"
yy4:
	++YYCURSOR;
#line 65 "lex_an.re"
	{write_ts(saved,"ERR", line, ts,0); return 0;}
#line 110 "lex_an.c"
yy6:
	yych = *++YYCURSOR;
	switch (yych) {
	case '"':	goto yy33;
	default:	goto yy6;
	}
yy8:
	++YYCURSOR;
#line 58 "lex_an.re"
	{write_ts(saved,"(", line, ts,0); goto loop;}
#line 121 "lex_an.c"
yy10:
	++YYCURSOR;
#line 59 "lex_an.re"
	{write_ts(saved,")", line, ts,0); goto loop;}
#line 126 "lex_an.c"
yy12:
	++YYCURSOR;
#line 62 "lex_an.re"
	{write_ts(saved,".", line, ts,0); goto loop;}
#line 131 "lex_an.c"
yy14:
	yych = *++YYCURSOR;
	switch (yych) {
	case '.':	goto yy35;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy14;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy37;
	default:	goto yy16;
	}
yy16:
#line 53 "lex_an.re"
	{
			write_ts(saved,"NUM", line, ts,atoi(saved));
			goto loop;}
#line 206 "lex_an.c"
yy17:
	++YYCURSOR;
#line 61 "lex_an.re"
	{write_ts(saved,";", line, ts,0); goto loop;}
#line 211 "lex_an.c"
yy19:
	++YYCURSOR;
#line 60 "lex_an.re"
	{write_ts(saved,"=", line, ts,0); goto loop;}
#line 216 "lex_an.c"
yy21:
	yych = *++YYCURSOR;
yy22:
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy21;
	default:	goto yy23;
	}
yy23:
#line 52 "lex_an.re"
	{write_ts(saved,"ID", line, ts,0); goto loop;}
#line 289 "lex_an.c"
yy24:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'l':	goto yy39;
	default:	goto yy22;
	}
yy25:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'u':	goto yy40;
	default:	goto yy22;
	}
yy26:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':	goto yy41;
	default:	goto yy22;
	}
yy27:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'o':	goto yy43;
	default:	goto yy22;
	}
yy28:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'r':	goto yy44;
	default:	goto yy22;
	}
yy29:
	++YYCURSOR;
#line 56 "lex_an.re"
	{write_ts(saved,"{", line, ts,0); goto loop;}
#line 324 "lex_an.c"
yy31:
	++YYCURSOR;
#line 57 "lex_an.re"
	{write_ts(saved,"}", line, ts,0); goto loop;}
#line 329 "lex_an.c"
yy33:
	++YYCURSOR;
#line 63 "lex_an.re"
	{write_ts(saved,"STR", line, ts,0); goto loop;}
#line 334 "lex_an.c"
yy35:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy35;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy37;
	default:	goto yy16;
	}
yy37:
	++YYCURSOR;
#line 64 "lex_an.re"
	{write_ts(saved,"ERR", line, ts,0); return 0;}
#line 407 "lex_an.c"
yy39:
	yych = *++YYCURSOR;
	switch (yych) {
	case 's':	goto yy45;
	default:	goto yy22;
	}
yy40:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy46;
	default:	goto yy22;
	}
yy41:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy21;
	default:	goto yy42;
	}
yy42:
#line 49 "lex_an.re"
	{write_ts(saved,"IF", line, ts,0); goto loop;}
#line 491 "lex_an.c"
yy43:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'o':	goto yy47;
	default:	goto yy22;
	}
yy44:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'i':	goto yy48;
	default:	goto yy22;
	}
yy45:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'e':	goto yy49;
	default:	goto yy22;
	}
yy46:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'c':	goto yy51;
	default:	goto yy22;
	}
yy47:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'p':	goto yy52;
	default:	goto yy22;
	}
yy48:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy54;
	default:	goto yy22;
	}
yy49:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy21;
	default:	goto yy50;
	}
yy50:
#line 50 "lex_an.re"
	{write_ts(saved,"ELSE", line, ts,0); goto loop;}
#line 599 "lex_an.c"
yy51:
	yych = *++YYCURSOR;
	switch (yych) {
	case 't':	goto yy55;
	default:	goto yy22;
	}
yy52:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy21;
	default:	goto yy53;
	}
yy53:
#line 48 "lex_an.re"
	{write_ts(saved,"LOOP", line, ts,0); goto loop;}
#line 677 "lex_an.c"
yy54:
	yych = *++YYCURSOR;
	switch (yych) {
	case 't':	goto yy56;
	default:	goto yy22;
	}
yy55:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'i':	goto yy57;
	default:	goto yy22;
	}
yy56:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'f':	goto yy58;
	default:	goto yy22;
	}
yy57:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'o':	goto yy60;
	default:	goto yy22;
	}
yy58:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy21;
	default:	goto yy59;
	}
yy59:
#line 51 "lex_an.re"
	{write_ts(saved,"PRINTF", line, ts,0); goto loop;}
#line 773 "lex_an.c"
yy60:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'n':	goto yy61;
	default:	goto yy22;
	}
yy61:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case '_':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy21;
	default:	goto yy62;
	}
yy62:
#line 47 "lex_an.re"
	{write_ts(saved,"FUNCTION", line, ts,0); goto loop;}
#line 851 "lex_an.c"
}
#line 66 "lex_an.re"


}


void lex_check(char * file, TS * ts){
	FILE * fp = fopen(file,"r");
	FILE * of = fopen("lex.output","w");
//	fseek(fp,0,-1);
//	int size = ftell(fp);
//	fseek(fp,0,0);
	char c;
	int line = 1;
	char word[1000]; int wc = 0;
//	char buffer[1000];
	while (!feof(fp)){
		c = fgetc(fp);
//		putchar(c);
		if(c==' '||c=='\n'||c=='\t'){
			if (c == '\n')
				line ++;
			if (strlen(word) >= 1)
				lex(word,line, ts);
			for (int i = 0; i < wc; i++) word[i]=0;
			wc = 0;
		}else
			word[wc++] = c;
	}
	fclose(fp);
	printf("TS entries: %d\n TABLE:\n",ts->qnt_entries);
	printf("\nlabel\t\tline\t\tvalue\n");
	for (int i=0; i<ts->qnt_entries; i++){
		entries_t entrie = ts->entries[i];
		char * str = entrie.label;
		printf("%s\t\t%s\t\t%d\t\t%d\n",entrie.ident,str,entrie.line,entrie.value);
		if (strcmp(entrie.label,"ERR")==0)
			fprintf(stderr,"Erro na linha: %d\nIdentificador: %s\n",entrie.line,entrie.ident);
		fwrite(str,sizeof(char),strlen(str),of);
		fputc(' ',of);
	}
	fwrite("$\n",sizeof(char),2,of);
	fclose(of);
	printf("$\n");
/*    for (int i = 1; i < argc; ++i) {
        lex(argv[i]);
    }
	*/


}


int main(int argc, char **argv)
{
	char * file = argv[argc-1];
	TS ts;
	entries_t entries[1000];
	ts.qnt_entries = 0;
	ts.entries = entries;
	lex_check(file,&ts);
    return 0;
}
