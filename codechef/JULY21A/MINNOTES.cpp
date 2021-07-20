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
#define getcx getchar_unlocked
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

inline void inp( int &n ) {
	n = 0;    int ch = getcx(); int sign = 1;
	while ( ch < '0' || ch > '9' ) {if (ch == '-')sign = -1; ch = getcx();}
	while (  ch >= '0' && ch <= '9' )
		n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	n = n * sign;
}

void solve() {
	int n, i, j; inp(n);
	vector<int> a(n);
	vector<int> lg(n), rg(n);
	rep(i, 0, n) {
		inp(a[i]);
		lg[i] = a[i];
		if (i > 0) lg[i] = __gcd(lg[i], lg[i - 1]);
	}

	rev(i, n - 1, 0) {
		rg[i] = a[i];
		if (i < n - 1) rg[i] = __gcd(rg[i], rg[i + 1]);
	}

	int maxi = -1, p = -1, v = -1;
	rep(i, 0, n) {
		int g;
		if (i == 0) g = rg[i + 1];
		else if (i == n - 1) g = lg[i - 1];
		else g = __gcd(rg[i + 1], lg[i - 1]);

		if (maxi < g) {
			maxi = g;
			p = i;
			v = a[i];
		} else if (maxi == g && a[i] > v) {
			v = a[i];
			p = i;
		}
	}

	LL ans = 0;
	rep(i, 0, n) {
		if (i == p) ans++;
		else ans += (a[i] / maxi);
	}

	printf("%lld\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;

	inp(t);
	while (t--) {
		solve();
	}
	return 0;
}