#include <stdio.h>
#define m 10000000
long long int prime[m]={0},b[m];
int main()
{
    long long int t,i,n,j,p,k,q=0;
    for(p=2;p*p<=m;p++)
    {if(prime[p-1]==0){
        for(j=p;j<=m;j+=p)
        {
            if(j!=p&&j>=1&&prime[j-1]==0)
            {prime[j-1]=p;}
        }}
    }b[0]=0;
    for(i=1;i<m;i++)
    {
        if(prime[i]!=0)
        {b[i]=b[i-1]+prime[i];}
        else b[i]=b[i-1]+i+1;
    }
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n)
        printf("%lld\n",b[n-1]);
        else printf("0\n");
    }
    return 0;
}