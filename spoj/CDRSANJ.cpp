#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define MOD 1000000007
 
int prime[100005][3];
void sieve() {
	int i, j, k;
	prime[0][0] = prime[1][0] = 1;
	for(i=2;i*i<100005;i++) {
		for(j=2*i;j<100005;j+=i) {
			int p = i;
			int q = j/i;
			if((prime[j][1] == 0 && prime[j][2] == 0) || ((prime[j][1] + prime[j][2]) > (p+q))) {
				prime[j][1] = min(p, q);
				prime[j][2] = max(p, q);
			}
			prime[j][0] = 1;
		}
	}
}
 
int dp[100005];
int f(int n) {
	if(n <= 2) return n;
	if(dp[n] != -1) return dp[n];
	if(prime[n] == 0) {
		dp[n] = 0;
		return dp[n];
	}
	dp[n] = f(prime[n][1]) + f(prime[n][2]);
	return dp[n];
}
	
int main() {
	sieve();
	int i, j, n;
	memset(dp, -1, sizeof dp);
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
} 