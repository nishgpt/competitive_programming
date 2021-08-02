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

LL _gcd(LL a, LL b) {
	if (b == 0) return a;
	return _gcd(b, a % b);
}

void solve() {
	int n; in(n); int i, j;
	vector<LL> a(n);
	rep(i, 0, n) {inl(a[i]);}
	if (n <= 2) finish(n);

	vector<LL> d(n);
	rep(i, 1, n) {
		d[i] = abs(a[i] - a[i - 1]);
	}

	vector<LL> g(n);
	rep(i, 2, n) {
		g[i] = _gcd(d[i], d[i - 1]);
	}

	LL ans = 0;
	LL maxi = ans;
	g[1] = 1;
	rep(i, 2, n) {
		if (g[i] > 1 && (g[i - 1] % g[i] == 0 || g[i] % g[i - 1] == 0)) {
			ans++;
		}
		else {
			maxi = max(ans, maxi);
			ans = 0;
		}
	}
	maxi = max(maxi, ans);
	cout << maxi + 2 << en;
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