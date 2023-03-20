#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void input(int *data, unsigned len);
void move(int *data, unsigned len);
int extend(int *data, unsigned len);
void print(int *data, unsigned len);

int main()
{
    int array[SIZE*2];
    int len;

    input(array,SIZE);
    print(array,SIZE);
    move(array,SIZE);
    print(array,SIZE*2);
    len = extend(array,SIZE);
    print(array,len);
    print(array,SIZE*2);
//    printf("Hello world!\n");
    return 0;
}

void input(int *data, unsigned len)
{
    for(int i=0;i<len;++i)
        data[i] = rand()%50 - 25;
}
void move(int *data, unsigned len)
{
    for (int i=0;i<len;++i)
        data[i+len] = data[i];
}
int extend(int *data, unsigned len)
{
    int i,j;
    for(i=j=0;i<len;++i,++j){
        data[j] = data[i+len];
        if (data[j]%2==0){
            data[++j] = data[i+len]+1;
        }
    }
    return j;
}
void print(int *data, unsigned len)
{
    for(int i=0;i<len;++i)
        printf("%d ",data[i]);
    putchar('\n');
}
