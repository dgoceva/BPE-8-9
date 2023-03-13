#include "year.h"

unsigned input()
{
    unsigned year;

    do {
        printf("Input year:");
        scanf("%u",&year);
        assert(year>=1000);
        if (year<1000)
            printf("Year must be >=1000\n");
    } while(year<1000);

    return year;
}

/*
void zerofill(unsigned digits[])
{
    for (int i=0;i<10;++i)
        digits[i]=0;
}
*/

int is_found(unsigned year)
{
    unsigned digits[10]={0};

 //   zerofill(digits);

    while (year){
        int d = year%10;
        digits[d]++;
        if (digits[d]>1) {
            return 0;
        }
        year/=10;
    }
    return 1;
}
