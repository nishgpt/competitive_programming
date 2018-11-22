/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 1000007
#define MOD 1000000007

using namespace std;

LL pressure[MAX];
int main() {
    
    int n, h, p, i;
    scanf("%d", &n);

    vector<pair<LL, LL> > v;
    for(i=0;i<n;i++) {
        cin>>p>>h;
        v.pb(mp(p, h));
    }

    int last = 0, idx = 0;
    for(i=0;i<MAX;i++) {
        if(v[idx].second >= (i - last + 1)) {
            //if(i<100)cout<<i<<endl;
            pressure[i] = 10 * v[idx].first; 
        }
        if(v[idx].second == (i - last + 1)) {
            idx++;
            last = i+1;
        }
    }
    
    for(i=1;i<MAX;i++) {
        pressure[i] += pressure[i-1];
    }

    cout<<endl;
    int q, l, r;
    cin>>q;
    while(q--) {
        scanf("%d %d", &l, &r);
        r--;
        LL ans = pressure[r];
        if(l>0) ans -= pressure[l-1];

        cout<<ans<<endl;
    }
    return 0;
}

