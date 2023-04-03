#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 5
#define MAX_SIZE 1000
#define DELIM ","

struct TTStudent {
    unsigned fnom;
    char name[SIZE];
    float avmark;
};

typedef struct TTStudent TStudent;

TStudent input();
void output(TStudent student);
void writeToTxt(char *fname,TStudent student);
unsigned readFromTxt(char *fname, TStudent *group,unsigned len);
bool readStudent(FILE *f, TStudent *student);
void parseStudent(char *str, TStudent *student);
void printGroup(TStudent *group,unsigned len);
unsigned countStudents(char *fname);

#endif // STUDENT_H_INCLUDED
