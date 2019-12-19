/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 1000000007
#define MAX_ITER 10000000

using namespace std;

int main() {
    int t, n, i, j, l, r;
    cin>>t;

    while(t--) {
        cin>>n;
        vector<pair<int, int> > ranges;
        for(i=0;i<n;i++) {
            cin>>l>>r;
            ranges.pb(mp(l, r));
        }

        set<int> points; //for unique points in ranges
        map<int, int> rev_indices; //key: index, value: actual point
        vector<int> st;
        vector<int> e;
        for(i=0;i<ranges.size();i++) {
            if(i == MAX_ITER) raise(SIGABRT);
            points.insert(ranges[i].first);
            points.insert(ranges[i].second);
            st.pb(ranges[i].first);
            e.pb(ranges[i].second);
        }

        sort(st.begin(), st.end());
        sort(e.begin(), e.end());
        
        set<int>:: iterator it = points.begin();
        int idx = 0;
        for(it = points.begin(); it != points.end(); it++, idx++){
            if(idx==MAX_ITER) raise(SIGABRT);
            rev_indices[idx] = *it;
        }
        
        int mini = INT_MAX;
        for(i=1;i<idx;i++) {
            if(i==MAX_ITER) raise(SIGABRT);
            int num_of_ranges_ending_before = upper_bound(e.begin(), e.end(), rev_indices[i-1]) - e.begin();
            int num_of_ranges_starting_after = n - (lower_bound(st.begin(), st.end(), rev_indices[i]) - st.begin());

            if(num_of_ranges_ending_before > 0 && num_of_ranges_starting_after > 0) {
                mini = min(mini, n - (num_of_ranges_ending_before + num_of_ranges_starting_after));
            }
        }

        if(mini == INT_MAX) mini = -1;
        cout<<mini<<endl;
    }
    return 0;
}

