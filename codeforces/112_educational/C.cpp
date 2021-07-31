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

// int calc(vector<int> a[2], int m) {
// 	vector<int> sum[2]; int i, j;
// 	rep(i, 0, 2) sum[i].resize(m);

// 	rep(j, 0, m) {
// 		sum[0][j] = a[0][j];
// 		if (j > 0) sum[0][j] += sum[0][j - 1];
// 	}

// 	rev(j, m - 1, 0) {
// 		sum[1][j] = a[1][j];
// 		if (j < m - 1) sum[1][j] += sum[1][j + 1];
// 	}

// 	int maxi = -1, idx = -1;
// 	rep(j, 0, m) {
// 		if (sum[0][j] + sum[1][j] > maxi) {
// 			maxi = sum[0][j] + sum[1][j];
// 			idx = j;
// 		}
// 	}

// 	return idx;
// }

void solve() {
	int m; in(m); int i, j;
	vector<int> v[2];
	v[0].resize(m); v[1].resize(m);

	LL s1 = 0, s2 = 0;
	rep(i, 0, 2) {
		rep(j, 0, m) {
			in(v[i][j]);
			if (i == 0) s1 += v[i][j];
			else s2 += v[i][j];
		}
	}

	vector<int> sum[2];
	rep(i, 0, 2) sum[i].resize(m);

	rep(j, 0, m) {
		sum[0][j] = v[0][j];
		if (j > 0) sum[0][j] += sum[0][j - 1];
	}

	rev(j, m - 1, 0) {
		sum[1][j] = v[1][j];
		if (j < m - 1) sum[1][j] += sum[1][j + 1];
	}

	LL ans = 1000000000000;
	rep(j, 0, m) {
		LL temp = max(s1 - sum[0][j], s2 - sum[1][j]);
		ans = min(ans, temp);
	}
	finish(ans);
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