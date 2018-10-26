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

LL freq[1000005];
void func(LL k,LL p)
{
	LL i,j;
	LL ans=0;
	if(freq[0]){ans+=((freq[0]*(freq[0]+1))/2);freq[0]=0;}
	rep(i,1,p+1)
	{
		if(freq[i])
		{
			j=freq[i]-1;
			ans+=(j*(j+1)/2);
		}
		freq[i]=0;
	}
	printf("%lld\n",ans);
}
int main()
{
	LL i,t,j,k,n;
	inp(t);
	string s;
	while(t--)
	{
		inp(n);inp(k);
		cin>>s;//MS(freq);
		freq[s[0]-48]++;
		LL p=s[0]-48,q;LL ans=0;
		rep(i,1,n)
		{
			q=p+s[i]-48;
			freq[q]++;
			p=q;
		}
		if(!k){func(k,p);continue;}
		if(freq[0])
			{ans+=(freq[0]*freq[k]);freq[0]=0;}
		rep(i,1,p+1)
		{
			if(freq[i])
			{
				//one for i+k-1
				if(i+k-1<=1000000)
				ans+=freq[i+k-1];
				//rest for i+k
				if(i+k<=1000000)
				ans+=(freq[i+k]*(freq[i]-1));
			}
			freq[i]=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}