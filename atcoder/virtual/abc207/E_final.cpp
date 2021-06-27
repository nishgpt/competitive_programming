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
#define MAX 3005
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

LL dp[MAX][MAX];
LL mem[MAX][MAX];

void solve() {
	int n, i, j, k; in(n);

	LL v[n + 1], sum[n + 1];

	v[0] = 0; sum[0] = 0;
	rep(i, 1, n + 1) {
		inl(v[i]);
		sum[i] = sum[i - 1] + v[i];
	}

	dp[1][1] = 1;
	mem[0][1] = 1;

	LL ans = 0;
	rep(i, 1, n + 1) {
		rep(j, 1, n + 1) {
			dp[i][j] = mem[sum[i] % j][j];
		}
		rep(j, 1, n + 1) {
			int r = sum[i] % (j + 1);
			mem[r][j + 1] = (mem[r][j + 1] + dp[i][j]) % MOD;
		}
	}

	rep(i, 1, n + 1) {
		ans = (ans + dp[n][i]) % MOD;
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