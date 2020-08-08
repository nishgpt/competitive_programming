/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
#include <functional>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 100005
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
typedef pair<int, LL> pil;
const char en = '\n';

struct compare { 
    bool operator()(pil& p1, pil& p2) {
		LL loss1 = p1.X * (p1.Y - p1.Y/2);
		LL loss2 = p2.X * (p2.Y - p2.Y/2);
		return loss1 < loss2;
    }
};

vector<pil> adj[MAX];
map<pi, pil> leaf_paths;

int dfs(int node, int par) {
	int cnt = 0;
	for(int i=0;i<adj[node].size();i++) {
		if(par != adj[node][i].X) {
			int temp = dfs(adj[node][i].X, node);
			leaf_paths[MP(min(node, adj[node][i].X), max(node, adj[node][i].X))] = MP(temp, adj[node][i].Y);
			cnt += temp;
		}
	}
	if(cnt == 0) cnt = 1;
	return cnt;
}

void solve() {
	int n;in(n);
	LL s; inl(s);
	int u, v; LL w;
	
	for(int i=0;i<n-1;i++) {
		in2(u, v);
		inl(w);
		adj[u].PB(MP(v, w));
		adj[v].PB(MP(u, w));
	}
	
	dfs(1, -1);
	
	map<pi, pil> :: iterator it;
	priority_queue<pil, vector<pil>, compare> pq;
	LL sum = 0;
	for(it=leaf_paths.begin();it!=leaf_paths.end();it++) {
		LL contri = it->Y.Y * it->Y.X;
		sum += contri;
		pq.push(MP(it->Y.X, it->Y.Y));
	}
	
	int ans = 0;
	while(sum > s) {
		pil edge = pq.top();
		pq.pop();
		
		sum -= (edge.X * edge.Y);
		edge.Y>>=1;
		sum += (edge.X * edge.Y);
		pq.push(edge);
		ans++;
	}
	cout<<ans<<en;
	
	//clear
	for(int i=1;i<=n;i++) adj[i].clear();
	leaf_paths.clear();
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
