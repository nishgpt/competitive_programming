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
 
typedef pair<int, int> pi;
 
int cost[MAX], n;
vector<pi> mincost(MAX);
int change[MAX];
vector<int> adj[MAX];
LL total = 0;
 
pi dfs(int node, int parent) {
	mincost[node] = MP(node, cost[node]);
	if(parent != -1 && mincost[parent].Y < mincost[node].Y) {
		mincost[node] = mincost[parent];
	}
	
	int z = 0, o = 0;
	for(int i=0;i<adj[node].size();i++) {
		if(parent != adj[node][i]) {
			pi res = dfs(adj[node][i], node);
			z += res.X;
			o += res.Y;
		}
	}
	if(change[node] == 0) z++;
	else if(change[node] == 1) o++;
	
	//if possible to resolve at this point
	if(mincost[node].X == node) {
		total += ((LL) 2 * min(z, o)) * mincost[node].Y;
		return MP(z-min(z, o), o-min(z, o));
	}
	
	return MP(z, o);
}
 
int main() {
	int u, v;
	
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%d %d %d", &cost[i], &u, &v);
		if(u == 0 && v == 1) change[i] = 0;
		else if(u == 1 && v == 0) change[i] = 1;
		else change[i] = -1;
	}
		
	for(int i=0;i<n-1;i++) {
		scanf("%d %d", &u, &v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	pi root_info = dfs(1, -1);
	
	if(root_info.X != root_info.Y) cout<<"-1"<<endl;
	else {
		total += ((LL) (root_info.X + root_info.Y)) * mincost[1].Y;
		cout<<total<<endl;
	}
 
    return 0;
}
