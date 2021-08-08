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
#define MAX 260005
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

vector<pi> adj[MAX];

int gn(int i, int j, int n, int m) {
	return i * m + j;
}

bool ok(int i, int j, int n, int m) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

//for single jumps
int gw(char c, char d) {
	if (c == d) {
		return c == '#' ? 1 : 0;
	}

	if (c == '.' && d == '#') {
		return 1;
	}
	return 0;
}

/* Dijkstra Algo */
int dijkstra(int s, int d) {
	int mincost[MAX], i;
	rep(i, 0, MAX) mincost[i] = INT_MAX;

	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push(MP(0, s));
	mincost[s] = 0;

	while (!pq.empty()) {
		pi _top = pq.top();
		pq.pop();
		int node = _top.Y;

		for (i = 0; i < adj[node].size(); i++) {
			int ch = adj[node][i].X;
			int wt = adj[node][i].Y;
			if (mincost[node] + wt < mincost[ch]) {
				mincost[ch] = mincost[node] + wt;
				pq.push(MP(mincost[ch], ch));
			}
		}
	}

	return mincost[d];
}

void solve() {
	int n, m; in2(n, m);
	int i, j;
	string s[n];

	rep(i, 0, n) cin >> s[i];

	rep(i, 0, n) {
		rep(j, 0, m) {
			int curr = gn(i, j, n, m);

			if (ok(i, j + 1, n, m)) {
				int t = gn(i, j + 1, n, m);
				adj[curr].PB(MP(t, gw(s[i][j], s[i][j + 1])));
				adj[t].PB(MP(curr, gw(s[i][j + 1], s[i][j])));
			}

			if (ok(i + 1, j, n, m)) {
				int t = gn(i + 1, j, n, m);
				adj[curr].PB(MP(t, gw(s[i][j], s[i + 1][j])));
				adj[t].PB(MP(curr, gw(s[i + 1][j], s[i][j])));
			}

			if (ok(i, j + 2, n, m)) {
				int t = gn(i, j + 2, n, m);
				adj[curr].PB(MP(t, 1));
				adj[t].PB(MP(curr, 1));
			}
			if (ok(i + 1, j + 1, n, m)) {
				int t = gn(i + 1, j + 1, n, m);
				adj[curr].PB(MP(t, 1));
				adj[t].PB(MP(curr, 1));
			}

			if (ok(i + 1, j + 2, n, m)) {
				int t = gn(i + 1, j + 2, n, m);
				adj[curr].PB(MP(t, 1));
				adj[t].PB(MP(curr, 1));
			}

			if (ok(i + 2, j, n, m)) {
				int t = gn(i + 2, j, n, m);
				adj[curr].PB(MP(t, 1));
				adj[t].PB(MP(curr, 1));
			}


			if (ok(i + 1, j - 1, n, m)) {
				int t = gn(i + 1, j - 1, n, m);
				adj[curr].PB(MP(t, 1));
				adj[t].PB(MP(curr, 1));
			}


			if (ok(i + 1, j - 2, n, m)) {
				int t = gn(i + 1, j - 2, n, m);
				adj[curr].PB(MP(t, 1));
				adj[t].PB(MP(curr, 1));
			}
			if (ok(i + 2, j + 1, n, m)) {
				int t = gn(i + 2, j + 1, n, m);
				adj[curr].PB(MP(t, 1));
				adj[t].PB(MP(curr, 1));
			}
			if (ok(i + 2, j - 1, n, m)) {
				int t = gn(i + 2, j - 1, n, m);
				adj[curr].PB(MP(t, 1));
				adj[t].PB(MP(curr, 1));
			}
		}
	}

	int dest = n * m - 1;
	// rep(i, 0, dest + 1) {
	// 	cout << i << " -> ";
	// 	rep(j, 0, adj[i].size()) {
	// 		cout << adj[i][j].X << "," << adj[i][j].Y << " ";
	// 	}
	// 	cout << en;
	// }
	// chk(dest);

	cout << dijkstra(0, dest) << en;
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