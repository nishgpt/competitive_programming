#include<bits/stdc++.h>
#define LL long long
#define ABS(a) (a)<0?(-(a)):(a)
int main()
{
    int t,i,j,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        LL a[n],ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            ans+=((n-i-1)*a[i]-(i*a[i]));
        }
        printf("%lld\n",ABS(ans));
    }
    return 0;
}