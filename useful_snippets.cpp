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
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;


/* GCD */
int _gcd(int a, int b) {
	if (b == 0) return a;
	return _gcd(b, a % b);
}

/* Factorial modulo MOD */
LL fact[MAX];
void factorial() {
	fact[0] = 1;
	for (int i = 1; i < MAX; i++) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}
}

/* Modulo exponentiation */
LL power(LL base, LL exp, LL ans) {
	if (!exp) return ans % MOD;
	if (exp & 1) ans = (ans * base) % MOD;
	return power((base * base) % MOD, exp >> 1, ans);
}

/* nCr modulo MOD */
LL nCr(LL n, LL r) {
	if (n < r) return 0;
	LL numerator = fact[n];
	LL denominator = (fact[n - r] * fact[r]) % MOD;
	return (numerator * power(denominator, MOD - 2, 1)) % MOD;
}

/* DFS on tree */
void dfs(int node, vector<int> adj[MAX], int parent) {
	for (int i = 0; i < adj[node].size(); i++) {
		if (parent != adj[node][i]) {
			dfs(adj[node][i], adj, node);
		}
	}
	return ;
}

/* Dijkstra Algo */
int dijkstra(int s, int d, vector<pi> adj[MAX]) {
	int mincost[MAX], i;
	rep(i, 0, MAX) mincost[i] = INF;

	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push(MP(0, s));
	mincost[s] = 0;

	while (!pq.empty()) {
		pi _top = pq.top();
		pq.pop();
		int node = _top.Y;

		for (i = 0; i < adj[node].size(); i++) {
			int ch = adj[node][i].X;
			int wt = adj[node][i].Y;
			if (mincost[node] + wt < mincost[ch]) {
				mincost[ch] = mincost[node] + wt;
				pq.push(MP(mincost[ch], ch));
			}
		}
	}

	return mincost[d];
}

/* Preprocess method for KMP */
void preprocess(string p, int* pie, int m) {
	int len = 0, i = 1;
	pie[0] = 0;
	while (i < m) {
		if (p[i] == p[len]) {
			pie[i] = ++len; i++;
		}
		else {
			if (len) len = pie[len - 1];
			else {
				pie[i] = 0; i++;
			}
		}
	}
}

/* KMP evaluation */
int KMP(string s, string p, int *pie, int n, int m) {
	int i, q = 0; //q is no. of characters matched
	int occurences = 0;
	rep(i, 0, n) {
		while (q > 0 && p[q] != s[i])
			q = pie[q];
		if (p[q] == s[i])q++;
		if (q == m) {
			occurences++;
			q = pie[q];
		}
	}

	return occurences;
}

/* Sieve of Eratosthenes */
bitset<MAX> prime;
void compute_prime() {
	prime.flip(); //makes all true
	prime[0] = prime[1] = false;

	for (int i = 2; i * i < MAX; i++) {
		if (prime[i])
			for (int j = i * i; j < MAX; j += i) prime[j] = false;
	}
}

/* Covert to binary in LOG_MAX bits */
void convert_to_binary(LL num, vector<int> &v) {
	queue<int> q;
	while (num) {
		q.push(num & 1);
		num >>= 1;
	}

	for (int i = LOG_MAX - 1; i >= 0; i--) {
		if (q.empty()) break;
		else {
			v[i] = q.front();
			q.pop();
		}
	}
}

/* LCA with binary lifting */
int level[MAX];
int parent[MAX];
int p[MAX][LOG_MAX];
void precompute_lca(int n) {
	int i, j;

	for (i = 1; i <= n; i++)
		for (j = 0; (1 << j) <= n; j++)
			p[i][j] = -1;

	for (i = 1; i <= n; i++)
		p[i][0] = parent[i];

	for (j = 1; (1 << j) <= n; j++) {
		for (i = 1; i <= n; i++)
			if (p[i][j - 1] != -1)
				p[i][j] = p[p[i][j - 1]][j - 1];
	}
}

int get_lca(int u, int v) {
	int tmp, _log, i;
	if (level[u] < level[v]) {
		tmp = u, u = v, v = tmp;
	}

	for (_log = 1; 1 << _log <= level[u]; _log++);
	_log--;

	for (i = _log; i >= 0; i--) {
		if (level[u] - (1 << i) >= level[v]) u = p[u][i];
	}

	if (u == v) return u;

	for (i = _log; i >= 0; i--)
		if (p[u][i] != -1 && p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i];

	return parent[u];
}

/* Union Find / DSU */
//have a parent array global
int find(int u) {
	if (u == parent[u])return u;
	return parent[u] = find(parent[u]);
}

void _union(int u, int v) {
	parent[find(u)] = find(v);
}


/* Trie */
/**
 * Usage
 * counter = 1
 * for word in words:
 *   counter = insert(word, counter)
 **/
struct Trie {
	int next[26];
	bool leaf;
} nodes[MAX];

int insert(string s, int counter) {
	int curr = 0, a = counter;
	for (int i = 0; i < s.length(); i++) {
		if (!nodes[curr].next[s[i] - 'a']) {
			nodes[curr].next[s[i] - 'a'] = a;
			curr = a++;
		}
		else curr = nodes[curr].next[s[i] - 'a'];
		if (i + 1 == s.length()) nodes[curr].leaf = true;
	}
	return a;
}

/* Modulo multiplication */
LL mulmod(LL a, LL b) {
	a = (a + MOD) % MOD;
	b = (b + MOD) % MOD;
	LL res = 0;
	a %= MOD;
	while (b) {
		if (b & 1) res = (res + a) % MOD;
		a = (a * 2) % MOD;
		b >>= 1;
	}
	return res;
}

/* Topological sort */
/**
 * Print elements of stack at the end
 **/
stack<int> st;
void topoSort(int node, vector<int> *adj, vector<bool> &vis) {
	vis[node] = true;
	for (int i = 0; i < adj[node].size(); i++) {
		if (!vis[adj[node][i]]) topoSort(adj[node][i], adj, vis);
	}
	st.push(node);
}

int main() {

	return 0;
}

