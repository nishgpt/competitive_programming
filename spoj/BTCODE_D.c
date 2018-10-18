#include <stdio.h>
int main()
{
    long long unsigned int i,j,k,t,n,m,a[100][100],b[100][100],c[100][100],max=0,s=0;
    scanf("%llu",&t);
    while(t--)
    {k=0;max=0;s=0;
        scanf("%llu %llu",&m,&n);
        for(i=0;i<m;i++)
        {for(j=0;j<n;j++)scanf("%llu",&a[i][j]);}
        for(i=0;i<m;i++)
        {for(j=0;j<n;j++)scanf("%llu",&b[i][j]);}
        for(i=0;i<m;i++)
        {for(j=0;j<n;j++)scanf("%llu",&c[i][j]);}
        for(i=0;i<m;i++)
        {max=0;
            for(j=0;j<n;j++)
            {
                if(b[i][j]>a[i][j]){k=c[i][j]*a[i][j];}
                else k=c[i][j]*b[i][j];if(max<k)max=k;
            }s=s+max;
        }
        printf("%llu\n",s);
    }return 0;
}