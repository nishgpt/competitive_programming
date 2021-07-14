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

vector<pl> break_pair(pl p, LL x) {
	vector<pl> v;
	if (x == p.X && p.X + 1 <= p.Y) {
		v.PB(MP(p.X + 1, p.Y));
	}
	else if (x == p.Y && p.Y - 1 >= p.X) {
		v.PB(MP(p.X, p.Y - 1));
	}
	else {
		if (x - 1 >= p.X) v.PB(MP(p.X, x - 1));
		if (x + 1 <= p.Y) v.PB(MP(x + 1, p.Y));
	}

	return v;
}

void solve() {
	int n, m; in2(n, m);
	LL x, y; int i, j;
	set<pl> s;

	rep(i, 0, n) {
		inl2(x, y);
		s.insert(MP(x, y));
	}

	vector<LL> ans(m);
	rep(i, 0, m) {
		inl(x);
		set<pl> :: iterator it = s.upper_bound(MP(x, -1));
		if (it == s.end()) {
			set<pl> :: reverse_iterator rit = s.rbegin();
			pl p = *rit;
			vector<pl> bp;
			if (p.X <= x && x <= p.Y) {
				ans[i] = x;
				bp = break_pair(p, x);
			} else {
				ans[i] = p.Y;
				bp = break_pair(p, p.Y);
			}

			s.erase(s.find(p));
			rep(j, 0, bp.size()) {
				s.insert(bp[j]);
			}
		}

		else if (it == s.begin()) {
			pl p = *it;
			ans[i] = p.X;
			vector<pl> bp = break_pair(p, p.X);

			s.erase(s.find(p));
			rep(j, 0, bp.size()) {
				s.insert(bp[j]);
			}
		}

		else {
			pl p = *it;
			--it;
			pl prev = *it;
			vector<pl> bp;
			if (prev.X <= x && prev.Y >= x) {
				ans[i] = x;
				bp = break_pair(prev, x);
				s.erase(s.find(prev));
				rep(j, 0, bp.size()) s.insert(bp[j]);
			} else {
				LL d1 = abs(p.X - x);
				LL d2 = abs(x - prev.Y);

				if (d2 <= d1) {
					ans[i] = prev.Y;
					bp = break_pair(prev, prev.Y);
					s.erase(s.find(prev));
					rep(j, 0, bp.size()) s.insert(bp[j]);
				} else {
					ans[i] = p.X;
					bp = break_pair(p, p.X);
					s.erase(s.find(p));
					rep(j, 0, bp.size()) s.insert(bp[j]);
				}
			}
		}
		cout << ans[i] << " ";
	}
	cout << en;
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
