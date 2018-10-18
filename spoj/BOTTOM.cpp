#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define MS(a) memset(a, 0, sizeof a)

int comp[N], outdeg[N], visited[N];
vector<int> cp[N];
stack<int> s;

void dfs(int node, vector<int> adj[N]) {
	if(visited[node]) 
		return ;

	visited[node] = 1;
	int i;
	for(i=0;i<adj[node].size();i++) {
		dfs(adj[node][i], adj);
	}
	s.push(node);
}

void dfs1(int node, vector<int > adj[N], int val) {
	if(visited[node])
		return ;
	int i;
	visited[node] = 1;
	comp[node] = val;
	cp[val].push_back(node);
	for(i=0;i<adj[node].size();i++) {
		dfs1(adj[node][i], adj, val);
	}
}

int main() {
	int i, j, k, n, m;
	int u, v;
	while(scanf("%d %d", &n, &m) == 2) {
		if(n == 0 && m == 0)
			break;

		vector<int> ans;
		vector<int> adj[N], radj[N];
		for(i = 0;i<m;i++) {
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			radj[v].push_back(u);
		}
		MS(visited);

		for(i=1;i<=n;i++) {
			if(visited[i] == 0) {
				dfs(i, adj);
			}
		}
		
		MS(outdeg);
		MS(comp);
		k = 1;
		MS(visited);
		MS(cp);
		while(!s.empty()) {
			//cout<<"reverse dfs on = "<<s.top()<<endl;
			dfs1(s.top(), radj, k);
			k++;
			s.pop();
		}

		for(i=1;i<=n;i++) {
			for(j=0;j<adj[i].size();j++) {
				// cout<<i<<" comp = "<<comp[i]<< " " << adj[i][j] << " comp = "<< comp[adj[i][j]]<<endl;
				if(comp[i] != comp[adj[i][j]]) {
					outdeg[comp[i]]++;
				}
			}
		}

		for(i=1;i<=n;i++) {
			if(outdeg[i] == 0) {
				for(j=0;j<cp[i].size();j++) {
					ans.push_back(cp[i][j]);
				}				
			}
		}
		sort(ans.begin(), ans.end());
		for(i=0;i<ans.size();i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}