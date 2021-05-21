/*
 * compiler.cpp
 *
 *  Created on: 19 de mai de 2021
 *      Author: artur
 */
//#include "gramma_slr_v1.h"

#include "compiler.hpp"
#include <stdio.h>
#include <vector>

#include "my_compiler.h"

using namespace std;
int main(int argc, char **argv){

	cout << argc <<endl;
	ifstream f = ifstream(argc==2 ? argv[1] : "gramma_slr_v1.cgt",ios::in | ios::binary);
	fstream sts = fstream(argc==2 ? argv[1] : "TS.out",ios::in | ios::out | ios::binary);

	TS ts;
	read_file<int>((ifstream *)&sts, &(ts.qnt_entries));
	ts.entries = ( entries_t*) malloc ( sizeof(entries_t)*ts.qnt_entries );
	for (int i=0; i < ts.qnt_entries; i++)
		read_file<entries_t>((ifstream*)&sts, &(ts.entries[i]));
	char16_t line[23];
	int l_count=0;
	do {
		read_file<char16_t>(&f, &line[l_count]);
		l_count++;
	}while(l_count < 24 );

	unsigned short size;
	int count = 0;

	//Lê entrada
	size_t wcs_sz = sizeof line / sizeof *line;
	printf("%zu UTF-16 code units: [ ", wcs_sz);
//  for (size_t n = 0; n < wcs_sz; ++n) printf("%#x ", line[n]);
    for (size_t n = 0; n < wcs_sz; ++n) printf("%c", line[n]);
    printf("]\n");

	vector<record> rec;
	printf("end? %d tellg %d \n",(int)f.eof(),(int)f.tellg());
	char m;
	while(!f.eof()){
//		read_file<wchar_t>(&f,&m);
		read_file<char>(&f, &m);

		printf("[%d]Byte: %c (%d)\n",count++,m,m);//<<" size: "<<isize<<endl;
//		if ( m == 'M'||m=='P'){

//			printf("entrou %c\n",m);
//			read_file<char>(&f, (char*)&size,2);
//			unsigned int isize = tb2fb(size);
		read_file<unsigned short>(&f, &size,2);
		unsigned int isize = size;
		printf("(%d)\n",isize);
//			printf("size: %d\n",isize);
		record nrec;
		ent_t * entries = (ent_t*) malloc(sizeof(ent_t) * isize);
		nrec.size = isize;
		nrec.pos = entries;
		for (unsigned int i=1; i < isize; i++){
			char type;
			read_file<char>(&f, &type);
			nrec.pos[i].type = type;
//				if(type != 'E')
				cout << "\ttype: "<< type<<' ';
			switch(type){
				case 'E':
					break;
				case 'b':
				case 'B':
					read_file<char>(&f, &nrec.pos[i].value.b, 1);
					cout<< (unsigned int) nrec.pos[i].value.b;
					break;
				case 'I':
//						read_file<char[2]>(&f, &nrec.pos[i].value.i, 2);
//						cout<< (unsigned int)tb2fb(nrec.pos[i].value.i);
					read_file<unsigned short>(&f, &nrec.pos[i].value.i,1);
					cout<< (unsigned int) nrec.pos[i].value.i;
					break;
				case 'S':
					char16_t line[1000];
					int l_count=0;
					do {
//							cout<<f.tellg()<<endl;
						read_file<char16_t> (&f, &line[l_count]);
//							fwprintf (stdout,L"S: %c",&line[l_count]);
//							cout<<"s:\n";
					} while( line[l_count++] != 0 );
					line[l_count] = (char16_t)0;
//						fwscanf(((fstream)f).,L"%s\n",line);
					for (int n = 0; n < l_count; ++n) printf("%c", line[n]);
					break;
			}
			cout<<endl;
		}

	}
	return 0;

}
