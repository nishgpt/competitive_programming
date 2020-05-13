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
int v[MAX]; //which set does any value belong to currently
int idx[MAX][MAX]; //which set contain what indexes
int values[MAX][MAX]; // which set contain what values
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
		for(int i=0;i<m;i++) {
			inp(x);inp(y);
			adj[x][y] = 1;
			adj[y][x] = 1;
		}
		
		//connected components
		MSV(visited, 0);
		for(int i=1;i<=n;i++) {
			if(!visited[i]) dfs(i, n, i);
		}
		
		MSV(idx, 0);
		MSV(values, 0);
		MSV(v, 0);
		for(int i=1;i<=n;i++) {
			int _set = visited[i];
			idx[_set][i] = 1;
			values[_set][a[i]] = 1;
			v[a[i]] = _set;
		}
		
		int _time = 0;
		
		//go for each value
		for(int i=1;i<=n;i++) {
			int curr_set = v[i];
			int target_set = visited[i];

			if(curr_set == target_set) continue;
			
			int replace_with = -1;
			int size_of_set = 0;
			for(int j=1;j<=n;j++) {
				if(idx[curr_set][j] == 1) size_of_set++;
				if(values[target_set][j] == 1 && idx[target_set][j] != 1 && idx[curr_set][j] == 1) {
					replace_with = j;
					break;
				}
			}
			
			if(replace_with == -1 && size_of_set > 1) {
				for(int j=1;j<=n;j++) {
					if(values[target_set][j] == 1 && idx[target_set][j] != 1) {
						replace_with = j;
						break;
					}
				}
			}
			
			//cout<<"replacing values => "<<i<<" "<<replace_with<<endl;
			
			values[curr_set][i] = 0;
			values[target_set][i] = 1;
			values[curr_set][replace_with] = 1;
			values[target_set][replace_with] = 0;
			v[i] = target_set;
			v[replace_with] = curr_set;
			
			_time++;
		}
		
		for(int i=1;i<=n;i++) {
			if(v[i] != visited[i]) raise(SIGABRT);
		}
		
		cout<<_time<<endl;
	}

    return 0;
}

