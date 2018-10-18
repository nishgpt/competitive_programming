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

struct way
{
	int node;
	double cost;
};

double mincost[105];
bool operator <(way a,way b)
{
	return mincost[a.node]<mincost[b.node];
}

void dijkstra(vector<way> adj[],int st,int end,int n)
{
	int i,j,k;
	rep(i,0,n+1)mincost[i]=-1;
	mincost[st]=1.00;
	priority_queue<way> pq;
	pq.push((way){st,1.00});
	while(!pq.empty())
	{
		way x=pq.top();
		pq.pop();
		//cout<<x.node<<" "<<mincost[x.node]<<endl;
		rep(i,0,adj[x.node].size())
		{
			way k=adj[x.node][i];
			if(mincost[x.node]*(k.cost)>mincost[k.node])
			{
				mincost[k.node]=mincost[x.node]*k.cost;
				pq.push(k);
			}
		}
	}
	printf("%.6lf percent\n",mincost[end]*100);
	return ;
}
int main()
{
	int n,m,i,j,k,u,v;double c;
	while(1)
	{
		inp(n);
		if(n==0)break;
		inp(m);
		vector<way> adj[105];
		rep(i,0,m)
		{
			//inp(u);inp(v);inp(c);
			cin>>u>>v>>c;
			c=c/100.00;
			adj[u].PB((way){v,c});
			adj[v].PB((way){u,c});
		}
		dijkstra(adj,1,n,n);
	}
	return 0;
}
