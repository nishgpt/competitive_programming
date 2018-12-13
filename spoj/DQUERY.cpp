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

int mysqrt(int num)
{   
	if(num==0)
	   return 0;
	int n = (num / 2) + 1;
	int n1 = (n + (num / n)) / 2;
	while (n1 < n)
	{
		n = n1;   //x++;
		n1 = (n + (num / n)) / 2;
	} 
	return n;
}

int f[1000005],ans,n,m,a[30005],answer[200005];
struct X
{
	int st,end,idx,b;
}q[200005];

int cmp(struct X a,struct X b)
{
	return a.b==b.b?(a.end<b.end?1:0):(a.b<b.b?1:0);
}
void increase(int pos)
{
	f[a[pos]]++;
	if(f[a[pos]]==1)
		ans++;
}

void decrease(int pos)
{
	f[a[pos]]--;
	if(f[a[pos]]==0)
		ans--;
}
int main()
{
	int i,j,k;
	inp(n);
	rep(i,0,n)
		inp(a[i]);
	
	int sq=mysqrt(n);
	inp(m);
	rep(i,0,m)
	{
		inp(q[i].st);inp(q[i].end);
		q[i].st--;q[i].end--;
		q[i].idx=i;
		q[i].b=(q[i].st/sq);
	}
	sort(q,q+m,cmp);
	/*rep(i,0,m)
	{
		cout<<q[i].st<<" "<<q[i].end<<" "<<q[i].b<<endl;
	}*/
	int curl,curr;
	i=0;
	while(i<m)
	{
		if(i==0||q[i].b!=q[i-1].b)
		{
			//cout<<i<<endl;
			curl=curr=q[i].b*sq;
			ans=0;
			MS(f);
		}
		//cout<<curl<<" "<<curr<<endl;
		while(curl<q[i].st)
		{
			decrease(curl);
			curl++;
		}
		while(curl>q[i].st)
		{
			increase(curl-1);
			curl--;
		}
		while(curr<=q[i].end)
		{
			increase(curr);
			curr++;
		}
		while(curr>q[i].end+1)
		{
			decrease(curr-1);
			curr--;
		}
		//cout<<ans<<endl;
		answer[q[i].idx]=ans;
		i++;	
	}
	rep(i,0,m)
		printf("%d\n",answer[i]);
		return 0;
}