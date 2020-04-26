// TLE in all test cases 
/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 500005
#define LOG_MAX 20
#define MOD 1000000007
#define getcx getchar_unlocked

using namespace std;

inline void inp( int &n )
{ 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}   	
inline void inp1( LL &n )
{ 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
} 

vector<pair<int, LL> > adj[MAX];
bool flag;
int p[MAX][LOG_MAX];
int parent[MAX];
int level[MAX];
int root = 0;
vector<LL> wt;
map<pair<int, int>, int> edge_mp;
vector<pair<int, int> > edges;
LL values[MAX];

LL power(LL base, LL exp, LL ans) {
	if(!exp) return ans % MOD;
	if(exp&1) ans = (ans * base) % MOD;
	return power((base * base) % MOD, exp>>1, ans);
}

void assign_levels_and_parent() {
	int i;
	queue<pair<int, int> > que;
	que.push(mp(root, 0));
	
	level[root] = 0;
	parent[root] = -1;
	
	bool visited[MAX] = {false};
	visited[root] = true;
	
	//bfs to assign levels wrt root
	while(!que.empty()) {
		int node = que.front().first;
		int l = que.front().second;
		que.pop();
		
		for(i=0;i<adj[node].size();i++) {
			int v = adj[node][i].first;
			if(!visited[v]) {
				visited[v] = true;
				que.push(mp(v, l+1));
				level[v] = l+1;
				parent[v] = node;
			}
		}
	}
}
 
void precompute_for_lca(int N) {
	int i, j; 

	for (i = 0; i < N; i++)
		for (j = 0; 1 << j < N; j++)
			p[i][j] = -1; 

	for (i = 0; i < N; i++)
		p[i][0] = parent[i]; 

	for (j = 1; 1 << j < N; j++)
		for (i = 0; i < N; i++)
			if (p[i][j - 1] != -1)
				p[i][j] = p[p[i][j - 1]][j - 1];
}

void recalculate_values() {
	int i;
	queue<pair<int, LL> > q;
	q.push(mp(root, 0));
	bool visited[MAX] = {false};
	visited[root] = true;
	
	while(!q.empty()) {
		int node = q.front().first;
		LL value = q.front().second;
		values[node] = value;
		q.pop();
		for(i=0;i<adj[node].size();i++) {
			int v = adj[node][i].first;
			if(!visited[v]) {
				q.push(mp(v, (value + adj[node][i].second) % MOD));
				visited[v] = true;
			}
		}
	}
}

int lca(int u, int v) {
	int tmp, _log, i; 

	if (level[u] < level[v]) {
		tmp = u, u = v, v = tmp;
	} 

	for (_log = 1; 1 << _log <= level[u]; _log++);
	_log--; 

	for (i = _log; i >= 0; i--) {
		if (level[u] - (1 << i) >= level[v]) {
			u = p[u][i];
		}
	}

	if (u == v)
		return u; 

	for (i = _log; i >= 0; i--)
		if (p[u][i] != -1 && p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i]; 

	return parent[u];
}

int get_ancestor_at_level(int u, int target_level) {
	if(level[u] == target_level) return u;
	
	int _log;
	for (_log = 1; 1 << _log <= level[u]; _log++);
	_log--; 

	for (int i = _log; i >= 0; i--) {
		if (level[u] - (1 << i) >= target_level) {
			u = p[u][i];
		}
	}
	
	return u;
} 

