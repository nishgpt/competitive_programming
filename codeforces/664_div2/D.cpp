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
	LL n, d, m;
	inl2(n, d);inl(m);
	LL x;
	vector<LL> g(n, 0), l(n, 0);
	for(int i=0;i<n;i++) {
		inl(x);
		if(x > m) g[i] = x;
		else l[i] = x;
	}
	sort(g.rbegin(), g.rend());
	sort(l.rbegin(), l.rend());
	
	for(int i=1;i<l.size();i++) l[i] += l[i-1];
	for(int i=1;i<g.size();i++) g[i] += g[i-1];
	l.insert(l.begin(), 0);
	g.insert(g.begin(), 0);
	
	LL ans = 0;
	for(int i=0;i<=n;i++) {
		int g_items = (i+d) / (d+1);
		ans = max(ans, g[g_items] + l[n-i]);
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
