#include <stdio.h>
void sort(long int q[],long int x)
{
    long int p,r,t;
    for(p=0;p<x-1;p++)
    {
        for(r=p+1;r<x;r++)
        {
            if((q[p])>(q[r]))
            {
                t=(q[p]);
                (q[p])=(q[r]);
                (q[r])=t;
            }
        }
    }
}
int main()
{
     long int t,a[1000],b[1000],z[1000],i,j,k,d,c,n,m;
    scanf("%ld",&t);
    for(i=0;i<t;i++)
    {
        scanf("%ld ",&n);
        for(j=0;j<n;j++)
        scanf("%ld ",&a[j]);
        scanf("%ld ",&m);
        for(j=0;j<m;j++)
        scanf("%ld ",&b[j]);
        for(j=0;j<n;j++)
        {
            c=a[j]-b[0];
        if(c<0)
        c=b[0]-a[j];
            for(k=0;k<m;k++)
            {
                d=a[j]-b[k];
                if(d<0)
                d=b[k]-a[j];
             if(d<c)
             c=d;
            }
            z[j]=c;
        }
        sort(z,j);
        printf("%ld\n",z[0]);
    }
return 0;
}

        