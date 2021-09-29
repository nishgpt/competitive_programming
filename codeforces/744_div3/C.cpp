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

bool valid(int i, int j, int n, int m) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

bool check(int i, int j, int n, int m, int k, vector<string> &s) {
	//top left
	int idx;
	rep(idx, 1, k + 1) {
		if (valid(i - idx, j - idx, n, m) && s[i - idx][j - idx] == '*') continue;
		return false;
	}

	//top right
	rep(idx, 1, k + 1) {
		if (valid(i - idx, j + idx, n, m) && s[i - idx][j + idx] == '*') continue;
		return false;
	}
	return true;
}

void solve() {
	int n, m, k; in2(n, m), in(k); int i, j;
	vector<string> s(n);

	rep(i, 0, n) cin >> s[i];
	int a[n][m];
	MSV(a, 0);
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (s[i][j] == '*' && check(i, j, n, m, k, s)) {
				//paint
				int idx;
				a[i][j] = 1;
				rep(idx, 1, INT_MAX) {
					if (valid(i - idx, j - idx, n, m) && valid(i - idx, j + idx, n, m) && s[i - idx][j - idx] == '*' && s[i - idx][j + idx] == '*') {
						a[i - idx][j - idx] = 1;
						a[i - idx][j + idx] = 1;
					} else break;
				}
			}
		}
	}

	bool ok = true;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (s[i][j] == '*' && a[i][j] == 1) continue;
			if (s[i][j] == '.' && a[i][j] == 0) continue;
			ok = false;
			break;
		}
	}

	if (ok) finish("YES");
	finish("NO");
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