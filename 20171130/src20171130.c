#include "h20171130.h"

void homework_2017_11_30_main(void)
{
	homework_1();
	homework_2();
	homework_3();
	homework_P178_2();
	homework_P178_3();
}

void homework_1(void)
{
	ClearConsoleWindow();
	printf("You can give me a series of English words, "
		"and I'll sort them in order.\n"
		"So, how many English words would you like to give ?\n");

	int count = 0;
	while (1 != scanf("%d", &count) || count < 1)
	{
		printf("Must be a positive integer.\n");
		ClearInputQueue();
	}
	ClearInputQueue();

	char ** ref = New(char*, count);
	for (int i = 0; i < count; ++i)
	{
		printf("Please input the N.O.%d word : ", i + 1);
		char * word = New(char, 30);
		scanf("%s", word);
		ClearInputQueue();
		ref[i] = word;
	}

	printf("\nThe words you gave :\n");
	for (int i = 0; i < count; ++i)
	{
		printf("%s\t", ref[i]);
	}
	LineBreak();

	BubbleSort(ref, sizeof(char*), count, char_comparing);

	printf("\nThe words after sorting :\n");
	for (int i = 0; i < count; ++i)
	{
		printf("%s\t", ref[i]);
	}
	LineBreak();

	for (int i = 0; i < count; ++i)
	{
		Delete(ref[i]);
	}
	Delete(ref);
	Pause();
}

void homework_2(void)
{
	ClearConsoleWindow();
	printf("How many students are there?\n");
	int count = 0; 
	while (1 != scanf("%d", &count) || count < 1)
	{
		printf("Must be a positive integer.\n");
		ClearInputQueue();
	}
	ClearInputQueue();

	Students stu_list = (Students)New(Student*, count);
	for (int i = 0; i < count; ++i)
	{
		Student * stu = (Student*)New(Student, 1);

		printf("The N.O.%d student's name: ", i + 1);
		ReadLine(stu->name, 30);

		printf("The N.O.%d student's score: ", i + 1);
		while (1 != scanf("%lf", &(stu->score)) ||
			stu->score < 0)
		{
			printf("Must be a positive number.");
			ClearInputQueue();
		}
		ClearInputQueue();

		stu_list[i] = stu;
	}

	BubbleSort(stu_list, sizeof(Student*), count, stu_comparing);

	LineBreak();
	printf("The result after sorting: \n");
	printf("|\tName\t|\tScore\t|\n");
	for (int i = 0; i < count; ++i)
	{
		printf("|\t%s\t|\t%.2f\t|\n", 
			stu_list[i]->name, 
			stu_list[i]->score);
	}

	for (int i = 0; i < count; ++i)
	{
		Delete(stu_list[i]);
	}
	Delete(stu_list);
	Pause();
}

void homework_3(void)
{
	ClearConsoleWindow();
	srand((unsigned int)time(0));
	int nums[1000];
	for (int i = 0; i < 1000; ++i)
	{
		nums[i] = rand();
	}

	printf("I have generated 1000 integers, which one do you "
		"prefer to search ?\n");
	int target = 0;
	while (1 != scanf("%d", &target))
	{
		printf("Please input an interger!\n");
ClearInputQueue();
	}
	ClearInputQueue();

	BubbleSort(nums, sizeof(nums[0]), 1000, int_comparing);
	long res = BinarySearch(nums, &target, sizeof(nums[0]), 1000, int_comparing);

	if (res < 0)
	{
		printf("Oh! Nothing found!\n");
	}
	else
	{
		printf("I found it! Located at %d with value %d", res, nums[res]);
	}

	Pause();
}

void homework_P178_2(void)
{
	ClearConsoleWindow();
	printf("Please input (x, y) of two points: \n");
	Point a, b;

	printf("Pa_x = ");
	scanf("%lf", &a.x);
	ClearInputQueue();
	printf("Pa_y = ");
	scanf("%lf", &a.y);
	ClearInputQueue();
	printf("Pb_x = ");
	scanf("%lf", &b.x);
	ClearInputQueue();
	printf("Pb_y = ");
	scanf("%lf", &b.y);
	ClearInputQueue();

	printf("\nDistance between (%f, %f) and (%f, %f) equals to %f\n",
		a.x,
		a.y,
		b.x,
		b.y,
		Distance(a, b));
	Pause();
}

void homework_P178_3(void)
{
	ClearConsoleWindow();
	printf("Please input two complex numbers: \n");
	Complex a, b;

	printf("Re(a) = ");
	scanf("%lf", &a.real);
	ClearInputQueue();
	printf("Im(a) = ");
	scanf("%lf", &a.imaginary);
	ClearInputQueue();
	printf("Re(b) = ");
	scanf("%lf", &b.real);
	ClearInputQueue();
	printf("Im(b) = ");
	scanf("%lf", &b.imaginary);
	ClearInputQueue();

	Complex res = ComplexMultiply(a, b);
	printf("\n(%f + %f i) x (%f + %f i) = %f + %f i \n",
		a.real,
		a.imaginary,
		b.real,
		b.imaginary,
		res.real,
		res.imaginary);
	Pause();
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

int stu_comparing(
	void* i1,
	void* i2
)
{
	if (fabs((*(Students)i2)->score - (*(Students)i1)->score) < 1E-14)
	{
		return 0;
	}
	else if ((*(Students)i2)->score - (*(Students)i1)->score >= 1E-14)
	{
		return 1;
	}
	else
	{
		return -1;
	}
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

void BubbleSort(
	void* buf,
	size_t element_size,
	size_t length,
	int(*comparing)(void*, void*)
)
{
	char * _buf = (char*)buf;

	for (size_t last = 1; last < length; ++last)
	{
		for (size_t seek = 0; seek < length - last; ++seek)
		{
			if (comparing(_buf + seek * element_size,
					_buf + (seek + 1) * element_size) > 0)
			{
				Swap(_buf + seek * element_size,
					_buf + (seek + 1) * element_size, element_size);
			}
		}
	}
}

long BinarySearch(
	 void* buf,
	 void* target_item,
	size_t element_size,
	size_t length,
	int(*comparing)(void*, void*)
)
{
	size_t start = 0, end = length - 1;
	char * _buf = (char*)buf;

	int cmp_res = 0;

	while (start <= end && 
		(start >= 0 && start < length) &&
		(end >= 0 && end < length))
	{
		cmp_res = comparing(
			target_item,
			_buf + (start + end) / 2 * element_size
		);

		if (cmp_res == 0)
		{
			return (start + end) / 2;
		}
		else if (cmp_res > 0)
		{
			start = (start + end) / 2 + 1;
		}
		else // cmp_res < 0
		{
			end = (start + end) / 2 - 1;
		}
	}

	return -1;
}

double Distance(
	Point a,
	Point b
)
{
	return sqrt(
		(a.x - b.x) * (a.x - b.x) + 
		(a.y - b.y) * (a.y - b.y)
	);
}

Complex ComplexMultiply(
	Complex a,
	Complex b
)
{
	Complex result;
	result.real = a.real * b.real - a.imaginary * b.imaginary;
	result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
	return result;
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