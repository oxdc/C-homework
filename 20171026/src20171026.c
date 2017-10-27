#include "h20171026.h"

// Homework 2017 10 26
// Main function
void homework_2017_10_26_main(void)
{
	// Homework 2017 10 26
	// 1
	{
		int x = 0, y = 0;

		printf("Please input 2 integers: ");

		while (2 != scanf("%d %d", &x, &y))
		{
			printf("Please input two integers. Other inputs are not accepted.\n");

			ClearInputQueue();
		}

		ClearInputQueue();

		printf("The min of %d and %d is %d", x, y, homework_2017_10_26_GetMin(x, y));

		system("Pause");
	}

	// Homework 2017 10 26
	// 3
	{
		homework_2017_10_26_GetPrimes(100, 300);
		system("pause");
	}

	// Homework 2017 10 26
	// 5
	{
		homework_2017_10_26_PerfectNum();
		system("pause");
	}

	// Homework 2017 10 26
	// 8
	{
		homework_2017_10_26_draw(34);
		system("pause");
	}

	// Homework 2017 10 26
	// Hanoi
	{
		homework_2017_10_26_hanoi(64, 'a', 'b', 'c');
		system("pause");
	}
}

// Homework 2017 10 26
// 1
int homework_2017_10_26_GetMin(int x, int y)
{
	return (x < y) ? x : y;
}

// Homework 2017 10 26
// 3
void homework_2017_10_26_GetPrimes(int lower, int upper)
{
	int i;
	for (i = lower; i <= upper; ++i)
	{
		BOOL isPrime = TRUE;

		int di;
		for (di = i - 1; di > 1; --di)
		{
			if (i % di == 0)
			{
				isPrime = FALSE;
				break;
			}
		}

		if (isPrime)
		{
			printf("%d\n", i);
		}
	}
}

// Homework 2017 10 26
// 5
void homework_2017_10_26_PerfectNum()
{
	int k;
	for (k = 2; k <= 1000; k++)
	{
		int sum = 0;
		int j;
		for (j = 1; j < k; j++)
		{
			if (k % j == 0)
			{
				sum += j;
			}
		}

		if (sum == k)
		{
			printf("%d\n", k);
		}
	}
}

// Homework 2017 10 26
// 8
void homework_2017_10_26_draw(int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		int j;
		for (j = 0; j < n - i - 1; ++j)
		{
			putchar(' ');
		}

		int s;
		for (s = 0; s < 2 * i + 1; ++s)
		{
			putchar('A' + s % 26);
		}

		putchar('\n');
	}
}

// Homework 2017 10 26
// Hanoi
void homework_2017_10_26_hanoi(int n, char from, char buf, char to)
{
	if (n == 1)
	{
		printf("%d  from %c => %c\n", n, from, to);
	}
	else
	{
		homework_2017_10_26_hanoi(n - 1, from, to, buf);
		printf("%d  from %c => %c\n", n, from, to);
		homework_2017_10_26_hanoi(n - 1, buf, from, to);
	}
}