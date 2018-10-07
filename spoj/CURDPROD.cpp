#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define MS(a) memset(a, 0, sizeof a)
#define M 1000000
 
int main() {
	int t, i, j, k, n;
	LL a[10004];
	scanf("%d", &t);
	LL target;
	while(t--) {
		scanf("%d %lld", &n, &target);
		for(i=0;i<n;i++) {
			scanf("%lld", &a[i]);
		}
		LL l = 1, h = 1e18, ans;
		while(l <= h) {
			LL mid = (l+h)/2;
			LL curd = 0;
			int flag = 0;
			for(i=0;i<n;i++) {
				curd = curd + mid/a[i];
				if(curd >= target) {
					flag =1;
					break;
				}
			}
			if(flag) {
				ans = mid;
				h = mid - 1;
			}
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
} 