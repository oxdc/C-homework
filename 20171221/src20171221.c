#include "h20171221.h"

void homework_2017_12_21_main(void)
{
	homework_P222_1();
	homework_P222_2();
	homework_P222_3();
	homework_P222_4();
	homework_P222_5();
}

void homework_P222_1(void)
{
	Console.clear();
	char * strFileName = New(char, 256);

	printf("Please input the full-path of a source code file: ");
	ReadLine(strFileName, 256);
	Console.empty_stdin();

	FileStream pfSourceCodeFile = NULL;
	/*
	 * For more details on Try, Catch and Finally
	 * See CCT/tinyexception.h
	 */
	Try
	{
		pfSourceCodeFile = OpenFile(strFileName, "r");
		long lLineCount = DisplayFileAndCountLines(pfSourceCodeFile) check_exception__;
		printf("\nLines: %d\n", lLineCount);
	}
	Catch(Exception e)
	{
		DisplayExceptionMessage(e);
	}
	Finally
	{
		if (pfSourceCodeFile != NULL)
		{
			CloseFile(pfSourceCodeFile);
		}
	}

	Delete(strFileName);
	Console.pause();
}

void homework_P222_2(void)
{
	Console.clear();
	char * strFileName = New(char, 256);

	printf("Please input the full-path of a source code file: ");
	ReadLine(strFileName, 256);
	Console.empty_stdin();

	FileStream pfSourceCodeFile = NULL;

	Try
	{
		pfSourceCodeFile = OpenFile(strFileName, "r");
		long lLineCount = DisplayFileWithLineNumberAndCountLines(pfSourceCodeFile) check_exception__;
		printf("\nLines: %d\n", lLineCount);
	}
	Catch(Exception e)
	{
		DisplayExceptionMessage(e);
	}
	Finally
	{
		if (pfSourceCodeFile != NULL)
		{
			CloseFile(pfSourceCodeFile);
		}
	}

	Delete(strFileName);
	Console.pause();
}

void homework_P222_3(void)
{
	Console.clear();
	printf("Write perfect numbers to file1.txt\n");

	FileStream pfOutputFile = NULL;

	Try
	{
		pfOutputFile = OpenFile("file1.txt", "w");

		int k;
		for (k = 2; k <= 1000; k++)
		{
			int sum = 0;
			int j;
			for (j = 1; j < k; j++)
			{
				if (k % j == 0)
				{
					sum += j;
				}
			}

			if (sum == k)
			{
				fprintf(pfOutputFile, "%d\n", k);
			}

			if (ferror(pfOutputFile))
			{
				Throw(Exception__("IOException: An error occured when trying to write the file."));
				check_exception__;
			}
		}
	}
	Catch(Exception e)
	{
		DisplayExceptionMessage(e);
	}
	Finally
	{
		if (pfOutputFile != NULL)
		{
			CloseFile(pfOutputFile);
		}
	}

	Console.pause();
}

void homework_P222_4(void)
{
	Console.clear();
	printf("Reading data from file1.txt.\n");

	FileStream pfDataFile = NULL;

	Try
	{
		pfDataFile = OpenFile("file1.txt", "r");
		ReadData(pfDataFile) check_exception__;
	}
	Catch(Exception e)
	{
		DisplayExceptionMessage(e);
	}
	Finally
	{
		if (pfDataFile != NULL)
		{
			CloseFile(pfDataFile);
		}
	}

	Console.pause();
}

void homework_P222_5(void)
{
	Console.clear();
	LinkedList StuList;
	InitializeList(&StuList);

	GetStuData(&StuList);
	StudentExamData ** ref = GenerateReference(&StuList);
	DisplayStuData(ref);
	WriteToFile(ref);

	EmptyTheList(&StuList);
	Console.pause();
}

long DisplayFileAndCountLines(FileStream fs)
{
	if (fs == NULL)
	{
		Throw(Exception__("IOException: Invalid stream.")) 0L;
	}

	int ch = 0, count = 1;

	do {
		ch = fgetc(fs);
		putchar(ch);

		if (ch == '\n')
		{
			count++;
		}

		if (ferror(fs))
		{
			Throw(Exception__("IOException: An error occured when trying to read the file.")) 0L;
		}
	} while (ch != EOF);

	return count;
}

