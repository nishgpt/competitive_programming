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

vector<int> adj[MAX];
int st, e;
int vis[MAX];
int cnt;int offset;
void dfs(int node, int p) {
	if(vis[node]) {
		st = node;
		e = p;
		offset = vis[node] - 1;
		return;
	}
	
	vis[node] = cnt++;
	
	for(int i=0;i<adj[node].size();i++) {
		dfs(adj[node][i], node);
	}
	return;
}

vector<int> chain;
void get_chain(int node, int dest) {
	if(node == dest) {
		chain.PB(dest);
		return;
	}
	
	chain.PB(node);
	for(int i=0;i<adj[node].size();i++) {
		get_chain(adj[node][i], dest);
	}
}

int main() {
	LL n, k; int i;
	cin>>n>>k;
	
	int x;
	for(i=1;i<=n;i++) {
		cin>>x;
		adj[i].PB(x);
	}
	cnt = 1;
	
	dfs(1, 1);

	
	if(k < offset) {
		get_chain(1, st);
		cout<<chain[k]<<endl;
		return 0;
	}
	k-=offset;
	get_chain(st, e);
	int cn = chain.size();
	k = k % cn;
	
	
	cout<<chain[k]<<endl; 
	
    return 0;
}

