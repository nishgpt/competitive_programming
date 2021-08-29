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
	int n, m; in2(n, m);

	int i, j, k;
	vector<int> v[m];
	unordered_map<int, vector<pi> > mp;
	rep(i, 0, m) {
		in(k);
		rep(j, 0, k) {
			int x; in(x);
			v[i].PB(x);
			mp[x].PB(MP(i, j));
		}
	}

	set<pi> s;
	rep(i, 0, m) {
		if (s.find(MP(1, v[i][0])) != s.end()) {
			s.erase(s.find(MP(1, v[i][0])));
			s.insert(MP(2, v[i][0]));
		} else {
			s.insert(MP(1, v[i][0]));
		}
	}

	while (!s.empty()) {
		set<pi> :: reverse_iterator rt = s.rbegin();

		pi p = *rt;
		// cout << p.X << " " << p.Y << en;
		if (p.X < 2) {
			finish("No");
		}

		s.erase(s.find(p));
		int c = p.Y;
		if (mp[c][0].Y + 1 < v[mp[c][0].X].size()) {
			int col1 = v[mp[c][0].X][mp[c][0].Y + 1];
			if (s.find(MP(1, col1)) != s.end()) {
				s.erase(s.find(MP(1, col1)));
				s.insert(MP(2, col1));
			} else {
				s.insert(MP(1, col1));
			}
		}
		if (mp[c][1].Y + 1 < v[mp[c][1].X].size()) {
			int col2 = v[mp[c][1].X][mp[c][1].Y + 1];
			if (s.find(MP(1, col2)) != s.end()) {
				s.erase(s.find(MP(1, col2)));
				s.insert(MP(2, col2));
			} else {
				s.insert(MP(1, col2));
			}
		}
	}

	finish("Yes");
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