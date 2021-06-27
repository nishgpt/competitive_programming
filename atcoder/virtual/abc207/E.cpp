/*
	Author : Nishant Gupta 2.0
*/
//Passed Partially - Need to verify with more test cases : WIP
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

vector<LL> v;
LL dp[MAX][MAX];

LL callrev(int pos, int k, int op, int n, LL sum) {
	if (pos == 0 && k == 0) return 1;
	if (pos == 0 || k <= 0) return 0;
	if (dp[pos][k] != -1) return dp[pos][k];

	LL ans = callrev(pos - 1, k, 1, n, (sum + v[pos]) % k) % MOD;
	if ((sum + v[pos]) % k == 0) ans = (ans + callrev(pos - 1, k - 1, 0, n, 0)) % MOD;

	if (op == 0) dp[pos][k] = ans;
	return ans;
}

void solve() {
	MSV(dp, -1);
	int n; in(n);
	int i;
	v.PB(-1);
	rep(i, 0, n) {
		LL x; inl(x);
		v.PB(x);
	}

	LL ans = 0;
	rep(i, 1, n + 1) {
		ans = (ans + callrev(n, i, 0, n, 0)) % MOD;
	}

	cout << ans << en;
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