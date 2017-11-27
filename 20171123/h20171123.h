#ifndef _H_20171123_H_
#define _H_20171123_H_

#include "..\Include\lib.h"
#include "..\CCT\sysenv.h"
#include<ctype.h>
#include<string.h>
#include<time.h>

void homework_2017_11_23_main(void);

void homework_1(void);
void homework_2(void);
void homework_3(void);
void homework_4(void);
void homework_5(void);
void homework_p160_8(void);
void homework_p160_9(void);
void homework_p160_12(void);

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

int char_comparing(
	void* ch1,
	void* ch2
);

size_t MyStrlen(const char * str);

BOOL MyStrcmp(
	const char*	str1,
	const char*	str2
);

char ** ReadFromFile(
	const char*  file_name,
		 char**	 buffer
);

int IsEnglishCharacters(char ch);

void CharStat(const char * str);

typedef struct _matrix {
	 char* data;
	   int rows;
	   int columns;
	size_t element_size;
} Matrix;

void SaddlePoint(Matrix* mat);

void SquareConvolution(
	Matrix* mat,
		int left_top_row,
		int left_top_col
);

Matrix* InitMatrix(
	 Matrix* mat,
		 int rows,
		 int cols,
	  size_t element_size
);

void FreeMatrix(
	Matrix* mat
);

void* At(
	Matrix* mat,
		int row,
		int col
);

long TrOfMatrix_int(
	Matrix* mat,
		int n
);

char * ReadLine(
	char* str, 
	  int length
);

#endif // !_H_20171123_H_