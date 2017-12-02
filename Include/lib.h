#pragma warning(disable : 4996) // Disable _CRT_SECURE_WARNINGS on Visual Studio

#ifndef _LIB_H_OF_C_HOMEWORK_
#define _LIB_H_OF_C_HOMEWORK_

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b)

#define ClearInputQueue() while (getchar() != '\n') continue;
#ifndef BOOL
#define BOOL short
#endif // !BOOL

#define TRUE 1
#define FALSE 0

#define LineBreak() putchar('\n');

#endif // !_LIB_H_OF_C_HOMEWORK_
