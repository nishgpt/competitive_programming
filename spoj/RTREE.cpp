/*
    Author : Nishant Gupta 2.0
*/
#include<bits/stdc++.h>

#define LL long long int
#define pb push_back
#define mp make_pair
#define MAX 1000010
#define MOD 1000000007

using namespace std;

int ans[MAX]; 
vector<int> adj[MAX];
int parent[MAX];

pair<int, int> dfs(int node, int parent) {
    int max1 = 0, max2 = 0, i, max_ans = 0;

    for(i=0;i<adj[node].size();i++) {
        if(adj[node][i] != parent) {
            pair<int, int> child_data = dfs(adj[node][i], node);
            
            //update max_ans (if any child's subtree has better answer
            max_ans = max(max_ans, child_data.first);

            //update maximum lengths
            if(child_data.second + 1 >= max1) {
                max2 = max1;
                max1 = child_data.second + 1;
            }
            else if(child_data.second + 1 >= max2) {
                max2 = child_data.second + 1;
            }
        }
    }

    max_ans = max(max_ans, max1 + max2);
    ans[node] = max_ans;
    return mp(max_ans, max1);
}

int main() {
    int n, i, j, k, u, v, r, q;

    scanf("%d", &n);

    for(i=1;i<n;i++) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    scanf("%d", &r);
    
    dfs(r, -1);

    scanf("%d", &q);
    while(q--) {
        scanf("%d", &k);
        printf ("%d\n", ans[k]);
    }

    return 0;
}

