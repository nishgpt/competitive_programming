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
    int t, n, k, i;
    cin>>t;

    while(t--) {
        cin>>n>>k;

        int a[n];
        for(i=0;i<n;i++) {
            cin>>a[i];
        }

        sort(a, a+n, greater<int>());
        int least = a[k-1];
        cout<<upper_bound(a, a+n, least, greater<int>()) - a<<endl;
    }
    return 0;
}

