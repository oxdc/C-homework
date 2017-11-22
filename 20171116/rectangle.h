#ifndef _CharRectangle_H_
#define _CharRectangle_H_

#include "sysenv.h"
#include "../Include/lib.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct rectangle__ {
	void * _this;
	int x;
	int y;
	int height;
	int width;
	char mark;
} CharRectangle;

typedef CharRectangle* pCharRectangle;
typedef pCharRectangle CharRectangleList;
typedef CharRectangleList* pCharRectangleList;

pCharRectangle InitCharRectangle(
	pCharRectangle _r,
	int _x, 
	int _y, 
	int _height, 
	int _width, 
	char _mark
);

void Draw(
	CharRectangleList _r,
	size_t _size
);

#endif // !_CharRectangle_H_
