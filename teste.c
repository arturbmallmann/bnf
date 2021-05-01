#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
/*	int a;
	scanf("%d",&a);
	printf("Antes %d, depois %d\n",a,a<<1);
*/
	char * a = (char*) malloc(100);
	a[0]='\n';
	char b[108];
	int b_pos=0;
	while ( 1 ){
		scanf("%s",a);
		if ( !strcmp("exit",a) )
			break;
		if(b_pos!=0)
			b[b_pos++] = ' ';
		strcpy(b+b_pos,a);
		b_pos += strnlen(a,100);
	}
	printf("%d %c\n",(int)b[b_pos],(char)114);
	int kk = 2;
	printf("%s %d\n",b,kk);
	return 0;
}
