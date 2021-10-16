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

void solve() {
	int n, s, i; in2(n, s);
	string mini, maxi;

	if (n == 1 && s == 0) finish("0 0");

	//mini
	int sum = s;
	rep(i, 1, n + 1) {
		int left = sum - 9 * (n - i);
		if (left <= 0) {
			if (i == 1) left = 1;
			else left = 0;
		}
		if (left >= 0 && left <= 9) {
			mini.push_back((char)(left + '0'));
			sum -= left;
		}
		else {
			finish("-1 -1");
		}
	}

	//maxi
	sum = s;
	if (sum > 9 * n || sum < 1) finish("-1 -1");

	rep(i, 1, n + 1) {
		int left;
		if (sum > 9) left = 9;
		else left = sum;
		sum -= left;
		maxi.push_back((char)(left + '0'));
	}

	cout << mini << " " << maxi << en;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;

	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}