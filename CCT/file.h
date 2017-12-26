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
 * C File Helper
 *
 * Author : Oxdc
 * Email : frnet2016@gmail.com
 *
 * Last update : 2017-12-23
 * Version : 0.0.0.1 (dev)
 */

#ifndef _CCT_FILE_
#define _CCT_FILE_

#include<stdio.h>
#include<stdlib.h>
#include "tinyexception.h"

#define VISUALSTUDIO
#ifdef VISUALSTUDIO
#pragma warning(disable : 4996)
#endif // VISUALSTUDIO

typedef FILE* FileStream;

FileStream _CCT_file_OpenFile(const char * fileName, const char * mode);
void _CCT_file_CloseFile(FileStream stream);

#define OpenFile(fileName, mode)											\
	_CCT_file_OpenFile(fileName, mode) check_exception__
#define CloseFile(fileStream)												\
	_CCT_file_CloseFile(fileStream) check_exception__

#endif // _CCT_FILE_
