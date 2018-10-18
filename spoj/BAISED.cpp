#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    long long int a[100000],n,p,t,q=0,i;char ch,b[100];
    scanf("%lld",&t);
    while(t--)
    {q=0;
      ch=getchar();
       scanf("%lld",&n);
        for(p=0;p<n;p++)scanf("%s %lld",b,&a[p]);
        sort(a,a+n);
        for(p=0;p<n;p++)
        {i=abs(p-a[p]+1);
           q+=i;
        }
        printf("%lld\n",q);
    }
    return 0;
}


