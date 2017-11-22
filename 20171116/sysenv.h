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
 * C SysEnv
 *
 * Author : Oxdc
 * Email : frnet2016@gmail.com
 *
 * Last update : 2017-11-21
 * Version : 0.0.0.1 (dev)
 */

#ifndef _SYSENV_H_
#define _SYSENV_H_

#define WIN32

#include<stdio.h>
#include<stdlib.h>

int ConsoleWidth(void);
int ConsoleHeight(void);

#if defined(WIN32) || defined(WIN64)

#include<Windows.h>
#include<conio.h> 
#define ClearConsoleWindow() system("cls");
#define Pause() system("pause");
#define Wait(x) Sleep(x);

void GetConsoleInfo(CONSOLE_SCREEN_BUFFER_INFO * _i);

#elif defined(LINUX)

#include<unistd.h>
#include<sys/ioctl.h>
#define ClearConsoleWindow() system("clear");
#define Pause()													\
			printf("Please press ENTER to continue.\n");		\
			while(getchar()!='\n');
#define Wait(x) usleep((x) * 1000);

void GetConsoleInfo(struct winsize * _i);

#endif

#define CCT_STDERR_LOG(msg)										\
			perror(msg);										\
			Pause();											\
			exit(EXIT_FAILURE);

#endif // !_SYSENV_H_
