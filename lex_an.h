/*
 * lex_an.h
 *
 *  Created on: 19 de mai de 2021
 *      Author: artur
 */

#ifndef LEX_AN_H_
#define LEX_AN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_compiler.h"
static int lex(const char *YYCURSOR, const int line, TS * ts);

void lex_check(char * file, TS * ts);

#endif /* LEX_AN_H_ */
