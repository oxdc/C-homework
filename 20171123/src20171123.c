#include "h20171123.h"

void homework_2017_11_23_main(void)
{
	homework_1();
	homework_2();
	homework_3();
	homework_4();
	homework_5();
	homework_p160_8();
	homework_p160_9();
	homework_p160_12();
}

void homework_1(void)
{
	ClearConsoleWindow();
	printf("Please input 10 integers: \n");

	int ints[10] = { 0 };
	int i;
	int input = 0;

	for (i = 0; i < 10; ++i)
	{
		printf("Give me the NO.%d integer: ", i);
		while (1 != scanf("%d", &input))
		{
			printf("Input must be an integer!\n");
			ClearInputQueue();
		}
		ClearInputQueue();
		ints[i] = input;
	}

	printf("The numbers you gave are as follows: \n");
	for (i = 0; i < 10; ++i)
	{
		printf("%d\t", ints[i]);
	}
	putchar('\n');

	SelectionSort(ints, sizeof(int), 10, int_comparing);

	printf("After sorting: \n");
	for (i = 0; i < 10; ++i)
	{
		printf("%d\t", ints[i]);
	}
	putchar('\n');
	Pause();
}

void homework_2(void)
{
	ClearConsoleWindow();
	printf("A simple test for MyStrlen(): \n");
	printf("The length of \"Hello, world!\" is %d.\n",
		MyStrlen("Hello, world!"));
	Pause();
}

void homework_3(void)
{
	ClearConsoleWindow();
	printf("A simple test for MyStrcmp(): \n");
	printf("MyStrcmp(\"HelloWorld!\", \"Hello\") = %d"
		", strcmp(\"HelloWorld!\", \"Hello\") = %d\n",
		MyStrcmp("HelloWorld!", "Hello"), 
		strcmp("HelloWorld!", "Hello"));
	printf("MyStrcmp(\"love\", \"abandon\") = %d"
		", strcmp(\"love\", \"abandon\") = %d\n",
		MyStrcmp("love", "abandon"), 
		strcmp("love", "abandon"));
	printf("MyStrcmp(\"ABC\", \"D\") = %d"
		", strcmp(\"ABC\", \"D\") = %d\n",
		MyStrcmp("ABC", "D"), 
		strcmp("ABC", "D"));
	printf("MyStrcmp(\"efg\", \"www\") = %d"
		", strcmp(\"efg\", \"www\") = %d\n",
		MyStrcmp("efg", "www"), 
		strcmp("efg", "www"));
	Pause();
}

void homework_4(void)
{
	ClearConsoleWindow();
	printf("Please input 10 English words: \n");
	char words[10][50];
	char * ref[10];
	int i;
	for (i = 0; i < 10; ++i)
	{
		scanf("%s", words[i]);
		ref[i] = words[i];
	}
	ClearInputQueue();

	printf("The words you gave: \n");
	for (i = 0; i < 10; ++i)
	{
		printf("%s\t", ref[i]);
	}
	putchar('\n');
	
	SelectionSort(ref, sizeof(char*), 10, char_comparing);

	printf("After sorting: \n");
	for (i = 0; i < 10; ++i)
	{
		printf("%s\t", ref[i]);
	}
	putchar('\n');

	Pause();
}

void homework_5(void)
{
	ClearConsoleWindow();

	printf(
		" ############  WARNING ############\n"
		" ### Please make sure you have  ###\n"
		" ### put the txt file in the    ###\n"
		" ### right place. Or the pro-   ###\n"
		" ### gram may crash. :)         ###\n"
		" ##################################\n"
		" For more information, see the code\n"
		" or read README.txt\n");
	Pause();

	ClearConsoleWindow();
	char * text = NULL;
	ReadFromFile("..\\..\\20171123\\text.txt", &text);
	CharStat(text);
	free(text);
	Pause();
}

