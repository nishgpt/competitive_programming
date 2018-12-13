#include <stdio.h>
int main()
{
    long long unsigned int i,t,k,n=1,q,r,c=0;
    scanf("%llu",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%llu",&k);
        q=k/4;
        r=k%4;
        if(r==1)
        printf("%llu\n",q*1000+192);
        else if(r==2)
        printf("%llu\n",q*1000+442);
        else if(r==3)
        printf("%llu\n",q*1000+692);
        else if(r==0)
        printf("%llu\n",(q-1)*1000+942);
    }
    return 0;
}