#include<bits/stdc++.h>
using namespace std;
#define LL long long int
int main() {
	int i, j, k, n, t;
	string s;
	scanf("%d", &t);
	while(t--) {
		cin>>s;
		int f[2005] = {0};
		int b[2005] = {0};
		n = s.length();
		j = n-1;
		for(i=0;i<n;i++, j--) {
			if(i) f[i] += f[i-1];
			if(j != n-1) b[j] += b[j+1];
			if(s[i] == 'K') {
				f[i]++;
			}
			if(s[j] == 'K') {
				b[j]++;
			}
		}
		
		int ans = 0;
		for(i=1;i<n-1;i++) {
			if(s[i] == 'E') {
				ans += (f[i] * b[i]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 