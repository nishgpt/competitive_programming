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
#define INFL 1000000000000000000
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
typedef pair<LL, int> pli;
const char en = '\n';

/* Dijkstra Algo */
vector<pair<int, pl> > adj[MAX];
LL dijkstra(int s, int d) {
	LL mincost[MAX], i;
	rep(i, 0, MAX) mincost[i] = INFL;

	priority_queue<pli, vector<pli>, greater<pli> > pq;
	pq.push(MP(0, s));
	mincost[s] = 0;
	bool vis[MAX] = {false};

	while (!pq.empty()) {
		pi _top = pq.top();
		pq.pop();
		int node = _top.Y;

		if (vis[node]) continue;
		vis[node] = 1;

		for (i = 0; i < adj[node].size(); i++) {
			int ch = adj[node][i].X;
			LL c = adj[node][i].Y.X;
			LL d = adj[node][i].Y.Y;
			LL sq = sqrt(d);

			LL best_arrival = c + d / (mincost[node] + 1) + mincost[node];
			for (int j = -2; j <= 2; j++) {
				LL depart = sq + j;
				depart = max(depart, mincost[node]);
				if (depart < 0) raise(SIGABRT);
				best_arrival = min(depart + c + d / (depart + 1), best_arrival);
			}

			if (best_arrival < mincost[ch]) {
				mincost[ch] = best_arrival;
				pq.push(MP(mincost[ch], ch));
			}
		}
	}

	return mincost[d];
}

void solve() {
	int n, m; in2(n, m);

	while (m--) {
		LL c, d; int u, v;
		in2(u, v); inl2(c, d);

		adj[u].PB(MP(v, MP(c, d)));
		adj[v].PB(MP(u, MP(c, d)));
	}

	LL ans = dijkstra(1, n);
	cout << (ans == INFL ? -1 : ans) << en;
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