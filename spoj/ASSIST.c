#include <stdio.h>
int main()
{
    long int i,j,p=1,q=2,n,a[60001]={0},b[4233],c=0,flag;b[0]=2;
    for( ;p<3000; )
    {flag=0;j=q;c=0;
        for(i=j+1;i<=34000;i++)
        {
            if(a[i]==0){c++;if(flag==0){b[p++]=i;q=i;flag=1;}}
            if(c==j){a[i]=-99;c=0;}
        }
    }
    scanf("%ld",&n);
    while(n)
    {
        printf("%ld\n",b[n-1]);scanf("%ld",&n);
    }
    return 0;
}