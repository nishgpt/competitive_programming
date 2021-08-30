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
#define MAX 1003
#define LOG_MAX 20
#define MOD 998244353
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

LL dp[MAX][1025][11];

LL call(int pos, int mask, int last, int n, string &s) {
	if (pos > n) {
		int cnt = (mask == 0) ? 0 : 1;
		return cnt;
	}

	if (dp[pos][mask][last] != -1) return dp[pos][mask][last];

	//ignore this char
	LL ans = call(pos + 1, mask, last, n, s);

	int curr = s[pos] - 'A';
	bool seen = (((1 << curr) & mask) != 0);

	//add this char as append
	//1. when this is not seen before
	if (!seen) {
		ans = (ans + call(pos + 1, (mask | (1 << curr)), curr, n, s)) % MOD;
	}

	//2. when this is the last char
	if (seen && (last == curr)) {
		ans = (ans + call(pos + 1, mask, curr, n, s)) % MOD;
	}

	return dp[pos][mask][last] = ans;
}

void solve() {
	int n; in(n);
	string s; cin >> s;
	s = "." + s;

	MSV(dp, -1);
	finish(call(1, 0, 10, n, s));
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