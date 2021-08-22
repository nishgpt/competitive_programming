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

	//add this char as the only new
	int curr = s[pos] - 'A';
	//ans = (ans + call(pos + 1, (1 << curr), curr, n, s)) % MOD;

	//add this char as append
	bool seen = (((1 << curr) & mask) != 0);

	if (!seen) { //when this is not seen before
		ans = (ans + call(pos + 1, (mask | (1 << curr)), curr, n, s)) % MOD;
	}

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
	// int i, c1, c2;
	// rep(i, 1, n + 1) {
	// 	//copy previous data
	// 	int idx = s[i] - 'A';
	// 	rep(c1, 0, 10) {
	// 		rep(c2, 0, 10) {
	// 			if (c1 == c2) continue;

	// 			dp[i][c1][c2][0] = (dp[i][c1][c2][0] + dp[i - 1][c1][c2][0]) % MOD;
	// 			dp[i][c1][c2][1] = (dp[i][c1][c2][1] + dp[i - 1][c1][c2][1]) % MOD;
	// 		}
	// 	}

	// 	rep(c2, 0, 10) {
	// 		if (c2 != idx) {
	// 			dp[i][idx][c2][0] = (dp[i][idx][c2][0] + 1) % MOD;
	// 			rep(c1, 0, 10) {
	// 				if (c1 != idx) {
	// 					dp[i][idx][c2][1] = (dp[i][idx][c2][1] + dp[i - 1][c2][c1][1] + dp[i - 1][c2][c1][0]) % MOD;
	// 				}
	// 				else
	// 				}

	// 		}
	// 		else {
	// 			dp[i][idx][c2][1] = (dp[i][idx][c2][1] + 1) % MOD;
	// 		}
	// 	}
	// }

	LL ans = call(1, 0, 10, n, s);

	finish(ans);
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