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
 * C Auto Allocate Memory and Free
 *
 * Author : Oxdc
 * Email : frnet2016@gmail.com
 *
 * Last update : 2017-12-08
 * Version : 0.0.0.2 (dev)
 */

#ifndef _AUTO_ALLOC_H_
#define _AUTO_ALLOC_H_

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#ifdef VISUALSTUDIO
#pragma warning(disable : 4996)
#endif // VISUALSTUDIO

typedef struct __CCT_Heap_Buf {
	char* pBuf;
	size_t size;
} _CCT_Heap_Buf;

typedef int _cct_BOOL;
#define TRUE 1
#define FALSE 0

#define _CCT_FATAL_ERR_LOG(msg)												\
			perror("Fatal error. " #msg "");								\
			exit(EXIT_FAILURE)

void _CCT_autoalloc_InitBuf(void);
void* _CCT_autoalloc_AllocateMemory(size_t size);
void _CCT_autoalloc_AddToBuffer(char* p_new, size_t size);
void _CCT_autoalloc_FreeMemory(void);
void _CCT_autoalloc_DeleteItem(void* p_existed);
int _CCT_autoalloc_Search(void* p_existed);
void _CCT_autoalloc_DeleteFromBuffer(size_t loc);
void _CCT_autoalloc_DisplayAll(void);
size_t _CCT_autoalloc_GetBufferSize(void* p_existed);
void* _CCT_autoalloc_Clone(void* p_existed);

#define _CCT_IS_INIT()														\
			(_cct_buf != NULL &&											\
			_cct_isReg != FALSE &&											\
			_cct_buf_size != 0)

#define _CCT_CHECK_INIT()													\
			if(!_CCT_IS_INIT())												\
				_CCT_autoalloc_InitBuf()

#define New(type,size)														\
			(type*)_CCT_autoalloc_AllocateMemory(							\
					(size) * sizeof(type))

#define Clone(pointer)														\
			_CCT_autoalloc_Clone((pointer))

#define Delete(pointer)														\
			_CCT_autoalloc_DeleteItem((pointer))

#define SizeOf(pointer)														\
			_CCT_autoalloc_GetBufferSize((pointer))

#define CountOf(pointer,type)												\
			(_CCT_autoalloc_GetBufferSize((pointer)) / sizeof(type))

#define FreeHeap()															\
			_CCT_autoalloc_FreeMemory()

#define IsAllocated(pointer)												\
			((_CCT_autoalloc_Search((pointer)) > 0) ?						\
				TRUE :														\
				FALSE)

#define DisplayHeap()														\
			_CCT_autoalloc_DisplayAll()

#define ForEach(item,pointer,type)											\
			for(															\
				type* item = (type*)((pointer));							\
				item != (type*)((pointer)) +								\
					SizeOf((pointer)) / sizeof(type);						\
				++item														\
			)

#define $(pointer)															\
			*((pointer))

#define GetItem(pointer,loc,type)											\
			(*((type*)((pointer)) + (CountOf(pointer,type) + loc) %			\
					CountOf(pointer,type)))

#endif // !_AUTO_ALLOC_H_
