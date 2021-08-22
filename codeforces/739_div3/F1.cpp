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

bool isKBeautiful(string s) {
	set<int> st;
	int i;
	rep(i , 0, s.length()) {
		st.insert(s[i] - '0');
	}

	return st.size() <= 2;
}

void solve() {
	string s; int k;
	int idx;
	cin >> s;
	in(k);
	int i, j;

	int l = s.length();
	string ans;

	rep(j, 1, 10) {
		string x = string(l, (char)(j + '0'));
		if (x.compare(s) >= 0) {
			ans = x;
			break;
		}
	}

	if (k == 1) {
		finish(ans);
	}

	if (isKBeautiful(s)) {
		finish(s);
	}

	rep(i, 0, 10) {
		rep(j, i + 1, 10) {
			bool ok = true;
			int fill = -1;

			rep(idx, 0, l) {
				int v = s[idx] - '0';

				if (v < j) {
					string tmp = s;
					if (tmp[idx] - '0' < i) {
						for (int c = idx; c < l; c++) {
							tmp[c] = (char)(i + '0');
						}
					} else if (tmp[idx] - '0' >= i && tmp[idx] - '0' < j) {
						tmp[idx] = (char)(j + '0');
						for (int c = idx + 1; c < l; c++) {
							tmp[c] = (char)(i + '0');
						}
					}
					if (tmp.compare(ans) < 0) {
						ans = tmp;
					}
				}

				if (v != i && v != j) {
					ok = false; break;
				}
			}
		}
	}

	finish(ans);
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