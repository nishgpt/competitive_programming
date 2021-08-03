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


vector<int> get_ans(vector<int> &a, vector<int> &b, int idx, int n) {
	int i, pos = 0;
	vector<int> ans(n);
	rep(i, idx, n) {
		ans[pos] = (a[pos] + b[i]) % n;
		pos++;
	}
	rep(i, 0, idx) {
		ans[pos] = (a[pos] + b[i]) % n;
		pos++;
	}

	return ans;
}

void solve() {
	int n, i; in(n);

	vector<int> a(n), b(n);
	rep(i, 0, n) {
		in(a[i]);
		a[i] = a[i] % n;
	}
	rep(i, 0, n) {
		in(b[i]);
		b[i] = b[i] % n;
	}

	int mini = INT_MAX;
	rep(i, 0, n) {
		int x = (a[0] + b[i]) % n;
		mini = min(mini, x);
	}

	vector<int> idx;
	rep(i, 0, n) {
		int x = (a[0] + b[i]) % n;
		if (x == mini) {
			idx.PB(i);
		}
	}

	if (idx.size() > 2) raise(SIGABRT);

	vector<int> ans1 = get_ans(a, b, idx[0], n);
	vector<int> ans = ans1;

	if (idx.size() == 2) {
		vector<int> ans2 = get_ans(a, b, idx[1], n);
		bool first = false;
		rep(i, 0, n) {
			if (ans1[i] < ans2[i]) {
				first = true; break;
			} else if (ans2[i] < ans1[i]) {
				break;
			}
		}

		if (!first) {
			ans = ans2;
		}
	}

	rep(i, 0, n) cout << ans[i] << " ";
	cout << en;
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