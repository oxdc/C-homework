#include "h20171214.h"

void homework_2017_12_14_main(void)
{
	homework_P207_6();
	homework_P207_7();
	homework_students();
}

void homework_P207_6(void)
{
	ClearConsoleWindow();
	printf("Delete m characters from the k-th character in a string.\n");
	printf("For example: Hello World.\n");
	printf("Delete 4 charcaters from the 2th charcater.\n");
	char string1[] = "Hello World";
	DeleteCharacters(string1, 2, 4);
	printf("Result = %s\n", string1);
	Pause();
}

void homework_P207_7(void)
{
	ClearConsoleWindow();
	printf("Delete all \'o\'s in \"Hello World\"\n");
	char string2[] = "Hello World";
	DeleteSpecificCharacters(string2, 'o');
	printf("Result = %s\n", string2);
	Pause();
}

void homework_students(void)
{
	ClearConsoleWindow();

	LinkedList students;
	InitializeList(&students);

	printf("Please input the students' name and age one by one.\n");
	printf("Using # to terminate.\n\n");

	AddNewStudent(&students);

	Student** ref = GenerateReference(&students);

	DisplayStudentsList(ref);
	Pause();

	ClearConsoleWindow();
	printf("\nSort by name:\n");
	qsort(ref, CountOf(ref, Student*), sizeof(Student*), SortByName);
	DisplayStudentsList(ref);
	Pause();

	ClearConsoleWindow();
	printf("\nSort by age:\n");
	qsort(ref, CountOf(ref, Student*), sizeof(Student*), SortByAge);
	DisplayStudentsList(ref);
	Pause();

	EmptyTheList(&students);
}

char * DeleteCharacters(char * str, size_t start, size_t count)
{
	/*
	 * ATTENTION
	 * The question in the book is a kind of poor design since
	 * it doesn't follow the standard C. So I will not follow
	 * it, neither.
	 */
	while (str[start] != '\0')
	{
		str[start] = str[start + count];
		start++;
	}

	return str;
}

char * DeleteSpecificCharacters(char * str, char ch)
{
	size_t seek = 0, current = 0;
	while (str[seek] != '\0')
	{
		if (str[seek] == ch)
		{
			seek++;
		}
		str[current] = str[seek];

		seek++;
		current++;
	}
	str[current] = '\0';

	return str;
}

void AddNewStudent(LinkedList* stulist)
{
	while (TRUE)
	{
		Student* newStu = New(Student, 1);
		newStu->name = New(char, 40);
		printf("Please input the student's name: ");
		ReadLine(newStu->name, 40);
		if (strcmp(newStu->name, "#") == 0)
		{
			return;
		}
		printf("Please input the student's age: ");
		while (1 != scanf("%u", &(newStu->age)))
		{
			printf("Must be an positive integer.\n");
			ClearInputQueue();
		}
		ClearInputQueue();
		PushBackToList(stulist, (Item)newStu);
	}
}

void DisplayStudentsList(Student** stuRefList)
{
	ForEach(students, stuRefList, Student*)
	{
		printf("Name: %s , Age: %u\n", ($(students))->name, ($(students))->age);
	}
}

Student** GenerateReference(LinkedList* stulist)
{
	Student** ref = New(Student*, ListCount(stulist));
	for(size_t i = 0; i < ListCount(stulist); i++)
	{
		*(ref + i) = (Student*)GetListItem(stulist, i);
	}
	return ref;
}

int SortByName(const void* stu1, const void* stu2)
{
	return strcmp((*(Student**)stu1)->name, (*(Student**)stu2)->name);
}

int SortByAge(const void* stu1, const void* stu2)
{
	return (*(Student**)stu1)->age - (*(Student**)stu2)->age;
}

char * ReadLine(char* str, int length)
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