void homework_p160_8(void)
{
	ClearConsoleWindow();
	srand((unsigned int)time(NULL));
	Matrix mat_random;
	InitMatrix(&mat_random, 5, 6, sizeof(int));
	
	int i, j;
	for (i = 0; i < 5; i++)
	{
		printf("    | ");
		for (j = 0; j < 6; j++)
		{
			*(int*)At(&mat_random, i, j) = rand();
			printf("%6d ", *(int*)At(&mat_random, i, j));
		}
		printf(" |\n");
	}
	putchar('\n');

	SaddlePoint(&mat_random);

	printf("It's seems impossible to generate a random matrix with "
		"saddle points. So I also give an example here :\n");

	*(int*)At(&mat_random, 0, 0) = 1;
	*(int*)At(&mat_random, 0, 1) = 2;
	*(int*)At(&mat_random, 0, 2) = 3;
	*(int*)At(&mat_random, 0, 3) = 4;
	*(int*)At(&mat_random, 0, 4) = 5;
	*(int*)At(&mat_random, 0, 5) = 2;

	*(int*)At(&mat_random, 1, 0) = 6;
	*(int*)At(&mat_random, 1, 1) = 7;
	*(int*)At(&mat_random, 1, 2) = 9;
	*(int*)At(&mat_random, 1, 3) = 3;
	*(int*)At(&mat_random, 1, 4) = 6;
	*(int*)At(&mat_random, 1, 5) = 3;

	*(int*)At(&mat_random, 2, 0) = 1;
	*(int*)At(&mat_random, 2, 1) = 1;
	*(int*)At(&mat_random, 2, 2) = 1;
	*(int*)At(&mat_random, 2, 3) = 1;
	*(int*)At(&mat_random, 2, 4) = 7;
	*(int*)At(&mat_random, 2, 5) = 1;

	*(int*)At(&mat_random, 3, 0) = 1;
	*(int*)At(&mat_random, 3, 1) = 1;
	*(int*)At(&mat_random, 3, 2) = 1;
	*(int*)At(&mat_random, 3, 3) = 1;
	*(int*)At(&mat_random, 3, 4) = 7;
	*(int*)At(&mat_random, 3, 5) = 1;

	*(int*)At(&mat_random, 4, 0) = 1;
	*(int*)At(&mat_random, 4, 1) = 1;
	*(int*)At(&mat_random, 4, 2) = 1;
	*(int*)At(&mat_random, 4, 3) = 1;
	*(int*)At(&mat_random, 4, 4) = 5;
	*(int*)At(&mat_random, 4, 5) = 1;

	for (i = 0; i < 5; i++)
	{
		printf("    | ");
		for (j = 0; j < 6; j++)
		{
			printf("%6d ", *(int*)At(&mat_random, i, j));
		}
		printf(" |\n");
	}
	putchar('\n');

	SaddlePoint(&mat_random);

	printf("IMPORTANT: I also added a necessary condition to the "
		"definition of saddle point : they must be splitted, which"
		" will be better, but not perfect yet. :)\n");
	FreeMatrix(&mat_random);
	Pause();
}

void homework_p160_9(void)
{
	ClearConsoleWindow();
	Matrix mat;
	InitMatrix(&mat, 5, 5, sizeof(int));

	int i, j;
	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			*(int*)At(&mat, i, j) = j + 1;
		}
	}

	printf("A = \n");
	for (i = 0; i < 5; ++i)
	{
		printf("    | ");
		for (j = 0; j < 5; ++j)
		{
			printf("%5d ", *(int*)At(&mat, i, j));
		}
		printf(" |\n");
	}

	printf("tr(A) = %ld\n", TrOfMatrix_int(&mat, 5));
	FreeMatrix(&mat);
	Pause();
}

void homework_p160_12(void)
{
	ClearConsoleWindow();
	printf("Please input a sentence with no more than 500 characters: \n");
	char line[501];
	char result[501];
	if (!ReadLine(line, 501))
	{
		return;
	}

	int i, j;
	int count = 0;
	for (i = 0, j = 0; i < 501 && j < 501; ++i)
	{
		// Skip wide characters
		if (line[i] >= 0 && isspace(line[i]))
		{
			if (!count)
			{
				result[j++] = ' ';
			}
			count++;
		}
		else
		{
			count = 0;
			result[j++] = line[i];
		}
	}

	printf("\nThe result:\n%s\n", result);
	Pause();
}

void Swap(
	 void*	item1,
	 void*	item2,
	size_t	size
)
{
	while (size-- > 0)
	{
		char buf = ((char*)item1)[size];
		((char*)item1)[size] = ((char*)item2)[size];
		((char*)item2)[size] = buf;
	}
}

void SelectionSort(
	 void*	buf,
	size_t	size,
	size_t	length,
	   int	(*comparing)(void*, void*)
)
{
	char * _buf = (char*)buf;
	char * selected_item = (char*)buf;

	size_t top, seek;
	for (top = 0; top < length - 1; ++top)
	{
		selected_item = _buf + top * size;
		for (seek = top + 1; seek < length; ++seek)
		{
			if (comparing(selected_item, _buf + seek * size) > 0)
			{
				selected_item = _buf + seek * size;
			}
		}

		Swap(_buf + top * size, selected_item, size);
	}
}

int int_comparing(
	void* i1,
	void* i2
)
{
	return *(int*)i1 - *(int*)i2;
}

int char_comparing(
	void* ch1,
	void* ch2
)
{
	return strcmp(*(char**)ch1, *(char**)ch2);
}

size_t MyStrlen(const char * str)
{
	size_t length = 0;

	while (str[length++] != '\0')
		continue;

	return length - 1;
}

