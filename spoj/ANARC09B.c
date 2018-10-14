#include <stdio.h>
long long int gcd(long long int a,long long int b)
{if(a<b)return gcd(b,a);
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    long long int n,m,p,g,x,y,l;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        if(n==0&&m==0){break;}
        else
        {
            g=gcd(n,m);
            p=n*m;l=p/g;
            x=l/n;y=l/m;
            printf("%lld\n",x*y);
        }
    }
    return 0;
}