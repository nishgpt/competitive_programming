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

int ans[MAX];
void precompute() {
    int k = 0, i, j;
    for(i=1;i<MAX;i++) {
        if((k+1)*(k+1)*(k+1) == i) {
            k++;
        }

        ans[i] = INT_MAX;
        for(j=1;j<=k;j++) {
            ans[i] = min(ans[i], ans[i - j*j*j] + 1);
        }
    }
}

int main() {
    int n, t=1;
    precompute();
    
    while(scanf("%d",&n)!=EOF) {
        printf("Case #%d: %d\n", t++, ans[n]);
    }

    return 0;
}

