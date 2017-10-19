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

// Homework : 2017-10-19
// P103 3
void homework5_1(void)
{
	char ch = 'A';

	int i;
	for (i = 1; ch <= 'Z'; ++ch, ++i)
	{
		putchar(ch);

		if (i % 8 == 0)
		{
			putchar('\n');
		}
		else if(ch != 'Z')
		{
			putchar(',');
		}
	}

	putchar('\n');

	system("pause");
}

// Homework : 2017-10-19
// P103 5
void homework5_2(void)
{
	int i;
	int printedCount = 0;
	for (i = 1; i <= 1000; ++i)
	{
		if (i % 3 == 2 &&
			i % 5 == 3 &&
			i % 7 == 2)
		{
			printf("%d ", i);
			printedCount++;

			if (printedCount % 5 == 0)
			{
				putchar('\n');
			}
		}
	}

	system("pause");
}

// Homework : 2017-10-19
// P103 7
void homework5_3(void)
{
	int p = 1;
	double s = 0;
	
	for (; p <= 200; ++p)
	{
		s += 1 / (double)p;
	}

	printf("sum = %lf\n", s);

	system("pause");
}

// Homework : 2017-10-19
// P103 10
void homework5_4(void)
{
	int a1 = 1, a2 = 1;
	printf("%d, %d\n", a1, a2);

	while (a1 <= 10000 || a2 <= 10000)
	{
		a1 += a2;
		a2 += a1;
		printf("%d, %d\n", a1, a2);
	}

	system("pause");
}

// Homework : 2017-10-19
// P103 14
void homework5_5(void)
{
	int iNum = 0;

	printf("Please input a positive integer : ");

	while (1 != scanf("%d", &iNum) || iNum <= 0)
	{
		printf("Input must be a positive integer.\n");

		ClearInputQueue();
	}

	ClearInputQueue();

	int digits = (int)log10(iNum) + 1;

	printf("There are %d digit%s in %d\n", digits, (digits == 1) ? "" : "s", iNum);

	int sum = 0;

	int i;
	for (i = 0; i < digits; ++i)
	{
		sum += (iNum / (int)pow(10, i)) % 10;
	}

	printf("And the sum of each digit is equal to %d.\n", sum);

	system("pause");
}

// Homework : 2017-10-19
// P103 16
void homework5_6(void)
{
	int a = 1, b = 1;

	for (; a < 10; ++a)
	{
		for (b = 1; b <= a; ++b)
		{
			printf("%d x %d = %2d   ", b, a, a*b);
		}

		putchar('\n');
	}

	putchar('\n');

	system("pause");
}

// Homework : 2017-10-19
// P103 17
void homework5_7(void)
{
	char ch = 'A';
	char blank[4] = "   ";

	for (; ch <= 'D'; ++ch)
	{
		blank[3 - (ch - 'A')] = '\0';
		printf("%s", blank);

		int i;
		for (i = 0; i < 2 * (ch - 'A' + 1) - 1; ++i)
		{
			putchar(ch);
		}

		putchar('\n');
	}

	system("pause");
}