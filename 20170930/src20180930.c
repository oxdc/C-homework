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

#define PI 3.14159

// Homework : 2017-09-28
// P36 18
void homework3_1(void)
{
	double x = 1.2, y = 3.4, z = 2.2, u = 5.6, c = 3.2, a = 3.1, b = 0.3, R = 0.222;

	printf("IF...x = 1.2, y = 3.4, z = 2.2, u = 5.6, c = 3.2, a = 3.1, b = 0.3, R = 0.222 Then \n");
	printf("|(x + y)(z + u) + 2c| = %f\n", fabs((x + y) * (z + u) + 2 * c));
	printf("\\frac{\\pi r^2}{a + b} = %f\n", PI * R * R / (a + b));
	printf("\\frac{\\log ( x + \\cos y)}{3} = %f\n", log(x + cos(y)) / 3);
	printf("4x^2+2e^y = %f\n", 4 * x * x + 2 * exp(y));
	printf("4\\pi R^2 = %f\n", 4 * PI * R * R);

	system("pause");
}

// Homework : 2017-09-28
// P56 2
void homework3_2(void)
{
	printf("Please input the radius of a circle: ");

	double r = 0.0;

	while (1 != scanf("%lf", &r) || r <= 0.0)
	{
		printf("Input must be a positive real number.\n");
		ClearInputQueue();
	}

	ClearInputQueue();

	printf("perimeter = %.2f, area = %.2f\n", 2 * PI * r, PI * r * r);

	system("pause");
}

// Homework : 2017-09-28
// P56 3
void homework3_3(void)
{
	printf("Please input the temperature in Fahrenheit scale: ");

	double tmp = 0.0;

	while (1 != scanf("%lf", &tmp))
	{
		printf("Input must be a real number.\n");
		ClearInputQueue();
	}

	ClearInputQueue();
	
	if (tmp <= -169.52778)
	{
		printf("\aWow, you broke the Third Law of Thermodynamics. :( :( :(\a\n");
	}

	printf("Equals to %.2f in Celsius scale.\n", 5.0 * (tmp - 32) / 9.0);

	system("pause");
}

// Homework : 2017-09-28
// P56 5
void homework3_4(void)
{
	printf("\aI don\'t know the reason\b why\b there\t still\r exist\v such a \"stupid\" problem. \?%%\n");

	system("pause");
}