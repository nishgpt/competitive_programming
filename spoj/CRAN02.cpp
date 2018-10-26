/*	NISHANT GUPTA	CSE-MNNIT ALLAHABAD*/
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
typedef long long LL;typedef vector<int> VI;typedef pair<int, int> II;typedef vector<long long> VLL;typedef vector<bool> VB; 
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
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12 
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
inline void inp( LL &n )
{ 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	
LL freq[20000005],a[1000005],sum[10000005];
int main()
{
	LL i,j,t,n,k;
	inp(t);
	while(t--)
	{
		inp(n);
		LL min=100000000,max=-100000000;
		rep(i,0,n)
		{
			inp(a[i]);
			if(!i)sum[i]=a[i];
			else sum[i]=sum[i-1]+a[i];
			freq[sum[i]+10000000]++;
			if(sum[i]>max)max=sum[i];
			if(sum[i]<min)min=sum[i];
		}
		freq[10000000]+=1; //zero
		LL ans=0;
		min+=10000000;max+=10000000;
		rep(i,min,max+1)
		{
			ans+=(freq[i]*(freq[i]-1))>>1;
			freq[i]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}