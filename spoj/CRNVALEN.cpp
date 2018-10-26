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
	int a[10005],n,i,j,max1,max2;
	int t;
	inp(t);
	while(t--){
	int fmax1=0,fmax2=0;
	max1=max2=-1;
	int min=1000000007;
	inp(n);
	rep(i,n)
	{
		inp(a[i]);
		//freq[a[i]]++;
		if(a[i]<min)min=a[i];
		if(max1<a[i]){max2=max1;max1=a[i];}
		else if(a[i]>max2&&a[i]!=max1){max2=a[i];}
	}
	rep(i,n)
	{
		if(a[i]==max1)fmax1++;
		if(a[i]==max2)fmax2++;
	}
	if(max1>=n)printf("-1\n");
	else
	{
		if(max1==0)printf("0\n");
		else if(max1==n-1&&max2==-1)printf("%d\n",n);
		else if(max1-max2==1)
		{
			if(fmax2==max1&&max2==min)printf("%d\n",max1);
			else printf("-1\n");
		}
		else printf("-1\n");
	}
	}
	return 0;
}
	