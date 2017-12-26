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

#include "sysenv.h"

#if defined(WIN32) || defined(WIN64)
void GetConsoleInfo(CONSOLE_SCREEN_BUFFER_INFO * _i)
{
	if (_i == NULL)
	{
		CCT_STDERR_LOG("Cannot assign info to a null pointer.");
	}

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (handle == INVALID_HANDLE_VALUE)
	{
		CCT_STDERR_LOG("Cannot get stdout handle.");
	}

	if (!GetConsoleScreenBufferInfo(handle, _i))
	{
		CCT_STDERR_LOG("Cannot get console info.");
	}
}
#elif defined(LINUX)
void GetConsoleInfo(struct winsize * _i)
{
	if (!isatty(STDOUT_FILENO))
	{
		CCT_STDERR_LOG("No such file or directory.");
	}

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, _i) < 0)
	{
		CCT_STDERR_LOG("Cannot get console window size.");
	}
}
#endif

int ConsoleWidth(void)
{
#if defined(WIN32) || defined(WIN64)

	CONSOLE_SCREEN_BUFFER_INFO console_screen_info;
	GetConsoleInfo(&console_screen_info);
	return console_screen_info.dwSize.X;

#elif defined(LINUX)

	struct winsize console_screen_info;
	GetConsoleInfo(&console_screen_info);
	return console_screen_info.ws_col;

#endif
}

int ConsoleHeight(void)
{
#if defined(WIN32) || defined(WIN64)

	CONSOLE_SCREEN_BUFFER_INFO console_screen_info;
	GetConsoleInfo(&console_screen_info);
	return console_screen_info.dwSize.Y;

#elif defined(LINUX)

	struct winsize console_screen_info;
	GetConsoleInfo(&console_screen_info);
	return console_screen_info.ws_row;

#endif
}

void ClearConsoleWindow_(void)
{
	ClearConsoleWindow();
}

void Pause_(void)
{
	Pause();
}

void FlushStdin_(void)
{
	setbuf(stdin, NULL);
}

void Wait_(unsigned int milliseconds)
{
	Wait(milliseconds);
}
void SetCursorPos_(int x, int y)
{
#if defined(WIN32) || defined(WIN64)
	COORD cursorPosition;
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
#elif defined(LINUX)
#endif
}

const struct _Console_CCT_ Console = {
	ConsoleWidth,
	ConsoleHeight,
	ClearConsoleWindow_,
	Pause_,
	FlushStdin_,
	Wait_,
	SetCursorPos_
};
