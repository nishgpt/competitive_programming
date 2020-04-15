/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MAX_VAL 1000003
#define MOD 1000000007

using namespace std;

map<int, int> pfact[MAX_VAL];
vector<int> v[MAX_VAL];
void precompute() {
	int i, j;
	bool np[MAX_VAL] = {false};
	for(i=2;i*i<=MAX_VAL;i++) {
		if(!np[i]) {
			for(j=2*i;j<MAX_VAL;j+=i) {
				np[j] = true;
			}
		}
	}
	
	for(i=2;i*i<=MAX_VAL;i++) {
		for(j=2*i;j<MAX_VAL;j+=i) {
			if(!np[i] && i*i <= j) v[j].pb(i); //primes <= sqrt of number
			int other = j/i;
			if(!np[other] && other > i) v[j].pb(other); //primes > sqrt of number
		}
	}
	
	
	for(i=2;i<MAX_VAL;i++) {
		if(!np[i]) {
			pfact[i][i] = 1;
		} else {
			int copy = i;
			for(j=0;j<v[i].size();j++) {
				int cnt = 0;
				while(copy % v[i][j] == 0) {
					cnt++;
					copy/=v[i][j];
				}
				pfact[i][v[i][j]] = cnt;
			}
		}
	}
	/*
	 * printing code
	for(i=2;i<MAX_VAL;i++) {
		cout<<"number => "<< i<<endl;
		map<int, int> :: iterator it = pfact[i].begin();
		while(it != pfact[i].end()) {
			cout<<it->first<<" "<<it->second<<endl;
			it++;
		}
		cout<<"---------"<<endl;
	}
	*/
}

bool visited[MAX];
bool found;
void dfs(int node, int dest, vector<int> adj[MAX]) {
	visited[node] = true;
	
	if(node == dest) {
		found = true;
		return;
	}
	
	for(int i=0;i<adj[node].size();i++) {
		if(!visited[adj[node][i]]) {
			dfs(adj[node][i], dest, adj);
		}
		if(found) return;
	}
	
	visited[node] = false;
	return;
} 
	
int main() {
	int t, i, n, q, U, V;
	precompute();
	
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		vector<int> adj[MAX];
		for(i=1;i<n;i++) {
			scanf("%d %d", &U, &V);
			adj[U].pb(V);
			adj[V].pb(U);
		}
		
		int num[MAX];
		for(i=1;i<=n;i++) {
			scanf("%d", &num[i]);
		}
		
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d", &	U, &V);
			map<int, int> temp;
			memset(visited, false, sizeof visited);
			found = false;
			dfs(U, V, adj);
			
			for(i=1;i<=n;i++) {
				if(visited[i]) {
					map<int, int> :: iterator it = pfact[num[i]].begin();
					while(it != pfact[num[i]].end()) {
						temp[it->first] += it->second;
						it++;
					}
				}
			}
			
			LL ans = 1;
			map<int, int> :: iterator itt = temp.begin();
			while(itt != temp.end()) {
				//cout<<itt->first<<" "<<itt->second<<endl;
				ans = (ans * (1 + itt->second));
				if(ans >= MOD) ans %= MOD;
				itt++;
			}
			printf("%lld\n", ans);
		}
	}
    return 0;
}

