#include <stdio.h>
#include <stdlib.h>
//#undef __STRICT_ANSI__
#include <math.h>

#define EPS 1e-6
#define M_PI 3.14159265358979323846

double mycos(double x);

int main()
{
    int x;

    printf("X=");
    scanf("%d",&x);
    printf("COS(%d)=%g\n",x,mycos(x*M_PI/180));
    printf("cos(%d)=%g\n",x,cos(x*M_PI/180));
//    printf("Hello world!\n");

    double y = sqrt(x);
    printf("%g\n",y);
    return 0;
}

double mycos(double x)
{
    int cnt = 2;
    double cos = 1;
    double ch1=0,ch2=1;

    while (fabs(ch1-ch2)>=EPS)
    {
        ch1 = ch2;
        ch2 *= (-1)*x*x/((cnt-1)*cnt);
        cnt += 2;
        cos += ch2;
    }
    return cos;
}
