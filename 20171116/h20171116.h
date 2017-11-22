#ifndef  _H_20171116_H_
#define _H_20171116_H_

#include "../Include/lib.h"
#include "rectangle.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void homework_2017_11_16_main(void);

#define at(str, ch) ((int)(strchr((str), (ch)) - (str)))

void display_rectangle(void);
void walkant(void);

#endif // ! _H_20171116_H_