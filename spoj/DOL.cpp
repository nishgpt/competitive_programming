#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
 
int main() {
	int t, k=1;
	scanf("%d", &t);
	while(t--) {
		LL n;
		scanf("%lld", &n);
		while(!(n&1)) {
			n/=2;
		}
		printf("Case %d: %lld\n", k++, n);
	}
	return 0;
} 