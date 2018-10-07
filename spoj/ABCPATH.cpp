/*
  NISHANT GUPTA
  MNNIT ALLAHABAD
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define maxi(x,y) (x>y?x:y)
#define mini(x,y) (x<y?x:y)
#define abso(x) x<0?(-x):x
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
int n,m;
int calculate(int x,int y,char c,char a[][55],int ans[][55])
{
	if(ans[x][y]!=-1)return ans[x][y];
	int max=0;
	//printf("called(%d %d %c %d)\n",x,y,c,ans[x][y]);
	//east
	if(y+1<m&&a[x][y+1]==(char)(c+1))
	{ans[x][y]=maxi(ans[x][y],1+calculate(x,y+1,(char)(c+1),a,ans));max=maxi(max,ans[x][y]);}
	//printf("called(%d %d %c %d)\n",x,y,c,ans[x][y]);
	//south
	if(x+1<n&&a[x+1][y]==(char)(c+1))
	{ans[x][y]=maxi(ans[x][y],1+calculate(x+1,y,(char)(c+1),a,ans));max=maxi(max,ans[x][y]);}
	
	//west
	if(y-1>=0&&a[x][y-1]==(char)(c+1))
	{ans[x][y]=maxi(ans[x][y],1+calculate(x,y-1,(char)(c+1),a,ans));max=maxi(max,ans[x][y]);}
	
	//north
	if(x-1>=0&&a[x-1][y]==(char)(c+1))
	{ans[x][y]=maxi(ans[x][y],1+calculate(x-1,y,(char)(c+1),a,ans));max=maxi(max,ans[x][y]);}
	
	//south east
	if(y+1<m&&x+1<n&&a[x+1][y+1]==(char)(c+1))
	{ans[x][y]=maxi(ans[x][y],1+calculate(x+1,y+1,(char)(c+1),a,ans));max=maxi(max,ans[x][y]);}
	
	//south west
	if(y-1>=0&&x+1<n&&a[x+1][y-1]==(char)(c+1))
	{ans[x][y]=maxi(ans[x][y],1+calculate(x+1,y-1,(char)(c+1),a,ans));max=maxi(max,ans[x][y]);}
	
	//north east
	if(y+1<m&&x-1>=0&&a[x-1][y+1]==(char)(c+1))
	{ans[x][y]=maxi(ans[x][y],1+calculate(x-1,y+1,(char)(c+1),a,ans));max=maxi(max,ans[x][y]);}
	
	//north west
	if(y-1>=0&&x-1>=0&&a[x-1][y-1]==(char)(c+1))
	{ans[x][y]=maxi(ans[x][y],1+calculate(x-1,y-1,(char)(c+1),a,ans));max=maxi(max,ans[x][y]);}
	ans[x][y]=max;
	return max;
}
int main()
{
	int i,j,max_len,ans[55][55],k=1;
	char a[55][55];
	inp(n);inp(m);
	while((n+m))
	{
		rep(i,n)
		scanf("%s",a[i]);
		memset(ans,-1,sizeof ans);
		max_len=-1;
		rep(i,n)
		{
			rep(j,m)
			{
				if(a[i][j]=='A')
				{
					ans[i][j]=calculate(i,j,'A',a,ans);
					max_len=maxi(max_len,ans[i][j]);
				}
			}
		}
		/*rep(i,n)
		{
			rep(j,m)
			printf("%d\t",ans[i][j]);
			printf("\n");
		}
		*/
		printf("Case %d: %d\n",k++,max_len+1);
		inp(n);inp(m);
	}
	return 0;
} 
