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

	set<pi> s;
	rep(i, 0, n) {
		in(a[i]);
		if (a[i] > 0) {
			s.insert(MP(a[i], i + 1));
		}
	}

	vector<pi> ans;
	while (s.size() > 1) {
		set<pi> :: reverse_iterator rt = s.rbegin();
		pi m = *rt;
		rt++;
		pi sm = *rt;
		s.erase(s.find(m));
		s.erase(s.find(sm));
		sm.X--; m.X--;
		ans.PB(MP(sm.Y, m.Y));
		if (sm.X > 0) {
			s.insert(MP(sm.X, sm.Y));
		}
		if (m.X > 0) {
			s.insert(MP(m.X, m.Y));
		}
	}

	cout << ans.size() << en;
	rep(i, 0, ans.size()) {
		if (ans[i].X > n || ans[i].X < 1 || ans[i].Y > n || ans[i].Y < 1) raise(SIGABRT);
		cout << ans[i].X << " " << ans[i].Y << en;
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