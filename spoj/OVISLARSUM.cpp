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

LL mulmod(LL a, LL b, LL mod) {
    LL res = 0;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % mod;
        a = (a * 2) % mod;
        b /= 2;
    }
    return res % mod;
}

LL l, r, mod;
LL calc(LL num) {
    if(!num) return 0;

    LL q = num / mod;
    LL rem = num % mod;
    
    LL x = mulmod(q, mulmod(mod-1, mod, MOD*2), MOD*2) / 2;
    LL y = mulmod(rem, rem+1, MOD*2) / 2;

    return (x % MOD + y % MOD) % MOD;
}

int main() {
    cin>>l>>r>>mod;
    
    cout<<(calc(r) - calc(l-1) + MOD) % MOD<<endl;
    return 0;
}

