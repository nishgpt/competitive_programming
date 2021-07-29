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
#define MAX 1001
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

int dp[MAX][MAX], prev_max[MAX][MAX], freq[MAX][MAX];
void solve() {
	int n, k; in2(n, k);
	int i, j;

	vector<int> a(n + 1), last(n + 1);
	int pos[MAX] = {0};
	MSV(freq, 0); MSV(dp, 0); MSV(prev_max, 0);

	rep(i, 1, n + 1) {
		in(a[i]);
		rep(j, 1, MAX) {
			if (j == a[i]) freq[i][j] = 1;
			freq[i][j] += freq[i - 1][j];
		}
	}

	rep(i, 1, n + 1) {
		last[i] = pos[a[i]];
		pos[a[i]] = i;

		int maxi = 0;
		rep(j, 1, MAX) {
			maxi = max(maxi, freq[i][j]);
		}
		rep(j, 0, k + 1) {
			prev_max[i][j] = maxi;
		}
	}

	int ans = INT_MIN;
	rep(i, 1, n + 1) {
		rep(j, 1, k + 1) {
			dp[i][j] = 1 + max(prev_max[i - 1][j - 1], dp[last[i]][j]);
			prev_max[i][j] = max(prev_max[i][j], max(prev_max[i - 1][j], dp[i][j]));
			ans = max(ans, dp[i][j]);
		}
	}

	finish(ans);
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