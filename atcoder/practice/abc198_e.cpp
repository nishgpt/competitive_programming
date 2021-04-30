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

vector<int> ans;
int col[MAX];
vector<int> c(MAX);
vector<int> adj[MAX];

void dfs(int node, int p) {
	if(col[c[node]] == 0) {
		ans.PB(node);
	}
	
	col[c[node]]++;
	for(int i=0;i<adj[node].size();i++) {
		if(adj[node][i] != p) dfs(adj[node][i], node);
	}
	col[c[node]]--;
}

void solve() {
	int n; in(n);
	int u, v;
	
	for(int i=1;i<=n;i++) {
		in(c[i]);
	}
	
	for(int i=0;i<n-1;i++) {
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	dfs(1, -1);	
	sort(ans.begin(), ans.end());
	
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<en;
	}
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
