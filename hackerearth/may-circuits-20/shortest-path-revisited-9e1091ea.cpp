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
LL mincost[MAX];
vector<pair<int, LL> > adj[MAX];

struct info {
	int node;
	LL cost;
	multiset<LL> skipped;
};

bool operator <(info a, info b) {
	return a.cost>b.cost;
}

void dijkstra() {
	int i;
	rep(i, 0, MAX) mincost[i] = INFL;
	priority_queue<info> pq;
	
	multiset<LL> dummy;
	pq.push((info) {1, 0, dummy});
	mincost[1] = 0;
	
	while(!pq.empty()) {
		info _top = pq.top();
		pq.pop();
		
		rep(i, 0, adj[_top.node].size()) {
			multiset<LL> ms = _top.skipped;
			int ch = adj[_top.node][i].X;
			LL wt = adj[_top.node][i].Y;
			if(ms.size() < k) { //skipping wt of this edge
				if(mincost[_top.node] < mincost[ch]) {
					mincost[ch] = mincost[_top.node];
					ms.insert(wt);
					pq.push((info) {ch, mincost[ch], ms});
				}
			} else { //filled with k skipped edges
				multiset<LL>::iterator it = ms.begin();
				if((*it) < wt) {
					if(mincost[_top.node] + (*it) < mincost[ch]) {
						mincost[ch] = mincost[_top.node] + (*it);
						ms.erase(it);
						ms.insert(wt);
						pq.push((info) {ch, mincost[ch], ms});
					}
				} else {
					if(mincost[_top.node] + wt < mincost[ch]) {
						mincost[ch] = mincost[_top.node] + wt;
						pq.push((info) {ch, mincost[ch], ms});
					}
				}
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
		printf("%lld ", mincost[i]);
	}
	printf("\n");
	
    return 0;
}

