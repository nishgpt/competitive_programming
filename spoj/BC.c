#include <stdio.h>
long long int fun(long long int x)
{
    long long int a[]={1,2,4,8,16,32,64,128,256,512,1024,2048},i;
    for(i=0;i<12;i++){if(x==a[i]||x<a[i]){return i;}}
}
int main()
{
    
    long long int j,k,n,m,t,a1,a2;
    scanf("%lld",&t);
    for(j=1;j<=t;j++)
    {
        scanf("%lld %lld %lld",&n,&m,&k);
        a1=n*m*k-1;
        a2=fun(n)+fun(m)+fun(k);
        printf("Case #%lld: %lld %lld\n",j,a1,a2);
    }
    return 0;
}