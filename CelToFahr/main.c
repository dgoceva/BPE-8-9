#include <stdio.h>
#include <stdlib.h>
#define LOWER 0
#define UPPER 200
#define STEP 9

int main()
{
        float fahr;
/*    int lower;
    int upper,step;

//    scanf("%d%d%d",&lower,&upper,&step);
    printf("Lower=");
    scanf("%d",&lower);
    printf("Upper=");
    scanf("%d",&upper);
    printf("Step=");
    scanf("%d",&step);
*/
    printf("Cel\t\tFahr\n");
    // for(;;)
//    for (int cel=lower;cel<=upper;cel+=step)
    for (int cel=LOWER;cel<=UPPER;cel+=STEP)
    {
        fahr = cel*9./5.+32;
        printf("%d\t\t%g\n",cel,fahr);
    }
//    printf("Hello world!\n");
//    return EXIT_SUCCESS;
    return EXIT_FAILURE;
}
