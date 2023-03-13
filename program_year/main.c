#include "year.h"

int main()
{
    unsigned year;

    year = input();
    do {
        year++;
     } while (!is_found(year));
 //   printf("Hello world!\n");
    printf("%u",year);
    return 0;
}
