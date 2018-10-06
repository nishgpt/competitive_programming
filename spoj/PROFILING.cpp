/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define push_back pb
#define make_pair mp
#define MAX 100005
#define MOD 1000000007

using namespace std;

LL a[MAX];
LL get_count(int n, int k) {
    if(n < 0) return 0;
    
    if(a[n] != -1) return a[n];

    if(k > n) {
        return a[n] = 0;
    }

    if(k == n) {
        return a[n] = 1;
    }
    
    if(n > 1) return a[n] = (get_count(n-1, k) + get_count(n-2, k)) % MOD;
    return a[n] = 0;
}

int main() {
    int t, n, k;
    
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);

        if(n == k) {
            printf("1\n");
        }
        else if(k > n) {
            printf("0\n");
        }
        else {
            memset(a, -1, sizeof(a));  
            printf("%lld\n", get_count(n, k));
        }
    }
    return 0;
}

