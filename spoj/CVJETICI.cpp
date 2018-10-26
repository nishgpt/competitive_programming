#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define LL long long 
int bit[N];

void update(int pos, int val) {
	int i = pos;
	while(i<N) {
		bit[i] += val;
		i += (i&(-i));
	}
}

LL query(int pos) {
	int i = pos;LL ans = 0;
	while(i>0) {
		ans += bit[i];
		i -= (i&(-i));
	}	
	return ans;
}

int main() {
	int n, j, i, l, r;
	LL k = 0, oldf = 0;
	scanf("%d", &n);
	int flowers[N] = {0};
	while(n--) {
		scanf("%d %d", &l, &r);
		j = query(l);
		k = k + (j - flowers[l]);
		flowers[l] = j;
		j = query(r);
		k = k + (j - flowers[r]);
		flowers[r] = j;
		update(l+1, 1);
		update(r, -1);
		printf("%lld\n", k - oldf);
		oldf = k;
	}
	return 0;
}
