/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 1000000007
#define MOD 1000000007

using namespace std;

bool check(int *a, int mid, int k, int n) {
    int i, count=0;

    for(i=0;i<k;i++) {
        count += (a[i]/mid);
    }
    return count >= n;
}

int main() {
    int k, n;
    cin>>n>>k;

    int a[k];

    for(int i=0;i<k;i++) {
        cin>>a[i];
    }

    int low = 1, high = MAX;
    int ans;
    while(low<=high) {
        int mid = (low+high) >> 1;

        if(check(a, mid, k, n)) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }

    cout<<ans<<endl;
    return 0;
}

