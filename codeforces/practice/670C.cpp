/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 100005
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
#define in(x) scanf("%d", &x)
#define inl(x) scanf("%lld", &x)
#define in2(x, y) scanf("%d %d", &x, &y)
#define inl2(x, y) scanf("%lld %lld", &x, &y)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define finish(x) {cout<<x<<'\n'; return;}
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
const char en = '\n';

map<pi, int> mp;
vector<int> adj[MAX];
int dfs(int node, int par) {
	int cnt = 1;
	
	for(int i=0;i<adj[node].size();i++) {
		if(par == adj[node][i]) continue;
		int temp = dfs(adj[node][i], node);
		
		mp[MP(node, adj[node][i])] = temp;
		cnt += temp;
	}
	return cnt;
}

void solve() {	
	int n;in(n);
	int u, v;
	for(int i=0;i<n-1;i++) {
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	dfs(1, -1);
	
	vector<int> max_comp(n+1);
	for(int i=1;i<=n;i++) {
		int maxi = -1;
		for(int j=0;j<adj[i].size();j++) {
			if(mp.count(MP(i, adj[i][j]))) maxi = max(maxi, mp[MP(i, adj[i][j])]);
			else maxi = max(maxi, n - mp[MP(adj[i][j], i)]);
		}
		max_comp[i] = maxi;
	}
	
	vector<int> mnodes;
	int mini = INT_MAX;
	for(int i=1;i<=n;i++) {
		mini = min(mini, max_comp[i]);
	}
	for(int i=1;i<=n;i++) {
		if(mini == max_comp[i]) mnodes.PB(i);
	}
	
	if(mnodes.size() == 1) {
		cout<<mnodes[0]<<" "<<adj[mnodes[0]][0]<<en;
		cout<<mnodes[0]<<" "<<adj[mnodes[0]][0]<<en;
	}
	else {
		int node1 = mnodes[0];
		int node2 = mnodes[1];
		set<int> ch;
		for(int i=0;i<adj[node1].size();i++) {
			if(adj[node1][i] != node2) ch.insert(adj[node1][i]);
		}
		
		int found_node = -1;
		for(int i=0;i<adj[node2].size();i++) {
			if(adj[node2][i] != node1 && ch.find(adj[node2][i]) == ch.end()) {
				found_node = adj[node2][i];
				break;
			}
		}
		if(found_node == -1) raise(SIGABRT);
		
		cout<<node2<<" "<<found_node<<en;
		cout<<node1<<" "<<found_node<<en;
	}
	
	//clear off
	for(int i=1;i<=n;i++) adj[i].clear();
	mp.clear();
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
