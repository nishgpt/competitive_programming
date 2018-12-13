#include <stdio.h>
int main()
{
    int t,n,i,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        p=n;
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0){p-=(p/i);}
            while(n%i==0){n/=i;}
        }
        if(n>1){p-=(p/n);}
        printf("%d\n",p);
    }
    return 0;
}