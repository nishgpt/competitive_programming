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
int idx[MAX][MAX]; //which set contain what indexes
int values[MAX][MAX]; // which set contain what values
int visited[MAX]; //to tell which set does ith index belongs to
int v[MAX]; //which set does any value belong to currently
void dfs(int node, int n, int x) {
	visited[node] = x;
	
	for(int i=1;i<=n;i++) {
		if(!visited[i] && adj[node][i]==1) {
			dfs(i, n, x);
		}
	}
}

struct Value
{
    int value = -1;
};

map<string, Value> dp;

int func_calls, key_hits;
Value call(int n, string key, int match) {
	//if all in correct sets
	if(match == n) {
		Value zero;
		zero.value = 0;
		dp[key] = zero;
		return dp[key];
	}
	
	int ans = INT_MAX;
	
	//call
	string key1 = key;
	int temp, i; char x;
	for(i=1;i<=n;i++) {
		//if already in proper set, no-op
		if(v[i] == visited[i]) continue;
		bool both_matching = false;
		
		for(int j=1;j<=n;j++) {
			if(v[j] == visited[i] && v[j] != visited[j]) {
				temp = v[j], v[j] = v[i], v[i] = temp;
				x = key1[i-1], key1[i-1] = key1[j-1], key1[j-1] = x;
				
				int inc = 1;
				if(v[j] == visited[j]) { //will just swap these and leave
					both_matching = true;
					if(dp[key1].value == -1) ans = min(ans, 1 + call(n, key1, match + inc + 1).value);
					else ans = min(ans, 1 + dp[key1].value);
				}
				
				temp = v[j], v[j] = v[i], v[i] = temp;
				x = key1[i-1], key1[i-1] = key1[j-1], key1[j-1] = x;
				if(both_matching) break;
			}
		}
		
		if(both_matching) continue;
		
		for(int j=1;j<=n;j++) {
			if(v[j] == visited[i] && v[j] != visited[j]) {
				temp = v[j], v[j] = v[i], v[i] = temp;
				x = key1[i-1], key1[i-1] = key1[j-1], key1[j-1] = x;
				
				if(dp[key1].value == -1) ans = min(ans, 1 + call(n, key1, match + 1).value);
				else {
					ans = min(ans, 1 + dp[key1].value);
				}
				
				temp = v[j], v[j] = v[i], v[i] = temp;
				x = key1[i-1], key1[i-1] = key1[j-1], key1[j-1] = x;
			}
		}
	}
	
	Value final_ans;
	final_ans.value = ans;
	dp[key] = final_ans;
	return dp[key];
}

int main() {
	int t;
	int n, m, x, y;
	inp(t);
	
	while(t--) {
		dp.clear();
		inp(n);inp(m);
		int a[n+1];
		for(int i=1;i<=n;i++) inp(a[i]);
		
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
		
		//init some data structures
		MSV(idx, 0);
		MSV(values, 0);
		MSV(v, 0);
		for(int i=1;i<=n;i++) {
			int _set = visited[i];
			idx[_set][i] = 1;
			values[_set][a[i]] = 1;
			v[a[i]] = _set;
		}
		
		string key;
		int match  = 0;
		for(int i=1;i<=n;i++) {
			if(v[i] == visited[i]) match++;
			key = key + (char) (v[i]+'a');
		}
		
		key_hits = 0, func_calls = 0;
		cout<<call(n, key, match).value<<endl;
		//~cout<<"func calls => "<<func_calls<<", keyh its=> "<<key_hits<<", dp size=> "<<dp.size()<<endl;
	}

    return 0;
}
