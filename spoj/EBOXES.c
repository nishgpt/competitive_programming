#include <stdio.h>
int main()
{
    long long int i,j,k,n,f,t,test;
    scanf("%lld",&test);
    while(test--)
    {
      scanf("%lld %lld %lld %lld",&n,&k,&t,&f);
      printf("%lld\n",((f-n)/(k-1))+f);
    }
    return 0;
}