#ifndef _H_20171102_
#define _H_20171102_

#include "../Include/lib.h"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#include<time.h>
#include<limits.h>

#define PI 3.1415926535858

struct BitMap {
	size_t length;
	char * bits;
};

void __InitBitMap(struct BitMap * map, const size_t length);
void __FreeBitMap(struct BitMap * map);
BOOL __IsNOpen(const struct BitMap * map, const size_t location);
BOOL __IsNClose(const struct BitMap * map, const size_t location);
void __OpenN(struct BitMap * map, const size_t location);
void __CloseN(struct BitMap * map, const size_t location);
void __MergeBitMap(struct BitMap * output, const struct BitMap * map1, const struct BitMap * map2);

void homework_2017_11_02_main(void);

void GetNarcissusNumbers(void);

void GetInt(int * a, int * b);
void GetAllFactors(int x, const struct BitMap * factors);
int GetGreatestCommonDivisor_byBitMap(int a, int b);
int GetLeastCommonMultiple_byBitMap(int a, int b);
int GetGreatestCommonDivisor_byEuclideanAlgorithm(int a, int b);
int GetLeastCommonMultiple_byEuclideanAlgorithm(int a, int b);

long double lfrand(long double lower, long double upper);
long double lfabs(long double x);
long double CalculatePi(long double error);
double Integral(long double error);

int YangsTriangle(int row, int column);
void DisplayYangsTriangle(int depth);

#endif // !_H_20171102_