#include <stdio.h>
int main()
{
 long long int i,t,n;
scanf("%lld",&t);
while(t--)
{
scanf("%lld",&n);
i=(n-2)>0?(n-2):0;
printf("%lld\n",i);
}
return 0;
}