#include<stdio.h>
#include<math.h>
int main()
{
    long unsigned int t,n,x,y;
    scanf("%lu",&t);
    while(t--)
    {
        scanf("%lu",&n);
        x=(sqrt(8*(n-1)+1)-1)/2;
        y=x*(x+1)/2;
        y=n-y;
        if(!(x&1))
        printf("TERM %lu IS %lu/%lu\n",n,x+2-y,y);
        else
        printf("TERM %lu IS %lu/%lu\n",n,y,x+2-y);
    }
    return 0;
}