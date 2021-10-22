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

int mini, maxi;
vector<int> adj[MAX];
void dfs(int node, vector<bool> &vis, vector<int> &val) {
	int cnt = 0, i;
	vis[node] = true;
	rep(i, 0, adj[node].size()) {
		if (val[adj[node][i]] < val[node]) cnt++;
		if (!vis[adj[node][i]]) dfs(adj[node][i], vis, val);
	}
	mini = min(mini, cnt);
	maxi = max(maxi, cnt);
}

void solve() {
	int n, m, i, u, v;
	in2(n, m);
	vector<pi> deg(n);
	vector<int> val(n + 1);

	rep(i, 1, n + 1) adj[i].clear();

	while (m--) {
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}

	rep(i, 1, n + 1) {
		deg[i - 1] = MP(adj[i].size(), i);
	}
	sort(deg.rbegin(), deg.rend());

	int num = 1;
	rep(i, 0, deg.size()) {
		val[deg[i].Y] = num++;
	}

	vector<bool> vis(n + 1, false);
	mini = INT_MAX, maxi = -1;
	rep(i, 1, n + 1) {
		if (!vis[i]) {
			dfs(i, vis, val);
		}
	}

	cout << maxi - mini << en;
	rep(i, 1, n + 1) {
		cout << val[i] << " ";
	}
	cout << en;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}