#include <stdio.h>
int main()
{
    long long int t,p,i,j,k,l1,l2,a,b,x,y,z,ar[1000000]={0},lcm;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);lcm=0;
        for(p=2;p*p<=b;p++)
        {
            if(b%p==0)
            {
                j=b/p;y=0;z=0;l1=(a/p)*p;l2=a<j?j:(a/j)*j;x=l2;i=l1;
                while(y+z!=2) 
                   {
                    if(!y){if(i>=a){if(ar[i-a]<=p){ar[i-a]=p;}}i+=p;if(i>b){y=1;}}
                    if(!z){if(x>=a){if(ar[x-a]<=j)ar[x-a]=j;}x+=j;if(x>b){z=1;}}        
                    }
            }
        }ar[b-a]=b;
        for(i=0;i<b-a+1;i++){if(ar[i])lcm=(lcm+((b*(i+a))/ar[i]))%1000000007;else lcm=(lcm+b*(i+a))%1000000007;ar[i]=0;}
        printf("%lld\n",lcm%1000000007);
    }
    return 0;
}


