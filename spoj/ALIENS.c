#include <stdio.h>
int main()
{
    long long int t,i,h,p,ans,s,n,m,a[100000],q;
    scanf("%lld",&t);
    while(t--)
    {s=0;h=0;p=0;ans=0;q=0;
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++) scanf("%lld",&a[i]);
        for(i=0;i<n;i++)
        {
            if(s+a[i]<=m) {s=s+a[i];p++;if(h<p){h=p;ans=s;}else if(h==p){if(ans>s)ans=s;}}
            else if(s+a[i]>m)
            {s=s-a[q++];if(s>=0){i--;p--;}else if(s<0)s=0;}
        }
        printf("%lld %lld\n",ans,h);
    }
    return 0;
}