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

vector<int> adj[MAX];
vector<int> taken;
int parent[MAX];
bool choosen[MAX];

int find(int u) {
	if(u == parent[u])return u;
	return parent[u] = find(parent[u]);
}

void _union(int u, int v) {
	parent[find(u)] = find(v);
}

void solve() {
	int n, m;
	in2(n, m);
	
	int a[n+1], b[n+1];
	for(int i=1;i<=n;i++) {
		in(a[i]);
		adj[i].clear();
		parent[i] = i;
	}
	
	for(int i=1;i<=n;i++) in(b[i]);
	
	int u, v;
	for(int i=0;i<m;i++) {
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	taken.clear();
	MSV(choosen, false);
	double maxi = -1.0;
	for(int i=1;i<=n;i++) {
		double income = a[i] * 1.0 / b[i];
		maxi = max(maxi, income);
	}
	
	for(int i=1;i<=n;i++) {
		if(maxi == (a[i] * 1.0 / b[i])) {
			taken.PB(i);
			choosen[i] = true;
		}
	}
	
	for(int i=0;i<taken.size();i++) {
		int node = taken[i];
		for(int j=0;j<adj[node].size();j++) {
			if(choosen[adj[node][j]]) {
				_union(node, adj[node][j]);
			}
		}
	}
	
	int freq[MAX] = {0};
	for(int i=0;i<taken.size();i++) freq[find(taken[i])]++;
	
	int max_freq = -1, root = -1;
	for(int i=1;i<=n;i++) {
		if(max_freq < freq[i]) {
			root = i;
			max_freq = freq[i];
		}
	}
	
	vector<int> ans;
	for(int i=0;i<taken.size();i++) if(parent[taken[i]] == root) ans.PB(taken[i]);
	
	cout<<ans.size()<<en;
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
