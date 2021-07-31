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

void solve() {
	int n, m; in2(n, m);
	string s;
	cin >> s;

	vector<int> v(3);
	v[0] = 0; v[1] = 1; v[2] = 2;

	int a[6][n]; MSV(a, 0);
	int idx = 0;
	do {
		for (int i = 0; i < n; i++) {
			if (s[i] - 'a' != v[i % 3]) a[idx][i] = 1;
		}
		for (int i = 1; i < n; i++) {
			a[idx][i] += a[idx][i - 1];
		}
		idx++;
	} while (next_permutation(v.begin(), v.end()));

	while (m--) {
		int l, r; in2(l, r);
		l--; r--;

		int mini = INT_MAX;
		for (int i = 0; i < 6; i++) {
			int x = a[i][r];
			if (l > 0) x -= a[i][l - 1];

			mini = min(mini, x);
		}
		printf("%d\n", mini);
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