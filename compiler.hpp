#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <fstream>
#include <iostream>

#include <wchar.h>

using namespace std;
template<typename T>
void read_file(std::ifstream *strm, T *dest,int n=1){
	strm->read(reinterpret_cast<char *>(dest), sizeof(T)*n);
}
using namespace std;
template<typename T>
inline void write_file(std::ofstream *strm, T *src,int n=1){
	strm->write( reinterpret_cast<char *>(src), sizeof(T) * n);
}

unsigned int tb2fb(char * v) { //two bytes to four bytes
	return v[0] | v[1]<<8;
}
union value{
	char b;
	char i[2];
	wchar_t * str;
}typedef u_value;
struct entrie_s{
	char type;
	int size;
	u_value value;
}typedef ent_t;

struct struct_rec{
	ent_t *  pos;
	int size;
}typedef record;


#endif
