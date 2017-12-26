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

#include "file.h"

FileStream _CCT_file_OpenFile(const char * fileName, const char * mode)
{
	if (fileName == NULL)
	{
		Throw(Exception__("IOException: No file name is gaven.")) NULL;
	}

	if (mode == NULL)
	{
		Throw(Exception__("IOException: No open mode is gaven.")) NULL;
	}

	FileStream fs = fopen(fileName, mode);

	if (fs == NULL)
	{
		Throw(Exception__("IOException: Cannot open the file.")) NULL;
	}

	return fs;
}

void _CCT_file_CloseFile(FileStream stream)
{
	if (stream == NULL)
	{
		Throw(Exception__("IOException: Invalid stream."));
	}

	if (0 != fclose(stream))
	{
		Throw(Exception__("IOException: An error occured when trying to close the file."));
	}
}
