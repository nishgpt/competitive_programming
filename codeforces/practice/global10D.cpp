//WA - TODO:: Rectify
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

int dp[MAX][2];
int get_num(char c) {
	return c == 'L' ? 1 : 0;
}

int get_value(int l, int c, int n) {
	return (l<<2) + (c<<1) + n;
}

int call(int pos, int last, int n, string &s) {
	if(pos == n) return 0;
	if(dp[pos][last] != -1) return dp[pos][last];
	
	int ans = 1e9;
	int curr = get_num(s[pos]);
	int next = (pos+1 < n) ? get_num(s[pos+1]) : get_num(s[0]);
	int val = get_value(last, curr, next);
	
	if(val == 0) ans = min(ans, 1+call(pos+1, 1, n, s));
	else if(val == 1) {
		ans = min(ans, call(pos+1, 0, n, s));
		ans = min(ans, 1+call(pos+1, 1, n, s)); 
	}
	else if(val == 2) ans = min(ans, call(pos+1, 1, n, s));
	else if(val == 3) {
		ans = min(ans, call(pos+1, 1, n, s));
		ans = min(ans, 1+call(pos+1, 0, n, s));
	}
	else if(val == 4) {
		ans = min(ans, call(pos+1, 0, n, s));
		ans = min(ans, 1+call(pos+1, 1, n, s));
	}
	else if(val == 5) ans = min(ans, call(pos+1, 0, n, s));
	else if(val == 6) {
		ans = min(ans, call(pos+1, 1, n, s));
		ans = min(ans, 1+call(pos+1, 0, n, s));
	}
	else ans = min(ans, 1+call(pos+1, 0, n, s));
	
	return dp[pos][last] = ans;
}

void solve() {
	int n;in(n);
	for(int i=0;i<n;i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	string s;
	cin>>s;
	cout<<call(0, get_num(s[n-1]), n, s)<<en;
}

int main() {
	int t = 1;
	
	cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
