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
    int t, n, p, s;
    cin>>t;

    while(t--) {
        cin>>n;
        int a[9] = {0};
        for(int i=0;i<n;i++) {
            cin>>p>>s;
            if(p>=1 && p<=8) {
                a[p] = max(a[p], s);
            }
        }

        int total = 0;
        for(int i=1;i<=8;i++) {
            total += a[i];
        }

        cout<<total<<endl;
    }
    return 0;
}

