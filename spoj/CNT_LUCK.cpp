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
typedef long long unsigned int LL;
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
#define rep(i, a, n) for(i = a; i < n; i++)
#define rev(i, a, n) for(i = a; i > n; i--)
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
LL ncr[65][65]={0};
LL ar[]={4,7,44,47};
string bin(LL n)
{
	LL i;
	if(n==0)return "0";
	string str;
	char c;
	for(i=n;i;i>>=1)
	{
		c=(char)((i&1)+48);
		str=c+str;
	}
	return str;
}
LL comb(LL n,LL r)
{
	if(r>n|| n<0 || r<0)
		return 0;
	if(r==n)
		return 1;
	if(r > n-r)
		r = n-r;

	LL i,j,k;
	LL ans=1;
	for(i=1;i<=r;i++)
	{
		ans=ans*(n-i+1);
		ans=ans/i;
	}
	return ans;
}
LL func(LL n)
{
	string str;
	str=bin(n);
	//cout<<str<<endl;
	LL one=0,ans=0,i,j,l=str.length(),p;
	rep(i,0,l)
	{
		if(str[i]=='1')
		{
			//assume it as 0 and compute all possible comnbinations further
			p=l-i-1;
			rep(j,0,4)
			{
				if(ar[j]>=one)ans+=ncr[p][ar[j]-one];
			}
			one++; //now assume it 1 search for next 1
		}
	}
	return ans;
}
int main()
{
	LL t,i,a,b,j;
	rep(i,0,65)
	{
		ncr[i][i]=1;
		ncr[i][0]=1;
	}
	rep(i,1,65)
		rep(j,1,i)
			ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
	//computed ncr
	//printf("%llu\n",ncr[60][30]);
	inp(t);
	while(t--)
	{
		inp(a);inp(b);
		printf("%llu\n",func(b+1)-func(a));
	}
	return 0;
}