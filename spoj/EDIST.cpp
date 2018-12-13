#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
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
int a[3002][3002];
int min3(int x,int y,int z)
{
	return min(x,(min(y,z)));
}
int main()
{
	int i,t,j,n,m,c;
	char s1[3002],s2[3002];
	inp(t);
	while(t--)
	{
		scanf("%s",s1);
		scanf("%s",s2);
		memset(a,0,sizeof a);
		int l1=strlen(s1),l2=strlen(s2);
		rep(i,l1+1)a[i][0]=i;
		rep(i,l2+1)a[0][i]=i;
		for(i=1;i<=l1;i++)
		{
			for(j=1;j<=l2;j++)
			{
				a[i][j]=min3(a[i-1][j]+1,a[i][j-1]+1,a[i-1][j-1]+(s1[i-1]!=s2[j-1]));
			}
		}
		printf("%d\n",a[l1][l2]);
	}
	return 0;
}