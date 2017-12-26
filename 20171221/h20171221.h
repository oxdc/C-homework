#ifndef _H_2017_12_21_H_
#define _H_2017_12_21_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../Include/lib.h"
#include "../CCT/sysenv.h"
#include "../CCT/autoalloc.h"
#include "../CCT/linkedlist.h"
#include "../CCT/file.h"
#include "../CCT/tinyexception.h"

void homework_2017_12_21_main(void);

void homework_P222_1(void);
void homework_P222_2(void);
void homework_P222_3(void);
void homework_P222_4(void);
void homework_P222_5(void);

long DisplayFileAndCountLines(FileStream fs);
long DisplayFileWithLineNumberAndCountLines(FileStream fs);

void ReadData(FileStream fs);

typedef struct _StudentExamData {
	char * stuID;
	char * stuName;
	unsigned int score;
} StudentExamData;

StudentExamData StudentExamData__(const char * _StuID, const char * _StuName, unsigned int _Score);
void dStudentExamData__(StudentExamData * data);

void GetStuData(LinkedList * StuList);
StudentExamData** GenerateReference(LinkedList* StuList);
void DisplayStuData(StudentExamData ** StuListRef);
void WriteToFile(StudentExamData ** StuListRef);

char * ReadLine(char* str, int length);;

#endif // !_H_2017_12_21_H_
