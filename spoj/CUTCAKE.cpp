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
#define LL long long int
#define getcx getchar_unlocked
using namespace std;
inline void inp( LL &n ) 
{
    n=0;
    LL ch=getcx();LL sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}   


LL mysqrt(LL num)
{   //LL x=0;
	if(num==0)
	   return 0;
	LL n = (num / 2) + 1;
	LL n1 = (n + (num / n)) / 2;
	while (n1 < n)
	{
		n = n1;   //x++;
		n1 = (n + (num / n)) / 2;
	} 
	//printf("iterated %lld times\n",x);
	return n;
}

int main()
{
	LL n,k,t,j;
	inp(t);
	while(t--)
	{
		inp(n);
		j=8*n-7;
		LL sq=mysqrt(j);
		if(sq*sq!=j)sq++;
		sq--;
		if(sq&1)sq++;
		printf("%lld\n",sq/2);
	}
	return 0;
}
		