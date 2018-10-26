#include <stdio.h>
int main()
{
    long unsigned int t,i;
    long long unsigned int n,s;
    scanf("%lu",&t);
    for(i=0;i<t;i++)
    {
        scanf("%llu",&n);
        s=(n*(3*n+1))/2;
        printf("%llu\n",s%1000007);
    }
    return 0;
}