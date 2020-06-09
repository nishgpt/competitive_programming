/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 200005
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
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;

vector<int> adj[MAX];
int a[MAX];
int ans[MAX];
int final_ans[MAX];
int dfs(int node, int parent) {
	int own = (a[node] == 0) ? -1 : 1;
	ans[node] = own;
	for(int i=0;i<adj[node].size();i++) {
		if(parent != adj[node][i]) ans[node] += max(0, dfs(adj[node][i], node));
	}
	return ans[node];
}

void reverse(int node, int parent) {
	final_ans[node] = ans[node];
	for(int i=0;i<adj[node].size();i++) {
		if(parent != adj[node][i]) {
			ans[node] -= max(0, ans[adj[node][i]]);
			ans[adj[node][i]] += max(0, ans[node]);
			reverse(adj[node][i], node);
			ans[adj[node][i]] -= max(0, ans[node]);
			ans[node] += max(0, ans[adj[node][i]]);
		}
	}
}

void solve() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	
	int u, v;
	for(int i=0;i<n-1;i++) {
		scanf("%d %d", &u, &v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	dfs(1, -1);
	reverse(1, -1);
	
	for(int i=1;i<=n;i++) {
		printf("%d ", final_ans[i]);
	}
	printf("\n");
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
