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

int bits[300005], power[MAX];
void pre() {
	int bcnt=1;
	int p = 2;
	for(int i=0;i<300005;i++) {
		if(i==p) {
			p = p*2;
			bcnt++;
		}
		bits[i] = bcnt;
	}
	
	power[0] = 1;
	for(int i=1;i<MAX;i++) {
		power[i] = 2 * power[i-1];
	}
}

unordered_map<string, Value> dp;
int func_calls, key_hits;
int set_num[MAX];
Value call(int n, string key, int num) { //num is non matching numbers composed
	//func_calls++;
	//if all in correct sets
	if(!num) {
		Value zero;
		zero.value = 0;
		dp[key] = zero;
		return dp[key];
	}
	
	int ans = INT_MAX;
	//call
	string key1 = key;
	int temp; char x;
	int reserve = num;
	
	while(num) {
		int copy = reserve;
		int pidx = bits[num];
		int i = n - pidx + 1; //i is the number we are going forward for swapping
		int inner = set_num[visited[i]]; //visited[i] is the set where i needs to go to, hence set_num[visited[i]] is the composed number of elements in that set
		copy = copy - power[pidx - 1];
		set_num[v[i]] -= power[pidx - 1]; //remove from current set
		set_num[visited[i]] += power[pidx - 1]; //add in target set
		while(inner) {
			int idx = bits[inner];
			int j = n - idx + 1;
			if(v[j] != visited[j]) {
				set_num[v[j]] -= power[idx - 1]; //remove from current set
				set_num[v[i]] += power[idx - 1];
				temp = v[j], v[j] = v[i], v[i] = temp;
				x = key1[i-1], key1[i-1] = key1[j-1], key1[j-1] = x;
				
				bool both = false;
				if(v[j] == visited[j]) {
					both = true;
					copy = copy - power[idx - 1];
				}
				
				if(dp[key1].value == -1) ans = min(ans, 1 + call(n, key1, copy).value);
				else {
					ans = min(ans, 1 + dp[key1].value);
				}
								
				if(both) copy = copy + power[idx - 1];
				temp = v[j], v[j] = v[i], v[i] = temp;
				x = key1[i-1], key1[i-1] = key1[j-1], key1[j-1] = x;
				set_num[v[i]] -= power[idx - 1];
				set_num[v[j]] += power[idx - 1];
			}
			inner = inner - power[idx - 1];
		}
		
		set_num[visited[i]] -= power[pidx - 1];
		set_num[v[i]] += power[pidx - 1];
		num = num - power[pidx - 1];
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
	pre();
	
	while(t--) {
		dp.clear();
		inp(n);inp(m);
		int a[n+1];
		int pos[n+1];
		for(int i=1;i<=n;i++) {
			inp(a[i]);
			pos[a[i]] = i;
		}
		
		MSV(adj, 0);
		for(int i=0;i<m;i++) {
			inp(x);inp(y);
			adj[x][y] = 1;
			adj[y][x] = 1;
		}
		
		if(m == 0) {
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
				_time++;
			}
			cout<<_time<<endl;
			continue;
		}
		
		//connected components
		MSV(visited, 0);
		for(int i=1;i<=n;i++) {
			if(!visited[i]) dfs(i, n, i);
		}
		
		//init some data structures
		MSV(v, 0);
		for(int i=1;i<=n;i++) {
			v[a[i]] = visited[i];
		}
		
		int till_now = 0;
		for(int i=1;i<=n;i++) {
			if(v[i] != visited[i]) {
				for(int j=1;j<=n;j++) {
					if(v[j] != visited[j] && v[i] == visited[j] && v[j] == visited[i]) {
						//cout<<"swapping "<<i<<" "<<j<<endl;
						swap(v[i], v[j]);
						till_now++;
						break;
					}
				}
			}
		}
		
		string key;
		int number = 0;
		MSV(set_num, 0);
		for(int i=1;i<=n;i++) {
			if(v[i] != visited[i]) number += power[n-i];
			key = key + (char) (v[i]+'a');
			set_num[v[i]] += power[n-i];
		}
		// cout<<number<<"dnld"<<endl;
		//key_hits = 0, func_calls = 0;
		cout<<till_now + call(n, key, number).value<<endl;
		//cout<<"func calls => "<<func_calls<<", keyh its=> "<<key_hits<<", dp size=> "<<dp.size()<<endl;
	}

    return 0;
}
