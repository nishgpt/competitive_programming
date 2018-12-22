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

int main() {
    int t, a, b, h, w, n, i, j;
    cin>>t;

    while(t--) {
        cin>>a>>b>>h>>w;
        cin>>n;
        int wt[n];

        for(i=0;i<n;i++) {
            cin>>wt[i];
        }

        sort(wt, wt+n, greater<int>());

        int target = h-w;
        if(target<0) {
            cout<<0<<endl;
            continue;
        }

        for(i=1;i<n;i++) {
            wt[i] = wt[i] + wt[i-1];
        }

        int ans=-1;
        for(j=1;j<=n;j++) {
            for(i=j-1;i<n;i++) {
                int sum = wt[i];
                if(i-j >= 0) sum -= wt[i-j];

                if(sum > target) {
                    ans = j;
                    break;
                }
            }
            if(ans!=-1) break;
        }

        cout<<ans<<endl;
    }
    return 0;
}

