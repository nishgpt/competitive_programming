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

inline void inp( int &n ) {
	n = 0;    int ch = getcx(); int sign = 1;
	while ( ch < '0' || ch > '9' ) {if (ch == '-')sign = -1; ch = getcx();}
	while (  ch >= '0' && ch <= '9' )
		n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	n = n * sign;
}

inline void inp1( LL &n ) {
	n = 0;    LL ch = getcx(); LL sign = 1;
	while ( ch < '0' || ch > '9' ) {if (ch == '-')sign = -1; ch = getcx();}
	while (  ch >= '0' && ch <= '9' )
		n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	n = n * sign;
}

void solve() {
	int n, i, j;
	in(n);

	string s[n];
	rep(i, 0, n) cin >> s[i];

	int mini = INT_MAX;
	set<pi> st;

	//rows
	vector<int> rows(n, INT_MAX);
	rep(i, 0, n) {
		int e = 0;
		bool ok = true;
		rep(j, 0, n) {
			if (s[i][j] == 'O') {
				ok = false; break;
			}
			else if (s[i][j] == '.') e++;
		}
		if (ok) {
			rows[i] = e;
		}
		mini = min(mini, rows[i]);
	}

	vector<int> cols(n, INT_MAX);
	rep(j, 0, n) {
		int e = 0;
		bool ok = true;
		rep(i, 0, n) {
			if (s[i][j] == 'O') {
				ok = false; break;
			}
			else if (s[i][j] == '.') e++;
		}
		if (ok) cols[j] = e;
		mini = min(mini, cols[j]);
	}

	if (mini == INT_MAX) {
		finish("Impossible");
	}

	if (mini != 1) {
		int ans = 0;
		rep(i, 0, n) {
			if (rows[i] == mini) ans++;
			if (cols[i] == mini) ans++;
		}
		cout << mini << " " << ans << en;
		return;
	}

	//rows
	rep(i, 0, n) {
		if (rows[i] != 1) continue;
		rep(j, 0, n) {
			if (s[i][j] == '.') st.insert(MP(i, j));
		}
	}

	//cols
	rep(j, 0, n) {
		if (cols[j] != 1) continue;
		rep(i, 0, n) {
			if (s[i][j] == '.') st.insert(MP(i, j));
		}
	}

	cout << mini << " " << st.size() << en;
}

int main() {
	int t = 1;

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}