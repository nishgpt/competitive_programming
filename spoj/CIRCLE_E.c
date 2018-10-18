#include <stdio.h>
#include <math.h>
int main()
{
    long long int t; long double r1,r2,r3,a,b,c,r,d;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%Lf %Lf %Lf",&r1,&r2,&r3);
        a=(1.0/r1)+(1.0/r2)+(1.0/r3);
        b=(r1*r2);c=r2*r3;d=r3*r1;
        r=2*sqrt((1.0/b)+(1.0/c)+(1.0/d))+a;
        printf("%.6Lf\n",1.00/r);
    }
    return 0;
}