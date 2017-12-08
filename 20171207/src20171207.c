#include "h20171207.h"

void homework_2017_12_07_main(void)
{
	homework_P207_2();
	homework_P207_4();
	homework_P207_5();
	homework_4();
}

void homework_P207_2(void)
{
	ClearConsoleWindow();
	double r = 5.0, p = 0.0, a = 0.0;
	PerimeterAndArea(5, &p, &a);
	printf("Redius = %f, Perimeter = %f, Area = %f\n", r, p, a);
	Pause();
}

void homework_P207_4(void)
{
	ClearConsoleWindow();
	char a[] = "Hello World!";
	char b[13];
	MyStrcpy(b, a);
	printf("String a = %s\nAnd after calling MyStrcpy(b, a)\nString b = %s\n",
		a,
		b);
	Pause();
}

void homework_P207_5(void)
{
	ClearConsoleWindow();
	int * int_array = New(int, 20);

	srand((unsigned int)time(0));
	ForEach(item, int_array, int)
	{
		$(item) = rand();
		printf("%d\t", $(item));
	}
	LineBreak();

	printf("Average = %f\n", Average_cct_s(int_array));
	Pause();
}

void homework_4(void)
{
	ClearConsoleWindow();
	int * int_array = New(int, 10);
	input(int_array);
	sort(int_array);
	output(int_array);
	Pause();
}

void PerimeterAndArea(
	double   r,
	double * perimeter, 
	double * area
)
{
	if (r < 0)
	{
		printf("Redius must be a positive number.\n");
		*perimeter = *area = 0;
		return;
	}

	*perimeter = 2 * PI * r;
	*area = PI * r * r;
}

void MyStrcpy(
	      char * des,
	const char * res
)
{
	while (*res != '\0')
	{
		*des++ = *res++;
	}

	*des = '\0';
}

double Average_cct_s(int * arr)
{
	if (IsAllocated(arr))
	{
		int sum = 0;

		ForEach(item, arr, int)
		{
			sum += $(item);
		}

		return sum / (double)CountOf(arr, int);
	}
	else
	{
		printf("Please use `New(type, count)` to allocate memory.\n");
		return 0.0;
	}
}

double Average(
	 int * arr, 
	size_t size
)
{
	int sum = 0;
	size_t seek = size;

	while (seek-- > 0)
	{
		sum += arr[seek];
	}

	return sum / (double)size;
}

void input(int * data)
{
	int count = 1;
	ForEach(item, data, int)
	{
		printf("Please input the No.%d integer: ", count++);
		while (1 != scanf("%d", item))
		{
			printf("Input must be an integer.\n");
			ClearInputQueue();
		}
		ClearInputQueue();
	}
}

void sort(int * data)
{
	SelectionSort(data, sizeof(int), CountOf(data, int), int_comparing);
}

void output(int * data)
{
	int count = 1;
	ForEach(item, data, int)
	{
		printf("No.%d integer = %d\n", count++, $(item));
	}
	LineBreak();
}

int int_comparing(
	void* i1,
	void* i2
)
{
	return *(int*)i1 - *(int*)i2;
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