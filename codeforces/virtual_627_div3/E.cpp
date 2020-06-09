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
#define MAX 2005
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
typedef pair<int, int> pi;
typedef pair<LL, LL> pl;
 
int dp[MAX][MAX];
int solve(int curr, int pos, int a[], int n, int h, int l, int r) {
	if(pos == n) return (curr >= l && curr <= r);
	if(dp[curr][pos] != -1) return dp[curr][pos];
	
	int ans = (curr >= l && curr <= r) && pos != 0;
	
	dp[curr][pos] = ans + max(solve((curr + a[pos]) % h, pos+1, a, n, h, l, r), solve((curr + a[pos] - 1 +h) % h, pos+1, a, n, h, l, r));
	return dp[curr][pos]; 
}
 
void solve() {
	int n, h, l, r;
	cin>>n>>h>>l>>r;
	
	int a[n];
	for(int i=0;i<n;i++)  cin>>a[i];
	MSV(dp, -1);
	cout<<max(0, solve(0, 0, a, n, h, l, r))<<endl;
}
 
int main() {
	int t = 1;
	
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
