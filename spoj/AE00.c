#include <stdio.h>
int main()
{
unsigned int i,j,n,c=0;
scanf("%u",&n);
for(i=1;i<=n;i++)
{
    for(j=i;j<=n/i;j++)
    c++;
}
printf("%u\n",c);
return 0;
}