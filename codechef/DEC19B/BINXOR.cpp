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

LL fact[MAX];
void pre() {
    fact[0] = 1;
    for(int i=1;i<MAX;i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

LL power(LL b, LL e, LL ans) {
    if(!e) return ans % MOD;
    if(e&1) ans = (ans * b) % MOD;
    return power((b*b) % MOD, e>>1, ans);
}

LL nCr(int n, int r) {
    LL result = fact[n];
    LL den1 = fact[r];
    LL den2 = fact[n-r];

    result = (result * power(den1, MOD-2, 1)) % MOD;
    result = (result * power(den2, MOD-2, 1)) % MOD;
    return result;
}

int main() {
    int t, n, i;
    string a, b;
    pre();
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>a;cin>>b;

        int a_one = 0, b_one = 0;
        for(i=0;i<n;i++) {
            if(a[i] == '1') a_one++;
            if(b[i] == '1') b_one++;
        }
        
        LL ans = 0;
        int min_ones = abs(a_one - b_one);
        int max_ones;

        if(a_one + b_one <= n) {
            max_ones = a_one + b_one;
        } else {
            max_ones = 2 * n - (a_one + b_one);
        }
        
        //cout<<min_ones<<" "<<max_ones<<endl;
        for(i=min_ones;i<=max_ones;i+=2) {
            ans = (ans + nCr(n, i)) % MOD;
        }
        cout<<ans<<endl;
		
    }
    return 0;
}

