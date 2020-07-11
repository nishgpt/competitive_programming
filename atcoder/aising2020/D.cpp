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

/* Modulo exponentiation */
LL power(LL base, LL exp, LL ans, LL mod) {
	if(!exp) return ans % mod;
	if(exp&1) ans = (ans * base) % mod;
	return power((base * base) % mod, exp>>1, ans, mod);
}

int dp[MAX];
void pre() {
	MSV(dp, -1);
	dp[0] = 0;
	for(int i=1;i<MAX;i++) {
		int cnt = 0, copy = i;
		while(true) {
			int sb = __builtin_popcount(copy);
			int x = copy % sb;
			cnt++;
			if(dp[x] != -1) {cnt += dp[x];break;}
			copy = x;
		}
		dp[i] = cnt;
	}
}

void solve() {
	int n;
	in(n);
	string s;
	cin>>s;
	int sb = 0;
	for(int i=0;i<n;i++) {
		sb += (s[i] == '1');
	}
	
	int p = 0;
	LL mod1 = 0, mod2 = 0;
	for(int i=n-1;i>=0;i--,p++) {
		if(s[i] == '0') continue;
		if(sb>1)mod1 = (mod1 + power(2, p, 1, sb-1)) % (sb-1);
		mod2 = (mod2 + power(2, p, 1, sb+1)) % (sb+1);
	}
	
	LL ans[n];
	p = 0;
	for(int i=n-1;i>=0;i--,p++) {
		if(s[i] == '1') {
			if(sb - 1 == 0) {ans[i] = 0;continue;}
			LL now = (mod1 - power(2, p, 1, sb-1) + (sb-1)) % (sb-1);
			//assert for now?
			ans[i] = dp[now] + 1;
		}
		else {
			LL now = (mod2 + power(2, p, 1, sb+1)) % (sb+1);
			ans[i] = dp[now] + 1;
		}
	}
	
	for(int i=0;i<n;i++) {
		cout<<ans[i]<<en;
	}
}

int main() {
	int t = 1;
	pre();
	//~cin>>t;
	while(t--) {
		solve();
	}
    return 0;
}
