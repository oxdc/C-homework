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
		ClearInputQueue();
    }

	ClearInputQueue();

    int max = (iNum1 < iNum2) ? iNum2 : iNum1;

    printf("The square root of the maximum number = %f\n", sqrt(max));

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

		ClearInputQueue();
	}

	ClearInputQueue();

	printf("x = %f, x^2 = %f and x^3 = %f\n", inputNum, inputNum * inputNum, inputNum * inputNum * inputNum);

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

		ClearInputQueue();
	}

	ClearInputQueue();

	printf("Average = %f\n", (real1 + real2 + real3 + real4) / 4.0);

	system("pause");
}