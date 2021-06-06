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
const int N = 802;

int b[N][N], sum[N][N], p[N][N], psum[N][N];
void solve() {
	int i, j, n, k;
	in2(n, k);

	int a[n][n];
	vector<int> v;
	rep(i, 0, n) {
		rep(j, 0, n) {
			in(a[i][j]);
			v.PB(a[i][j]);
		}
	}

	sort(v.begin(), v.end());

	int low = 0, high = v.size();
	int ans = -1, threshold = k * k - ((k * k) / 2) - 1;

	while (low <= high) {
		int idx = (low + high) >> 1;
		int mid = v[idx];

		MSV(sum, 0); MSV(psum, 0);
		rep(i, 0, n) {
			rep(j, 0, n) {
				if (a[i][j] < mid) b[i][j] = 1;
				else b[i][j] = 0;

				if (a[i][j] == mid) p[i][j] = 1;
				else p[i][j] = 0;
			}
		}

		rep(i, 0, n) {
			rep(j, 0, n) {
				if (i == 0 && j == 0) {
					sum[i][j] = b[i][j];
					psum[i][j] = p[i][j];
				}
				else if (j == 0) {
					sum[i][j] = sum[i - 1][j] + b[i][j];
					psum[i][j] = psum[i - 1][j] + p[i][j];
				}
				else if (i == 0) {
					sum[i][j] = sum[i][j - 1] + b[i][j];
					psum[i][j] = psum[i][j - 1] + p[i][j];
				}
				else {
					sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + b[i][j];
					psum[i][j] = psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1] + p[i][j];
				}
			}
		}

		bool found = false;
		rep(i, k - 1, n) {
			rep(j, k - 1, n) {
				int x1 = (i - k >= 0) ? sum[i - k][j] : 0;
				int x2 = (j - k >= 0) ? sum[i][j - k] : 0;
				int x3 = (i - k >= 0 && j - k >= 0) ? sum[i - k][j - k] : 0;
				int total = sum[i][j] - x1 - x2 + x3;


				x1 = (i - k >= 0) ? psum[i - k][j] : 0;
				x2 = (j - k >= 0) ? psum[i][j - k] : 0;
				x3 = (i - k >= 0 && j - k >= 0) ? psum[i - k][j - k] : 0;
				int count_mid = psum[i][j] - x1 - x2 + x3;

				if (total > threshold) {
					found = true;
					continue;
				}

				if (total + count_mid > threshold) {
					found = true;
					ans = mid;
				}
			}
		}

		if (found) {
			high = idx - 1;
		} else low = idx + 1;
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