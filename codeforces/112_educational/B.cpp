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

pi shift(pi l1, pi r1, pi l2, pi r2) {
	int xd = min(r1.X, r2.X) - max(l1.X, l2.X);
	int yd = min(r1.Y, r2.Y) - max(l1.Y, l2.Y);
	if (xd < 0 || yd < 0) return MP(0, 0);

	return MP(xd, yd);
}

void solve() {
	int n, m; in2(n, m);
	int x1, y1, x2, y2;
	in2(x1, y1); in2(x2, y2);

	int w, h;
	in2(w, h);
	if (w + (x2 - x1) > n && h + (y2 - y1) > m) finish(-1);

	double mini = 1.0 * INT_MAX;

	//bottom left
	pi bl = shift(MP(0, 0), MP(w, h), MP(x1, y1), MP(x2, y2));
	if (x2 + bl.X <= n) mini = min(mini, 1.0 * bl.X);
	if (y2 + bl.Y <= m) mini = min(mini, 1.0 * bl.Y);

	//bottom right
	pi br = shift(MP(n - w, 0), MP(n, h), MP(x1, y1), MP(x2, y2));
	if (x1 - br.X >= 0) mini = min(mini, 1.0 * br.X);
	if (y2 + br.Y <= m) mini = min(mini, 1.0 * br.Y);

	//top left
	pi tl = shift(MP(0, m - h), MP(w, m), MP(x1, y1), MP(x2, y2));
	if (x2 + tl.X <= n) mini = min(mini, 1.0 * tl.X);
	if (y1 - tl.Y >= 0) mini = min(mini, 1.0 * tl.Y);

	//top right
	pi tr = shift(MP(n - w, m - h), MP(n, m), MP(x1, y1), MP(x2, y2));
	if (x1 - tr.X >= 0) mini = min(mini, 1.0 * tr.X);
	if (y1 - tr.Y >= 0) mini = min(mini, 1.0 * tr.Y);

	printf("%0.8lf\n", mini);
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