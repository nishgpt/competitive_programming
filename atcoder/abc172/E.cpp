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

/* Factorial modulo MOD */
LL fact[MAX];
void factorial() {
	fact[0] = 1;
	for(int i=1;i<MAX;i++) {
		fact[i] = (i * fact[i-1]) % MOD;
	}
}

/* Modulo exponentiation */
LL power(LL base, LL exp, LL ans) {
	if(!exp) return ans % MOD;
	if(exp&1) ans = (ans * base) % MOD;
	return power((base * base) % MOD, exp>>1, ans);
}

/* nCr modulo MOD */
LL nCr(LL n, LL r) {
	if(n < r) return 0;
	LL numerator = fact[n];
	LL denominator = (fact[n-r] * fact[r]) % MOD;
	return (numerator * power(denominator, MOD-2, 1)) % MOD;
}

LL derrangement(LL n) {
	LL f = fact[n];
	LL derr = 0;
	for(int i=0;i<=n;i++) {
		LL x = power(fact[i], MOD-2, 1);
		LL sign = (i % 2 == 0) ? 1 : -1;
		derr = (derr + sign * x);
		if(sign == -1) derr = derr + MOD;
		derr = derr % MOD;
	}
	//~chk(derr);
	return (derr * f) % MOD;
}

void pre() {
	factorial();
}

void solve() {
	LL n, m;
	inl2(n, m);
	
	LL npr = (nCr(m, n) * fact[n]) % MOD;
	
	LL y = 0;
	for(int i=0;i<=m-n;i++) {
		LL x1 = (nCr(m-n, i) * nCr(n, i)) % MOD;
		y = (y + x1) % MOD;
	}
	y = (y * derrangement(n)) % MOD;
	LL ans = (npr * y) % MOD;
	cout<<ans<<en;
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
