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
#define INFL 1000000000000000
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

LL calc(int n, int m, LL c, vector<vector<LL> > &a) {
	int i, j; LL ans = INFL;
	vector<vector<LL> > dp(n + 1, vector<LL> (m + 1));

	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			LL temp = a[i][j]; //build a station
			if (i != 1) {
				temp = min(temp, dp[i - 1][j] + c);
				ans = min(ans, dp[i - 1][j] + c + a[i][j]);
			}
			if (j != 1) {
				temp = min(temp, dp[i][j - 1] + c);
				ans = min(ans, dp[i][j - 1] + c + a[i][j]);
			}
			dp[i][j] = temp;
		}
	}
	return ans;
}

void solve() {
	int n, m; LL c;
	in2(n, m);
	inl(c);

	int i, j;

	vector<vector<LL> > a(n + 1, vector<LL> (m + 1));
	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			inl(a[i][j]);
		}
	}

	LL ans = calc(n, m, c, a);
	//rotate
	rep(i, 1, n + 1) {
		rep(j, 1, ((m + 1) / 2) + 1) {
			swap(a[i][j], a[i][m - j + 1]);
		}
	}

	ans = min(ans, calc(n, m, c, a));

	cout << ans << en;
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