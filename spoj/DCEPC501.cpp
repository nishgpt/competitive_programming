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
LL a[100015],sum[100015],dp[100015];
LL cal(int idx,int n)
{
	if(idx>n)return 0;
	if(dp[idx]!=-1)return dp[idx];
	LL sum1,sum2,sum3;
	sum1=sum[idx]-sum[idx-1];
	if(idx+1>n)sum2=sum[n]-sum[idx-1];else sum2=sum[idx+1]-sum[idx-1];
	if(idx+2>n)sum3=sum[n]-sum[idx-1];else sum3=sum[idx+2]-sum[idx-1];
	dp[idx]=MAX((sum1+cal(idx+2,n)),MAX((sum2+cal(idx+4,n)),(sum3+cal(idx+6,n))));
	return dp[idx];
}
int main()
{
	int t,n,i,j,k;
	inp(t);
	while(t--)
	{
		LL ans;
		inp(n);
		dp[0]=-1;
		sum[0]=0;
		rep(i,1,n+1)
		{
			inp1(a[i]);
			if(!i)sum[i]=a[i];
			else sum[i]=sum[i-1]+a[i];
			dp[i]=-1;
		}
		ans=cal(1,n);//index,a[],sum[],n
		printf("%lld\n",ans);
	}
	return 0;
}