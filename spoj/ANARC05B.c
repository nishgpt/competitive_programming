#include <stdio.h>
int main()
{
    long long int n,m,a[20010]={0},b[20010]={0},i,j,s,q,r,ans,n1,m1,max;
    while(1)
    {
        scanf("%lld",&n);
        if(n==0){break;}
        for(i=0;i<n;i++){scanf("%lld",&n1);a[n1+10000]++;}
        scanf("%lld",&m);
        for(i=0;i<m;i++){scanf("%lld",&m1);b[m1+10000]++;}
        s=0;r=0;ans=0;
        for(i=0;i<20010;i++)
        {
            if(a[i]){s=s+(i-10000);}
            if(b[i]){r=r+(i-10000);}
            if(a[i]>0&&b[i]>0)
            {max=s>r?s:r;s=max;r=max;}
            a[i]=0;b[i]=0;
        }
        ans=s>r?s:r;
        printf("%lld\n",ans);
    }
    return 0;
}