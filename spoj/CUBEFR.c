#include <stdio.h>
#define m 100
int a[1000000],cube[1000000]={0};
int main()
{
    int i,j,k=0,p,q,t,n;
    for(p=2;p<=m;p++)
    {q=p*p*p;
        if(cube[q-1]==0)
        {
            for(j=q;j<=1000000;j+=q)
            {
                cube[j-1]=1;
            }
        }
    }
    for(i=0;i<1000000;i++)
    {
        if(!cube[i]){k++;a[i]=k;}
        else a[i]=0;
    }
    q=1;
    scanf("%d",&t);
    while(q<=t)
    {
        scanf("%d",&n);
        printf("Case %d: ",q);
        if(a[n-1]==0){printf("Not Cube Free\n");}
        else printf("%d\n",a[n-1]);q++;
    }
    return 0;
}