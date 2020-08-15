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
#define MAX 3005
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
 
LL dp[MAX][MAX][4];
LL a[MAX][MAX];
 
LL _max(LL n1, LL n2) {
	if(n1 > n2) return n1;
	return n2;
}
 
void solve() {
	int r, c, k;
	in2(r, c);in(k);
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			a[i][j] = 0;
			for(int x=0;x<4;x++) dp[i][j][x] = 0;
		}
	}
			
	for(int i=0;i<k;i++) {
		int x,y;
		LL v;
		in2(x, y);inl(v);
		a[x-1][y-1] = v;
	}
	
	dp[0][0][1] = a[0][0];
	for(int j=1;j<c;j++) {
		dp[0][j][0] = dp[0][j-1][0];
		dp[0][j][1] = _max(dp[0][j-1][1], a[0][j]!=0 ? (dp[0][j-1][0] + a[0][j]) : 0);
		dp[0][j][2] = _max(dp[0][j-1][2], a[0][j]!=0 ? (dp[0][j-1][1] + a[0][j]) : 0);
		dp[0][j][3] = _max(dp[0][j-1][3], a[0][j]!=0 ? (dp[0][j-1][2] + a[0][j]) : 0);
	}
	
	for(int i=1;i<r;i++) {
		LL maxi = 0;
		for(int x=0;x<4;x++) maxi = max(dp[i-1][0][x], maxi);
		dp[i][0][0] = dp[i-1][0][0];
		dp[i][0][1] = _max(dp[i-1][0][1], a[i][0]!=0 ? maxi + a[i][0] : 0);
		dp[i][0][2] = _max(dp[i-1][0][2], a[i][0]!=0 ? (dp[i-1][0][1] + a[i][0]) : 0);
		dp[i][0][3] = _max(dp[i-1][0][3], a[i][0]!=0 ? (dp[i-1][0][2] + a[i][0]) : 0);
	}
	
	for(int i=1;i<r;i++) {
		for(int j=1;j<c;j++) {
			LL maxi = 0;
			for(int x=0;x<4;x++) maxi = _max(maxi, dp[i-1][j][x]);
			
			dp[i][j][0] = _max(maxi, dp[i][j-1][0]);
			if(a[i][j]!=0) {
				dp[i][j][1] = _max(maxi+a[i][j], dp[i][j-1][0]+a[i][j]);
				dp[i][j][2] = dp[i][j-1][1]+a[i][j];
				dp[i][j][3] = dp[i][j-1][2]+a[i][j];
			}
			dp[i][j][1] = _max(dp[i][j][1], dp[i][j-1][1]);
			dp[i][j][2] = _max(dp[i][j][2], dp[i][j-1][2]);
			dp[i][j][3] = _max(dp[i][j][3], dp[i][j-1][3]);
		}
	}
	
	LL ans = 0;
	for(int x=0;x<4;x++) ans = _max(ans, dp[r-1][c-1][x]);
	
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
