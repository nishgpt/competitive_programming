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

LL dfs(int node, int par, vector<vector<int> > &adj, vector<LL> &gold) {
	vector<LL> ch;
	int i;
	rep(i, 0, adj[node].size()) {
		if (par != adj[node][i]) {
			LL chgold = dfs(adj[node][i], node, adj, gold);
			ch.PB(chgold);
		}
	}

	int csz = ch.size();
	if (csz > 0) {
		sort(ch.rbegin(), ch.rend()); //since n is small and its a tree, sorting wont make much difference
	}

	LL val = gold[node] + (csz > 0 ? ch[0] : 0);
	if (node == 1 && csz > 1) {
		val += ch[1];
	}

	return val;
}

void solve() {
	int n, i, j; in(n);

	vector<vector<int> > adj(n + 1, vector<int> ());
	vector<LL> gold(n + 1);

	rep(i, 1, n + 1) inl(gold[i]);

	rep(i, 0, n - 1) {
		int u, v;
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}

	cout << dfs(1, -1, adj, gold) << en;
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