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
    int t, a;

    cin>>t;
    while(t--) {
        cin>>a;
        if(360 % (180 - a) == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

