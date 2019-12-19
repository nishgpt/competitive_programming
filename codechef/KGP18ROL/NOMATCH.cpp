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
    int t, n, i, j;
    cin>>t;

    while(t--) {
        cin>>n;

        int a[n];
        for(i=0;i<n;i++) {
            cin>>a[i];
        }

        sort(a, a+n);

        i = 0; j = n-1;
        LL ans = 0;
        while(i<j) {
            ans += (a[j] - a[i]);
            i++;
            j--;
        }

        cout<<ans<<endl;
    }
    return 0;
}

