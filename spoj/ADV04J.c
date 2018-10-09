#include <stdio.h>
int main()
{
    long long int t,n,i,c,p;
    scanf("%lld",&t);
    while(t--)
    {c=0;
        scanf("%lld",&n);
        for(i=n;i!=1;i/=2)
        {c++;}
        c+=1;
        if(n&(n-1)){c+=1;}
        printf("%lld\n",c);
    }
    return 0;
}