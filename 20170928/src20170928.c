/*
* ##########################################################################
* #                                                                        #
* #                           ATTENTION PLEASE                             #
* #                                                                        #
* ##########################################################################
*
* I have used a special line in `main.h` since I'm using Visual Studio 2017.
* Delete it unless you are using the same compiler.
*
*/

// You may need to change the following line if you have moved `src.c`
#include "../main.h"

int compare_int(const void * num1, const void * num2)
{
	return (*(int*)num1 - *(int*)num2);
}

// Homework : 2017-09-28
// 1
void homework2_1(void)
{
	printf("Please input the 3 sides of a triangle: ");
	int sides[3] = { 0 };
	double s = 0.0, area = 0.0;

	while (1)
	{
		if (3 != scanf("%d %d %d", &sides[0], &sides[1], &sides[2]))
		{
			printf("Inputs must be integers.\n");
			// defined in `main.h` (inline function)
			ClearInputQueue();
			/*
			 * void ClearInputQueue()
			 * {
			 *		while (getchar() != '\n')
			 *			continue;
			 * }
			 *
			 */
			continue;
		}

		if (sides[0] <= 0 || sides[1] <= 0 || sides[2] <= 0)
		{
			printf("Inputs must be positive integers.\n");
			continue;
		}

		qsort(sides, 3, sizeof(int), compare_int);

		if(sides[0] + sides[1] <= sides[2])
		{
			printf("Cannot make up a triangle.\n");
			continue;
		}

		break;
	}

	s = ((double)(sides[0] + sides[1] + sides[2])) / 2.0;

	area = sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));

	printf("Area of the triangle is %.2f\n", area);

	system("pause");
}

// Homework : 2017-09-28
// 2
void homework2_2(void)
{
	printf("Please input an English character: ");

	char ch = '\0';

	while (1 != scanf("%c", &ch) || !isalpha(ch))
	{
		printf("Inputs must be an English character.\n");

		ClearInputQueue();
	}

	ClearInputQueue();

	printf("ASCII = %d\n", ch);

	system("pause");
}

// Homework : 2017-09-28
// 3
void homework2_3(void)
{
	printf("Please input an English character: ");

	char ch = '\0';

	while (1 != scanf("%c", &ch) || !isalpha(ch))
	{
		printf("Inputs must be an English character.\n");

		ClearInputQueue();
	}

	ClearInputQueue();

	printf("upper to lower , lower to upper. result = %c\n", (isupper(ch)) ? tolower(ch) : toupper(ch));

	system("pause");
}

// Homework : 2017-09-28
// 4
void homework2_4(void)
{
	printf("Please input a positive integer: ");

	int inputNum = 0;

	while (1 != scanf("%d", &inputNum) || inputNum <= 0)
	{
		printf("Inputs must be a positive integer\n");

		ClearInputQueue();
	}

	ClearInputQueue();

	printf("Hex = %x\n", inputNum);
	printf("Oct = %o\n", inputNum);

	char * resultStr = (char*)malloc(256 * sizeof(char));

	if (NULL == resultStr)
	{
		fprintf(stderr, "Cannot allocate memory.\n");
		system("pause");
		return;
	}

	memset(resultStr, 0, 256);

	for(int i = 0; inputNum; i++)
	{
		sprintf(resultStr + i, "%d", inputNum % 2);
		inputNum = inputNum / 2;
	}

	size_t length = strlen(resultStr);
	
	for (size_t j = 0; j <= length / 2; ++j)
	{
		char ch = resultStr[j];
		resultStr[j] = resultStr[length - j - 1];
		resultStr[length - j - 1] = ch;
	}

	printf("Bin = %s\n", resultStr);

	free(resultStr);

	system("pause");
}

// Homework : 2017-09-28
// P38 5
void homework2_5(void)
{
	printf("Please input a five digits: ");

	int num;

	while (1 != scanf("%d", &num) || num < 10000 || num >= 100000)
	{
		printf("Input must be a five digits.\n");
		ClearInputQueue();
	}

	printf("First digit of the number : %d\n"
		"Second digit of the number : %d\n"
		"Third digit of the number : %d\n"
		"Fourth digit of the number : %d\n"
		"Fifth digit of the number : %d\n",
		num % 10,
		(num / 10) % 10,
		(num / 100) % 10,
		(num / 1000) % 10,
		(num / 10000) % 10);

	printf("and total of them equals to %d\n", 
		num % 10 +
		(num / 10) % 10 +
		(num / 100) % 10 +
		(num / 1000) % 10 +
		(num / 10000) % 10);

	system("pause");
}