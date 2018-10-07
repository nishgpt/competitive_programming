#include <bits/stdc++.h>
using namespace std;
#define MOD 4294967296
#define LL long long int
 
LL cal(LL n) {
	if(n < 1) {
		return 0;
	}
	int a[64] = {0}, j = 0, i;
	LL f[64] = {0}, tp[64] = {0}, sum[64] = {0};
	LL k = 1, p = 1;
	for(i=63;i>=0;i--) {
		tp[i] = p;
		a[i] = n&1;
		f[i] = (a[i]*k)%MOD;
		if(j == 0)sum[i] = 1;
		else {
			sum[i] = ((2*sum[i+1])%MOD + (k*p)%MOD)%MOD;
		}
		n>>=1;
		p = (p*3)%MOD;
		if(i<63)f[i] = (f[i] + f[i+1])%MOD;
		k*=2;
		j++;
	}
	
	LL ans = 0;
	for(i=0;i<64;i++) {
		if(a[i] == 1) {
			if(i!=63) ans = (ans + sum[i+1])%MOD;
			if(i == 63) ans = (ans + 1)%MOD;
			else ans = (ans + (tp[i]*(f[i+1]+1))%MOD)%MOD;
		}
	}
	return ans;
}
 
int main() {
	int t;
	LL l, r;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld %lld",&l, &r);
		//cout<<cal(r)<<endl;
		printf("%lld\n", (cal(r) - cal(l-1) + MOD)%MOD);
	}
	return 0;
} 