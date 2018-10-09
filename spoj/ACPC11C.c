#include <stdio.h>
int main()
{
    long long int t,i,j,n,a[100010],ans,sum,s,q,x,y,m;long long unsigned int m1,m2,m3;
    scanf("%lld",&t);
    while(t--)
    {sum=0;s=0;q=0;m1=-1;m2=-1;m3=-1;
        scanf("%lld",&n);
        for(i=0;i<n;i++){scanf("%lld",&a[i]);sum+=a[i];}
        x=sum-a[0];y=sum-a[n-1];m=x<y?x:y;
        j=n-1;
        for(i=0;i<n-1;i++)
        {
            s=s+a[i];q=q+a[j];
            x=s+sum-a[i+1];y=q+sum-a[j-1];
            if(x<m1){m1=x;}
            if(y<m2){m2=y;}
            j--;
        }
        m3=m1<m2?m1:m2;
        ans=m<m3?m:m3;
        printf("%lld\n",ans);
    }
    return 0;
}