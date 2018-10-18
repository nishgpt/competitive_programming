/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 200005
#define MOD 1000000007

using namespace std;

int main() {
    int n, k;

    cin>>n>>k;

    int i, j, h[n];
    for(i=0;i<n;i++) {
        cin>>h[i];
    }
    sort(h, h+n);
    
    LL a[MAX];

    if(h[0] == h[n-1]) {
        cout<<"0"<<endl;
        return 0;
    }

    for(i=0;i<=h[n-1];i++) {
        int x = upper_bound(h, h+n, i) - h;
        a[i] = ((i==0) ? 0 : a[i-1]) + (n - x);
    }
    
    int curr = h[0]-1;
    LL count = 1;
    for(i=h[0]-1;;) {
        if(a[i] - a[curr] > k) {
            count++;
            curr = i-1;
        } 
        else {
            i++;
        }
        if(i>h[n-1]) break;
    }
    cout<<count<<endl;
    return 0;
}

