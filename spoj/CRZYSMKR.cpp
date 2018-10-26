#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007

int main() {
	LL i, j, k, n, m;
	cin>>m;
	while(m--) {
		scanf("%lld", &n);
		n = n%11;
		k = (33 + 30*n)%11;
		k = 11-k;
		k = k%11;
		printf("%lld\n", k);
	}
	return 0;
}