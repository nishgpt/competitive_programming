/*
    Author: Team - baddy_boyz
    Members: Nishant Gupta, Arpit Uppal
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007

using namespace std;

int main() {
    int t, n;

    cin>>t;

    while(t--) {
        cin>>n;

        int a[n];
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        
        int pos=-1;
        for(int i=1;i<n;i++) {
            if(a[i] < a[i-1]) {
                pos = i;
                break;
            }
        }

        if(pos == -1) {
            cout<<"YES"<<endl;
            continue;
        }

        bool flag = true;
        for(int i = pos+1;i<n;i++) {
            if(a[i] < a[i-1]) {
                flag = false;
                break;
            }
        }

        if(pos != n-1 && a[0] < a[n-1]) flag = false;

        if(flag) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }
    return 0;
}

