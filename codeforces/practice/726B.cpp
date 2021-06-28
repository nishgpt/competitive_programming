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

LL tour_len(pl a, pl b, LL i, LL j) {
	return abs(a.X - i) + abs(a.Y - j) + abs(a.X - b.X) + abs(a.Y - b.Y) + abs(b.X - i) + abs(b.Y - j);
}

void solve() {
	int n, m, i, j;
	in2(n, m); in2(i, j);
	vector<pi> v;
	v.PB(MP(1, 1));
	v.PB(MP(1, m));
	v.PB(MP(n, m));
	v.PB(MP(n, 1));

	LL maxi = -1; int i1, i2;
	for (int x = 0; x < v.size(); x++) {
		for (int y = x + 1; y < v.size(); y++) {
			LL d = tour_len(v[x], v[y], i, j);
			if (maxi < d) {
				maxi = d;
				i1 = x; i2 = y;
			}

			d = tour_len(v[y], v[x], i, j);
			if (maxi < d) {
				maxi = d;
				i1 = x; i2 = y;
			}
		}
	}

	cout << v[i1].X << " " << v[i1].Y << " " << v[i2].X << " " << v[i2].Y << en;
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