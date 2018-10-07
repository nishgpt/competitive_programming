#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define M 1000005
#define MAX 1000000
 
int prime[M];
void mark_primes() {
	int i, j;
	prime[0] = prime[1] = 1;
	for(i=2;i*i<=M;i++) {
		if(!prime[i]) {
			for(j=i*i;j<M;j+=i) {
				prime[j] = 1;
			}
		}
	}
}
 
int ans[M];
queue<int> q;
void precompute() {
	int i, j;
	ans[2] = ans[3] = ans[5] = ans[7] = 1;
	q.push(2);q.push(3);q.push(5);q.push(7);
	int dig, num;
	while(!q.empty()) {
		int k = q.front();
		q.pop();
		ans[k] = 1;
		dig = log10(k) + 1;
		
		for(j=1;j<10;j++) {
			num = j*pow(10, dig) + k;
			if(num <= MAX && !prime[num]) {
				q.push(num);
			}
		}
	}
	for(i=1;i<=MAX;i++) {
		ans[i] = ans[i-1] + ans[i];
	}
}
 
int main() {
	int i, n;
	mark_primes();
	precompute();
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}