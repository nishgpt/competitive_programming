#include <stdio.h>
int main()
{
    long long unsigned int i,d,flag=0,b,h,q,r,j,sum=0;
    scanf("%llu %llu %llu",&i,&b,&j);
    for( ;!(i==0&&b==0&&j==0); )
    {
        if(j>i)
        h=j-i;
        else h=i-j;
        d=3;sum=0;flag=0;
        for( ; ; )
        {
            if(h<(d*b)&&h!=0)
            {d--;continue;}
            q=h/(d*b);
            sum=sum+q;
            r=h%(d*b);
            h=r;
            if(h==0)
            break;
            d--;
            if(h!=0&&h<b)
            {flag=1;break;}
        }
        if(flag==1)
        printf("No accounting tablet\n");
        else printf("%llu\n",sum);
        scanf("%llu %llu %llu",&i,&b,&j);
    }
    return 0;
}