long DisplayFileWithLineNumberAndCountLines(FileStream fs)
{
	if (fs == NULL)
	{
		Throw(Exception__("IOException: Invalid stream.")) 0L;
	}

	int count = 1;
	char * buffer = New(char, 100);

	while (!feof(fs))
	{ 
		if (fgets(buffer, 100, fs) != NULL)
		{
			printf("%d\t", count);
			fputs(buffer, stdout);

			count++;
		}

		if (ferror(fs))
		{
			Delete(buffer);
			Throw(Exception__("IOException: An error occured when trying to read the file.")) 0L;
		}
	}

	Delete(buffer);
	return count;
}

void ReadData(FileStream fs)
{
	int * pIntBuffer = New(int, 3);

	for (int i = 0; i < 3; ++i)
	{
		if (1 != fscanf(fs, "%d", &(pIntBuffer[i])))
		{
			Throw(Exception__("TypeErrorException: Cannot read the data."));
		}

		if (feof(fs))
		{
			Throw(Exception__("IOException: EOF."));
		}

		if (ferror(fs))
		{
			Throw(Exception__("IOException: An error occured when trying to read the file."));
		}
	}

	printf("Item 1 = %d\nItem 2 = %d\nItem 3 = %d\nAverage = %f\n",
		pIntBuffer[0],
		pIntBuffer[1],
		pIntBuffer[2],
		(pIntBuffer[0] + pIntBuffer[1] + pIntBuffer[2]) / (double)3);
}

StudentExamData StudentExamData__(const char * _StuID, const char * _StuName, unsigned int _Score)
{
	StudentExamData data;

	if (_StuID == NULL)
	{
		data.stuID = New(char, 1);
		data.stuID[0] = '\0';
	}
	else
	{
		data.stuID = New(char, strlen(_StuID) + 1);
		strcpy(data.stuID, _StuID);
	}

	if (_StuName == NULL)
	{
		data.stuName = New(char, 1);
		data.stuName[0] = '\0';
	}
	else
	{
		data.stuName = New(char, strlen(_StuName) + 1);
		strcpy(data.stuName, _StuName);
	}

	data.score = _Score;

	return data;
}

void dStudentExamData__(StudentExamData * data)
{
	Delete(data->stuID);
	Delete(data->stuName);
	Delete(data);
	data = NULL;
}

void GetStuData(LinkedList * StuList)
{
	int nCount = 1;

	while (TRUE)
	{
		printf("Please input the info of No.%d student: (# to end)\n", nCount);

		printf("Name: ");
		char * strName = New(char, 30);
		ReadLine(strName, 30);
		Console.empty_stdin();
		
		if (strcmp(strName, "#") == 0)
		{
			return;
		}

		printf("Student Number: ");
		char * strID = New(char, 30);
		ReadLine(strID, 30);
		Console.empty_stdin();

		printf("Score: ");
		unsigned int score = 0;
		while (1 != scanf("%ud", &score))
		{
			printf("Must be a positive number.\n");
			Console.empty_stdin();
		}
		Console.empty_stdin();

		StudentExamData * newItem = New(StudentExamData, 1);
		*newItem = StudentExamData__(strID, strName, score);
		PushBackToList(StuList, (Item)newItem);

		nCount++;
	}
}

StudentExamData** GenerateReference(LinkedList* StuList)
{
	StudentExamData** ref = New(StudentExamData*, ListCount(StuList));
	for (size_t i = 0; i < ListCount(StuList); i++)
	{
		*(ref + i) = (StudentExamData*)GetListItem(StuList, i);
	}
	return ref;
}

void DisplayStuData(StudentExamData ** StuListRef)
{
	ForEach(Student, StuListRef, StudentExamData*)
	{
		printf("Name: %s , Student Number: %s , Score: %u\n", 
			($(Student))->stuName, 
			($(Student))->stuID, 
			($(Student))->score);
	}
}

void WriteToFile(StudentExamData ** StuListRef)
{
	FileStream pfDataFile = NULL;

	Try
	{
		pfDataFile = OpenFile("file2.dat", "wb");
		ForEach(Student, StuListRef, StudentExamData*)
		{
			fwrite(($(Student))->stuName, SizeOf(($(Student))->stuName), 1, pfDataFile);
			fwrite(($(Student))->stuID, SizeOf(($(Student))->stuID), 1, pfDataFile);
			fwrite(&($(Student))->score, sizeof(unsigned int), 1, pfDataFile);

			if (ferror(pfDataFile))
			{
				Throw(Exception__("IOException: An error occured when trying to write the file."));
			}
		}
	}
	Catch(Exception e)
	{
		DisplayExceptionMessage(e);
	}
	Finally
	{
		if (pfDataFile != NULL)
		{
			CloseFile(pfDataFile);
		}
	}
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
