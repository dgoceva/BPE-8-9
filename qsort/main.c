#include <stdio.h>
#include <stdlib.h>

void print(int *data,unsigned len)
{
    for (int i=0;i<len;++i)
        printf("%d ",data[i]);
    putchar('\n');
}

int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int compare_desc(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
    int array[] = {10,9,8,7,6,5,4,3,2,1};

    print(array,10);
    qsort(array,10,sizeof(int),compare);
    print(array,10);
    qsort(array,10,sizeof(int),compare_desc);
     print(array,10);
     //printf("Hello world!\n");
    return 0;
}
