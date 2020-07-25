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

int dp[MAX][3];
vector<int> ans;
bool call(int pos, int col, int n, int *a) {
	if(pos == n-2) {
		if(a[n-1] != a[pos] && col == ans[n-1]) return false;
		ans[pos] = col;
		dp[pos][col] = 1;
		return true;
	}
	if(dp[pos][col] != -1) return (dp[pos][col] == 1);
	
	int nc = (col == 1) ? 2 : 1;
	bool possible = call(pos+1, nc, n, a);
	if(possible) {
		dp[pos][col] = 1;
		ans[pos] = col;
		return true;
	}
	
	if(a[pos] == a[pos+1]) {
		possible = call(pos+1, col, n, a);
		if(possible) {
			dp[pos][col] = 1;
			ans[pos] = col;
			return true;
		}
	}
	dp[pos][col] = 0;
	return false;
}

void solve() {
	int n;in(n);
	int a[n];
	ans.clear();
	ans.resize(n);
	bool same = true;
	for(int i=0;i<n;i++) {
		dp[i][1] = dp[i][2] = -1;
		in(a[i]);
		if(i>0 && a[i] != a[i-1]) same = false;
	}
	
	if(same) {
		cout<<1<<en;
		for(int i=0;i<n;i++) cout<<1<<" ";
		cout<<en;
		return ;
	}
	if(a[0] == a[n-1]) {
		cout<<2<<en;
		for(int i=0;i<n;i++) cout<<(i%2) + 1<<" ";
		cout<<en;
		return ;
	}
	
	ans[0] = 1; ans[n-1] = 2;
	bool possible = call(1, 2, n, a);
	if(!possible && a[1] == a[0]) {
		possible = call(1, 1, n, a);
	}
	
	if(possible) {
		cout<<2<<en;
		for(int i=0;i<n;i++) cout<<ans[i]<<" ";
		cout<<en;
		return ;
	}
	
	ans[n-1] = 3;
	cout<<3<<en;
	for(int i=0;i<n;i++) {
		if(i<n-1) cout<<(i%2 + 1)<<" ";
		else cout<<3;
	}
	cout<<en;
	
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
