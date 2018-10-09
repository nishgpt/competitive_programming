#include <stdio.h>
#define m 1000001
long long int prime[m]={0};
int main()
{
    long long int t,i,n,j,p,k;
    for(p=1;p<m;p++)
    {
        for(j=2*p;j<m;j+=p)
        {
            prime[j]+=p;
        }
    }
    prime[0]=0;prime[1]=0;
    for(i=2;i<m;i++)
    {
        prime[i]=prime[i-1]+prime[i];
    }
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",prime[n]);
    }
    return 0;
}

