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
	int n, k, i; in2(n, k);
	vector<int> acp(k + 1);
	rep(i, 1, k + 1) {
		in(acp[i]);
	}

	vector<int> l(n + 1), r(n + 1);
	vector<int> tmp(n + 1, -1);
	rep(i, 1, k + 1) {
		in(tmp[acp[i]]);
	}


	l[0] = INT_MAX; r[n] = INT_MAX;
	rep(i, 1, n + 1) {
		if (tmp[i] == -1) l[i] = INT_MAX;
		else l[i] = tmp[i];
		if (l[i - 1] != INT_MAX) l[i] = min(l[i], l[i - 1] + 1);

	}

	rev(i, n, 1) {
		if (tmp[i] == -1) r[i] = INT_MAX;
		else r[i] = tmp[i];
		if (i + 1 <= n && r[i + 1] != INT_MAX) r[i] = min(r[i], r[i + 1] + 1);
	}

	rep(i, 1, n + 1) {
		cout << min(l[i], r[i]) << " ";
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