/*
  NISHANT GUPTA
  MNNIT ALLAHABAD
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
//#include <limits.h>
#include <stdlib.h>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define INT_MAX 0x7FFF/0x7FFFFFFF
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n;i>=0;i--)
#define getcx getchar_unlocked
using namespace std;
inline void inp( int &n ) 
{
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}   
int que[2][36100],front=0,rear=0;
void push(int x,int y)
{
	que[0][rear]=x;
	que[1][rear++]=y;
}
void pop()
{front++;}
int abso(int x)
{
	if(x<0)return -x;
	return x;
}
int main()
{
	int t,i,j,k,n,m,x,y,ans[190][190];
	char a[190][190];
	inp(t);
	while(t--)
	{
		inp(n);inp(m);
		//memset(ans,10000000,sizeof(ans));
		rep(i,n)
		{rep(j,m)ans[i][j]=10000000;}
		rep(i,n)
		scanf("%s",a[i]);
		rep(i,n)
		{
			rep(j,m)
			{
				if(a[i][j]=='1')
				{
					ans[i][j]=0;front=rear=0;push(i,j);
					while(front!=rear)
					{
						x=que[0][front];y=que[1][front];
						pop();
						//north
						if(x-1>=0&&a[x-1][y]=='0'&&(abso(x-1-i)+abso(y-j))<ans[x-1][y])
						{push(x-1,y);ans[x-1][y]=abso(x-1-i)+abso(y-j);}
						//south
						if(x+1<n&&a[x+1][y]=='0'&&(abso(x+1-i)+abso(y-j))<ans[x+1][y])
						{push(x+1,y);ans[x+1][y]=abso(x+1-i)+abso(y-j);}
						//east
						if(y+1<m&&a[x][y+1]=='0'&&(abso(x-i)+abso(y+1-j))<ans[x][y+1])
						{push(x,y+1);ans[x][y+1]=abso(x-i)+abso(y+1-j);}
						//west
						if(y-1>=0&&a[x][y-1]=='0'&&(abso(x-i)+abso(y-1-j))<ans[x][y-1])
						{push(x,y-1);ans[x][y-1]=abso(x-i)+abso(y-1-j);}
					}
				}
			}
		}
		rep(i,n)
		{rep(j,m)printf("%d ",ans[i][j]);printf("\n");}
	}
	return 0;
}
		