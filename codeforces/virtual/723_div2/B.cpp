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
#define MAX 1000005
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

bool vis[MAX] = {false};
void pre() {
	queue<int> q;
	vector<int> v;
	v.PB(11); v.PB(111); v.PB(1111); v.PB(11111); v.PB(111111);
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
		vis[v[i]] = true;
	}
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		for (int i = 0; i < v.size(); i++) {
			if (v[i] + n < MAX && !vis[v[i] + n]) {
				q.push(v[i] + n);
				vis[v[i] + n] = true;
			}
		}
	}
}


bool possible(int n) {
	if (n < MAX) return vis[n];
	return true;
}

void solve() {
	int n; in(n);
	cout << (possible(n) ? "YES" : "NO") << en;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	pre();

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}