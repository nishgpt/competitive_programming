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
#define MAX 1005
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
int parent1[MAX], parent2[MAX];
int find1(int u) {
	if (u == parent1[u])return u;
	return parent1[u] = find1(parent1[u]);
}

void _union1(int u, int v) {
	parent1[find1(u)] = find1(v);
}

int find2(int u) {
	if (u == parent2[u])return u;
	return parent2[u] = find2(parent2[u]);
}

void _union2(int u, int v) {
	parent2[find2(u)] = find2(v);
}

void solve() {
	int n, m1, m2; in(n); in2(m1, m2);

	int i, j, u, v;
	rep(i, 1, n + 1) {
		parent1[i] = i;
		parent2[i] = i;
	}
	rep(i, 0, m1) {
		in2(u, v);
		_union1(u, v);
	}

	rep(i, 0, m2) {
		in2(u, v);
		_union2(u, v);
	}

	vector<pi> ans;

	rep(i, 1, n + 1) {
		rep(j, i + 1, n + 1) {
			if (parent1[find1(i)] != parent1[find1(j)] && parent2[find2(i)] != parent2[find2(j)]) {
				_union1(i, j);
				_union2(i, j);

				ans.PB(MP(i, j));
			}
		}
	}

	cout << ans.size() << en;
	rep(i, 0, ans.size()) {
		cout << ans[i].X << " " << ans[i].Y << en;
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