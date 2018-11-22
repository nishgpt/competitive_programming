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
        int v, pos = 0, neg = 0;
        for(int i=0;i<n;i++) {
            cin>>v;

            if(v<0) neg++;
            else if(v>0) pos++;
        }

        if(pos >= neg) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

