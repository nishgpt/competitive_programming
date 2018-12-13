#include <stdio.h>
#include <string.h>
#define maxi(x,y) (x>y?x:y)
int b[2510][2510][3];

int time(int h,int a,int p)
{
	if(p==0) //air
		{h+=3;a+=2;}
	else if(p==1) //water
		{h-=5;a-=10;}
	else if(p==2)  //fire
		{h-=20;a+=5;}

	if(h<=0||a<=0)
		return 0;
	if(b[h][a][p])
		return b[h][a][p];
	if(p==1)  //water to others
		b[h][a][p]=1+maxi(time(h,a,0),time(h,a,2));
	else if(p==2)  //fire to others
		b[h][a][p]=1+maxi(time(h,a,0),time(h,a,1));
	else if(p==0)   //air to others
		b[h][a][p]=1+maxi(time(h,a,1),time(h,a,2));
	return b[h][a][p];
}

int main()
{
	int i,t,p,h,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&h,&a);
		int ans=maxi(time(h,a,0),maxi(time(h,a,1),time(h,a,2)));
		printf("%d\n",ans);
	}
	return 0;
}