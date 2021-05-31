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

void solve() {
	int n, u, v;
	LL w;
	in(n);
	LL xors[n+1];
	
	vector<pair<int, LL> > adj[n+1];
	for(int i=0;i<n-1;i++) {
		in2(u, v);inl(w);
		adj[u].PB(MP(v, w));
		adj[v].PB(MP(u, w));
	}
	
	queue<pair<int, LL> > q;
	bool vis[n+1];
	MSV(vis, false);
	
	q.push(MP(1, 0L));
	vis[1] = true;
	xors[1] = 0L;
	
	while(!q.empty()) {
		int node = q.front().X;
		LL x = q.front().Y;
		q.pop();
		
		for(int i=0;i<adj[node].size();i++) {
			if(!vis[adj[node][i].X]) {
				xors[adj[node][i].X] = x ^ adj[node][i].Y;
				q.push(MP(adj[node][i].X, xors[adj[node][i].X]));
				vis[adj[node][i].X] = true;
			}
		}
	}
	
	LL ans = 0;
	LL p = 1;
	for(int i=0;i<60;i++, p=p*2) {
		LL one = 0, zero = 0;
		for(int node=1;node<=n;node++) {
			if(xors[node] & p) one++;
			else zero++;
		}
		
		ans = (ans + (((one * zero) % MOD) * (p%MOD)) % MOD) % MOD;
	}
	
	cout<<ans<<en;
}

int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
