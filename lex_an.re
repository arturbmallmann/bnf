#include "lex_an.h"

void write_ts(const char * ident, char * label, int line, TS * ts,int value){
	entries_t entrie;
	strcpy(entrie.ident, ident);
	strcpy(entrie.label, label);
	entrie.id=ts->qnt_entries;
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
    /*!re2c
        re2c:define:YYCTYPE = char;
        re2c:yyfill:enable = 0;

		//erro:
		err = [0-9]+"\."?[0-9]*[_a-zA-Z];

//		null = [\s\t\n]*;
		return = "return";
		function = "function";
		loop = "loop";
		if = "if";
		else = "else";
		id = [a-zA-Z][_0-9a-zA-Z]*;
		num = [0-9]+"\."?[0-9]*;
		openc = "{";
		closec = "}";
		openp = "(";
		closep = ")";
		plus = "+";
		minus = "-";
		mult = "*";
		div = "/";
		equal = "==";
		diff = "!=";
		attr = "=";
		enddot = ";";
		dot = ".";
		str = "\"" [^\"]* "\"";



    	[\x00] { return 0; } // qualquer simbolo whitespace sai do loop
//		null {printf("_");return 0;}
		return {write_ts(saved,"RETURN", line, ts,0); goto loop;}
		function {write_ts(saved,"FUNCTION", line, ts,0); goto loop;}
		loop {write_ts(saved,"LOOP", line, ts,0); goto loop;}
		if {write_ts(saved,"IF", line, ts,0); goto loop;}
		else {write_ts(saved,"ELSE", line, ts,0); goto loop;}
		id {write_ts(saved,"ID", line, ts,0); goto loop;}
		num {
			write_ts(saved,"NUM", line, ts,atoi(saved));
			goto loop;}
		openc {write_ts(saved,"{", line, ts,0); goto loop;}
		closec {write_ts(saved,"}", line, ts,0); goto loop;}
		openp {write_ts(saved,"(", line, ts,0); goto loop;}
		closep {write_ts(saved,")", line, ts,0); goto loop;}
		plus {write_ts(saved,"+", line, ts,0); goto loop;}
		minus {write_ts(saved,"-", line, ts,0); goto loop;}
		mult {write_ts(saved,"*", line, ts,0); goto loop;}
		div {write_ts(saved,"/", line, ts,0); goto loop;}
		equal {write_ts(saved,"==", line, ts,0); goto loop;}
		diff {write_ts(saved,"!=", line, ts,0); goto loop;}
		attr {write_ts(saved,"=", line, ts,0); goto loop;}
		enddot {write_ts(saved,";", line, ts,0); goto loop;}
		dot {write_ts(saved,".", line, ts,0); goto loop;}
		str {write_ts(saved,"STR", line, ts,0); goto loop;}
		err {write_ts(saved,"ERR", line, ts,0); return 0;}
		* {write_ts(saved,"ERR", line, ts,0); return 0;}
    */

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
	printf("\n\tid\tiden\tlabel\t\tline\t\tvalue\n");
	for (int i=0; i<ts->qnt_entries; i++){
		entries_t entrie = ts->entries[i];
		char * str = entrie.label;
		printf("%d\t%s\t\t%s\t\t%d\t\t%d\n",entrie.id,entrie.ident,str,entrie.line,entrie.value);
		if (strcmp(entrie.label,"ERR")==0)
			fprintf(stderr,"Erro na linha: %d\nIdentificador: %s\n",entrie.line,entrie.ident);
		fwrite(str,sizeof(char),strlen(str),of);
		fputc(' ',of);
	}
	fwrite("$\n",sizeof(char),2,of);
	fclose(of);
	printf("$\n");

	of = fopen("TS.out","w");
	fwrite(&(ts->qnt_entries),sizeof(int),1,of);
	fwrite(ts->entries,sizeof(entries_t),ts->qnt_entries,of);
	fclose(of);
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