BOOL MyStrcmp(
	const char*	str1, 
	const char*	str2
)
{
	int i = 0;

	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i] > 0) ? 1 : -1;
		}
		i++;
	}

	return 0;
}

char ** ReadFromFile(
	const char*  file_name,
		 char**	 buffer
)
{
	FILE * pf = fopen(file_name, "r");

	if (pf == NULL)
	{
		CCT_STDERR_LOG("Cannot open the file.");
	}

	fseek(pf, 0L, SEEK_END);
	size_t file_length = ftell(pf);
	*buffer = (char*)malloc((file_length + 1) * sizeof(char));
	(*buffer)[file_length] = '\0';
	fseek(pf, 0L, SEEK_SET);

	char ch;
	size_t i = 0;
	while ((ch = getc(pf)) != EOF &&
		i < file_length)
	{
		(*buffer)[i++] = ch;
	}
	(*buffer)[i] = '\0';

	fclose(pf);
	return buffer;
}

int IsEnglishCharacters(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return ch - 'A';
	}

	if (ch >= 'a' && ch <= 'z')
	{
		return ch - 'a';
	}

	return -1;
}

void CharStat(const char * str)
{
	if (str == NULL)
	{
		return;
	}

	int stat[26] = { 0 };
	int i = 0, sum = 0;

	while (str[i] != '\0')
	{
		int c = IsEnglishCharacters(str[i]);
		if (c >= 0)
		{
			stat[c] += 1;
			sum++;
		}
		i++;
	}

	int max_num = 0;
	for (i = 0; i < 26; i++)
	{
		max_num = (stat[i] > max_num) ?
			stat[i] :
			max_num;
	}

	int window_width = ConsoleWidth();
	int bar_width = (window_width - 2) / 26;

	printf("Statistical results :\n");
	i = bar_width * 26;
	while (i-- > 0)
	{
		putchar('-');
	}
	putchar('\n');

	for (i = 0; i < 20; ++i)
	{
		char * display_buf = (char*)malloc(window_width * sizeof(char));
		memset(display_buf, ' ', (window_width - 2) * sizeof(char));
		
		int j;
		for (j = 0; j < 26; ++j)
		{
			if (stat[j] / (double)max_num * 20 > 19 - i)
			{
				display_buf[bar_width * j + bar_width / 2] = '#';
			}
		}

		display_buf[window_width - 2] = '\n';
		display_buf[window_width - 1] = '\0';

		printf("%s", display_buf);

		free(display_buf);
	}

	i = bar_width * 26;
	while (i-- > 0)
	{
		putchar('-');
	}
	putchar('\n');

	i = 0;
	int j = 0;
	while (i++ < window_width - 1)
	{
		if (i == (j * bar_width + bar_width / 2 + 1) &&
			j < 26)
		{
			putchar('A' + j);
			j++;
		}
		else
		{
			putchar(' ');
		}
	}
	putchar('\n');

	putchar(' ');
	for (i = 0; i < 26; i++)
	{
		double value = stat[i] / (double)sum * 100;
		printf(value < 10 ? "%-*.1f" : "%-*.0f", bar_width, value);
	}
	printf("\n\n\n");

	Pause();

	i = window_width - 1;
	while (i-- > 0)
	{
		putchar('-');
	}
	putchar('\n');

	printf("Statistical results :\n");
	for (i = 0; i < 26; i++)
	{
		double value = stat[i] / (double)sum * 100;
		printf(" %c : %6.3f %%  ", 'A' + i, value);
		int j = 0;
		while (j < window_width - 16)
		{
			if (stat[i] / (double)max_num > j / (double)(window_width - 16))
			{
				putchar('#');
			}
			else
			{
				putchar(' ');
			}
			j++;
		}
		putchar('\n');
	}

	i = window_width - 1;
	while (i-- > 0)
	{
		putchar('-');
	}
	putchar('\n');
}

void SquareConvolution(
	Matrix* map,
	int left_top_row,
	int left_top_col
)
{
	if (left_top_row < 0 || 
		left_top_row >= map->rows - 1 ||
		left_top_col < 0 ||
		left_top_col >= map->columns - 1)
	{
		CCT_STDERR_LOG("Out of range.");
	}

	if (
		(int)(*(int*)At(map, left_top_row, left_top_col)) +
		(int)(*(int*)At(map, left_top_row + 1, left_top_col)) +
		(int)(*(int*)At(map, left_top_row, left_top_col + 1)) +
		(int)(*(int*)At(map, left_top_row + 1, left_top_col + 1))
			> 2)
	{
		*(int*)At(map, left_top_row, left_top_col) = 2;
		*(int*)At(map, left_top_row + 1, left_top_col) = 2;
		*(int*)At(map, left_top_row, left_top_col + 1) = 2;
		*(int*)At(map, left_top_row + 1, left_top_col + 1) = 2;
	}
}

