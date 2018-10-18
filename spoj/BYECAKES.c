#include <stdio.h>
int main()
{
    long long int i,k,c=0,a[5],b[5],q[5];
    for(i=0;i<4;i++)
    {scanf("%lld",&a[i]);if(a[i]==0)c++;}
    for(i=0;i<4;i++)
    scanf("%lld",&b[i]);
    while(a[0]!=-1)
    {k=0;if(c==4){printf("0 0 0 0\n");}
    else{
        for(i=0;i<4;i++)
        {
            if(a[i]>=b[i])
            {
                q[i]=a[i]/b[i];
                if(a[i]%b[i]!=0)
                q[i]++;
            }
            else{q[i]=1;}
            if(k<q[i]){k=q[i];}
        }
        for(i=0;i<4;i++)
        {b[i]=b[i]*k;a[i]=b[i]-a[i];}
        printf("%lld %lld %lld %lld\n",a[0],a[1],a[2],a[3]);
    }
    c=0;
     for(i=0;i<4;i++)
    {scanf("%lld",&a[i]);if(a[i]==0)c++;}
    for(i=0;i<4;i++)
    scanf("%lld",&b[i]);
    }
    return 0;
}