/*
	Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 4005
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

void compress(vector<pi> &v) {
	int i, j;
	set<int> s;
	rep(i, 0, v.size()) {
		s.insert(v[i].X);
		s.insert(v[i].Y);
	}

	set<int> :: iterator it = s.begin();

	int idx = 0;
	unordered_map<int, int> mp;
	while (it != s.end()) {
		mp[*it] = idx++;
		it++;
	}

	rep(i, 0, v.size()) {
		v[i].X = mp[v[i].X];
		v[i].Y = mp[v[i].Y];
	}
}

pi get_ul(int x1, int y1, int x2, int y2) {
	return MP(x1, y2);
}

pi get_br(int x1, int y1, int x2, int y2) {
	return MP(x2, y1);
}

void solve() {
	int n; in(n);
	int i, j;
	vector<pi> v(n);
	rep(i, 0, n) {
		in2(v[i].X, v[i].Y);
	}
	compress(v);

	map<pi, int> mp;
	rep(i, 0, n) {
		mp[MP(v[i].X, v[i].Y)] = 1;
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	rep(i, 0, n) {
		rep(j, i + 1, n) {
			if (v[i].X >= v[j].X || v[i].Y >= v[j].Y) continue;
			pi br = get_br(v[i].X, v[i].Y, v[j].X, v[j].Y);
			pi ul = get_ul(v[i].X, v[i].Y, v[j].X, v[j].Y);
			if (mp[br] > 0 && mp[ul] > 0) {
				cnt++;
			}
		}
	}
	finish(cnt);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;

	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}