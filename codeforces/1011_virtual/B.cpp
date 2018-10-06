/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define LIMIT 105
#define MOD 1000000007

using namespace std;

bool possible(int *a, int mid, int m, int n) {
    if(mid == 0) return true;
    int i, count = 0;
    for(i=0;i<LIMIT;i++) {
        count += (a[i]/mid);
    }

    return count >= n;
}

int main() {
    int n, m, a[MAX], x;

    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>x;
        a[x]++;
    }

    int low = 0, high = MAX, ans = 0;

    while(low <= high) {
        int mid = (low + high) >> 1;

        if(possible(a, mid, m, n)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout<<ans<<endl;
    return 0;
}

