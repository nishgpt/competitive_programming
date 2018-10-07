#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007
 
LL power(LL b, LL e, LL ans, LL mod) {
	if(!e) return ans%mod;
	if(e&1) ans = (ans*b)%mod;
	return power((b*b)%mod, e>>1, ans, mod);
}
 
LL fun(LL n) {
	if(n<=1) return 0;
	LL left = (n*(n+1))%MOD;
	left = left*(2*n+1)%MOD;
	left = (left*power(6, MOD-2, 1, MOD)) % MOD;
	
	LL right = n*(n+1)%MOD;
	right = (right * power(2, MOD-2, 1, MOD)) % MOD;
	LL ret = (left-right+MOD)%MOD;
	return (ret*power(2, MOD-2, 1, MOD))%MOD;
}
 
int main() {
	LL i, j, k, n, x, y, t;
 
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld", &x, &y);
		printf("%lld\n", (fun(y-1) - fun(x-2) + MOD) % MOD);
	}
	return 0;
} 