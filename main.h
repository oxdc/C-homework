/*
 * This is the header file of a test-only program
 *
 */

/*
 * ��Build pass@Visual Studio 2017/Codeblocks with Windows10x64 Professional��
 *
 * If you have any problem, Email me : frnet2016@gmail.com or tell me via QQ
 *
 */

/*
 * ##########################################################################
 * #                                                                        #
 * #                           ATTENTION PLEASE                             #
 * #                                                                        #
 * ##########################################################################
 *
 * I have used a special line below since I'm using Visual Studio 2017. Delete
 * it unless you are using the same compiler.
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#pragma warning(disable : 4996) // Disable _CRT_SECURE_WARNINGS on Visual Studio

inline void ClearInputQueue();
int compare_int(const void * num1, const void * num2);

void homework1_2(void);
void homework1_3(void);
void homework1_4(void);

void homework2_1(void);
void homework2_2(void);
void homework2_3(void);
void homework2_4(void);
void homework2_5(void);

void ClearInputQueue()
{
	while (getchar() != '\n')
		continue;
}