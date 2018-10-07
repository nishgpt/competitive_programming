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
 
struct way
{
	int node;
	int cost;
};
 
bool operator <(way a,way b)
{
	return a.cost>b.cost;
}
 
int mincost[100005];
 
void dijkstra(vector<way> adj[],int st,int end,int n)
{
	int i,j,k;
	rep(i,0,n+1)mincost[i]=INF;
	mincost[st]=0;
	priority_queue<way> pq;
	pq.push((way){st,0});
	while(!pq.empty())
	{
		way x=pq.top();
		pq.pop();
		rep(i,0,adj[x.node].size())
		{
			way k=adj[x.node][i];
			if(mincost[x.node]+k.cost<mincost[k.node])
			{
				mincost[k.node]=mincost[x.node]+k.cost;
				k.cost = mincost[k.node];
				pq.push(k);
			}
		}
	}
	if(mincost[end]==INF)printf("NONE\n");
	else printf("%d\n",mincost[end]);
	return ;
}
int main()
{
	int i,j,n,st,end,m,t,u,v,c;
	inp(t);
	while(t--)
	{
		scanf("%d %d %d %d",&n,&m,&st,&end);
		vector<way> adj[n+1];
		rep(i,0,m)
		{
			scanf("%d %d %d",&u,&v,&c);
			adj[u].PB((way){v,c});
			adj[v].PB((way){u,c});
		}
		dijkstra(adj,st,end,n);
	}
}