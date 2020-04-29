/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define getcx getchar_unlocked
#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define MAX 200005
#define MOD 163577857
#define INF 0x3f3f3f3f
#define INFL (LL(1e18))
#define rep(i, a, n) for(i=a;i<n;i++)
#define rev(i, a, n) for(i=a;i>=n;i--)
#define MSV(A,a) memset(A, a, sizeof(A))
#define rep_itr(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)

using namespace std;

inline void inp( int &n ) { 
	n=0;    int ch=getcx();int sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

inline void inp1( LL &n ) { 
	n=0;    LL ch=getcx();LL sign=1;   
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();} 
	while(  ch >= '0' && ch <= '9' )    
	n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

LL fact[MAX];
void factorial() {
	fact[0] = 1;
	for(int i=1;i<MAX;i++) {
		fact[i] = (i * fact[i-1]) % MOD;
	}
}

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

int main() {
	int t, n;
	factorial();
	inp(t);
	
	while(t--) {
		inp(n);
		int a[n];
		
		int o = 0, mo = 0, z = 0;
		for(int i=0;i<n;i++) {
			inp(a[i]);
			if(a[i] == -1) mo++;
			else if(a[i] == 0) z++;
			else o++;
		}
		
		LL all_zero = power(2, z, 1);
		for(int i=-n;i<=n;i++) {
			if(i < 0) {
				cout<<(all_zero * nCr(mo+o, o - i)) % MOD<<" ";
			}
			
			else if(i == 0) {
				LL ans = (all_zero - 1 + MOD) % MOD;
				LL temp = (nCr(mo+o, o) - 1 + MOD) % MOD;
				ans = (ans + (temp * all_zero) % MOD) % MOD;
				cout<<ans<<" ";
			}
			
			else {
				cout<<(all_zero * nCr(mo+o, mo+i)) % MOD<<" ";
			}
		}
		cout<<endl;
	}
    return 0;
}

