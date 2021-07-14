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
	LL n, c; inl2(n, c);
	LL l, r;
	vector<pair<LL, char> > a;
	int i, x;
	unordered_map<LL, int> mp;
	rep(i, 0, n) {
		inl2(l, r);
		a.PB(MP(l, 's'));
		a.PB(MP(r, 'e'));
		mp[r]++;
	}

	sort(a.begin(), a.end());

	LL ans = n, cnt = 0, prev = 0;
	LL freq[MAX] = {0};
	LL eq = 0;
	rep(i, 0, a.size()) {
		if (a[i].Y == 's') {
			if (prev != a[i].X) {
				freq[cnt] += (a[i].X - prev);
			}
			cnt++;
		}
		if (a[i].Y == 'e') {
			if (a[i].X != prev) {
				freq[cnt] += (a[i].X - prev - 1);
				freq[cnt - mp[a[i].X]]++;
			}
			cnt--;
		}
		prev = a[i].X;
	}

	// rep(i, 0, 10) {
	// 	cout << freq[i] << " ";
	// }
	// cout << en;


	LL cuts = 0;
	for (LL idx = MAX - 1; idx > 0; idx--) {
		if (freq[idx] == 0) continue;

		if (freq[idx] + cuts <= c) {
			ans += (freq[idx] * idx);
			cuts += freq[idx];
		} else {
			ans += ((c - cuts) * idx);
			cuts = c;
		}
		if (cuts == c) break;
	}

	cout << ans << en;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
