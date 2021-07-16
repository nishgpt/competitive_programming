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

/* LCA with binary lifting */
int level[MAX];
int parent[MAX];
int p[MAX][LOG_MAX];
vector<int> adj[MAX];

void precompute_lca(int n) {
	int i, j;

	for (i = 1; i <= n; i++)
		for (j = 0; (1 << j) <= n; j++)
			p[i][j] = -1;

	for (i = 1; i <= n; i++)
		p[i][0] = parent[i];

	for (j = 1; (1 << j) <= n; j++) {
		for (i = 1; i <= n; i++)
			if (p[i][j - 1] != -1)
				p[i][j] = p[p[i][j - 1]][j - 1];
	}
}

int get_lca(int u, int v) {
	int tmp, _log, i;
	if (level[u] < level[v]) {
		tmp = u, u = v, v = tmp;
	}

	for (_log = 1; 1 << _log <= level[u]; _log++);
	_log--;

	for (i = _log; i >= 0; i--) {
		if (level[u] - (1 << i) >= level[v]) u = p[u][i];
	}

	if (u == v) return u;

	for (i = _log; i >= 0; i--)
		if (p[u][i] != -1 && p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i];

	return parent[u];
}

//compute level[]
void bfs(int n) {
	queue<pi> q;
	bitset<MAX> vis;

	level[1] = 0;
	q.push(MP(1, 0));
	vis[1]	= true;

	while (!q.empty()) {
		int node = q.front().X;
		int l = q.front().Y;
		q.pop();

		for (int i = 0; i < adj[node].size(); i++) {
			if (!vis[adj[node][i]]) {
				q.push(MP(adj[node][i], l + 1));
				level[adj[node][i]] = l + 1;
				vis[adj[node][i]] = true;
			}
		}
	}
}

void solve() {
	int n, q; in2(n, q);
	int i, j;

	rep(i, 0, n - 1) {
		int u, v;
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}

	bfs(n);
	precompute_lca(n);

	while (q--) {
		int u, v;
		in2(u, v);
		int lca = get_lca(u, v);
		int roads = level[u] - level[lca] + level[v] - level[lca];
		if (roads & 1) {
			cout << "Road" << en;
		}
		else cout << "Town" << en;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;

	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}