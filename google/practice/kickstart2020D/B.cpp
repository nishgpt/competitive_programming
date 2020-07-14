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
#define MAX 10005
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

int dp[MAX][5];
vector<int> a;
int call(int pos, int curr, int n) {
	if(pos == n-1) return 0;
	if(dp[pos][curr] != -1) return dp[pos][curr];
	
	int ans = 1e7;
	if(a[pos+1] > a[pos]) {
		//dont break rule
		for(int i=curr+1;i<=4;i++) ans = min(ans, call(pos+1, i, n));
		//break the rule
		for(int i=1;i<curr;i++) ans = min(ans, 1 + call(pos+1, i, n));
	}
	else if(a[pos+1] < a[pos]) {
		//break the rule
		for(int i=curr+1;i<=4;i++) ans = min(ans, 1 + call(pos+1, i, n));
		//dont break rule
		for(int i=1;i<curr;i++) ans = min(ans, call(pos+1, i, n));
	}
	else {
		//dont break the rule
		ans = min(ans, call(pos+1, curr, n));
		//break the rule
		for(int i=1;i<=4;i++) if(i != curr) ans = min(ans, 1 + call(pos+1, i, n));
	}
	
	return dp[pos][curr] = ans;
}

void solve() {
	int n;in(n);
	a.clear();
	a.resize(n);
	for(int i=0;i<n;i++) {
	    in(a[i]);
	    for(int j=0;j<5;j++) dp[i][j] = -1;
	}
	
	int ans = 1e7;
	for(int i=1;i<=4;i++) ans = min(ans, call(0, i, n));
	cout<<ans<<en;
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
