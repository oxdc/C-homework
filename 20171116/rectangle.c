#include "rectangle.h"

pCharRectangle InitCharRectangle(
	pCharRectangle _r,
	int _x,
	int _y,
	int _height,
	int _width,
	char _mark
)
{
	if (_r == NULL) return NULL;

	_r->_this = _r;
	_r->x = _x;
	_r->y = _y;

	if (_y + _height > ConsoleHeight())
	{
		printf("WARNING : The window is too narrow to display the"
			"rectangle. The height of the rectangle is larger than"
			" the height of the console window, which means you "
			"may not be able to see the whole rectangle in some"
			"console, especially on Linux");
	}
	
	_r->height = _height;

	if (_x + _width > ConsoleWidth())
	{
		printf("WARNING : The window is too narrow to display the"
			"rectangle. The width of the rectangle is larger than"
			" the width of the console window. The rectangle width"
			" has been reset as : %d\n", ConsoleWidth() - _x);
		_r->width = ConsoleWidth() - _x;
	}
	else
	{
		_r->width = _width;
	}

	_r->mark = _mark;

	return _r;
}

void Draw(
	CharRectangleList _r,
	size_t _size
)
{
	ClearConsoleWindow();

	if (_r == NULL)
	{
		CCT_STDERR_LOG("Cannot draw an empty rectangle list.");
	}

	int max_height = 0;
	size_t i;
	for (i = 0; i < _size; ++i)
	{
		max_height = 
			(_r[i].height + _r[i].y > max_height) ? 
			_r[i].height + _r[i].y : 
			max_height;
	}
	const int width = ConsoleWidth() - 2, height = max_height;

	char ** display_layer;
	display_layer = (char**)malloc(height * sizeof(char*));

	{
		int i;
		for (i = 0; i < height; ++i)
		{
			display_layer[i] = (char*)malloc((width + 2) * sizeof(char));
			memset(display_layer[i], ' ', width);
			display_layer[i][width] = '\n';
			display_layer[i][width + 1] = '\0';
		}
	}

	{
		size_t i;
		for (i = 0; i < _size; ++i)
		{
			if (_r[i].x + _r[i].width > width)
			{
				printf("WARNING : The window is too narrow to display "
						"rectangle No. %d\n", i);
			}

			int row;
			for (row = 0; row < height; ++row)
			{
				int col;
				for (col = 0; col < width; ++col)
				{
					if (((row == _r[i].x || row == _r[i].x + _r[i].height - 1) && 
							col >= _r[i].y && 
							col <= _r[i].y + _r[i].width - 1) ||
						((col == _r[i].y || col == _r[i].y + _r[i].width - 1) && 
							row >= _r[i].x && 
							row <= _r[i].x + _r[i].height - 1))
					{
						display_layer[row][col] = _r[i].mark;
					}
				}
			}
		}
	}
	
	{
		int row;
		for (row = 0; row < height; ++row)
		{
			printf("%s", display_layer[row]);
		}
	}

	{
		int i;
		for (i = 0; i < height; ++i)
		{
			free(display_layer[i]);
		}
		free(display_layer);
	}
}