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

using namespace std;
int main(int argc, char **argv){
	ifstream f = ifstream("gramma_slr_v1.cgt",std::ios::in | std::ios::binary);

//	cout<<"teste";
//	wfstream f ("gramma_slr_v1.cgt",std::ios::in);// | std::ios::binary);
//	wchar_t m;
	char m;
	char size[2];
//	fwprintf(stdout,L"end? %d\n",f.eof());
//	f.seekg(0,ios::end);
//	printf("end? %d tellg %d \n",(int)f.eof(),(int)f.tellg());
//	f.read(&m, 1);
//	printf("end? %d tellg %d \n",(int)f.eof(),(int)f.tellg());

//	wchar_t line[50];
	char16_t line[23];
	int l_count=0;
	do {
//		fwprintf(stdout,L"%d \n",sizeof(wchar_t));
//	cout<<fflush;
//	cout<<"teste";
//		f.read(&line[l_count],1);
		read_file<char16_t>(&f, &line[l_count]);
//		cout<<"teste\n";
//		read_file<wchar_t> ((ifstream*)&f, &(line[l_count]));
		l_count++;
	}while(l_count < 24 );
//	printf ("begin: %zu",line,2);
	size_t wcs_sz = sizeof line / sizeof *line;
	printf("%zu UTF-16 code units: [ ", wcs_sz);
//    for (size_t n = 0; n < wcs_sz; ++n) printf("%#x ", line[n]);
    for (size_t n = 0; n < wcs_sz; ++n) printf("%c", line[n]);
    printf("]\n");
//		cout<<line<<endl;
//	return 0;
//	f.seekg(48,ios::beg); //46 unicodes + 1*2

	vector<record> rec;
	printf("end? %d tellg %d \n",(int)f.eof(),(int)f.tellg());
	while(!f.eof()){
//		read_file<wchar_t>(&f,&m);
		read_file<char>(&f, &m);
//		cout<<"M> "<<m<<endl;
//		return 0;
		printf("Byte: %c (%x)\n",m,m);//<<" size: "<<isize<<endl;
		if ( m == 'M'||m=='P'||m=='I'){
//			printf("entrou %c\n",m);
			read_file<char>(&f, (char*)&size,2);
			unsigned int isize = tb2fb(size);
//			printf("size: %d\n",isize);
			record nrec;
			ent_t * entries = (ent_t*) malloc(sizeof(ent_t) * isize);
			nrec.size = isize;
			nrec.pos = entries;
			for (unsigned int i=0; i < isize; i++){
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
						read_file<char[2]>(&f, &nrec.pos[i].value.i, 2);
						cout<< (unsigned int)tb2fb(nrec.pos[i].value.i);
						break;
					case 'S':
						char16_t line[1000];
						int l_count=0;
						do {
//							cout<<f.tellg()<<endl;
							read_file<char16_t> (&f, &line[l_count]);
//							fwprintf (stdout,L"S: %c",&line[l_count]);
//							cout<<"s:\n";
						}while( line[l_count++] != 0 );
//						fwscanf(((fstream)f).,L"%s\n",line);
						for (int n = 0; n < l_count; ++n) printf("%c", line[n]);
						break;
				}
				cout<<endl;
			}

		}
	}
	return 0;

}
