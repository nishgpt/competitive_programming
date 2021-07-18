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

void solve() {
	int n, m;
	in2(n, m);

	int i, j;
	int a[n][m];

	int dir[][2] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, { -1, 1}, {1, -1}, {1, 1}, { -1, -1}};
	MSV(a, 0);
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (i == 0 || j == 0 || j == m - 1 || i == n - 1) {
				bool f = true;
				for (int x = 0; x < 8; x++) {
					if (valid(i + dir[x][0], j + dir[x][1], n, m) && a[i + dir[x][0]][j + dir[x][1]] != 0) {
						f = false;
						break;
					}
				}
				if (f) a[i][j] = 1;
			}
			cout << a[i][j];
		}
		cout << en;
	}
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