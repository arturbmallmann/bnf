/*
 * my_compyler.h
 *
 *  Created on: 19 de mai de 2021
 *      Author: artur
 */

#ifndef MY_COMPILER_H_
#define MY_COMPILER_H_

struct struct_entries{
	int id;
	int line;
	int value;
	char label[100];
	char ident[100];
}typedef entries_t;


struct struct_TS{
	int qnt_entries;
	entries_t * entries;
	void (*add_entrie)(entries_t);
}typedef TS;


#endif /* MY_COMPILER_H_ */
