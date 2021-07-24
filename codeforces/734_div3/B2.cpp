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
#define MAX 200005
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

void solve() {
	int n, k; in2(n, k);
	vector<int> v(n);

	int i, j;

	vector<int> f[n + 1];
	rep(i, 0, n) {
		in(v[i]);
		f[v[i]].PB(i);
	}

	vector<int> divi;
	int maxi = (n / k) * k;
	while (maxi > 0) {
		divi.PB(maxi);
		maxi -= k;
	}
	sort(divi.begin(), divi.end());

	int low = 0, high = divi.size() - 1;
	int ans = divi[low];
	rep(i, low, high)

	while (low <= high) {
		int mid = (low + high) >> 1;
		int d = divi[mid];
		int cnt = 0, col = 1;
		rep(i, 1, n + 1) {
			int sz = f[i].size();
			rep(j, 0, min(sz, k)) {
				if (cnt == d) break;
				else {
					col++;
					if (col > k) col = 1;
					cnt++;
				}
			}
			if (cnt == d) break;
		}

		if (cnt >= d) {
			ans = d;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	// chk(ans);

	int c[n + 1]; MSV(c, 0);
	int cnt = 0, col = 1;
	rep(i, 1, n + 1) {
		int sz = f[i].size();
		rep(j, 0, min(sz, k)) {
			if (cnt == ans) break;
			else {
				c[f[i][j]] = col;
				col++;
				if (col > k) col = 1;
				cnt++;
			}
		}
		if (cnt == ans) break;
	}

	rep(i, 0, n) cout << c[i] << " ";
	cout << en;
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