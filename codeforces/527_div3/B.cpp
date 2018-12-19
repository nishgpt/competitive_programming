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
    int n;
    cin>>n;

    int i, j, a[n];

    for(i=0;i<n;i++) {
        cin>>a[i];
    }

    sort(a, a+n);

    int ans = 0;
    for(i=1;i<n;i+=2) {
        if(a[i] != a[i-1]) {
            ans += (a[i] - a[i-1]);
        }
    }

    cout<<ans<<endl;
    return 0;
}

