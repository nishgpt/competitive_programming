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
#define MAX 100
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

vector<int> adj[MAX];
bool dfs(int node, int d, int parent) {
	if(node == d) return true;
	
	bool possible = false;
	for(int i=0;i<adj[node].size();i++) {
		if(adj[node][i] != parent) possible = possible | dfs(adj[node][i], d, node);
	}
	return possible;
}

void solve() {
	int n;in(n);
	string inc, out;
	cin>>inc;
	cin>>out;
	
	for(int i=0;i<n;i++) adj[i].clear();
	
	for(int i=0;i<n;i++) {
		if(out[i] == 'N') continue;
		if(i-1 >= 0 && inc[i-1] == 'Y') adj[i].PB(i-1);
		if(i+1 < n && inc[i+1] == 'Y') adj[i].PB(i+1);
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(dfs(i, j, -1)) cout<<"Y";
			else cout<<"N";
		}
		cout<<en;
	}
}

int main() {
	int t = 1;
	
	cin>>t;
	for(int i=1;i<=t;i++) {
		cout<<"Case #"<<i<<":\n";
		solve();
	}
    return 0;
}
