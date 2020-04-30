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
#define MAX 200005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

int u, v, n, k;
vector<int> adj[MAX];
vector<int> levels;
bool vis[MAX];
int subtree[MAX];

int dfs(int node) {
	int sub_nodes = 0;
	int i;
	
	for(i=0;i<adj[node].size();i++) {
		if(!vis[adj[node][i]]) {
			vis[adj[node][i]] = true;
			sub_nodes += dfs(adj[node][i]);
		}
	}
	subtree[node] = sub_nodes;
	vis[node] = false;
	return sub_nodes + 1;
}

LL solve() {
	int i;
	for(i=0;i<n-1;i++) {
		scanf("%d %d", &u, &v);	
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	//DFS to find subtree size for every node
	vis[1] = true;
	dfs(1);
	
	
	//BFS to find levels
	queue<pair<int, int> > q;
	q.push(MP(0, 1));
	levels.PB(-1*subtree[1]);
	vis[1] = true;
	
	while(!q.empty()) {
		pair<int, int> f = q.front();
		q.pop();
		int node = f.Y;
		int level = f.X;
		for(i=0;i<adj[node].size();i++) {
			if(!vis[adj[node][i]]) {
				vis[adj[node][i]] = true;
				levels.PB(level+1-subtree[adj[node][i]]);
				q.push(MP(level+1, adj[node][i]));
			}
		}
	}
	
	sort(levels.rbegin(), levels.rend());
	
	LL ans = 0;
	for(i=0;i<k;i++) {
		ans = ans + levels[i];
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &k);	
	cout<<solve()<<"\n";
    return 0;
}
