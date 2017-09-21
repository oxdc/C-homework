/*
 * This is the source file of a test-only program
 *
 */

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

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// You may need to change the following line if you have moved `main.h`
#include "../main.h"

// Homework : 2017-09-21
// P38 2
void homework1_2(void)
{
    int iNum1 = 0, iNum2 = 0;

    printf("Please enter two integers:");

    while(scanf("%d %d", &iNum1, &iNum2) != 2)
    {
        printf("Inputs must be integers.\n");

		// Clear input queue
        while(getchar() != '\n')
            continue;
    }

	while (getchar() != '\n')
		continue;

    int max = (iNum1 < iNum2) ? iNum2 : iNum1;

    printf("The square root of the maximum number = %lf\n", sqrt(max));

    system("pause");
}

// Homework : 2017-09-21
// P38 3
void homework1_3(void)
{
	double inputNum = 0.0;

	printf("Please enter a real number:");

	while (scanf("%lf", &inputNum) != 1)
	{
		printf("Inputs must be a real number.\n");
		while (getchar() != '\n')
			continue;
	}

	while (getchar() != '\n')
		continue;

	printf("x = %lf, x^2 = %lf and sqrt(x) = %lf\n", inputNum, inputNum * inputNum, sqrt(inputNum));

	system("pause");
}

// Homework : 2017-09-21
// P38 4
void homework1_4(void)
{
	double real1 = 0.0, real2 = 0.0, real3 = 0.0, real4 = 0.0;

	printf("Please enter 4 real numbers:");

	while (scanf("%lf %lf %lf %lf", &real1, &real2, &real3, &real4) != 4)
	{
		printf("Inputs must be real numbers.\n");
		while (getchar() != '\n')
			continue;
	}

	while (getchar() != '\n')
		continue;

	printf("Average = %lf\n", (real1 + real2 + real3 + real4) / 4.0);

	system("pause");
}