/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 200005
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

int sub[MAX];
int stay[MAX];
int h[MAX];
vector<int> adj[MAX];
int dfs(int node, int par) {
	sub[node] = stay[node];
	
	for(int i=0;i<adj[node].size();i++) {
		if(adj[node][i] != par) sub[node] += dfs(adj[node][i], node);
	}
	return sub[node];
}

void solve() {
	int n, m;
	in2(n, m);
	for(int i=1;i<=n;i++) {
		in(stay[i]);
	}
	for(int i=1;i<=n;i++) {
		in(h[i]);
	}
	
	//clear adj
	for(int i=0;i<=n;i++) adj[i].clear();
	
	for(int i=0;i<n-1;i++) {
		int u, v;
		in2(u ,v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	dfs(1, -1); //calclate total people who will be passing through a certain node
	
	int g1 = (m+h[1])>>1;
	int b1 = m-g1;
	
	if(!(g1+b1 == m && g1-b1 ==h[1] && g1>=0 && b1>=0 && stay[1]<=g1+b1)) {
		finish("NO");
	}
	
	queue<pair<int, pair<int, int> > > q;
	q.push(MP(1, MP(g1, b1)));
	
	bool ok = true;
	vector<bool> vis(n+1, false);
	vis[1] = true;
	while(!q.empty()) {
		int node = q.front().X;
		int g = q.front().Y.X;
		int b = q.front().Y.Y;
		q.pop();
		
		LL sg = 0, sb = 0;
		for(int i=0;i<adj[node].size();i++) {
			int ch = adj[node][i];
			if(vis[ch]) continue;
			int cg = (sub[ch] + h[ch]) >> 1;
			int cb = sub[ch] - cg;
			
			if((cg+cb)!=sub[ch] || cg<0 || cb<0 || (cg-cb)!=h[ch]) {
				ok = false;break;
			}
			
			sg+=cg;
			sb+=cb;
			q.push(MP(ch, MP(cg, cb)));
			vis[ch] = true;
		}
		if(!ok) break;
		
		if(g+b != (sg+sb+stay[node]) || sg > g) {
			ok = false;break;
		}
	}
	
	if(ok) finish("YES");
	finish("NO");
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
