/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 1005
#define MOD 1000000007

using namespace std;

LL ans[MAX][10];
LL mul[10] = {0, 0, 5, 4, 3, 2, 2, 2, 2, 2};

void pre() {
    int i, j, d;
    for(i=1;i<10;i++) {
        ans[1][i] = 1;
    }

    for(i=2;i<MAX;i++) {
        ans[i][1] = ans[i-1][1];
        for(d=2;d<10;d++) {
            ans[i][d] = (ans[i-1][d] * mul[d]) % MOD;
        }
    }
}

int main() {
    LL n, t;
    pre();
    cin>>t;
    while(t--) {
        cin>>n;
        LL count = 0;
        for(int i=1;i<10;i++) {
            count = (count + ans[n][i]) % MOD;
        }

        cout<<count<<endl;
    }
    return 0;
}

