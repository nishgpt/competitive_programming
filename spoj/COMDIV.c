#include <stdio.h>
int g(int a,int b)
{
    if(a<b)return g(b,a);
    if(b==0)return a;
    else return g(b,a%b);
}
int main()
{
    int t,n,m,i,d,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        k=g(n,m);
        if(k==1)printf("1\n");
        else{
        d=1;
        for(i=2;i*i<k;i++)
        {
            if(k%i==0)d++;
        }
        d=d<<1;
        if(i*i==k)d++;
        printf("%d\n",d);}
    }
    return 0;
}