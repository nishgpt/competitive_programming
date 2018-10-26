#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n;i>=0;i--)
void fun(long long int n,long long int q[])
{
long long int x=1,y,m=0,r,i,j=n,k;
 while(1)
 { r=j%10;j=j/10;m=r*x+m;q[r]++;
   for(i=r-1;i>0;i--){q[i]+=x;}
  if(j==0)break;
  y=j*x;if(r){i=0;}else {i=1;q[0]+=y-x;}
  for( ;i<10;i++){q[i]+=y;}
  q[j%10]+=m;x*=10;
 }
}
int main()
{
	long long int i,a,b,ans,a1[10],b1[10];
	while(scanf("%lld %lld",&a,&b)==2)
	{
		if(a+b==-2)break;
		ans=0;
		rep(i,10){a1[i]=0;b1[i]=0;}
		if(a>1)fun(a-1,a1);
		if(b>=1)fun(b,b1);
		rep(i,10){ans+=(i*(b1[i]-a1[i]));}
		printf("%lld\n",ans);
	}
	return 0;
}