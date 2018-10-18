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
#define MAXN 30005
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
string s;
struct X
{
	int opn,cls;
}seg[4*MAXN];

void build_tree(int node,int st,int end)
{
	if(st==end)
	{
		if(s[st]=='(')
		{
			seg[node].opn=0;
			seg[node].cls=1;
		}
		else
		{
			seg[node].opn=1;
			seg[node].cls=0;
		}
		return ;
	}
	int mid=(st+end)>>1;
	build_tree(node*2,st,mid);
	build_tree(node*2+1,mid+1,end);
	seg[node].opn=seg[node*2].opn;
	seg[node].cls=seg[node*2+1].cls;
	if(seg[node*2].cls<seg[node*2+1].opn)seg[node].opn+=(seg[node*2+1].opn-seg[node*2].cls);
	else if(seg[node*2].cls>seg[node*2+1].opn)seg[node].cls+=(seg[node*2].cls-seg[node*2+1].opn);
	return ;
}

void update(int node,int st,int end,int pos)
{
	if(pos<st||pos>end)return ;
	if(st==end&&st==pos)
	{
		if(s[st]=='(')
		{
			s[st]=')';
			seg[node].opn=1;
			seg[node].cls=0;
		}
		else
		{
			s[st]='(';
			seg[node].opn=0;
			seg[node].cls=1;
		}
		return ;
	}
	int mid=(st+end)>>1;
	update(node*2,st,mid,pos);
	update(node*2+1,mid+1,end,pos);
	seg[node].opn=seg[node*2].opn;
	seg[node].cls=seg[node*2+1].cls;
	if(seg[node*2].cls<seg[node*2+1].opn)seg[node].opn+=(seg[node*2+1].opn-seg[node*2].cls);
	else if(seg[node*2].cls>seg[node*2+1].opn)seg[node].cls+=(seg[node*2].cls-seg[node*2+1].opn);
	return ;
}
int main()
{
	int i,j,k,n,m,x=1;
	while(x<=10)
	{
		inp(n);
		cin>>s;
		build_tree(1,0,n-1);
		inp(m);
		printf("Test %d:\n",x++);
		while(m--)
		{
			
			inp(k);
			if(!k)
			{
				if(seg[1].opn==0&&seg[1].cls==0)printf("YES\n");
				else printf("NO\n");
			}
			else
				update(1,0,n-1,k-1);
		}	
	}
	return 0;
}