int main() {
	int n, q, op, x, y, un;
	LL c;
	
	inp(n);inp(q);
	for(int i=0;i<n-1;i++) {
		inp(x);inp(y);inp1(c);
		edge_mp[mp(min(x, y), max(x, y))] = i;
		wt.pb(c);
		edges.pb(mp(x, y));
		adj[x].pb(mp(y, c));
		adj[y].pb(mp(x, c));
	}
	
	map<pair<int, int>, int> pos_map; 
	for(int i=0;i<n;i++) {
		for(int j=0;j<adj[i].size();j++) {
			pos_map[mp(i, adj[i][j].first)] = j;
		} 
	}
	
	assign_levels_and_parent();
	precompute_for_lca(n);
	
	vector<pair<int, pair<int, int> > > query; //first: query number, second contains pair of nodes
	vector<pair<int, int> > updates; //first: query number, second: node
	vector<pair<bool, int> > Q;
	int qq = 0, uu = 0;
	for(int i=0;i<q;i++) {
		inp(op);
		
		if(op == 0) {
			inp(un);
			updates.pb(mp(i, un));
			Q.pb(mp(false, uu));
			uu++;
		} else {
			inp(x);inp(y);
			query.pb(mp(i, mp(x, y)));
			Q.pb(mp(true, qq));
			qq++;
		} 
	}
	
	int sq = sqrt(q);
	int st = 0;
	while(true) {
		if(st == q) break;
		recalculate_values();
		map<int, int> uops;
		
		for(int i=st;i<min(st+sq, q);i++) {
			if(Q[i].first) { //query operation
				int idx = Q[i].second;
				int node1 = query[idx].second.first;
				int node2 = query[idx].second.second;
				int LCA = lca(node1, node2);
				LL ans = (values[node1] + values[node2] - 2 * values[LCA] + MOD) % MOD;
				
				if(node1 == node2) {
					cout<<ans<<endl;
					continue;
				}
				
				map<int, int> edge_count; //edge number -> number of times it got updated
				map<int, int> :: iterator it;
				//check if there are any updates
				for(it = uops.begin(); it!=uops.end();it++) {
					int unode = it -> first; int times = it -> second;
					int e_num;
					
					if(unode == node1 || unode == node2) {
						if(lca(LCA, parent[unode]) != LCA) continue;
						e_num = edge_mp[mp(min(unode, parent[unode]), max(unode, parent[unode]))];
						edge_count[e_num] += times;
					}
					
					else if(unode == LCA) {
						int other1 = (LCA == node1) ? -1 : get_ancestor_at_level(node1, level[LCA] + 1);
						int other2 = (LCA == node2) ? -1 : get_ancestor_at_level(node2, level[LCA] + 1);
						
						if(other1 != -1) {
							e_num = edge_mp[mp(min(unode, other1), max(unode, other1))];
							edge_count[e_num] += times;
						}
						if(other2 != -1) {
							e_num = edge_mp[mp(min(unode, other2), max(unode, other2))];
							edge_count[e_num] += times;
						}
					} 
					
					else {
						int m_node = -1;
						if(lca(unode, LCA) != LCA) continue;
						if(lca(unode, node1) == unode) m_node = node1;
						else if(lca(unode, node2) == unode) m_node = node2;
						
						if(m_node != -1) {
							e_num = edge_mp[mp(min(unode, parent[unode]), max(unode, parent[unode]))];
							edge_count[e_num] += times;
							
							int other = get_ancestor_at_level(m_node, level[unode] + 1);
							e_num = edge_mp[mp(min(unode, other), max(unode, other))];
							edge_count[e_num] += times;
						}
					}
				}
				
				map<int, int> :: iterator et;
				for(et = edge_count.begin();et != edge_count.end();et++) {
					int e_num = et -> first; int times = et -> second;
					LL upd_wt = (wt[e_num] * power(2, times, 1)) % MOD; 
					ans = (ans - wt[e_num] + upd_wt + MOD) % MOD;
				}
			
				cout<<ans<<endl;
			} else { //update operation
				int idx = Q[i].second;
				int vertex = updates[idx].second;
				uops[vertex]++;
			}
		}
		
		//update weights everywhere once per sqrt(q) times
		for(int i=0;i<edges.size();i++) {
			int node1 = edges[i].first;
			int node2 = edges[i].second;
			int total_updates = uops[node1] + uops[node2];
			
			wt[i] = (wt[i] * power(2, total_updates, 1)) % MOD;
		}
		st += sq;
	}
	return 0;
}

