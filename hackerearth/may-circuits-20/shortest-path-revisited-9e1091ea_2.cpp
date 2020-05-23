/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 100005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 1e18
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

inline void inp1( LL &n ) { 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int n, m, u, v, k;
LL w;
LL mincost[MAX][20];
vector<pair<int, LL> > adj[MAX];

struct info {
	int node;
	int layer;
	LL cost;
};

bool operator <(info a, info b) {
	return a.cost>b.cost;
}

void dijkstra() {
	int i, j;
	rep(i, 0, MAX) rep(j, 0, 20) mincost[i][j] = INFL;
	
	priority_queue<info> pq;
	
	pq.push((info) {1, 0, 0});
	mincost[1][0] = 0;
	
	while(!pq.empty()) {
		info _top = pq.top();
		int node = _top.node;
		int layer = _top.layer;
		pq.pop();
		
		if(layer + 1 <= k && mincost[node][layer] < mincost[node][layer+1]) {
			mincost[node][layer+1] = mincost[node][layer];
			pq.push((info) {node, layer + 1, mincost[node][layer]});
		}
		
		rep(i, 0, adj[node].size()) {
			if(mincost[node][layer] + adj[node][i].Y < mincost[adj[node][i].X][layer]) {
				mincost[adj[node][i].X][layer] = mincost[node][layer] + adj[node][i].Y;
				pq.push((info) {adj[node][i].X, layer, mincost[adj[node][i].X][layer]});
			}
			
			if(layer + 1 <= k && mincost[node][layer] < mincost[adj[node][i].X][layer+1]) {
				mincost[adj[node][i].X][layer+1] = mincost[node][layer];
				pq.push((info) {adj[node][i].X, layer+1, mincost[adj[node][i].X][layer+1]}); 
			}
		}
	}
}

int main() {
	inp(n);inp(m);inp(k);
	int i;
	
	rep(i, 0, m) {
		inp(u);inp(v);inp1(w);
		adj[u].PB(MP(v, w));
		adj[v].PB(MP(u, w));
	}
	
	dijkstra();
	for(i=1;i<=n;i++) {
		printf("%lld ", mincost[i][k]);
	}
	printf("\n");
	
    return 0;
}

