#include <stdio.h>
#include <string.h>
#define max(a,b) a>b?a:b
int main()
{
	int x[10],i,j,y[10],h[21],w[21],c,d;
	while(scanf("%d %d",&c,&d)==2)
	{
		if(c+d==0)break;
		j=0;memset(h,0,sizeof h);memset(w,0,sizeof w);
		for(i=0;i<c;i++){scanf("%d",&x[i]);h[x[i]]++;}
		for(i=0;i<d;i++){scanf("%d",&y[i]);w[y[i]]++;}
		for(i=1;i<21;i++)
			j=i*(max(h[i],w[i]))+j;
		printf("%d\n",j);
	}
	return 0;
}
