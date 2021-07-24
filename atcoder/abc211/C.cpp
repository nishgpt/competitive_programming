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

int count_(string a, string b)
{
	int m = a.length();
	int n = b.length();

	// Create a table to store results of sub-problems
	int lookup[m + 1][n + 1]; MSV(lookup, 0);

	// If first string is empty
	for (int i = 0; i <= n; ++i)
		lookup[0][i] = 0;

	// If second string is empty
	for (int i = 0; i <= m; ++i)
		lookup[i][0] = 1;

	// Fill lookup[][] in bottom up manner
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// If last characters are same, we have two
			// options -
			// 1. consider last characters of both strings
			//    in solution
			// 2. ignore last character of first string
			if (a[i - 1] == b[j - 1])
				lookup[i][j] = (lookup[i - 1][j - 1] + lookup[i - 1][j]) % MOD;

			else
				// If last character are different, ignore
				// last character of first string
				lookup[i][j] = lookup[i - 1][j];
		}
	}

	return lookup[m][n] % MOD;
}


void solve() {
	string p = "chokudai";
	string s;
	cin >> s;

	cout << count_(s, p) << en;
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