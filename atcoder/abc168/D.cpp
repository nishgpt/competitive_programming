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
int main() {
	int n, m, x, y, i;
	cin>>n>>m;
	
	for(i=0;i<m;i++) {
		inp(x);inp(y);
		adj[x].PB(y);
		adj[y].PB(x);
	}
	
	int p[n+1];
	MSV(p, -1);
	queue<int> q;
	q.push(1);
	p[1] = 1;
	
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		
		for(i=0;i<adj[node].size();i++) {
			if(p[adj[node][i]] == -1) {
				q.push(adj[node][i]);
				p[adj[node][i]] = node;
			}
		}
	}
	bool f = true;
	for(i=2;i<=n;i++) {
		if(p[i] == -1) {f= false; break;}
	}
	
	if(f) {
		printf("Yes\n");
		for(i=2;i<=n;i++) printf("%d\n", p[i]);
	} else printf("No\n");
		
    return 0;
}

