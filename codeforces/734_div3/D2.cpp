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
#define MAX 102
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

char ans[MAX][MAX];
string s = "qwertyuiopasdfghjklzxcvbnm";

int left_(int n, int m, int k) { //when rows are odd, how many horizonatal will be left for special case
	m = m / 2;
	int q = k / m;
	if (q % 2 == 0 && q > 0) q--; //fill odd number of rows
	return k - q * m;
}

bool possible(int n, int m, int k) {
	if (n == 1 && m == 1) return true;
	if (n & 1) {
		int q = k / (m / 2);
		if (q == 0) return false;
		if (left_(n, m, k) % 2 == 0) return true;
		return false;
	}

	//when rows are even
	if (m & 1) m--;
	int maxi = (m * n) / 2;
	if (k % 2 == 0 && k <= maxi) return true;
	return false;
}

void fill_vertical(int n, int m) {
	int i, j, p;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (ans[i][j] == '.') {
				int idx = -1;
				rep(p, 0, s.length()) {
					idx = p;
					if ((j > 0 && ans[i][j - 1] == s[idx]) || (i > 0 && ans[i - 1][j] == s[idx]) || (i + 1 < n && j > 0 && ans[i + 1][j - 1] == s[idx])) continue;
					break;
				}
				ans[i][j] = s[idx];
				ans[i + 1][j] = s[idx];
			}
		}
	}
}

void solve() {
	int n, m, k, i, j, p;
	in2(n, m); in(k);
	sort(s.begin(), s.end());

	bool ok = possible(n, m, k);
	if (!ok) finish("NO");
	cout << "YES" << en;


	rep(i, 0, n) rep(j, 0, m) ans[i][j] = '.';

	if (n % 2 == 0) { //rows even
		int r = 0, c = 0;
		while (k--) {
			if (r >= n) {
				r = 0;
				c += 2;
			}

			int idx = -1;
			rep(i, 0, s.length()) {
				idx = i;
				if ((c > 0 && ans[r][c - 1] == s[idx]) || (r > 0 && ans[r - 1][c] == s[idx])) continue;
				break;
			}
			ans[r][c] = s[idx];
			ans[r][c + 1] = s[idx];
			r++;
		}

		fill_vertical(n, m);
	}

	else { //rows odd
		int left = left_(n, m, k);
		int fill = k - left;

		int r = 0, c = 0;
		while (fill--) {
			if (c >= m) {
				r++;
				c = 0;
			}
			int idx = -1;
			rep(i, 0, s.length()) {
				idx = i;
				if ((c > 0 && ans[r][c - 1] == s[idx]) || (r > 0 && ans[r - 1][c] == s[idx])) continue;
				break;
			}
			ans[r][c] = s[idx];
			ans[r][c + 1] = s[idx];
			c += 2;
		}

		r++; c = 0;
		int fr = r;
		while (left--) {
			if (r >= n) {
				r = fr;
				c += 2;
			}

			int idx = -1;
			rep(i, 0, s.length()) {
				idx = i;
				if ((c > 0 && ans[r][c - 1] == s[idx]) || (r > 0 && ans[r - 1][c] == s[idx])) continue;
				break;
			}
			ans[r][c] = s[idx];
			ans[r][c + 1] = s[idx];
			r++;
		}

		fill_vertical(n, m);
	}

	rep(i, 0, n) {
		rep(j, 0, m) {
			cout << ans[i][j];
		}
		cout << en;
	}

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