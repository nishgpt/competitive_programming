#include <stdio.h>
int prime(int x)
{
    int q,c=0;
    for(q=2;q<x;q++)
    {
        if(x%q==0)
        c++;
    }
    if(c==0)
    return 1;
    else return 0;
}
int main()
{
    int i,j,k,n,h,t,a[1000],p=0;
    scanf("%d",&t);
    for(i=30;p!=1000;i++)
    {h=0;
        for(j=2;j<=(i/2);j++)
        {
            if(i%j==0)
            {k=prime(j);
            if(k==1)
            h++;
            }
        }
        if(h>=3)
        {a[p++]=i;}
    }
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%d\n",a[n-1]);
    }
    return 0;
}