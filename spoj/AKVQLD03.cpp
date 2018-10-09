/*
  NISHANT GUPTA
  MNNIT ALLAHABAD
*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define abso(x) x<0?(-x):x
#define rep(i,x,n) for(i=x;i<n;i++)
#define rev(i,x,n) for(i=n;i>=x;i--)
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
int bit[1000005];
int query(int pos)
{
	int sum=0;
	while(pos>0)
	{
		sum+=bit[pos];
		pos-=(pos&-pos);
	}
	return sum;
}

void update(int pos,int val,int n)
{
	while(pos<=n)
	{
		bit[pos]+=val;
		pos+=(pos&-pos);
	}
}

int main()
{
	int i,j,k,n,a,b,q,pos,val;
	char s[10];
	inp(n);inp(q);
	rep(i,0,q)
	{
		scanf("%s",s);
		if(s[0]=='f')
		{
			inp(a);inp(b);
			if(a==1)printf("%d\n",query(b));
			else printf("%d\n",query(b)-query(a-1));
		}
		else if(s[0]=='a')
		{
			inp(pos);inp(val);
			update(pos,val,n);
		}
	}
	return 0;
}