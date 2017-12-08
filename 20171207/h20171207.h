#ifndef _H_2017_12_07_H_
#define _H_2017_12_07_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "../CCT/autoalloc.h"
#include "../Include/lib.h"
#include "../CCT/sysenv.h"

void homework_2017_12_07_main(void);

void homework_P207_2(void);
void homework_P207_4(void);
void homework_P207_5(void);
void homework_4(void);

void PerimeterAndArea(
	double   r,
	double * perimeter,
	double * area
);

void MyStrcpy(
	      char * des,
	const char * res
);

double Average_cct_s(int * arr);

double Average(
	 int * arr,
	size_t size
);

void input(int * data);
void sort(int * data);
void output(int * data);

void Swap(
	 void*	item1,
	 void*	item2,
	size_t	size
);

void SelectionSort(
	 void*	buf,
	size_t	size,
	size_t	length,
	   int	(*comparing)(void*, void*)
);

int int_comparing(
	void* i1,
	void* i2
);

#define PI 3.1415926

#endif // !_H_2017_12_07_H_
