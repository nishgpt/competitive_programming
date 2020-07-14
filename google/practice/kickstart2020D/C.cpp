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
#define MAX 500005
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
vector<LL> ax, bx;
vector<int> taken;

void dfs(int node, int step, bool isA) {
	taken.PB(node);
	for(int i=0;i<adj[node].size();i++) dfs(adj[node][i], step, isA);
	
	int sz = taken.size();
	if(isA) ax[node]++;
	else bx[node]++;
	
	if(sz - step >= 0) {
		if(isA) ax[taken[sz-step-1]] += ax[node];
		else bx[taken[sz-step-1]] += bx[node];
	}
	taken.pop_back();
}

void clear(int n) {
	ax.clear();bx.clear();
	for(int i=1;i<=n;i++) adj[i].clear();	
}

void solve() {
	LL n, a, b;
	inl(n);
	inl2(a, b);
	clear(n);
	
	for(int i=1;i<n;i++) {
		int x;in(x);
		adj[x].PB(i+1);
	}
	
	ax.resize(n+1, 0);
	dfs(1, a, true);
	bx.resize(n+1, 0);
	dfs(1, b, false);
	
	LL numerator = 0, denominator = n*n;
	for(int i=1;i<=n;i++) {
		numerator += ((ax[i] * (n-bx[i])) + ((n-ax[i]) * bx[i]) + ax[i]*bx[i]);
	}
	printf("%0.8lf\n", (1.0 * numerator) / denominator);
}

int main() {
	int t = 1;
	
	cin>>t;
	for(int i=1;i<=t;i++) {
		cout<<"Case #"<<i<<": ";
		solve();
	}
    return 0;
}
