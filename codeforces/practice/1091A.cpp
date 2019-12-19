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
    int y, b, r;
    cin>>y>>b>>r;

    int i, ans;
    for(i=1;i<=y;i++) {
        if(i+1<=b && i+2<=r) {
            ans = (i+i+1+i+2);
        }
    }

    cout<<ans<<endl;
    return 0;
}

