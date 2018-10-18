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

int main()
{
	int i,x,j,k,n,a[5005],diff[5005],temp[2][5005],p=0;
	inp(n);
	diff[0]=0;
	rep(i,n)
	{
		inp(a[i]);
		if(i)
		{
			diff[i]=diff[i-1]+(a[i]-a[i-1]);
			if(!p){temp[0][p]=diff[i];temp[1][p++]=a[i];}
			else
			{
				k=0;
				for(j=0;j<p;j++)
				{
					if(a[i]==temp[1][j]+temp[0][j])
					{k=1;temp[1][j]=a[i];}
				}
				if(!k){temp[0][p]=diff[i];temp[1][p++]=a[i];}
			}
			//for(x=0;x<p;x++)printf("%d %d\n",temp[0][x],temp[1][x]);printf("\n");
		}
	}
	
	printf("%d\n",p);
	return 0;
}