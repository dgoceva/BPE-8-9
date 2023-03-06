#include <stdio.h>
#include <stdlib.h>

static unsigned digits[10];
int main()
{
    unsigned year;
    int found;

    do {
        scanf("%u",&year);
        if (year<1000)
            printf("Year must be >=1000\n");
    } while(year<1000);

    do {
        year++;
        unsigned n=year;
        found=1;
        for (int i=0;i<10;++i)
            digits[i]=0;
        while (n){
            int d = n%10;
            digits[d]++;
            if (digits[d]>1) {
                found=0;
                break;
            }
            n/=10;
        }
     } while (!found);
 //   printf("Hello world!\n");
    printf("%u",year);
    return 0;
}
