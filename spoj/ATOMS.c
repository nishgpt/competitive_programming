#include <stdio.h>
int main()
{
	long long unsigned int x,a,r,i,j,k;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu %llu %llu",&a,&r,&x);
		k=0;
		if(x<=a){printf("0\n");continue;}
		j=x/a;
		i=r;
		while(i<=j)
		{
			i=i*r;
			k++;
		}
		//if(a>x)k--;
		printf("%llu\n",k);
	}
	return 0;
}