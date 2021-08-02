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

LL _gcd(LL a, LL b) {
	if (b == 0) return a;
	return _gcd(b, a % b);
}

LL seg[4 * MAX];
void construct(int node, int st, int end, vector<LL> &d) {
	if (st == end) {
		seg[node] = d[st];
		return;
	}

	int mid = (st + end) >> 1;
	construct(node << 1, st, mid, d);
	construct(1 + (node << 1), mid + 1, end, d);
	int l = node << 1;
	int r = l + 1;
	seg[node] = _gcd(seg[l], seg[r]);
}

LL query(int node, int st, int end, int qs, int qe) {
	if (st > end || qs > end || qe < st) {
		return 0;
	}

	if (st >= qs && qe >= end) {
		return seg[node];
	}

	int mid = (st + end) >> 1;
	LL l = query(node << 1, st, mid, qs, qe);
	LL r = query(1 + (node << 1), mid + 1, end, qs, qe);

	return _gcd(l, r);
}

void solve() {
	int n; in(n); int i, j;
	vector<LL> a(n);
	rep(i, 0, n) {
		inl(a[i]);
	}

	if (n <= 1) finish(n);

	vector<LL> d(n); d[0] = 0;
	rep(i, 1, n) {
		d[i] = abs(a[i] - a[i - 1]);
	}

	construct(1, 0, n, d);

	int st = 0, end = 0, ans = 0;
	while (end < n) {
		LL g = query(1, 0, n, st, end);
		if (g > 1) {
			ans = max(ans, end - st + 1);
			end++;
		} else {
			st++;
			if (st > end) end++;
		}
	}

	cout << ans + 1 << en;
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