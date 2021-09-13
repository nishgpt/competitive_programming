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

void solve(int tc) {
	int n, m, x, y, i, j;
	in2(n, m); in2(x, y);
	string s;
	cin >> s;
	if (s.compare("Impossible") == 0) {
		if (x >= n + m - 1 && y >= n + m - 1) {
			cout << "Wrong Answer for tc #" << tc << en;
			cout << "Expected -> Possible" << en;
			raise(SIGABRT);
		}
		cout << "Correct Answer for tc #" << tc << en;
		return;
	}

	//possible case
	vector<vector<int> > a(n, vector<int> (m, 0));
	rep(i, 0, n) {
		rep(j, 0, m) {
			in(a[i][j]);
		}
	}

	rep(i, 0, n) {
		rep(j, 0, m) {
			if (a[i][j] < 1 || a[i][j] > 1000) {
				cout << "Wrong Answer for tc #" << tc << en;
				cout << "Expected Values in range [1, 1000], Found => " << a[i][j] << en;
				raise(SIGABRT);
			}
		}
	}

	//From top left to bottom right
	int lt[n][m];
	MSV(lt, 0);
	rep(i , 0, m) {
		lt[0][i] = a[0][i];
		if (i > 0) lt[0][i] += lt[0][i - 1];
	}
	rep(i, 0, n) {
		lt[i][0] = a[i][0];
		if (i > 0) lt[i][0] += lt[i - 1][0];
	}
	rep(i, 1, n) {
		rep(j, 1, m) {
			lt[i][j] = a[i][j] + min(lt[i - 1][j], lt[i][j - 1]);
		}
	}
	if (lt[n - 1][m - 1] != x) {
		cout << "Wrong Answer for tc #" << tc << en;
		cout << "Expected Answer to topL to bottomR => " << x << ", Found => " << lt[n - 1][m - 1] << en;
		raise(SIGABRT);
	}

	//From top right to bottom left
	int rt[n][m];
	MSV(rt, 0);
	rev(i, m - 1, 0) {
		rt[0][i] = a[0][i];
		if (i < m - 1) rt[0][i] += rt[0][i + 1];
	}
	rep(i, 0, n) {
		rt[i][m - 1] = a[i][m - 1];
		if (i > 0) rt[i][m - 1] += rt[i - 1][m - 1];
	}

	rep(i, 1, n) {
		rev(j, m - 2, 0) {
			rt[i][j] = a[i][j] + min(rt[i - 1][j], rt[i][j + 1]);
		}
	}
	if (rt[n - 1][0] != y) {
		cout << "Wrong Answer for tc #" << tc << en;
		cout << "Expected Answer to topR to bottomL => " << y << ", Found => " << rt[n - 1][0] << en;
		raise(SIGABRT);
	}

	// cout << x << " = " << lt[n - 1][m - 1] << " ::: " << y << " = " << rt[n - 1][0] << en;
	cout << "Correct Answer for tc #" << tc << en;
}

int main() {
	int t = 1;

	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
	return 0;
}