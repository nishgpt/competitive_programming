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
#define MAX 61
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

LL nCr[MAX][MAX];
void pre() {
	int i, j;
	rep(i, 0, MAX) {
		nCr[i][0] = 1;
		nCr[i][i] = 1;
	}

	rep(i, 1, MAX) {
		rep(j, 1, i) {
			nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
		}
	}
}

string get_ans(int a, int b, LL k) {
	if (a == 0 && b == 0) return "";
	if (a == 0) return string(b, 'b');
	if (b == 0) return string(a, 'a');

	LL half = nCr[a + b - 1][b];
	string ans = "a";
	if (k <= half) {
		return ans + get_ans(a - 1, b, k);
	}

	ans = "b";
	return ans + get_ans(a, b - 1, k - half);
}

void solve() {
	int a, b;
	LL k;
	in2(a, b); inl(k);
	cout << get_ans(a, b, k) << en;
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