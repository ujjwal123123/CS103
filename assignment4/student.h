#include "generic-list.h"

typedef struct student {
    int roll;
    char* name;
    int marks;
} STUDENT;

STUDENT* newStudent(int roll, char* name, int marks)
{
    STUDENT* new = (STUDENT*)malloc(sizeof(STUDENT));
    new->roll = roll;
    new->name = name;
    new->marks = marks;
    return new;
}

void printStudent(void* data)
{
    STUDENT* pstudent = (STUDENT*)data;
    printf("[%d]: %s [%d]\n", pstudent->marks, pstudent->name, pstudent->roll);
}