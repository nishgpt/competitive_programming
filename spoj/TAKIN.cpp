#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define MAX 50
 
LL solve(LL *a, int n, LL m) {
	LL limit = (1 << n);
	LL i, j;
	LL ans = -1;
	for(i=0;i<limit;i++) {
		LL sum = 0;
		bool flag = true;
		for(j=0;j<n;j++) {
			if((1<<j) & i) {
				if(sum + a[j] <= m) {
					sum += a[j];
				} 
				else {
					flag = false;
					break;
				}
			}
		}
		if(flag) ans = max(ans, sum);
	}
	return ans;
}
 
int main() {
	int i, t, j, k, n;
	LL m;
	scanf("%d", &t);
	LL a[MAX];
	while(t--) {
		scanf("%d %lld", &n, &m);
		for(i=0;i<n;i++) {
			scanf("%lld", &a[i]);
		}
		cout<<solve(a, n, m)<<endl;
	}
	return 0;
} 