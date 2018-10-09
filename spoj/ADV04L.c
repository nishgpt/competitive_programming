#include <stdio.h>
int main()
{
    long long unsigned int i,j,f,a[87],n,b[87],m=1,c=1,d,k,p,t,s;
    a[0]=1;a[1]=1;
    for(i=2;i<87;i++)
    {d=c+m;m=c;c=d;a[i]=d;}
    scanf("%llu",&t);
    while(t--)
    {p=0;s=0;
        scanf("%llu\n",&n);f=0;
        if(n==1)printf("2\n");
        else{
        for(i=0;i<87;i++)
        {
            if(n==a[i]){k=i;f=1;break;}
        else if(a[i]>n){k=i-1;break;}
        }
        b[p++]=k;
        if(f==0)
        {n=n-a[k];
        for(j=k-1;j>=0;j--)
        {
            if(n==a[j]){b[p++]=j;break;}
            else if(n>a[j]){b[p++]=j;n=n-a[j];}
        }
        }
        for(j=0;j<p;j++){s=s+a[b[j]+1];}
        printf("%llu\n",s);}
    }
    return 0;
}