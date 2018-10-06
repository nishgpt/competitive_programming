/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 2005
#define MOD 1000000007

using namespace std;

int main() {
    int i, n, j, k;
    cin>>n>>k;

    vector<pair<int, int> > v;
    int a[MAX];
    int f[MAX] = {0};

    for(i=0;i<n;i++) {
        cin>>a[i];
        v.pb(mp(a[i], i));    
    }

    sort(v.rbegin(), v.rend());
    
    int kk = k;
    for(i=0;i<v.size() && (kk--);i++) {
        f[v[i].second] = 1;
    }

    int st = -1;
    int ans = 0;
    vector<int> s;
    for(i=0;i<n;i++) {
        if(f[i] == 1) {
            ans = ans + a[i];
            s.pb(i-st);
            st = i;
        }
        else {
            continue;
        }
    }

    s[k-1] = s[k-1] + (n-1-st);

    cout<<ans<<endl;
    for(i=0;i<s.size();i++) {
        cout<<s[i]<<" ";
    }
    
    return 0;
}

