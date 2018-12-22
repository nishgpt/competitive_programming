/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAX 2000000009

using namespace std;

vector<pair<int, int> > v;
int _count[1005];
int main() {
    int n, m, i, j, x;

    scanf("%d %d", &n, &m);

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%d", &x);
            v.pb(mp(x, i));
        }
    }
    
    sort(v.begin(), v.end());

    int l = v.size();

    int curr = 0;
    set<int> st;
    st.insert(v[0].second);
    _count[v[0].second]++;
    int mini = MAX;

    for(i=curr+1;i<l;) {
        st.insert(v[i].second);
        _count[v[i].second]++;        
        if(st.size() == n) {
            mini = min(mini, (v[i].first - v[curr].first));
            _count[v[curr].second]--;
            _count[v[i].second]--;
            if(_count[v[curr].second] == 0) {
                st.erase(v[curr].second);
            }
            curr++;
            continue;
        }
        i++;
    }

    cout<<mini<<endl;
    return 0;
}

