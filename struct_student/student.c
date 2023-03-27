#include "student.h"

TStudent input()
{
    TStudent student;

    printf("Faculty Number: ");
    scanf("%u",&student.fnom);
    fflush(stdin);
    printf("Name: ");
//    scanf("%49s",student.name);
    fgets(student.name,SIZE,stdin);
    fflush(stdin);
    printf("Average Mark: ");
    scanf("%f",&student.avmark);

    return student;
}
void output(TStudent student)
{
    printf("(%u,%s,%g)\n",student.fnom,student.name,student.avmark);
}
