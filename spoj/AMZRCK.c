#include <stdio.h>
int main()
{
    long long unsigned int i,t,n,a[60];
    a[0]=2;a[1]=3;
    for(i=2;i<60;i++)
        a[i]=a[i-1]+a[i-2];
        scanf("%llu",&t);
        while(t--)
        {
            scanf("%llu",&n);
            if(n==0)
            printf("1\n");
            else
            printf("%llu\n",a[n-1]);
        }
        return 0;
}