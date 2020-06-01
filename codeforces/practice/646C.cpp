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
#define MAX 1005
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

int dfs(int node, vector<int> adj[MAX], bool vis[MAX]) {
	vis[node] = true;
	
	int cnt = 0;
	for(int i=0;i<adj[node].size();i++) {
		if(vis[adj[node][i]] == false) {
			cnt+= (dfs(adj[node][i], adj, vis)+1);
		}
	}
	return cnt;
}

int main() {
	int t, u, v, n, x;
	cin>>t;
	
	while(t--) {
		cin>>n>>x;
		vector<int> adj[MAX]; 
		bool vis[MAX] = {false};
		
		for(int i=0;i<n-1;i++) {
			cin>>u>>v;
			adj[u].PB(v);
			adj[v].PB(u);
		}
		
		if(adj[x].size() <= 1) cout<<"Ayush"<<endl;
		else if(dfs(x, adj, vis)&1) cout<<"Ayush"<<endl;
		else cout<<"Ashish"<<endl;
	}

    return 0;
}

