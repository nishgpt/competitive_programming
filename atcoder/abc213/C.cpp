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
	int h, w, n;
	in2(h, w); in(n);
	int i, j;

	vector<pi> v(n + 1);
	set<int> r, c;
	rep(i, 0, n) {
		int x, y;
		in2(x, y);
		r.insert(x);
		c.insert(y);
		v[i + 1] = MP(x, y);
	}

	set<int> :: iterator it = r.begin();
	vector<int> rr, cc;
	while (it != r.end()) {
		rr.PB(*it);
		it++;
	}
	set<int> :: iterator ct = c.begin();
	while (ct != c.end()) {
		cc.PB(*ct);
		ct++;
	}

	rep(i, 1, n + 1) {
		int row = upper_bound(rr.begin(), rr.end(), v[i].X) - rr.begin();
		int col = upper_bound(cc.begin(), cc.end(), v[i].Y) - cc.begin();

		cout << row << " " << col << en;
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;

	// cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}
