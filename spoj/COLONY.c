/*
  NISHANT GUPTA
  MNNIT ALLAHABAD
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
//#include <algorithm>
#include <stdlib.h>
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define abso(x) x<0?(-x):x
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n;i>=0;i--)
#define LL long long int
//#define getcx getchar_unlocked
//using namespace std;
/*inline void inp( LL &n ) 
{
    n=0;
    LL ch=getcx();LL sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
} */  
int main()
{
	LL i,j,k,p,y,q;
	LL a[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776,2199023255552,4398046511104,8796093022208,17592186044416,35184372088832,70368744177664,140737488355328,281474976710656,562949953421312,1125899906842624,2251799813685248};
	//inp(y);
	//inp(p);
	scanf("%lld",&y);
	scanf("%lld",&p);
	q=0;
	p++;
	for(i=y;i>0;i--)
	{
		if(p>(a[i]/2))
		{
			p=p-(a[i]/2);
		}
		else q++;
	}
	if(q&1)
	printf("blue\n");
	else printf("red\n");
	return 0;
}