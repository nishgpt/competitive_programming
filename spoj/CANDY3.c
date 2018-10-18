#include <stdio.h>
int main()
{
    long long unsigned int a[1000000],i,n,j,t;
    scanf("%llu",&t);
    while(t--)
    {j=0;
     scanf("\n%llu",&n);
     for(i=0;i<n;i++)
     scanf("%llu",&a[i]);
     for(i=0;i<n;i++)
     j=j+(a[i]%n);
     if(j%n==0)
     printf("YES\n");
     else
     printf("NO\n");
    }
    return 0;
}