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

int main() {
    int i, prev = 0, k, c = 0, n, ans = 0;
    cin>>n;

    for(i=0;i<n;i++) {
        cin>>k;
        c = c + (prev - k);
        if(c < 0) {
            ans += (-1*c);
            c = 0;
        }
        prev = k;
    }

    cout<<ans<<endl;
    return 0;
}

