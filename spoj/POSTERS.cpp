/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 10000007
#define MOD 1000000007

using namespace std;

vector<int> v[MAX];
int a[MAX];
int main() {
    int t, n;
    cin>>t;

    while(t--) {
        cin>>n;

        int i, j, l, r;
        vector<pair<int, int> > ranges;
        for(i=0;i<n;i++) {
            cin>>l>>r;
            ranges.pb(mp(l, r));
            v[l].pb(i+1);
        }

        set<int, std::greater<int> > st;
        set<int> ans;
        for(i=1;i<MAX;i++) {
            int sz = v[i].size();
            for(j=0;j<sz;j++) {
                st.insert(v[i][j]);
            }
            //Now check if set's highest element's range contains ith index
            while(!st.empty()) {
                set<int, std::greater<int> > :: iterator it = st.begin();
                int highest = *it;
                if(i >= ranges[highest-1].first && i <= ranges[highest-1].second) {
                    a[i] = highest;
                    ans.insert(highest);
                    break;
                }
                st.erase(it);
            }
        }
        
        cout<<ans.size()<<endl;
    }
    return 0;
}
