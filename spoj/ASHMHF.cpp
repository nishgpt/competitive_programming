/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MINI 1e18
#define MOD 1000000007

using namespace std;

void print_array(LL *a, int n) {
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int t, n, i, j, tc = 1;

    cin>>t;
    while(t--) {
        cin>>n;
        
        LL a[n];
        map<int, int> index;

        for(i=0;i<n;i++) {
            cin>>a[i];
            index[a[i]] = i;
        }

        sort(a, a+n);

        LL left[n], right[n];

        for(i=0;i<n;i++) {
            if(i==0) left[i] = 0;
            else left[i] = left[i-1] + i * (a[i] - a[i-1]); 
        }

        for(i=n-1;i>=0;i--) {
            if(i==n-1) right[i] = 0;
            else right[i] = right[i+1] + (n - 1 - i) * (a[i+1] - a[i]);
        }

        LL mini = MINI;
        int idx;
        for(i=0;i<n;i++) {
            if(left[i] + right[i] < mini) {
                mini = left[i] + right[i];
                idx = index[a[i]];
            }
            else if(left[i] + right[i] == mini && idx > index[a[i]]) {
                idx = index[a[i]];
            }
        }

        printf("Case %d: %d\n", tc++, idx+1);
    }
    return 0;
}

