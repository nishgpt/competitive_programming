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
    int i, j, k, n, m;

    cin>>n>>m;
    LL a[n];
    stack<pair<LL, int> > v[m];
    for(i=0;i<n;i++) {
        cin>>a[i];
        v[a[i]%m].push(mp(a[i], i));
    }

    int sz = n/m;
    int moves = 0;
    vector<int> less;
    vector<int> more;
    for(i=0;i<m;i++) {
        if(v[i].size()>sz) more.pb(i);
        else if (v[i].size()<sz) less.pb(i);
    }

    int st = less[0];
    for(i=0;i<more.size();i++) {
        while(v[more[i]].size() > sz) {
            for(j=st;j<less.size();j++) {
                if(less[j] < more[i]) continue;
                while(v[less[j]].size() < sz) {
                    pair<LL, int> p = v[more[i]].top();
                    v[more[i]].pop();

                    p.first += (less[j]-more[i]);
                    v[less[j]].push(p);
                    moves++;
                    
                    if(v[less[j]].size() == sz) {
                        st = j+1;
                        break;
                    }
                    if(v[more[i]].size() == sz) break;
                }
                if(v[more[i]].size() == sz) break;
            }
        }
    }

    vector<int> more1;
    vector<int> less1;
    for(i=0;i<m;i++) {
        if(v[i].size() > sz) more1.pb(i);
        else if(v[i].size() < sz) less1.pb(i);
    }

    st = less1[0];
    for(i=0;i<more1.size();i++) {
        while(v[more1[i]].size() > sz) {
            for(j=st;j<less1.size();j++) {
                while(v[less1[j]].size() < sz) {
                    pair<LL, int> p = v[more1[i]].top();
                    v[more1[i]].pop();

                    p.first += ((less1[j]-more1[i]+m)%m);
                    v[less1[j]].push(p);
                    moves++;
                    
                    if(v[less1[j]].size() == sz) {
                        st = j+1;
                        break;
                    }
                    if(v[more1[i]].size() == sz) break;
                }
                if(v[more1[i]].size() == sz) break;
            }
        }
    }

    cout<<moves<<endl;
    int ans[n];
    for(i=0;i<m;i++) {
        while(v[i].size() != 0) {
            pair<LL, int > p = v[i].top();
            v[i].pop();
            a[p.second] = p.first;
        }
    }

    for(i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}

