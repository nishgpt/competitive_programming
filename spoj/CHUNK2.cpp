/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define PMAX 1300000
#define MOD 1000000007

using namespace std;

int parent[MAX];
vector<int> p;


int find_parent(int node) {
    if(parent[node] == node) {
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}

void _union(int u, int v) {
    parent[find_parent(u)] = find_parent(v);
}


void pre() {
    int i, j;
    bool primes[PMAX];
    memset(primes, true, sizeof primes);

    primes[0] = primes[1] = false;
    for(i=2;i*i<PMAX;i++) {
        if(primes[i]) {
            for(j=i*i;j<PMAX;j+=i) {
                primes[j] = false;
            }
        }
    }

    for(i=2;i<PMAX;i++) {
        if(primes[i]) {
            p.pb(i);
        }
    }
}

int main() {
    int t, n, u, v, m, i, j;
    pre();
    cin>>t;

    while(t--) {
        cin>>n>>m;
        
        for(i=1;i<=n;i++) {
            parent[i] = i;
        }

        for(i=0;i<m;i++) {
            cin>>u>>v;
            _union(u, v);                
        }        

        if(m == 0) {
            cout<<"-1"<<endl;
            continue;
        }

        int freq[MAX] = {0};
        for(i=1;i<=n;i++) {
            parent[i] = find_parent(i);
            freq[parent[i]]++;
        }

        int maxi = -1;
        for(i=1;i<=n;i++) {
            maxi = max(maxi, freq[i]);
        }
        
        cout<<p[maxi-1]<<endl;
    }
    return 0;
}

