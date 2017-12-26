/*
 * This file is part of the CppCommonTools distribution
 * Copyright (c) 2017 Oxdc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * C Tiny Exception - Try-Catch-Finally
 *
 * Author : Oxdc
 * Email : frnet2016@gmail.com
 *
 * Last update : 2017-12-23
 * Version : 0.0.0.1 (dev)
 */

#ifndef _TINY_EXCEPTION_H_
#define _TINY_EXCEPTION_H_

#define WIN32

#include<stdio.h>
#include<stdlib.h>
#include "autoalloc.h"

#if defined(WIN32) || defined(WIN64)
#include<Windows.h>
#endif

#define VISUALSTUDIO
#ifdef VISUALSTUDIO
#pragma warning(disable : 4996)
#endif // VISUALSTUDIO

typedef struct CCT_Tiny_Exception__ {
	const char * message;
} Exception;

extern Exception ** exception_items;

Exception Exception__(const char * msg);
void throw__f(Exception e);
void AddException();
int CheckException();
void DisplayExceptionMessage__f(Exception e);

#define NULL_EXCEPTION												\
	Exception__(NULL)

#define Throw(expression)											\
	throw__f(expression);											\
	return

#define Try															\
	AddException();													\
	for(int __try_loop = 0; __try_loop < 1; ++__try_loop)

#define Catch(expression)											\
	for(															\
		expression =												\
			((exception_items[0] == NULL) ?							\
			NULL_EXCEPTION :										\
			*(exception_items[0]));									\
		CheckException();											\
	)

#define Finally														\
	for(int __finally_loop = 0; __finally_loop < 1;					\
		++ __finally_loop)

#define check_exception__											\
	;																\
	if(exception_items[0] != NULL)									\
		break

#if defined(WIN32) || defined(WIN64)
#define DisplayExceptionMessage(e)									\
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),		\
		0xC);														\
	printf("%s %d %s\n\t", __FILE__, __LINE__, __FUNCTION__);		\
	DisplayExceptionMessage__f(e);									\
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),		\
		0x7)
#elif defined(LINUX)
#define DisplayExceptionMessage(e)									\
	printf("%s %d %s\n\t", __FILE__, __LINE__, __FUNCTION__);		\
	DisplayExceptionMessage__f(e)
#endif

#endif // !_TINY_EXCEPTION_H_
