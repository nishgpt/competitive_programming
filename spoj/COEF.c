#include <stdio.h>
#define Z long long unsigned int
Z fac(Z x)
{
    if(x==1) return 1;
    else if(x==0) return 1;
    else return x*fac(x-1);
}
int main()
{
   Z i,j,a[13],n,k,p,q;
   while(scanf("%llu %llu",&n,&k)!=EOF)
   {p=1;
       for(i=0;i<k;i++)
       scanf("%llu",&a[i]);
       for(i=0;i<k;i++)
       p=p*fac(a[i]);
       q=fac(n);
       printf("%llu\n",q/p);
   }
   return 0;
}