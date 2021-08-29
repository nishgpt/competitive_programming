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

LL sum(LL a, LL l) {
	if (a > l) return 0;
	return ((l - a + 1) * (a + l)) / 2;
}
void solve() {
	int n, k; in2(n, k);
	int i, j;
	set<LL> s;
	unordered_map<LL, LL> mp;

	LL ans = 0;
	vector<LL> v(n);
	rep(i, 0, n) {
		inl(v[i]);
		mp[v[i]]++;
		s.insert(v[i]);
	}
	s.insert(0);

	int taken = 0;
	while (s.size() > 1 && taken < k) {
		set<LL> :: reverse_iterator rt = s.rbegin();
		LL m1 = *rt;
		rt++;
		LL m2 = *rt;
		LL diff = m1 - m2;
		LL pot = diff * mp[m1];

		// cout << m1 << " " << m2 << " " << pot << endl;
		if (pot + taken <= k) {
			ans = ans + mp[m1] * sum(m2 + 1, m1);
			s.erase(s.find(m1));
			mp[m2] += mp[m1];
			taken += pot;
		} else {
			LL can = k - taken;
			LL q = can / mp[m1];
			LL r = can % mp[m1];
			if (q > 0) {
				ans = ans + mp[m1] * sum(m1 - q + 1, m1);
			}
			ans = ans + r * (m1 - q);
			taken += can;
		}
		// cout << ans << endl;
	}

	cout << ans << en;
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