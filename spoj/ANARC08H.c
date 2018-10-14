#include <stdio.h>
long int abc(long int n,long int k)
{
    long int r=0,i=2;
    while(i<=n)
    {r=(r+k)%i;i++;}
    return r+1;
}
int main()
{
    long int n,k,w;
    scanf("%ld %ld",&n,&k);
    while(!(n==0&&k==0))
    {
        w=abc(n,k);
        printf("%ld %ld %ld\n",n,k,w);
        scanf("%ld %ld",&n,&k);
    }
    return 0;
}