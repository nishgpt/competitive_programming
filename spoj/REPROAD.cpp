#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007
 
int main() {
	int t, i, j, k, n;
	int a[10005];
	cin>>t;
	while(t--) {
		scanf("%d %d", &n, &k);
		for(i=0;i<n;i++) {
			scanf("%d", &a[i]);
			if(a[i]) a[i] = 0;
			else a[i] = -1;
		}
 
		int st = 0, end = 0, m = 0;
		for(i=0;i<n;) {
			if(a[i] == 0) {
				end++;
				i++;
			}
			else {
				if(k-1 < 0) {
					if(a[st] == -1)k++;
					st++;
				}
				else {
					k--;
					end++;
					i++;
				}
			}
			m = max(m, (end-st));
		}
		printf("%d\n", m);
	}
	return 0;
} 