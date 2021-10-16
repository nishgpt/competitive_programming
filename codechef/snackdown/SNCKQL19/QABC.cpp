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
        int a[n], b[n];
        
        for(i=0;i<n;i++) {
            cin>>a[i];
        }
        for(i=0;i<n;i++) {
            cin>>b[i];
        }

        string ans = "TAK";
        for(i=n-1;i>=2;i--) {
            if(b[i] < a[i] || ((b[i] - a[i]) % 3 != 0)) {
                ans = "NIE";
                break;
            }

            int times = (b[i] - a[i]) / 3;
            a[i] += times * 3;
            a[i-1] += times * 2;
            a[i-2] += times;
        }

        if(a[0] != b[0] || a[1] != b[1]) ans = "NIE";

        cout<<ans<<endl;
    }
    return 0;
}

