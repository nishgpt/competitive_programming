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

bool comp(pl &a, pl &b) {
	if (a.Y > b.Y) return true;
	if (a.Y == b.Y) return a.X >= b.X;
	return false;
}

void solve() {
	int n, i, j; in(n);
	vector<pl> v(n);

	rep(i, 0, n) {
		inl2(v[i].X, v[i].Y);
	}

	sort(v.begin(), v.end(), comp);

	i = 0; j = n - 1;

	LL items = 0;
	LL sum = 0;
	while (i <= j) {
		if (items >= v[j].Y) {
			items += v[j].X;
			sum += v[j].X;
			v[j].X = 0;
			j--;
		} else {
			LL req = v[j].Y - items;
			if (req < v[i].X) {
				v[i].X -= req;
				items += req;
				sum += 2 * req;
			} else {
				req = v[i].X;
				v[i].X -= req;
				items += req;
				sum += 2 * req;
				i++;
			}
		}
	}

	rep(i, 0, n) {
		sum += v[i].X;
	}

	cout << sum << en;
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