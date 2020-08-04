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
#define MAX 26
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

stack<int> st;
void topoSort(int node, vector<int> adj[MAX], vector<bool> &vis) {
	vis[node] = true;
	
	for(int i=0;i<adj[node].size();i++) {
		if(!vis[adj[node][i]]) topoSort(adj[node][i], adj, vis);
	}
	st.push(node);
}

bool cycle;
void dfs(int node, vector<int> *adj, vector<bool> &vis) {
	vis[node] = true;
	
	for(int i=0;i<adj[node].size();i++) {
		if(vis[adj[node][i]]) {
			cycle = true;
			return;
		}
		dfs(adj[node][i], adj, vis);
		if(cycle) return;
	}
	
	vis[node] = false;
}

void solve() {
	cycle = false;
	int n, m;in2(n, m);
	string s[n];
	bool present[MAX] = {false};
	for(int i=0;i<n;i++) {
		cin>>s[i];
		for(int j=0;j<m;j++) present[s[i][j]-'A'] = true;
	}
	
	bool taken[MAX][MAX] = {false};
	vector<bool> vis(MAX, false);
	vector<int> adj[MAX];
	
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<m;j++) {
			int u = s[i][j] - 'A';
			int v = s[i+1][j] - 'A';
			if(s[i][j] != s[i+1][j]) {
				adj[v].PB(u);
				taken[v][u] = true;
			}
		}
	}
	
	for(int i=0;i<MAX;i++) {
		if(present[i]) dfs(i, adj, vis);
		if(cycle) finish(-1);
	}
	
	vis.resize(MAX, false);
	for(int i=0;i<MAX;i++) {
		if(present[i] && !vis[i]) topoSort(i, adj, vis);
	}
	
	while(!st.empty()) {
		cout<<(char) (st.top() + 'A');
		st.pop();
	}
	cout<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	for(int i=1;i<=t;i++) {
		cout<<"Case #"<<i<<": ";
		solve();
	}
    return 0;
}
