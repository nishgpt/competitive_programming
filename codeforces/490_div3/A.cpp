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
    int i, j, k, n;
    cin>>n>>k;

    int a[n];
    for(i=0;i<n;i++) {
        cin>>a[i];
    }

    int l = 0, r = 0;

    for(i=0;i<n;i++) {
        if(a[i]<=k) l++;
        else break;
    }
    
    if(i!=n) {
        for(i=n-1;i>=0;i--) {
            if(a[i]<=k) r++;
            else break;
        }
    }

    cout<<l+r<<endl;
    return 0;
}

