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
	int i, j, k, n, t;
	inp(t);
	while(t--) {
		inp(n);
		LL a[n];
		for(i=0;i<n;i++) {
			inpll(a[i]);
		}
		LL b[n];
		for(i=0;i<n;i++) {
			inpll(b[i]);
		}
 
		LL last	= -1; int flag = 0;
		for(i=0;i<n;i++) {
			if(a[i] >= last && b[i] >= last) {
				last = min(a[i], b[i]);
			}
			else if(a[i] >= last) {
				last = a[i];
			}
			else if(b[i]>= last) {
				last = b[i];
			}
			else {
				flag = 1;
				break;
			}
		}
		if(flag) {
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	return 0;
}