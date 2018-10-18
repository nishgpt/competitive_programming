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
#define INF 1000000000
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

int find(int u,int *parent)
{
	if(u==parent[u])return u;
	int x=find(parent[u],parent);
	parent[u]=x;
	return x;
}

void _union(int u,int v,int *parent)
{
	parent[find(u,parent)]=find(v,parent);
}

int main()
{
	int t,i,j,k,n,m,u,c;
	inp(t);
	string s;
	while(t--)
	{
		getchar();
		inp(n);
		vector<pair<int,pair<int,int> > > edge;
		int parent[n+1];
		rep(i,0,n+1)parent[i]=i;
		rep(i,1,n+1)
		{
			cin>>s;
			inp(m);
			rep(j,0,m)
			{
				inp(u);inp(c);
				if(u>i)
				{
					edge.PB(MP(c,MP(i,u)));
				}
			}
		}
		sort(edge.begin(),edge.end());
		int ans=0;
		//rep(i,0,edge.size())
		//cout<<edge[i].Y.X<<" "<<edge[i].Y.Y<<" "<<edge[i].X<<endl;
		rep(i,0,edge.size())
		{
			int x=edge[i].Y.X;
			int y=edge[i].Y.Y;
			if(find(y,parent)!=find(x,parent)) //cycle not formed
			{
				_union(x,y,parent);
				ans+=edge[i].X;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}