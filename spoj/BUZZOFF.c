#include <stdio.h>
long long unsigned int a[2][2],ans[2][2];

int main()
{
    long long unsigned int t,r,i,j,n,b[2][2],k,m=1000000007;
    scanf("%llu",&t);
    while(t--)
    {
    a[0][0]=1;a[0][1]=1;a[1][0]=1;a[1][1]=0;ans[0][0]=1;ans[0][1]=0;ans[1][0]=0;ans[1][1]=1;
        scanf("%llu",&n);
        n+=2;
        while(n!=0)
        {
            r=n&1;n>>=1;
            //printf("here...");
            if(r)
            {for(i=0;i<2;i++){for(j=0;j<2;j++){b[i][j]=0;}}
                for(i=0;i<2;i++)
                {
                    for(j=0;j<2;j++)
                    {
                        for(k=0;k<2;k++)
                        {
                            b[i][j]+=((ans[i][k]*a[k][j])%m);
                        }
                    }
                }
                for(i=0;i<2;i++){for(j=0;j<2;j++)ans[i][j]=b[i][j];}
            }
            for(i=0;i<2;i++){for(j=0;j<2;j++){b[i][j]=0;}}
            for(i=0;i<2;i++)
                {
                    for(j=0;j<2;j++)
                    {
                        for(k=0;k<2;k++)
                        {
                            b[i][j]+=((a[i][k]*a[k][j])%m);
                        }
                    }
                }
                for(i=0;i<2;i++){for(j=0;j<2;j++)a[i][j]=b[i][j];}
        }
        printf("%llu\n",(ans[0][0]%m-2%m+m)%m);
    }
    return 0;
}
