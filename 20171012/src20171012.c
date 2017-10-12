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

// Homework : 2017-10-12
// P77 2
void homework4_1(void)
{
	printf("Please input an English character: ");

	char ch = '\0';

	while (1 != scanf("%c", &ch) || !isalpha(ch))
	{
		printf("Inputs must be an English character.\n");

		ClearInputQueue();
	}
	
	ClearInputQueue();

	printf("result = %c\n", (isupper(ch)) ? tolower(ch) : ch);

	system("pause");
}

// Homework : 2017-10-12
// P77 7
int IsLeapYear(int year)
{
	return (
		(year % 4 == 0 && year % 100 != 0) && 
		year % 400 == 0 && 
		year >= 0
		) ? 1 : 0;
}

void homework4_2(void)
{
	int year = 0, month = 0, day = 0;

	/* DO NOT use switch-case block or if-else block.
	   Radom access of array will be faster than switch-case and if-else.
	   Moreover, this method uses less memory since J**s also take up memory.
	   J**s = JMP, JECXZ, JA, JB, JG, JL, JE, JZ, JS, JC, JO, JP ... on x86 CPU
	   */
	int daysLeap[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int daysNotLeap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

	printf("Please input a date as : `year,month,day` : ");

	while (1)
	{
		if (3 != scanf("%d,%d,%d", &year, &month, &day))
		{
			printf("Bad input. Please note the format : `year,month,day`.\nExample : 2007,12,3\n");

			// Clean the input queue if and only if the moment after input
			ClearInputQueue();

			continue;
		}

		if (year <= 0)
		{
			printf("Year is illegal.\n");
			continue; // #1
		}

		if (month < 1 || month > 12)
		{
			printf("Month is illegal.\n");
			continue; // #1
		}

		if (day < 1 || day > (IsLeapYear(year) ? daysLeap[month - 1] : daysNotLeap[month - 1]))
		{
			printf("Day is illegal.\n");
			continue; // #1
		}

		/* #1 : display assertions one by one. 
		   Or display all of them at the same time without `continue`.
		   The later design will be more customer-friendly in real programming project.
		   */
		break;
	}

	ClearInputQueue();

	int sum = 0;

	for (int i = 1; i < month; ++i)
	{
		sum += IsLeapYear(year) ? daysLeap[i - 1] : daysNotLeap[i - 1];
	}

	sum += day;

	printf("Its the %d%s day in this year.\n", sum, 
		/* using lookup table to display order numbers in English, 
		   such as 1st, 2nd, 3rd. 
		   This will be easier and faster than if-else blocks. */
		"st\0nd\0rd\0th" + 
			/* if the last digit of sum is 1, 2, 3 and it's not 11, 12, 13 */
			((sum % 10 > 0 && sum % 10 < 4 && sum % 100 != 11 && sum % 100 != 12 && sum % 100 != 13)
			/* then show *st *nd or *rd */
			? (sum % 10 - 1) * 3 
			/* or display *th instead */
			: 9)
	);

	system("pause");
}

// Homework : 2017-10-12
// P77 8
void homework4_3_1(void)
{
	printf("Following code will show you how to deal with narrow characters in C/C++.\n");
	printf("Please input a `char` and press `ENTER` to confirm : ");

	char ch = '\0';

	while (1)
	{
		ch = getchar();

		if (getchar() != '\n')
		{
			printf("Only one character, please! DO NOT enter a string or a wide character.\n");
			ClearInputQueue();
			continue;
		}

		break;
	}

	if (ch < 0)
	{
		printf("You probably give me a Chinese character or any other wide characters.\n");
	}
	else if (isalpha(ch))
	{
		printf("You give me an English character.\n");
	}
	else if (isdigit(ch))
	{
		printf("You give me a digit.\n");
	}
	/* I regard `¿Õ¸ñ` as blank since this will be closer with 
	   the situations in program design */
	else if (isblank(ch))
	{
		printf("You give me something blank.\n");
	}
	else
	{
		printf("Other kind of character is provided.\n");
	}

	system("pause");
}

void homework4_3_2(void)
{
	printf("Following code will show you how to deal with wide characters in C/C++.\n");
	printf("Please input a `char` and press `ENTER` to confirm : ");

	wchar_t ch;

	ch = getwchar();

	ClearInputQueue();

	/* The following result is associated with the locale settings. 
	   However, changing the global locale setting may not be a good idea. */
	if (iswalpha(ch))
	{
		printf("You give me an alphabetic letter.\n");
	}
	else if (iswdigit(ch))
	{
		printf("You give me a digit.\n");
	}
	/* I regard `¿Õ¸ñ` as blank since this will be closer with
	   the situations in program design. */
	else if (iswblank(ch))
	{
		printf("You give me something blank.\n");
	}
	else
	{
		printf("Other kind of character is provided.\n");
	}

	system("pause");
}

// Homework : 2017-10-12
// P77 9
void homework4_4(void)
{
	printf("Please tell me your weight (kg): ");

	double weight = 0.0, height = 0.0;

	while (1 != scanf("%lf", &weight) || weight <= 0)
	{
		printf("Input must be a positive real number.\n");

		ClearInputQueue();
	}

	ClearInputQueue();

	printf("Please tell me your height (m): ");

	while (1 != scanf("%lf", &height) || height <= 0)
	{
		printf("Input must be a positive real number.\n");

		ClearInputQueue();
	}

	ClearInputQueue();

	double t = weight / (height * height);

	if (t < 18)
	{
		printf("Underweight!\n");
	}
	else if (18 <= t && t < 25)
	{
		printf("Normal weight.\n");
	}
	else if (25 <= t && t < 27)
	{
		printf("Overweight!\n");
	}
	else
	{
		printf("Obese!\n");
	}

	system("pause");
}