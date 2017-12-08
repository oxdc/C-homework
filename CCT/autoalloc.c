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

#include "autoalloc.h"

_cct_BOOL _cct_isReg = FALSE;
_CCT_Heap_Buf ** _cct_buf = NULL;
size_t _cct_buf_size = 0;

void _CCT_autoalloc_InitBuf(void)
{
	if (!_cct_isReg && !atexit(_CCT_autoalloc_FreeMemory))
	{
		_cct_isReg = TRUE;
	}

	if (_cct_buf == NULL)
	{
		_cct_buf = (_CCT_Heap_Buf**)malloc(sizeof(_CCT_Heap_Buf*));
		_CCT_Heap_Buf * head = (_CCT_Heap_Buf*)malloc(sizeof(_CCT_Heap_Buf));
		if (_cct_buf == NULL || head == NULL)
		{
			_CCT_FATAL_ERR_LOG("Cannot allocate memory.");
		}
		head->pBuf = (char*)_cct_buf;
		head->size = 1;
		_cct_buf[0] = head;
		_cct_buf_size = 1;
	}
}

void * _CCT_autoalloc_AllocateMemory(size_t size)
{
	_CCT_CHECK_INIT();

	if (size == 0)
	{
		return NULL;
	}

	char * new_buffer = (char*)malloc(size);
	
	if (new_buffer == NULL)
	{
		perror("Cannot allocate memory.");
		return NULL;
	}

	_CCT_autoalloc_AddToBuffer(new_buffer, size);

	return new_buffer;
}

void _CCT_autoalloc_AddToBuffer(char* p_new, size_t size)
{
	_CCT_CHECK_INIT();

	if (p_new == NULL || size == 0)
	{
		return;
	}

	_CCT_Heap_Buf ** p_new_buf = 
		(_CCT_Heap_Buf**)malloc((_cct_buf_size + 1) * sizeof(_CCT_Heap_Buf*));
	_CCT_Heap_Buf * newItem = (_CCT_Heap_Buf*)malloc(sizeof(_CCT_Heap_Buf));

	if (p_new_buf == NULL || newItem == NULL)
	{
		_CCT_FATAL_ERR_LOG("Cannot allocate memory.");
	}

	memcpy(p_new_buf, _cct_buf, _cct_buf_size * sizeof(_CCT_Heap_Buf*));

	free(_cct_buf);

	_cct_buf = p_new_buf;
	newItem->pBuf = p_new;
	newItem->size = size;
	_cct_buf[_cct_buf_size] = newItem;
	_cct_buf[0]->pBuf = (char*)_cct_buf;
	_cct_buf_size++;
}

void _CCT_autoalloc_FreeMemory(void)
{
	if (_cct_buf == NULL)
	{
		return;
	}

	size_t seek;
	for (seek = 1; seek < _cct_buf_size; ++seek)
	{
		if (_cct_buf[seek]->pBuf != NULL)
		{
			free(_cct_buf[seek]->pBuf);
			free(_cct_buf[seek]);
			_cct_buf[seek] = NULL;
		}
	}
	free(_cct_buf[0]);
	free(_cct_buf);
	_cct_buf = NULL;
	_cct_buf_size = 0;
}

void _CCT_autoalloc_DeleteItem(void* p_existed)
{
	if (p_existed == NULL ||
		!_CCT_IS_INIT() ||
		_cct_buf == NULL)
	{
		return;
	}

	int loc = _CCT_autoalloc_Search(p_existed);
	if (loc == -1)
	{
		perror("Memory block not found. Process terminated.");
		return;
	}

	_CCT_autoalloc_DeleteFromBuffer((size_t)loc);

	free(p_existed);
}

int _CCT_autoalloc_Search(void* p_existed)
{
	if (p_existed == NULL || 
		!_CCT_IS_INIT() || 
		_cct_buf == NULL)
	{
		return -1;
	}

	size_t seek;
	for (seek = 1; seek < _cct_buf_size; ++seek)
	{
		if ((void*)_cct_buf[seek]->pBuf == p_existed)
		{
			return (int)seek;
		}
	}

	return -1;
}

void _CCT_autoalloc_DeleteFromBuffer(size_t loc)
{
	if (loc < 0 ||
		loc >= _cct_buf_size)
	{
		perror("Out of range");
		return;
	}

	if (!_CCT_IS_INIT() ||
		_cct_buf == NULL ||
		_cct_buf_size <= 1)
	{
		perror("Out of range");
		return;
	}

	_CCT_Heap_Buf ** p_new_buf = 
		(_CCT_Heap_Buf**)malloc((_cct_buf_size - 1) * sizeof(_CCT_Heap_Buf*));

	if (p_new_buf == NULL)
	{
		_CCT_FATAL_ERR_LOG("Cannot allocate memory.");
	}

	memcpy(p_new_buf, 
		_cct_buf, 
		loc * sizeof(_CCT_Heap_Buf*));
	memcpy(p_new_buf + loc, 
		_cct_buf + loc + 1,
		(_cct_buf_size - loc - 1) * sizeof(_CCT_Heap_Buf*));

	free(_cct_buf);
	_cct_buf = p_new_buf;
	_cct_buf[0]->pBuf = (char*)p_new_buf;
	_cct_buf_size--;
}

void _CCT_autoalloc_DisplayAll(void)
{
	if (!_CCT_IS_INIT() ||
		_cct_buf == NULL ||
		_cct_buf_size <= 1)
	{
		printf("Null.\n");
		return;
	}

	printf("Heap group: buf @ %p | size %zu\n", 
		_cct_buf, 
		_cct_buf_size);

	size_t seek;
	printf("  Head     : buf @ %p | size %zu\n",
		_cct_buf[0]->pBuf,
		_cct_buf[0]->size);
	for (seek = 1; seek < _cct_buf_size; ++seek)
	{
		printf("  Item %3zu : buf @ %p | size %zu\n", 
			seek, 
			_cct_buf[seek]->pBuf, 
			_cct_buf[seek]->size);
	}
}

size_t _CCT_autoalloc_GetBufferSize(void * p_existed)
{
	if (p_existed == NULL ||
		!_CCT_IS_INIT() ||
		_cct_buf == NULL)
	{
		perror("Empty heap. Process terminated.");
		return 0;
	}

	int loc = _CCT_autoalloc_Search(p_existed);
	if (loc == -1)
	{
		perror("Memory block not found. Process terminated.");
		return 0;
	}
	
	return _cct_buf[loc]->size;
}

void* _CCT_autoalloc_Clone(void* p_existed)
{
	if (p_existed == NULL ||
		!_CCT_IS_INIT() ||
		_cct_buf == NULL)
	{
		perror("Empty heap. Process terminated.");
		return NULL;
	}

	int loc = _CCT_autoalloc_Search(p_existed);
	if (loc == -1)
	{
		perror("Memory block not found. Process terminated.");
		return NULL;
	}

	char * new_buffer_to_clone = _CCT_autoalloc_AllocateMemory(_cct_buf[loc]->size);
	memcpy(new_buffer_to_clone, p_existed, _cct_buf[loc]->size);

	return new_buffer_to_clone;
}