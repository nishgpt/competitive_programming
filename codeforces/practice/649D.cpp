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
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define finish(x) {cout<<x<<'\n'; return;}
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

int num[MAX];
vector<int> adj[MAX];
vector<int> ans;
bool blocked[MAX];

void print_cycle(int s, int d) {
	cout<<2<<en;
	cout<<d-s+1<<en;
	for(int i=s;i<=d;i++) cout<<ans[i]<<" ";
	cout<<en;
}

void dfs(int node, int cnt, int parent, int k) {
	num[node] = cnt;
	ans.PB(node);
	
	for(int i=0;i<adj[node].size();i++) {
		if(num[adj[node][i]] != -1) {
			int len = num[node] - num[adj[node][i]] + 1;
			if(adj[node][i] != parent && len <= k && len > 2) {
				print_cycle(num[adj[node][i]], num[node]);
				exit(0);
			}
		} else dfs(adj[node][i], cnt+1, node, k);
	}
	ans.pop_back();
	if(!blocked[node]) {
		for(int i=0;i<adj[node].size();i++) blocked[adj[node][i]] = true;
	}
}

void solve() {
	int n, m, k;
	in3(n, m, k);
		
	for(int i=0;i<m;i++) {
		int u, v;
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	//try to solve for #2
	MSV(num, -1);
	dfs(1, 0, -1, k);
	
	//solve for #1
	int needed = (k+1)>>1;
	cout<<1<<en;
	for(int i=1;i<=n && needed > 0; i++) {
		if(!blocked[i]) {cout<<i<<" ";needed--;}
	}
	cout<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
