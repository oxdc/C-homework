#ifndef _H_2017_12_14_H_
#define _H_2017_12_14_H_

#include "../CCT/sysenv.h"
#include "../CCT/autoalloc.h"
#include "../CCT/linkedlist.h"
#include "../Include/lib.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void homework_2017_12_14_main(void);

void homework_P207_6(void);
void homework_P207_7(void);
void homework_students(void);

char* DeleteCharacters(char * str, size_t start, size_t count);
char* DeleteSpecificCharacters(char * str, char ch);

typedef struct _struct_Student {
	char * name;
	unsigned int age;
} Student;

void AddNewStudent(LinkedList* stulist);
void DisplayStudentsList(Student** stuRefList);
Student** GenerateReference(LinkedList* stulist);
int SortByName(const void* stu1, const void* stu2);
int SortByAge(const void* stu1, const void* stu2);
char * ReadLine(char* str, int length);

#endif // !_H_2017_12_14_H_
