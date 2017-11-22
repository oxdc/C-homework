#include "h20171102.h"

#define min(x, y) (((x) < (y)) ? ((x)) : ((y)))
#define max(x, y) (((x) > (y)) ? ((x)) : ((y)))

/*
 * initialize a bit map with given length
 * @param map [a pointer to an non-null bit map]
 * @param length [the length of the bit map]
 */
void __InitBitMap(struct BitMap * map, const size_t length)
{
	if (map == NULL)
	{
		perror("Cannot initialization an null map.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	map->length = length;
	map->bits = (char*)malloc((length / 8 + 1) * sizeof(char));
	memset(map->bits, 0, length / 8 + 1);

	if (map->bits == NULL)
	{
		perror("Cannot allocate memory.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}
}

/*
 * delete a given bit map
 * @param map [a pointer to a bit map]
 */
void __FreeBitMap(struct BitMap * map)
{
	free(map->bits);
	map->bits = NULL;
	free(map);
}

/*
 * To find out whether a bit is open (equals to 1) at given position
 * @param map [a pointer to an non-null bit map]
 * @param location [the position of the bit]
 * @return TRUE [if open]
 */
BOOL __IsNOpen(const struct BitMap * map, const size_t location)
{
	if (map == NULL)
	{
		perror("Cannot access a null bit map.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	if (location < 0 || location > map->length - 1)
	{
		perror("Out of range.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	return (map->bits[location / 8] >> (7 - location % 8)) & 0x1;
}

/*
 * To find out whether a bit is closed (equals to 0) at given position
 * @param map [a pointer to an non-null bit map]
 * @param location [the position of the bit]
 * @return TRUE [if closed]
 */
BOOL __IsNClose(const struct BitMap * map, const size_t location)
{
	return (__IsNOpen(map, location) == TRUE) ? FALSE : TRUE;
}

/*
 * To open a bit (set to 1) at given position
 * @param map [a pointer to an non-null bit map]
 * @param location [the position of the bit]
 */
void __OpenN(struct BitMap * map, const size_t location)
{
	if (__IsNClose(map, location))
	{
		map->bits[location / 8] |= 1 << (7 - location % 8);
	}
}

/*
 * To close a bit (set to 0) at given position
 * @param map [a pointer to an non-null bit map]
 * @param location [the position of the bit]
 */
void __CloseN(struct BitMap * map, const size_t location)
{
	if (__IsNOpen(map, location))
	{
		map->bits[location / 8] &= ~(1 << (7 - location % 8));
	}
}

/*
 * To merge two given bit map. And get a new bit map with the same
 *  open bit in map1 and map2.
 * @param output [a pointer to an empty bit map to store the result]
 * @param map1 [a pointer to an non-null bit map]
 * @param map1 [a pointer to another non-null bit map]
 */
void __MergeBitMap(struct BitMap * output, const struct BitMap * map1, const struct BitMap * map2)
{
	if (map1 == NULL || map2 == NULL)
	{
		perror("Cannot access a null bit map.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	if (output->length != min(map1->length, map2->length))
	{
		perror("Dimension error.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	int i;
	for (i = 0; i < output->length / 8 + 1; ++i)
	{
		output->bits[i] = (map1->bits[i]) & (map2->bits[i]);
	}
}

void GetInt(int * a, int * b)
{
	while (2 != scanf("%d %d", a, b) || a <= 0 || b <= 0)
	{
		printf("Must input two POSITIVE INTEGERS.\n");

		ClearInputQueue();
	}

	ClearInputQueue();
}

// Homework 2017 10 26
// Main function
void homework_2017_11_02_main(void)
{
	// Homework 2017 10 26
	// 4
	{
		printf("All Narcissus Numbers: \n");
		GetNarcissusNumbers();
	}

	// Homework 2017 10 26
	// 7
	{
		printf("The first method to get the greatest common divisor \nand the least common multiple.\n");
		printf("Using bit map to store information.\n");
		printf("Please input two positive integers: ");

		int a = 0, b = 0;
		GetInt(&a, &b);
		printf("the greatest common divisor of %d and %d is %d\n",
			a,
			b,
			GetGreatestCommonDivisor_byBitMap(a, b));
		printf("the least common multiple of %d and %d is %d\n",
			a,
			b,
			GetLeastCommonMultiple_byBitMap(a, b));

		printf("---------------------------------------------------\n");
		printf("The second method to get the greatest common divisor \nand the least common multiple.\n");
		printf("Using Euclidean algorithm.\n");
		printf("the greatest common divisor of %d and %d is %d\n",
			a,
			b,
			GetGreatestCommonDivisor_byEuclideanAlgorithm(a, b));
		printf("the least common multiple of %d and %d is %d\n",
			a,
			b,
			GetLeastCommonMultiple_byEuclideanAlgorithm(a, b));

		system("pause");
	}

	// Homework 2017 10 26
	// 10
	{
		srand((unsigned int)time(NULL));
		long double error1 = 1e-7;
		printf("Pi = %lf\n", CalculatePi(error1));

		system("pause");
	}

	// Homework 2017 10 26
	// integral of sin(x) from 0 to pi/2
	{
		srand((unsigned int)time(NULL));
		long double error2 = 1e-7;
		printf("integral of sin(x) from 0 to pi/2 = %lf\n", Integral(error2));

		system("pause");
	}

	// Homework 2017 10 26
	// Yang's triangle (also Pascal's triangle)
	{
		printf("Yang's triangle (also Pascal's triangle)\n");
		printf("Please input the number of rows: ");

		int depth = 0;

		while (1 != scanf("%d", &depth) || depth < 0 || depth > 14)
		{
			printf("Please input a number between 1 and 14.\n");

			ClearInputQueue();
		}

		ClearInputQueue();

		DisplayYangsTriangle(depth);

		system("pause");
	}
}

// Homework 2017 10 26
// 4
void GetNarcissusNumbers(void)
{
	int i;
	for (i = 100; i < 1000; ++i)
	{
		if ((pow(i % 10, 3) +
			pow((i / 10) % 10, 3) +
			pow((i / 100) % 10, 3)) == i)
		{
			printf("%d\n", i);
		}
	}

	system("pause");
}

void GetAllFactors(int x, const struct BitMap * factors)
{
	int i;

	__OpenN(factors, 0);
	__OpenN(factors, x - 1);

	for (i = 2; i < x; ++i)
	{
		if (x % i == 0)
		{
			__OpenN(factors, i - 1);
		}
	}
}

int GetGreatestCommonDivisor_byBitMap(int a, int b)
{
	struct BitMap * factorsOfa = (struct BitMap *)malloc(sizeof(struct BitMap));
	struct BitMap * factorsOfb = (struct BitMap *)malloc(sizeof(struct BitMap));
	__InitBitMap(factorsOfa, a);
	__InitBitMap(factorsOfb, b);

	GetAllFactors(a, factorsOfa);
	GetAllFactors(b, factorsOfb);

	struct BitMap * commonFactors = (struct BitMap *)malloc(sizeof(struct BitMap));
	__InitBitMap(commonFactors, min(factorsOfa->length, factorsOfb->length));
	__MergeBitMap(commonFactors, factorsOfa, factorsOfb);

	int i, result;
	for (i = commonFactors->length; i > 0; --i)
	{
		if (__IsNOpen(commonFactors, i - 1))
		{
			__FreeBitMap(factorsOfa);
			__FreeBitMap(factorsOfb);
			__FreeBitMap(commonFactors);
			return i;
		}
	}
}

int GetLeastCommonMultiple_byBitMap(int a, int b)
{
	return a * b / GetGreatestCommonDivisor_byBitMap(a, b);
}

int GetGreatestCommonDivisor_byEuclideanAlgorithm(int a, int b)
{
	if (b)
	{
		while ((a %= b) && (b %= a))
			continue;
	}

	return a + b;
}

int GetLeastCommonMultiple_byEuclideanAlgorithm(int a, int b)
{
	return a * b / GetGreatestCommonDivisor_byEuclideanAlgorithm(a, b);
}

long double lfrand(long double lower, long double upper)
{
	if (upper - lower > RAND_MAX)
	{
		printf("WARNING: the given range is too wide.\n");
	}

	long double a = rand() / (long double)RAND_MAX;
	long double b = rand() / (long double)RAND_MAX;
	a = a * 10000 - (int)(a * 10000) + b;
	a = ((a > 1) ? (a - 1) : a);

	return lower + a * (upper - lower);
}

long double lfabs(long double x)
{
	return x < 0 ? -x : x;
}

double CalculatePi(long double error)
{
	long long total = 0, totalInTheCircle = 0;
	double storedResult = 0.0;

	do
	{
		long double x = 0.0, y = 0.0;
		x = lfrand(-1.0, 1.0);
		y = lfrand(-1.0, 1.0);

		total++;

		if (x*x + y*y < 1.0)
		{
			totalInTheCircle++;
		}

		if (total % 100)
		{
			if (lfabs((storedResult - totalInTheCircle / (long double)total) * 4) < error &&
				lfabs((storedResult - totalInTheCircle / (long double)total) * 4) > 0 &&
				storedResult != 0.0)
			{
				return totalInTheCircle / (long double)total * 4;
			}

			storedResult = totalInTheCircle / (long double)total;
		}
	} while (TRUE);
}

double Integral(long double error)
{
	long long total = 0, totalUnderSin = 0;
	double storedResult = 0.0;

	do
	{
		long double x = 0.0, y = 0.0;
		x = lfrand(0.0, PI/2);
		y = lfrand(0.0, 1.0);

		total++;

		if (y < sin(x))
		{
			totalUnderSin++;
		}

		if (total % 100)
		{
			if (lfabs((storedResult - totalUnderSin / (long double)total) * (PI / 2)) < error &&
				lfabs((storedResult - totalUnderSin / (long double)total) * (PI / 2)) > 0 &&
				storedResult != 0.0)
			{
				return totalUnderSin / (long double)total * (PI / 2);
			}

			storedResult = totalUnderSin / (long double)total;
		}
	} while (TRUE);
}

int YangsTriangle(int row, int column)
{
	if (column > 2 * row - 1)
	{
		perror("Out of range.\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	if (column == 1 || column == row)
	{
		return 1;
	}
	else
	{
		return YangsTriangle(row - 1, column - 1) + YangsTriangle(row - 1, column);
	}
}

void DisplayYangsTriangle(int depth)
{
	int row;
	for (row = 1; row <= depth; ++row)
	{
		int i;
		for (i = 1; i <= depth - row; ++i)
		{
			printf("    ");
		}

		int column;
		for (column = 1; column <= row; ++column)
		{
			int result = YangsTriangle(row, column);

			printf(result < 10 ? " %d      " :
				  (result < 100 ? " %d     " : "%d     "),
				   result);
		}

		putchar('\n');
	}
}
