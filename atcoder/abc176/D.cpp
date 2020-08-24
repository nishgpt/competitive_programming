/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 1000005
#define LOG_MAX 20
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define finish(x) {cout<<x<<'\n'; return;}
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

int n, m;
vector<pi> adj[MAX];
bool valid(int i, int j) {
	return i>=0 && j>=0 && i<n && j<m;
}

/* Dijkstra Algo */
int dijkstra(int s, int d) {
	int mincost[MAX], i;
	rep(i, 0, MAX) mincost[i] = INT_MAX;
	
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push(MP(0, s));
	mincost[s] = 0;
	
	while(!pq.empty()) {
		pi _top = pq.top();
		pq.pop();
		int node = _top.Y;
		
		for(i=0;i<adj[node].size();i++) {
			int ch = adj[node][i].X;
			int wt = adj[node][i].Y;
			if(mincost[node] + wt < mincost[ch]) {
				mincost[ch] = mincost[node] + wt;
				pq.push(MP(mincost[ch], ch));
			} 
		}
	}
	
	return mincost[d];
}

int get_node(int i, int j) {
	return i*m + j;
}

void solve() {
	in2(n, m);
	int si, sj, di, dj;
	in2(si, sj);
	in2(di, dj);
	si--;sj--;di--;dj--;
	
	string s[n];
	for(int i=0;i<n;i++) cin>>s[i];
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(s[i][j] == '#') continue;
			int u = get_node(i, j);
			
			for(int xi=i-2;xi<=i+2;xi++) {
				for(int xj=j-2;xj<=j+2;xj++) {
					if(valid(xi, xj) && s[xi][xj] == '.') {
						int wt = (abs(xi-i) + abs(xj-j)) == 1 ? 0 : 1;
						int v = get_node(xi, xj);
						adj[u].PB(MP(v, wt));
					}
				}
			}
		}
	}
	
	int st = get_node(si, sj);
	int dest = get_node(di, dj);
	int ans = dijkstra(st, dest);
	if(ans == INT_MAX) ans = -1;
	cout<<ans<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
