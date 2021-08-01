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
#define MAX 5001
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

int adj[MAX][MAX], cnt[MAX][MAX];
bool vis[MAX];
void dfs(int node, int c, int n) {
	chk(node);
	int i, j;

	vis[node] = true;
	rep(i, 1, n + 1) {
		if (i != 1 && adj[node][i] && !vis[i]) {
			dfs(i, c + 1, n);
		}
	}

	rep(i, 1, n + 1) {
		if (i == 1 && node != 1 && adj[node][i]) {
			cnt[node][1]++;
		}
		if (i != 1) {
			rep(j, 1, n + 1) {
				if (adj[node][i]) cnt[node][j + 1] += cnt[i][j];
			}
		}
	}
}

void solve() {
	MSV(adj, 1);
	int n, m, k; in2(n, m); in(k);
	int i, j;

	rep(i, 1, n + 1) {
		adj[i][i] = 0;
	}

	rep(i, 0, m) {
		int u, v; in2(u, v);
		adj[u][v] = 0;
		adj[v][u] = 0;
	}

	dfs(1, 0, n);

	rep(i, 1, n + 1) {
		cout << cnt[1][i] << " ";
	}
	cout << en;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;

	// cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}