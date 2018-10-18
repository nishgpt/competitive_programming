#include <stdio.h>
int main()
{
    long long int n,s;
    scanf("%lld",&n);
    while(n)
    {
        n++;
        s=(3*n*n-n)/2;
        printf("%lld\n",s);
        scanf("%lld",&n);
    }
    return 0;
}