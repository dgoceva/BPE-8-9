#include "student.h"

int main()
{
//    TStudent student;
//    TStudent group[3];
    unsigned size = countStudents("students.csv");
    //TStudent group[size];
    TStudent *group;
    group = (TStudent*) malloc(size*sizeof(TStudent));
    if(group==NULL){
        perror("Memory error: ");
        exit(EXIT_FAILURE);
    }

//    student = input();
//    output(student);
 //   writeToTxt("students.csv",student);
//    student = readFromTxt("students.csv");
//    output(student);
    size = readFromTxt("students.csv",group,size);
    printGroup(group,size);

    free(group);

//    printf("Hello world!\n");
    return 0;
}
