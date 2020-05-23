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
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl
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

typedef pair<int, int> pi; 

int dijkstra(int s, int d, vector<pi> adj[MAX]) {
	int mincost[MAX], i;
	rep(i, 0, MAX) mincost[i] = INF;
	
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push(MP(0, s));
	mincost[s] = 0;
	
	while(!pq.empty()) {
		pi _top = pq.top();
		pq.pop();
		int node = _top.Y;
		
		for(i=0;i<adj[node].size();i++) {
			int ch = adj[node][i].X;
			int wt = adj[node][i].Y;
			if(mincost[node] + wt < mincost[ch]) {
				mincost[ch] = mincost[node] + wt;
				pq.push(MP(mincost[ch], ch));
			} 
		}
	}
	
	return mincost[d];
}

int main() {
	int n, m, i, j;
	cin>>n>>m;
	
	string s[n];
	
	for(i=0;i<n;i++) {
		cin>>s[i];
	}
	
	vector<pi> adj[MAX];
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			int node = i*m + j;
			if(j+1 < m) {
				if(s[i][j] == '.' && s[i][j+1] == '#') adj[node].PB(MP(i*m+j+1, 1));
				else adj[node].PB(MP(i*m+j+1, 0));
			}
			
			if(i+1 < n) {
				if(s[i][j] == '.' && s[i+1][j] == '#') adj[node].PB(MP((i+1)*m+j, 1));
				else adj[node].PB(MP((i+1)*m+j, 0));
			}
		}
	}
	
	cout<<dijkstra(0, (n*m-1), adj) + (s[0][0] == '#')<<endl;
		
    return 0;
}

