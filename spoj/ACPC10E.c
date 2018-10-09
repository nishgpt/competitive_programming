#include <stdio.h>
#include <math.h>
long long int power(long long int e)
{
    long long int y,x=1;for(y=1;y<=e;y++){x=x*2;}
    return x;
}
int main()
{
    long long int g,d,a,t,n,m,k,i,j,ans,mat;
    while(scanf("%lld %lld %lld %lld",&g,&t,&a,&d)==4)
    {mat=0;
        if(g==-1&&a==-1&&t==-1&&d==-1)break;
        n=g*a+d;
        k=log2(n)+1;
        j=power(k);
        m=j-n;if(m==n){ans=0;}else ans=m;
        mat+=(g*(t*(t-1)/2));
        for(i=(n+ans)/2;i!=0;i/=2){mat+=i;}
        printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g,a,t,d,mat,ans);
    }
    return 0;
}