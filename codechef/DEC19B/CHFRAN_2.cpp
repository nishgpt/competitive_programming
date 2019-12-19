/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 1000000
#define MOD 1000000007
#define MAX_ITER 10000000
#define getcx getchar_unlocked

using namespace std;

inline void inp( int &n ) {
    n=0;    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
    while(  ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
}

void handle_separately(vector<pair<int, int> > ranges, vector<int> st, vector<int> e, int n) {
    int uniq[MAX+2] = {0};
    int as[MAX+2] = {0}, ae[MAX+2] = {0};
    int i;

    // for(i=0;i<n;i++) {
    //     uniq[ranges[i].first] = 1;
    //     uniq[ranges[i].second] = 1;
    //     as[st[i]]++;
    //     ae[e[i]]++;
    // }

    // vector<int> rev_indices;
    // for(i=1;i<=MAX;i++) {
    //     if(uniq[i] == 1) rev_indices.pb(i);
    //     as[i]+=as[i-1];
    //     ae[i]+=ae[i-1];
    // }

    // int mini = INT_MAX;
    // int idx = rev_indices.size();
    // for(i=1;i<idx;i++) {
    //     if(i==MAX_ITER) raise(SIGABRT);
    //     int num_of_ranges_ending_before = ae[rev_indices[i-1]];
    //     int num_of_ranges_starting_after = n - as[rev_indices[i]-1];

    //     if(num_of_ranges_ending_before > 0 && num_of_ranges_starting_after > 0) {
    //         mini = min(mini, n - (num_of_ranges_ending_before + num_of_ranges_starting_after));
    //     }
    // }

    // if(mini == INT_MAX) mini = -1;
    // cout<<mini<<endl;
}

int main() {
    int t, n, i, j, l, r;
    inp(t);

    while(t--) {
        inp(n);
        bool f = true;
        vector<pair<int, int> > ranges;
        vector<int> st;
        vector<int> e;
        for(i=0;i<n;i++) {
            inp(l);inp(r);
            ranges.pb(mp(l, r));
            st.pb(l);
            e.pb(r);
            if(r > MAX) f = false;
        }

        if(f) {
            handle_separately(ranges, st, e, n);
            continue;
        }

        set<int> points; //for unique points in ranges
        map<int, int> rev_indices; //key: index, value: actual point
        for(i=0;i<n;i++) {
            points.insert(ranges[i].first);
            points.insert(ranges[i].second);
        }

        set<int>:: iterator it;
        int idx = 0;
        for(it = points.begin(); it != points.end(); it++, idx++){
            // if(idx==MAX_ITER) raise(SIGABRT);
            rev_indices[idx] = *it;
        }
        
        

        sort(st.begin(), st.end());
        sort(e.begin(), e.end());

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
        printf("%d\n", mini);
    }
    return 0;
}

