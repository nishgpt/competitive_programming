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
	int n, m;
	in2(n, m);

	vector<int> one(n, 0), two(n, 0), v;
	for (int i = 0; i < n; i++) {
		int x; in(x);
		v.PB(x);
	}

	int l1 = -1;
	for (int i = 0; i < n; i++) {
		one[i] = l1;
		if (v[i] == 1) {
			l1 = i;
		}
	}

	int l2 = -1;
	for (int i = n - 1; i >= 0; i--) {
		two[i] = l2;
		if (v[i] == 2) {
			l2 = i;
		}
	}

	while (m--) {
		int p; in(p); p--;
		int ans = INT_MAX;

		if (p == 0) ans = 0;
		else if (v[p] != 0) ans = 0;
		else {
			if (one[p] == -1 && two[p] == -1) ans = -1;
			else if (one[p] == -1) ans = two[p] - p;
			else if (two[p] == -1) ans = p - one[p];
			else ans = min(p - one[p], two[p] - p);
		}

		if (ans == INT_MAX) raise(SIGABRT);

		cout << ans << " ";
	}

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