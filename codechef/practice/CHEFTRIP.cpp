/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

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

using namespace std;

typedef pair<int, int> pi;

inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

inline void inp1( LL &n ) { 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

int level[MAX];
int a[MAX];
int parent[MAX];
int p[MAX][LOG_MAX];
int last_dec[MAX], last_inc[MAX];

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

	for (_log=1;1<<_log<=level[u];_log++);
	_log--;

	for (i=_log;i>=0;i--) {
		if (level[u] - (1 << i) >= level[v]) u = p[u][i];
	}

	if (u == v) return u; 

	for (i = _log; i >= 0; i--)
		if (p[u][i] != -1 && p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i]; 

	return parent[u];
}

void assign_levels_and_parent(int n, vector<int> adj[]) {
	//bfs with root 1
	bool vis[n+1];
	MSV(vis, false);
	
	queue<pi> q;
	q.push(MP(1, 0));
	level[1] = 0; parent[1] = -1; vis[1] = true;

	while(!q.empty()) {
		int node = q.front().X;
		int l = q.front().Y;
		q.pop();
		for(int i=0;i<adj[node].size();i++) {
			if(!vis[adj[node][i]]) {
				parent[adj[node][i]] = node;
				level[adj[node][i]] = l+1;
				vis[adj[node][i]] = true;
				q.push(MP(adj[node][i], l+1));
			}
		}
	}
}

pi dfs(int node, vector<int> adj[], bool vis[]) {
	if(vis[node]) return MP(last_inc[node], last_dec[node]);
	
	vis[node] = true;
	last_inc[node] = node;
	last_dec[node] = node;
	
	if(parent[node] != -1) {
		int pp = parent[node];
		pi info = dfs(pp, adj, vis);
			
		if(a[node] < a[pp]) last_inc[node] = info.X; 
		else if(a[node] > a[pp]) last_dec[node] = info.Y;
	}
	return MP(last_inc[node], last_dec[node]);
}

void compute_last_inc_dec(int n, vector<int> adj[]) {
	bool vis[n+1];
	MSV(vis, false);
	priority_queue<pi> pq;
	
	for(int i=1;i<=n;i++) pq.push(MP(level[i], i));
	
	while(!pq.empty()) {
		pi t = pq.top();
		pq.pop();
		int node = t.Y;
		if(vis[node]) continue;
		
		dfs(node, adj, vis);
	}
}

bool is_beautiful(int x, int y) {
	if(x == y) return true;
	
	int lca = get_lca(x, y);
	
	//x, y, lca are different
	bool beautiful = false;
	if(x != y && y != lca && x != lca) {
		if(level[last_inc[x]] > level[lca]) {
			beautiful |= (level[last_dec[last_inc[x]]] <= level[lca] && level[last_inc[y]] <= level[lca]);
		}
		
		if(level[last_inc[x]] <= level[lca]) {
			beautiful |= (level[last_dec[y]] <= level[lca]);
			beautiful |= (level[last_inc[y]] > level[lca] && level[last_dec[last_inc[y]]] <= level[lca]);
			beautiful |= (level[last_inc[y]] <= level[lca]);
		}
		
		beautiful |= (level[last_dec[x]] <= level[lca] && level[last_inc[y]] <= level[lca]);
	} else if(x == lca) {
		beautiful |= (level[last_dec[y]] <= level[lca]);
		beautiful |= (level[last_inc[y]] <= level[lca]);
		beautiful |= (level[last_inc[y]] > level[lca] && level[last_dec[last_inc[y]]] <= level[lca]);
	} else if(y == lca) {
		beautiful |= (level[last_inc[x]] <= level[lca]);
		beautiful |= (level[last_dec[x]] <= level[lca]);
		beautiful |= (level[last_inc[x]] > level[lca] && level[last_dec[last_inc[x]]] <= level[lca]);
	}
	
	return beautiful;
}

int main() {
	int t, n, q, i, u, v, x, y;
	
	inp(t);
	while(t--) {
		inp(n);inp(q);
		vector<int> adj[n+1];
		for(i=0;i<n-1;i++) {
			inp(u);inp(v);
			adj[u].PB(v);
			adj[v].PB(u);
		}
		for(i=1;i<=n;i++) inp(a[i]);

		assign_levels_and_parent(n, adj);
		precompute_lca(n);
		compute_last_inc_dec(n, adj);
		
		for(i=0;i<q;i++) {
			inp(x);inp(y);
			if(is_beautiful(x, y)) cout<<"1";
			else cout<<"0";
		}
		cout<<"\n";
	}
	

    return 0;
}

