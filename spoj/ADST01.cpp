#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define MS(a) memset(a, 0, sizeof a)
#define M 1000000
 
LL power(LL b, LL e, LL ans, LL mod) {
	if(!e) return ans%mod;
	if(e&1) ans = (ans*b)%mod;
	return power((b*b)%mod, e/2, ans, mod);
}
 
int main() {
	int t, i, j;
	scanf("%d", &t);
	LL n;
	while(t--) {
		scanf("%lld", &n);
		LL num = (power(10, n, 1, MOD) - 1 + MOD)%MOD;
		num = (num * 10)%MOD;
		num = (num * power(9, MOD-2, 1, MOD))%MOD;
		num = (num - n + MOD)%MOD;
		num = (num * 5)%MOD;
		num = (num * power(9, MOD-2, 1, MOD))%MOD;
		num = (num + n)%MOD;
		printf("%lld\n", num);
	}
	return 0;
} 