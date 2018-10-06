/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 105
#define MOD 1000000007

using namespace std;

int main() {
    int n, a[MAX] = {0}, x, ans;

    cin>>n;
    while(n--) {
        cin>>x;
        a[x]++;
    }

    ans = -1;
    for(int i=0;i<MAX;i++) {
        ans = max(ans, a[i]);
    }

    cout<<ans<<endl;
    return 0;
}

