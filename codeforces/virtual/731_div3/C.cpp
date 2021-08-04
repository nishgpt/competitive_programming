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
	int n, m, k; in(k); in2(n, m);
	int i, j;
	vector<int> a(n), b(m);

	rep(i, 0, n) in(a[i]);
	rep(i, 0, m) {
		in(b[i]);
	}
	int l = 0, r = 0;

	vector<int> ans;
	while (true) {
		if (l < n && a[l] == 0) {
			ans.PB(0);
			l++;
			k++;
		}
		else if (r < m && b[r] == 0) {
			r++;
			k++;
			ans.PB(0);
		}
		else if (l < n && a[l] > 0 && a[l] <= k) {
			ans.PB(a[l]);
			l++;
		}
		else if (r < m && b[r] > 0 && b[r] <= k) {
			ans.PB(b[r]);
			r++;
		}
		else break;
	}
	// cout << ans.size() << en;

	if (ans.size() != n + m) finish(-1);
	rep(i, 0, ans.size()) cout << ans[i] << " ";
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