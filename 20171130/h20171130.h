#ifndef _H_2017_11_30_
#define _H_2017_11_30_

#include "../CCT/sysenv.h"
#include "../CCT/autoalloc.h"
#include "../Include/lib.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<limits.h>
#include<float.h>

typedef struct _Student {
	char name[30];
	double score;
} Student;

typedef Student** Students;
typedef struct tPoint {
	double x;
	double y;
} Point;

typedef struct tComplex {
	double real;
	double imaginary;
} Complex;

void homework_2017_11_30_main(void);

void homework_1(void);
void homework_2(void);
void homework_3(void);
void homework_P178_2(void);
void homework_P178_3(void);

void Swap(
	 void*	item1,
	 void*	item2,
	size_t	size
);

int int_comparing(
	void* i1,
	void* i2
);

int char_comparing(
	void* ch1,
	void* ch2
);

int stu_comparing(
	void* i1,
	void* i2
);

void BubbleSort(
	 void* buf,
	size_t element_size,
	size_t length,
	int(*comparing)(void*, void*)
);

long BinarySearch(
	 void* buf,
	 void* target_item,
	size_t element_size,
	size_t length,
	int(*comparing)(void*, void*)
);

double Distance(
	Point a,
	Point b
);

Complex ComplexMultiply(
	Complex a,
	Complex b
);

char * ReadLine(
	char* str,
	int length
);
#endif // !_H_2017_11_30_
