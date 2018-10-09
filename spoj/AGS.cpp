/*
	NISHANT GUPTA
	CSE-MNNIT ALLAHABAD
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB; 
#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define EPS 1e-12 
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(i = a; i < n; i++)
#define rev(i, a, n) for(i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
inline void inp( int &n )
{ 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	
inline void inp1( LL &n )
{ 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

LL mod;
LL mulmod(LL a,LL b,LL c)
{
	LL ans=0;
	while(b>0)
	{
		if(b&1)ans=(ans+a)%c;
		a=(a*2)%c;
		b>>=1;
	}
	return ans%c;
}
LL power(LL base,LL e,LL ans,LL m)
{
	if(!e)return ans%m;
	if(e&1)ans=mulmod(ans,base,m);
	return power(mulmod(base,base,m),e>>1,ans,m);
}
LL calc(LL a,LL d,LL r,LL p)
{
	//cout<<a<<" "<<d<<" "<<r<<" "<<p<<endl;
	LL mm=mod*(r-1);
	//cout<<"mm "<<mm<<endl;
	LL ans=(a%mod);
	//cout<<ans<<endl;
	ans=(ans*power(r,p,1,mod))%mod;
	//cout<<ans<<endl;
	LL x=mulmod(d,r,mod);
	LL y=(power(r,p,1,mm)-1+mm)%mm;
	y=y/(r-1);
	//cout<<x<<" "<<y<<endl;
	LL num=mulmod(x,y,mod);
	//cout<<num<<endl;
	ans=(ans+num)%mod;
	return ans;
}
int main()
{
	LL i,j,k,n,t,r,a,d,ans;
	inp1(t);
	while(t--)
	{
		inp1(a);inp1(d);inp1(r);
		inp1(n);inp1(mod);
		ans=0;
		if(n==1)
		{printf("%lld\n",a%mod);continue;}
		if(r==1)
		{
			ans=(a+(n/2)*d)%mod;
		}
		else
		{
			LL nn=n;
			if((n&1)==0)nn--;
			ans=calc(a,d,r,nn/2);
			//cout<<ans<<endl;
			if((n&1)==0)  //even 
			{
				ans=(ans+d)%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}