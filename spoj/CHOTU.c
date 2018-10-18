#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	double x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf",&x,&y);
		printf("%.3lf\n",2.0*x*sqrt(1-(y*y)/(x*x)));
	}
	return 0;
}