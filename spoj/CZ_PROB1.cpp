#include <stdio.h>
#include <string.h>
#include <math.h>
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

int main()
{
	LL n,i,j,t,s,k,p,prime[10000]={0},a[10000];
	for(p=2;p*p<=10000;p++)
	{
		if(!prime[p])
		for(j=2*p;j<=10000;j+=p)
			prime[j]=1;
	}
	prime[0]=prime[1]=1;
	p=0;a[p++]=2;
	for(i=3;i<10000;i++){if(!prime[i]&&(!((i-1)%4)))a[p++]=i;}
	//printf("%lld\n",p);
	//inp(t);
	scanf("%lld",&t);
	while(t--)
	{
		//inp(n);inp(k);
		scanf("%lld %lld",&n,&k);
		if(k==1)printf("1\n");
		else if(k==2)printf("%lld\n",(a[n-1]/2)+1);
		else if(k==3)printf("%lld\n",((a[n-1]+3)*(a[n-1]+3))/12);
	}
return 0;
}