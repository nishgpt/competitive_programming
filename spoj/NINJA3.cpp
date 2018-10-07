#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define MS(a) memset(a, 0, sizeof a)
#define inp(a) scanf("%d", &a)
#define inpll(a) scanf("%lld", &a)
 
int main() {
	LL i, t, k, n, a, b;
	inpll(t);
	while(t--) {
		inpll(n);inpll(a);inpll(b);
		k = __gcd(a, b);
		for(i=0;i<k;i++) {
			cout<<n;
		}
		cout<<endl;
	}
	return 0;
} 