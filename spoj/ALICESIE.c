#include <stdio.h>
int main()
{
    long long int n,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%llu",&n);
        if(!(n&1))
        printf("%lld\n",n/2);
        else printf("%lld\n",(n/2)+1);
    }
    return 0;
}