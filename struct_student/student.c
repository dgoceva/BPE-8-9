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

void writeToTxt(char *fname,TStudent student)
{
    FILE *f;

    if ((f = fopen(fname,"a"))==NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }

    fprintf(f,"%u,%s,%g\n",student.fnom,student.name,student.avmark);
    fclose(f);
}
unsigned countStudents(char *fname)
{
    FILE *f;
    char buff[MAX_SIZE];
    unsigned count=0;

     if((f=fopen(fname,"r"))==NULL){
        perror("open file error: ");
        exit(EXIT_FAILURE);
    }

    while(true){
        if(fgets(buff,MAX_SIZE,f)==NULL){
            if(feof(f)){
                fclose(f);
                return count;
            }
            perror(NULL);
            fclose(f);
            exit(EXIT_FAILURE);
       }
       count++;
    }
}

bool readStudent(FILE *f, TStudent *student)
{
    char buff[MAX_SIZE];


    if(fgets(buff,MAX_SIZE,f)==NULL){
        if(feof(f)){
            return false;
        }
        perror(NULL);
        fclose(f);
        exit(EXIT_FAILURE);
   }
   parseStudent(buff, student);
   return true;
}

void parseStudent(char *str, TStudent *student)
{
    char *token;

    if((token=strtok(str,DELIM))==NULL){
        perror("No faculty number: ");
        exit(EXIT_FAILURE);
    }
    student->fnom = atoi(token);

    if((token=strtok(NULL,DELIM))==NULL){
        perror("No name: ");
        exit(EXIT_FAILURE);
    }
    strcpy(student->name,token);

    if((token=strtok(NULL,DELIM))==NULL){
        perror("No mark: ");
        exit(EXIT_FAILURE);
    }
    student->avmark = atof(token);
}

unsigned readFromTxt(char *fname, TStudent *group,unsigned len)
{
     FILE *f;
     int i;

     if((f=fopen(fname,"r"))==NULL){
        perror("open file error: ");
        exit(EXIT_FAILURE);
    }

    for(i=0;i<len && readStudent(f,group+i);++i)
        ;

    fclose(f);
    return i;
}
void printGroup(TStudent *group,unsigned len)
{
    for(int i=0;i<len;++i){
        output(group[i]);
    }
}