void SaddlePoint(
	Matrix* mat
)
{
	if (mat == NULL)
	{
		return;
	}

	// An array to store the maximum number of each row
	int * row_max = (int*)malloc(mat->rows * sizeof(int));
	// An array to store the minimum number of each column
	int * col_min = (int*)malloc(mat->columns * sizeof(int));
	memset(row_max, 0, mat->rows * sizeof(int));
	memset(col_min, 0, mat->columns * sizeof(int));

	int row, col;

	// To find the maximum number of each row
	for (row = 0; row < mat->rows; ++row)
	{
		int row_max_n = *(int*)At(mat, row, 0);
		for (col = 0; col < mat->columns; ++col)
		{
			if (*(int*)At(mat, row, col) > row_max_n)
			{
				row_max_n = *(int*)At(mat, row, col);
			}
		}
		row_max[row] = row_max_n;
	}

	// To find the minimum number of each column
	for (col = 0; col < mat->columns; ++col)
	{
		int col_min_n = *(int*)At(mat, 0, col);
		for (row = 0; row < mat->rows; ++row)
		{
			if (*(int*)At(mat, row, col) < col_min_n)
			{
				col_min_n = *(int*)At(mat, row, col);
			}
		}
		col_min[col] = col_min_n;
	}

	// A tiny "int"-map to store the distribution information
	// of all suspicious points
	Matrix map;
	InitMatrix(&map, mat->rows, mat->columns, sizeof(int));

	// If there exists a suspicious point, then give it a value 1
	for (row = 0; row < mat->rows; ++row)
	{
		for (col = 0; col < mat->columns; ++col)
		{
			if (*(int*)At(mat, row, col) == row_max[row] &&
				*(int*)At(mat, row, col) == col_min[col])
			{
				*(int*)At(&map, row, col) = 1;
			}
			else
			{
				*(int*)At(&map, row, col) = 0;
			}
		}
	}

	// To check each 2x2 square. If the total value is above
	// 2, it means that there are more than 2 suspicious points
	// in a 2x2 square, namely, they are "connected".
	// If so, give them a value 2, which shows that saddle points
	// must be splitted.
	// 
	// Examples :
	// | 1  1 |
	// | 0  1 | => Not suspicious points, connected set
	//
	// | 1  0 |
	// | 0  1 | => Suspicious points!
	//
	// | 1  0 |
	// | 0  2 | => Not suspicious points, connected set
	for (row = 0; row < mat->rows - 1; ++row)
	{
		for (col = 0; col < mat->columns - 1; ++col)
		{
			SquareConvolution(&map, row, col);
		}
	}

	// To display each suspicious point
	BOOL isSaddlePointExist = FALSE;
	for (row = 0; row < mat->rows; ++row)
	{
		for (col = 0; col < mat->columns; ++col)
		{
			if (*(int*)At(&map, row, col) == 1)
			{
				printf("Saddle point found! Mat(%d, %d) = %d\n",
					row + 1,
					col + 1,
					*(int*)At(mat, row, col));
				isSaddlePointExist = TRUE;
			}
		}
	}

	if (!isSaddlePointExist)
	{
		printf("No saddle point found.\n");
	}

	FreeMatrix(&map);
	free(col_min);
	free(row_max);
}

Matrix* InitMatrix(
	 Matrix* mat,
		 int rows,
		 int cols,
	  size_t element_size
)
{
	mat->data = (char*)malloc(rows * cols * element_size * sizeof(char));
	mat->rows = rows;
	mat->columns = cols;
	mat->element_size = element_size;

	if (mat->data == NULL)
	{
		CCT_STDERR_LOG("Cannot allocate memory.");
	}

	return mat;
}

void FreeMatrix(
	Matrix* mat
)
{
	free(mat->data);
	mat->data = NULL;
}

void* At(
	Matrix* mat,
		int row,
		int col
)
{
	if (row >= mat->rows || col >= mat->columns)
	{
		return NULL;
	}
	else
	{
		return mat->data + (row * mat->columns + col) * mat->element_size;
	}
}

long TrOfMatrix_int(
	Matrix* mat, 
		int n
)
{
	long trSum = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		trSum += *(int*)At(mat, i, i);
	}
	return trSum;
}

char * ReadLine(
	char* str,
	int length
)
{
	int i = 0;
	char * mem = fgets(str, length, stdin);

	if (mem)
	{
		// To move to the end of a line
		while (str[i] != '\n' && str[i] != '\0')
		{
			i++;
		}

		// To delete '\n'
		if (str[i] == '\n')
		{
			str[i] = '\0';
		}
		// Otherwise, there must be characters remain in
		// the input queue
		else
		{
			ClearInputQueue();
		}
	}

	return mem;
}