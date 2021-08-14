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

/* Union Find / DSU */
//have a parent array global
int parent[MAX];
LL sz[MAX];
int find(int u) {
	if (u == parent[u])return u;
	return parent[u] = find(parent[u]);
}

void _union(int u, int v) {
	parent[find(u)] = find(v);
}

void solve() {
	LL n; inl(n);
	LL i, u, v, w;
	rep(i, 1, n + 1) {
		parent[i] = i;
		sz[i] = 1;
	}

	vector<pair<LL, pl> > edge;
	rep(i, 0, n - 1) {
		inl2(u, v); inl(w);
		edge.PB(MP(w, MP(u, v)));
	}

	sort(edge.begin(), edge.end());

	LL ans = 0;
	rep(i, 0, edge.size()) {
		u = edge[i].Y.X;
		v = edge[i].Y.Y;
		w = edge[i].X;

		LL szu = sz[find(u)];
		LL szv = sz[find(v)];
		ans = ans + (szu * szv * w);
		_union(u, v);
		sz[find(u)] = szu + szv;
	}

	finish(ans);
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