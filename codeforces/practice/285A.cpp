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
    int n, k, i;

    vector<int> ans;
    cin>>n;
    cin>>k;

    int st = n;
    while(k--) {
        ans.pb(st--);
    }

    for(i=1;i<=st;i++) {
        ans.pb(i);
    }

    for(i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

