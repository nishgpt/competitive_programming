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

int mini = INT_MAX, n, m;
vector<int> adj[MAX];
bool vis[MAX];
int l[MAX];
int c[MAX];

void bfs() {
	queue<pi> q;
	q.push(MP(1, 0));
	l[1] = 0;
	vis[1] = true;

	while (!q.empty()) {
		int node = q.front().X;
		int level = q.front().Y;
		q.pop();

		for (int i = 0; i < adj[node].size(); i++) {
			if (!vis[adj[node][i]]) {
				q.push(MP(adj[node][i], level + 1));
				l[adj[node][i]] = level + 1;
				vis[adj[node][i]] = true;
			}
		}
	}
}

int dfs2(int node, int cnt) {
	if (node == n && cnt == mini) {
		return 1;
	}

	vis[node] = true;
	int ans = 0;
	for (int i = 0; i < adj[node].size(); i++) {
		if (!vis[adj[node][i]] && cnt + 1 == l[adj[node][i]]) {
			int temp = dfs2(adj[node][i], cnt + 1);
			ans = (ans + temp) % MOD;
		} else if (vis[adj[node][i]] && cnt + 1 == l[adj[node][i]]) {
			ans = (ans + c[adj[node][i]]) % MOD;
		}
	}

	return c[node] = ans;
}

void solve() {
	int u, v;

	in2(n, m);
	int i;
	rep(i, 0, m) {
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}

	bfs();
	mini = l[n];

	MSV(vis, false);
	int tot = dfs2(1, 0);
	cout << tot << en;
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