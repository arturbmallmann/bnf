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
//	wchar_t m;
	char m;
	char size[2];
	fwprintf(stdout,L"end? %d\n",f.eof());
//	f.seekg(0,ios::end);
//	printf("end? %d tellg %d \n",(int)f.eof(),(int)f.tellg());
//	f.read(&m, 1);
//	printf("end? %d tellg %d \n",(int)f.eof(),(int)f.tellg());

	wchar_t line[50];
	int l_count=0;
	{
		read_file<wchar_t> (&f, &(line[l_count]));
		l_count++;
		fwprintf(stdout,L"...");
	}while(l_count == 25 )
//						fwscanf(((fstream)f).,L"%s\n",line);
	fwprintf (stdout,L"begin:\n");//,L"teste");
	return 0;
//	f.seekg(48,ios::beg); //46 unicodes + 1*2

	vector<record> rec;
	printf("end? %d tellg %d \n",(int)f.eof(),(int)f.tellg());
	while(!f.eof()){
//		read_file<wchar_t>(&f,&m);
		read_file<char>(&f, &m);
		cout<<"M> "<<m<<endl;
//		return 0;
		if ( m == 'M'||m=='P'){
			printf("entrou %c\n",m);
			read_file<char>(&f, (char*)&size,2);
			unsigned int isize = tb2fb(size);
			printf("size: %d m: %c",isize,m);
			record nrec;
			ent_t * entries = (ent_t*) malloc(sizeof(ent_t) * isize);
			nrec.size = isize;
			nrec.pos = entries;
			for (unsigned int i=0; i < isize; i++){
				char type;
				read_file<char>(&f, &type);
				nrec.pos[i].type = type;
				if(type != 'E')
					cout << "type: "<< type<<endl;
				switch(type){
					case 'E':break;
					case 'b':
					case 'B':read_file<char>(&f, &nrec.pos[i].value.b, 1); break;
					case 'I':
							read_file<char>(&f, &nrec.pos[i].value.b, 2);
							cout<< tb2fb(&nrec.pos[i].value.b)<<endl;
							break;
					case 'S':
						wchar_t line[1000];
						int l_count=0;
						{
							read_file<wchar_t> (&f, &line[l_count]);
							fwprintf (stdout,L"S: %c",&line[l_count]);
							cout<<"s:\n";
						}while(wcscmp(&line[l_count++],L"\n") == 0 )
//						fwscanf(((fstream)f).,L"%s\n",line);
						fwprintf (stdout,L"S: %s\n",line);
						break;
				}
			}

			cout<<"m: "<<m;//<<" size: "<<isize<<endl;
		}
	}
	return 0;

}
