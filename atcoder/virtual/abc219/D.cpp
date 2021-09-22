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
#define MAX 301
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


int dp[MAX][MAX][MAX];
void solve() {
	int x, y, n;
	int i, j, idx;

	in(n);
	in2(x, y);
	vector<pi> v(n + 1);
	rep(i, 1, n + 1) {
		in2(v[i].X, v[i].Y);
	}

	int mini[MAX][MAX];
	rep(i, 0, x + 1) {
		rep(j, 0, y + 1) {
			dp[0][i][j] = INT_MAX;
			mini[i][j] = INT_MAX;
		}
	}

	rep(idx, 1, n + 1) {
		rep(i, 0, x + 1) {
			rep(j, 0, y + 1) {
				dp[idx][i][j] = dp[idx - 1][i][j];
				if (i - v[idx].X <= 0 && j - v[idx].Y <= 0) {
					dp[idx][i][j] = min(dp[idx][i][j], 1);
				}
				else if (i - v[idx].X >= 0 && j - v[idx].Y <= 0) {
					if (mini[i - v[idx].X][0] == INT_MAX) continue;
					dp[idx][i][j] = min(dp[idx][i][j], 1 + mini[i - v[idx].X][0]);
				}
				else if (i - v[idx].X <= 0 && j - v[idx].Y >= 0) {
					if (mini[0][j - v[idx].Y] == INT_MAX) continue;
					dp[idx][i][j] = min(dp[idx][i][j], 1 + mini[0][j - v[idx].Y]);
				} else {
					if (mini[i - v[idx].X][j - v[idx].Y] == INT_MAX) continue;
					dp[idx][i][j] = min(dp[idx][i][j], 1 + mini[i - v[idx].X][j - v[idx].Y]);
				}
			}
		}

		for (i = x; i >= 0; i--) {
			for (j = y; j >= 0; j--) {
				mini[i][j] = dp[idx][i][j];
				if (i + 1 <= x) {
					mini[i][j] = min(mini[i][j], mini[i + 1][j]);
				}
				if (j + 1 <= y) {
					mini[i][j] = min(mini[i][j], mini[i][j + 1]);
				}
			}
		}
	}
	if (dp[n][x][y] == INT_MAX) dp[n][x][y] = -1;
	cout << dp[n][x][y] << en;
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