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

vector<int> adj[MAX];
map<pi, LL> mp;
LL dfs(int node, int par, int n) {
	LL cnt = 1;
	for(int i=0;i<adj[node].size();i++) {
		if(adj[node][i] != par) {
			LL temp = dfs(adj[node][i], node, n);
			mp[MP(min(adj[node][i], node), max(adj[node][i], node))] = temp * (n-temp);
			cnt += temp;
		}
	}
	return cnt;
}

void solve() {
	int n;in(n);
	
	for(int i=0;i<n-1;i++) {
		int u, v;
		in2(u, v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	
	dfs(1, -1, n);
	map<pi, LL> :: iterator it = mp.begin();
	vector<LL> a;
	while(it != mp.end()) {
		a.PB(it->second);
		++it;
	}
	sort(a.rbegin(), a.rend());
	for(int i=0;i<a.size();i++) a[i] = a[i] % MOD;
	
	int m;in(m);
	vector<int> p(m);
	for(int i=0;i<m;i++) in(p[i]);
	sort(p.rbegin(), p.rend());
	
	LL ans = 0;
	if(m <= n-1) {
		for(int i=0;i<m;i++) ans = (ans + (a[i] * p[i]) % MOD) % MOD;
		for(int i=m;i<a.size();i++) ans = (ans + a[i]) % MOD;	
	}
	else {
		vector<int> pp;
		int extra = m-(n-1);
		LL extra_prod = 1;
		for(int i=0;i<=extra;i++) extra_prod = (extra_prod * p[i]) % MOD;
		
		pp.PB(extra_prod);
		for(int i=extra+1;i<m;i++) pp.PB(p[i]);
		for(int i=0;i<a.size();i++) ans = (ans + (a[i] * pp[i]) % MOD) % MOD;
	}
	
	cout<<ans<<en;
	
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
