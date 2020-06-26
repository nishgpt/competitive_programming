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

LL dp[MAX][3][2];
LL call(int pos, int x, LL a[], int n, int fl) {
	if(pos >= n) return 0;
	if(dp[pos][x][fl] != -1) return dp[pos][x][fl];
	
	LL ans = -1;
	if(x == 0) {
		//keep going
		ans = max(ans, a[pos] + call(pos+2, x, a, n, fl));

		//shift from now only fl = 1 or from next fl = 0
		if(pos + 1 < n) ans = max(ans, call(pos+1, 1, a, n, 1));
		if(pos + 2 < n) ans = max(ans, a[pos] + call(pos+1, 1, a, n, 0));
	}
	
	else if(x == 1) {
		//keep going
		if(fl) ans = max(ans, a[pos] + call(pos+2, x, a, n, fl));
		else if(pos + 3 < n) ans = max(ans, a[pos] + call(pos+2, x, a, n, fl));

		//shift again
		if(fl) ans = max(ans, a[pos] + call(pos+1, 2, a, n, fl));
		else ans = max(ans, a[pos] + call(pos+3, 2, a, n, fl)); 
	}
	else {
		//keep going
		ans = max(ans, a[pos] + call(pos+2, x, a, n, fl));
	}
	return dp[pos][x][fl] = ans;
}

void solve() {
	int n;
	in(n);
	LL a[n];
	for(int i=0;i<n;i++) {
		inl(a[i]);
		for(int j=0;j<3;j++) for(int k=0;k<2;k++) dp[i][j][k] = -1;
	}
	
	cout<<call(0, 0, a, n, 0)<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
