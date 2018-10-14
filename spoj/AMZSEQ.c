#include <stdio.h>
int main()
{
    long long unsigned int i,n,a[30];
    a[0]=3;a[1]=7;
    for(i=2;i<30;i++)
        a[i]=(3*a[i-2])+2*(a[i-1]-a[i-2]);
        scanf("%llu",&n);
            if(n==0)
            printf("1\n");
            else
            printf("%llu\n",a[n-1]);
        return 0;
}