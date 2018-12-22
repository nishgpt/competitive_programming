/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 29
#define MOD 1000000007

using namespace std;

LL a[MAX];

void pre() {
    LL i, pow2 = 1;
    for(i=0;i<MAX;i++) {
        a[i] = pow2*5;
        pow2<<=1;

        if(i) a[i] = a[i] + a[i-1];
        // cout<<a[i]<<endl;
    }
}

void print_ans(LL n) {
    string ans;
    switch(n) {
        case 1:
            ans = "Asad";
            break;
        case 2:
            ans = "Foyj";
            break;
        case 3:
            ans = "Juwel";
            break;
        case 4:
            ans = "Mijan";
            break;
        case 5:
            ans = "Tanmay";
            break;
    }

    cout<<ans<<endl;
}

int main() {
    LL i, n;
    pre();

    while(scanf("%lld", &n) != EOF) {
        if(n<=5) {
            print_ans(n);
            continue;
        }

        LL idx = lower_bound(a, a+MAX, n) - a;
        if(a[idx] == n) {
            print_ans(5);
            continue;
        }

        LL repetition = (a[idx] - a[idx-1]) / 5;
        n = n - a[idx-1];
        LL q = (n / repetition);
        LL r = n % repetition;
        if(r != 0) q++;
    
        print_ans(q);
    }
    return 0;
}

