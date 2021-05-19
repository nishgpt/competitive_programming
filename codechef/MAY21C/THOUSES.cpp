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
#define MAX 300005
#define LOG_MAX 20
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
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

LL ans;
LL rearrange_dfs(int node, int par, vector<pair<LL, int> > adj[MAX]) {
	//call rearrange_dfs for children 
	for(int i=0;i<adj[node].size();i++) {
		if(par != adj[node][i].Y) {
			LL value = rearrange_dfs(adj[node][i].Y, node, adj);
			adj[node][i].X = value;
		}
	}
	
	//rearrange children now
	sort(adj[node].rbegin(), adj[node].rend());
	
	//populate value for node
	LL offset = 1, value = 1; //self value preset 
	for(int i=0;i<adj[node].size();i++, offset++) {
		if(par != adj[node][i].Y) {
			value += (offset * adj[node][i].X);
		}
	}
	
	return value;
}

void compute_dfs(int node, int par, int seed_x, vector<pair<LL, int> > adj[MAX]) {
	ans = (ans + seed_x) % MOD;
	
	LL offset = 1;
	for(int i=0;i<adj[node].size();i++, offset++) {
		if(par == adj[node][i].Y) continue;
		
		int ch_seed_x = (offset * seed_x) % MOD;
		compute_dfs(adj[node][i].Y, node, ch_seed_x, adj);
	}
}

void solve() {
	int n, x; in2(n, x);
	int u, v;
	vector<pair<LL, int> > adj[MAX];
	
	for(int i=0;i<n-1;i++) {
		in2(u, v);
		adj[u].PB(MP(-1, v));
		adj[v].PB(MP(-1, u));
	}
	
	rearrange_dfs(1, -1, adj);
	
	ans = 0;
	compute_dfs(1, -1, x, adj);
	
	printf("%lld\n", ans);
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
