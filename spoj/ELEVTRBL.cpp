/*
  NISHANT GUPTA
  MNNIT ALLAHABAD
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
//#define abso(x) ((x)<0?(-x):(x))
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
int abso(int x)
{
	if(x<0)return -x;
	return x;
}  
int queue[2][2000005],front=0,rear=0,visited[2000005]={0};
void insert(int x,int level)
{
	queue[0][rear]=x;
	queue[1][rear++]=level;
}
void del()
{front++;}
int gcd(int x,int y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int main()
{
	int i,k,st,l,dest,up,down,floors;
	inp(floors);
	inp(st);inp(dest);
	inp(up);inp(down);
	if(st==dest){printf("0\n");return 0;}
	//int a=abso(st-dest),g=gcd(up,down);//printf("%d\n",a);
		//bfs
		insert(st,0);visited[st]=1;int f=0;
		while(front!=rear)
		{
			k=queue[0][front];l=queue[1][front];
			del();
			if(k==dest){f=1;break;}
			if(k+up<=floors&&visited[k+up]!=1)
				{insert(k+up,l+1);visited[k+up]=1;}
			if(k-down>=1&&visited[k-down]!=1)
				{insert(k-down,l+1);visited[k-down]=1;}
		}
		if(f)
		printf("%d\n",l);
		else printf("use the stairs\n");
	return 0;
}