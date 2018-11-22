/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 100005
#define MOD 99991

using namespace std;

LL c[MAX];
LL f[MAX];
LL dfs(int parent, int node, vector<int> adj[MAX]) {
    LL candies = 1;

    for(int i=0;i<adj[node].size();i++) {
        if(adj[node][i] != parent) {
            candies += dfs(node, adj[node][i], adj);
        }
    }

    return c[node] = candies;
}

LL dfs2(int parent, int node, vector<int> adj[MAX]) {
    
    for(int i=0;i<adj[node].size();i++) {
        if(adj[node][i] != parent) {
            c[node] += dfs2(node, adj[node][i], adj);
        }
    }

    return c[node];
}

void pre() {
    int i;
    f[0] = 1;

    for(i=1;i<MAX;i++) {
        f[i] = (i * f[i-1]) % MOD;
    }
}

int main() {
    int t, n, u, v, q, i, j;
    pre();
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        vector<int> adj[MAX];
        memset(c, 0, sizeof c);
        for(i=0;i<n-1;i++) {
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(-1, 1, adj);
        dfs2(-1, 1, adj);
        scanf("%d", &q);

        while(q--) {
            scanf("%d", &j);
            if(c[j] >= MOD) printf("0\n");
            else printf("%lld\n", f[c[j]]);
        }
        
    }
    return 0;
}

