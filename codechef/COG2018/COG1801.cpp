/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007

using namespace std;

LL f[MAX];
void pre() {
    int i;
    f[0] = 1;
    for(i=1;i<MAX;i++) {
        f[i] = (i * f[i-1]) % MOD;
    }
}

LL power(LL b, LL e, LL ans) {
    if(!e) return ans;
    if(e&1) ans = (ans * b) % MOD;
    return power((b*b) % MOD, e>>1, ans);
}

LL nCr(int n, int r) {
    LL num = f[n];
    LL den = (f[r] * f[n-r]) % MOD;
    return (num * power(den, MOD-2, 1)) % MOD;
}

int main() {
    int t, n, p, k, i, j;
	pre();
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d", &n, &p, &k);

        LL a[n];

        for(i=0;i<n;i++) {
            scanf("%lld", &a[i]);
        }

        sort(a, a+n);

        LL ans = 0;
        for(i=0;i<n;i++) {
            int elements = upper_bound(a, a+n, a[i]*p) - a - i - 1;
            if(elements >= k-1) {
                ans = (ans + nCr(elements, k-1)) % MOD;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}


