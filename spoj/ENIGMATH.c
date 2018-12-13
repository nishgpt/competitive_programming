#include <stdio.h>
int gcd(int x,int y)
{
	if(y==0)return x;
	else return gcd(y,x%y);
}
int main()
{
	int a,b,ans1,ans2,g,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		g=gcd(a,b);
	printf("%d %d\n",b/g,a/g);
	}
	return 0;
}
