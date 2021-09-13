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

int get_ans(string s, int n) {
	int cnt = 0, prev = -1, i, j;
	rep(i, 0, n) {
		if (s[i] == 'X') {
			if (prev == 0) cnt++;
			prev = 1;
		} else if (s[i] == 'O') {
			if (prev == 1) cnt++;
			prev = 0;
		}
	}
	return cnt;
}

void solve() {
	int n, i, j; in(n);
	string s; cin >> s;

	int ans = 0;
	rep(i, 0, n) {
		rep(j, i, n) {
			string x = s.substr(i, (j - i + 1));
			ans = (ans + get_ans(x, (j - i + 1))) % MOD;
		}
	}

	cout << ans << endl;
}

int main() {

	int t = 1;

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}