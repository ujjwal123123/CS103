

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
    printf("[%d]: %s [%d]\n", pstudent->roll, pstudent->name, pstudent->marks);
}

int compareStudent(STUDENT* ps1, STUDENT* ps2)
{
    return (ps1->roll - ps2->roll);
}