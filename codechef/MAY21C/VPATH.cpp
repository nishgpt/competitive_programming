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
const char en = '\n';

pl dfs(int node, int par, vector<int> adj[MAX]) {
	LL node_sum = 1, node_comb = 0; //for the node itself
	
	vector<pl> ch_ans;
	LL ch_sum = 0;
	for(int i=0;i<adj[node].size();i++) {
		if(adj[node][i] != par) {
			pl ch = dfs(adj[node][i], node, adj);
			ch_ans.PB(ch);
			ch_sum = (ch_sum + ch.X) % MOD;
		}
	}
	
	//sum twice
	node_sum = (node_sum + (2 * ch_sum) % MOD) % MOD;
	
	//combinations across different children
	for(int i=0;i<ch_ans.size();i++) {
		node_comb = (node_comb + ch_ans[i].Y) % MOD;
		ch_sum = (ch_sum - ch_ans[i].X + MOD) % MOD;
		node_comb = (node_comb + (ch_sum * ch_ans[i].X * 2) % MOD) % MOD;
	}
	
	return MP(node_sum, node_comb);
}

void solve() {
	int n; in(n);
	int u, v;
	vector<int> adj[MAX];
	
	for(int i=0;i<n-1;i++) {
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	pl ans = dfs(1, -1, adj);
	cout<<(ans.X + ans.Y) % MOD<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
