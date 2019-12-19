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
    int t, n;

    cin>>t;

    while(t--) {
        cin>>n;
        int i, x, elem = 0, f = 0;

        for(i=0;i<n;i++) {
            cin>>x;
            if(x == 0) {
                elem--;
            } else elem++;

            if(elem < 0) f = 1;
        }

        if(f) cout<<"Invalid"<<endl;
        else cout<<"Valid"<<endl;
    }
    return 0;
}

