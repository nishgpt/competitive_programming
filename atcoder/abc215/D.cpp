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
#define MAX 100002
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

unordered_map<int, int> mp[MAX];
unordered_map<int, int> uni;
void pre() {
	int i, j;
	rep(i, 1, MAX) {
		int cp = i;
		for (j = 2; j * j <= i; j++) {
			while (cp % j == 0) {
				mp[i][j]++;
				cp = cp / j;
			}
		}

		if (cp > 1) {
			mp[i][cp]++;
		}
	}

	// rep(i, 1, 100) {
	// 	cout << i << " -> ";
	// 	rep(j, 2, i + 1) {
	// 		if (mp[i][j] > 0) cout << j << " ";
	// 	}
	// 	cout << en;
	// }
}

void solve() {
	int n, m, i, j; in2(n, m);
	vector<int> a(n);

	rep(i, 0, n) {
		in(a[i]);
		unordered_map<int, int> :: iterator it = mp[a[i]].begin();

		while (it != mp[a[i]].end()) {
			if (it->second > 0) {
				uni[it->first]++;
			}
			it++;
		}
	}

	vector<int> ans;
	rep(i, 1, m + 1) {
		unordered_map<int, int> :: iterator it = mp[i].begin();

		bool ok = true;
		while (it != mp[i].end()) {
			if (it->Y > 0 && uni[it->X] > 0) {
				ok = false; break;
			}
			it++;
		}

		if (ok) ans.PB(i);
	}

	cout << ans.size() << en;
	rep(i, 0, ans.size()) {
		cout << ans[i] << en;
	}


}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pre();
	int t = 1;

	// cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}