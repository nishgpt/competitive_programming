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

inline void inp( int &n ) {
	n = 0;    int ch = getcx(); int sign = 1;
	while ( ch < '0' || ch > '9' ) {if (ch == '-')sign = -1; ch = getcx();}
	while (  ch >= '0' && ch <= '9' )
		n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	n = n * sign;
}

inline void inp1( LL &n ) {
	n = 0;    LL ch = getcx(); LL sign = 1;
	while ( ch < '0' || ch > '9' ) {if (ch == '-')sign = -1; ch = getcx();}
	while (  ch >= '0' && ch <= '9' )
		n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	n = n * sign;
}

const int N = 26;
void solve() {
	int adj[N][N], ops[N][N];
	MSV(adj, 0);
	MSV(ops, -1);

	string s; int n, m, i, j;

	cin >> s;
	n = s.length();
	in(m);
	while (m--) {
		string p;
		cin >> p;
		adj[p[0] - 'A'][p[1] - 'A'] = 1;
	}

	rep(i, 0, N) {
		//start a bfs from every char
		int root = i;
		queue<pi> q;
		bool vis[N] = {false};

		q.push(MP(root, 0));
		vis[root] = true;

		while (!q.empty()) {
			int node = q.front().X;
			int l = q.front().Y;
			ops[root][node] = l; //mark number of ops needed to go from root to node
			q.pop();

			rep(j, 0, N) {
				if (!vis[j] && adj[node][j] == 1) {
					q.push(MP(j, l + 1));
					vis[j] = true;
				}
			}
		}
	}

	int ans = INT_MAX;
	rep(i, 0, N) {
		int cnt = 0;
		rep(j, 0, n) {
			int ch = s[j] - 'A';
			if (ops[ch][i] == -1) {
				cnt = INT_MAX;
				break;
			}
			cnt += ops[ch][i];
		}
		ans = min(ans, cnt);
	}

	if (ans == INT_MAX) ans = -1;

	finish(ans);
}

int main() {
	int t = 1;

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}