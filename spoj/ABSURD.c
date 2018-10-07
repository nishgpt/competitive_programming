#include <stdio.h>
#include <math.h>
int a[20],top=-1;
void push(int x)
{
    a[++top]=x;
}
int pop()
{
    if(top!=-1)return a[top--];
    else return 99;
}
int fun(int r)
{int re,d;
        while(1)
        {
            if(r%10!=0){break;}
            r/=10;
        }
        d=log10(r)+1;
        re=2*d;if(r%10==5)re-=1;
        return re;
}
int main()
{
    int t,je,ne,i,j,k,m,n,b[20],c[20],p,q,flag,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);q=0;p=0;flag=0;
        j=ceil(0.95*n);k=floor(1.05*n);
        ne=fun(n);
        je=fun(j);
        if(je<ne){printf("absurd\n");continue;}
        for(i=j;i!=0;i/=10)
        {push(i%10);}
        while(1)
        {
            m=pop();if(m==99)break;
            b[q++]=m;
        }
        for(i=k;i!=0;i/=10)
        {push(i%10);}
        while(1)
        {
            m=pop();if(m==99)break;
            c[p++]=m;
        }
        for(i=0;i<q;i++)
        {
            if(b[i]!=c[i]){flag=1;break;}
        }
        if(flag==1){ans=2*(i+1);if(b[i]<5&&c[i]>=5){ans-=1;}if(ans<ne){printf("absurd\n");}else printf("not absurd\n");}
           else printf("not absurd\n");
        }
        return 0;
}