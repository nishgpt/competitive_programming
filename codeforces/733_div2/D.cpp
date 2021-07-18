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
#define MAX 200005
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
	int n, i, j; in(n);
	vector<int> v(n);

	int a[n + 1]; MSV(a, 0);
	vector<int> pos[n + 1];
	rep(i, 0, n) {
		in(v[i]);
		a[v[i]]++;
		pos[v[i]].PB(i);
	}

	vector<int> ref = v;

	queue<int> q;
	rep(i, 1, n + 1) {
		if (a[i] == 0) q.push(i);
	}
	int qs = q.size();

	bitset<MAX> b;
	rep(i, 1, n + 1) {
		int sz = pos[i].size();
		rep(j, 0, sz - 1) {
			if (qs == 1) {
				v[pos[i][j]] = q.front();
				b[pos[i][j]] = true;
				q.pop();
				qs--;
			} else {
				while (!q.empty()) {
					if (pos[i][j] + 1 == q.front()) {
						int x = q.front();
						q.pop();
						q.push(x);
					} else {
						v[pos[i][j]] = q.front();
						q.pop(); b[pos[i][j]] = true;
						qs--;
						break;
					}
				}
			}
		}
	}

	int cnt = 0, idx = -1, widx = -1;
	rep(i, 0, n) {
		if (v[i] == i + 1) {
			cnt++;
			widx = i;
		}
		else if (b[i]) {
			idx = i;
		}
	}

	if (cnt > 1) raise(SIGABRT);

	if (cnt == 1) {
		if (idx == -1) {
			int val = ref[widx];
			rep(i, 0, n) {
				if (v[i] == val && i != widx) {
					idx = i;
					break;
				}
			}
		}
		swap(v[widx], v[idx]);
	}

	int ans = 0;
	rep(i, 0, n) if (ref[i] == v[i]) ans++;
	cout << ans << en;

	if (ans == 0) raise(SIGABRT);
	rep(i, 0, n) cout << v[i] << " ";
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