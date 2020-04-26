/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 10005
#define MOD 1000000007

using namespace std;

vector<pair<int, int> > adj[MAX];
int n, m, k, u, v, st, _end, w;
map<pair<int, int>, int> edges;
bool visited[MAX];
int blacklisted[MAX];
int next_node[MAX];
//NAIVE DFS
int  dfs(int node) {
	if(node == _end) {
		return 1;
	}
	
	visited[node] = true;
	int mini = MOD;
	int nnode = -1;
	for(int i=0;i<adj[node].size();i++) {
		if(!visited[adj[node][i].first]) {
			int temp = dfs(adj[node][i].first);
			if(mini > temp) {
				mini = temp;
				nnode = adj[node][i].first;
			}
		}
	}
	
	next_node[node] = nnode;
	return mini + (1 - blacklisted[node]);
} 

int main() {
	int i;
	
	cin>>n>>m>>k;
	cin>>st>>_end;
	
	for(i=1;i<=m;i++) {
		cin>>u>>v>>w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
		edges[mp(min(u, v), max(u, v))] = i;
	}
	
	int bl;
	for(i=1;i<=k;i++) {
		cin>>bl;
		blacklisted[bl] = 1;
	}
	
	dfs(st);
	queue<int> path;
	int node = st;
	while(node != _end) {
		int nnode = next_node[node];
		path.push(edges[mp(min(node, nnode), max(node, nnode))]);
		node = nnode;
	}
	
	int total_edges = path.size();
	cout<<total_edges<<endl;
	while(!path.empty()) {
		cout<<path.front()<<endl;
		path.pop();
	}
	
    return 0;
}

