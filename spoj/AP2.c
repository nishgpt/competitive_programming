#include <stdio.h>
int main()
{
	long long int t,th,tl,s,i,j,a,d,n;
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld %lld %lld",&th,&tl,&s);
		n=(2*s)/(th+tl);
		d=(tl-th)/(n-5);
		a=th-2*d;
		printf("%lld\n",n);
		for(j=0;j<n;j++)
			printf("%lld ",a+d*j);
		printf("\n");
	}
	return 0;
}
