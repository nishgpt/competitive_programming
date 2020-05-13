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
#define MAX 19
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

int adj[MAX][MAX];
int visited[MAX];
int solve(int *a, int n) {
	int pos[n+1];
	for(int i=1;i<=n;i++) {
		pos[a[i]] = i;
	}
	int curr = 0;
	int _time = 0;
	while(curr < n) {
		++curr;
		if(curr == pos[curr]) continue;
		
		int i1 = pos[curr];
		int i2 = curr;
		
		int temp = a[i1];
		a[i1] = a[i2];
		a[i2] = temp;
		pos[temp] = i2;
		pos[a[i1]] = i1;
		if(visited[i1] != visited[i2]) _time++;
	}
	
	return _time;
}

void dfs(int node, int n, int x) {
	visited[node] = x;
	
	for(int i=1;i<=n;i++) {
		if(!visited[i] && adj[node][i]==1) {
			dfs(i, n, x);
		}
	}
}

int main() {
	int t;
	int n, m, x, y;
	inp(t);
	
	//Solving for 1st subtask
	while(t--) {
		inp(n);inp(m);
		int a[n+1];
		for(int i=1;i<=n;i++) {
			inp(a[i]);
		}
		
		MSV(adj, 0);
		vector<pair<int, int> > robots;
		for(int i=0;i<m;i++) {
			inp(x);inp(y);
			robots.PB(MP(x, y));
			adj[x][y] = 1;
			adj[y][x] = 1;
		}
		
		int r = robots.size();
		if(r >= n-1) {
			cout<<0<<endl;
			continue;
		}
		
		//connected components
		memset(visited, 0, sizeof visited);
		for(int i=1;i<=n;i++) {
			if(!visited[i]) dfs(i, n, i);
		}
		
		bool f = true;
		for(int i=2;i<=n;i++) {
			if(visited[i] != visited[i-1]) {
				f=false;
				break;
			}
		}
		
		if(f) {
			cout<<0<<endl;
			continue;
		}
		int acopy1[n+1];
		memcpy(&acopy1, &a, sizeof a);
		int ans = solve(acopy1, n);
		//~cout<<ans<<endl;
		for(int i=0;i<(1<<r);i++) {
			vector<int> v;
			
			for(int j=0;j<r;j++) {
				if(i&(1<<j)) {
					v.PB(j);
				}
			}
			
			do {
				int acopy[n+1];
				memcpy(&acopy, &a, sizeof a);
				vector<pair<int, int> > moves;
				
				//perform the robots operations
				for(int k = 0;k<v.size();k++) {
					int i1 = robots[v[k]].X;
					int i2 = robots[v[k]].Y;
					moves.PB(MP(i1, i2));
					swap(acopy[i1], acopy[i2]);
				}
				ans = min(ans, solve(acopy, n));
			} while(next_permutation(v.begin(), v.end()));
		}
		cout<<ans<<endl;
	}

    return 0;
}
