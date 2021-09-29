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

void solve() {
	int n; in(n);
	int i, j;
	vector<int> a(n);
	rep(i, 0, n) {
		in(a[i]);
	}

	vector<pair<pi, int> > ans;
	rep(i, 0, n) {
		vector<pi> b;
		rep(j, i, n) {
			b.PB(MP(a[j], j));
		}
		// cout << "i = " << i << en;
		// rep(j, 0, b.size()) {
		// 	cout << b[j].X << " " << b[j].Y << en;
		// }

		sort(b.begin(), b.end());

		int idx = i;
		int edx = b[0].Y;
		int mini = b[0].X;
		// chk2(b[0].X, b[0].Y);
		// chk2(idx, edx);
		if (edx - idx > 0) {
			ans.PB(MP(MP(idx + 1, edx + 1), edx - idx));
			rev(j, edx, idx + 1) {
				a[j] = a[j - 1];
			}
			a[idx] = mini;
		}
	}

	cout << ans.size() << en;
	rep(i, 0, ans.size()) {
		cout << ans[i].X.X << " " << ans[i].X.Y << " " << ans[i].Y << en;
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